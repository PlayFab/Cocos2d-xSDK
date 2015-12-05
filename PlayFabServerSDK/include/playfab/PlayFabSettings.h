#ifndef PLAYFAB_PLAYFABSETTINGS_H_
#define PLAYFAB_PLAYFABSETTINGS_H_

#include <string>
#include "playfab/PlayFabError.h"

namespace PlayFab
{
    class PlayFabSettings
    {
    public:
        static bool useDevelopmentEnvironment;
        static std::string serverURL;
        static std::string developmentEnvironmentURL;
        static std::string productionEnvironmentURL;
        static std::string titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        static ErrorCallback globalErrorHandler;
        static std::string developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)

        static std::string getURL(const std::string& callPath)
        {
            if (serverURL.length() == 0)
                serverURL = "https://"+titleId+(useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL);
            return serverURL + callPath;
        }
    };
}
#endif
