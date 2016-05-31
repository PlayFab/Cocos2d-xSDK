#include "HttpRequest.h"
#include "HttpRequesterCURL.h"
#include "PlayFabResultHandler.h"
#include "PlayFabSettings.h"
#include "PlayFabVersion.h"
#include "PlayFabClientAPI.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::ClientModels;

std::string PlayFabClientAPI::mUserSessionTicket; // Private, Client-Specific

PlayFabClientAPI::PlayFabClientAPI() {}

void PlayFabClientAPI::GetPhotonAuthenticationToken(
    GetPhotonAuthenticationTokenRequest& request,
    ProcessApiCallback<GetPhotonAuthenticationTokenResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPhotonAuthenticationToken"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPhotonAuthenticationTokenResult, userData);
}

void PlayFabClientAPI::OnGetPhotonAuthenticationTokenResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPhotonAuthenticationTokenResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPhotonAuthenticationTokenResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPhotonAuthenticationTokenResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithAndroidDeviceID(
    LoginWithAndroidDeviceIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithAndroidDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithAndroidDeviceIDResult, userData);
}

void PlayFabClientAPI::OnLoginWithAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithCustomID(
    LoginWithCustomIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithCustomID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithCustomIDResult, userData);
}

void PlayFabClientAPI::OnLoginWithCustomIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithEmailAddress(
    LoginWithEmailAddressRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithEmailAddress"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithEmailAddressResult, userData);
}

void PlayFabClientAPI::OnLoginWithEmailAddressResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithFacebook(
    LoginWithFacebookRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithFacebook"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithFacebookResult, userData);
}

void PlayFabClientAPI::OnLoginWithFacebookResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithGameCenter(
    LoginWithGameCenterRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithGameCenter"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithGameCenterResult, userData);
}

void PlayFabClientAPI::OnLoginWithGameCenterResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithGoogleAccount(
    LoginWithGoogleAccountRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithGoogleAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithGoogleAccountResult, userData);
}

void PlayFabClientAPI::OnLoginWithGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithIOSDeviceID(
    LoginWithIOSDeviceIDRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithIOSDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithIOSDeviceIDResult, userData);
}

void PlayFabClientAPI::OnLoginWithIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithKongregate(
    LoginWithKongregateRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithKongregate"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithKongregateResult, userData);
}

void PlayFabClientAPI::OnLoginWithKongregateResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithPlayFab(
    LoginWithPlayFabRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithPlayFab"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithPlayFabResult, userData);
}

void PlayFabClientAPI::OnLoginWithPlayFabResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithPSN(
    LoginWithPSNRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithPSN"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithPSNResult, userData);
}

void PlayFabClientAPI::OnLoginWithPSNResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithSteam(
    LoginWithSteamRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithSteam"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithSteamResult, userData);
}

void PlayFabClientAPI::OnLoginWithSteamResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LoginWithXbox(
    LoginWithXboxRequest& request,
    ProcessApiCallback<LoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithXbox"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithXboxResult, userData);
}

void PlayFabClientAPI::OnLoginWithXboxResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LoginResult> successCallback = reinterpret_cast<ProcessApiCallback<LoginResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RegisterPlayFabUser(
    RegisterPlayFabUserRequest& request,
    ProcessApiCallback<RegisterPlayFabUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
        request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RegisterPlayFabUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRegisterPlayFabUserResult, userData);
}

void PlayFabClientAPI::OnRegisterPlayFabUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    RegisterPlayFabUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (outResult.SessionTicket.length() > 0)
            (static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;
        MultiStepClientLogin(outResult.SettingsForUser->NeedsAttribution);

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RegisterPlayFabUserResult> successCallback = reinterpret_cast<ProcessApiCallback<RegisterPlayFabUserResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::AddUsernamePassword(
    AddUsernamePasswordRequest& request,
    ProcessApiCallback<AddUsernamePasswordResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AddUsernamePassword"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddUsernamePasswordResult, userData);
}

void PlayFabClientAPI::OnAddUsernamePasswordResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddUsernamePasswordResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<AddUsernamePasswordResult> successCallback = reinterpret_cast<ProcessApiCallback<AddUsernamePasswordResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetAccountInfo(
    GetAccountInfoRequest& request,
    ProcessApiCallback<GetAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetAccountInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetAccountInfoResult, userData);
}

void PlayFabClientAPI::OnGetAccountInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetAccountInfoResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetAccountInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<GetAccountInfoResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(
    GetPlayFabIDsFromFacebookIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayFabIDsFromFacebookIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromFacebookIDsResult, userData);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromFacebookIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayFabIDsFromGameCenterIDs(
    GetPlayFabIDsFromGameCenterIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayFabIDsFromGameCenterIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromGameCenterIDsResult, userData);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromGameCenterIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromGameCenterIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromGameCenterIDsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayFabIDsFromGoogleIDs(
    GetPlayFabIDsFromGoogleIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayFabIDsFromGoogleIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromGoogleIDsResult, userData);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromGoogleIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromGoogleIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromGoogleIDsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayFabIDsFromKongregateIDs(
    GetPlayFabIDsFromKongregateIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayFabIDsFromKongregateIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromKongregateIDsResult, userData);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromKongregateIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromKongregateIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromKongregateIDsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayFabIDsFromPSNAccountIDs(
    GetPlayFabIDsFromPSNAccountIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayFabIDsFromPSNAccountIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromPSNAccountIDsResult, userData);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromPSNAccountIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromPSNAccountIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromPSNAccountIDsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayFabIDsFromSteamIDs(
    GetPlayFabIDsFromSteamIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayFabIDsFromSteamIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromSteamIDsResult, userData);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromSteamIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromSteamIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetUserCombinedInfo(
    GetUserCombinedInfoRequest& request,
    ProcessApiCallback<GetUserCombinedInfoResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserCombinedInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserCombinedInfoResult, userData);
}

void PlayFabClientAPI::OnGetUserCombinedInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserCombinedInfoResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetUserCombinedInfoResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserCombinedInfoResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkAndroidDeviceID(
    LinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<LinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkAndroidDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkAndroidDeviceIDResult, userData);
}

