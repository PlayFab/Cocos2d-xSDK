#include "PlayFabProfilesDataModels.h"

using namespace PlayFab;
using namespace PlayFab::ProfilesModels;
using namespace rapidjson;

void PlayFab::ProfilesModels::writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case EffectTypeAllow: writer.String("Allow"); break;
    case EffectTypeDeny: writer.String("Deny"); break;

    }
}

EffectType PlayFab::ProfilesModels::readEffectTypeFromValue(const rapidjson::Value& obj)
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
void PlayFab::ProfilesModels::writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case EntityTypestitle: writer.String("title"); break;
    case EntityTypesmaster_player_account: writer.String("master_player_account"); break;
    case EntityTypestitle_player_account: writer.String("title_player_account"); break;
    case EntityTypescharacter: writer.String("character"); break;
    case EntityTypesgroup: writer.String("group"); break;
    case EntityTypesservice: writer.String("service"); break;

    }
}

EntityTypes PlayFab::ProfilesModels::readEntityTypesFromValue(const rapidjson::Value& obj)
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
        _EntityTypesMap["service"] = EntityTypesservice;

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
    if (Language.length() > 0) { writer.String("Language"); writer.String(Language.c_str()); }
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
    const Value::ConstMemberIterator Language_member = obj.FindMember("Language");
    if (Language_member != obj.MemberEnd() && !Language_member->value.IsNull()) Language = Language_member->value.GetString();
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

GetEntityProfilesRequest::~GetEntityProfilesRequest()
{

}

void GetEntityProfilesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DataAsObject.notNull()) { writer.String("DataAsObject"); writer.Bool(DataAsObject); }
    writer.String("Entities");
    writer.StartArray();
    for (std::list<EntityKey>::iterator iter = Entities.begin(); iter != Entities.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.EndObject();
}

bool GetEntityProfilesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataAsObject_member = obj.FindMember("DataAsObject");
    if (DataAsObject_member != obj.MemberEnd() && !DataAsObject_member->value.IsNull()) DataAsObject = DataAsObject_member->value.GetBool();
    const Value::ConstMemberIterator Entities_member = obj.FindMember("Entities");
    if (Entities_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Entities_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Entities.push_back(EntityKey(memberList[i]));
        }
    }

    return true;
}

GetEntityProfilesResponse::~GetEntityProfilesResponse()
{

}

void GetEntityProfilesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Profiles.empty()) {
        writer.String("Profiles");
        writer.StartArray();
        for (std::list<EntityProfileBody>::iterator iter = Profiles.begin(); iter != Profiles.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetEntityProfilesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Profiles_member = obj.FindMember("Profiles");
    if (Profiles_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Profiles_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Profiles.push_back(EntityProfileBody(memberList[i]));
        }
    }

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
void PlayFab::ProfilesModels::writeOperationTypesEnumJSON(OperationTypes enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case OperationTypesCreated: writer.String("Created"); break;
    case OperationTypesUpdated: writer.String("Updated"); break;
    case OperationTypesDeleted: writer.String("Deleted"); break;
    case OperationTypesNone: writer.String("None"); break;

    }
}

OperationTypes PlayFab::ProfilesModels::readOperationTypesFromValue(const rapidjson::Value& obj)
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

SetProfileLanguageRequest::~SetProfileLanguageRequest()
{
    if (Entity != NULL) delete Entity;

}

void SetProfileLanguageRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("ExpectedVersion"); writer.Int(ExpectedVersion);
    if (Language.length() > 0) { writer.String("Language"); writer.String(Language.c_str()); }
    writer.EndObject();
}

bool SetProfileLanguageRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator ExpectedVersion_member = obj.FindMember("ExpectedVersion");
    if (ExpectedVersion_member != obj.MemberEnd() && !ExpectedVersion_member->value.IsNull()) ExpectedVersion = ExpectedVersion_member->value.GetInt();
    const Value::ConstMemberIterator Language_member = obj.FindMember("Language");
    if (Language_member != obj.MemberEnd() && !Language_member->value.IsNull()) Language = Language_member->value.GetString();

    return true;
}

SetProfileLanguageResponse::~SetProfileLanguageResponse()
{

}

void SetProfileLanguageResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (OperationResult.notNull()) { writer.String("OperationResult"); writeOperationTypesEnumJSON(OperationResult, writer); }
    if (VersionNumber.notNull()) { writer.String("VersionNumber"); writer.Int(VersionNumber); }
    writer.EndObject();
}

bool SetProfileLanguageResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator OperationResult_member = obj.FindMember("OperationResult");
    if (OperationResult_member != obj.MemberEnd() && !OperationResult_member->value.IsNull()) OperationResult = readOperationTypesFromValue(OperationResult_member->value);
    const Value::ConstMemberIterator VersionNumber_member = obj.FindMember("VersionNumber");
    if (VersionNumber_member != obj.MemberEnd() && !VersionNumber_member->value.IsNull()) VersionNumber = VersionNumber_member->value.GetInt();

    return true;
}
