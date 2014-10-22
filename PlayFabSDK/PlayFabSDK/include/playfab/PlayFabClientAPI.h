#ifndef PLAYFAB_CLIENTAPI_H_
#define PLAYFAB_CLIENTAPI_H_

#include "playfab/IHttpRequester.h"
#include "playfab/PlayFabError.h"
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabSettings.h"

#include <string>


namespace PlayFab
{
	
    
    class PlayFabClientAPI
    {
    public:
		
		typedef void(*AddUsernamePasswordCallback)(ClientModels::AddUsernamePasswordResult& result, void* userData);
		typedef void(*LoginWithAndroidDeviceIDCallback)(ClientModels::LoginResult& result, void* userData);
		typedef void(*LoginWithFacebookCallback)(ClientModels::LoginResult& result, void* userData);
		typedef void(*LoginWithGameCenterCallback)(ClientModels::LoginResult& result, void* userData);
		typedef void(*LoginWithGoogleAccountCallback)(ClientModels::LoginResult& result, void* userData);
		typedef void(*LoginWithIOSDeviceIDCallback)(ClientModels::LoginResult& result, void* userData);
		typedef void(*LoginWithPlayFabCallback)(ClientModels::LoginResult& result, void* userData);
		typedef void(*LoginWithSteamCallback)(ClientModels::LoginResult& result, void* userData);
		typedef void(*RegisterPlayFabUserCallback)(ClientModels::RegisterPlayFabUserResult& result, void* userData);
		typedef void(*SendAccountRecoveryEmailCallback)(ClientModels::SendAccountRecoveryEmailResult& result, void* userData);
		typedef void(*GetAccountInfoCallback)(ClientModels::GetAccountInfoResult& result, void* userData);
		typedef void(*GetUserCombinedInfoCallback)(ClientModels::GetUserCombinedInfoResult& result, void* userData);
		typedef void(*LinkFacebookAccountCallback)(ClientModels::LinkFacebookAccountResult& result, void* userData);
		typedef void(*LinkGameCenterAccountCallback)(ClientModels::LinkGameCenterAccountResult& result, void* userData);
		typedef void(*LinkSteamAccountCallback)(ClientModels::LinkSteamAccountResult& result, void* userData);
		typedef void(*UnlinkFacebookAccountCallback)(ClientModels::UnlinkFacebookAccountResult& result, void* userData);
		typedef void(*UnlinkGameCenterAccountCallback)(ClientModels::UnlinkGameCenterAccountResult& result, void* userData);
		typedef void(*UnlinkSteamAccountCallback)(ClientModels::UnlinkSteamAccountResult& result, void* userData);
		typedef void(*UpdateEmailAddressCallback)(ClientModels::UpdateEmailAddressResult& result, void* userData);
		typedef void(*UpdatePasswordCallback)(ClientModels::UpdatePasswordResult& result, void* userData);
		typedef void(*UpdateUserTitleDisplayNameCallback)(ClientModels::UpdateUserTitleDisplayNameResult& result, void* userData);
		typedef void(*GetFriendLeaderboardCallback)(ClientModels::GetLeaderboardResult& result, void* userData);
		typedef void(*GetLeaderboardCallback)(ClientModels::GetLeaderboardResult& result, void* userData);
		typedef void(*GetLeaderboardAroundCurrentUserCallback)(ClientModels::GetLeaderboardAroundCurrentUserResult& result, void* userData);
		typedef void(*GetUserDataCallback)(ClientModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserReadOnlyDataCallback)(ClientModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserStatisticsCallback)(ClientModels::GetUserStatisticsResult& result, void* userData);
		typedef void(*UpdateUserDataCallback)(ClientModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserStatisticsCallback)(ClientModels::UpdateUserStatisticsResult& result, void* userData);
		typedef void(*GetCatalogItemsCallback)(ClientModels::GetCatalogItemsResult& result, void* userData);
		typedef void(*GetStoreItemsCallback)(ClientModels::GetStoreItemsResult& result, void* userData);
		typedef void(*GetTitleDataCallback)(ClientModels::GetTitleDataResult& result, void* userData);
		typedef void(*GetTitleNewsCallback)(ClientModels::GetTitleNewsResult& result, void* userData);
		typedef void(*AddUserVirtualCurrencyCallback)(ClientModels::ModifyUserVirtualCurrencyResult& result, void* userData);
		typedef void(*ConfirmPurchaseCallback)(ClientModels::ConfirmPurchaseResult& result, void* userData);
		typedef void(*ConsumeItemCallback)(ClientModels::ConsumeItemResult& result, void* userData);
		typedef void(*GetUserInventoryCallback)(ClientModels::GetUserInventoryResult& result, void* userData);
		typedef void(*PayForPurchaseCallback)(ClientModels::PayForPurchaseResult& result, void* userData);
		typedef void(*PurchaseItemCallback)(ClientModels::PurchaseItemResult& result, void* userData);
		typedef void(*RedeemCouponCallback)(ClientModels::RedeemCouponResult& result, void* userData);
		typedef void(*StartPurchaseCallback)(ClientModels::StartPurchaseResult& result, void* userData);
		typedef void(*SubtractUserVirtualCurrencyCallback)(ClientModels::ModifyUserVirtualCurrencyResult& result, void* userData);
		typedef void(*UnlockContainerItemCallback)(ClientModels::UnlockContainerItemResult& result, void* userData);
		typedef void(*AddFriendCallback)(ClientModels::AddFriendResult& result, void* userData);
		typedef void(*GetFriendsListCallback)(ClientModels::GetFriendsListResult& result, void* userData);
		typedef void(*RemoveFriendCallback)(ClientModels::RemoveFriendResult& result, void* userData);
		typedef void(*SetFriendTagsCallback)(ClientModels::SetFriendTagsResult& result, void* userData);
		typedef void(*RegisterForIOSPushNotificationCallback)(ClientModels::RegisterForIOSPushNotificationResult& result, void* userData);
		typedef void(*ValidateIOSReceiptCallback)(ClientModels::ValidateIOSReceiptResult& result, void* userData);
		typedef void(*GetCurrentGamesCallback)(ClientModels::CurrentGamesResult& result, void* userData);
		typedef void(*GetGameServerRegionsCallback)(ClientModels::GameServerRegionsResult& result, void* userData);
		typedef void(*MatchmakeCallback)(ClientModels::MatchmakeResult& result, void* userData);
		typedef void(*StartGameCallback)(ClientModels::StartGameResult& result, void* userData);
		typedef void(*AndroidDevicePushNotificationRegistrationCallback)(ClientModels::AndroidDevicePushNotificationRegistrationResult& result, void* userData);
		typedef void(*ValidateGooglePlayPurchaseCallback)(ClientModels::ValidateGooglePlayPurchaseResult& result, void* userData);
		typedef void(*LogEventCallback)(ClientModels::LogEventResult& result, void* userData);
		typedef void(*AddSharedGroupMembersCallback)(ClientModels::AddSharedGroupMembersResult& result, void* userData);
		typedef void(*CreateSharedGroupCallback)(ClientModels::CreateSharedGroupResult& result, void* userData);
		typedef void(*GetSharedGroupDataCallback)(ClientModels::GetSharedGroupDataResult& result, void* userData);
		typedef void(*RemoveSharedGroupMembersCallback)(ClientModels::RemoveSharedGroupMembersResult& result, void* userData);
		typedef void(*UpdateSharedGroupDataCallback)(ClientModels::UpdateSharedGroupDataResult& result, void* userData);
		
	
        PlayFabClientAPI();
        PlayFabClientAPI(IHttpRequester* requester, bool ownRequester);
        ~PlayFabClientAPI();