void PlayFabClientAPI::OnLinkAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkAndroidDeviceIDResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkAndroidDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkAndroidDeviceIDResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkCustomID(
    LinkCustomIDRequest& request,
    ProcessApiCallback<LinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkCustomID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkCustomIDResult, userData);
}

void PlayFabClientAPI::OnLinkCustomIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkCustomIDResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkCustomIDResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkCustomIDResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkFacebookAccount(
    LinkFacebookAccountRequest& request,
    ProcessApiCallback<LinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkFacebookAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkFacebookAccountResult, userData);
}

void PlayFabClientAPI::OnLinkFacebookAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkFacebookAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkFacebookAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkFacebookAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkGameCenterAccount(
    LinkGameCenterAccountRequest& request,
    ProcessApiCallback<LinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkGameCenterAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkGameCenterAccountResult, userData);
}

void PlayFabClientAPI::OnLinkGameCenterAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkGameCenterAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkGameCenterAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkGameCenterAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkGoogleAccount(
    LinkGoogleAccountRequest& request,
    ProcessApiCallback<LinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkGoogleAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkGoogleAccountResult, userData);
}

void PlayFabClientAPI::OnLinkGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkGoogleAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkGoogleAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkGoogleAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkIOSDeviceID(
    LinkIOSDeviceIDRequest& request,
    ProcessApiCallback<LinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkIOSDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkIOSDeviceIDResult, userData);
}

void PlayFabClientAPI::OnLinkIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkIOSDeviceIDResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkIOSDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkIOSDeviceIDResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkKongregate(
    LinkKongregateAccountRequest& request,
    ProcessApiCallback<LinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkKongregate"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkKongregateResult, userData);
}

void PlayFabClientAPI::OnLinkKongregateResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkKongregateAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkKongregateAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkKongregateAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkPSNAccount(
    LinkPSNAccountRequest& request,
    ProcessApiCallback<LinkPSNAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkPSNAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkPSNAccountResult, userData);
}

void PlayFabClientAPI::OnLinkPSNAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkPSNAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkPSNAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkPSNAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkSteamAccount(
    LinkSteamAccountRequest& request,
    ProcessApiCallback<LinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkSteamAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkSteamAccountResult, userData);
}

void PlayFabClientAPI::OnLinkSteamAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkSteamAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkSteamAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkSteamAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LinkXboxAccount(
    LinkXboxAccountRequest& request,
    ProcessApiCallback<LinkXboxAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkXboxAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkXboxAccountResult, userData);
}

void PlayFabClientAPI::OnLinkXboxAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkXboxAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LinkXboxAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<LinkXboxAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ReportPlayer(
    ReportPlayerClientRequest& request,
    ProcessApiCallback<ReportPlayerClientResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ReportPlayer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnReportPlayerResult, userData);
}

void PlayFabClientAPI::OnReportPlayerResult(int httpStatus, HttpRequest* request, void* userData)
{
    ReportPlayerClientResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ReportPlayerClientResult> successCallback = reinterpret_cast<ProcessApiCallback<ReportPlayerClientResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::SendAccountRecoveryEmail(
    SendAccountRecoveryEmailRequest& request,
    ProcessApiCallback<SendAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/SendAccountRecoveryEmail"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSendAccountRecoveryEmailResult, userData);
}

void PlayFabClientAPI::OnSendAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData)
{
    SendAccountRecoveryEmailResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<SendAccountRecoveryEmailResult> successCallback = reinterpret_cast<ProcessApiCallback<SendAccountRecoveryEmailResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkAndroidDeviceID(
    UnlinkAndroidDeviceIDRequest& request,
    ProcessApiCallback<UnlinkAndroidDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkAndroidDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkAndroidDeviceIDResult, userData);
}

void PlayFabClientAPI::OnUnlinkAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkAndroidDeviceIDResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkAndroidDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkAndroidDeviceIDResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkCustomID(
    UnlinkCustomIDRequest& request,
    ProcessApiCallback<UnlinkCustomIDResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkCustomID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkCustomIDResult, userData);
}

void PlayFabClientAPI::OnUnlinkCustomIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkCustomIDResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkCustomIDResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkCustomIDResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkFacebookAccount(
    
    ProcessApiCallback<UnlinkFacebookAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkFacebookAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkFacebookAccountResult, userData);
}

void PlayFabClientAPI::OnUnlinkFacebookAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkFacebookAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkFacebookAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkFacebookAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkGameCenterAccount(
    
    ProcessApiCallback<UnlinkGameCenterAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkGameCenterAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkGameCenterAccountResult, userData);
}

void PlayFabClientAPI::OnUnlinkGameCenterAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkGameCenterAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkGameCenterAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkGameCenterAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkGoogleAccount(
    
    ProcessApiCallback<UnlinkGoogleAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkGoogleAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkGoogleAccountResult, userData);
}

void PlayFabClientAPI::OnUnlinkGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkGoogleAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkGoogleAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkGoogleAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkIOSDeviceID(
    UnlinkIOSDeviceIDRequest& request,
    ProcessApiCallback<UnlinkIOSDeviceIDResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkIOSDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkIOSDeviceIDResult, userData);
}

void PlayFabClientAPI::OnUnlinkIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkIOSDeviceIDResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkIOSDeviceIDResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkIOSDeviceIDResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkKongregate(
    
    ProcessApiCallback<UnlinkKongregateAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkKongregate"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkKongregateResult, userData);
}

void PlayFabClientAPI::OnUnlinkKongregateResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkKongregateAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkKongregateAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkKongregateAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkPSNAccount(
    
    ProcessApiCallback<UnlinkPSNAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkPSNAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkPSNAccountResult, userData);
}

void PlayFabClientAPI::OnUnlinkPSNAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkPSNAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkPSNAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkPSNAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkSteamAccount(
    
    ProcessApiCallback<UnlinkSteamAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkSteamAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkSteamAccountResult, userData);
}

