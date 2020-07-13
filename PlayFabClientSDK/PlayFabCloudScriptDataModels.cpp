#include "PlayFabCloudScriptDataModels.h"

using namespace PlayFab;
using namespace PlayFab::CloudScriptModels;
using namespace rapidjson;


AdCampaignAttributionModel::~AdCampaignAttributionModel()
{

}

void AdCampaignAttributionModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("AttributedAt"); writeDatetime(AttributedAt, writer);
    if (CampaignId.length() > 0) { writer.String("CampaignId"); writer.String(CampaignId.c_str()); }
    if (Platform.length() > 0) { writer.String("Platform"); writer.String(Platform.c_str()); }
    writer.EndObject();
}

bool AdCampaignAttributionModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AttributedAt_member = obj.FindMember("AttributedAt");
    if (AttributedAt_member != obj.MemberEnd() && !AttributedAt_member->value.IsNull()) AttributedAt = readDatetime(AttributedAt_member->value);
    const Value::ConstMemberIterator CampaignId_member = obj.FindMember("CampaignId");
    if (CampaignId_member != obj.MemberEnd() && !CampaignId_member->value.IsNull()) CampaignId = CampaignId_member->value.GetString();
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();

    return true;
}
void PlayFab::CloudScriptModels::writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case CloudScriptRevisionOptionLive: writer.String("Live"); break;
    case CloudScriptRevisionOptionLatest: writer.String("Latest"); break;
    case CloudScriptRevisionOptionSpecific: writer.String("Specific"); break;

    }
}

CloudScriptRevisionOption PlayFab::CloudScriptModels::readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj)
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
void PlayFab::CloudScriptModels::writeEmailVerificationStatusEnumJSON(EmailVerificationStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case EmailVerificationStatusUnverified: writer.String("Unverified"); break;
    case EmailVerificationStatusPending: writer.String("Pending"); break;
    case EmailVerificationStatusConfirmed: writer.String("Confirmed"); break;

    }
}

EmailVerificationStatus PlayFab::CloudScriptModels::readEmailVerificationStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, EmailVerificationStatus> _EmailVerificationStatusMap;
    if (_EmailVerificationStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _EmailVerificationStatusMap["Unverified"] = EmailVerificationStatusUnverified;
        _EmailVerificationStatusMap["Pending"] = EmailVerificationStatusPending;
        _EmailVerificationStatusMap["Confirmed"] = EmailVerificationStatusConfirmed;

    }

    auto output = _EmailVerificationStatusMap.find(obj.GetString());
    if (output != _EmailVerificationStatusMap.end())
        return output->second;

    return EmailVerificationStatusUnverified; // Basically critical fail
}

ContactEmailInfoModel::~ContactEmailInfoModel()
{

}

void ContactEmailInfoModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (EmailAddress.length() > 0) { writer.String("EmailAddress"); writer.String(EmailAddress.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    if (VerificationStatus.notNull()) { writer.String("VerificationStatus"); writeEmailVerificationStatusEnumJSON(VerificationStatus, writer); }
    writer.EndObject();
}

bool ContactEmailInfoModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator EmailAddress_member = obj.FindMember("EmailAddress");
    if (EmailAddress_member != obj.MemberEnd() && !EmailAddress_member->value.IsNull()) EmailAddress = EmailAddress_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator VerificationStatus_member = obj.FindMember("VerificationStatus");
    if (VerificationStatus_member != obj.MemberEnd() && !VerificationStatus_member->value.IsNull()) VerificationStatus = readEmailVerificationStatusFromValue(VerificationStatus_member->value);

    return true;
}
void PlayFab::CloudScriptModels::writeContinentCodeEnumJSON(ContinentCode enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case ContinentCodeAF: writer.String("AF"); break;
    case ContinentCodeAN: writer.String("AN"); break;
    case ContinentCodeAS: writer.String("AS"); break;
    case ContinentCodeEU: writer.String("EU"); break;
    case ContinentCodeNA: writer.String("NA"); break;
    case ContinentCodeOC: writer.String("OC"); break;
    case ContinentCodeSA: writer.String("SA"); break;

    }
}

