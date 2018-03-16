#include "PlayFabEntityDataModels.h"

using namespace PlayFab;
using namespace PlayFab::EntityModels;
using namespace rapidjson;

void PlayFab::EntityModels::writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case EntityTypestitle: writer.String("title"); break;
    case EntityTypesmaster_player_account: writer.String("master_player_account"); break;
    case EntityTypestitle_player_account: writer.String("title_player_account"); break;
    case EntityTypescharacter: writer.String("character"); break;
    case EntityTypesgroup: writer.String("group"); break;

    }
}

EntityTypes PlayFab::EntityModels::readEntityTypesFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, EntityTypes> _EntityTypesMap;
    if (_EntityTypesMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _EntityTypesMap["title"] = EntityTypestitle;
        _EntityTypesMap["master_player_account"] = EntityTypesmaster_player_account;
        _EntityTypesMap["title_player_account"] = EntityTypestitle_player_account;
        _EntityTypesMap["character"] = EntityTypescharacter;
        _EntityTypesMap["group"] = EntityTypesgroup;

    }

    auto output = _EntityTypesMap.find(obj.GetString());
    if (output != _EntityTypesMap.end())
        return output->second;

    return EntityTypestitle; // Basically critical fail
}

EntityKey::~EntityKey()
{

}

void EntityKey::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Id"); writer.String(Id.c_str());
    if (Type.notNull()) { writer.String("Type"); writeEntityTypesEnumJSON(Type, writer); }
    if (TypeString.length() > 0) { writer.String("TypeString"); writer.String(TypeString.c_str()); }
    writer.EndObject();
}

bool EntityKey::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator Type_member = obj.FindMember("Type");
    if (Type_member != obj.MemberEnd() && !Type_member->value.IsNull()) Type = readEntityTypesFromValue(Type_member->value);
    const Value::ConstMemberIterator TypeString_member = obj.FindMember("TypeString");
    if (TypeString_member != obj.MemberEnd() && !TypeString_member->value.IsNull()) TypeString = TypeString_member->value.GetString();

    return true;
}

AbortFileUploadsRequest::~AbortFileUploadsRequest()
{

}

void AbortFileUploadsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("FileNames");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = FileNames.begin(); iter != FileNames.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    if (ProfileVersion.notNull()) { writer.String("ProfileVersion"); writer.Int(ProfileVersion); }
    writer.EndObject();
}

bool AbortFileUploadsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
    if (FileNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = FileNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            FileNames.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

    return true;
}

AbortFileUploadsResponse::~AbortFileUploadsResponse()
{
    if (Entity != NULL) delete Entity;

}

void AbortFileUploadsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    writer.EndObject();
}

bool AbortFileUploadsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

    return true;
}

AcceptGroupApplicationRequest::~AcceptGroupApplicationRequest()
{

}

void AcceptGroupApplicationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool AcceptGroupApplicationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

AcceptGroupInvitationRequest::~AcceptGroupInvitationRequest()
{
    if (Entity != NULL) delete Entity;

}

void AcceptGroupInvitationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool AcceptGroupInvitationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

AddMembersRequest::~AddMembersRequest()
{

}

void AddMembersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    writer.String("Members");
    writer.StartArray();
    for (std::list<EntityKey>::iterator iter = Members.begin(); iter != Members.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    writer.EndObject();
}

bool AddMembersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
    if (Members_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Members_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Members.push_back(EntityKey(memberList[i]));
        }
    }
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

    return true;
}

ApplyToGroupRequest::~ApplyToGroupRequest()
{
    if (Entity != NULL) delete Entity;

}

void ApplyToGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AutoAcceptOutstandingInvite.notNull()) { writer.String("AutoAcceptOutstandingInvite"); writer.Bool(AutoAcceptOutstandingInvite); }
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool ApplyToGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AutoAcceptOutstandingInvite_member = obj.FindMember("AutoAcceptOutstandingInvite");
    if (AutoAcceptOutstandingInvite_member != obj.MemberEnd() && !AutoAcceptOutstandingInvite_member->value.IsNull()) AutoAcceptOutstandingInvite = AutoAcceptOutstandingInvite_member->value.GetBool();
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

EntityWithLineage::~EntityWithLineage()
{
    if (Key != NULL) delete Key;

}

void EntityWithLineage::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Key != NULL) { writer.String("Key"); Key->writeJSON(writer); }
    if (!Lineage.empty()) {
        writer.String("Lineage");
        writer.StartObject();
        for (std::map<std::string, EntityKey>::iterator iter = Lineage.begin(); iter != Lineage.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool EntityWithLineage::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = new EntityKey(Key_member->value);
    const Value::ConstMemberIterator Lineage_member = obj.FindMember("Lineage");
    if (Lineage_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Lineage_member->value.MemberBegin(); iter != Lineage_member->value.MemberEnd(); ++iter) {
            Lineage[iter->name.GetString()] = EntityKey(iter->value);
        }
    }

    return true;
}

ApplyToGroupResponse::~ApplyToGroupResponse()
{
    if (Entity != NULL) delete Entity;
    if (Group != NULL) delete Group;

}

void ApplyToGroupResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("Expires"); writeDatetime(Expires, writer);
    if (Group != NULL) { writer.String("Group"); Group->writeJSON(writer); }
    writer.EndObject();
}

bool ApplyToGroupResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
    const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
    if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);

    return true;
}

BlockEntityRequest::~BlockEntityRequest()
{

}

void BlockEntityRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool BlockEntityRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

ChangeMemberRoleRequest::~ChangeMemberRoleRequest()
{

}

void ChangeMemberRoleRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DestinationRoleId.length() > 0) { writer.String("DestinationRoleId"); writer.String(DestinationRoleId.c_str()); }
    writer.String("Group"); Group.writeJSON(writer);
    writer.String("Members");
    writer.StartArray();
    for (std::list<EntityKey>::iterator iter = Members.begin(); iter != Members.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.String("OriginRoleId"); writer.String(OriginRoleId.c_str());
    writer.EndObject();
}

