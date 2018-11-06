#include "HttpRequest.h"
#include "HttpRequesterCURL.h"
#include "PlayFabResultHandler.h"
#include "PlayFabSettings.h"
#include "PlayFabServerAPI.h"
#include <string>

using namespace PlayFab;
using namespace PlayFab::ServerModels;

PlayFabServerAPI::PlayFabServerAPI() {}

void PlayFabServerAPI::AddCharacterVirtualCurrency(
    AddCharacterVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/AddCharacterVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ModifyCharacterVirtualCurrencyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddCharacterVirtualCurrencyResult, userData);
}

void PlayFabServerAPI::OnAddCharacterVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyCharacterVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::AddFriend(
    AddFriendRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/AddFriend"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddFriendResult, userData);
}

void PlayFabServerAPI::OnAddFriendResult(int httpStatus, HttpRequest* request, void* userData)
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

void PlayFabServerAPI::AddPlayerTag(
    AddPlayerTagRequest& request,
    ProcessApiCallback<AddPlayerTagResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/AddPlayerTag"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<AddPlayerTagResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddPlayerTagResult, userData);
}

void PlayFabServerAPI::OnAddPlayerTagResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddPlayerTagResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<AddPlayerTagResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::AddSharedGroupMembers(
    AddSharedGroupMembersRequest& request,
    ProcessApiCallback<AddSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/AddSharedGroupMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<AddSharedGroupMembersResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddSharedGroupMembersResult, userData);
}

void PlayFabServerAPI::OnAddSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    AddSharedGroupMembersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<AddSharedGroupMembersResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::AddUserVirtualCurrency(
    AddUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/AddUserVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAddUserVirtualCurrencyResult, userData);
}

void PlayFabServerAPI::OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyUserVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::AuthenticateSessionTicket(
    AuthenticateSessionTicketRequest& request,
    ProcessApiCallback<AuthenticateSessionTicketResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/AuthenticateSessionTicket"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<AuthenticateSessionTicketResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAuthenticateSessionTicketResult, userData);
}

void PlayFabServerAPI::OnAuthenticateSessionTicketResult(int httpStatus, HttpRequest* request, void* userData)
{
    AuthenticateSessionTicketResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<AuthenticateSessionTicketResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::AwardSteamAchievement(
    AwardSteamAchievementRequest& request,
    ProcessApiCallback<AwardSteamAchievementResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/AwardSteamAchievement"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<AwardSteamAchievementResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnAwardSteamAchievementResult, userData);
}

void PlayFabServerAPI::OnAwardSteamAchievementResult(int httpStatus, HttpRequest* request, void* userData)
{
    AwardSteamAchievementResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<AwardSteamAchievementResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::BanUsers(
    BanUsersRequest& request,
    ProcessApiCallback<BanUsersResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/BanUsers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<BanUsersResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnBanUsersResult, userData);
}

void PlayFabServerAPI::OnBanUsersResult(int httpStatus, HttpRequest* request, void* userData)
{
    BanUsersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<BanUsersResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::ConsumeItem(
    ConsumeItemRequest& request,
    ProcessApiCallback<ConsumeItemResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/ConsumeItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ConsumeItemResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnConsumeItemResult, userData);
}

void PlayFabServerAPI::OnConsumeItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    ConsumeItemResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ConsumeItemResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::CreateSharedGroup(
    CreateSharedGroupRequest& request,
    ProcessApiCallback<CreateSharedGroupResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/CreateSharedGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<CreateSharedGroupResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnCreateSharedGroupResult, userData);
}

void PlayFabServerAPI::OnCreateSharedGroupResult(int httpStatus, HttpRequest* request, void* userData)
{
    CreateSharedGroupResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<CreateSharedGroupResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::DeleteCharacterFromUser(
    DeleteCharacterFromUserRequest& request,
    ProcessApiCallback<DeleteCharacterFromUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/DeleteCharacterFromUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<DeleteCharacterFromUserResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteCharacterFromUserResult, userData);
}

void PlayFabServerAPI::OnDeleteCharacterFromUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    DeleteCharacterFromUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<DeleteCharacterFromUserResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::DeletePlayer(
    DeletePlayerRequest& request,
    ProcessApiCallback<DeletePlayerResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/DeletePlayer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<DeletePlayerResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeletePlayerResult, userData);
}

