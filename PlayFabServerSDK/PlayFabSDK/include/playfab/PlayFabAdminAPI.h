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
		typedef void(*SendAccountRecoveryEmailCallback)(AdminModels::SendAccountRecoveryEmailResult& result, void* userData);
		typedef void(*UpdateUserTitleDisplayNameCallback)(AdminModels::UpdateUserTitleDisplayNameResult& result, void* userData);
		typedef void(*GetUserDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserInternalDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
		typedef void(*GetUserReadOnlyDataCallback)(AdminModels::GetUserDataResult& result, void* userData);
		typedef void(*ResetUserStatisticsCallback)(AdminModels::ResetUserStatisticsResult& result, void* userData);
		typedef void(*UpdateUserDataCallback)(AdminModels::UpdateUserDataResult& result, void* userData);
		typedef void(*UpdateUserInternalDataCallback)(AdminModels::UpdateUserDataResult& result, void* userData);
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
		
	
        PlayFabAdminAPI();
        PlayFabAdminAPI(IHttpRequester* requester, bool ownRequester);
        ~PlayFabAdminAPI();

        IHttpRequester* GetRequester(bool relinquishOwnership = false);
        void Update();

        // ------------ Generated API calls
		
		void GetUserAccountInfo(AdminModels::LookupUserAccountInfoRequest& request, GetUserAccountInfoCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SendAccountRecoveryEmail(AdminModels::SendAccountRecoveryEmailRequest& request, SendAccountRecoveryEmailCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserTitleDisplayName(AdminModels::UpdateUserTitleDisplayNameRequest& request, UpdateUserTitleDisplayNameCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserData(AdminModels::GetUserDataRequest& request, GetUserDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserInternalData(AdminModels::GetUserDataRequest& request, GetUserInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserReadOnlyData(AdminModels::GetUserDataRequest& request, GetUserReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ResetUserStatistics(AdminModels::ResetUserStatisticsRequest& request, ResetUserStatisticsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserData(AdminModels::UpdateUserDataRequest& request, UpdateUserDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserInternalData(AdminModels::UpdateUserInternalDataRequest& request, UpdateUserInternalDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateUserReadOnlyData(AdminModels::UpdateUserDataRequest& request, UpdateUserReadOnlyDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddNews(AdminModels::AddNewsRequest& request, AddNewsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddVirtualCurrencyTypes(AdminModels::AddVirtualCurrencyTypesRequest& request, AddVirtualCurrencyTypesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetCatalogItems(AdminModels::GetCatalogItemsRequest& request, GetCatalogItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetRandomResultTables(GetRandomResultTablesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetStoreItems(AdminModels::GetStoreItemsRequest& request, GetStoreItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetTitleData(AdminModels::GetTitleDataRequest& request, GetTitleDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ListVirtualCurrencyTypes(ListVirtualCurrencyTypesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, SetCatalogItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetStoreItems(AdminModels::UpdateStoreItemsRequest& request, SetStoreItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SetTitleData(AdminModels::SetTitleDataRequest& request, SetTitleDataCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateCatalogItems(AdminModels::UpdateCatalogItemsRequest& request, UpdateCatalogItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateRandomResultTables(AdminModels::UpdateRandomResultTablesRequest& request, UpdateRandomResultTablesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void UpdateStoreItems(AdminModels::UpdateStoreItemsRequest& request, UpdateStoreItemsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddUserVirtualCurrency(AdminModels::AddUserVirtualCurrencyRequest& request, AddUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetUserInventory(AdminModels::GetUserInventoryRequest& request, GetUserInventoryCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GrantItemsToUsers(AdminModels::GrantItemsToUsersRequest& request, GrantItemsToUsersCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RevokeInventoryItem(AdminModels::RevokeInventoryItemRequest& request, RevokeInventoryItemCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void SubtractUserVirtualCurrency(AdminModels::SubtractUserVirtualCurrencyRequest& request, SubtractUserVirtualCurrencyCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetMatchmakerGameInfo(AdminModels::GetMatchmakerGameInfoRequest& request, GetMatchmakerGameInfoCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetMatchmakerGameModes(AdminModels::GetMatchmakerGameModesRequest& request, GetMatchmakerGameModesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ModifyMatchmakerGameModes(AdminModels::ModifyMatchmakerGameModesRequest& request, ModifyMatchmakerGameModesCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void AddServerBuild(AdminModels::AddServerBuildRequest& request, AddServerBuildCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetServerBuildInfo(AdminModels::GetServerBuildInfoRequest& request, GetServerBuildInfoCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void GetServerBuildUploadUrl(AdminModels::GetServerBuildUploadURLRequest& request, GetServerBuildUploadUrlCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ListServerBuilds(ListServerBuildsCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void ModifyServerBuild(AdminModels::ModifyServerBuildRequest& request, ModifyServerBuildCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		
		void RemoveServerBuild(AdminModels::RemoveServerBuildRequest& request, RemoveServerBuildCallback callback, ErrorCallback errorCallback = NULL, void* userData = NULL);
		

    private:

        // ------------ Generated result handlers
		
		static void OnGetUserAccountInfoResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnSendAccountRecoveryEmailResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserTitleDisplayNameResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnGetUserReadOnlyDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnResetUserStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserDataResult(int httpStatus, HttpRequest* request, void* userData);
		
		static void OnUpdateUserInternalDataResult(int httpStatus, HttpRequest* request, void* userData);
		
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
		
 
        bool mOwnsRequester;
        IHttpRequester* mHttpRequester;
		
		
    };

};

#endif