        IHttpRequester* GetRequester(bool relinquishOwnership = false);
        void Update();

        // ------------ Generated API calls
		
		void AddUsernamePassword(ClientModels::AddUsernamePasswordRequest& request, AddUsernamePasswordCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LoginWithAndroidDeviceID(ClientModels::LoginWithAndroidDeviceIDRequest& request, LoginWithAndroidDeviceIDCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LoginWithFacebook(ClientModels::LoginWithFacebookRequest& request, LoginWithFacebookCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LoginWithGameCenter(ClientModels::LoginWithGameCenterRequest& request, LoginWithGameCenterCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LoginWithGoogleAccount(ClientModels::LoginWithGoogleAccountRequest& request, LoginWithGoogleAccountCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LoginWithIOSDeviceID(ClientModels::LoginWithIOSDeviceIDRequest& request, LoginWithIOSDeviceIDCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LoginWithPlayFab(ClientModels::LoginWithPlayFabRequest& request, LoginWithPlayFabCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LoginWithSteam(ClientModels::LoginWithSteamRequest& request, LoginWithSteamCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RegisterPlayFabUser(ClientModels::RegisterPlayFabUserRequest& request, RegisterPlayFabUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SendAccountRecoveryEmail(ClientModels::SendAccountRecoveryEmailRequest& request, SendAccountRecoveryEmailCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetAccountInfo(ClientModels::GetAccountInfoRequest& request, GetAccountInfoCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserCombinedInfo(ClientModels::GetUserCombinedInfoRequest& request, GetUserCombinedInfoCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LinkFacebookAccount(ClientModels::LinkFacebookAccountRequest& request, LinkFacebookAccountCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LinkGameCenterAccount(ClientModels::LinkGameCenterAccountRequest& request, LinkGameCenterAccountCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LinkSteamAccount(ClientModels::LinkSteamAccountRequest& request, LinkSteamAccountCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UnlinkFacebookAccount(UnlinkFacebookAccountCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UnlinkGameCenterAccount(UnlinkGameCenterAccountCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UnlinkSteamAccount(UnlinkSteamAccountCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateEmailAddress(ClientModels::UpdateEmailAddressRequest& request, UpdateEmailAddressCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdatePassword(ClientModels::UpdatePasswordRequest& request, UpdatePasswordCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserTitleDisplayName(ClientModels::UpdateUserTitleDisplayNameRequest& request, UpdateUserTitleDisplayNameCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetFriendLeaderboard(ClientModels::GetFriendLeaderboardRequest& request, GetFriendLeaderboardCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetLeaderboard(ClientModels::GetLeaderboardRequest& request, GetLeaderboardCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetLeaderboardAroundCurrentUser(ClientModels::GetLeaderboardAroundCurrentUserRequest& request, GetLeaderboardAroundCurrentUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserData(ClientModels::GetUserDataRequest& request, GetUserDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserReadOnlyData(ClientModels::GetUserDataRequest& request, GetUserReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserStatistics(GetUserStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserData(ClientModels::UpdateUserDataRequest& request, UpdateUserDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserStatistics(ClientModels::UpdateUserStatisticsRequest& request, UpdateUserStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCatalogItems(ClientModels::GetCatalogItemsRequest& request, GetCatalogItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetStoreItems(ClientModels::GetStoreItemsRequest& request, GetStoreItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetTitleData(ClientModels::GetTitleDataRequest& request, GetTitleDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetTitleNews(ClientModels::GetTitleNewsRequest& request, GetTitleNewsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddUserVirtualCurrency(ClientModels::AddUserVirtualCurrencyRequest& request, AddUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ConfirmPurchase(ClientModels::ConfirmPurchaseRequest& request, ConfirmPurchaseCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ConsumeItem(ClientModels::ConsumeItemRequest& request, ConsumeItemCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserInventory(GetUserInventoryCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void PayForPurchase(ClientModels::PayForPurchaseRequest& request, PayForPurchaseCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void PurchaseItem(ClientModels::PurchaseItemRequest& request, PurchaseItemCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RedeemCoupon(ClientModels::RedeemCouponRequest& request, RedeemCouponCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void StartPurchase(ClientModels::StartPurchaseRequest& request, StartPurchaseCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SubtractUserVirtualCurrency(ClientModels::SubtractUserVirtualCurrencyRequest& request, SubtractUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UnlockContainerItem(ClientModels::UnlockContainerItemRequest& request, UnlockContainerItemCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddFriend(ClientModels::AddFriendRequest& request, AddFriendCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetFriendsList(ClientModels::GetFriendsListRequest& request, GetFriendsListCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RemoveFriend(ClientModels::RemoveFriendRequest& request, RemoveFriendCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetFriendTags(ClientModels::SetFriendTagsRequest& request, SetFriendTagsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RegisterForIOSPushNotification(ClientModels::RegisterForIOSPushNotificationRequest& request, RegisterForIOSPushNotificationCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ValidateIOSReceipt(ClientModels::ValidateIOSReceiptRequest& request, ValidateIOSReceiptCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCurrentGames(ClientModels::CurrentGamesRequest& request, GetCurrentGamesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetGameServerRegions(ClientModels::GameServerRegionsRequest& request, GetGameServerRegionsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void Matchmake(ClientModels::MatchmakeRequest& request, MatchmakeCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void StartGame(ClientModels::StartGameRequest& request, StartGameCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AndroidDevicePushNotificationRegistration(ClientModels::AndroidDevicePushNotificationRegistrationRequest& request, AndroidDevicePushNotificationRegistrationCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ValidateGooglePlayPurchase(ClientModels::ValidateGooglePlayPurchaseRequest& request, ValidateGooglePlayPurchaseCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LogEvent(ClientModels::LogEventRequest& request, LogEventCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddSharedGroupMembers(ClientModels::AddSharedGroupMembersRequest& request, AddSharedGroupMembersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void CreateSharedGroup(ClientModels::CreateSharedGroupRequest& request, CreateSharedGroupCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetSharedGroupData(ClientModels::GetSharedGroupDataRequest& request, GetSharedGroupDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RemoveSharedGroupMembers(ClientModels::RemoveSharedGroupMembersRequest& request, RemoveSharedGroupMembersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateSharedGroupData(ClientModels::UpdateSharedGroupDataRequest& request, UpdateSharedGroupDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		

    private:

        // ------------ Generated result handlers
		
		static void OnAddUsernamePasswordResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLoginWithAndroidDeviceIDResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLoginWithFacebookResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLoginWithGameCenterResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLoginWithGoogleAccountResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLoginWithIOSDeviceIDResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLoginWithPlayFabResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLoginWithSteamResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRegisterPlayFabUserResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSendAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetAccountInfoResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserCombinedInfoResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLinkFacebookAccountResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLinkGameCenterAccountResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLinkSteamAccountResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUnlinkFacebookAccountResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUnlinkGameCenterAccountResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUnlinkSteamAccountResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateEmailAddressResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdatePasswordResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserTitleDisplayNameResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetFriendLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetLeaderboardAroundCurrentUserResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetStoreItemsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetTitleNewsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnConfirmPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnConsumeItemResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnPayForPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnPurchaseItemResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRedeemCouponResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnStartPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUnlockContainerItemResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddFriendResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetFriendsListResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRemoveFriendResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSetFriendTagsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRegisterForIOSPushNotificationResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnValidateIOSReceiptResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetCurrentGamesResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetGameServerRegionsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnMatchmakeResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnStartGameResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAndroidDevicePushNotificationRegistrationResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnValidateGooglePlayPurchaseResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLogEventResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnCreateSharedGroupResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRemoveSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
		
 
        bool mOwnsRequester;
        IHttpRequester* mHttpRequester;
		
		
        std::string mUserSessionTicket;
		
    };

};

#endif