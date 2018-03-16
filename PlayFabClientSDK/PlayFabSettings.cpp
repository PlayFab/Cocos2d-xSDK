#include "PlayFabSettings.h"
#include <HttpRequesterCURL.h>

namespace PlayFab
{
    IHttpRequester* PlayFabSettings::httpRequester = new HttpRequesterCURL();

    const std::string PlayFabSettings::sdkVersion = "0.38.180316";
    const std::string PlayFabSettings::buildIdentifier = "jbuild_cocos2d-xsdk_1";
    const std::string PlayFabSettings::versionString = "Cocos2d-xSDK-0.38.180316";

    bool PlayFabSettings::useDevelopmentEnvironment = false;
    std::string PlayFabSettings::serverURL;
    std::string PlayFabSettings::developmentEnvironmentURL = ".playfabsandbox.com";
    std::string PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
    std::string PlayFabSettings::titleId;
    ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;
    std::string PlayFabSettings::entityToken = "";
    std::string PlayFabSettings::clientSessionTicket = "";
    std::string PlayFabSettings::advertisingIdType = "";
    std::string PlayFabSettings::advertisingIdValue = "";

    bool PlayFabSettings::disableAdvertising = false;
    const std::string PlayFabSettings::AD_TYPE_IDFA = "Idfa";
    const std::string PlayFabSettings::AD_TYPE_ANDROID_ID = "Adid";
}
