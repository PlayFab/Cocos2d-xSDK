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
        static void ExecuteFunction(CloudScriptModels::ExecuteFunctionRequest& request, ProcessApiCallback<CloudScriptModels::ExecuteFunctionResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListFunctions(ProcessApiCallback<CloudScriptModels::ListFunctionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListHttpFunctions(ProcessApiCallback<CloudScriptModels::ListHttpFunctionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListQueuedFunctions(ProcessApiCallback<CloudScriptModels::ListQueuedFunctionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PostFunctionResultForEntityTriggeredAction(CloudScriptModels::PostFunctionResultForEntityTriggeredActionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PostFunctionResultForFunctionExecution(CloudScriptModels::PostFunctionResultForFunctionExecutionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PostFunctionResultForPlayerTriggeredAction(CloudScriptModels::PostFunctionResultForPlayerTriggeredActionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PostFunctionResultForScheduledTask(CloudScriptModels::PostFunctionResultForScheduledTaskRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RegisterHttpFunction(CloudScriptModels::RegisterHttpFunctionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RegisterQueuedFunction(CloudScriptModels::RegisterQueuedFunctionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnregisterFunction(CloudScriptModels::UnregisterFunctionRequest& request, ProcessApiCallback<CloudScriptModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabCloudScriptAPI();

        // ------------ Generated result handlers
        static void OnExecuteEntityCloudScriptResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnExecuteFunctionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListFunctionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListHttpFunctionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListQueuedFunctionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPostFunctionResultForEntityTriggeredActionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPostFunctionResultForFunctionExecutionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPostFunctionResultForPlayerTriggeredActionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPostFunctionResultForScheduledTaskResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRegisterHttpFunctionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRegisterQueuedFunctionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnregisterFunctionResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
