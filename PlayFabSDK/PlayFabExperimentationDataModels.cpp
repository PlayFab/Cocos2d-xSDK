#include "PlayFabExperimentationDataModels.h"

using namespace PlayFab;
using namespace PlayFab::ExperimentationModels;
using namespace rapidjson;

void PlayFab::ExperimentationModels::writeAnalysisTaskStateEnumJSON(AnalysisTaskState enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case AnalysisTaskStateWaiting: writer.String("Waiting"); break;
    case AnalysisTaskStateReadyForSubmission: writer.String("ReadyForSubmission"); break;
    case AnalysisTaskStateSubmittingToPipeline: writer.String("SubmittingToPipeline"); break;
    case AnalysisTaskStateRunning: writer.String("Running"); break;
    case AnalysisTaskStateCompleted: writer.String("Completed"); break;
    case AnalysisTaskStateFailed: writer.String("Failed"); break;
    case AnalysisTaskStateCanceled: writer.String("Canceled"); break;

    }
}

AnalysisTaskState PlayFab::ExperimentationModels::readAnalysisTaskStateFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, AnalysisTaskState> _AnalysisTaskStateMap;
    if (_AnalysisTaskStateMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _AnalysisTaskStateMap["Waiting"] = AnalysisTaskStateWaiting;
        _AnalysisTaskStateMap["ReadyForSubmission"] = AnalysisTaskStateReadyForSubmission;
        _AnalysisTaskStateMap["SubmittingToPipeline"] = AnalysisTaskStateSubmittingToPipeline;
        _AnalysisTaskStateMap["Running"] = AnalysisTaskStateRunning;
        _AnalysisTaskStateMap["Completed"] = AnalysisTaskStateCompleted;
        _AnalysisTaskStateMap["Failed"] = AnalysisTaskStateFailed;
        _AnalysisTaskStateMap["Canceled"] = AnalysisTaskStateCanceled;

    }

    auto output = _AnalysisTaskStateMap.find(obj.GetString());
    if (output != _AnalysisTaskStateMap.end())
        return output->second;

    return AnalysisTaskStateWaiting; // Basically critical fail
}

CreateExclusionGroupRequest::~CreateExclusionGroupRequest()
{

}

void CreateExclusionGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    writer.String("Name"); writer.String(Name.c_str());
    writer.EndObject();
}

bool CreateExclusionGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

    return true;
}

CreateExclusionGroupResult::~CreateExclusionGroupResult()
{

}

void CreateExclusionGroupResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ExclusionGroupId.length() > 0) { writer.String("ExclusionGroupId"); writer.String(ExclusionGroupId.c_str()); }
    writer.EndObject();
}

bool CreateExclusionGroupResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ExclusionGroupId_member = obj.FindMember("ExclusionGroupId");
    if (ExclusionGroupId_member != obj.MemberEnd() && !ExclusionGroupId_member->value.IsNull()) ExclusionGroupId = ExclusionGroupId_member->value.GetString();

    return true;
}
void PlayFab::ExperimentationModels::writeExperimentTypeEnumJSON(ExperimentType enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case ExperimentTypeActive: writer.String("Active"); break;
    case ExperimentTypeSnapshot: writer.String("Snapshot"); break;

    }
}

ExperimentType PlayFab::ExperimentationModels::readExperimentTypeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, ExperimentType> _ExperimentTypeMap;
    if (_ExperimentTypeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _ExperimentTypeMap["Active"] = ExperimentTypeActive;
        _ExperimentTypeMap["Snapshot"] = ExperimentTypeSnapshot;

    }

    auto output = _ExperimentTypeMap.find(obj.GetString());
    if (output != _ExperimentTypeMap.end())
        return output->second;

    return ExperimentTypeActive; // Basically critical fail
}

Variable::~Variable()
{

}

void Variable::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Name"); writer.String(Name.c_str());
    if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
    writer.EndObject();
}

bool Variable::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

    return true;
}

Variant::~Variant()
{

}

