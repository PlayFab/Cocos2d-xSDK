#ifndef PLAYFAB_ADMINAPI_H_
#define PLAYFAB_ADMINAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabAdminDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabAdminAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void BanUsers(AdminModels::BanUsersRequest& request, ProcessApiCallback<AdminModels::BanUsersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, ProcessApiCallback<AdminModels::LookupUserAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserBans(AdminModels::GetUserBansRequest& request, ProcessApiCallback<AdminModels::GetUserBansResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ResetUsers(AdminModels::ResetUsersRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RevokeAllBansForUser(AdminModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<AdminModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RevokeBans(AdminModels::RevokeBansRequest& request, ProcessApiCallback<AdminModels::RevokeBansResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<AdminModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateBans(AdminModels::UpdateBansRequest& request, ProcessApiCallback<AdminModels::UpdateBansResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<AdminModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreatePlayerStatisticDefinition(AdminModels::CreatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::CreatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteUsers(AdminModels::DeleteUsersRequest& request, ProcessApiCallback<AdminModels::DeleteUsersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetDataReport(AdminModels::GetDataReportRequest& request, ProcessApiCallback<AdminModels::GetDataReportResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerStatisticDefinitions(ProcessApiCallback<AdminModels::GetPlayerStatisticDefinitionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerStatisticVersions(AdminModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<AdminModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherInternalData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, ProcessApiCallback<AdminModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void IncrementPlayerStatisticVersion(AdminModels::IncrementPlayerStatisticVersionRequest& request, ProcessApiCallback<AdminModels::IncrementPlayerStatisticVersionResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RefundPurchase(AdminModels::RefundPurchaseRequest& request, ProcessApiCallback<AdminModels::RefundPurchaseResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetUserStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ResolvePurchaseDispute(AdminModels::ResolvePurchaseDisputeRequest& request, ProcessApiCallback<AdminModels::ResolvePurchaseDisputeResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdatePlayerStatisticDefinition(AdminModels::UpdatePlayerStatisticDefinitionRequest& request, ProcessApiCallback<AdminModels::UpdatePlayerStatisticDefinitionResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherInternalData(AdminModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, ProcessApiCallback<AdminModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddNews(AdminModels::AddNewsRequest& request, ProcessApiCallback<AdminModels::AddNewsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteStore(AdminModels::DeleteStoreRequest& request, ProcessApiCallback<AdminModels::DeleteStoreResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, ProcessApiCallback<AdminModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPublisherData(AdminModels::GetPublisherDataRequest& request, ProcessApiCallback<AdminModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetRandomResultTables(AdminModels::GetRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetStoreItems(AdminModels::GetStoreItemsRequest& request, ProcessApiCallback<AdminModels::GetStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleInternalData(AdminModels::GetTitleDataRequest& request, ProcessApiCallback<AdminModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListVirtualCurrencyTypes(ProcessApiCallback<AdminModels::ListVirtualCurrencyTypesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveVirtualCurrencyTypes(AdminModels::RemoveVirtualCurrencyTypesRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetTitleData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetTitleInternalData(AdminModels::SetTitleDataRequest& request, ProcessApiCallback<AdminModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetupPushNotification(AdminModels::SetupPushNotificationRequest& request, ProcessApiCallback<AdminModels::SetupPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, ProcessApiCallback<AdminModels::UpdateCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, ProcessApiCallback<AdminModels::UpdateRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, ProcessApiCallback<AdminModels::UpdateStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserInventory(AdminModels::GetUserInventoryRequest& request, ProcessApiCallback<AdminModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, ProcessApiCallback<AdminModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, ProcessApiCallback<AdminModels::RevokeInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<AdminModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameInfoResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::GetMatchmakerGameModesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ProcessApiCallback<AdminModels::ModifyMatchmakerGameModesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddServerBuild(AdminModels::AddServerBuildRequest& request, ProcessApiCallback<AdminModels::AddServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, ProcessApiCallback<AdminModels::GetServerBuildInfoResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, ProcessApiCallback<AdminModels::GetServerBuildUploadURLResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListServerBuilds(ProcessApiCallback<AdminModels::ListBuildsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ProcessApiCallback<AdminModels::ModifyServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, ProcessApiCallback<AdminModels::RemoveServerBuildResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetPublisherData(AdminModels::SetPublisherDataRequest& request, ProcessApiCallback<AdminModels::SetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCloudScriptRevision(AdminModels::GetCloudScriptRevisionRequest& request, ProcessApiCallback<AdminModels::GetCloudScriptRevisionResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCloudScriptVersions(ProcessApiCallback<AdminModels::GetCloudScriptVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetPublishedRevision(AdminModels::SetPublishedRevisionRequest& request, ProcessApiCallback<AdminModels::SetPublishedRevisionResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCloudScript(AdminModels::UpdateCloudScriptRequest& request, ProcessApiCallback<AdminModels::UpdateCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteContent(AdminModels::DeleteContentRequest& request, ProcessApiCallback<AdminModels::BlankResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetContentList(AdminModels::GetContentListRequest& request, ProcessApiCallback<AdminModels::GetContentListResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetContentUploadUrl(AdminModels::GetContentUploadUrlRequest& request, ProcessApiCallback<AdminModels::GetContentUploadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ResetCharacterStatistics(AdminModels::ResetCharacterStatisticsRequest& request, ProcessApiCallback<AdminModels::ResetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddPlayerTag(AdminModels::AddPlayerTagRequest& request, ProcessApiCallback<AdminModels::AddPlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetAllActionGroups(ProcessApiCallback<AdminModels::GetAllActionGroupsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetAllSegments(ProcessApiCallback<AdminModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerSegments(AdminModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<AdminModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayersInSegment(AdminModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<AdminModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerTags(AdminModels::GetPlayerTagsRequest& request, ProcessApiCallback<AdminModels::GetPlayerTagsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemovePlayerTag(AdminModels::RemovePlayerTagRequest& request, ProcessApiCallback<AdminModels::RemovePlayerTagResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabAdminAPI();

        // ------------ Generated result handlers
        static void OnBanUsersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserAccountInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserBansResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnResetUsersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRevokeAllBansForUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRevokeBansResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSendAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateBansResult(int httpStatus, HttpRequest* request, void* userData);
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
        static void OnRefundPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnResetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnResolvePurchaseDisputeResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdatePlayerStatisticDefinitionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddNewsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddVirtualCurrencyTypesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteStoreResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetRandomResultTablesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListVirtualCurrencyTypesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveVirtualCurrencyTypesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetTitleInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
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
        static void OnSetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCloudScriptRevisionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCloudScriptVersionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetPublishedRevisionResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCloudScriptResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteContentResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetContentListResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetContentUploadUrlResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnResetCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddPlayerTagResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetAllActionGroupsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetAllSegmentsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerSegmentsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayersInSegmentResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerTagsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemovePlayerTagResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
