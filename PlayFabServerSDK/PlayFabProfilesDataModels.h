#ifndef PLAYFAB_PROFILES_DATA_MODELS_H_
#define PLAYFAB_PROFILES_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ProfilesModels
    {
        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        void writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer);
        EffectType readEffectTypeFromValue(const rapidjson::Value& obj);

        struct EntityDataObject : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            EntityDataObject() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            EntityDataObject(const EntityDataObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            EntityDataObject(const rapidjson::Value& obj) : EntityDataObject()
            {
                readFromValue(obj);
            }

            ~EntityDataObject();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

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

        struct EntityPermissionStatement : public PlayFabBaseModel
        {
            std::string Action;
            std::string Comment;
            MultitypeVar Condition;
            EffectType Effect;
            MultitypeVar Principal;
            std::string Resource;

            EntityPermissionStatement() :
                PlayFabBaseModel(),
                Action(),
                Comment(),
                Condition(),
                Effect(),
                Principal(),
                Resource()
            {}

            EntityPermissionStatement(const EntityPermissionStatement& src) :
                PlayFabBaseModel(),
                Action(src.Action),
                Comment(src.Comment),
                Condition(src.Condition),
                Effect(src.Effect),
                Principal(src.Principal),
                Resource(src.Resource)
            {}

            EntityPermissionStatement(const rapidjson::Value& obj) : EntityPermissionStatement()
            {
                readFromValue(obj);
            }

            ~EntityPermissionStatement();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EntityProfileFileMetadata : public PlayFabBaseModel
        {
            std::string Checksum;
            std::string FileName;
            time_t LastModified;
            Int32 Size;

            EntityProfileFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                FileName(),
                LastModified(0),
                Size(0)
            {}

            EntityProfileFileMetadata(const EntityProfileFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            EntityProfileFileMetadata(const rapidjson::Value& obj) : EntityProfileFileMetadata()
            {
                readFromValue(obj);
            }

            ~EntityProfileFileMetadata();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EntityProfileBody : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::string EntityChain;
            std::map<std::string, EntityProfileFileMetadata> Files;
            std::string FriendlyName;
            std::string Language;
            EntityLineage* Lineage;
            std::map<std::string, EntityDataObject> Objects;
            std::list<EntityPermissionStatement> Permissions;
            Int32 VersionNumber;

            EntityProfileBody() :
                PlayFabBaseModel(),
                Entity(NULL),
                EntityChain(),
                Files(),
                FriendlyName(),
                Language(),
                Lineage(NULL),
                Objects(),
                Permissions(),
                VersionNumber(0)
            {}

            EntityProfileBody(const EntityProfileBody& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                EntityChain(src.EntityChain),
                Files(src.Files),
                FriendlyName(src.FriendlyName),
                Language(src.Language),
                Lineage(src.Lineage ? new EntityLineage(*src.Lineage) : NULL),
                Objects(src.Objects),
                Permissions(src.Permissions),
                VersionNumber(src.VersionNumber)
            {}

            EntityProfileBody(const rapidjson::Value& obj) : EntityProfileBody()
            {
                readFromValue(obj);
            }

            ~EntityProfileBody();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetEntityProfileRequest : public PlayFabBaseModel
        {
            OptionalBool DataAsObject;
            EntityKey* Entity;

            GetEntityProfileRequest() :
                PlayFabBaseModel(),
                DataAsObject(),
                Entity(NULL)
            {}

            GetEntityProfileRequest(const GetEntityProfileRequest& src) :
                PlayFabBaseModel(),
                DataAsObject(src.DataAsObject),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            GetEntityProfileRequest(const rapidjson::Value& obj) : GetEntityProfileRequest()
            {
                readFromValue(obj);
            }

            ~GetEntityProfileRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetEntityProfileResponse : public PlayFabBaseModel
        {
            EntityProfileBody* Profile;

            GetEntityProfileResponse() :
                PlayFabBaseModel(),
                Profile(NULL)
            {}

            GetEntityProfileResponse(const GetEntityProfileResponse& src) :
                PlayFabBaseModel(),
                Profile(src.Profile ? new EntityProfileBody(*src.Profile) : NULL)
            {}

            GetEntityProfileResponse(const rapidjson::Value& obj) : GetEntityProfileResponse()
            {
                readFromValue(obj);
            }

            ~GetEntityProfileResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetEntityProfilesRequest : public PlayFabBaseModel
        {
            OptionalBool DataAsObject;
            std::list<EntityKey> Entities;

            GetEntityProfilesRequest() :
                PlayFabBaseModel(),
                DataAsObject(),
                Entities()
            {}

            GetEntityProfilesRequest(const GetEntityProfilesRequest& src) :
                PlayFabBaseModel(),
                DataAsObject(src.DataAsObject),
                Entities(src.Entities)
            {}

            GetEntityProfilesRequest(const rapidjson::Value& obj) : GetEntityProfilesRequest()
            {
                readFromValue(obj);
            }

            ~GetEntityProfilesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetEntityProfilesResponse : public PlayFabBaseModel
        {
            std::list<EntityProfileBody> Profiles;

            GetEntityProfilesResponse() :
                PlayFabBaseModel(),
                Profiles()
            {}

            GetEntityProfilesResponse(const GetEntityProfilesResponse& src) :
                PlayFabBaseModel(),
                Profiles(src.Profiles)
            {}

            GetEntityProfilesResponse(const rapidjson::Value& obj) : GetEntityProfilesResponse()
            {
                readFromValue(obj);
            }

            ~GetEntityProfilesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetGlobalPolicyRequest : public PlayFabBaseModel
        {

            GetGlobalPolicyRequest() :
                PlayFabBaseModel()
            {}

            GetGlobalPolicyRequest(const GetGlobalPolicyRequest& src) :
                PlayFabBaseModel()
            {}

            GetGlobalPolicyRequest(const rapidjson::Value& obj) : GetGlobalPolicyRequest()
            {
                readFromValue(obj);
            }

            ~GetGlobalPolicyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetGlobalPolicyResponse : public PlayFabBaseModel
        {
            std::list<EntityPermissionStatement> Permissions;

            GetGlobalPolicyResponse() :
                PlayFabBaseModel(),
                Permissions()
            {}

            GetGlobalPolicyResponse(const GetGlobalPolicyResponse& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            GetGlobalPolicyResponse(const rapidjson::Value& obj) : GetGlobalPolicyResponse()
            {
                readFromValue(obj);
            }

            ~GetGlobalPolicyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        void writeOperationTypesEnumJSON(OperationTypes enumVal, PFStringJsonWriter& writer);
        OperationTypes readOperationTypesFromValue(const rapidjson::Value& obj);

        struct SetEntityProfilePolicyRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            std::list<EntityPermissionStatement> Statements;

            SetEntityProfilePolicyRequest() :
                PlayFabBaseModel(),
                Entity(),
                Statements()
            {}

            SetEntityProfilePolicyRequest(const SetEntityProfilePolicyRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Statements(src.Statements)
            {}

            SetEntityProfilePolicyRequest(const rapidjson::Value& obj) : SetEntityProfilePolicyRequest()
            {
                readFromValue(obj);
            }

            ~SetEntityProfilePolicyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetEntityProfilePolicyResponse : public PlayFabBaseModel
        {
            std::list<EntityPermissionStatement> Permissions;

            SetEntityProfilePolicyResponse() :
                PlayFabBaseModel(),
                Permissions()
            {}

            SetEntityProfilePolicyResponse(const SetEntityProfilePolicyResponse& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            SetEntityProfilePolicyResponse(const rapidjson::Value& obj) : SetEntityProfilePolicyResponse()
            {
                readFromValue(obj);
            }

            ~SetEntityProfilePolicyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetGlobalPolicyRequest : public PlayFabBaseModel
        {
            std::list<EntityPermissionStatement> Permissions;

            SetGlobalPolicyRequest() :
                PlayFabBaseModel(),
                Permissions()
            {}

            SetGlobalPolicyRequest(const SetGlobalPolicyRequest& src) :
                PlayFabBaseModel(),
                Permissions(src.Permissions)
            {}

            SetGlobalPolicyRequest(const rapidjson::Value& obj) : SetGlobalPolicyRequest()
            {
                readFromValue(obj);
            }

            ~SetGlobalPolicyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetGlobalPolicyResponse : public PlayFabBaseModel
        {

            SetGlobalPolicyResponse() :
                PlayFabBaseModel()
            {}

            SetGlobalPolicyResponse(const SetGlobalPolicyResponse& src) :
                PlayFabBaseModel()
            {}

            SetGlobalPolicyResponse(const rapidjson::Value& obj) : SetGlobalPolicyResponse()
            {
                readFromValue(obj);
            }

            ~SetGlobalPolicyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetProfileLanguageRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ExpectedVersion;
            std::string Language;

            SetProfileLanguageRequest() :
                PlayFabBaseModel(),
                Entity(NULL),
                ExpectedVersion(0),
                Language()
            {}

            SetProfileLanguageRequest(const SetProfileLanguageRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                ExpectedVersion(src.ExpectedVersion),
                Language(src.Language)
            {}

            SetProfileLanguageRequest(const rapidjson::Value& obj) : SetProfileLanguageRequest()
            {
                readFromValue(obj);
            }

            ~SetProfileLanguageRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetProfileLanguageResponse : public PlayFabBaseModel
        {
            Boxed<OperationTypes> OperationResult;
            OptionalInt32 VersionNumber;

            SetProfileLanguageResponse() :
                PlayFabBaseModel(),
                OperationResult(),
                VersionNumber()
            {}

            SetProfileLanguageResponse(const SetProfileLanguageResponse& src) :
                PlayFabBaseModel(),
                OperationResult(src.OperationResult),
                VersionNumber(src.VersionNumber)
            {}

            SetProfileLanguageResponse(const rapidjson::Value& obj) : SetProfileLanguageResponse()
            {
                readFromValue(obj);
            }

            ~SetProfileLanguageResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