void Variant::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }
    writer.String("IsControl"); writer.Bool(IsControl);
    writer.String("Name"); writer.String(Name.c_str());
    if (TitleDataOverrideLabel.length() > 0) { writer.String("TitleDataOverrideLabel"); writer.String(TitleDataOverrideLabel.c_str()); }
    writer.String("TrafficPercentage"); writer.Uint(TrafficPercentage);
    if (!Variables.empty()) {
        writer.String("Variables");
        writer.StartArray();
        for (std::list<Variable>::iterator iter = Variables.begin(); iter != Variables.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool Variant::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator IsControl_member = obj.FindMember("IsControl");
    if (IsControl_member != obj.MemberEnd() && !IsControl_member->value.IsNull()) IsControl = IsControl_member->value.GetBool();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator TitleDataOverrideLabel_member = obj.FindMember("TitleDataOverrideLabel");
    if (TitleDataOverrideLabel_member != obj.MemberEnd() && !TitleDataOverrideLabel_member->value.IsNull()) TitleDataOverrideLabel = TitleDataOverrideLabel_member->value.GetString();
    const Value::ConstMemberIterator TrafficPercentage_member = obj.FindMember("TrafficPercentage");
    if (TrafficPercentage_member != obj.MemberEnd() && !TrafficPercentage_member->value.IsNull()) TrafficPercentage = TrafficPercentage_member->value.GetUint();
    const Value::ConstMemberIterator Variables_member = obj.FindMember("Variables");
    if (Variables_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Variables_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Variables.push_back(Variable(memberList[i]));
        }
    }

    return true;
}

CreateExperimentRequest::~CreateExperimentRequest()
{

}

void CreateExperimentRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    if (Duration.notNull()) { writer.String("Duration"); writer.Uint(Duration); }
    if (EndDate.notNull()) { writer.String("EndDate"); writeDatetime(EndDate, writer); }
    if (ExclusionGroupId.length() > 0) { writer.String("ExclusionGroupId"); writer.String(ExclusionGroupId.c_str()); }
    if (ExclusionGroupTrafficAllocation.notNull()) { writer.String("ExclusionGroupTrafficAllocation"); writer.Uint(ExclusionGroupTrafficAllocation); }
    if (pfExperimentType.notNull()) { writer.String("ExperimentType"); writeExperimentTypeEnumJSON(pfExperimentType, writer); }
    writer.String("Name"); writer.String(Name.c_str());
    if (SegmentId.length() > 0) { writer.String("SegmentId"); writer.String(SegmentId.c_str()); }
    writer.String("StartDate"); writeDatetime(StartDate, writer);
    if (!TitlePlayerAccountTestIds.empty()) {
        writer.String("TitlePlayerAccountTestIds");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = TitlePlayerAccountTestIds.begin(); iter != TitlePlayerAccountTestIds.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("Variants");
    writer.StartArray();
    for (std::list<Variant>::iterator iter = Variants.begin(); iter != Variants.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.EndObject();
}

bool CreateExperimentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator Duration_member = obj.FindMember("Duration");
    if (Duration_member != obj.MemberEnd() && !Duration_member->value.IsNull()) Duration = Duration_member->value.GetUint();
    const Value::ConstMemberIterator EndDate_member = obj.FindMember("EndDate");
    if (EndDate_member != obj.MemberEnd() && !EndDate_member->value.IsNull()) EndDate = readDatetime(EndDate_member->value);
    const Value::ConstMemberIterator ExclusionGroupId_member = obj.FindMember("ExclusionGroupId");
    if (ExclusionGroupId_member != obj.MemberEnd() && !ExclusionGroupId_member->value.IsNull()) ExclusionGroupId = ExclusionGroupId_member->value.GetString();
    const Value::ConstMemberIterator ExclusionGroupTrafficAllocation_member = obj.FindMember("ExclusionGroupTrafficAllocation");
    if (ExclusionGroupTrafficAllocation_member != obj.MemberEnd() && !ExclusionGroupTrafficAllocation_member->value.IsNull()) ExclusionGroupTrafficAllocation = ExclusionGroupTrafficAllocation_member->value.GetUint();
    const Value::ConstMemberIterator ExperimentType_member = obj.FindMember("ExperimentType");
    if (ExperimentType_member != obj.MemberEnd() && !ExperimentType_member->value.IsNull()) pfExperimentType = readExperimentTypeFromValue(ExperimentType_member->value);
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator SegmentId_member = obj.FindMember("SegmentId");
    if (SegmentId_member != obj.MemberEnd() && !SegmentId_member->value.IsNull()) SegmentId = SegmentId_member->value.GetString();
    const Value::ConstMemberIterator StartDate_member = obj.FindMember("StartDate");
    if (StartDate_member != obj.MemberEnd() && !StartDate_member->value.IsNull()) StartDate = readDatetime(StartDate_member->value);
    const Value::ConstMemberIterator TitlePlayerAccountTestIds_member = obj.FindMember("TitlePlayerAccountTestIds");
    if (TitlePlayerAccountTestIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TitlePlayerAccountTestIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TitlePlayerAccountTestIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator Variants_member = obj.FindMember("Variants");
    if (Variants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Variants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Variants.push_back(Variant(memberList[i]));
        }
    }

    return true;
}

CreateExperimentResult::~CreateExperimentResult()
{

}

void CreateExperimentResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ExperimentId.length() > 0) { writer.String("ExperimentId"); writer.String(ExperimentId.c_str()); }
    writer.EndObject();
}

bool CreateExperimentResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ExperimentId_member = obj.FindMember("ExperimentId");
    if (ExperimentId_member != obj.MemberEnd() && !ExperimentId_member->value.IsNull()) ExperimentId = ExperimentId_member->value.GetString();

    return true;
}

DeleteExclusionGroupRequest::~DeleteExclusionGroupRequest()
{

}

void DeleteExclusionGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("ExclusionGroupId"); writer.String(ExclusionGroupId.c_str());
    writer.EndObject();
}

bool DeleteExclusionGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator ExclusionGroupId_member = obj.FindMember("ExclusionGroupId");
    if (ExclusionGroupId_member != obj.MemberEnd() && !ExclusionGroupId_member->value.IsNull()) ExclusionGroupId = ExclusionGroupId_member->value.GetString();

    return true;
}

DeleteExperimentRequest::~DeleteExperimentRequest()
{

}

void DeleteExperimentRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("ExperimentId"); writer.String(ExperimentId.c_str());
    writer.EndObject();
}

bool DeleteExperimentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator ExperimentId_member = obj.FindMember("ExperimentId");
    if (ExperimentId_member != obj.MemberEnd() && !ExperimentId_member->value.IsNull()) ExperimentId = ExperimentId_member->value.GetString();

    return true;
}

EmptyResponse::~EmptyResponse()
{

}

void EmptyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool EmptyResponse::readFromValue(const rapidjson::Value& obj)
{

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

ExclusionGroupTrafficAllocation::~ExclusionGroupTrafficAllocation()
{

}

void ExclusionGroupTrafficAllocation::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ExperimentId.length() > 0) { writer.String("ExperimentId"); writer.String(ExperimentId.c_str()); }
    writer.String("TrafficAllocation"); writer.Uint(TrafficAllocation);
    writer.EndObject();
}

bool ExclusionGroupTrafficAllocation::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ExperimentId_member = obj.FindMember("ExperimentId");
    if (ExperimentId_member != obj.MemberEnd() && !ExperimentId_member->value.IsNull()) ExperimentId = ExperimentId_member->value.GetString();
    const Value::ConstMemberIterator TrafficAllocation_member = obj.FindMember("TrafficAllocation");
    if (TrafficAllocation_member != obj.MemberEnd() && !TrafficAllocation_member->value.IsNull()) TrafficAllocation = TrafficAllocation_member->value.GetUint();

    return true;
}
void PlayFab::ExperimentationModels::writeExperimentStateEnumJSON(ExperimentState enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case ExperimentStateNew: writer.String("New"); break;
    case ExperimentStateStarted: writer.String("Started"); break;
    case ExperimentStateStopped: writer.String("Stopped"); break;
    case ExperimentStateDeleted: writer.String("Deleted"); break;

    }
}

ExperimentState PlayFab::ExperimentationModels::readExperimentStateFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, ExperimentState> _ExperimentStateMap;
    if (_ExperimentStateMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _ExperimentStateMap["New"] = ExperimentStateNew;
        _ExperimentStateMap["Started"] = ExperimentStateStarted;
        _ExperimentStateMap["Stopped"] = ExperimentStateStopped;
        _ExperimentStateMap["Deleted"] = ExperimentStateDeleted;

    }

    auto output = _ExperimentStateMap.find(obj.GetString());
    if (output != _ExperimentStateMap.end())
        return output->second;

    return ExperimentStateNew; // Basically critical fail
}

Experiment::~Experiment()
{

}

