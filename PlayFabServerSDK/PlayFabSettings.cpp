#include "PlayFabSettings.h"
#include <HttpRequesterCURL.h>

namespace PlayFab
{
    IHttpRequester* PlayFabSettings::httpRequester = new HttpRequesterCURL();

    const std::string PlayFabSettings::sdkVersion = "0.53.181114";
    const std::string PlayFabSettings::buildIdentifier = "jbuild_cocos2d-xsdk__sdk-slave2016-3_2";
    const std::string PlayFabSettings::versionString = "Cocos2d-xSDK-0.53.181114";

    bool PlayFabSettings::useDevelopmentEnvironment = false;
    std::string PlayFabSettings::serverURL;
    std::string PlayFabSettings::developmentEnvironmentURL = ".playfabsandbox.com";
    std::string PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
    std::string PlayFabSettings::titleId;
    ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;
    std::string PlayFabSettings::entityToken = "";
    std::string PlayFabSettings::developerSecretKey;
    std::string PlayFabSettings::clientSessionTicket = "";
}
