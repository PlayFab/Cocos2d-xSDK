#include "PlayFabEventsDataModels.h"

using namespace PlayFab;
using namespace PlayFab::EventsModels;
using namespace rapidjson;

void PlayFab::EventsModels::writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer)
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

EntityTypes PlayFab::EventsModels::readEntityTypesFromValue(const rapidjson::Value& obj)
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

EventContents::~EventContents()
{

}

void EventContents::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Entity"); Entity.writeJSON(writer);
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
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
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