bool ChangeMemberRoleRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DestinationRoleId_member = obj.FindMember("DestinationRoleId");
    if (DestinationRoleId_member != obj.MemberEnd() && !DestinationRoleId_member->value.IsNull()) DestinationRoleId = DestinationRoleId_member->value.GetString();
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
    if (Members_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Members_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Members.push_back(EntityKey(memberList[i]));
        }
    }
    const Value::ConstMemberIterator OriginRoleId_member = obj.FindMember("OriginRoleId");
    if (OriginRoleId_member != obj.MemberEnd() && !OriginRoleId_member->value.IsNull()) OriginRoleId = OriginRoleId_member->value.GetString();

    return true;
}

CreateGroupRequest::~CreateGroupRequest()
{
    if (Entity != NULL) delete Entity;

}

void CreateGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("GroupName"); writer.String(GroupName.c_str());
    writer.EndObject();
}

bool CreateGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
    if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();

    return true;
}

CreateGroupResponse::~CreateGroupResponse()
{

}

void CreateGroupResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AdminRoleId.length() > 0) { writer.String("AdminRoleId"); writer.String(AdminRoleId.c_str()); }
    writer.String("Created"); writeDatetime(Created, writer);
    writer.String("Group"); Group.writeJSON(writer);
    if (GroupName.length() > 0) { writer.String("GroupName"); writer.String(GroupName.c_str()); }
    if (MemberRoleId.length() > 0) { writer.String("MemberRoleId"); writer.String(MemberRoleId.c_str()); }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    if (!Roles.empty()) {
        writer.String("Roles");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Roles.begin(); iter != Roles.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool CreateGroupResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
    if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
    if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
    const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
    if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
    if (Roles_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Roles_member->value.MemberBegin(); iter != Roles_member->value.MemberEnd(); ++iter) {
            Roles[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

CreateGroupRoleRequest::~CreateGroupRoleRequest()
{

}

void CreateGroupRoleRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    writer.String("RoleId"); writer.String(RoleId.c_str());
    writer.String("RoleName"); writer.String(RoleName.c_str());
    writer.EndObject();
}

bool CreateGroupRoleRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
    const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
    if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

    return true;
}

CreateGroupRoleResponse::~CreateGroupRoleResponse()
{

}

void CreateGroupRoleResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    if (RoleName.length() > 0) { writer.String("RoleName"); writer.String(RoleName.c_str()); }
    writer.EndObject();
}

bool CreateGroupRoleResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
    const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
    if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

    return true;
}

DeleteFilesRequest::~DeleteFilesRequest()
{

}

void DeleteFilesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("FileNames");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = FileNames.begin(); iter != FileNames.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    if (ProfileVersion.notNull()) { writer.String("ProfileVersion"); writer.Int(ProfileVersion); }
    writer.EndObject();
}

bool DeleteFilesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
    if (FileNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = FileNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            FileNames.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

    return true;
}

DeleteFilesResponse::~DeleteFilesResponse()
{
    if (Entity != NULL) delete Entity;

}

void DeleteFilesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    writer.EndObject();
}

bool DeleteFilesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

    return true;
}

DeleteGroupRequest::~DeleteGroupRequest()
{

}

void DeleteGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool DeleteGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

DeleteRoleRequest::~DeleteRoleRequest()
{

}

void DeleteRoleRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    writer.EndObject();
}

bool DeleteRoleRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

    return true;
}
void PlayFab::EntityModels::writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case EffectTypeAllow: writer.String("Allow"); break;
    case EffectTypeDeny: writer.String("Deny"); break;

    }
}

EffectType PlayFab::EntityModels::readEffectTypeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, EffectType> _EffectTypeMap;
    if (_EffectTypeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _EffectTypeMap["Allow"] = EffectTypeAllow;
        _EffectTypeMap["Deny"] = EffectTypeDeny;

    }

    auto output = _EffectTypeMap.find(obj.GetString());
    if (output != _EffectTypeMap.end())
        return output->second;

    return EffectTypeAllow; // Basically critical fail
}

EmptyResult::~EmptyResult()
{

}

void EmptyResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool EmptyResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

EntityDataObject::~EntityDataObject()
{

}

void EntityDataObject::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DataObject.notNull()) { writer.String("DataObject"); DataObject.writeJSON(writer); }
    if (EscapedDataObject.length() > 0) { writer.String("EscapedDataObject"); writer.String(EscapedDataObject.c_str()); }
    if (ObjectName.length() > 0) { writer.String("ObjectName"); writer.String(ObjectName.c_str()); }
    writer.EndObject();
}

bool EntityDataObject::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataObject_member = obj.FindMember("DataObject");
    if (DataObject_member != obj.MemberEnd() && !DataObject_member->value.IsNull()) DataObject = MultitypeVar(DataObject_member->value);
    const Value::ConstMemberIterator EscapedDataObject_member = obj.FindMember("EscapedDataObject");
    if (EscapedDataObject_member != obj.MemberEnd() && !EscapedDataObject_member->value.IsNull()) EscapedDataObject = EscapedDataObject_member->value.GetString();
    const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
    if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();

    return true;
}

EntityMemberRole::~EntityMemberRole()
{

}

void EntityMemberRole::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Members.empty()) {
        writer.String("Members");
        writer.StartArray();
        for (std::list<EntityWithLineage>::iterator iter = Members.begin(); iter != Members.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    if (RoleName.length() > 0) { writer.String("RoleName"); writer.String(RoleName.c_str()); }
    writer.EndObject();
}

bool EntityMemberRole::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
    if (Members_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Members_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Members.push_back(EntityWithLineage(memberList[i]));
        }
    }
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
    const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
    if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

    return true;
}

EntityPermissionStatement::~EntityPermissionStatement()
{

}

