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
            //set keys for keyboard
            KeyEventRules.Add(ConfigData->KeyboardNavigation.UpKey, EUINavigation::Up);
            KeyEventRules.Add(ConfigData->KeyboardNavigation.DownKey, EUINavigation::Down);
            KeyEventRules.Add(ConfigData->KeyboardNavigation.LeftKey, EUINavigation::Left);
            KeyEventRules.Add(ConfigData->KeyboardNavigation.RightKey, EUINavigation::Right);
            KeyActionRules.Add(ConfigData->KeyboardNavigation.Accept, EUINavigationAction::Accept);
            KeyActionRules.Add(ConfigData->KeyboardNavigation.Back, EUINavigationAction::Back); 

            // set keys for gamepad
            KeyEventRules.Add(ConfigData->GamepadNavigation.UpKey, EUINavigation::Up);
            KeyEventRules.Add(ConfigData->GamepadNavigation.DownKey, EUINavigation::Down);
            KeyEventRules.Add(ConfigData->GamepadNavigation.LeftKey, EUINavigation::Left);
            KeyEventRules.Add(ConfigData->GamepadNavigation.RightKey, EUINavigation::Right);
            KeyActionRules.Add(ConfigData->GamepadNavigation.Accept, EUINavigationAction::Accept);
            KeyActionRules.Add(ConfigData->GamepadNavigation.Back, EUINavigationAction::Back);
            return;
        }

    }

private:

    UPROPERTY()
    TObjectPtr<UCustomNavigationData> NavData;
};