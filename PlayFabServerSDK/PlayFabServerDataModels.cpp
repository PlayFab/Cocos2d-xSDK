#include "PlayFabServerDataModels.h"

using namespace PlayFab;
using namespace PlayFab::ServerModels;
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

AddCharacterVirtualCurrencyRequest::~AddCharacterVirtualCurrencyRequest()
{

}

void AddCharacterVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.String("Amount"); writer.Int(Amount);

    writer.EndObject();
}

bool AddCharacterVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
    if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

    return true;
}

AddFriendRequest::~AddFriendRequest()
{

}

void AddFriendRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (FriendPlayFabId.length() > 0) { writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str()); }
    if (FriendUsername.length() > 0) { writer.String("FriendUsername"); writer.String(FriendUsername.c_str()); }
    if (FriendEmail.length() > 0) { writer.String("FriendEmail"); writer.String(FriendEmail.c_str()); }
    if (FriendTitleDisplayName.length() > 0) { writer.String("FriendTitleDisplayName"); writer.String(FriendTitleDisplayName.c_str()); }

    writer.EndObject();
}

bool AddFriendRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::ConstMemberIterator FriendUsername_member = obj.FindMember("FriendUsername");
    if (FriendUsername_member != obj.MemberEnd() && !FriendUsername_member->value.IsNull()) FriendUsername = FriendUsername_member->value.GetString();
    const Value::ConstMemberIterator FriendEmail_member = obj.FindMember("FriendEmail");
    if (FriendEmail_member != obj.MemberEnd() && !FriendEmail_member->value.IsNull()) FriendEmail = FriendEmail_member->value.GetString();
    const Value::ConstMemberIterator FriendTitleDisplayName_member = obj.FindMember("FriendTitleDisplayName");
    if (FriendTitleDisplayName_member != obj.MemberEnd() && !FriendTitleDisplayName_member->value.IsNull()) FriendTitleDisplayName = FriendTitleDisplayName_member->value.GetString();

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

AddSharedGroupMembersRequest::~AddSharedGroupMembersRequest()
{

}

void AddSharedGroupMembersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
    if (!PlayFabIds.empty()) {
    writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool AddSharedGroupMembersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

AddSharedGroupMembersResult::~AddSharedGroupMembersResult()
{

}

void AddSharedGroupMembersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool AddSharedGroupMembersResult::readFromValue(const rapidjson::Value& obj)
{

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

AuthenticateSessionTicketRequest::~AuthenticateSessionTicketRequest()
{

}

void AuthenticateSessionTicketRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SessionTicket"); writer.String(SessionTicket.c_str());

    writer.EndObject();
}

bool AuthenticateSessionTicketRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SessionTicket_member = obj.FindMember("SessionTicket");
    if (SessionTicket_member != obj.MemberEnd() && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();

    return true;
}
void PlayFab::ServerModels::writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
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

UserOrigination PlayFab::ServerModels::readUserOriginationFromValue(const rapidjson::Value& obj)
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
void PlayFab::ServerModels::writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
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

Currency PlayFab::ServerModels::readCurrencyFromValue(const rapidjson::Value& obj)
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
void PlayFab::ServerModels::writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
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

TitleActivationStatus PlayFab::ServerModels::readTitleActivationStatusFromValue(const rapidjson::Value& obj)
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

AuthenticateSessionTicketResult::~AuthenticateSessionTicketResult()
{
    if (UserInfo != NULL) delete UserInfo;

}

void AuthenticateSessionTicketResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }

    writer.EndObject();
}

bool AuthenticateSessionTicketResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
    if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

    return true;
}

AwardSteamAchievementItem::~AwardSteamAchievementItem()
{

}

void AwardSteamAchievementItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("AchievementName"); writer.String(AchievementName.c_str());
    writer.String("Result"); writer.Bool(Result);

    writer.EndObject();
}

bool AwardSteamAchievementItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator AchievementName_member = obj.FindMember("AchievementName");
    if (AchievementName_member != obj.MemberEnd() && !AchievementName_member->value.IsNull()) AchievementName = AchievementName_member->value.GetString();
    const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
    if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();

    return true;
}

AwardSteamAchievementRequest::~AwardSteamAchievementRequest()
{

}

void AwardSteamAchievementRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Achievements");
    writer.StartArray();
    for (std::list<AwardSteamAchievementItem>::iterator iter = Achievements.begin(); iter != Achievements.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool AwardSteamAchievementRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Achievements_member = obj.FindMember("Achievements");
    if (Achievements_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Achievements_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Achievements.push_back(AwardSteamAchievementItem(memberList[i]));
        }
    }

    return true;
}

AwardSteamAchievementResult::~AwardSteamAchievementResult()
{

}

void AwardSteamAchievementResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!AchievementResults.empty()) {
    writer.String("AchievementResults");
    writer.StartArray();
    for (std::list<AwardSteamAchievementItem>::iterator iter = AchievementResults.begin(); iter != AchievementResults.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool AwardSteamAchievementResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AchievementResults_member = obj.FindMember("AchievementResults");
    if (AchievementResults_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AchievementResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AchievementResults.push_back(AwardSteamAchievementItem(memberList[i]));
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
    writer.String("IsLimitedEdition"); writer.Bool(IsLimitedEdition);
    writer.String("InitialLimitedEditionCount"); writer.Int(InitialLimitedEditionCount);

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
    const Value::ConstMemberIterator IsLimitedEdition_member = obj.FindMember("IsLimitedEdition");
    if (IsLimitedEdition_member != obj.MemberEnd() && !IsLimitedEdition_member->value.IsNull()) IsLimitedEdition = IsLimitedEdition_member->value.GetBool();
    const Value::ConstMemberIterator InitialLimitedEditionCount_member = obj.FindMember("InitialLimitedEditionCount");
    if (InitialLimitedEditionCount_member != obj.MemberEnd() && !InitialLimitedEditionCount_member->value.IsNull()) InitialLimitedEditionCount = InitialLimitedEditionCount_member->value.GetInt();

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

CharacterInventory::~CharacterInventory()
{

}

void CharacterInventory::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (!Inventory.empty()) {
    writer.String("Inventory");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool CharacterInventory::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }

    return true;
}

CharacterLeaderboardEntry::~CharacterLeaderboardEntry()
{

}

void CharacterLeaderboardEntry::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (CharacterName.length() > 0) { writer.String("CharacterName"); writer.String(CharacterName.c_str()); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    writer.String("StatValue"); writer.Int(StatValue);
    writer.String("Position"); writer.Int(Position);

    writer.EndObject();
}

bool CharacterLeaderboardEntry::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
    if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();
    const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
    if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();

    return true;
}

CharacterResult::~CharacterResult()
{

}

void CharacterResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (CharacterName.length() > 0) { writer.String("CharacterName"); writer.String(CharacterName.c_str()); }
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }

    writer.EndObject();
}

bool CharacterResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();

    return true;
}
void PlayFab::ServerModels::writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case CloudScriptRevisionOptionLive: writer.String("Live"); break;
    case CloudScriptRevisionOptionLatest: writer.String("Latest"); break;
    case CloudScriptRevisionOptionSpecific: writer.String("Specific"); break;

    }
}

CloudScriptRevisionOption PlayFab::ServerModels::readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, CloudScriptRevisionOption> _CloudScriptRevisionOptionMap;
    if (_CloudScriptRevisionOptionMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _CloudScriptRevisionOptionMap["Live"] = CloudScriptRevisionOptionLive;
        _CloudScriptRevisionOptionMap["Latest"] = CloudScriptRevisionOptionLatest;
        _CloudScriptRevisionOptionMap["Specific"] = CloudScriptRevisionOptionSpecific;

    }

    auto output = _CloudScriptRevisionOptionMap.find(obj.GetString());
    if (output != _CloudScriptRevisionOptionMap.end())
        return output->second;

    return CloudScriptRevisionOptionLive; // Basically critical fail
}

ConsumeItemRequest::~ConsumeItemRequest()
{

}

void ConsumeItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("ConsumeCount"); writer.Int(ConsumeCount);
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }

    writer.EndObject();
}

bool ConsumeItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator ConsumeCount_member = obj.FindMember("ConsumeCount");
    if (ConsumeCount_member != obj.MemberEnd() && !ConsumeCount_member->value.IsNull()) ConsumeCount = ConsumeCount_member->value.GetInt();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

    return true;
}

ConsumeItemResult::~ConsumeItemResult()
{

}

void ConsumeItemResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
    writer.String("RemainingUses"); writer.Int(RemainingUses);

    writer.EndObject();
}

bool ConsumeItemResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();

    return true;
}

CreateSharedGroupRequest::~CreateSharedGroupRequest()
{

}

void CreateSharedGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }

    writer.EndObject();
}

bool CreateSharedGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

    return true;
}

CreateSharedGroupResult::~CreateSharedGroupResult()
{

}

void CreateSharedGroupResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }

    writer.EndObject();
}

bool CreateSharedGroupResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

    return true;
}

DeleteCharacterFromUserRequest::~DeleteCharacterFromUserRequest()
{

}

void DeleteCharacterFromUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("SaveCharacterInventory"); writer.Bool(SaveCharacterInventory);

    writer.EndObject();
}