ContinentCode PlayFab::CloudScriptModels::readContinentCodeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, ContinentCode> _ContinentCodeMap;
    if (_ContinentCodeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _ContinentCodeMap["AF"] = ContinentCodeAF;
        _ContinentCodeMap["AN"] = ContinentCodeAN;
        _ContinentCodeMap["AS"] = ContinentCodeAS;
        _ContinentCodeMap["EU"] = ContinentCodeEU;
        _ContinentCodeMap["NA"] = ContinentCodeNA;
        _ContinentCodeMap["OC"] = ContinentCodeOC;
        _ContinentCodeMap["SA"] = ContinentCodeSA;

    }

    auto output = _ContinentCodeMap.find(obj.GetString());
    if (output != _ContinentCodeMap.end())
        return output->second;

    return ContinentCodeAF; // Basically critical fail
}
void PlayFab::CloudScriptModels::writeCountryCodeEnumJSON(CountryCode enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case CountryCodeAF: writer.String("AF"); break;
    case CountryCodeAX: writer.String("AX"); break;
    case CountryCodeAL: writer.String("AL"); break;
    case CountryCodeDZ: writer.String("DZ"); break;
    case CountryCodeAS: writer.String("AS"); break;
    case CountryCodeAD: writer.String("AD"); break;
    case CountryCodeAO: writer.String("AO"); break;
    case CountryCodeAI: writer.String("AI"); break;
    case CountryCodeAQ: writer.String("AQ"); break;
    case CountryCodeAG: writer.String("AG"); break;
    case CountryCodeAR: writer.String("AR"); break;
    case CountryCodeAM: writer.String("AM"); break;
    case CountryCodeAW: writer.String("AW"); break;
    case CountryCodeAU: writer.String("AU"); break;
    case CountryCodeAT: writer.String("AT"); break;
    case CountryCodeAZ: writer.String("AZ"); break;
    case CountryCodeBS: writer.String("BS"); break;
    case CountryCodeBH: writer.String("BH"); break;
    case CountryCodeBD: writer.String("BD"); break;
    case CountryCodeBB: writer.String("BB"); break;
    case CountryCodeBY: writer.String("BY"); break;
    case CountryCodeBE: writer.String("BE"); break;
    case CountryCodeBZ: writer.String("BZ"); break;
    case CountryCodeBJ: writer.String("BJ"); break;
    case CountryCodeBM: writer.String("BM"); break;
    case CountryCodeBT: writer.String("BT"); break;
    case CountryCodeBO: writer.String("BO"); break;
    case CountryCodeBQ: writer.String("BQ"); break;
    case CountryCodeBA: writer.String("BA"); break;
    case CountryCodeBW: writer.String("BW"); break;
    case CountryCodeBV: writer.String("BV"); break;
    case CountryCodeBR: writer.String("BR"); break;
    case CountryCodeIO: writer.String("IO"); break;
    case CountryCodeBN: writer.String("BN"); break;
    case CountryCodeBG: writer.String("BG"); break;
    case CountryCodeBF: writer.String("BF"); break;
    case CountryCodeBI: writer.String("BI"); break;
    case CountryCodeKH: writer.String("KH"); break;
    case CountryCodeCM: writer.String("CM"); break;
    case CountryCodeCA: writer.String("CA"); break;
    case CountryCodeCV: writer.String("CV"); break;
    case CountryCodeKY: writer.String("KY"); break;
    case CountryCodeCF: writer.String("CF"); break;
    case CountryCodeTD: writer.String("TD"); break;
    case CountryCodeCL: writer.String("CL"); break;
    case CountryCodeCN: writer.String("CN"); break;
    case CountryCodeCX: writer.String("CX"); break;
    case CountryCodeCC: writer.String("CC"); break;
    case CountryCodeCO: writer.String("CO"); break;
    case CountryCodeKM: writer.String("KM"); break;
    case CountryCodeCG: writer.String("CG"); break;
    case CountryCodeCD: writer.String("CD"); break;
    case CountryCodeCK: writer.String("CK"); break;
    case CountryCodeCR: writer.String("CR"); break;
    case CountryCodeCI: writer.String("CI"); break;
    case CountryCodeHR: writer.String("HR"); break;
    case CountryCodeCU: writer.String("CU"); break;
    case CountryCodeCW: writer.String("CW"); break;
    case CountryCodeCY: writer.String("CY"); break;
    case CountryCodeCZ: writer.String("CZ"); break;
    case CountryCodeDK: writer.String("DK"); break;
    case CountryCodeDJ: writer.String("DJ"); break;
    case CountryCodeDM: writer.String("DM"); break;
    case CountryCodeDO: writer.String("DO"); break;
    case CountryCodeEC: writer.String("EC"); break;
    case CountryCodeEG: writer.String("EG"); break;
    case CountryCodeSV: writer.String("SV"); break;
    case CountryCodeGQ: writer.String("GQ"); break;
    case CountryCodeER: writer.String("ER"); break;
    case CountryCodeEE: writer.String("EE"); break;
    case CountryCodeET: writer.String("ET"); break;
    case CountryCodeFK: writer.String("FK"); break;
    case CountryCodeFO: writer.String("FO"); break;
    case CountryCodeFJ: writer.String("FJ"); break;
    case CountryCodeFI: writer.String("FI"); break;
    case CountryCodeFR: writer.String("FR"); break;
    case CountryCodeGF: writer.String("GF"); break;
    case CountryCodePF: writer.String("PF"); break;
    case CountryCodeTF: writer.String("TF"); break;
    case CountryCodeGA: writer.String("GA"); break;
    case CountryCodeGM: writer.String("GM"); break;
    case CountryCodeGE: writer.String("GE"); break;
    case CountryCodeDE: writer.String("DE"); break;
    case CountryCodeGH: writer.String("GH"); break;
    case CountryCodeGI: writer.String("GI"); break;
    case CountryCodeGR: writer.String("GR"); break;
    case CountryCodeGL: writer.String("GL"); break;
    case CountryCodeGD: writer.String("GD"); break;
    case CountryCodeGP: writer.String("GP"); break;
    case CountryCodeGU: writer.String("GU"); break;
    case CountryCodeGT: writer.String("GT"); break;
    case CountryCodeGG: writer.String("GG"); break;
    case CountryCodeGN: writer.String("GN"); break;
    case CountryCodeGW: writer.String("GW"); break;
    case CountryCodeGY: writer.String("GY"); break;
    case CountryCodeHT: writer.String("HT"); break;
    case CountryCodeHM: writer.String("HM"); break;
    case CountryCodeVA: writer.String("VA"); break;
    case CountryCodeHN: writer.String("HN"); break;
    case CountryCodeHK: writer.String("HK"); break;
    case CountryCodeHU: writer.String("HU"); break;
    case CountryCodeIS: writer.String("IS"); break;
    case CountryCodeIN: writer.String("IN"); break;
    case CountryCodeID: writer.String("ID"); break;
    case CountryCodeIR: writer.String("IR"); break;
    case CountryCodeIQ: writer.String("IQ"); break;
    case CountryCodeIE: writer.String("IE"); break;
    case CountryCodeIM: writer.String("IM"); break;
    case CountryCodeIL: writer.String("IL"); break;
    case CountryCodeIT: writer.String("IT"); break;
    case CountryCodeJM: writer.String("JM"); break;
    case CountryCodeJP: writer.String("JP"); break;
    case CountryCodeJE: writer.String("JE"); break;
    case CountryCodeJO: writer.String("JO"); break;
    case CountryCodeKZ: writer.String("KZ"); break;
    case CountryCodeKE: writer.String("KE"); break;
    case CountryCodeKI: writer.String("KI"); break;
    case CountryCodeKP: writer.String("KP"); break;
    case CountryCodeKR: writer.String("KR"); break;
    case CountryCodeKW: writer.String("KW"); break;
    case CountryCodeKG: writer.String("KG"); break;
    case CountryCodeLA: writer.String("LA"); break;
    case CountryCodeLV: writer.String("LV"); break;
    case CountryCodeLB: writer.String("LB"); break;
    case CountryCodeLS: writer.String("LS"); break;
    case CountryCodeLR: writer.String("LR"); break;
    case CountryCodeLY: writer.String("LY"); break;
    case CountryCodeLI: writer.String("LI"); break;
    case CountryCodeLT: writer.String("LT"); break;
    case CountryCodeLU: writer.String("LU"); break;
    case CountryCodeMO: writer.String("MO"); break;
    case CountryCodeMK: writer.String("MK"); break;
    case CountryCodeMG: writer.String("MG"); break;
    case CountryCodeMW: writer.String("MW"); break;
    case CountryCodeMY: writer.String("MY"); break;
    case CountryCodeMV: writer.String("MV"); break;
    case CountryCodeML: writer.String("ML"); break;
    case CountryCodeMT: writer.String("MT"); break;
    case CountryCodeMH: writer.String("MH"); break;
    case CountryCodeMQ: writer.String("MQ"); break;
    case CountryCodeMR: writer.String("MR"); break;
    case CountryCodeMU: writer.String("MU"); break;
    case CountryCodeYT: writer.String("YT"); break;
    case CountryCodeMX: writer.String("MX"); break;
    case CountryCodeFM: writer.String("FM"); break;
    case CountryCodeMD: writer.String("MD"); break;
    case CountryCodeMC: writer.String("MC"); break;
    case CountryCodeMN: writer.String("MN"); break;
    case CountryCodeME: writer.String("ME"); break;
    case CountryCodeMS: writer.String("MS"); break;
    case CountryCodeMA: writer.String("MA"); break;
    case CountryCodeMZ: writer.String("MZ"); break;
    case CountryCodeMM: writer.String("MM"); break;
    case CountryCodeNA: writer.String("NA"); break;
    case CountryCodeNR: writer.String("NR"); break;
    case CountryCodeNP: writer.String("NP"); break;
    case CountryCodeNL: writer.String("NL"); break;
    case CountryCodeNC: writer.String("NC"); break;
    case CountryCodeNZ: writer.String("NZ"); break;
    case CountryCodeNI: writer.String("NI"); break;
    case CountryCodeNE: writer.String("NE"); break;
    case CountryCodeNG: writer.String("NG"); break;
    case CountryCodeNU: writer.String("NU"); break;
    case CountryCodeNF: writer.String("NF"); break;
    case CountryCodeMP: writer.String("MP"); break;
    case CountryCodeNO: writer.String("NO"); break;
    case CountryCodeOM: writer.String("OM"); break;
    case CountryCodePK: writer.String("PK"); break;
    case CountryCodePW: writer.String("PW"); break;
    case CountryCodePS: writer.String("PS"); break;
    case CountryCodePA: writer.String("PA"); break;
    case CountryCodePG: writer.String("PG"); break;
    case CountryCodePY: writer.String("PY"); break;
    case CountryCodePE: writer.String("PE"); break;
    case CountryCodePH: writer.String("PH"); break;
    case CountryCodePN: writer.String("PN"); break;
    case CountryCodePL: writer.String("PL"); break;
    case CountryCodePT: writer.String("PT"); break;
    case CountryCodePR: writer.String("PR"); break;
    case CountryCodeQA: writer.String("QA"); break;
    case CountryCodeRE: writer.String("RE"); break;
    case CountryCodeRO: writer.String("RO"); break;
    case CountryCodeRU: writer.String("RU"); break;
    case CountryCodeRW: writer.String("RW"); break;
    case CountryCodeBL: writer.String("BL"); break;
    case CountryCodeSH: writer.String("SH"); break;
    case CountryCodeKN: writer.String("KN"); break;
    case CountryCodeLC: writer.String("LC"); break;
    case CountryCodeMF: writer.String("MF"); break;
    case CountryCodePM: writer.String("PM"); break;
    case CountryCodeVC: writer.String("VC"); break;
    case CountryCodeWS: writer.String("WS"); break;
    case CountryCodeSM: writer.String("SM"); break;
    case CountryCodeST: writer.String("ST"); break;
    case CountryCodeSA: writer.String("SA"); break;
    case CountryCodeSN: writer.String("SN"); break;
    case CountryCodeRS: writer.String("RS"); break;
    case CountryCodeSC: writer.String("SC"); break;
    case CountryCodeSL: writer.String("SL"); break;
    case CountryCodeSG: writer.String("SG"); break;
    case CountryCodeSX: writer.String("SX"); break;
    case CountryCodeSK: writer.String("SK"); break;
    case CountryCodeSI: writer.String("SI"); break;
    case CountryCodeSB: writer.String("SB"); break;
    case CountryCodeSO: writer.String("SO"); break;
    case CountryCodeZA: writer.String("ZA"); break;
    case CountryCodeGS: writer.String("GS"); break;
    case CountryCodeSS: writer.String("SS"); break;
    case CountryCodeES: writer.String("ES"); break;
    case CountryCodeLK: writer.String("LK"); break;
    case CountryCodeSD: writer.String("SD"); break;
    case CountryCodeSR: writer.String("SR"); break;
    case CountryCodeSJ: writer.String("SJ"); break;
    case CountryCodeSZ: writer.String("SZ"); break;
    case CountryCodeSE: writer.String("SE"); break;
    case CountryCodeCH: writer.String("CH"); break;
    case CountryCodeSY: writer.String("SY"); break;
    case CountryCodeTW: writer.String("TW"); break;
    case CountryCodeTJ: writer.String("TJ"); break;
    case CountryCodeTZ: writer.String("TZ"); break;
    case CountryCodeTH: writer.String("TH"); break;
    case CountryCodeTL: writer.String("TL"); break;
    case CountryCodeTG: writer.String("TG"); break;
    case CountryCodeTK: writer.String("TK"); break;
    case CountryCodeTO: writer.String("TO"); break;
    case CountryCodeTT: writer.String("TT"); break;
    case CountryCodeTN: writer.String("TN"); break;
    case CountryCodeTR: writer.String("TR"); break;
    case CountryCodeTM: writer.String("TM"); break;
    case CountryCodeTC: writer.String("TC"); break;
    case CountryCodeTV: writer.String("TV"); break;
    case CountryCodeUG: writer.String("UG"); break;
    case CountryCodeUA: writer.String("UA"); break;
    case CountryCodeAE: writer.String("AE"); break;
    case CountryCodeGB: writer.String("GB"); break;
    case CountryCodeUS: writer.String("US"); break;
    case CountryCodeUM: writer.String("UM"); break;
    case CountryCodeUY: writer.String("UY"); break;
    case CountryCodeUZ: writer.String("UZ"); break;
    case CountryCodeVU: writer.String("VU"); break;
    case CountryCodeVE: writer.String("VE"); break;
    case CountryCodeVN: writer.String("VN"); break;
    case CountryCodeVG: writer.String("VG"); break;
    case CountryCodeVI: writer.String("VI"); break;
    case CountryCodeWF: writer.String("WF"); break;
    case CountryCodeEH: writer.String("EH"); break;
    case CountryCodeYE: writer.String("YE"); break;
    case CountryCodeZM: writer.String("ZM"); break;
    case CountryCodeZW: writer.String("ZW"); break;

    }
}

