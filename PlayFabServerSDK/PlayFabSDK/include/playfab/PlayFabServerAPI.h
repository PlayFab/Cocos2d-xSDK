#ifndef PLAYFAB_SERVERAPI_H_
#define PLAYFAB_SERVERAPI_H_

#include "playfab/IHttpRequester.h"
#include "playfab/PlayFabError.h"
#include "playfab/PlayFabServerDataModels.h"
#include "playfab/PlayFabSettings.h"

#include <string>


namespace PlayFab
{
	
    
    class PlayFabServerAPI
    {
    public:
		
		typedef void(*AuthenticateSessionTicketCallback)(ServerModels::AuthenticateSessionTicketResult& result, void* userData);
		typedef void(*GetUserAccountInfoCallback)(ServerModels::GetUserAccountInfoResult& result, void* userData);
		typedef void(*SendPushNotificationCallback)(ServerModels::SendPushNotificationResult& result, void* userData);
		typedef void(*GetLeaderboardCallback)(ServerModels::GetLeaderboardResult& result, void* userData);
		typedef void(*GetLeaderboardAroundUserCallback)(ServerModels::GetLeaderboardAroundUserResult& result, void* userData);
		typedef void(*GetUserDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserInternalDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserPublisherDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserPublisherInternalDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserPublisherReadOnlyDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserReadOnlyDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserStatisticsCallback)(ServerModels::GetUserStatisticsResult& result, void* userData);
		typedef void(*UpdateUserDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserInternalDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserPublisherDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserPublisherInternalDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserPublisherReadOnlyDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserReadOnlyDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserStatisticsCallback)(ServerModels::UpdateUserStatisticsResult& result, void* userData);
		typedef void(*GetCatalogItemsCallback)(ServerModels::GetCatalogItemsResult& result, void* userData);
		typedef void(*GetTitleDataCallback)(ServerModels::GetTitleDataResult& result, void* userData);
		typedef void(*SetTitleDataCallback)(ServerModels::SetTitleDataResult& result, void* userData);
		typedef void(*AddUserVirtualCurrencyCallback)(ServerModels::ModifyUserVirtualCurrencyResult& result, void* userData);
		typedef void(*GetUserInventoryCallback)(ServerModels::GetUserInventoryResult& result, void* userData);
		typedef void(*GrantItemsToUserCallback)(ServerModels::GrantItemsToUserResult& result, void* userData);
		typedef void(*GrantItemsToUsersCallback)(ServerModels::GrantItemsToUsersResult& result, void* userData);
		typedef void(*ModifyItemUsesCallback)(ServerModels::ModifyItemUsesResult& result, void* userData);
		typedef void(*ReportPlayerCallback)(ServerModels::ReportPlayerServerResult& result, void* userData);
		typedef void(*SubtractUserVirtualCurrencyCallback)(ServerModels::ModifyUserVirtualCurrencyResult& result, void* userData);
		typedef void(*NotifyMatchmakerPlayerLeftCallback)(ServerModels::NotifyMatchmakerPlayerLeftResult& result, void* userData);
		typedef void(*RedeemMatchmakerTicketCallback)(ServerModels::RedeemMatchmakerTicketResult& result, void* userData);
		typedef void(*AwardSteamAchievementCallback)(ServerModels::AwardSteamAchievementResult& result, void* userData);
		typedef void(*AddSharedGroupMembersCallback)(ServerModels::AddSharedGroupMembersResult& result, void* userData);
		typedef void(*CreateSharedGroupCallback)(ServerModels::CreateSharedGroupResult& result, void* userData);
		typedef void(*DeleteSharedGroupCallback)(ServerModels::EmptyResult& result, void* userData);
		typedef void(*GetPublisherDataCallback)(ServerModels::GetPublisherDataResult& result, void* userData);
		typedef void(*GetSharedGroupDataCallback)(ServerModels::GetSharedGroupDataResult& result, void* userData);
		typedef void(*RemoveSharedGroupMembersCallback)(ServerModels::RemoveSharedGroupMembersResult& result, void* userData);
		typedef void(*SetPublisherDataCallback)(ServerModels::SetPublisherDataResult& result, void* userData);
		typedef void(*UpdateSharedGroupDataCallback)(ServerModels::UpdateSharedGroupDataResult& result, void* userData);
		
	
        PlayFabServerAPI();
        PlayFabServerAPI(IHttpRequester* requester, bool ownRequester);
        ~PlayFabServerAPI();

        IHttpRequester* GetRequester(bool relinquishOwnership = false);
        void Update();

        // ------------ Generated API calls
		
		void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, AuthenticateSessionTicketCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, GetUserAccountInfoCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SendPushNotification(ServerModels::SendPushNotificationRequest& request, SendPushNotificationCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetLeaderboard(ServerModels::GetLeaderboardRequest& request, GetLeaderboardCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, GetLeaderboardAroundUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserData(ServerModels::GetUserDataRequest& request, GetUserDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserInternalData(ServerModels::GetUserDataRequest& request, GetUserInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserPublisherData(ServerModels::GetUserDataRequest& request, GetUserPublisherDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserPublisherInternalData(ServerModels::GetUserDataRequest& request, GetUserPublisherInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserPublisherReadOnlyData(ServerModels::GetUserDataRequest& request, GetUserPublisherReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, GetUserReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserStatistics(ServerModels::GetUserStatisticsRequest& request, GetUserStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserData(ServerModels::UpdateUserDataRequest& request, UpdateUserDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, UpdateUserInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserPublisherData(ServerModels::UpdateUserDataRequest& request, UpdateUserPublisherDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserPublisherInternalData(ServerModels::UpdateUserInternalDataRequest& request, UpdateUserPublisherInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserPublisherReadOnlyData(ServerModels::UpdateUserDataRequest& request, UpdateUserPublisherReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, UpdateUserReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserStatistics(ServerModels::UpdateUserStatisticsRequest& request, UpdateUserStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, GetCatalogItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetTitleData(ServerModels::GetTitleDataRequest& request, GetTitleDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetTitleData(ServerModels::SetTitleDataRequest& request, SetTitleDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, AddUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserInventory(ServerModels::GetUserInventoryRequest& request, GetUserInventoryCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, GrantItemsToUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, GrantItemsToUsersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ModifyItemUsesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ReportPlayerCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, SubtractUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, NotifyMatchmakerPlayerLeftCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, RedeemMatchmakerTicketCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, AwardSteamAchievementCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, AddSharedGroupMembersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, CreateSharedGroupCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, DeleteSharedGroupCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetPublisherData(ServerModels::GetPublisherDataRequest& request, GetPublisherDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, GetSharedGroupDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, RemoveSharedGroupMembersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetPublisherData(ServerModels::SetPublisherDataRequest& request, SetPublisherDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, UpdateSharedGroupDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		

    private:

        // ------------ Generated result handlers
		
		static void OnAuthenticateSessionTicketResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserAccountInfoResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSendPushNotificationResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetLeaderboardAroundUserResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserPublisherInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserPublisherReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGrantItemsToUserResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGrantItemsToUsersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnModifyItemUsesResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnReportPlayerResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnNotifyMatchmakerPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRedeemMatchmakerTicketResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAwardSteamAchievementResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnCreateSharedGroupResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnDeleteSharedGroupResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRemoveSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
		
 
        bool mOwnsRequester;
        IHttpRequester* mHttpRequester;
		
		
    };

};

#endif