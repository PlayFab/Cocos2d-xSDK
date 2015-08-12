#include "playfab/PlayFabMatchmakerAPI.h"
#include "playfab/HttpRequest.h"
#include "playfab/PlayFabSettings.h"
#include "playfab/PlayFabResultHandler.h"
#include "playfab/HttpRequesterCURL.h"
#include "playfab/PlayFabVersion.h"

#include <string>


using namespace PlayFab;
using namespace PlayFab::MatchmakerModels;

PlayFabMatchmakerAPI::PlayFabMatchmakerAPI()
    : PlayFabMatchmakerAPI(NULL, false)
{
   
}

PlayFabMatchmakerAPI::PlayFabMatchmakerAPI(IHttpRequester* requester, bool ownRequester)
    : mHttpRequester(requester), mOwnsRequester(ownRequester)
{
    if(mHttpRequester == NULL)
    {
        mOwnsRequester = true;
        mHttpRequester = new HttpRequesterCURL();
    }

}



PlayFabMatchmakerAPI::~PlayFabMatchmakerAPI()
{
    if(mOwnsRequester && mHttpRequester != NULL)
    {
        delete mHttpRequester;
        mOwnsRequester = false;
        mHttpRequester = NULL;
    }
}



IHttpRequester* PlayFabMatchmakerAPI::GetRequester(bool relinquishOwnership /* = false*/)
{
    if(relinquishOwnership)
    {
        mOwnsRequester = false;
    }
    return mHttpRequester;
}

size_t PlayFabMatchmakerAPI::Update()
{
    if(mHttpRequester != NULL)
    {
        return mHttpRequester->UpdateRequests();
    }

	return 0;
}




void PlayFabMatchmakerAPI::AuthUser(
    AuthUserRequest& request,
    AuthUserCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/AuthUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAuthUserResult, this);
}

void PlayFabMatchmakerAPI::OnAuthUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    AuthUserResponse outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            AuthUserCallback successCallback = (AuthUserCallback)(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != NULL)
        {
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        }

        if (request->GetErrorCallback() != NULL)
        {
            request->GetErrorCallback()(errorResult, request->GetUserData());
        }
    }

    delete request;
}


void PlayFabMatchmakerAPI::PlayerJoined(
    PlayerJoinedRequest& request,
    PlayerJoinedCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/PlayerJoined"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnPlayerJoinedResult, this);
}

void PlayFabMatchmakerAPI::OnPlayerJoinedResult(int httpStatus, HttpRequest* request, void* userData)
{
    PlayerJoinedResponse outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            PlayerJoinedCallback successCallback = (PlayerJoinedCallback)(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != NULL)
        {
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        }

        if (request->GetErrorCallback() != NULL)
        {
            request->GetErrorCallback()(errorResult, request->GetUserData());
        }
    }

    delete request;
}


void PlayFabMatchmakerAPI::PlayerLeft(
    PlayerLeftRequest& request,
    PlayerLeftCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/PlayerLeft"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnPlayerLeftResult, this);
}

void PlayFabMatchmakerAPI::OnPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData)
{
    PlayerLeftResponse outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            PlayerLeftCallback successCallback = (PlayerLeftCallback)(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != NULL)
        {
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        }

        if (request->GetErrorCallback() != NULL)
        {
            request->GetErrorCallback()(errorResult, request->GetUserData());
        }
    }

    delete request;
}


void PlayFabMatchmakerAPI::StartGame(
    StartGameRequest& request,
    StartGameCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/StartGame"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnStartGameResult, this);
}

void PlayFabMatchmakerAPI::OnStartGameResult(int httpStatus, HttpRequest* request, void* userData)
{
    StartGameResponse outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            StartGameCallback successCallback = (StartGameCallback)(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != NULL)
        {
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        }

        if (request->GetErrorCallback() != NULL)
        {
            request->GetErrorCallback()(errorResult, request->GetUserData());
        }
    }

    delete request;
}


void PlayFabMatchmakerAPI::UserInfo(
    UserInfoRequest& request,
    UserInfoCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Matchmaker/UserInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUserInfoResult, this);
}

void PlayFabMatchmakerAPI::OnUserInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    UserInfoResponse outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UserInfoCallback successCallback = (UserInfoCallback)(request->GetResultCallback());
            successCallback(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != NULL)
        {
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        }

        if (request->GetErrorCallback() != NULL)
        {
            request->GetErrorCallback()(errorResult, request->GetUserData());
        }
    }

    delete request;
}




