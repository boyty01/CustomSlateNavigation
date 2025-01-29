# Usage

Create a Data Asset from Custom Navigation Class:

![image](https://github.com/user-attachments/assets/260b9106-9e9e-4dde-8018-26be9bb085f6)

Adjust the keys you want to modify for keyboard and/or gamepad:

![image](https://github.com/user-attachments/assets/e2e68740-e9c0-4873-9210-5a7be16ee9e3)

Assign custom navigation data asset in project settings under Game->Custom Slate Navigation
![image](https://github.com/user-attachments/assets/6fd3675b-6ad6-498c-ba9d-12bf657cd993)

Restart the editor.

## Limitations

Custom Navigation data only accepts single key overrides for individual UINavigation and UINavigationAction's.  All default configs are removed if valid custom data is specified. To support multiple keys for a single input device, you'll need to customise the source code to handle arrays instead of individual values per device action property.  