void PlayFabServerAPI::OnDeletePlayerResult(int httpStatus, HttpRequest* request, void* userData)
{
    DeletePlayerResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<DeletePlayerResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::DeleteSharedGroup(
    DeleteSharedGroupRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/DeleteSharedGroup"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeleteSharedGroupResult, userData);
}

void PlayFabServerAPI::OnDeleteSharedGroupResult(int httpStatus, HttpRequest* request, void* userData)
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

void PlayFabServerAPI::DeregisterGame(
    DeregisterGameRequest& request,
    ProcessApiCallback<DeregisterGameResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/DeregisterGame"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<DeregisterGameResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnDeregisterGameResult, userData);
}

void PlayFabServerAPI::OnDeregisterGameResult(int httpStatus, HttpRequest* request, void* userData)
{
    DeregisterGameResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<DeregisterGameResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::EvaluateRandomResultTable(
    EvaluateRandomResultTableRequest& request,
    ProcessApiCallback<EvaluateRandomResultTableResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/EvaluateRandomResultTable"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EvaluateRandomResultTableResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnEvaluateRandomResultTableResult, userData);
}

void PlayFabServerAPI::OnEvaluateRandomResultTableResult(int httpStatus, HttpRequest* request, void* userData)
{
    EvaluateRandomResultTableResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<EvaluateRandomResultTableResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::ExecuteCloudScript(
    ExecuteCloudScriptServerRequest& request,
    ProcessApiCallback<ExecuteCloudScriptResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/ExecuteCloudScript"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ExecuteCloudScriptResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnExecuteCloudScriptResult, userData);
}

void PlayFabServerAPI::OnExecuteCloudScriptResult(int httpStatus, HttpRequest* request, void* userData)
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

void PlayFabServerAPI::GetAllSegments(
    ProcessApiCallback<GetAllSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetAllSegments"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetAllSegmentsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetAllSegmentsResult, userData);
}

void PlayFabServerAPI::OnGetAllSegmentsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetAllSegmentsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetAllSegmentsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetAllUsersCharacters(
    ListUsersCharactersRequest& request,
    ProcessApiCallback<ListUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetAllUsersCharacters"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ListUsersCharactersResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetAllUsersCharactersResult, userData);
}

void PlayFabServerAPI::OnGetAllUsersCharactersResult(int httpStatus, HttpRequest* request, void* userData)
{
    ListUsersCharactersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ListUsersCharactersResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetCatalogItems(
    GetCatalogItemsRequest& request,
    ProcessApiCallback<GetCatalogItemsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetCatalogItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetCatalogItemsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCatalogItemsResult, userData);
}

void PlayFabServerAPI::OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCatalogItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetCatalogItemsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetCharacterData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetCharacterData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetCharacterDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterDataResult, userData);
}

void PlayFabServerAPI::OnGetCharacterDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetCharacterInternalData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetCharacterInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetCharacterDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterInternalDataResult, userData);
}

void PlayFabServerAPI::OnGetCharacterInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetCharacterInventory(
    GetCharacterInventoryRequest& request,
    ProcessApiCallback<GetCharacterInventoryResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetCharacterInventory"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetCharacterInventoryResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterInventoryResult, userData);
}

void PlayFabServerAPI::OnGetCharacterInventoryResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterInventoryResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetCharacterInventoryResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetCharacterLeaderboard(
    GetCharacterLeaderboardRequest& request,
    ProcessApiCallback<GetCharacterLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetCharacterLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetCharacterLeaderboardResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterLeaderboardResult, userData);
}

void PlayFabServerAPI::OnGetCharacterLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterLeaderboardResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetCharacterLeaderboardResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetCharacterReadOnlyData(
    GetCharacterDataRequest& request,
    ProcessApiCallback<GetCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetCharacterReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetCharacterDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterReadOnlyDataResult, userData);
}

void PlayFabServerAPI::OnGetCharacterReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetCharacterDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetCharacterStatistics(
    GetCharacterStatisticsRequest& request,
    ProcessApiCallback<GetCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetCharacterStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetCharacterStatisticsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetCharacterStatisticsResult, userData);
}

void PlayFabServerAPI::OnGetCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetCharacterStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetCharacterStatisticsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetContentDownloadUrl(
    GetContentDownloadUrlRequest& request,
    ProcessApiCallback<GetContentDownloadUrlResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetContentDownloadUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetContentDownloadUrlResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetContentDownloadUrlResult, userData);
}

void PlayFabServerAPI::OnGetContentDownloadUrlResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetContentDownloadUrlResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetContentDownloadUrlResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetFriendLeaderboard(
    GetFriendLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetFriendLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetLeaderboardResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetFriendLeaderboardResult, userData);
}

void PlayFabServerAPI::OnGetFriendLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetFriendsList(
    GetFriendsListRequest& request,
    ProcessApiCallback<GetFriendsListResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetFriendsList"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetFriendsListResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetFriendsListResult, userData);
}

void PlayFabServerAPI::OnGetFriendsListResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetFriendsListResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetFriendsListResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetLeaderboard(
    GetLeaderboardRequest& request,
    ProcessApiCallback<GetLeaderboardResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetLeaderboard"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetLeaderboardResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardResult, userData);
}

void PlayFabServerAPI::OnGetLeaderboardResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetLeaderboardResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetLeaderboardAroundCharacter(
    GetLeaderboardAroundCharacterRequest& request,
    ProcessApiCallback<GetLeaderboardAroundCharacterResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetLeaderboardAroundCharacter"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetLeaderboardAroundCharacterResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardAroundCharacterResult, userData);
}

void PlayFabServerAPI::OnGetLeaderboardAroundCharacterResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardAroundCharacterResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetLeaderboardAroundCharacterResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetLeaderboardAroundUser(
    GetLeaderboardAroundUserRequest& request,
    ProcessApiCallback<GetLeaderboardAroundUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetLeaderboardAroundUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetLeaderboardAroundUserResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardAroundUserResult, userData);
}

