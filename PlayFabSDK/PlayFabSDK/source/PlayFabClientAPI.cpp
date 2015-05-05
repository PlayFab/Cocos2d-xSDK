#include "playfab/PlayFabClientAPI.h"
#include "playfab/HttpRequest.h"
#include "playfab/PlayFabSettings.h"
#include "playfab/PlayFabResultHandler.h"
#include "playfab/HttpRequesterCURL.h"
#include "playfab/PlayFabVersion.h"

#include <string>


using namespace PlayFab;
using namespace PlayFab::ClientModels;

PlayFabClientAPI::PlayFabClientAPI()
    : PlayFabClientAPI(NULL, false)
{
   
}

PlayFabClientAPI::PlayFabClientAPI(IHttpRequester* requester, bool ownRequester)
    : mHttpRequester(requester), mOwnsRequester(ownRequester)
{
    if(mHttpRequester == NULL)
    {
        mOwnsRequester = true;
        mHttpRequester = new HttpRequesterCURL();
    }

}



PlayFabClientAPI::~PlayFabClientAPI()
{
    if(mOwnsRequester && mHttpRequester != NULL)
    {
        delete mHttpRequester;
        mOwnsRequester = false;
        mHttpRequester = NULL;
    }
}



IHttpRequester* PlayFabClientAPI::GetRequester(bool relinquishOwnership /* = false*/)
{
    if(relinquishOwnership)
    {
        mOwnsRequester = false;
    }
    return mHttpRequester;
}

void PlayFabClientAPI::Update()
{
    if(mHttpRequester != NULL)
    {
        mHttpRequester->UpdateRequests();
    }
}


void PlayFabClientAPI::GetPhotonAuthenticationToken(
    GetPhotonAuthenticationTokenRequest& request,
    GetPhotonAuthenticationTokenCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPhotonAuthenticationToken"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetPhotonAuthenticationTokenResult, this);
}

void PlayFabClientAPI::OnGetPhotonAuthenticationTokenResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPhotonAuthenticationTokenResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetPhotonAuthenticationTokenCallback successCallback = (GetPhotonAuthenticationTokenCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LoginWithAndroidDeviceID(
    LoginWithAndroidDeviceIDRequest& request,
    LoginWithAndroidDeviceIDCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
		request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithAndroidDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLoginWithAndroidDeviceIDResult, this);
}

