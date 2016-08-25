#include "PlayFabAdminDataModels.h"

using namespace PlayFab;
using namespace PlayFab::AdminModels;
using namespace rapidjson;


AdCampaignAttribution::~AdCampaignAttribution()
{

}

void AdCampaignAttribution::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Platform.length() > 0) { writer.String("Platform"); writer.String(Platform.c_str()); }
    if (CampaignId.length() > 0) { writer.String("CampaignId"); writer.String(CampaignId.c_str()); }
    writer.String("AttributedAt"); writeDatetime(AttributedAt, writer);

    writer.EndObject();
}

bool AdCampaignAttribution::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();
    const Value::ConstMemberIterator CampaignId_member = obj.FindMember("CampaignId");
    if (CampaignId_member != obj.MemberEnd() && !CampaignId_member->value.IsNull()) CampaignId = CampaignId_member->value.GetString();
    const Value::ConstMemberIterator AttributedAt_member = obj.FindMember("AttributedAt");
    if (AttributedAt_member != obj.MemberEnd() && !AttributedAt_member->value.IsNull()) AttributedAt = readDatetime(AttributedAt_member->value);

    return true;
}

AddNewsRequest::~AddNewsRequest()
{

}

void AddNewsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    writer.String("Title"); writer.String(Title.c_str());
    writer.String("Body"); writer.String(Body.c_str());

    writer.EndObject();
}

bool AddNewsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
    if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd() && !Body_member->value.IsNull()) Body = Body_member->value.GetString();

    return true;
}

AddNewsResult::~AddNewsResult()
{

}

void AddNewsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (NewsId.length() > 0) { writer.String("NewsId"); writer.String(NewsId.c_str()); }

    writer.EndObject();
}

bool AddNewsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator NewsId_member = obj.FindMember("NewsId");
    if (NewsId_member != obj.MemberEnd() && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();

    return true;
}

AddPlayerTagRequest::~AddPlayerTagRequest()
{

}

void AddPlayerTagRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("TagName"); writer.String(TagName.c_str());

    writer.EndObject();
}

bool AddPlayerTagRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator TagName_member = obj.FindMember("TagName");
    if (TagName_member != obj.MemberEnd() && !TagName_member->value.IsNull()) TagName = TagName_member->value.GetString();

    return true;
}

AddPlayerTagResult::~AddPlayerTagResult()
{

}

void AddPlayerTagResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool AddPlayerTagResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}
void PlayFab::AdminModels::writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
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

Region PlayFab::AdminModels::readRegionFromValue(const rapidjson::Value& obj)
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

AddServerBuildRequest::~AddServerBuildRequest()
{

}

void AddServerBuildRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildId"); writer.String(BuildId.c_str());
    if (CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
    if (ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
    if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);

    writer.EndObject();
}

bool AddServerBuildRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
    if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
    const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
    if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
    const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
    if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
    if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
    if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();

    return true;
}
void PlayFab::AdminModels::writeGameBuildStatusEnumJSON(GameBuildStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case GameBuildStatusAvailable: writer.String("Available"); break;
    case GameBuildStatusValidating: writer.String("Validating"); break;
    case GameBuildStatusInvalidBuildPackage: writer.String("InvalidBuildPackage"); break;
    case GameBuildStatusProcessing: writer.String("Processing"); break;
    case GameBuildStatusFailedToProcess: writer.String("FailedToProcess"); break;

    }
}

GameBuildStatus PlayFab::AdminModels::readGameBuildStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, GameBuildStatus> _GameBuildStatusMap;
    if (_GameBuildStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _GameBuildStatusMap["Available"] = GameBuildStatusAvailable;
        _GameBuildStatusMap["Validating"] = GameBuildStatusValidating;
        _GameBuildStatusMap["InvalidBuildPackage"] = GameBuildStatusInvalidBuildPackage;
        _GameBuildStatusMap["Processing"] = GameBuildStatusProcessing;
        _GameBuildStatusMap["FailedToProcess"] = GameBuildStatusFailedToProcess;

    }

    auto output = _GameBuildStatusMap.find(obj.GetString());
    if (output != _GameBuildStatusMap.end())
        return output->second;

    return GameBuildStatusAvailable; // Basically critical fail
}

AddServerBuildResult::~AddServerBuildResult()
{

}

void AddServerBuildResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
    if (CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
    if (ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    writer.String("Timestamp"); writeDatetime(Timestamp, writer);
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    if (Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }

    writer.EndObject();
}

bool AddServerBuildResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
    const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
    if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
    if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
    const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
    if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
    const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
    if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
    const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
    if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
    if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);

    return true;
}

AddUserVirtualCurrencyRequest::~AddUserVirtualCurrencyRequest()
{

}

void AddUserVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.String("Amount"); writer.Int(Amount);

    writer.EndObject();
}

bool AddUserVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
    if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

    return true;
}

VirtualCurrencyData::~VirtualCurrencyData()
{

}

void VirtualCurrencyData::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("CurrencyCode"); writer.String(CurrencyCode.c_str());
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (InitialDeposit.notNull()) { writer.String("InitialDeposit"); writer.Int(InitialDeposit); }
    if (RechargeRate.notNull()) { writer.String("RechargeRate"); writer.Int(RechargeRate); }
    if (RechargeMax.notNull()) { writer.String("RechargeMax"); writer.Int(RechargeMax); }

    writer.EndObject();
}

bool VirtualCurrencyData::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
    if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator InitialDeposit_member = obj.FindMember("InitialDeposit");
    if (InitialDeposit_member != obj.MemberEnd() && !InitialDeposit_member->value.IsNull()) InitialDeposit = InitialDeposit_member->value.GetInt();
    const Value::ConstMemberIterator RechargeRate_member = obj.FindMember("RechargeRate");
    if (RechargeRate_member != obj.MemberEnd() && !RechargeRate_member->value.IsNull()) RechargeRate = RechargeRate_member->value.GetInt();
    const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
    if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();

    return true;
}

AddVirtualCurrencyTypesRequest::~AddVirtualCurrencyTypesRequest()
{

}

void AddVirtualCurrencyTypesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("VirtualCurrencies");
    writer.StartArray();
    for (std::list<VirtualCurrencyData>::iterator iter = VirtualCurrencies.begin(); iter != VirtualCurrencies.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool AddVirtualCurrencyTypesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
    if (VirtualCurrencies_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = VirtualCurrencies_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
        }
    }

    return true;
}

BanInfo::~BanInfo()
{

}

void BanInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (BanId.length() > 0) { writer.String("BanId"); writer.String(BanId.c_str()); }
    if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
    if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
    if (Created.notNull()) { writer.String("Created"); writeDatetime(Created, writer); }
    if (Expires.notNull()) { writer.String("Expires"); writeDatetime(Expires, writer); }
    if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
    writer.String("Active"); writer.Bool(Active);

    writer.EndObject();
}

bool BanInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator BanId_member = obj.FindMember("BanId");
    if (BanId_member != obj.MemberEnd() && !BanId_member->value.IsNull()) BanId = BanId_member->value.GetString();
    const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
    if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
    const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
    if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
    if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
    const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
    if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
    const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
    if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();

    return true;
}

BanRequest::~BanRequest()
{

}

void BanRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
    if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
    if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
    if (DurationInHours.notNull()) { writer.String("DurationInHours"); writer.Uint(DurationInHours); }

    writer.EndObject();
}

bool BanRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
    if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
    const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
    if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
    const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
    if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
    const Value::ConstMemberIterator DurationInHours_member = obj.FindMember("DurationInHours");
    if (DurationInHours_member != obj.MemberEnd() && !DurationInHours_member->value.IsNull()) DurationInHours = DurationInHours_member->value.GetUint();

    return true;
}

BanUsersRequest::~BanUsersRequest()
{

}

void BanUsersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Bans");
    writer.StartArray();
    for (std::list<BanRequest>::iterator iter = Bans.begin(); iter != Bans.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool BanUsersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Bans_member = obj.FindMember("Bans");
    if (Bans_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Bans_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Bans.push_back(BanRequest(memberList[i]));
        }
    }

    return true;
}

BanUsersResult::~BanUsersResult()
{

}

void BanUsersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool BanUsersResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

    return true;
}

BlankResult::~BlankResult()
{

}

void BlankResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool BlankResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

CatalogItemConsumableInfo::~CatalogItemConsumableInfo()
{

}

void CatalogItemConsumableInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (UsageCount.notNull()) { writer.String("UsageCount"); writer.Uint(UsageCount); }
    if (UsagePeriod.notNull()) { writer.String("UsagePeriod"); writer.Uint(UsagePeriod); }
    if (UsagePeriodGroup.length() > 0) { writer.String("UsagePeriodGroup"); writer.String(UsagePeriodGroup.c_str()); }

    writer.EndObject();
}

bool CatalogItemConsumableInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator UsageCount_member = obj.FindMember("UsageCount");
    if (UsageCount_member != obj.MemberEnd() && !UsageCount_member->value.IsNull()) UsageCount = UsageCount_member->value.GetUint();
    const Value::ConstMemberIterator UsagePeriod_member = obj.FindMember("UsagePeriod");
    if (UsagePeriod_member != obj.MemberEnd() && !UsagePeriod_member->value.IsNull()) UsagePeriod = UsagePeriod_member->value.GetUint();
    const Value::ConstMemberIterator UsagePeriodGroup_member = obj.FindMember("UsagePeriodGroup");
    if (UsagePeriodGroup_member != obj.MemberEnd() && !UsagePeriodGroup_member->value.IsNull()) UsagePeriodGroup = UsagePeriodGroup_member->value.GetString();

    return true;
}

CatalogItemContainerInfo::~CatalogItemContainerInfo()
{

}

void CatalogItemContainerInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (KeyItemId.length() > 0) { writer.String("KeyItemId"); writer.String(KeyItemId.c_str()); }
    if (!ItemContents.empty()) {
    writer.String("ItemContents");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = ItemContents.begin(); iter != ItemContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!ResultTableContents.empty()) {
    writer.String("ResultTableContents");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = ResultTableContents.begin(); iter != ResultTableContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!VirtualCurrencyContents.empty()) {
    writer.String("VirtualCurrencyContents");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = VirtualCurrencyContents.begin(); iter != VirtualCurrencyContents.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool CatalogItemContainerInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator KeyItemId_member = obj.FindMember("KeyItemId");
    if (KeyItemId_member != obj.MemberEnd() && !KeyItemId_member->value.IsNull()) KeyItemId = KeyItemId_member->value.GetString();
    const Value::ConstMemberIterator ItemContents_member = obj.FindMember("ItemContents");
    if (ItemContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemContents.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator ResultTableContents_member = obj.FindMember("ResultTableContents");
    if (ResultTableContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ResultTableContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ResultTableContents.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator VirtualCurrencyContents_member = obj.FindMember("VirtualCurrencyContents");
    if (VirtualCurrencyContents_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyContents_member->value.MemberBegin(); iter != VirtualCurrencyContents_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyContents[iter->name.GetString()] = iter->value.GetUint();
        }
    }

    return true;
}

CatalogItemBundleInfo::~CatalogItemBundleInfo()
{

}

void CatalogItemBundleInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!BundledItems.empty()) {
    writer.String("BundledItems");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = BundledItems.begin(); iter != BundledItems.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!BundledResultTables.empty()) {
    writer.String("BundledResultTables");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = BundledResultTables.begin(); iter != BundledResultTables.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!BundledVirtualCurrencies.empty()) {
    writer.String("BundledVirtualCurrencies");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = BundledVirtualCurrencies.begin(); iter != BundledVirtualCurrencies.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool CatalogItemBundleInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BundledItems_member = obj.FindMember("BundledItems");
    if (BundledItems_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundledItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundledItems.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator BundledResultTables_member = obj.FindMember("BundledResultTables");
    if (BundledResultTables_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundledResultTables_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundledResultTables.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator BundledVirtualCurrencies_member = obj.FindMember("BundledVirtualCurrencies");
    if (BundledVirtualCurrencies_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = BundledVirtualCurrencies_member->value.MemberBegin(); iter != BundledVirtualCurrencies_member->value.MemberEnd(); ++iter) {
            BundledVirtualCurrencies[iter->name.GetString()] = iter->value.GetUint();
        }
    }

    return true;
}

CatalogItem::~CatalogItem()
{
    if (Consumable != NULL) delete Consumable;
    if (Container != NULL) delete Container;
    if (Bundle != NULL) delete Bundle;

}

void CatalogItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ItemId"); writer.String(ItemId.c_str());
    if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    if (!VirtualCurrencyPrices.empty()) {
    writer.String("VirtualCurrencyPrices");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
    if (!RealCurrencyPrices.empty()) {
    writer.String("RealCurrencyPrices");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
    if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (CustomData.length() > 0) { writer.String("CustomData"); writer.String(CustomData.c_str()); }
    if (Consumable != NULL) { writer.String("Consumable"); Consumable->writeJSON(writer); }
    if (Container != NULL) { writer.String("Container"); Container->writeJSON(writer); }
    if (Bundle != NULL) { writer.String("Bundle"); Bundle->writeJSON(writer); }
    writer.String("CanBecomeCharacter"); writer.Bool(CanBecomeCharacter);
    writer.String("IsStackable"); writer.Bool(IsStackable);
    writer.String("IsTradable"); writer.Bool(IsTradable);
    if (ItemImageUrl.length() > 0) { writer.String("ItemImageUrl"); writer.String(ItemImageUrl.c_str()); }

    writer.EndObject();
}

bool CatalogItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
    if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
    const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
    if (RealCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
            RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = CustomData_member->value.GetString();
    const Value::ConstMemberIterator Consumable_member = obj.FindMember("Consumable");
    if (Consumable_member != obj.MemberEnd() && !Consumable_member->value.IsNull()) Consumable = new CatalogItemConsumableInfo(Consumable_member->value);
    const Value::ConstMemberIterator Container_member = obj.FindMember("Container");
    if (Container_member != obj.MemberEnd() && !Container_member->value.IsNull()) Container = new CatalogItemContainerInfo(Container_member->value);
    const Value::ConstMemberIterator Bundle_member = obj.FindMember("Bundle");
    if (Bundle_member != obj.MemberEnd() && !Bundle_member->value.IsNull()) Bundle = new CatalogItemBundleInfo(Bundle_member->value);
    const Value::ConstMemberIterator CanBecomeCharacter_member = obj.FindMember("CanBecomeCharacter");
    if (CanBecomeCharacter_member != obj.MemberEnd() && !CanBecomeCharacter_member->value.IsNull()) CanBecomeCharacter = CanBecomeCharacter_member->value.GetBool();
    const Value::ConstMemberIterator IsStackable_member = obj.FindMember("IsStackable");
    if (IsStackable_member != obj.MemberEnd() && !IsStackable_member->value.IsNull()) IsStackable = IsStackable_member->value.GetBool();
    const Value::ConstMemberIterator IsTradable_member = obj.FindMember("IsTradable");
    if (IsTradable_member != obj.MemberEnd() && !IsTradable_member->value.IsNull()) IsTradable = IsTradable_member->value.GetBool();
    const Value::ConstMemberIterator ItemImageUrl_member = obj.FindMember("ItemImageUrl");
    if (ItemImageUrl_member != obj.MemberEnd() && !ItemImageUrl_member->value.IsNull()) ItemImageUrl = ItemImageUrl_member->value.GetString();

    return true;
}

CloudScriptFile::~CloudScriptFile()
{

}

void CloudScriptFile::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Filename"); writer.String(Filename.c_str());
    writer.String("FileContents"); writer.String(FileContents.c_str());

    writer.EndObject();
}

bool CloudScriptFile::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Filename_member = obj.FindMember("Filename");
    if (Filename_member != obj.MemberEnd() && !Filename_member->value.IsNull()) Filename = Filename_member->value.GetString();
    const Value::ConstMemberIterator FileContents_member = obj.FindMember("FileContents");
    if (FileContents_member != obj.MemberEnd() && !FileContents_member->value.IsNull()) FileContents = FileContents_member->value.GetString();

    return true;
}

