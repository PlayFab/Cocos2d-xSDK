#include "PlayFabInsightsDataModels.h"

using namespace PlayFab;
using namespace PlayFab::InsightsModels;
using namespace rapidjson;


InsightsEmptyRequest::~InsightsEmptyRequest()
{

}

void InsightsEmptyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool InsightsEmptyRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

InsightsPerformanceLevel::~InsightsPerformanceLevel()
{

}

void InsightsPerformanceLevel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ActiveEventExports"); writer.Int(ActiveEventExports);
    writer.String("CacheSizeMB"); writer.Int(CacheSizeMB);
    writer.String("Concurrency"); writer.Int(Concurrency);
    writer.String("CreditsPerMinute"); writer.Double(CreditsPerMinute);
    writer.String("EventsPerSecond"); writer.Int(EventsPerSecond);
    writer.String("Level"); writer.Int(Level);
    writer.String("MaxMemoryPerQueryMB"); writer.Int(MaxMemoryPerQueryMB);
    writer.String("VirtualCpuCores"); writer.Int(VirtualCpuCores);
    writer.EndObject();
}

bool InsightsPerformanceLevel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ActiveEventExports_member = obj.FindMember("ActiveEventExports");
    if (ActiveEventExports_member != obj.MemberEnd() && !ActiveEventExports_member->value.IsNull()) ActiveEventExports = ActiveEventExports_member->value.GetInt();
    const Value::ConstMemberIterator CacheSizeMB_member = obj.FindMember("CacheSizeMB");
    if (CacheSizeMB_member != obj.MemberEnd() && !CacheSizeMB_member->value.IsNull()) CacheSizeMB = CacheSizeMB_member->value.GetInt();
    const Value::ConstMemberIterator Concurrency_member = obj.FindMember("Concurrency");
    if (Concurrency_member != obj.MemberEnd() && !Concurrency_member->value.IsNull()) Concurrency = Concurrency_member->value.GetInt();
    const Value::ConstMemberIterator CreditsPerMinute_member = obj.FindMember("CreditsPerMinute");
    if (CreditsPerMinute_member != obj.MemberEnd() && !CreditsPerMinute_member->value.IsNull()) CreditsPerMinute = CreditsPerMinute_member->value.GetDouble();
    const Value::ConstMemberIterator EventsPerSecond_member = obj.FindMember("EventsPerSecond");
    if (EventsPerSecond_member != obj.MemberEnd() && !EventsPerSecond_member->value.IsNull()) EventsPerSecond = EventsPerSecond_member->value.GetInt();
    const Value::ConstMemberIterator Level_member = obj.FindMember("Level");
    if (Level_member != obj.MemberEnd() && !Level_member->value.IsNull()) Level = Level_member->value.GetInt();
    const Value::ConstMemberIterator MaxMemoryPerQueryMB_member = obj.FindMember("MaxMemoryPerQueryMB");
    if (MaxMemoryPerQueryMB_member != obj.MemberEnd() && !MaxMemoryPerQueryMB_member->value.IsNull()) MaxMemoryPerQueryMB = MaxMemoryPerQueryMB_member->value.GetInt();
    const Value::ConstMemberIterator VirtualCpuCores_member = obj.FindMember("VirtualCpuCores");
    if (VirtualCpuCores_member != obj.MemberEnd() && !VirtualCpuCores_member->value.IsNull()) VirtualCpuCores = VirtualCpuCores_member->value.GetInt();

    return true;
}

InsightsGetLimitsResponse::~InsightsGetLimitsResponse()
{

}

void InsightsGetLimitsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("DefaultPerformanceLevel"); writer.Int(DefaultPerformanceLevel);
    writer.String("DefaultStorageRetentionDays"); writer.Int(DefaultStorageRetentionDays);
    writer.String("StorageMaxRetentionDays"); writer.Int(StorageMaxRetentionDays);
    writer.String("StorageMinRetentionDays"); writer.Int(StorageMinRetentionDays);
    if (!SubMeters.empty()) {
        writer.String("SubMeters");
        writer.StartArray();
        for (std::list<InsightsPerformanceLevel>::iterator iter = SubMeters.begin(); iter != SubMeters.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool InsightsGetLimitsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DefaultPerformanceLevel_member = obj.FindMember("DefaultPerformanceLevel");
    if (DefaultPerformanceLevel_member != obj.MemberEnd() && !DefaultPerformanceLevel_member->value.IsNull()) DefaultPerformanceLevel = DefaultPerformanceLevel_member->value.GetInt();
    const Value::ConstMemberIterator DefaultStorageRetentionDays_member = obj.FindMember("DefaultStorageRetentionDays");
    if (DefaultStorageRetentionDays_member != obj.MemberEnd() && !DefaultStorageRetentionDays_member->value.IsNull()) DefaultStorageRetentionDays = DefaultStorageRetentionDays_member->value.GetInt();
    const Value::ConstMemberIterator StorageMaxRetentionDays_member = obj.FindMember("StorageMaxRetentionDays");
    if (StorageMaxRetentionDays_member != obj.MemberEnd() && !StorageMaxRetentionDays_member->value.IsNull()) StorageMaxRetentionDays = StorageMaxRetentionDays_member->value.GetInt();
    const Value::ConstMemberIterator StorageMinRetentionDays_member = obj.FindMember("StorageMinRetentionDays");
    if (StorageMinRetentionDays_member != obj.MemberEnd() && !StorageMinRetentionDays_member->value.IsNull()) StorageMinRetentionDays = StorageMinRetentionDays_member->value.GetInt();
    const Value::ConstMemberIterator SubMeters_member = obj.FindMember("SubMeters");
    if (SubMeters_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = SubMeters_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            SubMeters.push_back(InsightsPerformanceLevel(memberList[i]));
        }
    }

    return true;
}

