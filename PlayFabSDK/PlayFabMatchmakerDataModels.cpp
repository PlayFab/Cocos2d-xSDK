#include "PlayFabMatchmakerDataModels.h"

using namespace PlayFab;
using namespace PlayFab::MatchmakerModels;
using namespace rapidjson;


AuthUserRequest::~AuthUserRequest()
{

}

void AuthUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("AuthorizationTicket"); writer.String(AuthorizationTicket.c_str());
    writer.EndObject();
}

bool AuthUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AuthorizationTicket_member = obj.FindMember("AuthorizationTicket");
    if (AuthorizationTicket_member != obj.MemberEnd() && !AuthorizationTicket_member->value.IsNull()) AuthorizationTicket = AuthorizationTicket_member->value.GetString();

    return true;
}

AuthUserResponse::~AuthUserResponse()
{

}

void AuthUserResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Authorized"); writer.Bool(Authorized);
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.EndObject();
}

bool AuthUserResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Authorized_member = obj.FindMember("Authorized");
    if (Authorized_member != obj.MemberEnd() && !Authorized_member->value.IsNull()) Authorized = Authorized_member->value.GetBool();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

ItemInstance::~ItemInstance()
{

}

void ItemInstance::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    if (!BundleContents.empty()) {
        writer.String("BundleContents");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (!CustomData.empty()) {
        writer.String("CustomData");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (Expiration.notNull()) { writer.String("Expiration"); writeDatetime(Expiration, writer); }
    if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
    if (ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
    if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
    if (PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
    if (RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
    if (UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
    writer.String("UnitPrice"); writer.Uint(UnitPrice);
    if (UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
    writer.EndObject();
}

bool ItemInstance::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::ConstMemberIterator BundleContents_member = obj.FindMember("BundleContents");
    if (BundleContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundleContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundleContents.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator BundleParent_member = obj.FindMember("BundleParent");
    if (BundleParent_member != obj.MemberEnd() && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
            CustomData[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
    if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
    const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
    if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
    const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
    const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
    if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
    const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
    if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
    const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
    if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();

    return true;
}

PlayerJoinedRequest::~PlayerJoinedRequest()
{

}

void PlayerJoinedRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("LobbyId"); writer.String(LobbyId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool PlayerJoinedRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

PlayerJoinedResponse::~PlayerJoinedResponse()
{

}

void PlayerJoinedResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool PlayerJoinedResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

PlayerLeftRequest::~PlayerLeftRequest()
{

}

void PlayerLeftRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("LobbyId"); writer.String(LobbyId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool PlayerLeftRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

PlayerLeftResponse::~PlayerLeftResponse()
{

}

void PlayerLeftResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool PlayerLeftResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}
void PlayFab::MatchmakerModels::writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case RegionUSCentral: writer.String("USCentral"); break;
    case RegionUSEast: writer.String("USEast"); break;
    case RegionEUWest: writer.String("EUWest"); break;
    case RegionSingapore: writer.String("Singapore"); break;
    case RegionJapan: writer.String("Japan"); break;
    case RegionBrazil: writer.String("Brazil"); break;
    case RegionAustralia: writer.String("Australia"); break;

    }
}

Region PlayFab::MatchmakerModels::readRegionFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, Region> _RegionMap;
    if (_RegionMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _RegionMap["USCentral"] = RegionUSCentral;
        _RegionMap["USEast"] = RegionUSEast;
        _RegionMap["EUWest"] = RegionEUWest;
        _RegionMap["Singapore"] = RegionSingapore;
        _RegionMap["Japan"] = RegionJapan;
        _RegionMap["Brazil"] = RegionBrazil;
        _RegionMap["Australia"] = RegionAustralia;

    }

    auto output = _RegionMap.find(obj.GetString());
    if (output != _RegionMap.end())
        return output->second;

    return RegionUSCentral; // Basically critical fail
}

StartGameRequest::~StartGameRequest()
{

}

void StartGameRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Build"); writer.String(Build.c_str());
    if (CustomCommandLineData.length() > 0) { writer.String("CustomCommandLineData"); writer.String(CustomCommandLineData.c_str()); }
    writer.String("ExternalMatchmakerEventEndpoint"); writer.String(ExternalMatchmakerEventEndpoint.c_str());
    writer.String("GameMode"); writer.String(GameMode.c_str());
    writer.String("Region"); writeRegionEnumJSON(pfRegion, writer);
    writer.EndObject();
}

bool StartGameRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Build_member = obj.FindMember("Build");
    if (Build_member != obj.MemberEnd() && !Build_member->value.IsNull()) Build = Build_member->value.GetString();
    const Value::ConstMemberIterator CustomCommandLineData_member = obj.FindMember("CustomCommandLineData");
    if (CustomCommandLineData_member != obj.MemberEnd() && !CustomCommandLineData_member->value.IsNull()) CustomCommandLineData = CustomCommandLineData_member->value.GetString();
    const Value::ConstMemberIterator ExternalMatchmakerEventEndpoint_member = obj.FindMember("ExternalMatchmakerEventEndpoint");
    if (ExternalMatchmakerEventEndpoint_member != obj.MemberEnd() && !ExternalMatchmakerEventEndpoint_member->value.IsNull()) ExternalMatchmakerEventEndpoint = ExternalMatchmakerEventEndpoint_member->value.GetString();
    const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
    if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);

    return true;
}

StartGameResponse::~StartGameResponse()
{

}

void StartGameResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (GameID.length() > 0) { writer.String("GameID"); writer.String(GameID.c_str()); }
    if (ServerIPV4Address.length() > 0) { writer.String("ServerIPV4Address"); writer.String(ServerIPV4Address.c_str()); }
    if (ServerIPV6Address.length() > 0) { writer.String("ServerIPV6Address"); writer.String(ServerIPV6Address.c_str()); }
    writer.String("ServerPort"); writer.Uint(ServerPort);
    if (ServerPublicDNSName.length() > 0) { writer.String("ServerPublicDNSName"); writer.String(ServerPublicDNSName.c_str()); }
    writer.EndObject();
}

bool StartGameResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GameID_member = obj.FindMember("GameID");
    if (GameID_member != obj.MemberEnd() && !GameID_member->value.IsNull()) GameID = GameID_member->value.GetString();
    const Value::ConstMemberIterator ServerIPV4Address_member = obj.FindMember("ServerIPV4Address");
    if (ServerIPV4Address_member != obj.MemberEnd() && !ServerIPV4Address_member->value.IsNull()) ServerIPV4Address = ServerIPV4Address_member->value.GetString();
    const Value::ConstMemberIterator ServerIPV6Address_member = obj.FindMember("ServerIPV6Address");
    if (ServerIPV6Address_member != obj.MemberEnd() && !ServerIPV6Address_member->value.IsNull()) ServerIPV6Address = ServerIPV6Address_member->value.GetString();
    const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
    if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetUint();
    const Value::ConstMemberIterator ServerPublicDNSName_member = obj.FindMember("ServerPublicDNSName");
    if (ServerPublicDNSName_member != obj.MemberEnd() && !ServerPublicDNSName_member->value.IsNull()) ServerPublicDNSName = ServerPublicDNSName_member->value.GetString();

    return true;
}

UserInfoRequest::~UserInfoRequest()
{

}

void UserInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("MinCatalogVersion"); writer.Int(MinCatalogVersion);
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UserInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator MinCatalogVersion_member = obj.FindMember("MinCatalogVersion");
    if (MinCatalogVersion_member != obj.MemberEnd() && !MinCatalogVersion_member->value.IsNull()) MinCatalogVersion = MinCatalogVersion_member->value.GetInt();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

VirtualCurrencyRechargeTime::~VirtualCurrencyRechargeTime()
{

}

void VirtualCurrencyRechargeTime::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("RechargeMax"); writer.Int(RechargeMax);
    writer.String("RechargeTime"); writeDatetime(RechargeTime, writer);
    writer.String("SecondsToRecharge"); writer.Int(SecondsToRecharge);
    writer.EndObject();
}