bool DeleteCharacterFromUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator SaveCharacterInventory_member = obj.FindMember("SaveCharacterInventory");
    if (SaveCharacterInventory_member != obj.MemberEnd() && !SaveCharacterInventory_member->value.IsNull()) SaveCharacterInventory = SaveCharacterInventory_member->value.GetBool();

    return true;
}

DeleteCharacterFromUserResult::~DeleteCharacterFromUserResult()
{

}

void DeleteCharacterFromUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool DeleteCharacterFromUserResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

DeleteSharedGroupRequest::~DeleteSharedGroupRequest()
{

}

void DeleteSharedGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }

    writer.EndObject();
}

bool DeleteSharedGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

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

DeregisterGameRequest::~DeregisterGameRequest()
{

}

void DeregisterGameRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("LobbyId"); writer.String(LobbyId.c_str());

    writer.EndObject();
}

bool DeregisterGameRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

    return true;
}

DeregisterGameResponse::~DeregisterGameResponse()
{

}

void DeregisterGameResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool DeregisterGameResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

EmptyResult::~EmptyResult()
{

}

void EmptyResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool EmptyResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

EvaluateRandomResultTableRequest::~EvaluateRandomResultTableRequest()
{

}

void EvaluateRandomResultTableRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TableId"); writer.String(TableId.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool EvaluateRandomResultTableRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
    if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

    return true;
}

EvaluateRandomResultTableResult::~EvaluateRandomResultTableResult()
{

}

void EvaluateRandomResultTableResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (ResultItemId.length() > 0) { writer.String("ResultItemId"); writer.String(ResultItemId.c_str()); }

    writer.EndObject();
}

bool EvaluateRandomResultTableResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ResultItemId_member = obj.FindMember("ResultItemId");
    if (ResultItemId_member != obj.MemberEnd() && !ResultItemId_member->value.IsNull()) ResultItemId = ResultItemId_member->value.GetString();

    return true;
}

LogStatement::~LogStatement()
{

}

void LogStatement::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Level.length() > 0) { writer.String("Level"); writer.String(Level.c_str()); }
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    if (Data.notNull()) { writer.String("Data"); Data.writeJSON(writer); }

    writer.EndObject();
}

bool LogStatement::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Level_member = obj.FindMember("Level");
    if (Level_member != obj.MemberEnd() && !Level_member->value.IsNull()) Level = Level_member->value.GetString();
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd() && !Data_member->value.IsNull()) Data = MultitypeVar(Data_member->value);

    return true;
}

ScriptExecutionError::~ScriptExecutionError()
{

}

void ScriptExecutionError::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Error.length() > 0) { writer.String("Error"); writer.String(Error.c_str()); }
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    if (StackTrace.length() > 0) { writer.String("StackTrace"); writer.String(StackTrace.c_str()); }

    writer.EndObject();
}

bool ScriptExecutionError::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator StackTrace_member = obj.FindMember("StackTrace");
    if (StackTrace_member != obj.MemberEnd() && !StackTrace_member->value.IsNull()) StackTrace = StackTrace_member->value.GetString();

    return true;
}

ExecuteCloudScriptResult::~ExecuteCloudScriptResult()
{
    if (Error != NULL) delete Error;

}

void ExecuteCloudScriptResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (FunctionName.length() > 0) { writer.String("FunctionName"); writer.String(FunctionName.c_str()); }
    writer.String("Revision"); writer.Int(Revision);
    if (FunctionResult.notNull()) { writer.String("FunctionResult"); FunctionResult.writeJSON(writer); }
    if (!Logs.empty()) {
    writer.String("Logs");
    writer.StartArray();
    for (std::list<LogStatement>::iterator iter = Logs.begin(); iter != Logs.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    writer.String("ExecutionTimeSeconds"); writer.Double(ExecutionTimeSeconds);
    writer.String("ProcessorTimeSeconds"); writer.Double(ProcessorTimeSeconds);
    writer.String("MemoryConsumedBytes"); writer.Uint(MemoryConsumedBytes);
    writer.String("APIRequestsIssued"); writer.Int(APIRequestsIssued);
    writer.String("HttpRequestsIssued"); writer.Int(HttpRequestsIssued);
    if (Error != NULL) { writer.String("Error"); Error->writeJSON(writer); }

    writer.EndObject();
}

bool ExecuteCloudScriptResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
    if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
    const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
    if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = MultitypeVar(FunctionResult_member->value);
    const Value::ConstMemberIterator Logs_member = obj.FindMember("Logs");
    if (Logs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Logs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Logs.push_back(LogStatement(memberList[i]));
        }
    }
    const Value::ConstMemberIterator ExecutionTimeSeconds_member = obj.FindMember("ExecutionTimeSeconds");
    if (ExecutionTimeSeconds_member != obj.MemberEnd() && !ExecutionTimeSeconds_member->value.IsNull()) ExecutionTimeSeconds = ExecutionTimeSeconds_member->value.GetDouble();
    const Value::ConstMemberIterator ProcessorTimeSeconds_member = obj.FindMember("ProcessorTimeSeconds");
    if (ProcessorTimeSeconds_member != obj.MemberEnd() && !ProcessorTimeSeconds_member->value.IsNull()) ProcessorTimeSeconds = ProcessorTimeSeconds_member->value.GetDouble();
    const Value::ConstMemberIterator MemoryConsumedBytes_member = obj.FindMember("MemoryConsumedBytes");
    if (MemoryConsumedBytes_member != obj.MemberEnd() && !MemoryConsumedBytes_member->value.IsNull()) MemoryConsumedBytes = MemoryConsumedBytes_member->value.GetUint();
    const Value::ConstMemberIterator APIRequestsIssued_member = obj.FindMember("APIRequestsIssued");
    if (APIRequestsIssued_member != obj.MemberEnd() && !APIRequestsIssued_member->value.IsNull()) APIRequestsIssued = APIRequestsIssued_member->value.GetInt();
    const Value::ConstMemberIterator HttpRequestsIssued_member = obj.FindMember("HttpRequestsIssued");
    if (HttpRequestsIssued_member != obj.MemberEnd() && !HttpRequestsIssued_member->value.IsNull()) HttpRequestsIssued = HttpRequestsIssued_member->value.GetInt();
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = new ScriptExecutionError(Error_member->value);

    return true;
}

ExecuteCloudScriptServerRequest::~ExecuteCloudScriptServerRequest()
{

}

void ExecuteCloudScriptServerRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.String("FunctionName"); writer.String(FunctionName.c_str());
    if (FunctionParameter.notNull()) { writer.String("FunctionParameter"); FunctionParameter.writeJSON(writer); }
    if (RevisionSelection.notNull()) { writer.String("RevisionSelection"); writeCloudScriptRevisionOptionEnumJSON(RevisionSelection, writer); }
    if (SpecificRevision.notNull()) { writer.String("SpecificRevision"); writer.Int(SpecificRevision); }
    if (GeneratePlayStreamEvent.notNull()) { writer.String("GeneratePlayStreamEvent"); writer.Bool(GeneratePlayStreamEvent); }

    writer.EndObject();
}

bool ExecuteCloudScriptServerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionParameter_member = obj.FindMember("FunctionParameter");
    if (FunctionParameter_member != obj.MemberEnd() && !FunctionParameter_member->value.IsNull()) FunctionParameter = MultitypeVar(FunctionParameter_member->value);
    const Value::ConstMemberIterator RevisionSelection_member = obj.FindMember("RevisionSelection");
    if (RevisionSelection_member != obj.MemberEnd() && !RevisionSelection_member->value.IsNull()) RevisionSelection = readCloudScriptRevisionOptionFromValue(RevisionSelection_member->value);
    const Value::ConstMemberIterator SpecificRevision_member = obj.FindMember("SpecificRevision");
    if (SpecificRevision_member != obj.MemberEnd() && !SpecificRevision_member->value.IsNull()) SpecificRevision = SpecificRevision_member->value.GetInt();
    const Value::ConstMemberIterator GeneratePlayStreamEvent_member = obj.FindMember("GeneratePlayStreamEvent");
    if (GeneratePlayStreamEvent_member != obj.MemberEnd() && !GeneratePlayStreamEvent_member->value.IsNull()) GeneratePlayStreamEvent = GeneratePlayStreamEvent_member->value.GetBool();

    return true;
}

FacebookPlayFabIdPair::~FacebookPlayFabIdPair()
{

}

void FacebookPlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (FacebookId.length() > 0) { writer.String("FacebookId"); writer.String(FacebookId.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }

    writer.EndObject();
}

bool FacebookPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
    if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

FriendInfo::~FriendInfo()
{
    if (FacebookInfo != NULL) delete FacebookInfo;
    if (SteamInfo != NULL) delete SteamInfo;
    if (GameCenterInfo != NULL) delete GameCenterInfo;

}

void FriendInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (FriendPlayFabId.length() > 0) { writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
    if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (CurrentMatchmakerLobbyId.length() > 0) { writer.String("CurrentMatchmakerLobbyId"); writer.String(CurrentMatchmakerLobbyId.c_str()); }
    if (FacebookInfo != NULL) { writer.String("FacebookInfo"); FacebookInfo->writeJSON(writer); }
    if (SteamInfo != NULL) { writer.String("SteamInfo"); SteamInfo->writeJSON(writer); }
    if (GameCenterInfo != NULL) { writer.String("GameCenterInfo"); GameCenterInfo->writeJSON(writer); }

    writer.EndObject();
}

