#include "PlayFabEventsDataModels.h"

using namespace PlayFab;
using namespace PlayFab::EventsModels;
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

EventContents::~EventContents()
{
    if (Entity != NULL) delete Entity;

}

void EventContents::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("EventNamespace"); writer.String(EventNamespace.c_str());
    writer.String("Name"); writer.String(Name.c_str());
    if (OriginalId.length() > 0) { writer.String("OriginalId"); writer.String(OriginalId.c_str()); }
    if (OriginalTimestamp.notNull()) { writer.String("OriginalTimestamp"); writeDatetime(OriginalTimestamp, writer); }
    if (Payload.notNull()) { writer.String("Payload"); Payload.writeJSON(writer); }
    if (PayloadJSON.length() > 0) { writer.String("PayloadJSON"); writer.String(PayloadJSON.c_str()); }
    writer.EndObject();
}

bool EventContents::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator EventNamespace_member = obj.FindMember("EventNamespace");
    if (EventNamespace_member != obj.MemberEnd() && !EventNamespace_member->value.IsNull()) EventNamespace = EventNamespace_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator OriginalId_member = obj.FindMember("OriginalId");
    if (OriginalId_member != obj.MemberEnd() && !OriginalId_member->value.IsNull()) OriginalId = OriginalId_member->value.GetString();
    const Value::ConstMemberIterator OriginalTimestamp_member = obj.FindMember("OriginalTimestamp");
    if (OriginalTimestamp_member != obj.MemberEnd() && !OriginalTimestamp_member->value.IsNull()) OriginalTimestamp = readDatetime(OriginalTimestamp_member->value);
    const Value::ConstMemberIterator Payload_member = obj.FindMember("Payload");
    if (Payload_member != obj.MemberEnd() && !Payload_member->value.IsNull()) Payload = MultitypeVar(Payload_member->value);
    const Value::ConstMemberIterator PayloadJSON_member = obj.FindMember("PayloadJSON");
    if (PayloadJSON_member != obj.MemberEnd() && !PayloadJSON_member->value.IsNull()) PayloadJSON = PayloadJSON_member->value.GetString();

    return true;
}

WriteEventsRequest::~WriteEventsRequest()
{

}

void WriteEventsRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("Events");
    writer.StartArray();
    for (std::list<EventContents>::iterator iter = Events.begin(); iter != Events.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.EndObject();
}

bool WriteEventsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Events_member = obj.FindMember("Events");
    if (Events_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Events_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Events.push_back(EventContents(memberList[i]));
        }
    }

    return true;
}

WriteEventsResponse::~WriteEventsResponse()
{

}

void WriteEventsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!AssignedEventIds.empty()) {
        writer.String("AssignedEventIds");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = AssignedEventIds.begin(); iter != AssignedEventIds.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool WriteEventsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AssignedEventIds_member = obj.FindMember("AssignedEventIds");
    if (AssignedEventIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AssignedEventIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AssignedEventIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

