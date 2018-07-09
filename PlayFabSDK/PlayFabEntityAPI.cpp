#include "HttpRequest.h"
#include "HttpRequesterCURL.h"
#include "PlayFabResultHandler.h"
#include "PlayFabSettings.h"
#include "PlayFabEntityAPI.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::EntityModels;

PlayFabEntityAPI::PlayFabEntityAPI() {}

void PlayFabEntityAPI::AbortFileUploads(
    AbortFileUploadsRequest& request,
    ProcessApiCallback<AbortFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/File/AbortFileUploads"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<AbortFileUploadsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAbortFileUploadsResult, userData);
}

void PlayFabEntityAPI::OnAbortFileUploadsResult(int httpStatus, HttpRequest* request, void* userData)
{
    AbortFileUploadsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<AbortFileUploadsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::AcceptGroupApplication(
    AcceptGroupApplicationRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/AcceptGroupApplication"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAcceptGroupApplicationResult, userData);
}

void PlayFabEntityAPI::OnAcceptGroupApplicationResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::AcceptGroupInvitation(
    AcceptGroupInvitationRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/AcceptGroupInvitation"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAcceptGroupInvitationResult, userData);
}

void PlayFabEntityAPI::OnAcceptGroupInvitationResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::AddMembers(
    AddMembersRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/AddMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddMembersResult, userData);
}

void PlayFabEntityAPI::OnAddMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ApplyToGroup(
    ApplyToGroupRequest& request,
    ProcessApiCallback<ApplyToGroupResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/ApplyToGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ApplyToGroupResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnApplyToGroupResult, userData);
}

void PlayFabEntityAPI::OnApplyToGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    ApplyToGroupResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ApplyToGroupResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::BlockEntity(
    BlockEntityRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/BlockEntity"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnBlockEntityResult, userData);
}

void PlayFabEntityAPI::OnBlockEntityResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ChangeMemberRole(
    ChangeMemberRoleRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/ChangeMemberRole"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnChangeMemberRoleResult, userData);
}

void PlayFabEntityAPI::OnChangeMemberRoleResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::CreateGroup(
    CreateGroupRequest& request,
    ProcessApiCallback<CreateGroupResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/CreateGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<CreateGroupResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCreateGroupResult, userData);
}

void PlayFabEntityAPI::OnCreateGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateGroupResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<CreateGroupResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::CreateRole(
    CreateGroupRoleRequest& request,
    ProcessApiCallback<CreateGroupRoleResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/CreateRole"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<CreateGroupRoleResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCreateRoleResult, userData);
}

void PlayFabEntityAPI::OnCreateRoleResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateGroupRoleResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<CreateGroupRoleResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::DeleteFiles(
    DeleteFilesRequest& request,
    ProcessApiCallback<DeleteFilesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/File/DeleteFiles"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<DeleteFilesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteFilesResult, userData);
}

void PlayFabEntityAPI::OnDeleteFilesResult(int httpStatus, HttpRequest* request, void* userData)
{
    DeleteFilesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<DeleteFilesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::DeleteGroup(
    DeleteGroupRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/DeleteGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteGroupResult, userData);
}

void PlayFabEntityAPI::OnDeleteGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::DeleteRole(
    DeleteRoleRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/DeleteRole"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteRoleResult, userData);
}

void PlayFabEntityAPI::OnDeleteRoleResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ExecuteEntityCloudScript(
    ExecuteEntityCloudScriptRequest& request,
    ProcessApiCallback<ExecuteCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/CloudScript/ExecuteEntityCloudScript"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ExecuteCloudScriptResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnExecuteEntityCloudScriptResult, userData);
}

