#ifndef PLAYFAB_MATCHMAKER_DATA_MODELS_H_
#define PLAYFAB_MATCHMAKER_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

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

        struct DeregisterGameRequest : public PlayFabBaseModel
        {
            std::string LobbyId;

            DeregisterGameRequest() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            DeregisterGameRequest(const DeregisterGameRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            DeregisterGameRequest(const rapidjson::Value& obj) : DeregisterGameRequest()
            {
                readFromValue(obj);
            }

            ~DeregisterGameRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeregisterGameResponse : public PlayFabBaseModel
        {

            DeregisterGameResponse() :
                PlayFabBaseModel()
            {}

            DeregisterGameResponse(const DeregisterGameResponse& src) :
                PlayFabBaseModel()
            {}

            DeregisterGameResponse(const rapidjson::Value& obj) : DeregisterGameResponse()
            {
                readFromValue(obj);
            }

            ~DeregisterGameResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ItemInstance : public PlayFabBaseModel
        {
            std::string Annotation;
            std::list<std::string> BundleContents;
            std::string BundleParent;
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomData;
            std::string DisplayName;
            OptionalTime Expiration;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            OptionalTime PurchaseDate;
            OptionalInt32 RemainingUses;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            OptionalInt32 UsesIncrementedBy;

            ItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PurchaseDate(),
                RemainingUses(),
                UnitCurrency(),
                UnitPrice(0),
                UsesIncrementedBy()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
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

        struct RegisterGameRequest : public PlayFabBaseModel
        {
            std::string Build;
            std::string GameMode;
            std::string LobbyId;
            Region pfRegion;
            std::string ServerHost;
            std::string ServerIPV6Address;
            std::string ServerPort;
            std::map<std::string, std::string> Tags;

            RegisterGameRequest() :
                PlayFabBaseModel(),
                Build(),
                GameMode(),
                LobbyId(),
                pfRegion(),
                ServerHost(),
                ServerIPV6Address(),
                ServerPort(),
                Tags()
            {}

            RegisterGameRequest(const RegisterGameRequest& src) :
                PlayFabBaseModel(),
                Build(src.Build),
                GameMode(src.GameMode),
                LobbyId(src.LobbyId),
                pfRegion(src.pfRegion),
                ServerHost(src.ServerHost),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                Tags(src.Tags)
            {}

            RegisterGameRequest(const rapidjson::Value& obj) : RegisterGameRequest()
            {
                readFromValue(obj);
            }

            ~RegisterGameRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegisterGameResponse : public PlayFabBaseModel
        {
            std::string LobbyId;

            RegisterGameResponse() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            RegisterGameResponse(const RegisterGameResponse& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            RegisterGameResponse(const rapidjson::Value& obj) : RegisterGameResponse()
            {
                readFromValue(obj);
            }

            ~RegisterGameResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StartGameRequest : public PlayFabBaseModel
        {
            std::string Build;
            std::string CustomCommandLineData;
            std::string ExternalMatchmakerEventEndpoint;
            std::string GameMode;
            Region pfRegion;

            StartGameRequest() :
                PlayFabBaseModel(),
                Build(),
                CustomCommandLineData(),
                ExternalMatchmakerEventEndpoint(),
                GameMode(),
                pfRegion()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabBaseModel(),
                Build(src.Build),
                CustomCommandLineData(src.CustomCommandLineData),
                ExternalMatchmakerEventEndpoint(src.ExternalMatchmakerEventEndpoint),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion)
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
            std::string ServerIPV6Address;
            Uint32 ServerPort;

            StartGameResponse() :
                PlayFabBaseModel(),
                GameID(),
                ServerHostname(),
                ServerIPV6Address(),
                ServerPort(0)
            {}

            StartGameResponse(const StartGameResponse& src) :
                PlayFabBaseModel(),
                GameID(src.GameID),
                ServerHostname(src.ServerHostname),
                ServerIPV6Address(src.ServerIPV6Address),
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
            Int32 MinCatalogVersion;
            std::string PlayFabId;

            UserInfoRequest() :
                PlayFabBaseModel(),
                MinCatalogVersion(0),
                PlayFabId()
            {}

            UserInfoRequest(const UserInfoRequest& src) :
                PlayFabBaseModel(),
                MinCatalogVersion(src.MinCatalogVersion),
                PlayFabId(src.PlayFabId)
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
            Int32 RechargeMax;
            time_t RechargeTime;
            Int32 SecondsToRecharge;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                RechargeMax(0),
                RechargeTime(0),
                SecondsToRecharge(0)
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                RechargeMax(src.RechargeMax),
                RechargeTime(src.RechargeTime),
                SecondsToRecharge(src.SecondsToRecharge)
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
            std::list<ItemInstance> Inventory;
            bool IsDeveloper;
            std::string PlayFabId;
            std::string SteamId;
            std::string TitleDisplayName;
            std::string Username;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            UserInfoResponse() :
                PlayFabBaseModel(),
                Inventory(),
                IsDeveloper(false),
                PlayFabId(),
                SteamId(),
                TitleDisplayName(),
                Username(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            UserInfoResponse(const UserInfoResponse& src) :
                PlayFabBaseModel(),
                Inventory(src.Inventory),
                IsDeveloper(src.IsDeveloper),
                PlayFabId(src.PlayFabId),
                SteamId(src.SteamId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
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
