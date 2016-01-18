#include "playfab/PlayFabAdminAPI.h"
#include "playfab/HttpRequest.h"
#include "playfab/PlayFabSettings.h"
#include "playfab/PlayFabResultHandler.h"
#include "playfab/HttpRequesterCURL.h"
#include "playfab/PlayFabVersion.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::AdminModels;

IHttpRequester* PlayFabAdminAPI::mHttpRequester = new HttpRequesterCURL();

PlayFabAdminAPI::PlayFabAdminAPI() {}

size_t PlayFabAdminAPI::Update()
{
    return mHttpRequester->UpdateRequests();
}

void PlayFabAdminAPI::GetUserAccountInfo(
    LookupUserAccountInfoRequest& request,
    GetUserAccountInfoCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetUserAccountInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserAccountInfoResult, nullptr);
}

void PlayFabAdminAPI::OnGetUserAccountInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    LookupUserAccountInfoResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetUserAccountInfoCallback successCallback = reinterpret_cast<GetUserAccountInfoCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::ResetUsers(
    ResetUsersRequest& request,
    ResetUsersCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/ResetUsers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnResetUsersResult, nullptr);
}

void PlayFabAdminAPI::OnResetUsersResult(int httpStatus, HttpRequest* request, void* userData)
{
    BlankResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ResetUsersCallback successCallback = reinterpret_cast<ResetUsersCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::SendAccountRecoveryEmail(
    SendAccountRecoveryEmailRequest& request,
    SendAccountRecoveryEmailCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/SendAccountRecoveryEmail"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSendAccountRecoveryEmailResult, nullptr);
}

void PlayFabAdminAPI::OnSendAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData)
{
    SendAccountRecoveryEmailResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            SendAccountRecoveryEmailCallback successCallback = reinterpret_cast<SendAccountRecoveryEmailCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateUserTitleDisplayName(
    UpdateUserTitleDisplayNameRequest& request,
    UpdateUserTitleDisplayNameCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateUserTitleDisplayName"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserTitleDisplayNameResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateUserTitleDisplayNameResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserTitleDisplayNameResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateUserTitleDisplayNameCallback successCallback = reinterpret_cast<UpdateUserTitleDisplayNameCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::DeleteUsers(
    DeleteUsersRequest& request,
    DeleteUsersCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/DeleteUsers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnDeleteUsersResult, nullptr);
}

void PlayFabAdminAPI::OnDeleteUsersResult(int httpStatus, HttpRequest* request, void* userData)
{
    DeleteUsersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            DeleteUsersCallback successCallback = reinterpret_cast<DeleteUsersCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetDataReport(
    GetDataReportRequest& request,
    GetDataReportCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetDataReport"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetDataReportResult, nullptr);
}

void PlayFabAdminAPI::OnGetDataReportResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetDataReportResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetDataReportCallback successCallback = reinterpret_cast<GetDataReportCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetUserData(
    GetUserDataRequest& request,
    GetUserDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetUserData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserDataResult, nullptr);
}

void PlayFabAdminAPI::OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetUserDataCallback successCallback = reinterpret_cast<GetUserDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetUserInternalData(
    GetUserDataRequest& request,
    GetUserInternalDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetUserInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserInternalDataResult, nullptr);
}

void PlayFabAdminAPI::OnGetUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetUserInternalDataCallback successCallback = reinterpret_cast<GetUserInternalDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetUserPublisherData(
    GetUserDataRequest& request,
    GetUserPublisherDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetUserPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserPublisherDataResult, nullptr);
}

void PlayFabAdminAPI::OnGetUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetUserPublisherDataCallback successCallback = reinterpret_cast<GetUserPublisherDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetUserPublisherInternalData(
    GetUserDataRequest& request,
    GetUserPublisherInternalDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetUserPublisherInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserPublisherInternalDataResult, nullptr);
}

void PlayFabAdminAPI::OnGetUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetUserPublisherInternalDataCallback successCallback = reinterpret_cast<GetUserPublisherInternalDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetUserPublisherReadOnlyData(
    GetUserDataRequest& request,
    GetUserPublisherReadOnlyDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetUserPublisherReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserPublisherReadOnlyDataResult, nullptr);
}

