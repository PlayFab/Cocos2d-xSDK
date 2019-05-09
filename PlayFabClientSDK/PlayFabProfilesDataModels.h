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

        struct EntityStatisticChildValue : public PlayFabBaseModel
        {
            std::string ChildName;
            std::string Metadata;
            Int32 Value;

            EntityStatisticChildValue() :
                PlayFabBaseModel(),
                ChildName(),
                Metadata(),
                Value(0)
            {}

            EntityStatisticChildValue(const EntityStatisticChildValue& src) :
                PlayFabBaseModel(),
                ChildName(src.ChildName),
                Metadata(src.Metadata),
                Value(src.Value)
            {}

            EntityStatisticChildValue(const rapidjson::Value& obj) : EntityStatisticChildValue()
            {
                readFromValue(obj);
            }

            ~EntityStatisticChildValue();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EntityStatisticValue : public PlayFabBaseModel
        {
            std::map<std::string, EntityStatisticChildValue> ChildStatistics;
            std::string Metadata;
            std::string Name;
            OptionalInt32 Value;
            Int32 Version;

            EntityStatisticValue() :
                PlayFabBaseModel(),
                ChildStatistics(),
                Metadata(),
                Name(),
                Value(),
                Version(0)
            {}

            EntityStatisticValue(const EntityStatisticValue& src) :
                PlayFabBaseModel(),
                ChildStatistics(src.ChildStatistics),
                Metadata(src.Metadata),
                Name(src.Name),
                Value(src.Value),
                Version(src.Version)
            {}

            EntityStatisticValue(const rapidjson::Value& obj) : EntityStatisticValue()
            {
                readFromValue(obj);
            }

            ~EntityStatisticValue();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EntityProfileBody : public PlayFabBaseModel
        {
            std::string AvatarUrl;
            time_t Created;
            std::string DisplayName;
            EntityKey* Entity;
            std::string EntityChain;
            std::map<std::string, EntityProfileFileMetadata> Files;
            std::string Language;
            EntityLineage* Lineage;
            std::map<std::string, EntityDataObject> Objects;
            std::list<EntityPermissionStatement> Permissions;
            std::map<std::string, EntityStatisticValue> Statistics;
            Int32 VersionNumber;

            EntityProfileBody() :
                PlayFabBaseModel(),
                AvatarUrl(),
                Created(0),
                DisplayName(),
                Entity(NULL),
                EntityChain(),
                Files(),
                Language(),
                Lineage(NULL),
                Objects(),
                Permissions(),
                Statistics(),
                VersionNumber(0)
            {}

            EntityProfileBody(const EntityProfileBody& src) :
                PlayFabBaseModel(),
                AvatarUrl(src.AvatarUrl),
                Created(src.Created),
                DisplayName(src.DisplayName),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                EntityChain(src.EntityChain),
                Files(src.Files),
                Language(src.Language),
                Lineage(src.Lineage ? new EntityLineage(*src.Lineage) : NULL),
                Objects(src.Objects),
                Permissions(src.Permissions),
                Statistics(src.Statistics),
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
