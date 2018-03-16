#ifndef PLAYFAB_ENTITY_DATA_MODELS_H_
#define PLAYFAB_ENTITY_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace EntityModels
    {
        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup
        };

        void writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer);
        EntityTypes readEntityTypesFromValue(const rapidjson::Value& obj);

        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            Boxed<EntityTypes> Type;
            std::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
            {}

            EntityKey(const rapidjson::Value& obj) : EntityKey()
            {
                readFromValue(obj);
            }

            ~EntityKey();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AbortFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            OptionalInt32 ProfileVersion;

            AbortFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            AbortFileUploadsRequest(const AbortFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            AbortFileUploadsRequest(const rapidjson::Value& obj) : AbortFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~AbortFileUploadsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AbortFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;

            AbortFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                ProfileVersion(0)
            {}

            AbortFileUploadsResponse(const AbortFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                ProfileVersion(src.ProfileVersion)
            {}

            AbortFileUploadsResponse(const rapidjson::Value& obj) : AbortFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~AbortFileUploadsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AcceptGroupApplicationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            AcceptGroupApplicationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            AcceptGroupApplicationRequest(const AcceptGroupApplicationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            AcceptGroupApplicationRequest(const rapidjson::Value& obj) : AcceptGroupApplicationRequest()
            {
                readFromValue(obj);
            }

            ~AcceptGroupApplicationRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AcceptGroupInvitationRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;
            EntityKey Group;

            AcceptGroupInvitationRequest() :
                PlayFabBaseModel(),
                Entity(NULL),
                Group()
            {}

            AcceptGroupInvitationRequest(const AcceptGroupInvitationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Group(src.Group)
            {}

            AcceptGroupInvitationRequest(const rapidjson::Value& obj) : AcceptGroupInvitationRequest()
            {
                readFromValue(obj);
            }

            ~AcceptGroupInvitationRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            std::list<EntityKey> Members;
            std::string RoleId;

            AddMembersRequest() :
                PlayFabBaseModel(),
                Group(),
                Members(),
                RoleId()
            {}

            AddMembersRequest(const AddMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                Members(src.Members),
                RoleId(src.RoleId)
            {}

            AddMembersRequest(const rapidjson::Value& obj) : AddMembersRequest()
            {
                readFromValue(obj);
            }

            ~AddMembersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ApplyToGroupRequest : public PlayFabBaseModel
        {
            OptionalBool AutoAcceptOutstandingInvite;
            EntityKey* Entity;
            EntityKey Group;

            ApplyToGroupRequest() :
                PlayFabBaseModel(),
                AutoAcceptOutstandingInvite(),
                Entity(NULL),
                Group()
            {}

            ApplyToGroupRequest(const ApplyToGroupRequest& src) :
                PlayFabBaseModel(),
                AutoAcceptOutstandingInvite(src.AutoAcceptOutstandingInvite),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Group(src.Group)
            {}

            ApplyToGroupRequest(const rapidjson::Value& obj) : ApplyToGroupRequest()
            {
                readFromValue(obj);
            }

            ~ApplyToGroupRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EntityWithLineage : public PlayFabBaseModel
        {
            EntityKey* Key;
            std::map<std::string, EntityKey> Lineage;

            EntityWithLineage() :
                PlayFabBaseModel(),
                Key(NULL),
                Lineage()
            {}

            EntityWithLineage(const EntityWithLineage& src) :
                PlayFabBaseModel(),
                Key(src.Key ? new EntityKey(*src.Key) : NULL),
                Lineage(src.Lineage)
            {}

            EntityWithLineage(const rapidjson::Value& obj) : EntityWithLineage()
            {
                readFromValue(obj);
            }

            ~EntityWithLineage();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ApplyToGroupResponse : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            time_t Expires;
            EntityKey* Group;

            ApplyToGroupResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Expires(0),
                Group(NULL)
            {}

            ApplyToGroupResponse(const ApplyToGroupResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : NULL),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : NULL)
            {}

            ApplyToGroupResponse(const rapidjson::Value& obj) : ApplyToGroupResponse()
            {
                readFromValue(obj);
            }

            ~ApplyToGroupResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BlockEntityRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            BlockEntityRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            BlockEntityRequest(const BlockEntityRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            BlockEntityRequest(const rapidjson::Value& obj) : BlockEntityRequest()
            {
                readFromValue(obj);
            }

            ~BlockEntityRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ChangeMemberRoleRequest : public PlayFabBaseModel
        {
            std::string DestinationRoleId;
            EntityKey Group;
            std::list<EntityKey> Members;
            std::string OriginRoleId;

            ChangeMemberRoleRequest() :
                PlayFabBaseModel(),
                DestinationRoleId(),
                Group(),
                Members(),
                OriginRoleId()
            {}

            ChangeMemberRoleRequest(const ChangeMemberRoleRequest& src) :
                PlayFabBaseModel(),
                DestinationRoleId(src.DestinationRoleId),
                Group(src.Group),
                Members(src.Members),
                OriginRoleId(src.OriginRoleId)
            {}

            ChangeMemberRoleRequest(const rapidjson::Value& obj) : ChangeMemberRoleRequest()
            {
                readFromValue(obj);
            }

            ~ChangeMemberRoleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateGroupRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::string GroupName;

            CreateGroupRequest() :
                PlayFabBaseModel(),
                Entity(NULL),
                GroupName()
            {}

            CreateGroupRequest(const CreateGroupRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                GroupName(src.GroupName)
            {}

            CreateGroupRequest(const rapidjson::Value& obj) : CreateGroupRequest()
            {
                readFromValue(obj);
            }

            ~CreateGroupRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateGroupResponse : public PlayFabBaseModel
        {
            std::string AdminRoleId;
            time_t Created;
            EntityKey Group;
            std::string GroupName;
            std::string MemberRoleId;
            Int32 ProfileVersion;
            std::map<std::string, std::string> Roles;

            CreateGroupResponse() :
                PlayFabBaseModel(),
                AdminRoleId(),
                Created(0),
                Group(),
                GroupName(),
                MemberRoleId(),
                ProfileVersion(0),
                Roles()
            {}

            CreateGroupResponse(const CreateGroupResponse& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                Created(src.Created),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            CreateGroupResponse(const rapidjson::Value& obj) : CreateGroupResponse()
            {
                readFromValue(obj);
            }

            ~CreateGroupResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateGroupRoleRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            std::string RoleId;
            std::string RoleName;

            CreateGroupRoleRequest() :
                PlayFabBaseModel(),
                Group(),
                RoleId(),
                RoleName()
            {}

            CreateGroupRoleRequest(const CreateGroupRoleRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            CreateGroupRoleRequest(const rapidjson::Value& obj) : CreateGroupRoleRequest()
            {
                readFromValue(obj);
            }

            ~CreateGroupRoleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateGroupRoleResponse : public PlayFabBaseModel
        {
            Int32 ProfileVersion;
            std::string RoleId;
            std::string RoleName;

            CreateGroupRoleResponse() :
                PlayFabBaseModel(),
                ProfileVersion(0),
                RoleId(),
                RoleName()
            {}

            CreateGroupRoleResponse(const CreateGroupRoleResponse& src) :
                PlayFabBaseModel(),
                ProfileVersion(src.ProfileVersion),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            CreateGroupRoleResponse(const rapidjson::Value& obj) : CreateGroupRoleResponse()
            {
                readFromValue(obj);
            }

            ~CreateGroupRoleResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteFilesRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            OptionalInt32 ProfileVersion;

            DeleteFilesRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            DeleteFilesRequest(const DeleteFilesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            DeleteFilesRequest(const rapidjson::Value& obj) : DeleteFilesRequest()
            {
                readFromValue(obj);
            }

            ~DeleteFilesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteFilesResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;

            DeleteFilesResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                ProfileVersion(0)
            {}

            DeleteFilesResponse(const DeleteFilesResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                ProfileVersion(src.ProfileVersion)
            {}

            DeleteFilesResponse(const rapidjson::Value& obj) : DeleteFilesResponse()
            {
                readFromValue(obj);
            }

            ~DeleteFilesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteGroupRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            DeleteGroupRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            DeleteGroupRequest(const DeleteGroupRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            DeleteGroupRequest(const rapidjson::Value& obj) : DeleteGroupRequest()
            {
                readFromValue(obj);
            }

            ~DeleteGroupRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteRoleRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            std::string RoleId;

            DeleteRoleRequest() :
                PlayFabBaseModel(),
                Group(),
                RoleId()
            {}

            DeleteRoleRequest(const DeleteRoleRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            DeleteRoleRequest(const rapidjson::Value& obj) : DeleteRoleRequest()
            {
                readFromValue(obj);
            }

            ~DeleteRoleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        void writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer);
        EffectType readEffectTypeFromValue(const rapidjson::Value& obj);

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

        struct EntityMemberRole : public PlayFabBaseModel
        {
            std::list<EntityWithLineage> Members;
            std::string RoleId;
            std::string RoleName;

            EntityMemberRole() :
                PlayFabBaseModel(),
                Members(),
                RoleId(),
                RoleName()
            {}

            EntityMemberRole(const EntityMemberRole& src) :
                PlayFabBaseModel(),
                Members(src.Members),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            EntityMemberRole(const rapidjson::Value& obj) : EntityMemberRole()
            {
                readFromValue(obj);
            }

            ~EntityMemberRole();

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
            std::map<std::string, EntityDataObject> Objects;
            std::list<EntityPermissionStatement> Permissions;
            Int32 VersionNumber;

            EntityProfileBody() :
                PlayFabBaseModel(),
                Entity(NULL),
                EntityChain(),
                Files(),
                Objects(),
                Permissions(),
                VersionNumber(0)
            {}

            EntityProfileBody(const EntityProfileBody& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                EntityChain(src.EntityChain),
                Files(src.Files),
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

        struct FinalizeFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            std::list<std::string> FileNames;

            FinalizeFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames()
            {}

            FinalizeFileUploadsRequest(const FinalizeFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames)
            {}

            FinalizeFileUploadsRequest(const rapidjson::Value& obj) : FinalizeFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~FinalizeFileUploadsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFileMetadata : public PlayFabBaseModel
        {
            std::string Checksum;
            std::string DownloadUrl;
            std::string FileName;
            time_t LastModified;
            Int32 Size;

            GetFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                DownloadUrl(),
                FileName(),
                LastModified(0),
                Size(0)
            {}

            GetFileMetadata(const GetFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                DownloadUrl(src.DownloadUrl),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            GetFileMetadata(const rapidjson::Value& obj) : GetFileMetadata()
            {
                readFromValue(obj);
            }

            ~GetFileMetadata();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FinalizeFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<std::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            FinalizeFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Metadata(),
                ProfileVersion(0)
            {}

            FinalizeFileUploadsResponse(const FinalizeFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            FinalizeFileUploadsResponse(const rapidjson::Value& obj) : FinalizeFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~FinalizeFileUploadsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetEntityProfileRequest : public PlayFabBaseModel
        {
            OptionalBool DataAsObject;
            EntityKey Entity;

            GetEntityProfileRequest() :
                PlayFabBaseModel(),
                DataAsObject(),
                Entity()
            {}

            GetEntityProfileRequest(const GetEntityProfileRequest& src) :
                PlayFabBaseModel(),
                DataAsObject(src.DataAsObject),
                Entity(src.Entity)
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

        struct GetFilesRequest : public PlayFabBaseModel
        {
            EntityKey Entity;

            GetFilesRequest() :
                PlayFabBaseModel(),
                Entity()
            {}

            GetFilesRequest(const GetFilesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity)
            {}

            GetFilesRequest(const rapidjson::Value& obj) : GetFilesRequest()
            {
                readFromValue(obj);
            }

            ~GetFilesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFilesResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<std::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            GetFilesResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Metadata(),
                ProfileVersion(0)
            {}

            GetFilesResponse(const GetFilesResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            GetFilesResponse(const rapidjson::Value& obj) : GetFilesResponse()
            {
                readFromValue(obj);
            }

            ~GetFilesResponse();

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

        struct GetGroupRequest : public PlayFabBaseModel
        {
            EntityKey* Group;
            std::string GroupName;

            GetGroupRequest() :
                PlayFabBaseModel(),
                Group(NULL),
                GroupName()
            {}

            GetGroupRequest(const GetGroupRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group ? new EntityKey(*src.Group) : NULL),
                GroupName(src.GroupName)
            {}

            GetGroupRequest(const rapidjson::Value& obj) : GetGroupRequest()
            {
                readFromValue(obj);
            }

            ~GetGroupRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetGroupResponse : public PlayFabBaseModel
        {
            std::string AdminRoleId;
            time_t Created;
            EntityKey Group;
            std::string GroupName;
            std::string MemberRoleId;
            Int32 ProfileVersion;
            std::map<std::string, std::string> Roles;

            GetGroupResponse() :
                PlayFabBaseModel(),
                AdminRoleId(),
                Created(0),
                Group(),
                GroupName(),
                MemberRoleId(),
                ProfileVersion(0),
                Roles()
            {}

            GetGroupResponse(const GetGroupResponse& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                Created(src.Created),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            GetGroupResponse(const rapidjson::Value& obj) : GetGroupResponse()
            {
                readFromValue(obj);
            }

            ~GetGroupResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetObjectsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            OptionalBool EscapeObject;

            GetObjectsRequest() :
                PlayFabBaseModel(),
                Entity(),
                EscapeObject()
            {}

            GetObjectsRequest(const GetObjectsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                EscapeObject(src.EscapeObject)
            {}

            GetObjectsRequest(const rapidjson::Value& obj) : GetObjectsRequest()
            {
                readFromValue(obj);
            }

            ~GetObjectsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ObjectResult : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            ObjectResult() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            ObjectResult(const ObjectResult& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ObjectResult(const rapidjson::Value& obj) : ObjectResult()
            {
                readFromValue(obj);
            }

            ~ObjectResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetObjectsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<std::string, ObjectResult> Objects;
            Int32 ProfileVersion;

            GetObjectsResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Objects(),
                ProfileVersion(0)
            {}

            GetObjectsResponse(const GetObjectsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Objects(src.Objects),
                ProfileVersion(src.ProfileVersion)
            {}

            GetObjectsResponse(const rapidjson::Value& obj) : GetObjectsResponse()
            {
                readFromValue(obj);
            }

            ~GetObjectsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GroupApplication : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            time_t Expires;
            EntityKey* Group;

            GroupApplication() :
                PlayFabBaseModel(),
                Entity(NULL),
                Expires(0),
                Group(NULL)
            {}

            GroupApplication(const GroupApplication& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : NULL),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : NULL)
            {}

            GroupApplication(const rapidjson::Value& obj) : GroupApplication()
            {
                readFromValue(obj);
            }

            ~GroupApplication();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GroupBlock : public PlayFabBaseModel
        {
            EntityWithLineage* Entity;
            EntityKey Group;

            GroupBlock() :
                PlayFabBaseModel(),
                Entity(NULL),
                Group()
            {}

            GroupBlock(const GroupBlock& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityWithLineage(*src.Entity) : NULL),
                Group(src.Group)
            {}

            GroupBlock(const rapidjson::Value& obj) : GroupBlock()
            {
                readFromValue(obj);
            }

            ~GroupBlock();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GroupInvitation : public PlayFabBaseModel
        {
            time_t Expires;
            EntityKey* Group;
            EntityWithLineage* InvitedByEntity;
            EntityWithLineage* InvitedEntity;
            std::string RoleId;

            GroupInvitation() :
                PlayFabBaseModel(),
                Expires(0),
                Group(NULL),
                InvitedByEntity(NULL),
                InvitedEntity(NULL),
                RoleId()
            {}

            GroupInvitation(const GroupInvitation& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : NULL),
                InvitedByEntity(src.InvitedByEntity ? new EntityWithLineage(*src.InvitedByEntity) : NULL),
                InvitedEntity(src.InvitedEntity ? new EntityWithLineage(*src.InvitedEntity) : NULL),
                RoleId(src.RoleId)
            {}

            GroupInvitation(const rapidjson::Value& obj) : GroupInvitation()
            {
                readFromValue(obj);
            }

            ~GroupInvitation();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GroupRole : public PlayFabBaseModel
        {
            std::string RoleId;
            std::string RoleName;

            GroupRole() :
                PlayFabBaseModel(),
                RoleId(),
                RoleName()
            {}

            GroupRole(const GroupRole& src) :
                PlayFabBaseModel(),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            GroupRole(const rapidjson::Value& obj) : GroupRole()
            {
                readFromValue(obj);
            }

            ~GroupRole();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GroupWithRoles : public PlayFabBaseModel
        {
            EntityKey* Group;
            std::string GroupName;
            Int32 ProfileVersion;
            std::list<GroupRole> Roles;

            GroupWithRoles() :
                PlayFabBaseModel(),
                Group(NULL),
                GroupName(),
                ProfileVersion(0),
                Roles()
            {}

            GroupWithRoles(const GroupWithRoles& src) :
                PlayFabBaseModel(),
                Group(src.Group ? new EntityKey(*src.Group) : NULL),
                GroupName(src.GroupName),
                ProfileVersion(src.ProfileVersion),
                Roles(src.Roles)
            {}

            GroupWithRoles(const rapidjson::Value& obj) : GroupWithRoles()
            {
                readFromValue(obj);
            }

            ~GroupWithRoles();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InitiateFileUploadMetadata : public PlayFabBaseModel
        {
            std::string FileName;
            std::string UploadUrl;

            InitiateFileUploadMetadata() :
                PlayFabBaseModel(),
                FileName(),
                UploadUrl()
            {}

            InitiateFileUploadMetadata(const InitiateFileUploadMetadata& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                UploadUrl(src.UploadUrl)
            {}

            InitiateFileUploadMetadata(const rapidjson::Value& obj) : InitiateFileUploadMetadata()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadMetadata();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InitiateFileUploadsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            std::list<std::string> FileNames;
            OptionalInt32 ProfileVersion;

            InitiateFileUploadsRequest() :
                PlayFabBaseModel(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            InitiateFileUploadsRequest(const InitiateFileUploadsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            InitiateFileUploadsRequest(const rapidjson::Value& obj) : InitiateFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InitiateFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;
            std::list<InitiateFileUploadMetadata> UploadDetails;

            InitiateFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                ProfileVersion(0),
                UploadDetails()
            {}

            InitiateFileUploadsResponse(const InitiateFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                ProfileVersion(src.ProfileVersion),
                UploadDetails(src.UploadDetails)
            {}

            InitiateFileUploadsResponse(const rapidjson::Value& obj) : InitiateFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InviteToGroupRequest : public PlayFabBaseModel
        {
            OptionalBool AutoAcceptOutstandingApplication;
            EntityKey Entity;
            EntityKey Group;
            std::string RoleId;

            InviteToGroupRequest() :
                PlayFabBaseModel(),
                AutoAcceptOutstandingApplication(),
                Entity(),
                Group(),
                RoleId()
            {}

            InviteToGroupRequest(const InviteToGroupRequest& src) :
                PlayFabBaseModel(),
                AutoAcceptOutstandingApplication(src.AutoAcceptOutstandingApplication),
                Entity(src.Entity),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            InviteToGroupRequest(const rapidjson::Value& obj) : InviteToGroupRequest()
            {
                readFromValue(obj);
            }

            ~InviteToGroupRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InviteToGroupResponse : public PlayFabBaseModel
        {
            time_t Expires;
            EntityKey* Group;
            EntityWithLineage* InvitedByEntity;
            EntityWithLineage* InvitedEntity;
            std::string RoleId;

            InviteToGroupResponse() :
                PlayFabBaseModel(),
                Expires(0),
                Group(NULL),
                InvitedByEntity(NULL),
                InvitedEntity(NULL),
                RoleId()
            {}

            InviteToGroupResponse(const InviteToGroupResponse& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                Group(src.Group ? new EntityKey(*src.Group) : NULL),
                InvitedByEntity(src.InvitedByEntity ? new EntityWithLineage(*src.InvitedByEntity) : NULL),
                InvitedEntity(src.InvitedEntity ? new EntityWithLineage(*src.InvitedEntity) : NULL),
                RoleId(src.RoleId)
            {}

            InviteToGroupResponse(const rapidjson::Value& obj) : InviteToGroupResponse()
            {
                readFromValue(obj);
            }

            ~InviteToGroupResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct IsMemberRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;
            std::string RoleId;

            IsMemberRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group(),
                RoleId()
            {}

            IsMemberRequest(const IsMemberRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group),
                RoleId(src.RoleId)
            {}

            IsMemberRequest(const rapidjson::Value& obj) : IsMemberRequest()
            {
                readFromValue(obj);
            }

            ~IsMemberRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct IsMemberResponse : public PlayFabBaseModel
        {
            bool IsMember;

            IsMemberResponse() :
                PlayFabBaseModel(),
                IsMember(false)
            {}

            IsMemberResponse(const IsMemberResponse& src) :
                PlayFabBaseModel(),
                IsMember(src.IsMember)
            {}

            IsMemberResponse(const rapidjson::Value& obj) : IsMemberResponse()
            {
                readFromValue(obj);
            }

            ~IsMemberResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListGroupApplicationsRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupApplicationsRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupApplicationsRequest(const ListGroupApplicationsRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupApplicationsRequest(const rapidjson::Value& obj) : ListGroupApplicationsRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupApplicationsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListGroupApplicationsResponse : public PlayFabBaseModel
        {
            std::list<GroupApplication> Applications;

            ListGroupApplicationsResponse() :
                PlayFabBaseModel(),
                Applications()
            {}

            ListGroupApplicationsResponse(const ListGroupApplicationsResponse& src) :
                PlayFabBaseModel(),
                Applications(src.Applications)
            {}

            ListGroupApplicationsResponse(const rapidjson::Value& obj) : ListGroupApplicationsResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupApplicationsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListGroupBlocksRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupBlocksRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupBlocksRequest(const ListGroupBlocksRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupBlocksRequest(const rapidjson::Value& obj) : ListGroupBlocksRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupBlocksRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListGroupBlocksResponse : public PlayFabBaseModel
        {
            std::list<GroupBlock> BlockedEntities;

            ListGroupBlocksResponse() :
                PlayFabBaseModel(),
                BlockedEntities()
            {}

            ListGroupBlocksResponse(const ListGroupBlocksResponse& src) :
                PlayFabBaseModel(),
                BlockedEntities(src.BlockedEntities)
            {}

            ListGroupBlocksResponse(const rapidjson::Value& obj) : ListGroupBlocksResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupBlocksResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListGroupInvitationsRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupInvitationsRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupInvitationsRequest(const ListGroupInvitationsRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupInvitationsRequest(const rapidjson::Value& obj) : ListGroupInvitationsRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupInvitationsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListGroupInvitationsResponse : public PlayFabBaseModel
        {
            std::list<GroupInvitation> Invitations;

            ListGroupInvitationsResponse() :
                PlayFabBaseModel(),
                Invitations()
            {}

            ListGroupInvitationsResponse(const ListGroupInvitationsResponse& src) :
                PlayFabBaseModel(),
                Invitations(src.Invitations)
            {}

            ListGroupInvitationsResponse(const rapidjson::Value& obj) : ListGroupInvitationsResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupInvitationsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListGroupMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;

            ListGroupMembersRequest() :
                PlayFabBaseModel(),
                Group()
            {}

            ListGroupMembersRequest(const ListGroupMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group)
            {}

            ListGroupMembersRequest(const rapidjson::Value& obj) : ListGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~ListGroupMembersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListGroupMembersResponse : public PlayFabBaseModel
        {
            std::list<EntityMemberRole> Members;

            ListGroupMembersResponse() :
                PlayFabBaseModel(),
                Members()
            {}

            ListGroupMembersResponse(const ListGroupMembersResponse& src) :
                PlayFabBaseModel(),
                Members(src.Members)
            {}

            ListGroupMembersResponse(const rapidjson::Value& obj) : ListGroupMembersResponse()
            {
                readFromValue(obj);
            }

            ~ListGroupMembersResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListMembershipOpportunitiesRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            ListMembershipOpportunitiesRequest() :
                PlayFabBaseModel(),
                Entity(NULL)
            {}

            ListMembershipOpportunitiesRequest(const ListMembershipOpportunitiesRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            ListMembershipOpportunitiesRequest(const rapidjson::Value& obj) : ListMembershipOpportunitiesRequest()
            {
                readFromValue(obj);
            }

            ~ListMembershipOpportunitiesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListMembershipOpportunitiesResponse : public PlayFabBaseModel
        {
            std::list<GroupApplication> Applications;
            std::list<GroupInvitation> Invitations;

            ListMembershipOpportunitiesResponse() :
                PlayFabBaseModel(),
                Applications(),
                Invitations()
            {}

            ListMembershipOpportunitiesResponse(const ListMembershipOpportunitiesResponse& src) :
                PlayFabBaseModel(),
                Applications(src.Applications),
                Invitations(src.Invitations)
            {}

            ListMembershipOpportunitiesResponse(const rapidjson::Value& obj) : ListMembershipOpportunitiesResponse()
            {
                readFromValue(obj);
            }

            ~ListMembershipOpportunitiesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListMembershipRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            ListMembershipRequest() :
                PlayFabBaseModel(),
                Entity(NULL)
            {}

            ListMembershipRequest(const ListMembershipRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            ListMembershipRequest(const rapidjson::Value& obj) : ListMembershipRequest()
            {
                readFromValue(obj);
            }

            ~ListMembershipRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListMembershipResponse : public PlayFabBaseModel
        {
            std::list<GroupWithRoles> Groups;

            ListMembershipResponse() :
                PlayFabBaseModel(),
                Groups()
            {}

            ListMembershipResponse(const ListMembershipResponse& src) :
                PlayFabBaseModel(),
                Groups(src.Groups)
            {}

            ListMembershipResponse(const rapidjson::Value& obj) : ListMembershipResponse()
            {
                readFromValue(obj);
            }

            ~ListMembershipResponse();

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

        struct RemoveGroupApplicationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            RemoveGroupApplicationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            RemoveGroupApplicationRequest(const RemoveGroupApplicationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            RemoveGroupApplicationRequest(const rapidjson::Value& obj) : RemoveGroupApplicationRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGroupApplicationRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveGroupInvitationRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            RemoveGroupInvitationRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            RemoveGroupInvitationRequest(const RemoveGroupInvitationRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            RemoveGroupInvitationRequest(const rapidjson::Value& obj) : RemoveGroupInvitationRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGroupInvitationRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveMembersRequest : public PlayFabBaseModel
        {
            EntityKey Group;
            std::list<EntityKey> Members;
            std::string RoleId;

            RemoveMembersRequest() :
                PlayFabBaseModel(),
                Group(),
                Members(),
                RoleId()
            {}

            RemoveMembersRequest(const RemoveMembersRequest& src) :
                PlayFabBaseModel(),
                Group(src.Group),
                Members(src.Members),
                RoleId(src.RoleId)
            {}

            RemoveMembersRequest(const rapidjson::Value& obj) : RemoveMembersRequest()
            {
                readFromValue(obj);
            }

            ~RemoveMembersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

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

        struct SetObject : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            OptionalBool DeleteObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            SetObject() :
                PlayFabBaseModel(),
                DataObject(),
                DeleteObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            SetObject(const SetObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                DeleteObject(src.DeleteObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            SetObject(const rapidjson::Value& obj) : SetObject()
            {
                readFromValue(obj);
            }

            ~SetObject();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetObjectInfo : public PlayFabBaseModel
        {
            std::string ObjectName;
            std::string OperationReason;
            Boxed<OperationTypes> SetResult;

            SetObjectInfo() :
                PlayFabBaseModel(),
                ObjectName(),
                OperationReason(),
                SetResult()
            {}

            SetObjectInfo(const SetObjectInfo& src) :
                PlayFabBaseModel(),
                ObjectName(src.ObjectName),
                OperationReason(src.OperationReason),
                SetResult(src.SetResult)
            {}

            SetObjectInfo(const rapidjson::Value& obj) : SetObjectInfo()
            {
                readFromValue(obj);
            }

            ~SetObjectInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetObjectsRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            OptionalInt32 ExpectedProfileVersion;
            std::list<SetObject> Objects;

            SetObjectsRequest() :
                PlayFabBaseModel(),
                Entity(),
                ExpectedProfileVersion(),
                Objects()
            {}

            SetObjectsRequest(const SetObjectsRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Objects(src.Objects)
            {}

            SetObjectsRequest(const rapidjson::Value& obj) : SetObjectsRequest()
            {
                readFromValue(obj);
            }

            ~SetObjectsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetObjectsResponse : public PlayFabBaseModel
        {
            Int32 ProfileVersion;
            std::list<SetObjectInfo> SetResults;

            SetObjectsResponse() :
                PlayFabBaseModel(),
                ProfileVersion(0),
                SetResults()
            {}

            SetObjectsResponse(const SetObjectsResponse& src) :
                PlayFabBaseModel(),
                ProfileVersion(src.ProfileVersion),
                SetResults(src.SetResults)
            {}

            SetObjectsResponse(const rapidjson::Value& obj) : SetObjectsResponse()
            {
                readFromValue(obj);
            }

            ~SetObjectsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnblockEntityRequest : public PlayFabBaseModel
        {
            EntityKey Entity;
            EntityKey Group;

            UnblockEntityRequest() :
                PlayFabBaseModel(),
                Entity(),
                Group()
            {}

            UnblockEntityRequest(const UnblockEntityRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
                Group(src.Group)
            {}

            UnblockEntityRequest(const rapidjson::Value& obj) : UnblockEntityRequest()
            {
                readFromValue(obj);
            }

            ~UnblockEntityRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateGroupRequest : public PlayFabBaseModel
        {
            std::string AdminRoleId;
            OptionalInt32 ExpectedProfileVersion;
            EntityKey Group;
            std::string GroupName;
            std::string MemberRoleId;

            UpdateGroupRequest() :
                PlayFabBaseModel(),
                AdminRoleId(),
                ExpectedProfileVersion(),
                Group(),
                GroupName(),
                MemberRoleId()
            {}

            UpdateGroupRequest(const UpdateGroupRequest& src) :
                PlayFabBaseModel(),
                AdminRoleId(src.AdminRoleId),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Group(src.Group),
                GroupName(src.GroupName),
                MemberRoleId(src.MemberRoleId)
            {}

            UpdateGroupRequest(const rapidjson::Value& obj) : UpdateGroupRequest()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateGroupResponse : public PlayFabBaseModel
        {
            std::string OperationReason;
            Int32 ProfileVersion;
            Boxed<OperationTypes> SetResult;

            UpdateGroupResponse() :
                PlayFabBaseModel(),
                OperationReason(),
                ProfileVersion(0),
                SetResult()
            {}

            UpdateGroupResponse(const UpdateGroupResponse& src) :
                PlayFabBaseModel(),
                OperationReason(src.OperationReason),
                ProfileVersion(src.ProfileVersion),
                SetResult(src.SetResult)
            {}

            UpdateGroupResponse(const rapidjson::Value& obj) : UpdateGroupResponse()
            {
                readFromValue(obj);
            }

            ~UpdateGroupResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateGroupRoleRequest : public PlayFabBaseModel
        {
            OptionalInt32 ExpectedProfileVersion;
            EntityKey Group;
            std::string RoleId;
            std::string RoleName;

            UpdateGroupRoleRequest() :
                PlayFabBaseModel(),
                ExpectedProfileVersion(),
                Group(),
                RoleId(),
                RoleName()
            {}

            UpdateGroupRoleRequest(const UpdateGroupRoleRequest& src) :
                PlayFabBaseModel(),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Group(src.Group),
                RoleId(src.RoleId),
                RoleName(src.RoleName)
            {}

            UpdateGroupRoleRequest(const rapidjson::Value& obj) : UpdateGroupRoleRequest()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRoleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateGroupRoleResponse : public PlayFabBaseModel
        {
            std::string OperationReason;
            Int32 ProfileVersion;
            Boxed<OperationTypes> SetResult;

            UpdateGroupRoleResponse() :
                PlayFabBaseModel(),
                OperationReason(),
                ProfileVersion(0),
                SetResult()
            {}

            UpdateGroupRoleResponse(const UpdateGroupRoleResponse& src) :
                PlayFabBaseModel(),
                OperationReason(src.OperationReason),
                ProfileVersion(src.ProfileVersion),
                SetResult(src.SetResult)
            {}

            UpdateGroupRoleResponse(const rapidjson::Value& obj) : UpdateGroupRoleResponse()
            {
                readFromValue(obj);
            }

            ~UpdateGroupRoleResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