void Experiment::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    if (Duration.notNull()) { writer.String("Duration"); writer.Uint(Duration); }
    if (EndDate.notNull()) { writer.String("EndDate"); writeDatetime(EndDate, writer); }
    if (ExclusionGroupId.length() > 0) { writer.String("ExclusionGroupId"); writer.String(ExclusionGroupId.c_str()); }
    if (ExclusionGroupTrafficAllocation.notNull()) { writer.String("ExclusionGroupTrafficAllocation"); writer.Uint(ExclusionGroupTrafficAllocation); }
    if (pfExperimentType.notNull()) { writer.String("ExperimentType"); writeExperimentTypeEnumJSON(pfExperimentType, writer); }
    if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    if (SegmentId.length() > 0) { writer.String("SegmentId"); writer.String(SegmentId.c_str()); }
    writer.String("StartDate"); writeDatetime(StartDate, writer);
    if (State.notNull()) { writer.String("State"); writeExperimentStateEnumJSON(State, writer); }
    if (!TitlePlayerAccountTestIds.empty()) {
        writer.String("TitlePlayerAccountTestIds");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = TitlePlayerAccountTestIds.begin(); iter != TitlePlayerAccountTestIds.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (!Variants.empty()) {
        writer.String("Variants");
        writer.StartArray();
        for (std::list<Variant>::iterator iter = Variants.begin(); iter != Variants.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool Experiment::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator Duration_member = obj.FindMember("Duration");
    if (Duration_member != obj.MemberEnd() && !Duration_member->value.IsNull()) Duration = Duration_member->value.GetUint();
    const Value::ConstMemberIterator EndDate_member = obj.FindMember("EndDate");
    if (EndDate_member != obj.MemberEnd() && !EndDate_member->value.IsNull()) EndDate = readDatetime(EndDate_member->value);
    const Value::ConstMemberIterator ExclusionGroupId_member = obj.FindMember("ExclusionGroupId");
    if (ExclusionGroupId_member != obj.MemberEnd() && !ExclusionGroupId_member->value.IsNull()) ExclusionGroupId = ExclusionGroupId_member->value.GetString();
    const Value::ConstMemberIterator ExclusionGroupTrafficAllocation_member = obj.FindMember("ExclusionGroupTrafficAllocation");
    if (ExclusionGroupTrafficAllocation_member != obj.MemberEnd() && !ExclusionGroupTrafficAllocation_member->value.IsNull()) ExclusionGroupTrafficAllocation = ExclusionGroupTrafficAllocation_member->value.GetUint();
    const Value::ConstMemberIterator ExperimentType_member = obj.FindMember("ExperimentType");
    if (ExperimentType_member != obj.MemberEnd() && !ExperimentType_member->value.IsNull()) pfExperimentType = readExperimentTypeFromValue(ExperimentType_member->value);
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator SegmentId_member = obj.FindMember("SegmentId");
    if (SegmentId_member != obj.MemberEnd() && !SegmentId_member->value.IsNull()) SegmentId = SegmentId_member->value.GetString();
    const Value::ConstMemberIterator StartDate_member = obj.FindMember("StartDate");
    if (StartDate_member != obj.MemberEnd() && !StartDate_member->value.IsNull()) StartDate = readDatetime(StartDate_member->value);
    const Value::ConstMemberIterator State_member = obj.FindMember("State");
    if (State_member != obj.MemberEnd() && !State_member->value.IsNull()) State = readExperimentStateFromValue(State_member->value);
    const Value::ConstMemberIterator TitlePlayerAccountTestIds_member = obj.FindMember("TitlePlayerAccountTestIds");
    if (TitlePlayerAccountTestIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TitlePlayerAccountTestIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TitlePlayerAccountTestIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator Variants_member = obj.FindMember("Variants");
    if (Variants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Variants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Variants.push_back(Variant(memberList[i]));
        }
    }

    return true;
}

ExperimentExclusionGroup::~ExperimentExclusionGroup()
{

}

void ExperimentExclusionGroup::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    if (ExclusionGroupId.length() > 0) { writer.String("ExclusionGroupId"); writer.String(ExclusionGroupId.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    writer.EndObject();
}

bool ExperimentExclusionGroup::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator ExclusionGroupId_member = obj.FindMember("ExclusionGroupId");
    if (ExclusionGroupId_member != obj.MemberEnd() && !ExclusionGroupId_member->value.IsNull()) ExclusionGroupId = ExclusionGroupId_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

    return true;
}

GetExclusionGroupsRequest::~GetExclusionGroupsRequest()
{

}

void GetExclusionGroupsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool GetExclusionGroupsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

GetExclusionGroupsResult::~GetExclusionGroupsResult()
{

}

void GetExclusionGroupsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!ExclusionGroups.empty()) {
        writer.String("ExclusionGroups");
        writer.StartArray();
        for (std::list<ExperimentExclusionGroup>::iterator iter = ExclusionGroups.begin(); iter != ExclusionGroups.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetExclusionGroupsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ExclusionGroups_member = obj.FindMember("ExclusionGroups");
    if (ExclusionGroups_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ExclusionGroups_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ExclusionGroups.push_back(ExperimentExclusionGroup(memberList[i]));
        }
    }

    return true;
}

GetExclusionGroupTrafficRequest::~GetExclusionGroupTrafficRequest()
{

}

void GetExclusionGroupTrafficRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("ExclusionGroupId"); writer.String(ExclusionGroupId.c_str());
    writer.EndObject();
}

bool GetExclusionGroupTrafficRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator ExclusionGroupId_member = obj.FindMember("ExclusionGroupId");
    if (ExclusionGroupId_member != obj.MemberEnd() && !ExclusionGroupId_member->value.IsNull()) ExclusionGroupId = ExclusionGroupId_member->value.GetString();

    return true;
}

GetExclusionGroupTrafficResult::~GetExclusionGroupTrafficResult()
{

}

void GetExclusionGroupTrafficResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!TrafficAllocations.empty()) {
        writer.String("TrafficAllocations");
        writer.StartArray();
        for (std::list<ExclusionGroupTrafficAllocation>::iterator iter = TrafficAllocations.begin(); iter != TrafficAllocations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetExclusionGroupTrafficResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator TrafficAllocations_member = obj.FindMember("TrafficAllocations");
    if (TrafficAllocations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TrafficAllocations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TrafficAllocations.push_back(ExclusionGroupTrafficAllocation(memberList[i]));
        }
    }

    return true;
}

GetExperimentsRequest::~GetExperimentsRequest()
{

}

void GetExperimentsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool GetExperimentsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

GetExperimentsResult::~GetExperimentsResult()
{

}

void GetExperimentsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Experiments.empty()) {
        writer.String("Experiments");
        writer.StartArray();
        for (std::list<Experiment>::iterator iter = Experiments.begin(); iter != Experiments.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetExperimentsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Experiments_member = obj.FindMember("Experiments");
    if (Experiments_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Experiments_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Experiments.push_back(Experiment(memberList[i]));
        }
    }

    return true;
}

GetLatestScorecardRequest::~GetLatestScorecardRequest()
{

}

void GetLatestScorecardRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    if (ExperimentId.length() > 0) { writer.String("ExperimentId"); writer.String(ExperimentId.c_str()); }
    writer.EndObject();
}

bool GetLatestScorecardRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator ExperimentId_member = obj.FindMember("ExperimentId");
    if (ExperimentId_member != obj.MemberEnd() && !ExperimentId_member->value.IsNull()) ExperimentId = ExperimentId_member->value.GetString();

    return true;
}

MetricData::~MetricData()
{

}

void MetricData::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ConfidenceIntervalEnd"); writer.Double(ConfidenceIntervalEnd);
    writer.String("ConfidenceIntervalStart"); writer.Double(ConfidenceIntervalStart);
    writer.String("DeltaAbsoluteChange"); writer.Double(DeltaAbsoluteChange);
    writer.String("DeltaRelativeChange"); writer.Double(DeltaRelativeChange);
    if (InternalName.length() > 0) { writer.String("InternalName"); writer.String(InternalName.c_str()); }
    if (Movement.length() > 0) { writer.String("Movement"); writer.String(Movement.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    writer.String("PMove"); writer.Double(PMove);
    writer.String("PValue"); writer.Double(PValue);
    writer.String("PValueThreshold"); writer.Double(PValueThreshold);
    if (StatSigLevel.length() > 0) { writer.String("StatSigLevel"); writer.String(StatSigLevel.c_str()); }
    writer.String("StdDev"); writer.Double(StdDev);
    writer.String("Value"); writer.Double(Value);
    writer.EndObject();
}

bool MetricData::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ConfidenceIntervalEnd_member = obj.FindMember("ConfidenceIntervalEnd");
    if (ConfidenceIntervalEnd_member != obj.MemberEnd() && !ConfidenceIntervalEnd_member->value.IsNull()) ConfidenceIntervalEnd = ConfidenceIntervalEnd_member->value.GetDouble();
    const Value::ConstMemberIterator ConfidenceIntervalStart_member = obj.FindMember("ConfidenceIntervalStart");
    if (ConfidenceIntervalStart_member != obj.MemberEnd() && !ConfidenceIntervalStart_member->value.IsNull()) ConfidenceIntervalStart = ConfidenceIntervalStart_member->value.GetDouble();
    const Value::ConstMemberIterator DeltaAbsoluteChange_member = obj.FindMember("DeltaAbsoluteChange");
    if (DeltaAbsoluteChange_member != obj.MemberEnd() && !DeltaAbsoluteChange_member->value.IsNull()) DeltaAbsoluteChange = (float)DeltaAbsoluteChange_member->value.GetDouble();
    const Value::ConstMemberIterator DeltaRelativeChange_member = obj.FindMember("DeltaRelativeChange");
    if (DeltaRelativeChange_member != obj.MemberEnd() && !DeltaRelativeChange_member->value.IsNull()) DeltaRelativeChange = (float)DeltaRelativeChange_member->value.GetDouble();
    const Value::ConstMemberIterator InternalName_member = obj.FindMember("InternalName");
    if (InternalName_member != obj.MemberEnd() && !InternalName_member->value.IsNull()) InternalName = InternalName_member->value.GetString();
    const Value::ConstMemberIterator Movement_member = obj.FindMember("Movement");
    if (Movement_member != obj.MemberEnd() && !Movement_member->value.IsNull()) Movement = Movement_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator PMove_member = obj.FindMember("PMove");
    if (PMove_member != obj.MemberEnd() && !PMove_member->value.IsNull()) PMove = (float)PMove_member->value.GetDouble();
    const Value::ConstMemberIterator PValue_member = obj.FindMember("PValue");
    if (PValue_member != obj.MemberEnd() && !PValue_member->value.IsNull()) PValue = (float)PValue_member->value.GetDouble();
    const Value::ConstMemberIterator PValueThreshold_member = obj.FindMember("PValueThreshold");
    if (PValueThreshold_member != obj.MemberEnd() && !PValueThreshold_member->value.IsNull()) PValueThreshold = (float)PValueThreshold_member->value.GetDouble();
    const Value::ConstMemberIterator StatSigLevel_member = obj.FindMember("StatSigLevel");
    if (StatSigLevel_member != obj.MemberEnd() && !StatSigLevel_member->value.IsNull()) StatSigLevel = StatSigLevel_member->value.GetString();
    const Value::ConstMemberIterator StdDev_member = obj.FindMember("StdDev");
    if (StdDev_member != obj.MemberEnd() && !StdDev_member->value.IsNull()) StdDev = (float)StdDev_member->value.GetDouble();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = (float)Value_member->value.GetDouble();

    return true;
}