CountryCode PlayFab::CloudScriptModels::readCountryCodeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, CountryCode> _CountryCodeMap;
    if (_CountryCodeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _CountryCodeMap["AF"] = CountryCodeAF;
        _CountryCodeMap["AX"] = CountryCodeAX;
        _CountryCodeMap["AL"] = CountryCodeAL;
        _CountryCodeMap["DZ"] = CountryCodeDZ;
        _CountryCodeMap["AS"] = CountryCodeAS;
        _CountryCodeMap["AD"] = CountryCodeAD;
        _CountryCodeMap["AO"] = CountryCodeAO;
        _CountryCodeMap["AI"] = CountryCodeAI;
        _CountryCodeMap["AQ"] = CountryCodeAQ;
        _CountryCodeMap["AG"] = CountryCodeAG;
        _CountryCodeMap["AR"] = CountryCodeAR;
        _CountryCodeMap["AM"] = CountryCodeAM;
        _CountryCodeMap["AW"] = CountryCodeAW;
        _CountryCodeMap["AU"] = CountryCodeAU;
        _CountryCodeMap["AT"] = CountryCodeAT;
        _CountryCodeMap["AZ"] = CountryCodeAZ;
        _CountryCodeMap["BS"] = CountryCodeBS;
        _CountryCodeMap["BH"] = CountryCodeBH;
        _CountryCodeMap["BD"] = CountryCodeBD;
        _CountryCodeMap["BB"] = CountryCodeBB;
        _CountryCodeMap["BY"] = CountryCodeBY;
        _CountryCodeMap["BE"] = CountryCodeBE;
        _CountryCodeMap["BZ"] = CountryCodeBZ;
        _CountryCodeMap["BJ"] = CountryCodeBJ;
        _CountryCodeMap["BM"] = CountryCodeBM;
        _CountryCodeMap["BT"] = CountryCodeBT;
        _CountryCodeMap["BO"] = CountryCodeBO;
        _CountryCodeMap["BQ"] = CountryCodeBQ;
        _CountryCodeMap["BA"] = CountryCodeBA;
        _CountryCodeMap["BW"] = CountryCodeBW;
        _CountryCodeMap["BV"] = CountryCodeBV;
        _CountryCodeMap["BR"] = CountryCodeBR;
        _CountryCodeMap["IO"] = CountryCodeIO;
        _CountryCodeMap["BN"] = CountryCodeBN;
        _CountryCodeMap["BG"] = CountryCodeBG;
        _CountryCodeMap["BF"] = CountryCodeBF;
        _CountryCodeMap["BI"] = CountryCodeBI;
        _CountryCodeMap["KH"] = CountryCodeKH;
        _CountryCodeMap["CM"] = CountryCodeCM;
        _CountryCodeMap["CA"] = CountryCodeCA;
        _CountryCodeMap["CV"] = CountryCodeCV;
        _CountryCodeMap["KY"] = CountryCodeKY;
        _CountryCodeMap["CF"] = CountryCodeCF;
        _CountryCodeMap["TD"] = CountryCodeTD;
        _CountryCodeMap["CL"] = CountryCodeCL;
        _CountryCodeMap["CN"] = CountryCodeCN;
        _CountryCodeMap["CX"] = CountryCodeCX;
        _CountryCodeMap["CC"] = CountryCodeCC;
        _CountryCodeMap["CO"] = CountryCodeCO;
        _CountryCodeMap["KM"] = CountryCodeKM;
        _CountryCodeMap["CG"] = CountryCodeCG;
        _CountryCodeMap["CD"] = CountryCodeCD;
        _CountryCodeMap["CK"] = CountryCodeCK;
        _CountryCodeMap["CR"] = CountryCodeCR;
        _CountryCodeMap["CI"] = CountryCodeCI;
        _CountryCodeMap["HR"] = CountryCodeHR;
        _CountryCodeMap["CU"] = CountryCodeCU;
        _CountryCodeMap["CW"] = CountryCodeCW;
        _CountryCodeMap["CY"] = CountryCodeCY;
        _CountryCodeMap["CZ"] = CountryCodeCZ;
        _CountryCodeMap["DK"] = CountryCodeDK;
        _CountryCodeMap["DJ"] = CountryCodeDJ;
        _CountryCodeMap["DM"] = CountryCodeDM;
        _CountryCodeMap["DO"] = CountryCodeDO;
        _CountryCodeMap["EC"] = CountryCodeEC;
        _CountryCodeMap["EG"] = CountryCodeEG;
        _CountryCodeMap["SV"] = CountryCodeSV;
        _CountryCodeMap["GQ"] = CountryCodeGQ;
        _CountryCodeMap["ER"] = CountryCodeER;
        _CountryCodeMap["EE"] = CountryCodeEE;
        _CountryCodeMap["ET"] = CountryCodeET;
        _CountryCodeMap["FK"] = CountryCodeFK;
        _CountryCodeMap["FO"] = CountryCodeFO;
        _CountryCodeMap["FJ"] = CountryCodeFJ;
        _CountryCodeMap["FI"] = CountryCodeFI;
        _CountryCodeMap["FR"] = CountryCodeFR;
        _CountryCodeMap["GF"] = CountryCodeGF;
        _CountryCodeMap["PF"] = CountryCodePF;
        _CountryCodeMap["TF"] = CountryCodeTF;
        _CountryCodeMap["GA"] = CountryCodeGA;
        _CountryCodeMap["GM"] = CountryCodeGM;
        _CountryCodeMap["GE"] = CountryCodeGE;
        _CountryCodeMap["DE"] = CountryCodeDE;
        _CountryCodeMap["GH"] = CountryCodeGH;
        _CountryCodeMap["GI"] = CountryCodeGI;
        _CountryCodeMap["GR"] = CountryCodeGR;
        _CountryCodeMap["GL"] = CountryCodeGL;
        _CountryCodeMap["GD"] = CountryCodeGD;
        _CountryCodeMap["GP"] = CountryCodeGP;
        _CountryCodeMap["GU"] = CountryCodeGU;
        _CountryCodeMap["GT"] = CountryCodeGT;
        _CountryCodeMap["GG"] = CountryCodeGG;
        _CountryCodeMap["GN"] = CountryCodeGN;
        _CountryCodeMap["GW"] = CountryCodeGW;
        _CountryCodeMap["GY"] = CountryCodeGY;
        _CountryCodeMap["HT"] = CountryCodeHT;
        _CountryCodeMap["HM"] = CountryCodeHM;
        _CountryCodeMap["VA"] = CountryCodeVA;
        _CountryCodeMap["HN"] = CountryCodeHN;
        _CountryCodeMap["HK"] = CountryCodeHK;
        _CountryCodeMap["HU"] = CountryCodeHU;
        _CountryCodeMap["IS"] = CountryCodeIS;
        _CountryCodeMap["IN"] = CountryCodeIN;
        _CountryCodeMap["ID"] = CountryCodeID;
        _CountryCodeMap["IR"] = CountryCodeIR;
        _CountryCodeMap["IQ"] = CountryCodeIQ;
        _CountryCodeMap["IE"] = CountryCodeIE;
        _CountryCodeMap["IM"] = CountryCodeIM;
        _CountryCodeMap["IL"] = CountryCodeIL;
        _CountryCodeMap["IT"] = CountryCodeIT;
        _CountryCodeMap["JM"] = CountryCodeJM;
        _CountryCodeMap["JP"] = CountryCodeJP;
        _CountryCodeMap["JE"] = CountryCodeJE;
        _CountryCodeMap["JO"] = CountryCodeJO;
        _CountryCodeMap["KZ"] = CountryCodeKZ;
        _CountryCodeMap["KE"] = CountryCodeKE;
        _CountryCodeMap["KI"] = CountryCodeKI;
        _CountryCodeMap["KP"] = CountryCodeKP;
        _CountryCodeMap["KR"] = CountryCodeKR;
        _CountryCodeMap["KW"] = CountryCodeKW;
        _CountryCodeMap["KG"] = CountryCodeKG;
        _CountryCodeMap["LA"] = CountryCodeLA;
        _CountryCodeMap["LV"] = CountryCodeLV;
        _CountryCodeMap["LB"] = CountryCodeLB;
        _CountryCodeMap["LS"] = CountryCodeLS;
        _CountryCodeMap["LR"] = CountryCodeLR;
        _CountryCodeMap["LY"] = CountryCodeLY;
        _CountryCodeMap["LI"] = CountryCodeLI;
        _CountryCodeMap["LT"] = CountryCodeLT;
        _CountryCodeMap["LU"] = CountryCodeLU;
        _CountryCodeMap["MO"] = CountryCodeMO;
        _CountryCodeMap["MK"] = CountryCodeMK;
        _CountryCodeMap["MG"] = CountryCodeMG;
        _CountryCodeMap["MW"] = CountryCodeMW;
        _CountryCodeMap["MY"] = CountryCodeMY;
        _CountryCodeMap["MV"] = CountryCodeMV;
        _CountryCodeMap["ML"] = CountryCodeML;
        _CountryCodeMap["MT"] = CountryCodeMT;
        _CountryCodeMap["MH"] = CountryCodeMH;
        _CountryCodeMap["MQ"] = CountryCodeMQ;
        _CountryCodeMap["MR"] = CountryCodeMR;
        _CountryCodeMap["MU"] = CountryCodeMU;
        _CountryCodeMap["YT"] = CountryCodeYT;
        _CountryCodeMap["MX"] = CountryCodeMX;
        _CountryCodeMap["FM"] = CountryCodeFM;
        _CountryCodeMap["MD"] = CountryCodeMD;
        _CountryCodeMap["MC"] = CountryCodeMC;
        _CountryCodeMap["MN"] = CountryCodeMN;
        _CountryCodeMap["ME"] = CountryCodeME;
        _CountryCodeMap["MS"] = CountryCodeMS;
        _CountryCodeMap["MA"] = CountryCodeMA;
        _CountryCodeMap["MZ"] = CountryCodeMZ;
        _CountryCodeMap["MM"] = CountryCodeMM;
        _CountryCodeMap["NA"] = CountryCodeNA;
        _CountryCodeMap["NR"] = CountryCodeNR;
        _CountryCodeMap["NP"] = CountryCodeNP;
        _CountryCodeMap["NL"] = CountryCodeNL;
        _CountryCodeMap["NC"] = CountryCodeNC;
        _CountryCodeMap["NZ"] = CountryCodeNZ;
        _CountryCodeMap["NI"] = CountryCodeNI;
        _CountryCodeMap["NE"] = CountryCodeNE;
        _CountryCodeMap["NG"] = CountryCodeNG;
        _CountryCodeMap["NU"] = CountryCodeNU;
        _CountryCodeMap["NF"] = CountryCodeNF;
        _CountryCodeMap["MP"] = CountryCodeMP;
        _CountryCodeMap["NO"] = CountryCodeNO;
        _CountryCodeMap["OM"] = CountryCodeOM;
        _CountryCodeMap["PK"] = CountryCodePK;
        _CountryCodeMap["PW"] = CountryCodePW;
        _CountryCodeMap["PS"] = CountryCodePS;
        _CountryCodeMap["PA"] = CountryCodePA;
        _CountryCodeMap["PG"] = CountryCodePG;
        _CountryCodeMap["PY"] = CountryCodePY;
        _CountryCodeMap["PE"] = CountryCodePE;
        _CountryCodeMap["PH"] = CountryCodePH;
        _CountryCodeMap["PN"] = CountryCodePN;
        _CountryCodeMap["PL"] = CountryCodePL;
        _CountryCodeMap["PT"] = CountryCodePT;
        _CountryCodeMap["PR"] = CountryCodePR;
        _CountryCodeMap["QA"] = CountryCodeQA;
        _CountryCodeMap["RE"] = CountryCodeRE;
        _CountryCodeMap["RO"] = CountryCodeRO;
        _CountryCodeMap["RU"] = CountryCodeRU;
        _CountryCodeMap["RW"] = CountryCodeRW;
        _CountryCodeMap["BL"] = CountryCodeBL;
        _CountryCodeMap["SH"] = CountryCodeSH;
        _CountryCodeMap["KN"] = CountryCodeKN;
        _CountryCodeMap["LC"] = CountryCodeLC;
        _CountryCodeMap["MF"] = CountryCodeMF;
        _CountryCodeMap["PM"] = CountryCodePM;
        _CountryCodeMap["VC"] = CountryCodeVC;
        _CountryCodeMap["WS"] = CountryCodeWS;
        _CountryCodeMap["SM"] = CountryCodeSM;
        _CountryCodeMap["ST"] = CountryCodeST;
        _CountryCodeMap["SA"] = CountryCodeSA;
        _CountryCodeMap["SN"] = CountryCodeSN;
        _CountryCodeMap["RS"] = CountryCodeRS;
        _CountryCodeMap["SC"] = CountryCodeSC;
        _CountryCodeMap["SL"] = CountryCodeSL;
        _CountryCodeMap["SG"] = CountryCodeSG;
        _CountryCodeMap["SX"] = CountryCodeSX;
        _CountryCodeMap["SK"] = CountryCodeSK;
        _CountryCodeMap["SI"] = CountryCodeSI;
        _CountryCodeMap["SB"] = CountryCodeSB;
        _CountryCodeMap["SO"] = CountryCodeSO;
        _CountryCodeMap["ZA"] = CountryCodeZA;
        _CountryCodeMap["GS"] = CountryCodeGS;
        _CountryCodeMap["SS"] = CountryCodeSS;
        _CountryCodeMap["ES"] = CountryCodeES;
        _CountryCodeMap["LK"] = CountryCodeLK;
        _CountryCodeMap["SD"] = CountryCodeSD;
        _CountryCodeMap["SR"] = CountryCodeSR;
        _CountryCodeMap["SJ"] = CountryCodeSJ;
        _CountryCodeMap["SZ"] = CountryCodeSZ;
        _CountryCodeMap["SE"] = CountryCodeSE;
        _CountryCodeMap["CH"] = CountryCodeCH;
        _CountryCodeMap["SY"] = CountryCodeSY;
        _CountryCodeMap["TW"] = CountryCodeTW;
        _CountryCodeMap["TJ"] = CountryCodeTJ;
        _CountryCodeMap["TZ"] = CountryCodeTZ;
        _CountryCodeMap["TH"] = CountryCodeTH;
        _CountryCodeMap["TL"] = CountryCodeTL;
        _CountryCodeMap["TG"] = CountryCodeTG;
        _CountryCodeMap["TK"] = CountryCodeTK;
        _CountryCodeMap["TO"] = CountryCodeTO;
        _CountryCodeMap["TT"] = CountryCodeTT;
        _CountryCodeMap["TN"] = CountryCodeTN;
        _CountryCodeMap["TR"] = CountryCodeTR;
        _CountryCodeMap["TM"] = CountryCodeTM;
        _CountryCodeMap["TC"] = CountryCodeTC;
        _CountryCodeMap["TV"] = CountryCodeTV;
        _CountryCodeMap["UG"] = CountryCodeUG;
        _CountryCodeMap["UA"] = CountryCodeUA;
        _CountryCodeMap["AE"] = CountryCodeAE;
        _CountryCodeMap["GB"] = CountryCodeGB;
        _CountryCodeMap["US"] = CountryCodeUS;
        _CountryCodeMap["UM"] = CountryCodeUM;
        _CountryCodeMap["UY"] = CountryCodeUY;
        _CountryCodeMap["UZ"] = CountryCodeUZ;
        _CountryCodeMap["VU"] = CountryCodeVU;
        _CountryCodeMap["VE"] = CountryCodeVE;
        _CountryCodeMap["VN"] = CountryCodeVN;
        _CountryCodeMap["VG"] = CountryCodeVG;
        _CountryCodeMap["VI"] = CountryCodeVI;
        _CountryCodeMap["WF"] = CountryCodeWF;
        _CountryCodeMap["EH"] = CountryCodeEH;
        _CountryCodeMap["YE"] = CountryCodeYE;
        _CountryCodeMap["ZM"] = CountryCodeZM;
        _CountryCodeMap["ZW"] = CountryCodeZW;

    }

    auto output = _CountryCodeMap.find(obj.GetString());
    if (output != _CountryCodeMap.end())
        return output->second;

    return CountryCodeAF; // Basically critical fail
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

