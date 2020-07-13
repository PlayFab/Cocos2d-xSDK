#include "HttpRequest.h"
#include "HttpRequesterCURL.h"
#include "PlayFabResultHandler.h"
#include "PlayFabSettings.h"
#include "PlayFabInsightsAPI.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::InsightsModels;

PlayFabInsightsAPI::PlayFabInsightsAPI() {}

void PlayFabInsightsAPI::GetDetails(
    InsightsEmptyRequest& request,
    ProcessApiCallback<InsightsGetDetailsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Insights/GetDetails"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<InsightsGetDetailsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetDetailsResult, userData);
}

void PlayFabInsightsAPI::OnGetDetailsResult(int httpStatus, HttpRequest* request, void* userData)
{
    InsightsGetDetailsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<InsightsGetDetailsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabInsightsAPI::GetLimits(
    InsightsEmptyRequest& request,
    ProcessApiCallback<InsightsGetLimitsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Insights/GetLimits"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<InsightsGetLimitsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLimitsResult, userData);
}

void PlayFabInsightsAPI::OnGetLimitsResult(int httpStatus, HttpRequest* request, void* userData)
{
    InsightsGetLimitsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<InsightsGetLimitsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabInsightsAPI::GetOperationStatus(
    InsightsGetOperationStatusRequest& request,
    ProcessApiCallback<InsightsGetOperationStatusResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Insights/GetOperationStatus"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<InsightsGetOperationStatusResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetOperationStatusResult, userData);
}

void PlayFabInsightsAPI::OnGetOperationStatusResult(int httpStatus, HttpRequest* request, void* userData)
{
    InsightsGetOperationStatusResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<InsightsGetOperationStatusResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabInsightsAPI::GetPendingOperations(
    InsightsGetPendingOperationsRequest& request,
    ProcessApiCallback<InsightsGetPendingOperationsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Insights/GetPendingOperations"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<InsightsGetPendingOperationsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPendingOperationsResult, userData);
}

void PlayFabInsightsAPI::OnGetPendingOperationsResult(int httpStatus, HttpRequest* request, void* userData)
{
    InsightsGetPendingOperationsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<InsightsGetPendingOperationsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabInsightsAPI::SetPerformance(
    InsightsSetPerformanceRequest& request,
    ProcessApiCallback<InsightsOperationResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Insights/SetPerformance"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<InsightsOperationResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetPerformanceResult, userData);
}

void PlayFabInsightsAPI::OnSetPerformanceResult(int httpStatus, HttpRequest* request, void* userData)
{
    InsightsOperationResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<InsightsOperationResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabInsightsAPI::SetStorageRetention(
    InsightsSetStorageRetentionRequest& request,
    ProcessApiCallback<InsightsOperationResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Insights/SetStorageRetention"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<InsightsOperationResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetStorageRetentionResult, userData);
}

void PlayFabInsightsAPI::OnSetStorageRetentionResult(int httpStatus, HttpRequest* request, void* userData)
{
    InsightsOperationResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<InsightsOperationResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}


