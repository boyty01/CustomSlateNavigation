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

#include "CustomSlateNavigation.h"
#include "Config/CustomNavigationSettings.h"
#include "ISettingsModule.h"
#include "Config/CustomNavigationConfig.h"

#define LOCTEXT_NAMESPACE "FCustomSlateNavigationModule"

void FCustomSlateNavigationModule::StartupModule()
{
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->RegisterSettings(
            "Project", // Settings appear under "Project" category
            "Game",    // Settings appear under "Game"
            "Custom Slate Navigation", // Name in UI
            FText::FromString("Custom Slate Navigation"),
            FText::FromString("Configure custom navigation key bindings."),
            GetMutableDefault<UCustomNavigationSettings>()
        );
    }

	const UCustomNavigationSettings* NavSettings = GetDefault<UCustomNavigationSettings>();
    if (NavSettings)
    {
        UCustomNavigationData* ConfigData = Cast<UCustomNavigationData>(NavSettings->CustomNavigationData.LoadSynchronous());

        if (ConfigData)
        {
            // Apply custom navigation config
            FSlateApplication::Get().SetNavigationConfig(MakeShared<FCustomNavigationConfig>(ConfigData));
            UE_LOG(LogClass, Log, TEXT("Custom Navigation data loaded."));
        }
    }
}

void FCustomSlateNavigationModule::ShutdownModule()
{
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "Game", "Custom Navigation");
    }
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomSlateNavigationModule, CustomSlateNavigation)