void PlayFabEntityAPI::OnExecuteEntityCloudScriptResult(int httpStatus, HttpRequest* request, void* userData)
{
    ExecuteCloudScriptResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ExecuteCloudScriptResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::FinalizeFileUploads(
    FinalizeFileUploadsRequest& request,
    ProcessApiCallback<FinalizeFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/File/FinalizeFileUploads"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<FinalizeFileUploadsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnFinalizeFileUploadsResult, userData);
}

void PlayFabEntityAPI::OnFinalizeFileUploadsResult(int httpStatus, HttpRequest* request, void* userData)
{
    FinalizeFileUploadsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<FinalizeFileUploadsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::GetEntityToken(
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

void PlayFabEntityAPI::OnGetEntityTokenResult(int httpStatus, HttpRequest* request, void* userData)
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

void PlayFabEntityAPI::GetFiles(
    GetFilesRequest& request,
    ProcessApiCallback<GetFilesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/File/GetFiles"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetFilesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetFilesResult, userData);
}

void PlayFabEntityAPI::OnGetFilesResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetFilesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetFilesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::GetGlobalPolicy(
    ProcessApiCallback<GetGlobalPolicyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Profile/GetGlobalPolicy"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetGlobalPolicyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGlobalPolicyResult, userData);
}

void PlayFabEntityAPI::OnGetGlobalPolicyResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGlobalPolicyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetGlobalPolicyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::GetGroup(
    GetGroupRequest& request,
    ProcessApiCallback<GetGroupResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/GetGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetGroupResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetGroupResult, userData);
}

void PlayFabEntityAPI::OnGetGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetGroupResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetGroupResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::GetObjects(
    GetObjectsRequest& request,
    ProcessApiCallback<GetObjectsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Object/GetObjects"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetObjectsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetObjectsResult, userData);
}

void PlayFabEntityAPI::OnGetObjectsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetObjectsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetObjectsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::GetProfile(
    GetEntityProfileRequest& request,
    ProcessApiCallback<GetEntityProfileResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Profile/GetProfile"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetEntityProfileResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetProfileResult, userData);
}

void PlayFabEntityAPI::OnGetProfileResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetEntityProfileResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetEntityProfileResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::GetProfiles(
    GetEntityProfilesRequest& request,
    ProcessApiCallback<GetEntityProfilesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Profile/GetProfiles"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetEntityProfilesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetProfilesResult, userData);
}

void PlayFabEntityAPI::OnGetProfilesResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetEntityProfilesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetEntityProfilesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::InitiateFileUploads(
    InitiateFileUploadsRequest& request,
    ProcessApiCallback<InitiateFileUploadsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/File/InitiateFileUploads"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<InitiateFileUploadsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnInitiateFileUploadsResult, userData);
}

void PlayFabEntityAPI::OnInitiateFileUploadsResult(int httpStatus, HttpRequest* request, void* userData)
{
    InitiateFileUploadsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<InitiateFileUploadsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::InviteToGroup(
    InviteToGroupRequest& request,
    ProcessApiCallback<InviteToGroupResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/InviteToGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<InviteToGroupResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnInviteToGroupResult, userData);
}

void PlayFabEntityAPI::OnInviteToGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    InviteToGroupResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<InviteToGroupResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::IsMember(
    IsMemberRequest& request,
    ProcessApiCallback<IsMemberResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/IsMember"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<IsMemberResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnIsMemberResult, userData);
}

void PlayFabEntityAPI::OnIsMemberResult(int httpStatus, HttpRequest* request, void* userData)
{
    IsMemberResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<IsMemberResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ListGroupApplications(
    ListGroupApplicationsRequest& request,
    ProcessApiCallback<ListGroupApplicationsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/ListGroupApplications"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListGroupApplicationsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListGroupApplicationsResult, userData);
}

void PlayFabEntityAPI::OnListGroupApplicationsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListGroupApplicationsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListGroupApplicationsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ListGroupBlocks(
    ListGroupBlocksRequest& request,
    ProcessApiCallback<ListGroupBlocksResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/ListGroupBlocks"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListGroupBlocksResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListGroupBlocksResult, userData);
}

void PlayFabEntityAPI::OnListGroupBlocksResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListGroupBlocksResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListGroupBlocksResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ListGroupInvitations(
    ListGroupInvitationsRequest& request,
    ProcessApiCallback<ListGroupInvitationsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/ListGroupInvitations"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListGroupInvitationsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListGroupInvitationsResult, userData);
}

void PlayFabEntityAPI::OnListGroupInvitationsResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListGroupInvitationsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListGroupInvitationsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ListGroupMembers(
    ListGroupMembersRequest& request,
    ProcessApiCallback<ListGroupMembersResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/ListGroupMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListGroupMembersResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListGroupMembersResult, userData);
}

void PlayFabEntityAPI::OnListGroupMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListGroupMembersResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListGroupMembersResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ListMembership(
    ListMembershipRequest& request,
    ProcessApiCallback<ListMembershipResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/ListMembership"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListMembershipResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListMembershipResult, userData);
}

void PlayFabEntityAPI::OnListMembershipResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListMembershipResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListMembershipResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::ListMembershipOpportunities(
    ListMembershipOpportunitiesRequest& request,
    ProcessApiCallback<ListMembershipOpportunitiesResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/ListMembershipOpportunities"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListMembershipOpportunitiesResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnListMembershipOpportunitiesResult, userData);
}

void PlayFabEntityAPI::OnListMembershipOpportunitiesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListMembershipOpportunitiesResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListMembershipOpportunitiesResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::RemoveGroupApplication(
    RemoveGroupApplicationRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/RemoveGroupApplication"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemoveGroupApplicationResult, userData);
}

void PlayFabEntityAPI::OnRemoveGroupApplicationResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::RemoveGroupInvitation(
    RemoveGroupInvitationRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/RemoveGroupInvitation"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemoveGroupInvitationResult, userData);
}

void PlayFabEntityAPI::OnRemoveGroupInvitationResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::RemoveMembers(
    RemoveMembersRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/RemoveMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemoveMembersResult, userData);
}

void PlayFabEntityAPI::OnRemoveMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::SetGlobalPolicy(
    SetGlobalPolicyRequest& request,
    ProcessApiCallback<SetGlobalPolicyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Profile/SetGlobalPolicy"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetGlobalPolicyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetGlobalPolicyResult, userData);
}

void PlayFabEntityAPI::OnSetGlobalPolicyResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetGlobalPolicyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetGlobalPolicyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::SetObjects(
    SetObjectsRequest& request,
    ProcessApiCallback<SetObjectsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Object/SetObjects"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetObjectsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetObjectsResult, userData);
}

void PlayFabEntityAPI::OnSetObjectsResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetObjectsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetObjectsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::SetProfilePolicy(
    SetEntityProfilePolicyRequest& request,
    ProcessApiCallback<SetEntityProfilePolicyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Profile/SetProfilePolicy"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetEntityProfilePolicyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetProfilePolicyResult, userData);
}

void PlayFabEntityAPI::OnSetProfilePolicyResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetEntityProfilePolicyResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetEntityProfilePolicyResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::UnblockEntity(
    UnblockEntityRequest& request,
    ProcessApiCallback<EmptyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/UnblockEntity"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnblockEntityResult, userData);
}

void PlayFabEntityAPI::OnUnblockEntityResult(int httpStatus, HttpRequest* request, void* userData)
{
    EmptyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EmptyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::UpdateGroup(
    UpdateGroupRequest& request,
    ProcessApiCallback<UpdateGroupResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/UpdateGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateGroupResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateGroupResult, userData);
}

void PlayFabEntityAPI::OnUpdateGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateGroupResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateGroupResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::UpdateRole(
    UpdateGroupRoleRequest& request,
    ProcessApiCallback<UpdateGroupRoleResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Group/UpdateRole"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateGroupRoleResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateRoleResult, userData);
}

void PlayFabEntityAPI::OnUpdateRoleResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateGroupRoleResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateGroupRoleResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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

void PlayFabEntityAPI::WriteEvents(
    WriteEventsRequest& request,
    ProcessApiCallback<WriteEventsResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Event/WriteEvents"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-EntityToken", PlayFabSettings::entityToken);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<WriteEventsResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnWriteEventsResult, userData);
}

void PlayFabEntityAPI::OnWriteEventsResult(int httpStatus, HttpRequest* request, void* userData)
{
    WriteEventsResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<WriteEventsResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
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