LogStatement::~LogStatement()
{

}

void LogStatement::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Data.notNull()) { writer.String("Data"); Data.writeJSON(writer); }
    if (Level.length() > 0) { writer.String("Level"); writer.String(Level.c_str()); }
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    writer.EndObject();
}

bool LogStatement::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd() && !Data_member->value.IsNull()) Data = MultitypeVar(Data_member->value);
    const Value::ConstMemberIterator Level_member = obj.FindMember("Level");
    if (Level_member != obj.MemberEnd() && !Level_member->value.IsNull()) Level = Level_member->value.GetString();
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();

    return true;
}

ExecuteCloudScriptResult::~ExecuteCloudScriptResult()
{
    if (Error != NULL) delete Error;

}

void ExecuteCloudScriptResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("APIRequestsIssued"); writer.Int(APIRequestsIssued);
    if (Error != NULL) { writer.String("Error"); Error->writeJSON(writer); }
    writer.String("ExecutionTimeSeconds"); writer.Double(ExecutionTimeSeconds);
    if (FunctionName.length() > 0) { writer.String("FunctionName"); writer.String(FunctionName.c_str()); }
    if (FunctionResult.notNull()) { writer.String("FunctionResult"); FunctionResult.writeJSON(writer); }
    if (FunctionResultTooLarge.notNull()) { writer.String("FunctionResultTooLarge"); writer.Bool(FunctionResultTooLarge); }
    writer.String("HttpRequestsIssued"); writer.Int(HttpRequestsIssued);
    if (!Logs.empty()) {
        writer.String("Logs");
        writer.StartArray();
        for (std::list<LogStatement>::iterator iter = Logs.begin(); iter != Logs.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (LogsTooLarge.notNull()) { writer.String("LogsTooLarge"); writer.Bool(LogsTooLarge); }
    writer.String("MemoryConsumedBytes"); writer.Uint(MemoryConsumedBytes);
    writer.String("ProcessorTimeSeconds"); writer.Double(ProcessorTimeSeconds);
    writer.String("Revision"); writer.Int(Revision);
    writer.EndObject();
}

bool ExecuteCloudScriptResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator APIRequestsIssued_member = obj.FindMember("APIRequestsIssued");
    if (APIRequestsIssued_member != obj.MemberEnd() && !APIRequestsIssued_member->value.IsNull()) APIRequestsIssued = APIRequestsIssued_member->value.GetInt();
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = new ScriptExecutionError(Error_member->value);
    const Value::ConstMemberIterator ExecutionTimeSeconds_member = obj.FindMember("ExecutionTimeSeconds");
    if (ExecutionTimeSeconds_member != obj.MemberEnd() && !ExecutionTimeSeconds_member->value.IsNull()) ExecutionTimeSeconds = ExecutionTimeSeconds_member->value.GetDouble();
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
    if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = MultitypeVar(FunctionResult_member->value);
    const Value::ConstMemberIterator FunctionResultTooLarge_member = obj.FindMember("FunctionResultTooLarge");
    if (FunctionResultTooLarge_member != obj.MemberEnd() && !FunctionResultTooLarge_member->value.IsNull()) FunctionResultTooLarge = FunctionResultTooLarge_member->value.GetBool();
    const Value::ConstMemberIterator HttpRequestsIssued_member = obj.FindMember("HttpRequestsIssued");
    if (HttpRequestsIssued_member != obj.MemberEnd() && !HttpRequestsIssued_member->value.IsNull()) HttpRequestsIssued = HttpRequestsIssued_member->value.GetInt();
    const Value::ConstMemberIterator Logs_member = obj.FindMember("Logs");
    if (Logs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Logs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Logs.push_back(LogStatement(memberList[i]));
        }
    }
    const Value::ConstMemberIterator LogsTooLarge_member = obj.FindMember("LogsTooLarge");
    if (LogsTooLarge_member != obj.MemberEnd() && !LogsTooLarge_member->value.IsNull()) LogsTooLarge = LogsTooLarge_member->value.GetBool();
    const Value::ConstMemberIterator MemoryConsumedBytes_member = obj.FindMember("MemoryConsumedBytes");
    if (MemoryConsumedBytes_member != obj.MemberEnd() && !MemoryConsumedBytes_member->value.IsNull()) MemoryConsumedBytes = MemoryConsumedBytes_member->value.GetUint();
    const Value::ConstMemberIterator ProcessorTimeSeconds_member = obj.FindMember("ProcessorTimeSeconds");
    if (ProcessorTimeSeconds_member != obj.MemberEnd() && !ProcessorTimeSeconds_member->value.IsNull()) ProcessorTimeSeconds = ProcessorTimeSeconds_member->value.GetDouble();
    const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
    if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

    return true;
}

