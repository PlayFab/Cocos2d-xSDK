#include "PlayFabSettings.h"
#include <string>

namespace PlayFab
{
    bool PlayFabSettings::useDevelopmentEnvironment = false;
    std::string PlayFabSettings::serverURL;
    std::string PlayFabSettings::developmentEnvironmentURL = ".playfabsandbox.com";
    std::string PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
    std::string PlayFabSettings::titleId;
    ErrorCallback PlayFabSettings::globalErrorHandler = nullptr;
    std::string PlayFabSettings::logicServerURL = "";
    std::string PlayFabSettings::advertisingIdType = "";
    std::string PlayFabSettings::advertisingIdValue = "";

    bool PlayFabSettings::disableAdvertising = false;
    const std::string PlayFabSettings::AD_TYPE_IDFA = "Idfa";
    const std::string PlayFabSettings::AD_TYPE_ANDROID_ID = "Android_Id";
}