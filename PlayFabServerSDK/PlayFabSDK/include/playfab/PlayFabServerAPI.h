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
		typedef void(*GetPlayFabIDsFromFacebookIDsCallback)(ServerModels::GetPlayFabIDsFromFacebookIDsResult& result, void* userData);
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
		typedef void(*GetTitleInternalDataCallback)(ServerModels::GetTitleDataResult& result, void* userData);
		typedef void(*GetTitleNewsCallback)(ServerModels::GetTitleNewsResult& result, void* userData);
		typedef void(*SetTitleDataCallback)(ServerModels::SetTitleDataResult& result, void* userData);
		typedef void(*SetTitleInternalDataCallback)(ServerModels::SetTitleDataResult& result, void* userData);
		typedef void(*AddCharacterVirtualCurrencyCallback)(ServerModels::ModifyCharacterVirtualCurrencyResult& result, void* userData);
		typedef void(*AddUserVirtualCurrencyCallback)(ServerModels::ModifyUserVirtualCurrencyResult& result, void* userData);
		typedef void(*GetCharacterInventoryCallback)(ServerModels::GetCharacterInventoryResult& result, void* userData);
		typedef void(*GetUserInventoryCallback)(ServerModels::GetUserInventoryResult& result, void* userData);
		typedef void(*GrantItemsToCharacterCallback)(ServerModels::GrantItemsToCharacterResult& result, void* userData);
		typedef void(*GrantItemsToUserCallback)(ServerModels::GrantItemsToUserResult& result, void* userData);
		typedef void(*GrantItemsToUsersCallback)(ServerModels::GrantItemsToUsersResult& result, void* userData);
		typedef void(*ModifyItemUsesCallback)(ServerModels::ModifyItemUsesResult& result, void* userData);
		typedef void(*MoveItemToCharacterFromCharacterCallback)(ServerModels::MoveItemToCharacterFromCharacterResult& result, void* userData);
		typedef void(*MoveItemToCharacterFromUserCallback)(ServerModels::MoveItemToCharacterFromUserResult& result, void* userData);
		typedef void(*MoveItemToUserFromCharacterCallback)(ServerModels::MoveItemToUserFromCharacterResult& result, void* userData);
		typedef void(*ReportPlayerCallback)(ServerModels::ReportPlayerServerResult& result, void* userData);
		typedef void(*SubtractCharacterVirtualCurrencyCallback)(ServerModels::ModifyCharacterVirtualCurrencyResult& result, void* userData);
		typedef void(*SubtractUserVirtualCurrencyCallback)(ServerModels::ModifyUserVirtualCurrencyResult& result, void* userData);
		typedef void(*UpdateUserInventoryItemCustomDataCallback)(ServerModels::UpdateUserInventoryItemDataResult& result, void* userData);
		typedef void(*NotifyMatchmakerPlayerLeftCallback)(ServerModels::NotifyMatchmakerPlayerLeftResult& result, void* userData);
		typedef void(*RedeemMatchmakerTicketCallback)(ServerModels::RedeemMatchmakerTicketResult& result, void* userData);
		typedef void(*AwardSteamAchievementCallback)(ServerModels::AwardSteamAchievementResult& result, void* userData);
		typedef void(*LogEventCallback)(ServerModels::LogEventResult& result, void* userData);
		typedef void(*AddSharedGroupMembersCallback)(ServerModels::AddSharedGroupMembersResult& result, void* userData);
		typedef void(*CreateSharedGroupCallback)(ServerModels::CreateSharedGroupResult& result, void* userData);
		typedef void(*DeleteSharedGroupCallback)(ServerModels::EmptyResult& result, void* userData);
		typedef void(*GetPublisherDataCallback)(ServerModels::GetPublisherDataResult& result, void* userData);
		typedef void(*GetSharedGroupDataCallback)(ServerModels::GetSharedGroupDataResult& result, void* userData);
		typedef void(*RemoveSharedGroupMembersCallback)(ServerModels::RemoveSharedGroupMembersResult& result, void* userData);
		typedef void(*SetPublisherDataCallback)(ServerModels::SetPublisherDataResult& result, void* userData);
		typedef void(*UpdateSharedGroupDataCallback)(ServerModels::UpdateSharedGroupDataResult& result, void* userData);
		typedef void(*GetContentDownloadUrlCallback)(ServerModels::GetContentDownloadUrlResult& result, void* userData);
		typedef void(*DeleteCharacterFromUserCallback)(ServerModels::DeleteCharacterFromUserResult& result, void* userData);
		typedef void(*GetAllUsersCharactersCallback)(ServerModels::ListUsersCharactersResult& result, void* userData);
		typedef void(*GetCharacterLeaderboardCallback)(ServerModels::GetCharacterLeaderboardResult& result, void* userData);
		typedef void(*GetCharacterStatisticsCallback)(ServerModels::GetCharacterStatisticsResult& result, void* userData);
		typedef void(*GetLeaderboardAroundCharacterCallback)(ServerModels::GetLeaderboardAroundCharacterResult& result, void* userData);
		typedef void(*GetLeaderboardForUserCharactersCallback)(ServerModels::GetLeaderboardForUsersCharactersResult& result, void* userData);
		typedef void(*GrantCharacterToUserCallback)(ServerModels::GrantCharacterToUserResult& result, void* userData);
		typedef void(*UpdateCharacterStatisticsCallback)(ServerModels::UpdateCharacterStatisticsResult& result, void* userData);
		typedef void(*GetCharacterDataCallback)(ServerModels::GetCharacterDataResult& result, void* userData);
		typedef void(*GetCharacterInternalDataCallback)(ServerModels::GetCharacterDataResult& result, void* userData);
		typedef void(*GetCharacterReadOnlyDataCallback)(ServerModels::GetCharacterDataResult& result, void* userData);
		typedef void(*UpdateCharacterDataCallback)(ServerModels::UpdateCharacterDataResult& result, void* userData);
		typedef void(*UpdateCharacterInternalDataCallback)(ServerModels::UpdateCharacterDataResult& result, void* userData);
		typedef void(*UpdateCharacterReadOnlyDataCallback)(ServerModels::UpdateCharacterDataResult& result, void* userData);
		
	
        PlayFabServerAPI();
        PlayFabServerAPI(IHttpRequester* requester, bool ownRequester);
        ~PlayFabServerAPI();

        IHttpRequester* GetRequester(bool relinquishOwnership = false);
        size_t Update();

		

        // ------------ Generated API calls
		
		void AuthenticateSessionTicket(ServerModels::AuthenticateSessionTicketRequest& request, AuthenticateSessionTicketCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetPlayFabIDsFromFacebookIDs(ServerModels::GetPlayFabIDsFromFacebookIDsRequest& request, GetPlayFabIDsFromFacebookIDsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
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
		
		void GetTitleInternalData(ServerModels::GetTitleDataRequest& request, GetTitleInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetTitleNews(ServerModels::GetTitleNewsRequest& request, GetTitleNewsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetTitleData(ServerModels::SetTitleDataRequest& request, SetTitleDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetTitleInternalData(ServerModels::SetTitleDataRequest& request, SetTitleInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddCharacterVirtualCurrency(ServerModels::AddCharacterVirtualCurrencyRequest& request, AddCharacterVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddUserVirtualCurrency(ServerModels::AddUserVirtualCurrencyRequest& request, AddUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCharacterInventory(ServerModels::GetCharacterInventoryRequest& request, GetCharacterInventoryCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserInventory(ServerModels::GetUserInventoryRequest& request, GetUserInventoryCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GrantItemsToCharacter(ServerModels::GrantItemsToCharacterRequest& request, GrantItemsToCharacterCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GrantItemsToUser(ServerModels::GrantItemsToUserRequest& request, GrantItemsToUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GrantItemsToUsers(ServerModels::GrantItemsToUsersRequest& request, GrantItemsToUsersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ModifyItemUses(ServerModels::ModifyItemUsesRequest& request, ModifyItemUsesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void MoveItemToCharacterFromCharacter(ServerModels::MoveItemToCharacterFromCharacterRequest& request, MoveItemToCharacterFromCharacterCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void MoveItemToCharacterFromUser(ServerModels::MoveItemToCharacterFromUserRequest& request, MoveItemToCharacterFromUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void MoveItemToUserFromCharacter(ServerModels::MoveItemToUserFromCharacterRequest& request, MoveItemToUserFromCharacterCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ReportPlayer(ServerModels::ReportPlayerServerRequest& request, ReportPlayerCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SubtractCharacterVirtualCurrency(ServerModels::SubtractCharacterVirtualCurrencyRequest& request, SubtractCharacterVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SubtractUserVirtualCurrency(ServerModels::SubtractUserVirtualCurrencyRequest& request, SubtractUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserInventoryItemCustomData(ServerModels::UpdateUserInventoryItemDataRequest& request, UpdateUserInventoryItemCustomDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void NotifyMatchmakerPlayerLeft(ServerModels::NotifyMatchmakerPlayerLeftRequest& request, NotifyMatchmakerPlayerLeftCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RedeemMatchmakerTicket(ServerModels::RedeemMatchmakerTicketRequest& request, RedeemMatchmakerTicketCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AwardSteamAchievement(ServerModels::AwardSteamAchievementRequest& request, AwardSteamAchievementCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void LogEvent(ServerModels::LogEventRequest& request, LogEventCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddSharedGroupMembers(ServerModels::AddSharedGroupMembersRequest& request, AddSharedGroupMembersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void CreateSharedGroup(ServerModels::CreateSharedGroupRequest& request, CreateSharedGroupCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void DeleteSharedGroup(ServerModels::DeleteSharedGroupRequest& request, DeleteSharedGroupCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetPublisherData(ServerModels::GetPublisherDataRequest& request, GetPublisherDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetSharedGroupData(ServerModels::GetSharedGroupDataRequest& request, GetSharedGroupDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RemoveSharedGroupMembers(ServerModels::RemoveSharedGroupMembersRequest& request, RemoveSharedGroupMembersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetPublisherData(ServerModels::SetPublisherDataRequest& request, SetPublisherDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateSharedGroupData(ServerModels::UpdateSharedGroupDataRequest& request, UpdateSharedGroupDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetContentDownloadUrl(ServerModels::GetContentDownloadUrlRequest& request, GetContentDownloadUrlCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void DeleteCharacterFromUser(ServerModels::DeleteCharacterFromUserRequest& request, DeleteCharacterFromUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetAllUsersCharacters(ServerModels::ListUsersCharactersRequest& request, GetAllUsersCharactersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCharacterLeaderboard(ServerModels::GetCharacterLeaderboardRequest& request, GetCharacterLeaderboardCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCharacterStatistics(ServerModels::GetCharacterStatisticsRequest& request, GetCharacterStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetLeaderboardAroundCharacter(ServerModels::GetLeaderboardAroundCharacterRequest& request, GetLeaderboardAroundCharacterCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetLeaderboardForUserCharacters(ServerModels::GetLeaderboardForUsersCharactersRequest& request, GetLeaderboardForUserCharactersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GrantCharacterToUser(ServerModels::GrantCharacterToUserRequest& request, GrantCharacterToUserCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateCharacterStatistics(ServerModels::UpdateCharacterStatisticsRequest& request, UpdateCharacterStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCharacterData(ServerModels::GetCharacterDataRequest& request, GetCharacterDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCharacterInternalData(ServerModels::GetCharacterDataRequest& request, GetCharacterInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCharacterReadOnlyData(ServerModels::GetCharacterDataRequest& request, GetCharacterReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateCharacterData(ServerModels::UpdateCharacterDataRequest& request, UpdateCharacterDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateCharacterInternalData(ServerModels::UpdateCharacterDataRequest& request, UpdateCharacterInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateCharacterReadOnlyData(ServerModels::UpdateCharacterDataRequest& request, UpdateCharacterReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		

    private:

        // ------------ Generated result handlers
		
		static void OnAuthenticateSessionTicketResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetPlayFabIDsFromFacebookIDsResult(int httpStatus, HttpRequest* request, void* userData);
		
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
		
		static void OnGetTitleInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetTitleNewsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSetTitleDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSetTitleInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddCharacterVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetCharacterInventoryResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserInventoryResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGrantItemsToCharacterResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGrantItemsToUserResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGrantItemsToUsersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnModifyItemUsesResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnMoveItemToCharacterFromCharacterResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnMoveItemToCharacterFromUserResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnMoveItemToUserFromCharacterResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnReportPlayerResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSubtractCharacterVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSubtractUserVirtualCurrencyResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserInventoryItemCustomDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnNotifyMatchmakerPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRedeemMatchmakerTicketResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAwardSteamAchievementResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnLogEventResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnAddSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnCreateSharedGroupResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnDeleteSharedGroupResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnRemoveSharedGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSetPublisherDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateSharedGroupDataResult(int httpStatus, HttpRequest* request, void* userData);
		
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
		
 
        bool mOwnsRequester;
        IHttpRequester* mHttpRequester;
		
		
    };

};

#endif