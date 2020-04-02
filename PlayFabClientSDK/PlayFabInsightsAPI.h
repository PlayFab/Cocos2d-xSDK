#ifndef PLAYFAB_INSIGHTSAPI_H_
#define PLAYFAB_INSIGHTSAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabInsightsDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabInsightsAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void GetDetails(ProcessApiCallback<InsightsModels::InsightsGetDetailsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLimits(ProcessApiCallback<InsightsModels::InsightsGetLimitsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetOperationStatus(InsightsModels::InsightsGetOperationStatusRequest& request, ProcessApiCallback<InsightsModels::InsightsGetOperationStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPendingOperations(InsightsModels::InsightsGetPendingOperationsRequest& request, ProcessApiCallback<InsightsModels::InsightsGetPendingOperationsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetPerformance(InsightsModels::InsightsSetPerformanceRequest& request, ProcessApiCallback<InsightsModels::InsightsOperationResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetStorageRetention(InsightsModels::InsightsSetStorageRetentionRequest& request, ProcessApiCallback<InsightsModels::InsightsOperationResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabInsightsAPI();

        // ------------ Generated result handlers
        static void OnGetDetailsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLimitsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetOperationStatusResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPendingOperationsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetPerformanceResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetStorageRetentionResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