bool FriendInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
    if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator CurrentMatchmakerLobbyId_member = obj.FindMember("CurrentMatchmakerLobbyId");
    if (CurrentMatchmakerLobbyId_member != obj.MemberEnd() && !CurrentMatchmakerLobbyId_member->value.IsNull()) CurrentMatchmakerLobbyId = CurrentMatchmakerLobbyId_member->value.GetString();
    const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
    if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
    const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
    if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
    const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
    if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);

    return true;
}
void PlayFab::ServerModels::writeGameInstanceStateEnumJSON(GameInstanceState enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case GameInstanceStateOpen: writer.String("Open"); break;
    case GameInstanceStateClosed: writer.String("Closed"); break;

    }
}

GameInstanceState PlayFab::ServerModels::readGameInstanceStateFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, GameInstanceState> _GameInstanceStateMap;
    if (_GameInstanceStateMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _GameInstanceStateMap["Open"] = GameInstanceStateOpen;
        _GameInstanceStateMap["Closed"] = GameInstanceStateClosed;

    }

    auto output = _GameInstanceStateMap.find(obj.GetString());
    if (output != _GameInstanceStateMap.end())
        return output->second;

    return GameInstanceStateOpen; // Basically critical fail
}

GetActionGroupResult::~GetActionGroupResult()
{

}

void GetActionGroupResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Name"); writer.String(Name.c_str());
    if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }

    writer.EndObject();
}

bool GetActionGroupResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();

    return true;
}

GetAllActionGroupsRequest::~GetAllActionGroupsRequest()
{

}

void GetAllActionGroupsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool GetAllActionGroupsRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetAllActionGroupsResult::~GetAllActionGroupsResult()
{

}

void GetAllActionGroupsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ActionGroups");
    writer.StartArray();
    for (std::list<GetActionGroupResult>::iterator iter = ActionGroups.begin(); iter != ActionGroups.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GetAllActionGroupsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ActionGroups_member = obj.FindMember("ActionGroups");
    if (ActionGroups_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ActionGroups_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ActionGroups.push_back(GetActionGroupResult(memberList[i]));
        }
    }

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

GetCharacterDataRequest::~GetCharacterDataRequest()
{

}

void GetCharacterDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
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

bool GetCharacterDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
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
void PlayFab::ServerModels::writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case UserDataPermissionPrivate: writer.String("Private"); break;
    case UserDataPermissionPublic: writer.String("Public"); break;

    }
}

UserDataPermission PlayFab::ServerModels::readUserDataPermissionFromValue(const rapidjson::Value& obj)
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

GetCharacterDataResult::~GetCharacterDataResult()
{

}

void GetCharacterDataResult::writeJSON(PFStringJsonWriter& writer)
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
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }

    writer.EndObject();
}

bool GetCharacterDataResult::readFromValue(const rapidjson::Value& obj)
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
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

    return true;
}

GetCharacterInventoryRequest::~GetCharacterInventoryRequest()
{

}

void GetCharacterInventoryRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool GetCharacterInventoryRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

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

GetCharacterInventoryResult::~GetCharacterInventoryResult()
{

}

void GetCharacterInventoryResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
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

bool GetCharacterInventoryResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
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

GetCharacterLeaderboardRequest::~GetCharacterLeaderboardRequest()
{

}

void GetCharacterLeaderboardRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("StartPosition"); writer.Int(StartPosition);
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetCharacterLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

    return true;
}

GetCharacterLeaderboardResult::~GetCharacterLeaderboardResult()
{

}

void GetCharacterLeaderboardResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<CharacterLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetCharacterLeaderboardResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
        }
    }

    return true;
}

GetCharacterStatisticsRequest::~GetCharacterStatisticsRequest()
{

}

void GetCharacterStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());

    writer.EndObject();
}

bool GetCharacterStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

    return true;
}

GetCharacterStatisticsResult::~GetCharacterStatisticsResult()
{

}

void GetCharacterStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (!CharacterStatistics.empty()) {
    writer.String("CharacterStatistics");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool GetCharacterStatisticsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
    if (CharacterStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
            CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }

    return true;
}

GetContentDownloadUrlRequest::~GetContentDownloadUrlRequest()
{

}

void GetContentDownloadUrlRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Key"); writer.String(Key.c_str());
    if (HttpMethod.length() > 0) { writer.String("HttpMethod"); writer.String(HttpMethod.c_str()); }
    if (ThruCDN.notNull()) { writer.String("ThruCDN"); writer.Bool(ThruCDN); }

    writer.EndObject();
}

bool GetContentDownloadUrlRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::ConstMemberIterator HttpMethod_member = obj.FindMember("HttpMethod");
    if (HttpMethod_member != obj.MemberEnd() && !HttpMethod_member->value.IsNull()) HttpMethod = HttpMethod_member->value.GetString();
    const Value::ConstMemberIterator ThruCDN_member = obj.FindMember("ThruCDN");
    if (ThruCDN_member != obj.MemberEnd() && !ThruCDN_member->value.IsNull()) ThruCDN = ThruCDN_member->value.GetBool();

    return true;
}

GetContentDownloadUrlResult::~GetContentDownloadUrlResult()
{

}

void GetContentDownloadUrlResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }

    writer.EndObject();
}

bool GetContentDownloadUrlResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator URL_member = obj.FindMember("URL");
    if (URL_member != obj.MemberEnd() && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

    return true;
}

GetFriendLeaderboardRequest::~GetFriendLeaderboardRequest()
{

}

void GetFriendLeaderboardRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("StartPosition"); writer.Int(StartPosition);
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
    if (IncludeSteamFriends.notNull()) { writer.String("IncludeSteamFriends"); writer.Bool(IncludeSteamFriends); }
    if (IncludeFacebookFriends.notNull()) { writer.String("IncludeFacebookFriends"); writer.Bool(IncludeFacebookFriends); }

    writer.EndObject();
}

bool GetFriendLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
    const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
    if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
    const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
    if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();

    return true;
}

GetFriendsListRequest::~GetFriendsListRequest()
{

}

void GetFriendsListRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (IncludeSteamFriends.notNull()) { writer.String("IncludeSteamFriends"); writer.Bool(IncludeSteamFriends); }
    if (IncludeFacebookFriends.notNull()) { writer.String("IncludeFacebookFriends"); writer.Bool(IncludeFacebookFriends); }

    writer.EndObject();
}

bool GetFriendsListRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
    if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
    const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
    if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();

    return true;
}

GetFriendsListResult::~GetFriendsListResult()
{

}

void GetFriendsListResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Friends.empty()) {
    writer.String("Friends");
    writer.StartArray();
    for (std::list<FriendInfo>::iterator iter = Friends.begin(); iter != Friends.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetFriendsListResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Friends_member = obj.FindMember("Friends");
    if (Friends_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Friends_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Friends.push_back(FriendInfo(memberList[i]));
        }
    }

    return true;
}

GetLeaderboardAroundCharacterRequest::~GetLeaderboardAroundCharacterRequest()
{

}

void GetLeaderboardAroundCharacterRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetLeaderboardAroundCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

    return true;
}

GetLeaderboardAroundCharacterResult::~GetLeaderboardAroundCharacterResult()
{

}

void GetLeaderboardAroundCharacterResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<CharacterLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetLeaderboardAroundCharacterResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
        }
    }

    return true;
}

GetLeaderboardAroundUserRequest::~GetLeaderboardAroundUserRequest()
{

}

void GetLeaderboardAroundUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetLeaderboardAroundUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

    return true;
}

PlayerLeaderboardEntry::~PlayerLeaderboardEntry()
{

}

void PlayerLeaderboardEntry::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    writer.String("StatValue"); writer.Int(StatValue);
    writer.String("Position"); writer.Int(Position);

    writer.EndObject();
}

bool PlayerLeaderboardEntry::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
    if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();
    const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
    if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();

    return true;
}

GetLeaderboardAroundUserResult::~GetLeaderboardAroundUserResult()
{

}

void GetLeaderboardAroundUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<PlayerLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetLeaderboardAroundUserResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
        }
    }

    return true;
}

GetLeaderboardForUsersCharactersRequest::~GetLeaderboardForUsersCharactersRequest()
{

}

void GetLeaderboardForUsersCharactersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetLeaderboardForUsersCharactersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

    return true;
}

GetLeaderboardForUsersCharactersResult::~GetLeaderboardForUsersCharactersResult()
{

}

void GetLeaderboardForUsersCharactersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<CharacterLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetLeaderboardForUsersCharactersResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
        }
    }

    return true;
}

GetLeaderboardRequest::~GetLeaderboardRequest()
{

}

void GetLeaderboardRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("StartPosition"); writer.Int(StartPosition);
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

    return true;
}

GetLeaderboardResult::~GetLeaderboardResult()
{

}

void GetLeaderboardResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Leaderboard.empty()) {
    writer.String("Leaderboard");
    writer.StartArray();
    for (std::list<PlayerLeaderboardEntry>::iterator iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetLeaderboardResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
        }
    }

    return true;
}

GetPlayerCombinedInfoRequestParams::~GetPlayerCombinedInfoRequestParams()
{

}