void PlayFabClientAPI::OnUnlinkSteamAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkSteamAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkSteamAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkSteamAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlinkXboxAccount(
    UnlinkXboxAccountRequest& request,
    ProcessApiCallback<UnlinkXboxAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkXboxAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkXboxAccountResult, userData);
}

void PlayFabClientAPI::OnUnlinkXboxAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkXboxAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlinkXboxAccountResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlinkXboxAccountResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateUserTitleDisplayName(
    UpdateUserTitleDisplayNameRequest& request,
    ProcessApiCallback<UpdateUserTitleDisplayNameResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateUserTitleDisplayName"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserTitleDisplayNameResult, userData);
}

void PlayFabClientAPI::OnUpdateUserTitleDisplayNameResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserTitleDisplayNameResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateUserTitleDisplayNameResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserTitleDisplayNameResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetFriendLeaderboard(
    GetFriendLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetFriendLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetFriendLeaderboardResult, userData);
}

void PlayFabClientAPI::OnGetFriendLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetFriendLeaderboardAroundCurrentUser(
    GetFriendLeaderboardAroundCurrentUserRequest& request,
    ProcessApiCallback<GetFriendLeaderboardAroundCurrentUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetFriendLeaderboardAroundCurrentUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetFriendLeaderboardAroundCurrentUserResult, userData);
}

void PlayFabClientAPI::OnGetFriendLeaderboardAroundCurrentUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetFriendLeaderboardAroundCurrentUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetFriendLeaderboardAroundCurrentUserResult> successCallback = reinterpret_cast<ProcessApiCallback<GetFriendLeaderboardAroundCurrentUserResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetFriendLeaderboardAroundPlayer(
    GetFriendLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetFriendLeaderboardAroundPlayer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetFriendLeaderboardAroundPlayerResult, userData);
}

void PlayFabClientAPI::OnGetFriendLeaderboardAroundPlayerResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetFriendLeaderboardAroundPlayerResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<GetFriendLeaderboardAroundPlayerResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetLeaderboard(
    GetLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardResult, userData);
}

void PlayFabClientAPI::OnGetLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetLeaderboardAroundCurrentUser(
    GetLeaderboardAroundCurrentUserRequest& request,
    ProcessApiCallback<GetLeaderboardAroundCurrentUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboardAroundCurrentUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardAroundCurrentUserResult, userData);
}

void PlayFabClientAPI::OnGetLeaderboardAroundCurrentUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardAroundCurrentUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetLeaderboardAroundCurrentUserResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardAroundCurrentUserResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetLeaderboardAroundPlayer(
    GetLeaderboardAroundPlayerRequest& request,
    ProcessApiCallback<GetLeaderboardAroundPlayerResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboardAroundPlayer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardAroundPlayerResult, userData);
}

void PlayFabClientAPI::OnGetLeaderboardAroundPlayerResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardAroundPlayerResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetLeaderboardAroundPlayerResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardAroundPlayerResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayerStatistics(
    GetPlayerStatisticsRequest& request,
    ProcessApiCallback<GetPlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayerStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerStatisticsResult, userData);
}

void PlayFabClientAPI::OnGetPlayerStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayerStatisticsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayerStatisticVersions(
    GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayerStatisticVersions"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerStatisticVersionsResult, userData);
}

void PlayFabClientAPI::OnGetPlayerStatisticVersionsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerStatisticVersionsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayerStatisticVersionsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayerStatisticVersionsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetUserData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserDataResult, userData);
}

void PlayFabClientAPI::OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetUserPublisherData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserPublisherDataResult, userData);
}

void PlayFabClientAPI::OnGetUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetUserPublisherReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserPublisherReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserPublisherReadOnlyDataResult, userData);
}

void PlayFabClientAPI::OnGetUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetUserReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserReadOnlyDataResult, userData);
}

void PlayFabClientAPI::OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetUserStatistics(
    
    ProcessApiCallback<GetUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserStatisticsResult, userData);
}

void PlayFabClientAPI::OnGetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetUserStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserStatisticsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdatePlayerStatistics(
    UpdatePlayerStatisticsRequest& request,
    ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdatePlayerStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdatePlayerStatisticsResult, userData);
}

void PlayFabClientAPI::OnUpdatePlayerStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdatePlayerStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdatePlayerStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdatePlayerStatisticsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateUserData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateUserData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserDataResult, userData);
}

void PlayFabClientAPI::OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateUserPublisherData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateUserPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserPublisherDataResult, userData);
}

void PlayFabClientAPI::OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateUserDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateUserStatistics(
    UpdateUserStatisticsRequest& request,
    ProcessApiCallback<UpdateUserStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateUserStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserStatisticsResult, userData);
}

void PlayFabClientAPI::OnUpdateUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateUserStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateUserStatisticsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetCatalogItems(
    GetCatalogItemsRequest& request,
    ProcessApiCallback<GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCatalogItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCatalogItemsResult, userData);
}

void PlayFabClientAPI::OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCatalogItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetCatalogItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCatalogItemsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPublisherData(
    GetPublisherDataRequest& request,
    ProcessApiCallback<GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPublisherDataResult, userData);
}

void PlayFabClientAPI::OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPublisherDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPublisherDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPublisherDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetStoreItems(
    GetStoreItemsRequest& request,
    ProcessApiCallback<GetStoreItemsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetStoreItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetStoreItemsResult, userData);
}

void PlayFabClientAPI::OnGetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetStoreItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetStoreItemsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetStoreItemsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetTitleData(
    GetTitleDataRequest& request,
    ProcessApiCallback<GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetTitleData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetTitleDataResult, userData);
}

void PlayFabClientAPI::OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetTitleDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetTitleDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetTitleNews(
    GetTitleNewsRequest& request,
    ProcessApiCallback<GetTitleNewsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetTitleNews"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetTitleNewsResult, userData);
}

void PlayFabClientAPI::OnGetTitleNewsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleNewsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetTitleNewsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetTitleNewsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::AddUserVirtualCurrency(
    AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AddUserVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddUserVirtualCurrencyResult, userData);
}

void PlayFabClientAPI::OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyUserVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ConfirmPurchase(
    ConfirmPurchaseRequest& request,
    ProcessApiCallback<ConfirmPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ConfirmPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnConfirmPurchaseResult, userData);
}