void EntityPermissionStatement::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Action"); writer.String(Action.c_str());
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    if (Condition.notNull()) { writer.String("Condition"); Condition.writeJSON(writer); }
    writer.String("Effect"); writeEffectTypeEnumJSON(Effect, writer);
    writer.String("Principal"); Principal.writeJSON(writer);
    writer.String("Resource"); writer.String(Resource.c_str());
    writer.EndObject();
}

bool EntityPermissionStatement::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Action_member = obj.FindMember("Action");
    if (Action_member != obj.MemberEnd() && !Action_member->value.IsNull()) Action = Action_member->value.GetString();
    const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
    if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    const Value::ConstMemberIterator Condition_member = obj.FindMember("Condition");
    if (Condition_member != obj.MemberEnd() && !Condition_member->value.IsNull()) Condition = MultitypeVar(Condition_member->value);
    const Value::ConstMemberIterator Effect_member = obj.FindMember("Effect");
    if (Effect_member != obj.MemberEnd() && !Effect_member->value.IsNull()) Effect = readEffectTypeFromValue(Effect_member->value);
    const Value::ConstMemberIterator Principal_member = obj.FindMember("Principal");
    if (Principal_member != obj.MemberEnd() && !Principal_member->value.IsNull()) Principal = MultitypeVar(Principal_member->value);
    const Value::ConstMemberIterator Resource_member = obj.FindMember("Resource");
    if (Resource_member != obj.MemberEnd() && !Resource_member->value.IsNull()) Resource = Resource_member->value.GetString();

    return true;
}

EntityProfileFileMetadata::~EntityProfileFileMetadata()
{

}

void EntityProfileFileMetadata::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Checksum.length() > 0) { writer.String("Checksum"); writer.String(Checksum.c_str()); }
    if (FileName.length() > 0) { writer.String("FileName"); writer.String(FileName.c_str()); }
    writer.String("LastModified"); writeDatetime(LastModified, writer);
    writer.String("Size"); writer.Int(Size);
    writer.EndObject();
}

bool EntityProfileFileMetadata::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Checksum_member = obj.FindMember("Checksum");
    if (Checksum_member != obj.MemberEnd() && !Checksum_member->value.IsNull()) Checksum = Checksum_member->value.GetString();
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
    const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
    if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);
    const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
    if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetInt();

    return true;
}

EntityProfileBody::~EntityProfileBody()
{
    if (Entity != NULL) delete Entity;

}

void EntityProfileBody::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (EntityChain.length() > 0) { writer.String("EntityChain"); writer.String(EntityChain.c_str()); }
    if (!Files.empty()) {
        writer.String("Files");
        writer.StartObject();
        for (std::map<std::string, EntityProfileFileMetadata>::iterator iter = Files.begin(); iter != Files.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    if (!Objects.empty()) {
        writer.String("Objects");
        writer.StartObject();
        for (std::map<std::string, EntityDataObject>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    if (!Permissions.empty()) {
        writer.String("Permissions");
        writer.StartArray();
        for (std::list<EntityPermissionStatement>::iterator iter = Permissions.begin(); iter != Permissions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.String("VersionNumber"); writer.Int(VersionNumber);
    writer.EndObject();
}

bool EntityProfileBody::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator EntityChain_member = obj.FindMember("EntityChain");
    if (EntityChain_member != obj.MemberEnd() && !EntityChain_member->value.IsNull()) EntityChain = EntityChain_member->value.GetString();
    const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
    if (Files_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Files_member->value.MemberBegin(); iter != Files_member->value.MemberEnd(); ++iter) {
            Files[iter->name.GetString()] = EntityProfileFileMetadata(iter->value);
        }
    }
    const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
    if (Objects_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Objects_member->value.MemberBegin(); iter != Objects_member->value.MemberEnd(); ++iter) {
            Objects[iter->name.GetString()] = EntityDataObject(iter->value);
        }
    }
    const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
    if (Permissions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Permissions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Permissions.push_back(EntityPermissionStatement(memberList[i]));
        }
    }
    const Value::ConstMemberIterator VersionNumber_member = obj.FindMember("VersionNumber");
    if (VersionNumber_member != obj.MemberEnd() && !VersionNumber_member->value.IsNull()) VersionNumber = VersionNumber_member->value.GetInt();

    return true;
}

FinalizeFileUploadsRequest::~FinalizeFileUploadsRequest()
{

}

void FinalizeFileUploadsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("FileNames");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = FileNames.begin(); iter != FileNames.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.EndObject();
}

bool FinalizeFileUploadsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
    if (FileNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = FileNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            FileNames.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetFileMetadata::~GetFileMetadata()
{

}

void GetFileMetadata::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Checksum.length() > 0) { writer.String("Checksum"); writer.String(Checksum.c_str()); }
    if (DownloadUrl.length() > 0) { writer.String("DownloadUrl"); writer.String(DownloadUrl.c_str()); }
    if (FileName.length() > 0) { writer.String("FileName"); writer.String(FileName.c_str()); }
    writer.String("LastModified"); writeDatetime(LastModified, writer);
    writer.String("Size"); writer.Int(Size);
    writer.EndObject();
}

bool GetFileMetadata::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Checksum_member = obj.FindMember("Checksum");
    if (Checksum_member != obj.MemberEnd() && !Checksum_member->value.IsNull()) Checksum = Checksum_member->value.GetString();
    const Value::ConstMemberIterator DownloadUrl_member = obj.FindMember("DownloadUrl");
    if (DownloadUrl_member != obj.MemberEnd() && !DownloadUrl_member->value.IsNull()) DownloadUrl = DownloadUrl_member->value.GetString();
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
    const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
    if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);
    const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
    if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetInt();

    return true;
}

FinalizeFileUploadsResponse::~FinalizeFileUploadsResponse()
{
    if (Entity != NULL) delete Entity;

}

void FinalizeFileUploadsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, GetFileMetadata>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    writer.EndObject();
}

