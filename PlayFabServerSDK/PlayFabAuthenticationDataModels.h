#ifndef PLAYFAB_AUTHENTICATION_DATA_MODELS_H_
#define PLAYFAB_AUTHENTICATION_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace AuthenticationModels
    {
        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            std::string Type;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type)
            {}

            EntityKey(const rapidjson::Value& obj) : EntityKey()
            {
                readFromValue(obj);
            }

            ~EntityKey();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EntityLineage : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string GroupId;
            std::string MasterPlayerAccountId;
            std::string NamespaceId;
            std::string TitleId;
            std::string TitlePlayerAccountId;

            EntityLineage() :
                PlayFabBaseModel(),
                CharacterId(),
                GroupId(),
                MasterPlayerAccountId(),
                NamespaceId(),
                TitleId(),
                TitlePlayerAccountId()
            {}

            EntityLineage(const EntityLineage& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                GroupId(src.GroupId),
                MasterPlayerAccountId(src.MasterPlayerAccountId),
                NamespaceId(src.NamespaceId),
                TitleId(src.TitleId),
                TitlePlayerAccountId(src.TitlePlayerAccountId)
            {}

            EntityLineage(const rapidjson::Value& obj) : EntityLineage()
            {
                readFromValue(obj);
            }

            ~EntityLineage();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetEntityTokenRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey* Entity;

            GetEntityTokenRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(NULL)
            {}

            GetEntityTokenRequest(const GetEntityTokenRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            GetEntityTokenRequest(const rapidjson::Value& obj) : GetEntityTokenRequest()
            {
                readFromValue(obj);
            }

            ~GetEntityTokenRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetEntityTokenResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::string EntityToken;
            OptionalTime TokenExpiration;

            GetEntityTokenResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                EntityToken(),
                TokenExpiration()
            {}

            GetEntityTokenResponse(const GetEntityTokenResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            GetEntityTokenResponse(const rapidjson::Value& obj) : GetEntityTokenResponse()
            {
                readFromValue(obj);
            }

            ~GetEntityTokenResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum IdentifiedDeviceType
        {
            IdentifiedDeviceTypeUnknown,
            IdentifiedDeviceTypeXboxOne,
            IdentifiedDeviceTypeScarlett
        };

        void writeIdentifiedDeviceTypeEnumJSON(IdentifiedDeviceType enumVal, PFStringJsonWriter& writer);
        IdentifiedDeviceType readIdentifiedDeviceTypeFromValue(const rapidjson::Value& obj);

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
            LoginIdentityProviderWindowsHello,
            LoginIdentityProviderGameServer,
            LoginIdentityProviderCustomServer,
            LoginIdentityProviderNintendoSwitch,
            LoginIdentityProviderFacebookInstantGames,
            LoginIdentityProviderOpenIdConnect,
            LoginIdentityProviderApple,
            LoginIdentityProviderNintendoSwitchAccount
        };

        void writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer);
        LoginIdentityProvider readLoginIdentityProviderFromValue(const rapidjson::Value& obj);

        struct ValidateEntityTokenRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string EntityToken;

            ValidateEntityTokenRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                EntityToken()
            {}

            ValidateEntityTokenRequest(const ValidateEntityTokenRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                EntityToken(src.EntityToken)
            {}

            ValidateEntityTokenRequest(const rapidjson::Value& obj) : ValidateEntityTokenRequest()
            {
                readFromValue(obj);
            }

            ~ValidateEntityTokenRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateEntityTokenResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Boxed<IdentifiedDeviceType> pfIdentifiedDeviceType;
            Boxed<LoginIdentityProvider> IdentityProvider;
            EntityLineage* Lineage;

            ValidateEntityTokenResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                pfIdentifiedDeviceType(),
                IdentityProvider(),
                Lineage(NULL)
            {}

            ValidateEntityTokenResponse(const ValidateEntityTokenResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                pfIdentifiedDeviceType(src.pfIdentifiedDeviceType),
                IdentityProvider(src.IdentityProvider),
                Lineage(src.Lineage ? new EntityLineage(*src.Lineage) : NULL)
            {}

            ValidateEntityTokenResponse(const rapidjson::Value& obj) : ValidateEntityTokenResponse()
            {
                readFromValue(obj);
            }

            ~ValidateEntityTokenResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