void PlayFabClientAPI::OnConfirmPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    ConfirmPurchaseResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ConfirmPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ConfirmPurchaseResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ConsumeItem(
    ConsumeItemRequest& request,
    ProcessApiCallback<ConsumeItemResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ConsumeItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnConsumeItemResult, userData);
}

void PlayFabClientAPI::OnConsumeItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    ConsumeItemResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ConsumeItemResult> successCallback = reinterpret_cast<ProcessApiCallback<ConsumeItemResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetCharacterInventory(
    GetCharacterInventoryRequest& request,
    ProcessApiCallback<GetCharacterInventoryResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterInventory"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterInventoryResult, userData);
}

void PlayFabClientAPI::OnGetCharacterInventoryResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterInventoryResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetCharacterInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterInventoryResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPurchase(
    GetPurchaseRequest& request,
    ProcessApiCallback<GetPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPurchaseResult, userData);
}

void PlayFabClientAPI::OnGetPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPurchaseResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<GetPurchaseResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetUserInventory(
    
    ProcessApiCallback<GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserInventory"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserInventoryResult, userData);
}

void PlayFabClientAPI::OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserInventoryResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetUserInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<GetUserInventoryResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::PayForPurchase(
    PayForPurchaseRequest& request,
    ProcessApiCallback<PayForPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/PayForPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnPayForPurchaseResult, userData);
}

void PlayFabClientAPI::OnPayForPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    PayForPurchaseResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<PayForPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<PayForPurchaseResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::PurchaseItem(
    PurchaseItemRequest& request,
    ProcessApiCallback<PurchaseItemResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/PurchaseItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnPurchaseItemResult, userData);
}

void PlayFabClientAPI::OnPurchaseItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    PurchaseItemResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<PurchaseItemResult> successCallback = reinterpret_cast<ProcessApiCallback<PurchaseItemResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RedeemCoupon(
    RedeemCouponRequest& request,
    ProcessApiCallback<RedeemCouponResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RedeemCoupon"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRedeemCouponResult, userData);
}

void PlayFabClientAPI::OnRedeemCouponResult(int httpStatus, HttpRequest* request, void* userData)
{
    RedeemCouponResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RedeemCouponResult> successCallback = reinterpret_cast<ProcessApiCallback<RedeemCouponResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::StartPurchase(
    StartPurchaseRequest& request,
    ProcessApiCallback<StartPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/StartPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnStartPurchaseResult, userData);
}

void PlayFabClientAPI::OnStartPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    StartPurchaseResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<StartPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<StartPurchaseResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::SubtractUserVirtualCurrency(
    SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/SubtractUserVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSubtractUserVirtualCurrencyResult, userData);
}

void PlayFabClientAPI::OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyUserVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ModifyUserVirtualCurrencyResult> successCallback = reinterpret_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlockContainerInstance(
    UnlockContainerInstanceRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlockContainerInstance"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlockContainerInstanceResult, userData);
}

void PlayFabClientAPI::OnUnlockContainerInstanceResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlockContainerItemResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlockContainerItemResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UnlockContainerItem(
    UnlockContainerItemRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlockContainerItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlockContainerItemResult, userData);
}

void PlayFabClientAPI::OnUnlockContainerItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlockContainerItemResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UnlockContainerItemResult> successCallback = reinterpret_cast<ProcessApiCallback<UnlockContainerItemResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::AddFriend(
    AddFriendRequest& request,
    ProcessApiCallback<AddFriendResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AddFriend"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddFriendResult, userData);
}

void PlayFabClientAPI::OnAddFriendResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddFriendResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<AddFriendResult> successCallback = reinterpret_cast<ProcessApiCallback<AddFriendResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetFriendsList(
    GetFriendsListRequest& request,
    ProcessApiCallback<GetFriendsListResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetFriendsList"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetFriendsListResult, userData);
}

void PlayFabClientAPI::OnGetFriendsListResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetFriendsListResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetFriendsListResult> successCallback = reinterpret_cast<ProcessApiCallback<GetFriendsListResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RemoveFriend(
    RemoveFriendRequest& request,
    ProcessApiCallback<RemoveFriendResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RemoveFriend"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemoveFriendResult, userData);
}

