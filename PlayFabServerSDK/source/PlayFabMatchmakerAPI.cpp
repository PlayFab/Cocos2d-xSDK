#include "playfab/PlayFabMatchmakerAPI.h"
#include "playfab/HttpRequest.h"
#include "playfab/PlayFabSettings.h"
#include "playfab/PlayFabResultHandler.h"
#include "playfab/HttpRequesterCURL.h"
#include "playfab/PlayFabVersion.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::MatchmakerModels;

IHttpRequester* PlayFabMatchmakerAPI::mHttpRequester = new HttpRequesterCURL();

PlayFabMatchmakerAPI::PlayFabMatchmakerAPI() {}

size_t PlayFabMatchmakerAPI::Update()
{
    return mHttpRequester->UpdateRequests();
}

void PlayFabMatchmakerAPI::AuthUser(
    AuthUserRequest& request,
    ProcessApiCallback<AuthUserResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/AuthUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAuthUserResult, nullptr);
}

void PlayFabMatchmakerAPI::OnAuthUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    AuthUserResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<AuthUserResponse> successCallback = reinterpret_cast<ProcessApiCallback<AuthUserResponse>>(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
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
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnPlayerJoinedResult, nullptr);
}

void PlayFabMatchmakerAPI::OnPlayerJoinedResult(int httpStatus, HttpRequest* request, void* userData)
{
    PlayerJoinedResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<PlayerJoinedResponse> successCallback = reinterpret_cast<ProcessApiCallback<PlayerJoinedResponse>>(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
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
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnPlayerLeftResult, nullptr);
}

void PlayFabMatchmakerAPI::OnPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData)
{
    PlayerLeftResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<PlayerLeftResponse> successCallback = reinterpret_cast<ProcessApiCallback<PlayerLeftResponse>>(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
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
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnStartGameResult, nullptr);
}

void PlayFabMatchmakerAPI::OnStartGameResult(int httpStatus, HttpRequest* request, void* userData)
{
    StartGameResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<StartGameResponse> successCallback = reinterpret_cast<ProcessApiCallback<StartGameResponse>>(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
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
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUserInfoResult, nullptr);
}

void PlayFabMatchmakerAPI::OnUserInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    UserInfoResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UserInfoResponse> successCallback = reinterpret_cast<ProcessApiCallback<UserInfoResponse>>(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
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


