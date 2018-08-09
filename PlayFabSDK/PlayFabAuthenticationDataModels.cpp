#include "PlayFabAuthenticationDataModels.h"

using namespace PlayFab;
using namespace PlayFab::AuthenticationModels;
using namespace rapidjson;

void PlayFab::AuthenticationModels::writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer)
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

EntityTypes PlayFab::AuthenticationModels::readEntityTypesFromValue(const rapidjson::Value& obj)
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