ExecuteEntityCloudScriptRequest::~ExecuteEntityCloudScriptRequest()
{
    if (Entity != NULL) delete Entity;

}

void ExecuteEntityCloudScriptRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("FunctionName"); writer.String(FunctionName.c_str());
    if (FunctionParameter.notNull()) { writer.String("FunctionParameter"); FunctionParameter.writeJSON(writer); }
    if (GeneratePlayStreamEvent.notNull()) { writer.String("GeneratePlayStreamEvent"); writer.Bool(GeneratePlayStreamEvent); }
    if (RevisionSelection.notNull()) { writer.String("RevisionSelection"); writeCloudScriptRevisionOptionEnumJSON(RevisionSelection, writer); }
    if (SpecificRevision.notNull()) { writer.String("SpecificRevision"); writer.Int(SpecificRevision); }
    writer.EndObject();
}

bool ExecuteEntityCloudScriptRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionParameter_member = obj.FindMember("FunctionParameter");
    if (FunctionParameter_member != obj.MemberEnd() && !FunctionParameter_member->value.IsNull()) FunctionParameter = MultitypeVar(FunctionParameter_member->value);
    const Value::ConstMemberIterator GeneratePlayStreamEvent_member = obj.FindMember("GeneratePlayStreamEvent");
    if (GeneratePlayStreamEvent_member != obj.MemberEnd() && !GeneratePlayStreamEvent_member->value.IsNull()) GeneratePlayStreamEvent = GeneratePlayStreamEvent_member->value.GetBool();
    const Value::ConstMemberIterator RevisionSelection_member = obj.FindMember("RevisionSelection");
    if (RevisionSelection_member != obj.MemberEnd() && !RevisionSelection_member->value.IsNull()) RevisionSelection = readCloudScriptRevisionOptionFromValue(RevisionSelection_member->value);
    const Value::ConstMemberIterator SpecificRevision_member = obj.FindMember("SpecificRevision");
    if (SpecificRevision_member != obj.MemberEnd() && !SpecificRevision_member->value.IsNull()) SpecificRevision = SpecificRevision_member->value.GetInt();

    return true;
}

ExecuteFunctionRequest::~ExecuteFunctionRequest()
{
    if (Entity != NULL) delete Entity;

}

void ExecuteFunctionRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("FunctionName"); writer.String(FunctionName.c_str());
    if (FunctionParameter.notNull()) { writer.String("FunctionParameter"); FunctionParameter.writeJSON(writer); }
    if (GeneratePlayStreamEvent.notNull()) { writer.String("GeneratePlayStreamEvent"); writer.Bool(GeneratePlayStreamEvent); }
    writer.EndObject();
}

bool ExecuteFunctionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionParameter_member = obj.FindMember("FunctionParameter");
    if (FunctionParameter_member != obj.MemberEnd() && !FunctionParameter_member->value.IsNull()) FunctionParameter = MultitypeVar(FunctionParameter_member->value);
    const Value::ConstMemberIterator GeneratePlayStreamEvent_member = obj.FindMember("GeneratePlayStreamEvent");
    if (GeneratePlayStreamEvent_member != obj.MemberEnd() && !GeneratePlayStreamEvent_member->value.IsNull()) GeneratePlayStreamEvent = GeneratePlayStreamEvent_member->value.GetBool();

    return true;
}

FunctionExecutionError::~FunctionExecutionError()
{

}

void FunctionExecutionError::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Error.length() > 0) { writer.String("Error"); writer.String(Error.c_str()); }
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    if (StackTrace.length() > 0) { writer.String("StackTrace"); writer.String(StackTrace.c_str()); }
    writer.EndObject();
}

bool FunctionExecutionError::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator StackTrace_member = obj.FindMember("StackTrace");
    if (StackTrace_member != obj.MemberEnd() && !StackTrace_member->value.IsNull()) StackTrace = StackTrace_member->value.GetString();

    return true;
}

ExecuteFunctionResult::~ExecuteFunctionResult()
{
    if (Error != NULL) delete Error;

}

void ExecuteFunctionResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Error != NULL) { writer.String("Error"); Error->writeJSON(writer); }
    writer.String("ExecutionTimeMilliseconds"); writer.Int(ExecutionTimeMilliseconds);
    if (FunctionName.length() > 0) { writer.String("FunctionName"); writer.String(FunctionName.c_str()); }
    if (FunctionResult.notNull()) { writer.String("FunctionResult"); FunctionResult.writeJSON(writer); }
    if (FunctionResultTooLarge.notNull()) { writer.String("FunctionResultTooLarge"); writer.Bool(FunctionResultTooLarge); }
    writer.EndObject();
}

bool ExecuteFunctionResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = new FunctionExecutionError(Error_member->value);
    const Value::ConstMemberIterator ExecutionTimeMilliseconds_member = obj.FindMember("ExecutionTimeMilliseconds");
    if (ExecutionTimeMilliseconds_member != obj.MemberEnd() && !ExecutionTimeMilliseconds_member->value.IsNull()) ExecutionTimeMilliseconds = ExecutionTimeMilliseconds_member->value.GetInt();
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
    if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = MultitypeVar(FunctionResult_member->value);
    const Value::ConstMemberIterator FunctionResultTooLarge_member = obj.FindMember("FunctionResultTooLarge");
    if (FunctionResultTooLarge_member != obj.MemberEnd() && !FunctionResultTooLarge_member->value.IsNull()) FunctionResultTooLarge = FunctionResultTooLarge_member->value.GetBool();

    return true;
}

FunctionModel::~FunctionModel()
{

}

void FunctionModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (FunctionAddress.length() > 0) { writer.String("FunctionAddress"); writer.String(FunctionAddress.c_str()); }
    if (FunctionName.length() > 0) { writer.String("FunctionName"); writer.String(FunctionName.c_str()); }
    if (TriggerType.length() > 0) { writer.String("TriggerType"); writer.String(TriggerType.c_str()); }
    writer.EndObject();
}

bool FunctionModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FunctionAddress_member = obj.FindMember("FunctionAddress");
    if (FunctionAddress_member != obj.MemberEnd() && !FunctionAddress_member->value.IsNull()) FunctionAddress = FunctionAddress_member->value.GetString();
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator TriggerType_member = obj.FindMember("TriggerType");
    if (TriggerType_member != obj.MemberEnd() && !TriggerType_member->value.IsNull()) TriggerType = TriggerType_member->value.GetString();

    return true;
}

HttpFunctionModel::~HttpFunctionModel()
{

}

void HttpFunctionModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (FunctionName.length() > 0) { writer.String("FunctionName"); writer.String(FunctionName.c_str()); }
    if (FunctionUrl.length() > 0) { writer.String("FunctionUrl"); writer.String(FunctionUrl.c_str()); }
    writer.EndObject();
}