bool FinalizeFileUploadsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = GetFileMetadata(iter->value);
        }
    }
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

    return true;
}

GetEntityProfileRequest::~GetEntityProfileRequest()
{

}

void GetEntityProfileRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DataAsObject.notNull()) { writer.String("DataAsObject"); writer.Bool(DataAsObject); }
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.EndObject();
}

bool GetEntityProfileRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataAsObject_member = obj.FindMember("DataAsObject");
    if (DataAsObject_member != obj.MemberEnd() && !DataAsObject_member->value.IsNull()) DataAsObject = DataAsObject_member->value.GetBool();
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);

    return true;
}

GetEntityProfileResponse::~GetEntityProfileResponse()
{
    if (Profile != NULL) delete Profile;

}

void GetEntityProfileResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Profile != NULL) { writer.String("Profile"); Profile->writeJSON(writer); }
    writer.EndObject();
}

bool GetEntityProfileResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
    if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new EntityProfileBody(Profile_member->value);

    return true;
}

GetEntityTokenRequest::~GetEntityTokenRequest()
{
    if (Entity != NULL) delete Entity;

}

void GetEntityTokenRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool GetEntityTokenRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

GetEntityTokenResponse::~GetEntityTokenResponse()
{
    if (Entity != NULL) delete Entity;

}

void GetEntityTokenResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (EntityToken.length() > 0) { writer.String("EntityToken"); writer.String(EntityToken.c_str()); }
    if (TokenExpiration.notNull()) { writer.String("TokenExpiration"); writeDatetime(TokenExpiration, writer); }
    writer.EndObject();
}

bool GetEntityTokenResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator EntityToken_member = obj.FindMember("EntityToken");
    if (EntityToken_member != obj.MemberEnd() && !EntityToken_member->value.IsNull()) EntityToken = EntityToken_member->value.GetString();
    const Value::ConstMemberIterator TokenExpiration_member = obj.FindMember("TokenExpiration");
    if (TokenExpiration_member != obj.MemberEnd() && !TokenExpiration_member->value.IsNull()) TokenExpiration = readDatetime(TokenExpiration_member->value);

    return true;
}

GetFilesRequest::~GetFilesRequest()
{

}

void GetFilesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.EndObject();
}

bool GetFilesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);

    return true;
}

GetFilesResponse::~GetFilesResponse()
{
    if (Entity != NULL) delete Entity;

}

void GetFilesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, GetFileMetadata>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    writer.EndObject();
}

bool GetFilesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = GetFileMetadata(iter->value);
        }
    }
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

    return true;
}

GetGlobalPolicyRequest::~GetGlobalPolicyRequest()
{

}

void GetGlobalPolicyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool GetGlobalPolicyRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetGlobalPolicyResponse::~GetGlobalPolicyResponse()
{

}

void GetGlobalPolicyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Permissions.empty()) {
        writer.String("Permissions");
        writer.StartArray();
        for (std::list<EntityPermissionStatement>::iterator iter = Permissions.begin(); iter != Permissions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetGlobalPolicyResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
    if (Permissions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Permissions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Permissions.push_back(EntityPermissionStatement(memberList[i]));
        }
    }

    return true;
}

GetGroupRequest::~GetGroupRequest()
{
    if (Group != NULL) delete Group;

}

void GetGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Group != NULL) { writer.String("Group"); Group->writeJSON(writer); }
    if (GroupName.length() > 0) { writer.String("GroupName"); writer.String(GroupName.c_str()); }
    writer.EndObject();
}

bool GetGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
    const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
    if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();

    return true;
}

GetGroupResponse::~GetGroupResponse()
{

}

void GetGroupResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AdminRoleId.length() > 0) { writer.String("AdminRoleId"); writer.String(AdminRoleId.c_str()); }
    writer.String("Created"); writeDatetime(Created, writer);
    writer.String("Group"); Group.writeJSON(writer);
    if (GroupName.length() > 0) { writer.String("GroupName"); writer.String(GroupName.c_str()); }
    if (MemberRoleId.length() > 0) { writer.String("MemberRoleId"); writer.String(MemberRoleId.c_str()); }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    if (!Roles.empty()) {
        writer.String("Roles");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Roles.begin(); iter != Roles.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool GetGroupResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
    if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
    if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
    const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
    if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
    if (Roles_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Roles_member->value.MemberBegin(); iter != Roles_member->value.MemberEnd(); ++iter) {
            Roles[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

GetObjectsRequest::~GetObjectsRequest()
{

}

void GetObjectsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    if (EscapeObject.notNull()) { writer.String("EscapeObject"); writer.Bool(EscapeObject); }
    writer.EndObject();
}

bool GetObjectsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator EscapeObject_member = obj.FindMember("EscapeObject");
    if (EscapeObject_member != obj.MemberEnd() && !EscapeObject_member->value.IsNull()) EscapeObject = EscapeObject_member->value.GetBool();

    return true;
}

ObjectResult::~ObjectResult()
{

}

void ObjectResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DataObject.notNull()) { writer.String("DataObject"); DataObject.writeJSON(writer); }
    if (EscapedDataObject.length() > 0) { writer.String("EscapedDataObject"); writer.String(EscapedDataObject.c_str()); }
    if (ObjectName.length() > 0) { writer.String("ObjectName"); writer.String(ObjectName.c_str()); }
    writer.EndObject();
}

bool ObjectResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataObject_member = obj.FindMember("DataObject");
    if (DataObject_member != obj.MemberEnd() && !DataObject_member->value.IsNull()) DataObject = MultitypeVar(DataObject_member->value);
    const Value::ConstMemberIterator EscapedDataObject_member = obj.FindMember("EscapedDataObject");
    if (EscapedDataObject_member != obj.MemberEnd() && !EscapedDataObject_member->value.IsNull()) EscapedDataObject = EscapedDataObject_member->value.GetString();
    const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
    if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();

    return true;
}

