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

ActivateAPIKeyRequest::~ActivateAPIKeyRequest()
{
    if (Entity != NULL) delete Entity;

}

void ActivateAPIKeyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (APIKeyId.length() > 0) { writer.String("APIKeyId"); writer.String(APIKeyId.c_str()); }
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool ActivateAPIKeyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator APIKeyId_member = obj.FindMember("APIKeyId");
    if (APIKeyId_member != obj.MemberEnd() && !APIKeyId_member->value.IsNull()) APIKeyId = APIKeyId_member->value.GetString();
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

ActivateAPIKeyResponse::~ActivateAPIKeyResponse()
{

}

void ActivateAPIKeyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool ActivateAPIKeyResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

CreateAPIKeyDetails::~CreateAPIKeyDetails()
{

}

void CreateAPIKeyDetails::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Active"); writer.Bool(Active);
    if (APIKeyId.length() > 0) { writer.String("APIKeyId"); writer.String(APIKeyId.c_str()); }
    if (APIKeySecret.length() > 0) { writer.String("APIKeySecret"); writer.String(APIKeySecret.c_str()); }
    writer.String("Created"); writeDatetime(Created, writer);
    writer.EndObject();
}

bool CreateAPIKeyDetails::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
    if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();
    const Value::ConstMemberIterator APIKeyId_member = obj.FindMember("APIKeyId");
    if (APIKeyId_member != obj.MemberEnd() && !APIKeyId_member->value.IsNull()) APIKeyId = APIKeyId_member->value.GetString();
    const Value::ConstMemberIterator APIKeySecret_member = obj.FindMember("APIKeySecret");
    if (APIKeySecret_member != obj.MemberEnd() && !APIKeySecret_member->value.IsNull()) APIKeySecret = APIKeySecret_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);

    return true;
}

CreateAPIKeyRequest::~CreateAPIKeyRequest()
{
    if (Entity != NULL) delete Entity;

}

void CreateAPIKeyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool CreateAPIKeyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

CreateAPIKeyResponse::~CreateAPIKeyResponse()
{
    if (Entity != NULL) delete Entity;
    if (Key != NULL) delete Key;

}

void CreateAPIKeyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (Key != NULL) { writer.String("Key"); Key->writeJSON(writer); }
    writer.EndObject();
}

bool CreateAPIKeyResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = new CreateAPIKeyDetails(Key_member->value);

    return true;
}

DeactivateAPIKeyRequest::~DeactivateAPIKeyRequest()
{
    if (Entity != NULL) delete Entity;

}

void DeactivateAPIKeyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (APIKeyId.length() > 0) { writer.String("APIKeyId"); writer.String(APIKeyId.c_str()); }
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool DeactivateAPIKeyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator APIKeyId_member = obj.FindMember("APIKeyId");
    if (APIKeyId_member != obj.MemberEnd() && !APIKeyId_member->value.IsNull()) APIKeyId = APIKeyId_member->value.GetString();
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

DeactivateAPIKeyResponse::~DeactivateAPIKeyResponse()
{

}

void DeactivateAPIKeyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool DeactivateAPIKeyResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

DeleteAPIKeyRequest::~DeleteAPIKeyRequest()
{
    if (Entity != NULL) delete Entity;

}

void DeleteAPIKeyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (APIKeyId.length() > 0) { writer.String("APIKeyId"); writer.String(APIKeyId.c_str()); }
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool DeleteAPIKeyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator APIKeyId_member = obj.FindMember("APIKeyId");
    if (APIKeyId_member != obj.MemberEnd() && !APIKeyId_member->value.IsNull()) APIKeyId = APIKeyId_member->value.GetString();
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

DeleteAPIKeyResponse::~DeleteAPIKeyResponse()
{

}

void DeleteAPIKeyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool DeleteAPIKeyResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetAPIKeyDetails::~GetAPIKeyDetails()
{

}

void GetAPIKeyDetails::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Active"); writer.Bool(Active);
    if (APIKeyId.length() > 0) { writer.String("APIKeyId"); writer.String(APIKeyId.c_str()); }
    writer.String("Created"); writeDatetime(Created, writer);
    writer.EndObject();
}

bool GetAPIKeyDetails::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
    if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();
    const Value::ConstMemberIterator APIKeyId_member = obj.FindMember("APIKeyId");
    if (APIKeyId_member != obj.MemberEnd() && !APIKeyId_member->value.IsNull()) APIKeyId = APIKeyId_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);

    return true;
}

GetAPIKeysRequest::~GetAPIKeysRequest()
{
    if (Entity != NULL) delete Entity;

}

void GetAPIKeysRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    writer.EndObject();
}

bool GetAPIKeysRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);

    return true;
}

GetAPIKeysResponse::~GetAPIKeysResponse()
{
    if (Entity != NULL) delete Entity;

}

void GetAPIKeysResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (!Keys.empty()) {
        writer.String("Keys");
        writer.StartArray();
        for (std::list<GetAPIKeyDetails>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetAPIKeysResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(GetAPIKeyDetails(memberList[i]));
        }
    }

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

