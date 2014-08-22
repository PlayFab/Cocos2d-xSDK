#ifndef PLAYFAB_SERVER_DATA_MODELS_H_
#define PLAYFAB_SERVER_DATA_MODELS_H_

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
namespace ServerModels
{

	
	struct AddUserVirtualCurrencyRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string VirtualCurrency;
		Int32 Amount;
	
        AddUserVirtualCurrencyRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			VirtualCurrency(),
			Amount(0)
			{}
		
		AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			VirtualCurrency(src.VirtualCurrency),
			Amount(src.Amount)
			{}
			
		AddUserVirtualCurrencyRequest(const rapidjson::Value& obj) : AddUserVirtualCurrencyRequest()
        {
            readFromValue(obj);
        }
		
		~AddUserVirtualCurrencyRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct AwardSteamAchievementItem : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string AchievementName;
		bool Result;
	
        AwardSteamAchievementItem() :
			PlayFabBaseModel(),
			PlayFabId(),
			AchievementName(),
			Result(false)
			{}
		
		AwardSteamAchievementItem(const AwardSteamAchievementItem& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			AchievementName(src.AchievementName),
			Result(src.Result)
			{}
			
		AwardSteamAchievementItem(const rapidjson::Value& obj) : AwardSteamAchievementItem()
        {
            readFromValue(obj);
        }
		
		~AwardSteamAchievementItem();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct AwardSteamAchievementRequest : public PlayFabBaseModel
    {
		
		std::list<AwardSteamAchievementItem> Achievements;
	
        AwardSteamAchievementRequest() :
			PlayFabBaseModel(),
			Achievements()
			{}
		
		AwardSteamAchievementRequest(const AwardSteamAchievementRequest& src) :
			PlayFabBaseModel(),
			Achievements(src.Achievements)
			{}
			
		AwardSteamAchievementRequest(const rapidjson::Value& obj) : AwardSteamAchievementRequest()
        {
            readFromValue(obj);
        }
		
		~AwardSteamAchievementRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct AwardSteamAchievementResult : public PlayFabBaseModel
    {
		
		std::list<AwardSteamAchievementItem> AchievementResults;
	
        AwardSteamAchievementResult() :
			PlayFabBaseModel(),
			AchievementResults()
			{}
		
		AwardSteamAchievementResult(const AwardSteamAchievementResult& src) :
			PlayFabBaseModel(),
			AchievementResults(src.AchievementResults)
			{}
			
		AwardSteamAchievementResult(const rapidjson::Value& obj) : AwardSteamAchievementResult()
        {
            readFromValue(obj);
        }
		
		~AwardSteamAchievementResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct CatalogItemConsumableInfo : public PlayFabBaseModel
    {
		
		OptionalUint32 UsageCount;
		OptionalUint32 UsagePeriod;
		std::string UsagePeriodGroup;
	
        CatalogItemConsumableInfo() :
			PlayFabBaseModel(),
			UsageCount(),
			UsagePeriod(),
			UsagePeriodGroup()
			{}
		
		CatalogItemConsumableInfo(const CatalogItemConsumableInfo& src) :
			PlayFabBaseModel(),
			UsageCount(src.UsageCount),
			UsagePeriod(src.UsagePeriod),
			UsagePeriodGroup(src.UsagePeriodGroup)
			{}
			
		CatalogItemConsumableInfo(const rapidjson::Value& obj) : CatalogItemConsumableInfo()
        {
            readFromValue(obj);
        }
		
		~CatalogItemConsumableInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct CatalogItemContainerInfo : public PlayFabBaseModel
    {
		
		std::string KeyItemId;
		std::list<std::string> ItemContents;
		std::list<std::string> ResultTableContents;
		std::map<std::string, Uint32> VirtualCurrencyContents;
	
        CatalogItemContainerInfo() :
			PlayFabBaseModel(),
			KeyItemId(),
			ItemContents(),
			ResultTableContents(),
			VirtualCurrencyContents()
			{}
		
		CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
			PlayFabBaseModel(),
			KeyItemId(src.KeyItemId),
			ItemContents(src.ItemContents),
			ResultTableContents(src.ResultTableContents),
			VirtualCurrencyContents(src.VirtualCurrencyContents)
			{}
			
		CatalogItemContainerInfo(const rapidjson::Value& obj) : CatalogItemContainerInfo()
        {
            readFromValue(obj);
        }
		
		~CatalogItemContainerInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct CatalogItemBundleInfo : public PlayFabBaseModel
    {
		
		std::list<std::string> BundledItems;
		std::list<std::string> BundledResultTables;
		std::map<std::string, Uint32> BundledVirtualCurrencies;
	
        CatalogItemBundleInfo() :
			PlayFabBaseModel(),
			BundledItems(),
			BundledResultTables(),
			BundledVirtualCurrencies()
			{}
		
		CatalogItemBundleInfo(const CatalogItemBundleInfo& src) :
			PlayFabBaseModel(),
			BundledItems(src.BundledItems),
			BundledResultTables(src.BundledResultTables),
			BundledVirtualCurrencies(src.BundledVirtualCurrencies)
			{}
			
		CatalogItemBundleInfo(const rapidjson::Value& obj) : CatalogItemBundleInfo()
        {
            readFromValue(obj);
        }
		
		~CatalogItemBundleInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct CatalogItem : public PlayFabBaseModel
    {
		
		std::string ItemId;
		std::string ItemClass;
		std::string CatalogVersion;
		std::string DisplayName;
		std::string Description;
		std::map<std::string, Uint32> VirtualCurrencyPrices;
		std::map<std::string, Uint32> RealCurrencyPrices;
		OptionalTime ReleaseDate;
		OptionalTime ExpirationDate;
		OptionalBool IsFree;
		OptionalBool NotForSale;
		OptionalBool NotForTrade;
		std::list<std::string> Tags;
		std::string CustomData;
		std::list<std::string> GrantedIfPlayerHas;
		CatalogItemConsumableInfo* Consumable;
		CatalogItemContainerInfo* Container;
		CatalogItemBundleInfo* Bundle;
	
        CatalogItem() :
			PlayFabBaseModel(),
			ItemId(),
			ItemClass(),
			CatalogVersion(),
			DisplayName(),
			Description(),
			VirtualCurrencyPrices(),
			RealCurrencyPrices(),
			ReleaseDate(),
			ExpirationDate(),
			IsFree(),
			NotForSale(),
			NotForTrade(),
			Tags(),
			CustomData(),
			GrantedIfPlayerHas(),
			Consumable(NULL),
			Container(NULL),
			Bundle(NULL)
			{}
		
		CatalogItem(const CatalogItem& src) :
			PlayFabBaseModel(),
			ItemId(src.ItemId),
			ItemClass(src.ItemClass),
			CatalogVersion(src.CatalogVersion),
			DisplayName(src.DisplayName),
			Description(src.Description),
			VirtualCurrencyPrices(src.VirtualCurrencyPrices),
			RealCurrencyPrices(src.RealCurrencyPrices),
			ReleaseDate(src.ReleaseDate),
			ExpirationDate(src.ExpirationDate),
			IsFree(src.IsFree),
			NotForSale(src.NotForSale),
			NotForTrade(src.NotForTrade),
			Tags(src.Tags),
			CustomData(src.CustomData),
			GrantedIfPlayerHas(src.GrantedIfPlayerHas),
			Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : NULL),
			Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : NULL),
			Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : NULL)
			{}
			
		CatalogItem(const rapidjson::Value& obj) : CatalogItem()
        {
            readFromValue(obj);
        }
		
		~CatalogItem();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	enum Currency
	{
		CurrencyUSD,
		CurrencyGBP,
		CurrencyEUR,
		CurrencyRUB,
		CurrencyBRL,
		CurrencyCIS,
		CurrencyCAD
	};
	
	void writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer);
	Currency readCurrencyFromValue(const rapidjson::Value& obj);
	
	
	struct GetCatalogItemsRequest : public PlayFabBaseModel
    {
		
		std::string CatalogVersion;
	
        GetCatalogItemsRequest() :
			PlayFabBaseModel(),
			CatalogVersion()
			{}
		
		GetCatalogItemsRequest(const GetCatalogItemsRequest& src) :
			PlayFabBaseModel(),
			CatalogVersion(src.CatalogVersion)
			{}
			
		GetCatalogItemsRequest(const rapidjson::Value& obj) : GetCatalogItemsRequest()
        {
            readFromValue(obj);
        }
		
		~GetCatalogItemsRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetCatalogItemsResult : public PlayFabBaseModel
    {
		
		std::list<CatalogItem> Catalog;
	
        GetCatalogItemsResult() :
			PlayFabBaseModel(),
			Catalog()
			{}
		
		GetCatalogItemsResult(const GetCatalogItemsResult& src) :
			PlayFabBaseModel(),
			Catalog(src.Catalog)
			{}
			
		GetCatalogItemsResult(const rapidjson::Value& obj) : GetCatalogItemsResult()
        {
            readFromValue(obj);
        }
		
		~GetCatalogItemsResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardAroundUserRequest : public PlayFabBaseModel
    {
		
		std::string StatisticName;
		std::string PlayFabId;
		OptionalInt32 MaxResultsCount;
	
        GetLeaderboardAroundUserRequest() :
			PlayFabBaseModel(),
			StatisticName(),
			PlayFabId(),
			MaxResultsCount()
			{}
		
		GetLeaderboardAroundUserRequest(const GetLeaderboardAroundUserRequest& src) :
			PlayFabBaseModel(),
			StatisticName(src.StatisticName),
			PlayFabId(src.PlayFabId),
			MaxResultsCount(src.MaxResultsCount)
			{}
			
		GetLeaderboardAroundUserRequest(const rapidjson::Value& obj) : GetLeaderboardAroundUserRequest()
        {
            readFromValue(obj);
        }
		
		~GetLeaderboardAroundUserRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct PlayerLeaderboardEntry : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string DisplayName;
		Int32 StatValue;
		Int32 Position;
	
        PlayerLeaderboardEntry() :
			PlayFabBaseModel(),
			PlayFabId(),
			DisplayName(),
			StatValue(0),
			Position(0)
			{}
		
		PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			DisplayName(src.DisplayName),
			StatValue(src.StatValue),
			Position(src.Position)
			{}
			
		PlayerLeaderboardEntry(const rapidjson::Value& obj) : PlayerLeaderboardEntry()
        {
            readFromValue(obj);
        }
		
		~PlayerLeaderboardEntry();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardAroundUserResult : public PlayFabBaseModel
    {
		
		std::list<PlayerLeaderboardEntry> Leaderboard;
	
        GetLeaderboardAroundUserResult() :
			PlayFabBaseModel(),
			Leaderboard()
			{}
		
		GetLeaderboardAroundUserResult(const GetLeaderboardAroundUserResult& src) :
			PlayFabBaseModel(),
			Leaderboard(src.Leaderboard)
			{}
			
		GetLeaderboardAroundUserResult(const rapidjson::Value& obj) : GetLeaderboardAroundUserResult()
        {
            readFromValue(obj);
        }
		
		~GetLeaderboardAroundUserResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardRequest : public PlayFabBaseModel
    {
		
		std::string StatisticName;
		Int32 StartPosition;
		OptionalInt32 MaxResultsCount;
	
        GetLeaderboardRequest() :
			PlayFabBaseModel(),
			StatisticName(),
			StartPosition(0),
			MaxResultsCount()
			{}
		
		GetLeaderboardRequest(const GetLeaderboardRequest& src) :
			PlayFabBaseModel(),
			StatisticName(src.StatisticName),
			StartPosition(src.StartPosition),
			MaxResultsCount(src.MaxResultsCount)
			{}
			
		GetLeaderboardRequest(const rapidjson::Value& obj) : GetLeaderboardRequest()
        {
            readFromValue(obj);
        }
		
		~GetLeaderboardRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardResult : public PlayFabBaseModel
    {
		
		std::list<PlayerLeaderboardEntry> Leaderboard;
	
        GetLeaderboardResult() :
			PlayFabBaseModel(),
			Leaderboard()
			{}
		
		GetLeaderboardResult(const GetLeaderboardResult& src) :
			PlayFabBaseModel(),
			Leaderboard(src.Leaderboard)
			{}
			
		GetLeaderboardResult(const rapidjson::Value& obj) : GetLeaderboardResult()
        {
            readFromValue(obj);
        }
		
		~GetLeaderboardResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetTitleDataRequest : public PlayFabBaseModel
    {
		
		std::list<std::string> Keys;
	
        GetTitleDataRequest() :
			PlayFabBaseModel(),
			Keys()
			{}
		
		GetTitleDataRequest(const GetTitleDataRequest& src) :
			PlayFabBaseModel(),
			Keys(src.Keys)
			{}
			
		GetTitleDataRequest(const rapidjson::Value& obj) : GetTitleDataRequest()
        {
            readFromValue(obj);
        }
		
		~GetTitleDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetTitleDataResult : public PlayFabBaseModel
    {
		
		std::map<std::string, std::string> Data;
	
        GetTitleDataResult() :
			PlayFabBaseModel(),
			Data()
			{}
		
		GetTitleDataResult(const GetTitleDataResult& src) :
			PlayFabBaseModel(),
			Data(src.Data)
			{}
			
		GetTitleDataResult(const rapidjson::Value& obj) : GetTitleDataResult()
        {
            readFromValue(obj);
        }
		
		~GetTitleDataResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetUserAccountInfoRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
	
        GetUserAccountInfoRequest() :
			PlayFabBaseModel(),
			PlayFabId()
			{}
		
		GetUserAccountInfoRequest(const GetUserAccountInfoRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId)
			{}
			
		GetUserAccountInfoRequest(const rapidjson::Value& obj) : GetUserAccountInfoRequest()
        {
            readFromValue(obj);
        }
		
		~GetUserAccountInfoRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	enum UserOrigination
	{
		UserOriginationOrganic,
		UserOriginationSteam,
		UserOriginationGoogle,
		UserOriginationAmazon,
		UserOriginationFacebook,
		UserOriginationKongregate,
		UserOriginationGamersFirst,
		UserOriginationUnknown,
		UserOriginationIOS,
		UserOriginationLoadTest,
		UserOriginationAndroid
	};
	
	void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer);
	UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj);
	
	
	struct UserTitleInfo : public PlayFabBaseModel
    {
		
		std::string DisplayName;
		Boxed<UserOrigination> Origination;
		time_t Created;
		OptionalTime LastLogin;
		OptionalTime FirstLogin;
	
        UserTitleInfo() :
			PlayFabBaseModel(),
			DisplayName(),
			Origination(),
			Created(0),
			LastLogin(),
			FirstLogin()
			{}
		
		UserTitleInfo(const UserTitleInfo& src) :
			PlayFabBaseModel(),
			DisplayName(src.DisplayName),
			Origination(src.Origination),
			Created(src.Created),
			LastLogin(src.LastLogin),
			FirstLogin(src.FirstLogin)
			{}
			
		UserTitleInfo(const rapidjson::Value& obj) : UserTitleInfo()
        {
            readFromValue(obj);
        }
		
		~UserTitleInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UserPrivateAccountInfo : public PlayFabBaseModel
    {
		
		std::string Email;
	
        UserPrivateAccountInfo() :
			PlayFabBaseModel(),
			Email()
			{}
		
		UserPrivateAccountInfo(const UserPrivateAccountInfo& src) :
			PlayFabBaseModel(),
			Email(src.Email)
			{}
			
		UserPrivateAccountInfo(const rapidjson::Value& obj) : UserPrivateAccountInfo()
        {
            readFromValue(obj);
        }
		
		~UserPrivateAccountInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UserFacebookInfo : public PlayFabBaseModel
    {
		
		std::string FacebookId;
		std::string FacebookUsername;
		std::string FacebookDisplayname;
	
        UserFacebookInfo() :
			PlayFabBaseModel(),
			FacebookId(),
			FacebookUsername(),
			FacebookDisplayname()
			{}
		
		UserFacebookInfo(const UserFacebookInfo& src) :
			PlayFabBaseModel(),
			FacebookId(src.FacebookId),
			FacebookUsername(src.FacebookUsername),
			FacebookDisplayname(src.FacebookDisplayname)
			{}
			
		UserFacebookInfo(const rapidjson::Value& obj) : UserFacebookInfo()
        {
            readFromValue(obj);
        }
		
		~UserFacebookInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	enum TitleActivationStatus
	{
		TitleActivationStatusNone,
		TitleActivationStatusActivatedTitleKey,
		TitleActivationStatusPendingSteam,
		TitleActivationStatusActivatedSteam,
		TitleActivationStatusRevokedSteam
	};
	
	void writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer);
	TitleActivationStatus readTitleActivationStatusFromValue(const rapidjson::Value& obj);
	
	
	struct UserSteamInfo : public PlayFabBaseModel
    {
		
		std::string SteamId;
		std::string SteamCountry;
		Boxed<Currency> SteamCurrency;
		Boxed<TitleActivationStatus> SteamActivationStatus;
	
        UserSteamInfo() :
			PlayFabBaseModel(),
			SteamId(),
			SteamCountry(),
			SteamCurrency(),
			SteamActivationStatus()
			{}
		
		UserSteamInfo(const UserSteamInfo& src) :
			PlayFabBaseModel(),
			SteamId(src.SteamId),
			SteamCountry(src.SteamCountry),
			SteamCurrency(src.SteamCurrency),
			SteamActivationStatus(src.SteamActivationStatus)
			{}
			
		UserSteamInfo(const rapidjson::Value& obj) : UserSteamInfo()
        {
            readFromValue(obj);
        }
		
		~UserSteamInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UserGameCenterInfo : public PlayFabBaseModel
    {
		
		std::string GameCenterId;
	
        UserGameCenterInfo() :
			PlayFabBaseModel(),
			GameCenterId()
			{}
		
		UserGameCenterInfo(const UserGameCenterInfo& src) :
			PlayFabBaseModel(),
			GameCenterId(src.GameCenterId)
			{}
			
		UserGameCenterInfo(const rapidjson::Value& obj) : UserGameCenterInfo()
        {
            readFromValue(obj);
        }
		
		~UserGameCenterInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UserAccountInfo : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		time_t Created;
		std::string Username;
		UserTitleInfo* TitleInfo;
		UserPrivateAccountInfo* PrivateInfo;
		UserFacebookInfo* FacebookInfo;
		UserSteamInfo* SteamInfo;
		UserGameCenterInfo* GameCenterInfo;
	
        UserAccountInfo() :
			PlayFabBaseModel(),
			PlayFabId(),
			Created(0),
			Username(),
			TitleInfo(NULL),
			PrivateInfo(NULL),
			FacebookInfo(NULL),
			SteamInfo(NULL),
			GameCenterInfo(NULL)
			{}
		
		UserAccountInfo(const UserAccountInfo& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			Created(src.Created),
			Username(src.Username),
			TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : NULL),
			PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : NULL),
			FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : NULL),
			SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : NULL),
			GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL)
			{}
			
		UserAccountInfo(const rapidjson::Value& obj) : UserAccountInfo()
        {
            readFromValue(obj);
        }
		
		~UserAccountInfo();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetUserAccountInfoResult : public PlayFabBaseModel
    {
		
		UserAccountInfo* UserInfo;
	
        GetUserAccountInfoResult() :
			PlayFabBaseModel(),
			UserInfo(NULL)
			{}
		
		GetUserAccountInfoResult(const GetUserAccountInfoResult& src) :
			PlayFabBaseModel(),
			UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : NULL)
			{}
			
		GetUserAccountInfoResult(const rapidjson::Value& obj) : GetUserAccountInfoResult()
        {
            readFromValue(obj);
        }
		
		~GetUserAccountInfoResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetUserDataRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::list<std::string> Keys;
	
        GetUserDataRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			Keys()
			{}
		
		GetUserDataRequest(const GetUserDataRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			Keys(src.Keys)
			{}
			
		GetUserDataRequest(const rapidjson::Value& obj) : GetUserDataRequest()
        {
            readFromValue(obj);
        }
		
		~GetUserDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	enum UserDataPermission
	{
		UserDataPermissionPrivate,
		UserDataPermissionPublic
	};
	
	void writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer);
	UserDataPermission readUserDataPermissionFromValue(const rapidjson::Value& obj);
	
	
	struct UserDataRecord : public PlayFabBaseModel
    {
		
		std::string Value;
		time_t LastUpdated;
		Boxed<UserDataPermission> Permission;
	
        UserDataRecord() :
			PlayFabBaseModel(),
			Value(),
			LastUpdated(0),
			Permission()
			{}
		
		UserDataRecord(const UserDataRecord& src) :
			PlayFabBaseModel(),
			Value(src.Value),
			LastUpdated(src.LastUpdated),
			Permission(src.Permission)
			{}
			
		UserDataRecord(const rapidjson::Value& obj) : UserDataRecord()
        {
            readFromValue(obj);
        }
		
		~UserDataRecord();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetUserDataResult : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::map<std::string, UserDataRecord> Data;
	
        GetUserDataResult() :
			PlayFabBaseModel(),
			PlayFabId(),
			Data()
			{}
		
		GetUserDataResult(const GetUserDataResult& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			Data(src.Data)
			{}
			
		GetUserDataResult(const rapidjson::Value& obj) : GetUserDataResult()
        {
            readFromValue(obj);
        }
		
		~GetUserDataResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetUserInventoryRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CatalogVersion;
	
        GetUserInventoryRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CatalogVersion()
			{}
		
		GetUserInventoryRequest(const GetUserInventoryRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CatalogVersion(src.CatalogVersion)
			{}
			
		GetUserInventoryRequest(const rapidjson::Value& obj) : GetUserInventoryRequest()
        {
            readFromValue(obj);
        }
		
		~GetUserInventoryRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ItemInstance : public PlayFabBaseModel
    {
		
		std::string ItemId;
		std::string ItemInstanceId;
		std::string ItemClass;
		OptionalTime PurchaseDate;
		OptionalTime Expiration;
		OptionalUint32 RemainingUses;
		std::string Annotation;
		std::string CatalogVersion;
		std::string BundleParent;
	
        ItemInstance() :
			PlayFabBaseModel(),
			ItemId(),
			ItemInstanceId(),
			ItemClass(),
			PurchaseDate(),
			Expiration(),
			RemainingUses(),
			Annotation(),
			CatalogVersion(),
			BundleParent()
			{}
		
		ItemInstance(const ItemInstance& src) :
			PlayFabBaseModel(),
			ItemId(src.ItemId),
			ItemInstanceId(src.ItemInstanceId),
			ItemClass(src.ItemClass),
			PurchaseDate(src.PurchaseDate),
			Expiration(src.Expiration),
			RemainingUses(src.RemainingUses),
			Annotation(src.Annotation),
			CatalogVersion(src.CatalogVersion),
			BundleParent(src.BundleParent)
			{}
			
		ItemInstance(const rapidjson::Value& obj) : ItemInstance()
        {
            readFromValue(obj);
        }
		
		~ItemInstance();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetUserInventoryResult : public PlayFabBaseModel
    {
		
		std::list<ItemInstance> Inventory;
		std::map<std::string, Int32> VirtualCurrency;
	
        GetUserInventoryResult() :
			PlayFabBaseModel(),
			Inventory(),
			VirtualCurrency()
			{}
		
		GetUserInventoryResult(const GetUserInventoryResult& src) :
			PlayFabBaseModel(),
			Inventory(src.Inventory),
			VirtualCurrency(src.VirtualCurrency)
			{}
			
		GetUserInventoryResult(const rapidjson::Value& obj) : GetUserInventoryResult()
        {
            readFromValue(obj);
        }
		
		~GetUserInventoryResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetUserStatisticsRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
	
        GetUserStatisticsRequest() :
			PlayFabBaseModel(),
			PlayFabId()
			{}
		
		GetUserStatisticsRequest(const GetUserStatisticsRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId)
			{}
			
		GetUserStatisticsRequest(const rapidjson::Value& obj) : GetUserStatisticsRequest()
        {
            readFromValue(obj);
        }
		
		~GetUserStatisticsRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetUserStatisticsResult : public PlayFabBaseModel
    {
		
		std::map<std::string, Int32> UserStatistics;
	
        GetUserStatisticsResult() :
			PlayFabBaseModel(),
			UserStatistics()
			{}
		
		GetUserStatisticsResult(const GetUserStatisticsResult& src) :
			PlayFabBaseModel(),
			UserStatistics(src.UserStatistics)
			{}
			
		GetUserStatisticsResult(const rapidjson::Value& obj) : GetUserStatisticsResult()
        {
            readFromValue(obj);
        }
		
		~GetUserStatisticsResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ItemGrant : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string ItemId;
		std::string Annotation;
	
        ItemGrant() :
			PlayFabBaseModel(),
			PlayFabId(),
			ItemId(),
			Annotation()
			{}
		
		ItemGrant(const ItemGrant& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			ItemId(src.ItemId),
			Annotation(src.Annotation)
			{}
			
		ItemGrant(const rapidjson::Value& obj) : ItemGrant()
        {
            readFromValue(obj);
        }
		
		~ItemGrant();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GrantItemsToUsersRequest : public PlayFabBaseModel
    {
		
		std::string CatalogVersion;
		std::list<ItemGrant> ItemGrants;
	
        GrantItemsToUsersRequest() :
			PlayFabBaseModel(),
			CatalogVersion(),
			ItemGrants()
			{}
		
		GrantItemsToUsersRequest(const GrantItemsToUsersRequest& src) :
			PlayFabBaseModel(),
			CatalogVersion(src.CatalogVersion),
			ItemGrants(src.ItemGrants)
			{}
			
		GrantItemsToUsersRequest(const rapidjson::Value& obj) : GrantItemsToUsersRequest()
        {
            readFromValue(obj);
        }
		
		~GrantItemsToUsersRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ItemGrantResult : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string ItemId;
		std::string ItemInstanceId;
		std::string Annotation;
		bool Result;
	
        ItemGrantResult() :
			PlayFabBaseModel(),
			PlayFabId(),
			ItemId(),
			ItemInstanceId(),
			Annotation(),
			Result(false)
			{}
		
		ItemGrantResult(const ItemGrantResult& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			ItemId(src.ItemId),
			ItemInstanceId(src.ItemInstanceId),
			Annotation(src.Annotation),
			Result(src.Result)
			{}
			
		ItemGrantResult(const rapidjson::Value& obj) : ItemGrantResult()
        {
            readFromValue(obj);
        }
		
		~ItemGrantResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GrantItemsToUsersResult : public PlayFabBaseModel
    {
		
		std::list<ItemGrantResult> ItemGrantResults;
	
        GrantItemsToUsersResult() :
			PlayFabBaseModel(),
			ItemGrantResults()
			{}
		
		GrantItemsToUsersResult(const GrantItemsToUsersResult& src) :
			PlayFabBaseModel(),
			ItemGrantResults(src.ItemGrantResults)
			{}
			
		GrantItemsToUsersResult(const rapidjson::Value& obj) : GrantItemsToUsersResult()
        {
            readFromValue(obj);
        }
		
		~GrantItemsToUsersResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ModifyUserVirtualCurrencyResult : public PlayFabBaseModel
    {
		
		std::string VirtualCurrency;
		Int32 Balance;
	
        ModifyUserVirtualCurrencyResult() :
			PlayFabBaseModel(),
			VirtualCurrency(),
			Balance(0)
			{}
		
		ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
			PlayFabBaseModel(),
			VirtualCurrency(src.VirtualCurrency),
			Balance(src.Balance)
			{}
			
		ModifyUserVirtualCurrencyResult(const rapidjson::Value& obj) : ModifyUserVirtualCurrencyResult()
        {
            readFromValue(obj);
        }
		
		~ModifyUserVirtualCurrencyResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct NotifyMatchmakerPlayerLeftRequest : public PlayFabBaseModel
    {
		
		std::string ServerId;
		std::string PlayFabId;
	
        NotifyMatchmakerPlayerLeftRequest() :
			PlayFabBaseModel(),
			ServerId(),
			PlayFabId()
			{}
		
		NotifyMatchmakerPlayerLeftRequest(const NotifyMatchmakerPlayerLeftRequest& src) :
			PlayFabBaseModel(),
			ServerId(src.ServerId),
			PlayFabId(src.PlayFabId)
			{}
			
		NotifyMatchmakerPlayerLeftRequest(const rapidjson::Value& obj) : NotifyMatchmakerPlayerLeftRequest()
        {
            readFromValue(obj);
        }
		
		~NotifyMatchmakerPlayerLeftRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	enum PlayerConnectionState
	{
		PlayerConnectionStateUnassigned,
		PlayerConnectionStateConnecting,
		PlayerConnectionStateParticipating,
		PlayerConnectionStateParticipated,
		PlayerConnectionStateReconnecting
	};
	
	void writePlayerConnectionStateEnumJSON(PlayerConnectionState enumVal, PFStringJsonWriter& writer);
	PlayerConnectionState readPlayerConnectionStateFromValue(const rapidjson::Value& obj);
	
	
	struct NotifyMatchmakerPlayerLeftResult : public PlayFabBaseModel
    {
		
		Boxed<PlayerConnectionState> PlayerState;
	
        NotifyMatchmakerPlayerLeftResult() :
			PlayFabBaseModel(),
			PlayerState()
			{}
		
		NotifyMatchmakerPlayerLeftResult(const NotifyMatchmakerPlayerLeftResult& src) :
			PlayFabBaseModel(),
			PlayerState(src.PlayerState)
			{}
			
		NotifyMatchmakerPlayerLeftResult(const rapidjson::Value& obj) : NotifyMatchmakerPlayerLeftResult()
        {
            readFromValue(obj);
        }
		
		~NotifyMatchmakerPlayerLeftResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct RedeemMatchmakerTicketRequest : public PlayFabBaseModel
    {
		
		std::string Ticket;
		std::string IP;
		std::string ServerId;
	
        RedeemMatchmakerTicketRequest() :
			PlayFabBaseModel(),
			Ticket(),
			IP(),
			ServerId()
			{}
		
		RedeemMatchmakerTicketRequest(const RedeemMatchmakerTicketRequest& src) :
			PlayFabBaseModel(),
			Ticket(src.Ticket),
			IP(src.IP),
			ServerId(src.ServerId)
			{}
			
		RedeemMatchmakerTicketRequest(const rapidjson::Value& obj) : RedeemMatchmakerTicketRequest()
        {
            readFromValue(obj);
        }
		
		~RedeemMatchmakerTicketRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct RedeemMatchmakerTicketResult : public PlayFabBaseModel
    {
		
		bool TicketIsValid;
		std::string Error;
		UserAccountInfo* UserInfo;
	
        RedeemMatchmakerTicketResult() :
			PlayFabBaseModel(),
			TicketIsValid(false),
			Error(),
			UserInfo(NULL)
			{}
		
		RedeemMatchmakerTicketResult(const RedeemMatchmakerTicketResult& src) :
			PlayFabBaseModel(),
			TicketIsValid(src.TicketIsValid),
			Error(src.Error),
			UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : NULL)
			{}
			
		RedeemMatchmakerTicketResult(const rapidjson::Value& obj) : RedeemMatchmakerTicketResult()
        {
            readFromValue(obj);
        }
		
		~RedeemMatchmakerTicketResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct SetTitleDataRequest : public PlayFabBaseModel
    {
		
		std::string Key;
		std::string Value;
	
        SetTitleDataRequest() :
			PlayFabBaseModel(),
			Key(),
			Value()
			{}
		
		SetTitleDataRequest(const SetTitleDataRequest& src) :
			PlayFabBaseModel(),
			Key(src.Key),
			Value(src.Value)
			{}
			
		SetTitleDataRequest(const rapidjson::Value& obj) : SetTitleDataRequest()
        {
            readFromValue(obj);
        }
		
		~SetTitleDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct SetTitleDataResult : public PlayFabBaseModel
    {
		
	
        SetTitleDataResult() :
			PlayFabBaseModel()
			{}
		
		SetTitleDataResult(const SetTitleDataResult& src) :
			PlayFabBaseModel()
			{}
			
		SetTitleDataResult(const rapidjson::Value& obj) : SetTitleDataResult()
        {
            readFromValue(obj);
        }
		
		~SetTitleDataResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string VirtualCurrency;
		Int32 Amount;
	
        SubtractUserVirtualCurrencyRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			VirtualCurrency(),
			Amount(0)
			{}
		
		SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			VirtualCurrency(src.VirtualCurrency),
			Amount(src.Amount)
			{}
			
		SubtractUserVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractUserVirtualCurrencyRequest()
        {
            readFromValue(obj);
        }
		
		~SubtractUserVirtualCurrencyRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateUserDataRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::map<std::string, std::string> Data;
		Boxed<UserDataPermission> Permission;
	
        UpdateUserDataRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			Data(),
			Permission()
			{}
		
		UpdateUserDataRequest(const UpdateUserDataRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			Data(src.Data),
			Permission(src.Permission)
			{}
			
		UpdateUserDataRequest(const rapidjson::Value& obj) : UpdateUserDataRequest()
        {
            readFromValue(obj);
        }
		
		~UpdateUserDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateUserDataResult : public PlayFabBaseModel
    {
		
	
        UpdateUserDataResult() :
			PlayFabBaseModel()
			{}
		
		UpdateUserDataResult(const UpdateUserDataResult& src) :
			PlayFabBaseModel()
			{}
			
		UpdateUserDataResult(const rapidjson::Value& obj) : UpdateUserDataResult()
        {
            readFromValue(obj);
        }
		
		~UpdateUserDataResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateUserInternalDataRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::map<std::string, std::string> Data;
	
        UpdateUserInternalDataRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			Data()
			{}
		
		UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			Data(src.Data)
			{}
			
		UpdateUserInternalDataRequest(const rapidjson::Value& obj) : UpdateUserInternalDataRequest()
        {
            readFromValue(obj);
        }
		
		~UpdateUserInternalDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateUserStatisticsRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::map<std::string, Int32> UserStatistics;
	
        UpdateUserStatisticsRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			UserStatistics()
			{}
		
		UpdateUserStatisticsRequest(const UpdateUserStatisticsRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			UserStatistics(src.UserStatistics)
			{}
			
		UpdateUserStatisticsRequest(const rapidjson::Value& obj) : UpdateUserStatisticsRequest()
        {
            readFromValue(obj);
        }
		
		~UpdateUserStatisticsRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateUserStatisticsResult : public PlayFabBaseModel
    {
		
	
        UpdateUserStatisticsResult() :
			PlayFabBaseModel()
			{}
		
		UpdateUserStatisticsResult(const UpdateUserStatisticsResult& src) :
			PlayFabBaseModel()
			{}
			
		UpdateUserStatisticsResult(const rapidjson::Value& obj) : UpdateUserStatisticsResult()
        {
            readFromValue(obj);
        }
		
		~UpdateUserStatisticsResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	

}
}

#endif