void PlayFabAdminAPI::OnGetUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetUserPublisherReadOnlyDataCallback successCallback = reinterpret_cast<GetUserPublisherReadOnlyDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetUserReadOnlyData(
    GetUserDataRequest& request,
    GetUserReadOnlyDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetUserReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserReadOnlyDataResult, nullptr);
}

void PlayFabAdminAPI::OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetUserReadOnlyDataCallback successCallback = reinterpret_cast<GetUserReadOnlyDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::ResetUserStatistics(
    ResetUserStatisticsRequest& request,
    ResetUserStatisticsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/ResetUserStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnResetUserStatisticsResult, nullptr);
}

void PlayFabAdminAPI::OnResetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ResetUserStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ResetUserStatisticsCallback successCallback = reinterpret_cast<ResetUserStatisticsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateUserData(
    UpdateUserDataRequest& request,
    UpdateUserDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateUserData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserDataResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateUserDataCallback successCallback = reinterpret_cast<UpdateUserDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateUserInternalData(
    UpdateUserInternalDataRequest& request,
    UpdateUserInternalDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateUserInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserInternalDataResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateUserInternalDataCallback successCallback = reinterpret_cast<UpdateUserInternalDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateUserPublisherData(
    UpdateUserDataRequest& request,
    UpdateUserPublisherDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateUserPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserPublisherDataResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateUserPublisherDataCallback successCallback = reinterpret_cast<UpdateUserPublisherDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateUserPublisherInternalData(
    UpdateUserInternalDataRequest& request,
    UpdateUserPublisherInternalDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateUserPublisherInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserPublisherInternalDataResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateUserPublisherInternalDataCallback successCallback = reinterpret_cast<UpdateUserPublisherInternalDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateUserPublisherReadOnlyData(
    UpdateUserDataRequest& request,
    UpdateUserPublisherReadOnlyDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateUserPublisherReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserPublisherReadOnlyDataResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateUserPublisherReadOnlyDataCallback successCallback = reinterpret_cast<UpdateUserPublisherReadOnlyDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateUserReadOnlyData(
    UpdateUserDataRequest& request,
    UpdateUserReadOnlyDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateUserReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateUserReadOnlyDataResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateUserReadOnlyDataCallback successCallback = reinterpret_cast<UpdateUserReadOnlyDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::AddNews(
    AddNewsRequest& request,
    AddNewsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/AddNews"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAddNewsResult, nullptr);
}

void PlayFabAdminAPI::OnAddNewsResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddNewsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            AddNewsCallback successCallback = reinterpret_cast<AddNewsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::AddVirtualCurrencyTypes(
    AddVirtualCurrencyTypesRequest& request,
    AddVirtualCurrencyTypesCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/AddVirtualCurrencyTypes"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAddVirtualCurrencyTypesResult, nullptr);
}

void PlayFabAdminAPI::OnAddVirtualCurrencyTypesResult(int httpStatus, HttpRequest* request, void* userData)
{
    BlankResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            AddVirtualCurrencyTypesCallback successCallback = reinterpret_cast<AddVirtualCurrencyTypesCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetCatalogItems(
    GetCatalogItemsRequest& request,
    GetCatalogItemsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetCatalogItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCatalogItemsResult, nullptr);
}

void PlayFabAdminAPI::OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCatalogItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetCatalogItemsCallback successCallback = reinterpret_cast<GetCatalogItemsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetRandomResultTables(
    GetRandomResultTablesRequest& request,
    GetRandomResultTablesCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetRandomResultTables"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetRandomResultTablesResult, nullptr);
}

void PlayFabAdminAPI::OnGetRandomResultTablesResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetRandomResultTablesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetRandomResultTablesCallback successCallback = reinterpret_cast<GetRandomResultTablesCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetStoreItems(
    GetStoreItemsRequest& request,
    GetStoreItemsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetStoreItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetStoreItemsResult, nullptr);
}

void PlayFabAdminAPI::OnGetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetStoreItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetStoreItemsCallback successCallback = reinterpret_cast<GetStoreItemsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetTitleData(
    GetTitleDataRequest& request,
    GetTitleDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetTitleData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetTitleDataResult, nullptr);
}

void PlayFabAdminAPI::OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetTitleDataCallback successCallback = reinterpret_cast<GetTitleDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::ListVirtualCurrencyTypes(
    
    ListVirtualCurrencyTypesCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/ListVirtualCurrencyTypes"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnListVirtualCurrencyTypesResult, nullptr);
}

void PlayFabAdminAPI::OnListVirtualCurrencyTypesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListVirtualCurrencyTypesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ListVirtualCurrencyTypesCallback successCallback = reinterpret_cast<ListVirtualCurrencyTypesCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::SetCatalogItems(
    UpdateCatalogItemsRequest& request,
    SetCatalogItemsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/SetCatalogItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSetCatalogItemsResult, nullptr);
}

void PlayFabAdminAPI::OnSetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCatalogItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            SetCatalogItemsCallback successCallback = reinterpret_cast<SetCatalogItemsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::SetStoreItems(
    UpdateStoreItemsRequest& request,
    SetStoreItemsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/SetStoreItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSetStoreItemsResult, nullptr);
}

void PlayFabAdminAPI::OnSetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateStoreItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            SetStoreItemsCallback successCallback = reinterpret_cast<SetStoreItemsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::SetTitleData(
    SetTitleDataRequest& request,
    SetTitleDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/SetTitleData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSetTitleDataResult, nullptr);
}

void PlayFabAdminAPI::OnSetTitleDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetTitleDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            SetTitleDataCallback successCallback = reinterpret_cast<SetTitleDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::SetupPushNotification(
    SetupPushNotificationRequest& request,
    SetupPushNotificationCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/SetupPushNotification"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSetupPushNotificationResult, nullptr);
}

void PlayFabAdminAPI::OnSetupPushNotificationResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetupPushNotificationResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            SetupPushNotificationCallback successCallback = reinterpret_cast<SetupPushNotificationCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateCatalogItems(
    UpdateCatalogItemsRequest& request,
    UpdateCatalogItemsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateCatalogItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateCatalogItemsResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCatalogItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateCatalogItemsCallback successCallback = reinterpret_cast<UpdateCatalogItemsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateRandomResultTables(
    UpdateRandomResultTablesRequest& request,
    UpdateRandomResultTablesCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateRandomResultTables"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateRandomResultTablesResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateRandomResultTablesResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateRandomResultTablesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateRandomResultTablesCallback successCallback = reinterpret_cast<UpdateRandomResultTablesCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateStoreItems(
    UpdateStoreItemsRequest& request,
    UpdateStoreItemsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateStoreItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateStoreItemsResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateStoreItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateStoreItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateStoreItemsCallback successCallback = reinterpret_cast<UpdateStoreItemsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::AddUserVirtualCurrency(
    AddUserVirtualCurrencyRequest& request,
    AddUserVirtualCurrencyCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/AddUserVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAddUserVirtualCurrencyResult, nullptr);
}

void PlayFabAdminAPI::OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyUserVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            AddUserVirtualCurrencyCallback successCallback = reinterpret_cast<AddUserVirtualCurrencyCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetUserInventory(
    GetUserInventoryRequest& request,
    GetUserInventoryCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetUserInventory"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetUserInventoryResult, nullptr);
}

void PlayFabAdminAPI::OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserInventoryResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetUserInventoryCallback successCallback = reinterpret_cast<GetUserInventoryCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GrantItemsToUsers(
    GrantItemsToUsersRequest& request,
    GrantItemsToUsersCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GrantItemsToUsers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGrantItemsToUsersResult, nullptr);
}

void PlayFabAdminAPI::OnGrantItemsToUsersResult(int httpStatus, HttpRequest* request, void* userData)
{
    GrantItemsToUsersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GrantItemsToUsersCallback successCallback = reinterpret_cast<GrantItemsToUsersCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::RevokeInventoryItem(
    RevokeInventoryItemRequest& request,
    RevokeInventoryItemCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/RevokeInventoryItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRevokeInventoryItemResult, nullptr);
}

void PlayFabAdminAPI::OnRevokeInventoryItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    RevokeInventoryResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            RevokeInventoryItemCallback successCallback = reinterpret_cast<RevokeInventoryItemCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::SubtractUserVirtualCurrency(
    SubtractUserVirtualCurrencyRequest& request,
    SubtractUserVirtualCurrencyCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/SubtractUserVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSubtractUserVirtualCurrencyResult, nullptr);
}

