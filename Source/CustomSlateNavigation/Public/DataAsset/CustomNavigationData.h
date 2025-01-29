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
#include "Engine/DataAsset.h"
#include "CustomNavigationData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FKeyboardNavigationOverrides
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> UpKey = { EKeys::W };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> DownKey = { EKeys::S };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey>LeftKey = { EKeys::A };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> RightKey = { EKeys::D };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> Accept = {EKeys::Enter};

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> Back = { EKeys::Escape };

    TMap<EUINavigation, TArray<FKey>> GetMappedNavigation()
    {
        return TMap<EUINavigation, TArray<FKey>>
        {
            { EUINavigation::Up, UpKey },
            { EUINavigation::Down, DownKey },
            { EUINavigation::Left, LeftKey },
            { EUINavigation::Right, RightKey },
        };
    }

    TMap<EUINavigationAction, TArray<FKey>> GetMappedActions()
    {
        return TMap<EUINavigationAction, TArray<FKey>>
        {
            { EUINavigationAction::Accept, Accept },
            { EUINavigationAction::Back, Back }
        };
    }
};

USTRUCT(BlueprintType)
struct FGamepadNavigationOverrides
{
    GENERATED_BODY()

    /*
    If this is true, Accept and Back gamepad key overrides will not be applied and will revert to the default Virtual_Accept and Virtual_Back keys based on platform inputs. Recommended to keep this
    true if you're anticipating shipping to multiple platforms or input devices with different conventions.
    */
    UPROPERTY(EditAnywhere, Config, Category = "Navigation")
    bool bKeepVirtualKeyBindings{ true };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> UpKey = { EKeys::Gamepad_DPad_Up };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> DownKey = { EKeys::Gamepad_DPad_Down };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> LeftKey = {EKeys::Gamepad_DPad_Left};

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation")
    TArray<FKey> RightKey = { EKeys::Gamepad_DPad_Right };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation", meta = (EditCondition = "bKeepVirtualKeyBindings == false", EditConditionHides))
    TArray<FKey> Accept = { EKeys::Gamepad_FaceButton_Bottom };

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Navigation", meta = (EditCondition = "bKeepVirtualKeyBindings == false", EditConditionHides))
    TArray<FKey> Back = { EKeys::Gamepad_FaceButton_Right };

    TMap<EUINavigation, TArray<FKey>> GetMappedNavigation()
    {
        return TMap<EUINavigation, TArray<FKey>>
        {
            { EUINavigation::Up, UpKey },
            { EUINavigation::Down, DownKey },
            { EUINavigation::Left, LeftKey },
            { EUINavigation::Right, RightKey },
        };
    }

    TMap<EUINavigationAction, TArray<FKey>> GetMappedActions()
    {
        return TMap<EUINavigationAction, TArray<FKey>>
        {
            { EUINavigationAction::Accept, Accept },
            { EUINavigationAction::Back, Back }
        };
    }
};

UCLASS(BlueprintType, Config=Game, DefaultConfig)
class CUSTOMSLATENAVIGATION_API UCustomNavigationData : public UDataAsset
{
	GENERATED_BODY()
	
public:
  
        UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Keyboard")
        FKeyboardNavigationOverrides KeyboardNavigation;

        UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gamepad")
        FGamepadNavigationOverrides GamepadNavigation;


};
