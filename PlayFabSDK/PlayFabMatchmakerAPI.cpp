#include "HttpRequest.h"
#include "HttpRequesterCURL.h"
#include "PlayFabResultHandler.h"
#include "PlayFabSettings.h"
#include "PlayFabMatchmakerAPI.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::MatchmakerModels;

PlayFabMatchmakerAPI::PlayFabMatchmakerAPI() {}

void PlayFabMatchmakerAPI::AuthUser(
    AuthUserRequest& request,
    ProcessApiCallback<AuthUserResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/AuthUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<AuthUserResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAuthUserResult, userData);
}

void PlayFabMatchmakerAPI::OnAuthUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    AuthUserResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<AuthUserResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMatchmakerAPI::PlayerJoined(
    PlayerJoinedRequest& request,
    ProcessApiCallback<PlayerJoinedResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/PlayerJoined"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<PlayerJoinedResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnPlayerJoinedResult, userData);
}

void PlayFabMatchmakerAPI::OnPlayerJoinedResult(int httpStatus, HttpRequest* request, void* userData)
{
    PlayerJoinedResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<PlayerJoinedResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMatchmakerAPI::PlayerLeft(
    PlayerLeftRequest& request,
    ProcessApiCallback<PlayerLeftResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/PlayerLeft"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<PlayerLeftResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnPlayerLeftResult, userData);
}

void PlayFabMatchmakerAPI::OnPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData)
{
    PlayerLeftResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<PlayerLeftResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMatchmakerAPI::StartGame(
    StartGameRequest& request,
    ProcessApiCallback<StartGameResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/StartGame"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<StartGameResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnStartGameResult, userData);
}

void PlayFabMatchmakerAPI::OnStartGameResult(int httpStatus, HttpRequest* request, void* userData)
{
    StartGameResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<StartGameResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMatchmakerAPI::UserInfo(
    UserInfoRequest& request,
    ProcessApiCallback<UserInfoResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/UserInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UserInfoResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUserInfoResult, userData);
}

void PlayFabMatchmakerAPI::OnUserInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    UserInfoResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UserInfoResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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