void PlayFabServerAPI::OnGetLeaderboardAroundUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardAroundUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetLeaderboardAroundUserResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetLeaderboardForUserCharacters(
    GetLeaderboardForUsersCharactersRequest& request,
    ProcessApiCallback<GetLeaderboardForUsersCharactersResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetLeaderboardForUserCharacters"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetLeaderboardForUsersCharactersResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetLeaderboardForUserCharactersResult, userData);
}

void PlayFabServerAPI::OnGetLeaderboardForUserCharactersResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetLeaderboardForUsersCharactersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetLeaderboardForUsersCharactersResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayerCombinedInfo(
    GetPlayerCombinedInfoRequest& request,
    ProcessApiCallback<GetPlayerCombinedInfoResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayerCombinedInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayerCombinedInfoResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerCombinedInfoResult, userData);
}

void PlayFabServerAPI::OnGetPlayerCombinedInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerCombinedInfoResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayerCombinedInfoResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayerProfile(
    GetPlayerProfileRequest& request,
    ProcessApiCallback<GetPlayerProfileResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayerProfile"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayerProfileResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerProfileResult, userData);
}

void PlayFabServerAPI::OnGetPlayerProfileResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerProfileResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayerProfileResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayerSegments(
    GetPlayersSegmentsRequest& request,
    ProcessApiCallback<GetPlayerSegmentsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayerSegments"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayerSegmentsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerSegmentsResult, userData);
}

void PlayFabServerAPI::OnGetPlayerSegmentsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerSegmentsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayerSegmentsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayersInSegment(
    GetPlayersInSegmentRequest& request,
    ProcessApiCallback<GetPlayersInSegmentResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayersInSegment"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayersInSegmentResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayersInSegmentResult, userData);
}

void PlayFabServerAPI::OnGetPlayersInSegmentResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayersInSegmentResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayersInSegmentResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayerStatistics(
    GetPlayerStatisticsRequest& request,
    ProcessApiCallback<GetPlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayerStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayerStatisticsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerStatisticsResult, userData);
}

void PlayFabServerAPI::OnGetPlayerStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayerStatisticsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayerStatisticVersions(
    GetPlayerStatisticVersionsRequest& request,
    ProcessApiCallback<GetPlayerStatisticVersionsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayerStatisticVersions"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayerStatisticVersionsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerStatisticVersionsResult, userData);
}

void PlayFabServerAPI::OnGetPlayerStatisticVersionsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerStatisticVersionsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayerStatisticVersionsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayerTags(
    GetPlayerTagsRequest& request,
    ProcessApiCallback<GetPlayerTagsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayerTags"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayerTagsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayerTagsResult, userData);
}

void PlayFabServerAPI::OnGetPlayerTagsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayerTagsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayerTagsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayFabIDsFromFacebookIDs(
    GetPlayFabIDsFromFacebookIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayFabIDsFromFacebookIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromFacebookIDsResult, userData);
}

void PlayFabServerAPI::OnGetPlayFabIDsFromFacebookIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromFacebookIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookIDsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayFabIDsFromFacebookInstantGamesIds(
    GetPlayFabIDsFromFacebookInstantGamesIdsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayFabIDsFromFacebookInstantGamesIds"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromFacebookInstantGamesIdsResult, userData);
}

void PlayFabServerAPI::OnGetPlayFabIDsFromFacebookInstantGamesIdsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromFacebookInstantGamesIdsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayFabIDsFromFacebookInstantGamesIdsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayFabIDsFromNintendoSwitchDeviceIds(
    GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayFabIDsFromNintendoSwitchDeviceIds"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult, userData);
}

void PlayFabServerAPI::OnGetPlayFabIDsFromNintendoSwitchDeviceIdsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromNintendoSwitchDeviceIdsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayFabIDsFromNintendoSwitchDeviceIdsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayFabIDsFromSteamIDs(
    GetPlayFabIDsFromSteamIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayFabIDsFromSteamIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromSteamIDsResult, userData);
}

void PlayFabServerAPI::OnGetPlayFabIDsFromSteamIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromSteamIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayFabIDsFromSteamIDsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPlayFabIDsFromXboxLiveIDs(
    GetPlayFabIDsFromXboxLiveIDsRequest& request,
    ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPlayFabIDsFromXboxLiveIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPlayFabIDsFromXboxLiveIDsResult, userData);
}

void PlayFabServerAPI::OnGetPlayFabIDsFromXboxLiveIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPlayFabIDsFromXboxLiveIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPlayFabIDsFromXboxLiveIDsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetPublisherData(
    GetPublisherDataRequest& request,
    ProcessApiCallback<GetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetPublisherDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetPublisherDataResult, userData);
}

void PlayFabServerAPI::OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetPublisherDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetPublisherDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetRandomResultTables(
    GetRandomResultTablesRequest& request,
    ProcessApiCallback<GetRandomResultTablesResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetRandomResultTables"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetRandomResultTablesResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetRandomResultTablesResult, userData);
}

