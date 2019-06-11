#include "HttpRequest.h"
#include "HttpRequesterCURL.h"
#include "PlayFabResultHandler.h"
#include "PlayFabSettings.h"
#include "PlayFabAuthenticationAPI.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::AuthenticationModels;

PlayFabAuthenticationAPI::PlayFabAuthenticationAPI() {}

void PlayFabAuthenticationAPI::GetEntityToken(
    GetEntityTokenRequest& request,
    ProcessApiCallback<GetEntityTokenResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    std::string authKey, authValue;
    if (PlayFabSettings::entityToken.length() > 0) {
        authKey = "X-EntityToken"; authValue = PlayFabSettings::entityToken;
    } else if (PlayFabSettings::clientSessionTicket.length() > 0) {
        authKey = "X-Authorization"; authValue = PlayFabSettings::clientSessionTicket;
    } else if (PlayFabSettings::developerSecretKey.length() > 0) {
        authKey = "X-SecretKey"; authValue = PlayFabSettings::developerSecretKey;
    }
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Authentication/GetEntityToken"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader(authKey, authValue);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetEntityTokenResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetEntityTokenResult, userData);
}

void PlayFabAuthenticationAPI::OnGetEntityTokenResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetEntityTokenResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.EntityToken.length() > 0)
            PlayFabSettings::entityToken = outResult.EntityToken;
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetEntityTokenResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabAuthenticationAPI::ValidateEntityToken(
    ValidateEntityTokenRequest& request,
    ProcessApiCallback<ValidateEntityTokenResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Authentication/ValidateEntityToken"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ValidateEntityTokenResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnValidateEntityTokenResult, userData);
}

void PlayFabAuthenticationAPI::OnValidateEntityTokenResult(int httpStatus, HttpRequest* request, void* userData)
{
    ValidateEntityTokenResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ValidateEntityTokenResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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