CloudScriptVersionStatus::~CloudScriptVersionStatus()
{

}

void CloudScriptVersionStatus::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Version"); writer.Int(Version);
    writer.String("PublishedRevision"); writer.Int(PublishedRevision);
    writer.String("LatestRevision"); writer.Int(LatestRevision);

    writer.EndObject();
}

bool CloudScriptVersionStatus::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::ConstMemberIterator PublishedRevision_member = obj.FindMember("PublishedRevision");
    if (PublishedRevision_member != obj.MemberEnd() && !PublishedRevision_member->value.IsNull()) PublishedRevision = PublishedRevision_member->value.GetInt();
    const Value::ConstMemberIterator LatestRevision_member = obj.FindMember("LatestRevision");
    if (LatestRevision_member != obj.MemberEnd() && !LatestRevision_member->value.IsNull()) LatestRevision = LatestRevision_member->value.GetInt();

    return true;
}

ContentInfo::~ContentInfo()
{

}

void ContentInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Key.length() > 0) { writer.String("Key"); writer.String(Key.c_str()); }
    writer.String("Size"); writer.Uint(Size);
    writer.String("LastModified"); writeDatetime(LastModified, writer);

    writer.EndObject();
}

bool ContentInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
    if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetUint();
    const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
    if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);

    return true;
}
void PlayFab::AdminModels::writeStatisticResetIntervalOptionEnumJSON(StatisticResetIntervalOption enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case StatisticResetIntervalOptionNever: writer.String("Never"); break;
    case StatisticResetIntervalOptionHour: writer.String("Hour"); break;
    case StatisticResetIntervalOptionDay: writer.String("Day"); break;
    case StatisticResetIntervalOptionWeek: writer.String("Week"); break;
    case StatisticResetIntervalOptionMonth: writer.String("Month"); break;

    }
}

StatisticResetIntervalOption PlayFab::AdminModels::readStatisticResetIntervalOptionFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, StatisticResetIntervalOption> _StatisticResetIntervalOptionMap;
    if (_StatisticResetIntervalOptionMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _StatisticResetIntervalOptionMap["Never"] = StatisticResetIntervalOptionNever;
        _StatisticResetIntervalOptionMap["Hour"] = StatisticResetIntervalOptionHour;
        _StatisticResetIntervalOptionMap["Day"] = StatisticResetIntervalOptionDay;
        _StatisticResetIntervalOptionMap["Week"] = StatisticResetIntervalOptionWeek;
        _StatisticResetIntervalOptionMap["Month"] = StatisticResetIntervalOptionMonth;

    }

    auto output = _StatisticResetIntervalOptionMap.find(obj.GetString());
    if (output != _StatisticResetIntervalOptionMap.end())
        return output->second;

    return StatisticResetIntervalOptionNever; // Basically critical fail
}
void PlayFab::AdminModels::writeStatisticAggregationMethodEnumJSON(StatisticAggregationMethod enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case StatisticAggregationMethodLast: writer.String("Last"); break;
    case StatisticAggregationMethodMin: writer.String("Min"); break;
    case StatisticAggregationMethodMax: writer.String("Max"); break;
    case StatisticAggregationMethodSum: writer.String("Sum"); break;

    }
}

StatisticAggregationMethod PlayFab::AdminModels::readStatisticAggregationMethodFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, StatisticAggregationMethod> _StatisticAggregationMethodMap;
    if (_StatisticAggregationMethodMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _StatisticAggregationMethodMap["Last"] = StatisticAggregationMethodLast;
        _StatisticAggregationMethodMap["Min"] = StatisticAggregationMethodMin;
        _StatisticAggregationMethodMap["Max"] = StatisticAggregationMethodMax;
        _StatisticAggregationMethodMap["Sum"] = StatisticAggregationMethodSum;

    }

    auto output = _StatisticAggregationMethodMap.find(obj.GetString());
    if (output != _StatisticAggregationMethodMap.end())
        return output->second;

    return StatisticAggregationMethodLast; // Basically critical fail
}

CreatePlayerStatisticDefinitionRequest::~CreatePlayerStatisticDefinitionRequest()
{

}

void CreatePlayerStatisticDefinitionRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    if (VersionChangeInterval.notNull()) { writer.String("VersionChangeInterval"); writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer); }
    if (AggregationMethod.notNull()) { writer.String("AggregationMethod"); writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer); }

    writer.EndObject();
}

bool CreatePlayerStatisticDefinitionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
    if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
    const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
    if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

    return true;
}

PlayerStatisticDefinition::~PlayerStatisticDefinition()
{

}

void PlayerStatisticDefinition::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
    writer.String("CurrentVersion"); writer.Uint(CurrentVersion);
    if (VersionChangeInterval.notNull()) { writer.String("VersionChangeInterval"); writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer); }
    if (AggregationMethod.notNull()) { writer.String("AggregationMethod"); writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer); }

    writer.EndObject();
}

bool PlayerStatisticDefinition::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator CurrentVersion_member = obj.FindMember("CurrentVersion");
    if (CurrentVersion_member != obj.MemberEnd() && !CurrentVersion_member->value.IsNull()) CurrentVersion = CurrentVersion_member->value.GetUint();
    const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
    if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
    const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
    if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

    return true;
}

CreatePlayerStatisticDefinitionResult::~CreatePlayerStatisticDefinitionResult()
{
    if (Statistic != NULL) delete Statistic;

}

void CreatePlayerStatisticDefinitionResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Statistic != NULL) { writer.String("Statistic"); Statistic->writeJSON(writer); }

    writer.EndObject();
}

bool CreatePlayerStatisticDefinitionResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Statistic_member = obj.FindMember("Statistic");
    if (Statistic_member != obj.MemberEnd() && !Statistic_member->value.IsNull()) Statistic = new PlayerStatisticDefinition(Statistic_member->value);

    return true;
}
void PlayFab::AdminModels::writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case CurrencyAED: writer.String("AED"); break;
    case CurrencyAFN: writer.String("AFN"); break;
    case CurrencyALL: writer.String("ALL"); break;
    case CurrencyAMD: writer.String("AMD"); break;
    case CurrencyANG: writer.String("ANG"); break;
    case CurrencyAOA: writer.String("AOA"); break;
    case CurrencyARS: writer.String("ARS"); break;
    case CurrencyAUD: writer.String("AUD"); break;
    case CurrencyAWG: writer.String("AWG"); break;
    case CurrencyAZN: writer.String("AZN"); break;
    case CurrencyBAM: writer.String("BAM"); break;
    case CurrencyBBD: writer.String("BBD"); break;
    case CurrencyBDT: writer.String("BDT"); break;
    case CurrencyBGN: writer.String("BGN"); break;
    case CurrencyBHD: writer.String("BHD"); break;
    case CurrencyBIF: writer.String("BIF"); break;
    case CurrencyBMD: writer.String("BMD"); break;
    case CurrencyBND: writer.String("BND"); break;
    case CurrencyBOB: writer.String("BOB"); break;
    case CurrencyBRL: writer.String("BRL"); break;
    case CurrencyBSD: writer.String("BSD"); break;
    case CurrencyBTN: writer.String("BTN"); break;
    case CurrencyBWP: writer.String("BWP"); break;
    case CurrencyBYR: writer.String("BYR"); break;
    case CurrencyBZD: writer.String("BZD"); break;
    case CurrencyCAD: writer.String("CAD"); break;
    case CurrencyCDF: writer.String("CDF"); break;
    case CurrencyCHF: writer.String("CHF"); break;
    case CurrencyCLP: writer.String("CLP"); break;
    case CurrencyCNY: writer.String("CNY"); break;
    case CurrencyCOP: writer.String("COP"); break;
    case CurrencyCRC: writer.String("CRC"); break;
    case CurrencyCUC: writer.String("CUC"); break;
    case CurrencyCUP: writer.String("CUP"); break;
    case CurrencyCVE: writer.String("CVE"); break;
    case CurrencyCZK: writer.String("CZK"); break;
    case CurrencyDJF: writer.String("DJF"); break;
    case CurrencyDKK: writer.String("DKK"); break;
    case CurrencyDOP: writer.String("DOP"); break;
    case CurrencyDZD: writer.String("DZD"); break;
    case CurrencyEGP: writer.String("EGP"); break;
    case CurrencyERN: writer.String("ERN"); break;
    case CurrencyETB: writer.String("ETB"); break;
    case CurrencyEUR: writer.String("EUR"); break;
    case CurrencyFJD: writer.String("FJD"); break;
    case CurrencyFKP: writer.String("FKP"); break;
    case CurrencyGBP: writer.String("GBP"); break;
    case CurrencyGEL: writer.String("GEL"); break;
    case CurrencyGGP: writer.String("GGP"); break;
    case CurrencyGHS: writer.String("GHS"); break;
    case CurrencyGIP: writer.String("GIP"); break;
    case CurrencyGMD: writer.String("GMD"); break;
    case CurrencyGNF: writer.String("GNF"); break;
    case CurrencyGTQ: writer.String("GTQ"); break;
    case CurrencyGYD: writer.String("GYD"); break;
    case CurrencyHKD: writer.String("HKD"); break;
    case CurrencyHNL: writer.String("HNL"); break;
    case CurrencyHRK: writer.String("HRK"); break;
    case CurrencyHTG: writer.String("HTG"); break;
    case CurrencyHUF: writer.String("HUF"); break;
    case CurrencyIDR: writer.String("IDR"); break;
    case CurrencyILS: writer.String("ILS"); break;
    case CurrencyIMP: writer.String("IMP"); break;
    case CurrencyINR: writer.String("INR"); break;
    case CurrencyIQD: writer.String("IQD"); break;
    case CurrencyIRR: writer.String("IRR"); break;
    case CurrencyISK: writer.String("ISK"); break;
    case CurrencyJEP: writer.String("JEP"); break;
    case CurrencyJMD: writer.String("JMD"); break;
    case CurrencyJOD: writer.String("JOD"); break;
    case CurrencyJPY: writer.String("JPY"); break;
    case CurrencyKES: writer.String("KES"); break;
    case CurrencyKGS: writer.String("KGS"); break;
    case CurrencyKHR: writer.String("KHR"); break;
    case CurrencyKMF: writer.String("KMF"); break;
    case CurrencyKPW: writer.String("KPW"); break;
    case CurrencyKRW: writer.String("KRW"); break;
    case CurrencyKWD: writer.String("KWD"); break;
    case CurrencyKYD: writer.String("KYD"); break;
    case CurrencyKZT: writer.String("KZT"); break;
    case CurrencyLAK: writer.String("LAK"); break;
    case CurrencyLBP: writer.String("LBP"); break;
    case CurrencyLKR: writer.String("LKR"); break;
    case CurrencyLRD: writer.String("LRD"); break;
    case CurrencyLSL: writer.String("LSL"); break;
    case CurrencyLYD: writer.String("LYD"); break;
    case CurrencyMAD: writer.String("MAD"); break;
    case CurrencyMDL: writer.String("MDL"); break;
    case CurrencyMGA: writer.String("MGA"); break;
    case CurrencyMKD: writer.String("MKD"); break;
    case CurrencyMMK: writer.String("MMK"); break;
    case CurrencyMNT: writer.String("MNT"); break;
    case CurrencyMOP: writer.String("MOP"); break;
    case CurrencyMRO: writer.String("MRO"); break;
    case CurrencyMUR: writer.String("MUR"); break;
    case CurrencyMVR: writer.String("MVR"); break;
    case CurrencyMWK: writer.String("MWK"); break;
    case CurrencyMXN: writer.String("MXN"); break;
    case CurrencyMYR: writer.String("MYR"); break;
    case CurrencyMZN: writer.String("MZN"); break;
    case CurrencyNAD: writer.String("NAD"); break;
    case CurrencyNGN: writer.String("NGN"); break;
    case CurrencyNIO: writer.String("NIO"); break;
    case CurrencyNOK: writer.String("NOK"); break;
    case CurrencyNPR: writer.String("NPR"); break;
    case CurrencyNZD: writer.String("NZD"); break;
    case CurrencyOMR: writer.String("OMR"); break;
    case CurrencyPAB: writer.String("PAB"); break;
    case CurrencyPEN: writer.String("PEN"); break;
    case CurrencyPGK: writer.String("PGK"); break;
    case CurrencyPHP: writer.String("PHP"); break;
    case CurrencyPKR: writer.String("PKR"); break;
    case CurrencyPLN: writer.String("PLN"); break;
    case CurrencyPYG: writer.String("PYG"); break;
    case CurrencyQAR: writer.String("QAR"); break;
    case CurrencyRON: writer.String("RON"); break;
    case CurrencyRSD: writer.String("RSD"); break;
    case CurrencyRUB: writer.String("RUB"); break;
    case CurrencyRWF: writer.String("RWF"); break;
    case CurrencySAR: writer.String("SAR"); break;
    case CurrencySBD: writer.String("SBD"); break;
    case CurrencySCR: writer.String("SCR"); break;
    case CurrencySDG: writer.String("SDG"); break;
    case CurrencySEK: writer.String("SEK"); break;
    case CurrencySGD: writer.String("SGD"); break;
    case CurrencySHP: writer.String("SHP"); break;
    case CurrencySLL: writer.String("SLL"); break;
    case CurrencySOS: writer.String("SOS"); break;
    case CurrencySPL: writer.String("SPL"); break;
    case CurrencySRD: writer.String("SRD"); break;
    case CurrencySTD: writer.String("STD"); break;
    case CurrencySVC: writer.String("SVC"); break;
    case CurrencySYP: writer.String("SYP"); break;
    case CurrencySZL: writer.String("SZL"); break;
    case CurrencyTHB: writer.String("THB"); break;
    case CurrencyTJS: writer.String("TJS"); break;
    case CurrencyTMT: writer.String("TMT"); break;
    case CurrencyTND: writer.String("TND"); break;
    case CurrencyTOP: writer.String("TOP"); break;
    case CurrencyTRY: writer.String("TRY"); break;
    case CurrencyTTD: writer.String("TTD"); break;
    case CurrencyTVD: writer.String("TVD"); break;
    case CurrencyTWD: writer.String("TWD"); break;
    case CurrencyTZS: writer.String("TZS"); break;
    case CurrencyUAH: writer.String("UAH"); break;
    case CurrencyUGX: writer.String("UGX"); break;
    case CurrencyUSD: writer.String("USD"); break;
    case CurrencyUYU: writer.String("UYU"); break;
    case CurrencyUZS: writer.String("UZS"); break;
    case CurrencyVEF: writer.String("VEF"); break;
    case CurrencyVND: writer.String("VND"); break;
    case CurrencyVUV: writer.String("VUV"); break;
    case CurrencyWST: writer.String("WST"); break;
    case CurrencyXAF: writer.String("XAF"); break;
    case CurrencyXCD: writer.String("XCD"); break;
    case CurrencyXDR: writer.String("XDR"); break;
    case CurrencyXOF: writer.String("XOF"); break;
    case CurrencyXPF: writer.String("XPF"); break;
    case CurrencyYER: writer.String("YER"); break;
    case CurrencyZAR: writer.String("ZAR"); break;
    case CurrencyZMW: writer.String("ZMW"); break;
    case CurrencyZWD: writer.String("ZWD"); break;

    }
}