void GetPlayerCombinedInfoRequestParams::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("GetUserAccountInfo"); writer.Bool(GetUserAccountInfo);
    writer.String("GetUserInventory"); writer.Bool(GetUserInventory);
    writer.String("GetUserVirtualCurrency"); writer.Bool(GetUserVirtualCurrency);
    writer.String("GetUserData"); writer.Bool(GetUserData);
    if (!UserDataKeys.empty()) {
    writer.String("UserDataKeys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = UserDataKeys.begin(); iter != UserDataKeys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    writer.String("GetUserReadOnlyData"); writer.Bool(GetUserReadOnlyData);
    if (!UserReadOnlyDataKeys.empty()) {
    writer.String("UserReadOnlyDataKeys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = UserReadOnlyDataKeys.begin(); iter != UserReadOnlyDataKeys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    writer.String("GetCharacterInventories"); writer.Bool(GetCharacterInventories);
    writer.String("GetCharacterList"); writer.Bool(GetCharacterList);
    writer.String("GetTitleData"); writer.Bool(GetTitleData);
    if (!TitleDataKeys.empty()) {
    writer.String("TitleDataKeys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = TitleDataKeys.begin(); iter != TitleDataKeys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    writer.String("GetPlayerStatistics"); writer.Bool(GetPlayerStatistics);
    if (!PlayerStatisticNames.empty()) {
    writer.String("PlayerStatisticNames");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayerStatisticNames.begin(); iter != PlayerStatisticNames.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayerCombinedInfoRequestParams::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GetUserAccountInfo_member = obj.FindMember("GetUserAccountInfo");
    if (GetUserAccountInfo_member != obj.MemberEnd() && !GetUserAccountInfo_member->value.IsNull()) GetUserAccountInfo = GetUserAccountInfo_member->value.GetBool();
    const Value::ConstMemberIterator GetUserInventory_member = obj.FindMember("GetUserInventory");
    if (GetUserInventory_member != obj.MemberEnd() && !GetUserInventory_member->value.IsNull()) GetUserInventory = GetUserInventory_member->value.GetBool();
    const Value::ConstMemberIterator GetUserVirtualCurrency_member = obj.FindMember("GetUserVirtualCurrency");
    if (GetUserVirtualCurrency_member != obj.MemberEnd() && !GetUserVirtualCurrency_member->value.IsNull()) GetUserVirtualCurrency = GetUserVirtualCurrency_member->value.GetBool();
    const Value::ConstMemberIterator GetUserData_member = obj.FindMember("GetUserData");
    if (GetUserData_member != obj.MemberEnd() && !GetUserData_member->value.IsNull()) GetUserData = GetUserData_member->value.GetBool();
    const Value::ConstMemberIterator UserDataKeys_member = obj.FindMember("UserDataKeys");
    if (UserDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserDataKeys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator GetUserReadOnlyData_member = obj.FindMember("GetUserReadOnlyData");
    if (GetUserReadOnlyData_member != obj.MemberEnd() && !GetUserReadOnlyData_member->value.IsNull()) GetUserReadOnlyData = GetUserReadOnlyData_member->value.GetBool();
    const Value::ConstMemberIterator UserReadOnlyDataKeys_member = obj.FindMember("UserReadOnlyDataKeys");
    if (UserReadOnlyDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserReadOnlyDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserReadOnlyDataKeys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator GetCharacterInventories_member = obj.FindMember("GetCharacterInventories");
    if (GetCharacterInventories_member != obj.MemberEnd() && !GetCharacterInventories_member->value.IsNull()) GetCharacterInventories = GetCharacterInventories_member->value.GetBool();
    const Value::ConstMemberIterator GetCharacterList_member = obj.FindMember("GetCharacterList");
    if (GetCharacterList_member != obj.MemberEnd() && !GetCharacterList_member->value.IsNull()) GetCharacterList = GetCharacterList_member->value.GetBool();
    const Value::ConstMemberIterator GetTitleData_member = obj.FindMember("GetTitleData");
    if (GetTitleData_member != obj.MemberEnd() && !GetTitleData_member->value.IsNull()) GetTitleData = GetTitleData_member->value.GetBool();
    const Value::ConstMemberIterator TitleDataKeys_member = obj.FindMember("TitleDataKeys");
    if (TitleDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TitleDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TitleDataKeys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator GetPlayerStatistics_member = obj.FindMember("GetPlayerStatistics");
    if (GetPlayerStatistics_member != obj.MemberEnd() && !GetPlayerStatistics_member->value.IsNull()) GetPlayerStatistics = GetPlayerStatistics_member->value.GetBool();
    const Value::ConstMemberIterator PlayerStatisticNames_member = obj.FindMember("PlayerStatisticNames");
    if (PlayerStatisticNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatisticNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatisticNames.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetPlayerCombinedInfoRequest::~GetPlayerCombinedInfoRequest()
{

}

void GetPlayerCombinedInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("InfoRequestParameters"); InfoRequestParameters.writeJSON(writer);

    writer.EndObject();
}

bool GetPlayerCombinedInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
    if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

    return true;
}

StatisticValue::~StatisticValue()
{

}

void StatisticValue::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
    writer.String("Value"); writer.Int(Value);
    writer.String("Version"); writer.Uint(Version);

    writer.EndObject();
}

bool StatisticValue::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

    return true;
}

GetPlayerCombinedInfoResultPayload::~GetPlayerCombinedInfoResultPayload()
{
    if (AccountInfo != NULL) delete AccountInfo;

}

void GetPlayerCombinedInfoResultPayload::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (AccountInfo != NULL) { writer.String("AccountInfo"); AccountInfo->writeJSON(writer); }
    if (!UserInventory.empty()) {
    writer.String("UserInventory");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = UserInventory.begin(); iter != UserInventory.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!UserVirtualCurrency.empty()) {
    writer.String("UserVirtualCurrency");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = UserVirtualCurrency.begin(); iter != UserVirtualCurrency.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
    if (!UserVirtualCurrencyRechargeTimes.empty()) {
    writer.String("UserVirtualCurrencyRechargeTimes");
    writer.StartObject();
    for (std::map<std::string, VirtualCurrencyRechargeTime>::iterator iter = UserVirtualCurrencyRechargeTimes.begin(); iter != UserVirtualCurrencyRechargeTimes.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
    if (!UserData.empty()) {
    writer.String("UserData");
    writer.StartObject();
    for (std::map<std::string, UserDataRecord>::iterator iter = UserData.begin(); iter != UserData.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
    writer.String("UserDataVersion"); writer.Uint(UserDataVersion);
    if (!UserReadOnlyData.empty()) {
    writer.String("UserReadOnlyData");
    writer.StartObject();
    for (std::map<std::string, UserDataRecord>::iterator iter = UserReadOnlyData.begin(); iter != UserReadOnlyData.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
    writer.String("UserReadOnlyDataVersion"); writer.Uint(UserReadOnlyDataVersion);
    if (!CharacterList.empty()) {
    writer.String("CharacterList");
    writer.StartArray();
    for (std::list<CharacterResult>::iterator iter = CharacterList.begin(); iter != CharacterList.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!CharacterInventories.empty()) {
    writer.String("CharacterInventories");
    writer.StartArray();
    for (std::list<CharacterInventory>::iterator iter = CharacterInventories.begin(); iter != CharacterInventories.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!TitleData.empty()) {
    writer.String("TitleData");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = TitleData.begin(); iter != TitleData.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }
    if (!PlayerStatistics.empty()) {
    writer.String("PlayerStatistics");
    writer.StartArray();
    for (std::list<StatisticValue>::iterator iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayerCombinedInfoResultPayload::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AccountInfo_member = obj.FindMember("AccountInfo");
    if (AccountInfo_member != obj.MemberEnd() && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);
    const Value::ConstMemberIterator UserInventory_member = obj.FindMember("UserInventory");
    if (UserInventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserInventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserInventory.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::ConstMemberIterator UserVirtualCurrency_member = obj.FindMember("UserVirtualCurrency");
    if (UserVirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserVirtualCurrency_member->value.MemberBegin(); iter != UserVirtualCurrency_member->value.MemberEnd(); ++iter) {
            UserVirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::ConstMemberIterator UserVirtualCurrencyRechargeTimes_member = obj.FindMember("UserVirtualCurrencyRechargeTimes");
    if (UserVirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserVirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != UserVirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
            UserVirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
        }
    }
    const Value::ConstMemberIterator UserData_member = obj.FindMember("UserData");
    if (UserData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserData_member->value.MemberBegin(); iter != UserData_member->value.MemberEnd(); ++iter) {
            UserData[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::ConstMemberIterator UserDataVersion_member = obj.FindMember("UserDataVersion");
    if (UserDataVersion_member != obj.MemberEnd() && !UserDataVersion_member->value.IsNull()) UserDataVersion = UserDataVersion_member->value.GetUint();
    const Value::ConstMemberIterator UserReadOnlyData_member = obj.FindMember("UserReadOnlyData");
    if (UserReadOnlyData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserReadOnlyData_member->value.MemberBegin(); iter != UserReadOnlyData_member->value.MemberEnd(); ++iter) {
            UserReadOnlyData[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::ConstMemberIterator UserReadOnlyDataVersion_member = obj.FindMember("UserReadOnlyDataVersion");
    if (UserReadOnlyDataVersion_member != obj.MemberEnd() && !UserReadOnlyDataVersion_member->value.IsNull()) UserReadOnlyDataVersion = UserReadOnlyDataVersion_member->value.GetUint();
    const Value::ConstMemberIterator CharacterList_member = obj.FindMember("CharacterList");
    if (CharacterList_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = CharacterList_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            CharacterList.push_back(CharacterResult(memberList[i]));
        }
    }
    const Value::ConstMemberIterator CharacterInventories_member = obj.FindMember("CharacterInventories");
    if (CharacterInventories_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = CharacterInventories_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            CharacterInventories.push_back(CharacterInventory(memberList[i]));
        }
    }
    const Value::ConstMemberIterator TitleData_member = obj.FindMember("TitleData");
    if (TitleData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = TitleData_member->value.MemberBegin(); iter != TitleData_member->value.MemberEnd(); ++iter) {
            TitleData[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
    if (PlayerStatistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatistics.push_back(StatisticValue(memberList[i]));
        }
    }

    return true;
}

GetPlayerCombinedInfoResult::~GetPlayerCombinedInfoResult()
{
    if (InfoResultPayload != NULL) delete InfoResultPayload;

}

void GetPlayerCombinedInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (InfoResultPayload != NULL) { writer.String("InfoResultPayload"); InfoResultPayload->writeJSON(writer); }

    writer.EndObject();
}

bool GetPlayerCombinedInfoResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator InfoResultPayload_member = obj.FindMember("InfoResultPayload");
    if (InfoResultPayload_member != obj.MemberEnd() && !InfoResultPayload_member->value.IsNull()) InfoResultPayload = new GetPlayerCombinedInfoResultPayload(InfoResultPayload_member->value);

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
void PlayFab::ServerModels::writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer)
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

LoginIdentityProvider PlayFab::ServerModels::readLoginIdentityProviderFromValue(const rapidjson::Value& obj)
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
void PlayFab::ServerModels::writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case PushNotificationPlatformApplePushNotificationService: writer.String("ApplePushNotificationService"); break;
    case PushNotificationPlatformGoogleCloudMessaging: writer.String("GoogleCloudMessaging"); break;

    }
}

PushNotificationPlatform PlayFab::ServerModels::readPushNotificationPlatformFromValue(const rapidjson::Value& obj)
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
    if (TotalValueToDateInUSD.notNull()) { writer.String("TotalValueToDateInUSD"); writer.Uint(TotalValueToDateInUSD); }
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
    const Value::ConstMemberIterator TotalValueToDateInUSD_member = obj.FindMember("TotalValueToDateInUSD");
    if (TotalValueToDateInUSD_member != obj.MemberEnd() && !TotalValueToDateInUSD_member->value.IsNull()) TotalValueToDateInUSD = TotalValueToDateInUSD_member->value.GetUint();
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

StatisticNameVersion::~StatisticNameVersion()
{

}

void StatisticNameVersion::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("Version"); writer.Uint(Version);

    writer.EndObject();
}

bool StatisticNameVersion::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

    return true;
}

GetPlayerStatisticsRequest::~GetPlayerStatisticsRequest()
{

}

void GetPlayerStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (!StatisticNames.empty()) {
    writer.String("StatisticNames");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = StatisticNames.begin(); iter != StatisticNames.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!StatisticNameVersions.empty()) {
    writer.String("StatisticNameVersions");
    writer.StartArray();
    for (std::list<StatisticNameVersion>::iterator iter = StatisticNameVersions.begin(); iter != StatisticNameVersions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayerStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator StatisticNames_member = obj.FindMember("StatisticNames");
    if (StatisticNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = StatisticNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            StatisticNames.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator StatisticNameVersions_member = obj.FindMember("StatisticNameVersions");
    if (StatisticNameVersions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = StatisticNameVersions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            StatisticNameVersions.push_back(StatisticNameVersion(memberList[i]));
        }
    }

    return true;
}

GetPlayerStatisticsResult::~GetPlayerStatisticsResult()
{

}

void GetPlayerStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (!Statistics.empty()) {
    writer.String("Statistics");
    writer.StartArray();
    for (std::list<StatisticValue>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayerStatisticsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statistics.push_back(StatisticValue(memberList[i]));
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

GetPlayFabIDsFromFacebookIDsRequest::~GetPlayFabIDsFromFacebookIDsRequest()
{

}

void GetPlayFabIDsFromFacebookIDsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("FacebookIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = FacebookIDs.begin(); iter != FacebookIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GetPlayFabIDsFromFacebookIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FacebookIDs_member = obj.FindMember("FacebookIDs");
    if (FacebookIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = FacebookIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            FacebookIDs.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetPlayFabIDsFromFacebookIDsResult::~GetPlayFabIDsFromFacebookIDsResult()
{

}

void GetPlayFabIDsFromFacebookIDsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Data.empty()) {
    writer.String("Data");
    writer.StartArray();
    for (std::list<FacebookPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayFabIDsFromFacebookIDsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(FacebookPlayFabIdPair(memberList[i]));
        }
    }

    return true;
}

GetPlayFabIDsFromSteamIDsRequest::~GetPlayFabIDsFromSteamIDsRequest()
{

}

void GetPlayFabIDsFromSteamIDsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!SteamIDs.empty()) {
    writer.String("SteamIDs");
    writer.StartArray();
    for (std::list<Uint64>::iterator iter = SteamIDs.begin(); iter != SteamIDs.end(); iter++) {
        writer.Uint64(*iter);
    }
    writer.EndArray();
     }
    if (!SteamStringIDs.empty()) {
    writer.String("SteamStringIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = SteamStringIDs.begin(); iter != SteamStringIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayFabIDsFromSteamIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SteamIDs_member = obj.FindMember("SteamIDs");
    if (SteamIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = SteamIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            SteamIDs.push_back(memberList[i].GetUint64());
        }
    }
    const Value::ConstMemberIterator SteamStringIDs_member = obj.FindMember("SteamStringIDs");
    if (SteamStringIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = SteamStringIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            SteamStringIDs.push_back(memberList[i].GetString());
        }
    }

    return true;
}

SteamPlayFabIdPair::~SteamPlayFabIdPair()
{

}

void SteamPlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SteamId"); writer.Uint64(SteamId);
    if (SteamStringId.length() > 0) { writer.String("SteamStringId"); writer.String(SteamStringId.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }

    writer.EndObject();
}

bool SteamPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
    if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetUint64();
    const Value::ConstMemberIterator SteamStringId_member = obj.FindMember("SteamStringId");
    if (SteamStringId_member != obj.MemberEnd() && !SteamStringId_member->value.IsNull()) SteamStringId = SteamStringId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetPlayFabIDsFromSteamIDsResult::~GetPlayFabIDsFromSteamIDsResult()
{

}

void GetPlayFabIDsFromSteamIDsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Data.empty()) {
    writer.String("Data");
    writer.StartArray();
    for (std::list<SteamPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayFabIDsFromSteamIDsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(SteamPlayFabIdPair(memberList[i]));
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
    writer.String("TableIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = TableIDs.begin(); iter != TableIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GetRandomResultTablesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator TableIDs_member = obj.FindMember("TableIDs");
    if (TableIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TableIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TableIDs.push_back(memberList[i].GetString());
        }
    }

    return true;
}
void PlayFab::ServerModels::writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case ResultTableNodeTypeItemId: writer.String("ItemId"); break;
    case ResultTableNodeTypeTableId: writer.String("TableId"); break;

    }
}

ResultTableNodeType PlayFab::ServerModels::readResultTableNodeTypeFromValue(const rapidjson::Value& obj)
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

GetSharedGroupDataRequest::~GetSharedGroupDataRequest()
{

}

void GetSharedGroupDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }
    if (!Keys.empty()) {
    writer.String("Keys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (GetMembers.notNull()) { writer.String("GetMembers"); writer.Bool(GetMembers); }

    writer.EndObject();
}

bool GetSharedGroupDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
    const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator GetMembers_member = obj.FindMember("GetMembers");
    if (GetMembers_member != obj.MemberEnd() && !GetMembers_member->value.IsNull()) GetMembers = GetMembers_member->value.GetBool();

    return true;
}

SharedGroupDataRecord::~SharedGroupDataRecord()
{

}

void SharedGroupDataRecord::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
    if (LastUpdatedBy.length() > 0) { writer.String("LastUpdatedBy"); writer.String(LastUpdatedBy.c_str()); }
    writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
    if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }

    writer.EndObject();
}

bool SharedGroupDataRecord::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
    const Value::ConstMemberIterator LastUpdatedBy_member = obj.FindMember("LastUpdatedBy");
    if (LastUpdatedBy_member != obj.MemberEnd() && !LastUpdatedBy_member->value.IsNull()) LastUpdatedBy = LastUpdatedBy_member->value.GetString();
    const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
    if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
    const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
    if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

    return true;
}

GetSharedGroupDataResult::~GetSharedGroupDataResult()
{

}

void GetSharedGroupDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, SharedGroupDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
    if (!Members.empty()) {
    writer.String("Members");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Members.begin(); iter != Members.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetSharedGroupDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = SharedGroupDataRecord(iter->value);
        }
    }
    const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
    if (Members_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Members_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Members.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetTimeRequest::~GetTimeRequest()
{

}

void GetTimeRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool GetTimeRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetTimeResult::~GetTimeResult()
{

}

void GetTimeResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Time"); writeDatetime(Time, writer);

    writer.EndObject();
}

bool GetTimeResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Time_member = obj.FindMember("Time");
    if (Time_member != obj.MemberEnd() && !Time_member->value.IsNull()) Time = readDatetime(Time_member->value);

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

GetTitleNewsRequest::~GetTitleNewsRequest()
{

}

void GetTitleNewsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Count.notNull()) { writer.String("Count"); writer.Int(Count); }

    writer.EndObject();
}

bool GetTitleNewsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Count_member = obj.FindMember("Count");
    if (Count_member != obj.MemberEnd() && !Count_member->value.IsNull()) Count = Count_member->value.GetInt();

    return true;
}

TitleNewsItem::~TitleNewsItem()
{

}

void TitleNewsItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Timestamp"); writeDatetime(Timestamp, writer);
    if (NewsId.length() > 0) { writer.String("NewsId"); writer.String(NewsId.c_str()); }
    if (Title.length() > 0) { writer.String("Title"); writer.String(Title.c_str()); }
    if (Body.length() > 0) { writer.String("Body"); writer.String(Body.c_str()); }

    writer.EndObject();
}

bool TitleNewsItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator NewsId_member = obj.FindMember("NewsId");
    if (NewsId_member != obj.MemberEnd() && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();
    const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
    if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd() && !Body_member->value.IsNull()) Body = Body_member->value.GetString();

    return true;
}

GetTitleNewsResult::~GetTitleNewsResult()
{

}

void GetTitleNewsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!News.empty()) {
    writer.String("News");
    writer.StartArray();
    for (std::list<TitleNewsItem>::iterator iter = News.begin(); iter != News.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetTitleNewsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator News_member = obj.FindMember("News");
    if (News_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = News_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            News.push_back(TitleNewsItem(memberList[i]));
        }
    }

    return true;
}

GetUserAccountInfoRequest::~GetUserAccountInfoRequest()
{

}

void GetUserAccountInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool GetUserAccountInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetUserAccountInfoResult::~GetUserAccountInfoResult()
{
    if (UserInfo != NULL) delete UserInfo;

}

void GetUserAccountInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }

    writer.EndObject();
}

bool GetUserAccountInfoResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
    if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

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

GetUserStatisticsRequest::~GetUserStatisticsRequest()
{

}

void GetUserStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool GetUserStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetUserStatisticsResult::~GetUserStatisticsResult()
{

}

void GetUserStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (!UserStatistics.empty()) {
    writer.String("UserStatistics");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = UserStatistics.begin(); iter != UserStatistics.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool GetUserStatisticsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator UserStatistics_member = obj.FindMember("UserStatistics");
    if (UserStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserStatistics_member->value.MemberBegin(); iter != UserStatistics_member->value.MemberEnd(); ++iter) {
            UserStatistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }

    return true;
}

GrantCharacterToUserRequest::~GrantCharacterToUserRequest()
{

}

void GrantCharacterToUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterName"); writer.String(CharacterName.c_str());
    writer.String("CharacterType"); writer.String(CharacterType.c_str());

    writer.EndObject();
}

