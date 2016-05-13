Cocos2d-xSDK README
========
1. Overview:
----
PlayFab SDKs for c++ based Cocos2d-x game development.

The cocos sdk has not yet been fully tested across all Cocos platforms.  However, this list is improving over time.
* These platforms are tested and should function very well:
 * win32
 * ios_mac
 * android
* These platforms are not tested/working yet:
 * android-studio
 * linux
 * win8.1-universal
 * win10

For Android:
AndroidSdk: targeting Andorid 5.0.1 (API 21).
If you wish to target Android 6.0 (API 23), then you may need this fix:
http://discuss.cocos2d-x.org/t/android-23-6-0-compile-errors-import-org-apache-http-header/26876
This seems to be a case where Google removed code that Cocos relies on.  If you attempt to compile API 23 without the linked fix, you will probably get build errors.

2. Prerequisites:
----
* Users should be very familiar with the topics covered in our [getting started guide](https://playfab.com/docs/getting-started-with-playfab/).

To connect to the PlayFab service, your machine must be running TLS v1.2 or better.
* For Windows, this means Windows 7 and above
* [Official Microsoft Documentation](https://msdn.microsoft.com/en-us/library/windows/desktop/aa380516%28v=vs.85%29.aspx)
* [Support for SSL/TLS protocols on Windows](http://blogs.msdn.com/b/kaushal/archive/2011/10/02/support-for-ssl-tls-protocols-on-windows.aspx)

3. Source Code & Key Repository Components:
----
This package contains three different versions of the PlayFab SDK.

* PlayFabClientSDK - This version contains only client libraries and is designed for integration with your game client
* PlayFabServerSDK - Contains server and admin APIs designed to be called from your custom logic server or build process
* PlayFabSDK - Contains all APIs in one SDK, as well as a unit-test project
* PlayFabSdkExample - A pre-built example using PlayFabSDK, which runs a full set of tests verifying that PlayFab works on the supported platforms.

4. testTitleData.json file required for example unit-test-project
----

This file provides your secret title information to the unit-test project, so it can execute tests in your own PlayFab title

The format is as follows:

    {
    	"titleId": "your Game Title ID, found in the settings/credentials section of your dashboard on the website",
    	"developerSecretKey": "your PlayFab API Secret Key, found in the settings/credentials section of your dashboard on the website - NEVER SHARE THIS KEY WITH PLAYERS",
    	"titleCanUpdateSettings": "false",  // "true" or "false", based on your Allow Client to Post Player Statistics option, found in the settings/general section of your dashboard on the website
    	"userName": "testUser", // Arbitrary username, you can change this to any valid username
    	"userEmail": "your@email.com", // This email address will be bound to the username above
    	"userPassword": "testPassword", // This must be the correct password for the testUser above (if that user does not exist yet, this will be the new password)
    	"characterName": "testCharacter" // Arbitrary characterName, you can change this to any valid characterName
    }

It is read from the hard-coded loction of: TEST_TITLE_DATA_LOC in PlayFabApiTest.h, you can redirect this to an input that matches your file location


5. Troubleshooting:
----
For a complete list of available APIs, check out the [online documentation](http://api.playfab.com/Documentation/).

#### Contact Us
We love to hear from our developer community!
Do you have ideas on how we can make our products and services better?

Our Developer Success Team can assist with answering any questions as well as process any feedback you have about PlayFab services.

[Forums, Support and Knowledge Base](https://community.playfab.com/hc/en-us)

6. Acknowledgements
----
Special thanks to the team at Mingle Games (http://mingle-games.com/) for their assistance in expanding mobile support for this SDK!

7. Copyright and Licensing Information:
----
  Apache License --
  Version 2.0, January 2004
  http://www.apache.org/licenses/

  Full details available within the LICENSE file.