void PlayFabClientAPI::OnRemoveFriendResult(int httpStatus, HttpRequest* request, void* userData)
{
    RemoveFriendResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RemoveFriendResult> successCallback = reinterpret_cast<ProcessApiCallback<RemoveFriendResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::SetFriendTags(
    SetFriendTagsRequest& request,
    ProcessApiCallback<SetFriendTagsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/SetFriendTags"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetFriendTagsResult, userData);
}

void PlayFabClientAPI::OnSetFriendTagsResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetFriendTagsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<SetFriendTagsResult> successCallback = reinterpret_cast<ProcessApiCallback<SetFriendTagsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RegisterForIOSPushNotification(
    RegisterForIOSPushNotificationRequest& request,
    ProcessApiCallback<RegisterForIOSPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RegisterForIOSPushNotification"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRegisterForIOSPushNotificationResult, userData);
}

void PlayFabClientAPI::OnRegisterForIOSPushNotificationResult(int httpStatus, HttpRequest* request, void* userData)
{
    RegisterForIOSPushNotificationResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RegisterForIOSPushNotificationResult> successCallback = reinterpret_cast<ProcessApiCallback<RegisterForIOSPushNotificationResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RestoreIOSPurchases(
    RestoreIOSPurchasesRequest& request,
    ProcessApiCallback<RestoreIOSPurchasesResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RestoreIOSPurchases"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRestoreIOSPurchasesResult, userData);
}

void PlayFabClientAPI::OnRestoreIOSPurchasesResult(int httpStatus, HttpRequest* request, void* userData)
{
    RestoreIOSPurchasesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RestoreIOSPurchasesResult> successCallback = reinterpret_cast<ProcessApiCallback<RestoreIOSPurchasesResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ValidateIOSReceipt(
    ValidateIOSReceiptRequest& request,
    ProcessApiCallback<ValidateIOSReceiptResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ValidateIOSReceipt"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnValidateIOSReceiptResult, userData);
}

void PlayFabClientAPI::OnValidateIOSReceiptResult(int httpStatus, HttpRequest* request, void* userData)
{
    ValidateIOSReceiptResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ValidateIOSReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ValidateIOSReceiptResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetCurrentGames(
    CurrentGamesRequest& request,
    ProcessApiCallback<CurrentGamesResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCurrentGames"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCurrentGamesResult, userData);
}

void PlayFabClientAPI::OnGetCurrentGamesResult(int httpStatus, HttpRequest* request, void* userData)
{
    CurrentGamesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<CurrentGamesResult> successCallback = reinterpret_cast<ProcessApiCallback<CurrentGamesResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetGameServerRegions(
    GameServerRegionsRequest& request,
    ProcessApiCallback<GameServerRegionsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGameServerRegions"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGameServerRegionsResult, userData);
}

void PlayFabClientAPI::OnGetGameServerRegionsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GameServerRegionsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GameServerRegionsResult> successCallback = reinterpret_cast<ProcessApiCallback<GameServerRegionsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::Matchmake(
    MatchmakeRequest& request,
    ProcessApiCallback<MatchmakeResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/Matchmake"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnMatchmakeResult, userData);
}

void PlayFabClientAPI::OnMatchmakeResult(int httpStatus, HttpRequest* request, void* userData)
{
    MatchmakeResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<MatchmakeResult> successCallback = reinterpret_cast<ProcessApiCallback<MatchmakeResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::StartGame(
    StartGameRequest& request,
    ProcessApiCallback<StartGameResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/StartGame"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnStartGameResult, userData);
}

void PlayFabClientAPI::OnStartGameResult(int httpStatus, HttpRequest* request, void* userData)
{
    StartGameResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<StartGameResult> successCallback = reinterpret_cast<ProcessApiCallback<StartGameResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::AndroidDevicePushNotificationRegistration(
    AndroidDevicePushNotificationRegistrationRequest& request,
    ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AndroidDevicePushNotificationRegistration"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAndroidDevicePushNotificationRegistrationResult, userData);
}

void PlayFabClientAPI::OnAndroidDevicePushNotificationRegistrationResult(int httpStatus, HttpRequest* request, void* userData)
{
    AndroidDevicePushNotificationRegistrationResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult> successCallback = reinterpret_cast<ProcessApiCallback<AndroidDevicePushNotificationRegistrationResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ValidateGooglePlayPurchase(
    ValidateGooglePlayPurchaseRequest& request,
    ProcessApiCallback<ValidateGooglePlayPurchaseResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ValidateGooglePlayPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnValidateGooglePlayPurchaseResult, userData);
}

void PlayFabClientAPI::OnValidateGooglePlayPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    ValidateGooglePlayPurchaseResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ValidateGooglePlayPurchaseResult> successCallback = reinterpret_cast<ProcessApiCallback<ValidateGooglePlayPurchaseResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LogEvent(
    LogEventRequest& request,
    ProcessApiCallback<LogEventResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LogEvent"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLogEventResult, userData);
}

void PlayFabClientAPI::OnLogEventResult(int httpStatus, HttpRequest* request, void* userData)
{
    LogEventResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LogEventResult> successCallback = reinterpret_cast<ProcessApiCallback<LogEventResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::WriteCharacterEvent(
    WriteClientCharacterEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/WriteCharacterEvent"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnWriteCharacterEventResult, userData);
}

void PlayFabClientAPI::OnWriteCharacterEventResult(int httpStatus, HttpRequest* request, void* userData)
{
    WriteEventResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<WriteEventResponse>>(request->GetResultCallback());
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

void PlayFabClientAPI::WritePlayerEvent(
    WriteClientPlayerEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/WritePlayerEvent"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnWritePlayerEventResult, userData);
}

void PlayFabClientAPI::OnWritePlayerEventResult(int httpStatus, HttpRequest* request, void* userData)
{
    WriteEventResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<WriteEventResponse>>(request->GetResultCallback());
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

void PlayFabClientAPI::WriteTitleEvent(
    WriteTitleEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/WriteTitleEvent"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnWriteTitleEventResult, userData);
}

void PlayFabClientAPI::OnWriteTitleEventResult(int httpStatus, HttpRequest* request, void* userData)
{
    WriteEventResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<WriteEventResponse> successCallback = reinterpret_cast<ProcessApiCallback<WriteEventResponse>>(request->GetResultCallback());
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

void PlayFabClientAPI::AddSharedGroupMembers(
    AddSharedGroupMembersRequest& request,
    ProcessApiCallback<AddSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AddSharedGroupMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddSharedGroupMembersResult, userData);
}

void PlayFabClientAPI::OnAddSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddSharedGroupMembersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<AddSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<AddSharedGroupMembersResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::CreateSharedGroup(
    CreateSharedGroupRequest& request,
    ProcessApiCallback<CreateSharedGroupResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/CreateSharedGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCreateSharedGroupResult, userData);
}

void PlayFabClientAPI::OnCreateSharedGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateSharedGroupResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<CreateSharedGroupResult> successCallback = reinterpret_cast<ProcessApiCallback<CreateSharedGroupResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetSharedGroupData(
    GetSharedGroupDataRequest& request,
    ProcessApiCallback<GetSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetSharedGroupData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetSharedGroupDataResult, userData);
}

void PlayFabClientAPI::OnGetSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetSharedGroupDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetSharedGroupDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RemoveSharedGroupMembers(
    RemoveSharedGroupMembersRequest& request,
    ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RemoveSharedGroupMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemoveSharedGroupMembersResult, userData);
}

void PlayFabClientAPI::OnRemoveSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    RemoveSharedGroupMembersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RemoveSharedGroupMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<RemoveSharedGroupMembersResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateSharedGroupData(
    UpdateSharedGroupDataRequest& request,
    ProcessApiCallback<UpdateSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateSharedGroupData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateSharedGroupDataResult, userData);
}

void PlayFabClientAPI::OnUpdateSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateSharedGroupDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateSharedGroupDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateSharedGroupDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ConsumePSNEntitlements(
    ConsumePSNEntitlementsRequest& request,
    ProcessApiCallback<ConsumePSNEntitlementsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ConsumePSNEntitlements"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnConsumePSNEntitlementsResult, userData);
}

void PlayFabClientAPI::OnConsumePSNEntitlementsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ConsumePSNEntitlementsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ConsumePSNEntitlementsResult> successCallback = reinterpret_cast<ProcessApiCallback<ConsumePSNEntitlementsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RefreshPSNAuthToken(
    RefreshPSNAuthTokenRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RefreshPSNAuthToken"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRefreshPSNAuthTokenResult, userData);
}

void PlayFabClientAPI::OnRefreshPSNAuthTokenResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<EmptyResult> successCallback = reinterpret_cast<ProcessApiCallback<EmptyResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ExecuteCloudScript(
    ExecuteCloudScriptRequest& request,
    ProcessApiCallback<ExecuteCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ExecuteCloudScript"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnExecuteCloudScriptResult, userData);
}

void PlayFabClientAPI::OnExecuteCloudScriptResult(int httpStatus, HttpRequest* request, void* userData)
{
    ExecuteCloudScriptResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ExecuteCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<ExecuteCloudScriptResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetCloudScriptUrl(
    GetCloudScriptUrlRequest& request,
    ProcessApiCallback<GetCloudScriptUrlResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCloudScriptUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCloudScriptUrlResult, userData);
}

void PlayFabClientAPI::OnGetCloudScriptUrlResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCloudScriptUrlResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
if (outResult.Url.length() > 0) PlayFabSettings::logicServerURL = outResult.Url;

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetCloudScriptUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCloudScriptUrlResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RunCloudScript(
    RunCloudScriptRequest& request,
    ProcessApiCallback<RunCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getLogicURL("/Client/RunCloudScript"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRunCloudScriptResult, userData);
}

void PlayFabClientAPI::OnRunCloudScriptResult(int httpStatus, HttpRequest* request, void* userData)
{
    RunCloudScriptResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RunCloudScriptResult> successCallback = reinterpret_cast<ProcessApiCallback<RunCloudScriptResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetContentDownloadUrl(
    GetContentDownloadUrlRequest& request,
    ProcessApiCallback<GetContentDownloadUrlResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetContentDownloadUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetContentDownloadUrlResult, userData);
}

void PlayFabClientAPI::OnGetContentDownloadUrlResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetContentDownloadUrlResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetContentDownloadUrlResult> successCallback = reinterpret_cast<ProcessApiCallback<GetContentDownloadUrlResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetAllUsersCharacters(
    ListUsersCharactersRequest& request,
    ProcessApiCallback<ListUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetAllUsersCharacters"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetAllUsersCharactersResult, userData);
}

void PlayFabClientAPI::OnGetAllUsersCharactersResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListUsersCharactersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ListUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<ListUsersCharactersResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetCharacterLeaderboard(
    GetCharacterLeaderboardRequest& request,
    ProcessApiCallback<GetCharacterLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterLeaderboardResult, userData);
}

void PlayFabClientAPI::OnGetCharacterLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterLeaderboardResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetCharacterLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterLeaderboardResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetCharacterStatistics(
    GetCharacterStatisticsRequest& request,
    ProcessApiCallback<GetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterStatisticsResult, userData);
}

void PlayFabClientAPI::OnGetCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterStatisticsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetLeaderboardAroundCharacter(
    GetLeaderboardAroundCharacterRequest& request,
    ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboardAroundCharacter"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardAroundCharacterResult, userData);
}

void PlayFabClientAPI::OnGetLeaderboardAroundCharacterResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardAroundCharacterResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetLeaderboardAroundCharacterResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardAroundCharacterResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetLeaderboardForUserCharacters(
    GetLeaderboardForUsersCharactersRequest& request,
    ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboardForUserCharacters"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardForUserCharactersResult, userData);
}

void PlayFabClientAPI::OnGetLeaderboardForUserCharactersResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardForUsersCharactersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetLeaderboardForUsersCharactersResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardForUsersCharactersResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GrantCharacterToUser(
    GrantCharacterToUserRequest& request,
    ProcessApiCallback<GrantCharacterToUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GrantCharacterToUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGrantCharacterToUserResult, userData);
}

void PlayFabClientAPI::OnGrantCharacterToUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    GrantCharacterToUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GrantCharacterToUserResult> successCallback = reinterpret_cast<ProcessApiCallback<GrantCharacterToUserResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateCharacterStatistics(
    UpdateCharacterStatisticsRequest& request,
    ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateCharacterStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateCharacterStatisticsResult, userData);
}

void PlayFabClientAPI::OnUpdateCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCharacterStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateCharacterStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateCharacterStatisticsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetCharacterData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterDataResult, userData);
}