bool GrantCharacterToUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();

    return true;
}

GrantCharacterToUserResult::~GrantCharacterToUserResult()
{

}

void GrantCharacterToUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }

    writer.EndObject();
}

bool GrantCharacterToUserResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

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

GrantItemsToCharacterRequest::~GrantItemsToCharacterRequest()
{

}

void GrantItemsToCharacterRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    if (!ItemIds.empty()) {
    writer.String("ItemIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = ItemIds.begin(); iter != ItemIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GrantItemsToCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::ConstMemberIterator ItemIds_member = obj.FindMember("ItemIds");
    if (ItemIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GrantItemsToCharacterResult::~GrantItemsToCharacterResult()
{

}

void GrantItemsToCharacterResult::writeJSON(PFStringJsonWriter& writer)
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

bool GrantItemsToCharacterResult::readFromValue(const rapidjson::Value& obj)
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

GrantItemsToUserRequest::~GrantItemsToUserRequest()
{

}

void GrantItemsToUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    writer.String("ItemIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = ItemIds.begin(); iter != ItemIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GrantItemsToUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::ConstMemberIterator ItemIds_member = obj.FindMember("ItemIds");
    if (ItemIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GrantItemsToUserResult::~GrantItemsToUserResult()
{

}

void GrantItemsToUserResult::writeJSON(PFStringJsonWriter& writer)
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

bool GrantItemsToUserResult::readFromValue(const rapidjson::Value& obj)
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

ListUsersCharactersRequest::~ListUsersCharactersRequest()
{

}

void ListUsersCharactersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool ListUsersCharactersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

ListUsersCharactersResult::~ListUsersCharactersResult()
{

}

void ListUsersCharactersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Characters.empty()) {
    writer.String("Characters");
    writer.StartArray();
    for (std::list<CharacterResult>::iterator iter = Characters.begin(); iter != Characters.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool ListUsersCharactersResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Characters_member = obj.FindMember("Characters");
    if (Characters_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Characters_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Characters.push_back(CharacterResult(memberList[i]));
        }
    }

    return true;
}

LogEventRequest::~LogEventRequest()
{

}

void LogEventRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (EntityId.length() > 0) { writer.String("EntityId"); writer.String(EntityId.c_str()); }
    if (EntityType.length() > 0) { writer.String("EntityType"); writer.String(EntityType.c_str()); }
    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    if (EventName.length() > 0) { writer.String("EventName"); writer.String(EventName.c_str()); }
    if (!Body.empty()) {
    writer.String("Body");
    writer.StartObject();
    for (std::map<std::string, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
    writer.String("ProfileSetEvent"); writer.Bool(ProfileSetEvent);

    writer.EndObject();
}

bool LogEventRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator EntityId_member = obj.FindMember("EntityId");
    if (EntityId_member != obj.MemberEnd() && !EntityId_member->value.IsNull()) EntityId = EntityId_member->value.GetString();
    const Value::ConstMemberIterator EntityType_member = obj.FindMember("EntityType");
    if (EntityType_member != obj.MemberEnd() && !EntityType_member->value.IsNull()) EntityType = EntityType_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
    if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }
    const Value::ConstMemberIterator ProfileSetEvent_member = obj.FindMember("ProfileSetEvent");
    if (ProfileSetEvent_member != obj.MemberEnd() && !ProfileSetEvent_member->value.IsNull()) ProfileSetEvent = ProfileSetEvent_member->value.GetBool();

    return true;
}

LogEventResult::~LogEventResult()
{

}

void LogEventResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LogEventResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

ModifyCharacterVirtualCurrencyResult::~ModifyCharacterVirtualCurrencyResult()
{

}

void ModifyCharacterVirtualCurrencyResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
    writer.String("Balance"); writer.Int(Balance);

    writer.EndObject();
}

bool ModifyCharacterVirtualCurrencyResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
    if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();

    return true;
}

ModifyItemUsesRequest::~ModifyItemUsesRequest()
{

}

void ModifyItemUsesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("UsesToAdd"); writer.Int(UsesToAdd);

    writer.EndObject();
}