void PlayFabAdminAPI::OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyUserVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            SubtractUserVirtualCurrencyCallback successCallback = reinterpret_cast<SubtractUserVirtualCurrencyCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetMatchmakerGameInfo(
    GetMatchmakerGameInfoRequest& request,
    GetMatchmakerGameInfoCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetMatchmakerGameInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetMatchmakerGameInfoResult, nullptr);
}

void PlayFabAdminAPI::OnGetMatchmakerGameInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetMatchmakerGameInfoResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetMatchmakerGameInfoCallback successCallback = reinterpret_cast<GetMatchmakerGameInfoCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetMatchmakerGameModes(
    GetMatchmakerGameModesRequest& request,
    GetMatchmakerGameModesCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetMatchmakerGameModes"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetMatchmakerGameModesResult, nullptr);
}

void PlayFabAdminAPI::OnGetMatchmakerGameModesResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetMatchmakerGameModesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetMatchmakerGameModesCallback successCallback = reinterpret_cast<GetMatchmakerGameModesCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::ModifyMatchmakerGameModes(
    ModifyMatchmakerGameModesRequest& request,
    ModifyMatchmakerGameModesCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/ModifyMatchmakerGameModes"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnModifyMatchmakerGameModesResult, nullptr);
}

void PlayFabAdminAPI::OnModifyMatchmakerGameModesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyMatchmakerGameModesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ModifyMatchmakerGameModesCallback successCallback = reinterpret_cast<ModifyMatchmakerGameModesCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::AddServerBuild(
    AddServerBuildRequest& request,
    AddServerBuildCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/AddServerBuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnAddServerBuildResult, nullptr);
}

