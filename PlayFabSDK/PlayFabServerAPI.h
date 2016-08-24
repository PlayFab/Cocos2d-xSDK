#ifndef PLAYFAB_SERVERAPI_H_
#define PLAYFAB_SERVERAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabServerDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabServerAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = void(*)(const ResType& result, void* userData);

        // ------------ Generated API calls
        static void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, ProcessApiCallback<ServerModels::AuthenticateSessionTicketResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void BanUsers(ServerModels::BanUsersRequest& request, ProcessApiCallback<ServerModels::BanUsersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromSteamIDs(ServerModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ServerModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, ProcessApiCallback<ServerModels::GetUserAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserBans(ServerModels::GetUserBansRequest& request, ProcessApiCallback<ServerModels::GetUserBansResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RevokeAllBansForUser(ServerModels::RevokeAllBansForUserRequest& request, ProcessApiCallback<ServerModels::RevokeAllBansForUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RevokeBans(ServerModels::RevokeBansRequest& request, ProcessApiCallback<ServerModels::RevokeBansResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SendPushNotification(ServerModels::SendPushNotificationRequest& request, ProcessApiCallback<ServerModels::SendPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateBans(ServerModels::UpdateBansRequest& request, ProcessApiCallback<ServerModels::UpdateBansResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteUsers(ServerModels::DeleteUsersRequest& request, ProcessApiCallback<ServerModels::DeleteUsersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLeaderboard(ServerModels::GetLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerCombinedInfo(ServerModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ServerModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerStatistics(ServerModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerStatisticVersions(ServerModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ServerModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, ProcessApiCallback<ServerModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'GetPlayerStatistics' instead
        static void GetUserStatistics(ServerModels::GetUserStatisticsRequest& request, ProcessApiCallback<ServerModels::GetUserStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdatePlayerStatistics(ServerModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, ProcessApiCallback<ServerModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'UpdatePlayerStatistics' instead
        static void UpdateUserStatistics(ServerModels::UpdateUserStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateUserStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, ProcessApiCallback<ServerModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPublisherData(ServerModels::GetPublisherDataRequest& request, ProcessApiCallback<ServerModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleInternalData(ServerModels::GetTitleDataRequest& request, ProcessApiCallback<ServerModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleNews(ServerModels::GetTitleNewsRequest& request, ProcessApiCallback<ServerModels::GetTitleNewsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetPublisherData(ServerModels::SetPublisherDataRequest& request, ProcessApiCallback<ServerModels::SetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetTitleData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetTitleInternalData(ServerModels::SetTitleDataRequest& request, ProcessApiCallback<ServerModels::SetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ConsumeItem(ServerModels::ConsumeItemRequest& request, ProcessApiCallback<ServerModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void EvaluateRandomResultTable(ServerModels::EvaluateRandomResultTableRequest& request, ProcessApiCallback<ServerModels::EvaluateRandomResultTableResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ServerModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetRandomResultTables(ServerModels::GetRandomResultTablesRequest& request, ProcessApiCallback<ServerModels::GetRandomResultTablesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserInventory(ServerModels::GetUserInventoryRequest& request, ProcessApiCallback<ServerModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, ProcessApiCallback<ServerModels::GrantItemsToCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, ProcessApiCallback<ServerModels::GrantItemsToUsersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ProcessApiCallback<ServerModels::ModifyItemUsesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::MoveItemToCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, ProcessApiCallback<ServerModels::MoveItemToUserFromCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RedeemCoupon(ServerModels::RedeemCouponRequest& request, ProcessApiCallback<ServerModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ProcessApiCallback<ServerModels::ReportPlayerServerResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RevokeInventoryItem(ServerModels::RevokeInventoryItemRequest& request, ProcessApiCallback<ServerModels::RevokeInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyCharacterVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ServerModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlockContainerInstance(ServerModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlockContainerItem(ServerModels::UnlockContainerItemRequest& request, ProcessApiCallback<ServerModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, ProcessApiCallback<ServerModels::NotifyMatchmakerPlayerLeftResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, ProcessApiCallback<ServerModels::RedeemMatchmakerTicketResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetGameServerInstanceData(ServerModels::SetGameServerInstanceDataRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetGameServerInstanceState(ServerModels::SetGameServerInstanceStateRequest& request, ProcessApiCallback<ServerModels::SetGameServerInstanceStateResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, ProcessApiCallback<ServerModels::AwardSteamAchievementResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'WritePlayerEvent' instead
        static void LogEvent(ServerModels::LogEventRequest& request, ProcessApiCallback<ServerModels::LogEventResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void WriteCharacterEvent(ServerModels::WriteServerCharacterEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void WritePlayerEvent(ServerModels::WriteServerPlayerEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void WriteTitleEvent(ServerModels::WriteTitleEventRequest& request, ProcessApiCallback<ServerModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, ProcessApiCallback<ServerModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, ProcessApiCallback<ServerModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ServerModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ServerModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ExecuteCloudScript(ServerModels::ExecuteCloudScriptServerRequest& request, ProcessApiCallback<ServerModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ServerModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, ProcessApiCallback<ServerModels::DeleteCharacterFromUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, ProcessApiCallback<ServerModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ServerModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ServerModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ServerModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, ProcessApiCallback<ServerModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ServerModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetAllSegments(ProcessApiCallback<ServerModels::GetAllSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerSegments(ServerModels::GetPlayersSegmentsRequest& request, ProcessApiCallback<ServerModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayersInSegment(ServerModels::GetPlayersInSegmentRequest& request, ProcessApiCallback<ServerModels::GetPlayersInSegmentResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabServerAPI();

        // ------------ Generated result handlers
        static void OnAuthenticateSessionTicketResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnBanUsersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromFacebookIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromSteamIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserAccountInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserBansResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRevokeAllBansForUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRevokeBansResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSendPushNotificationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateBansResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteUsersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardAroundUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerCombinedInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerStatisticVersionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdatePlayerStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleNewsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetTitleInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddCharacterVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnConsumeItemResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnEvaluateRandomResultTableResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterInventoryResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetRandomResultTablesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGrantItemsToCharacterResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGrantItemsToUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGrantItemsToUsersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnModifyItemUsesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnMoveItemToCharacterFromCharacterResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnMoveItemToCharacterFromUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnMoveItemToUserFromCharacterResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRedeemCouponResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnReportPlayerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRevokeInventoryItemResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSubtractCharacterVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlockContainerInstanceResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlockContainerItemResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserInventoryItemCustomDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnNotifyMatchmakerPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRedeemMatchmakerTicketResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetGameServerInstanceDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetGameServerInstanceStateResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAwardSteamAchievementResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLogEventResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnWriteCharacterEventResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnWritePlayerEventResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnWriteTitleEventResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateSharedGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteSharedGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnExecuteCloudScriptResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetContentDownloadUrlResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteCharacterFromUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetAllUsersCharactersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardAroundCharacterResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardForUserCharactersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGrantCharacterToUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCharacterDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCharacterInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCharacterReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetAllSegmentsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerSegmentsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayersInSegmentResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
