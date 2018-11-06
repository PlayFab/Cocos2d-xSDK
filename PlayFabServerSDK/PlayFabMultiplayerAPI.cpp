#include "HttpRequest.h"
#include "HttpRequesterCURL.h"
#include "PlayFabResultHandler.h"
#include "PlayFabSettings.h"
#include "PlayFabMultiplayerAPI.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::MultiplayerModels;

PlayFabMultiplayerAPI::PlayFabMultiplayerAPI() {}

void PlayFabMultiplayerAPI::CreateBuildWithCustomContainer(
    CreateBuildWithCustomContainerRequest& request,
    ProcessApiCallback<CreateBuildWithCustomContainerResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/CreateBuildWithCustomContainer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<CreateBuildWithCustomContainerResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCreateBuildWithCustomContainerResult, userData);
}

void PlayFabMultiplayerAPI::OnCreateBuildWithCustomContainerResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateBuildWithCustomContainerResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<CreateBuildWithCustomContainerResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::CreateBuildWithManagedContainer(
    CreateBuildWithManagedContainerRequest& request,
    ProcessApiCallback<CreateBuildWithManagedContainerResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/CreateBuildWithManagedContainer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<CreateBuildWithManagedContainerResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCreateBuildWithManagedContainerResult, userData);
}

void PlayFabMultiplayerAPI::OnCreateBuildWithManagedContainerResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateBuildWithManagedContainerResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<CreateBuildWithManagedContainerResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::CreateRemoteUser(
    CreateRemoteUserRequest& request,
    ProcessApiCallback<CreateRemoteUserResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/CreateRemoteUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<CreateRemoteUserResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCreateRemoteUserResult, userData);
}

void PlayFabMultiplayerAPI::OnCreateRemoteUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateRemoteUserResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<CreateRemoteUserResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::DeleteAsset(
    DeleteAssetRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/DeleteAsset"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteAssetResult, userData);
}

void PlayFabMultiplayerAPI::OnDeleteAssetResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::DeleteBuild(
    DeleteBuildRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/DeleteBuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteBuildResult, userData);
}

void PlayFabMultiplayerAPI::OnDeleteBuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::DeleteCertificate(
    DeleteCertificateRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/DeleteCertificate"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteCertificateResult, userData);
}

void PlayFabMultiplayerAPI::OnDeleteCertificateResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::DeleteRemoteUser(
    DeleteRemoteUserRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/DeleteRemoteUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteRemoteUserResult, userData);
}

void PlayFabMultiplayerAPI::OnDeleteRemoteUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::EnableMultiplayerServersForTitle(
    ProcessApiCallback<EnableMultiplayerServersForTitleResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/EnableMultiplayerServersForTitle"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EnableMultiplayerServersForTitleResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnEnableMultiplayerServersForTitleResult, userData);
}

void PlayFabMultiplayerAPI::OnEnableMultiplayerServersForTitleResult(int httpStatus, HttpRequest* request, void* userData)
{
    EnableMultiplayerServersForTitleResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EnableMultiplayerServersForTitleResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::GetAssetUploadUrl(
    GetAssetUploadUrlRequest& request,
    ProcessApiCallback<GetAssetUploadUrlResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/GetAssetUploadUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetAssetUploadUrlResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetAssetUploadUrlResult, userData);
}

void PlayFabMultiplayerAPI::OnGetAssetUploadUrlResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetAssetUploadUrlResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetAssetUploadUrlResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::GetBuild(
    GetBuildRequest& request,
    ProcessApiCallback<GetBuildResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/GetBuild"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetBuildResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetBuildResult, userData);
}

void PlayFabMultiplayerAPI::OnGetBuildResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetBuildResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetBuildResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::GetContainerRegistryCredentials(
    ProcessApiCallback<GetContainerRegistryCredentialsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/GetContainerRegistryCredentials"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetContainerRegistryCredentialsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetContainerRegistryCredentialsResult, userData);
}

void PlayFabMultiplayerAPI::OnGetContainerRegistryCredentialsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetContainerRegistryCredentialsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetContainerRegistryCredentialsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::GetMultiplayerServerDetails(
    GetMultiplayerServerDetailsRequest& request,
    ProcessApiCallback<GetMultiplayerServerDetailsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/GetMultiplayerServerDetails"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetMultiplayerServerDetailsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetMultiplayerServerDetailsResult, userData);
}

void PlayFabMultiplayerAPI::OnGetMultiplayerServerDetailsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetMultiplayerServerDetailsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetMultiplayerServerDetailsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::GetRemoteLoginEndpoint(
    GetRemoteLoginEndpointRequest& request,
    ProcessApiCallback<GetRemoteLoginEndpointResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/GetRemoteLoginEndpoint"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetRemoteLoginEndpointResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetRemoteLoginEndpointResult, userData);
}

