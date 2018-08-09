#ifndef PLAYFAB_CLOUDSCRIPTAPI_H_
#define PLAYFAB_CLOUDSCRIPTAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabCloudScriptDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabCloudScriptAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void ExecuteEntityCloudScript(CloudScriptModels::ExecuteEntityCloudScriptRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabCloudScriptAPI();

        // ------------ Generated result handlers
        static void OnExecuteEntityCloudScriptResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