Currency PlayFab::AdminModels::readCurrencyFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, Currency> _CurrencyMap;
    if (_CurrencyMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _CurrencyMap["AED"] = CurrencyAED;
        _CurrencyMap["AFN"] = CurrencyAFN;
        _CurrencyMap["ALL"] = CurrencyALL;
        _CurrencyMap["AMD"] = CurrencyAMD;
        _CurrencyMap["ANG"] = CurrencyANG;
        _CurrencyMap["AOA"] = CurrencyAOA;
        _CurrencyMap["ARS"] = CurrencyARS;
        _CurrencyMap["AUD"] = CurrencyAUD;
        _CurrencyMap["AWG"] = CurrencyAWG;
        _CurrencyMap["AZN"] = CurrencyAZN;
        _CurrencyMap["BAM"] = CurrencyBAM;
        _CurrencyMap["BBD"] = CurrencyBBD;
        _CurrencyMap["BDT"] = CurrencyBDT;
        _CurrencyMap["BGN"] = CurrencyBGN;
        _CurrencyMap["BHD"] = CurrencyBHD;
        _CurrencyMap["BIF"] = CurrencyBIF;
        _CurrencyMap["BMD"] = CurrencyBMD;
        _CurrencyMap["BND"] = CurrencyBND;
        _CurrencyMap["BOB"] = CurrencyBOB;
        _CurrencyMap["BRL"] = CurrencyBRL;
        _CurrencyMap["BSD"] = CurrencyBSD;
        _CurrencyMap["BTN"] = CurrencyBTN;
        _CurrencyMap["BWP"] = CurrencyBWP;
        _CurrencyMap["BYR"] = CurrencyBYR;
        _CurrencyMap["BZD"] = CurrencyBZD;
        _CurrencyMap["CAD"] = CurrencyCAD;
        _CurrencyMap["CDF"] = CurrencyCDF;
        _CurrencyMap["CHF"] = CurrencyCHF;
        _CurrencyMap["CLP"] = CurrencyCLP;
        _CurrencyMap["CNY"] = CurrencyCNY;
        _CurrencyMap["COP"] = CurrencyCOP;
        _CurrencyMap["CRC"] = CurrencyCRC;
        _CurrencyMap["CUC"] = CurrencyCUC;
        _CurrencyMap["CUP"] = CurrencyCUP;
        _CurrencyMap["CVE"] = CurrencyCVE;
        _CurrencyMap["CZK"] = CurrencyCZK;
        _CurrencyMap["DJF"] = CurrencyDJF;
        _CurrencyMap["DKK"] = CurrencyDKK;
        _CurrencyMap["DOP"] = CurrencyDOP;
        _CurrencyMap["DZD"] = CurrencyDZD;
        _CurrencyMap["EGP"] = CurrencyEGP;
        _CurrencyMap["ERN"] = CurrencyERN;
        _CurrencyMap["ETB"] = CurrencyETB;
        _CurrencyMap["EUR"] = CurrencyEUR;
        _CurrencyMap["FJD"] = CurrencyFJD;
        _CurrencyMap["FKP"] = CurrencyFKP;
        _CurrencyMap["GBP"] = CurrencyGBP;
        _CurrencyMap["GEL"] = CurrencyGEL;
        _CurrencyMap["GGP"] = CurrencyGGP;
        _CurrencyMap["GHS"] = CurrencyGHS;
        _CurrencyMap["GIP"] = CurrencyGIP;
        _CurrencyMap["GMD"] = CurrencyGMD;
        _CurrencyMap["GNF"] = CurrencyGNF;
        _CurrencyMap["GTQ"] = CurrencyGTQ;
        _CurrencyMap["GYD"] = CurrencyGYD;
        _CurrencyMap["HKD"] = CurrencyHKD;
        _CurrencyMap["HNL"] = CurrencyHNL;
        _CurrencyMap["HRK"] = CurrencyHRK;
        _CurrencyMap["HTG"] = CurrencyHTG;
        _CurrencyMap["HUF"] = CurrencyHUF;
        _CurrencyMap["IDR"] = CurrencyIDR;
        _CurrencyMap["ILS"] = CurrencyILS;
        _CurrencyMap["IMP"] = CurrencyIMP;
        _CurrencyMap["INR"] = CurrencyINR;
        _CurrencyMap["IQD"] = CurrencyIQD;
        _CurrencyMap["IRR"] = CurrencyIRR;
        _CurrencyMap["ISK"] = CurrencyISK;
        _CurrencyMap["JEP"] = CurrencyJEP;
        _CurrencyMap["JMD"] = CurrencyJMD;
        _CurrencyMap["JOD"] = CurrencyJOD;
        _CurrencyMap["JPY"] = CurrencyJPY;
        _CurrencyMap["KES"] = CurrencyKES;
        _CurrencyMap["KGS"] = CurrencyKGS;
        _CurrencyMap["KHR"] = CurrencyKHR;
        _CurrencyMap["KMF"] = CurrencyKMF;
        _CurrencyMap["KPW"] = CurrencyKPW;
        _CurrencyMap["KRW"] = CurrencyKRW;
        _CurrencyMap["KWD"] = CurrencyKWD;
        _CurrencyMap["KYD"] = CurrencyKYD;
        _CurrencyMap["KZT"] = CurrencyKZT;
        _CurrencyMap["LAK"] = CurrencyLAK;
        _CurrencyMap["LBP"] = CurrencyLBP;
        _CurrencyMap["LKR"] = CurrencyLKR;
        _CurrencyMap["LRD"] = CurrencyLRD;
        _CurrencyMap["LSL"] = CurrencyLSL;
        _CurrencyMap["LYD"] = CurrencyLYD;
        _CurrencyMap["MAD"] = CurrencyMAD;
        _CurrencyMap["MDL"] = CurrencyMDL;
        _CurrencyMap["MGA"] = CurrencyMGA;
        _CurrencyMap["MKD"] = CurrencyMKD;
        _CurrencyMap["MMK"] = CurrencyMMK;
        _CurrencyMap["MNT"] = CurrencyMNT;
        _CurrencyMap["MOP"] = CurrencyMOP;
        _CurrencyMap["MRO"] = CurrencyMRO;
        _CurrencyMap["MUR"] = CurrencyMUR;
        _CurrencyMap["MVR"] = CurrencyMVR;
        _CurrencyMap["MWK"] = CurrencyMWK;
        _CurrencyMap["MXN"] = CurrencyMXN;
        _CurrencyMap["MYR"] = CurrencyMYR;
        _CurrencyMap["MZN"] = CurrencyMZN;
        _CurrencyMap["NAD"] = CurrencyNAD;
        _CurrencyMap["NGN"] = CurrencyNGN;
        _CurrencyMap["NIO"] = CurrencyNIO;
        _CurrencyMap["NOK"] = CurrencyNOK;
        _CurrencyMap["NPR"] = CurrencyNPR;
        _CurrencyMap["NZD"] = CurrencyNZD;
        _CurrencyMap["OMR"] = CurrencyOMR;
        _CurrencyMap["PAB"] = CurrencyPAB;
        _CurrencyMap["PEN"] = CurrencyPEN;
        _CurrencyMap["PGK"] = CurrencyPGK;
        _CurrencyMap["PHP"] = CurrencyPHP;
        _CurrencyMap["PKR"] = CurrencyPKR;
        _CurrencyMap["PLN"] = CurrencyPLN;
        _CurrencyMap["PYG"] = CurrencyPYG;
        _CurrencyMap["QAR"] = CurrencyQAR;
        _CurrencyMap["RON"] = CurrencyRON;
        _CurrencyMap["RSD"] = CurrencyRSD;
        _CurrencyMap["RUB"] = CurrencyRUB;
        _CurrencyMap["RWF"] = CurrencyRWF;
        _CurrencyMap["SAR"] = CurrencySAR;
        _CurrencyMap["SBD"] = CurrencySBD;
        _CurrencyMap["SCR"] = CurrencySCR;
        _CurrencyMap["SDG"] = CurrencySDG;
        _CurrencyMap["SEK"] = CurrencySEK;
        _CurrencyMap["SGD"] = CurrencySGD;
        _CurrencyMap["SHP"] = CurrencySHP;
        _CurrencyMap["SLL"] = CurrencySLL;
        _CurrencyMap["SOS"] = CurrencySOS;
        _CurrencyMap["SPL"] = CurrencySPL;
        _CurrencyMap["SRD"] = CurrencySRD;
        _CurrencyMap["STD"] = CurrencySTD;
        _CurrencyMap["SVC"] = CurrencySVC;
        _CurrencyMap["SYP"] = CurrencySYP;
        _CurrencyMap["SZL"] = CurrencySZL;
        _CurrencyMap["THB"] = CurrencyTHB;
        _CurrencyMap["TJS"] = CurrencyTJS;
        _CurrencyMap["TMT"] = CurrencyTMT;
        _CurrencyMap["TND"] = CurrencyTND;
        _CurrencyMap["TOP"] = CurrencyTOP;
        _CurrencyMap["TRY"] = CurrencyTRY;
        _CurrencyMap["TTD"] = CurrencyTTD;
        _CurrencyMap["TVD"] = CurrencyTVD;
        _CurrencyMap["TWD"] = CurrencyTWD;
        _CurrencyMap["TZS"] = CurrencyTZS;
        _CurrencyMap["UAH"] = CurrencyUAH;
        _CurrencyMap["UGX"] = CurrencyUGX;
        _CurrencyMap["USD"] = CurrencyUSD;
        _CurrencyMap["UYU"] = CurrencyUYU;
        _CurrencyMap["UZS"] = CurrencyUZS;
        _CurrencyMap["VEF"] = CurrencyVEF;
        _CurrencyMap["VND"] = CurrencyVND;
        _CurrencyMap["VUV"] = CurrencyVUV;
        _CurrencyMap["WST"] = CurrencyWST;
        _CurrencyMap["XAF"] = CurrencyXAF;
        _CurrencyMap["XCD"] = CurrencyXCD;
        _CurrencyMap["XDR"] = CurrencyXDR;
        _CurrencyMap["XOF"] = CurrencyXOF;
        _CurrencyMap["XPF"] = CurrencyXPF;
        _CurrencyMap["YER"] = CurrencyYER;
        _CurrencyMap["ZAR"] = CurrencyZAR;
        _CurrencyMap["ZMW"] = CurrencyZMW;
        _CurrencyMap["ZWD"] = CurrencyZWD;

    }

    auto output = _CurrencyMap.find(obj.GetString());
    if (output != _CurrencyMap.end())
        return output->second;

    return CurrencyAED; // Basically critical fail
}

DeleteContentRequest::~DeleteContentRequest()
{

}

void DeleteContentRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Key"); writer.String(Key.c_str());

    writer.EndObject();
}

bool DeleteContentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();

    return true;
}

DeleteStoreRequest::~DeleteStoreRequest()
{

}

void DeleteStoreRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("StoreId"); writer.String(StoreId.c_str());

    writer.EndObject();
}

bool DeleteStoreRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
    if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();

    return true;
}

DeleteStoreResult::~DeleteStoreResult()
{

}

void DeleteStoreResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool DeleteStoreResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

DeleteUsersRequest::~DeleteUsersRequest()
{

}

void DeleteUsersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
    writer.String("TitleId"); writer.String(TitleId.c_str());

    writer.EndObject();
}

bool DeleteUsersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

    return true;
}

DeleteUsersResult::~DeleteUsersResult()
{

}

void DeleteUsersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool DeleteUsersResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GameModeInfo::~GameModeInfo()
{

}

void GameModeInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Gamemode"); writer.String(Gamemode.c_str());
    writer.String("MinPlayerCount"); writer.Uint(MinPlayerCount);
    writer.String("MaxPlayerCount"); writer.Uint(MaxPlayerCount);
    if (StartOpen.notNull()) { writer.String("StartOpen"); writer.Bool(StartOpen); }

    writer.EndObject();
}

bool GameModeInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Gamemode_member = obj.FindMember("Gamemode");
    if (Gamemode_member != obj.MemberEnd() && !Gamemode_member->value.IsNull()) Gamemode = Gamemode_member->value.GetString();
    const Value::ConstMemberIterator MinPlayerCount_member = obj.FindMember("MinPlayerCount");
    if (MinPlayerCount_member != obj.MemberEnd() && !MinPlayerCount_member->value.IsNull()) MinPlayerCount = MinPlayerCount_member->value.GetUint();
    const Value::ConstMemberIterator MaxPlayerCount_member = obj.FindMember("MaxPlayerCount");
    if (MaxPlayerCount_member != obj.MemberEnd() && !MaxPlayerCount_member->value.IsNull()) MaxPlayerCount = MaxPlayerCount_member->value.GetUint();
    const Value::ConstMemberIterator StartOpen_member = obj.FindMember("StartOpen");
    if (StartOpen_member != obj.MemberEnd() && !StartOpen_member->value.IsNull()) StartOpen = StartOpen_member->value.GetBool();

    return true;
}

GetAllSegmentsRequest::~GetAllSegmentsRequest()
{

}

void GetAllSegmentsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool GetAllSegmentsRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetSegmentResult::~GetSegmentResult()
{

}

void GetSegmentResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Id"); writer.String(Id.c_str());
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    if (ABTestParent.length() > 0) { writer.String("ABTestParent"); writer.String(ABTestParent.c_str()); }

    writer.EndObject();
}

bool GetSegmentResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator ABTestParent_member = obj.FindMember("ABTestParent");
    if (ABTestParent_member != obj.MemberEnd() && !ABTestParent_member->value.IsNull()) ABTestParent = ABTestParent_member->value.GetString();

    return true;
}

GetAllSegmentsResult::~GetAllSegmentsResult()
{

}

void GetAllSegmentsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Segments.empty()) {
    writer.String("Segments");
    writer.StartArray();
    for (std::list<GetSegmentResult>::iterator iter = Segments.begin(); iter != Segments.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetAllSegmentsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Segments_member = obj.FindMember("Segments");
    if (Segments_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Segments_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Segments.push_back(GetSegmentResult(memberList[i]));
        }
    }

    return true;
}

GetCatalogItemsRequest::~GetCatalogItemsRequest()
{

}

void GetCatalogItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool GetCatalogItemsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

    return true;
}

GetCatalogItemsResult::~GetCatalogItemsResult()
{

}

void GetCatalogItemsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Catalog.empty()) {
    writer.String("Catalog");
    writer.StartArray();
    for (std::list<CatalogItem>::iterator iter = Catalog.begin(); iter != Catalog.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetCatalogItemsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Catalog_member = obj.FindMember("Catalog");
    if (Catalog_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Catalog_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Catalog.push_back(CatalogItem(memberList[i]));
        }
    }

    return true;
}

GetCloudScriptRevisionRequest::~GetCloudScriptRevisionRequest()
{

}

void GetCloudScriptRevisionRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
    if (Revision.notNull()) { writer.String("Revision"); writer.Int(Revision); }

    writer.EndObject();
}

bool GetCloudScriptRevisionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
    if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

    return true;
}

GetCloudScriptRevisionResult::~GetCloudScriptRevisionResult()
{

}

void GetCloudScriptRevisionResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Version"); writer.Int(Version);
    writer.String("Revision"); writer.Int(Revision);
    writer.String("CreatedAt"); writeDatetime(CreatedAt, writer);
    if (!Files.empty()) {
    writer.String("Files");
    writer.StartArray();
    for (std::list<CloudScriptFile>::iterator iter = Files.begin(); iter != Files.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    writer.String("IsPublished"); writer.Bool(IsPublished);

    writer.EndObject();
}

bool GetCloudScriptRevisionResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
    if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
    const Value::ConstMemberIterator CreatedAt_member = obj.FindMember("CreatedAt");
    if (CreatedAt_member != obj.MemberEnd() && !CreatedAt_member->value.IsNull()) CreatedAt = readDatetime(CreatedAt_member->value);
    const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
    if (Files_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Files_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Files.push_back(CloudScriptFile(memberList[i]));
        }
    }
    const Value::ConstMemberIterator IsPublished_member = obj.FindMember("IsPublished");
    if (IsPublished_member != obj.MemberEnd() && !IsPublished_member->value.IsNull()) IsPublished = IsPublished_member->value.GetBool();

    return true;
}

GetCloudScriptVersionsRequest::~GetCloudScriptVersionsRequest()
{

}

void GetCloudScriptVersionsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool GetCloudScriptVersionsRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetCloudScriptVersionsResult::~GetCloudScriptVersionsResult()
{

}

void GetCloudScriptVersionsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Versions.empty()) {
    writer.String("Versions");
    writer.StartArray();
    for (std::list<CloudScriptVersionStatus>::iterator iter = Versions.begin(); iter != Versions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetCloudScriptVersionsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Versions_member = obj.FindMember("Versions");
    if (Versions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Versions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Versions.push_back(CloudScriptVersionStatus(memberList[i]));
        }
    }

    return true;
}

GetContentListRequest::~GetContentListRequest()
{

}

void GetContentListRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Prefix.length() > 0) { writer.String("Prefix"); writer.String(Prefix.c_str()); }

    writer.EndObject();
}

bool GetContentListRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Prefix_member = obj.FindMember("Prefix");
    if (Prefix_member != obj.MemberEnd() && !Prefix_member->value.IsNull()) Prefix = Prefix_member->value.GetString();

    return true;
}

GetContentListResult::~GetContentListResult()
{

}

void GetContentListResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ItemCount"); writer.Int(ItemCount);
    writer.String("TotalSize"); writer.Uint(TotalSize);
    if (!Contents.empty()) {
    writer.String("Contents");
    writer.StartArray();
    for (std::list<ContentInfo>::iterator iter = Contents.begin(); iter != Contents.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetContentListResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ItemCount_member = obj.FindMember("ItemCount");
    if (ItemCount_member != obj.MemberEnd() && !ItemCount_member->value.IsNull()) ItemCount = ItemCount_member->value.GetInt();
    const Value::ConstMemberIterator TotalSize_member = obj.FindMember("TotalSize");
    if (TotalSize_member != obj.MemberEnd() && !TotalSize_member->value.IsNull()) TotalSize = TotalSize_member->value.GetUint();
    const Value::ConstMemberIterator Contents_member = obj.FindMember("Contents");
    if (Contents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Contents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Contents.push_back(ContentInfo(memberList[i]));
        }
    }

    return true;
}

GetContentUploadUrlRequest::~GetContentUploadUrlRequest()
{

}

void GetContentUploadUrlRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Key"); writer.String(Key.c_str());
    if (ContentType.length() > 0) { writer.String("ContentType"); writer.String(ContentType.c_str()); }

    writer.EndObject();
}

bool GetContentUploadUrlRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::ConstMemberIterator ContentType_member = obj.FindMember("ContentType");
    if (ContentType_member != obj.MemberEnd() && !ContentType_member->value.IsNull()) ContentType = ContentType_member->value.GetString();

    return true;
}

GetContentUploadUrlResult::~GetContentUploadUrlResult()
{

}

void GetContentUploadUrlResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }

    writer.EndObject();
}

bool GetContentUploadUrlResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator URL_member = obj.FindMember("URL");
    if (URL_member != obj.MemberEnd() && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

    return true;
}

GetDataReportRequest::~GetDataReportRequest()
{

}

void GetDataReportRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ReportName"); writer.String(ReportName.c_str());
    writer.String("Year"); writer.Int(Year);
    writer.String("Month"); writer.Int(Month);
    writer.String("Day"); writer.Int(Day);

    writer.EndObject();
}

bool GetDataReportRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ReportName_member = obj.FindMember("ReportName");
    if (ReportName_member != obj.MemberEnd() && !ReportName_member->value.IsNull()) ReportName = ReportName_member->value.GetString();
    const Value::ConstMemberIterator Year_member = obj.FindMember("Year");
    if (Year_member != obj.MemberEnd() && !Year_member->value.IsNull()) Year = Year_member->value.GetInt();
    const Value::ConstMemberIterator Month_member = obj.FindMember("Month");
    if (Month_member != obj.MemberEnd() && !Month_member->value.IsNull()) Month = Month_member->value.GetInt();
    const Value::ConstMemberIterator Day_member = obj.FindMember("Day");
    if (Day_member != obj.MemberEnd() && !Day_member->value.IsNull()) Day = Day_member->value.GetInt();

    return true;
}

GetDataReportResult::~GetDataReportResult()
{

}

void GetDataReportResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (DownloadUrl.length() > 0) { writer.String("DownloadUrl"); writer.String(DownloadUrl.c_str()); }

    writer.EndObject();
}

bool GetDataReportResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DownloadUrl_member = obj.FindMember("DownloadUrl");
    if (DownloadUrl_member != obj.MemberEnd() && !DownloadUrl_member->value.IsNull()) DownloadUrl = DownloadUrl_member->value.GetString();

    return true;
}

GetMatchmakerGameInfoRequest::~GetMatchmakerGameInfoRequest()
{

}

void GetMatchmakerGameInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("LobbyId"); writer.String(LobbyId.c_str());

    writer.EndObject();
}

bool GetMatchmakerGameInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

    return true;
}

GetMatchmakerGameInfoResult::~GetMatchmakerGameInfoResult()
{

}

void GetMatchmakerGameInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (LobbyId.length() > 0) { writer.String("LobbyId"); writer.String(LobbyId.c_str()); }
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    writer.String("StartTime"); writeDatetime(StartTime, writer);
    if (EndTime.notNull()) { writer.String("EndTime"); writeDatetime(EndTime, writer); }
    if (Mode.length() > 0) { writer.String("Mode"); writer.String(Mode.c_str()); }
    if (BuildVersion.length() > 0) { writer.String("BuildVersion"); writer.String(BuildVersion.c_str()); }
    if (pfRegion.notNull()) { writer.String("Region"); writeRegionEnumJSON(pfRegion, writer); }
    if (!Players.empty()) {
    writer.String("Players");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Players.begin(); iter != Players.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (ServerAddress.length() > 0) { writer.String("ServerAddress"); writer.String(ServerAddress.c_str()); }
    writer.String("ServerPort"); writer.Uint(ServerPort);

    writer.EndObject();
}

bool GetMatchmakerGameInfoResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator StartTime_member = obj.FindMember("StartTime");
    if (StartTime_member != obj.MemberEnd() && !StartTime_member->value.IsNull()) StartTime = readDatetime(StartTime_member->value);
    const Value::ConstMemberIterator EndTime_member = obj.FindMember("EndTime");
    if (EndTime_member != obj.MemberEnd() && !EndTime_member->value.IsNull()) EndTime = readDatetime(EndTime_member->value);
    const Value::ConstMemberIterator Mode_member = obj.FindMember("Mode");
    if (Mode_member != obj.MemberEnd() && !Mode_member->value.IsNull()) Mode = Mode_member->value.GetString();
    const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
    if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator Players_member = obj.FindMember("Players");
    if (Players_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Players_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Players.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator ServerAddress_member = obj.FindMember("ServerAddress");
    if (ServerAddress_member != obj.MemberEnd() && !ServerAddress_member->value.IsNull()) ServerAddress = ServerAddress_member->value.GetString();
    const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
    if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetUint();

    return true;
}

GetMatchmakerGameModesRequest::~GetMatchmakerGameModesRequest()
{

}

void GetMatchmakerGameModesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildVersion"); writer.String(BuildVersion.c_str());

    writer.EndObject();
}

bool GetMatchmakerGameModesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
    if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();

    return true;
}

GetMatchmakerGameModesResult::~GetMatchmakerGameModesResult()
{

}

void GetMatchmakerGameModesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!GameModes.empty()) {
    writer.String("GameModes");
    writer.StartArray();
    for (std::list<GameModeInfo>::iterator iter = GameModes.begin(); iter != GameModes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetMatchmakerGameModesResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GameModes_member = obj.FindMember("GameModes");
    if (GameModes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameModes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameModes.push_back(GameModeInfo(memberList[i]));
        }
    }

    return true;
}

GetPlayerSegmentsResult::~GetPlayerSegmentsResult()
{

}

void GetPlayerSegmentsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Segments.empty()) {
    writer.String("Segments");
    writer.StartArray();
    for (std::list<GetSegmentResult>::iterator iter = Segments.begin(); iter != Segments.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayerSegmentsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Segments_member = obj.FindMember("Segments");
    if (Segments_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Segments_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Segments.push_back(GetSegmentResult(memberList[i]));
        }
    }

    return true;
}

GetPlayersInSegmentRequest::~GetPlayersInSegmentRequest()
{

}

void GetPlayersInSegmentRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SegmentId"); writer.String(SegmentId.c_str());
    if (SecondsToLive.notNull()) { writer.String("SecondsToLive"); writer.Uint(SecondsToLive); }
    if (MaxBatchSize.notNull()) { writer.String("MaxBatchSize"); writer.Uint(MaxBatchSize); }
    if (ContinuationToken.length() > 0) { writer.String("ContinuationToken"); writer.String(ContinuationToken.c_str()); }

    writer.EndObject();
}

bool GetPlayersInSegmentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SegmentId_member = obj.FindMember("SegmentId");
    if (SegmentId_member != obj.MemberEnd() && !SegmentId_member->value.IsNull()) SegmentId = SegmentId_member->value.GetString();
    const Value::ConstMemberIterator SecondsToLive_member = obj.FindMember("SecondsToLive");
    if (SecondsToLive_member != obj.MemberEnd() && !SecondsToLive_member->value.IsNull()) SecondsToLive = SecondsToLive_member->value.GetUint();
    const Value::ConstMemberIterator MaxBatchSize_member = obj.FindMember("MaxBatchSize");
    if (MaxBatchSize_member != obj.MemberEnd() && !MaxBatchSize_member->value.IsNull()) MaxBatchSize = MaxBatchSize_member->value.GetUint();
    const Value::ConstMemberIterator ContinuationToken_member = obj.FindMember("ContinuationToken");
    if (ContinuationToken_member != obj.MemberEnd() && !ContinuationToken_member->value.IsNull()) ContinuationToken = ContinuationToken_member->value.GetString();

    return true;
}
void PlayFab::AdminModels::writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer)
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

    }
}

LoginIdentityProvider PlayFab::AdminModels::readLoginIdentityProviderFromValue(const rapidjson::Value& obj)
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

    }

    auto output = _LoginIdentityProviderMap.find(obj.GetString());
    if (output != _LoginIdentityProviderMap.end())
        return output->second;

    return LoginIdentityProviderUnknown; // Basically critical fail
}
void PlayFab::AdminModels::writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case PushNotificationPlatformApplePushNotificationService: writer.String("ApplePushNotificationService"); break;
    case PushNotificationPlatformGoogleCloudMessaging: writer.String("GoogleCloudMessaging"); break;

    }
}

PushNotificationPlatform PlayFab::AdminModels::readPushNotificationPlatformFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, PushNotificationPlatform> _PushNotificationPlatformMap;
    if (_PushNotificationPlatformMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _PushNotificationPlatformMap["ApplePushNotificationService"] = PushNotificationPlatformApplePushNotificationService;
        _PushNotificationPlatformMap["GoogleCloudMessaging"] = PushNotificationPlatformGoogleCloudMessaging;

    }

    auto output = _PushNotificationPlatformMap.find(obj.GetString());
    if (output != _PushNotificationPlatformMap.end())
        return output->second;

    return PushNotificationPlatformApplePushNotificationService; // Basically critical fail
}

PushNotificationRegistration::~PushNotificationRegistration()
{

}

void PushNotificationRegistration::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Platform.notNull()) { writer.String("Platform"); writePushNotificationPlatformEnumJSON(Platform, writer); }
    if (NotificationEndpointARN.length() > 0) { writer.String("NotificationEndpointARN"); writer.String(NotificationEndpointARN.c_str()); }

    writer.EndObject();
}

bool PushNotificationRegistration::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushNotificationPlatformFromValue(Platform_member->value);
    const Value::ConstMemberIterator NotificationEndpointARN_member = obj.FindMember("NotificationEndpointARN");
    if (NotificationEndpointARN_member != obj.MemberEnd() && !NotificationEndpointARN_member->value.IsNull()) NotificationEndpointARN = NotificationEndpointARN_member->value.GetString();

    return true;
}

PlayerLinkedAccount::~PlayerLinkedAccount()
{

}

void PlayerLinkedAccount::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Platform.notNull()) { writer.String("Platform"); writeLoginIdentityProviderEnumJSON(Platform, writer); }
    if (PlatformUserId.length() > 0) { writer.String("PlatformUserId"); writer.String(PlatformUserId.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }

    writer.EndObject();
}

bool PlayerLinkedAccount::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readLoginIdentityProviderFromValue(Platform_member->value);
    const Value::ConstMemberIterator PlatformUserId_member = obj.FindMember("PlatformUserId");
    if (PlatformUserId_member != obj.MemberEnd() && !PlatformUserId_member->value.IsNull()) PlatformUserId = PlatformUserId_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
    if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

    return true;
}

PlayerStatistic::~PlayerStatistic()
{

}

void PlayerStatistic::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }
    writer.String("StatisticVersion"); writer.Int(StatisticVersion);
    writer.String("StatisticValue"); writer.Int(StatisticValue);
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }

    writer.EndObject();
}

bool PlayerStatistic::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator StatisticVersion_member = obj.FindMember("StatisticVersion");
    if (StatisticVersion_member != obj.MemberEnd() && !StatisticVersion_member->value.IsNull()) StatisticVersion = StatisticVersion_member->value.GetInt();
    const Value::ConstMemberIterator StatisticValue_member = obj.FindMember("StatisticValue");
    if (StatisticValue_member != obj.MemberEnd() && !StatisticValue_member->value.IsNull()) StatisticValue = StatisticValue_member->value.GetInt();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

    return true;
}

PlayerProfile::~PlayerProfile()
{

}