GetObjectsResponse::~GetObjectsResponse()
{
    if (Entity != NULL) delete Entity;

}

void GetObjectsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (!Objects.empty()) {
        writer.String("Objects");
        writer.StartObject();
        for (std::map<std::string, ObjectResult>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    writer.EndObject();
}

bool GetObjectsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
    if (Objects_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Objects_member->value.MemberBegin(); iter != Objects_member->value.MemberEnd(); ++iter) {
            Objects[iter->name.GetString()] = ObjectResult(iter->value);
        }
    }
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

    return true;
}

GroupApplication::~GroupApplication()
{
    if (Entity != NULL) delete Entity;
    if (Group != NULL) delete Group;

}

void GroupApplication::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("Expires"); writeDatetime(Expires, writer);
    if (Group != NULL) { writer.String("Group"); Group->writeJSON(writer); }
    writer.EndObject();
}

bool GroupApplication::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
    const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
    if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);

    return true;
}

GroupBlock::~GroupBlock()
{
    if (Entity != NULL) delete Entity;

}

void GroupBlock::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool GroupBlock::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityWithLineage(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

GroupInvitation::~GroupInvitation()
{
    if (Group != NULL) delete Group;
    if (InvitedByEntity != NULL) delete InvitedByEntity;
    if (InvitedEntity != NULL) delete InvitedEntity;

}

void GroupInvitation::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Expires"); writeDatetime(Expires, writer);
    if (Group != NULL) { writer.String("Group"); Group->writeJSON(writer); }
    if (InvitedByEntity != NULL) { writer.String("InvitedByEntity"); InvitedByEntity->writeJSON(writer); }
    if (InvitedEntity != NULL) { writer.String("InvitedEntity"); InvitedEntity->writeJSON(writer); }
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    writer.EndObject();
}

bool GroupInvitation::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
    if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
    const Value::ConstMemberIterator InvitedByEntity_member = obj.FindMember("InvitedByEntity");
    if (InvitedByEntity_member != obj.MemberEnd() && !InvitedByEntity_member->value.IsNull()) InvitedByEntity = new EntityWithLineage(InvitedByEntity_member->value);
    const Value::ConstMemberIterator InvitedEntity_member = obj.FindMember("InvitedEntity");
    if (InvitedEntity_member != obj.MemberEnd() && !InvitedEntity_member->value.IsNull()) InvitedEntity = new EntityWithLineage(InvitedEntity_member->value);
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

    return true;
}

GroupRole::~GroupRole()
{

}

void GroupRole::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    if (RoleName.length() > 0) { writer.String("RoleName"); writer.String(RoleName.c_str()); }
    writer.EndObject();
}

bool GroupRole::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
    const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
    if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

    return true;
}

GroupWithRoles::~GroupWithRoles()
{
    if (Group != NULL) delete Group;

}

void GroupWithRoles::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Group != NULL) { writer.String("Group"); Group->writeJSON(writer); }
    if (GroupName.length() > 0) { writer.String("GroupName"); writer.String(GroupName.c_str()); }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    if (!Roles.empty()) {
        writer.String("Roles");
        writer.StartArray();
        for (std::list<GroupRole>::iterator iter = Roles.begin(); iter != Roles.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GroupWithRoles::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
    const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
    if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator Roles_member = obj.FindMember("Roles");
    if (Roles_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Roles_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Roles.push_back(GroupRole(memberList[i]));
        }
    }

    return true;
}

InitiateFileUploadMetadata::~InitiateFileUploadMetadata()
{

}

void InitiateFileUploadMetadata::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (FileName.length() > 0) { writer.String("FileName"); writer.String(FileName.c_str()); }
    if (UploadUrl.length() > 0) { writer.String("UploadUrl"); writer.String(UploadUrl.c_str()); }
    writer.EndObject();
}

bool InitiateFileUploadMetadata::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
    const Value::ConstMemberIterator UploadUrl_member = obj.FindMember("UploadUrl");
    if (UploadUrl_member != obj.MemberEnd() && !UploadUrl_member->value.IsNull()) UploadUrl = UploadUrl_member->value.GetString();

    return true;
}

InitiateFileUploadsRequest::~InitiateFileUploadsRequest()
{

}

void InitiateFileUploadsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("FileNames");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = FileNames.begin(); iter != FileNames.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    if (ProfileVersion.notNull()) { writer.String("ProfileVersion"); writer.Int(ProfileVersion); }
    writer.EndObject();
}

bool InitiateFileUploadsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FileNames_member = obj.FindMember("FileNames");
    if (FileNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = FileNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            FileNames.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();

    return true;
}

InitiateFileUploadsResponse::~InitiateFileUploadsResponse()
{
    if (Entity != NULL) delete Entity;

}

void InitiateFileUploadsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    if (!UploadDetails.empty()) {
        writer.String("UploadDetails");
        writer.StartArray();
        for (std::list<InitiateFileUploadMetadata>::iterator iter = UploadDetails.begin(); iter != UploadDetails.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool InitiateFileUploadsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator UploadDetails_member = obj.FindMember("UploadDetails");
    if (UploadDetails_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UploadDetails_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UploadDetails.push_back(InitiateFileUploadMetadata(memberList[i]));
        }
    }

    return true;
}

InviteToGroupRequest::~InviteToGroupRequest()
{

}

void InviteToGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AutoAcceptOutstandingApplication.notNull()) { writer.String("AutoAcceptOutstandingApplication"); writer.Bool(AutoAcceptOutstandingApplication); }
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("Group"); Group.writeJSON(writer);
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    writer.EndObject();
}

bool InviteToGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AutoAcceptOutstandingApplication_member = obj.FindMember("AutoAcceptOutstandingApplication");
    if (AutoAcceptOutstandingApplication_member != obj.MemberEnd() && !AutoAcceptOutstandingApplication_member->value.IsNull()) AutoAcceptOutstandingApplication = AutoAcceptOutstandingApplication_member->value.GetBool();
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

    return true;
}

