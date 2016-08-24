#ifndef PLAYFAB_CLIENTAPI_H_
#define PLAYFAB_CLIENTAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabClientDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabClientAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = void(*)(const ResType& result, void* userData);

        // Public, Client-Specific
        static void MultiStepClientLogin(bool needsAttribution);
        static bool IsClientLoggedIn();

        // ------------ Generated API calls
        static void GetPhotonAuthenticationToken(ClientModels::GetPhotonAuthenticationTokenRequest& request, ProcessApiCallback<ClientModels::GetPhotonAuthenticationTokenResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithCustomID(ClientModels::LoginWithCustomIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithEmailAddress(ClientModels::LoginWithEmailAddressRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithKongregate(ClientModels::LoginWithKongregateRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithSteam(ClientModels::LoginWithSteamRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LoginWithTwitch(ClientModels::LoginWithTwitchRequest& request, ProcessApiCallback<ClientModels::LoginResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, ProcessApiCallback<ClientModels::RegisterPlayFabUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddGenericID(ClientModels::AddGenericIDRequest& request, ProcessApiCallback<ClientModels::AddGenericIDResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, ProcessApiCallback<ClientModels::AddUsernamePasswordResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetAccountInfo(ClientModels::GetAccountInfoRequest& request, ProcessApiCallback<ClientModels::GetAccountInfoResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerCombinedInfo(ClientModels::GetPlayerCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetPlayerCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromFacebookIDs(ClientModels::GetPlayFabIDsFromFacebookIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromFacebookIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromGameCenterIDs(ClientModels::GetPlayFabIDsFromGameCenterIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGameCenterIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromGenericIDs(ClientModels::GetPlayFabIDsFromGenericIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGenericIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromGoogleIDs(ClientModels::GetPlayFabIDsFromGoogleIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromGoogleIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromKongregateIDs(ClientModels::GetPlayFabIDsFromKongregateIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromKongregateIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromSteamIDs(ClientModels::GetPlayFabIDsFromSteamIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromSteamIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayFabIDsFromTwitchIDs(ClientModels::GetPlayFabIDsFromTwitchIDsRequest& request, ProcessApiCallback<ClientModels::GetPlayFabIDsFromTwitchIDsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'GetPlayerCombinedInfo' instead
        static void GetUserCombinedInfo(ClientModels::GetUserCombinedInfoRequest& request, ProcessApiCallback<ClientModels::GetUserCombinedInfoResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkAndroidDeviceID(ClientModels::LinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkCustomID(ClientModels::LinkCustomIDRequest& request, ProcessApiCallback<ClientModels::LinkCustomIDResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, ProcessApiCallback<ClientModels::LinkFacebookAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, ProcessApiCallback<ClientModels::LinkGameCenterAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkGoogleAccount(ClientModels::LinkGoogleAccountRequest& request, ProcessApiCallback<ClientModels::LinkGoogleAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkIOSDeviceID(ClientModels::LinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::LinkIOSDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkKongregate(ClientModels::LinkKongregateAccountRequest& request, ProcessApiCallback<ClientModels::LinkKongregateAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, ProcessApiCallback<ClientModels::LinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void LinkTwitch(ClientModels::LinkTwitchAccountRequest& request, ProcessApiCallback<ClientModels::LinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveGenericID(ClientModels::RemoveGenericIDRequest& request, ProcessApiCallback<ClientModels::RemoveGenericIDResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ReportPlayer(ClientModels::ReportPlayerClientRequest& request, ProcessApiCallback<ClientModels::ReportPlayerClientResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, ProcessApiCallback<ClientModels::SendAccountRecoveryEmailResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkAndroidDeviceID(ClientModels::UnlinkAndroidDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkAndroidDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkCustomID(ClientModels::UnlinkCustomIDRequest& request, ProcessApiCallback<ClientModels::UnlinkCustomIDResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkFacebookAccount(ProcessApiCallback<ClientModels::UnlinkFacebookAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkGameCenterAccount(ProcessApiCallback<ClientModels::UnlinkGameCenterAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkGoogleAccount(ProcessApiCallback<ClientModels::UnlinkGoogleAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkIOSDeviceID(ClientModels::UnlinkIOSDeviceIDRequest& request, ProcessApiCallback<ClientModels::UnlinkIOSDeviceIDResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkKongregate(ProcessApiCallback<ClientModels::UnlinkKongregateAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkSteamAccount(ProcessApiCallback<ClientModels::UnlinkSteamAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlinkTwitch(ProcessApiCallback<ClientModels::UnlinkTwitchAccountResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, ProcessApiCallback<ClientModels::UpdateUserTitleDisplayNameResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'GetFriendLeaderboardAroundPlayer' instead
        static void GetFriendLeaderboardAroundCurrentUser(ClientModels::GetFriendLeaderboardAroundCurrentUserRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundCurrentUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetFriendLeaderboardAroundPlayer(ClientModels::GetFriendLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetFriendLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLeaderboard(ClientModels::GetLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'GetLeaderboardAroundPlayer' instead
        static void GetLeaderboardAroundCurrentUser(ClientModels::GetLeaderboardAroundCurrentUserRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCurrentUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLeaderboardAroundPlayer(ClientModels::GetLeaderboardAroundPlayerRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerStatistics(ClientModels::GetPlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerStatisticVersions(ClientModels::GetPlayerStatisticVersionsRequest& request, ProcessApiCallback<ClientModels::GetPlayerStatisticVersionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserPublisherReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, ProcessApiCallback<ClientModels::GetUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'GetPlayerStatistics' instead
        static void GetUserStatistics(ProcessApiCallback<ClientModels::GetUserStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdatePlayerStatistics(ClientModels::UpdatePlayerStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdatePlayerStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateUserPublisherData(ClientModels::UpdateUserDataRequest& request, ProcessApiCallback<ClientModels::UpdateUserDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'UpdatePlayerStatistics' instead
        static void UpdateUserStatistics(ClientModels::UpdateUserStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateUserStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, ProcessApiCallback<ClientModels::GetCatalogItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPublisherData(ClientModels::GetPublisherDataRequest& request, ProcessApiCallback<ClientModels::GetPublisherDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetStoreItems(ClientModels::GetStoreItemsRequest& request, ProcessApiCallback<ClientModels::GetStoreItemsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleData(ClientModels::GetTitleDataRequest& request, ProcessApiCallback<ClientModels::GetTitleDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleNews(ClientModels::GetTitleNewsRequest& request, ProcessApiCallback<ClientModels::GetTitleNewsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ProcessApiCallback<ClientModels::ConfirmPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ConsumeItem(ClientModels::ConsumeItemRequest& request, ProcessApiCallback<ClientModels::ConsumeItemResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterInventory(ClientModels::GetCharacterInventoryRequest& request, ProcessApiCallback<ClientModels::GetCharacterInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPurchase(ClientModels::GetPurchaseRequest& request, ProcessApiCallback<ClientModels::GetPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetUserInventory(ProcessApiCallback<ClientModels::GetUserInventoryResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PayForPurchase(ClientModels::PayForPurchaseRequest& request, ProcessApiCallback<ClientModels::PayForPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PurchaseItem(ClientModels::PurchaseItemRequest& request, ProcessApiCallback<ClientModels::PurchaseItemResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RedeemCoupon(ClientModels::RedeemCouponRequest& request, ProcessApiCallback<ClientModels::RedeemCouponResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void StartPurchase(ClientModels::StartPurchaseRequest& request, ProcessApiCallback<ClientModels::StartPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, ProcessApiCallback<ClientModels::ModifyUserVirtualCurrencyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlockContainerInstance(ClientModels::UnlockContainerInstanceRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, ProcessApiCallback<ClientModels::UnlockContainerItemResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddFriend(ClientModels::AddFriendRequest& request, ProcessApiCallback<ClientModels::AddFriendResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetFriendsList(ClientModels::GetFriendsListRequest& request, ProcessApiCallback<ClientModels::GetFriendsListResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveFriend(ClientModels::RemoveFriendRequest& request, ProcessApiCallback<ClientModels::RemoveFriendResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetFriendTags(ClientModels::SetFriendTagsRequest& request, ProcessApiCallback<ClientModels::SetFriendTagsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, ProcessApiCallback<ClientModels::RegisterForIOSPushNotificationResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RestoreIOSPurchases(ClientModels::RestoreIOSPurchasesRequest& request, ProcessApiCallback<ClientModels::RestoreIOSPurchasesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateIOSReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCurrentGames(ClientModels::CurrentGamesRequest& request, ProcessApiCallback<ClientModels::CurrentGamesResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, ProcessApiCallback<ClientModels::GameServerRegionsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void Matchmake(ClientModels::MatchmakeRequest& request, ProcessApiCallback<ClientModels::MatchmakeResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void StartGame(ClientModels::StartGameRequest& request, ProcessApiCallback<ClientModels::StartGameResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, ProcessApiCallback<ClientModels::AndroidDevicePushNotificationRegistrationResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ProcessApiCallback<ClientModels::ValidateGooglePlayPurchaseResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'WritePlayerEvent' instead
        static void LogEvent(ClientModels::LogEventRequest& request, ProcessApiCallback<ClientModels::LogEventResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void WriteCharacterEvent(ClientModels::WriteClientCharacterEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void WritePlayerEvent(ClientModels::WriteClientPlayerEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void WriteTitleEvent(ClientModels::WriteTitleEventRequest& request, ProcessApiCallback<ClientModels::WriteEventResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::AddSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, ProcessApiCallback<ClientModels::CreateSharedGroupResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::GetSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, ProcessApiCallback<ClientModels::RemoveSharedGroupMembersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, ProcessApiCallback<ClientModels::UpdateSharedGroupDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ExecuteCloudScript(ClientModels::ExecuteCloudScriptRequest& request, ProcessApiCallback<ClientModels::ExecuteCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'ExecuteCloudScript' instead
        static void GetCloudScriptUrl(ClientModels::GetCloudScriptUrlRequest& request, ProcessApiCallback<ClientModels::GetCloudScriptUrlResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        // Deprecated - Use 'ExecuteCloudScript' instead
        static void RunCloudScript(ClientModels::RunCloudScriptRequest& request, ProcessApiCallback<ClientModels::RunCloudScriptResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetContentDownloadUrl(ClientModels::GetContentDownloadUrlRequest& request, ProcessApiCallback<ClientModels::GetContentDownloadUrlResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetAllUsersCharacters(ClientModels::ListUsersCharactersRequest& request, ProcessApiCallback<ClientModels::ListUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterLeaderboard(ClientModels::GetCharacterLeaderboardRequest& request, ProcessApiCallback<ClientModels::GetCharacterLeaderboardResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterStatistics(ClientModels::GetCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::GetCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLeaderboardAroundCharacter(ClientModels::GetLeaderboardAroundCharacterRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardAroundCharacterResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLeaderboardForUserCharacters(ClientModels::GetLeaderboardForUsersCharactersRequest& request, ProcessApiCallback<ClientModels::GetLeaderboardForUsersCharactersResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GrantCharacterToUser(ClientModels::GrantCharacterToUserRequest& request, ProcessApiCallback<ClientModels::GrantCharacterToUserResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCharacterStatistics(ClientModels::UpdateCharacterStatisticsRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetCharacterReadOnlyData(ClientModels::GetCharacterDataRequest& request, ProcessApiCallback<ClientModels::GetCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateCharacterData(ClientModels::UpdateCharacterDataRequest& request, ProcessApiCallback<ClientModels::UpdateCharacterDataResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ValidateAmazonIAPReceipt(ClientModels::ValidateAmazonReceiptRequest& request, ProcessApiCallback<ClientModels::ValidateAmazonReceiptResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AcceptTrade(ClientModels::AcceptTradeRequest& request, ProcessApiCallback<ClientModels::AcceptTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CancelTrade(ClientModels::CancelTradeRequest& request, ProcessApiCallback<ClientModels::CancelTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerTrades(ClientModels::GetPlayerTradesRequest& request, ProcessApiCallback<ClientModels::GetPlayerTradesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTradeStatus(ClientModels::GetTradeStatusRequest& request, ProcessApiCallback<ClientModels::GetTradeStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void OpenTrade(ClientModels::OpenTradeRequest& request, ProcessApiCallback<ClientModels::OpenTradeResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AttributeInstall(ClientModels::AttributeInstallRequest& request, ProcessApiCallback<ClientModels::AttributeInstallResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetPlayerSegments(ProcessApiCallback<ClientModels::GetPlayerSegmentsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabClientAPI();

        // ------------ Generated result handlers
        static void OnGetPhotonAuthenticationTokenResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithCustomIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithEmailAddressResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithFacebookResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithGameCenterResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithKongregateResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithPlayFabResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithSteamResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLoginWithTwitchResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRegisterPlayFabUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddGenericIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddUsernamePasswordResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetAccountInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerCombinedInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromFacebookIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromGameCenterIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromGenericIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromGoogleIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromKongregateIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromSteamIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayFabIDsFromTwitchIDsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserCombinedInfoResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkCustomIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkFacebookAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkGameCenterAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkKongregateResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkSteamAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLinkTwitchResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveGenericIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnReportPlayerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSendAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkCustomIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkFacebookAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkGameCenterAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkKongregateResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkSteamAccountResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlinkTwitchResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserTitleDisplayNameResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetFriendLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetFriendLeaderboardAroundCurrentUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetFriendLeaderboardAroundPlayerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardAroundCurrentUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardAroundPlayerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerStatisticVersionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdatePlayerStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleNewsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnConfirmPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnConsumeItemResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterInventoryResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPayForPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPurchaseItemResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRedeemCouponResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnStartPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlockContainerInstanceResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnlockContainerItemResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddFriendResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetFriendsListResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveFriendResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetFriendTagsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRegisterForIOSPushNotificationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRestoreIOSPurchasesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnValidateIOSReceiptResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCurrentGamesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetGameServerRegionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnMatchmakeResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnStartGameResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAndroidDevicePushNotificationRegistrationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnValidateGooglePlayPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnLogEventResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnWriteCharacterEventResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnWritePlayerEventResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnWriteTitleEventResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateSharedGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnExecuteCloudScriptResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCloudScriptUrlResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRunCloudScriptResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetContentDownloadUrlResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetAllUsersCharactersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardAroundCharacterResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLeaderboardForUserCharactersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGrantCharacterToUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCharacterStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetCharacterReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateCharacterDataResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnValidateAmazonIAPReceiptResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAcceptTradeResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCancelTradeResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerTradesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTradeStatusResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnOpenTradeResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAttributeInstallResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetPlayerSegmentsResult(int httpStatus, HttpRequest* request, void* userData);

        // Private, Client-Specific
        static std::string mUserSessionTicket;
    };
};
#endif
