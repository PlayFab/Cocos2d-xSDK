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

EntityKey::~EntityKey()
{

}

void EntityKey::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Id"); writer.String(Id.c_str());
    if (Type.length() > 0) { writer.String("Type"); writer.String(Type.c_str()); }
    writer.EndObject();
}

bool EntityKey::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator Type_member = obj.FindMember("Type");
    if (Type_member != obj.MemberEnd() && !Type_member->value.IsNull()) Type = Type_member->value.GetString();

    return true;
}

EntityLineage::~EntityLineage()
{

}

void EntityLineage::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (GroupId.length() > 0) { writer.String("GroupId"); writer.String(GroupId.c_str()); }
    if (MasterPlayerAccountId.length() > 0) { writer.String("MasterPlayerAccountId"); writer.String(MasterPlayerAccountId.c_str()); }
    if (NamespaceId.length() > 0) { writer.String("NamespaceId"); writer.String(NamespaceId.c_str()); }
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    if (TitlePlayerAccountId.length() > 0) { writer.String("TitlePlayerAccountId"); writer.String(TitlePlayerAccountId.c_str()); }
    writer.EndObject();
}

bool EntityLineage::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator GroupId_member = obj.FindMember("GroupId");
    if (GroupId_member != obj.MemberEnd() && !GroupId_member->value.IsNull()) GroupId = GroupId_member->value.GetString();
    const Value::ConstMemberIterator MasterPlayerAccountId_member = obj.FindMember("MasterPlayerAccountId");
    if (MasterPlayerAccountId_member != obj.MemberEnd() && !MasterPlayerAccountId_member->value.IsNull()) MasterPlayerAccountId = MasterPlayerAccountId_member->value.GetString();
    const Value::ConstMemberIterator NamespaceId_member = obj.FindMember("NamespaceId");
    if (NamespaceId_member != obj.MemberEnd() && !NamespaceId_member->value.IsNull()) NamespaceId = NamespaceId_member->value.GetString();
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator TitlePlayerAccountId_member = obj.FindMember("TitlePlayerAccountId");
    if (TitlePlayerAccountId_member != obj.MemberEnd() && !TitlePlayerAccountId_member->value.IsNull()) TitlePlayerAccountId = TitlePlayerAccountId_member->value.GetString();

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

EntityStatisticChildValue::~EntityStatisticChildValue()
{

}

void EntityStatisticChildValue::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ChildName.length() > 0) { writer.String("ChildName"); writer.String(ChildName.c_str()); }
    if (Metadata.length() > 0) { writer.String("Metadata"); writer.String(Metadata.c_str()); }
    writer.String("Value"); writer.Int(Value);
    writer.EndObject();
}

bool EntityStatisticChildValue::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ChildName_member = obj.FindMember("ChildName");
    if (ChildName_member != obj.MemberEnd() && !ChildName_member->value.IsNull()) ChildName = ChildName_member->value.GetString();
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd() && !Metadata_member->value.IsNull()) Metadata = Metadata_member->value.GetString();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();

    return true;
}

EntityStatisticValue::~EntityStatisticValue()
{

}

void EntityStatisticValue::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!ChildStatistics.empty()) {
        writer.String("ChildStatistics");
        writer.StartObject();
        for (std::map<std::string, EntityStatisticChildValue>::iterator iter = ChildStatistics.begin(); iter != ChildStatistics.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    if (Metadata.length() > 0) { writer.String("Metadata"); writer.String(Metadata.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    if (Value.notNull()) { writer.String("Value"); writer.Int(Value); }
    writer.String("Version"); writer.Int(Version);
    writer.EndObject();
}

bool EntityStatisticValue::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ChildStatistics_member = obj.FindMember("ChildStatistics");
    if (ChildStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = ChildStatistics_member->value.MemberBegin(); iter != ChildStatistics_member->value.MemberEnd(); ++iter) {
            ChildStatistics[iter->name.GetString()] = EntityStatisticChildValue(iter->value);
        }
    }
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd() && !Metadata_member->value.IsNull()) Metadata = Metadata_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

    return true;
}

EntityProfileBody::~EntityProfileBody()
{
    if (Entity != NULL) delete Entity;
    if (Lineage != NULL) delete Lineage;

}

