Cocos2d-xSDK
============

PlayFab SDKs for c++ based Cocos2d-x game development

# SDKs

This package contains three different versions of the PlayFab SDK. 

PlayFabClientSDK - This version contains only client libraries and is designed for integration with your game client
PlayFabServerSDK - Contains server and admin APIs designed to be called from your custom logic server or build process
PlayFabSDK - Contains all APIs in one SDK.

# Integration

To integrate the PlayFab SDK into your cocos2d-x project, follow these steps. First, determine which version of the SDK you need for your project. From that version, copy the PlayFabSDK directory into your Cocos2d-x project folder. Next you must add the source files, headers and dependencies into your project. Here is the general overview for all Cocos2d-x platforms:

1. Link against libcurl
2. Link against zlib
3. Add the PlayFabSDK/include directory to your project's header search path
4. Add all the source files from playFabSDK/source to your project.

The specifics of how to do this vary by platform:

## Visual Studios 2013

Open your project's property page, and navigate to "Configuration Properties\Linker\Input". At the top of the dialog, change the Configuration drop-down menu to "All Configurations"

Add libcurl_imp.lib;libzlib.lib; to the Additional Dependencies line.

Now click over to "Configuration Properties\C/C++\General"

Add the following paths to the "Additional Include Directories" line:

$(EngineRoot)external\curl\include\win32;$(EngineRoot)external\win32-specific\zlib\include;..\PlayFabSDK\include;

Close the properties. Now right click your project, and select "Add\New Filter...". Name it PlayFab or the like. Right click your new PlayFab filter and select "Add\Existing Items...". Add all the files in "PlayFabSDK\source" to your project.

Compile!

## Android

Edit the file YOURGAME/proj.android/jni/Android.mk

Add the following lines under LOCAL_SRC_FILES:

```
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
				   ../../PlayFabSDK/source/HttpRequest.cpp \
				   ../../PlayFabSDK/source/PlayFabBaseModel.cpp \
				   ../../PlayFabSDK/source/PlayFabClientAPI.cpp \
				   ../../PlayFabSDK/source/PlayFabClientDataModels.cpp \
				   ../../PlayFabSDK/source/PlayFabResultHandler.cpp \
				   ../../PlayFabSDK/source/PlayFabSettings.cpp \
				   ../../PlayFabSDK/source/PlayFabVersion.cpp \
				   ../../PlayFabSDK/source/HttpRequesterCURL.cpp
```

Add the following after LOCAL_C_INCLUDES

```
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/external/curl/include/android
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../PlayFabSDK/include
```

Uncomment the following two lines:

```
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
$(call import-module,network)
```

## XCode

Open up your game's project file in Xcode. 

### Add source files to project

Drag the PlayFabSDK folder into your project in Xcode. Make sure both the iOS and Mac targers are checked (if applicable to your poject).

### Add search headers

Open your project's build settings tab. Find "Search Paths/Header Search Paths". Double click it to open, and add $(SRCROOT)/../PlayFabSDK/include to the end of the search paths.

If you have put the SDK in a different location, edit this path as needed.

For some reason, the Cocos2d-x project template includes the curl headers by default on MacOS, but not iOS. To fix that:

Under Targets, pick your project's iOS Target. Find "Search Paths/Header Search Paths" again, and double click to open. Add $(SRCROOT)/../cocos2d/external/curl/include/ios to the paths.

Compile and enjoy!

# API Docs

Please see http://api.playfab.com/Documentation/ for complete documentation of all PlayFab SDK calls.