InviteToGroupResponse::~InviteToGroupResponse()
{
    if (Group != NULL) delete Group;
    if (InvitedByEntity != NULL) delete InvitedByEntity;
    if (InvitedEntity != NULL) delete InvitedEntity;

}

void InviteToGroupResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Expires"); writeDatetime(Expires, writer);
    if (Group != NULL) { writer.String("Group"); Group->writeJSON(writer); }
    if (InvitedByEntity != NULL) { writer.String("InvitedByEntity"); InvitedByEntity->writeJSON(writer); }
    if (InvitedEntity != NULL) { writer.String("InvitedEntity"); InvitedEntity->writeJSON(writer); }
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    writer.EndObject();
}

bool InviteToGroupResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
    if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = new EntityKey(Group_member->value);
    const Value::ConstMemberIterator InvitedByEntity_member = obj.FindMember("InvitedByEntity");
    if (InvitedByEntity_member != obj.MemberEnd() && !InvitedByEntity_member->value.IsNull()) InvitedByEntity = new EntityWithLineage(InvitedByEntity_member->value);
    const Value::ConstMemberIterator InvitedEntity_member = obj.FindMember("InvitedEntity");
    if (InvitedEntity_member != obj.MemberEnd() && !InvitedEntity_member->value.IsNull()) InvitedEntity = new EntityWithLineage(InvitedEntity_member->value);
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

    return true;
}

IsMemberRequest::~IsMemberRequest()
{

}

void IsMemberRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("Group"); Group.writeJSON(writer);
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    writer.EndObject();
}

bool IsMemberRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

    return true;
}

IsMemberResponse::~IsMemberResponse()
{

}

void IsMemberResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("IsMember"); writer.Bool(IsMember);
    writer.EndObject();
}

bool IsMemberResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IsMember_member = obj.FindMember("IsMember");
    if (IsMember_member != obj.MemberEnd() && !IsMember_member->value.IsNull()) IsMember = IsMember_member->value.GetBool();

    return true;
}

ListGroupApplicationsRequest::~ListGroupApplicationsRequest()
{

}

void ListGroupApplicationsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool ListGroupApplicationsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

ListGroupApplicationsResponse::~ListGroupApplicationsResponse()
{

}

void ListGroupApplicationsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Applications.empty()) {
        writer.String("Applications");
        writer.StartArray();
        for (std::list<GroupApplication>::iterator iter = Applications.begin(); iter != Applications.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListGroupApplicationsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Applications_member = obj.FindMember("Applications");
    if (Applications_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Applications_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Applications.push_back(GroupApplication(memberList[i]));
        }
    }

    return true;
}

ListGroupBlocksRequest::~ListGroupBlocksRequest()
{

}

void ListGroupBlocksRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool ListGroupBlocksRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

ListGroupBlocksResponse::~ListGroupBlocksResponse()
{

}

void ListGroupBlocksResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!BlockedEntities.empty()) {
        writer.String("BlockedEntities");
        writer.StartArray();
        for (std::list<GroupBlock>::iterator iter = BlockedEntities.begin(); iter != BlockedEntities.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListGroupBlocksResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BlockedEntities_member = obj.FindMember("BlockedEntities");
    if (BlockedEntities_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BlockedEntities_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BlockedEntities.push_back(GroupBlock(memberList[i]));
        }
    }

    return true;
}

ListGroupInvitationsRequest::~ListGroupInvitationsRequest()
{

}

void ListGroupInvitationsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool ListGroupInvitationsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

ListGroupInvitationsResponse::~ListGroupInvitationsResponse()
{

}

void ListGroupInvitationsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Invitations.empty()) {
        writer.String("Invitations");
        writer.StartArray();
        for (std::list<GroupInvitation>::iterator iter = Invitations.begin(); iter != Invitations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListGroupInvitationsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Invitations_member = obj.FindMember("Invitations");
    if (Invitations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Invitations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Invitations.push_back(GroupInvitation(memberList[i]));
        }
    }

    return true;
}

ListGroupMembersRequest::~ListGroupMembersRequest()
{

}

void ListGroupMembersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool ListGroupMembersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

ListGroupMembersResponse::~ListGroupMembersResponse()
{

}

void ListGroupMembersResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Members.empty()) {
        writer.String("Members");
        writer.StartArray();
        for (std::list<EntityMemberRole>::iterator iter = Members.begin(); iter != Members.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListGroupMembersResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
    if (Members_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Members_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Members.push_back(EntityMemberRole(memberList[i]));
        }
    }

    return true;
}

ListMembershipOpportunitiesRequest::~ListMembershipOpportunitiesRequest()
{
    if (Entity != NULL) delete Entity;

}

void ListMembershipOpportunitiesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool ListMembershipOpportunitiesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

ListMembershipOpportunitiesResponse::~ListMembershipOpportunitiesResponse()
{

}

void ListMembershipOpportunitiesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Applications.empty()) {
        writer.String("Applications");
        writer.StartArray();
        for (std::list<GroupApplication>::iterator iter = Applications.begin(); iter != Applications.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Invitations.empty()) {
        writer.String("Invitations");
        writer.StartArray();
        for (std::list<GroupInvitation>::iterator iter = Invitations.begin(); iter != Invitations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListMembershipOpportunitiesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Applications_member = obj.FindMember("Applications");
    if (Applications_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Applications_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Applications.push_back(GroupApplication(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Invitations_member = obj.FindMember("Invitations");
    if (Invitations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Invitations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Invitations.push_back(GroupInvitation(memberList[i]));
        }
    }

    return true;
}

ListMembershipRequest::~ListMembershipRequest()
{
    if (Entity != NULL) delete Entity;

}

void ListMembershipRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool ListMembershipRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

ListMembershipResponse::~ListMembershipResponse()
{

}

void ListMembershipResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Groups.empty()) {
        writer.String("Groups");
        writer.StartArray();
        for (std::list<GroupWithRoles>::iterator iter = Groups.begin(); iter != Groups.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListMembershipResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Groups_member = obj.FindMember("Groups");
    if (Groups_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Groups_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Groups.push_back(GroupWithRoles(memberList[i]));
        }
    }

    return true;
}
void PlayFab::EntityModels::writeOperationTypesEnumJSON(OperationTypes enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case OperationTypesCreated: writer.String("Created"); break;
    case OperationTypesUpdated: writer.String("Updated"); break;
    case OperationTypesDeleted: writer.String("Deleted"); break;
    case OperationTypesNone: writer.String("None"); break;

    }
}

OperationTypes PlayFab::EntityModels::readOperationTypesFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, OperationTypes> _OperationTypesMap;
    if (_OperationTypesMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _OperationTypesMap["Created"] = OperationTypesCreated;
        _OperationTypesMap["Updated"] = OperationTypesUpdated;
        _OperationTypesMap["Deleted"] = OperationTypesDeleted;
        _OperationTypesMap["None"] = OperationTypesNone;

    }

    auto output = _OperationTypesMap.find(obj.GetString());
    if (output != _OperationTypesMap.end())
        return output->second;

    return OperationTypesCreated; // Basically critical fail
}

RemoveGroupApplicationRequest::~RemoveGroupApplicationRequest()
{

}

void RemoveGroupApplicationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool RemoveGroupApplicationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

RemoveGroupInvitationRequest::~RemoveGroupInvitationRequest()
{

}

void RemoveGroupInvitationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool RemoveGroupInvitationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

RemoveMembersRequest::~RemoveMembersRequest()
{

}

void RemoveMembersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Group"); Group.writeJSON(writer);
    writer.String("Members");
    writer.StartArray();
    for (std::list<EntityKey>::iterator iter = Members.begin(); iter != Members.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    writer.EndObject();
}

bool RemoveMembersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
    if (Members_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Members_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Members.push_back(EntityKey(memberList[i]));
        }
    }
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();

    return true;
}

SetEntityProfilePolicyRequest::~SetEntityProfilePolicyRequest()
{

}

void SetEntityProfilePolicyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    if (!Statements.empty()) {
        writer.String("Statements");
        writer.StartArray();
        for (std::list<EntityPermissionStatement>::iterator iter = Statements.begin(); iter != Statements.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool SetEntityProfilePolicyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Statements_member = obj.FindMember("Statements");
    if (Statements_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statements_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statements.push_back(EntityPermissionStatement(memberList[i]));
        }
    }

    return true;
}

SetEntityProfilePolicyResponse::~SetEntityProfilePolicyResponse()
{

}

void SetEntityProfilePolicyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Permissions.empty()) {
        writer.String("Permissions");
        writer.StartArray();
        for (std::list<EntityPermissionStatement>::iterator iter = Permissions.begin(); iter != Permissions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool SetEntityProfilePolicyResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
    if (Permissions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Permissions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Permissions.push_back(EntityPermissionStatement(memberList[i]));
        }
    }

    return true;
}

SetGlobalPolicyRequest::~SetGlobalPolicyRequest()
{

}

void SetGlobalPolicyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Permissions.empty()) {
        writer.String("Permissions");
        writer.StartArray();
        for (std::list<EntityPermissionStatement>::iterator iter = Permissions.begin(); iter != Permissions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool SetGlobalPolicyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Permissions_member = obj.FindMember("Permissions");
    if (Permissions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Permissions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Permissions.push_back(EntityPermissionStatement(memberList[i]));
        }
    }

    return true;
}

SetGlobalPolicyResponse::~SetGlobalPolicyResponse()
{

}

void SetGlobalPolicyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool SetGlobalPolicyResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SetObject::~SetObject()
{

}

void SetObject::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DataObject.notNull()) { writer.String("DataObject"); DataObject.writeJSON(writer); }
    if (DeleteObject.notNull()) { writer.String("DeleteObject"); writer.Bool(DeleteObject); }
    if (EscapedDataObject.length() > 0) { writer.String("EscapedDataObject"); writer.String(EscapedDataObject.c_str()); }
    writer.String("ObjectName"); writer.String(ObjectName.c_str());
    writer.EndObject();
}

bool SetObject::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataObject_member = obj.FindMember("DataObject");
    if (DataObject_member != obj.MemberEnd() && !DataObject_member->value.IsNull()) DataObject = MultitypeVar(DataObject_member->value);
    const Value::ConstMemberIterator DeleteObject_member = obj.FindMember("DeleteObject");
    if (DeleteObject_member != obj.MemberEnd() && !DeleteObject_member->value.IsNull()) DeleteObject = DeleteObject_member->value.GetBool();
    const Value::ConstMemberIterator EscapedDataObject_member = obj.FindMember("EscapedDataObject");
    if (EscapedDataObject_member != obj.MemberEnd() && !EscapedDataObject_member->value.IsNull()) EscapedDataObject = EscapedDataObject_member->value.GetString();
    const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
    if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();

    return true;
}

SetObjectInfo::~SetObjectInfo()
{

}

void SetObjectInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ObjectName.length() > 0) { writer.String("ObjectName"); writer.String(ObjectName.c_str()); }
    if (OperationReason.length() > 0) { writer.String("OperationReason"); writer.String(OperationReason.c_str()); }
    if (SetResult.notNull()) { writer.String("SetResult"); writeOperationTypesEnumJSON(SetResult, writer); }
    writer.EndObject();
}

bool SetObjectInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ObjectName_member = obj.FindMember("ObjectName");
    if (ObjectName_member != obj.MemberEnd() && !ObjectName_member->value.IsNull()) ObjectName = ObjectName_member->value.GetString();
    const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
    if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
    const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
    if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

    return true;
}

