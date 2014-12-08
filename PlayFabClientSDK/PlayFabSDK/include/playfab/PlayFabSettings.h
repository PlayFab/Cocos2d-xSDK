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
		static std::string logicServerURL;
        static std::string titleId;
        static ErrorCallback globalErrorHandler;

        static std::string getURL(const std::string& callPath)
        {
            if (serverURL.length() == 0)
                serverURL = "https://"+titleId+(useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL);
            return serverURL + callPath;
        }
		
		static std::string getLogicURL(const std::string& callPath)
		{
			return logicServerURL + callPath;
		}
		
    };


}
#endif