void PlayFabAdminAPI::OnAddServerBuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddServerBuildResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            AddServerBuildCallback successCallback = reinterpret_cast<AddServerBuildCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetServerBuildInfo(
    GetServerBuildInfoRequest& request,
    GetServerBuildInfoCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetServerBuildInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetServerBuildInfoResult, nullptr);
}

void PlayFabAdminAPI::OnGetServerBuildInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetServerBuildInfoResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetServerBuildInfoCallback successCallback = reinterpret_cast<GetServerBuildInfoCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetServerBuildUploadUrl(
    GetServerBuildUploadURLRequest& request,
    GetServerBuildUploadUrlCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetServerBuildUploadUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetServerBuildUploadUrlResult, nullptr);
}

void PlayFabAdminAPI::OnGetServerBuildUploadUrlResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetServerBuildUploadURLResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetServerBuildUploadUrlCallback successCallback = reinterpret_cast<GetServerBuildUploadUrlCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::ListServerBuilds(
    
    ListServerBuildsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/ListServerBuilds"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnListServerBuildsResult, nullptr);
}

void PlayFabAdminAPI::OnListServerBuildsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListBuildsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ListServerBuildsCallback successCallback = reinterpret_cast<ListServerBuildsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::ModifyServerBuild(
    ModifyServerBuildRequest& request,
    ModifyServerBuildCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/ModifyServerBuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnModifyServerBuildResult, nullptr);
}

void PlayFabAdminAPI::OnModifyServerBuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyServerBuildResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ModifyServerBuildCallback successCallback = reinterpret_cast<ModifyServerBuildCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::RemoveServerBuild(
    RemoveServerBuildRequest& request,
    RemoveServerBuildCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/RemoveServerBuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnRemoveServerBuildResult, nullptr);
}