bool ModifyItemUsesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator UsesToAdd_member = obj.FindMember("UsesToAdd");
    if (UsesToAdd_member != obj.MemberEnd() && !UsesToAdd_member->value.IsNull()) UsesToAdd = UsesToAdd_member->value.GetInt();

    return true;
}

ModifyItemUsesResult::~ModifyItemUsesResult()
{

}

void ModifyItemUsesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
    writer.String("RemainingUses"); writer.Int(RemainingUses);

    writer.EndObject();
}

bool ModifyItemUsesResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();

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

MoveItemToCharacterFromCharacterRequest::~MoveItemToCharacterFromCharacterRequest()
{

}

void MoveItemToCharacterFromCharacterRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("GivingCharacterId"); writer.String(GivingCharacterId.c_str());
    writer.String("ReceivingCharacterId"); writer.String(ReceivingCharacterId.c_str());
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());

    writer.EndObject();
}

bool MoveItemToCharacterFromCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator GivingCharacterId_member = obj.FindMember("GivingCharacterId");
    if (GivingCharacterId_member != obj.MemberEnd() && !GivingCharacterId_member->value.IsNull()) GivingCharacterId = GivingCharacterId_member->value.GetString();
    const Value::ConstMemberIterator ReceivingCharacterId_member = obj.FindMember("ReceivingCharacterId");
    if (ReceivingCharacterId_member != obj.MemberEnd() && !ReceivingCharacterId_member->value.IsNull()) ReceivingCharacterId = ReceivingCharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

    return true;
}

MoveItemToCharacterFromCharacterResult::~MoveItemToCharacterFromCharacterResult()
{

}

void MoveItemToCharacterFromCharacterResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool MoveItemToCharacterFromCharacterResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

MoveItemToCharacterFromUserRequest::~MoveItemToCharacterFromUserRequest()
{

}

void MoveItemToCharacterFromUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());

    writer.EndObject();
}

bool MoveItemToCharacterFromUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

    return true;
}

MoveItemToCharacterFromUserResult::~MoveItemToCharacterFromUserResult()
{

}

void MoveItemToCharacterFromUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool MoveItemToCharacterFromUserResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

MoveItemToUserFromCharacterRequest::~MoveItemToUserFromCharacterRequest()
{

}

void MoveItemToUserFromCharacterRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());

    writer.EndObject();
}

bool MoveItemToUserFromCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

    return true;
}

MoveItemToUserFromCharacterResult::~MoveItemToUserFromCharacterResult()
{

}

void MoveItemToUserFromCharacterResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool MoveItemToUserFromCharacterResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

NotifyMatchmakerPlayerLeftRequest::~NotifyMatchmakerPlayerLeftRequest()
{

}

void NotifyMatchmakerPlayerLeftRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("LobbyId"); writer.String(LobbyId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool NotifyMatchmakerPlayerLeftRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}
void PlayFab::ServerModels::writePlayerConnectionStateEnumJSON(PlayerConnectionState enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case PlayerConnectionStateUnassigned: writer.String("Unassigned"); break;
    case PlayerConnectionStateConnecting: writer.String("Connecting"); break;
    case PlayerConnectionStateParticipating: writer.String("Participating"); break;
    case PlayerConnectionStateParticipated: writer.String("Participated"); break;
    case PlayerConnectionStateReconnecting: writer.String("Reconnecting"); break;

    }
}

PlayerConnectionState PlayFab::ServerModels::readPlayerConnectionStateFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, PlayerConnectionState> _PlayerConnectionStateMap;
    if (_PlayerConnectionStateMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _PlayerConnectionStateMap["Unassigned"] = PlayerConnectionStateUnassigned;
        _PlayerConnectionStateMap["Connecting"] = PlayerConnectionStateConnecting;
        _PlayerConnectionStateMap["Participating"] = PlayerConnectionStateParticipating;
        _PlayerConnectionStateMap["Participated"] = PlayerConnectionStateParticipated;
        _PlayerConnectionStateMap["Reconnecting"] = PlayerConnectionStateReconnecting;

    }

    auto output = _PlayerConnectionStateMap.find(obj.GetString());
    if (output != _PlayerConnectionStateMap.end())
        return output->second;

    return PlayerConnectionStateUnassigned; // Basically critical fail
}

NotifyMatchmakerPlayerLeftResult::~NotifyMatchmakerPlayerLeftResult()
{

}

void NotifyMatchmakerPlayerLeftResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayerState.notNull()) { writer.String("PlayerState"); writePlayerConnectionStateEnumJSON(PlayerState, writer); }

    writer.EndObject();
}

bool NotifyMatchmakerPlayerLeftResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayerState_member = obj.FindMember("PlayerState");
    if (PlayerState_member != obj.MemberEnd() && !PlayerState_member->value.IsNull()) PlayerState = readPlayerConnectionStateFromValue(PlayerState_member->value);

    return true;
}

RedeemCouponRequest::~RedeemCouponRequest()
{

}

void RedeemCouponRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("CouponCode"); writer.String(CouponCode.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool RedeemCouponRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CouponCode_member = obj.FindMember("CouponCode");
    if (CouponCode_member != obj.MemberEnd() && !CouponCode_member->value.IsNull()) CouponCode = CouponCode_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

    return true;
}

RedeemCouponResult::~RedeemCouponResult()
{

}

void RedeemCouponResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!GrantedItems.empty()) {
    writer.String("GrantedItems");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = GrantedItems.begin(); iter != GrantedItems.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool RedeemCouponResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
    if (GrantedItems_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GrantedItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GrantedItems.push_back(ItemInstance(memberList[i]));
        }
    }

    return true;
}

RedeemMatchmakerTicketRequest::~RedeemMatchmakerTicketRequest()
{

}

void RedeemMatchmakerTicketRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Ticket"); writer.String(Ticket.c_str());
    writer.String("LobbyId"); writer.String(LobbyId.c_str());

    writer.EndObject();
}

bool RedeemMatchmakerTicketRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Ticket_member = obj.FindMember("Ticket");
    if (Ticket_member != obj.MemberEnd() && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

    return true;
}

RedeemMatchmakerTicketResult::~RedeemMatchmakerTicketResult()
{
    if (UserInfo != NULL) delete UserInfo;

}

void RedeemMatchmakerTicketResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TicketIsValid"); writer.Bool(TicketIsValid);
    if (Error.length() > 0) { writer.String("Error"); writer.String(Error.c_str()); }
    if (UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }

    writer.EndObject();
}

bool RedeemMatchmakerTicketResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator TicketIsValid_member = obj.FindMember("TicketIsValid");
    if (TicketIsValid_member != obj.MemberEnd() && !TicketIsValid_member->value.IsNull()) TicketIsValid = TicketIsValid_member->value.GetBool();
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
    const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
    if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

    return true;
}

RefreshGameServerInstanceHeartbeatRequest::~RefreshGameServerInstanceHeartbeatRequest()
{

}

void RefreshGameServerInstanceHeartbeatRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("LobbyId"); writer.String(LobbyId.c_str());

    writer.EndObject();
}

bool RefreshGameServerInstanceHeartbeatRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

    return true;
}

RefreshGameServerInstanceHeartbeatResult::~RefreshGameServerInstanceHeartbeatResult()
{

}

void RefreshGameServerInstanceHeartbeatResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool RefreshGameServerInstanceHeartbeatResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}
void PlayFab::ServerModels::writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
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

Region PlayFab::ServerModels::readRegionFromValue(const rapidjson::Value& obj)
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

RegisterGameRequest::~RegisterGameRequest()
{

}

void RegisterGameRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ServerHost"); writer.String(ServerHost.c_str());
    writer.String("ServerPort"); writer.String(ServerPort.c_str());
    writer.String("Build"); writer.String(Build.c_str());
    writer.String("Region"); writeRegionEnumJSON(pfRegion, writer);
    writer.String("GameMode"); writer.String(GameMode.c_str());
    if (!Tags.empty()) {
    writer.String("Tags");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = Tags.begin(); iter != Tags.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool RegisterGameRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ServerHost_member = obj.FindMember("ServerHost");
    if (ServerHost_member != obj.MemberEnd() && !ServerHost_member->value.IsNull()) ServerHost = ServerHost_member->value.GetString();
    const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
    if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetString();
    const Value::ConstMemberIterator Build_member = obj.FindMember("Build");
    if (Build_member != obj.MemberEnd() && !Build_member->value.IsNull()) Build = Build_member->value.GetString();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
    if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Tags_member->value.MemberBegin(); iter != Tags_member->value.MemberEnd(); ++iter) {
            Tags[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

RegisterGameResponse::~RegisterGameResponse()
{

}

void RegisterGameResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (LobbyId.length() > 0) { writer.String("LobbyId"); writer.String(LobbyId.c_str()); }

    writer.EndObject();
}

bool RegisterGameResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

    return true;
}

RemoveFriendRequest::~RemoveFriendRequest()
{

}

void RemoveFriendRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());

    writer.EndObject();
}

bool RemoveFriendRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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

RemoveSharedGroupMembersRequest::~RemoveSharedGroupMembersRequest()
{

}

void RemoveSharedGroupMembersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
    if (!PlayFabIds.empty()) {
    writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool RemoveSharedGroupMembersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

RemoveSharedGroupMembersResult::~RemoveSharedGroupMembersResult()
{

}

void RemoveSharedGroupMembersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool RemoveSharedGroupMembersResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

ReportPlayerServerRequest::~ReportPlayerServerRequest()
{

}

void ReportPlayerServerRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ReporterId"); writer.String(ReporterId.c_str());
    writer.String("ReporteeId"); writer.String(ReporteeId.c_str());
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }

    writer.EndObject();
}

bool ReportPlayerServerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ReporterId_member = obj.FindMember("ReporterId");
    if (ReporterId_member != obj.MemberEnd() && !ReporterId_member->value.IsNull()) ReporterId = ReporterId_member->value.GetString();
    const Value::ConstMemberIterator ReporteeId_member = obj.FindMember("ReporteeId");
    if (ReporteeId_member != obj.MemberEnd() && !ReporteeId_member->value.IsNull()) ReporteeId = ReporteeId_member->value.GetString();
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
    if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();

    return true;
}

ReportPlayerServerResult::~ReportPlayerServerResult()
{

}

void ReportPlayerServerResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Updated"); writer.Bool(Updated);
    writer.String("SubmissionsRemaining"); writer.Int(SubmissionsRemaining);

    writer.EndObject();
}

bool ReportPlayerServerResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Updated_member = obj.FindMember("Updated");
    if (Updated_member != obj.MemberEnd() && !Updated_member->value.IsNull()) Updated = Updated_member->value.GetBool();
    const Value::ConstMemberIterator SubmissionsRemaining_member = obj.FindMember("SubmissionsRemaining");
    if (SubmissionsRemaining_member != obj.MemberEnd() && !SubmissionsRemaining_member->value.IsNull()) SubmissionsRemaining = SubmissionsRemaining_member->value.GetInt();

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

SendPushNotificationRequest::~SendPushNotificationRequest()
{

}

void SendPushNotificationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Recipient"); writer.String(Recipient.c_str());
    writer.String("Message"); writer.String(Message.c_str());
    if (Subject.length() > 0) { writer.String("Subject"); writer.String(Subject.c_str()); }

    writer.EndObject();
}

bool SendPushNotificationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Recipient_member = obj.FindMember("Recipient");
    if (Recipient_member != obj.MemberEnd() && !Recipient_member->value.IsNull()) Recipient = Recipient_member->value.GetString();
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator Subject_member = obj.FindMember("Subject");
    if (Subject_member != obj.MemberEnd() && !Subject_member->value.IsNull()) Subject = Subject_member->value.GetString();

    return true;
}

SendPushNotificationResult::~SendPushNotificationResult()
{

}

void SendPushNotificationResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SendPushNotificationResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SetGameServerInstanceDataRequest::~SetGameServerInstanceDataRequest()
{

}

void SetGameServerInstanceDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("LobbyId"); writer.String(LobbyId.c_str());
    writer.String("GameServerData"); writer.String(GameServerData.c_str());

    writer.EndObject();
}

