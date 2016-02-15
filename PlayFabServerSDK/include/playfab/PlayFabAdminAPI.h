#ifndef PLAYFAB_ADMINAPI_H_
#define PLAYFAB_ADMINAPI_H_

#include "playfab/IHttpRequester.h"
#include "playfab/PlayFabError.h"
#include "playfab/PlayFabAdminDataModels.h"
#include "playfab/PlayFabSettings.h"
#include <string>

namespace PlayFab
{
    class PlayFabAdminAPI
    {
    public:
        typedef void(*GetUserAccountInfoCallback)(AdminModels::LookupUserAccountInfoResult& result, void* userData);
        typedef void(*ResetUsersCallback)(AdminModels::BlankResult& result, void* userData);
        typedef void(*SendAccountRecoveryEmailCallback)(AdminModels::SendAccountRecoveryEmailResult& result, void* userData);
        typedef void(*UpdateUserTitleDisplayNameCallback)(AdminModels::UpdateUserTitleDisplayNameResult& result, void* userData);
        typedef void(*CreatePlayerStatisticDefinitionCallback)(AdminModels::CreatePlayerStatisticDefinitionResult& result, void* userData);
        typedef void(*DeleteUsersCallback)(AdminModels::DeleteUsersResult& result, void* userData);
        typedef void(*GetDataReportCallback)(AdminModels::GetDataReportResult& result, void* userData);
        typedef void(*GetPlayerStatisticDefinitionsCallback)(AdminModels::GetPlayerStatisticDefinitionsResult& result, void* userData);
        typedef void(*GetPlayerStatisticVersionsCallback)(AdminModels::GetPlayerStatisticVersionsResult& result, void* userData);
        typedef void(*GetUserDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
        typedef void(*GetUserInternalDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
        typedef void(*GetUserPublisherDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
        typedef void(*GetUserPublisherInternalDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
        typedef void(*GetUserPublisherReadOnlyDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
        typedef void(*GetUserReadOnlyDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
        typedef void(*IncrementPlayerStatisticVersionCallback)(AdminModels::IncrementPlayerStatisticVersionResult& result, void* userData);
        typedef void(*ResetUserStatisticsCallback)(AdminModels::ResetUserStatisticsResult& result, void* userData);
        typedef void(*UpdatePlayerStatisticDefinitionCallback)(AdminModels::UpdatePlayerStatisticDefinitionResult& result, void* userData);
        typedef void(*UpdateUserDataCallback)(AdminModels::UpdateUserDataResult& result, void* userData);
        typedef void(*UpdateUserInternalDataCallback)(AdminModels::UpdateUserDataResult& result, void* userData);
        typedef void(*UpdateUserPublisherDataCallback)(AdminModels::UpdateUserDataResult& result, void* userData);
        typedef void(*UpdateUserPublisherInternalDataCallback)(AdminModels::UpdateUserDataResult& result, void* userData);
        typedef void(*UpdateUserPublisherReadOnlyDataCallback)(AdminModels::UpdateUserDataResult& result, void* userData);
        typedef void(*UpdateUserReadOnlyDataCallback)(AdminModels::UpdateUserDataResult& result, void* userData);
        typedef void(*AddNewsCallback)(AdminModels::AddNewsResult& result, void* userData);
        typedef void(*AddVirtualCurrencyTypesCallback)(AdminModels::BlankResult& result, void* userData);
        typedef void(*GetCatalogItemsCallback)(AdminModels::GetCatalogItemsResult& result, void* userData);
        typedef void(*GetRandomResultTablesCallback)(AdminModels::GetRandomResultTablesResult& result, void* userData);
        typedef void(*GetStoreItemsCallback)(AdminModels::GetStoreItemsResult& result, void* userData);
        typedef void(*GetTitleDataCallback)(AdminModels::GetTitleDataResult& result, void* userData);
        typedef void(*ListVirtualCurrencyTypesCallback)(AdminModels::ListVirtualCurrencyTypesResult& result, void* userData);
        typedef void(*SetCatalogItemsCallback)(AdminModels::UpdateCatalogItemsResult& result, void* userData);
        typedef void(*SetStoreItemsCallback)(AdminModels::UpdateStoreItemsResult& result, void* userData);
        typedef void(*SetTitleDataCallback)(AdminModels::SetTitleDataResult& result, void* userData);
        typedef void(*SetupPushNotificationCallback)(AdminModels::SetupPushNotificationResult& result, void* userData);
        typedef void(*UpdateCatalogItemsCallback)(AdminModels::UpdateCatalogItemsResult& result, void* userData);
        typedef void(*UpdateRandomResultTablesCallback)(AdminModels::UpdateRandomResultTablesResult& result, void* userData);
        typedef void(*UpdateStoreItemsCallback)(AdminModels::UpdateStoreItemsResult& result, void* userData);
        typedef void(*AddUserVirtualCurrencyCallback)(AdminModels::ModifyUserVirtualCurrencyResult& result, void* userData);
        typedef void(*GetUserInventoryCallback)(AdminModels::GetUserInventoryResult& result, void* userData);
        typedef void(*GrantItemsToUsersCallback)(AdminModels::GrantItemsToUsersResult& result, void* userData);
        typedef void(*RevokeInventoryItemCallback)(AdminModels::RevokeInventoryResult& result, void* userData);
        typedef void(*SubtractUserVirtualCurrencyCallback)(AdminModels::ModifyUserVirtualCurrencyResult& result, void* userData);
        typedef void(*GetMatchmakerGameInfoCallback)(AdminModels::GetMatchmakerGameInfoResult& result, void* userData);
        typedef void(*GetMatchmakerGameModesCallback)(AdminModels::GetMatchmakerGameModesResult& result, void* userData);
        typedef void(*ModifyMatchmakerGameModesCallback)(AdminModels::ModifyMatchmakerGameModesResult& result, void* userData);
        typedef void(*AddServerBuildCallback)(AdminModels::AddServerBuildResult& result, void* userData);
        typedef void(*GetServerBuildInfoCallback)(AdminModels::GetServerBuildInfoResult& result, void* userData);
        typedef void(*GetServerBuildUploadUrlCallback)(AdminModels::GetServerBuildUploadURLResult& result, void* userData);
        typedef void(*ListServerBuildsCallback)(AdminModels::ListBuildsResult& result, void* userData);
        typedef void(*ModifyServerBuildCallback)(AdminModels::ModifyServerBuildResult& result, void* userData);
        typedef void(*RemoveServerBuildCallback)(AdminModels::RemoveServerBuildResult& result, void* userData);
        typedef void(*GetPublisherDataCallback)(AdminModels::GetPublisherDataResult& result, void* userData);
        typedef void(*SetPublisherDataCallback)(AdminModels::SetPublisherDataResult& result, void* userData);
        typedef void(*GetCloudScriptRevisionCallback)(AdminModels::GetCloudScriptRevisionResult& result, void* userData);
        typedef void(*GetCloudScriptVersionsCallback)(AdminModels::GetCloudScriptVersionsResult& result, void* userData);
        typedef void(*SetPublishedRevisionCallback)(AdminModels::SetPublishedRevisionResult& result, void* userData);
        typedef void(*UpdateCloudScriptCallback)(AdminModels::UpdateCloudScriptResult& result, void* userData);
        typedef void(*DeleteContentCallback)(AdminModels::BlankResult& result, void* userData);
        typedef void(*GetContentListCallback)(AdminModels::GetContentListResult& result, void* userData);
        typedef void(*GetContentUploadUrlCallback)(AdminModels::GetContentUploadUrlResult& result, void* userData);
        typedef void(*ResetCharacterStatisticsCallback)(AdminModels::ResetCharacterStatisticsResult& result, void* userData);

        static size_t Update();

        // ------------ Generated API calls
        static void GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, GetUserAccountInfoCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ResetUsers(AdminModels::ResetUsersRequest& request, ResetUsersCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, SendAccountRecoveryEmailCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, UpdateUserTitleDisplayNameCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, CreatePlayerStatisticDefinitionCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteUsers(AdminModels::DeleteUsersRequest& request, DeleteUsersCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetDataReport(AdminModels::GetDataReportRequest& request, GetDataReportCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerStatisticDefinitions(GetPlayerStatisticDefinitionsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, GetPlayerStatisticVersionsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserData(AdminModels::GetUserDataRequest& request, GetUserDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserInternalData(AdminModels::GetUserDataRequest& request, GetUserInternalDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherData(AdminModels::GetUserDataRequest& request, GetUserPublisherDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, GetUserPublisherInternalDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, GetUserPublisherReadOnlyDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, GetUserReadOnlyDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, IncrementPlayerStatisticVersionCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ResetUserStatisticsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, UpdatePlayerStatisticDefinitionCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserData(AdminModels::UpdateUserDataRequest& request, UpdateUserDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, UpdateUserInternalDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, UpdateUserPublisherDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, UpdateUserPublisherInternalDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, UpdateUserPublisherReadOnlyDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, UpdateUserReadOnlyDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddNews(AdminModels::AddNewsRequest& request, AddNewsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, AddVirtualCurrencyTypesCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, GetCatalogItemsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, GetRandomResultTablesCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetStoreItems(AdminModels::GetStoreItemsRequest& request, GetStoreItemsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleData(AdminModels::GetTitleDataRequest& request, GetTitleDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListVirtualCurrencyTypes(ListVirtualCurrencyTypesCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, SetCatalogItemsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, SetStoreItemsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetTitleData(AdminModels::SetTitleDataRequest& request, SetTitleDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, SetupPushNotificationCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, UpdateCatalogItemsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, UpdateRandomResultTablesCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, UpdateStoreItemsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, AddUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserInventory(AdminModels::GetUserInventoryRequest& request, GetUserInventoryCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, GrantItemsToUsersCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, RevokeInventoryItemCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, SubtractUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, GetMatchmakerGameInfoCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, GetMatchmakerGameModesCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ModifyMatchmakerGameModesCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddServerBuild(AdminModels::AddServerBuildRequest& request, AddServerBuildCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, GetServerBuildInfoCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, GetServerBuildUploadUrlCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListServerBuilds(ListServerBuildsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ModifyServerBuildCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, RemoveServerBuildCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPublisherData(AdminModels::GetPublisherDataRequest& request, GetPublisherDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetPublisherData(AdminModels::SetPublisherDataRequest& request, SetPublisherDataCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, GetCloudScriptRevisionCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCloudScriptVersions(GetCloudScriptVersionsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, SetPublishedRevisionCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, UpdateCloudScriptCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteContent(AdminModels::DeleteContentRequest& request, DeleteContentCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetContentList(AdminModels::GetContentListRequest& request, GetContentListCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, GetContentUploadUrlCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ResetCharacterStatisticsCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabAdminAPI();

        // ------------ Generated result handlers
        static void OnGetUserAccountInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnResetUsersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSendAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserTitleDisplayNameResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreatePlayerStatisticDefinitionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteUsersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetDataReportResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerStatisticDefinitionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerStatisticVersionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnIncrementPlayerStatisticVersionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnResetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdatePlayerStatisticDefinitionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddNewsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddVirtualCurrencyTypesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetRandomResultTablesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListVirtualCurrencyTypesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetupPushNotificationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateRandomResultTablesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateStoreItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGrantItemsToUsersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRevokeInventoryItemResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetMatchmakerGameInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetMatchmakerGameModesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnModifyMatchmakerGameModesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddServerBuildResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetServerBuildInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetServerBuildUploadUrlResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListServerBuildsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnModifyServerBuildResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveServerBuildResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCloudScriptRevisionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCloudScriptVersionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetPublishedRevisionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCloudScriptResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteContentResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetContentListResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetContentUploadUrlResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnResetCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData);

        static IHttpRequester* mHttpRequester;
    };
};
#endif