void PlayFabClientAPI::OnGetCharacterDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetCharacterReadOnlyData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterReadOnlyDataResult, userData);
}

void PlayFabClientAPI::OnGetCharacterReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetCharacterDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateCharacterData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateCharacterData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateCharacterDataResult, userData);
}

void PlayFabClientAPI::OnUpdateCharacterDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateCharacterDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateCharacterDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ValidateAmazonIAPReceipt(
    ValidateAmazonReceiptRequest& request,
    ProcessApiCallback<ValidateAmazonReceiptResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ValidateAmazonIAPReceipt"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnValidateAmazonIAPReceiptResult, userData);
}

void PlayFabClientAPI::OnValidateAmazonIAPReceiptResult(int httpStatus, HttpRequest* request, void* userData)
{
    ValidateAmazonReceiptResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ValidateAmazonReceiptResult> successCallback = reinterpret_cast<ProcessApiCallback<ValidateAmazonReceiptResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::AcceptTrade(
    AcceptTradeRequest& request,
    ProcessApiCallback<AcceptTradeResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AcceptTrade"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAcceptTradeResult, userData);
}

void PlayFabClientAPI::OnAcceptTradeResult(int httpStatus, HttpRequest* request, void* userData)
{
    AcceptTradeResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<AcceptTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<AcceptTradeResponse>>(request->GetResultCallback());
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

void PlayFabClientAPI::CancelTrade(
    CancelTradeRequest& request,
    ProcessApiCallback<CancelTradeResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/CancelTrade"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCancelTradeResult, userData);
}

void PlayFabClientAPI::OnCancelTradeResult(int httpStatus, HttpRequest* request, void* userData)
{
    CancelTradeResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<CancelTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<CancelTradeResponse>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetPlayerTrades(
    GetPlayerTradesRequest& request,
    ProcessApiCallback<GetPlayerTradesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayerTrades"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerTradesResult, userData);
}

void PlayFabClientAPI::OnGetPlayerTradesResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerTradesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetPlayerTradesResponse> successCallback = reinterpret_cast<ProcessApiCallback<GetPlayerTradesResponse>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetTradeStatus(
    GetTradeStatusRequest& request,
    ProcessApiCallback<GetTradeStatusResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetTradeStatus"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetTradeStatusResult, userData);
}

void PlayFabClientAPI::OnGetTradeStatusResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTradeStatusResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetTradeStatusResponse> successCallback = reinterpret_cast<ProcessApiCallback<GetTradeStatusResponse>>(request->GetResultCallback());
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

void PlayFabClientAPI::OpenTrade(
    OpenTradeRequest& request,
    ProcessApiCallback<OpenTradeResponse> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/OpenTrade"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnOpenTradeResult, userData);
}

void PlayFabClientAPI::OnOpenTradeResult(int httpStatus, HttpRequest* request, void* userData)
{
    OpenTradeResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<OpenTradeResponse> successCallback = reinterpret_cast<ProcessApiCallback<OpenTradeResponse>>(request->GetResultCallback());
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

void PlayFabClientAPI::AttributeInstall(
    AttributeInstallRequest& request,
    ProcessApiCallback<AttributeInstallResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AttributeInstall"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAttributeInstallResult, userData);
}

void PlayFabClientAPI::OnAttributeInstallResult(int httpStatus, HttpRequest* request, void* userData)
{
    AttributeInstallResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        // Modify advertisingIdType:  Prevents us from sending the id multiple times, and allows automated tests to determine id was sent successfully
        PlayFabSettings::advertisingIdType += "_Successful";

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<AttributeInstallResult> successCallback = reinterpret_cast<ProcessApiCallback<AttributeInstallResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ApproveGuildRoleChange(
    ApproveGuildRoleChangeRequest& request,
    ProcessApiCallback<ApproveGuildRoleChangeResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ApproveGuildRoleChange"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnApproveGuildRoleChangeResult, userData);
}

void PlayFabClientAPI::OnApproveGuildRoleChangeResult(int httpStatus, HttpRequest* request, void* userData)
{
    ApproveGuildRoleChangeResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ApproveGuildRoleChangeResult> successCallback = reinterpret_cast<ProcessApiCallback<ApproveGuildRoleChangeResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ChangeGuildMemberRole(
    ChangeGuildMemberRoleRequest& request,
    ProcessApiCallback<ChangeGuildMemberRoleResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ChangeGuildMemberRole"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnChangeGuildMemberRoleResult, userData);
}

void PlayFabClientAPI::OnChangeGuildMemberRoleResult(int httpStatus, HttpRequest* request, void* userData)
{
    ChangeGuildMemberRoleResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ChangeGuildMemberRoleResult> successCallback = reinterpret_cast<ProcessApiCallback<ChangeGuildMemberRoleResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::CreateGuild(
    CreateGuildRequest& request,
    ProcessApiCallback<CreateGuildResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/CreateGuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCreateGuildResult, userData);
}

void PlayFabClientAPI::OnCreateGuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateGuildResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<CreateGuildResult> successCallback = reinterpret_cast<ProcessApiCallback<CreateGuildResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::DeleteGuild(
    DeleteGuildRequest& request,
    ProcessApiCallback<DeleteGuildResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/DeleteGuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteGuildResult, userData);
}

void PlayFabClientAPI::OnDeleteGuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    DeleteGuildResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<DeleteGuildResult> successCallback = reinterpret_cast<ProcessApiCallback<DeleteGuildResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::DenyGuildRoleChange(
    DenyGuildRoleChangeRequest& request,
    ProcessApiCallback<DenyGuildRoleChangeResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/DenyGuildRoleChange"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDenyGuildRoleChangeResult, userData);
}

void PlayFabClientAPI::OnDenyGuildRoleChangeResult(int httpStatus, HttpRequest* request, void* userData)
{
    DenyGuildRoleChangeResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<DenyGuildRoleChangeResult> successCallback = reinterpret_cast<ProcessApiCallback<DenyGuildRoleChangeResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetGuildData(
    GetGuildDataRequest& request,
    ProcessApiCallback<GetGuildDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGuildData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGuildDataResult, userData);
}

void PlayFabClientAPI::OnGetGuildDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGuildDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetGuildDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetGuildDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetGuildInventory(
    GetGuildInventoryRequest& request,
    ProcessApiCallback<GetGuildInventoryResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGuildInventory"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGuildInventoryResult, userData);
}

void PlayFabClientAPI::OnGetGuildInventoryResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGuildInventoryResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetGuildInventoryResult> successCallback = reinterpret_cast<ProcessApiCallback<GetGuildInventoryResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetGuildMembershipLeaderboard(
    GetGuildMembershipLeaderboardRequest& request,
    ProcessApiCallback<GetGuildMembershipLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGuildMembershipLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGuildMembershipLeaderboardResult, userData);
}

void PlayFabClientAPI::OnGetGuildMembershipLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGuildMembershipLeaderboardResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetGuildMembershipLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<GetGuildMembershipLeaderboardResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetGuildReadOnlyData(
    GetGuildDataRequest& request,
    ProcessApiCallback<GetGuildDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGuildReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGuildReadOnlyDataResult, userData);
}

void PlayFabClientAPI::OnGetGuildReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGuildDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetGuildDataResult> successCallback = reinterpret_cast<ProcessApiCallback<GetGuildDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetGuildsLeaderboard(
    GetGuildsLeaderboardRequest& request,
    ProcessApiCallback<GetGuildsLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGuildsLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGuildsLeaderboardResult, userData);
}

void PlayFabClientAPI::OnGetGuildsLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGuildsLeaderboardResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetGuildsLeaderboardResult> successCallback = reinterpret_cast<ProcessApiCallback<GetGuildsLeaderboardResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetGuildsLeaderboardAroundGuild(
    GetGuildsLeaderboardAroundGuildRequest& request,
    ProcessApiCallback<GetGuildsLeaderboardAroundGuildResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGuildsLeaderboardAroundGuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGuildsLeaderboardAroundGuildResult, userData);
}

void PlayFabClientAPI::OnGetGuildsLeaderboardAroundGuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGuildsLeaderboardAroundGuildResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetGuildsLeaderboardAroundGuildResult> successCallback = reinterpret_cast<ProcessApiCallback<GetGuildsLeaderboardAroundGuildResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetGuildStatistics(
    GetGuildStatisticsRequest& request,
    ProcessApiCallback<GetGuildStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGuildStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGuildStatisticsResult, userData);
}