void PlayFabAdminAPI::OnRemoveServerBuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    RemoveServerBuildResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            RemoveServerBuildCallback successCallback = reinterpret_cast<RemoveServerBuildCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetPublisherData(
    GetPublisherDataRequest& request,
    GetPublisherDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetPublisherDataResult, nullptr);
}

void PlayFabAdminAPI::OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPublisherDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetPublisherDataCallback successCallback = reinterpret_cast<GetPublisherDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::SetPublisherData(
    SetPublisherDataRequest& request,
    SetPublisherDataCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/SetPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSetPublisherDataResult, nullptr);
}

void PlayFabAdminAPI::OnSetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetPublisherDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            SetPublisherDataCallback successCallback = reinterpret_cast<SetPublisherDataCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetCloudScriptRevision(
    GetCloudScriptRevisionRequest& request,
    GetCloudScriptRevisionCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetCloudScriptRevision"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCloudScriptRevisionResult, nullptr);
}

void PlayFabAdminAPI::OnGetCloudScriptRevisionResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCloudScriptRevisionResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetCloudScriptRevisionCallback successCallback = reinterpret_cast<GetCloudScriptRevisionCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetCloudScriptVersions(
    
    GetCloudScriptVersionsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetCloudScriptVersions"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetCloudScriptVersionsResult, nullptr);
}

void PlayFabAdminAPI::OnGetCloudScriptVersionsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCloudScriptVersionsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetCloudScriptVersionsCallback successCallback = reinterpret_cast<GetCloudScriptVersionsCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::SetPublishedRevision(
    SetPublishedRevisionRequest& request,
    SetPublishedRevisionCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/SetPublishedRevision"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnSetPublishedRevisionResult, nullptr);
}

void PlayFabAdminAPI::OnSetPublishedRevisionResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetPublishedRevisionResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            SetPublishedRevisionCallback successCallback = reinterpret_cast<SetPublishedRevisionCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::UpdateCloudScript(
    UpdateCloudScriptRequest& request,
    UpdateCloudScriptCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/UpdateCloudScript"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnUpdateCloudScriptResult, nullptr);
}

void PlayFabAdminAPI::OnUpdateCloudScriptResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCloudScriptResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            UpdateCloudScriptCallback successCallback = reinterpret_cast<UpdateCloudScriptCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::DeleteContent(
    DeleteContentRequest& request,
    DeleteContentCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/DeleteContent"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnDeleteContentResult, nullptr);
}

void PlayFabAdminAPI::OnDeleteContentResult(int httpStatus, HttpRequest* request, void* userData)
{
    BlankResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            DeleteContentCallback successCallback = reinterpret_cast<DeleteContentCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetContentList(
    GetContentListRequest& request,
    GetContentListCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetContentList"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetContentListResult, nullptr);
}

void PlayFabAdminAPI::OnGetContentListResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetContentListResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetContentListCallback successCallback = reinterpret_cast<GetContentListCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::GetContentUploadUrl(
    GetContentUploadUrlRequest& request,
    GetContentUploadUrlCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/GetContentUploadUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnGetContentUploadUrlResult, nullptr);
}

void PlayFabAdminAPI::OnGetContentUploadUrlResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetContentUploadUrlResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            GetContentUploadUrlCallback successCallback = reinterpret_cast<GetContentUploadUrlCallback>(request->GetResultCallback());
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

void PlayFabAdminAPI::ResetCharacterStatistics(
    ResetCharacterStatisticsRequest& request,
    ResetCharacterStatisticsCallback callback,
    ErrorCallback errorCallback,
    void* userData
    )
{
    
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Admin/ResetCharacterStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabVersionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    httpRequest->SetResultCallback(reinterpret_cast<void*>(callback));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    mHttpRequester->AddRequest(httpRequest, OnResetCharacterStatisticsResult, nullptr);
}

void PlayFabAdminAPI::OnResetCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ResetCharacterStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {

        if (request->GetResultCallback() != nullptr)
        {
            ResetCharacterStatisticsCallback successCallback = reinterpret_cast<ResetCharacterStatisticsCallback>(request->GetResultCallback());
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


