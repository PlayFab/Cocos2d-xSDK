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
		
		typedef void(*GetUserAccountInfoCallback)(ServerModels::GetUserAccountInfoResult& result, void* userData);
		typedef void(*SendPushNotificationCallback)(ServerModels::SendPushNotificationResult& result, void* userData);
		typedef void(*GetLeaderboardCallback)(ServerModels::GetLeaderboardResult& result, void* userData);
		typedef void(*GetLeaderboardAroundUserCallback)(ServerModels::GetLeaderboardAroundUserResult& result, void* userData);
		typedef void(*GetUserDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserInternalDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserReadOnlyDataCallback)(ServerModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserStatisticsCallback)(ServerModels::GetUserStatisticsResult& result, void* userData);
		typedef void(*UpdateUserDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserInternalDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserReadOnlyDataCallback)(ServerModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserStatisticsCallback)(ServerModels::UpdateUserStatisticsResult& result, void* userData);
		typedef void(*GetCatalogItemsCallback)(ServerModels::GetCatalogItemsResult& result, void* userData);
		typedef void(*GetTitleDataCallback)(ServerModels::GetTitleDataResult& result, void* userData);
		typedef void(*SetTitleDataCallback)(ServerModels::SetTitleDataResult& result, void* userData);
		typedef void(*AddUserVirtualCurrencyCallback)(ServerModels::ModifyUserVirtualCurrencyResult& result, void* userData);
		typedef void(*GetUserInventoryCallback)(ServerModels::GetUserInventoryResult& result, void* userData);
		typedef void(*GrantItemsToUsersCallback)(ServerModels::GrantItemsToUsersResult& result, void* userData);
		typedef void(*SubtractUserVirtualCurrencyCallback)(ServerModels::ModifyUserVirtualCurrencyResult& result, void* userData);
		typedef void(*NotifyMatchmakerPlayerLeftCallback)(ServerModels::NotifyMatchmakerPlayerLeftResult& result, void* userData);
		typedef void(*RedeemMatchmakerTicketCallback)(ServerModels::RedeemMatchmakerTicketResult& result, void* userData);
		typedef void(*AwardSteamAchievementCallback)(ServerModels::AwardSteamAchievementResult& result, void* userData);
		
	
        PlayFabServerAPI();
        PlayFabServerAPI(IHttpRequester* requester, bool ownRequester);
        ~PlayFabServerAPI();

        IHttpRequester* GetRequester(bool relinquishOwnership = false);
        void Update();

        // ------------ Generated API calls
		
		void GetUserAccountInfo(ServerModels::GetUserAccountInfoRequest& request, GetUserAccountInfoCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SendPushNotification(ServerModels::SendPushNotificationRequest& request, SendPushNotificationCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetLeaderboard(ServerModels::GetLeaderboardRequest& request, GetLeaderboardCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetLeaderboardAroundUser(ServerModels::GetLeaderboardAroundUserRequest& request, GetLeaderboardAroundUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserData(ServerModels::GetUserDataRequest& request, GetUserDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserInternalData(ServerModels::GetUserDataRequest& request, GetUserInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserReadOnlyData(ServerModels::GetUserDataRequest& request, GetUserReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserStatistics(ServerModels::GetUserStatisticsRequest& request, GetUserStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserData(ServerModels::UpdateUserDataRequest& request, UpdateUserDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserInternalData(ServerModels::UpdateUserInternalDataRequest& request, UpdateUserInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserReadOnlyData(ServerModels::UpdateUserDataRequest& request, UpdateUserReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserStatistics(ServerModels::UpdateUserStatisticsRequest& request, UpdateUserStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCatalogItems(ServerModels::GetCatalogItemsRequest& request, GetCatalogItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetTitleData(ServerModels::GetTitleDataRequest& request, GetTitleDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetTitleData(ServerModels::SetTitleDataRequest& request, SetTitleDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, AddUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserInventory(ServerModels::GetUserInventoryRequest& request, GetUserInventoryCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, GrantItemsToUsersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, SubtractUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, NotifyMatchmakerPlayerLeftCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, RedeemMatchmakerTicketCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, AwardSteamAchievementCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		

    private:

        // ------------ Generated result handlers
		
		static void OnGetUserAccountInfoResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSendPushNotificationResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetLeaderboardResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetLeaderboardAroundUserResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetCatalogItemsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGrantItemsToUsersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnNotifyMatchmakerPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRedeemMatchmakerTicketResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAwardSteamAchievementResult(int httpStatus, HttpRequest* request, void* userData);
		
 
        bool mOwnsRequester;
        IHttpRequester* mHttpRequester;
		
		
    };

};

#endif