void PlayFabClientAPI::OnGetGuildStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGuildStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetGuildStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetGuildStatisticsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::GetLeaderboardOfPlayersGuilds(
    GetLeaderboardOfPlayersGuildsRequest& request,
    ProcessApiCallback<GetLeaderboardOfPlayersGuildsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboardOfPlayersGuilds"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardOfPlayersGuildsResult, userData);
}

void PlayFabClientAPI::OnGetLeaderboardOfPlayersGuildsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardOfPlayersGuildsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<GetLeaderboardOfPlayersGuildsResult> successCallback = reinterpret_cast<ProcessApiCallback<GetLeaderboardOfPlayersGuildsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::LeaveGuild(
    LeaveGuildRequest& request,
    ProcessApiCallback<LeaveGuildResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LeaveGuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLeaveGuildResult, userData);
}

void PlayFabClientAPI::OnLeaveGuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    LeaveGuildResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<LeaveGuildResult> successCallback = reinterpret_cast<ProcessApiCallback<LeaveGuildResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ListGuildMembers(
    ListGuildMembersRequest& request,
    ProcessApiCallback<ListGuildMembersResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ListGuildMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListGuildMembersResult, userData);
}

void PlayFabClientAPI::OnListGuildMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListGuildMembersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ListGuildMembersResult> successCallback = reinterpret_cast<ProcessApiCallback<ListGuildMembersResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ListPendingGuildRoleChangeRequests(
    ListPendingGuildRoleChangeRequestsRequest& request,
    ProcessApiCallback<ListPendingGuildRoleChangeRequestsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ListPendingGuildRoleChangeRequests"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListPendingGuildRoleChangeRequestsResult, userData);
}

