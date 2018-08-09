#include "PlayFabCloudScriptDataModels.h"

using namespace PlayFab;
using namespace PlayFab::CloudScriptModels;
using namespace rapidjson;

void PlayFab::CloudScriptModels::writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case CloudScriptRevisionOptionLive: writer.String("Live"); break;
    case CloudScriptRevisionOptionLatest: writer.String("Latest"); break;
    case CloudScriptRevisionOptionSpecific: writer.String("Specific"); break;

    }
}

CloudScriptRevisionOption PlayFab::CloudScriptModels::readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, CloudScriptRevisionOption> _CloudScriptRevisionOptionMap;
    if (_CloudScriptRevisionOptionMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _CloudScriptRevisionOptionMap["Live"] = CloudScriptRevisionOptionLive;
        _CloudScriptRevisionOptionMap["Latest"] = CloudScriptRevisionOptionLatest;
        _CloudScriptRevisionOptionMap["Specific"] = CloudScriptRevisionOptionSpecific;

    }

    auto output = _CloudScriptRevisionOptionMap.find(obj.GetString());
    if (output != _CloudScriptRevisionOptionMap.end())
        return output->second;

    return CloudScriptRevisionOptionLive; // Basically critical fail
}
void PlayFab::CloudScriptModels::writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer)
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

EntityTypes PlayFab::CloudScriptModels::readEntityTypesFromValue(const rapidjson::Value& obj)
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

ScriptExecutionError::~ScriptExecutionError()
{

}

void ScriptExecutionError::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Error.length() > 0) { writer.String("Error"); writer.String(Error.c_str()); }
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    if (StackTrace.length() > 0) { writer.String("StackTrace"); writer.String(StackTrace.c_str()); }
    writer.EndObject();
}

bool ScriptExecutionError::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator StackTrace_member = obj.FindMember("StackTrace");
    if (StackTrace_member != obj.MemberEnd() && !StackTrace_member->value.IsNull()) StackTrace = StackTrace_member->value.GetString();

    return true;
}

LogStatement::~LogStatement()
{

}

void LogStatement::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Data.notNull()) { writer.String("Data"); Data.writeJSON(writer); }
    if (Level.length() > 0) { writer.String("Level"); writer.String(Level.c_str()); }
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    writer.EndObject();
}

bool LogStatement::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd() && !Data_member->value.IsNull()) Data = MultitypeVar(Data_member->value);
    const Value::ConstMemberIterator Level_member = obj.FindMember("Level");
    if (Level_member != obj.MemberEnd() && !Level_member->value.IsNull()) Level = Level_member->value.GetString();
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();

    return true;
}

ExecuteCloudScriptResult::~ExecuteCloudScriptResult()
{
    if (Error != NULL) delete Error;

}

void ExecuteCloudScriptResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("APIRequestsIssued"); writer.Int(APIRequestsIssued);
    if (Error != NULL) { writer.String("Error"); Error->writeJSON(writer); }
    writer.String("ExecutionTimeSeconds"); writer.Double(ExecutionTimeSeconds);
    if (FunctionName.length() > 0) { writer.String("FunctionName"); writer.String(FunctionName.c_str()); }
    if (FunctionResult.notNull()) { writer.String("FunctionResult"); FunctionResult.writeJSON(writer); }
    if (FunctionResultTooLarge.notNull()) { writer.String("FunctionResultTooLarge"); writer.Bool(FunctionResultTooLarge); }
    writer.String("HttpRequestsIssued"); writer.Int(HttpRequestsIssued);
    if (!Logs.empty()) {
        writer.String("Logs");
        writer.StartArray();
        for (std::list<LogStatement>::iterator iter = Logs.begin(); iter != Logs.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (LogsTooLarge.notNull()) { writer.String("LogsTooLarge"); writer.Bool(LogsTooLarge); }
    writer.String("MemoryConsumedBytes"); writer.Uint(MemoryConsumedBytes);
    writer.String("ProcessorTimeSeconds"); writer.Double(ProcessorTimeSeconds);
    writer.String("Revision"); writer.Int(Revision);
    writer.EndObject();
}

bool ExecuteCloudScriptResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator APIRequestsIssued_member = obj.FindMember("APIRequestsIssued");
    if (APIRequestsIssued_member != obj.MemberEnd() && !APIRequestsIssued_member->value.IsNull()) APIRequestsIssued = APIRequestsIssued_member->value.GetInt();
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = new ScriptExecutionError(Error_member->value);
    const Value::ConstMemberIterator ExecutionTimeSeconds_member = obj.FindMember("ExecutionTimeSeconds");
    if (ExecutionTimeSeconds_member != obj.MemberEnd() && !ExecutionTimeSeconds_member->value.IsNull()) ExecutionTimeSeconds = ExecutionTimeSeconds_member->value.GetDouble();
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
    if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = MultitypeVar(FunctionResult_member->value);
    const Value::ConstMemberIterator FunctionResultTooLarge_member = obj.FindMember("FunctionResultTooLarge");
    if (FunctionResultTooLarge_member != obj.MemberEnd() && !FunctionResultTooLarge_member->value.IsNull()) FunctionResultTooLarge = FunctionResultTooLarge_member->value.GetBool();
    const Value::ConstMemberIterator HttpRequestsIssued_member = obj.FindMember("HttpRequestsIssued");
    if (HttpRequestsIssued_member != obj.MemberEnd() && !HttpRequestsIssued_member->value.IsNull()) HttpRequestsIssued = HttpRequestsIssued_member->value.GetInt();
    const Value::ConstMemberIterator Logs_member = obj.FindMember("Logs");
    if (Logs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Logs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Logs.push_back(LogStatement(memberList[i]));
        }
    }
    const Value::ConstMemberIterator LogsTooLarge_member = obj.FindMember("LogsTooLarge");
    if (LogsTooLarge_member != obj.MemberEnd() && !LogsTooLarge_member->value.IsNull()) LogsTooLarge = LogsTooLarge_member->value.GetBool();
    const Value::ConstMemberIterator MemoryConsumedBytes_member = obj.FindMember("MemoryConsumedBytes");
    if (MemoryConsumedBytes_member != obj.MemberEnd() && !MemoryConsumedBytes_member->value.IsNull()) MemoryConsumedBytes = MemoryConsumedBytes_member->value.GetUint();
    const Value::ConstMemberIterator ProcessorTimeSeconds_member = obj.FindMember("ProcessorTimeSeconds");
    if (ProcessorTimeSeconds_member != obj.MemberEnd() && !ProcessorTimeSeconds_member->value.IsNull()) ProcessorTimeSeconds = ProcessorTimeSeconds_member->value.GetDouble();
    const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
    if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

    return true;
}

ExecuteEntityCloudScriptRequest::~ExecuteEntityCloudScriptRequest()
{
    if (Entity != NULL) delete Entity;

}

void ExecuteEntityCloudScriptRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.String("FunctionName"); writer.String(FunctionName.c_str());
    if (FunctionParameter.notNull()) { writer.String("FunctionParameter"); FunctionParameter.writeJSON(writer); }
    if (GeneratePlayStreamEvent.notNull()) { writer.String("GeneratePlayStreamEvent"); writer.Bool(GeneratePlayStreamEvent); }
    if (RevisionSelection.notNull()) { writer.String("RevisionSelection"); writeCloudScriptRevisionOptionEnumJSON(RevisionSelection, writer); }
    if (SpecificRevision.notNull()) { writer.String("SpecificRevision"); writer.Int(SpecificRevision); }
    writer.EndObject();
}

bool ExecuteEntityCloudScriptRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionParameter_member = obj.FindMember("FunctionParameter");
    if (FunctionParameter_member != obj.MemberEnd() && !FunctionParameter_member->value.IsNull()) FunctionParameter = MultitypeVar(FunctionParameter_member->value);
    const Value::ConstMemberIterator GeneratePlayStreamEvent_member = obj.FindMember("GeneratePlayStreamEvent");
    if (GeneratePlayStreamEvent_member != obj.MemberEnd() && !GeneratePlayStreamEvent_member->value.IsNull()) GeneratePlayStreamEvent = GeneratePlayStreamEvent_member->value.GetBool();
    const Value::ConstMemberIterator RevisionSelection_member = obj.FindMember("RevisionSelection");
    if (RevisionSelection_member != obj.MemberEnd() && !RevisionSelection_member->value.IsNull()) RevisionSelection = readCloudScriptRevisionOptionFromValue(RevisionSelection_member->value);
    const Value::ConstMemberIterator SpecificRevision_member = obj.FindMember("SpecificRevision");
    if (SpecificRevision_member != obj.MemberEnd() && !SpecificRevision_member->value.IsNull()) SpecificRevision = SpecificRevision_member->value.GetInt();

    return true;
}