bool HttpFunctionModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionUrl_member = obj.FindMember("FunctionUrl");
    if (FunctionUrl_member != obj.MemberEnd() && !FunctionUrl_member->value.IsNull()) FunctionUrl = FunctionUrl_member->value.GetString();

    return true;
}
void PlayFab::CloudScriptModels::writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer)
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

LoginIdentityProvider PlayFab::CloudScriptModels::readLoginIdentityProviderFromValue(const rapidjson::Value& obj)
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

LinkedPlatformAccountModel::~LinkedPlatformAccountModel()
{

}

void LinkedPlatformAccountModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    if (Platform.notNull()) { writer.String("Platform"); writeLoginIdentityProviderEnumJSON(Platform, writer); }
    if (PlatformUserId.length() > 0) { writer.String("PlatformUserId"); writer.String(PlatformUserId.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    writer.EndObject();
}

bool LinkedPlatformAccountModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
    if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readLoginIdentityProviderFromValue(Platform_member->value);
    const Value::ConstMemberIterator PlatformUserId_member = obj.FindMember("PlatformUserId");
    if (PlatformUserId_member != obj.MemberEnd() && !PlatformUserId_member->value.IsNull()) PlatformUserId = PlatformUserId_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

    return true;
}

ListFunctionsRequest::~ListFunctionsRequest()
{

}

void ListFunctionsRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.EndObject();
}

bool ListFunctionsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

ListFunctionsResult::~ListFunctionsResult()
{

}

void ListFunctionsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Functions.empty()) {
        writer.String("Functions");
        writer.StartArray();
        for (std::list<FunctionModel>::iterator iter = Functions.begin(); iter != Functions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListFunctionsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Functions_member = obj.FindMember("Functions");
    if (Functions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Functions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Functions.push_back(FunctionModel(memberList[i]));
        }
    }

    return true;
}

ListHttpFunctionsResult::~ListHttpFunctionsResult()
{

}

void ListHttpFunctionsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Functions.empty()) {
        writer.String("Functions");
        writer.StartArray();
        for (std::list<HttpFunctionModel>::iterator iter = Functions.begin(); iter != Functions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListHttpFunctionsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Functions_member = obj.FindMember("Functions");
    if (Functions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Functions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Functions.push_back(HttpFunctionModel(memberList[i]));
        }
    }

    return true;
}

QueuedFunctionModel::~QueuedFunctionModel()
{

}

void QueuedFunctionModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ConnectionString.length() > 0) { writer.String("ConnectionString"); writer.String(ConnectionString.c_str()); }
    if (FunctionName.length() > 0) { writer.String("FunctionName"); writer.String(FunctionName.c_str()); }
    if (QueueName.length() > 0) { writer.String("QueueName"); writer.String(QueueName.c_str()); }
    writer.EndObject();
}

bool QueuedFunctionModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ConnectionString_member = obj.FindMember("ConnectionString");
    if (ConnectionString_member != obj.MemberEnd() && !ConnectionString_member->value.IsNull()) ConnectionString = ConnectionString_member->value.GetString();
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator QueueName_member = obj.FindMember("QueueName");
    if (QueueName_member != obj.MemberEnd() && !QueueName_member->value.IsNull()) QueueName = QueueName_member->value.GetString();

    return true;
}

ListQueuedFunctionsResult::~ListQueuedFunctionsResult()
{

}

void ListQueuedFunctionsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Functions.empty()) {
        writer.String("Functions");
        writer.StartArray();
        for (std::list<QueuedFunctionModel>::iterator iter = Functions.begin(); iter != Functions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListQueuedFunctionsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Functions_member = obj.FindMember("Functions");
    if (Functions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Functions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Functions.push_back(QueuedFunctionModel(memberList[i]));
        }
    }

    return true;
}

LocationModel::~LocationModel()
{

}

void LocationModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (City.length() > 0) { writer.String("City"); writer.String(City.c_str()); }
    if (pfContinentCode.notNull()) { writer.String("ContinentCode"); writeContinentCodeEnumJSON(pfContinentCode, writer); }
    if (pfCountryCode.notNull()) { writer.String("CountryCode"); writeCountryCodeEnumJSON(pfCountryCode, writer); }
    if (Latitude.notNull()) { writer.String("Latitude"); writer.Double(Latitude); }
    if (Longitude.notNull()) { writer.String("Longitude"); writer.Double(Longitude); }
    writer.EndObject();
}

bool LocationModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator City_member = obj.FindMember("City");
    if (City_member != obj.MemberEnd() && !City_member->value.IsNull()) City = City_member->value.GetString();
    const Value::ConstMemberIterator ContinentCode_member = obj.FindMember("ContinentCode");
    if (ContinentCode_member != obj.MemberEnd() && !ContinentCode_member->value.IsNull()) pfContinentCode = readContinentCodeFromValue(ContinentCode_member->value);
    const Value::ConstMemberIterator CountryCode_member = obj.FindMember("CountryCode");
    if (CountryCode_member != obj.MemberEnd() && !CountryCode_member->value.IsNull()) pfCountryCode = readCountryCodeFromValue(CountryCode_member->value);
    const Value::ConstMemberIterator Latitude_member = obj.FindMember("Latitude");
    if (Latitude_member != obj.MemberEnd() && !Latitude_member->value.IsNull()) Latitude = Latitude_member->value.GetDouble();
    const Value::ConstMemberIterator Longitude_member = obj.FindMember("Longitude");
    if (Longitude_member != obj.MemberEnd() && !Longitude_member->value.IsNull()) Longitude = Longitude_member->value.GetDouble();

    return true;
}
void PlayFab::CloudScriptModels::writeSubscriptionProviderStatusEnumJSON(SubscriptionProviderStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case SubscriptionProviderStatusNoError: writer.String("NoError"); break;
    case SubscriptionProviderStatusCancelled: writer.String("Cancelled"); break;
    case SubscriptionProviderStatusUnknownError: writer.String("UnknownError"); break;
    case SubscriptionProviderStatusBillingError: writer.String("BillingError"); break;
    case SubscriptionProviderStatusProductUnavailable: writer.String("ProductUnavailable"); break;
    case SubscriptionProviderStatusCustomerDidNotAcceptPriceChange: writer.String("CustomerDidNotAcceptPriceChange"); break;
    case SubscriptionProviderStatusFreeTrial: writer.String("FreeTrial"); break;
    case SubscriptionProviderStatusPaymentPending: writer.String("PaymentPending"); break;

    }
}

SubscriptionProviderStatus PlayFab::CloudScriptModels::readSubscriptionProviderStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, SubscriptionProviderStatus> _SubscriptionProviderStatusMap;
    if (_SubscriptionProviderStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _SubscriptionProviderStatusMap["NoError"] = SubscriptionProviderStatusNoError;
        _SubscriptionProviderStatusMap["Cancelled"] = SubscriptionProviderStatusCancelled;
        _SubscriptionProviderStatusMap["UnknownError"] = SubscriptionProviderStatusUnknownError;
        _SubscriptionProviderStatusMap["BillingError"] = SubscriptionProviderStatusBillingError;
        _SubscriptionProviderStatusMap["ProductUnavailable"] = SubscriptionProviderStatusProductUnavailable;
        _SubscriptionProviderStatusMap["CustomerDidNotAcceptPriceChange"] = SubscriptionProviderStatusCustomerDidNotAcceptPriceChange;
        _SubscriptionProviderStatusMap["FreeTrial"] = SubscriptionProviderStatusFreeTrial;
        _SubscriptionProviderStatusMap["PaymentPending"] = SubscriptionProviderStatusPaymentPending;

    }

    auto output = _SubscriptionProviderStatusMap.find(obj.GetString());
    if (output != _SubscriptionProviderStatusMap.end())
        return output->second;

    return SubscriptionProviderStatusNoError; // Basically critical fail
}

SubscriptionModel::~SubscriptionModel()
{

}

void SubscriptionModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Expiration"); writeDatetime(Expiration, writer);
    writer.String("InitialSubscriptionTime"); writeDatetime(InitialSubscriptionTime, writer);
    writer.String("IsActive"); writer.Bool(IsActive);
    if (Status.notNull()) { writer.String("Status"); writeSubscriptionProviderStatusEnumJSON(Status, writer); }
    if (SubscriptionId.length() > 0) { writer.String("SubscriptionId"); writer.String(SubscriptionId.c_str()); }
    if (SubscriptionItemId.length() > 0) { writer.String("SubscriptionItemId"); writer.String(SubscriptionItemId.c_str()); }
    if (SubscriptionProvider.length() > 0) { writer.String("SubscriptionProvider"); writer.String(SubscriptionProvider.c_str()); }
    writer.EndObject();
}

bool SubscriptionModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
    if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
    const Value::ConstMemberIterator InitialSubscriptionTime_member = obj.FindMember("InitialSubscriptionTime");
    if (InitialSubscriptionTime_member != obj.MemberEnd() && !InitialSubscriptionTime_member->value.IsNull()) InitialSubscriptionTime = readDatetime(InitialSubscriptionTime_member->value);
    const Value::ConstMemberIterator IsActive_member = obj.FindMember("IsActive");
    if (IsActive_member != obj.MemberEnd() && !IsActive_member->value.IsNull()) IsActive = IsActive_member->value.GetBool();
    const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
    if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readSubscriptionProviderStatusFromValue(Status_member->value);
    const Value::ConstMemberIterator SubscriptionId_member = obj.FindMember("SubscriptionId");
    if (SubscriptionId_member != obj.MemberEnd() && !SubscriptionId_member->value.IsNull()) SubscriptionId = SubscriptionId_member->value.GetString();
    const Value::ConstMemberIterator SubscriptionItemId_member = obj.FindMember("SubscriptionItemId");
    if (SubscriptionItemId_member != obj.MemberEnd() && !SubscriptionItemId_member->value.IsNull()) SubscriptionItemId = SubscriptionItemId_member->value.GetString();
    const Value::ConstMemberIterator SubscriptionProvider_member = obj.FindMember("SubscriptionProvider");
    if (SubscriptionProvider_member != obj.MemberEnd() && !SubscriptionProvider_member->value.IsNull()) SubscriptionProvider = SubscriptionProvider_member->value.GetString();

    return true;
}