ScorecardDataRow::~ScorecardDataRow()
{

}

void ScorecardDataRow::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("IsControl"); writer.Bool(IsControl);
    if (!MetricDataRows.empty()) {
        writer.String("MetricDataRows");
        writer.StartObject();
        for (std::map<std::string, MetricData>::iterator iter = MetricDataRows.begin(); iter != MetricDataRows.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("PlayerCount"); writer.Uint(PlayerCount);
    if (VariantName.length() > 0) { writer.String("VariantName"); writer.String(VariantName.c_str()); }
    writer.EndObject();
}

bool ScorecardDataRow::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IsControl_member = obj.FindMember("IsControl");
    if (IsControl_member != obj.MemberEnd() && !IsControl_member->value.IsNull()) IsControl = IsControl_member->value.GetBool();
    const Value::ConstMemberIterator MetricDataRows_member = obj.FindMember("MetricDataRows");
    if (MetricDataRows_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = MetricDataRows_member->value.MemberBegin(); iter != MetricDataRows_member->value.MemberEnd(); ++iter) {
            MetricDataRows[iter->name.GetString()] = MetricData(iter->value);
        }
    }
    const Value::ConstMemberIterator PlayerCount_member = obj.FindMember("PlayerCount");
    if (PlayerCount_member != obj.MemberEnd() && !PlayerCount_member->value.IsNull()) PlayerCount = PlayerCount_member->value.GetUint();
    const Value::ConstMemberIterator VariantName_member = obj.FindMember("VariantName");
    if (VariantName_member != obj.MemberEnd() && !VariantName_member->value.IsNull()) VariantName = VariantName_member->value.GetString();

    return true;
}

Scorecard::~Scorecard()
{

}

