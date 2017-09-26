#ifndef PLAYFAB_SERVER_DATA_MODELS_H_
#define PLAYFAB_SERVER_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ServerModels
    {
        struct AdCampaignAttribution : public PlayFabBaseModel
        {
            time_t AttributedAt;
            std::string CampaignId;
            std::string Platform;

            AdCampaignAttribution() :
                PlayFabBaseModel(),
                AttributedAt(0),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttribution(const AdCampaignAttribution& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            AdCampaignAttribution(const rapidjson::Value& obj) : AdCampaignAttribution()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttribution();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AdCampaignAttributionModel : public PlayFabBaseModel
        {
            time_t AttributedAt;
            std::string CampaignId;
            std::string Platform;

            AdCampaignAttributionModel() :
                PlayFabBaseModel(),
                AttributedAt(0),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttributionModel(const AdCampaignAttributionModel& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            AdCampaignAttributionModel(const rapidjson::Value& obj) : AdCampaignAttributionModel()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttributionModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddCharacterVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string CharacterId;
            std::string PlayFabId;
            std::string VirtualCurrency;

            AddCharacterVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                CharacterId(),
                PlayFabId(),
                VirtualCurrency()
            {}

            AddCharacterVirtualCurrencyRequest(const AddCharacterVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            AddCharacterVirtualCurrencyRequest(const rapidjson::Value& obj) : AddCharacterVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddCharacterVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddFriendRequest : public PlayFabBaseModel
        {
            std::string FriendEmail;
            std::string FriendPlayFabId;
            std::string FriendTitleDisplayName;
            std::string FriendUsername;
            std::string PlayFabId;

            AddFriendRequest() :
                PlayFabBaseModel(),
                FriendEmail(),
                FriendPlayFabId(),
                FriendTitleDisplayName(),
                FriendUsername(),
                PlayFabId()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabBaseModel(),
                FriendEmail(src.FriendEmail),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendTitleDisplayName(src.FriendTitleDisplayName),
                FriendUsername(src.FriendUsername),
                PlayFabId(src.PlayFabId)
            {}

            AddFriendRequest(const rapidjson::Value& obj) : AddFriendRequest()
            {
                readFromValue(obj);
            }

            ~AddFriendRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddPlayerTagRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string TagName;

            AddPlayerTagRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                TagName()
            {}

            AddPlayerTagRequest(const AddPlayerTagRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            AddPlayerTagRequest(const rapidjson::Value& obj) : AddPlayerTagRequest()
            {
                readFromValue(obj);
            }

            ~AddPlayerTagRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddPlayerTagResult : public PlayFabBaseModel
        {

            AddPlayerTagResult() :
                PlayFabBaseModel()
            {}

            AddPlayerTagResult(const AddPlayerTagResult& src) :
                PlayFabBaseModel()
            {}

            AddPlayerTagResult(const rapidjson::Value& obj) : AddPlayerTagResult()
            {
                readFromValue(obj);
            }

            ~AddPlayerTagResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddSharedGroupMembersRequest : public PlayFabBaseModel
        {
            std::list<std::string> PlayFabIds;
            std::string SharedGroupId;

            AddSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                SharedGroupId()
            {}

            AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
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
            Int32 Amount;
            std::string PlayFabId;
            std::string VirtualCurrency;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                PlayFabId(),
                VirtualCurrency()
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            AddUserVirtualCurrencyRequest(const rapidjson::Value& obj) : AddUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddUserVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        void writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer);
        PushNotificationPlatform readPushNotificationPlatformFromValue(const rapidjson::Value& obj);

        struct AdvancedPushPlatformMsg : public PlayFabBaseModel
        {
            std::string Json;
            PushNotificationPlatform Platform;

            AdvancedPushPlatformMsg() :
                PlayFabBaseModel(),
                Json(),
                Platform()
            {}

            AdvancedPushPlatformMsg(const AdvancedPushPlatformMsg& src) :
                PlayFabBaseModel(),
                Json(src.Json),
                Platform(src.Platform)
            {}

            AdvancedPushPlatformMsg(const rapidjson::Value& obj) : AdvancedPushPlatformMsg()
            {
                readFromValue(obj);
            }

            ~AdvancedPushPlatformMsg();

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

        struct UserAndroidDeviceInfo : public PlayFabBaseModel
        {
            std::string AndroidDeviceId;

            UserAndroidDeviceInfo() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UserAndroidDeviceInfo(const UserAndroidDeviceInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UserAndroidDeviceInfo(const rapidjson::Value& obj) : UserAndroidDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserAndroidDeviceInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserCustomIdInfo : public PlayFabBaseModel
        {
            std::string CustomId;

            UserCustomIdInfo() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UserCustomIdInfo(const UserCustomIdInfo& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UserCustomIdInfo(const rapidjson::Value& obj) : UserCustomIdInfo()
            {
                readFromValue(obj);
            }

            ~UserCustomIdInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserFacebookInfo : public PlayFabBaseModel
        {
            std::string FacebookId;
            std::string FullName;

            UserFacebookInfo() :
                PlayFabBaseModel(),
                FacebookId(),
                FullName()
            {}

            UserFacebookInfo(const UserFacebookInfo& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                FullName(src.FullName)
            {}

            UserFacebookInfo(const rapidjson::Value& obj) : UserFacebookInfo()
            {
                readFromValue(obj);
            }

            ~UserFacebookInfo();

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

        struct UserGoogleInfo : public PlayFabBaseModel
        {
            std::string GoogleEmail;
            std::string GoogleGender;
            std::string GoogleId;
            std::string GoogleLocale;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleEmail(),
                GoogleGender(),
                GoogleId(),
                GoogleLocale()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleEmail(src.GoogleEmail),
                GoogleGender(src.GoogleGender),
                GoogleId(src.GoogleId),
                GoogleLocale(src.GoogleLocale)
            {}

            UserGoogleInfo(const rapidjson::Value& obj) : UserGoogleInfo()
            {
                readFromValue(obj);
            }

            ~UserGoogleInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
            std::string IosDeviceId;

            UserIosDeviceInfo() :
                PlayFabBaseModel(),
                IosDeviceId()
            {}

            UserIosDeviceInfo(const UserIosDeviceInfo& src) :
                PlayFabBaseModel(),
                IosDeviceId(src.IosDeviceId)
            {}

            UserIosDeviceInfo(const rapidjson::Value& obj) : UserIosDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserIosDeviceInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserKongregateInfo : public PlayFabBaseModel
        {
            std::string KongregateId;
            std::string KongregateName;

            UserKongregateInfo() :
                PlayFabBaseModel(),
                KongregateId(),
                KongregateName()
            {}

            UserKongregateInfo(const UserKongregateInfo& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                KongregateName(src.KongregateName)
            {}

            UserKongregateInfo(const rapidjson::Value& obj) : UserKongregateInfo()
            {
                readFromValue(obj);
            }

            ~UserKongregateInfo();

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

        struct UserPsnInfo : public PlayFabBaseModel
        {
            std::string PsnAccountId;
            std::string PsnOnlineId;

            UserPsnInfo() :
                PlayFabBaseModel(),
                PsnAccountId(),
                PsnOnlineId()
            {}

            UserPsnInfo(const UserPsnInfo& src) :
                PlayFabBaseModel(),
                PsnAccountId(src.PsnAccountId),
                PsnOnlineId(src.PsnOnlineId)
            {}

            UserPsnInfo(const rapidjson::Value& obj) : UserPsnInfo()
            {
                readFromValue(obj);
            }

            ~UserPsnInfo();

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

        enum Currency
        {
            CurrencyAED,
            CurrencyAFN,
            CurrencyALL,
            CurrencyAMD,
            CurrencyANG,
            CurrencyAOA,
            CurrencyARS,
            CurrencyAUD,
            CurrencyAWG,
            CurrencyAZN,
            CurrencyBAM,
            CurrencyBBD,
            CurrencyBDT,
            CurrencyBGN,
            CurrencyBHD,
            CurrencyBIF,
            CurrencyBMD,
            CurrencyBND,
            CurrencyBOB,
            CurrencyBRL,
            CurrencyBSD,
            CurrencyBTN,
            CurrencyBWP,
            CurrencyBYR,
            CurrencyBZD,
            CurrencyCAD,
            CurrencyCDF,
            CurrencyCHF,
            CurrencyCLP,
            CurrencyCNY,
            CurrencyCOP,
            CurrencyCRC,
            CurrencyCUC,
            CurrencyCUP,
            CurrencyCVE,
            CurrencyCZK,
            CurrencyDJF,
            CurrencyDKK,
            CurrencyDOP,
            CurrencyDZD,
            CurrencyEGP,
            CurrencyERN,
            CurrencyETB,
            CurrencyEUR,
            CurrencyFJD,
            CurrencyFKP,
            CurrencyGBP,
            CurrencyGEL,
            CurrencyGGP,
            CurrencyGHS,
            CurrencyGIP,
            CurrencyGMD,
            CurrencyGNF,
            CurrencyGTQ,
            CurrencyGYD,
            CurrencyHKD,
            CurrencyHNL,
            CurrencyHRK,
            CurrencyHTG,
            CurrencyHUF,
            CurrencyIDR,
            CurrencyILS,
            CurrencyIMP,
            CurrencyINR,
            CurrencyIQD,
            CurrencyIRR,
            CurrencyISK,
            CurrencyJEP,
            CurrencyJMD,
            CurrencyJOD,
            CurrencyJPY,
            CurrencyKES,
            CurrencyKGS,
            CurrencyKHR,
            CurrencyKMF,
            CurrencyKPW,
            CurrencyKRW,
            CurrencyKWD,
            CurrencyKYD,
            CurrencyKZT,
            CurrencyLAK,
            CurrencyLBP,
            CurrencyLKR,
            CurrencyLRD,
            CurrencyLSL,
            CurrencyLYD,
            CurrencyMAD,
            CurrencyMDL,
            CurrencyMGA,
            CurrencyMKD,
            CurrencyMMK,
            CurrencyMNT,
            CurrencyMOP,
            CurrencyMRO,
            CurrencyMUR,
            CurrencyMVR,
            CurrencyMWK,
            CurrencyMXN,
            CurrencyMYR,
            CurrencyMZN,
            CurrencyNAD,
            CurrencyNGN,
            CurrencyNIO,
            CurrencyNOK,
            CurrencyNPR,
            CurrencyNZD,
            CurrencyOMR,
            CurrencyPAB,
            CurrencyPEN,
            CurrencyPGK,
            CurrencyPHP,
            CurrencyPKR,
            CurrencyPLN,
            CurrencyPYG,
            CurrencyQAR,
            CurrencyRON,
            CurrencyRSD,
            CurrencyRUB,
            CurrencyRWF,
            CurrencySAR,
            CurrencySBD,
            CurrencySCR,
            CurrencySDG,
            CurrencySEK,
            CurrencySGD,
            CurrencySHP,
            CurrencySLL,
            CurrencySOS,
            CurrencySPL,
            CurrencySRD,
            CurrencySTD,
            CurrencySVC,
            CurrencySYP,
            CurrencySZL,
            CurrencyTHB,
            CurrencyTJS,
            CurrencyTMT,
            CurrencyTND,
            CurrencyTOP,
            CurrencyTRY,
            CurrencyTTD,
            CurrencyTVD,
            CurrencyTWD,
            CurrencyTZS,
            CurrencyUAH,
            CurrencyUGX,
            CurrencyUSD,
            CurrencyUYU,
            CurrencyUZS,
            CurrencyVEF,
            CurrencyVND,
            CurrencyVUV,
            CurrencyWST,
            CurrencyXAF,
            CurrencyXCD,
            CurrencyXDR,
            CurrencyXOF,
            CurrencyXPF,
            CurrencyYER,
            CurrencyZAR,
            CurrencyZMW,
            CurrencyZWD
        };

        void writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer);
        Currency readCurrencyFromValue(const rapidjson::Value& obj);

        struct UserSteamInfo : public PlayFabBaseModel
        {
            Boxed<TitleActivationStatus> SteamActivationStatus;
            std::string SteamCountry;
            Boxed<Currency> SteamCurrency;
            std::string SteamId;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamActivationStatus(),
                SteamCountry(),
                SteamCurrency(),
                SteamId()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamActivationStatus(src.SteamActivationStatus),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamId(src.SteamId)
            {}

            UserSteamInfo(const rapidjson::Value& obj) : UserSteamInfo()
            {
                readFromValue(obj);
            }

            ~UserSteamInfo();

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
            UserOriginationGameCenter,
            UserOriginationCustomId,
            UserOriginationXboxLive,
            UserOriginationParse,
            UserOriginationTwitch,
            UserOriginationWindowsHello
        };

        void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer);
        UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj);

        struct UserTitleInfo : public PlayFabBaseModel
        {
            std::string AvatarUrl;
            time_t Created;
            std::string DisplayName;
            OptionalTime FirstLogin;
            OptionalBool isBanned;
            OptionalTime LastLogin;
            Boxed<UserOrigination> Origination;

            UserTitleInfo() :
                PlayFabBaseModel(),
                AvatarUrl(),
                Created(0),
                DisplayName(),
                FirstLogin(),
                isBanned(),
                LastLogin(),
                Origination()
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                AvatarUrl(src.AvatarUrl),
                Created(src.Created),
                DisplayName(src.DisplayName),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned),
                LastLogin(src.LastLogin),
                Origination(src.Origination)
            {}

            UserTitleInfo(const rapidjson::Value& obj) : UserTitleInfo()
            {
                readFromValue(obj);
            }

            ~UserTitleInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserTwitchInfo : public PlayFabBaseModel
        {
            std::string TwitchId;
            std::string TwitchUserName;

            UserTwitchInfo() :
                PlayFabBaseModel(),
                TwitchId(),
                TwitchUserName()
            {}

            UserTwitchInfo(const UserTwitchInfo& src) :
                PlayFabBaseModel(),
                TwitchId(src.TwitchId),
                TwitchUserName(src.TwitchUserName)
            {}

            UserTwitchInfo(const rapidjson::Value& obj) : UserTwitchInfo()
            {
                readFromValue(obj);
            }

            ~UserTwitchInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserXboxInfo : public PlayFabBaseModel
        {
            std::string XboxUserId;

            UserXboxInfo() :
                PlayFabBaseModel(),
                XboxUserId()
            {}

            UserXboxInfo(const UserXboxInfo& src) :
                PlayFabBaseModel(),
                XboxUserId(src.XboxUserId)
            {}

            UserXboxInfo(const rapidjson::Value& obj) : UserXboxInfo()
            {
                readFromValue(obj);
            }

            ~UserXboxInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            UserAndroidDeviceInfo* AndroidDeviceInfo;
            time_t Created;
            UserCustomIdInfo* CustomIdInfo;
            UserFacebookInfo* FacebookInfo;
            UserGameCenterInfo* GameCenterInfo;
            UserGoogleInfo* GoogleInfo;
            UserIosDeviceInfo* IosDeviceInfo;
            UserKongregateInfo* KongregateInfo;
            std::string PlayFabId;
            UserPrivateAccountInfo* PrivateInfo;
            UserPsnInfo* PsnInfo;
            UserSteamInfo* SteamInfo;
            UserTitleInfo* TitleInfo;
            UserTwitchInfo* TwitchInfo;
            std::string Username;
            UserXboxInfo* XboxInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                AndroidDeviceInfo(NULL),
                Created(0),
                CustomIdInfo(NULL),
                FacebookInfo(NULL),
                GameCenterInfo(NULL),
                GoogleInfo(NULL),
                IosDeviceInfo(NULL),
                KongregateInfo(NULL),
                PlayFabId(),
                PrivateInfo(NULL),
                PsnInfo(NULL),
                SteamInfo(NULL),
                TitleInfo(NULL),
                TwitchInfo(NULL),
                Username(),
                XboxInfo(NULL)
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceInfo(src.AndroidDeviceInfo ? new UserAndroidDeviceInfo(*src.AndroidDeviceInfo) : NULL),
                Created(src.Created),
                CustomIdInfo(src.CustomIdInfo ? new UserCustomIdInfo(*src.CustomIdInfo) : NULL),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : NULL),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL),
                GoogleInfo(src.GoogleInfo ? new UserGoogleInfo(*src.GoogleInfo) : NULL),
                IosDeviceInfo(src.IosDeviceInfo ? new UserIosDeviceInfo(*src.IosDeviceInfo) : NULL),
                KongregateInfo(src.KongregateInfo ? new UserKongregateInfo(*src.KongregateInfo) : NULL),
                PlayFabId(src.PlayFabId),
                PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : NULL),
                PsnInfo(src.PsnInfo ? new UserPsnInfo(*src.PsnInfo) : NULL),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : NULL),
                TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : NULL),
                TwitchInfo(src.TwitchInfo ? new UserTwitchInfo(*src.TwitchInfo) : NULL),
                Username(src.Username),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : NULL)
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
            std::string AchievementName;
            std::string PlayFabId;
            bool Result;

            AwardSteamAchievementItem() :
                PlayFabBaseModel(),
                AchievementName(),
                PlayFabId(),
                Result(false)
            {}

            AwardSteamAchievementItem(const AwardSteamAchievementItem& src) :
                PlayFabBaseModel(),
                AchievementName(src.AchievementName),
                PlayFabId(src.PlayFabId),
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

        struct BanInfo : public PlayFabBaseModel
        {
            bool Active;
            std::string BanId;
            OptionalTime Created;
            OptionalTime Expires;
            std::string IPAddress;
            std::string MACAddress;
            std::string PlayFabId;
            std::string Reason;

            BanInfo() :
                PlayFabBaseModel(),
                Active(false),
                BanId(),
                Created(),
                Expires(),
                IPAddress(),
                MACAddress(),
                PlayFabId(),
                Reason()
            {}

            BanInfo(const BanInfo& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                BanId(src.BanId),
                Created(src.Created),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            BanInfo(const rapidjson::Value& obj) : BanInfo()
            {
                readFromValue(obj);
            }

            ~BanInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BanRequest : public PlayFabBaseModel
        {
            OptionalUint32 DurationInHours;
            std::string IPAddress;
            std::string MACAddress;
            std::string PlayFabId;
            std::string Reason;

            BanRequest() :
                PlayFabBaseModel(),
                DurationInHours(),
                IPAddress(),
                MACAddress(),
                PlayFabId(),
                Reason()
            {}

            BanRequest(const BanRequest& src) :
                PlayFabBaseModel(),
                DurationInHours(src.DurationInHours),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            BanRequest(const rapidjson::Value& obj) : BanRequest()
            {
                readFromValue(obj);
            }

            ~BanRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BanUsersRequest : public PlayFabBaseModel
        {
            std::list<BanRequest> Bans;

            BanUsersRequest() :
                PlayFabBaseModel(),
                Bans()
            {}

            BanUsersRequest(const BanUsersRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans)
            {}

            BanUsersRequest(const rapidjson::Value& obj) : BanUsersRequest()
            {
                readFromValue(obj);
            }

            ~BanUsersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BanUsersResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            BanUsersResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            BanUsersResult(const BanUsersResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            BanUsersResult(const rapidjson::Value& obj) : BanUsersResult()
            {
                readFromValue(obj);
            }

            ~BanUsersResult();

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
            std::list<std::string> ItemContents;
            std::string KeyItemId;
            std::list<std::string> ResultTableContents;
            std::map<std::string, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                ItemContents(),
                KeyItemId(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                ItemContents(src.ItemContents),
                KeyItemId(src.KeyItemId),
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

        struct CatalogItem : public PlayFabBaseModel
        {
            CatalogItemBundleInfo* Bundle;
            bool CanBecomeCharacter;
            std::string CatalogVersion;
            CatalogItemConsumableInfo* Consumable;
            CatalogItemContainerInfo* Container;
            std::string CustomData;
            std::string Description;
            std::string DisplayName;
            Int32 InitialLimitedEditionCount;
            bool IsLimitedEdition;
            bool IsStackable;
            bool IsTradable;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemImageUrl;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::list<std::string> Tags;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            CatalogItem() :
                PlayFabBaseModel(),
                Bundle(NULL),
                CanBecomeCharacter(false),
                CatalogVersion(),
                Consumable(NULL),
                Container(NULL),
                CustomData(),
                Description(),
                DisplayName(),
                InitialLimitedEditionCount(0),
                IsLimitedEdition(false),
                IsStackable(false),
                IsTradable(false),
                ItemClass(),
                ItemId(),
                ItemImageUrl(),
                RealCurrencyPrices(),
                Tags(),
                VirtualCurrencyPrices()
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : NULL),
                CanBecomeCharacter(src.CanBecomeCharacter),
                CatalogVersion(src.CatalogVersion),
                Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : NULL),
                Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : NULL),
                CustomData(src.CustomData),
                Description(src.Description),
                DisplayName(src.DisplayName),
                InitialLimitedEditionCount(src.InitialLimitedEditionCount),
                IsLimitedEdition(src.IsLimitedEdition),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemImageUrl(src.ItemImageUrl),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem();

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

        struct CharacterInventory : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::list<ItemInstance> Inventory;

            CharacterInventory() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory()
            {}

            CharacterInventory(const CharacterInventory& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory)
            {}

            CharacterInventory(const rapidjson::Value& obj) : CharacterInventory()
            {
                readFromValue(obj);
            }

            ~CharacterInventory();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CharacterLeaderboardEntry : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string CharacterName;
            std::string CharacterType;
            std::string DisplayName;
            std::string PlayFabId;
            Int32 Position;
            Int32 StatValue;

            CharacterLeaderboardEntry() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType(),
                DisplayName(),
                PlayFabId(),
                Position(0),
                StatValue(0)
            {}

            CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                StatValue(src.StatValue)
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

        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        void writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer);
        CloudScriptRevisionOption readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj);

        struct ConsumeItemRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            Int32 ConsumeCount;
            std::string ItemInstanceId;
            std::string PlayFabId;

            ConsumeItemRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                ConsumeCount(0),
                ItemInstanceId(),
                PlayFabId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ConsumeCount(src.ConsumeCount),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ConsumeItemRequest(const rapidjson::Value& obj) : ConsumeItemRequest()
            {
                readFromValue(obj);
            }

            ~ConsumeItemRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConsumeItemResult : public PlayFabBaseModel
        {
            std::string ItemInstanceId;
            Int32 RemainingUses;

            ConsumeItemResult() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                RemainingUses(0)
            {}

            ConsumeItemResult(const ConsumeItemResult& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ConsumeItemResult(const rapidjson::Value& obj) : ConsumeItemResult()
            {
                readFromValue(obj);
            }

            ~ConsumeItemResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum EmailVerificationStatus
        {
            EmailVerificationStatusUnverified,
            EmailVerificationStatusPending,
            EmailVerificationStatusConfirmed
        };

        void writeEmailVerificationStatusEnumJSON(EmailVerificationStatus enumVal, PFStringJsonWriter& writer);
        EmailVerificationStatus readEmailVerificationStatusFromValue(const rapidjson::Value& obj);

        struct ContactEmailInfo : public PlayFabBaseModel
        {
            std::string EmailAddress;
            std::string Name;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfo() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name(),
                VerificationStatus()
            {}

            ContactEmailInfo(const ContactEmailInfo& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name),
                VerificationStatus(src.VerificationStatus)
            {}

            ContactEmailInfo(const rapidjson::Value& obj) : ContactEmailInfo()
            {
                readFromValue(obj);
            }

            ~ContactEmailInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ContactEmailInfoModel : public PlayFabBaseModel
        {
            std::string EmailAddress;
            std::string Name;

            ContactEmailInfoModel() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name()
            {}

            ContactEmailInfoModel(const ContactEmailInfoModel& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name)
            {}

            ContactEmailInfoModel(const rapidjson::Value& obj) : ContactEmailInfoModel()
            {
                readFromValue(obj);
            }

            ~ContactEmailInfoModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum ContinentCode
        {
            ContinentCodeAF,
            ContinentCodeAN,
            ContinentCodeAS,
            ContinentCodeEU,
            ContinentCodeNA,
            ContinentCodeOC,
            ContinentCodeSA
        };

        void writeContinentCodeEnumJSON(ContinentCode enumVal, PFStringJsonWriter& writer);
        ContinentCode readContinentCodeFromValue(const rapidjson::Value& obj);

        enum CountryCode
        {
            CountryCodeAF,
            CountryCodeAX,
            CountryCodeAL,
            CountryCodeDZ,
            CountryCodeAS,
            CountryCodeAD,
            CountryCodeAO,
            CountryCodeAI,
            CountryCodeAQ,
            CountryCodeAG,
            CountryCodeAR,
            CountryCodeAM,
            CountryCodeAW,
            CountryCodeAU,
            CountryCodeAT,
            CountryCodeAZ,
            CountryCodeBS,
            CountryCodeBH,
            CountryCodeBD,
            CountryCodeBB,
            CountryCodeBY,
            CountryCodeBE,
            CountryCodeBZ,
            CountryCodeBJ,
            CountryCodeBM,
            CountryCodeBT,
            CountryCodeBO,
            CountryCodeBQ,
            CountryCodeBA,
            CountryCodeBW,
            CountryCodeBV,
            CountryCodeBR,
            CountryCodeIO,
            CountryCodeBN,
            CountryCodeBG,
            CountryCodeBF,
            CountryCodeBI,
            CountryCodeKH,
            CountryCodeCM,
            CountryCodeCA,
            CountryCodeCV,
            CountryCodeKY,
            CountryCodeCF,
            CountryCodeTD,
            CountryCodeCL,
            CountryCodeCN,
            CountryCodeCX,
            CountryCodeCC,
            CountryCodeCO,
            CountryCodeKM,
            CountryCodeCG,
            CountryCodeCD,
            CountryCodeCK,
            CountryCodeCR,
            CountryCodeCI,
            CountryCodeHR,
            CountryCodeCU,
            CountryCodeCW,
            CountryCodeCY,
            CountryCodeCZ,
            CountryCodeDK,
            CountryCodeDJ,
            CountryCodeDM,
            CountryCodeDO,
            CountryCodeEC,
            CountryCodeEG,
            CountryCodeSV,
            CountryCodeGQ,
            CountryCodeER,
            CountryCodeEE,
            CountryCodeET,
            CountryCodeFK,
            CountryCodeFO,
            CountryCodeFJ,
            CountryCodeFI,
            CountryCodeFR,
            CountryCodeGF,
            CountryCodePF,
            CountryCodeTF,
            CountryCodeGA,
            CountryCodeGM,
            CountryCodeGE,
            CountryCodeDE,
            CountryCodeGH,
            CountryCodeGI,
            CountryCodeGR,
            CountryCodeGL,
            CountryCodeGD,
            CountryCodeGP,
            CountryCodeGU,
            CountryCodeGT,
            CountryCodeGG,
            CountryCodeGN,
            CountryCodeGW,
            CountryCodeGY,
            CountryCodeHT,
            CountryCodeHM,
            CountryCodeVA,
            CountryCodeHN,
            CountryCodeHK,
            CountryCodeHU,
            CountryCodeIS,
            CountryCodeIN,
            CountryCodeID,
            CountryCodeIR,
            CountryCodeIQ,
            CountryCodeIE,
            CountryCodeIM,
            CountryCodeIL,
            CountryCodeIT,
            CountryCodeJM,
            CountryCodeJP,
            CountryCodeJE,
            CountryCodeJO,
            CountryCodeKZ,
            CountryCodeKE,
            CountryCodeKI,
            CountryCodeKP,
            CountryCodeKR,
            CountryCodeKW,
            CountryCodeKG,
            CountryCodeLA,
            CountryCodeLV,
            CountryCodeLB,
            CountryCodeLS,
            CountryCodeLR,
            CountryCodeLY,
            CountryCodeLI,
            CountryCodeLT,
            CountryCodeLU,
            CountryCodeMO,
            CountryCodeMK,
            CountryCodeMG,
            CountryCodeMW,
            CountryCodeMY,
            CountryCodeMV,
            CountryCodeML,
            CountryCodeMT,
            CountryCodeMH,
            CountryCodeMQ,
            CountryCodeMR,
            CountryCodeMU,
            CountryCodeYT,
            CountryCodeMX,
            CountryCodeFM,
            CountryCodeMD,
            CountryCodeMC,
            CountryCodeMN,
            CountryCodeME,
            CountryCodeMS,
            CountryCodeMA,
            CountryCodeMZ,
            CountryCodeMM,
            CountryCodeNA,
            CountryCodeNR,
            CountryCodeNP,
            CountryCodeNL,
            CountryCodeNC,
            CountryCodeNZ,
            CountryCodeNI,
            CountryCodeNE,
            CountryCodeNG,
            CountryCodeNU,
            CountryCodeNF,
            CountryCodeMP,
            CountryCodeNO,
            CountryCodeOM,
            CountryCodePK,
            CountryCodePW,
            CountryCodePS,
            CountryCodePA,
            CountryCodePG,
            CountryCodePY,
            CountryCodePE,
            CountryCodePH,
            CountryCodePN,
            CountryCodePL,
            CountryCodePT,
            CountryCodePR,
            CountryCodeQA,
            CountryCodeRE,
            CountryCodeRO,
            CountryCodeRU,
            CountryCodeRW,
            CountryCodeBL,
            CountryCodeSH,
            CountryCodeKN,
            CountryCodeLC,
            CountryCodeMF,
            CountryCodePM,
            CountryCodeVC,
            CountryCodeWS,
            CountryCodeSM,
            CountryCodeST,
            CountryCodeSA,
            CountryCodeSN,
            CountryCodeRS,
            CountryCodeSC,
            CountryCodeSL,
            CountryCodeSG,
            CountryCodeSX,
            CountryCodeSK,
            CountryCodeSI,
            CountryCodeSB,
            CountryCodeSO,
            CountryCodeZA,
            CountryCodeGS,
            CountryCodeSS,
            CountryCodeES,
            CountryCodeLK,
            CountryCodeSD,
            CountryCodeSR,
            CountryCodeSJ,
            CountryCodeSZ,
            CountryCodeSE,
            CountryCodeCH,
            CountryCodeSY,
            CountryCodeTW,
            CountryCodeTJ,
            CountryCodeTZ,
            CountryCodeTH,
            CountryCodeTL,
            CountryCodeTG,
            CountryCodeTK,
            CountryCodeTO,
            CountryCodeTT,
            CountryCodeTN,
            CountryCodeTR,
            CountryCodeTM,
            CountryCodeTC,
            CountryCodeTV,
            CountryCodeUG,
            CountryCodeUA,
            CountryCodeAE,
            CountryCodeGB,
            CountryCodeUS,
            CountryCodeUM,
            CountryCodeUY,
            CountryCodeUZ,
            CountryCodeVU,
            CountryCodeVE,
            CountryCodeVN,
            CountryCodeVG,
            CountryCodeVI,
            CountryCodeWF,
            CountryCodeEH,
            CountryCodeYE,
            CountryCodeZM,
            CountryCodeZW
        };

        void writeCountryCodeEnumJSON(CountryCode enumVal, PFStringJsonWriter& writer);
        CountryCode readCountryCodeFromValue(const rapidjson::Value& obj);

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
            std::string CharacterId;
            std::string PlayFabId;
            bool SaveCharacterInventory;

            DeleteCharacterFromUserRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                PlayFabId(),
                SaveCharacterInventory(false)
            {}

            DeleteCharacterFromUserRequest(const DeleteCharacterFromUserRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId),
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

        struct DeleteUsersRequest : public PlayFabBaseModel
        {
            std::list<std::string> PlayFabIds;
            std::string TitleId;

            DeleteUsersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                TitleId()
            {}

            DeleteUsersRequest(const DeleteUsersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                TitleId(src.TitleId)
            {}

            DeleteUsersRequest(const rapidjson::Value& obj) : DeleteUsersRequest()
            {
                readFromValue(obj);
            }

            ~DeleteUsersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteUsersResult : public PlayFabBaseModel
        {

            DeleteUsersResult() :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const DeleteUsersResult& src) :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const rapidjson::Value& obj) : DeleteUsersResult()
            {
                readFromValue(obj);
            }

            ~DeleteUsersResult();

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

        struct EvaluateRandomResultTableRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string TableId;

            EvaluateRandomResultTableRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                TableId()
            {}

            EvaluateRandomResultTableRequest(const EvaluateRandomResultTableRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                TableId(src.TableId)
            {}

            EvaluateRandomResultTableRequest(const rapidjson::Value& obj) : EvaluateRandomResultTableRequest()
            {
                readFromValue(obj);
            }

            ~EvaluateRandomResultTableRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EvaluateRandomResultTableResult : public PlayFabBaseModel
        {
            std::string ResultItemId;

            EvaluateRandomResultTableResult() :
                PlayFabBaseModel(),
                ResultItemId()
            {}

            EvaluateRandomResultTableResult(const EvaluateRandomResultTableResult& src) :
                PlayFabBaseModel(),
                ResultItemId(src.ResultItemId)
            {}

            EvaluateRandomResultTableResult(const rapidjson::Value& obj) : EvaluateRandomResultTableResult()
            {
                readFromValue(obj);
            }

            ~EvaluateRandomResultTableResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
            std::string Error;
            std::string Message;
            std::string StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ScriptExecutionError(const rapidjson::Value& obj) : ScriptExecutionError()
            {
                readFromValue(obj);
            }

            ~ScriptExecutionError();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LogStatement : public PlayFabBaseModel
        {
            MultitypeVar Data;
            std::string Level;
            std::string Message;

            LogStatement() :
                PlayFabBaseModel(),
                Data(),
                Level(),
                Message()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Level(src.Level),
                Message(src.Message)
            {}

            LogStatement(const rapidjson::Value& obj) : LogStatement()
            {
                readFromValue(obj);
            }

            ~LogStatement();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ExecuteCloudScriptResult : public PlayFabBaseModel
        {
            Int32 APIRequestsIssued;
            ScriptExecutionError* Error;
            double ExecutionTimeSeconds;
            std::string FunctionName;
            MultitypeVar FunctionResult;
            OptionalBool FunctionResultTooLarge;
            Int32 HttpRequestsIssued;
            std::list<LogStatement> Logs;
            OptionalBool LogsTooLarge;
            Uint32 MemoryConsumedBytes;
            double ProcessorTimeSeconds;
            Int32 Revision;

            ExecuteCloudScriptResult() :
                PlayFabBaseModel(),
                APIRequestsIssued(0),
                Error(NULL),
                ExecutionTimeSeconds(0),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge(),
                HttpRequestsIssued(0),
                Logs(),
                LogsTooLarge(),
                MemoryConsumedBytes(0),
                ProcessorTimeSeconds(0),
                Revision(0)
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabBaseModel(),
                APIRequestsIssued(src.APIRequestsIssued),
                Error(src.Error ? new ScriptExecutionError(*src.Error) : NULL),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                Revision(src.Revision)
            {}

            ExecuteCloudScriptResult(const rapidjson::Value& obj) : ExecuteCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ExecuteCloudScriptServerRequest : public PlayFabBaseModel
        {
            std::string FunctionName;
            MultitypeVar FunctionParameter;
            OptionalBool GeneratePlayStreamEvent;
            std::string PlayFabId;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            OptionalInt32 SpecificRevision;

            ExecuteCloudScriptServerRequest() :
                PlayFabBaseModel(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                PlayFabId(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteCloudScriptServerRequest(const ExecuteCloudScriptServerRequest& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                PlayFabId(src.PlayFabId),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ExecuteCloudScriptServerRequest(const rapidjson::Value& obj) : ExecuteCloudScriptServerRequest()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptServerRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FacebookPlayFabIdPair : public PlayFabBaseModel
        {
            std::string FacebookId;
            std::string PlayFabId;

            FacebookPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookId(),
                PlayFabId()
            {}

            FacebookPlayFabIdPair(const FacebookPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                PlayFabId(src.PlayFabId)
            {}

            FacebookPlayFabIdPair(const rapidjson::Value& obj) : FacebookPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~FacebookPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello
        };

        void writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer);
        LoginIdentityProvider readLoginIdentityProviderFromValue(const rapidjson::Value& obj);

        struct LinkedPlatformAccountModel : public PlayFabBaseModel
        {
            std::string Email;
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;

            LinkedPlatformAccountModel() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            LinkedPlatformAccountModel(const LinkedPlatformAccountModel& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            LinkedPlatformAccountModel(const rapidjson::Value& obj) : LinkedPlatformAccountModel()
            {
                readFromValue(obj);
            }

            ~LinkedPlatformAccountModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LocationModel : public PlayFabBaseModel
        {
            std::string City;
            Boxed<ContinentCode> pfContinentCode;
            Boxed<CountryCode> pfCountryCode;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            LocationModel() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            LocationModel(const LocationModel& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            LocationModel(const rapidjson::Value& obj) : LocationModel()
            {
                readFromValue(obj);
            }

            ~LocationModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum SubscriptionProviderStatus
        {
            SubscriptionProviderStatusNoError,
            SubscriptionProviderStatusCancelled,
            SubscriptionProviderStatusUnknownError,
            SubscriptionProviderStatusBillingError,
            SubscriptionProviderStatusProductUnavailable,
            SubscriptionProviderStatusCustomerDidNotAcceptPriceChange,
            SubscriptionProviderStatusFreeTrial,
            SubscriptionProviderStatusPaymentPending
        };

        void writeSubscriptionProviderStatusEnumJSON(SubscriptionProviderStatus enumVal, PFStringJsonWriter& writer);
        SubscriptionProviderStatus readSubscriptionProviderStatusFromValue(const rapidjson::Value& obj);

        struct SubscriptionModel : public PlayFabBaseModel
        {
            time_t Expiration;
            time_t InitialSubscriptionTime;
            bool IsActive;
            Boxed<SubscriptionProviderStatus> Status;
            std::string SubscriptionId;
            std::string SubscriptionItemId;
            std::string SubscriptionProvider;

            SubscriptionModel() :
                PlayFabBaseModel(),
                Expiration(0),
                InitialSubscriptionTime(0),
                IsActive(false),
                Status(),
                SubscriptionId(),
                SubscriptionItemId(),
                SubscriptionProvider()
            {}

            SubscriptionModel(const SubscriptionModel& src) :
                PlayFabBaseModel(),
                Expiration(src.Expiration),
                InitialSubscriptionTime(src.InitialSubscriptionTime),
                IsActive(src.IsActive),
                Status(src.Status),
                SubscriptionId(src.SubscriptionId),
                SubscriptionItemId(src.SubscriptionItemId),
                SubscriptionProvider(src.SubscriptionProvider)
            {}

            SubscriptionModel(const rapidjson::Value& obj) : SubscriptionModel()
            {
                readFromValue(obj);
            }

            ~SubscriptionModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct MembershipModel : public PlayFabBaseModel
        {
            bool IsActive;
            time_t MembershipExpiration;
            std::string MembershipId;
            OptionalTime OverrideExpiration;
            std::list<SubscriptionModel> Subscriptions;

            MembershipModel() :
                PlayFabBaseModel(),
                IsActive(false),
                MembershipExpiration(0),
                MembershipId(),
                OverrideExpiration(),
                Subscriptions()
            {}

            MembershipModel(const MembershipModel& src) :
                PlayFabBaseModel(),
                IsActive(src.IsActive),
                MembershipExpiration(src.MembershipExpiration),
                MembershipId(src.MembershipId),
                OverrideExpiration(src.OverrideExpiration),
                Subscriptions(src.Subscriptions)
            {}

            MembershipModel(const rapidjson::Value& obj) : MembershipModel()
            {
                readFromValue(obj);
            }

            ~MembershipModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PushNotificationRegistrationModel : public PlayFabBaseModel
        {
            std::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistrationModel() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistrationModel(const PushNotificationRegistrationModel& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            PushNotificationRegistrationModel(const rapidjson::Value& obj) : PushNotificationRegistrationModel()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistrationModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StatisticModel : public PlayFabBaseModel
        {
            std::string Name;
            Int32 Value;
            Int32 Version;

            StatisticModel() :
                PlayFabBaseModel(),
                Name(),
                Value(0),
                Version(0)
            {}

            StatisticModel(const StatisticModel& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticModel(const rapidjson::Value& obj) : StatisticModel()
            {
                readFromValue(obj);
            }

            ~StatisticModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct TagModel : public PlayFabBaseModel
        {
            std::string TagValue;

            TagModel() :
                PlayFabBaseModel(),
                TagValue()
            {}

            TagModel(const TagModel& src) :
                PlayFabBaseModel(),
                TagValue(src.TagValue)
            {}

            TagModel(const rapidjson::Value& obj) : TagModel()
            {
                readFromValue(obj);
            }

            ~TagModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValueToDateModel : public PlayFabBaseModel
        {
            std::string Currency;
            Uint32 TotalValue;
            std::string TotalValueAsDecimal;

            ValueToDateModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(0),
                TotalValueAsDecimal()
            {}

            ValueToDateModel(const ValueToDateModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue),
                TotalValueAsDecimal(src.TotalValueAsDecimal)
            {}

            ValueToDateModel(const rapidjson::Value& obj) : ValueToDateModel()
            {
                readFromValue(obj);
            }

            ~ValueToDateModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct VirtualCurrencyBalanceModel : public PlayFabBaseModel
        {
            std::string Currency;
            Int32 TotalValue;

            VirtualCurrencyBalanceModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(0)
            {}

            VirtualCurrencyBalanceModel(const VirtualCurrencyBalanceModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue)
            {}

            VirtualCurrencyBalanceModel(const rapidjson::Value& obj) : VirtualCurrencyBalanceModel()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyBalanceModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerProfileModel : public PlayFabBaseModel
        {
            std::list<AdCampaignAttributionModel> AdCampaignAttributions;
            std::string AvatarUrl;
            OptionalTime BannedUntil;
            std::list<ContactEmailInfoModel> ContactEmailAddresses;
            OptionalTime Created;
            std::string DisplayName;
            OptionalTime LastLogin;
            std::list<LinkedPlatformAccountModel> LinkedAccounts;
            std::list<LocationModel> Locations;
            std::list<MembershipModel> Memberships;
            Boxed<LoginIdentityProvider> Origination;
            std::string PlayerId;
            std::string PublisherId;
            std::list<PushNotificationRegistrationModel> PushNotificationRegistrations;
            std::list<StatisticModel> Statistics;
            std::list<TagModel> Tags;
            std::string TitleId;
            OptionalUint32 TotalValueToDateInUSD;
            std::list<ValueToDateModel> ValuesToDate;
            std::list<VirtualCurrencyBalanceModel> VirtualCurrencyBalances;

            PlayerProfileModel() :
                PlayFabBaseModel(),
                AdCampaignAttributions(),
                AvatarUrl(),
                BannedUntil(),
                ContactEmailAddresses(),
                Created(),
                DisplayName(),
                LastLogin(),
                LinkedAccounts(),
                Locations(),
                Memberships(),
                Origination(),
                PlayerId(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                VirtualCurrencyBalances()
            {}

            PlayerProfileModel(const PlayerProfileModel& src) :
                PlayFabBaseModel(),
                AdCampaignAttributions(src.AdCampaignAttributions),
                AvatarUrl(src.AvatarUrl),
                BannedUntil(src.BannedUntil),
                ContactEmailAddresses(src.ContactEmailAddresses),
                Created(src.Created),
                DisplayName(src.DisplayName),
                LastLogin(src.LastLogin),
                LinkedAccounts(src.LinkedAccounts),
                Locations(src.Locations),
                Memberships(src.Memberships),
                Origination(src.Origination),
                PlayerId(src.PlayerId),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            PlayerProfileModel(const rapidjson::Value& obj) : PlayerProfileModel()
            {
                readFromValue(obj);
            }

            ~PlayerProfileModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FriendInfo : public PlayFabBaseModel
        {
            std::string CurrentMatchmakerLobbyId;
            UserFacebookInfo* FacebookInfo;
            std::string FriendPlayFabId;
            UserGameCenterInfo* GameCenterInfo;
            PlayerProfileModel* Profile;
            UserSteamInfo* SteamInfo;
            std::list<std::string> Tags;
            std::string TitleDisplayName;
            std::string Username;

            FriendInfo() :
                PlayFabBaseModel(),
                CurrentMatchmakerLobbyId(),
                FacebookInfo(NULL),
                FriendPlayFabId(),
                GameCenterInfo(NULL),
                Profile(NULL),
                SteamInfo(NULL),
                Tags(),
                TitleDisplayName(),
                Username()
            {}

            FriendInfo(const FriendInfo& src) :
                PlayFabBaseModel(),
                CurrentMatchmakerLobbyId(src.CurrentMatchmakerLobbyId),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : NULL),
                FriendPlayFabId(src.FriendPlayFabId),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : NULL),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : NULL),
                Tags(src.Tags),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            FriendInfo(const rapidjson::Value& obj) : FriendInfo()
            {
                readFromValue(obj);
            }

            ~FriendInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum GameInstanceState
        {
            GameInstanceStateOpen,
            GameInstanceStateClosed
        };

        void writeGameInstanceStateEnumJSON(GameInstanceState enumVal, PFStringJsonWriter& writer);
        GameInstanceState readGameInstanceStateFromValue(const rapidjson::Value& obj);

        // Deprecated - Do not use
        struct GetActionGroupResult : public PlayFabBaseModel
        {
            std::string Id;
            std::string Name;

            GetActionGroupResult() :
                PlayFabBaseModel(),
                Id(),
                Name()
            {}

            GetActionGroupResult(const GetActionGroupResult& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name)
            {}

            GetActionGroupResult(const rapidjson::Value& obj) : GetActionGroupResult()
            {
                readFromValue(obj);
            }

            ~GetActionGroupResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        // Deprecated - Do not use
        struct GetAllActionGroupsRequest : public PlayFabBaseModel
        {

            GetAllActionGroupsRequest() :
                PlayFabBaseModel()
            {}

            GetAllActionGroupsRequest(const GetAllActionGroupsRequest& src) :
                PlayFabBaseModel()
            {}

            GetAllActionGroupsRequest(const rapidjson::Value& obj) : GetAllActionGroupsRequest()
            {
                readFromValue(obj);
            }

            ~GetAllActionGroupsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        // Deprecated - Do not use
        struct GetAllActionGroupsResult : public PlayFabBaseModel
        {
            std::list<GetActionGroupResult> ActionGroups;

            GetAllActionGroupsResult() :
                PlayFabBaseModel(),
                ActionGroups()
            {}

            GetAllActionGroupsResult(const GetAllActionGroupsResult& src) :
                PlayFabBaseModel(),
                ActionGroups(src.ActionGroups)
            {}

            GetAllActionGroupsResult(const rapidjson::Value& obj) : GetAllActionGroupsResult()
            {
                readFromValue(obj);
            }

            ~GetAllActionGroupsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAllSegmentsRequest : public PlayFabBaseModel
        {

            GetAllSegmentsRequest() :
                PlayFabBaseModel()
            {}

            GetAllSegmentsRequest(const GetAllSegmentsRequest& src) :
                PlayFabBaseModel()
            {}

            GetAllSegmentsRequest(const rapidjson::Value& obj) : GetAllSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetAllSegmentsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetSegmentResult : public PlayFabBaseModel
        {
            std::string ABTestParent;
            std::string Id;
            std::string Name;

            GetSegmentResult() :
                PlayFabBaseModel(),
                ABTestParent(),
                Id(),
                Name()
            {}

            GetSegmentResult(const GetSegmentResult& src) :
                PlayFabBaseModel(),
                ABTestParent(src.ABTestParent),
                Id(src.Id),
                Name(src.Name)
            {}

            GetSegmentResult(const rapidjson::Value& obj) : GetSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetSegmentResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAllSegmentsResult : public PlayFabBaseModel
        {
            std::list<GetSegmentResult> Segments;

            GetAllSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetAllSegmentsResult(const GetAllSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetAllSegmentsResult(const rapidjson::Value& obj) : GetAllSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetAllSegmentsResult();

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
            std::string CharacterId;
            OptionalUint32 IfChangedFromDataVersion;
            std::list<std::string> Keys;
            std::string PlayFabId;

            GetCharacterDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetCharacterDataRequest(const GetCharacterDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
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
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;
            std::string Value;

            UserDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(0),
                Permission(),
                Value()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission),
                Value(src.Value)
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
            Uint32 DataVersion;
            std::string PlayFabId;

            GetCharacterDataResult() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                DataVersion(0),
                PlayFabId()
            {}

            GetCharacterDataResult(const GetCharacterDataResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                DataVersion(src.DataVersion),
                PlayFabId(src.PlayFabId)
            {}

            GetCharacterDataResult(const rapidjson::Value& obj) : GetCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterInventoryRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string PlayFabId;

            GetCharacterInventoryRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                PlayFabId()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId)
            {}

            GetCharacterInventoryRequest(const rapidjson::Value& obj) : GetCharacterInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryRequest();

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

        struct GetCharacterInventoryResult : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::list<ItemInstance> Inventory;
            std::string PlayFabId;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory(),
                PlayFabId(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetCharacterInventoryResult(const rapidjson::Value& obj) : GetCharacterInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterLeaderboardRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string CharacterType;
            Int32 MaxResultsCount;
            Int32 StartPosition;
            std::string StatisticName;

            GetCharacterLeaderboardRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(0),
                StartPosition(0),
                StatisticName()
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName)
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
            std::string CharacterId;
            std::string PlayFabId;

            GetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                PlayFabId()
            {}

            GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId)
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
            std::string CharacterId;
            std::map<std::string, Int32> CharacterStatistics;
            std::string PlayFabId;

            GetCharacterStatisticsResult() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterStatistics(),
                PlayFabId()
            {}

            GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics),
                PlayFabId(src.PlayFabId)
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
            std::string HttpMethod;
            std::string Key;
            OptionalBool ThruCDN;

            GetContentDownloadUrlRequest() :
                PlayFabBaseModel(),
                HttpMethod(),
                Key(),
                ThruCDN()
            {}

            GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
                PlayFabBaseModel(),
                HttpMethod(src.HttpMethod),
                Key(src.Key),
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

        struct PlayerProfileViewConstraints : public PlayFabBaseModel
        {
            bool ShowAvatarUrl;
            bool ShowBannedUntil;
            bool ShowCampaignAttributions;
            bool ShowContactEmailAddresses;
            bool ShowCreated;
            bool ShowDisplayName;
            bool ShowLastLogin;
            bool ShowLinkedAccounts;
            bool ShowLocations;
            bool ShowMemberships;
            bool ShowOrigination;
            bool ShowPushNotificationRegistrations;
            bool ShowStatistics;
            bool ShowTags;
            bool ShowTotalValueToDateInUsd;
            bool ShowValuesToDate;

            PlayerProfileViewConstraints() :
                PlayFabBaseModel(),
                ShowAvatarUrl(false),
                ShowBannedUntil(false),
                ShowCampaignAttributions(false),
                ShowContactEmailAddresses(false),
                ShowCreated(false),
                ShowDisplayName(false),
                ShowLastLogin(false),
                ShowLinkedAccounts(false),
                ShowLocations(false),
                ShowMemberships(false),
                ShowOrigination(false),
                ShowPushNotificationRegistrations(false),
                ShowStatistics(false),
                ShowTags(false),
                ShowTotalValueToDateInUsd(false),
                ShowValuesToDate(false)
            {}

            PlayerProfileViewConstraints(const PlayerProfileViewConstraints& src) :
                PlayFabBaseModel(),
                ShowAvatarUrl(src.ShowAvatarUrl),
                ShowBannedUntil(src.ShowBannedUntil),
                ShowCampaignAttributions(src.ShowCampaignAttributions),
                ShowContactEmailAddresses(src.ShowContactEmailAddresses),
                ShowCreated(src.ShowCreated),
                ShowDisplayName(src.ShowDisplayName),
                ShowLastLogin(src.ShowLastLogin),
                ShowLinkedAccounts(src.ShowLinkedAccounts),
                ShowLocations(src.ShowLocations),
                ShowMemberships(src.ShowMemberships),
                ShowOrigination(src.ShowOrigination),
                ShowPushNotificationRegistrations(src.ShowPushNotificationRegistrations),
                ShowStatistics(src.ShowStatistics),
                ShowTags(src.ShowTags),
                ShowTotalValueToDateInUsd(src.ShowTotalValueToDateInUsd),
                ShowValuesToDate(src.ShowValuesToDate)
            {}

            PlayerProfileViewConstraints(const rapidjson::Value& obj) : PlayerProfileViewConstraints()
            {
                readFromValue(obj);
            }

            ~PlayerProfileViewConstraints();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendLeaderboardRequest : public PlayFabBaseModel
        {
            OptionalBool IncludeFacebookFriends;
            OptionalBool IncludeSteamFriends;
            Int32 MaxResultsCount;
            std::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            OptionalInt32 Version;

            GetFriendLeaderboardRequest() :
                PlayFabBaseModel(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(0),
                PlayFabId(),
                ProfileConstraints(NULL),
                StartPosition(0),
                StatisticName(),
                Version()
            {}

            GetFriendLeaderboardRequest(const GetFriendLeaderboardRequest& src) :
                PlayFabBaseModel(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            GetFriendLeaderboardRequest(const rapidjson::Value& obj) : GetFriendLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendsListRequest : public PlayFabBaseModel
        {
            OptionalBool IncludeFacebookFriends;
            OptionalBool IncludeSteamFriends;
            std::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetFriendsListRequest() :
                PlayFabBaseModel(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                PlayFabId(),
                ProfileConstraints(NULL)
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabBaseModel(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL)
            {}

            GetFriendsListRequest(const rapidjson::Value& obj) : GetFriendsListRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendsListRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendsListResult : public PlayFabBaseModel
        {
            std::list<FriendInfo> Friends;

            GetFriendsListResult() :
                PlayFabBaseModel(),
                Friends()
            {}

            GetFriendsListResult(const GetFriendsListResult& src) :
                PlayFabBaseModel(),
                Friends(src.Friends)
            {}

            GetFriendsListResult(const rapidjson::Value& obj) : GetFriendsListResult()
            {
                readFromValue(obj);
            }

            ~GetFriendsListResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardAroundCharacterRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string CharacterType;
            Int32 MaxResultsCount;
            std::string PlayFabId;
            std::string StatisticName;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(0),
                PlayFabId(),
                StatisticName()
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                StatisticName(src.StatisticName)
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
            Int32 MaxResultsCount;
            std::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;
            std::string StatisticName;
            OptionalInt32 Version;

            GetLeaderboardAroundUserRequest() :
                PlayFabBaseModel(),
                MaxResultsCount(0),
                PlayFabId(),
                ProfileConstraints(NULL),
                StatisticName(),
                Version()
            {}

            GetLeaderboardAroundUserRequest(const GetLeaderboardAroundUserRequest& src) :
                PlayFabBaseModel(),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                StatisticName(src.StatisticName),
                Version(src.Version)
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
            std::string DisplayName;
            std::string PlayFabId;
            Int32 Position;
            PlayerProfileModel* Profile;
            Int32 StatValue;

            PlayerLeaderboardEntry() :
                PlayFabBaseModel(),
                DisplayName(),
                PlayFabId(),
                Position(0),
                Profile(NULL),
                StatValue(0)
            {}

            PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : NULL),
                StatValue(src.StatValue)
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
            OptionalTime NextReset;
            Int32 Version;

            GetLeaderboardAroundUserResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                NextReset(),
                Version(0)
            {}

            GetLeaderboardAroundUserResult(const GetLeaderboardAroundUserResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
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
            Int32 MaxResultsCount;
            std::string PlayFabId;
            std::string StatisticName;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabBaseModel(),
                MaxResultsCount(0),
                PlayFabId(),
                StatisticName()
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                StatisticName(src.StatisticName)
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
            Int32 MaxResultsCount;
            PlayerProfileViewConstraints* ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            OptionalInt32 Version;

            GetLeaderboardRequest() :
                PlayFabBaseModel(),
                MaxResultsCount(0),
                ProfileConstraints(NULL),
                StartPosition(0),
                StatisticName(),
                Version()
            {}

            GetLeaderboardRequest(const GetLeaderboardRequest& src) :
                PlayFabBaseModel(),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version)
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
            OptionalTime NextReset;
            Int32 Version;

            GetLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                NextReset(),
                Version(0)
            {}

            GetLeaderboardResult(const GetLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            GetLeaderboardResult(const rapidjson::Value& obj) : GetLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerCombinedInfoRequestParams : public PlayFabBaseModel
        {
            bool GetCharacterInventories;
            bool GetCharacterList;
            bool GetPlayerProfile;
            bool GetPlayerStatistics;
            bool GetTitleData;
            bool GetUserAccountInfo;
            bool GetUserData;
            bool GetUserInventory;
            bool GetUserReadOnlyData;
            bool GetUserVirtualCurrency;
            std::list<std::string> PlayerStatisticNames;
            PlayerProfileViewConstraints* ProfileConstraints;
            std::list<std::string> TitleDataKeys;
            std::list<std::string> UserDataKeys;
            std::list<std::string> UserReadOnlyDataKeys;

            GetPlayerCombinedInfoRequestParams() :
                PlayFabBaseModel(),
                GetCharacterInventories(false),
                GetCharacterList(false),
                GetPlayerProfile(false),
                GetPlayerStatistics(false),
                GetTitleData(false),
                GetUserAccountInfo(false),
                GetUserData(false),
                GetUserInventory(false),
                GetUserReadOnlyData(false),
                GetUserVirtualCurrency(false),
                PlayerStatisticNames(),
                ProfileConstraints(NULL),
                TitleDataKeys(),
                UserDataKeys(),
                UserReadOnlyDataKeys()
            {}

            GetPlayerCombinedInfoRequestParams(const GetPlayerCombinedInfoRequestParams& src) :
                PlayFabBaseModel(),
                GetCharacterInventories(src.GetCharacterInventories),
                GetCharacterList(src.GetCharacterList),
                GetPlayerProfile(src.GetPlayerProfile),
                GetPlayerStatistics(src.GetPlayerStatistics),
                GetTitleData(src.GetTitleData),
                GetUserAccountInfo(src.GetUserAccountInfo),
                GetUserData(src.GetUserData),
                GetUserInventory(src.GetUserInventory),
                GetUserReadOnlyData(src.GetUserReadOnlyData),
                GetUserVirtualCurrency(src.GetUserVirtualCurrency),
                PlayerStatisticNames(src.PlayerStatisticNames),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                TitleDataKeys(src.TitleDataKeys),
                UserDataKeys(src.UserDataKeys),
                UserReadOnlyDataKeys(src.UserReadOnlyDataKeys)
            {}

            GetPlayerCombinedInfoRequestParams(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequestParams()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequestParams();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerCombinedInfoRequest : public PlayFabBaseModel
        {
            GetPlayerCombinedInfoRequestParams InfoRequestParameters;
            std::string PlayFabId;

            GetPlayerCombinedInfoRequest() :
                PlayFabBaseModel(),
                InfoRequestParameters(),
                PlayFabId()
            {}

            GetPlayerCombinedInfoRequest(const GetPlayerCombinedInfoRequest& src) :
                PlayFabBaseModel(),
                InfoRequestParameters(src.InfoRequestParameters),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerCombinedInfoRequest(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StatisticValue : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 Value;
            Uint32 Version;

            StatisticValue() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version(0)
            {}

            StatisticValue(const StatisticValue& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticValue(const rapidjson::Value& obj) : StatisticValue()
            {
                readFromValue(obj);
            }

            ~StatisticValue();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerCombinedInfoResultPayload : public PlayFabBaseModel
        {
            UserAccountInfo* AccountInfo;
            std::list<CharacterInventory> CharacterInventories;
            std::list<CharacterResult> CharacterList;
            PlayerProfileModel* PlayerProfile;
            std::list<StatisticValue> PlayerStatistics;
            std::map<std::string, std::string> TitleData;
            std::map<std::string, UserDataRecord> UserData;
            Uint32 UserDataVersion;
            std::list<ItemInstance> UserInventory;
            std::map<std::string, UserDataRecord> UserReadOnlyData;
            Uint32 UserReadOnlyDataVersion;
            std::map<std::string, Int32> UserVirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> UserVirtualCurrencyRechargeTimes;

            GetPlayerCombinedInfoResultPayload() :
                PlayFabBaseModel(),
                AccountInfo(NULL),
                CharacterInventories(),
                CharacterList(),
                PlayerProfile(NULL),
                PlayerStatistics(),
                TitleData(),
                UserData(),
                UserDataVersion(0),
                UserInventory(),
                UserReadOnlyData(),
                UserReadOnlyDataVersion(0),
                UserVirtualCurrency(),
                UserVirtualCurrencyRechargeTimes()
            {}

            GetPlayerCombinedInfoResultPayload(const GetPlayerCombinedInfoResultPayload& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : NULL),
                CharacterInventories(src.CharacterInventories),
                CharacterList(src.CharacterList),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : NULL),
                PlayerStatistics(src.PlayerStatistics),
                TitleData(src.TitleData),
                UserData(src.UserData),
                UserDataVersion(src.UserDataVersion),
                UserInventory(src.UserInventory),
                UserReadOnlyData(src.UserReadOnlyData),
                UserReadOnlyDataVersion(src.UserReadOnlyDataVersion),
                UserVirtualCurrency(src.UserVirtualCurrency),
                UserVirtualCurrencyRechargeTimes(src.UserVirtualCurrencyRechargeTimes)
            {}

            GetPlayerCombinedInfoResultPayload(const rapidjson::Value& obj) : GetPlayerCombinedInfoResultPayload()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResultPayload();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerCombinedInfoResult : public PlayFabBaseModel
        {
            GetPlayerCombinedInfoResultPayload* InfoResultPayload;
            std::string PlayFabId;

            GetPlayerCombinedInfoResult() :
                PlayFabBaseModel(),
                InfoResultPayload(NULL),
                PlayFabId()
            {}

            GetPlayerCombinedInfoResult(const GetPlayerCombinedInfoResult& src) :
                PlayFabBaseModel(),
                InfoResultPayload(src.InfoResultPayload ? new GetPlayerCombinedInfoResultPayload(*src.InfoResultPayload) : NULL),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerCombinedInfoResult(const rapidjson::Value& obj) : GetPlayerCombinedInfoResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerProfileRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetPlayerProfileRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                ProfileConstraints(NULL)
            {}

            GetPlayerProfileRequest(const GetPlayerProfileRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL)
            {}

            GetPlayerProfileRequest(const rapidjson::Value& obj) : GetPlayerProfileRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerProfileResult : public PlayFabBaseModel
        {
            PlayerProfileModel* PlayerProfile;

            GetPlayerProfileResult() :
                PlayFabBaseModel(),
                PlayerProfile(NULL)
            {}

            GetPlayerProfileResult(const GetPlayerProfileResult& src) :
                PlayFabBaseModel(),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : NULL)
            {}

            GetPlayerProfileResult(const rapidjson::Value& obj) : GetPlayerProfileResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerSegmentsResult : public PlayFabBaseModel
        {
            std::list<GetSegmentResult> Segments;

            GetPlayerSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetPlayerSegmentsResult(const GetPlayerSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetPlayerSegmentsResult(const rapidjson::Value& obj) : GetPlayerSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerSegmentsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayersInSegmentRequest : public PlayFabBaseModel
        {
            std::string ContinuationToken;
            OptionalUint32 MaxBatchSize;
            OptionalUint32 SecondsToLive;
            std::string SegmentId;

            GetPlayersInSegmentRequest() :
                PlayFabBaseModel(),
                ContinuationToken(),
                MaxBatchSize(),
                SecondsToLive(),
                SegmentId()
            {}

            GetPlayersInSegmentRequest(const GetPlayersInSegmentRequest& src) :
                PlayFabBaseModel(),
                ContinuationToken(src.ContinuationToken),
                MaxBatchSize(src.MaxBatchSize),
                SecondsToLive(src.SecondsToLive),
                SegmentId(src.SegmentId)
            {}

            GetPlayersInSegmentRequest(const rapidjson::Value& obj) : GetPlayersInSegmentRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLinkedAccount : public PlayFabBaseModel
        {
            std::string Email;
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;

            PlayerLinkedAccount() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            PlayerLinkedAccount(const PlayerLinkedAccount& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            PlayerLinkedAccount(const rapidjson::Value& obj) : PlayerLinkedAccount()
            {
                readFromValue(obj);
            }

            ~PlayerLinkedAccount();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLocation : public PlayFabBaseModel
        {
            std::string City;
            ContinentCode pfContinentCode;
            CountryCode pfCountryCode;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            PlayerLocation() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            PlayerLocation(const PlayerLocation& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            PlayerLocation(const rapidjson::Value& obj) : PlayerLocation()
            {
                readFromValue(obj);
            }

            ~PlayerLocation();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerStatistic : public PlayFabBaseModel
        {
            std::string Id;
            std::string Name;
            Int32 StatisticValue;
            Int32 StatisticVersion;

            PlayerStatistic() :
                PlayFabBaseModel(),
                Id(),
                Name(),
                StatisticValue(0),
                StatisticVersion(0)
            {}

            PlayerStatistic(const PlayerStatistic& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name),
                StatisticValue(src.StatisticValue),
                StatisticVersion(src.StatisticVersion)
            {}

            PlayerStatistic(const rapidjson::Value& obj) : PlayerStatistic()
            {
                readFromValue(obj);
            }

            ~PlayerStatistic();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PushNotificationRegistration : public PlayFabBaseModel
        {
            std::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistration() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistration(const PushNotificationRegistration& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            PushNotificationRegistration(const rapidjson::Value& obj) : PushNotificationRegistration()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistration();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerProfile : public PlayFabBaseModel
        {
            std::list<AdCampaignAttribution> AdCampaignAttributions;
            std::string AvatarUrl;
            OptionalTime BannedUntil;
            std::list<ContactEmailInfo> ContactEmailAddresses;
            OptionalTime Created;
            std::string DisplayName;
            OptionalTime LastLogin;
            std::list<PlayerLinkedAccount> LinkedAccounts;
            std::map<std::string, PlayerLocation> Locations;
            Boxed<LoginIdentityProvider> Origination;
            std::string PlayerId;
            std::list<PlayerStatistic> PlayerStatistics;
            std::string PublisherId;
            std::list<PushNotificationRegistration> PushNotificationRegistrations;
            std::map<std::string, Int32> Statistics;
            std::list<std::string> Tags;
            std::string TitleId;
            OptionalUint32 TotalValueToDateInUSD;
            std::map<std::string, Uint32> ValuesToDate;
            std::map<std::string, Int32> VirtualCurrencyBalances;

            PlayerProfile() :
                PlayFabBaseModel(),
                AdCampaignAttributions(),
                AvatarUrl(),
                BannedUntil(),
                ContactEmailAddresses(),
                Created(),
                DisplayName(),
                LastLogin(),
                LinkedAccounts(),
                Locations(),
                Origination(),
                PlayerId(),
                PlayerStatistics(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                VirtualCurrencyBalances()
            {}

            PlayerProfile(const PlayerProfile& src) :
                PlayFabBaseModel(),
                AdCampaignAttributions(src.AdCampaignAttributions),
                AvatarUrl(src.AvatarUrl),
                BannedUntil(src.BannedUntil),
                ContactEmailAddresses(src.ContactEmailAddresses),
                Created(src.Created),
                DisplayName(src.DisplayName),
                LastLogin(src.LastLogin),
                LinkedAccounts(src.LinkedAccounts),
                Locations(src.Locations),
                Origination(src.Origination),
                PlayerId(src.PlayerId),
                PlayerStatistics(src.PlayerStatistics),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            PlayerProfile(const rapidjson::Value& obj) : PlayerProfile()
            {
                readFromValue(obj);
            }

            ~PlayerProfile();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayersInSegmentResult : public PlayFabBaseModel
        {
            std::string ContinuationToken;
            std::list<PlayerProfile> PlayerProfiles;
            Int32 ProfilesInSegment;

            GetPlayersInSegmentResult() :
                PlayFabBaseModel(),
                ContinuationToken(),
                PlayerProfiles(),
                ProfilesInSegment(0)
            {}

            GetPlayersInSegmentResult(const GetPlayersInSegmentResult& src) :
                PlayFabBaseModel(),
                ContinuationToken(src.ContinuationToken),
                PlayerProfiles(src.PlayerProfiles),
                ProfilesInSegment(src.ProfilesInSegment)
            {}

            GetPlayersInSegmentResult(const rapidjson::Value& obj) : GetPlayersInSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayersSegmentsRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            GetPlayersSegmentsRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetPlayersSegmentsRequest(const GetPlayersSegmentsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayersSegmentsRequest(const rapidjson::Value& obj) : GetPlayersSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersSegmentsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StatisticNameVersion : public PlayFabBaseModel
        {
            std::string StatisticName;
            Uint32 Version;

            StatisticNameVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0)
            {}

            StatisticNameVersion(const StatisticNameVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            StatisticNameVersion(const rapidjson::Value& obj) : StatisticNameVersion()
            {
                readFromValue(obj);
            }

            ~StatisticNameVersion();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticsRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::list<std::string> StatisticNames;
            std::list<StatisticNameVersion> StatisticNameVersions;

            GetPlayerStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                StatisticNames(),
                StatisticNameVersions()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                StatisticNames(src.StatisticNames),
                StatisticNameVersions(src.StatisticNameVersions)
            {}

            GetPlayerStatisticsRequest(const rapidjson::Value& obj) : GetPlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticsResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::list<StatisticValue> Statistics;

            GetPlayerStatisticsResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Statistics()
            {}

            GetPlayerStatisticsResult(const GetPlayerStatisticsResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Statistics(src.Statistics)
            {}

            GetPlayerStatisticsResult(const rapidjson::Value& obj) : GetPlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticVersionsRequest : public PlayFabBaseModel
        {
            std::string StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName)
            {}

            GetPlayerStatisticVersionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            time_t ActivationTime;
            OptionalTime DeactivationTime;
            OptionalTime ScheduledActivationTime;
            OptionalTime ScheduledDeactivationTime;
            std::string StatisticName;
            Uint32 Version;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                ActivationTime(0),
                DeactivationTime(),
                ScheduledActivationTime(),
                ScheduledDeactivationTime(),
                StatisticName(),
                Version(0)
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                ActivationTime(src.ActivationTime),
                DeactivationTime(src.DeactivationTime),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            PlayerStatisticVersion(const rapidjson::Value& obj) : PlayerStatisticVersion()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticVersion();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabBaseModel
        {
            std::list<PlayerStatisticVersion> StatisticVersions;

            GetPlayerStatisticVersionsResult() :
                PlayFabBaseModel(),
                StatisticVersions()
            {}

            GetPlayerStatisticVersionsResult(const GetPlayerStatisticVersionsResult& src) :
                PlayFabBaseModel(),
                StatisticVersions(src.StatisticVersions)
            {}

            GetPlayerStatisticVersionsResult(const rapidjson::Value& obj) : GetPlayerStatisticVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerTagsRequest : public PlayFabBaseModel
        {
            std::string Namespace;
            std::string PlayFabId;

            GetPlayerTagsRequest() :
                PlayFabBaseModel(),
                Namespace(),
                PlayFabId()
            {}

            GetPlayerTagsRequest(const GetPlayerTagsRequest& src) :
                PlayFabBaseModel(),
                Namespace(src.Namespace),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerTagsRequest(const rapidjson::Value& obj) : GetPlayerTagsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerTagsResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::list<std::string> Tags;

            GetPlayerTagsResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Tags()
            {}

            GetPlayerTagsResult(const GetPlayerTagsResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            GetPlayerTagsResult(const rapidjson::Value& obj) : GetPlayerTagsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromFacebookIDsRequest : public PlayFabBaseModel
        {
            std::list<std::string> FacebookIDs;

            GetPlayFabIDsFromFacebookIDsRequest() :
                PlayFabBaseModel(),
                FacebookIDs()
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const GetPlayFabIDsFromFacebookIDsRequest& src) :
                PlayFabBaseModel(),
                FacebookIDs(src.FacebookIDs)
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromFacebookIDsResult : public PlayFabBaseModel
        {
            std::list<FacebookPlayFabIdPair> Data;

            GetPlayFabIDsFromFacebookIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromFacebookIDsResult(const GetPlayFabIDsFromFacebookIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromFacebookIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromSteamIDsRequest : public PlayFabBaseModel
        {
            std::list<std::string> SteamStringIDs;

            GetPlayFabIDsFromSteamIDsRequest() :
                PlayFabBaseModel(),
                SteamStringIDs()
            {}

            GetPlayFabIDsFromSteamIDsRequest(const GetPlayFabIDsFromSteamIDsRequest& src) :
                PlayFabBaseModel(),
                SteamStringIDs(src.SteamStringIDs)
            {}

            GetPlayFabIDsFromSteamIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SteamPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string SteamStringId;

            SteamPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                SteamStringId()
            {}

            SteamPlayFabIdPair(const SteamPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                SteamStringId(src.SteamStringId)
            {}

            SteamPlayFabIdPair(const rapidjson::Value& obj) : SteamPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~SteamPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromSteamIDsResult : public PlayFabBaseModel
        {
            std::list<SteamPlayFabIdPair> Data;

            GetPlayFabIDsFromSteamIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromSteamIDsResult(const GetPlayFabIDsFromSteamIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromSteamIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsResult();

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

        struct GetRandomResultTablesRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::list<std::string> TableIDs;

            GetRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                TableIDs()
            {}

            GetRandomResultTablesRequest(const GetRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                TableIDs(src.TableIDs)
            {}

            GetRandomResultTablesRequest(const rapidjson::Value& obj) : GetRandomResultTablesRequest()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        void writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer);
        ResultTableNodeType readResultTableNodeTypeFromValue(const rapidjson::Value& obj);

        struct ResultTableNode : public PlayFabBaseModel
        {
            std::string ResultItem;
            ResultTableNodeType ResultItemType;
            Int32 Weight;

            ResultTableNode() :
                PlayFabBaseModel(),
                ResultItem(),
                ResultItemType(),
                Weight(0)
            {}

            ResultTableNode(const ResultTableNode& src) :
                PlayFabBaseModel(),
                ResultItem(src.ResultItem),
                ResultItemType(src.ResultItemType),
                Weight(src.Weight)
            {}

            ResultTableNode(const rapidjson::Value& obj) : ResultTableNode()
            {
                readFromValue(obj);
            }

            ~ResultTableNode();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RandomResultTableListing : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::list<ResultTableNode> Nodes;
            std::string TableId;

            RandomResultTableListing() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Nodes(),
                TableId()
            {}

            RandomResultTableListing(const RandomResultTableListing& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                Nodes(src.Nodes),
                TableId(src.TableId)
            {}

            RandomResultTableListing(const rapidjson::Value& obj) : RandomResultTableListing()
            {
                readFromValue(obj);
            }

            ~RandomResultTableListing();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetRandomResultTablesResult : public PlayFabBaseModel
        {
            std::map<std::string, RandomResultTableListing> Tables;

            GetRandomResultTablesResult() :
                PlayFabBaseModel(),
                Tables()
            {}

            GetRandomResultTablesResult(const GetRandomResultTablesResult& src) :
                PlayFabBaseModel(),
                Tables(src.Tables)
            {}

            GetRandomResultTablesResult(const rapidjson::Value& obj) : GetRandomResultTablesResult()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetSharedGroupDataRequest : public PlayFabBaseModel
        {
            OptionalBool GetMembers;
            std::list<std::string> Keys;
            std::string SharedGroupId;

            GetSharedGroupDataRequest() :
                PlayFabBaseModel(),
                GetMembers(),
                Keys(),
                SharedGroupId()
            {}

            GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                GetMembers(src.GetMembers),
                Keys(src.Keys),
                SharedGroupId(src.SharedGroupId)
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
            time_t LastUpdated;
            std::string LastUpdatedBy;
            Boxed<UserDataPermission> Permission;
            std::string Value;

            SharedGroupDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(0),
                LastUpdatedBy(),
                Permission(),
                Value()
            {}

            SharedGroupDataRecord(const SharedGroupDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                LastUpdatedBy(src.LastUpdatedBy),
                Permission(src.Permission),
                Value(src.Value)
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

        struct GetTimeRequest : public PlayFabBaseModel
        {

            GetTimeRequest() :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const GetTimeRequest& src) :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const rapidjson::Value& obj) : GetTimeRequest()
            {
                readFromValue(obj);
            }

            ~GetTimeRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTimeResult : public PlayFabBaseModel
        {
            time_t Time;

            GetTimeResult() :
                PlayFabBaseModel(),
                Time(0)
            {}

            GetTimeResult(const GetTimeResult& src) :
                PlayFabBaseModel(),
                Time(src.Time)
            {}

            GetTimeResult(const rapidjson::Value& obj) : GetTimeResult()
            {
                readFromValue(obj);
            }

            ~GetTimeResult();

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

        struct GetTitleNewsRequest : public PlayFabBaseModel
        {
            OptionalInt32 Count;

            GetTitleNewsRequest() :
                PlayFabBaseModel(),
                Count()
            {}

            GetTitleNewsRequest(const GetTitleNewsRequest& src) :
                PlayFabBaseModel(),
                Count(src.Count)
            {}

            GetTitleNewsRequest(const rapidjson::Value& obj) : GetTitleNewsRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct TitleNewsItem : public PlayFabBaseModel
        {
            std::string Body;
            std::string NewsId;
            time_t Timestamp;
            std::string Title;

            TitleNewsItem() :
                PlayFabBaseModel(),
                Body(),
                NewsId(),
                Timestamp(0),
                Title()
            {}

            TitleNewsItem(const TitleNewsItem& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                NewsId(src.NewsId),
                Timestamp(src.Timestamp),
                Title(src.Title)
            {}

            TitleNewsItem(const rapidjson::Value& obj) : TitleNewsItem()
            {
                readFromValue(obj);
            }

            ~TitleNewsItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitleNewsResult : public PlayFabBaseModel
        {
            std::list<TitleNewsItem> News;

            GetTitleNewsResult() :
                PlayFabBaseModel(),
                News()
            {}

            GetTitleNewsResult(const GetTitleNewsResult& src) :
                PlayFabBaseModel(),
                News(src.News)
            {}

            GetTitleNewsResult(const rapidjson::Value& obj) : GetTitleNewsResult()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsResult();

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

        struct GetUserBansRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            GetUserBansRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserBansRequest(const GetUserBansRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetUserBansRequest(const rapidjson::Value& obj) : GetUserBansRequest()
            {
                readFromValue(obj);
            }

            ~GetUserBansRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            GetUserBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            GetUserBansResult(const GetUserBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            GetUserBansResult(const rapidjson::Value& obj) : GetUserBansResult()
            {
                readFromValue(obj);
            }

            ~GetUserBansResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserDataRequest : public PlayFabBaseModel
        {
            OptionalUint32 IfChangedFromDataVersion;
            std::list<std::string> Keys;
            std::string PlayFabId;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
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
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;
            std::string PlayFabId;

            GetUserDataResult() :
                PlayFabBaseModel(),
                Data(),
                DataVersion(0),
                PlayFabId()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                DataVersion(src.DataVersion),
                PlayFabId(src.PlayFabId)
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

            GetUserInventoryRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetUserInventoryRequest(const rapidjson::Value& obj) : GetUserInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> Inventory;
            std::string PlayFabId;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                Inventory(),
                PlayFabId(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                Inventory(src.Inventory),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetUserInventoryResult(const rapidjson::Value& obj) : GetUserInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GrantCharacterToUserRequest : public PlayFabBaseModel
        {
            std::string CharacterName;
            std::string CharacterType;
            std::string PlayFabId;

            GrantCharacterToUserRequest() :
                PlayFabBaseModel(),
                CharacterName(),
                CharacterType(),
                PlayFabId()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabBaseModel(),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType),
                PlayFabId(src.PlayFabId)
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

        struct GrantedItemInstance : public PlayFabBaseModel
        {
            std::string Annotation;
            std::list<std::string> BundleContents;
            std::string BundleParent;
            std::string CatalogVersion;
            std::string CharacterId;
            std::map<std::string, std::string> CustomData;
            std::string DisplayName;
            OptionalTime Expiration;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            std::string PlayFabId;
            OptionalTime PurchaseDate;
            OptionalInt32 RemainingUses;
            bool Result;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            OptionalInt32 UsesIncrementedBy;

            GrantedItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CharacterId(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PlayFabId(),
                PurchaseDate(),
                RemainingUses(),
                Result(false),
                UnitCurrency(),
                UnitPrice(0),
                UsesIncrementedBy()
            {}

            GrantedItemInstance(const GrantedItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                Result(src.Result),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
            {}

            GrantedItemInstance(const rapidjson::Value& obj) : GrantedItemInstance()
            {
                readFromValue(obj);
            }

            ~GrantedItemInstance();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GrantItemsToCharacterRequest : public PlayFabBaseModel
        {
            std::string Annotation;
            std::string CatalogVersion;
            std::string CharacterId;
            std::list<std::string> ItemIds;
            std::string PlayFabId;

            GrantItemsToCharacterRequest() :
                PlayFabBaseModel(),
                Annotation(),
                CatalogVersion(),
                CharacterId(),
                ItemIds(),
                PlayFabId()
            {}

            GrantItemsToCharacterRequest(const GrantItemsToCharacterRequest& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ItemIds(src.ItemIds),
                PlayFabId(src.PlayFabId)
            {}

            GrantItemsToCharacterRequest(const rapidjson::Value& obj) : GrantItemsToCharacterRequest()
            {
                readFromValue(obj);
            }

            ~GrantItemsToCharacterRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GrantItemsToCharacterResult : public PlayFabBaseModel
        {
            std::list<GrantedItemInstance> ItemGrantResults;

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
            std::string Annotation;
            std::string CatalogVersion;
            std::list<std::string> ItemIds;
            std::string PlayFabId;

            GrantItemsToUserRequest() :
                PlayFabBaseModel(),
                Annotation(),
                CatalogVersion(),
                ItemIds(),
                PlayFabId()
            {}

            GrantItemsToUserRequest(const GrantItemsToUserRequest& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                ItemIds(src.ItemIds),
                PlayFabId(src.PlayFabId)
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
            std::list<GrantedItemInstance> ItemGrantResults;

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
            std::string Annotation;
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::string ItemId;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            ItemGrant() :
                PlayFabBaseModel(),
                Annotation(),
                CharacterId(),
                Data(),
                ItemId(),
                KeysToRemove(),
                PlayFabId()
            {}

            ItemGrant(const ItemGrant& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                CharacterId(src.CharacterId),
                Data(src.Data),
                ItemId(src.ItemId),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
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
            std::list<GrantedItemInstance> ItemGrantResults;

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

        struct ModifyCharacterVirtualCurrencyResult : public PlayFabBaseModel
        {
            Int32 Balance;
            std::string VirtualCurrency;

            ModifyCharacterVirtualCurrencyResult() :
                PlayFabBaseModel(),
                Balance(0),
                VirtualCurrency()
            {}

            ModifyCharacterVirtualCurrencyResult(const ModifyCharacterVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                Balance(src.Balance),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ModifyCharacterVirtualCurrencyResult(const rapidjson::Value& obj) : ModifyCharacterVirtualCurrencyResult()
            {
                readFromValue(obj);
            }

            ~ModifyCharacterVirtualCurrencyResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ModifyItemUsesRequest : public PlayFabBaseModel
        {
            std::string ItemInstanceId;
            std::string PlayFabId;
            Int32 UsesToAdd;

            ModifyItemUsesRequest() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                PlayFabId(),
                UsesToAdd(0)
            {}

            ModifyItemUsesRequest(const ModifyItemUsesRequest& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId),
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
            Int32 Balance;
            Int32 BalanceChange;
            std::string PlayFabId;
            std::string VirtualCurrency;

            ModifyUserVirtualCurrencyResult() :
                PlayFabBaseModel(),
                Balance(0),
                BalanceChange(0),
                PlayFabId(),
                VirtualCurrency()
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                Balance(src.Balance),
                BalanceChange(src.BalanceChange),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
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
            std::string GivingCharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;
            std::string ReceivingCharacterId;

            MoveItemToCharacterFromCharacterRequest() :
                PlayFabBaseModel(),
                GivingCharacterId(),
                ItemInstanceId(),
                PlayFabId(),
                ReceivingCharacterId()
            {}

            MoveItemToCharacterFromCharacterRequest(const MoveItemToCharacterFromCharacterRequest& src) :
                PlayFabBaseModel(),
                GivingCharacterId(src.GivingCharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId),
                ReceivingCharacterId(src.ReceivingCharacterId)
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
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            MoveItemToCharacterFromUserRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            MoveItemToCharacterFromUserRequest(const MoveItemToCharacterFromUserRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
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
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            MoveItemToUserFromCharacterRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            MoveItemToUserFromCharacterRequest(const MoveItemToUserFromCharacterRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
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
            PlayerConnectionStateParticipated
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

        struct PushNotificationPackage : public PlayFabBaseModel
        {
            std::string CustomData;
            std::string Icon;
            std::string Message;
            std::string ScheduleDate;
            std::string Sound;
            std::string Title;

            PushNotificationPackage() :
                PlayFabBaseModel(),
                CustomData(),
                Icon(),
                Message(),
                ScheduleDate(),
                Sound(),
                Title()
            {}

            PushNotificationPackage(const PushNotificationPackage& src) :
                PlayFabBaseModel(),
                CustomData(src.CustomData),
                Icon(src.Icon),
                Message(src.Message),
                ScheduleDate(src.ScheduleDate),
                Sound(src.Sound),
                Title(src.Title)
            {}

            PushNotificationPackage(const rapidjson::Value& obj) : PushNotificationPackage()
            {
                readFromValue(obj);
            }

            ~PushNotificationPackage();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RedeemCouponRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string CouponCode;
            std::string PlayFabId;

            RedeemCouponRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                CouponCode(),
                PlayFabId()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CouponCode(src.CouponCode),
                PlayFabId(src.PlayFabId)
            {}

            RedeemCouponRequest(const rapidjson::Value& obj) : RedeemCouponRequest()
            {
                readFromValue(obj);
            }

            ~RedeemCouponRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RedeemCouponResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> GrantedItems;

            RedeemCouponResult() :
                PlayFabBaseModel(),
                GrantedItems()
            {}

            RedeemCouponResult(const RedeemCouponResult& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems)
            {}

            RedeemCouponResult(const rapidjson::Value& obj) : RedeemCouponResult()
            {
                readFromValue(obj);
            }

            ~RedeemCouponResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RedeemMatchmakerTicketRequest : public PlayFabBaseModel
        {
            std::string LobbyId;
            std::string Ticket;

            RedeemMatchmakerTicketRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                Ticket()
            {}

            RedeemMatchmakerTicketRequest(const RedeemMatchmakerTicketRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                Ticket(src.Ticket)
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
            std::string Error;
            bool TicketIsValid;
            UserAccountInfo* UserInfo;

            RedeemMatchmakerTicketResult() :
                PlayFabBaseModel(),
                Error(),
                TicketIsValid(false),
                UserInfo(NULL)
            {}

            RedeemMatchmakerTicketResult(const RedeemMatchmakerTicketResult& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                TicketIsValid(src.TicketIsValid),
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

        struct RefreshGameServerInstanceHeartbeatRequest : public PlayFabBaseModel
        {
            std::string LobbyId;

            RefreshGameServerInstanceHeartbeatRequest() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            RefreshGameServerInstanceHeartbeatRequest(const RefreshGameServerInstanceHeartbeatRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            RefreshGameServerInstanceHeartbeatRequest(const rapidjson::Value& obj) : RefreshGameServerInstanceHeartbeatRequest()
            {
                readFromValue(obj);
            }

            ~RefreshGameServerInstanceHeartbeatRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RefreshGameServerInstanceHeartbeatResult : public PlayFabBaseModel
        {

            RefreshGameServerInstanceHeartbeatResult() :
                PlayFabBaseModel()
            {}

            RefreshGameServerInstanceHeartbeatResult(const RefreshGameServerInstanceHeartbeatResult& src) :
                PlayFabBaseModel()
            {}

            RefreshGameServerInstanceHeartbeatResult(const rapidjson::Value& obj) : RefreshGameServerInstanceHeartbeatResult()
            {
                readFromValue(obj);
            }

            ~RefreshGameServerInstanceHeartbeatResult();

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
            std::string ServerPort;
            std::map<std::string, std::string> Tags;

            RegisterGameRequest() :
                PlayFabBaseModel(),
                Build(),
                GameMode(),
                LobbyId(),
                pfRegion(),
                ServerHost(),
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

        struct RemoveFriendRequest : public PlayFabBaseModel
        {
            std::string FriendPlayFabId;
            std::string PlayFabId;

            RemoveFriendRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                PlayFabId()
            {}

            RemoveFriendRequest(const RemoveFriendRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                PlayFabId(src.PlayFabId)
            {}

            RemoveFriendRequest(const rapidjson::Value& obj) : RemoveFriendRequest()
            {
                readFromValue(obj);
            }

            ~RemoveFriendRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemovePlayerTagRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string TagName;

            RemovePlayerTagRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                TagName()
            {}

            RemovePlayerTagRequest(const RemovePlayerTagRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            RemovePlayerTagRequest(const rapidjson::Value& obj) : RemovePlayerTagRequest()
            {
                readFromValue(obj);
            }

            ~RemovePlayerTagRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemovePlayerTagResult : public PlayFabBaseModel
        {

            RemovePlayerTagResult() :
                PlayFabBaseModel()
            {}

            RemovePlayerTagResult(const RemovePlayerTagResult& src) :
                PlayFabBaseModel()
            {}

            RemovePlayerTagResult(const rapidjson::Value& obj) : RemovePlayerTagResult()
            {
                readFromValue(obj);
            }

            ~RemovePlayerTagResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveSharedGroupMembersRequest : public PlayFabBaseModel
        {
            std::list<std::string> PlayFabIds;
            std::string SharedGroupId;

            RemoveSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                SharedGroupId()
            {}

            RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
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
            std::string Comment;
            std::string ReporteeId;
            std::string ReporterId;

            ReportPlayerServerRequest() :
                PlayFabBaseModel(),
                Comment(),
                ReporteeId(),
                ReporterId()
            {}

            ReportPlayerServerRequest(const ReportPlayerServerRequest& src) :
                PlayFabBaseModel(),
                Comment(src.Comment),
                ReporteeId(src.ReporteeId),
                ReporterId(src.ReporterId)
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
            Int32 SubmissionsRemaining;

            ReportPlayerServerResult() :
                PlayFabBaseModel(),
                SubmissionsRemaining(0)
            {}

            ReportPlayerServerResult(const ReportPlayerServerResult& src) :
                PlayFabBaseModel(),
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

        struct RevokeAllBansForUserRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            RevokeAllBansForUserRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            RevokeAllBansForUserRequest(const RevokeAllBansForUserRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            RevokeAllBansForUserRequest(const rapidjson::Value& obj) : RevokeAllBansForUserRequest()
            {
                readFromValue(obj);
            }

            ~RevokeAllBansForUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeAllBansForUserResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            RevokeAllBansForUserResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            RevokeAllBansForUserResult(const RevokeAllBansForUserResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            RevokeAllBansForUserResult(const rapidjson::Value& obj) : RevokeAllBansForUserResult()
            {
                readFromValue(obj);
            }

            ~RevokeAllBansForUserResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeBansRequest : public PlayFabBaseModel
        {
            std::list<std::string> BanIds;

            RevokeBansRequest() :
                PlayFabBaseModel(),
                BanIds()
            {}

            RevokeBansRequest(const RevokeBansRequest& src) :
                PlayFabBaseModel(),
                BanIds(src.BanIds)
            {}

            RevokeBansRequest(const rapidjson::Value& obj) : RevokeBansRequest()
            {
                readFromValue(obj);
            }

            ~RevokeBansRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            RevokeBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            RevokeBansResult(const RevokeBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            RevokeBansResult(const rapidjson::Value& obj) : RevokeBansResult()
            {
                readFromValue(obj);
            }

            ~RevokeBansResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeInventoryItemRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            RevokeInventoryItemRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            RevokeInventoryItemRequest(const RevokeInventoryItemRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            RevokeInventoryItemRequest(const rapidjson::Value& obj) : RevokeInventoryItemRequest()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItemRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeInventoryResult : public PlayFabBaseModel
        {

            RevokeInventoryResult() :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const RevokeInventoryResult& src) :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const rapidjson::Value& obj) : RevokeInventoryResult()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SendPushNotificationRequest : public PlayFabBaseModel
        {
            std::list<AdvancedPushPlatformMsg> AdvancedPlatformDelivery;
            std::string Message;
            PushNotificationPackage* Package;
            std::string Recipient;
            std::string Subject;
            std::list<PushNotificationPlatform> TargetPlatforms;

            SendPushNotificationRequest() :
                PlayFabBaseModel(),
                AdvancedPlatformDelivery(),
                Message(),
                Package(NULL),
                Recipient(),
                Subject(),
                TargetPlatforms()
            {}

            SendPushNotificationRequest(const SendPushNotificationRequest& src) :
                PlayFabBaseModel(),
                AdvancedPlatformDelivery(src.AdvancedPlatformDelivery),
                Message(src.Message),
                Package(src.Package ? new PushNotificationPackage(*src.Package) : NULL),
                Recipient(src.Recipient),
                Subject(src.Subject),
                TargetPlatforms(src.TargetPlatforms)
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

        struct SetFriendTagsRequest : public PlayFabBaseModel
        {
            std::string FriendPlayFabId;
            std::string PlayFabId;
            std::list<std::string> Tags;

            SetFriendTagsRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                PlayFabId(),
                Tags()
            {}

            SetFriendTagsRequest(const SetFriendTagsRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            SetFriendTagsRequest(const rapidjson::Value& obj) : SetFriendTagsRequest()
            {
                readFromValue(obj);
            }

            ~SetFriendTagsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetGameServerInstanceDataRequest : public PlayFabBaseModel
        {
            std::string GameServerData;
            std::string LobbyId;

            SetGameServerInstanceDataRequest() :
                PlayFabBaseModel(),
                GameServerData(),
                LobbyId()
            {}

            SetGameServerInstanceDataRequest(const SetGameServerInstanceDataRequest& src) :
                PlayFabBaseModel(),
                GameServerData(src.GameServerData),
                LobbyId(src.LobbyId)
            {}

            SetGameServerInstanceDataRequest(const rapidjson::Value& obj) : SetGameServerInstanceDataRequest()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetGameServerInstanceDataResult : public PlayFabBaseModel
        {

            SetGameServerInstanceDataResult() :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceDataResult(const SetGameServerInstanceDataResult& src) :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceDataResult(const rapidjson::Value& obj) : SetGameServerInstanceDataResult()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetGameServerInstanceStateRequest : public PlayFabBaseModel
        {
            std::string LobbyId;
            GameInstanceState State;

            SetGameServerInstanceStateRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                State()
            {}

            SetGameServerInstanceStateRequest(const SetGameServerInstanceStateRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                State(src.State)
            {}

            SetGameServerInstanceStateRequest(const rapidjson::Value& obj) : SetGameServerInstanceStateRequest()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceStateRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetGameServerInstanceStateResult : public PlayFabBaseModel
        {

            SetGameServerInstanceStateResult() :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceStateResult(const SetGameServerInstanceStateResult& src) :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceStateResult(const rapidjson::Value& obj) : SetGameServerInstanceStateResult()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceStateResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetGameServerInstanceTagsRequest : public PlayFabBaseModel
        {
            std::string LobbyId;
            std::map<std::string, std::string> Tags;

            SetGameServerInstanceTagsRequest() :
                PlayFabBaseModel(),
                LobbyId(),
                Tags()
            {}

            SetGameServerInstanceTagsRequest(const SetGameServerInstanceTagsRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                Tags(src.Tags)
            {}

            SetGameServerInstanceTagsRequest(const rapidjson::Value& obj) : SetGameServerInstanceTagsRequest()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceTagsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetGameServerInstanceTagsResult : public PlayFabBaseModel
        {

            SetGameServerInstanceTagsResult() :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceTagsResult(const SetGameServerInstanceTagsResult& src) :
                PlayFabBaseModel()
            {}

            SetGameServerInstanceTagsResult(const rapidjson::Value& obj) : SetGameServerInstanceTagsResult()
            {
                readFromValue(obj);
            }

            ~SetGameServerInstanceTagsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetPlayerSecretRequest : public PlayFabBaseModel
        {
            std::string PlayerSecret;
            std::string PlayFabId;

            SetPlayerSecretRequest() :
                PlayFabBaseModel(),
                PlayerSecret(),
                PlayFabId()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabBaseModel(),
                PlayerSecret(src.PlayerSecret),
                PlayFabId(src.PlayFabId)
            {}

            SetPlayerSecretRequest(const rapidjson::Value& obj) : SetPlayerSecretRequest()
            {
                readFromValue(obj);
            }

            ~SetPlayerSecretRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetPlayerSecretResult : public PlayFabBaseModel
        {

            SetPlayerSecretResult() :
                PlayFabBaseModel()
            {}

            SetPlayerSecretResult(const SetPlayerSecretResult& src) :
                PlayFabBaseModel()
            {}

            SetPlayerSecretResult(const rapidjson::Value& obj) : SetPlayerSecretResult()
            {
                readFromValue(obj);
            }

            ~SetPlayerSecretResult();

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

        struct StatisticUpdate : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 Value;
            OptionalUint32 Version;

            StatisticUpdate() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version()
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticUpdate(const rapidjson::Value& obj) : StatisticUpdate()
            {
                readFromValue(obj);
            }

            ~StatisticUpdate();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SubtractCharacterVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string CharacterId;
            std::string PlayFabId;
            std::string VirtualCurrency;

            SubtractCharacterVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                CharacterId(),
                PlayFabId(),
                VirtualCurrency()
            {}

            SubtractCharacterVirtualCurrencyRequest(const SubtractCharacterVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            SubtractCharacterVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractCharacterVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~SubtractCharacterVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string PlayFabId;
            std::string VirtualCurrency;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                PlayFabId(),
                VirtualCurrency()
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            SubtractUserVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~SubtractUserVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlockContainerInstanceRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemInstanceId;
            std::string KeyItemInstanceId;
            std::string PlayFabId;

            UnlockContainerInstanceRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemInstanceId(),
                KeyItemInstanceId(),
                PlayFabId()
            {}

            UnlockContainerInstanceRequest(const UnlockContainerInstanceRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemInstanceId(src.ContainerItemInstanceId),
                KeyItemInstanceId(src.KeyItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            UnlockContainerInstanceRequest(const rapidjson::Value& obj) : UnlockContainerInstanceRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerInstanceRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlockContainerItemRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemId;
            std::string PlayFabId;

            UnlockContainerItemRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemId(),
                PlayFabId()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemId(src.ContainerItemId),
                PlayFabId(src.PlayFabId)
            {}

            UnlockContainerItemRequest(const rapidjson::Value& obj) : UnlockContainerItemRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlockContainerItemResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> GrantedItems;
            std::string UnlockedItemInstanceId;
            std::string UnlockedWithItemInstanceId;
            std::map<std::string, Uint32> VirtualCurrency;

            UnlockContainerItemResult() :
                PlayFabBaseModel(),
                GrantedItems(),
                UnlockedItemInstanceId(),
                UnlockedWithItemInstanceId(),
                VirtualCurrency()
            {}

            UnlockContainerItemResult(const UnlockContainerItemResult& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems),
                UnlockedItemInstanceId(src.UnlockedItemInstanceId),
                UnlockedWithItemInstanceId(src.UnlockedWithItemInstanceId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            UnlockContainerItemResult(const rapidjson::Value& obj) : UnlockContainerItemResult()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateAvatarUrlRequest : public PlayFabBaseModel
        {
            std::string ImageUrl;
            std::string PlayFabId;

            UpdateAvatarUrlRequest() :
                PlayFabBaseModel(),
                ImageUrl(),
                PlayFabId()
            {}

            UpdateAvatarUrlRequest(const UpdateAvatarUrlRequest& src) :
                PlayFabBaseModel(),
                ImageUrl(src.ImageUrl),
                PlayFabId(src.PlayFabId)
            {}

            UpdateAvatarUrlRequest(const rapidjson::Value& obj) : UpdateAvatarUrlRequest()
            {
                readFromValue(obj);
            }

            ~UpdateAvatarUrlRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateBanRequest : public PlayFabBaseModel
        {
            OptionalBool Active;
            std::string BanId;
            OptionalTime Expires;
            std::string IPAddress;
            std::string MACAddress;
            OptionalBool Permanent;
            std::string Reason;

            UpdateBanRequest() :
                PlayFabBaseModel(),
                Active(),
                BanId(),
                Expires(),
                IPAddress(),
                MACAddress(),
                Permanent(),
                Reason()
            {}

            UpdateBanRequest(const UpdateBanRequest& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                BanId(src.BanId),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Permanent(src.Permanent),
                Reason(src.Reason)
            {}

            UpdateBanRequest(const rapidjson::Value& obj) : UpdateBanRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBanRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateBansRequest : public PlayFabBaseModel
        {
            std::list<UpdateBanRequest> Bans;

            UpdateBansRequest() :
                PlayFabBaseModel(),
                Bans()
            {}

            UpdateBansRequest(const UpdateBansRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans)
            {}

            UpdateBansRequest(const rapidjson::Value& obj) : UpdateBansRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBansRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            UpdateBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            UpdateBansResult(const UpdateBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            UpdateBansResult(const rapidjson::Value& obj) : UpdateBansResult()
            {
                readFromValue(obj);
            }

            ~UpdateBansResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCharacterDataRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string PlayFabId;

            UpdateCharacterDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                KeysToRemove(),
                Permission(),
                PlayFabId()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                PlayFabId(src.PlayFabId)
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
            Uint32 DataVersion;

            UpdateCharacterDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateCharacterDataResult(const UpdateCharacterDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
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
            std::string CharacterId;
            std::map<std::string, Int32> CharacterStatistics;
            std::string PlayFabId;

            UpdateCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterStatistics(),
                PlayFabId()
            {}

            UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics),
                PlayFabId(src.PlayFabId)
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

        struct UpdatePlayerStatisticsRequest : public PlayFabBaseModel
        {
            OptionalBool ForceUpdate;
            std::string PlayFabId;
            std::list<StatisticUpdate> Statistics;

            UpdatePlayerStatisticsRequest() :
                PlayFabBaseModel(),
                ForceUpdate(),
                PlayFabId(),
                Statistics()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                ForceUpdate(src.ForceUpdate),
                PlayFabId(src.PlayFabId),
                Statistics(src.Statistics)
            {}

            UpdatePlayerStatisticsRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerStatisticsResult : public PlayFabBaseModel
        {

            UpdatePlayerStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const UpdatePlayerStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const rapidjson::Value& obj) : UpdatePlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateSharedGroupDataRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string SharedGroupId;

            UpdateSharedGroupDataRequest() :
                PlayFabBaseModel(),
                Data(),
                KeysToRemove(),
                Permission(),
                SharedGroupId()
            {}

            UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                SharedGroupId(src.SharedGroupId)
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
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string PlayFabId;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                Data(),
                KeysToRemove(),
                Permission(),
                PlayFabId()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                PlayFabId(src.PlayFabId)
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
            Uint32 DataVersion;

            UpdateUserDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateUserDataResult(const UpdateUserDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
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
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            UpdateUserInternalDataRequest() :
                PlayFabBaseModel(),
                Data(),
                KeysToRemove(),
                PlayFabId()
            {}

            UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            UpdateUserInternalDataRequest(const rapidjson::Value& obj) : UpdateUserInternalDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserInternalDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserInventoryItemDataRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::string ItemInstanceId;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            UpdateUserInventoryItemDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                ItemInstanceId(),
                KeysToRemove(),
                PlayFabId()
            {}

            UpdateUserInventoryItemDataRequest(const UpdateUserInventoryItemDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                ItemInstanceId(src.ItemInstanceId),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            UpdateUserInventoryItemDataRequest(const rapidjson::Value& obj) : UpdateUserInventoryItemDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserInventoryItemDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteEventResponse : public PlayFabBaseModel
        {
            std::string EventId;

            WriteEventResponse() :
                PlayFabBaseModel(),
                EventId()
            {}

            WriteEventResponse(const WriteEventResponse& src) :
                PlayFabBaseModel(),
                EventId(src.EventId)
            {}

            WriteEventResponse(const rapidjson::Value& obj) : WriteEventResponse()
            {
                readFromValue(obj);
            }

            ~WriteEventResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteServerCharacterEventRequest : public PlayFabBaseModel
        {
            std::map<std::string, MultitypeVar> Body;
            std::string CharacterId;
            std::string EventName;
            std::string PlayFabId;
            OptionalTime Timestamp;

            WriteServerCharacterEventRequest() :
                PlayFabBaseModel(),
                Body(),
                CharacterId(),
                EventName(),
                PlayFabId(),
                Timestamp()
            {}

            WriteServerCharacterEventRequest(const WriteServerCharacterEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                CharacterId(src.CharacterId),
                EventName(src.EventName),
                PlayFabId(src.PlayFabId),
                Timestamp(src.Timestamp)
            {}

            WriteServerCharacterEventRequest(const rapidjson::Value& obj) : WriteServerCharacterEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteServerCharacterEventRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteServerPlayerEventRequest : public PlayFabBaseModel
        {
            std::map<std::string, MultitypeVar> Body;
            std::string EventName;
            std::string PlayFabId;
            OptionalTime Timestamp;

            WriteServerPlayerEventRequest() :
                PlayFabBaseModel(),
                Body(),
                EventName(),
                PlayFabId(),
                Timestamp()
            {}

            WriteServerPlayerEventRequest(const WriteServerPlayerEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                EventName(src.EventName),
                PlayFabId(src.PlayFabId),
                Timestamp(src.Timestamp)
            {}

            WriteServerPlayerEventRequest(const rapidjson::Value& obj) : WriteServerPlayerEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteServerPlayerEventRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteTitleEventRequest : public PlayFabBaseModel
        {
            std::map<std::string, MultitypeVar> Body;
            std::string EventName;
            OptionalTime Timestamp;

            WriteTitleEventRequest() :
                PlayFabBaseModel(),
                Body(),
                EventName(),
                Timestamp()
            {}

            WriteTitleEventRequest(const WriteTitleEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            WriteTitleEventRequest(const rapidjson::Value& obj) : WriteTitleEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteTitleEventRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
