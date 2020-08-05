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

GetEntityTokenRequest::~GetEntityTokenRequest()
{
    if (Entity != NULL) delete Entity;

}

void GetEntityTokenRequest::writeJSON(PFStringJsonWriter& writer)
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

bool GetEntityTokenRequest::readFromValue(const rapidjson::Value& obj)
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
void PlayFab::AuthenticationModels::writeIdentifiedDeviceTypeEnumJSON(IdentifiedDeviceType enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case IdentifiedDeviceTypeUnknown: writer.String("Unknown"); break;
    case IdentifiedDeviceTypeXboxOne: writer.String("XboxOne"); break;
    case IdentifiedDeviceTypeScarlett: writer.String("Scarlett"); break;

    }
}

IdentifiedDeviceType PlayFab::AuthenticationModels::readIdentifiedDeviceTypeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, IdentifiedDeviceType> _IdentifiedDeviceTypeMap;
    if (_IdentifiedDeviceTypeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _IdentifiedDeviceTypeMap["Unknown"] = IdentifiedDeviceTypeUnknown;
        _IdentifiedDeviceTypeMap["XboxOne"] = IdentifiedDeviceTypeXboxOne;
        _IdentifiedDeviceTypeMap["Scarlett"] = IdentifiedDeviceTypeScarlett;

    }

    auto output = _IdentifiedDeviceTypeMap.find(obj.GetString());
    if (output != _IdentifiedDeviceTypeMap.end())
        return output->second;

    return IdentifiedDeviceTypeUnknown; // Basically critical fail
}
void PlayFab::AuthenticationModels::writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case LoginIdentityProviderUnknown: writer.String("Unknown"); break;
    case LoginIdentityProviderPlayFab: writer.String("PlayFab"); break;
    case LoginIdentityProviderCustom: writer.String("Custom"); break;
    case LoginIdentityProviderGameCenter: writer.String("GameCenter"); break;
    case LoginIdentityProviderGooglePlay: writer.String("GooglePlay"); break;
    case LoginIdentityProviderSteam: writer.String("Steam"); break;
    case LoginIdentityProviderXBoxLive: writer.String("XBoxLive"); break;
    case LoginIdentityProviderPSN: writer.String("PSN"); break;
    case LoginIdentityProviderKongregate: writer.String("Kongregate"); break;
    case LoginIdentityProviderFacebook: writer.String("Facebook"); break;
    case LoginIdentityProviderIOSDevice: writer.String("IOSDevice"); break;
    case LoginIdentityProviderAndroidDevice: writer.String("AndroidDevice"); break;
    case LoginIdentityProviderTwitch: writer.String("Twitch"); break;
    case LoginIdentityProviderWindowsHello: writer.String("WindowsHello"); break;
    case LoginIdentityProviderGameServer: writer.String("GameServer"); break;
    case LoginIdentityProviderCustomServer: writer.String("CustomServer"); break;
    case LoginIdentityProviderNintendoSwitch: writer.String("NintendoSwitch"); break;
    case LoginIdentityProviderFacebookInstantGames: writer.String("FacebookInstantGames"); break;
    case LoginIdentityProviderOpenIdConnect: writer.String("OpenIdConnect"); break;
    case LoginIdentityProviderApple: writer.String("Apple"); break;
    case LoginIdentityProviderNintendoSwitchAccount: writer.String("NintendoSwitchAccount"); break;

    }
}