void Scorecard::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DateGenerated.length() > 0) { writer.String("DateGenerated"); writer.String(DateGenerated.c_str()); }
    if (Duration.length() > 0) { writer.String("Duration"); writer.String(Duration.c_str()); }
    writer.String("EventsProcessed"); writer.Double(EventsProcessed);
    if (ExperimentId.length() > 0) { writer.String("ExperimentId"); writer.String(ExperimentId.c_str()); }
    if (ExperimentName.length() > 0) { writer.String("ExperimentName"); writer.String(ExperimentName.c_str()); }
    if (LatestJobStatus.notNull()) { writer.String("LatestJobStatus"); writeAnalysisTaskStateEnumJSON(LatestJobStatus, writer); }
    writer.String("SampleRatioMismatch"); writer.Bool(SampleRatioMismatch);
    if (!ScorecardDataRows.empty()) {
        writer.String("ScorecardDataRows");
        writer.StartArray();
        for (std::list<ScorecardDataRow>::iterator iter = ScorecardDataRows.begin(); iter != ScorecardDataRows.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool Scorecard::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DateGenerated_member = obj.FindMember("DateGenerated");
    if (DateGenerated_member != obj.MemberEnd() && !DateGenerated_member->value.IsNull()) DateGenerated = DateGenerated_member->value.GetString();
    const Value::ConstMemberIterator Duration_member = obj.FindMember("Duration");
    if (Duration_member != obj.MemberEnd() && !Duration_member->value.IsNull()) Duration = Duration_member->value.GetString();
    const Value::ConstMemberIterator EventsProcessed_member = obj.FindMember("EventsProcessed");
    if (EventsProcessed_member != obj.MemberEnd() && !EventsProcessed_member->value.IsNull()) EventsProcessed = EventsProcessed_member->value.GetDouble();
    const Value::ConstMemberIterator ExperimentId_member = obj.FindMember("ExperimentId");
    if (ExperimentId_member != obj.MemberEnd() && !ExperimentId_member->value.IsNull()) ExperimentId = ExperimentId_member->value.GetString();
    const Value::ConstMemberIterator ExperimentName_member = obj.FindMember("ExperimentName");
    if (ExperimentName_member != obj.MemberEnd() && !ExperimentName_member->value.IsNull()) ExperimentName = ExperimentName_member->value.GetString();
    const Value::ConstMemberIterator LatestJobStatus_member = obj.FindMember("LatestJobStatus");
    if (LatestJobStatus_member != obj.MemberEnd() && !LatestJobStatus_member->value.IsNull()) LatestJobStatus = readAnalysisTaskStateFromValue(LatestJobStatus_member->value);
    const Value::ConstMemberIterator SampleRatioMismatch_member = obj.FindMember("SampleRatioMismatch");
    if (SampleRatioMismatch_member != obj.MemberEnd() && !SampleRatioMismatch_member->value.IsNull()) SampleRatioMismatch = SampleRatioMismatch_member->value.GetBool();
    const Value::ConstMemberIterator ScorecardDataRows_member = obj.FindMember("ScorecardDataRows");
    if (ScorecardDataRows_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ScorecardDataRows_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ScorecardDataRows.push_back(ScorecardDataRow(memberList[i]));
        }
    }

    return true;
}

GetLatestScorecardResult::~GetLatestScorecardResult()
{
    if (pfScorecard != NULL) delete pfScorecard;

}

void GetLatestScorecardResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (pfScorecard != NULL) { writer.String("Scorecard"); pfScorecard->writeJSON(writer); }
    writer.EndObject();
}

bool GetLatestScorecardResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Scorecard_member = obj.FindMember("Scorecard");
    if (Scorecard_member != obj.MemberEnd() && !Scorecard_member->value.IsNull()) pfScorecard = new Scorecard(Scorecard_member->value);

    return true;
}

GetTreatmentAssignmentRequest::~GetTreatmentAssignmentRequest()
{
    if (Entity != NULL) delete Entity;

}

void GetTreatmentAssignmentRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool GetTreatmentAssignmentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

TreatmentAssignment::~TreatmentAssignment()
{

}

void TreatmentAssignment::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Variables.empty()) {
        writer.String("Variables");
        writer.StartArray();
        for (std::list<Variable>::iterator iter = Variables.begin(); iter != Variables.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Variants.empty()) {
        writer.String("Variants");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = Variants.begin(); iter != Variants.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool TreatmentAssignment::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Variables_member = obj.FindMember("Variables");
    if (Variables_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Variables_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Variables.push_back(Variable(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Variants_member = obj.FindMember("Variants");
    if (Variants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Variants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Variants.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetTreatmentAssignmentResult::~GetTreatmentAssignmentResult()
{
    if (pfTreatmentAssignment != NULL) delete pfTreatmentAssignment;

}

void GetTreatmentAssignmentResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (pfTreatmentAssignment != NULL) { writer.String("TreatmentAssignment"); pfTreatmentAssignment->writeJSON(writer); }
    writer.EndObject();
}

bool GetTreatmentAssignmentResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator TreatmentAssignment_member = obj.FindMember("TreatmentAssignment");
    if (TreatmentAssignment_member != obj.MemberEnd() && !TreatmentAssignment_member->value.IsNull()) pfTreatmentAssignment = new TreatmentAssignment(TreatmentAssignment_member->value);

    return true;
}

StartExperimentRequest::~StartExperimentRequest()
{

}

void StartExperimentRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("ExperimentId"); writer.String(ExperimentId.c_str());
    writer.EndObject();
}

bool StartExperimentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator ExperimentId_member = obj.FindMember("ExperimentId");
    if (ExperimentId_member != obj.MemberEnd() && !ExperimentId_member->value.IsNull()) ExperimentId = ExperimentId_member->value.GetString();

    return true;
}

StopExperimentRequest::~StopExperimentRequest()
{

}

void StopExperimentRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("ExperimentId"); writer.String(ExperimentId.c_str());
    writer.EndObject();
}

bool StopExperimentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator ExperimentId_member = obj.FindMember("ExperimentId");
    if (ExperimentId_member != obj.MemberEnd() && !ExperimentId_member->value.IsNull()) ExperimentId = ExperimentId_member->value.GetString();

    return true;
}