void PlayFabClientAPI::OnListPendingGuildRoleChangeRequestsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListPendingGuildRoleChangeRequestsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ListPendingGuildRoleChangeRequestsResult> successCallback = reinterpret_cast<ProcessApiCallback<ListPendingGuildRoleChangeRequestsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::ListPlayerGuildMemberships(
    
    ProcessApiCallback<ListPlayerGuildMembershipsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ListPlayerGuildMemberships"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListPlayerGuildMembershipsResult, userData);
}

void PlayFabClientAPI::OnListPlayerGuildMembershipsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListPlayerGuildMembershipsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<ListPlayerGuildMembershipsResult> successCallback = reinterpret_cast<ProcessApiCallback<ListPlayerGuildMembershipsResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RemoveGuildMember(
    RemoveGuildMemberRequest& request,
    ProcessApiCallback<RemoveGuildMemberResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RemoveGuildMember"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemoveGuildMemberResult, userData);
}

void PlayFabClientAPI::OnRemoveGuildMemberResult(int httpStatus, HttpRequest* request, void* userData)
{
    RemoveGuildMemberResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RemoveGuildMemberResult> successCallback = reinterpret_cast<ProcessApiCallback<RemoveGuildMemberResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::RequestGuildRoleChange(
    RequestGuildRoleChangeRequest& request,
    ProcessApiCallback<RequestGuildRoleChangeResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RequestGuildRoleChange"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRequestGuildRoleChangeResult, userData);
}

void PlayFabClientAPI::OnRequestGuildRoleChangeResult(int httpStatus, HttpRequest* request, void* userData)
{
    RequestGuildRoleChangeResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<RequestGuildRoleChangeResult> successCallback = reinterpret_cast<ProcessApiCallback<RequestGuildRoleChangeResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateGuildData(
    UpdateGuildDataRequest& request,
    ProcessApiCallback<UpdateGuildDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateGuildData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateGuildDataResult, userData);
}

void PlayFabClientAPI::OnUpdateGuildDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateGuildDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateGuildDataResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateGuildDataResult>>(request->GetResultCallback());
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

void PlayFabClientAPI::UpdateGuildStatistics(
    UpdateGuildStatisticsRequest& request,
    ProcessApiCallback<UpdateGuildStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateGuildStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-Authorization", mUserSessionTicket);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateGuildStatisticsResult, userData);
}

void PlayFabClientAPI::OnUpdateGuildStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateGuildStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ProcessApiCallback<UpdateGuildStatisticsResult> successCallback = reinterpret_cast<ProcessApiCallback<UpdateGuildStatisticsResult>>(request->GetResultCallback());
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

bool PlayFabClientAPI::IsClientLoggedIn()
{
    return !mUserSessionTicket.empty();
}

void PlayFabClientAPI::MultiStepClientLogin(bool needsAttribution)
{
    if (needsAttribution && !PlayFabSettings::disableAdvertising && PlayFabSettings::advertisingIdType.length() > 0 && PlayFabSettings::advertisingIdValue.length() > 0)
    {
        AttributeInstallRequest request;
        if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_IDFA)
            request.Idfa = PlayFabSettings::advertisingIdValue;
        else if (PlayFabSettings::advertisingIdType == PlayFabSettings::AD_TYPE_ANDROID_ID)
            request.Android_Id = PlayFabSettings::advertisingIdValue;
        else
            return;
        AttributeInstall(request, nullptr, nullptr);
    }
}
