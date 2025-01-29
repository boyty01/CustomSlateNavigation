# Usage

Create a Data Asset from Custom Navigation Class:

![image](https://github.com/user-attachments/assets/260b9106-9e9e-4dde-8018-26be9bb085f6)

Adjust the keys you want to modify for keyboard and/or gamepad:

![image](https://github.com/user-attachments/assets/cf6a1345-884b-4c66-9fb0-0c45aea5af98)


Assign custom navigation data asset in project settings under Game->Custom Slate Navigation
![image](https://github.com/user-attachments/assets/6fd3675b-6ad6-498c-ba9d-12bf657cd993)

Restart the editor.

## Notes

### Virtual keys for non-keyboard input
By default, gamepad settings will not add custom Accept or Back key bindings to maintain support for multi-platform layouts using Virtual_Accept and Virtual_Back inputs.  If you're planning to support different platforms and input devices then it's recommended to leave this as is, if you want to explicitly set the gamepad button for Virtual keys then unsetting bKeepVirtualKeyBindings under gamepad navigation will allow you to set the keys.

### Replaces all navigation behavior by default
Custom navigation completely replaces the default navigation inputs, so if you want to keep any default behavior, you'll need to explicitly add it to the data asset.

### Settings are applied on startup
Navigation settings are applied on module startup so any changes made to the settings won't be reflected until you restart the editor/game. 