void PlayerProfile::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayerId.length() > 0) { writer.String("PlayerId"); writer.String(PlayerId.c_str()); }
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (PublisherId.length() > 0) { writer.String("PublisherId"); writer.String(PublisherId.c_str()); }
    if (Origination.notNull()) { writer.String("Origination"); writeLoginIdentityProviderEnumJSON(Origination, writer); }
    if (Created.notNull()) { writer.String("Created"); writeDatetime(Created, writer); }
    if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
    if (BannedUntil.notNull()) { writer.String("BannedUntil"); writeDatetime(BannedUntil, writer); }
    if (!Statistics.empty()) {
    writer.String("Statistics");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = Statistics.begin(); iter != Statistics.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
    if (!ValuesToDate.empty()) {
    writer.String("ValuesToDate");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = ValuesToDate.begin(); iter != ValuesToDate.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
    if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!VirtualCurrencyBalances.empty()) {
    writer.String("VirtualCurrencyBalances");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = VirtualCurrencyBalances.begin(); iter != VirtualCurrencyBalances.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
    if (!AdCampaignAttributions.empty()) {
    writer.String("AdCampaignAttributions");
    writer.StartArray();
    for (std::list<AdCampaignAttribution>::iterator iter = AdCampaignAttributions.begin(); iter != AdCampaignAttributions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!PushNotificationRegistrations.empty()) {
    writer.String("PushNotificationRegistrations");
    writer.StartArray();
    for (std::list<PushNotificationRegistration>::iterator iter = PushNotificationRegistrations.begin(); iter != PushNotificationRegistrations.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!LinkedAccounts.empty()) {
    writer.String("LinkedAccounts");
    writer.StartArray();
    for (std::list<PlayerLinkedAccount>::iterator iter = LinkedAccounts.begin(); iter != LinkedAccounts.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!PlayerStatistics.empty()) {
    writer.String("PlayerStatistics");
    writer.StartArray();
    for (std::list<PlayerStatistic>::iterator iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool PlayerProfile::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
    if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator PublisherId_member = obj.FindMember("PublisherId");
    if (PublisherId_member != obj.MemberEnd() && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();
    const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
    if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readLoginIdentityProviderFromValue(Origination_member->value);
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
    if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
    const Value::ConstMemberIterator BannedUntil_member = obj.FindMember("BannedUntil");
    if (BannedUntil_member != obj.MemberEnd() && !BannedUntil_member->value.IsNull()) BannedUntil = readDatetime(BannedUntil_member->value);
    const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Statistics_member->value.MemberBegin(); iter != Statistics_member->value.MemberEnd(); ++iter) {
            Statistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::ConstMemberIterator ValuesToDate_member = obj.FindMember("ValuesToDate");
    if (ValuesToDate_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = ValuesToDate_member->value.MemberBegin(); iter != ValuesToDate_member->value.MemberEnd(); ++iter) {
            ValuesToDate[iter->name.GetString()] = iter->value.GetUint();
        }
    }
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
    if (VirtualCurrencyBalances_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyBalances_member->value.MemberBegin(); iter != VirtualCurrencyBalances_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyBalances[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::ConstMemberIterator AdCampaignAttributions_member = obj.FindMember("AdCampaignAttributions");
    if (AdCampaignAttributions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AdCampaignAttributions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AdCampaignAttributions.push_back(AdCampaignAttribution(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PushNotificationRegistrations_member = obj.FindMember("PushNotificationRegistrations");
    if (PushNotificationRegistrations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PushNotificationRegistrations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PushNotificationRegistrations.push_back(PushNotificationRegistration(memberList[i]));
        }
    }
    const Value::ConstMemberIterator LinkedAccounts_member = obj.FindMember("LinkedAccounts");
    if (LinkedAccounts_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = LinkedAccounts_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            LinkedAccounts.push_back(PlayerLinkedAccount(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
    if (PlayerStatistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatistics.push_back(PlayerStatistic(memberList[i]));
        }
    }

    return true;
}

GetPlayersInSegmentResult::~GetPlayersInSegmentResult()
{

}

void GetPlayersInSegmentResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ProfilesInSegment"); writer.Int(ProfilesInSegment);
    if (ContinuationToken.length() > 0) { writer.String("ContinuationToken"); writer.String(ContinuationToken.c_str()); }
    if (!PlayerProfiles.empty()) {
    writer.String("PlayerProfiles");
    writer.StartArray();
    for (std::list<PlayerProfile>::iterator iter = PlayerProfiles.begin(); iter != PlayerProfiles.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayersInSegmentResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ProfilesInSegment_member = obj.FindMember("ProfilesInSegment");
    if (ProfilesInSegment_member != obj.MemberEnd() && !ProfilesInSegment_member->value.IsNull()) ProfilesInSegment = ProfilesInSegment_member->value.GetInt();
    const Value::ConstMemberIterator ContinuationToken_member = obj.FindMember("ContinuationToken");
    if (ContinuationToken_member != obj.MemberEnd() && !ContinuationToken_member->value.IsNull()) ContinuationToken = ContinuationToken_member->value.GetString();
    const Value::ConstMemberIterator PlayerProfiles_member = obj.FindMember("PlayerProfiles");
    if (PlayerProfiles_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerProfiles_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerProfiles.push_back(PlayerProfile(memberList[i]));
        }
    }

    return true;
}

GetPlayersSegmentsRequest::~GetPlayersSegmentsRequest()
{

}

void GetPlayersSegmentsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool GetPlayersSegmentsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetPlayerStatisticDefinitionsRequest::~GetPlayerStatisticDefinitionsRequest()
{

}

void GetPlayerStatisticDefinitionsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool GetPlayerStatisticDefinitionsRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetPlayerStatisticDefinitionsResult::~GetPlayerStatisticDefinitionsResult()
{

}

void GetPlayerStatisticDefinitionsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Statistics.empty()) {
    writer.String("Statistics");
    writer.StartArray();
    for (std::list<PlayerStatisticDefinition>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayerStatisticDefinitionsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statistics.push_back(PlayerStatisticDefinition(memberList[i]));
        }
    }

    return true;
}

GetPlayerStatisticVersionsRequest::~GetPlayerStatisticVersionsRequest()
{

}

void GetPlayerStatisticVersionsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }

    writer.EndObject();
}

bool GetPlayerStatisticVersionsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

    return true;
}
void PlayFab::AdminModels::writeStatisticVersionArchivalStatusEnumJSON(StatisticVersionArchivalStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case StatisticVersionArchivalStatusNotScheduled: writer.String("NotScheduled"); break;
    case StatisticVersionArchivalStatusScheduled: writer.String("Scheduled"); break;
    case StatisticVersionArchivalStatusQueued: writer.String("Queued"); break;
    case StatisticVersionArchivalStatusInProgress: writer.String("InProgress"); break;
    case StatisticVersionArchivalStatusComplete: writer.String("Complete"); break;

    }
}

StatisticVersionArchivalStatus PlayFab::AdminModels::readStatisticVersionArchivalStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, StatisticVersionArchivalStatus> _StatisticVersionArchivalStatusMap;
    if (_StatisticVersionArchivalStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _StatisticVersionArchivalStatusMap["NotScheduled"] = StatisticVersionArchivalStatusNotScheduled;
        _StatisticVersionArchivalStatusMap["Scheduled"] = StatisticVersionArchivalStatusScheduled;
        _StatisticVersionArchivalStatusMap["Queued"] = StatisticVersionArchivalStatusQueued;
        _StatisticVersionArchivalStatusMap["InProgress"] = StatisticVersionArchivalStatusInProgress;
        _StatisticVersionArchivalStatusMap["Complete"] = StatisticVersionArchivalStatusComplete;

    }

    auto output = _StatisticVersionArchivalStatusMap.find(obj.GetString());
    if (output != _StatisticVersionArchivalStatusMap.end())
        return output->second;

    return StatisticVersionArchivalStatusNotScheduled; // Basically critical fail
}

PlayerStatisticVersion::~PlayerStatisticVersion()
{

}

void PlayerStatisticVersion::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
    writer.String("Version"); writer.Uint(Version);
    if (ScheduledActivationTime.notNull()) { writer.String("ScheduledActivationTime"); writeDatetime(ScheduledActivationTime, writer); }
    writer.String("ActivationTime"); writeDatetime(ActivationTime, writer);
    if (ScheduledDeactivationTime.notNull()) { writer.String("ScheduledDeactivationTime"); writeDatetime(ScheduledDeactivationTime, writer); }
    if (DeactivationTime.notNull()) { writer.String("DeactivationTime"); writeDatetime(DeactivationTime, writer); }
    if (ArchivalStatus.notNull()) { writer.String("ArchivalStatus"); writeStatisticVersionArchivalStatusEnumJSON(ArchivalStatus, writer); }
    if (ArchiveDownloadUrl.length() > 0) { writer.String("ArchiveDownloadUrl"); writer.String(ArchiveDownloadUrl.c_str()); }

    writer.EndObject();
}

bool PlayerStatisticVersion::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();
    const Value::ConstMemberIterator ScheduledActivationTime_member = obj.FindMember("ScheduledActivationTime");
    if (ScheduledActivationTime_member != obj.MemberEnd() && !ScheduledActivationTime_member->value.IsNull()) ScheduledActivationTime = readDatetime(ScheduledActivationTime_member->value);
    const Value::ConstMemberIterator ActivationTime_member = obj.FindMember("ActivationTime");
    if (ActivationTime_member != obj.MemberEnd() && !ActivationTime_member->value.IsNull()) ActivationTime = readDatetime(ActivationTime_member->value);
    const Value::ConstMemberIterator ScheduledDeactivationTime_member = obj.FindMember("ScheduledDeactivationTime");
    if (ScheduledDeactivationTime_member != obj.MemberEnd() && !ScheduledDeactivationTime_member->value.IsNull()) ScheduledDeactivationTime = readDatetime(ScheduledDeactivationTime_member->value);
    const Value::ConstMemberIterator DeactivationTime_member = obj.FindMember("DeactivationTime");
    if (DeactivationTime_member != obj.MemberEnd() && !DeactivationTime_member->value.IsNull()) DeactivationTime = readDatetime(DeactivationTime_member->value);
    const Value::ConstMemberIterator ArchivalStatus_member = obj.FindMember("ArchivalStatus");
    if (ArchivalStatus_member != obj.MemberEnd() && !ArchivalStatus_member->value.IsNull()) ArchivalStatus = readStatisticVersionArchivalStatusFromValue(ArchivalStatus_member->value);
    const Value::ConstMemberIterator ArchiveDownloadUrl_member = obj.FindMember("ArchiveDownloadUrl");
    if (ArchiveDownloadUrl_member != obj.MemberEnd() && !ArchiveDownloadUrl_member->value.IsNull()) ArchiveDownloadUrl = ArchiveDownloadUrl_member->value.GetString();

    return true;
}

GetPlayerStatisticVersionsResult::~GetPlayerStatisticVersionsResult()
{

}

void GetPlayerStatisticVersionsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!StatisticVersions.empty()) {
    writer.String("StatisticVersions");
    writer.StartArray();
    for (std::list<PlayerStatisticVersion>::iterator iter = StatisticVersions.begin(); iter != StatisticVersions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayerStatisticVersionsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticVersions_member = obj.FindMember("StatisticVersions");
    if (StatisticVersions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = StatisticVersions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            StatisticVersions.push_back(PlayerStatisticVersion(memberList[i]));
        }
    }

    return true;
}

GetPlayerTagsRequest::~GetPlayerTagsRequest()
{

}

void GetPlayerTagsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (Namespace.length() > 0) { writer.String("Namespace"); writer.String(Namespace.c_str()); }

    writer.EndObject();
}

bool GetPlayerTagsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Namespace_member = obj.FindMember("Namespace");
    if (Namespace_member != obj.MemberEnd() && !Namespace_member->value.IsNull()) Namespace = Namespace_member->value.GetString();

    return true;
}

GetPlayerTagsResult::~GetPlayerTagsResult()
{

}

void GetPlayerTagsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("Tags");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GetPlayerTagsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetPublisherDataRequest::~GetPublisherDataRequest()
{

}

void GetPublisherDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Keys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GetPublisherDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetPublisherDataResult::~GetPublisherDataResult()
{

}

void GetPublisherDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool GetPublisherDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

GetRandomResultTablesRequest::~GetRandomResultTablesRequest()
{

}

void GetRandomResultTablesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool GetRandomResultTablesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

    return true;
}
void PlayFab::AdminModels::writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case ResultTableNodeTypeItemId: writer.String("ItemId"); break;
    case ResultTableNodeTypeTableId: writer.String("TableId"); break;

    }
}

ResultTableNodeType PlayFab::AdminModels::readResultTableNodeTypeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, ResultTableNodeType> _ResultTableNodeTypeMap;
    if (_ResultTableNodeTypeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _ResultTableNodeTypeMap["ItemId"] = ResultTableNodeTypeItemId;
        _ResultTableNodeTypeMap["TableId"] = ResultTableNodeTypeTableId;

    }

    auto output = _ResultTableNodeTypeMap.find(obj.GetString());
    if (output != _ResultTableNodeTypeMap.end())
        return output->second;

    return ResultTableNodeTypeItemId; // Basically critical fail
}

ResultTableNode::~ResultTableNode()
{

}

void ResultTableNode::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ResultItemType"); writeResultTableNodeTypeEnumJSON(ResultItemType, writer);
    writer.String("ResultItem"); writer.String(ResultItem.c_str());
    writer.String("Weight"); writer.Int(Weight);

    writer.EndObject();
}

bool ResultTableNode::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ResultItemType_member = obj.FindMember("ResultItemType");
    if (ResultItemType_member != obj.MemberEnd() && !ResultItemType_member->value.IsNull()) ResultItemType = readResultTableNodeTypeFromValue(ResultItemType_member->value);
    const Value::ConstMemberIterator ResultItem_member = obj.FindMember("ResultItem");
    if (ResultItem_member != obj.MemberEnd() && !ResultItem_member->value.IsNull()) ResultItem = ResultItem_member->value.GetString();
    const Value::ConstMemberIterator Weight_member = obj.FindMember("Weight");
    if (Weight_member != obj.MemberEnd() && !Weight_member->value.IsNull()) Weight = Weight_member->value.GetInt();

    return true;
}

RandomResultTableListing::~RandomResultTableListing()
{

}

void RandomResultTableListing::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("TableId"); writer.String(TableId.c_str());
    writer.String("Nodes");
    writer.StartArray();
    for (std::list<ResultTableNode>::iterator iter = Nodes.begin(); iter != Nodes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool RandomResultTableListing::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
    if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
    const Value::ConstMemberIterator Nodes_member = obj.FindMember("Nodes");
    if (Nodes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Nodes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Nodes.push_back(ResultTableNode(memberList[i]));
        }
    }

    return true;
}

GetRandomResultTablesResult::~GetRandomResultTablesResult()
{

}

void GetRandomResultTablesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Tables.empty()) {
    writer.String("Tables");
    writer.StartObject();
    for (std::map<std::string, RandomResultTableListing>::iterator iter = Tables.begin(); iter != Tables.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool GetRandomResultTablesResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Tables_member = obj.FindMember("Tables");
    if (Tables_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Tables_member->value.MemberBegin(); iter != Tables_member->value.MemberEnd(); ++iter) {
            Tables[iter->name.GetString()] = RandomResultTableListing(iter->value);
        }
    }

    return true;
}

GetServerBuildInfoRequest::~GetServerBuildInfoRequest()
{

}

void GetServerBuildInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildId"); writer.String(BuildId.c_str());

    writer.EndObject();
}

bool GetServerBuildInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

    return true;
}

GetServerBuildInfoResult::~GetServerBuildInfoResult()
{

}

void GetServerBuildInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    writer.String("Timestamp"); writeDatetime(Timestamp, writer);
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    if (Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
    if (ErrorMessage.length() > 0) { writer.String("ErrorMessage"); writer.String(ErrorMessage.c_str()); }

    writer.EndObject();
}

bool GetServerBuildInfoResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
    const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
    if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
    if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
    const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
    if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
    if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);
    const Value::ConstMemberIterator ErrorMessage_member = obj.FindMember("ErrorMessage");
    if (ErrorMessage_member != obj.MemberEnd() && !ErrorMessage_member->value.IsNull()) ErrorMessage = ErrorMessage_member->value.GetString();

    return true;
}

GetServerBuildUploadURLRequest::~GetServerBuildUploadURLRequest()
{

}

void GetServerBuildUploadURLRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildId"); writer.String(BuildId.c_str());

    writer.EndObject();
}

bool GetServerBuildUploadURLRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

    return true;
}

GetServerBuildUploadURLResult::~GetServerBuildUploadURLResult()
{

}

void GetServerBuildUploadURLResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }

    writer.EndObject();
}

bool GetServerBuildUploadURLResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator URL_member = obj.FindMember("URL");
    if (URL_member != obj.MemberEnd() && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

    return true;
}