MembershipModel::~MembershipModel()
{

}

void MembershipModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("IsActive"); writer.Bool(IsActive);
    writer.String("MembershipExpiration"); writeDatetime(MembershipExpiration, writer);
    if (MembershipId.length() > 0) { writer.String("MembershipId"); writer.String(MembershipId.c_str()); }
    if (OverrideExpiration.notNull()) { writer.String("OverrideExpiration"); writeDatetime(OverrideExpiration, writer); }
    if (!Subscriptions.empty()) {
        writer.String("Subscriptions");
        writer.StartArray();
        for (std::list<SubscriptionModel>::iterator iter = Subscriptions.begin(); iter != Subscriptions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool MembershipModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IsActive_member = obj.FindMember("IsActive");
    if (IsActive_member != obj.MemberEnd() && !IsActive_member->value.IsNull()) IsActive = IsActive_member->value.GetBool();
    const Value::ConstMemberIterator MembershipExpiration_member = obj.FindMember("MembershipExpiration");
    if (MembershipExpiration_member != obj.MemberEnd() && !MembershipExpiration_member->value.IsNull()) MembershipExpiration = readDatetime(MembershipExpiration_member->value);
    const Value::ConstMemberIterator MembershipId_member = obj.FindMember("MembershipId");
    if (MembershipId_member != obj.MemberEnd() && !MembershipId_member->value.IsNull()) MembershipId = MembershipId_member->value.GetString();
    const Value::ConstMemberIterator OverrideExpiration_member = obj.FindMember("OverrideExpiration");
    if (OverrideExpiration_member != obj.MemberEnd() && !OverrideExpiration_member->value.IsNull()) OverrideExpiration = readDatetime(OverrideExpiration_member->value);
    const Value::ConstMemberIterator Subscriptions_member = obj.FindMember("Subscriptions");
    if (Subscriptions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Subscriptions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Subscriptions.push_back(SubscriptionModel(memberList[i]));
        }
    }

    return true;
}

NameIdentifier::~NameIdentifier()
{

}

void NameIdentifier::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    writer.EndObject();
}

bool NameIdentifier::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

    return true;
}
void PlayFab::CloudScriptModels::writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case PushNotificationPlatformApplePushNotificationService: writer.String("ApplePushNotificationService"); break;
    case PushNotificationPlatformGoogleCloudMessaging: writer.String("GoogleCloudMessaging"); break;

    }
}

PushNotificationPlatform PlayFab::CloudScriptModels::readPushNotificationPlatformFromValue(const rapidjson::Value& obj)
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

PushNotificationRegistrationModel::~PushNotificationRegistrationModel()
{

}

void PushNotificationRegistrationModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (NotificationEndpointARN.length() > 0) { writer.String("NotificationEndpointARN"); writer.String(NotificationEndpointARN.c_str()); }
    if (Platform.notNull()) { writer.String("Platform"); writePushNotificationPlatformEnumJSON(Platform, writer); }
    writer.EndObject();
}

bool PushNotificationRegistrationModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator NotificationEndpointARN_member = obj.FindMember("NotificationEndpointARN");
    if (NotificationEndpointARN_member != obj.MemberEnd() && !NotificationEndpointARN_member->value.IsNull()) NotificationEndpointARN = NotificationEndpointARN_member->value.GetString();
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushNotificationPlatformFromValue(Platform_member->value);

    return true;
}

StatisticModel::~StatisticModel()
{

}

void StatisticModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    writer.String("Value"); writer.Int(Value);
    writer.String("Version"); writer.Int(Version);
    writer.EndObject();
}

bool StatisticModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

    return true;
}

TagModel::~TagModel()
{

}

void TagModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (TagValue.length() > 0) { writer.String("TagValue"); writer.String(TagValue.c_str()); }
    writer.EndObject();
}

bool TagModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator TagValue_member = obj.FindMember("TagValue");
    if (TagValue_member != obj.MemberEnd() && !TagValue_member->value.IsNull()) TagValue = TagValue_member->value.GetString();

    return true;
}

ValueToDateModel::~ValueToDateModel()
{

}

void ValueToDateModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Currency.length() > 0) { writer.String("Currency"); writer.String(Currency.c_str()); }
    writer.String("TotalValue"); writer.Uint(TotalValue);
    if (TotalValueAsDecimal.length() > 0) { writer.String("TotalValueAsDecimal"); writer.String(TotalValueAsDecimal.c_str()); }
    writer.EndObject();
}

bool ValueToDateModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
    if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
    const Value::ConstMemberIterator TotalValue_member = obj.FindMember("TotalValue");
    if (TotalValue_member != obj.MemberEnd() && !TotalValue_member->value.IsNull()) TotalValue = TotalValue_member->value.GetUint();
    const Value::ConstMemberIterator TotalValueAsDecimal_member = obj.FindMember("TotalValueAsDecimal");
    if (TotalValueAsDecimal_member != obj.MemberEnd() && !TotalValueAsDecimal_member->value.IsNull()) TotalValueAsDecimal = TotalValueAsDecimal_member->value.GetString();

    return true;
}

PlayerProfileModel::~PlayerProfileModel()
{

}

void PlayerProfileModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!AdCampaignAttributions.empty()) {
        writer.String("AdCampaignAttributions");
        writer.StartArray();
        for (std::list<AdCampaignAttributionModel>::iterator iter = AdCampaignAttributions.begin(); iter != AdCampaignAttributions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (AvatarUrl.length() > 0) { writer.String("AvatarUrl"); writer.String(AvatarUrl.c_str()); }
    if (BannedUntil.notNull()) { writer.String("BannedUntil"); writeDatetime(BannedUntil, writer); }
    if (!ContactEmailAddresses.empty()) {
        writer.String("ContactEmailAddresses");
        writer.StartArray();
        for (std::list<ContactEmailInfoModel>::iterator iter = ContactEmailAddresses.begin(); iter != ContactEmailAddresses.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (Created.notNull()) { writer.String("Created"); writeDatetime(Created, writer); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (!ExperimentVariants.empty()) {
        writer.String("ExperimentVariants");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = ExperimentVariants.begin(); iter != ExperimentVariants.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
    if (!LinkedAccounts.empty()) {
        writer.String("LinkedAccounts");
        writer.StartArray();
        for (std::list<LinkedPlatformAccountModel>::iterator iter = LinkedAccounts.begin(); iter != LinkedAccounts.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Locations.empty()) {
        writer.String("Locations");
        writer.StartArray();
        for (std::list<LocationModel>::iterator iter = Locations.begin(); iter != Locations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Memberships.empty()) {
        writer.String("Memberships");
        writer.StartArray();
        for (std::list<MembershipModel>::iterator iter = Memberships.begin(); iter != Memberships.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (Origination.notNull()) { writer.String("Origination"); writeLoginIdentityProviderEnumJSON(Origination, writer); }
    if (PlayerId.length() > 0) { writer.String("PlayerId"); writer.String(PlayerId.c_str()); }
    if (PublisherId.length() > 0) { writer.String("PublisherId"); writer.String(PublisherId.c_str()); }
    if (!PushNotificationRegistrations.empty()) {
        writer.String("PushNotificationRegistrations");
        writer.StartArray();
        for (std::list<PushNotificationRegistrationModel>::iterator iter = PushNotificationRegistrations.begin(); iter != PushNotificationRegistrations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Statistics.empty()) {
        writer.String("Statistics");
        writer.StartArray();
        for (std::list<StatisticModel>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Tags.empty()) {
        writer.String("Tags");
        writer.StartArray();
        for (std::list<TagModel>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    if (TotalValueToDateInUSD.notNull()) { writer.String("TotalValueToDateInUSD"); writer.Uint(TotalValueToDateInUSD); }
    if (!ValuesToDate.empty()) {
        writer.String("ValuesToDate");
        writer.StartArray();
        for (std::list<ValueToDateModel>::iterator iter = ValuesToDate.begin(); iter != ValuesToDate.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool PlayerProfileModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AdCampaignAttributions_member = obj.FindMember("AdCampaignAttributions");
    if (AdCampaignAttributions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AdCampaignAttributions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AdCampaignAttributions.push_back(AdCampaignAttributionModel(memberList[i]));
        }
    }
    const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
    if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
    const Value::ConstMemberIterator BannedUntil_member = obj.FindMember("BannedUntil");
    if (BannedUntil_member != obj.MemberEnd() && !BannedUntil_member->value.IsNull()) BannedUntil = readDatetime(BannedUntil_member->value);
    const Value::ConstMemberIterator ContactEmailAddresses_member = obj.FindMember("ContactEmailAddresses");
    if (ContactEmailAddresses_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ContactEmailAddresses_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ContactEmailAddresses.push_back(ContactEmailInfoModel(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator ExperimentVariants_member = obj.FindMember("ExperimentVariants");
    if (ExperimentVariants_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ExperimentVariants_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ExperimentVariants.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
    if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
    const Value::ConstMemberIterator LinkedAccounts_member = obj.FindMember("LinkedAccounts");
    if (LinkedAccounts_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = LinkedAccounts_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            LinkedAccounts.push_back(LinkedPlatformAccountModel(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Locations_member = obj.FindMember("Locations");
    if (Locations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Locations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Locations.push_back(LocationModel(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Memberships_member = obj.FindMember("Memberships");
    if (Memberships_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Memberships_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Memberships.push_back(MembershipModel(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
    if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readLoginIdentityProviderFromValue(Origination_member->value);
    const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
    if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
    const Value::ConstMemberIterator PublisherId_member = obj.FindMember("PublisherId");
    if (PublisherId_member != obj.MemberEnd() && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();
    const Value::ConstMemberIterator PushNotificationRegistrations_member = obj.FindMember("PushNotificationRegistrations");
    if (PushNotificationRegistrations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PushNotificationRegistrations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PushNotificationRegistrations.push_back(PushNotificationRegistrationModel(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Statistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Statistics.push_back(StatisticModel(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(TagModel(memberList[i]));
        }
    }
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator TotalValueToDateInUSD_member = obj.FindMember("TotalValueToDateInUSD");
    if (TotalValueToDateInUSD_member != obj.MemberEnd() && !TotalValueToDateInUSD_member->value.IsNull()) TotalValueToDateInUSD = TotalValueToDateInUSD_member->value.GetUint();
    const Value::ConstMemberIterator ValuesToDate_member = obj.FindMember("ValuesToDate");
    if (ValuesToDate_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ValuesToDate_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ValuesToDate.push_back(ValueToDateModel(memberList[i]));
        }
    }

    return true;
}

PlayStreamEventEnvelopeModel::~PlayStreamEventEnvelopeModel()
{

}

void PlayStreamEventEnvelopeModel::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (EntityId.length() > 0) { writer.String("EntityId"); writer.String(EntityId.c_str()); }
    if (EntityType.length() > 0) { writer.String("EntityType"); writer.String(EntityType.c_str()); }
    if (EventData.length() > 0) { writer.String("EventData"); writer.String(EventData.c_str()); }
    if (EventName.length() > 0) { writer.String("EventName"); writer.String(EventName.c_str()); }
    if (EventNamespace.length() > 0) { writer.String("EventNamespace"); writer.String(EventNamespace.c_str()); }
    if (EventSettings.length() > 0) { writer.String("EventSettings"); writer.String(EventSettings.c_str()); }
    writer.EndObject();
}

bool PlayStreamEventEnvelopeModel::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator EntityId_member = obj.FindMember("EntityId");
    if (EntityId_member != obj.MemberEnd() && !EntityId_member->value.IsNull()) EntityId = EntityId_member->value.GetString();
    const Value::ConstMemberIterator EntityType_member = obj.FindMember("EntityType");
    if (EntityType_member != obj.MemberEnd() && !EntityType_member->value.IsNull()) EntityType = EntityType_member->value.GetString();
    const Value::ConstMemberIterator EventData_member = obj.FindMember("EventData");
    if (EventData_member != obj.MemberEnd() && !EventData_member->value.IsNull()) EventData = EventData_member->value.GetString();
    const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
    if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::ConstMemberIterator EventNamespace_member = obj.FindMember("EventNamespace");
    if (EventNamespace_member != obj.MemberEnd() && !EventNamespace_member->value.IsNull()) EventNamespace = EventNamespace_member->value.GetString();
    const Value::ConstMemberIterator EventSettings_member = obj.FindMember("EventSettings");
    if (EventSettings_member != obj.MemberEnd() && !EventSettings_member->value.IsNull()) EventSettings = EventSettings_member->value.GetString();

    return true;
}

PostFunctionResultForEntityTriggeredActionRequest::~PostFunctionResultForEntityTriggeredActionRequest()
{

}

void PostFunctionResultForEntityTriggeredActionRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("FunctionResult"); FunctionResult.writeJSON(writer);
    writer.EndObject();
}

bool PostFunctionResultForEntityTriggeredActionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
    if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = ExecuteFunctionResult(FunctionResult_member->value);

    return true;
}

PostFunctionResultForFunctionExecutionRequest::~PostFunctionResultForFunctionExecutionRequest()
{

}

void PostFunctionResultForFunctionExecutionRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("FunctionResult"); FunctionResult.writeJSON(writer);
    writer.EndObject();
}

bool PostFunctionResultForFunctionExecutionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
    if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = ExecuteFunctionResult(FunctionResult_member->value);

    return true;
}

PostFunctionResultForPlayerTriggeredActionRequest::~PostFunctionResultForPlayerTriggeredActionRequest()
{
    if (Entity != NULL) delete Entity;
    if (PlayStreamEventEnvelope != NULL) delete PlayStreamEventEnvelope;

}

void PostFunctionResultForPlayerTriggeredActionRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("FunctionResult"); FunctionResult.writeJSON(writer);
    writer.String("PlayerProfile"); PlayerProfile.writeJSON(writer);
    if (PlayStreamEventEnvelope != NULL) { writer.String("PlayStreamEventEnvelope"); PlayStreamEventEnvelope->writeJSON(writer); }
    writer.EndObject();
}

bool PostFunctionResultForPlayerTriggeredActionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
    if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = ExecuteFunctionResult(FunctionResult_member->value);
    const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
    if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = PlayerProfileModel(PlayerProfile_member->value);
    const Value::ConstMemberIterator PlayStreamEventEnvelope_member = obj.FindMember("PlayStreamEventEnvelope");
    if (PlayStreamEventEnvelope_member != obj.MemberEnd() && !PlayStreamEventEnvelope_member->value.IsNull()) PlayStreamEventEnvelope = new PlayStreamEventEnvelopeModel(PlayStreamEventEnvelope_member->value);

    return true;
}

PostFunctionResultForScheduledTaskRequest::~PostFunctionResultForScheduledTaskRequest()
{

}

void PostFunctionResultForScheduledTaskRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("Entity"); Entity.writeJSON(writer);
    writer.String("FunctionResult"); FunctionResult.writeJSON(writer);
    writer.String("ScheduledTaskId"); ScheduledTaskId.writeJSON(writer);
    writer.EndObject();
}

bool PostFunctionResultForScheduledTaskRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = EntityKey(Entity_member->value);
    const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
    if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = ExecuteFunctionResult(FunctionResult_member->value);
    const Value::ConstMemberIterator ScheduledTaskId_member = obj.FindMember("ScheduledTaskId");
    if (ScheduledTaskId_member != obj.MemberEnd() && !ScheduledTaskId_member->value.IsNull()) ScheduledTaskId = NameIdentifier(ScheduledTaskId_member->value);

    return true;
}

RegisterHttpFunctionRequest::~RegisterHttpFunctionRequest()
{

}

void RegisterHttpFunctionRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("FunctionName"); writer.String(FunctionName.c_str());
    writer.String("FunctionUrl"); writer.String(FunctionUrl.c_str());
    writer.EndObject();
}

bool RegisterHttpFunctionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionUrl_member = obj.FindMember("FunctionUrl");
    if (FunctionUrl_member != obj.MemberEnd() && !FunctionUrl_member->value.IsNull()) FunctionUrl = FunctionUrl_member->value.GetString();

    return true;
}

RegisterQueuedFunctionRequest::~RegisterQueuedFunctionRequest()
{

}

void RegisterQueuedFunctionRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ConnectionString"); writer.String(ConnectionString.c_str());
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("FunctionName"); writer.String(FunctionName.c_str());
    writer.String("QueueName"); writer.String(QueueName.c_str());
    writer.EndObject();
}

bool RegisterQueuedFunctionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ConnectionString_member = obj.FindMember("ConnectionString");
    if (ConnectionString_member != obj.MemberEnd() && !ConnectionString_member->value.IsNull()) ConnectionString = ConnectionString_member->value.GetString();
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator QueueName_member = obj.FindMember("QueueName");
    if (QueueName_member != obj.MemberEnd() && !QueueName_member->value.IsNull()) QueueName = QueueName_member->value.GetString();

    return true;
}
void PlayFab::CloudScriptModels::writeTriggerTypeEnumJSON(TriggerType enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case TriggerTypeHTTP: writer.String("HTTP"); break;
    case TriggerTypeQueue: writer.String("Queue"); break;

    }
}

TriggerType PlayFab::CloudScriptModels::readTriggerTypeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, TriggerType> _TriggerTypeMap;
    if (_TriggerTypeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _TriggerTypeMap["HTTP"] = TriggerTypeHTTP;
        _TriggerTypeMap["Queue"] = TriggerTypeQueue;

    }

    auto output = _TriggerTypeMap.find(obj.GetString());
    if (output != _TriggerTypeMap.end())
        return output->second;

    return TriggerTypeHTTP; // Basically critical fail
}

UnregisterFunctionRequest::~UnregisterFunctionRequest()
{

}

void UnregisterFunctionRequest::writeJSON(PFStringJsonWriter& writer)
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
    writer.String("FunctionName"); writer.String(FunctionName.c_str());
    writer.EndObject();
}

bool UnregisterFunctionRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();

    return true;
}