LoginIdentityProvider PlayFab::AuthenticationModels::readLoginIdentityProviderFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, LoginIdentityProvider> _LoginIdentityProviderMap;
    if (_LoginIdentityProviderMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _LoginIdentityProviderMap["Unknown"] = LoginIdentityProviderUnknown;
        _LoginIdentityProviderMap["PlayFab"] = LoginIdentityProviderPlayFab;
        _LoginIdentityProviderMap["Custom"] = LoginIdentityProviderCustom;
        _LoginIdentityProviderMap["GameCenter"] = LoginIdentityProviderGameCenter;
        _LoginIdentityProviderMap["GooglePlay"] = LoginIdentityProviderGooglePlay;
        _LoginIdentityProviderMap["Steam"] = LoginIdentityProviderSteam;
        _LoginIdentityProviderMap["XBoxLive"] = LoginIdentityProviderXBoxLive;
        _LoginIdentityProviderMap["PSN"] = LoginIdentityProviderPSN;
        _LoginIdentityProviderMap["Kongregate"] = LoginIdentityProviderKongregate;
        _LoginIdentityProviderMap["Facebook"] = LoginIdentityProviderFacebook;
        _LoginIdentityProviderMap["IOSDevice"] = LoginIdentityProviderIOSDevice;
        _LoginIdentityProviderMap["AndroidDevice"] = LoginIdentityProviderAndroidDevice;
        _LoginIdentityProviderMap["Twitch"] = LoginIdentityProviderTwitch;
        _LoginIdentityProviderMap["WindowsHello"] = LoginIdentityProviderWindowsHello;
        _LoginIdentityProviderMap["GameServer"] = LoginIdentityProviderGameServer;
        _LoginIdentityProviderMap["CustomServer"] = LoginIdentityProviderCustomServer;
        _LoginIdentityProviderMap["NintendoSwitch"] = LoginIdentityProviderNintendoSwitch;
        _LoginIdentityProviderMap["FacebookInstantGames"] = LoginIdentityProviderFacebookInstantGames;
        _LoginIdentityProviderMap["OpenIdConnect"] = LoginIdentityProviderOpenIdConnect;
        _LoginIdentityProviderMap["Apple"] = LoginIdentityProviderApple;
        _LoginIdentityProviderMap["NintendoSwitchAccount"] = LoginIdentityProviderNintendoSwitchAccount;

    }

    auto output = _LoginIdentityProviderMap.find(obj.GetString());
    if (output != _LoginIdentityProviderMap.end())
        return output->second;

    return LoginIdentityProviderUnknown; // Basically critical fail
}

ValidateEntityTokenRequest::~ValidateEntityTokenRequest()
{

}

void ValidateEntityTokenRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("EntityToken"); writer.String(EntityToken.c_str());
    writer.EndObject();
}

bool ValidateEntityTokenRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator EntityToken_member = obj.FindMember("EntityToken");
    if (EntityToken_member != obj.MemberEnd() && !EntityToken_member->value.IsNull()) EntityToken = EntityToken_member->value.GetString();

    return true;
}

ValidateEntityTokenResponse::~ValidateEntityTokenResponse()
{
    if (Entity != NULL) delete Entity;
    if (Lineage != NULL) delete Lineage;

}

void ValidateEntityTokenResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (pfIdentifiedDeviceType.notNull()) { writer.String("IdentifiedDeviceType"); writeIdentifiedDeviceTypeEnumJSON(pfIdentifiedDeviceType, writer); }
    if (IdentityProvider.notNull()) { writer.String("IdentityProvider"); writeLoginIdentityProviderEnumJSON(IdentityProvider, writer); }
    if (Lineage != NULL) { writer.String("Lineage"); Lineage->writeJSON(writer); }
    writer.EndObject();
}

bool ValidateEntityTokenResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator IdentifiedDeviceType_member = obj.FindMember("IdentifiedDeviceType");
    if (IdentifiedDeviceType_member != obj.MemberEnd() && !IdentifiedDeviceType_member->value.IsNull()) pfIdentifiedDeviceType = readIdentifiedDeviceTypeFromValue(IdentifiedDeviceType_member->value);
    const Value::ConstMemberIterator IdentityProvider_member = obj.FindMember("IdentityProvider");
    if (IdentityProvider_member != obj.MemberEnd() && !IdentityProvider_member->value.IsNull()) IdentityProvider = readLoginIdentityProviderFromValue(IdentityProvider_member->value);
    const Value::ConstMemberIterator Lineage_member = obj.FindMember("Lineage");
    if (Lineage_member != obj.MemberEnd() && !Lineage_member->value.IsNull()) Lineage = new EntityLineage(Lineage_member->value);

    return true;
}