void EntityProfileBody::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AvatarUrl.length() > 0) { writer.String("AvatarUrl"); writer.String(AvatarUrl.c_str()); }
    writer.String("Created"); writeDatetime(Created, writer);
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (EntityChain.length() > 0) { writer.String("EntityChain"); writer.String(EntityChain.c_str()); }
    if (!ExperimentVariants.empty()) {
        writer.String("ExperimentVariants");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = ExperimentVariants.begin(); iter != ExperimentVariants.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (!Files.empty()) {
        writer.String("Files");
        writer.StartObject();
        for (std::map<std::string, EntityProfileFileMetadata>::iterator iter = Files.begin(); iter != Files.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    if (Language.length() > 0) { writer.String("Language"); writer.String(Language.c_str()); }
    if (LeaderboardMetadata.length() > 0) { writer.String("LeaderboardMetadata"); writer.String(LeaderboardMetadata.c_str()); }
    if (Lineage != NULL) { writer.String("Lineage"); Lineage->writeJSON(writer); }
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
    if (!Statistics.empty()) {
        writer.String("Statistics");
        writer.StartObject();
        for (std::map<std::string, EntityStatisticValue>::iterator iter = Statistics.begin(); iter != Statistics.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("VersionNumber"); writer.Int(VersionNumber);
    writer.EndObject();
}

bool EntityProfileBody::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
    if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator EntityChain_member = obj.FindMember("EntityChain");
    if (EntityChain_member != obj.MemberEnd() && !EntityChain_member->value.IsNull()) EntityChain = EntityChain_member->value.GetString();
    const Value::ConstMemberIterator ExperimentVariants_member = obj.FindMember("ExperimentVariants");
    if (ExperimentVariants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ExperimentVariants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ExperimentVariants.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
    if (Files_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Files_member->value.MemberBegin(); iter != Files_member->value.MemberEnd(); ++iter) {
            Files[iter->name.GetString()] = EntityProfileFileMetadata(iter->value);
        }
    }
    const Value::ConstMemberIterator Language_member = obj.FindMember("Language");
    if (Language_member != obj.MemberEnd() && !Language_member->value.IsNull()) Language = Language_member->value.GetString();
    const Value::ConstMemberIterator LeaderboardMetadata_member = obj.FindMember("LeaderboardMetadata");
    if (LeaderboardMetadata_member != obj.MemberEnd() && !LeaderboardMetadata_member->value.IsNull()) LeaderboardMetadata = LeaderboardMetadata_member->value.GetString();
    const Value::ConstMemberIterator Lineage_member = obj.FindMember("Lineage");
    if (Lineage_member != obj.MemberEnd() && !Lineage_member->value.IsNull()) Lineage = new EntityLineage(Lineage_member->value);
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
    const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Statistics_member->value.MemberBegin(); iter != Statistics_member->value.MemberEnd(); ++iter) {
            Statistics[iter->name.GetString()] = EntityStatisticValue(iter->value);
        }
    }
    const Value::ConstMemberIterator VersionNumber_member = obj.FindMember("VersionNumber");
    if (VersionNumber_member != obj.MemberEnd() && !VersionNumber_member->value.IsNull()) VersionNumber = VersionNumber_member->value.GetInt();

    return true;
}

GetEntityProfileRequest::~GetEntityProfileRequest()
{
    if (Entity != NULL) delete Entity;

}

void GetEntityProfileRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DataAsObject.notNull()) { writer.String("DataAsObject"); writer.Bool(DataAsObject); }
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool GetEntityProfileRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataAsObject_member = obj.FindMember("DataAsObject");
    if (DataAsObject_member != obj.MemberEnd() && !DataAsObject_member->value.IsNull()) DataAsObject = DataAsObject_member->value.GetBool();
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

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

GetTitlePlayersFromMasterPlayerAccountIdsRequest::~GetTitlePlayersFromMasterPlayerAccountIdsRequest()
{

}

void GetTitlePlayersFromMasterPlayerAccountIdsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("MasterPlayerAccountIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = MasterPlayerAccountIds.begin(); iter != MasterPlayerAccountIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    writer.EndObject();
}

bool GetTitlePlayersFromMasterPlayerAccountIdsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator MasterPlayerAccountIds_member = obj.FindMember("MasterPlayerAccountIds");
    if (MasterPlayerAccountIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = MasterPlayerAccountIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            MasterPlayerAccountIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

    return true;
}

GetTitlePlayersFromMasterPlayerAccountIdsResponse::~GetTitlePlayersFromMasterPlayerAccountIdsResponse()
{

}

void GetTitlePlayersFromMasterPlayerAccountIdsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!TitlePlayerAccounts.empty()) {
        writer.String("TitlePlayerAccounts");
        writer.StartObject();
        for (std::map<std::string, EntityKey>::iterator iter = TitlePlayerAccounts.begin(); iter != TitlePlayerAccounts.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool GetTitlePlayersFromMasterPlayerAccountIdsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator TitlePlayerAccounts_member = obj.FindMember("TitlePlayerAccounts");
    if (TitlePlayerAccounts_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = TitlePlayerAccounts_member->value.MemberBegin(); iter != TitlePlayerAccounts_member->value.MemberEnd(); ++iter) {
            TitlePlayerAccounts[iter->name.GetString()] = EntityKey(iter->value);
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
    if (ExpectedVersion.notNull()) { writer.String("ExpectedVersion"); writer.Int(ExpectedVersion); }
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