SetObjectsRequest::~SetObjectsRequest()
{

}

void SetObjectsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    if (ExpectedProfileVersion.notNull()) { writer.String("ExpectedProfileVersion"); writer.Int(ExpectedProfileVersion); }
    writer.String("Objects");
    writer.StartArray();
    for (std::list<SetObject>::iterator iter = Objects.begin(); iter != Objects.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.EndObject();
}

bool SetObjectsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
    if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator Objects_member = obj.FindMember("Objects");
    if (Objects_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Objects_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Objects.push_back(SetObject(memberList[i]));
        }
    }

    return true;
}

SetObjectsResponse::~SetObjectsResponse()
{

}

void SetObjectsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    if (!SetResults.empty()) {
        writer.String("SetResults");
        writer.StartArray();
        for (std::list<SetObjectInfo>::iterator iter = SetResults.begin(); iter != SetResults.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool SetObjectsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator SetResults_member = obj.FindMember("SetResults");
    if (SetResults_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = SetResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            SetResults.push_back(SetObjectInfo(memberList[i]));
        }
    }

    return true;
}

UnblockEntityRequest::~UnblockEntityRequest()
{

}

void UnblockEntityRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("Group"); Group.writeJSON(writer);
    writer.EndObject();
}

bool UnblockEntityRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);

    return true;
}

UpdateGroupRequest::~UpdateGroupRequest()
{

}

void UpdateGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AdminRoleId.length() > 0) { writer.String("AdminRoleId"); writer.String(AdminRoleId.c_str()); }
    if (ExpectedProfileVersion.notNull()) { writer.String("ExpectedProfileVersion"); writer.Int(ExpectedProfileVersion); }
    writer.String("Group"); Group.writeJSON(writer);
    if (GroupName.length() > 0) { writer.String("GroupName"); writer.String(GroupName.c_str()); }
    if (MemberRoleId.length() > 0) { writer.String("MemberRoleId"); writer.String(MemberRoleId.c_str()); }
    writer.EndObject();
}

bool UpdateGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AdminRoleId_member = obj.FindMember("AdminRoleId");
    if (AdminRoleId_member != obj.MemberEnd() && !AdminRoleId_member->value.IsNull()) AdminRoleId = AdminRoleId_member->value.GetString();
    const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
    if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator GroupName_member = obj.FindMember("GroupName");
    if (GroupName_member != obj.MemberEnd() && !GroupName_member->value.IsNull()) GroupName = GroupName_member->value.GetString();
    const Value::ConstMemberIterator MemberRoleId_member = obj.FindMember("MemberRoleId");
    if (MemberRoleId_member != obj.MemberEnd() && !MemberRoleId_member->value.IsNull()) MemberRoleId = MemberRoleId_member->value.GetString();

    return true;
}

UpdateGroupResponse::~UpdateGroupResponse()
{

}

void UpdateGroupResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (OperationReason.length() > 0) { writer.String("OperationReason"); writer.String(OperationReason.c_str()); }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    if (SetResult.notNull()) { writer.String("SetResult"); writeOperationTypesEnumJSON(SetResult, writer); }
    writer.EndObject();
}

bool UpdateGroupResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
    if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
    if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

    return true;
}

UpdateGroupRoleRequest::~UpdateGroupRoleRequest()
{

}

void UpdateGroupRoleRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ExpectedProfileVersion.notNull()) { writer.String("ExpectedProfileVersion"); writer.Int(ExpectedProfileVersion); }
    writer.String("Group"); Group.writeJSON(writer);
    if (RoleId.length() > 0) { writer.String("RoleId"); writer.String(RoleId.c_str()); }
    writer.String("RoleName"); writer.String(RoleName.c_str());
    writer.EndObject();
}

bool UpdateGroupRoleRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ExpectedProfileVersion_member = obj.FindMember("ExpectedProfileVersion");
    if (ExpectedProfileVersion_member != obj.MemberEnd() && !ExpectedProfileVersion_member->value.IsNull()) ExpectedProfileVersion = ExpectedProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator Group_member = obj.FindMember("Group");
    if (Group_member != obj.MemberEnd() && !Group_member->value.IsNull()) Group = EntityKey(Group_member->value);
    const Value::ConstMemberIterator RoleId_member = obj.FindMember("RoleId");
    if (RoleId_member != obj.MemberEnd() && !RoleId_member->value.IsNull()) RoleId = RoleId_member->value.GetString();
    const Value::ConstMemberIterator RoleName_member = obj.FindMember("RoleName");
    if (RoleName_member != obj.MemberEnd() && !RoleName_member->value.IsNull()) RoleName = RoleName_member->value.GetString();

    return true;
}

UpdateGroupRoleResponse::~UpdateGroupRoleResponse()
{

}

void UpdateGroupRoleResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (OperationReason.length() > 0) { writer.String("OperationReason"); writer.String(OperationReason.c_str()); }
    writer.String("ProfileVersion"); writer.Int(ProfileVersion);
    if (SetResult.notNull()) { writer.String("SetResult"); writeOperationTypesEnumJSON(SetResult, writer); }
    writer.EndObject();
}

bool UpdateGroupRoleResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator OperationReason_member = obj.FindMember("OperationReason");
    if (OperationReason_member != obj.MemberEnd() && !OperationReason_member->value.IsNull()) OperationReason = OperationReason_member->value.GetString();
    const Value::ConstMemberIterator ProfileVersion_member = obj.FindMember("ProfileVersion");
    if (ProfileVersion_member != obj.MemberEnd() && !ProfileVersion_member->value.IsNull()) ProfileVersion = ProfileVersion_member->value.GetInt();
    const Value::ConstMemberIterator SetResult_member = obj.FindMember("SetResult");
    if (SetResult_member != obj.MemberEnd() && !SetResult_member->value.IsNull()) SetResult = readOperationTypesFromValue(SetResult_member->value);

    return true;
}

