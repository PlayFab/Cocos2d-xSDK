#ifndef PLAYFAB_SERVER_DATA_MODELS_H_
#define PLAYFAB_SERVER_DATA_MODELS_H_

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
namespace ServerModels
{

	
	struct AddSharedGroupMembersRequest : public PlayFabBaseModel
    {
		
		std::string SharedGroupId;
		std::list<std::string> PlayFabIds;
	
        AddSharedGroupMembersRequest() :
			PlayFabBaseModel(),
			SharedGroupId(),
			PlayFabIds()
			{}
		
		AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
			PlayFabBaseModel(),
			SharedGroupId(src.SharedGroupId),
			PlayFabIds(src.PlayFabIds)
			{}
			
		AddSharedGroupMembersRequest(const rapidjson::Value& obj) : AddSharedGroupMembersRequest()
        {
            readFromValue(obj);
        }
		
		~AddSharedGroupMembersRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct AddSharedGroupMembersResult : public PlayFabBaseModel
    {
		
	
        AddSharedGroupMembersResult() :
			PlayFabBaseModel()
			{}
		
		AddSharedGroupMembersResult(const AddSharedGroupMembersResult& src) :
			PlayFabBaseModel()
			{}
			
		AddSharedGroupMembersResult(const rapidjson::Value& obj) : AddSharedGroupMembersResult()
        {
            readFromValue(obj);
        }
		
		~AddSharedGroupMembersResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
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
	
	struct AuthenticateSessionTicketRequest : public PlayFabBaseModel
    {
		
		std::string SessionTicket;
	
        AuthenticateSessionTicketRequest() :
			PlayFabBaseModel(),
			SessionTicket()
			{}
		
		AuthenticateSessionTicketRequest(const AuthenticateSessionTicketRequest& src) :
			PlayFabBaseModel(),
			SessionTicket(src.SessionTicket)
			{}
			
		AuthenticateSessionTicketRequest(const rapidjson::Value& obj) : AuthenticateSessionTicketRequest()
        {
            readFromValue(obj);
        }
		
		~AuthenticateSessionTicketRequest();
		
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
		UserOriginationAndroid,
		UserOriginationPSN,
		UserOriginationGameCenter
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
		OptionalBool isBanned;
	
        UserTitleInfo() :
			PlayFabBaseModel(),
			DisplayName(),
			Origination(),
			Created(0),
			LastLogin(),
			FirstLogin(),
			isBanned()
			{}
		
		UserTitleInfo(const UserTitleInfo& src) :
			PlayFabBaseModel(),
			DisplayName(src.DisplayName),
			Origination(src.Origination),
			Created(src.Created),
			LastLogin(src.LastLogin),
			FirstLogin(src.FirstLogin),
			isBanned(src.isBanned)
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
	
        UserFacebookInfo() :
			PlayFabBaseModel(),
			FacebookId()
			{}
		
		UserFacebookInfo(const UserFacebookInfo& src) :
			PlayFabBaseModel(),
			FacebookId(src.FacebookId)
			{}
			
		UserFacebookInfo(const rapidjson::Value& obj) : UserFacebookInfo()
        {
            readFromValue(obj);
        }
		
		~UserFacebookInfo();
		
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
	
	struct AuthenticateSessionTicketResult : public PlayFabBaseModel
    {
		
		UserAccountInfo* UserInfo;
	
        AuthenticateSessionTicketResult() :
			PlayFabBaseModel(),
			UserInfo(NULL)
			{}
		
		AuthenticateSessionTicketResult(const AuthenticateSessionTicketResult& src) :
			PlayFabBaseModel(),
			UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : NULL)
			{}
			
		AuthenticateSessionTicketResult(const rapidjson::Value& obj) : AuthenticateSessionTicketResult()
        {
            readFromValue(obj);
        }
		
		~AuthenticateSessionTicketResult();
		
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
	
	struct CharacterLeaderboardEntry : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterId;
		std::string CharacterName;
		std::string DisplayName;
		std::string CharacterType;
		Int32 StatValue;
		Int32 Position;
	
        CharacterLeaderboardEntry() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterId(),
			CharacterName(),
			DisplayName(),
			CharacterType(),
			StatValue(0),
			Position(0)
			{}
		
		CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId),
			CharacterName(src.CharacterName),
			DisplayName(src.DisplayName),
			CharacterType(src.CharacterType),
			StatValue(src.StatValue),
			Position(src.Position)
			{}
			
		CharacterLeaderboardEntry(const rapidjson::Value& obj) : CharacterLeaderboardEntry()
        {
            readFromValue(obj);
        }
		
		~CharacterLeaderboardEntry();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct CharacterResult : public PlayFabBaseModel
    {
		
		std::string CharacterId;
		std::string CharacterName;
		std::string CharacterType;
	
        CharacterResult() :
			PlayFabBaseModel(),
			CharacterId(),
			CharacterName(),
			CharacterType()
			{}
		
		CharacterResult(const CharacterResult& src) :
			PlayFabBaseModel(),
			CharacterId(src.CharacterId),
			CharacterName(src.CharacterName),
			CharacterType(src.CharacterType)
			{}
			
		CharacterResult(const rapidjson::Value& obj) : CharacterResult()
        {
            readFromValue(obj);
        }
		
		~CharacterResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct CreateSharedGroupRequest : public PlayFabBaseModel
    {
		
		std::string SharedGroupId;
	
        CreateSharedGroupRequest() :
			PlayFabBaseModel(),
			SharedGroupId()
			{}
		
		CreateSharedGroupRequest(const CreateSharedGroupRequest& src) :
			PlayFabBaseModel(),
			SharedGroupId(src.SharedGroupId)
			{}
			
		CreateSharedGroupRequest(const rapidjson::Value& obj) : CreateSharedGroupRequest()
        {
            readFromValue(obj);
        }
		
		~CreateSharedGroupRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct CreateSharedGroupResult : public PlayFabBaseModel
    {
		
		std::string SharedGroupId;
	
        CreateSharedGroupResult() :
			PlayFabBaseModel(),
			SharedGroupId()
			{}
		
		CreateSharedGroupResult(const CreateSharedGroupResult& src) :
			PlayFabBaseModel(),
			SharedGroupId(src.SharedGroupId)
			{}
			
		CreateSharedGroupResult(const rapidjson::Value& obj) : CreateSharedGroupResult()
        {
            readFromValue(obj);
        }
		
		~CreateSharedGroupResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct DeleteCharacterFromUserRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterId;
		bool SaveCharacterInventory;
	
        DeleteCharacterFromUserRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterId(),
			SaveCharacterInventory(false)
			{}
		
		DeleteCharacterFromUserRequest(const DeleteCharacterFromUserRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId),
			SaveCharacterInventory(src.SaveCharacterInventory)
			{}
			
		DeleteCharacterFromUserRequest(const rapidjson::Value& obj) : DeleteCharacterFromUserRequest()
        {
            readFromValue(obj);
        }
		
		~DeleteCharacterFromUserRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct DeleteCharacterFromUserResult : public PlayFabBaseModel
    {
		
	
        DeleteCharacterFromUserResult() :
			PlayFabBaseModel()
			{}
		
		DeleteCharacterFromUserResult(const DeleteCharacterFromUserResult& src) :
			PlayFabBaseModel()
			{}
			
		DeleteCharacterFromUserResult(const rapidjson::Value& obj) : DeleteCharacterFromUserResult()
        {
            readFromValue(obj);
        }
		
		~DeleteCharacterFromUserResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct DeleteSharedGroupRequest : public PlayFabBaseModel
    {
		
		std::string SharedGroupId;
	
        DeleteSharedGroupRequest() :
			PlayFabBaseModel(),
			SharedGroupId()
			{}
		
		DeleteSharedGroupRequest(const DeleteSharedGroupRequest& src) :
			PlayFabBaseModel(),
			SharedGroupId(src.SharedGroupId)
			{}
			
		DeleteSharedGroupRequest(const rapidjson::Value& obj) : DeleteSharedGroupRequest()
        {
            readFromValue(obj);
        }
		
		~DeleteSharedGroupRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct EmptyResult : public PlayFabBaseModel
    {
		
	
        EmptyResult() :
			PlayFabBaseModel()
			{}
		
		EmptyResult(const EmptyResult& src) :
			PlayFabBaseModel()
			{}
			
		EmptyResult(const rapidjson::Value& obj) : EmptyResult()
        {
            readFromValue(obj);
        }
		
		~EmptyResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
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
	
	struct GetCharacterDataRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterId;
		std::list<std::string> Keys;
	
        GetCharacterDataRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterId(),
			Keys()
			{}
		
		GetCharacterDataRequest(const GetCharacterDataRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId),
			Keys(src.Keys)
			{}
			
		GetCharacterDataRequest(const rapidjson::Value& obj) : GetCharacterDataRequest()
        {
            readFromValue(obj);
        }
		
		~GetCharacterDataRequest();
		
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
	
	struct GetCharacterDataResult : public PlayFabBaseModel
    {
		
		std::string CharacterId;
		std::map<std::string, UserDataRecord> Data;
	
        GetCharacterDataResult() :
			PlayFabBaseModel(),
			CharacterId(),
			Data()
			{}
		
		GetCharacterDataResult(const GetCharacterDataResult& src) :
			PlayFabBaseModel(),
			CharacterId(src.CharacterId),
			Data(src.Data)
			{}
			
		GetCharacterDataResult(const rapidjson::Value& obj) : GetCharacterDataResult()
        {
            readFromValue(obj);
        }
		
		~GetCharacterDataResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetCharacterLeaderboardRequest : public PlayFabBaseModel
    {
		
		std::string CharacterId;
		std::string CharacterType;
		std::string StatisticName;
		Int32 StartPosition;
		Int32 MaxResultsCount;
	
        GetCharacterLeaderboardRequest() :
			PlayFabBaseModel(),
			CharacterId(),
			CharacterType(),
			StatisticName(),
			StartPosition(0),
			MaxResultsCount(0)
			{}
		
		GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
			PlayFabBaseModel(),
			CharacterId(src.CharacterId),
			CharacterType(src.CharacterType),
			StatisticName(src.StatisticName),
			StartPosition(src.StartPosition),
			MaxResultsCount(src.MaxResultsCount)
			{}
			
		GetCharacterLeaderboardRequest(const rapidjson::Value& obj) : GetCharacterLeaderboardRequest()
        {
            readFromValue(obj);
        }
		
		~GetCharacterLeaderboardRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetCharacterLeaderboardResult : public PlayFabBaseModel
    {
		
		std::list<CharacterLeaderboardEntry> Leaderboard;
	
        GetCharacterLeaderboardResult() :
			PlayFabBaseModel(),
			Leaderboard()
			{}
		
		GetCharacterLeaderboardResult(const GetCharacterLeaderboardResult& src) :
			PlayFabBaseModel(),
			Leaderboard(src.Leaderboard)
			{}
			
		GetCharacterLeaderboardResult(const rapidjson::Value& obj) : GetCharacterLeaderboardResult()
        {
            readFromValue(obj);
        }
		
		~GetCharacterLeaderboardResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetCharacterStatisticsRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterId;
	
        GetCharacterStatisticsRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterId()
			{}
		
		GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId)
			{}
			
		GetCharacterStatisticsRequest(const rapidjson::Value& obj) : GetCharacterStatisticsRequest()
        {
            readFromValue(obj);
        }
		
		~GetCharacterStatisticsRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetCharacterStatisticsResult : public PlayFabBaseModel
    {
		
		std::map<std::string, Int32> CharacterStatistics;
	
        GetCharacterStatisticsResult() :
			PlayFabBaseModel(),
			CharacterStatistics()
			{}
		
		GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
			PlayFabBaseModel(),
			CharacterStatistics(src.CharacterStatistics)
			{}
			
		GetCharacterStatisticsResult(const rapidjson::Value& obj) : GetCharacterStatisticsResult()
        {
            readFromValue(obj);
        }
		
		~GetCharacterStatisticsResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetContentDownloadUrlRequest : public PlayFabBaseModel
    {
		
		std::string Key;
		std::string HttpMethod;
		OptionalBool ThruCDN;
	
        GetContentDownloadUrlRequest() :
			PlayFabBaseModel(),
			Key(),
			HttpMethod(),
			ThruCDN()
			{}
		
		GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
			PlayFabBaseModel(),
			Key(src.Key),
			HttpMethod(src.HttpMethod),
			ThruCDN(src.ThruCDN)
			{}
			
		GetContentDownloadUrlRequest(const rapidjson::Value& obj) : GetContentDownloadUrlRequest()
        {
            readFromValue(obj);
        }
		
		~GetContentDownloadUrlRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetContentDownloadUrlResult : public PlayFabBaseModel
    {
		
		std::string URL;
	
        GetContentDownloadUrlResult() :
			PlayFabBaseModel(),
			URL()
			{}
		
		GetContentDownloadUrlResult(const GetContentDownloadUrlResult& src) :
			PlayFabBaseModel(),
			URL(src.URL)
			{}
			
		GetContentDownloadUrlResult(const rapidjson::Value& obj) : GetContentDownloadUrlResult()
        {
            readFromValue(obj);
        }
		
		~GetContentDownloadUrlResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardAroundCharacterRequest : public PlayFabBaseModel
    {
		
		std::string StatisticName;
		std::string PlayFabId;
		std::string CharacterId;
		std::string CharacterType;
		Int32 MaxResultsCount;
	
        GetLeaderboardAroundCharacterRequest() :
			PlayFabBaseModel(),
			StatisticName(),
			PlayFabId(),
			CharacterId(),
			CharacterType(),
			MaxResultsCount(0)
			{}
		
		GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
			PlayFabBaseModel(),
			StatisticName(src.StatisticName),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId),
			CharacterType(src.CharacterType),
			MaxResultsCount(src.MaxResultsCount)
			{}
			
		GetLeaderboardAroundCharacterRequest(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterRequest()
        {
            readFromValue(obj);
        }
		
		~GetLeaderboardAroundCharacterRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardAroundCharacterResult : public PlayFabBaseModel
    {
		
		std::list<CharacterLeaderboardEntry> Leaderboard;
	
        GetLeaderboardAroundCharacterResult() :
			PlayFabBaseModel(),
			Leaderboard()
			{}
		
		GetLeaderboardAroundCharacterResult(const GetLeaderboardAroundCharacterResult& src) :
			PlayFabBaseModel(),
			Leaderboard(src.Leaderboard)
			{}
			
		GetLeaderboardAroundCharacterResult(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterResult()
        {
            readFromValue(obj);
        }
		
		~GetLeaderboardAroundCharacterResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardAroundUserRequest : public PlayFabBaseModel
    {
		
		std::string StatisticName;
		std::string PlayFabId;
		Int32 MaxResultsCount;
	
        GetLeaderboardAroundUserRequest() :
			PlayFabBaseModel(),
			StatisticName(),
			PlayFabId(),
			MaxResultsCount(0)
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
	
	struct GetLeaderboardForUsersCharactersRequest : public PlayFabBaseModel
    {
		
		std::string StatisticName;
		std::string PlayFabId;
		Int32 MaxResultsCount;
	
        GetLeaderboardForUsersCharactersRequest() :
			PlayFabBaseModel(),
			StatisticName(),
			PlayFabId(),
			MaxResultsCount(0)
			{}
		
		GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
			PlayFabBaseModel(),
			StatisticName(src.StatisticName),
			PlayFabId(src.PlayFabId),
			MaxResultsCount(src.MaxResultsCount)
			{}
			
		GetLeaderboardForUsersCharactersRequest(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersRequest()
        {
            readFromValue(obj);
        }
		
		~GetLeaderboardForUsersCharactersRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardForUsersCharactersResult : public PlayFabBaseModel
    {
		
		std::list<CharacterLeaderboardEntry> Leaderboard;
	
        GetLeaderboardForUsersCharactersResult() :
			PlayFabBaseModel(),
			Leaderboard()
			{}
		
		GetLeaderboardForUsersCharactersResult(const GetLeaderboardForUsersCharactersResult& src) :
			PlayFabBaseModel(),
			Leaderboard(src.Leaderboard)
			{}
			
		GetLeaderboardForUsersCharactersResult(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersResult()
        {
            readFromValue(obj);
        }
		
		~GetLeaderboardForUsersCharactersResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetLeaderboardRequest : public PlayFabBaseModel
    {
		
		std::string StatisticName;
		Int32 StartPosition;
		Int32 MaxResultsCount;
	
        GetLeaderboardRequest() :
			PlayFabBaseModel(),
			StatisticName(),
			StartPosition(0),
			MaxResultsCount(0)
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
	
	struct GetPublisherDataRequest : public PlayFabBaseModel
    {
		
		std::list<std::string> Keys;
	
        GetPublisherDataRequest() :
			PlayFabBaseModel(),
			Keys()
			{}
		
		GetPublisherDataRequest(const GetPublisherDataRequest& src) :
			PlayFabBaseModel(),
			Keys(src.Keys)
			{}
			
		GetPublisherDataRequest(const rapidjson::Value& obj) : GetPublisherDataRequest()
        {
            readFromValue(obj);
        }
		
		~GetPublisherDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetPublisherDataResult : public PlayFabBaseModel
    {
		
		std::map<std::string, std::string> Data;
	
        GetPublisherDataResult() :
			PlayFabBaseModel(),
			Data()
			{}
		
		GetPublisherDataResult(const GetPublisherDataResult& src) :
			PlayFabBaseModel(),
			Data(src.Data)
			{}
			
		GetPublisherDataResult(const rapidjson::Value& obj) : GetPublisherDataResult()
        {
            readFromValue(obj);
        }
		
		~GetPublisherDataResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetSharedGroupDataRequest : public PlayFabBaseModel
    {
		
		std::string SharedGroupId;
		std::list<std::string> Keys;
		OptionalBool GetMembers;
	
        GetSharedGroupDataRequest() :
			PlayFabBaseModel(),
			SharedGroupId(),
			Keys(),
			GetMembers()
			{}
		
		GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
			PlayFabBaseModel(),
			SharedGroupId(src.SharedGroupId),
			Keys(src.Keys),
			GetMembers(src.GetMembers)
			{}
			
		GetSharedGroupDataRequest(const rapidjson::Value& obj) : GetSharedGroupDataRequest()
        {
            readFromValue(obj);
        }
		
		~GetSharedGroupDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct SharedGroupDataRecord : public PlayFabBaseModel
    {
		
		std::string Value;
		std::string LastUpdatedBy;
		time_t LastUpdated;
		Boxed<UserDataPermission> Permission;
	
        SharedGroupDataRecord() :
			PlayFabBaseModel(),
			Value(),
			LastUpdatedBy(),
			LastUpdated(0),
			Permission()
			{}
		
		SharedGroupDataRecord(const SharedGroupDataRecord& src) :
			PlayFabBaseModel(),
			Value(src.Value),
			LastUpdatedBy(src.LastUpdatedBy),
			LastUpdated(src.LastUpdated),
			Permission(src.Permission)
			{}
			
		SharedGroupDataRecord(const rapidjson::Value& obj) : SharedGroupDataRecord()
        {
            readFromValue(obj);
        }
		
		~SharedGroupDataRecord();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GetSharedGroupDataResult : public PlayFabBaseModel
    {
		
		std::map<std::string, SharedGroupDataRecord> Data;
		std::list<std::string> Members;
	
        GetSharedGroupDataResult() :
			PlayFabBaseModel(),
			Data(),
			Members()
			{}
		
		GetSharedGroupDataResult(const GetSharedGroupDataResult& src) :
			PlayFabBaseModel(),
			Data(src.Data),
			Members(src.Members)
			{}
			
		GetSharedGroupDataResult(const rapidjson::Value& obj) : GetSharedGroupDataResult()
        {
            readFromValue(obj);
        }
		
		~GetSharedGroupDataResult();
		
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
		OptionalInt32 RemainingUses;
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
	
	struct GrantCharacterToUserRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterName;
		std::string CharacterType;
	
        GrantCharacterToUserRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterName(),
			CharacterType()
			{}
		
		GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterName(src.CharacterName),
			CharacterType(src.CharacterType)
			{}
			
		GrantCharacterToUserRequest(const rapidjson::Value& obj) : GrantCharacterToUserRequest()
        {
            readFromValue(obj);
        }
		
		~GrantCharacterToUserRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GrantCharacterToUserResult : public PlayFabBaseModel
    {
		
		std::string CharacterId;
	
        GrantCharacterToUserResult() :
			PlayFabBaseModel(),
			CharacterId()
			{}
		
		GrantCharacterToUserResult(const GrantCharacterToUserResult& src) :
			PlayFabBaseModel(),
			CharacterId(src.CharacterId)
			{}
			
		GrantCharacterToUserResult(const rapidjson::Value& obj) : GrantCharacterToUserResult()
        {
            readFromValue(obj);
        }
		
		~GrantCharacterToUserResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GrantItemsToCharacterRequest : public PlayFabBaseModel
    {
		
		std::string CatalogVersion;
		std::string CharacterId;
		std::string PlayFabId;
		std::string Annotation;
		std::list<std::string> ItemIds;
	
        GrantItemsToCharacterRequest() :
			PlayFabBaseModel(),
			CatalogVersion(),
			CharacterId(),
			PlayFabId(),
			Annotation(),
			ItemIds()
			{}
		
		GrantItemsToCharacterRequest(const GrantItemsToCharacterRequest& src) :
			PlayFabBaseModel(),
			CatalogVersion(src.CatalogVersion),
			CharacterId(src.CharacterId),
			PlayFabId(src.PlayFabId),
			Annotation(src.Annotation),
			ItemIds(src.ItemIds)
			{}
			
		GrantItemsToCharacterRequest(const rapidjson::Value& obj) : GrantItemsToCharacterRequest()
        {
            readFromValue(obj);
        }
		
		~GrantItemsToCharacterRequest();
		
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
		std::string CharacterId;
	
        ItemGrantResult() :
			PlayFabBaseModel(),
			PlayFabId(),
			ItemId(),
			ItemInstanceId(),
			Annotation(),
			Result(false),
			CharacterId()
			{}
		
		ItemGrantResult(const ItemGrantResult& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			ItemId(src.ItemId),
			ItemInstanceId(src.ItemInstanceId),
			Annotation(src.Annotation),
			Result(src.Result),
			CharacterId(src.CharacterId)
			{}
			
		ItemGrantResult(const rapidjson::Value& obj) : ItemGrantResult()
        {
            readFromValue(obj);
        }
		
		~ItemGrantResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GrantItemsToCharacterResult : public PlayFabBaseModel
    {
		
		std::list<ItemGrantResult> ItemGrantResults;
	
        GrantItemsToCharacterResult() :
			PlayFabBaseModel(),
			ItemGrantResults()
			{}
		
		GrantItemsToCharacterResult(const GrantItemsToCharacterResult& src) :
			PlayFabBaseModel(),
			ItemGrantResults(src.ItemGrantResults)
			{}
			
		GrantItemsToCharacterResult(const rapidjson::Value& obj) : GrantItemsToCharacterResult()
        {
            readFromValue(obj);
        }
		
		~GrantItemsToCharacterResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GrantItemsToUserRequest : public PlayFabBaseModel
    {
		
		std::string CatalogVersion;
		std::string PlayFabId;
		std::string Annotation;
		std::list<std::string> ItemIds;
	
        GrantItemsToUserRequest() :
			PlayFabBaseModel(),
			CatalogVersion(),
			PlayFabId(),
			Annotation(),
			ItemIds()
			{}
		
		GrantItemsToUserRequest(const GrantItemsToUserRequest& src) :
			PlayFabBaseModel(),
			CatalogVersion(src.CatalogVersion),
			PlayFabId(src.PlayFabId),
			Annotation(src.Annotation),
			ItemIds(src.ItemIds)
			{}
			
		GrantItemsToUserRequest(const rapidjson::Value& obj) : GrantItemsToUserRequest()
        {
            readFromValue(obj);
        }
		
		~GrantItemsToUserRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct GrantItemsToUserResult : public PlayFabBaseModel
    {
		
		std::list<ItemGrantResult> ItemGrantResults;
	
        GrantItemsToUserResult() :
			PlayFabBaseModel(),
			ItemGrantResults()
			{}
		
		GrantItemsToUserResult(const GrantItemsToUserResult& src) :
			PlayFabBaseModel(),
			ItemGrantResults(src.ItemGrantResults)
			{}
			
		GrantItemsToUserResult(const rapidjson::Value& obj) : GrantItemsToUserResult()
        {
            readFromValue(obj);
        }
		
		~GrantItemsToUserResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ItemGrant : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string ItemId;
		std::string Annotation;
		std::string CharacterId;
	
        ItemGrant() :
			PlayFabBaseModel(),
			PlayFabId(),
			ItemId(),
			Annotation(),
			CharacterId()
			{}
		
		ItemGrant(const ItemGrant& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			ItemId(src.ItemId),
			Annotation(src.Annotation),
			CharacterId(src.CharacterId)
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
	
	struct ListUsersCharactersRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
	
        ListUsersCharactersRequest() :
			PlayFabBaseModel(),
			PlayFabId()
			{}
		
		ListUsersCharactersRequest(const ListUsersCharactersRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId)
			{}
			
		ListUsersCharactersRequest(const rapidjson::Value& obj) : ListUsersCharactersRequest()
        {
            readFromValue(obj);
        }
		
		~ListUsersCharactersRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ListUsersCharactersResult : public PlayFabBaseModel
    {
		
		std::list<CharacterResult> Characters;
	
        ListUsersCharactersResult() :
			PlayFabBaseModel(),
			Characters()
			{}
		
		ListUsersCharactersResult(const ListUsersCharactersResult& src) :
			PlayFabBaseModel(),
			Characters(src.Characters)
			{}
			
		ListUsersCharactersResult(const rapidjson::Value& obj) : ListUsersCharactersResult()
        {
            readFromValue(obj);
        }
		
		~ListUsersCharactersResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct LogEventRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string EntityId;
		std::string EntityType;
		OptionalTime Timestamp;
		std::string EventName;
		std::map<std::string, MultitypeVar> Body;
		bool ProfileSetEvent;
	
        LogEventRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			EntityId(),
			EntityType(),
			Timestamp(),
			EventName(),
			Body(),
			ProfileSetEvent(false)
			{}
		
		LogEventRequest(const LogEventRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			EntityId(src.EntityId),
			EntityType(src.EntityType),
			Timestamp(src.Timestamp),
			EventName(src.EventName),
			Body(src.Body),
			ProfileSetEvent(src.ProfileSetEvent)
			{}
			
		LogEventRequest(const rapidjson::Value& obj) : LogEventRequest()
        {
            readFromValue(obj);
        }
		
		~LogEventRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct LogEventResult : public PlayFabBaseModel
    {
		
	
        LogEventResult() :
			PlayFabBaseModel()
			{}
		
		LogEventResult(const LogEventResult& src) :
			PlayFabBaseModel()
			{}
			
		LogEventResult(const rapidjson::Value& obj) : LogEventResult()
        {
            readFromValue(obj);
        }
		
		~LogEventResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ModifyItemUsesRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string ItemInstanceId;
		Int32 UsesToAdd;
	
        ModifyItemUsesRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			ItemInstanceId(),
			UsesToAdd(0)
			{}
		
		ModifyItemUsesRequest(const ModifyItemUsesRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			ItemInstanceId(src.ItemInstanceId),
			UsesToAdd(src.UsesToAdd)
			{}
			
		ModifyItemUsesRequest(const rapidjson::Value& obj) : ModifyItemUsesRequest()
        {
            readFromValue(obj);
        }
		
		~ModifyItemUsesRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ModifyItemUsesResult : public PlayFabBaseModel
    {
		
		std::string ItemInstanceId;
		Int32 RemainingUses;
	
        ModifyItemUsesResult() :
			PlayFabBaseModel(),
			ItemInstanceId(),
			RemainingUses(0)
			{}
		
		ModifyItemUsesResult(const ModifyItemUsesResult& src) :
			PlayFabBaseModel(),
			ItemInstanceId(src.ItemInstanceId),
			RemainingUses(src.RemainingUses)
			{}
			
		ModifyItemUsesResult(const rapidjson::Value& obj) : ModifyItemUsesResult()
        {
            readFromValue(obj);
        }
		
		~ModifyItemUsesResult();
		
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
	
	struct MoveItemToCharacterFromCharacterRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string GivingCharacterId;
		std::string ReceivingCharacterId;
		std::string ItemInstanceId;
	
        MoveItemToCharacterFromCharacterRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			GivingCharacterId(),
			ReceivingCharacterId(),
			ItemInstanceId()
			{}
		
		MoveItemToCharacterFromCharacterRequest(const MoveItemToCharacterFromCharacterRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			GivingCharacterId(src.GivingCharacterId),
			ReceivingCharacterId(src.ReceivingCharacterId),
			ItemInstanceId(src.ItemInstanceId)
			{}
			
		MoveItemToCharacterFromCharacterRequest(const rapidjson::Value& obj) : MoveItemToCharacterFromCharacterRequest()
        {
            readFromValue(obj);
        }
		
		~MoveItemToCharacterFromCharacterRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct MoveItemToCharacterFromCharacterResult : public PlayFabBaseModel
    {
		
	
        MoveItemToCharacterFromCharacterResult() :
			PlayFabBaseModel()
			{}
		
		MoveItemToCharacterFromCharacterResult(const MoveItemToCharacterFromCharacterResult& src) :
			PlayFabBaseModel()
			{}
			
		MoveItemToCharacterFromCharacterResult(const rapidjson::Value& obj) : MoveItemToCharacterFromCharacterResult()
        {
            readFromValue(obj);
        }
		
		~MoveItemToCharacterFromCharacterResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct MoveItemToCharacterFromUserRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterId;
		std::string ItemInstanceId;
	
        MoveItemToCharacterFromUserRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterId(),
			ItemInstanceId()
			{}
		
		MoveItemToCharacterFromUserRequest(const MoveItemToCharacterFromUserRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId),
			ItemInstanceId(src.ItemInstanceId)
			{}
			
		MoveItemToCharacterFromUserRequest(const rapidjson::Value& obj) : MoveItemToCharacterFromUserRequest()
        {
            readFromValue(obj);
        }
		
		~MoveItemToCharacterFromUserRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct MoveItemToCharacterFromUserResult : public PlayFabBaseModel
    {
		
	
        MoveItemToCharacterFromUserResult() :
			PlayFabBaseModel()
			{}
		
		MoveItemToCharacterFromUserResult(const MoveItemToCharacterFromUserResult& src) :
			PlayFabBaseModel()
			{}
			
		MoveItemToCharacterFromUserResult(const rapidjson::Value& obj) : MoveItemToCharacterFromUserResult()
        {
            readFromValue(obj);
        }
		
		~MoveItemToCharacterFromUserResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct MoveItemToUserFromCharacterRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterId;
		std::string ItemInstanceId;
	
        MoveItemToUserFromCharacterRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterId(),
			ItemInstanceId()
			{}
		
		MoveItemToUserFromCharacterRequest(const MoveItemToUserFromCharacterRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId),
			ItemInstanceId(src.ItemInstanceId)
			{}
			
		MoveItemToUserFromCharacterRequest(const rapidjson::Value& obj) : MoveItemToUserFromCharacterRequest()
        {
            readFromValue(obj);
        }
		
		~MoveItemToUserFromCharacterRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct MoveItemToUserFromCharacterResult : public PlayFabBaseModel
    {
		
	
        MoveItemToUserFromCharacterResult() :
			PlayFabBaseModel()
			{}
		
		MoveItemToUserFromCharacterResult(const MoveItemToUserFromCharacterResult& src) :
			PlayFabBaseModel()
			{}
			
		MoveItemToUserFromCharacterResult(const rapidjson::Value& obj) : MoveItemToUserFromCharacterResult()
        {
            readFromValue(obj);
        }
		
		~MoveItemToUserFromCharacterResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct NotifyMatchmakerPlayerLeftRequest : public PlayFabBaseModel
    {
		
		std::string LobbyId;
		std::string PlayFabId;
	
        NotifyMatchmakerPlayerLeftRequest() :
			PlayFabBaseModel(),
			LobbyId(),
			PlayFabId()
			{}
		
		NotifyMatchmakerPlayerLeftRequest(const NotifyMatchmakerPlayerLeftRequest& src) :
			PlayFabBaseModel(),
			LobbyId(src.LobbyId),
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
		std::string LobbyId;
	
        RedeemMatchmakerTicketRequest() :
			PlayFabBaseModel(),
			Ticket(),
			LobbyId()
			{}
		
		RedeemMatchmakerTicketRequest(const RedeemMatchmakerTicketRequest& src) :
			PlayFabBaseModel(),
			Ticket(src.Ticket),
			LobbyId(src.LobbyId)
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
	
	struct RemoveSharedGroupMembersRequest : public PlayFabBaseModel
    {
		
		std::string SharedGroupId;
		std::list<std::string> PlayFabIds;
	
        RemoveSharedGroupMembersRequest() :
			PlayFabBaseModel(),
			SharedGroupId(),
			PlayFabIds()
			{}
		
		RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
			PlayFabBaseModel(),
			SharedGroupId(src.SharedGroupId),
			PlayFabIds(src.PlayFabIds)
			{}
			
		RemoveSharedGroupMembersRequest(const rapidjson::Value& obj) : RemoveSharedGroupMembersRequest()
        {
            readFromValue(obj);
        }
		
		~RemoveSharedGroupMembersRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct RemoveSharedGroupMembersResult : public PlayFabBaseModel
    {
		
	
        RemoveSharedGroupMembersResult() :
			PlayFabBaseModel()
			{}
		
		RemoveSharedGroupMembersResult(const RemoveSharedGroupMembersResult& src) :
			PlayFabBaseModel()
			{}
			
		RemoveSharedGroupMembersResult(const rapidjson::Value& obj) : RemoveSharedGroupMembersResult()
        {
            readFromValue(obj);
        }
		
		~RemoveSharedGroupMembersResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ReportPlayerServerRequest : public PlayFabBaseModel
    {
		
		std::string ReporterId;
		std::string ReporteeId;
		std::string TitleId;
		std::string Comment;
	
        ReportPlayerServerRequest() :
			PlayFabBaseModel(),
			ReporterId(),
			ReporteeId(),
			TitleId(),
			Comment()
			{}
		
		ReportPlayerServerRequest(const ReportPlayerServerRequest& src) :
			PlayFabBaseModel(),
			ReporterId(src.ReporterId),
			ReporteeId(src.ReporteeId),
			TitleId(src.TitleId),
			Comment(src.Comment)
			{}
			
		ReportPlayerServerRequest(const rapidjson::Value& obj) : ReportPlayerServerRequest()
        {
            readFromValue(obj);
        }
		
		~ReportPlayerServerRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct ReportPlayerServerResult : public PlayFabBaseModel
    {
		
		bool Updated;
		Int32 SubmissionsRemaining;
	
        ReportPlayerServerResult() :
			PlayFabBaseModel(),
			Updated(false),
			SubmissionsRemaining(0)
			{}
		
		ReportPlayerServerResult(const ReportPlayerServerResult& src) :
			PlayFabBaseModel(),
			Updated(src.Updated),
			SubmissionsRemaining(src.SubmissionsRemaining)
			{}
			
		ReportPlayerServerResult(const rapidjson::Value& obj) : ReportPlayerServerResult()
        {
            readFromValue(obj);
        }
		
		~ReportPlayerServerResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct SendPushNotificationRequest : public PlayFabBaseModel
    {
		
		std::string Recipient;
		std::string Message;
		std::string Subject;
	
        SendPushNotificationRequest() :
			PlayFabBaseModel(),
			Recipient(),
			Message(),
			Subject()
			{}
		
		SendPushNotificationRequest(const SendPushNotificationRequest& src) :
			PlayFabBaseModel(),
			Recipient(src.Recipient),
			Message(src.Message),
			Subject(src.Subject)
			{}
			
		SendPushNotificationRequest(const rapidjson::Value& obj) : SendPushNotificationRequest()
        {
            readFromValue(obj);
        }
		
		~SendPushNotificationRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct SendPushNotificationResult : public PlayFabBaseModel
    {
		
	
        SendPushNotificationResult() :
			PlayFabBaseModel()
			{}
		
		SendPushNotificationResult(const SendPushNotificationResult& src) :
			PlayFabBaseModel()
			{}
			
		SendPushNotificationResult(const rapidjson::Value& obj) : SendPushNotificationResult()
        {
            readFromValue(obj);
        }
		
		~SendPushNotificationResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct SetPublisherDataRequest : public PlayFabBaseModel
    {
		
		std::string Key;
		std::string Value;
	
        SetPublisherDataRequest() :
			PlayFabBaseModel(),
			Key(),
			Value()
			{}
		
		SetPublisherDataRequest(const SetPublisherDataRequest& src) :
			PlayFabBaseModel(),
			Key(src.Key),
			Value(src.Value)
			{}
			
		SetPublisherDataRequest(const rapidjson::Value& obj) : SetPublisherDataRequest()
        {
            readFromValue(obj);
        }
		
		~SetPublisherDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct SetPublisherDataResult : public PlayFabBaseModel
    {
		
	
        SetPublisherDataResult() :
			PlayFabBaseModel()
			{}
		
		SetPublisherDataResult(const SetPublisherDataResult& src) :
			PlayFabBaseModel()
			{}
			
		SetPublisherDataResult(const rapidjson::Value& obj) : SetPublisherDataResult()
        {
            readFromValue(obj);
        }
		
		~SetPublisherDataResult();
		
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
	
	struct UpdateCharacterDataRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterId;
		std::map<std::string, std::string> Data;
		Boxed<UserDataPermission> Permission;
	
        UpdateCharacterDataRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterId(),
			Data(),
			Permission()
			{}
		
		UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId),
			Data(src.Data),
			Permission(src.Permission)
			{}
			
		UpdateCharacterDataRequest(const rapidjson::Value& obj) : UpdateCharacterDataRequest()
        {
            readFromValue(obj);
        }
		
		~UpdateCharacterDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateCharacterDataResult : public PlayFabBaseModel
    {
		
	
        UpdateCharacterDataResult() :
			PlayFabBaseModel()
			{}
		
		UpdateCharacterDataResult(const UpdateCharacterDataResult& src) :
			PlayFabBaseModel()
			{}
			
		UpdateCharacterDataResult(const rapidjson::Value& obj) : UpdateCharacterDataResult()
        {
            readFromValue(obj);
        }
		
		~UpdateCharacterDataResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateCharacterStatisticsRequest : public PlayFabBaseModel
    {
		
		std::string PlayFabId;
		std::string CharacterId;
		std::map<std::string, Int32> CharacterStatistics;
	
        UpdateCharacterStatisticsRequest() :
			PlayFabBaseModel(),
			PlayFabId(),
			CharacterId(),
			CharacterStatistics()
			{}
		
		UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
			PlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			CharacterId(src.CharacterId),
			CharacterStatistics(src.CharacterStatistics)
			{}
			
		UpdateCharacterStatisticsRequest(const rapidjson::Value& obj) : UpdateCharacterStatisticsRequest()
        {
            readFromValue(obj);
        }
		
		~UpdateCharacterStatisticsRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateCharacterStatisticsResult : public PlayFabBaseModel
    {
		
	
        UpdateCharacterStatisticsResult() :
			PlayFabBaseModel()
			{}
		
		UpdateCharacterStatisticsResult(const UpdateCharacterStatisticsResult& src) :
			PlayFabBaseModel()
			{}
			
		UpdateCharacterStatisticsResult(const rapidjson::Value& obj) : UpdateCharacterStatisticsResult()
        {
            readFromValue(obj);
        }
		
		~UpdateCharacterStatisticsResult();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateSharedGroupDataRequest : public PlayFabBaseModel
    {
		
		std::string SharedGroupId;
		std::map<std::string, std::string> Data;
		Boxed<UserDataPermission> Permission;
	
        UpdateSharedGroupDataRequest() :
			PlayFabBaseModel(),
			SharedGroupId(),
			Data(),
			Permission()
			{}
		
		UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
			PlayFabBaseModel(),
			SharedGroupId(src.SharedGroupId),
			Data(src.Data),
			Permission(src.Permission)
			{}
			
		UpdateSharedGroupDataRequest(const rapidjson::Value& obj) : UpdateSharedGroupDataRequest()
        {
            readFromValue(obj);
        }
		
		~UpdateSharedGroupDataRequest();
		
        void writeJSON(PFStringJsonWriter& writer);
        bool readFromValue(const rapidjson::Value& obj);
    };
	
	struct UpdateSharedGroupDataResult : public PlayFabBaseModel
    {
		
	
        UpdateSharedGroupDataResult() :
			PlayFabBaseModel()
			{}
		
		UpdateSharedGroupDataResult(const UpdateSharedGroupDataResult& src) :
			PlayFabBaseModel()
			{}
			
		UpdateSharedGroupDataResult(const rapidjson::Value& obj) : UpdateSharedGroupDataResult()
        {
            readFromValue(obj);
        }
		
		~UpdateSharedGroupDataResult();
		
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