void PlayFabMultiplayerAPI::OnGetRemoteLoginEndpointResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetRemoteLoginEndpointResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetRemoteLoginEndpointResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::GetTitleEnabledForMultiplayerServersStatus(
    ProcessApiCallback<GetTitleEnabledForMultiplayerServersStatusResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/GetTitleEnabledForMultiplayerServersStatus"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetTitleEnabledForMultiplayerServersStatusResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetTitleEnabledForMultiplayerServersStatusResult, userData);
}

void PlayFabMultiplayerAPI::OnGetTitleEnabledForMultiplayerServersStatusResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleEnabledForMultiplayerServersStatusResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetTitleEnabledForMultiplayerServersStatusResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ListAssetSummaries(
    ListAssetSummariesRequest& request,
    ProcessApiCallback<ListAssetSummariesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ListAssetSummaries"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListAssetSummariesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListAssetSummariesResult, userData);
}

void PlayFabMultiplayerAPI::OnListAssetSummariesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListAssetSummariesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListAssetSummariesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ListBuildSummaries(
    ListBuildSummariesRequest& request,
    ProcessApiCallback<ListBuildSummariesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ListBuildSummaries"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListBuildSummariesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListBuildSummariesResult, userData);
}

void PlayFabMultiplayerAPI::OnListBuildSummariesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListBuildSummariesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListBuildSummariesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ListCertificateSummaries(
    ListCertificateSummariesRequest& request,
    ProcessApiCallback<ListCertificateSummariesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ListCertificateSummaries"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListCertificateSummariesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListCertificateSummariesResult, userData);
}

void PlayFabMultiplayerAPI::OnListCertificateSummariesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListCertificateSummariesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListCertificateSummariesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ListContainerImages(
    ListContainerImagesRequest& request,
    ProcessApiCallback<ListContainerImagesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ListContainerImages"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListContainerImagesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListContainerImagesResult, userData);
}

void PlayFabMultiplayerAPI::OnListContainerImagesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListContainerImagesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListContainerImagesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ListContainerImageTags(
    ListContainerImageTagsRequest& request,
    ProcessApiCallback<ListContainerImageTagsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ListContainerImageTags"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListContainerImageTagsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListContainerImageTagsResult, userData);
}

void PlayFabMultiplayerAPI::OnListContainerImageTagsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListContainerImageTagsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListContainerImageTagsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ListMultiplayerServers(
    ListMultiplayerServersRequest& request,
    ProcessApiCallback<ListMultiplayerServersResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ListMultiplayerServers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListMultiplayerServersResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListMultiplayerServersResult, userData);
}

void PlayFabMultiplayerAPI::OnListMultiplayerServersResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListMultiplayerServersResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListMultiplayerServersResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ListQosServers(
    ProcessApiCallback<ListQosServersResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ListQosServers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListQosServersResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListQosServersResult, userData);
}

void PlayFabMultiplayerAPI::OnListQosServersResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListQosServersResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListQosServersResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ListVirtualMachineSummaries(
    ListVirtualMachineSummariesRequest& request,
    ProcessApiCallback<ListVirtualMachineSummariesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ListVirtualMachineSummaries"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListVirtualMachineSummariesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListVirtualMachineSummariesResult, userData);
}

void PlayFabMultiplayerAPI::OnListVirtualMachineSummariesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListVirtualMachineSummariesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListVirtualMachineSummariesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::RequestMultiplayerServer(
    RequestMultiplayerServerRequest& request,
    ProcessApiCallback<RequestMultiplayerServerResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/RequestMultiplayerServer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RequestMultiplayerServerResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRequestMultiplayerServerResult, userData);
}

void PlayFabMultiplayerAPI::OnRequestMultiplayerServerResult(int httpStatus, HttpRequest* request, void* userData)
{
    RequestMultiplayerServerResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RequestMultiplayerServerResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::RolloverContainerRegistryCredentials(
    ProcessApiCallback<RolloverContainerRegistryCredentialsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/RolloverContainerRegistryCredentials"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RolloverContainerRegistryCredentialsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRolloverContainerRegistryCredentialsResult, userData);
}

void PlayFabMultiplayerAPI::OnRolloverContainerRegistryCredentialsResult(int httpStatus, HttpRequest* request, void* userData)
{
    RolloverContainerRegistryCredentialsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RolloverContainerRegistryCredentialsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::ShutdownMultiplayerServer(
    ShutdownMultiplayerServerRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/ShutdownMultiplayerServer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnShutdownMultiplayerServerResult, userData);
}

void PlayFabMultiplayerAPI::OnShutdownMultiplayerServerResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::UpdateBuildRegions(
    UpdateBuildRegionsRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/UpdateBuildRegions"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateBuildRegionsResult, userData);
}

void PlayFabMultiplayerAPI::OnUpdateBuildRegionsResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabMultiplayerAPI::UploadCertificate(
    UploadCertificateRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/MultiplayerServer/UploadCertificate"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUploadCertificateResult, userData);
}

void PlayFabMultiplayerAPI::OnUploadCertificateResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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