GetStoreItemsRequest::~GetStoreItemsRequest()
{

}

void GetStoreItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("StoreId"); writer.String(StoreId.c_str());

    writer.EndObject();
}

bool GetStoreItemsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
    if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();

    return true;
}

StoreItem::~StoreItem()
{

}

void StoreItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ItemId"); writer.String(ItemId.c_str());
    if (!VirtualCurrencyPrices.empty()) {
    writer.String("VirtualCurrencyPrices");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }
    if (!RealCurrencyPrices.empty()) {
    writer.String("RealCurrencyPrices");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool StoreItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
    if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
    const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
    if (RealCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
            RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }

    return true;
}

GetStoreItemsResult::~GetStoreItemsResult()
{

}

void GetStoreItemsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Store.empty()) {
    writer.String("Store");
    writer.StartArray();
    for (std::list<StoreItem>::iterator iter = Store.begin(); iter != Store.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetStoreItemsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Store_member = obj.FindMember("Store");
    if (Store_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Store_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Store.push_back(StoreItem(memberList[i]));
        }
    }

    return true;
}

GetTitleDataRequest::~GetTitleDataRequest()
{

}

void GetTitleDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetTitleDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetTitleDataResult::~GetTitleDataResult()
{

}

void GetTitleDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool GetTitleDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

GetUserBansRequest::~GetUserBansRequest()
{

}

void GetUserBansRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool GetUserBansRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetUserBansResult::~GetUserBansResult()
{

}

void GetUserBansResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetUserBansResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

    return true;
}

GetUserDataRequest::~GetUserDataRequest()
{

}

void GetUserDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Uint(IfChangedFromDataVersion); }

    writer.EndObject();
}

bool GetUserDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
    if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();

    return true;
}
void PlayFab::AdminModels::writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case UserDataPermissionPrivate: writer.String("Private"); break;
    case UserDataPermissionPublic: writer.String("Public"); break;

    }
}

UserDataPermission PlayFab::AdminModels::readUserDataPermissionFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, UserDataPermission> _UserDataPermissionMap;
    if (_UserDataPermissionMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _UserDataPermissionMap["Private"] = UserDataPermissionPrivate;
        _UserDataPermissionMap["Public"] = UserDataPermissionPublic;

    }

    auto output = _UserDataPermissionMap.find(obj.GetString());
    if (output != _UserDataPermissionMap.end())
        return output->second;

    return UserDataPermissionPrivate; // Basically critical fail
}

UserDataRecord::~UserDataRecord()
{

}

void UserDataRecord::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
    writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
    if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }

    writer.EndObject();
}

bool UserDataRecord::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
    const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
    if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
    const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
    if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

    return true;
}

GetUserDataResult::~GetUserDataResult()
{

}

void GetUserDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.String("DataVersion"); writer.Uint(DataVersion);
    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool GetUserDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }

    return true;
}

GetUserInventoryRequest::~GetUserInventoryRequest()
{

}

void GetUserInventoryRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool GetUserInventoryRequest::readFromValue(const rapidjson::Value& obj)
{
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

    if (ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
    if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
    if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
    if (PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
    if (Expiration.notNull()) { writer.String("Expiration"); writeDatetime(Expiration, writer); }
    if (RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
    if (UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
    writer.String("UnitPrice"); writer.Uint(UnitPrice);
    if (!BundleContents.empty()) {
    writer.String("BundleContents");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!CustomData.empty()) {
    writer.String("CustomData");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool ItemInstance::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
    if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
    const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
    if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
    const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
    const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
    if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();
    const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator BundleParent_member = obj.FindMember("BundleParent");
    if (BundleParent_member != obj.MemberEnd() && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
    if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
    const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
    if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
    const Value::ConstMemberIterator BundleContents_member = obj.FindMember("BundleContents");
    if (BundleContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundleContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundleContents.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
            CustomData[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

VirtualCurrencyRechargeTime::~VirtualCurrencyRechargeTime()
{

}

void VirtualCurrencyRechargeTime::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SecondsToRecharge"); writer.Int(SecondsToRecharge);
    writer.String("RechargeTime"); writeDatetime(RechargeTime, writer);
    writer.String("RechargeMax"); writer.Int(RechargeMax);

    writer.EndObject();
}

bool VirtualCurrencyRechargeTime::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SecondsToRecharge_member = obj.FindMember("SecondsToRecharge");
    if (SecondsToRecharge_member != obj.MemberEnd() && !SecondsToRecharge_member->value.IsNull()) SecondsToRecharge = SecondsToRecharge_member->value.GetInt();
    const Value::ConstMemberIterator RechargeTime_member = obj.FindMember("RechargeTime");
    if (RechargeTime_member != obj.MemberEnd() && !RechargeTime_member->value.IsNull()) RechargeTime = readDatetime(RechargeTime_member->value);
    const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
    if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();

    return true;
}

GetUserInventoryResult::~GetUserInventoryResult()
{

}

void GetUserInventoryResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (!Inventory.empty()) {
    writer.String("Inventory");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
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

bool GetUserInventoryResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
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

GrantedItemInstance::~GrantedItemInstance()
{

}

void GrantedItemInstance::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("Result"); writer.Bool(Result);
    if (ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
    if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
    if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
    if (PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
    if (Expiration.notNull()) { writer.String("Expiration"); writeDatetime(Expiration, writer); }
    if (RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
    if (UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
    writer.String("UnitPrice"); writer.Uint(UnitPrice);
    if (!BundleContents.empty()) {
    writer.String("BundleContents");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!CustomData.empty()) {
    writer.String("CustomData");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool GrantedItemInstance::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
    if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();
    const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
    if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
    const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
    if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
    const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
    const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
    if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();
    const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator BundleParent_member = obj.FindMember("BundleParent");
    if (BundleParent_member != obj.MemberEnd() && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
    if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
    const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
    if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
    const Value::ConstMemberIterator BundleContents_member = obj.FindMember("BundleContents");
    if (BundleContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BundleContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundleContents.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
            CustomData[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

ItemGrant::~ItemGrant()
{

}

void ItemGrant::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("ItemId"); writer.String(ItemId.c_str());
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
    if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool ItemGrant::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GrantItemsToUsersRequest::~GrantItemsToUsersRequest()
{

}

void GrantItemsToUsersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("ItemGrants");
    writer.StartArray();
    for (std::list<ItemGrant>::iterator iter = ItemGrants.begin(); iter != ItemGrants.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GrantItemsToUsersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator ItemGrants_member = obj.FindMember("ItemGrants");
    if (ItemGrants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemGrants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemGrants.push_back(ItemGrant(memberList[i]));
        }
    }

    return true;
}

GrantItemsToUsersResult::~GrantItemsToUsersResult()
{

}

void GrantItemsToUsersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!ItemGrantResults.empty()) {
    writer.String("ItemGrantResults");
    writer.StartArray();
    for (std::list<GrantedItemInstance>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GrantItemsToUsersResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ItemGrantResults_member = obj.FindMember("ItemGrantResults");
    if (ItemGrantResults_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemGrantResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemGrantResults.push_back(GrantedItemInstance(memberList[i]));
        }
    }

    return true;
}

IncrementPlayerStatisticVersionRequest::~IncrementPlayerStatisticVersionRequest()
{

}

void IncrementPlayerStatisticVersionRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }

    writer.EndObject();
}

bool IncrementPlayerStatisticVersionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

    return true;
}

IncrementPlayerStatisticVersionResult::~IncrementPlayerStatisticVersionResult()
{
    if (StatisticVersion != NULL) delete StatisticVersion;

}

void IncrementPlayerStatisticVersionResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (StatisticVersion != NULL) { writer.String("StatisticVersion"); StatisticVersion->writeJSON(writer); }

    writer.EndObject();
}

bool IncrementPlayerStatisticVersionResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticVersion_member = obj.FindMember("StatisticVersion");
    if (StatisticVersion_member != obj.MemberEnd() && !StatisticVersion_member->value.IsNull()) StatisticVersion = new PlayerStatisticVersion(StatisticVersion_member->value);

    return true;
}

ListBuildsRequest::~ListBuildsRequest()
{

}

void ListBuildsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool ListBuildsRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

ListBuildsResult::~ListBuildsResult()
{

}

void ListBuildsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Builds.empty()) {
    writer.String("Builds");
    writer.StartArray();
    for (std::list<GetServerBuildInfoResult>::iterator iter = Builds.begin(); iter != Builds.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool ListBuildsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Builds_member = obj.FindMember("Builds");
    if (Builds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Builds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Builds.push_back(GetServerBuildInfoResult(memberList[i]));
        }
    }

    return true;
}

ListVirtualCurrencyTypesRequest::~ListVirtualCurrencyTypesRequest()
{

}

void ListVirtualCurrencyTypesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool ListVirtualCurrencyTypesRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

ListVirtualCurrencyTypesResult::~ListVirtualCurrencyTypesResult()
{

}

void ListVirtualCurrencyTypesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!VirtualCurrencies.empty()) {
    writer.String("VirtualCurrencies");
    writer.StartArray();
    for (std::list<VirtualCurrencyData>::iterator iter = VirtualCurrencies.begin(); iter != VirtualCurrencies.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool ListVirtualCurrencyTypesResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
    if (VirtualCurrencies_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = VirtualCurrencies_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
        }
    }

    return true;
}

LookupUserAccountInfoRequest::~LookupUserAccountInfoRequest()
{

}

void LookupUserAccountInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }

    writer.EndObject();
}

bool LookupUserAccountInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
    if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
    if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();

    return true;
}
void PlayFab::AdminModels::writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case UserOriginationOrganic: writer.String("Organic"); break;
    case UserOriginationSteam: writer.String("Steam"); break;
    case UserOriginationGoogle: writer.String("Google"); break;
    case UserOriginationAmazon: writer.String("Amazon"); break;
    case UserOriginationFacebook: writer.String("Facebook"); break;
    case UserOriginationKongregate: writer.String("Kongregate"); break;
    case UserOriginationGamersFirst: writer.String("GamersFirst"); break;
    case UserOriginationUnknown: writer.String("Unknown"); break;
    case UserOriginationIOS: writer.String("IOS"); break;
    case UserOriginationLoadTest: writer.String("LoadTest"); break;
    case UserOriginationAndroid: writer.String("Android"); break;
    case UserOriginationPSN: writer.String("PSN"); break;
    case UserOriginationGameCenter: writer.String("GameCenter"); break;
    case UserOriginationCustomId: writer.String("CustomId"); break;
    case UserOriginationXboxLive: writer.String("XboxLive"); break;
    case UserOriginationParse: writer.String("Parse"); break;
    case UserOriginationTwitch: writer.String("Twitch"); break;

    }
}

UserOrigination PlayFab::AdminModels::readUserOriginationFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, UserOrigination> _UserOriginationMap;
    if (_UserOriginationMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _UserOriginationMap["Organic"] = UserOriginationOrganic;
        _UserOriginationMap["Steam"] = UserOriginationSteam;
        _UserOriginationMap["Google"] = UserOriginationGoogle;
        _UserOriginationMap["Amazon"] = UserOriginationAmazon;
        _UserOriginationMap["Facebook"] = UserOriginationFacebook;
        _UserOriginationMap["Kongregate"] = UserOriginationKongregate;
        _UserOriginationMap["GamersFirst"] = UserOriginationGamersFirst;
        _UserOriginationMap["Unknown"] = UserOriginationUnknown;
        _UserOriginationMap["IOS"] = UserOriginationIOS;
        _UserOriginationMap["LoadTest"] = UserOriginationLoadTest;
        _UserOriginationMap["Android"] = UserOriginationAndroid;
        _UserOriginationMap["PSN"] = UserOriginationPSN;
        _UserOriginationMap["GameCenter"] = UserOriginationGameCenter;
        _UserOriginationMap["CustomId"] = UserOriginationCustomId;
        _UserOriginationMap["XboxLive"] = UserOriginationXboxLive;
        _UserOriginationMap["Parse"] = UserOriginationParse;
        _UserOriginationMap["Twitch"] = UserOriginationTwitch;

    }

    auto output = _UserOriginationMap.find(obj.GetString());
    if (output != _UserOriginationMap.end())
        return output->second;

    return UserOriginationOrganic; // Basically critical fail
}

UserTitleInfo::~UserTitleInfo()
{

}

void UserTitleInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (Origination.notNull()) { writer.String("Origination"); writeUserOriginationEnumJSON(Origination, writer); }
    writer.String("Created"); writeDatetime(Created, writer);
    if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
    if (FirstLogin.notNull()) { writer.String("FirstLogin"); writeDatetime(FirstLogin, writer); }
    if (isBanned.notNull()) { writer.String("isBanned"); writer.Bool(isBanned); }

    writer.EndObject();
}

bool UserTitleInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
    if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readUserOriginationFromValue(Origination_member->value);
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
    if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
    const Value::ConstMemberIterator FirstLogin_member = obj.FindMember("FirstLogin");
    if (FirstLogin_member != obj.MemberEnd() && !FirstLogin_member->value.IsNull()) FirstLogin = readDatetime(FirstLogin_member->value);
    const Value::ConstMemberIterator isBanned_member = obj.FindMember("isBanned");
    if (isBanned_member != obj.MemberEnd() && !isBanned_member->value.IsNull()) isBanned = isBanned_member->value.GetBool();

    return true;
}

UserPrivateAccountInfo::~UserPrivateAccountInfo()
{

}

void UserPrivateAccountInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }

    writer.EndObject();
}

bool UserPrivateAccountInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
    if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

    return true;
}

UserFacebookInfo::~UserFacebookInfo()
{

}

void UserFacebookInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (FacebookId.length() > 0) { writer.String("FacebookId"); writer.String(FacebookId.c_str()); }
    if (FullName.length() > 0) { writer.String("FullName"); writer.String(FullName.c_str()); }

    writer.EndObject();
}

bool UserFacebookInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
    if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
    const Value::ConstMemberIterator FullName_member = obj.FindMember("FullName");
    if (FullName_member != obj.MemberEnd() && !FullName_member->value.IsNull()) FullName = FullName_member->value.GetString();

    return true;
}
void PlayFab::AdminModels::writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case TitleActivationStatusNone: writer.String("None"); break;
    case TitleActivationStatusActivatedTitleKey: writer.String("ActivatedTitleKey"); break;
    case TitleActivationStatusPendingSteam: writer.String("PendingSteam"); break;
    case TitleActivationStatusActivatedSteam: writer.String("ActivatedSteam"); break;
    case TitleActivationStatusRevokedSteam: writer.String("RevokedSteam"); break;

    }
}

TitleActivationStatus PlayFab::AdminModels::readTitleActivationStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, TitleActivationStatus> _TitleActivationStatusMap;
    if (_TitleActivationStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _TitleActivationStatusMap["None"] = TitleActivationStatusNone;
        _TitleActivationStatusMap["ActivatedTitleKey"] = TitleActivationStatusActivatedTitleKey;
        _TitleActivationStatusMap["PendingSteam"] = TitleActivationStatusPendingSteam;
        _TitleActivationStatusMap["ActivatedSteam"] = TitleActivationStatusActivatedSteam;
        _TitleActivationStatusMap["RevokedSteam"] = TitleActivationStatusRevokedSteam;

    }

    auto output = _TitleActivationStatusMap.find(obj.GetString());
    if (output != _TitleActivationStatusMap.end())
        return output->second;

    return TitleActivationStatusNone; // Basically critical fail
}

UserSteamInfo::~UserSteamInfo()
{

}

void UserSteamInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
    if (SteamCountry.length() > 0) { writer.String("SteamCountry"); writer.String(SteamCountry.c_str()); }
    if (SteamCurrency.notNull()) { writer.String("SteamCurrency"); writeCurrencyEnumJSON(SteamCurrency, writer); }
    if (SteamActivationStatus.notNull()) { writer.String("SteamActivationStatus"); writeTitleActivationStatusEnumJSON(SteamActivationStatus, writer); }

    writer.EndObject();
}

bool UserSteamInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
    if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();
    const Value::ConstMemberIterator SteamCountry_member = obj.FindMember("SteamCountry");
    if (SteamCountry_member != obj.MemberEnd() && !SteamCountry_member->value.IsNull()) SteamCountry = SteamCountry_member->value.GetString();
    const Value::ConstMemberIterator SteamCurrency_member = obj.FindMember("SteamCurrency");
    if (SteamCurrency_member != obj.MemberEnd() && !SteamCurrency_member->value.IsNull()) SteamCurrency = readCurrencyFromValue(SteamCurrency_member->value);
    const Value::ConstMemberIterator SteamActivationStatus_member = obj.FindMember("SteamActivationStatus");
    if (SteamActivationStatus_member != obj.MemberEnd() && !SteamActivationStatus_member->value.IsNull()) SteamActivationStatus = readTitleActivationStatusFromValue(SteamActivationStatus_member->value);

    return true;
}

UserGameCenterInfo::~UserGameCenterInfo()
{

}

void UserGameCenterInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (GameCenterId.length() > 0) { writer.String("GameCenterId"); writer.String(GameCenterId.c_str()); }

    writer.EndObject();
}

bool UserGameCenterInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
    if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();

    return true;
}

UserIosDeviceInfo::~UserIosDeviceInfo()
{

}

void UserIosDeviceInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (IosDeviceId.length() > 0) { writer.String("IosDeviceId"); writer.String(IosDeviceId.c_str()); }

    writer.EndObject();
}

bool UserIosDeviceInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IosDeviceId_member = obj.FindMember("IosDeviceId");
    if (IosDeviceId_member != obj.MemberEnd() && !IosDeviceId_member->value.IsNull()) IosDeviceId = IosDeviceId_member->value.GetString();

    return true;
}

UserAndroidDeviceInfo::~UserAndroidDeviceInfo()
{

}

void UserAndroidDeviceInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (AndroidDeviceId.length() > 0) { writer.String("AndroidDeviceId"); writer.String(AndroidDeviceId.c_str()); }

    writer.EndObject();
}

bool UserAndroidDeviceInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
    if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();

    return true;
}

UserKongregateInfo::~UserKongregateInfo()
{

}

void UserKongregateInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (KongregateId.length() > 0) { writer.String("KongregateId"); writer.String(KongregateId.c_str()); }
    if (KongregateName.length() > 0) { writer.String("KongregateName"); writer.String(KongregateName.c_str()); }

    writer.EndObject();
}

bool UserKongregateInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
    if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
    const Value::ConstMemberIterator KongregateName_member = obj.FindMember("KongregateName");
    if (KongregateName_member != obj.MemberEnd() && !KongregateName_member->value.IsNull()) KongregateName = KongregateName_member->value.GetString();

    return true;
}

UserTwitchInfo::~UserTwitchInfo()
{

}

void UserTwitchInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (TwitchId.length() > 0) { writer.String("TwitchId"); writer.String(TwitchId.c_str()); }
    if (TwitchUserName.length() > 0) { writer.String("TwitchUserName"); writer.String(TwitchUserName.c_str()); }

    writer.EndObject();
}

bool UserTwitchInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator TwitchId_member = obj.FindMember("TwitchId");
    if (TwitchId_member != obj.MemberEnd() && !TwitchId_member->value.IsNull()) TwitchId = TwitchId_member->value.GetString();
    const Value::ConstMemberIterator TwitchUserName_member = obj.FindMember("TwitchUserName");
    if (TwitchUserName_member != obj.MemberEnd() && !TwitchUserName_member->value.IsNull()) TwitchUserName = TwitchUserName_member->value.GetString();

    return true;
}

UserPsnInfo::~UserPsnInfo()
{

}

void UserPsnInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PsnAccountId.length() > 0) { writer.String("PsnAccountId"); writer.String(PsnAccountId.c_str()); }
    if (PsnOnlineId.length() > 0) { writer.String("PsnOnlineId"); writer.String(PsnOnlineId.c_str()); }

    writer.EndObject();
}

bool UserPsnInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PsnAccountId_member = obj.FindMember("PsnAccountId");
    if (PsnAccountId_member != obj.MemberEnd() && !PsnAccountId_member->value.IsNull()) PsnAccountId = PsnAccountId_member->value.GetString();
    const Value::ConstMemberIterator PsnOnlineId_member = obj.FindMember("PsnOnlineId");
    if (PsnOnlineId_member != obj.MemberEnd() && !PsnOnlineId_member->value.IsNull()) PsnOnlineId = PsnOnlineId_member->value.GetString();

    return true;
}

UserGoogleInfo::~UserGoogleInfo()
{

}

void UserGoogleInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (GoogleId.length() > 0) { writer.String("GoogleId"); writer.String(GoogleId.c_str()); }
    if (GoogleEmail.length() > 0) { writer.String("GoogleEmail"); writer.String(GoogleEmail.c_str()); }
    if (GoogleLocale.length() > 0) { writer.String("GoogleLocale"); writer.String(GoogleLocale.c_str()); }
    if (GoogleGender.length() > 0) { writer.String("GoogleGender"); writer.String(GoogleGender.c_str()); }

    writer.EndObject();
}

bool UserGoogleInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GoogleId_member = obj.FindMember("GoogleId");
    if (GoogleId_member != obj.MemberEnd() && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
    const Value::ConstMemberIterator GoogleEmail_member = obj.FindMember("GoogleEmail");
    if (GoogleEmail_member != obj.MemberEnd() && !GoogleEmail_member->value.IsNull()) GoogleEmail = GoogleEmail_member->value.GetString();
    const Value::ConstMemberIterator GoogleLocale_member = obj.FindMember("GoogleLocale");
    if (GoogleLocale_member != obj.MemberEnd() && !GoogleLocale_member->value.IsNull()) GoogleLocale = GoogleLocale_member->value.GetString();
    const Value::ConstMemberIterator GoogleGender_member = obj.FindMember("GoogleGender");
    if (GoogleGender_member != obj.MemberEnd() && !GoogleGender_member->value.IsNull()) GoogleGender = GoogleGender_member->value.GetString();

    return true;
}

UserXboxInfo::~UserXboxInfo()
{

}

void UserXboxInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (XboxUserId.length() > 0) { writer.String("XboxUserId"); writer.String(XboxUserId.c_str()); }

    writer.EndObject();
}

bool UserXboxInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator XboxUserId_member = obj.FindMember("XboxUserId");
    if (XboxUserId_member != obj.MemberEnd() && !XboxUserId_member->value.IsNull()) XboxUserId = XboxUserId_member->value.GetString();

    return true;
}

UserCustomIdInfo::~UserCustomIdInfo()
{

}

void UserCustomIdInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CustomId.length() > 0) { writer.String("CustomId"); writer.String(CustomId.c_str()); }

    writer.EndObject();
}

bool UserCustomIdInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
    if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

    return true;
}

UserAccountInfo::~UserAccountInfo()
{
    if (TitleInfo != NULL) delete TitleInfo;
    if (PrivateInfo != NULL) delete PrivateInfo;
    if (FacebookInfo != NULL) delete FacebookInfo;
    if (SteamInfo != NULL) delete SteamInfo;
    if (GameCenterInfo != NULL) delete GameCenterInfo;
    if (IosDeviceInfo != NULL) delete IosDeviceInfo;
    if (AndroidDeviceInfo != NULL) delete AndroidDeviceInfo;
    if (KongregateInfo != NULL) delete KongregateInfo;
    if (TwitchInfo != NULL) delete TwitchInfo;
    if (PsnInfo != NULL) delete PsnInfo;
    if (GoogleInfo != NULL) delete GoogleInfo;
    if (XboxInfo != NULL) delete XboxInfo;
    if (CustomIdInfo != NULL) delete CustomIdInfo;

}

void UserAccountInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.String("Created"); writeDatetime(Created, writer);
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (TitleInfo != NULL) { writer.String("TitleInfo"); TitleInfo->writeJSON(writer); }
    if (PrivateInfo != NULL) { writer.String("PrivateInfo"); PrivateInfo->writeJSON(writer); }
    if (FacebookInfo != NULL) { writer.String("FacebookInfo"); FacebookInfo->writeJSON(writer); }
    if (SteamInfo != NULL) { writer.String("SteamInfo"); SteamInfo->writeJSON(writer); }
    if (GameCenterInfo != NULL) { writer.String("GameCenterInfo"); GameCenterInfo->writeJSON(writer); }
    if (IosDeviceInfo != NULL) { writer.String("IosDeviceInfo"); IosDeviceInfo->writeJSON(writer); }
    if (AndroidDeviceInfo != NULL) { writer.String("AndroidDeviceInfo"); AndroidDeviceInfo->writeJSON(writer); }
    if (KongregateInfo != NULL) { writer.String("KongregateInfo"); KongregateInfo->writeJSON(writer); }
    if (TwitchInfo != NULL) { writer.String("TwitchInfo"); TwitchInfo->writeJSON(writer); }
    if (PsnInfo != NULL) { writer.String("PsnInfo"); PsnInfo->writeJSON(writer); }
    if (GoogleInfo != NULL) { writer.String("GoogleInfo"); GoogleInfo->writeJSON(writer); }
    if (XboxInfo != NULL) { writer.String("XboxInfo"); XboxInfo->writeJSON(writer); }
    if (CustomIdInfo != NULL) { writer.String("CustomIdInfo"); CustomIdInfo->writeJSON(writer); }

    writer.EndObject();
}

bool UserAccountInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator TitleInfo_member = obj.FindMember("TitleInfo");
    if (TitleInfo_member != obj.MemberEnd() && !TitleInfo_member->value.IsNull()) TitleInfo = new UserTitleInfo(TitleInfo_member->value);
    const Value::ConstMemberIterator PrivateInfo_member = obj.FindMember("PrivateInfo");
    if (PrivateInfo_member != obj.MemberEnd() && !PrivateInfo_member->value.IsNull()) PrivateInfo = new UserPrivateAccountInfo(PrivateInfo_member->value);
    const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
    if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
    const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
    if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
    const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
    if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
    const Value::ConstMemberIterator IosDeviceInfo_member = obj.FindMember("IosDeviceInfo");
    if (IosDeviceInfo_member != obj.MemberEnd() && !IosDeviceInfo_member->value.IsNull()) IosDeviceInfo = new UserIosDeviceInfo(IosDeviceInfo_member->value);
    const Value::ConstMemberIterator AndroidDeviceInfo_member = obj.FindMember("AndroidDeviceInfo");
    if (AndroidDeviceInfo_member != obj.MemberEnd() && !AndroidDeviceInfo_member->value.IsNull()) AndroidDeviceInfo = new UserAndroidDeviceInfo(AndroidDeviceInfo_member->value);
    const Value::ConstMemberIterator KongregateInfo_member = obj.FindMember("KongregateInfo");
    if (KongregateInfo_member != obj.MemberEnd() && !KongregateInfo_member->value.IsNull()) KongregateInfo = new UserKongregateInfo(KongregateInfo_member->value);
    const Value::ConstMemberIterator TwitchInfo_member = obj.FindMember("TwitchInfo");
    if (TwitchInfo_member != obj.MemberEnd() && !TwitchInfo_member->value.IsNull()) TwitchInfo = new UserTwitchInfo(TwitchInfo_member->value);
    const Value::ConstMemberIterator PsnInfo_member = obj.FindMember("PsnInfo");
    if (PsnInfo_member != obj.MemberEnd() && !PsnInfo_member->value.IsNull()) PsnInfo = new UserPsnInfo(PsnInfo_member->value);
    const Value::ConstMemberIterator GoogleInfo_member = obj.FindMember("GoogleInfo");
    if (GoogleInfo_member != obj.MemberEnd() && !GoogleInfo_member->value.IsNull()) GoogleInfo = new UserGoogleInfo(GoogleInfo_member->value);
    const Value::ConstMemberIterator XboxInfo_member = obj.FindMember("XboxInfo");
    if (XboxInfo_member != obj.MemberEnd() && !XboxInfo_member->value.IsNull()) XboxInfo = new UserXboxInfo(XboxInfo_member->value);
    const Value::ConstMemberIterator CustomIdInfo_member = obj.FindMember("CustomIdInfo");
    if (CustomIdInfo_member != obj.MemberEnd() && !CustomIdInfo_member->value.IsNull()) CustomIdInfo = new UserCustomIdInfo(CustomIdInfo_member->value);

    return true;
}

LookupUserAccountInfoResult::~LookupUserAccountInfoResult()
{
    if (UserInfo != NULL) delete UserInfo;

}

void LookupUserAccountInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }

    writer.EndObject();
}

bool LookupUserAccountInfoResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
    if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

    return true;
}

ModifyMatchmakerGameModesRequest::~ModifyMatchmakerGameModesRequest()
{

}

void ModifyMatchmakerGameModesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildVersion"); writer.String(BuildVersion.c_str());
    writer.String("GameModes");
    writer.StartArray();
    for (std::list<GameModeInfo>::iterator iter = GameModes.begin(); iter != GameModes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool ModifyMatchmakerGameModesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
    if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    const Value::ConstMemberIterator GameModes_member = obj.FindMember("GameModes");
    if (GameModes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameModes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameModes.push_back(GameModeInfo(memberList[i]));
        }
    }

    return true;
}

ModifyMatchmakerGameModesResult::~ModifyMatchmakerGameModesResult()
{

}

void ModifyMatchmakerGameModesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool ModifyMatchmakerGameModesResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

ModifyServerBuildRequest::~ModifyServerBuildRequest()
{

}

void ModifyServerBuildRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildId"); writer.String(BuildId.c_str());
    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
    if (CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
    if (ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }

    writer.EndObject();
}

bool ModifyServerBuildRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
    const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
    if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
    if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
    const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
    if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
    const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
    if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
    const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
    if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();

    return true;
}

ModifyServerBuildResult::~ModifyServerBuildResult()
{

}

void ModifyServerBuildResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    if (!ActiveRegions.empty()) {
    writer.String("ActiveRegions");
    writer.StartArray();
    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
        writeRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
     }
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    writer.String("MinFreeGameSlots"); writer.Int(MinFreeGameSlots);
    if (CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
    if (ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    writer.String("Timestamp"); writeDatetime(Timestamp, writer);
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    if (Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }

    writer.EndObject();
}

bool ModifyServerBuildResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
    if (ActiveRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActiveRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActiveRegions.push_back(readRegionFromValue(memberList[i]));
        }
    }
    const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
    if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
    if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
    const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
    if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
    const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
    if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
    const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
    if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
    if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);

    return true;
}

ModifyUserVirtualCurrencyResult::~ModifyUserVirtualCurrencyResult()
{

}

void ModifyUserVirtualCurrencyResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
    writer.String("BalanceChange"); writer.Int(BalanceChange);
    writer.String("Balance"); writer.Int(Balance);

    writer.EndObject();
}

bool ModifyUserVirtualCurrencyResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::ConstMemberIterator BalanceChange_member = obj.FindMember("BalanceChange");
    if (BalanceChange_member != obj.MemberEnd() && !BalanceChange_member->value.IsNull()) BalanceChange = BalanceChange_member->value.GetInt();
    const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
    if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();

    return true;
}

