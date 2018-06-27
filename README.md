# Open Virtual Store Development Kit (OVSKit)

This is a XCode static library which includes a bunch of useful functions for developer to facilitate the development of Swift/ObjectiveC program.
Moreover, OVSKit is used to establish the service connection between the OVS-App and OVS-Server, So that you can have a iOS mobile app (as well as Android app) in 10 minutes without programming


## Setup and Install.
You can use the Cocoapod to install the OVSKit. The Podfile is as below, you need to based on your situation and update your Podfile:

```
use_frameworks!
platform :ios, '10.0'
source 'https://github.com/CocoaPods/Specs.git'


target 'OVSApp' do
  pod 'OVSKit',:git => 'https://github.com/OpenVS/OVSKit.git', :branch => '0.0.5'
end

target 'OVSAppTests' do
	inherit! :search_paths
end

```

## Version Feature
* [Version 0.0.6] (https://github.com/OpenVS/OVSKit/tree/0.0.6) 
   - Add OVSCredential for OVSApp 1.0 release
   - Add function to make the log output looks pretty
* [Version 0.0.5] (https://github.com/OpenVS/OVSKit/tree/0.0.5) 
   - Clean useless class and files 


## Common Issues
* if you meet the issue that can not make pod install. and get the error message as below
```
RuntimeError - [Xcodeproj] Unknown object version
```
Please update your gem and cocopod as below:
```
1. $> bundle update
2. $> sudo gem install cocoapods --pre
```


If you want to get more detailed information, please visit: http://www.openvs.org