void PlayFabServerAPI::OnGetRandomResultTablesResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetRandomResultTablesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetRandomResultTablesResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetServerCustomIDsFromPlayFabIDs(
    GetServerCustomIDsFromPlayFabIDsRequest& request,
    ProcessApiCallback<GetServerCustomIDsFromPlayFabIDsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetServerCustomIDsFromPlayFabIDs"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetServerCustomIDsFromPlayFabIDsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetServerCustomIDsFromPlayFabIDsResult, userData);
}

void PlayFabServerAPI::OnGetServerCustomIDsFromPlayFabIDsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetServerCustomIDsFromPlayFabIDsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetServerCustomIDsFromPlayFabIDsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetSharedGroupData(
    GetSharedGroupDataRequest& request,
    ProcessApiCallback<GetSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetSharedGroupData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetSharedGroupDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetSharedGroupDataResult, userData);
}

void PlayFabServerAPI::OnGetSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetSharedGroupDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetSharedGroupDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetTime(
    ProcessApiCallback<GetTimeResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetTime"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetTimeResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody("{}");
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetTimeResult, userData);
}

void PlayFabServerAPI::OnGetTimeResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTimeResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetTimeResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetTitleData(
    GetTitleDataRequest& request,
    ProcessApiCallback<GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetTitleData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetTitleDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetTitleDataResult, userData);
}

void PlayFabServerAPI::OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetTitleDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetTitleInternalData(
    GetTitleDataRequest& request,
    ProcessApiCallback<GetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetTitleInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetTitleDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetTitleInternalDataResult, userData);
}

void PlayFabServerAPI::OnGetTitleInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetTitleDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetTitleNews(
    GetTitleNewsRequest& request,
    ProcessApiCallback<GetTitleNewsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetTitleNews"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetTitleNewsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetTitleNewsResult, userData);
}

void PlayFabServerAPI::OnGetTitleNewsResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetTitleNewsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetTitleNewsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserAccountInfo(
    GetUserAccountInfoRequest& request,
    ProcessApiCallback<GetUserAccountInfoResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserAccountInfo"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserAccountInfoResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserAccountInfoResult, userData);
}

void PlayFabServerAPI::OnGetUserAccountInfoResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserAccountInfoResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserAccountInfoResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserBans(
    GetUserBansRequest& request,
    ProcessApiCallback<GetUserBansResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserBans"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserBansResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserBansResult, userData);
}

void PlayFabServerAPI::OnGetUserBansResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserBansResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserBansResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserDataResult, userData);
}

void PlayFabServerAPI::OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserInternalData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserInternalDataResult, userData);
}

void PlayFabServerAPI::OnGetUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserInventory(
    GetUserInventoryRequest& request,
    ProcessApiCallback<GetUserInventoryResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserInventory"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserInventoryResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserInventoryResult, userData);
}

void PlayFabServerAPI::OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserInventoryResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserInventoryResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserPublisherData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserPublisherDataResult, userData);
}

void PlayFabServerAPI::OnGetUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserPublisherInternalData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserPublisherInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserPublisherInternalDataResult, userData);
}

void PlayFabServerAPI::OnGetUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserPublisherReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserPublisherReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserPublisherReadOnlyDataResult, userData);
}

void PlayFabServerAPI::OnGetUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GetUserReadOnlyData(
    GetUserDataRequest& request,
    ProcessApiCallback<GetUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GetUserReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GetUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGetUserReadOnlyDataResult, userData);
}

void PlayFabServerAPI::OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    GetUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GetUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GrantCharacterToUser(
    GrantCharacterToUserRequest& request,
    ProcessApiCallback<GrantCharacterToUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GrantCharacterToUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GrantCharacterToUserResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGrantCharacterToUserResult, userData);
}

void PlayFabServerAPI::OnGrantCharacterToUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    GrantCharacterToUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GrantCharacterToUserResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GrantItemsToCharacter(
    GrantItemsToCharacterRequest& request,
    ProcessApiCallback<GrantItemsToCharacterResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GrantItemsToCharacter"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GrantItemsToCharacterResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGrantItemsToCharacterResult, userData);
}

void PlayFabServerAPI::OnGrantItemsToCharacterResult(int httpStatus, HttpRequest* request, void* userData)
{
    GrantItemsToCharacterResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GrantItemsToCharacterResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GrantItemsToUser(
    GrantItemsToUserRequest& request,
    ProcessApiCallback<GrantItemsToUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GrantItemsToUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GrantItemsToUserResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGrantItemsToUserResult, userData);
}

void PlayFabServerAPI::OnGrantItemsToUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    GrantItemsToUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GrantItemsToUserResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::GrantItemsToUsers(
    GrantItemsToUsersRequest& request,
    ProcessApiCallback<GrantItemsToUsersResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/GrantItemsToUsers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<GrantItemsToUsersResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnGrantItemsToUsersResult, userData);
}

void PlayFabServerAPI::OnGrantItemsToUsersResult(int httpStatus, HttpRequest* request, void* userData)
{
    GrantItemsToUsersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<GrantItemsToUsersResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::LinkXboxAccount(
    LinkXboxAccountRequest& request,
    ProcessApiCallback<LinkXboxAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/LinkXboxAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<LinkXboxAccountResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLinkXboxAccountResult, userData);
}

