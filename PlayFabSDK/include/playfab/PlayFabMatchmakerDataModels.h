#ifndef PLAYFAB_MATCHMAKER_DATA_MODELS_H_
#define PLAYFAB_MATCHMAKER_DATA_MODELS_H_

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace MatchmakerModels
    {
        struct AuthUserRequest : public PlayFabBaseModel
        {
            std::string AuthorizationTicket;

            AuthUserRequest() :
                PlayFabBaseModel(),
                AuthorizationTicket()
            {}

            AuthUserRequest(const AuthUserRequest& src) :
                PlayFabBaseModel(),
                AuthorizationTicket(src.AuthorizationTicket)
            {}

            AuthUserRequest(const rapidjson::Value& obj) : AuthUserRequest()
            {
                readFromValue(obj);
            }

            ~AuthUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AuthUserResponse : public PlayFabBaseModel
        {
            bool Authorized;
            std::string PlayFabId;

            AuthUserResponse() :
                PlayFabBaseModel(),
                Authorized(false),
                PlayFabId()
            {}

            AuthUserResponse(const AuthUserResponse& src) :
                PlayFabBaseModel(),
                Authorized(src.Authorized),
                PlayFabId(src.PlayFabId)
            {}

            AuthUserResponse(const rapidjson::Value& obj) : AuthUserResponse()
            {
                readFromValue(obj);
            }

            ~AuthUserResponse();

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
            OptionalInt32 UsesIncrementedBy;
            std::string Annotation;
            std::string CatalogVersion;
            std::string BundleParent;
            std::string DisplayName;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            std::list<std::string> BundleContents;
            std::map<std::string, std::string> CustomData;

            ItemInstance() :
                PlayFabBaseModel(),
                ItemId(),
                ItemInstanceId(),
                ItemClass(),
                PurchaseDate(),
                Expiration(),
                RemainingUses(),
                UsesIncrementedBy(),
                Annotation(),
                CatalogVersion(),
                BundleParent(),
                DisplayName(),
                UnitCurrency(),
                UnitPrice(0),
                BundleContents(),
                CustomData()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                ItemClass(src.ItemClass),
                PurchaseDate(src.PurchaseDate),
                Expiration(src.Expiration),
                RemainingUses(src.RemainingUses),
                UsesIncrementedBy(src.UsesIncrementedBy),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                BundleParent(src.BundleParent),
                DisplayName(src.DisplayName),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                BundleContents(src.BundleContents),
                CustomData(src.CustomData)
            {}

            ItemInstance(const rapidjson::Value& obj) : ItemInstance()
            {
                readFromValue(obj);
            }

            ~ItemInstance();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerJoinedRequest : public PlayFabBaseModel
        {
            std::string LobbyId;
            std::string PlayFabId;

            PlayerJoinedRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                PlayFabId()
            {}

            PlayerJoinedRequest(const PlayerJoinedRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            PlayerJoinedRequest(const rapidjson::Value& obj) : PlayerJoinedRequest()
            {
                readFromValue(obj);
            }

            ~PlayerJoinedRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerJoinedResponse : public PlayFabBaseModel
        {

            PlayerJoinedResponse() :
                PlayFabBaseModel()
            {}

            PlayerJoinedResponse(const PlayerJoinedResponse& src) :
                PlayFabBaseModel()
            {}

            PlayerJoinedResponse(const rapidjson::Value& obj) : PlayerJoinedResponse()
            {
                readFromValue(obj);
            }

            ~PlayerJoinedResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLeftRequest : public PlayFabBaseModel
        {
            std::string LobbyId;
            std::string PlayFabId;

            PlayerLeftRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                PlayFabId()
            {}

            PlayerLeftRequest(const PlayerLeftRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            PlayerLeftRequest(const rapidjson::Value& obj) : PlayerLeftRequest()
            {
                readFromValue(obj);
            }

            ~PlayerLeftRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLeftResponse : public PlayFabBaseModel
        {

            PlayerLeftResponse() :
                PlayFabBaseModel()
            {}

            PlayerLeftResponse(const PlayerLeftResponse& src) :
                PlayFabBaseModel()
            {}

            PlayerLeftResponse(const rapidjson::Value& obj) : PlayerLeftResponse()
            {
                readFromValue(obj);
            }

            ~PlayerLeftResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum Region
        {
            RegionUSCentral,
            RegionUSEast,
            RegionEUWest,
            RegionSingapore,
            RegionJapan,
            RegionBrazil,
            RegionAustralia
        };

        void writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer);
        Region readRegionFromValue(const rapidjson::Value& obj);

        struct StartGameRequest : public PlayFabBaseModel
        {
            std::string Build;
            Region pfRegion;
            std::string GameMode;
            std::string CustomCommandLineData;
            std::string ExternalMatchmakerEventEndpoint;

            StartGameRequest() :
                PlayFabBaseModel(),
                Build(),
                pfRegion(),
                GameMode(),
                CustomCommandLineData(),
                ExternalMatchmakerEventEndpoint()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabBaseModel(),
                Build(src.Build),
                pfRegion(src.pfRegion),
                GameMode(src.GameMode),
                CustomCommandLineData(src.CustomCommandLineData),
                ExternalMatchmakerEventEndpoint(src.ExternalMatchmakerEventEndpoint)
            {}

            StartGameRequest(const rapidjson::Value& obj) : StartGameRequest()
            {
                readFromValue(obj);
            }

            ~StartGameRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StartGameResponse : public PlayFabBaseModel
        {
            std::string GameID;
            std::string ServerHostname;
            Uint32 ServerPort;

            StartGameResponse() :
                PlayFabBaseModel(),
                GameID(),
                ServerHostname(),
                ServerPort(0)
            {}

            StartGameResponse(const StartGameResponse& src) :
                PlayFabBaseModel(),
                GameID(src.GameID),
                ServerHostname(src.ServerHostname),
                ServerPort(src.ServerPort)
            {}

            StartGameResponse(const rapidjson::Value& obj) : StartGameResponse()
            {
                readFromValue(obj);
            }

            ~StartGameResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserInfoRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            Int32 MinCatalogVersion;

            UserInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                MinCatalogVersion(0)
            {}

            UserInfoRequest(const UserInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                MinCatalogVersion(src.MinCatalogVersion)
            {}

            UserInfoRequest(const rapidjson::Value& obj) : UserInfoRequest()
            {
                readFromValue(obj);
            }

            ~UserInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
            Int32 SecondsToRecharge;
            time_t RechargeTime;
            Int32 RechargeMax;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                SecondsToRecharge(0),
                RechargeTime(0),
                RechargeMax(0)
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                SecondsToRecharge(src.SecondsToRecharge),
                RechargeTime(src.RechargeTime),
                RechargeMax(src.RechargeMax)
            {}

            VirtualCurrencyRechargeTime(const rapidjson::Value& obj) : VirtualCurrencyRechargeTime()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyRechargeTime();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserInfoResponse : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string Username;
            std::string TitleDisplayName;
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;
            bool IsDeveloper;
            std::string SteamId;

            UserInfoResponse() :
                PlayFabBaseModel(),
                PlayFabId(),
                Username(),
                TitleDisplayName(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes(),
                IsDeveloper(false),
                SteamId()
            {}

            UserInfoResponse(const UserInfoResponse& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Username(src.Username),
                TitleDisplayName(src.TitleDisplayName),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes),
                IsDeveloper(src.IsDeveloper),
                SteamId(src.SteamId)
            {}

            UserInfoResponse(const rapidjson::Value& obj) : UserInfoResponse()
            {
                readFromValue(obj);
            }

            ~UserInfoResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