InsightsGetOperationStatusResponse::~InsightsGetOperationStatusResponse()
{

}

void InsightsGetOperationStatusResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    writer.String("OperationCompletedTime"); writeDatetime(OperationCompletedTime, writer);
    if (OperationId.length() > 0) { writer.String("OperationId"); writer.String(OperationId.c_str()); }
    writer.String("OperationLastUpdated"); writeDatetime(OperationLastUpdated, writer);
    writer.String("OperationStartedTime"); writeDatetime(OperationStartedTime, writer);
    if (OperationType.length() > 0) { writer.String("OperationType"); writer.String(OperationType.c_str()); }
    writer.String("OperationValue"); writer.Int(OperationValue);
    if (Status.length() > 0) { writer.String("Status"); writer.String(Status.c_str()); }
    writer.EndObject();
}

bool InsightsGetOperationStatusResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator OperationCompletedTime_member = obj.FindMember("OperationCompletedTime");
    if (OperationCompletedTime_member != obj.MemberEnd() && !OperationCompletedTime_member->value.IsNull()) OperationCompletedTime = readDatetime(OperationCompletedTime_member->value);
    const Value::ConstMemberIterator OperationId_member = obj.FindMember("OperationId");
    if (OperationId_member != obj.MemberEnd() && !OperationId_member->value.IsNull()) OperationId = OperationId_member->value.GetString();
    const Value::ConstMemberIterator OperationLastUpdated_member = obj.FindMember("OperationLastUpdated");
    if (OperationLastUpdated_member != obj.MemberEnd() && !OperationLastUpdated_member->value.IsNull()) OperationLastUpdated = readDatetime(OperationLastUpdated_member->value);
    const Value::ConstMemberIterator OperationStartedTime_member = obj.FindMember("OperationStartedTime");
    if (OperationStartedTime_member != obj.MemberEnd() && !OperationStartedTime_member->value.IsNull()) OperationStartedTime = readDatetime(OperationStartedTime_member->value);
    const Value::ConstMemberIterator OperationType_member = obj.FindMember("OperationType");
    if (OperationType_member != obj.MemberEnd() && !OperationType_member->value.IsNull()) OperationType = OperationType_member->value.GetString();
    const Value::ConstMemberIterator OperationValue_member = obj.FindMember("OperationValue");
    if (OperationValue_member != obj.MemberEnd() && !OperationValue_member->value.IsNull()) OperationValue = OperationValue_member->value.GetInt();
    const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
    if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = Status_member->value.GetString();

    return true;
}

InsightsGetDetailsResponse::~InsightsGetDetailsResponse()
{
    if (Limits != NULL) delete Limits;

}

void InsightsGetDetailsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("DataUsageMb"); writer.Uint(DataUsageMb);
    if (ErrorMessage.length() > 0) { writer.String("ErrorMessage"); writer.String(ErrorMessage.c_str()); }
    if (Limits != NULL) { writer.String("Limits"); Limits->writeJSON(writer); }
    if (!PendingOperations.empty()) {
        writer.String("PendingOperations");
        writer.StartArray();
        for (std::list<InsightsGetOperationStatusResponse>::iterator iter = PendingOperations.begin(); iter != PendingOperations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.String("PerformanceLevel"); writer.Int(PerformanceLevel);
    writer.String("RetentionDays"); writer.Int(RetentionDays);
    writer.EndObject();
}

bool InsightsGetDetailsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataUsageMb_member = obj.FindMember("DataUsageMb");
    if (DataUsageMb_member != obj.MemberEnd() && !DataUsageMb_member->value.IsNull()) DataUsageMb = DataUsageMb_member->value.GetUint();
    const Value::ConstMemberIterator ErrorMessage_member = obj.FindMember("ErrorMessage");
    if (ErrorMessage_member != obj.MemberEnd() && !ErrorMessage_member->value.IsNull()) ErrorMessage = ErrorMessage_member->value.GetString();
    const Value::ConstMemberIterator Limits_member = obj.FindMember("Limits");
    if (Limits_member != obj.MemberEnd() && !Limits_member->value.IsNull()) Limits = new InsightsGetLimitsResponse(Limits_member->value);
    const Value::ConstMemberIterator PendingOperations_member = obj.FindMember("PendingOperations");
    if (PendingOperations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PendingOperations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PendingOperations.push_back(InsightsGetOperationStatusResponse(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PerformanceLevel_member = obj.FindMember("PerformanceLevel");
    if (PerformanceLevel_member != obj.MemberEnd() && !PerformanceLevel_member->value.IsNull()) PerformanceLevel = PerformanceLevel_member->value.GetInt();
    const Value::ConstMemberIterator RetentionDays_member = obj.FindMember("RetentionDays");
    if (RetentionDays_member != obj.MemberEnd() && !RetentionDays_member->value.IsNull()) RetentionDays = RetentionDays_member->value.GetInt();

    return true;
}

InsightsGetOperationStatusRequest::~InsightsGetOperationStatusRequest()
{

}

void InsightsGetOperationStatusRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (OperationId.length() > 0) { writer.String("OperationId"); writer.String(OperationId.c_str()); }
    writer.EndObject();
}

bool InsightsGetOperationStatusRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator OperationId_member = obj.FindMember("OperationId");
    if (OperationId_member != obj.MemberEnd() && !OperationId_member->value.IsNull()) OperationId = OperationId_member->value.GetString();

    return true;
}

InsightsGetPendingOperationsRequest::~InsightsGetPendingOperationsRequest()
{

}

void InsightsGetPendingOperationsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (OperationType.length() > 0) { writer.String("OperationType"); writer.String(OperationType.c_str()); }
    writer.EndObject();
}

bool InsightsGetPendingOperationsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator OperationType_member = obj.FindMember("OperationType");
    if (OperationType_member != obj.MemberEnd() && !OperationType_member->value.IsNull()) OperationType = OperationType_member->value.GetString();

    return true;
}

InsightsGetPendingOperationsResponse::~InsightsGetPendingOperationsResponse()
{

}

void InsightsGetPendingOperationsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!PendingOperations.empty()) {
        writer.String("PendingOperations");
        writer.StartArray();
        for (std::list<InsightsGetOperationStatusResponse>::iterator iter = PendingOperations.begin(); iter != PendingOperations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool InsightsGetPendingOperationsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PendingOperations_member = obj.FindMember("PendingOperations");
    if (PendingOperations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PendingOperations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PendingOperations.push_back(InsightsGetOperationStatusResponse(memberList[i]));
        }
    }

    return true;
}

InsightsOperationResponse::~InsightsOperationResponse()
{

}

void InsightsOperationResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    if (OperationId.length() > 0) { writer.String("OperationId"); writer.String(OperationId.c_str()); }
    if (OperationType.length() > 0) { writer.String("OperationType"); writer.String(OperationType.c_str()); }
    writer.EndObject();
}

bool InsightsOperationResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator OperationId_member = obj.FindMember("OperationId");
    if (OperationId_member != obj.MemberEnd() && !OperationId_member->value.IsNull()) OperationId = OperationId_member->value.GetString();
    const Value::ConstMemberIterator OperationType_member = obj.FindMember("OperationType");
    if (OperationType_member != obj.MemberEnd() && !OperationType_member->value.IsNull()) OperationType = OperationType_member->value.GetString();

    return true;
}

InsightsSetPerformanceRequest::~InsightsSetPerformanceRequest()
{

}

void InsightsSetPerformanceRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("PerformanceLevel"); writer.Int(PerformanceLevel);
    writer.EndObject();
}

bool InsightsSetPerformanceRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PerformanceLevel_member = obj.FindMember("PerformanceLevel");
    if (PerformanceLevel_member != obj.MemberEnd() && !PerformanceLevel_member->value.IsNull()) PerformanceLevel = PerformanceLevel_member->value.GetInt();

    return true;
}

InsightsSetStorageRetentionRequest::~InsightsSetStorageRetentionRequest()
{

}

void InsightsSetStorageRetentionRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("RetentionDays"); writer.Int(RetentionDays);
    writer.EndObject();
}

bool InsightsSetStorageRetentionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator RetentionDays_member = obj.FindMember("RetentionDays");
    if (RetentionDays_member != obj.MemberEnd() && !RetentionDays_member->value.IsNull()) RetentionDays = RetentionDays_member->value.GetInt();

    return true;
}