void PlayFabServerAPI::OnLinkXboxAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    LinkXboxAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<LinkXboxAccountResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::LoginWithServerCustomId(
    LoginWithServerCustomIdRequest& request,
    ProcessApiCallback<ServerLoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/LoginWithServerCustomId"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ServerLoginResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithServerCustomIdResult, userData);
}

void PlayFabServerAPI::OnLoginWithServerCustomIdResult(int httpStatus, HttpRequest* request, void* userData)
{
    ServerLoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ServerLoginResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::LoginWithXbox(
    LoginWithXboxRequest& request,
    ProcessApiCallback<ServerLoginResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/LoginWithXbox"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ServerLoginResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnLoginWithXboxResult, userData);
}

void PlayFabServerAPI::OnLoginWithXboxResult(int httpStatus, HttpRequest* request, void* userData)
{
    ServerLoginResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ServerLoginResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::ModifyItemUses(
    ModifyItemUsesRequest& request,
    ProcessApiCallback<ModifyItemUsesResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/ModifyItemUses"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ModifyItemUsesResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnModifyItemUsesResult, userData);
}

void PlayFabServerAPI::OnModifyItemUsesResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyItemUsesResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ModifyItemUsesResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::MoveItemToCharacterFromCharacter(
    MoveItemToCharacterFromCharacterRequest& request,
    ProcessApiCallback<MoveItemToCharacterFromCharacterResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/MoveItemToCharacterFromCharacter"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<MoveItemToCharacterFromCharacterResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnMoveItemToCharacterFromCharacterResult, userData);
}

void PlayFabServerAPI::OnMoveItemToCharacterFromCharacterResult(int httpStatus, HttpRequest* request, void* userData)
{
    MoveItemToCharacterFromCharacterResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<MoveItemToCharacterFromCharacterResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::MoveItemToCharacterFromUser(
    MoveItemToCharacterFromUserRequest& request,
    ProcessApiCallback<MoveItemToCharacterFromUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/MoveItemToCharacterFromUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<MoveItemToCharacterFromUserResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnMoveItemToCharacterFromUserResult, userData);
}

void PlayFabServerAPI::OnMoveItemToCharacterFromUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    MoveItemToCharacterFromUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<MoveItemToCharacterFromUserResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::MoveItemToUserFromCharacter(
    MoveItemToUserFromCharacterRequest& request,
    ProcessApiCallback<MoveItemToUserFromCharacterResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/MoveItemToUserFromCharacter"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<MoveItemToUserFromCharacterResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnMoveItemToUserFromCharacterResult, userData);
}

void PlayFabServerAPI::OnMoveItemToUserFromCharacterResult(int httpStatus, HttpRequest* request, void* userData)
{
    MoveItemToUserFromCharacterResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<MoveItemToUserFromCharacterResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::NotifyMatchmakerPlayerLeft(
    NotifyMatchmakerPlayerLeftRequest& request,
    ProcessApiCallback<NotifyMatchmakerPlayerLeftResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/NotifyMatchmakerPlayerLeft"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<NotifyMatchmakerPlayerLeftResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnNotifyMatchmakerPlayerLeftResult, userData);
}

void PlayFabServerAPI::OnNotifyMatchmakerPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData)
{
    NotifyMatchmakerPlayerLeftResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<NotifyMatchmakerPlayerLeftResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RedeemCoupon(
    RedeemCouponRequest& request,
    ProcessApiCallback<RedeemCouponResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RedeemCoupon"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RedeemCouponResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRedeemCouponResult, userData);
}

void PlayFabServerAPI::OnRedeemCouponResult(int httpStatus, HttpRequest* request, void* userData)
{
    RedeemCouponResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RedeemCouponResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RedeemMatchmakerTicket(
    RedeemMatchmakerTicketRequest& request,
    ProcessApiCallback<RedeemMatchmakerTicketResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RedeemMatchmakerTicket"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RedeemMatchmakerTicketResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRedeemMatchmakerTicketResult, userData);
}

void PlayFabServerAPI::OnRedeemMatchmakerTicketResult(int httpStatus, HttpRequest* request, void* userData)
{
    RedeemMatchmakerTicketResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RedeemMatchmakerTicketResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RefreshGameServerInstanceHeartbeat(
    RefreshGameServerInstanceHeartbeatRequest& request,
    ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RefreshGameServerInstanceHeartbeat"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRefreshGameServerInstanceHeartbeatResult, userData);
}

void PlayFabServerAPI::OnRefreshGameServerInstanceHeartbeatResult(int httpStatus, HttpRequest* request, void* userData)
{
    RefreshGameServerInstanceHeartbeatResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RefreshGameServerInstanceHeartbeatResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RegisterGame(
    RegisterGameRequest& request,
    ProcessApiCallback<RegisterGameResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RegisterGame"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RegisterGameResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRegisterGameResult, userData);
}

void PlayFabServerAPI::OnRegisterGameResult(int httpStatus, HttpRequest* request, void* userData)
{
    RegisterGameResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RegisterGameResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RemoveFriend(
    RemoveFriendRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RemoveFriend"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemoveFriendResult, userData);
}

void PlayFabServerAPI::OnRemoveFriendResult(int httpStatus, HttpRequest* request, void* userData)
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

void PlayFabServerAPI::RemovePlayerTag(
    RemovePlayerTagRequest& request,
    ProcessApiCallback<RemovePlayerTagResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RemovePlayerTag"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RemovePlayerTagResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemovePlayerTagResult, userData);
}

void PlayFabServerAPI::OnRemovePlayerTagResult(int httpStatus, HttpRequest* request, void* userData)
{
    RemovePlayerTagResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RemovePlayerTagResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RemoveSharedGroupMembers(
    RemoveSharedGroupMembersRequest& request,
    ProcessApiCallback<RemoveSharedGroupMembersResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RemoveSharedGroupMembers"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RemoveSharedGroupMembersResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRemoveSharedGroupMembersResult, userData);
}

void PlayFabServerAPI::OnRemoveSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData)
{
    RemoveSharedGroupMembersResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RemoveSharedGroupMembersResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::ReportPlayer(
    ReportPlayerServerRequest& request,
    ProcessApiCallback<ReportPlayerServerResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/ReportPlayer"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ReportPlayerServerResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnReportPlayerResult, userData);
}

void PlayFabServerAPI::OnReportPlayerResult(int httpStatus, HttpRequest* request, void* userData)
{
    ReportPlayerServerResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ReportPlayerServerResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RevokeAllBansForUser(
    RevokeAllBansForUserRequest& request,
    ProcessApiCallback<RevokeAllBansForUserResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RevokeAllBansForUser"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RevokeAllBansForUserResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRevokeAllBansForUserResult, userData);
}

void PlayFabServerAPI::OnRevokeAllBansForUserResult(int httpStatus, HttpRequest* request, void* userData)
{
    RevokeAllBansForUserResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RevokeAllBansForUserResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RevokeBans(
    RevokeBansRequest& request,
    ProcessApiCallback<RevokeBansResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RevokeBans"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RevokeBansResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRevokeBansResult, userData);
}

void PlayFabServerAPI::OnRevokeBansResult(int httpStatus, HttpRequest* request, void* userData)
{
    RevokeBansResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RevokeBansResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RevokeInventoryItem(
    RevokeInventoryItemRequest& request,
    ProcessApiCallback<RevokeInventoryResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RevokeInventoryItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RevokeInventoryResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRevokeInventoryItemResult, userData);
}

void PlayFabServerAPI::OnRevokeInventoryItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    RevokeInventoryResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RevokeInventoryResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::RevokeInventoryItems(
    RevokeInventoryItemsRequest& request,
    ProcessApiCallback<RevokeInventoryItemsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/RevokeInventoryItems"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<RevokeInventoryItemsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnRevokeInventoryItemsResult, userData);
}

void PlayFabServerAPI::OnRevokeInventoryItemsResult(int httpStatus, HttpRequest* request, void* userData)
{
    RevokeInventoryItemsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<RevokeInventoryItemsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SendCustomAccountRecoveryEmail(
    SendCustomAccountRecoveryEmailRequest& request,
    ProcessApiCallback<SendCustomAccountRecoveryEmailResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SendCustomAccountRecoveryEmail"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SendCustomAccountRecoveryEmailResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSendCustomAccountRecoveryEmailResult, userData);
}

void PlayFabServerAPI::OnSendCustomAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData)
{
    SendCustomAccountRecoveryEmailResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SendCustomAccountRecoveryEmailResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SendEmailFromTemplate(
    SendEmailFromTemplateRequest& request,
    ProcessApiCallback<SendEmailFromTemplateResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SendEmailFromTemplate"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SendEmailFromTemplateResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSendEmailFromTemplateResult, userData);
}

void PlayFabServerAPI::OnSendEmailFromTemplateResult(int httpStatus, HttpRequest* request, void* userData)
{
    SendEmailFromTemplateResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SendEmailFromTemplateResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SendPushNotification(
    SendPushNotificationRequest& request,
    ProcessApiCallback<SendPushNotificationResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SendPushNotification"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SendPushNotificationResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSendPushNotificationResult, userData);
}

void PlayFabServerAPI::OnSendPushNotificationResult(int httpStatus, HttpRequest* request, void* userData)
{
    SendPushNotificationResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SendPushNotificationResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SetFriendTags(
    SetFriendTagsRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SetFriendTags"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetFriendTagsResult, userData);
}

void PlayFabServerAPI::OnSetFriendTagsResult(int httpStatus, HttpRequest* request, void* userData)
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

void PlayFabServerAPI::SetGameServerInstanceData(
    SetGameServerInstanceDataRequest& request,
    ProcessApiCallback<SetGameServerInstanceDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SetGameServerInstanceData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetGameServerInstanceDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetGameServerInstanceDataResult, userData);
}

void PlayFabServerAPI::OnSetGameServerInstanceDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetGameServerInstanceDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetGameServerInstanceDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SetGameServerInstanceState(
    SetGameServerInstanceStateRequest& request,
    ProcessApiCallback<SetGameServerInstanceStateResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SetGameServerInstanceState"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetGameServerInstanceStateResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetGameServerInstanceStateResult, userData);
}

void PlayFabServerAPI::OnSetGameServerInstanceStateResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetGameServerInstanceStateResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetGameServerInstanceStateResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SetGameServerInstanceTags(
    SetGameServerInstanceTagsRequest& request,
    ProcessApiCallback<SetGameServerInstanceTagsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SetGameServerInstanceTags"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetGameServerInstanceTagsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetGameServerInstanceTagsResult, userData);
}

void PlayFabServerAPI::OnSetGameServerInstanceTagsResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetGameServerInstanceTagsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetGameServerInstanceTagsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SetPlayerSecret(
    SetPlayerSecretRequest& request,
    ProcessApiCallback<SetPlayerSecretResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SetPlayerSecret"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetPlayerSecretResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetPlayerSecretResult, userData);
}

void PlayFabServerAPI::OnSetPlayerSecretResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetPlayerSecretResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetPlayerSecretResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SetPublisherData(
    SetPublisherDataRequest& request,
    ProcessApiCallback<SetPublisherDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SetPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetPublisherDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetPublisherDataResult, userData);
}

void PlayFabServerAPI::OnSetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetPublisherDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetPublisherDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SetTitleData(
    SetTitleDataRequest& request,
    ProcessApiCallback<SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SetTitleData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetTitleDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetTitleDataResult, userData);
}

void PlayFabServerAPI::OnSetTitleDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetTitleDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetTitleDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SetTitleInternalData(
    SetTitleDataRequest& request,
    ProcessApiCallback<SetTitleDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SetTitleInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<SetTitleDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSetTitleInternalDataResult, userData);
}

void PlayFabServerAPI::OnSetTitleInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    SetTitleDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<SetTitleDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SubtractCharacterVirtualCurrency(
    SubtractCharacterVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SubtractCharacterVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ModifyCharacterVirtualCurrencyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSubtractCharacterVirtualCurrencyResult, userData);
}

void PlayFabServerAPI::OnSubtractCharacterVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyCharacterVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ModifyCharacterVirtualCurrencyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::SubtractUserVirtualCurrency(
    SubtractUserVirtualCurrencyRequest& request,
    ProcessApiCallback<ModifyUserVirtualCurrencyResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/SubtractUserVirtualCurrency"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<ModifyUserVirtualCurrencyResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnSubtractUserVirtualCurrencyResult, userData);
}

void PlayFabServerAPI::OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData)
{
    ModifyUserVirtualCurrencyResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<ModifyUserVirtualCurrencyResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UnlinkXboxAccount(
    UnlinkXboxAccountRequest& request,
    ProcessApiCallback<UnlinkXboxAccountResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UnlinkXboxAccount"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UnlinkXboxAccountResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlinkXboxAccountResult, userData);
}

void PlayFabServerAPI::OnUnlinkXboxAccountResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlinkXboxAccountResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UnlinkXboxAccountResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UnlockContainerInstance(
    UnlockContainerInstanceRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UnlockContainerInstance"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UnlockContainerItemResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlockContainerInstanceResult, userData);
}

void PlayFabServerAPI::OnUnlockContainerInstanceResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlockContainerItemResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UnlockContainerItem(
    UnlockContainerItemRequest& request,
    ProcessApiCallback<UnlockContainerItemResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UnlockContainerItem"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UnlockContainerItemResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUnlockContainerItemResult, userData);
}

void PlayFabServerAPI::OnUnlockContainerItemResult(int httpStatus, HttpRequest* request, void* userData)
{
    UnlockContainerItemResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UnlockContainerItemResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateAvatarUrl(
    UpdateAvatarUrlRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateAvatarUrl"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateAvatarUrlResult, userData);
}

void PlayFabServerAPI::OnUpdateAvatarUrlResult(int httpStatus, HttpRequest* request, void* userData)
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

void PlayFabServerAPI::UpdateBans(
    UpdateBansRequest& request,
    ProcessApiCallback<UpdateBansResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateBans"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateBansResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateBansResult, userData);
}

void PlayFabServerAPI::OnUpdateBansResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateBansResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateBansResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateCharacterData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateCharacterData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateCharacterDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateCharacterDataResult, userData);
}

void PlayFabServerAPI::OnUpdateCharacterDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateCharacterInternalData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateCharacterInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateCharacterDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateCharacterInternalDataResult, userData);
}

void PlayFabServerAPI::OnUpdateCharacterInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateCharacterReadOnlyData(
    UpdateCharacterDataRequest& request,
    ProcessApiCallback<UpdateCharacterDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateCharacterReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateCharacterDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateCharacterReadOnlyDataResult, userData);
}

void PlayFabServerAPI::OnUpdateCharacterReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCharacterDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateCharacterDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateCharacterStatistics(
    UpdateCharacterStatisticsRequest& request,
    ProcessApiCallback<UpdateCharacterStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateCharacterStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateCharacterStatisticsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateCharacterStatisticsResult, userData);
}

void PlayFabServerAPI::OnUpdateCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateCharacterStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateCharacterStatisticsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdatePlayerStatistics(
    UpdatePlayerStatisticsRequest& request,
    ProcessApiCallback<UpdatePlayerStatisticsResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdatePlayerStatistics"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdatePlayerStatisticsResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdatePlayerStatisticsResult, userData);
}

void PlayFabServerAPI::OnUpdatePlayerStatisticsResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdatePlayerStatisticsResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdatePlayerStatisticsResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateSharedGroupData(
    UpdateSharedGroupDataRequest& request,
    ProcessApiCallback<UpdateSharedGroupDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateSharedGroupData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateSharedGroupDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateSharedGroupDataResult, userData);
}

void PlayFabServerAPI::OnUpdateSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateSharedGroupDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateSharedGroupDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateUserData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateUserData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserDataResult, userData);
}

