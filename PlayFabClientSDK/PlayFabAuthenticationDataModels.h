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

        struct ActivateAPIKeyRequest : public PlayFabBaseModel
        {
            std::string APIKeyId;
            EntityKey* Entity;

            ActivateAPIKeyRequest() :
                PlayFabBaseModel(),
                APIKeyId(),
                Entity(NULL)
            {}

            ActivateAPIKeyRequest(const ActivateAPIKeyRequest& src) :
                PlayFabBaseModel(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            ActivateAPIKeyRequest(const rapidjson::Value& obj) : ActivateAPIKeyRequest()
            {
                readFromValue(obj);
            }

            ~ActivateAPIKeyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ActivateAPIKeyResponse : public PlayFabBaseModel
        {

            ActivateAPIKeyResponse() :
                PlayFabBaseModel()
            {}

            ActivateAPIKeyResponse(const ActivateAPIKeyResponse& src) :
                PlayFabBaseModel()
            {}

            ActivateAPIKeyResponse(const rapidjson::Value& obj) : ActivateAPIKeyResponse()
            {
                readFromValue(obj);
            }

            ~ActivateAPIKeyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateAPIKeyDetails : public PlayFabBaseModel
        {
            bool Active;
            std::string APIKeyId;
            std::string APIKeySecret;
            time_t Created;

            CreateAPIKeyDetails() :
                PlayFabBaseModel(),
                Active(false),
                APIKeyId(),
                APIKeySecret(),
                Created(0)
            {}

            CreateAPIKeyDetails(const CreateAPIKeyDetails& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                APIKeyId(src.APIKeyId),
                APIKeySecret(src.APIKeySecret),
                Created(src.Created)
            {}

            CreateAPIKeyDetails(const rapidjson::Value& obj) : CreateAPIKeyDetails()
            {
                readFromValue(obj);
            }

            ~CreateAPIKeyDetails();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateAPIKeyRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            CreateAPIKeyRequest() :
                PlayFabBaseModel(),
                Entity(NULL)
            {}

            CreateAPIKeyRequest(const CreateAPIKeyRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            CreateAPIKeyRequest(const rapidjson::Value& obj) : CreateAPIKeyRequest()
            {
                readFromValue(obj);
            }

            ~CreateAPIKeyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateAPIKeyResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            CreateAPIKeyDetails* Key;

            CreateAPIKeyResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Key(NULL)
            {}

            CreateAPIKeyResponse(const CreateAPIKeyResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Key(src.Key ? new CreateAPIKeyDetails(*src.Key) : NULL)
            {}

            CreateAPIKeyResponse(const rapidjson::Value& obj) : CreateAPIKeyResponse()
            {
                readFromValue(obj);
            }

            ~CreateAPIKeyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeactivateAPIKeyRequest : public PlayFabBaseModel
        {
            std::string APIKeyId;
            EntityKey* Entity;

            DeactivateAPIKeyRequest() :
                PlayFabBaseModel(),
                APIKeyId(),
                Entity(NULL)
            {}

            DeactivateAPIKeyRequest(const DeactivateAPIKeyRequest& src) :
                PlayFabBaseModel(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            DeactivateAPIKeyRequest(const rapidjson::Value& obj) : DeactivateAPIKeyRequest()
            {
                readFromValue(obj);
            }

            ~DeactivateAPIKeyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeactivateAPIKeyResponse : public PlayFabBaseModel
        {

            DeactivateAPIKeyResponse() :
                PlayFabBaseModel()
            {}

            DeactivateAPIKeyResponse(const DeactivateAPIKeyResponse& src) :
                PlayFabBaseModel()
            {}

            DeactivateAPIKeyResponse(const rapidjson::Value& obj) : DeactivateAPIKeyResponse()
            {
                readFromValue(obj);
            }

            ~DeactivateAPIKeyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteAPIKeyRequest : public PlayFabBaseModel
        {
            std::string APIKeyId;
            EntityKey* Entity;

            DeleteAPIKeyRequest() :
                PlayFabBaseModel(),
                APIKeyId(),
                Entity(NULL)
            {}

            DeleteAPIKeyRequest(const DeleteAPIKeyRequest& src) :
                PlayFabBaseModel(),
                APIKeyId(src.APIKeyId),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            DeleteAPIKeyRequest(const rapidjson::Value& obj) : DeleteAPIKeyRequest()
            {
                readFromValue(obj);
            }

            ~DeleteAPIKeyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteAPIKeyResponse : public PlayFabBaseModel
        {

            DeleteAPIKeyResponse() :
                PlayFabBaseModel()
            {}

            DeleteAPIKeyResponse(const DeleteAPIKeyResponse& src) :
                PlayFabBaseModel()
            {}

            DeleteAPIKeyResponse(const rapidjson::Value& obj) : DeleteAPIKeyResponse()
            {
                readFromValue(obj);
            }

            ~DeleteAPIKeyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAPIKeyDetails : public PlayFabBaseModel
        {
            bool Active;
            std::string APIKeyId;
            time_t Created;

            GetAPIKeyDetails() :
                PlayFabBaseModel(),
                Active(false),
                APIKeyId(),
                Created(0)
            {}

            GetAPIKeyDetails(const GetAPIKeyDetails& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                APIKeyId(src.APIKeyId),
                Created(src.Created)
            {}

            GetAPIKeyDetails(const rapidjson::Value& obj) : GetAPIKeyDetails()
            {
                readFromValue(obj);
            }

            ~GetAPIKeyDetails();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAPIKeysRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            GetAPIKeysRequest() :
                PlayFabBaseModel(),
                Entity(NULL)
            {}

            GetAPIKeysRequest(const GetAPIKeysRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            GetAPIKeysRequest(const rapidjson::Value& obj) : GetAPIKeysRequest()
            {
                readFromValue(obj);
            }

            ~GetAPIKeysRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAPIKeysResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::list<GetAPIKeyDetails> Keys;

            GetAPIKeysResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Keys()
            {}

            GetAPIKeysResponse(const GetAPIKeysResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Keys(src.Keys)
            {}

            GetAPIKeysResponse(const rapidjson::Value& obj) : GetAPIKeysResponse()
            {
                readFromValue(obj);
            }

            ~GetAPIKeysResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetEntityTokenRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            GetEntityTokenRequest() :
                PlayFabBaseModel(),
                Entity(NULL)
            {}

            GetEntityTokenRequest(const GetEntityTokenRequest& src) :
                PlayFabBaseModel(),
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


    }
}

#endif
