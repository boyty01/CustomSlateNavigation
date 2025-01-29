// Copyright (c) 2025 DMTesseracT
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#pragma once

#include "CoreMinimal.h"
#include "Framework/Application/NavigationConfig.h"
#include "InputCoreTypes.h"
#include "DataAsset/CustomNavigationData.h"
#include "Framework/Application/SlateApplication.h"

class FCustomNavigationConfig : public FNavigationConfig
{
public:


    FCustomNavigationConfig(UCustomNavigationData* ConfigData)
    {
        NavData = ConfigData;
        KeyEventRules.Empty(); // Clear previous bindings
        KeyActionRules.Empty(); // clear action keys

        if (ConfigData)
        {
            //set keys for keyboard navigation 
            for (auto& KeyboardNavMap : ConfigData->KeyboardNavigation.GetMappedNavigation())
            {
                for (FKey Key : KeyboardNavMap.Value)
                {
                    KeyEventRules.Emplace(Key, KeyboardNavMap.Key);
                }
            }

            //set keys for keyboard navigation actions
            for (auto& KeyboardNavMap : ConfigData->KeyboardNavigation.GetMappedActions())
            {
                for (FKey Key : KeyboardNavMap.Value)
                {
                    KeyActionRules.Emplace(Key, KeyboardNavMap.Key);
                }
            }

            //set keys for gamepad navigation 
            for (auto& GamepadNavMap : ConfigData->GamepadNavigation.GetMappedNavigation())
            {
                for (FKey Key : GamepadNavMap.Value)
                {
                    KeyEventRules.Emplace(Key, GamepadNavMap.Key);
                }
            }

            // if changing virtual keys is not allowed, just map the defaults.
            if (ConfigData->GamepadNavigation.bKeepVirtualKeyBindings)
            {
                KeyActionRules.Emplace(EKeys::Virtual_Back, EUINavigationAction::Back);
                KeyActionRules.Emplace(EKeys::Virtual_Accept, EUINavigationAction::Accept);
            }
            else 
            {
                //set keys forgamepad navigation actions
                for (auto& GamepadNavMap : ConfigData->GamepadNavigation.GetMappedActions())
                {
                    for (FKey Key : GamepadNavMap.Value)
                    {
                        KeyActionRules.Emplace(Key, GamepadNavMap.Key);
                    }
                }
            }

            return;
        }

    }

private:

    UPROPERTY()
    TObjectPtr<UCustomNavigationData> NavData;
};