void PlayFabServerAPI::OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateUserInternalData(
    UpdateUserInternalDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateUserInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserInternalDataResult, userData);
}

void PlayFabServerAPI::OnUpdateUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateUserInventoryItemCustomData(
    UpdateUserInventoryItemDataRequest& request,
    ProcessApiCallback<EmptyResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateUserInventoryItemCustomData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<EmptyResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserInventoryItemCustomDataResult, userData);
}

void PlayFabServerAPI::OnUpdateUserInventoryItemCustomDataResult(int httpStatus, HttpRequest* request, void* userData)
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

void PlayFabServerAPI::UpdateUserPublisherData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateUserPublisherData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserPublisherDataResult, userData);
}

void PlayFabServerAPI::OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateUserPublisherInternalData(
    UpdateUserInternalDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateUserPublisherInternalData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserPublisherInternalDataResult, userData);
}

void PlayFabServerAPI::OnUpdateUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateUserPublisherReadOnlyData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateUserPublisherReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserPublisherReadOnlyDataResult, userData);
}

void PlayFabServerAPI::OnUpdateUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::UpdateUserReadOnlyData(
    UpdateUserDataRequest& request,
    ProcessApiCallback<UpdateUserDataResult> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/UpdateUserReadOnlyData"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<UpdateUserDataResult>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnUpdateUserReadOnlyDataResult, userData);
}

