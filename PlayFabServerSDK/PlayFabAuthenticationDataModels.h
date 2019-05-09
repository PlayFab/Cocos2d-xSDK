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
