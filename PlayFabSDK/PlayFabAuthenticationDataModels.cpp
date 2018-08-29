#include "PlayFabAuthenticationDataModels.h"

using namespace PlayFab;
using namespace PlayFab::AuthenticationModels;
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