void PlayFabServerAPI::OnUpdateUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData)
{
    UpdateUserDataResult outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<UpdateUserDataResult> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::WriteCharacterEvent(
    WriteServerCharacterEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/WriteCharacterEvent"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<WriteEventResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnWriteCharacterEventResult, userData);
}

void PlayFabServerAPI::OnWriteCharacterEventResult(int httpStatus, HttpRequest* request, void* userData)
{
    WriteEventResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<WriteEventResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::WritePlayerEvent(
    WriteServerPlayerEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/WritePlayerEvent"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<WriteEventResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnWritePlayerEventResult, userData);
}

void PlayFabServerAPI::OnWritePlayerEventResult(int httpStatus, HttpRequest* request, void* userData)
{
    WriteEventResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<WriteEventResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}

void PlayFabServerAPI::WriteTitleEvent(
    WriteTitleEventRequest& request,
    ProcessApiCallback<WriteEventResponse> callback,
    ErrorCallback errorCallback,
    void* userData
)
{
    HttpRequest* httpRequest = new HttpRequest("POST", PlayFabSettings::getURL("/Server/WriteTitleEvent"));
    httpRequest->SetHeader("Content-Type", "application/json");
    httpRequest->SetHeader("X-PlayFabSDK", PlayFabSettings::versionString);
    httpRequest->SetHeader("X-SecretKey", PlayFabSettings::developerSecretKey);

    if (callback != nullptr)
        httpRequest->SetResultCallback(SharedVoidPointer(new ProcessApiCallback<WriteEventResponse>(callback)));
    httpRequest->SetErrorCallback(errorCallback);
    httpRequest->SetUserData(userData);

    httpRequest->SetBody(request.toJSONString());
    httpRequest->CompressBody();

    PlayFabSettings::httpRequester->AddRequest(httpRequest, OnWriteTitleEventResult, userData);
}

void PlayFabServerAPI::OnWriteTitleEventResult(int httpStatus, HttpRequest* request, void* userData)
{
    WriteEventResponse outResult;
    PlayFabError errorResult;

    if (PlayFabRequestHandler::DecodeRequest(httpStatus, request, userData, outResult, errorResult))
    {
        if (request->GetResultCallback() != nullptr)
        {
            (*static_cast<ProcessApiCallback<WriteEventResponse> *>(request->GetResultCallback().get()))(outResult, request->GetUserData());
        }
    }
    else
    {
        if (PlayFabSettings::globalErrorHandler != nullptr)
            PlayFabSettings::globalErrorHandler(errorResult, request->GetUserData());
        if (request->GetErrorCallback() != nullptr)
            request->GetErrorCallback()(errorResult, request->GetUserData());
    }

    delete request;
}