void PlayFabClientAPI::OnLoginWithAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.SessionTicket.length() > 0)
			(static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;

        if (request->GetResultCallback() != NULL)
        {
            LoginWithAndroidDeviceIDCallback successCallback = (LoginWithAndroidDeviceIDCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LoginWithEmailAddress(
    LoginWithEmailAddressRequest& request,
    LoginWithEmailAddressCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
		request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithEmailAddress"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLoginWithEmailAddressResult, this);
}

void PlayFabClientAPI::OnLoginWithEmailAddressResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.SessionTicket.length() > 0)
			(static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;

        if (request->GetResultCallback() != NULL)
        {
            LoginWithEmailAddressCallback successCallback = (LoginWithEmailAddressCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LoginWithFacebook(
    LoginWithFacebookRequest& request,
    LoginWithFacebookCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
		request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithFacebook"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLoginWithFacebookResult, this);
}

void PlayFabClientAPI::OnLoginWithFacebookResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.SessionTicket.length() > 0)
			(static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;

        if (request->GetResultCallback() != NULL)
        {
            LoginWithFacebookCallback successCallback = (LoginWithFacebookCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LoginWithGoogleAccount(
    LoginWithGoogleAccountRequest& request,
    LoginWithGoogleAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
		request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithGoogleAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLoginWithGoogleAccountResult, this);
}

void PlayFabClientAPI::OnLoginWithGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.SessionTicket.length() > 0)
			(static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;

        if (request->GetResultCallback() != NULL)
        {
            LoginWithGoogleAccountCallback successCallback = (LoginWithGoogleAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LoginWithIOSDeviceID(
    LoginWithIOSDeviceIDRequest& request,
    LoginWithIOSDeviceIDCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
		request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithIOSDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLoginWithIOSDeviceIDResult, this);
}

void PlayFabClientAPI::OnLoginWithIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.SessionTicket.length() > 0)
			(static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;

        if (request->GetResultCallback() != NULL)
        {
            LoginWithIOSDeviceIDCallback successCallback = (LoginWithIOSDeviceIDCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LoginWithPlayFab(
    LoginWithPlayFabRequest& request,
    LoginWithPlayFabCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
		request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithPlayFab"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLoginWithPlayFabResult, this);
}

void PlayFabClientAPI::OnLoginWithPlayFabResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.SessionTicket.length() > 0)
			(static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;

        if (request->GetResultCallback() != NULL)
        {
            LoginWithPlayFabCallback successCallback = (LoginWithPlayFabCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LoginWithSteam(
    LoginWithSteamRequest& request,
    LoginWithSteamCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
		request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LoginWithSteam"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLoginWithSteamResult, this);
}

void PlayFabClientAPI::OnLoginWithSteamResult(int httpStatus, HttpRequest* request, void* userData)
{
    LoginResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.SessionTicket.length() > 0)
			(static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;

        if (request->GetResultCallback() != NULL)
        {
            LoginWithSteamCallback successCallback = (LoginWithSteamCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::RegisterPlayFabUser(
    RegisterPlayFabUserRequest& request,
    RegisterPlayFabUserCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    if (PlayFabSettings::titleId.length() > 0)
		request.TitleId = PlayFabSettings::titleId;
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RegisterPlayFabUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRegisterPlayFabUserResult, this);
}

void PlayFabClientAPI::OnRegisterPlayFabUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    RegisterPlayFabUserResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.SessionTicket.length() > 0)
			(static_cast<PlayFabClientAPI*>(userData))->mUserSessionTicket = outResult.SessionTicket;

        if (request->GetResultCallback() != NULL)
        {
            RegisterPlayFabUserCallback successCallback = (RegisterPlayFabUserCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::AddUsernamePassword(
    AddUsernamePasswordRequest& request,
    AddUsernamePasswordCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AddUsernamePassword"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAddUsernamePasswordResult, this);
}

void PlayFabClientAPI::OnAddUsernamePasswordResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddUsernamePasswordResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            AddUsernamePasswordCallback successCallback = (AddUsernamePasswordCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetAccountInfo(
    GetAccountInfoRequest& request,
    GetAccountInfoCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetAccountInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetAccountInfoResult, this);
}

void PlayFabClientAPI::OnGetAccountInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetAccountInfoResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetAccountInfoCallback successCallback = (GetAccountInfoCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetPlayFabIDsFromFacebookIDs(
    GetPlayFabIDsFromFacebookIDsRequest& request,
    GetPlayFabIDsFromFacebookIDsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPlayFabIDsFromFacebookIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromFacebookIDsResult, this);
}

void PlayFabClientAPI::OnGetPlayFabIDsFromFacebookIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromFacebookIDsResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetPlayFabIDsFromFacebookIDsCallback successCallback = (GetPlayFabIDsFromFacebookIDsCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetUserCombinedInfo(
    GetUserCombinedInfoRequest& request,
    GetUserCombinedInfoCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserCombinedInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserCombinedInfoResult, this);
}

void PlayFabClientAPI::OnGetUserCombinedInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserCombinedInfoResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetUserCombinedInfoCallback successCallback = (GetUserCombinedInfoCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LinkAndroidDeviceID(
    LinkAndroidDeviceIDRequest& request,
    LinkAndroidDeviceIDCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkAndroidDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLinkAndroidDeviceIDResult, this);
}

void PlayFabClientAPI::OnLinkAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkAndroidDeviceIDResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            LinkAndroidDeviceIDCallback successCallback = (LinkAndroidDeviceIDCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LinkFacebookAccount(
    LinkFacebookAccountRequest& request,
    LinkFacebookAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkFacebookAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLinkFacebookAccountResult, this);
}

void PlayFabClientAPI::OnLinkFacebookAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkFacebookAccountResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            LinkFacebookAccountCallback successCallback = (LinkFacebookAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LinkGameCenterAccount(
    LinkGameCenterAccountRequest& request,
    LinkGameCenterAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkGameCenterAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLinkGameCenterAccountResult, this);
}

void PlayFabClientAPI::OnLinkGameCenterAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkGameCenterAccountResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            LinkGameCenterAccountCallback successCallback = (LinkGameCenterAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LinkGoogleAccount(
    LinkGoogleAccountRequest& request,
    LinkGoogleAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkGoogleAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLinkGoogleAccountResult, this);
}

void PlayFabClientAPI::OnLinkGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkGoogleAccountResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            LinkGoogleAccountCallback successCallback = (LinkGoogleAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LinkIOSDeviceID(
    LinkIOSDeviceIDRequest& request,
    LinkIOSDeviceIDCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkIOSDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLinkIOSDeviceIDResult, this);
}

void PlayFabClientAPI::OnLinkIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkIOSDeviceIDResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            LinkIOSDeviceIDCallback successCallback = (LinkIOSDeviceIDCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LinkSteamAccount(
    LinkSteamAccountRequest& request,
    LinkSteamAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LinkSteamAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLinkSteamAccountResult, this);
}

void PlayFabClientAPI::OnLinkSteamAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkSteamAccountResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            LinkSteamAccountCallback successCallback = (LinkSteamAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::SendAccountRecoveryEmail(
    SendAccountRecoveryEmailRequest& request,
    SendAccountRecoveryEmailCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/SendAccountRecoveryEmail"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSendAccountRecoveryEmailResult, this);
}

void PlayFabClientAPI::OnSendAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData)
{
    SendAccountRecoveryEmailResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            SendAccountRecoveryEmailCallback successCallback = (SendAccountRecoveryEmailCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UnlinkAndroidDeviceID(
    
    UnlinkAndroidDeviceIDCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkAndroidDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUnlinkAndroidDeviceIDResult, this);
}

void PlayFabClientAPI::OnUnlinkAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkAndroidDeviceIDResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UnlinkAndroidDeviceIDCallback successCallback = (UnlinkAndroidDeviceIDCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UnlinkFacebookAccount(
    
    UnlinkFacebookAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkFacebookAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUnlinkFacebookAccountResult, this);
}

void PlayFabClientAPI::OnUnlinkFacebookAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkFacebookAccountResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UnlinkFacebookAccountCallback successCallback = (UnlinkFacebookAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UnlinkGameCenterAccount(
    
    UnlinkGameCenterAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkGameCenterAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUnlinkGameCenterAccountResult, this);
}

void PlayFabClientAPI::OnUnlinkGameCenterAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkGameCenterAccountResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UnlinkGameCenterAccountCallback successCallback = (UnlinkGameCenterAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UnlinkGoogleAccount(
    
    UnlinkGoogleAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkGoogleAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUnlinkGoogleAccountResult, this);
}

void PlayFabClientAPI::OnUnlinkGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkGoogleAccountResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UnlinkGoogleAccountCallback successCallback = (UnlinkGoogleAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UnlinkIOSDeviceID(
    
    UnlinkIOSDeviceIDCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkIOSDeviceID"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUnlinkIOSDeviceIDResult, this);
}

void PlayFabClientAPI::OnUnlinkIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkIOSDeviceIDResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UnlinkIOSDeviceIDCallback successCallback = (UnlinkIOSDeviceIDCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UnlinkSteamAccount(
    
    UnlinkSteamAccountCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlinkSteamAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUnlinkSteamAccountResult, this);
}

void PlayFabClientAPI::OnUnlinkSteamAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkSteamAccountResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UnlinkSteamAccountCallback successCallback = (UnlinkSteamAccountCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UpdateUserTitleDisplayName(
    UpdateUserTitleDisplayNameRequest& request,
    UpdateUserTitleDisplayNameCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateUserTitleDisplayName"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserTitleDisplayNameResult, this);
}

void PlayFabClientAPI::OnUpdateUserTitleDisplayNameResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserTitleDisplayNameResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UpdateUserTitleDisplayNameCallback successCallback = (UpdateUserTitleDisplayNameCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetFriendLeaderboard(
    GetFriendLeaderboardRequest& request,
    GetFriendLeaderboardCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetFriendLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetFriendLeaderboardResult, this);
}

void PlayFabClientAPI::OnGetFriendLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetFriendLeaderboardCallback successCallback = (GetFriendLeaderboardCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetLeaderboard(
    GetLeaderboardRequest& request,
    GetLeaderboardCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetLeaderboardResult, this);
}

void PlayFabClientAPI::OnGetLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetLeaderboardCallback successCallback = (GetLeaderboardCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetLeaderboardAroundCurrentUser(
    GetLeaderboardAroundCurrentUserRequest& request,
    GetLeaderboardAroundCurrentUserCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboardAroundCurrentUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetLeaderboardAroundCurrentUserResult, this);
}

void PlayFabClientAPI::OnGetLeaderboardAroundCurrentUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardAroundCurrentUserResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetLeaderboardAroundCurrentUserCallback successCallback = (GetLeaderboardAroundCurrentUserCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetUserData(
    GetUserDataRequest& request,
    GetUserDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserDataResult, this);
}

void PlayFabClientAPI::OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetUserDataCallback successCallback = (GetUserDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetUserPublisherData(
    GetUserDataRequest& request,
    GetUserPublisherDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserPublisherDataResult, this);
}

void PlayFabClientAPI::OnGetUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetUserPublisherDataCallback successCallback = (GetUserPublisherDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetUserPublisherReadOnlyData(
    GetUserDataRequest& request,
    GetUserPublisherReadOnlyDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserPublisherReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserPublisherReadOnlyDataResult, this);
}

void PlayFabClientAPI::OnGetUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetUserPublisherReadOnlyDataCallback successCallback = (GetUserPublisherReadOnlyDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetUserReadOnlyData(
    GetUserDataRequest& request,
    GetUserReadOnlyDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserReadOnlyDataResult, this);
}

void PlayFabClientAPI::OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetUserReadOnlyDataCallback successCallback = (GetUserReadOnlyDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetUserStatistics(
    
    GetUserStatisticsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserStatisticsResult, this);
}

void PlayFabClientAPI::OnGetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserStatisticsResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetUserStatisticsCallback successCallback = (GetUserStatisticsCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UpdateUserData(
    UpdateUserDataRequest& request,
    UpdateUserDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateUserData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserDataResult, this);
}

void PlayFabClientAPI::OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UpdateUserDataCallback successCallback = (UpdateUserDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UpdateUserPublisherData(
    UpdateUserDataRequest& request,
    UpdateUserPublisherDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateUserPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserPublisherDataResult, this);
}

void PlayFabClientAPI::OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UpdateUserPublisherDataCallback successCallback = (UpdateUserPublisherDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UpdateUserStatistics(
    UpdateUserStatisticsRequest& request,
    UpdateUserStatisticsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateUserStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserStatisticsResult, this);
}

void PlayFabClientAPI::OnUpdateUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserStatisticsResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UpdateUserStatisticsCallback successCallback = (UpdateUserStatisticsCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetCatalogItems(
    GetCatalogItemsRequest& request,
    GetCatalogItemsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCatalogItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCatalogItemsResult, this);
}

void PlayFabClientAPI::OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCatalogItemsResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetCatalogItemsCallback successCallback = (GetCatalogItemsCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetStoreItems(
    GetStoreItemsRequest& request,
    GetStoreItemsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetStoreItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetStoreItemsResult, this);
}

void PlayFabClientAPI::OnGetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetStoreItemsResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetStoreItemsCallback successCallback = (GetStoreItemsCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetTitleData(
    GetTitleDataRequest& request,
    GetTitleDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetTitleData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetTitleDataResult, this);
}

void PlayFabClientAPI::OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetTitleDataCallback successCallback = (GetTitleDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetTitleNews(
    GetTitleNewsRequest& request,
    GetTitleNewsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetTitleNews"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetTitleNewsResult, this);
}

void PlayFabClientAPI::OnGetTitleNewsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleNewsResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetTitleNewsCallback successCallback = (GetTitleNewsCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::AddUserVirtualCurrency(
    AddUserVirtualCurrencyRequest& request,
    AddUserVirtualCurrencyCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AddUserVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAddUserVirtualCurrencyResult, this);
}

void PlayFabClientAPI::OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyUserVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            AddUserVirtualCurrencyCallback successCallback = (AddUserVirtualCurrencyCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::ConfirmPurchase(
    ConfirmPurchaseRequest& request,
    ConfirmPurchaseCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ConfirmPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnConfirmPurchaseResult, this);
}

void PlayFabClientAPI::OnConfirmPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    ConfirmPurchaseResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            ConfirmPurchaseCallback successCallback = (ConfirmPurchaseCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::ConsumeItem(
    ConsumeItemRequest& request,
    ConsumeItemCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ConsumeItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnConsumeItemResult, this);
}

void PlayFabClientAPI::OnConsumeItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    ConsumeItemResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            ConsumeItemCallback successCallback = (ConsumeItemCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetCharacterInventory(
    GetCharacterInventoryRequest& request,
    GetCharacterInventoryCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterInventory"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCharacterInventoryResult, this);
}

void PlayFabClientAPI::OnGetCharacterInventoryResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterInventoryResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetCharacterInventoryCallback successCallback = (GetCharacterInventoryCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetUserInventory(
    
    GetUserInventoryCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetUserInventory"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserInventoryResult, this);
}

void PlayFabClientAPI::OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserInventoryResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetUserInventoryCallback successCallback = (GetUserInventoryCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::PayForPurchase(
    PayForPurchaseRequest& request,
    PayForPurchaseCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/PayForPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnPayForPurchaseResult, this);
}

void PlayFabClientAPI::OnPayForPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    PayForPurchaseResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            PayForPurchaseCallback successCallback = (PayForPurchaseCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::PurchaseItem(
    PurchaseItemRequest& request,
    PurchaseItemCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/PurchaseItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnPurchaseItemResult, this);
}

void PlayFabClientAPI::OnPurchaseItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    PurchaseItemResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            PurchaseItemCallback successCallback = (PurchaseItemCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::RedeemCoupon(
    RedeemCouponRequest& request,
    RedeemCouponCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RedeemCoupon"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRedeemCouponResult, this);
}

void PlayFabClientAPI::OnRedeemCouponResult(int httpStatus, HttpRequest* request, void* userData)
{
    RedeemCouponResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            RedeemCouponCallback successCallback = (RedeemCouponCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::ReportPlayer(
    ReportPlayerClientRequest& request,
    ReportPlayerCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ReportPlayer"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnReportPlayerResult, this);
}

void PlayFabClientAPI::OnReportPlayerResult(int httpStatus, HttpRequest* request, void* userData)
{
    ReportPlayerClientResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            ReportPlayerCallback successCallback = (ReportPlayerCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::StartPurchase(
    StartPurchaseRequest& request,
    StartPurchaseCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/StartPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnStartPurchaseResult, this);
}

void PlayFabClientAPI::OnStartPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    StartPurchaseResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            StartPurchaseCallback successCallback = (StartPurchaseCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::SubtractUserVirtualCurrency(
    SubtractUserVirtualCurrencyRequest& request,
    SubtractUserVirtualCurrencyCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/SubtractUserVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSubtractUserVirtualCurrencyResult, this);
}

void PlayFabClientAPI::OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyUserVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            SubtractUserVirtualCurrencyCallback successCallback = (SubtractUserVirtualCurrencyCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UnlockContainerItem(
    UnlockContainerItemRequest& request,
    UnlockContainerItemCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UnlockContainerItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUnlockContainerItemResult, this);
}

void PlayFabClientAPI::OnUnlockContainerItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlockContainerItemResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UnlockContainerItemCallback successCallback = (UnlockContainerItemCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::AddFriend(
    AddFriendRequest& request,
    AddFriendCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AddFriend"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAddFriendResult, this);
}

void PlayFabClientAPI::OnAddFriendResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddFriendResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            AddFriendCallback successCallback = (AddFriendCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetFriendsList(
    GetFriendsListRequest& request,
    GetFriendsListCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetFriendsList"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetFriendsListResult, this);
}

void PlayFabClientAPI::OnGetFriendsListResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetFriendsListResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetFriendsListCallback successCallback = (GetFriendsListCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::RemoveFriend(
    RemoveFriendRequest& request,
    RemoveFriendCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RemoveFriend"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRemoveFriendResult, this);
}

void PlayFabClientAPI::OnRemoveFriendResult(int httpStatus, HttpRequest* request, void* userData)
{
    RemoveFriendResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            RemoveFriendCallback successCallback = (RemoveFriendCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::SetFriendTags(
    SetFriendTagsRequest& request,
    SetFriendTagsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/SetFriendTags"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSetFriendTagsResult, this);
}

void PlayFabClientAPI::OnSetFriendTagsResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetFriendTagsResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            SetFriendTagsCallback successCallback = (SetFriendTagsCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::RegisterForIOSPushNotification(
    RegisterForIOSPushNotificationRequest& request,
    RegisterForIOSPushNotificationCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RegisterForIOSPushNotification"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRegisterForIOSPushNotificationResult, this);
}

void PlayFabClientAPI::OnRegisterForIOSPushNotificationResult(int httpStatus, HttpRequest* request, void* userData)
{
    RegisterForIOSPushNotificationResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            RegisterForIOSPushNotificationCallback successCallback = (RegisterForIOSPushNotificationCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::RestoreIOSPurchases(
    RestoreIOSPurchasesRequest& request,
    RestoreIOSPurchasesCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RestoreIOSPurchases"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRestoreIOSPurchasesResult, this);
}

void PlayFabClientAPI::OnRestoreIOSPurchasesResult(int httpStatus, HttpRequest* request, void* userData)
{
    RestoreIOSPurchasesResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            RestoreIOSPurchasesCallback successCallback = (RestoreIOSPurchasesCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::ValidateIOSReceipt(
    ValidateIOSReceiptRequest& request,
    ValidateIOSReceiptCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ValidateIOSReceipt"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnValidateIOSReceiptResult, this);
}

void PlayFabClientAPI::OnValidateIOSReceiptResult(int httpStatus, HttpRequest* request, void* userData)
{
    ValidateIOSReceiptResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            ValidateIOSReceiptCallback successCallback = (ValidateIOSReceiptCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetCurrentGames(
    CurrentGamesRequest& request,
    GetCurrentGamesCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCurrentGames"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCurrentGamesResult, this);
}

void PlayFabClientAPI::OnGetCurrentGamesResult(int httpStatus, HttpRequest* request, void* userData)
{
    CurrentGamesResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetCurrentGamesCallback successCallback = (GetCurrentGamesCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetGameServerRegions(
    GameServerRegionsRequest& request,
    GetGameServerRegionsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetGameServerRegions"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetGameServerRegionsResult, this);
}

void PlayFabClientAPI::OnGetGameServerRegionsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GameServerRegionsResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetGameServerRegionsCallback successCallback = (GetGameServerRegionsCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::Matchmake(
    MatchmakeRequest& request,
    MatchmakeCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/Matchmake"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnMatchmakeResult, this);
}

void PlayFabClientAPI::OnMatchmakeResult(int httpStatus, HttpRequest* request, void* userData)
{
    MatchmakeResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            MatchmakeCallback successCallback = (MatchmakeCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::StartGame(
    StartGameRequest& request,
    StartGameCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/StartGame"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnStartGameResult, this);
}

void PlayFabClientAPI::OnStartGameResult(int httpStatus, HttpRequest* request, void* userData)
{
    StartGameResult outResult;
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


void PlayFabClientAPI::AndroidDevicePushNotificationRegistration(
    AndroidDevicePushNotificationRegistrationRequest& request,
    AndroidDevicePushNotificationRegistrationCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AndroidDevicePushNotificationRegistration"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAndroidDevicePushNotificationRegistrationResult, this);
}

void PlayFabClientAPI::OnAndroidDevicePushNotificationRegistrationResult(int httpStatus, HttpRequest* request, void* userData)
{
    AndroidDevicePushNotificationRegistrationResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            AndroidDevicePushNotificationRegistrationCallback successCallback = (AndroidDevicePushNotificationRegistrationCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::ValidateGooglePlayPurchase(
    ValidateGooglePlayPurchaseRequest& request,
    ValidateGooglePlayPurchaseCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/ValidateGooglePlayPurchase"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnValidateGooglePlayPurchaseResult, this);
}

void PlayFabClientAPI::OnValidateGooglePlayPurchaseResult(int httpStatus, HttpRequest* request, void* userData)
{
    ValidateGooglePlayPurchaseResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            ValidateGooglePlayPurchaseCallback successCallback = (ValidateGooglePlayPurchaseCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::LogEvent(
    LogEventRequest& request,
    LogEventCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/LogEvent"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnLogEventResult, this);
}

void PlayFabClientAPI::OnLogEventResult(int httpStatus, HttpRequest* request, void* userData)
{
    LogEventResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            LogEventCallback successCallback = (LogEventCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::AddSharedGroupMembers(
    AddSharedGroupMembersRequest& request,
    AddSharedGroupMembersCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/AddSharedGroupMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAddSharedGroupMembersResult, this);
}

void PlayFabClientAPI::OnAddSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddSharedGroupMembersResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            AddSharedGroupMembersCallback successCallback = (AddSharedGroupMembersCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::CreateSharedGroup(
    CreateSharedGroupRequest& request,
    CreateSharedGroupCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/CreateSharedGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnCreateSharedGroupResult, this);
}

void PlayFabClientAPI::OnCreateSharedGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateSharedGroupResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            CreateSharedGroupCallback successCallback = (CreateSharedGroupCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetPublisherData(
    GetPublisherDataRequest& request,
    GetPublisherDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetPublisherDataResult, this);
}

void PlayFabClientAPI::OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPublisherDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetPublisherDataCallback successCallback = (GetPublisherDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetSharedGroupData(
    GetSharedGroupDataRequest& request,
    GetSharedGroupDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetSharedGroupData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetSharedGroupDataResult, this);
}

void PlayFabClientAPI::OnGetSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetSharedGroupDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetSharedGroupDataCallback successCallback = (GetSharedGroupDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::RemoveSharedGroupMembers(
    RemoveSharedGroupMembersRequest& request,
    RemoveSharedGroupMembersCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RemoveSharedGroupMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRemoveSharedGroupMembersResult, this);
}

void PlayFabClientAPI::OnRemoveSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    RemoveSharedGroupMembersResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            RemoveSharedGroupMembersCallback successCallback = (RemoveSharedGroupMembersCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UpdateSharedGroupData(
    UpdateSharedGroupDataRequest& request,
    UpdateSharedGroupDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateSharedGroupData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateSharedGroupDataResult, this);
}

void PlayFabClientAPI::OnUpdateSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateSharedGroupDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UpdateSharedGroupDataCallback successCallback = (UpdateSharedGroupDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::RefreshPSNAuthToken(
    RefreshPSNAuthTokenRequest& request,
    RefreshPSNAuthTokenCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/RefreshPSNAuthToken"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRefreshPSNAuthTokenResult, this);
}

void PlayFabClientAPI::OnRefreshPSNAuthTokenResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            RefreshPSNAuthTokenCallback successCallback = (RefreshPSNAuthTokenCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetCloudScriptUrl(
    GetCloudScriptUrlRequest& request,
    GetCloudScriptUrlCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCloudScriptUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCloudScriptUrlResult, this);
}

void PlayFabClientAPI::OnGetCloudScriptUrlResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCloudScriptUrlResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        if (outResult.Url.length() > 0)
			PlayFabSettings::logicServerURL = outResult.Url;

        if (request->GetResultCallback() != NULL)
        {
            GetCloudScriptUrlCallback successCallback = (GetCloudScriptUrlCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::RunCloudScript(
    RunCloudScriptRequest& request,
    RunCloudScriptCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getLogicURL("/Client/RunCloudScript"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRunCloudScriptResult, this);
}

void PlayFabClientAPI::OnRunCloudScriptResult(int httpStatus, HttpRequest* request, void* userData)
{
    RunCloudScriptResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            RunCloudScriptCallback successCallback = (RunCloudScriptCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetContentDownloadUrl(
    GetContentDownloadUrlRequest& request,
    GetContentDownloadUrlCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetContentDownloadUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetContentDownloadUrlResult, this);
}

void PlayFabClientAPI::OnGetContentDownloadUrlResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetContentDownloadUrlResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetContentDownloadUrlCallback successCallback = (GetContentDownloadUrlCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetCharacterLeaderboard(
    GetCharacterLeaderboardRequest& request,
    GetCharacterLeaderboardCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCharacterLeaderboardResult, this);
}

void PlayFabClientAPI::OnGetCharacterLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterLeaderboardResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetCharacterLeaderboardCallback successCallback = (GetCharacterLeaderboardCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetLeaderboardAroundCharacter(
    GetLeaderboardAroundCharacterRequest& request,
    GetLeaderboardAroundCharacterCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboardAroundCharacter"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetLeaderboardAroundCharacterResult, this);
}

void PlayFabClientAPI::OnGetLeaderboardAroundCharacterResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardAroundCharacterResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetLeaderboardAroundCharacterCallback successCallback = (GetLeaderboardAroundCharacterCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetLeaderboardForUserCharacters(
    GetLeaderboardForUsersCharactersRequest& request,
    GetLeaderboardForUserCharactersCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetLeaderboardForUserCharacters"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetLeaderboardForUserCharactersResult, this);
}

void PlayFabClientAPI::OnGetLeaderboardForUserCharactersResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardForUsersCharactersResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetLeaderboardForUserCharactersCallback successCallback = (GetLeaderboardForUserCharactersCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GrantCharacterToUser(
    GrantCharacterToUserRequest& request,
    GrantCharacterToUserCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GrantCharacterToUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGrantCharacterToUserResult, this);
}

void PlayFabClientAPI::OnGrantCharacterToUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    GrantCharacterToUserResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GrantCharacterToUserCallback successCallback = (GrantCharacterToUserCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetCharacterData(
    GetCharacterDataRequest& request,
    GetCharacterDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCharacterDataResult, this);
}

void PlayFabClientAPI::OnGetCharacterDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetCharacterDataCallback successCallback = (GetCharacterDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::GetCharacterReadOnlyData(
    GetCharacterDataRequest& request,
    GetCharacterReadOnlyDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/GetCharacterReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCharacterReadOnlyDataResult, this);
}

void PlayFabClientAPI::OnGetCharacterReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            GetCharacterReadOnlyDataCallback successCallback = (GetCharacterReadOnlyDataCallback)(request->GetResultCallback());
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


void PlayFabClientAPI::UpdateCharacterData(
    UpdateCharacterDataRequest& request,
    UpdateCharacterDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Client/UpdateCharacterData"));
    httpRequest->SetHeader("Content-Type", "application/json");
	httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
	httpRequest->SetHeader("X-Authorization", mUserSessionTicket);
	
    httpRequest->SetResultCallback((void*)callback);
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateCharacterDataResult, this);
}

void PlayFabClientAPI::OnUpdateCharacterDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCharacterDataResult outResult;
    PlayFabError errorResult;

    bool success = PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult);

    if (success)
    {
        

        if (request->GetResultCallback() != NULL)
        {
            UpdateCharacterDataCallback successCallback = (UpdateCharacterDataCallback)(request->GetResultCallback());
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