bool VirtualCurrencyRechargeTime::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
    if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();
    const Value::ConstMemberIterator RechargeTime_member = obj.FindMember("RechargeTime");
    if (RechargeTime_member != obj.MemberEnd() && !RechargeTime_member->value.IsNull()) RechargeTime = readDatetime(RechargeTime_member->value);
    const Value::ConstMemberIterator SecondsToRecharge_member = obj.FindMember("SecondsToRecharge");
    if (SecondsToRecharge_member != obj.MemberEnd() && !SecondsToRecharge_member->value.IsNull()) SecondsToRecharge = SecondsToRecharge_member->value.GetInt();

    return true;
}

UserInfoResponse::~UserInfoResponse()
{

}

void UserInfoResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Inventory.empty()) {
        writer.String("Inventory");
        writer.StartArray();
        for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.String("IsDeveloper"); writer.Bool(IsDeveloper);
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
    if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (!VirtualCurrency.empty()) {
        writer.String("VirtualCurrency");
        writer.StartObject();
        for (std::map<std::string, Int32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.Int(iter->second);
        }
        writer.EndObject();
    }
    if (!VirtualCurrencyRechargeTimes.empty()) {
        writer.String("VirtualCurrencyRechargeTimes");
        writer.StartObject();
        for (std::map<std::string, VirtualCurrencyRechargeTime>::iterator iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool UserInfoResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::ConstMemberIterator IsDeveloper_member = obj.FindMember("IsDeveloper");
    if (IsDeveloper_member != obj.MemberEnd() && !IsDeveloper_member->value.IsNull()) IsDeveloper = IsDeveloper_member->value.GetBool();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
    if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();
    const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
    if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::ConstMemberIterator VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
    if (VirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != VirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
        }
    }

    return true;
}

