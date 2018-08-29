#include "PlayFabDataDataModels.h"

using namespace PlayFab;
using namespace PlayFab::DataModels;
using namespace rapidjson;


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
void PlayFab::DataModels::writeOperationTypesEnumJSON(OperationTypes enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case OperationTypesCreated: writer.String("Created"); break;
    case OperationTypesUpdated: writer.String("Updated"); break;
    case OperationTypesDeleted: writer.String("Deleted"); break;
    case OperationTypesNone: writer.String("None"); break;

    }
}

OperationTypes PlayFab::DataModels::readOperationTypesFromValue(const rapidjson::Value& obj)
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