bool SetGameServerInstanceDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator GameServerData_member = obj.FindMember("GameServerData");
    if (GameServerData_member != obj.MemberEnd() && !GameServerData_member->value.IsNull()) GameServerData = GameServerData_member->value.GetString();

    return true;
}

SetGameServerInstanceDataResult::~SetGameServerInstanceDataResult()
{

}

void SetGameServerInstanceDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SetGameServerInstanceDataResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SetGameServerInstanceStateRequest::~SetGameServerInstanceStateRequest()
{

}

void SetGameServerInstanceStateRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("LobbyId"); writer.String(LobbyId.c_str());
    writer.String("State"); writeGameInstanceStateEnumJSON(State, writer);

    writer.EndObject();
}

bool SetGameServerInstanceStateRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator State_member = obj.FindMember("State");
    if (State_member != obj.MemberEnd() && !State_member->value.IsNull()) State = readGameInstanceStateFromValue(State_member->value);

    return true;
}

SetGameServerInstanceStateResult::~SetGameServerInstanceStateResult()
{

}

void SetGameServerInstanceStateResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SetGameServerInstanceStateResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SetGameServerInstanceTagsRequest::~SetGameServerInstanceTagsRequest()
{

}

void SetGameServerInstanceTagsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("LobbyId"); writer.String(LobbyId.c_str());
    writer.String("Tags");
    writer.StartObject();
    for (std::map<std::string, std::string>::iterator iter = Tags.begin(); iter != Tags.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
    }
    writer.EndObject();
    

    writer.EndObject();
}

bool SetGameServerInstanceTagsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Tags_member->value.MemberBegin(); iter != Tags_member->value.MemberEnd(); ++iter) {
            Tags[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

SetGameServerInstanceTagsResult::~SetGameServerInstanceTagsResult()
{

}

void SetGameServerInstanceTagsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SetGameServerInstanceTagsResult::readFromValue(const rapidjson::Value& obj)
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

StatisticUpdate::~StatisticUpdate()
{

}

void StatisticUpdate::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    if (Version.notNull()) { writer.String("Version"); writer.Uint(Version); }
    writer.String("Value"); writer.Int(Value);

    writer.EndObject();
}

bool StatisticUpdate::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();

    return true;
}

SubtractCharacterVirtualCurrencyRequest::~SubtractCharacterVirtualCurrencyRequest()
{

}

void SubtractCharacterVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.String("Amount"); writer.Int(Amount);

    writer.EndObject();
}

bool SubtractCharacterVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
    if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

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

UnlockContainerInstanceRequest::~UnlockContainerInstanceRequest()
{

}

void UnlockContainerInstanceRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ContainerItemInstanceId"); writer.String(ContainerItemInstanceId.c_str());
    if (KeyItemInstanceId.length() > 0) { writer.String("KeyItemInstanceId"); writer.String(KeyItemInstanceId.c_str()); }
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool UnlockContainerInstanceRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ContainerItemInstanceId_member = obj.FindMember("ContainerItemInstanceId");
    if (ContainerItemInstanceId_member != obj.MemberEnd() && !ContainerItemInstanceId_member->value.IsNull()) ContainerItemInstanceId = ContainerItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator KeyItemInstanceId_member = obj.FindMember("KeyItemInstanceId");
    if (KeyItemInstanceId_member != obj.MemberEnd() && !KeyItemInstanceId_member->value.IsNull()) KeyItemInstanceId = KeyItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

    return true;
}

UnlockContainerItemRequest::~UnlockContainerItemRequest()
{

}

void UnlockContainerItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ContainerItemId"); writer.String(ContainerItemId.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool UnlockContainerItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ContainerItemId_member = obj.FindMember("ContainerItemId");
    if (ContainerItemId_member != obj.MemberEnd() && !ContainerItemId_member->value.IsNull()) ContainerItemId = ContainerItemId_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

    return true;
}

UnlockContainerItemResult::~UnlockContainerItemResult()
{

}

void UnlockContainerItemResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (UnlockedItemInstanceId.length() > 0) { writer.String("UnlockedItemInstanceId"); writer.String(UnlockedItemInstanceId.c_str()); }
    if (UnlockedWithItemInstanceId.length() > 0) { writer.String("UnlockedWithItemInstanceId"); writer.String(UnlockedWithItemInstanceId.c_str()); }
    if (!GrantedItems.empty()) {
    writer.String("GrantedItems");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = GrantedItems.begin(); iter != GrantedItems.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!VirtualCurrency.empty()) {
    writer.String("VirtualCurrency");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool UnlockContainerItemResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator UnlockedItemInstanceId_member = obj.FindMember("UnlockedItemInstanceId");
    if (UnlockedItemInstanceId_member != obj.MemberEnd() && !UnlockedItemInstanceId_member->value.IsNull()) UnlockedItemInstanceId = UnlockedItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator UnlockedWithItemInstanceId_member = obj.FindMember("UnlockedWithItemInstanceId");
    if (UnlockedWithItemInstanceId_member != obj.MemberEnd() && !UnlockedWithItemInstanceId_member->value.IsNull()) UnlockedWithItemInstanceId = UnlockedWithItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
    if (GrantedItems_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GrantedItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GrantedItems.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetUint();
        }
    }

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

UpdateCharacterDataRequest::~UpdateCharacterDataRequest()
{

}

void UpdateCharacterDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
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

bool UpdateCharacterDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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
    const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
    if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

    return true;
}

UpdateCharacterDataResult::~UpdateCharacterDataResult()
{

}

void UpdateCharacterDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("DataVersion"); writer.Uint(DataVersion);

    writer.EndObject();
}

bool UpdateCharacterDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

    return true;
}

UpdateCharacterStatisticsRequest::~UpdateCharacterStatisticsRequest()
{

}

void UpdateCharacterStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (!CharacterStatistics.empty()) {
    writer.String("CharacterStatistics");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool UpdateCharacterStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
    if (CharacterStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
            CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }

    return true;
}

UpdateCharacterStatisticsResult::~UpdateCharacterStatisticsResult()
{

}

void UpdateCharacterStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UpdateCharacterStatisticsResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UpdatePlayerStatisticsRequest::~UpdatePlayerStatisticsRequest()
{

}

void UpdatePlayerStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("Statistics");
    writer.StartArray();
    for (std::list<StatisticUpdate>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool UpdatePlayerStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statistics.push_back(StatisticUpdate(memberList[i]));
        }
    }

    return true;
}

UpdatePlayerStatisticsResult::~UpdatePlayerStatisticsResult()
{

}

void UpdatePlayerStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UpdatePlayerStatisticsResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UpdateSharedGroupDataRequest::~UpdateSharedGroupDataRequest()
{

}

void UpdateSharedGroupDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
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

bool UpdateSharedGroupDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
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

UpdateSharedGroupDataResult::~UpdateSharedGroupDataResult()
{

}

void UpdateSharedGroupDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UpdateSharedGroupDataResult::readFromValue(const rapidjson::Value& obj)
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

UpdateUserInventoryItemDataRequest::~UpdateUserInventoryItemDataRequest()
{

}

void UpdateUserInventoryItemDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
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

bool UpdateUserInventoryItemDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
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

UpdateUserStatisticsRequest::~UpdateUserStatisticsRequest()
{

}

void UpdateUserStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (!UserStatistics.empty()) {
    writer.String("UserStatistics");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = UserStatistics.begin(); iter != UserStatistics.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool UpdateUserStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator UserStatistics_member = obj.FindMember("UserStatistics");
    if (UserStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserStatistics_member->value.MemberBegin(); iter != UserStatistics_member->value.MemberEnd(); ++iter) {
            UserStatistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }

    return true;
}

UpdateUserStatisticsResult::~UpdateUserStatisticsResult()
{

}

void UpdateUserStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UpdateUserStatisticsResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

WriteEventResponse::~WriteEventResponse()
{

}

void WriteEventResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (EventId.length() > 0) { writer.String("EventId"); writer.String(EventId.c_str()); }

    writer.EndObject();
}

bool WriteEventResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator EventId_member = obj.FindMember("EventId");
    if (EventId_member != obj.MemberEnd() && !EventId_member->value.IsNull()) EventId = EventId_member->value.GetString();

    return true;
}

WriteServerCharacterEventRequest::~WriteServerCharacterEventRequest()
{

}

void WriteServerCharacterEventRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("EventName"); writer.String(EventName.c_str());
    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    if (!Body.empty()) {
    writer.String("Body");
    writer.StartObject();
    for (std::map<std::string, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool WriteServerCharacterEventRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
    if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }

    return true;
}

WriteServerPlayerEventRequest::~WriteServerPlayerEventRequest()
{

}

void WriteServerPlayerEventRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("EventName"); writer.String(EventName.c_str());
    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    if (!Body.empty()) {
    writer.String("Body");
    writer.StartObject();
    for (std::map<std::string, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool WriteServerPlayerEventRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
    if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }

    return true;
}

WriteTitleEventRequest::~WriteTitleEventRequest()
{

}

void WriteTitleEventRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("EventName"); writer.String(EventName.c_str());
    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    if (!Body.empty()) {
    writer.String("Body");
    writer.StartObject();
    for (std::map<std::string, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool WriteTitleEventRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
    if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }

    return true;
}