RandomResultTable::~RandomResultTable()
{

}

void RandomResultTable::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TableId"); writer.String(TableId.c_str());
    writer.String("Nodes");
    writer.StartArray();
    for (std::list<ResultTableNode>::iterator iter = Nodes.begin(); iter != Nodes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool RandomResultTable::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
    if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
    const Value::ConstMemberIterator Nodes_member = obj.FindMember("Nodes");
    if (Nodes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Nodes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Nodes.push_back(ResultTableNode(memberList[i]));
        }
    }

    return true;
}

RemovePlayerTagRequest::~RemovePlayerTagRequest()
{

}

void RemovePlayerTagRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("TagName"); writer.String(TagName.c_str());

    writer.EndObject();
}

bool RemovePlayerTagRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator TagName_member = obj.FindMember("TagName");
    if (TagName_member != obj.MemberEnd() && !TagName_member->value.IsNull()) TagName = TagName_member->value.GetString();

    return true;
}

RemovePlayerTagResult::~RemovePlayerTagResult()
{

}

void RemovePlayerTagResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool RemovePlayerTagResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

RemoveServerBuildRequest::~RemoveServerBuildRequest()
{

}

void RemoveServerBuildRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildId"); writer.String(BuildId.c_str());

    writer.EndObject();
}

bool RemoveServerBuildRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

    return true;
}

RemoveServerBuildResult::~RemoveServerBuildResult()
{

}

void RemoveServerBuildResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool RemoveServerBuildResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

RemoveVirtualCurrencyTypesRequest::~RemoveVirtualCurrencyTypesRequest()
{

}

void RemoveVirtualCurrencyTypesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("VirtualCurrencies");
    writer.StartArray();
    for (std::list<VirtualCurrencyData>::iterator iter = VirtualCurrencies.begin(); iter != VirtualCurrencies.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool RemoveVirtualCurrencyTypesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
    if (VirtualCurrencies_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = VirtualCurrencies_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
        }
    }

    return true;
}

ResetCharacterStatisticsRequest::~ResetCharacterStatisticsRequest()
{

}

void ResetCharacterStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());

    writer.EndObject();
}

bool ResetCharacterStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

    return true;
}

ResetCharacterStatisticsResult::~ResetCharacterStatisticsResult()
{

}

void ResetCharacterStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool ResetCharacterStatisticsResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UserCredentials::~UserCredentials()
{

}

void UserCredentials::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Username"); writer.String(Username.c_str());
    writer.String("Password"); writer.String(Password.c_str());

    writer.EndObject();
}

bool UserCredentials::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
    if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

    return true;
}

ResetUsersRequest::~ResetUsersRequest()
{

}

void ResetUsersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Users");
    writer.StartArray();
    for (std::list<UserCredentials>::iterator iter = Users.begin(); iter != Users.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool ResetUsersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Users_member = obj.FindMember("Users");
    if (Users_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Users_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Users.push_back(UserCredentials(memberList[i]));
        }
    }

    return true;
}

ResetUserStatisticsRequest::~ResetUserStatisticsRequest()
{

}

void ResetUserStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool ResetUserStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

ResetUserStatisticsResult::~ResetUserStatisticsResult()
{

}

void ResetUserStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool ResetUserStatisticsResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

RevokeAllBansForUserRequest::~RevokeAllBansForUserRequest()
{

}

void RevokeAllBansForUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool RevokeAllBansForUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

RevokeAllBansForUserResult::~RevokeAllBansForUserResult()
{

}

void RevokeAllBansForUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool RevokeAllBansForUserResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

    return true;
}

RevokeBansRequest::~RevokeBansRequest()
{

}

void RevokeBansRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BanIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = BanIds.begin(); iter != BanIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool RevokeBansRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BanIds_member = obj.FindMember("BanIds");
    if (BanIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

RevokeBansResult::~RevokeBansResult()
{

}

void RevokeBansResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool RevokeBansResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

    return true;
}

RevokeInventoryItemRequest::~RevokeInventoryItemRequest()
{

}

void RevokeInventoryItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());

    writer.EndObject();
}

bool RevokeInventoryItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

    return true;
}

RevokeInventoryResult::~RevokeInventoryResult()
{

}

void RevokeInventoryResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool RevokeInventoryResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SendAccountRecoveryEmailRequest::~SendAccountRecoveryEmailRequest()
{

}

void SendAccountRecoveryEmailRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Email"); writer.String(Email.c_str());

    writer.EndObject();
}

bool SendAccountRecoveryEmailRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
    if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

    return true;
}

SendAccountRecoveryEmailResult::~SendAccountRecoveryEmailResult()
{

}

void SendAccountRecoveryEmailResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SendAccountRecoveryEmailResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SetPublishedRevisionRequest::~SetPublishedRevisionRequest()
{

}

void SetPublishedRevisionRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Version"); writer.Int(Version);
    writer.String("Revision"); writer.Int(Revision);

    writer.EndObject();
}

bool SetPublishedRevisionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
    if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

    return true;
}

SetPublishedRevisionResult::~SetPublishedRevisionResult()
{

}

void SetPublishedRevisionResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SetPublishedRevisionResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SetPublisherDataRequest::~SetPublisherDataRequest()
{

}

void SetPublisherDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Key"); writer.String(Key.c_str());
    if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }

    writer.EndObject();
}

bool SetPublisherDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

    return true;
}

SetPublisherDataResult::~SetPublisherDataResult()
{

}

void SetPublisherDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SetPublisherDataResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SetTitleDataRequest::~SetTitleDataRequest()
{

}

void SetTitleDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Key"); writer.String(Key.c_str());
    if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }

    writer.EndObject();
}

bool SetTitleDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

    return true;
}

SetTitleDataResult::~SetTitleDataResult()
{

}

void SetTitleDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SetTitleDataResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SetupPushNotificationRequest::~SetupPushNotificationRequest()
{

}

void SetupPushNotificationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Name"); writer.String(Name.c_str());
    writer.String("Platform"); writer.String(Platform.c_str());
    if (Key.length() > 0) { writer.String("Key"); writer.String(Key.c_str()); }
    writer.String("Credential"); writer.String(Credential.c_str());
    writer.String("OverwriteOldARN"); writer.Bool(OverwriteOldARN);

    writer.EndObject();
}

bool SetupPushNotificationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::ConstMemberIterator Credential_member = obj.FindMember("Credential");
    if (Credential_member != obj.MemberEnd() && !Credential_member->value.IsNull()) Credential = Credential_member->value.GetString();
    const Value::ConstMemberIterator OverwriteOldARN_member = obj.FindMember("OverwriteOldARN");
    if (OverwriteOldARN_member != obj.MemberEnd() && !OverwriteOldARN_member->value.IsNull()) OverwriteOldARN = OverwriteOldARN_member->value.GetBool();

    return true;
}

SetupPushNotificationResult::~SetupPushNotificationResult()
{

}

void SetupPushNotificationResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (ARN.length() > 0) { writer.String("ARN"); writer.String(ARN.c_str()); }

    writer.EndObject();
}

bool SetupPushNotificationResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ARN_member = obj.FindMember("ARN");
    if (ARN_member != obj.MemberEnd() && !ARN_member->value.IsNull()) ARN = ARN_member->value.GetString();

    return true;
}

SubtractUserVirtualCurrencyRequest::~SubtractUserVirtualCurrencyRequest()
{

}

void SubtractUserVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.String("Amount"); writer.Int(Amount);

    writer.EndObject();
}

bool SubtractUserVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
    if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

    return true;
}

UpdateBanRequest::~UpdateBanRequest()
{

}

void UpdateBanRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BanId"); writer.String(BanId.c_str());
    if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
    if (Expires.notNull()) { writer.String("Expires"); writeDatetime(Expires, writer); }
    if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
    if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
    if (Permanent.notNull()) { writer.String("Permanent"); writer.Bool(Permanent); }
    if (Active.notNull()) { writer.String("Active"); writer.Bool(Active); }

    writer.EndObject();
}

bool UpdateBanRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BanId_member = obj.FindMember("BanId");
    if (BanId_member != obj.MemberEnd() && !BanId_member->value.IsNull()) BanId = BanId_member->value.GetString();
    const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
    if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
    const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
    if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
    const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
    if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
    const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
    if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
    const Value::ConstMemberIterator Permanent_member = obj.FindMember("Permanent");
    if (Permanent_member != obj.MemberEnd() && !Permanent_member->value.IsNull()) Permanent = Permanent_member->value.GetBool();
    const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
    if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();

    return true;
}

UpdateBansRequest::~UpdateBansRequest()
{

}

void UpdateBansRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Bans");
    writer.StartArray();
    for (std::list<UpdateBanRequest>::iterator iter = Bans.begin(); iter != Bans.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool UpdateBansRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Bans_member = obj.FindMember("Bans");
    if (Bans_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Bans_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Bans.push_back(UpdateBanRequest(memberList[i]));
        }
    }

    return true;
}

UpdateBansResult::~UpdateBansResult()
{

}

void UpdateBansResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!BanData.empty()) {
    writer.String("BanData");
    writer.StartArray();
    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool UpdateBansResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
    if (BanData_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BanData_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BanData.push_back(BanInfo(memberList[i]));
        }
    }

    return true;
}

UpdateCatalogItemsRequest::~UpdateCatalogItemsRequest()
{

}

void UpdateCatalogItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (SetAsDefaultCatalog.notNull()) { writer.String("SetAsDefaultCatalog"); writer.Bool(SetAsDefaultCatalog); }
    if (!Catalog.empty()) {
    writer.String("Catalog");
    writer.StartArray();
    for (std::list<CatalogItem>::iterator iter = Catalog.begin(); iter != Catalog.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool UpdateCatalogItemsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator SetAsDefaultCatalog_member = obj.FindMember("SetAsDefaultCatalog");
    if (SetAsDefaultCatalog_member != obj.MemberEnd() && !SetAsDefaultCatalog_member->value.IsNull()) SetAsDefaultCatalog = SetAsDefaultCatalog_member->value.GetBool();
    const Value::ConstMemberIterator Catalog_member = obj.FindMember("Catalog");
    if (Catalog_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Catalog_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Catalog.push_back(CatalogItem(memberList[i]));
        }
    }

    return true;
}

UpdateCatalogItemsResult::~UpdateCatalogItemsResult()
{

}

void UpdateCatalogItemsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UpdateCatalogItemsResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UpdateCloudScriptRequest::~UpdateCloudScriptRequest()
{

}

void UpdateCloudScriptRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
    writer.String("Files");
    writer.StartArray();
    for (std::list<CloudScriptFile>::iterator iter = Files.begin(); iter != Files.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    
    writer.String("Publish"); writer.Bool(Publish);
    if (DeveloperPlayFabId.length() > 0) { writer.String("DeveloperPlayFabId"); writer.String(DeveloperPlayFabId.c_str()); }

    writer.EndObject();
}

bool UpdateCloudScriptRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
    if (Files_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Files_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Files.push_back(CloudScriptFile(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Publish_member = obj.FindMember("Publish");
    if (Publish_member != obj.MemberEnd() && !Publish_member->value.IsNull()) Publish = Publish_member->value.GetBool();
    const Value::ConstMemberIterator DeveloperPlayFabId_member = obj.FindMember("DeveloperPlayFabId");
    if (DeveloperPlayFabId_member != obj.MemberEnd() && !DeveloperPlayFabId_member->value.IsNull()) DeveloperPlayFabId = DeveloperPlayFabId_member->value.GetString();

    return true;
}

UpdateCloudScriptResult::~UpdateCloudScriptResult()
{

}

void UpdateCloudScriptResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Version"); writer.Int(Version);
    writer.String("Revision"); writer.Int(Revision);

    writer.EndObject();
}

bool UpdateCloudScriptResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
    if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

    return true;
}

UpdatePlayerStatisticDefinitionRequest::~UpdatePlayerStatisticDefinitionRequest()
{

}

void UpdatePlayerStatisticDefinitionRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    if (VersionChangeInterval.notNull()) { writer.String("VersionChangeInterval"); writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer); }
    if (AggregationMethod.notNull()) { writer.String("AggregationMethod"); writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer); }

    writer.EndObject();
}

bool UpdatePlayerStatisticDefinitionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
    if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
    const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
    if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

    return true;
}

UpdatePlayerStatisticDefinitionResult::~UpdatePlayerStatisticDefinitionResult()
{
    if (Statistic != NULL) delete Statistic;

}

void UpdatePlayerStatisticDefinitionResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Statistic != NULL) { writer.String("Statistic"); Statistic->writeJSON(writer); }

    writer.EndObject();
}

bool UpdatePlayerStatisticDefinitionResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Statistic_member = obj.FindMember("Statistic");
    if (Statistic_member != obj.MemberEnd() && !Statistic_member->value.IsNull()) Statistic = new PlayerStatisticDefinition(Statistic_member->value);

    return true;
}

UpdateRandomResultTablesRequest::~UpdateRandomResultTablesRequest()
{

}

void UpdateRandomResultTablesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (!Tables.empty()) {
    writer.String("Tables");
    writer.StartArray();
    for (std::list<RandomResultTable>::iterator iter = Tables.begin(); iter != Tables.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool UpdateRandomResultTablesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator Tables_member = obj.FindMember("Tables");
    if (Tables_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tables_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tables.push_back(RandomResultTable(memberList[i]));
        }
    }

    return true;
}

UpdateRandomResultTablesResult::~UpdateRandomResultTablesResult()
{

}

void UpdateRandomResultTablesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UpdateRandomResultTablesResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UpdateStoreItemsRequest::~UpdateStoreItemsRequest()
{

}

void UpdateStoreItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("StoreId"); writer.String(StoreId.c_str());
    if (!Store.empty()) {
    writer.String("Store");
    writer.StartArray();
    for (std::list<StoreItem>::iterator iter = Store.begin(); iter != Store.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool UpdateStoreItemsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
    if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
    const Value::ConstMemberIterator Store_member = obj.FindMember("Store");
    if (Store_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Store_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Store.push_back(StoreItem(memberList[i]));
        }
    }

    return true;
}

UpdateStoreItemsResult::~UpdateStoreItemsResult()
{

}

void UpdateStoreItemsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UpdateStoreItemsResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UpdateUserDataRequest::~UpdateUserDataRequest()
{

}

void UpdateUserDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
    if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }

    writer.EndObject();
}

bool UpdateUserDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
    if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

    return true;
}

UpdateUserDataResult::~UpdateUserDataResult()
{

}

void UpdateUserDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("DataVersion"); writer.Uint(DataVersion);

    writer.EndObject();
}

bool UpdateUserDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

    return true;
}

UpdateUserInternalDataRequest::~UpdateUserInternalDataRequest()
{

}

void UpdateUserInternalDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
    if (!KeysToRemove.empty()) {
    writer.String("KeysToRemove");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool UpdateUserInternalDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }

    return true;
}

UpdateUserTitleDisplayNameRequest::~UpdateUserTitleDisplayNameRequest()
{

}

void UpdateUserTitleDisplayNameRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("DisplayName"); writer.String(DisplayName.c_str());

    writer.EndObject();
}

bool UpdateUserTitleDisplayNameRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

    return true;
}

UpdateUserTitleDisplayNameResult::~UpdateUserTitleDisplayNameResult()
{

}

void UpdateUserTitleDisplayNameResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }

    writer.EndObject();
}

bool UpdateUserTitleDisplayNameResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

    return true;
}