UpdateExclusionGroupRequest::~UpdateExclusionGroupRequest()
{

}

void UpdateExclusionGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    writer.String("ExclusionGroupId"); writer.String(ExclusionGroupId.c_str());
    writer.String("Name"); writer.String(Name.c_str());
    writer.EndObject();
}

bool UpdateExclusionGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator ExclusionGroupId_member = obj.FindMember("ExclusionGroupId");
    if (ExclusionGroupId_member != obj.MemberEnd() && !ExclusionGroupId_member->value.IsNull()) ExclusionGroupId = ExclusionGroupId_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

    return true;
}

UpdateExperimentRequest::~UpdateExperimentRequest()
{

}

void UpdateExperimentRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    if (Duration.notNull()) { writer.String("Duration"); writer.Uint(Duration); }
    if (EndDate.notNull()) { writer.String("EndDate"); writeDatetime(EndDate, writer); }
    if (ExclusionGroupId.length() > 0) { writer.String("ExclusionGroupId"); writer.String(ExclusionGroupId.c_str()); }
    if (ExclusionGroupTrafficAllocation.notNull()) { writer.String("ExclusionGroupTrafficAllocation"); writer.Uint(ExclusionGroupTrafficAllocation); }
    if (pfExperimentType.notNull()) { writer.String("ExperimentType"); writeExperimentTypeEnumJSON(pfExperimentType, writer); }
    writer.String("Id"); writer.String(Id.c_str());
    writer.String("Name"); writer.String(Name.c_str());
    if (SegmentId.length() > 0) { writer.String("SegmentId"); writer.String(SegmentId.c_str()); }
    writer.String("StartDate"); writeDatetime(StartDate, writer);
    if (!TitlePlayerAccountTestIds.empty()) {
        writer.String("TitlePlayerAccountTestIds");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = TitlePlayerAccountTestIds.begin(); iter != TitlePlayerAccountTestIds.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("Variants");
    writer.StartArray();
    for (std::list<Variant>::iterator iter = Variants.begin(); iter != Variants.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.EndObject();
}

bool UpdateExperimentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator Duration_member = obj.FindMember("Duration");
    if (Duration_member != obj.MemberEnd() && !Duration_member->value.IsNull()) Duration = Duration_member->value.GetUint();
    const Value::ConstMemberIterator EndDate_member = obj.FindMember("EndDate");
    if (EndDate_member != obj.MemberEnd() && !EndDate_member->value.IsNull()) EndDate = readDatetime(EndDate_member->value);
    const Value::ConstMemberIterator ExclusionGroupId_member = obj.FindMember("ExclusionGroupId");
    if (ExclusionGroupId_member != obj.MemberEnd() && !ExclusionGroupId_member->value.IsNull()) ExclusionGroupId = ExclusionGroupId_member->value.GetString();
    const Value::ConstMemberIterator ExclusionGroupTrafficAllocation_member = obj.FindMember("ExclusionGroupTrafficAllocation");
    if (ExclusionGroupTrafficAllocation_member != obj.MemberEnd() && !ExclusionGroupTrafficAllocation_member->value.IsNull()) ExclusionGroupTrafficAllocation = ExclusionGroupTrafficAllocation_member->value.GetUint();
    const Value::ConstMemberIterator ExperimentType_member = obj.FindMember("ExperimentType");
    if (ExperimentType_member != obj.MemberEnd() && !ExperimentType_member->value.IsNull()) pfExperimentType = readExperimentTypeFromValue(ExperimentType_member->value);
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator SegmentId_member = obj.FindMember("SegmentId");
    if (SegmentId_member != obj.MemberEnd() && !SegmentId_member->value.IsNull()) SegmentId = SegmentId_member->value.GetString();
    const Value::ConstMemberIterator StartDate_member = obj.FindMember("StartDate");
    if (StartDate_member != obj.MemberEnd() && !StartDate_member->value.IsNull()) StartDate = readDatetime(StartDate_member->value);
    const Value::ConstMemberIterator TitlePlayerAccountTestIds_member = obj.FindMember("TitlePlayerAccountTestIds");
    if (TitlePlayerAccountTestIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TitlePlayerAccountTestIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TitlePlayerAccountTestIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator Variants_member = obj.FindMember("Variants");
    if (Variants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Variants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Variants.push_back(Variant(memberList[i]));
        }
    }

    return true;
}

