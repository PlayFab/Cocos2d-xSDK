#include "playfab/PlayFabServerDataModels.h"

using namespace PlayFab;
using namespace PlayFab::ServerModels;
using namespace rapidjson;


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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* Amount_member = obj.FindMember("Amount");
    if (Amount_member != NULL && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != NULL && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::Member* FriendUsername_member = obj.FindMember("FriendUsername");
    if (FriendUsername_member != NULL && !FriendUsername_member->value.IsNull()) FriendUsername = FriendUsername_member->value.GetString();
    const Value::Member* FriendEmail_member = obj.FindMember("FriendEmail");
    if (FriendEmail_member != NULL && !FriendEmail_member->value.IsNull()) FriendEmail = FriendEmail_member->value.GetString();
    const Value::Member* FriendTitleDisplayName_member = obj.FindMember("FriendTitleDisplayName");
    if (FriendTitleDisplayName_member != NULL && !FriendTitleDisplayName_member->value.IsNull()) FriendTitleDisplayName = FriendTitleDisplayName_member->value.GetString();

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
    const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != NULL && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
    const Value::Member* PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != NULL) {
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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* Amount_member = obj.FindMember("Amount");
    if (Amount_member != NULL && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

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
    const Value::Member* SessionTicket_member = obj.FindMember("SessionTicket");
    if (SessionTicket_member != NULL && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();

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
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::Member* Origination_member = obj.FindMember("Origination");
    if (Origination_member != NULL && !Origination_member->value.IsNull()) Origination = readUserOriginationFromValue(Origination_member->value);
    const Value::Member* Created_member = obj.FindMember("Created");
    if (Created_member != NULL && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::Member* LastLogin_member = obj.FindMember("LastLogin");
    if (LastLogin_member != NULL && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
    const Value::Member* FirstLogin_member = obj.FindMember("FirstLogin");
    if (FirstLogin_member != NULL && !FirstLogin_member->value.IsNull()) FirstLogin = readDatetime(FirstLogin_member->value);
    const Value::Member* isBanned_member = obj.FindMember("isBanned");
    if (isBanned_member != NULL && !isBanned_member->value.IsNull()) isBanned = isBanned_member->value.GetBool();

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
    const Value::Member* Email_member = obj.FindMember("Email");
    if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

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
    const Value::Member* FacebookId_member = obj.FindMember("FacebookId");
    if (FacebookId_member != NULL && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
    const Value::Member* FullName_member = obj.FindMember("FullName");
    if (FullName_member != NULL && !FullName_member->value.IsNull()) FullName = FullName_member->value.GetString();

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
    const Value::Member* SteamId_member = obj.FindMember("SteamId");
    if (SteamId_member != NULL && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();
    const Value::Member* SteamCountry_member = obj.FindMember("SteamCountry");
    if (SteamCountry_member != NULL && !SteamCountry_member->value.IsNull()) SteamCountry = SteamCountry_member->value.GetString();
    const Value::Member* SteamCurrency_member = obj.FindMember("SteamCurrency");
    if (SteamCurrency_member != NULL && !SteamCurrency_member->value.IsNull()) SteamCurrency = readCurrencyFromValue(SteamCurrency_member->value);
    const Value::Member* SteamActivationStatus_member = obj.FindMember("SteamActivationStatus");
    if (SteamActivationStatus_member != NULL && !SteamActivationStatus_member->value.IsNull()) SteamActivationStatus = readTitleActivationStatusFromValue(SteamActivationStatus_member->value);

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
    const Value::Member* GameCenterId_member = obj.FindMember("GameCenterId");
    if (GameCenterId_member != NULL && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();

    return true;
}

UserAccountInfo::~UserAccountInfo()
{
    if (TitleInfo != NULL) delete TitleInfo;
    if (PrivateInfo != NULL) delete PrivateInfo;
    if (FacebookInfo != NULL) delete FacebookInfo;
    if (SteamInfo != NULL) delete SteamInfo;
    if (GameCenterInfo != NULL) delete GameCenterInfo;

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

    writer.EndObject();
}

bool UserAccountInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Created_member = obj.FindMember("Created");
    if (Created_member != NULL && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::Member* TitleInfo_member = obj.FindMember("TitleInfo");
    if (TitleInfo_member != NULL && !TitleInfo_member->value.IsNull()) TitleInfo = new UserTitleInfo(TitleInfo_member->value);
    const Value::Member* PrivateInfo_member = obj.FindMember("PrivateInfo");
    if (PrivateInfo_member != NULL && !PrivateInfo_member->value.IsNull()) PrivateInfo = new UserPrivateAccountInfo(PrivateInfo_member->value);
    const Value::Member* FacebookInfo_member = obj.FindMember("FacebookInfo");
    if (FacebookInfo_member != NULL && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
    const Value::Member* SteamInfo_member = obj.FindMember("SteamInfo");
    if (SteamInfo_member != NULL && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
    const Value::Member* GameCenterInfo_member = obj.FindMember("GameCenterInfo");
    if (GameCenterInfo_member != NULL && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);

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
    const Value::Member* UserInfo_member = obj.FindMember("UserInfo");
    if (UserInfo_member != NULL && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* AchievementName_member = obj.FindMember("AchievementName");
    if (AchievementName_member != NULL && !AchievementName_member->value.IsNull()) AchievementName = AchievementName_member->value.GetString();
    const Value::Member* Result_member = obj.FindMember("Result");
    if (Result_member != NULL && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();

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
    const Value::Member* Achievements_member = obj.FindMember("Achievements");
    if (Achievements_member != NULL) {
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
    const Value::Member* AchievementResults_member = obj.FindMember("AchievementResults");
    if (AchievementResults_member != NULL) {
        const rapidjson::Value& memberList = AchievementResults_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AchievementResults.push_back(AwardSteamAchievementItem(memberList[i]));
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
    const Value::Member* UsageCount_member = obj.FindMember("UsageCount");
    if (UsageCount_member != NULL && !UsageCount_member->value.IsNull()) UsageCount = UsageCount_member->value.GetUint();
    const Value::Member* UsagePeriod_member = obj.FindMember("UsagePeriod");
    if (UsagePeriod_member != NULL && !UsagePeriod_member->value.IsNull()) UsagePeriod = UsagePeriod_member->value.GetUint();
    const Value::Member* UsagePeriodGroup_member = obj.FindMember("UsagePeriodGroup");
    if (UsagePeriodGroup_member != NULL && !UsagePeriodGroup_member->value.IsNull()) UsagePeriodGroup = UsagePeriodGroup_member->value.GetString();

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
    const Value::Member* KeyItemId_member = obj.FindMember("KeyItemId");
    if (KeyItemId_member != NULL && !KeyItemId_member->value.IsNull()) KeyItemId = KeyItemId_member->value.GetString();
    const Value::Member* ItemContents_member = obj.FindMember("ItemContents");
    if (ItemContents_member != NULL) {
        const rapidjson::Value& memberList = ItemContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemContents.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* ResultTableContents_member = obj.FindMember("ResultTableContents");
    if (ResultTableContents_member != NULL) {
        const rapidjson::Value& memberList = ResultTableContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ResultTableContents.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* VirtualCurrencyContents_member = obj.FindMember("VirtualCurrencyContents");
    if (VirtualCurrencyContents_member != NULL) {
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
    const Value::Member* BundledItems_member = obj.FindMember("BundledItems");
    if (BundledItems_member != NULL) {
        const rapidjson::Value& memberList = BundledItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundledItems.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* BundledResultTables_member = obj.FindMember("BundledResultTables");
    if (BundledResultTables_member != NULL) {
        const rapidjson::Value& memberList = BundledResultTables_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundledResultTables.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* BundledVirtualCurrencies_member = obj.FindMember("BundledVirtualCurrencies");
    if (BundledVirtualCurrencies_member != NULL) {
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
    const Value::Member* ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::Member* ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != NULL && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::Member* Description_member = obj.FindMember("Description");
    if (Description_member != NULL && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::Member* VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
    if (VirtualCurrencyPrices_member != NULL) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
    const Value::Member* RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
    if (RealCurrencyPrices_member != NULL) {
        for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
            RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }
    const Value::Member* Tags_member = obj.FindMember("Tags");
    if (Tags_member != NULL) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != NULL && !CustomData_member->value.IsNull()) CustomData = CustomData_member->value.GetString();
    const Value::Member* Consumable_member = obj.FindMember("Consumable");
    if (Consumable_member != NULL && !Consumable_member->value.IsNull()) Consumable = new CatalogItemConsumableInfo(Consumable_member->value);
    const Value::Member* Container_member = obj.FindMember("Container");
    if (Container_member != NULL && !Container_member->value.IsNull()) Container = new CatalogItemContainerInfo(Container_member->value);
    const Value::Member* Bundle_member = obj.FindMember("Bundle");
    if (Bundle_member != NULL && !Bundle_member->value.IsNull()) Bundle = new CatalogItemBundleInfo(Bundle_member->value);
    const Value::Member* CanBecomeCharacter_member = obj.FindMember("CanBecomeCharacter");
    if (CanBecomeCharacter_member != NULL && !CanBecomeCharacter_member->value.IsNull()) CanBecomeCharacter = CanBecomeCharacter_member->value.GetBool();
    const Value::Member* IsStackable_member = obj.FindMember("IsStackable");
    if (IsStackable_member != NULL && !IsStackable_member->value.IsNull()) IsStackable = IsStackable_member->value.GetBool();
    const Value::Member* IsTradable_member = obj.FindMember("IsTradable");
    if (IsTradable_member != NULL && !IsTradable_member->value.IsNull()) IsTradable = IsTradable_member->value.GetBool();
    const Value::Member* ItemImageUrl_member = obj.FindMember("ItemImageUrl");
    if (ItemImageUrl_member != NULL && !ItemImageUrl_member->value.IsNull()) ItemImageUrl = ItemImageUrl_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != NULL && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != NULL && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::Member* StatValue_member = obj.FindMember("StatValue");
    if (StatValue_member != NULL && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();
    const Value::Member* Position_member = obj.FindMember("Position");
    if (Position_member != NULL && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();

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
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != NULL && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
    const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != NULL && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();

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
    const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != NULL && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

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
    const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != NULL && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* SaveCharacterInventory_member = obj.FindMember("SaveCharacterInventory");
    if (SaveCharacterInventory_member != NULL && !SaveCharacterInventory_member->value.IsNull()) SaveCharacterInventory = SaveCharacterInventory_member->value.GetBool();

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
    const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != NULL && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

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
    const Value::Member* PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != NULL) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

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
    const Value::Member* FacebookId_member = obj.FindMember("FacebookId");
    if (FacebookId_member != NULL && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != NULL && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::Member* TitleDisplayName_member = obj.FindMember("TitleDisplayName");
    if (TitleDisplayName_member != NULL && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
    const Value::Member* Tags_member = obj.FindMember("Tags");
    if (Tags_member != NULL) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* CurrentMatchmakerLobbyId_member = obj.FindMember("CurrentMatchmakerLobbyId");
    if (CurrentMatchmakerLobbyId_member != NULL && !CurrentMatchmakerLobbyId_member->value.IsNull()) CurrentMatchmakerLobbyId = CurrentMatchmakerLobbyId_member->value.GetString();
    const Value::Member* FacebookInfo_member = obj.FindMember("FacebookInfo");
    if (FacebookInfo_member != NULL && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
    const Value::Member* SteamInfo_member = obj.FindMember("SteamInfo");
    if (SteamInfo_member != NULL && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
    const Value::Member* GameCenterInfo_member = obj.FindMember("GameCenterInfo");
    if (GameCenterInfo_member != NULL && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);

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
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

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
    const Value::Member* Catalog_member = obj.FindMember("Catalog");
    if (Catalog_member != NULL) {
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
    if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Int(IfChangedFromDataVersion); }

    writer.EndObject();
}

bool GetCharacterDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* Keys_member = obj.FindMember("Keys");
    if (Keys_member != NULL) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
    if (IfChangedFromDataVersion_member != NULL && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetInt();

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
    const Value::Member* Value_member = obj.FindMember("Value");
    if (Value_member != NULL && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
    const Value::Member* LastUpdated_member = obj.FindMember("LastUpdated");
    if (LastUpdated_member != NULL && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
    const Value::Member* Permission_member = obj.FindMember("Permission");
    if (Permission_member != NULL && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != NULL && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

    return true;
}

GetCharacterInventoryRequest::~GetCharacterInventoryRequest()
{

}

void GetCharacterInventoryRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool GetCharacterInventoryRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

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
    const Value::Member* ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::Member* ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != NULL && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::Member* PurchaseDate_member = obj.FindMember("PurchaseDate");
    if (PurchaseDate_member != NULL && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
    const Value::Member* Expiration_member = obj.FindMember("Expiration");
    if (Expiration_member != NULL && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
    const Value::Member* RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != NULL && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
    const Value::Member* UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
    if (UsesIncrementedBy_member != NULL && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();
    const Value::Member* Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != NULL && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* BundleParent_member = obj.FindMember("BundleParent");
    if (BundleParent_member != NULL && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::Member* UnitCurrency_member = obj.FindMember("UnitCurrency");
    if (UnitCurrency_member != NULL && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
    const Value::Member* UnitPrice_member = obj.FindMember("UnitPrice");
    if (UnitPrice_member != NULL && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
    const Value::Member* BundleContents_member = obj.FindMember("BundleContents");
    if (BundleContents_member != NULL) {
        const rapidjson::Value& memberList = BundleContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundleContents.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != NULL) {
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
    const Value::Member* SecondsToRecharge_member = obj.FindMember("SecondsToRecharge");
    if (SecondsToRecharge_member != NULL && !SecondsToRecharge_member->value.IsNull()) SecondsToRecharge = SecondsToRecharge_member->value.GetInt();
    const Value::Member* RechargeTime_member = obj.FindMember("RechargeTime");
    if (RechargeTime_member != NULL && !RechargeTime_member->value.IsNull()) RechargeTime = readDatetime(RechargeTime_member->value);
    const Value::Member* RechargeMax_member = obj.FindMember("RechargeMax");
    if (RechargeMax_member != NULL && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != NULL) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::Member* VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
    if (VirtualCurrencyRechargeTimes_member != NULL) {
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
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != NULL && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != NULL && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != NULL && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

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
    const Value::Member* Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != NULL) {
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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CharacterStatistics_member = obj.FindMember("CharacterStatistics");
    if (CharacterStatistics_member != NULL) {
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
    const Value::Member* Key_member = obj.FindMember("Key");
    if (Key_member != NULL && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::Member* HttpMethod_member = obj.FindMember("HttpMethod");
    if (HttpMethod_member != NULL && !HttpMethod_member->value.IsNull()) HttpMethod = HttpMethod_member->value.GetString();
    const Value::Member* ThruCDN_member = obj.FindMember("ThruCDN");
    if (ThruCDN_member != NULL && !ThruCDN_member->value.IsNull()) ThruCDN = ThruCDN_member->value.GetBool();

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
    const Value::Member* URL_member = obj.FindMember("URL");
    if (URL_member != NULL && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != NULL && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != NULL && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
    const Value::Member* IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
    if (IncludeSteamFriends_member != NULL && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
    const Value::Member* IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
    if (IncludeFacebookFriends_member != NULL && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
    if (IncludeSteamFriends_member != NULL && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
    const Value::Member* IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
    if (IncludeFacebookFriends_member != NULL && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();

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
    const Value::Member* Friends_member = obj.FindMember("Friends");
    if (Friends_member != NULL) {
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
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != NULL && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != NULL && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

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
    const Value::Member* Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != NULL) {
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
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != NULL && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::Member* StatValue_member = obj.FindMember("StatValue");
    if (StatValue_member != NULL && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();
    const Value::Member* Position_member = obj.FindMember("Position");
    if (Position_member != NULL && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();

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
    const Value::Member* Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != NULL) {
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
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != NULL && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

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
    const Value::Member* Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != NULL) {
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
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != NULL && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != NULL && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

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
    const Value::Member* Leaderboard_member = obj.FindMember("Leaderboard");
    if (Leaderboard_member != NULL) {
        const rapidjson::Value& memberList = Leaderboard_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
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
    const Value::Member* FacebookIDs_member = obj.FindMember("FacebookIDs");
    if (FacebookIDs_member != NULL) {
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
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(FacebookPlayFabIdPair(memberList[i]));
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
    const Value::Member* Keys_member = obj.FindMember("Keys");
    if (Keys_member != NULL) {
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
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
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
    const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != NULL && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
    const Value::Member* Keys_member = obj.FindMember("Keys");
    if (Keys_member != NULL) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* GetMembers_member = obj.FindMember("GetMembers");
    if (GetMembers_member != NULL && !GetMembers_member->value.IsNull()) GetMembers = GetMembers_member->value.GetBool();

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
    const Value::Member* Value_member = obj.FindMember("Value");
    if (Value_member != NULL && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
    const Value::Member* LastUpdatedBy_member = obj.FindMember("LastUpdatedBy");
    if (LastUpdatedBy_member != NULL && !LastUpdatedBy_member->value.IsNull()) LastUpdatedBy = LastUpdatedBy_member->value.GetString();
    const Value::Member* LastUpdated_member = obj.FindMember("LastUpdated");
    if (LastUpdated_member != NULL && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
    const Value::Member* Permission_member = obj.FindMember("Permission");
    if (Permission_member != NULL && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

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
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = SharedGroupDataRecord(iter->value);
        }
    }
    const Value::Member* Members_member = obj.FindMember("Members");
    if (Members_member != NULL) {
        const rapidjson::Value& memberList = Members_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Members.push_back(memberList[i].GetString());
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
    const Value::Member* Keys_member = obj.FindMember("Keys");
    if (Keys_member != NULL) {
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
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
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
    const Value::Member* Count_member = obj.FindMember("Count");
    if (Count_member != NULL && !Count_member->value.IsNull()) Count = Count_member->value.GetInt();

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
    const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != NULL && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::Member* NewsId_member = obj.FindMember("NewsId");
    if (NewsId_member != NULL && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();
    const Value::Member* Title_member = obj.FindMember("Title");
    if (Title_member != NULL && !Title_member->value.IsNull()) Title = Title_member->value.GetString();
    const Value::Member* Body_member = obj.FindMember("Body");
    if (Body_member != NULL && !Body_member->value.IsNull()) Body = Body_member->value.GetString();

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
    const Value::Member* News_member = obj.FindMember("News");
    if (News_member != NULL) {
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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* UserInfo_member = obj.FindMember("UserInfo");
    if (UserInfo_member != NULL && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

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
    if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Int(IfChangedFromDataVersion); }

    writer.EndObject();
}

bool GetUserDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Keys_member = obj.FindMember("Keys");
    if (Keys_member != NULL) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
    if (IfChangedFromDataVersion_member != NULL && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != NULL && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != NULL) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::Member* VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
    if (VirtualCurrencyRechargeTimes_member != NULL) {
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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* UserStatistics_member = obj.FindMember("UserStatistics");
    if (UserStatistics_member != NULL) {
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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != NULL && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
    const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != NULL && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();

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
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* Result_member = obj.FindMember("Result");
    if (Result_member != NULL && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();
    const Value::Member* ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::Member* ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != NULL && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::Member* PurchaseDate_member = obj.FindMember("PurchaseDate");
    if (PurchaseDate_member != NULL && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
    const Value::Member* Expiration_member = obj.FindMember("Expiration");
    if (Expiration_member != NULL && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
    const Value::Member* RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != NULL && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
    const Value::Member* UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
    if (UsesIncrementedBy_member != NULL && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();
    const Value::Member* Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != NULL && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* BundleParent_member = obj.FindMember("BundleParent");
    if (BundleParent_member != NULL && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::Member* UnitCurrency_member = obj.FindMember("UnitCurrency");
    if (UnitCurrency_member != NULL && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
    const Value::Member* UnitPrice_member = obj.FindMember("UnitPrice");
    if (UnitPrice_member != NULL && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
    const Value::Member* BundleContents_member = obj.FindMember("BundleContents");
    if (BundleContents_member != NULL) {
        const rapidjson::Value& memberList = BundleContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BundleContents.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != NULL) {
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
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != NULL && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::Member* ItemIds_member = obj.FindMember("ItemIds");
    if (ItemIds_member != NULL) {
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
    const Value::Member* ItemGrantResults_member = obj.FindMember("ItemGrantResults");
    if (ItemGrantResults_member != NULL) {
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
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != NULL && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::Member* ItemIds_member = obj.FindMember("ItemIds");
    if (ItemIds_member != NULL) {
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
    const Value::Member* ItemGrantResults_member = obj.FindMember("ItemGrantResults");
    if (ItemGrantResults_member != NULL) {
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

    writer.EndObject();
}

bool ItemGrant::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::Member* Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != NULL && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

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
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* ItemGrants_member = obj.FindMember("ItemGrants");
    if (ItemGrants_member != NULL) {
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
    const Value::Member* ItemGrantResults_member = obj.FindMember("ItemGrantResults");
    if (ItemGrantResults_member != NULL) {
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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* Characters_member = obj.FindMember("Characters");
    if (Characters_member != NULL) {
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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* EntityId_member = obj.FindMember("EntityId");
    if (EntityId_member != NULL && !EntityId_member->value.IsNull()) EntityId = EntityId_member->value.GetString();
    const Value::Member* EntityType_member = obj.FindMember("EntityType");
    if (EntityType_member != NULL && !EntityType_member->value.IsNull()) EntityType = EntityType_member->value.GetString();
    const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != NULL && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::Member* EventName_member = obj.FindMember("EventName");
    if (EventName_member != NULL && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::Member* Body_member = obj.FindMember("Body");
    if (Body_member != NULL) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }
    const Value::Member* ProfileSetEvent_member = obj.FindMember("ProfileSetEvent");
    if (ProfileSetEvent_member != NULL && !ProfileSetEvent_member->value.IsNull()) ProfileSetEvent = ProfileSetEvent_member->value.GetBool();

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
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* Balance_member = obj.FindMember("Balance");
    if (Balance_member != NULL && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::Member* UsesToAdd_member = obj.FindMember("UsesToAdd");
    if (UsesToAdd_member != NULL && !UsesToAdd_member->value.IsNull()) UsesToAdd = UsesToAdd_member->value.GetInt();

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
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::Member* RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != NULL && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* BalanceChange_member = obj.FindMember("BalanceChange");
    if (BalanceChange_member != NULL && !BalanceChange_member->value.IsNull()) BalanceChange = BalanceChange_member->value.GetInt();
    const Value::Member* Balance_member = obj.FindMember("Balance");
    if (Balance_member != NULL && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* GivingCharacterId_member = obj.FindMember("GivingCharacterId");
    if (GivingCharacterId_member != NULL && !GivingCharacterId_member->value.IsNull()) GivingCharacterId = GivingCharacterId_member->value.GetString();
    const Value::Member* ReceivingCharacterId_member = obj.FindMember("ReceivingCharacterId");
    if (ReceivingCharacterId_member != NULL && !ReceivingCharacterId_member->value.IsNull()) ReceivingCharacterId = ReceivingCharacterId_member->value.GetString();
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

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
    const Value::Member* LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != NULL && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* PlayerState_member = obj.FindMember("PlayerState");
    if (PlayerState_member != NULL && !PlayerState_member->value.IsNull()) PlayerState = readPlayerConnectionStateFromValue(PlayerState_member->value);

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
    const Value::Member* CouponCode_member = obj.FindMember("CouponCode");
    if (CouponCode_member != NULL && !CouponCode_member->value.IsNull()) CouponCode = CouponCode_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

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
    const Value::Member* GrantedItems_member = obj.FindMember("GrantedItems");
    if (GrantedItems_member != NULL) {
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
    const Value::Member* Ticket_member = obj.FindMember("Ticket");
    if (Ticket_member != NULL && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();
    const Value::Member* LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != NULL && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

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
    const Value::Member* TicketIsValid_member = obj.FindMember("TicketIsValid");
    if (TicketIsValid_member != NULL && !TicketIsValid_member->value.IsNull()) TicketIsValid = TicketIsValid_member->value.GetBool();
    const Value::Member* Error_member = obj.FindMember("Error");
    if (Error_member != NULL && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
    const Value::Member* UserInfo_member = obj.FindMember("UserInfo");
    if (UserInfo_member != NULL && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

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
    const Value::Member* FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != NULL && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != NULL && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
    const Value::Member* PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != NULL) {
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
    const Value::Member* ReporterId_member = obj.FindMember("ReporterId");
    if (ReporterId_member != NULL && !ReporterId_member->value.IsNull()) ReporterId = ReporterId_member->value.GetString();
    const Value::Member* ReporteeId_member = obj.FindMember("ReporteeId");
    if (ReporteeId_member != NULL && !ReporteeId_member->value.IsNull()) ReporteeId = ReporteeId_member->value.GetString();
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* Comment_member = obj.FindMember("Comment");
    if (Comment_member != NULL && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();

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
    const Value::Member* Updated_member = obj.FindMember("Updated");
    if (Updated_member != NULL && !Updated_member->value.IsNull()) Updated = Updated_member->value.GetBool();
    const Value::Member* SubmissionsRemaining_member = obj.FindMember("SubmissionsRemaining");
    if (SubmissionsRemaining_member != NULL && !SubmissionsRemaining_member->value.IsNull()) SubmissionsRemaining = SubmissionsRemaining_member->value.GetInt();

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
    const Value::Member* Recipient_member = obj.FindMember("Recipient");
    if (Recipient_member != NULL && !Recipient_member->value.IsNull()) Recipient = Recipient_member->value.GetString();
    const Value::Member* Message_member = obj.FindMember("Message");
    if (Message_member != NULL && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::Member* Subject_member = obj.FindMember("Subject");
    if (Subject_member != NULL && !Subject_member->value.IsNull()) Subject = Subject_member->value.GetString();

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
    const Value::Member* Key_member = obj.FindMember("Key");
    if (Key_member != NULL && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::Member* Value_member = obj.FindMember("Value");
    if (Value_member != NULL && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

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
    const Value::Member* Key_member = obj.FindMember("Key");
    if (Key_member != NULL && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    const Value::Member* Value_member = obj.FindMember("Value");
    if (Value_member != NULL && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* Amount_member = obj.FindMember("Amount");
    if (Amount_member != NULL && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* Amount_member = obj.FindMember("Amount");
    if (Amount_member != NULL && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::Member* KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != NULL) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* Permission_member = obj.FindMember("Permission");
    if (Permission_member != NULL && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

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
    const Value::Member* DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != NULL && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CharacterStatistics_member = obj.FindMember("CharacterStatistics");
    if (CharacterStatistics_member != NULL) {
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
    const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != NULL && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::Member* KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != NULL) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* Permission_member = obj.FindMember("Permission");
    if (Permission_member != NULL && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::Member* KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != NULL) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* Permission_member = obj.FindMember("Permission");
    if (Permission_member != NULL && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

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
    const Value::Member* DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != NULL && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::Member* KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != NULL) {
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

    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
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
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::Member* KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != NULL) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }

    return true;
}

UpdateUserInventoryItemDataResult::~UpdateUserInventoryItemDataResult()
{

}

void UpdateUserInventoryItemDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UpdateUserInventoryItemDataResult::readFromValue(const rapidjson::Value& obj)
{

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
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* UserStatistics_member = obj.FindMember("UserStatistics");
    if (UserStatistics_member != NULL) {
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

