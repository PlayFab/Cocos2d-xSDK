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
    writer.String("AttributedAt"); writeDatetime(AttributedAt, writer);
    if (CampaignId.length() > 0) { writer.String("CampaignId"); writer.String(CampaignId.c_str()); }
    if (Platform.length() > 0) { writer.String("Platform"); writer.String(Platform.c_str()); }
    writer.EndObject();
}

bool AdCampaignAttribution::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AttributedAt_member = obj.FindMember("AttributedAt");
    if (AttributedAt_member != obj.MemberEnd() && !AttributedAt_member->value.IsNull()) AttributedAt = readDatetime(AttributedAt_member->value);
    const Value::ConstMemberIterator CampaignId_member = obj.FindMember("CampaignId");
    if (CampaignId_member != obj.MemberEnd() && !CampaignId_member->value.IsNull()) CampaignId = CampaignId_member->value.GetString();
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();

    return true;
}

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

AddCharacterVirtualCurrencyRequest::~AddCharacterVirtualCurrencyRequest()
{

}

void AddCharacterVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Amount"); writer.Int(Amount);
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.EndObject();
}

bool AddCharacterVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
    if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

    return true;
}

AddFriendRequest::~AddFriendRequest()
{

}

void AddFriendRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (FriendEmail.length() > 0) { writer.String("FriendEmail"); writer.String(FriendEmail.c_str()); }
    if (FriendPlayFabId.length() > 0) { writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str()); }
    if (FriendTitleDisplayName.length() > 0) { writer.String("FriendTitleDisplayName"); writer.String(FriendTitleDisplayName.c_str()); }
    if (FriendUsername.length() > 0) { writer.String("FriendUsername"); writer.String(FriendUsername.c_str()); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool AddFriendRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FriendEmail_member = obj.FindMember("FriendEmail");
    if (FriendEmail_member != obj.MemberEnd() && !FriendEmail_member->value.IsNull()) FriendEmail = FriendEmail_member->value.GetString();
    const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::ConstMemberIterator FriendTitleDisplayName_member = obj.FindMember("FriendTitleDisplayName");
    if (FriendTitleDisplayName_member != obj.MemberEnd() && !FriendTitleDisplayName_member->value.IsNull()) FriendTitleDisplayName = FriendTitleDisplayName_member->value.GetString();
    const Value::ConstMemberIterator FriendUsername_member = obj.FindMember("FriendUsername");
    if (FriendUsername_member != obj.MemberEnd() && !FriendUsername_member->value.IsNull()) FriendUsername = FriendUsername_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
    writer.EndObject();
}

bool AddSharedGroupMembersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

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
    writer.String("Amount"); writer.Int(Amount);
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.EndObject();
}

bool AddUserVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
    if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

    return true;
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

AdvancedPushPlatformMsg::~AdvancedPushPlatformMsg()
{

}

void AdvancedPushPlatformMsg::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Json"); writer.String(Json.c_str());
    writer.String("Platform"); writePushNotificationPlatformEnumJSON(Platform, writer);
    writer.EndObject();
}

bool AdvancedPushPlatformMsg::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Json_member = obj.FindMember("Json");
    if (Json_member != obj.MemberEnd() && !Json_member->value.IsNull()) Json = Json_member->value.GetString();
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushNotificationPlatformFromValue(Platform_member->value);

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

UserFacebookInstantGamesIdInfo::~UserFacebookInstantGamesIdInfo()
{

}

void UserFacebookInstantGamesIdInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (FacebookInstantGamesId.length() > 0) { writer.String("FacebookInstantGamesId"); writer.String(FacebookInstantGamesId.c_str()); }
    writer.EndObject();
}

bool UserFacebookInstantGamesIdInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FacebookInstantGamesId_member = obj.FindMember("FacebookInstantGamesId");
    if (FacebookInstantGamesId_member != obj.MemberEnd() && !FacebookInstantGamesId_member->value.IsNull()) FacebookInstantGamesId = FacebookInstantGamesId_member->value.GetString();

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

UserGoogleInfo::~UserGoogleInfo()
{

}

void UserGoogleInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (GoogleEmail.length() > 0) { writer.String("GoogleEmail"); writer.String(GoogleEmail.c_str()); }
    if (GoogleGender.length() > 0) { writer.String("GoogleGender"); writer.String(GoogleGender.c_str()); }
    if (GoogleId.length() > 0) { writer.String("GoogleId"); writer.String(GoogleId.c_str()); }
    if (GoogleLocale.length() > 0) { writer.String("GoogleLocale"); writer.String(GoogleLocale.c_str()); }
    writer.EndObject();
}

bool UserGoogleInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GoogleEmail_member = obj.FindMember("GoogleEmail");
    if (GoogleEmail_member != obj.MemberEnd() && !GoogleEmail_member->value.IsNull()) GoogleEmail = GoogleEmail_member->value.GetString();
    const Value::ConstMemberIterator GoogleGender_member = obj.FindMember("GoogleGender");
    if (GoogleGender_member != obj.MemberEnd() && !GoogleGender_member->value.IsNull()) GoogleGender = GoogleGender_member->value.GetString();
    const Value::ConstMemberIterator GoogleId_member = obj.FindMember("GoogleId");
    if (GoogleId_member != obj.MemberEnd() && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
    const Value::ConstMemberIterator GoogleLocale_member = obj.FindMember("GoogleLocale");
    if (GoogleLocale_member != obj.MemberEnd() && !GoogleLocale_member->value.IsNull()) GoogleLocale = GoogleLocale_member->value.GetString();

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

UserNintendoSwitchDeviceIdInfo::~UserNintendoSwitchDeviceIdInfo()
{

}

void UserNintendoSwitchDeviceIdInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (NintendoSwitchDeviceId.length() > 0) { writer.String("NintendoSwitchDeviceId"); writer.String(NintendoSwitchDeviceId.c_str()); }
    writer.EndObject();
}

bool UserNintendoSwitchDeviceIdInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator NintendoSwitchDeviceId_member = obj.FindMember("NintendoSwitchDeviceId");
    if (NintendoSwitchDeviceId_member != obj.MemberEnd() && !NintendoSwitchDeviceId_member->value.IsNull()) NintendoSwitchDeviceId = NintendoSwitchDeviceId_member->value.GetString();

    return true;
}

UserOpenIdInfo::~UserOpenIdInfo()
{

}

void UserOpenIdInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ConnectionId.length() > 0) { writer.String("ConnectionId"); writer.String(ConnectionId.c_str()); }
    if (Issuer.length() > 0) { writer.String("Issuer"); writer.String(Issuer.c_str()); }
    if (Subject.length() > 0) { writer.String("Subject"); writer.String(Subject.c_str()); }
    writer.EndObject();
}

bool UserOpenIdInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ConnectionId_member = obj.FindMember("ConnectionId");
    if (ConnectionId_member != obj.MemberEnd() && !ConnectionId_member->value.IsNull()) ConnectionId = ConnectionId_member->value.GetString();
    const Value::ConstMemberIterator Issuer_member = obj.FindMember("Issuer");
    if (Issuer_member != obj.MemberEnd() && !Issuer_member->value.IsNull()) Issuer = Issuer_member->value.GetString();
    const Value::ConstMemberIterator Subject_member = obj.FindMember("Subject");
    if (Subject_member != obj.MemberEnd() && !Subject_member->value.IsNull()) Subject = Subject_member->value.GetString();

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

UserSteamInfo::~UserSteamInfo()
{

}

void UserSteamInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (SteamActivationStatus.notNull()) { writer.String("SteamActivationStatus"); writeTitleActivationStatusEnumJSON(SteamActivationStatus, writer); }
    if (SteamCountry.length() > 0) { writer.String("SteamCountry"); writer.String(SteamCountry.c_str()); }
    if (SteamCurrency.notNull()) { writer.String("SteamCurrency"); writeCurrencyEnumJSON(SteamCurrency, writer); }
    if (SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
    writer.EndObject();
}

bool UserSteamInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SteamActivationStatus_member = obj.FindMember("SteamActivationStatus");
    if (SteamActivationStatus_member != obj.MemberEnd() && !SteamActivationStatus_member->value.IsNull()) SteamActivationStatus = readTitleActivationStatusFromValue(SteamActivationStatus_member->value);
    const Value::ConstMemberIterator SteamCountry_member = obj.FindMember("SteamCountry");
    if (SteamCountry_member != obj.MemberEnd() && !SteamCountry_member->value.IsNull()) SteamCountry = SteamCountry_member->value.GetString();
    const Value::ConstMemberIterator SteamCurrency_member = obj.FindMember("SteamCurrency");
    if (SteamCurrency_member != obj.MemberEnd() && !SteamCurrency_member->value.IsNull()) SteamCurrency = readCurrencyFromValue(SteamCurrency_member->value);
    const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
    if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();

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
    case UserOriginationWindowsHello: writer.String("WindowsHello"); break;
    case UserOriginationServerCustomId: writer.String("ServerCustomId"); break;
    case UserOriginationNintendoSwitchDeviceId: writer.String("NintendoSwitchDeviceId"); break;
    case UserOriginationFacebookInstantGamesId: writer.String("FacebookInstantGamesId"); break;
    case UserOriginationOpenIdConnect: writer.String("OpenIdConnect"); break;

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
        _UserOriginationMap["WindowsHello"] = UserOriginationWindowsHello;
        _UserOriginationMap["ServerCustomId"] = UserOriginationServerCustomId;
        _UserOriginationMap["NintendoSwitchDeviceId"] = UserOriginationNintendoSwitchDeviceId;
        _UserOriginationMap["FacebookInstantGamesId"] = UserOriginationFacebookInstantGamesId;
        _UserOriginationMap["OpenIdConnect"] = UserOriginationOpenIdConnect;

    }

    auto output = _UserOriginationMap.find(obj.GetString());
    if (output != _UserOriginationMap.end())
        return output->second;

    return UserOriginationOrganic; // Basically critical fail
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

UserTitleInfo::~UserTitleInfo()
{
    if (TitlePlayerAccount != NULL) delete TitlePlayerAccount;

}

void UserTitleInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AvatarUrl.length() > 0) { writer.String("AvatarUrl"); writer.String(AvatarUrl.c_str()); }
    writer.String("Created"); writeDatetime(Created, writer);
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (FirstLogin.notNull()) { writer.String("FirstLogin"); writeDatetime(FirstLogin, writer); }
    if (isBanned.notNull()) { writer.String("isBanned"); writer.Bool(isBanned); }
    if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
    if (Origination.notNull()) { writer.String("Origination"); writeUserOriginationEnumJSON(Origination, writer); }
    if (TitlePlayerAccount != NULL) { writer.String("TitlePlayerAccount"); TitlePlayerAccount->writeJSON(writer); }
    writer.EndObject();
}

bool UserTitleInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
    if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator FirstLogin_member = obj.FindMember("FirstLogin");
    if (FirstLogin_member != obj.MemberEnd() && !FirstLogin_member->value.IsNull()) FirstLogin = readDatetime(FirstLogin_member->value);
    const Value::ConstMemberIterator isBanned_member = obj.FindMember("isBanned");
    if (isBanned_member != obj.MemberEnd() && !isBanned_member->value.IsNull()) isBanned = isBanned_member->value.GetBool();
    const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
    if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
    const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
    if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readUserOriginationFromValue(Origination_member->value);
    const Value::ConstMemberIterator TitlePlayerAccount_member = obj.FindMember("TitlePlayerAccount");
    if (TitlePlayerAccount_member != obj.MemberEnd() && !TitlePlayerAccount_member->value.IsNull()) TitlePlayerAccount = new EntityKey(TitlePlayerAccount_member->value);

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

UserWindowsHelloInfo::~UserWindowsHelloInfo()
{

}

void UserWindowsHelloInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (WindowsHelloDeviceName.length() > 0) { writer.String("WindowsHelloDeviceName"); writer.String(WindowsHelloDeviceName.c_str()); }
    if (WindowsHelloPublicKeyHash.length() > 0) { writer.String("WindowsHelloPublicKeyHash"); writer.String(WindowsHelloPublicKeyHash.c_str()); }
    writer.EndObject();
}

bool UserWindowsHelloInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator WindowsHelloDeviceName_member = obj.FindMember("WindowsHelloDeviceName");
    if (WindowsHelloDeviceName_member != obj.MemberEnd() && !WindowsHelloDeviceName_member->value.IsNull()) WindowsHelloDeviceName = WindowsHelloDeviceName_member->value.GetString();
    const Value::ConstMemberIterator WindowsHelloPublicKeyHash_member = obj.FindMember("WindowsHelloPublicKeyHash");
    if (WindowsHelloPublicKeyHash_member != obj.MemberEnd() && !WindowsHelloPublicKeyHash_member->value.IsNull()) WindowsHelloPublicKeyHash = WindowsHelloPublicKeyHash_member->value.GetString();

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

UserAccountInfo::~UserAccountInfo()
{
    if (AndroidDeviceInfo != NULL) delete AndroidDeviceInfo;
    if (CustomIdInfo != NULL) delete CustomIdInfo;
    if (FacebookInfo != NULL) delete FacebookInfo;
    if (FacebookInstantGamesIdInfo != NULL) delete FacebookInstantGamesIdInfo;
    if (GameCenterInfo != NULL) delete GameCenterInfo;
    if (GoogleInfo != NULL) delete GoogleInfo;
    if (IosDeviceInfo != NULL) delete IosDeviceInfo;
    if (KongregateInfo != NULL) delete KongregateInfo;
    if (NintendoSwitchDeviceIdInfo != NULL) delete NintendoSwitchDeviceIdInfo;
    if (PrivateInfo != NULL) delete PrivateInfo;
    if (PsnInfo != NULL) delete PsnInfo;
    if (SteamInfo != NULL) delete SteamInfo;
    if (TitleInfo != NULL) delete TitleInfo;
    if (TwitchInfo != NULL) delete TwitchInfo;
    if (WindowsHelloInfo != NULL) delete WindowsHelloInfo;
    if (XboxInfo != NULL) delete XboxInfo;

}

void UserAccountInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AndroidDeviceInfo != NULL) { writer.String("AndroidDeviceInfo"); AndroidDeviceInfo->writeJSON(writer); }
    writer.String("Created"); writeDatetime(Created, writer);
    if (CustomIdInfo != NULL) { writer.String("CustomIdInfo"); CustomIdInfo->writeJSON(writer); }
    if (FacebookInfo != NULL) { writer.String("FacebookInfo"); FacebookInfo->writeJSON(writer); }
    if (FacebookInstantGamesIdInfo != NULL) { writer.String("FacebookInstantGamesIdInfo"); FacebookInstantGamesIdInfo->writeJSON(writer); }
    if (GameCenterInfo != NULL) { writer.String("GameCenterInfo"); GameCenterInfo->writeJSON(writer); }
    if (GoogleInfo != NULL) { writer.String("GoogleInfo"); GoogleInfo->writeJSON(writer); }
    if (IosDeviceInfo != NULL) { writer.String("IosDeviceInfo"); IosDeviceInfo->writeJSON(writer); }
    if (KongregateInfo != NULL) { writer.String("KongregateInfo"); KongregateInfo->writeJSON(writer); }
    if (NintendoSwitchDeviceIdInfo != NULL) { writer.String("NintendoSwitchDeviceIdInfo"); NintendoSwitchDeviceIdInfo->writeJSON(writer); }
    if (!OpenIdInfo.empty()) {
        writer.String("OpenIdInfo");
        writer.StartArray();
        for (std::list<UserOpenIdInfo>::iterator iter = OpenIdInfo.begin(); iter != OpenIdInfo.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (PrivateInfo != NULL) { writer.String("PrivateInfo"); PrivateInfo->writeJSON(writer); }
    if (PsnInfo != NULL) { writer.String("PsnInfo"); PsnInfo->writeJSON(writer); }
    if (SteamInfo != NULL) { writer.String("SteamInfo"); SteamInfo->writeJSON(writer); }
    if (TitleInfo != NULL) { writer.String("TitleInfo"); TitleInfo->writeJSON(writer); }
    if (TwitchInfo != NULL) { writer.String("TwitchInfo"); TwitchInfo->writeJSON(writer); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (WindowsHelloInfo != NULL) { writer.String("WindowsHelloInfo"); WindowsHelloInfo->writeJSON(writer); }
    if (XboxInfo != NULL) { writer.String("XboxInfo"); XboxInfo->writeJSON(writer); }
    writer.EndObject();
}

bool UserAccountInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AndroidDeviceInfo_member = obj.FindMember("AndroidDeviceInfo");
    if (AndroidDeviceInfo_member != obj.MemberEnd() && !AndroidDeviceInfo_member->value.IsNull()) AndroidDeviceInfo = new UserAndroidDeviceInfo(AndroidDeviceInfo_member->value);
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator CustomIdInfo_member = obj.FindMember("CustomIdInfo");
    if (CustomIdInfo_member != obj.MemberEnd() && !CustomIdInfo_member->value.IsNull()) CustomIdInfo = new UserCustomIdInfo(CustomIdInfo_member->value);
    const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
    if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
    const Value::ConstMemberIterator FacebookInstantGamesIdInfo_member = obj.FindMember("FacebookInstantGamesIdInfo");
    if (FacebookInstantGamesIdInfo_member != obj.MemberEnd() && !FacebookInstantGamesIdInfo_member->value.IsNull()) FacebookInstantGamesIdInfo = new UserFacebookInstantGamesIdInfo(FacebookInstantGamesIdInfo_member->value);
    const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
    if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
    const Value::ConstMemberIterator GoogleInfo_member = obj.FindMember("GoogleInfo");
    if (GoogleInfo_member != obj.MemberEnd() && !GoogleInfo_member->value.IsNull()) GoogleInfo = new UserGoogleInfo(GoogleInfo_member->value);
    const Value::ConstMemberIterator IosDeviceInfo_member = obj.FindMember("IosDeviceInfo");
    if (IosDeviceInfo_member != obj.MemberEnd() && !IosDeviceInfo_member->value.IsNull()) IosDeviceInfo = new UserIosDeviceInfo(IosDeviceInfo_member->value);
    const Value::ConstMemberIterator KongregateInfo_member = obj.FindMember("KongregateInfo");
    if (KongregateInfo_member != obj.MemberEnd() && !KongregateInfo_member->value.IsNull()) KongregateInfo = new UserKongregateInfo(KongregateInfo_member->value);
    const Value::ConstMemberIterator NintendoSwitchDeviceIdInfo_member = obj.FindMember("NintendoSwitchDeviceIdInfo");
    if (NintendoSwitchDeviceIdInfo_member != obj.MemberEnd() && !NintendoSwitchDeviceIdInfo_member->value.IsNull()) NintendoSwitchDeviceIdInfo = new UserNintendoSwitchDeviceIdInfo(NintendoSwitchDeviceIdInfo_member->value);
    const Value::ConstMemberIterator OpenIdInfo_member = obj.FindMember("OpenIdInfo");
    if (OpenIdInfo_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = OpenIdInfo_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            OpenIdInfo.push_back(UserOpenIdInfo(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator PrivateInfo_member = obj.FindMember("PrivateInfo");
    if (PrivateInfo_member != obj.MemberEnd() && !PrivateInfo_member->value.IsNull()) PrivateInfo = new UserPrivateAccountInfo(PrivateInfo_member->value);
    const Value::ConstMemberIterator PsnInfo_member = obj.FindMember("PsnInfo");
    if (PsnInfo_member != obj.MemberEnd() && !PsnInfo_member->value.IsNull()) PsnInfo = new UserPsnInfo(PsnInfo_member->value);
    const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
    if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
    const Value::ConstMemberIterator TitleInfo_member = obj.FindMember("TitleInfo");
    if (TitleInfo_member != obj.MemberEnd() && !TitleInfo_member->value.IsNull()) TitleInfo = new UserTitleInfo(TitleInfo_member->value);
    const Value::ConstMemberIterator TwitchInfo_member = obj.FindMember("TwitchInfo");
    if (TwitchInfo_member != obj.MemberEnd() && !TwitchInfo_member->value.IsNull()) TwitchInfo = new UserTwitchInfo(TwitchInfo_member->value);
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator WindowsHelloInfo_member = obj.FindMember("WindowsHelloInfo");
    if (WindowsHelloInfo_member != obj.MemberEnd() && !WindowsHelloInfo_member->value.IsNull()) WindowsHelloInfo = new UserWindowsHelloInfo(WindowsHelloInfo_member->value);
    const Value::ConstMemberIterator XboxInfo_member = obj.FindMember("XboxInfo");
    if (XboxInfo_member != obj.MemberEnd() && !XboxInfo_member->value.IsNull()) XboxInfo = new UserXboxInfo(XboxInfo_member->value);

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
    writer.String("AchievementName"); writer.String(AchievementName.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("Result"); writer.Bool(Result);
    writer.EndObject();
}

bool AwardSteamAchievementItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AchievementName_member = obj.FindMember("AchievementName");
    if (AchievementName_member != obj.MemberEnd() && !AchievementName_member->value.IsNull()) AchievementName = AchievementName_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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
    writer.String("Active"); writer.Bool(Active);
    if (BanId.length() > 0) { writer.String("BanId"); writer.String(BanId.c_str()); }
    if (Created.notNull()) { writer.String("Created"); writeDatetime(Created, writer); }
    if (Expires.notNull()) { writer.String("Expires"); writeDatetime(Expires, writer); }
    if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
    if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
    writer.EndObject();
}

bool BanInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
    if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();
    const Value::ConstMemberIterator BanId_member = obj.FindMember("BanId");
    if (BanId_member != obj.MemberEnd() && !BanId_member->value.IsNull()) BanId = BanId_member->value.GetString();
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
    if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
    const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
    if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
    const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
    if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
    if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();

    return true;
}

BanRequest::~BanRequest()
{

}

void BanRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DurationInHours.notNull()) { writer.String("DurationInHours"); writer.Uint(DurationInHours); }
    if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
    if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
    writer.EndObject();
}

bool BanRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DurationInHours_member = obj.FindMember("DurationInHours");
    if (DurationInHours_member != obj.MemberEnd() && !DurationInHours_member->value.IsNull()) DurationInHours = DurationInHours_member->value.GetUint();
    const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
    if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
    const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
    if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
    if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();

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
    if (!ItemContents.empty()) {
        writer.String("ItemContents");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = ItemContents.begin(); iter != ItemContents.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (KeyItemId.length() > 0) { writer.String("KeyItemId"); writer.String(KeyItemId.c_str()); }
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
    const Value::ConstMemberIterator ItemContents_member = obj.FindMember("ItemContents");
    if (ItemContents_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemContents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemContents.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator KeyItemId_member = obj.FindMember("KeyItemId");
    if (KeyItemId_member != obj.MemberEnd() && !KeyItemId_member->value.IsNull()) KeyItemId = KeyItemId_member->value.GetString();
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

CatalogItem::~CatalogItem()
{
    if (Bundle != NULL) delete Bundle;
    if (Consumable != NULL) delete Consumable;
    if (Container != NULL) delete Container;

}

void CatalogItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Bundle != NULL) { writer.String("Bundle"); Bundle->writeJSON(writer); }
    writer.String("CanBecomeCharacter"); writer.Bool(CanBecomeCharacter);
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (Consumable != NULL) { writer.String("Consumable"); Consumable->writeJSON(writer); }
    if (Container != NULL) { writer.String("Container"); Container->writeJSON(writer); }
    if (CustomData.length() > 0) { writer.String("CustomData"); writer.String(CustomData.c_str()); }
    if (Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    writer.String("InitialLimitedEditionCount"); writer.Int(InitialLimitedEditionCount);
    writer.String("IsLimitedEdition"); writer.Bool(IsLimitedEdition);
    writer.String("IsStackable"); writer.Bool(IsStackable);
    writer.String("IsTradable"); writer.Bool(IsTradable);
    if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
    writer.String("ItemId"); writer.String(ItemId.c_str());
    if (ItemImageUrl.length() > 0) { writer.String("ItemImageUrl"); writer.String(ItemImageUrl.c_str()); }
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
    if (!VirtualCurrencyPrices.empty()) {
        writer.String("VirtualCurrencyPrices");
        writer.StartObject();
        for (std::map<std::string, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.Uint(iter->second);
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool CatalogItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Bundle_member = obj.FindMember("Bundle");
    if (Bundle_member != obj.MemberEnd() && !Bundle_member->value.IsNull()) Bundle = new CatalogItemBundleInfo(Bundle_member->value);
    const Value::ConstMemberIterator CanBecomeCharacter_member = obj.FindMember("CanBecomeCharacter");
    if (CanBecomeCharacter_member != obj.MemberEnd() && !CanBecomeCharacter_member->value.IsNull()) CanBecomeCharacter = CanBecomeCharacter_member->value.GetBool();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator Consumable_member = obj.FindMember("Consumable");
    if (Consumable_member != obj.MemberEnd() && !Consumable_member->value.IsNull()) Consumable = new CatalogItemConsumableInfo(Consumable_member->value);
    const Value::ConstMemberIterator Container_member = obj.FindMember("Container");
    if (Container_member != obj.MemberEnd() && !Container_member->value.IsNull()) Container = new CatalogItemContainerInfo(Container_member->value);
    const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = CustomData_member->value.GetString();
    const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
    if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator InitialLimitedEditionCount_member = obj.FindMember("InitialLimitedEditionCount");
    if (InitialLimitedEditionCount_member != obj.MemberEnd() && !InitialLimitedEditionCount_member->value.IsNull()) InitialLimitedEditionCount = InitialLimitedEditionCount_member->value.GetInt();
    const Value::ConstMemberIterator IsLimitedEdition_member = obj.FindMember("IsLimitedEdition");
    if (IsLimitedEdition_member != obj.MemberEnd() && !IsLimitedEdition_member->value.IsNull()) IsLimitedEdition = IsLimitedEdition_member->value.GetBool();
    const Value::ConstMemberIterator IsStackable_member = obj.FindMember("IsStackable");
    if (IsStackable_member != obj.MemberEnd() && !IsStackable_member->value.IsNull()) IsStackable = IsStackable_member->value.GetBool();
    const Value::ConstMemberIterator IsTradable_member = obj.FindMember("IsTradable");
    if (IsTradable_member != obj.MemberEnd() && !IsTradable_member->value.IsNull()) IsTradable = IsTradable_member->value.GetBool();
    const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::ConstMemberIterator ItemImageUrl_member = obj.FindMember("ItemImageUrl");
    if (ItemImageUrl_member != obj.MemberEnd() && !ItemImageUrl_member->value.IsNull()) ItemImageUrl = ItemImageUrl_member->value.GetString();
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
    const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
    if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
        }
    }

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
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (CharacterName.length() > 0) { writer.String("CharacterName"); writer.String(CharacterName.c_str()); }
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.String("Position"); writer.Int(Position);
    writer.String("StatValue"); writer.Int(StatValue);
    writer.EndObject();
}

bool CharacterLeaderboardEntry::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
    if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();
    const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
    if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();

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
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ConsumeCount"); writer.Int(ConsumeCount);
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool ConsumeItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ConsumeCount_member = obj.FindMember("ConsumeCount");
    if (ConsumeCount_member != obj.MemberEnd() && !ConsumeCount_member->value.IsNull()) ConsumeCount = ConsumeCount_member->value.GetInt();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
void PlayFab::ServerModels::writeEmailVerificationStatusEnumJSON(EmailVerificationStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case EmailVerificationStatusUnverified: writer.String("Unverified"); break;
    case EmailVerificationStatusPending: writer.String("Pending"); break;
    case EmailVerificationStatusConfirmed: writer.String("Confirmed"); break;

    }
}

EmailVerificationStatus PlayFab::ServerModels::readEmailVerificationStatusFromValue(const rapidjson::Value& obj)
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

ContactEmailInfo::~ContactEmailInfo()
{

}

void ContactEmailInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (EmailAddress.length() > 0) { writer.String("EmailAddress"); writer.String(EmailAddress.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    if (VerificationStatus.notNull()) { writer.String("VerificationStatus"); writeEmailVerificationStatusEnumJSON(VerificationStatus, writer); }
    writer.EndObject();
}

bool ContactEmailInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator EmailAddress_member = obj.FindMember("EmailAddress");
    if (EmailAddress_member != obj.MemberEnd() && !EmailAddress_member->value.IsNull()) EmailAddress = EmailAddress_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator VerificationStatus_member = obj.FindMember("VerificationStatus");
    if (VerificationStatus_member != obj.MemberEnd() && !VerificationStatus_member->value.IsNull()) VerificationStatus = readEmailVerificationStatusFromValue(VerificationStatus_member->value);

    return true;
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
void PlayFab::ServerModels::writeContinentCodeEnumJSON(ContinentCode enumVal, PFStringJsonWriter& writer)
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

ContinentCode PlayFab::ServerModels::readContinentCodeFromValue(const rapidjson::Value& obj)
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
void PlayFab::ServerModels::writeCountryCodeEnumJSON(CountryCode enumVal, PFStringJsonWriter& writer)
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

CountryCode PlayFab::ServerModels::readCountryCodeFromValue(const rapidjson::Value& obj)
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
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("SaveCharacterInventory"); writer.Bool(SaveCharacterInventory);
    writer.EndObject();
}

bool DeleteCharacterFromUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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

DeletePlayerRequest::~DeletePlayerRequest()
{

}

void DeletePlayerRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool DeletePlayerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

DeletePlayerResult::~DeletePlayerResult()
{

}

void DeletePlayerResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool DeletePlayerResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

DeleteSharedGroupRequest::~DeleteSharedGroupRequest()
{

}

void DeleteSharedGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
    writer.EndObject();
}

bool DeleteSharedGroupRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

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

EmptyResponse::~EmptyResponse()
{

}

void EmptyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool EmptyResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

EntityTokenResponse::~EntityTokenResponse()
{
    if (Entity != NULL) delete Entity;

}

void EntityTokenResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Entity != NULL) { writer.String("Entity"); Entity->writeJSON(writer); }
    if (EntityToken.length() > 0) { writer.String("EntityToken"); writer.String(EntityToken.c_str()); }
    if (TokenExpiration.notNull()) { writer.String("TokenExpiration"); writeDatetime(TokenExpiration, writer); }
    writer.EndObject();
}

bool EntityTokenResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Entity_member = obj.FindMember("Entity");
    if (Entity_member != obj.MemberEnd() && !Entity_member->value.IsNull()) Entity = new EntityKey(Entity_member->value);
    const Value::ConstMemberIterator EntityToken_member = obj.FindMember("EntityToken");
    if (EntityToken_member != obj.MemberEnd() && !EntityToken_member->value.IsNull()) EntityToken = EntityToken_member->value.GetString();
    const Value::ConstMemberIterator TokenExpiration_member = obj.FindMember("TokenExpiration");
    if (TokenExpiration_member != obj.MemberEnd() && !TokenExpiration_member->value.IsNull()) TokenExpiration = readDatetime(TokenExpiration_member->value);

    return true;
}

EvaluateRandomResultTableRequest::~EvaluateRandomResultTableRequest()
{

}

void EvaluateRandomResultTableRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("TableId"); writer.String(TableId.c_str());
    writer.EndObject();
}

bool EvaluateRandomResultTableRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
    if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();

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

ExecuteCloudScriptServerRequest::~ExecuteCloudScriptServerRequest()
{

}

void ExecuteCloudScriptServerRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("FunctionName"); writer.String(FunctionName.c_str());
    if (FunctionParameter.notNull()) { writer.String("FunctionParameter"); FunctionParameter.writeJSON(writer); }
    if (GeneratePlayStreamEvent.notNull()) { writer.String("GeneratePlayStreamEvent"); writer.Bool(GeneratePlayStreamEvent); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (RevisionSelection.notNull()) { writer.String("RevisionSelection"); writeCloudScriptRevisionOptionEnumJSON(RevisionSelection, writer); }
    if (SpecificRevision.notNull()) { writer.String("SpecificRevision"); writer.Int(SpecificRevision); }
    writer.EndObject();
}

bool ExecuteCloudScriptServerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
    if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
    const Value::ConstMemberIterator FunctionParameter_member = obj.FindMember("FunctionParameter");
    if (FunctionParameter_member != obj.MemberEnd() && !FunctionParameter_member->value.IsNull()) FunctionParameter = MultitypeVar(FunctionParameter_member->value);
    const Value::ConstMemberIterator GeneratePlayStreamEvent_member = obj.FindMember("GeneratePlayStreamEvent");
    if (GeneratePlayStreamEvent_member != obj.MemberEnd() && !GeneratePlayStreamEvent_member->value.IsNull()) GeneratePlayStreamEvent = GeneratePlayStreamEvent_member->value.GetBool();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator RevisionSelection_member = obj.FindMember("RevisionSelection");
    if (RevisionSelection_member != obj.MemberEnd() && !RevisionSelection_member->value.IsNull()) RevisionSelection = readCloudScriptRevisionOptionFromValue(RevisionSelection_member->value);
    const Value::ConstMemberIterator SpecificRevision_member = obj.FindMember("SpecificRevision");
    if (SpecificRevision_member != obj.MemberEnd() && !SpecificRevision_member->value.IsNull()) SpecificRevision = SpecificRevision_member->value.GetInt();

    return true;
}

FacebookInstantGamesPlayFabIdPair::~FacebookInstantGamesPlayFabIdPair()
{

}

void FacebookInstantGamesPlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (FacebookInstantGamesId.length() > 0) { writer.String("FacebookInstantGamesId"); writer.String(FacebookInstantGamesId.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.EndObject();
}

bool FacebookInstantGamesPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FacebookInstantGamesId_member = obj.FindMember("FacebookInstantGamesId");
    if (FacebookInstantGamesId_member != obj.MemberEnd() && !FacebookInstantGamesId_member->value.IsNull()) FacebookInstantGamesId = FacebookInstantGamesId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    case LoginIdentityProviderWindowsHello: writer.String("WindowsHello"); break;
    case LoginIdentityProviderGameServer: writer.String("GameServer"); break;
    case LoginIdentityProviderCustomServer: writer.String("CustomServer"); break;
    case LoginIdentityProviderNintendoSwitch: writer.String("NintendoSwitch"); break;
    case LoginIdentityProviderFacebookInstantGames: writer.String("FacebookInstantGames"); break;
    case LoginIdentityProviderOpenIdConnect: writer.String("OpenIdConnect"); break;

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
        _LoginIdentityProviderMap["WindowsHello"] = LoginIdentityProviderWindowsHello;
        _LoginIdentityProviderMap["GameServer"] = LoginIdentityProviderGameServer;
        _LoginIdentityProviderMap["CustomServer"] = LoginIdentityProviderCustomServer;
        _LoginIdentityProviderMap["NintendoSwitch"] = LoginIdentityProviderNintendoSwitch;
        _LoginIdentityProviderMap["FacebookInstantGames"] = LoginIdentityProviderFacebookInstantGames;
        _LoginIdentityProviderMap["OpenIdConnect"] = LoginIdentityProviderOpenIdConnect;

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
void PlayFab::ServerModels::writeSubscriptionProviderStatusEnumJSON(SubscriptionProviderStatus enumVal, PFStringJsonWriter& writer)
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

SubscriptionProviderStatus PlayFab::ServerModels::readSubscriptionProviderStatusFromValue(const rapidjson::Value& obj)
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

FriendInfo::~FriendInfo()
{
    if (FacebookInfo != NULL) delete FacebookInfo;
    if (GameCenterInfo != NULL) delete GameCenterInfo;
    if (Profile != NULL) delete Profile;
    if (PSNInfo != NULL) delete PSNInfo;
    if (SteamInfo != NULL) delete SteamInfo;
    if (XboxInfo != NULL) delete XboxInfo;

}

void FriendInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CurrentMatchmakerLobbyId.length() > 0) { writer.String("CurrentMatchmakerLobbyId"); writer.String(CurrentMatchmakerLobbyId.c_str()); }
    if (FacebookInfo != NULL) { writer.String("FacebookInfo"); FacebookInfo->writeJSON(writer); }
    if (FriendPlayFabId.length() > 0) { writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str()); }
    if (GameCenterInfo != NULL) { writer.String("GameCenterInfo"); GameCenterInfo->writeJSON(writer); }
    if (Profile != NULL) { writer.String("Profile"); Profile->writeJSON(writer); }
    if (PSNInfo != NULL) { writer.String("PSNInfo"); PSNInfo->writeJSON(writer); }
    if (SteamInfo != NULL) { writer.String("SteamInfo"); SteamInfo->writeJSON(writer); }
    if (!Tags.empty()) {
        writer.String("Tags");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (XboxInfo != NULL) { writer.String("XboxInfo"); XboxInfo->writeJSON(writer); }
    writer.EndObject();
}

bool FriendInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CurrentMatchmakerLobbyId_member = obj.FindMember("CurrentMatchmakerLobbyId");
    if (CurrentMatchmakerLobbyId_member != obj.MemberEnd() && !CurrentMatchmakerLobbyId_member->value.IsNull()) CurrentMatchmakerLobbyId = CurrentMatchmakerLobbyId_member->value.GetString();
    const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
    if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
    const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
    if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
    const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
    if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new PlayerProfileModel(Profile_member->value);
    const Value::ConstMemberIterator PSNInfo_member = obj.FindMember("PSNInfo");
    if (PSNInfo_member != obj.MemberEnd() && !PSNInfo_member->value.IsNull()) PSNInfo = new UserPsnInfo(PSNInfo_member->value);
    const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
    if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
    if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator XboxInfo_member = obj.FindMember("XboxInfo");
    if (XboxInfo_member != obj.MemberEnd() && !XboxInfo_member->value.IsNull()) XboxInfo = new UserXboxInfo(XboxInfo_member->value);

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
void PlayFab::ServerModels::writeGenericErrorCodesEnumJSON(GenericErrorCodes enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case GenericErrorCodesSuccess: writer.String("Success"); break;
    case GenericErrorCodesUnkownError: writer.String("UnkownError"); break;
    case GenericErrorCodesInvalidParams: writer.String("InvalidParams"); break;
    case GenericErrorCodesAccountNotFound: writer.String("AccountNotFound"); break;
    case GenericErrorCodesAccountBanned: writer.String("AccountBanned"); break;
    case GenericErrorCodesInvalidUsernameOrPassword: writer.String("InvalidUsernameOrPassword"); break;
    case GenericErrorCodesInvalidTitleId: writer.String("InvalidTitleId"); break;
    case GenericErrorCodesInvalidEmailAddress: writer.String("InvalidEmailAddress"); break;
    case GenericErrorCodesEmailAddressNotAvailable: writer.String("EmailAddressNotAvailable"); break;
    case GenericErrorCodesInvalidUsername: writer.String("InvalidUsername"); break;
    case GenericErrorCodesInvalidPassword: writer.String("InvalidPassword"); break;
    case GenericErrorCodesUsernameNotAvailable: writer.String("UsernameNotAvailable"); break;
    case GenericErrorCodesInvalidSteamTicket: writer.String("InvalidSteamTicket"); break;
    case GenericErrorCodesAccountAlreadyLinked: writer.String("AccountAlreadyLinked"); break;
    case GenericErrorCodesLinkedAccountAlreadyClaimed: writer.String("LinkedAccountAlreadyClaimed"); break;
    case GenericErrorCodesInvalidFacebookToken: writer.String("InvalidFacebookToken"); break;
    case GenericErrorCodesAccountNotLinked: writer.String("AccountNotLinked"); break;
    case GenericErrorCodesFailedByPaymentProvider: writer.String("FailedByPaymentProvider"); break;
    case GenericErrorCodesCouponCodeNotFound: writer.String("CouponCodeNotFound"); break;
    case GenericErrorCodesInvalidContainerItem: writer.String("InvalidContainerItem"); break;
    case GenericErrorCodesContainerNotOwned: writer.String("ContainerNotOwned"); break;
    case GenericErrorCodesKeyNotOwned: writer.String("KeyNotOwned"); break;
    case GenericErrorCodesInvalidItemIdInTable: writer.String("InvalidItemIdInTable"); break;
    case GenericErrorCodesInvalidReceipt: writer.String("InvalidReceipt"); break;
    case GenericErrorCodesReceiptAlreadyUsed: writer.String("ReceiptAlreadyUsed"); break;
    case GenericErrorCodesReceiptCancelled: writer.String("ReceiptCancelled"); break;
    case GenericErrorCodesGameNotFound: writer.String("GameNotFound"); break;
    case GenericErrorCodesGameModeNotFound: writer.String("GameModeNotFound"); break;
    case GenericErrorCodesInvalidGoogleToken: writer.String("InvalidGoogleToken"); break;
    case GenericErrorCodesUserIsNotPartOfDeveloper: writer.String("UserIsNotPartOfDeveloper"); break;
    case GenericErrorCodesInvalidTitleForDeveloper: writer.String("InvalidTitleForDeveloper"); break;
    case GenericErrorCodesTitleNameConflicts: writer.String("TitleNameConflicts"); break;
    case GenericErrorCodesUserisNotValid: writer.String("UserisNotValid"); break;
    case GenericErrorCodesValueAlreadyExists: writer.String("ValueAlreadyExists"); break;
    case GenericErrorCodesBuildNotFound: writer.String("BuildNotFound"); break;
    case GenericErrorCodesPlayerNotInGame: writer.String("PlayerNotInGame"); break;
    case GenericErrorCodesInvalidTicket: writer.String("InvalidTicket"); break;
    case GenericErrorCodesInvalidDeveloper: writer.String("InvalidDeveloper"); break;
    case GenericErrorCodesInvalidOrderInfo: writer.String("InvalidOrderInfo"); break;
    case GenericErrorCodesRegistrationIncomplete: writer.String("RegistrationIncomplete"); break;
    case GenericErrorCodesInvalidPlatform: writer.String("InvalidPlatform"); break;
    case GenericErrorCodesUnknownError: writer.String("UnknownError"); break;
    case GenericErrorCodesSteamApplicationNotOwned: writer.String("SteamApplicationNotOwned"); break;
    case GenericErrorCodesWrongSteamAccount: writer.String("WrongSteamAccount"); break;
    case GenericErrorCodesTitleNotActivated: writer.String("TitleNotActivated"); break;
    case GenericErrorCodesRegistrationSessionNotFound: writer.String("RegistrationSessionNotFound"); break;
    case GenericErrorCodesNoSuchMod: writer.String("NoSuchMod"); break;
    case GenericErrorCodesFileNotFound: writer.String("FileNotFound"); break;
    case GenericErrorCodesDuplicateEmail: writer.String("DuplicateEmail"); break;
    case GenericErrorCodesItemNotFound: writer.String("ItemNotFound"); break;
    case GenericErrorCodesItemNotOwned: writer.String("ItemNotOwned"); break;
    case GenericErrorCodesItemNotRecycleable: writer.String("ItemNotRecycleable"); break;
    case GenericErrorCodesItemNotAffordable: writer.String("ItemNotAffordable"); break;
    case GenericErrorCodesInvalidVirtualCurrency: writer.String("InvalidVirtualCurrency"); break;
    case GenericErrorCodesWrongVirtualCurrency: writer.String("WrongVirtualCurrency"); break;
    case GenericErrorCodesWrongPrice: writer.String("WrongPrice"); break;
    case GenericErrorCodesNonPositiveValue: writer.String("NonPositiveValue"); break;
    case GenericErrorCodesInvalidRegion: writer.String("InvalidRegion"); break;
    case GenericErrorCodesRegionAtCapacity: writer.String("RegionAtCapacity"); break;
    case GenericErrorCodesServerFailedToStart: writer.String("ServerFailedToStart"); break;
    case GenericErrorCodesNameNotAvailable: writer.String("NameNotAvailable"); break;
    case GenericErrorCodesInsufficientFunds: writer.String("InsufficientFunds"); break;
    case GenericErrorCodesInvalidDeviceID: writer.String("InvalidDeviceID"); break;
    case GenericErrorCodesInvalidPushNotificationToken: writer.String("InvalidPushNotificationToken"); break;
    case GenericErrorCodesNoRemainingUses: writer.String("NoRemainingUses"); break;
    case GenericErrorCodesInvalidPaymentProvider: writer.String("InvalidPaymentProvider"); break;
    case GenericErrorCodesPurchaseInitializationFailure: writer.String("PurchaseInitializationFailure"); break;
    case GenericErrorCodesDuplicateUsername: writer.String("DuplicateUsername"); break;
    case GenericErrorCodesInvalidBuyerInfo: writer.String("InvalidBuyerInfo"); break;
    case GenericErrorCodesNoGameModeParamsSet: writer.String("NoGameModeParamsSet"); break;
    case GenericErrorCodesBodyTooLarge: writer.String("BodyTooLarge"); break;
    case GenericErrorCodesReservedWordInBody: writer.String("ReservedWordInBody"); break;
    case GenericErrorCodesInvalidTypeInBody: writer.String("InvalidTypeInBody"); break;
    case GenericErrorCodesInvalidRequest: writer.String("InvalidRequest"); break;
    case GenericErrorCodesReservedEventName: writer.String("ReservedEventName"); break;
    case GenericErrorCodesInvalidUserStatistics: writer.String("InvalidUserStatistics"); break;
    case GenericErrorCodesNotAuthenticated: writer.String("NotAuthenticated"); break;
    case GenericErrorCodesStreamAlreadyExists: writer.String("StreamAlreadyExists"); break;
    case GenericErrorCodesErrorCreatingStream: writer.String("ErrorCreatingStream"); break;
    case GenericErrorCodesStreamNotFound: writer.String("StreamNotFound"); break;
    case GenericErrorCodesInvalidAccount: writer.String("InvalidAccount"); break;
    case GenericErrorCodesPurchaseDoesNotExist: writer.String("PurchaseDoesNotExist"); break;
    case GenericErrorCodesInvalidPurchaseTransactionStatus: writer.String("InvalidPurchaseTransactionStatus"); break;
    case GenericErrorCodesAPINotEnabledForGameClientAccess: writer.String("APINotEnabledForGameClientAccess"); break;
    case GenericErrorCodesNoPushNotificationARNForTitle: writer.String("NoPushNotificationARNForTitle"); break;
    case GenericErrorCodesBuildAlreadyExists: writer.String("BuildAlreadyExists"); break;
    case GenericErrorCodesBuildPackageDoesNotExist: writer.String("BuildPackageDoesNotExist"); break;
    case GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle: writer.String("CustomAnalyticsEventsNotEnabledForTitle"); break;
    case GenericErrorCodesInvalidSharedGroupId: writer.String("InvalidSharedGroupId"); break;
    case GenericErrorCodesNotAuthorized: writer.String("NotAuthorized"); break;
    case GenericErrorCodesMissingTitleGoogleProperties: writer.String("MissingTitleGoogleProperties"); break;
    case GenericErrorCodesInvalidItemProperties: writer.String("InvalidItemProperties"); break;
    case GenericErrorCodesInvalidPSNAuthCode: writer.String("InvalidPSNAuthCode"); break;
    case GenericErrorCodesInvalidItemId: writer.String("InvalidItemId"); break;
    case GenericErrorCodesPushNotEnabledForAccount: writer.String("PushNotEnabledForAccount"); break;
    case GenericErrorCodesPushServiceError: writer.String("PushServiceError"); break;
    case GenericErrorCodesReceiptDoesNotContainInAppItems: writer.String("ReceiptDoesNotContainInAppItems"); break;
    case GenericErrorCodesReceiptContainsMultipleInAppItems: writer.String("ReceiptContainsMultipleInAppItems"); break;
    case GenericErrorCodesInvalidBundleID: writer.String("InvalidBundleID"); break;
    case GenericErrorCodesJavascriptException: writer.String("JavascriptException"); break;
    case GenericErrorCodesInvalidSessionTicket: writer.String("InvalidSessionTicket"); break;
    case GenericErrorCodesUnableToConnectToDatabase: writer.String("UnableToConnectToDatabase"); break;
    case GenericErrorCodesInternalServerError: writer.String("InternalServerError"); break;
    case GenericErrorCodesInvalidReportDate: writer.String("InvalidReportDate"); break;
    case GenericErrorCodesReportNotAvailable: writer.String("ReportNotAvailable"); break;
    case GenericErrorCodesDatabaseThroughputExceeded: writer.String("DatabaseThroughputExceeded"); break;
    case GenericErrorCodesInvalidGameTicket: writer.String("InvalidGameTicket"); break;
    case GenericErrorCodesExpiredGameTicket: writer.String("ExpiredGameTicket"); break;
    case GenericErrorCodesGameTicketDoesNotMatchLobby: writer.String("GameTicketDoesNotMatchLobby"); break;
    case GenericErrorCodesLinkedDeviceAlreadyClaimed: writer.String("LinkedDeviceAlreadyClaimed"); break;
    case GenericErrorCodesDeviceAlreadyLinked: writer.String("DeviceAlreadyLinked"); break;
    case GenericErrorCodesDeviceNotLinked: writer.String("DeviceNotLinked"); break;
    case GenericErrorCodesPartialFailure: writer.String("PartialFailure"); break;
    case GenericErrorCodesPublisherNotSet: writer.String("PublisherNotSet"); break;
    case GenericErrorCodesServiceUnavailable: writer.String("ServiceUnavailable"); break;
    case GenericErrorCodesVersionNotFound: writer.String("VersionNotFound"); break;
    case GenericErrorCodesRevisionNotFound: writer.String("RevisionNotFound"); break;
    case GenericErrorCodesInvalidPublisherId: writer.String("InvalidPublisherId"); break;
    case GenericErrorCodesDownstreamServiceUnavailable: writer.String("DownstreamServiceUnavailable"); break;
    case GenericErrorCodesAPINotIncludedInTitleUsageTier: writer.String("APINotIncludedInTitleUsageTier"); break;
    case GenericErrorCodesDAULimitExceeded: writer.String("DAULimitExceeded"); break;
    case GenericErrorCodesAPIRequestLimitExceeded: writer.String("APIRequestLimitExceeded"); break;
    case GenericErrorCodesInvalidAPIEndpoint: writer.String("InvalidAPIEndpoint"); break;
    case GenericErrorCodesBuildNotAvailable: writer.String("BuildNotAvailable"); break;
    case GenericErrorCodesConcurrentEditError: writer.String("ConcurrentEditError"); break;
    case GenericErrorCodesContentNotFound: writer.String("ContentNotFound"); break;
    case GenericErrorCodesCharacterNotFound: writer.String("CharacterNotFound"); break;
    case GenericErrorCodesCloudScriptNotFound: writer.String("CloudScriptNotFound"); break;
    case GenericErrorCodesContentQuotaExceeded: writer.String("ContentQuotaExceeded"); break;
    case GenericErrorCodesInvalidCharacterStatistics: writer.String("InvalidCharacterStatistics"); break;
    case GenericErrorCodesPhotonNotEnabledForTitle: writer.String("PhotonNotEnabledForTitle"); break;
    case GenericErrorCodesPhotonApplicationNotFound: writer.String("PhotonApplicationNotFound"); break;
    case GenericErrorCodesPhotonApplicationNotAssociatedWithTitle: writer.String("PhotonApplicationNotAssociatedWithTitle"); break;
    case GenericErrorCodesInvalidEmailOrPassword: writer.String("InvalidEmailOrPassword"); break;
    case GenericErrorCodesFacebookAPIError: writer.String("FacebookAPIError"); break;
    case GenericErrorCodesInvalidContentType: writer.String("InvalidContentType"); break;
    case GenericErrorCodesKeyLengthExceeded: writer.String("KeyLengthExceeded"); break;
    case GenericErrorCodesDataLengthExceeded: writer.String("DataLengthExceeded"); break;
    case GenericErrorCodesTooManyKeys: writer.String("TooManyKeys"); break;
    case GenericErrorCodesFreeTierCannotHaveVirtualCurrency: writer.String("FreeTierCannotHaveVirtualCurrency"); break;
    case GenericErrorCodesMissingAmazonSharedKey: writer.String("MissingAmazonSharedKey"); break;
    case GenericErrorCodesAmazonValidationError: writer.String("AmazonValidationError"); break;
    case GenericErrorCodesInvalidPSNIssuerId: writer.String("InvalidPSNIssuerId"); break;
    case GenericErrorCodesPSNInaccessible: writer.String("PSNInaccessible"); break;
    case GenericErrorCodesExpiredAuthToken: writer.String("ExpiredAuthToken"); break;
    case GenericErrorCodesFailedToGetEntitlements: writer.String("FailedToGetEntitlements"); break;
    case GenericErrorCodesFailedToConsumeEntitlement: writer.String("FailedToConsumeEntitlement"); break;
    case GenericErrorCodesTradeAcceptingUserNotAllowed: writer.String("TradeAcceptingUserNotAllowed"); break;
    case GenericErrorCodesTradeInventoryItemIsAssignedToCharacter: writer.String("TradeInventoryItemIsAssignedToCharacter"); break;
    case GenericErrorCodesTradeInventoryItemIsBundle: writer.String("TradeInventoryItemIsBundle"); break;
    case GenericErrorCodesTradeStatusNotValidForCancelling: writer.String("TradeStatusNotValidForCancelling"); break;
    case GenericErrorCodesTradeStatusNotValidForAccepting: writer.String("TradeStatusNotValidForAccepting"); break;
    case GenericErrorCodesTradeDoesNotExist: writer.String("TradeDoesNotExist"); break;
    case GenericErrorCodesTradeCancelled: writer.String("TradeCancelled"); break;
    case GenericErrorCodesTradeAlreadyFilled: writer.String("TradeAlreadyFilled"); break;
    case GenericErrorCodesTradeWaitForStatusTimeout: writer.String("TradeWaitForStatusTimeout"); break;
    case GenericErrorCodesTradeInventoryItemExpired: writer.String("TradeInventoryItemExpired"); break;
    case GenericErrorCodesTradeMissingOfferedAndAcceptedItems: writer.String("TradeMissingOfferedAndAcceptedItems"); break;
    case GenericErrorCodesTradeAcceptedItemIsBundle: writer.String("TradeAcceptedItemIsBundle"); break;
    case GenericErrorCodesTradeAcceptedItemIsStackable: writer.String("TradeAcceptedItemIsStackable"); break;
    case GenericErrorCodesTradeInventoryItemInvalidStatus: writer.String("TradeInventoryItemInvalidStatus"); break;
    case GenericErrorCodesTradeAcceptedCatalogItemInvalid: writer.String("TradeAcceptedCatalogItemInvalid"); break;
    case GenericErrorCodesTradeAllowedUsersInvalid: writer.String("TradeAllowedUsersInvalid"); break;
    case GenericErrorCodesTradeInventoryItemDoesNotExist: writer.String("TradeInventoryItemDoesNotExist"); break;
    case GenericErrorCodesTradeInventoryItemIsConsumed: writer.String("TradeInventoryItemIsConsumed"); break;
    case GenericErrorCodesTradeInventoryItemIsStackable: writer.String("TradeInventoryItemIsStackable"); break;
    case GenericErrorCodesTradeAcceptedItemsMismatch: writer.String("TradeAcceptedItemsMismatch"); break;
    case GenericErrorCodesInvalidKongregateToken: writer.String("InvalidKongregateToken"); break;
    case GenericErrorCodesFeatureNotConfiguredForTitle: writer.String("FeatureNotConfiguredForTitle"); break;
    case GenericErrorCodesNoMatchingCatalogItemForReceipt: writer.String("NoMatchingCatalogItemForReceipt"); break;
    case GenericErrorCodesInvalidCurrencyCode: writer.String("InvalidCurrencyCode"); break;
    case GenericErrorCodesNoRealMoneyPriceForCatalogItem: writer.String("NoRealMoneyPriceForCatalogItem"); break;
    case GenericErrorCodesTradeInventoryItemIsNotTradable: writer.String("TradeInventoryItemIsNotTradable"); break;
    case GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable: writer.String("TradeAcceptedCatalogItemIsNotTradable"); break;
    case GenericErrorCodesUsersAlreadyFriends: writer.String("UsersAlreadyFriends"); break;
    case GenericErrorCodesLinkedIdentifierAlreadyClaimed: writer.String("LinkedIdentifierAlreadyClaimed"); break;
    case GenericErrorCodesCustomIdNotLinked: writer.String("CustomIdNotLinked"); break;
    case GenericErrorCodesTotalDataSizeExceeded: writer.String("TotalDataSizeExceeded"); break;
    case GenericErrorCodesDeleteKeyConflict: writer.String("DeleteKeyConflict"); break;
    case GenericErrorCodesInvalidXboxLiveToken: writer.String("InvalidXboxLiveToken"); break;
    case GenericErrorCodesExpiredXboxLiveToken: writer.String("ExpiredXboxLiveToken"); break;
    case GenericErrorCodesResettableStatisticVersionRequired: writer.String("ResettableStatisticVersionRequired"); break;
    case GenericErrorCodesNotAuthorizedByTitle: writer.String("NotAuthorizedByTitle"); break;
    case GenericErrorCodesNoPartnerEnabled: writer.String("NoPartnerEnabled"); break;
    case GenericErrorCodesInvalidPartnerResponse: writer.String("InvalidPartnerResponse"); break;
    case GenericErrorCodesAPINotEnabledForGameServerAccess: writer.String("APINotEnabledForGameServerAccess"); break;
    case GenericErrorCodesStatisticNotFound: writer.String("StatisticNotFound"); break;
    case GenericErrorCodesStatisticNameConflict: writer.String("StatisticNameConflict"); break;
    case GenericErrorCodesStatisticVersionClosedForWrites: writer.String("StatisticVersionClosedForWrites"); break;
    case GenericErrorCodesStatisticVersionInvalid: writer.String("StatisticVersionInvalid"); break;
    case GenericErrorCodesAPIClientRequestRateLimitExceeded: writer.String("APIClientRequestRateLimitExceeded"); break;
    case GenericErrorCodesInvalidJSONContent: writer.String("InvalidJSONContent"); break;
    case GenericErrorCodesInvalidDropTable: writer.String("InvalidDropTable"); break;
    case GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval: writer.String("StatisticVersionAlreadyIncrementedForScheduledInterval"); break;
    case GenericErrorCodesStatisticCountLimitExceeded: writer.String("StatisticCountLimitExceeded"); break;
    case GenericErrorCodesStatisticVersionIncrementRateExceeded: writer.String("StatisticVersionIncrementRateExceeded"); break;
    case GenericErrorCodesContainerKeyInvalid: writer.String("ContainerKeyInvalid"); break;
    case GenericErrorCodesCloudScriptExecutionTimeLimitExceeded: writer.String("CloudScriptExecutionTimeLimitExceeded"); break;
    case GenericErrorCodesNoWritePermissionsForEvent: writer.String("NoWritePermissionsForEvent"); break;
    case GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded: writer.String("CloudScriptFunctionArgumentSizeExceeded"); break;
    case GenericErrorCodesCloudScriptAPIRequestCountExceeded: writer.String("CloudScriptAPIRequestCountExceeded"); break;
    case GenericErrorCodesCloudScriptAPIRequestError: writer.String("CloudScriptAPIRequestError"); break;
    case GenericErrorCodesCloudScriptHTTPRequestError: writer.String("CloudScriptHTTPRequestError"); break;
    case GenericErrorCodesInsufficientGuildRole: writer.String("InsufficientGuildRole"); break;
    case GenericErrorCodesGuildNotFound: writer.String("GuildNotFound"); break;
    case GenericErrorCodesOverLimit: writer.String("OverLimit"); break;
    case GenericErrorCodesEventNotFound: writer.String("EventNotFound"); break;
    case GenericErrorCodesInvalidEventField: writer.String("InvalidEventField"); break;
    case GenericErrorCodesInvalidEventName: writer.String("InvalidEventName"); break;
    case GenericErrorCodesCatalogNotConfigured: writer.String("CatalogNotConfigured"); break;
    case GenericErrorCodesOperationNotSupportedForPlatform: writer.String("OperationNotSupportedForPlatform"); break;
    case GenericErrorCodesSegmentNotFound: writer.String("SegmentNotFound"); break;
    case GenericErrorCodesStoreNotFound: writer.String("StoreNotFound"); break;
    case GenericErrorCodesInvalidStatisticName: writer.String("InvalidStatisticName"); break;
    case GenericErrorCodesTitleNotQualifiedForLimit: writer.String("TitleNotQualifiedForLimit"); break;
    case GenericErrorCodesInvalidServiceLimitLevel: writer.String("InvalidServiceLimitLevel"); break;
    case GenericErrorCodesServiceLimitLevelInTransition: writer.String("ServiceLimitLevelInTransition"); break;
    case GenericErrorCodesCouponAlreadyRedeemed: writer.String("CouponAlreadyRedeemed"); break;
    case GenericErrorCodesGameServerBuildSizeLimitExceeded: writer.String("GameServerBuildSizeLimitExceeded"); break;
    case GenericErrorCodesGameServerBuildCountLimitExceeded: writer.String("GameServerBuildCountLimitExceeded"); break;
    case GenericErrorCodesVirtualCurrencyCountLimitExceeded: writer.String("VirtualCurrencyCountLimitExceeded"); break;
    case GenericErrorCodesVirtualCurrencyCodeExists: writer.String("VirtualCurrencyCodeExists"); break;
    case GenericErrorCodesTitleNewsItemCountLimitExceeded: writer.String("TitleNewsItemCountLimitExceeded"); break;
    case GenericErrorCodesInvalidTwitchToken: writer.String("InvalidTwitchToken"); break;
    case GenericErrorCodesTwitchResponseError: writer.String("TwitchResponseError"); break;
    case GenericErrorCodesProfaneDisplayName: writer.String("ProfaneDisplayName"); break;
    case GenericErrorCodesUserAlreadyAdded: writer.String("UserAlreadyAdded"); break;
    case GenericErrorCodesInvalidVirtualCurrencyCode: writer.String("InvalidVirtualCurrencyCode"); break;
    case GenericErrorCodesVirtualCurrencyCannotBeDeleted: writer.String("VirtualCurrencyCannotBeDeleted"); break;
    case GenericErrorCodesIdentifierAlreadyClaimed: writer.String("IdentifierAlreadyClaimed"); break;
    case GenericErrorCodesIdentifierNotLinked: writer.String("IdentifierNotLinked"); break;
    case GenericErrorCodesInvalidContinuationToken: writer.String("InvalidContinuationToken"); break;
    case GenericErrorCodesExpiredContinuationToken: writer.String("ExpiredContinuationToken"); break;
    case GenericErrorCodesInvalidSegment: writer.String("InvalidSegment"); break;
    case GenericErrorCodesInvalidSessionId: writer.String("InvalidSessionId"); break;
    case GenericErrorCodesSessionLogNotFound: writer.String("SessionLogNotFound"); break;
    case GenericErrorCodesInvalidSearchTerm: writer.String("InvalidSearchTerm"); break;
    case GenericErrorCodesTwoFactorAuthenticationTokenRequired: writer.String("TwoFactorAuthenticationTokenRequired"); break;
    case GenericErrorCodesGameServerHostCountLimitExceeded: writer.String("GameServerHostCountLimitExceeded"); break;
    case GenericErrorCodesPlayerTagCountLimitExceeded: writer.String("PlayerTagCountLimitExceeded"); break;
    case GenericErrorCodesRequestAlreadyRunning: writer.String("RequestAlreadyRunning"); break;
    case GenericErrorCodesActionGroupNotFound: writer.String("ActionGroupNotFound"); break;
    case GenericErrorCodesMaximumSegmentBulkActionJobsRunning: writer.String("MaximumSegmentBulkActionJobsRunning"); break;
    case GenericErrorCodesNoActionsOnPlayersInSegmentJob: writer.String("NoActionsOnPlayersInSegmentJob"); break;
    case GenericErrorCodesDuplicateStatisticName: writer.String("DuplicateStatisticName"); break;
    case GenericErrorCodesScheduledTaskNameConflict: writer.String("ScheduledTaskNameConflict"); break;
    case GenericErrorCodesScheduledTaskCreateConflict: writer.String("ScheduledTaskCreateConflict"); break;
    case GenericErrorCodesInvalidScheduledTaskName: writer.String("InvalidScheduledTaskName"); break;
    case GenericErrorCodesInvalidTaskSchedule: writer.String("InvalidTaskSchedule"); break;
    case GenericErrorCodesSteamNotEnabledForTitle: writer.String("SteamNotEnabledForTitle"); break;
    case GenericErrorCodesLimitNotAnUpgradeOption: writer.String("LimitNotAnUpgradeOption"); break;
    case GenericErrorCodesNoSecretKeyEnabledForCloudScript: writer.String("NoSecretKeyEnabledForCloudScript"); break;
    case GenericErrorCodesTaskNotFound: writer.String("TaskNotFound"); break;
    case GenericErrorCodesTaskInstanceNotFound: writer.String("TaskInstanceNotFound"); break;
    case GenericErrorCodesInvalidIdentityProviderId: writer.String("InvalidIdentityProviderId"); break;
    case GenericErrorCodesMisconfiguredIdentityProvider: writer.String("MisconfiguredIdentityProvider"); break;
    case GenericErrorCodesInvalidScheduledTaskType: writer.String("InvalidScheduledTaskType"); break;
    case GenericErrorCodesBillingInformationRequired: writer.String("BillingInformationRequired"); break;
    case GenericErrorCodesLimitedEditionItemUnavailable: writer.String("LimitedEditionItemUnavailable"); break;
    case GenericErrorCodesInvalidAdPlacementAndReward: writer.String("InvalidAdPlacementAndReward"); break;
    case GenericErrorCodesAllAdPlacementViewsAlreadyConsumed: writer.String("AllAdPlacementViewsAlreadyConsumed"); break;
    case GenericErrorCodesGoogleOAuthNotConfiguredForTitle: writer.String("GoogleOAuthNotConfiguredForTitle"); break;
    case GenericErrorCodesGoogleOAuthError: writer.String("GoogleOAuthError"); break;
    case GenericErrorCodesUserNotFriend: writer.String("UserNotFriend"); break;
    case GenericErrorCodesInvalidSignature: writer.String("InvalidSignature"); break;
    case GenericErrorCodesInvalidPublicKey: writer.String("InvalidPublicKey"); break;
    case GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse: writer.String("GoogleOAuthNoIdTokenIncludedInResponse"); break;
    case GenericErrorCodesStatisticUpdateInProgress: writer.String("StatisticUpdateInProgress"); break;
    case GenericErrorCodesLeaderboardVersionNotAvailable: writer.String("LeaderboardVersionNotAvailable"); break;
    case GenericErrorCodesStatisticAlreadyHasPrizeTable: writer.String("StatisticAlreadyHasPrizeTable"); break;
    case GenericErrorCodesPrizeTableHasOverlappingRanks: writer.String("PrizeTableHasOverlappingRanks"); break;
    case GenericErrorCodesPrizeTableHasMissingRanks: writer.String("PrizeTableHasMissingRanks"); break;
    case GenericErrorCodesPrizeTableRankStartsAtZero: writer.String("PrizeTableRankStartsAtZero"); break;
    case GenericErrorCodesInvalidStatistic: writer.String("InvalidStatistic"); break;
    case GenericErrorCodesExpressionParseFailure: writer.String("ExpressionParseFailure"); break;
    case GenericErrorCodesExpressionInvokeFailure: writer.String("ExpressionInvokeFailure"); break;
    case GenericErrorCodesExpressionTooLong: writer.String("ExpressionTooLong"); break;
    case GenericErrorCodesDataUpdateRateExceeded: writer.String("DataUpdateRateExceeded"); break;
    case GenericErrorCodesRestrictedEmailDomain: writer.String("RestrictedEmailDomain"); break;
    case GenericErrorCodesEncryptionKeyDisabled: writer.String("EncryptionKeyDisabled"); break;
    case GenericErrorCodesEncryptionKeyMissing: writer.String("EncryptionKeyMissing"); break;
    case GenericErrorCodesEncryptionKeyBroken: writer.String("EncryptionKeyBroken"); break;
    case GenericErrorCodesNoSharedSecretKeyConfigured: writer.String("NoSharedSecretKeyConfigured"); break;
    case GenericErrorCodesSecretKeyNotFound: writer.String("SecretKeyNotFound"); break;
    case GenericErrorCodesPlayerSecretAlreadyConfigured: writer.String("PlayerSecretAlreadyConfigured"); break;
    case GenericErrorCodesAPIRequestsDisabledForTitle: writer.String("APIRequestsDisabledForTitle"); break;
    case GenericErrorCodesInvalidSharedSecretKey: writer.String("InvalidSharedSecretKey"); break;
    case GenericErrorCodesPrizeTableHasNoRanks: writer.String("PrizeTableHasNoRanks"); break;
    case GenericErrorCodesProfileDoesNotExist: writer.String("ProfileDoesNotExist"); break;
    case GenericErrorCodesContentS3OriginBucketNotConfigured: writer.String("ContentS3OriginBucketNotConfigured"); break;
    case GenericErrorCodesInvalidEnvironmentForReceipt: writer.String("InvalidEnvironmentForReceipt"); break;
    case GenericErrorCodesEncryptedRequestNotAllowed: writer.String("EncryptedRequestNotAllowed"); break;
    case GenericErrorCodesSignedRequestNotAllowed: writer.String("SignedRequestNotAllowed"); break;
    case GenericErrorCodesRequestViewConstraintParamsNotAllowed: writer.String("RequestViewConstraintParamsNotAllowed"); break;
    case GenericErrorCodesBadPartnerConfiguration: writer.String("BadPartnerConfiguration"); break;
    case GenericErrorCodesXboxBPCertificateFailure: writer.String("XboxBPCertificateFailure"); break;
    case GenericErrorCodesXboxXASSExchangeFailure: writer.String("XboxXASSExchangeFailure"); break;
    case GenericErrorCodesInvalidEntityId: writer.String("InvalidEntityId"); break;
    case GenericErrorCodesStatisticValueAggregationOverflow: writer.String("StatisticValueAggregationOverflow"); break;
    case GenericErrorCodesEmailMessageFromAddressIsMissing: writer.String("EmailMessageFromAddressIsMissing"); break;
    case GenericErrorCodesEmailMessageToAddressIsMissing: writer.String("EmailMessageToAddressIsMissing"); break;
    case GenericErrorCodesSmtpServerAuthenticationError: writer.String("SmtpServerAuthenticationError"); break;
    case GenericErrorCodesSmtpServerLimitExceeded: writer.String("SmtpServerLimitExceeded"); break;
    case GenericErrorCodesSmtpServerInsufficientStorage: writer.String("SmtpServerInsufficientStorage"); break;
    case GenericErrorCodesSmtpServerCommunicationError: writer.String("SmtpServerCommunicationError"); break;
    case GenericErrorCodesSmtpServerGeneralFailure: writer.String("SmtpServerGeneralFailure"); break;
    case GenericErrorCodesEmailClientTimeout: writer.String("EmailClientTimeout"); break;
    case GenericErrorCodesEmailClientCanceledTask: writer.String("EmailClientCanceledTask"); break;
    case GenericErrorCodesEmailTemplateMissing: writer.String("EmailTemplateMissing"); break;
    case GenericErrorCodesInvalidHostForTitleId: writer.String("InvalidHostForTitleId"); break;
    case GenericErrorCodesEmailConfirmationTokenDoesNotExist: writer.String("EmailConfirmationTokenDoesNotExist"); break;
    case GenericErrorCodesEmailConfirmationTokenExpired: writer.String("EmailConfirmationTokenExpired"); break;
    case GenericErrorCodesAccountDeleted: writer.String("AccountDeleted"); break;
    case GenericErrorCodesPlayerSecretNotConfigured: writer.String("PlayerSecretNotConfigured"); break;
    case GenericErrorCodesInvalidSignatureTime: writer.String("InvalidSignatureTime"); break;
    case GenericErrorCodesNoContactEmailAddressFound: writer.String("NoContactEmailAddressFound"); break;
    case GenericErrorCodesInvalidAuthToken: writer.String("InvalidAuthToken"); break;
    case GenericErrorCodesAuthTokenDoesNotExist: writer.String("AuthTokenDoesNotExist"); break;
    case GenericErrorCodesAuthTokenExpired: writer.String("AuthTokenExpired"); break;
    case GenericErrorCodesAuthTokenAlreadyUsedToResetPassword: writer.String("AuthTokenAlreadyUsedToResetPassword"); break;
    case GenericErrorCodesMembershipNameTooLong: writer.String("MembershipNameTooLong"); break;
    case GenericErrorCodesMembershipNotFound: writer.String("MembershipNotFound"); break;
    case GenericErrorCodesGoogleServiceAccountInvalid: writer.String("GoogleServiceAccountInvalid"); break;
    case GenericErrorCodesGoogleServiceAccountParseFailure: writer.String("GoogleServiceAccountParseFailure"); break;
    case GenericErrorCodesEntityTokenMissing: writer.String("EntityTokenMissing"); break;
    case GenericErrorCodesEntityTokenInvalid: writer.String("EntityTokenInvalid"); break;
    case GenericErrorCodesEntityTokenExpired: writer.String("EntityTokenExpired"); break;
    case GenericErrorCodesEntityTokenRevoked: writer.String("EntityTokenRevoked"); break;
    case GenericErrorCodesInvalidProductForSubscription: writer.String("InvalidProductForSubscription"); break;
    case GenericErrorCodesXboxInaccessible: writer.String("XboxInaccessible"); break;
    case GenericErrorCodesSubscriptionAlreadyTaken: writer.String("SubscriptionAlreadyTaken"); break;
    case GenericErrorCodesSmtpAddonNotEnabled: writer.String("SmtpAddonNotEnabled"); break;
    case GenericErrorCodesAPIConcurrentRequestLimitExceeded: writer.String("APIConcurrentRequestLimitExceeded"); break;
    case GenericErrorCodesXboxRejectedXSTSExchangeRequest: writer.String("XboxRejectedXSTSExchangeRequest"); break;
    case GenericErrorCodesVariableNotDefined: writer.String("VariableNotDefined"); break;
    case GenericErrorCodesTemplateVersionNotDefined: writer.String("TemplateVersionNotDefined"); break;
    case GenericErrorCodesFileTooLarge: writer.String("FileTooLarge"); break;
    case GenericErrorCodesTitleDeleted: writer.String("TitleDeleted"); break;
    case GenericErrorCodesTitleContainsUserAccounts: writer.String("TitleContainsUserAccounts"); break;
    case GenericErrorCodesTitleDeletionPlayerCleanupFailure: writer.String("TitleDeletionPlayerCleanupFailure"); break;
    case GenericErrorCodesEntityFileOperationPending: writer.String("EntityFileOperationPending"); break;
    case GenericErrorCodesNoEntityFileOperationPending: writer.String("NoEntityFileOperationPending"); break;
    case GenericErrorCodesEntityProfileVersionMismatch: writer.String("EntityProfileVersionMismatch"); break;
    case GenericErrorCodesTemplateVersionTooOld: writer.String("TemplateVersionTooOld"); break;
    case GenericErrorCodesMembershipDefinitionInUse: writer.String("MembershipDefinitionInUse"); break;
    case GenericErrorCodesPaymentPageNotConfigured: writer.String("PaymentPageNotConfigured"); break;
    case GenericErrorCodesFailedLoginAttemptRateLimitExceeded: writer.String("FailedLoginAttemptRateLimitExceeded"); break;
    case GenericErrorCodesEntityBlockedByGroup: writer.String("EntityBlockedByGroup"); break;
    case GenericErrorCodesRoleDoesNotExist: writer.String("RoleDoesNotExist"); break;
    case GenericErrorCodesEntityIsAlreadyMember: writer.String("EntityIsAlreadyMember"); break;
    case GenericErrorCodesDuplicateRoleId: writer.String("DuplicateRoleId"); break;
    case GenericErrorCodesGroupInvitationNotFound: writer.String("GroupInvitationNotFound"); break;
    case GenericErrorCodesGroupApplicationNotFound: writer.String("GroupApplicationNotFound"); break;
    case GenericErrorCodesOutstandingInvitationAcceptedInstead: writer.String("OutstandingInvitationAcceptedInstead"); break;
    case GenericErrorCodesOutstandingApplicationAcceptedInstead: writer.String("OutstandingApplicationAcceptedInstead"); break;
    case GenericErrorCodesRoleIsGroupDefaultMember: writer.String("RoleIsGroupDefaultMember"); break;
    case GenericErrorCodesRoleIsGroupAdmin: writer.String("RoleIsGroupAdmin"); break;
    case GenericErrorCodesRoleNameNotAvailable: writer.String("RoleNameNotAvailable"); break;
    case GenericErrorCodesGroupNameNotAvailable: writer.String("GroupNameNotAvailable"); break;
    case GenericErrorCodesEmailReportAlreadySent: writer.String("EmailReportAlreadySent"); break;
    case GenericErrorCodesEmailReportRecipientBlacklisted: writer.String("EmailReportRecipientBlacklisted"); break;
    case GenericErrorCodesEventNamespaceNotAllowed: writer.String("EventNamespaceNotAllowed"); break;
    case GenericErrorCodesEventEntityNotAllowed: writer.String("EventEntityNotAllowed"); break;
    case GenericErrorCodesInvalidEntityType: writer.String("InvalidEntityType"); break;
    case GenericErrorCodesNullTokenResultFromAad: writer.String("NullTokenResultFromAad"); break;
    case GenericErrorCodesInvalidTokenResultFromAad: writer.String("InvalidTokenResultFromAad"); break;
    case GenericErrorCodesNoValidCertificateForAad: writer.String("NoValidCertificateForAad"); break;
    case GenericErrorCodesInvalidCertificateForAad: writer.String("InvalidCertificateForAad"); break;
    case GenericErrorCodesDuplicateDropTableId: writer.String("DuplicateDropTableId"); break;
    case GenericErrorCodesMultiplayerServerError: writer.String("MultiplayerServerError"); break;
    case GenericErrorCodesMultiplayerServerTooManyRequests: writer.String("MultiplayerServerTooManyRequests"); break;
    case GenericErrorCodesMultiplayerServerNoContent: writer.String("MultiplayerServerNoContent"); break;
    case GenericErrorCodesMultiplayerServerBadRequest: writer.String("MultiplayerServerBadRequest"); break;
    case GenericErrorCodesMultiplayerServerUnauthorized: writer.String("MultiplayerServerUnauthorized"); break;
    case GenericErrorCodesMultiplayerServerForbidden: writer.String("MultiplayerServerForbidden"); break;
    case GenericErrorCodesMultiplayerServerNotFound: writer.String("MultiplayerServerNotFound"); break;
    case GenericErrorCodesMultiplayerServerConflict: writer.String("MultiplayerServerConflict"); break;
    case GenericErrorCodesMultiplayerServerInternalServerError: writer.String("MultiplayerServerInternalServerError"); break;
    case GenericErrorCodesMultiplayerServerUnavailable: writer.String("MultiplayerServerUnavailable"); break;
    case GenericErrorCodesExplicitContentDetected: writer.String("ExplicitContentDetected"); break;
    case GenericErrorCodesPIIContentDetected: writer.String("PIIContentDetected"); break;
    case GenericErrorCodesInvalidScheduledTaskParameter: writer.String("InvalidScheduledTaskParameter"); break;
    case GenericErrorCodesPerEntityEventRateLimitExceeded: writer.String("PerEntityEventRateLimitExceeded"); break;
    case GenericErrorCodesTitleDefaultLanguageNotSet: writer.String("TitleDefaultLanguageNotSet"); break;
    case GenericErrorCodesEmailTemplateMissingDefaultVersion: writer.String("EmailTemplateMissingDefaultVersion"); break;
    case GenericErrorCodesFacebookInstantGamesIdNotLinked: writer.String("FacebookInstantGamesIdNotLinked"); break;
    case GenericErrorCodesInvalidFacebookInstantGamesSignature: writer.String("InvalidFacebookInstantGamesSignature"); break;
    case GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle: writer.String("FacebookInstantGamesAuthNotConfiguredForTitle"); break;
    case GenericErrorCodesEntityProfileConstraintValidationFailed: writer.String("EntityProfileConstraintValidationFailed"); break;
    case GenericErrorCodesTelemetryIngestionKeyPending: writer.String("TelemetryIngestionKeyPending"); break;
    case GenericErrorCodesTelemetryIngestionKeyNotFound: writer.String("TelemetryIngestionKeyNotFound"); break;
    case GenericErrorCodesStatisticTagRequired: writer.String("StatisticTagRequired"); break;
    case GenericErrorCodesStatisticTagInvalid: writer.String("StatisticTagInvalid"); break;
    case GenericErrorCodesDataIntegrityError: writer.String("DataIntegrityError"); break;
    case GenericErrorCodesVirtualCurrencyCannotBeSetToOlderVersion: writer.String("VirtualCurrencyCannotBeSetToOlderVersion"); break;
    case GenericErrorCodesVirtualCurrencyMustBeWithinIntegerRange: writer.String("VirtualCurrencyMustBeWithinIntegerRange"); break;
    case GenericErrorCodesEmailTemplateInvalidSyntax: writer.String("EmailTemplateInvalidSyntax"); break;
    case GenericErrorCodesEmailTemplateMissingCallback: writer.String("EmailTemplateMissingCallback"); break;
    case GenericErrorCodesPushNotificationTemplateInvalidPayload: writer.String("PushNotificationTemplateInvalidPayload"); break;
    case GenericErrorCodesInvalidLocalizedPushNotificationLanguage: writer.String("InvalidLocalizedPushNotificationLanguage"); break;
    case GenericErrorCodesMissingLocalizedPushNotificationMessage: writer.String("MissingLocalizedPushNotificationMessage"); break;
    case GenericErrorCodesPushNotificationTemplateMissingPlatformPayload: writer.String("PushNotificationTemplateMissingPlatformPayload"); break;
    case GenericErrorCodesPushNotificationTemplatePayloadContainsInvalidJson: writer.String("PushNotificationTemplatePayloadContainsInvalidJson"); break;
    case GenericErrorCodesPushNotificationTemplateContainsInvalidIosPayload: writer.String("PushNotificationTemplateContainsInvalidIosPayload"); break;
    case GenericErrorCodesPushNotificationTemplateContainsInvalidAndroidPayload: writer.String("PushNotificationTemplateContainsInvalidAndroidPayload"); break;
    case GenericErrorCodesPushNotificationTemplateIosPayloadMissingNotificationBody: writer.String("PushNotificationTemplateIosPayloadMissingNotificationBody"); break;
    case GenericErrorCodesPushNotificationTemplateAndroidPayloadMissingNotificationBody: writer.String("PushNotificationTemplateAndroidPayloadMissingNotificationBody"); break;
    case GenericErrorCodesPushNotificationTemplateNotFound: writer.String("PushNotificationTemplateNotFound"); break;
    case GenericErrorCodesPushNotificationTemplateMissingDefaultVersion: writer.String("PushNotificationTemplateMissingDefaultVersion"); break;
    case GenericErrorCodesPushNotificationTemplateInvalidSyntax: writer.String("PushNotificationTemplateInvalidSyntax"); break;
    case GenericErrorCodesPushNotificationTemplateNoCustomPayloadForV1: writer.String("PushNotificationTemplateNoCustomPayloadForV1"); break;
    case GenericErrorCodesNoLeaderboardForStatistic: writer.String("NoLeaderboardForStatistic"); break;
    case GenericErrorCodesTitleNewsMissingDefaultLanguage: writer.String("TitleNewsMissingDefaultLanguage"); break;
    case GenericErrorCodesTitleNewsNotFound: writer.String("TitleNewsNotFound"); break;
    case GenericErrorCodesTitleNewsDuplicateLanguage: writer.String("TitleNewsDuplicateLanguage"); break;
    case GenericErrorCodesTitleNewsMissingTitleOrBody: writer.String("TitleNewsMissingTitleOrBody"); break;
    case GenericErrorCodesTitleNewsInvalidLanguage: writer.String("TitleNewsInvalidLanguage"); break;
    case GenericErrorCodesEmailRecipientBlacklisted: writer.String("EmailRecipientBlacklisted"); break;
    case GenericErrorCodesInvalidGameCenterAuthRequest: writer.String("InvalidGameCenterAuthRequest"); break;
    case GenericErrorCodesGameCenterAuthenticationFailed: writer.String("GameCenterAuthenticationFailed"); break;
    case GenericErrorCodesMatchmakingEntityInvalid: writer.String("MatchmakingEntityInvalid"); break;
    case GenericErrorCodesMatchmakingPlayerAttributesInvalid: writer.String("MatchmakingPlayerAttributesInvalid"); break;
    case GenericErrorCodesMatchmakingCreateTicketRequestMissing: writer.String("MatchmakingCreateTicketRequestMissing"); break;
    case GenericErrorCodesMatchmakingCreateTicketCreatorMissing: writer.String("MatchmakingCreateTicketCreatorMissing"); break;
    case GenericErrorCodesMatchmakingCreateTicketCreatorIdMissing: writer.String("MatchmakingCreateTicketCreatorIdMissing"); break;
    case GenericErrorCodesMatchmakingCreateTicketMemberListMissing: writer.String("MatchmakingCreateTicketMemberListMissing"); break;
    case GenericErrorCodesMatchmakingCreateTicketGiveUpAfterInvalid: writer.String("MatchmakingCreateTicketGiveUpAfterInvalid"); break;
    case GenericErrorCodesMatchmakingTicketIdMissing: writer.String("MatchmakingTicketIdMissing"); break;
    case GenericErrorCodesMatchmakingMatchIdMissing: writer.String("MatchmakingMatchIdMissing"); break;
    case GenericErrorCodesMatchmakingMatchIdIdMissing: writer.String("MatchmakingMatchIdIdMissing"); break;
    case GenericErrorCodesMatchmakingQueueNameMissing: writer.String("MatchmakingQueueNameMissing"); break;
    case GenericErrorCodesMatchmakingTitleIdMissing: writer.String("MatchmakingTitleIdMissing"); break;
    case GenericErrorCodesMatchmakingTicketIdIdMissing: writer.String("MatchmakingTicketIdIdMissing"); break;
    case GenericErrorCodesMatchmakingPlayerIdMissing: writer.String("MatchmakingPlayerIdMissing"); break;
    case GenericErrorCodesMatchmakingJoinTicketPlayerMissing: writer.String("MatchmakingJoinTicketPlayerMissing"); break;
    case GenericErrorCodesMatchmakingQueueConfigNotFound: writer.String("MatchmakingQueueConfigNotFound"); break;
    case GenericErrorCodesMatchmakingMatchNotFound: writer.String("MatchmakingMatchNotFound"); break;
    case GenericErrorCodesMatchmakingTicketNotFound: writer.String("MatchmakingTicketNotFound"); break;
    case GenericErrorCodesMatchmakingCreateTicketServerIdentityInvalid: writer.String("MatchmakingCreateTicketServerIdentityInvalid"); break;
    case GenericErrorCodesMatchmakingCreateTicketClientIdentityInvalid: writer.String("MatchmakingCreateTicketClientIdentityInvalid"); break;
    case GenericErrorCodesMatchmakingGetTicketPlayerMismatch: writer.String("MatchmakingGetTicketPlayerMismatch"); break;
    case GenericErrorCodesMatchmakingJoinTicketServerIdentityInvalid: writer.String("MatchmakingJoinTicketServerIdentityInvalid"); break;
    case GenericErrorCodesMatchmakingJoinTicketPlayerIdentityMismatch: writer.String("MatchmakingJoinTicketPlayerIdentityMismatch"); break;
    case GenericErrorCodesMatchmakingCancelTicketServerIdentityInvalid: writer.String("MatchmakingCancelTicketServerIdentityInvalid"); break;
    case GenericErrorCodesMatchmakingCancelTicketPlayerIdentityMismatch: writer.String("MatchmakingCancelTicketPlayerIdentityMismatch"); break;
    case GenericErrorCodesMatchmakingGetMatchIdentityMismatch: writer.String("MatchmakingGetMatchIdentityMismatch"); break;
    case GenericErrorCodesMatchmakingPlayerIdentityMismatch: writer.String("MatchmakingPlayerIdentityMismatch"); break;
    case GenericErrorCodesMatchmakingAlreadyJoinedTicket: writer.String("MatchmakingAlreadyJoinedTicket"); break;
    case GenericErrorCodesMatchmakingTicketAlreadyCompleted: writer.String("MatchmakingTicketAlreadyCompleted"); break;
    case GenericErrorCodesMatchmakingClientTimeout: writer.String("MatchmakingClientTimeout"); break;
    case GenericErrorCodesMatchmakingQueueConfigInvalid: writer.String("MatchmakingQueueConfigInvalid"); break;
    case GenericErrorCodesMatchmakingMemberProfileInvalid: writer.String("MatchmakingMemberProfileInvalid"); break;
    case GenericErrorCodesWriteAttemptedDuringExport: writer.String("WriteAttemptedDuringExport"); break;
    case GenericErrorCodesNintendoSwitchDeviceIdNotLinked: writer.String("NintendoSwitchDeviceIdNotLinked"); break;
    case GenericErrorCodesMatchmakingNotEnabled: writer.String("MatchmakingNotEnabled"); break;
    case GenericErrorCodesMatchmakingGetStatisticsIdentityInvalid: writer.String("MatchmakingGetStatisticsIdentityInvalid"); break;
    case GenericErrorCodesMatchmakingBucketOwnerNotFound: writer.String("MatchmakingBucketOwnerNotFound"); break;
    case GenericErrorCodesCannotEnableMultiplayerServersForTitle: writer.String("CannotEnableMultiplayerServersForTitle"); break;
    case GenericErrorCodesMatchmakingCancelAllTicketsUnauthorized: writer.String("MatchmakingCancelAllTicketsUnauthorized"); break;
    case GenericErrorCodesMatchmakingListTicketsUnauthorized: writer.String("MatchmakingListTicketsUnauthorized"); break;
    case GenericErrorCodesMatchmakingPlayerAttributesTooLarge: writer.String("MatchmakingPlayerAttributesTooLarge"); break;
    case GenericErrorCodesMatchmakingNumberOfPlayersInTicketTooLarge: writer.String("MatchmakingNumberOfPlayersInTicketTooLarge"); break;
    case GenericErrorCodesMatchmakingMatchTotalAttributeIsNegative: writer.String("MatchmakingMatchTotalAttributeIsNegative"); break;
    case GenericErrorCodesMatchmakingAttributeTypeInvalid: writer.String("MatchmakingAttributeTypeInvalid"); break;
    case GenericErrorCodesMatchmakingMatchTotalAttributeTooLarge: writer.String("MatchmakingMatchTotalAttributeTooLarge"); break;
    case GenericErrorCodesMatchmakingMatchTotalAttributeSumTooLarge: writer.String("MatchmakingMatchTotalAttributeSumTooLarge"); break;
    case GenericErrorCodesMatchmakingTicketUnmatchable: writer.String("MatchmakingTicketUnmatchable"); break;
    case GenericErrorCodesMatchmakingCommonRegionMissing: writer.String("MatchmakingCommonRegionMissing"); break;
    case GenericErrorCodesMatchmakingLatencyMeasurementMissing: writer.String("MatchmakingLatencyMeasurementMissing"); break;
    case GenericErrorCodesMatchmakingStatisticsNotFound: writer.String("MatchmakingStatisticsNotFound"); break;
    case GenericErrorCodesMatchmakingPlayerHasNotJoinedTicket: writer.String("MatchmakingPlayerHasNotJoinedTicket"); break;
    case GenericErrorCodesCannotEnablePartiesForTitle: writer.String("CannotEnablePartiesForTitle"); break;
    case GenericErrorCodesPartyError: writer.String("PartyError"); break;
    case GenericErrorCodesPartyRequests: writer.String("PartyRequests"); break;
    case GenericErrorCodesPartyNoContent: writer.String("PartyNoContent"); break;
    case GenericErrorCodesPartyBadRequest: writer.String("PartyBadRequest"); break;
    case GenericErrorCodesPartyUnauthorized: writer.String("PartyUnauthorized"); break;
    case GenericErrorCodesPartyForbidden: writer.String("PartyForbidden"); break;
    case GenericErrorCodesPartyNotFound: writer.String("PartyNotFound"); break;
    case GenericErrorCodesPartyConflict: writer.String("PartyConflict"); break;
    case GenericErrorCodesPartyInternalServerError: writer.String("PartyInternalServerError"); break;
    case GenericErrorCodesPartyUnavailable: writer.String("PartyUnavailable"); break;
    case GenericErrorCodesPartyTooManyRequests: writer.String("PartyTooManyRequests"); break;
    case GenericErrorCodesTitleConfigNotFound: writer.String("TitleConfigNotFound"); break;
    case GenericErrorCodesTitleConfigUpdateConflict: writer.String("TitleConfigUpdateConflict"); break;
    case GenericErrorCodesTitleConfigSerializationError: writer.String("TitleConfigSerializationError"); break;
    case GenericErrorCodesCatalogEntityInvalid: writer.String("CatalogEntityInvalid"); break;
    case GenericErrorCodesCatalogTitleIdMissing: writer.String("CatalogTitleIdMissing"); break;
    case GenericErrorCodesCatalogPlayerIdMissing: writer.String("CatalogPlayerIdMissing"); break;
    case GenericErrorCodesCatalogClientIdentityInvalid: writer.String("CatalogClientIdentityInvalid"); break;
    case GenericErrorCodesCatalogOneOrMoreFilesInvalid: writer.String("CatalogOneOrMoreFilesInvalid"); break;
    case GenericErrorCodesCatalogItemMetadataInvalid: writer.String("CatalogItemMetadataInvalid"); break;
    case GenericErrorCodesCatalogItemIdInvalid: writer.String("CatalogItemIdInvalid"); break;
    case GenericErrorCodesCatalogSearchParameterInvalid: writer.String("CatalogSearchParameterInvalid"); break;
    case GenericErrorCodesCatalogFeatureDisabled: writer.String("CatalogFeatureDisabled"); break;
    case GenericErrorCodesCatalogConfigMissing: writer.String("CatalogConfigMissing"); break;
    case GenericErrorCodesCatalogConfigTooManyContentTypes: writer.String("CatalogConfigTooManyContentTypes"); break;
    case GenericErrorCodesCatalogConfigContentTypeTooLong: writer.String("CatalogConfigContentTypeTooLong"); break;
    case GenericErrorCodesCatalogConfigTooManyTags: writer.String("CatalogConfigTooManyTags"); break;
    case GenericErrorCodesCatalogConfigTagTooLong: writer.String("CatalogConfigTagTooLong"); break;

    }
}

GenericErrorCodes PlayFab::ServerModels::readGenericErrorCodesFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, GenericErrorCodes> _GenericErrorCodesMap;
    if (_GenericErrorCodesMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _GenericErrorCodesMap["Success"] = GenericErrorCodesSuccess;
        _GenericErrorCodesMap["UnkownError"] = GenericErrorCodesUnkownError;
        _GenericErrorCodesMap["InvalidParams"] = GenericErrorCodesInvalidParams;
        _GenericErrorCodesMap["AccountNotFound"] = GenericErrorCodesAccountNotFound;
        _GenericErrorCodesMap["AccountBanned"] = GenericErrorCodesAccountBanned;
        _GenericErrorCodesMap["InvalidUsernameOrPassword"] = GenericErrorCodesInvalidUsernameOrPassword;
        _GenericErrorCodesMap["InvalidTitleId"] = GenericErrorCodesInvalidTitleId;
        _GenericErrorCodesMap["InvalidEmailAddress"] = GenericErrorCodesInvalidEmailAddress;
        _GenericErrorCodesMap["EmailAddressNotAvailable"] = GenericErrorCodesEmailAddressNotAvailable;
        _GenericErrorCodesMap["InvalidUsername"] = GenericErrorCodesInvalidUsername;
        _GenericErrorCodesMap["InvalidPassword"] = GenericErrorCodesInvalidPassword;
        _GenericErrorCodesMap["UsernameNotAvailable"] = GenericErrorCodesUsernameNotAvailable;
        _GenericErrorCodesMap["InvalidSteamTicket"] = GenericErrorCodesInvalidSteamTicket;
        _GenericErrorCodesMap["AccountAlreadyLinked"] = GenericErrorCodesAccountAlreadyLinked;
        _GenericErrorCodesMap["LinkedAccountAlreadyClaimed"] = GenericErrorCodesLinkedAccountAlreadyClaimed;
        _GenericErrorCodesMap["InvalidFacebookToken"] = GenericErrorCodesInvalidFacebookToken;
        _GenericErrorCodesMap["AccountNotLinked"] = GenericErrorCodesAccountNotLinked;
        _GenericErrorCodesMap["FailedByPaymentProvider"] = GenericErrorCodesFailedByPaymentProvider;
        _GenericErrorCodesMap["CouponCodeNotFound"] = GenericErrorCodesCouponCodeNotFound;
        _GenericErrorCodesMap["InvalidContainerItem"] = GenericErrorCodesInvalidContainerItem;
        _GenericErrorCodesMap["ContainerNotOwned"] = GenericErrorCodesContainerNotOwned;
        _GenericErrorCodesMap["KeyNotOwned"] = GenericErrorCodesKeyNotOwned;
        _GenericErrorCodesMap["InvalidItemIdInTable"] = GenericErrorCodesInvalidItemIdInTable;
        _GenericErrorCodesMap["InvalidReceipt"] = GenericErrorCodesInvalidReceipt;
        _GenericErrorCodesMap["ReceiptAlreadyUsed"] = GenericErrorCodesReceiptAlreadyUsed;
        _GenericErrorCodesMap["ReceiptCancelled"] = GenericErrorCodesReceiptCancelled;
        _GenericErrorCodesMap["GameNotFound"] = GenericErrorCodesGameNotFound;
        _GenericErrorCodesMap["GameModeNotFound"] = GenericErrorCodesGameModeNotFound;
        _GenericErrorCodesMap["InvalidGoogleToken"] = GenericErrorCodesInvalidGoogleToken;
        _GenericErrorCodesMap["UserIsNotPartOfDeveloper"] = GenericErrorCodesUserIsNotPartOfDeveloper;
        _GenericErrorCodesMap["InvalidTitleForDeveloper"] = GenericErrorCodesInvalidTitleForDeveloper;
        _GenericErrorCodesMap["TitleNameConflicts"] = GenericErrorCodesTitleNameConflicts;
        _GenericErrorCodesMap["UserisNotValid"] = GenericErrorCodesUserisNotValid;
        _GenericErrorCodesMap["ValueAlreadyExists"] = GenericErrorCodesValueAlreadyExists;
        _GenericErrorCodesMap["BuildNotFound"] = GenericErrorCodesBuildNotFound;
        _GenericErrorCodesMap["PlayerNotInGame"] = GenericErrorCodesPlayerNotInGame;
        _GenericErrorCodesMap["InvalidTicket"] = GenericErrorCodesInvalidTicket;
        _GenericErrorCodesMap["InvalidDeveloper"] = GenericErrorCodesInvalidDeveloper;
        _GenericErrorCodesMap["InvalidOrderInfo"] = GenericErrorCodesInvalidOrderInfo;
        _GenericErrorCodesMap["RegistrationIncomplete"] = GenericErrorCodesRegistrationIncomplete;
        _GenericErrorCodesMap["InvalidPlatform"] = GenericErrorCodesInvalidPlatform;
        _GenericErrorCodesMap["UnknownError"] = GenericErrorCodesUnknownError;
        _GenericErrorCodesMap["SteamApplicationNotOwned"] = GenericErrorCodesSteamApplicationNotOwned;
        _GenericErrorCodesMap["WrongSteamAccount"] = GenericErrorCodesWrongSteamAccount;
        _GenericErrorCodesMap["TitleNotActivated"] = GenericErrorCodesTitleNotActivated;
        _GenericErrorCodesMap["RegistrationSessionNotFound"] = GenericErrorCodesRegistrationSessionNotFound;
        _GenericErrorCodesMap["NoSuchMod"] = GenericErrorCodesNoSuchMod;
        _GenericErrorCodesMap["FileNotFound"] = GenericErrorCodesFileNotFound;
        _GenericErrorCodesMap["DuplicateEmail"] = GenericErrorCodesDuplicateEmail;
        _GenericErrorCodesMap["ItemNotFound"] = GenericErrorCodesItemNotFound;
        _GenericErrorCodesMap["ItemNotOwned"] = GenericErrorCodesItemNotOwned;
        _GenericErrorCodesMap["ItemNotRecycleable"] = GenericErrorCodesItemNotRecycleable;
        _GenericErrorCodesMap["ItemNotAffordable"] = GenericErrorCodesItemNotAffordable;
        _GenericErrorCodesMap["InvalidVirtualCurrency"] = GenericErrorCodesInvalidVirtualCurrency;
        _GenericErrorCodesMap["WrongVirtualCurrency"] = GenericErrorCodesWrongVirtualCurrency;
        _GenericErrorCodesMap["WrongPrice"] = GenericErrorCodesWrongPrice;
        _GenericErrorCodesMap["NonPositiveValue"] = GenericErrorCodesNonPositiveValue;
        _GenericErrorCodesMap["InvalidRegion"] = GenericErrorCodesInvalidRegion;
        _GenericErrorCodesMap["RegionAtCapacity"] = GenericErrorCodesRegionAtCapacity;
        _GenericErrorCodesMap["ServerFailedToStart"] = GenericErrorCodesServerFailedToStart;
        _GenericErrorCodesMap["NameNotAvailable"] = GenericErrorCodesNameNotAvailable;
        _GenericErrorCodesMap["InsufficientFunds"] = GenericErrorCodesInsufficientFunds;
        _GenericErrorCodesMap["InvalidDeviceID"] = GenericErrorCodesInvalidDeviceID;
        _GenericErrorCodesMap["InvalidPushNotificationToken"] = GenericErrorCodesInvalidPushNotificationToken;
        _GenericErrorCodesMap["NoRemainingUses"] = GenericErrorCodesNoRemainingUses;
        _GenericErrorCodesMap["InvalidPaymentProvider"] = GenericErrorCodesInvalidPaymentProvider;
        _GenericErrorCodesMap["PurchaseInitializationFailure"] = GenericErrorCodesPurchaseInitializationFailure;
        _GenericErrorCodesMap["DuplicateUsername"] = GenericErrorCodesDuplicateUsername;
        _GenericErrorCodesMap["InvalidBuyerInfo"] = GenericErrorCodesInvalidBuyerInfo;
        _GenericErrorCodesMap["NoGameModeParamsSet"] = GenericErrorCodesNoGameModeParamsSet;
        _GenericErrorCodesMap["BodyTooLarge"] = GenericErrorCodesBodyTooLarge;
        _GenericErrorCodesMap["ReservedWordInBody"] = GenericErrorCodesReservedWordInBody;
        _GenericErrorCodesMap["InvalidTypeInBody"] = GenericErrorCodesInvalidTypeInBody;
        _GenericErrorCodesMap["InvalidRequest"] = GenericErrorCodesInvalidRequest;
        _GenericErrorCodesMap["ReservedEventName"] = GenericErrorCodesReservedEventName;
        _GenericErrorCodesMap["InvalidUserStatistics"] = GenericErrorCodesInvalidUserStatistics;
        _GenericErrorCodesMap["NotAuthenticated"] = GenericErrorCodesNotAuthenticated;
        _GenericErrorCodesMap["StreamAlreadyExists"] = GenericErrorCodesStreamAlreadyExists;
        _GenericErrorCodesMap["ErrorCreatingStream"] = GenericErrorCodesErrorCreatingStream;
        _GenericErrorCodesMap["StreamNotFound"] = GenericErrorCodesStreamNotFound;
        _GenericErrorCodesMap["InvalidAccount"] = GenericErrorCodesInvalidAccount;
        _GenericErrorCodesMap["PurchaseDoesNotExist"] = GenericErrorCodesPurchaseDoesNotExist;
        _GenericErrorCodesMap["InvalidPurchaseTransactionStatus"] = GenericErrorCodesInvalidPurchaseTransactionStatus;
        _GenericErrorCodesMap["APINotEnabledForGameClientAccess"] = GenericErrorCodesAPINotEnabledForGameClientAccess;
        _GenericErrorCodesMap["NoPushNotificationARNForTitle"] = GenericErrorCodesNoPushNotificationARNForTitle;
        _GenericErrorCodesMap["BuildAlreadyExists"] = GenericErrorCodesBuildAlreadyExists;
        _GenericErrorCodesMap["BuildPackageDoesNotExist"] = GenericErrorCodesBuildPackageDoesNotExist;
        _GenericErrorCodesMap["CustomAnalyticsEventsNotEnabledForTitle"] = GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle;
        _GenericErrorCodesMap["InvalidSharedGroupId"] = GenericErrorCodesInvalidSharedGroupId;
        _GenericErrorCodesMap["NotAuthorized"] = GenericErrorCodesNotAuthorized;
        _GenericErrorCodesMap["MissingTitleGoogleProperties"] = GenericErrorCodesMissingTitleGoogleProperties;
        _GenericErrorCodesMap["InvalidItemProperties"] = GenericErrorCodesInvalidItemProperties;
        _GenericErrorCodesMap["InvalidPSNAuthCode"] = GenericErrorCodesInvalidPSNAuthCode;
        _GenericErrorCodesMap["InvalidItemId"] = GenericErrorCodesInvalidItemId;
        _GenericErrorCodesMap["PushNotEnabledForAccount"] = GenericErrorCodesPushNotEnabledForAccount;
        _GenericErrorCodesMap["PushServiceError"] = GenericErrorCodesPushServiceError;
        _GenericErrorCodesMap["ReceiptDoesNotContainInAppItems"] = GenericErrorCodesReceiptDoesNotContainInAppItems;
        _GenericErrorCodesMap["ReceiptContainsMultipleInAppItems"] = GenericErrorCodesReceiptContainsMultipleInAppItems;
        _GenericErrorCodesMap["InvalidBundleID"] = GenericErrorCodesInvalidBundleID;
        _GenericErrorCodesMap["JavascriptException"] = GenericErrorCodesJavascriptException;
        _GenericErrorCodesMap["InvalidSessionTicket"] = GenericErrorCodesInvalidSessionTicket;
        _GenericErrorCodesMap["UnableToConnectToDatabase"] = GenericErrorCodesUnableToConnectToDatabase;
        _GenericErrorCodesMap["InternalServerError"] = GenericErrorCodesInternalServerError;
        _GenericErrorCodesMap["InvalidReportDate"] = GenericErrorCodesInvalidReportDate;
        _GenericErrorCodesMap["ReportNotAvailable"] = GenericErrorCodesReportNotAvailable;
        _GenericErrorCodesMap["DatabaseThroughputExceeded"] = GenericErrorCodesDatabaseThroughputExceeded;
        _GenericErrorCodesMap["InvalidGameTicket"] = GenericErrorCodesInvalidGameTicket;
        _GenericErrorCodesMap["ExpiredGameTicket"] = GenericErrorCodesExpiredGameTicket;
        _GenericErrorCodesMap["GameTicketDoesNotMatchLobby"] = GenericErrorCodesGameTicketDoesNotMatchLobby;
        _GenericErrorCodesMap["LinkedDeviceAlreadyClaimed"] = GenericErrorCodesLinkedDeviceAlreadyClaimed;
        _GenericErrorCodesMap["DeviceAlreadyLinked"] = GenericErrorCodesDeviceAlreadyLinked;
        _GenericErrorCodesMap["DeviceNotLinked"] = GenericErrorCodesDeviceNotLinked;
        _GenericErrorCodesMap["PartialFailure"] = GenericErrorCodesPartialFailure;
        _GenericErrorCodesMap["PublisherNotSet"] = GenericErrorCodesPublisherNotSet;
        _GenericErrorCodesMap["ServiceUnavailable"] = GenericErrorCodesServiceUnavailable;
        _GenericErrorCodesMap["VersionNotFound"] = GenericErrorCodesVersionNotFound;
        _GenericErrorCodesMap["RevisionNotFound"] = GenericErrorCodesRevisionNotFound;
        _GenericErrorCodesMap["InvalidPublisherId"] = GenericErrorCodesInvalidPublisherId;
        _GenericErrorCodesMap["DownstreamServiceUnavailable"] = GenericErrorCodesDownstreamServiceUnavailable;
        _GenericErrorCodesMap["APINotIncludedInTitleUsageTier"] = GenericErrorCodesAPINotIncludedInTitleUsageTier;
        _GenericErrorCodesMap["DAULimitExceeded"] = GenericErrorCodesDAULimitExceeded;
        _GenericErrorCodesMap["APIRequestLimitExceeded"] = GenericErrorCodesAPIRequestLimitExceeded;
        _GenericErrorCodesMap["InvalidAPIEndpoint"] = GenericErrorCodesInvalidAPIEndpoint;
        _GenericErrorCodesMap["BuildNotAvailable"] = GenericErrorCodesBuildNotAvailable;
        _GenericErrorCodesMap["ConcurrentEditError"] = GenericErrorCodesConcurrentEditError;
        _GenericErrorCodesMap["ContentNotFound"] = GenericErrorCodesContentNotFound;
        _GenericErrorCodesMap["CharacterNotFound"] = GenericErrorCodesCharacterNotFound;
        _GenericErrorCodesMap["CloudScriptNotFound"] = GenericErrorCodesCloudScriptNotFound;
        _GenericErrorCodesMap["ContentQuotaExceeded"] = GenericErrorCodesContentQuotaExceeded;
        _GenericErrorCodesMap["InvalidCharacterStatistics"] = GenericErrorCodesInvalidCharacterStatistics;
        _GenericErrorCodesMap["PhotonNotEnabledForTitle"] = GenericErrorCodesPhotonNotEnabledForTitle;
        _GenericErrorCodesMap["PhotonApplicationNotFound"] = GenericErrorCodesPhotonApplicationNotFound;
        _GenericErrorCodesMap["PhotonApplicationNotAssociatedWithTitle"] = GenericErrorCodesPhotonApplicationNotAssociatedWithTitle;
        _GenericErrorCodesMap["InvalidEmailOrPassword"] = GenericErrorCodesInvalidEmailOrPassword;
        _GenericErrorCodesMap["FacebookAPIError"] = GenericErrorCodesFacebookAPIError;
        _GenericErrorCodesMap["InvalidContentType"] = GenericErrorCodesInvalidContentType;
        _GenericErrorCodesMap["KeyLengthExceeded"] = GenericErrorCodesKeyLengthExceeded;
        _GenericErrorCodesMap["DataLengthExceeded"] = GenericErrorCodesDataLengthExceeded;
        _GenericErrorCodesMap["TooManyKeys"] = GenericErrorCodesTooManyKeys;
        _GenericErrorCodesMap["FreeTierCannotHaveVirtualCurrency"] = GenericErrorCodesFreeTierCannotHaveVirtualCurrency;
        _GenericErrorCodesMap["MissingAmazonSharedKey"] = GenericErrorCodesMissingAmazonSharedKey;
        _GenericErrorCodesMap["AmazonValidationError"] = GenericErrorCodesAmazonValidationError;
        _GenericErrorCodesMap["InvalidPSNIssuerId"] = GenericErrorCodesInvalidPSNIssuerId;
        _GenericErrorCodesMap["PSNInaccessible"] = GenericErrorCodesPSNInaccessible;
        _GenericErrorCodesMap["ExpiredAuthToken"] = GenericErrorCodesExpiredAuthToken;
        _GenericErrorCodesMap["FailedToGetEntitlements"] = GenericErrorCodesFailedToGetEntitlements;
        _GenericErrorCodesMap["FailedToConsumeEntitlement"] = GenericErrorCodesFailedToConsumeEntitlement;
        _GenericErrorCodesMap["TradeAcceptingUserNotAllowed"] = GenericErrorCodesTradeAcceptingUserNotAllowed;
        _GenericErrorCodesMap["TradeInventoryItemIsAssignedToCharacter"] = GenericErrorCodesTradeInventoryItemIsAssignedToCharacter;
        _GenericErrorCodesMap["TradeInventoryItemIsBundle"] = GenericErrorCodesTradeInventoryItemIsBundle;
        _GenericErrorCodesMap["TradeStatusNotValidForCancelling"] = GenericErrorCodesTradeStatusNotValidForCancelling;
        _GenericErrorCodesMap["TradeStatusNotValidForAccepting"] = GenericErrorCodesTradeStatusNotValidForAccepting;
        _GenericErrorCodesMap["TradeDoesNotExist"] = GenericErrorCodesTradeDoesNotExist;
        _GenericErrorCodesMap["TradeCancelled"] = GenericErrorCodesTradeCancelled;
        _GenericErrorCodesMap["TradeAlreadyFilled"] = GenericErrorCodesTradeAlreadyFilled;
        _GenericErrorCodesMap["TradeWaitForStatusTimeout"] = GenericErrorCodesTradeWaitForStatusTimeout;
        _GenericErrorCodesMap["TradeInventoryItemExpired"] = GenericErrorCodesTradeInventoryItemExpired;
        _GenericErrorCodesMap["TradeMissingOfferedAndAcceptedItems"] = GenericErrorCodesTradeMissingOfferedAndAcceptedItems;
        _GenericErrorCodesMap["TradeAcceptedItemIsBundle"] = GenericErrorCodesTradeAcceptedItemIsBundle;
        _GenericErrorCodesMap["TradeAcceptedItemIsStackable"] = GenericErrorCodesTradeAcceptedItemIsStackable;
        _GenericErrorCodesMap["TradeInventoryItemInvalidStatus"] = GenericErrorCodesTradeInventoryItemInvalidStatus;
        _GenericErrorCodesMap["TradeAcceptedCatalogItemInvalid"] = GenericErrorCodesTradeAcceptedCatalogItemInvalid;
        _GenericErrorCodesMap["TradeAllowedUsersInvalid"] = GenericErrorCodesTradeAllowedUsersInvalid;
        _GenericErrorCodesMap["TradeInventoryItemDoesNotExist"] = GenericErrorCodesTradeInventoryItemDoesNotExist;
        _GenericErrorCodesMap["TradeInventoryItemIsConsumed"] = GenericErrorCodesTradeInventoryItemIsConsumed;
        _GenericErrorCodesMap["TradeInventoryItemIsStackable"] = GenericErrorCodesTradeInventoryItemIsStackable;
        _GenericErrorCodesMap["TradeAcceptedItemsMismatch"] = GenericErrorCodesTradeAcceptedItemsMismatch;
        _GenericErrorCodesMap["InvalidKongregateToken"] = GenericErrorCodesInvalidKongregateToken;
        _GenericErrorCodesMap["FeatureNotConfiguredForTitle"] = GenericErrorCodesFeatureNotConfiguredForTitle;
        _GenericErrorCodesMap["NoMatchingCatalogItemForReceipt"] = GenericErrorCodesNoMatchingCatalogItemForReceipt;
        _GenericErrorCodesMap["InvalidCurrencyCode"] = GenericErrorCodesInvalidCurrencyCode;
        _GenericErrorCodesMap["NoRealMoneyPriceForCatalogItem"] = GenericErrorCodesNoRealMoneyPriceForCatalogItem;
        _GenericErrorCodesMap["TradeInventoryItemIsNotTradable"] = GenericErrorCodesTradeInventoryItemIsNotTradable;
        _GenericErrorCodesMap["TradeAcceptedCatalogItemIsNotTradable"] = GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable;
        _GenericErrorCodesMap["UsersAlreadyFriends"] = GenericErrorCodesUsersAlreadyFriends;
        _GenericErrorCodesMap["LinkedIdentifierAlreadyClaimed"] = GenericErrorCodesLinkedIdentifierAlreadyClaimed;
        _GenericErrorCodesMap["CustomIdNotLinked"] = GenericErrorCodesCustomIdNotLinked;
        _GenericErrorCodesMap["TotalDataSizeExceeded"] = GenericErrorCodesTotalDataSizeExceeded;
        _GenericErrorCodesMap["DeleteKeyConflict"] = GenericErrorCodesDeleteKeyConflict;
        _GenericErrorCodesMap["InvalidXboxLiveToken"] = GenericErrorCodesInvalidXboxLiveToken;
        _GenericErrorCodesMap["ExpiredXboxLiveToken"] = GenericErrorCodesExpiredXboxLiveToken;
        _GenericErrorCodesMap["ResettableStatisticVersionRequired"] = GenericErrorCodesResettableStatisticVersionRequired;
        _GenericErrorCodesMap["NotAuthorizedByTitle"] = GenericErrorCodesNotAuthorizedByTitle;
        _GenericErrorCodesMap["NoPartnerEnabled"] = GenericErrorCodesNoPartnerEnabled;
        _GenericErrorCodesMap["InvalidPartnerResponse"] = GenericErrorCodesInvalidPartnerResponse;
        _GenericErrorCodesMap["APINotEnabledForGameServerAccess"] = GenericErrorCodesAPINotEnabledForGameServerAccess;
        _GenericErrorCodesMap["StatisticNotFound"] = GenericErrorCodesStatisticNotFound;
        _GenericErrorCodesMap["StatisticNameConflict"] = GenericErrorCodesStatisticNameConflict;
        _GenericErrorCodesMap["StatisticVersionClosedForWrites"] = GenericErrorCodesStatisticVersionClosedForWrites;
        _GenericErrorCodesMap["StatisticVersionInvalid"] = GenericErrorCodesStatisticVersionInvalid;
        _GenericErrorCodesMap["APIClientRequestRateLimitExceeded"] = GenericErrorCodesAPIClientRequestRateLimitExceeded;
        _GenericErrorCodesMap["InvalidJSONContent"] = GenericErrorCodesInvalidJSONContent;
        _GenericErrorCodesMap["InvalidDropTable"] = GenericErrorCodesInvalidDropTable;
        _GenericErrorCodesMap["StatisticVersionAlreadyIncrementedForScheduledInterval"] = GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval;
        _GenericErrorCodesMap["StatisticCountLimitExceeded"] = GenericErrorCodesStatisticCountLimitExceeded;
        _GenericErrorCodesMap["StatisticVersionIncrementRateExceeded"] = GenericErrorCodesStatisticVersionIncrementRateExceeded;
        _GenericErrorCodesMap["ContainerKeyInvalid"] = GenericErrorCodesContainerKeyInvalid;
        _GenericErrorCodesMap["CloudScriptExecutionTimeLimitExceeded"] = GenericErrorCodesCloudScriptExecutionTimeLimitExceeded;
        _GenericErrorCodesMap["NoWritePermissionsForEvent"] = GenericErrorCodesNoWritePermissionsForEvent;
        _GenericErrorCodesMap["CloudScriptFunctionArgumentSizeExceeded"] = GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded;
        _GenericErrorCodesMap["CloudScriptAPIRequestCountExceeded"] = GenericErrorCodesCloudScriptAPIRequestCountExceeded;
        _GenericErrorCodesMap["CloudScriptAPIRequestError"] = GenericErrorCodesCloudScriptAPIRequestError;
        _GenericErrorCodesMap["CloudScriptHTTPRequestError"] = GenericErrorCodesCloudScriptHTTPRequestError;
        _GenericErrorCodesMap["InsufficientGuildRole"] = GenericErrorCodesInsufficientGuildRole;
        _GenericErrorCodesMap["GuildNotFound"] = GenericErrorCodesGuildNotFound;
        _GenericErrorCodesMap["OverLimit"] = GenericErrorCodesOverLimit;
        _GenericErrorCodesMap["EventNotFound"] = GenericErrorCodesEventNotFound;
        _GenericErrorCodesMap["InvalidEventField"] = GenericErrorCodesInvalidEventField;
        _GenericErrorCodesMap["InvalidEventName"] = GenericErrorCodesInvalidEventName;
        _GenericErrorCodesMap["CatalogNotConfigured"] = GenericErrorCodesCatalogNotConfigured;
        _GenericErrorCodesMap["OperationNotSupportedForPlatform"] = GenericErrorCodesOperationNotSupportedForPlatform;
        _GenericErrorCodesMap["SegmentNotFound"] = GenericErrorCodesSegmentNotFound;
        _GenericErrorCodesMap["StoreNotFound"] = GenericErrorCodesStoreNotFound;
        _GenericErrorCodesMap["InvalidStatisticName"] = GenericErrorCodesInvalidStatisticName;
        _GenericErrorCodesMap["TitleNotQualifiedForLimit"] = GenericErrorCodesTitleNotQualifiedForLimit;
        _GenericErrorCodesMap["InvalidServiceLimitLevel"] = GenericErrorCodesInvalidServiceLimitLevel;
        _GenericErrorCodesMap["ServiceLimitLevelInTransition"] = GenericErrorCodesServiceLimitLevelInTransition;
        _GenericErrorCodesMap["CouponAlreadyRedeemed"] = GenericErrorCodesCouponAlreadyRedeemed;
        _GenericErrorCodesMap["GameServerBuildSizeLimitExceeded"] = GenericErrorCodesGameServerBuildSizeLimitExceeded;
        _GenericErrorCodesMap["GameServerBuildCountLimitExceeded"] = GenericErrorCodesGameServerBuildCountLimitExceeded;
        _GenericErrorCodesMap["VirtualCurrencyCountLimitExceeded"] = GenericErrorCodesVirtualCurrencyCountLimitExceeded;
        _GenericErrorCodesMap["VirtualCurrencyCodeExists"] = GenericErrorCodesVirtualCurrencyCodeExists;
        _GenericErrorCodesMap["TitleNewsItemCountLimitExceeded"] = GenericErrorCodesTitleNewsItemCountLimitExceeded;
        _GenericErrorCodesMap["InvalidTwitchToken"] = GenericErrorCodesInvalidTwitchToken;
        _GenericErrorCodesMap["TwitchResponseError"] = GenericErrorCodesTwitchResponseError;
        _GenericErrorCodesMap["ProfaneDisplayName"] = GenericErrorCodesProfaneDisplayName;
        _GenericErrorCodesMap["UserAlreadyAdded"] = GenericErrorCodesUserAlreadyAdded;
        _GenericErrorCodesMap["InvalidVirtualCurrencyCode"] = GenericErrorCodesInvalidVirtualCurrencyCode;
        _GenericErrorCodesMap["VirtualCurrencyCannotBeDeleted"] = GenericErrorCodesVirtualCurrencyCannotBeDeleted;
        _GenericErrorCodesMap["IdentifierAlreadyClaimed"] = GenericErrorCodesIdentifierAlreadyClaimed;
        _GenericErrorCodesMap["IdentifierNotLinked"] = GenericErrorCodesIdentifierNotLinked;
        _GenericErrorCodesMap["InvalidContinuationToken"] = GenericErrorCodesInvalidContinuationToken;
        _GenericErrorCodesMap["ExpiredContinuationToken"] = GenericErrorCodesExpiredContinuationToken;
        _GenericErrorCodesMap["InvalidSegment"] = GenericErrorCodesInvalidSegment;
        _GenericErrorCodesMap["InvalidSessionId"] = GenericErrorCodesInvalidSessionId;
        _GenericErrorCodesMap["SessionLogNotFound"] = GenericErrorCodesSessionLogNotFound;
        _GenericErrorCodesMap["InvalidSearchTerm"] = GenericErrorCodesInvalidSearchTerm;
        _GenericErrorCodesMap["TwoFactorAuthenticationTokenRequired"] = GenericErrorCodesTwoFactorAuthenticationTokenRequired;
        _GenericErrorCodesMap["GameServerHostCountLimitExceeded"] = GenericErrorCodesGameServerHostCountLimitExceeded;
        _GenericErrorCodesMap["PlayerTagCountLimitExceeded"] = GenericErrorCodesPlayerTagCountLimitExceeded;
        _GenericErrorCodesMap["RequestAlreadyRunning"] = GenericErrorCodesRequestAlreadyRunning;
        _GenericErrorCodesMap["ActionGroupNotFound"] = GenericErrorCodesActionGroupNotFound;
        _GenericErrorCodesMap["MaximumSegmentBulkActionJobsRunning"] = GenericErrorCodesMaximumSegmentBulkActionJobsRunning;
        _GenericErrorCodesMap["NoActionsOnPlayersInSegmentJob"] = GenericErrorCodesNoActionsOnPlayersInSegmentJob;
        _GenericErrorCodesMap["DuplicateStatisticName"] = GenericErrorCodesDuplicateStatisticName;
        _GenericErrorCodesMap["ScheduledTaskNameConflict"] = GenericErrorCodesScheduledTaskNameConflict;
        _GenericErrorCodesMap["ScheduledTaskCreateConflict"] = GenericErrorCodesScheduledTaskCreateConflict;
        _GenericErrorCodesMap["InvalidScheduledTaskName"] = GenericErrorCodesInvalidScheduledTaskName;
        _GenericErrorCodesMap["InvalidTaskSchedule"] = GenericErrorCodesInvalidTaskSchedule;
        _GenericErrorCodesMap["SteamNotEnabledForTitle"] = GenericErrorCodesSteamNotEnabledForTitle;
        _GenericErrorCodesMap["LimitNotAnUpgradeOption"] = GenericErrorCodesLimitNotAnUpgradeOption;
        _GenericErrorCodesMap["NoSecretKeyEnabledForCloudScript"] = GenericErrorCodesNoSecretKeyEnabledForCloudScript;
        _GenericErrorCodesMap["TaskNotFound"] = GenericErrorCodesTaskNotFound;
        _GenericErrorCodesMap["TaskInstanceNotFound"] = GenericErrorCodesTaskInstanceNotFound;
        _GenericErrorCodesMap["InvalidIdentityProviderId"] = GenericErrorCodesInvalidIdentityProviderId;
        _GenericErrorCodesMap["MisconfiguredIdentityProvider"] = GenericErrorCodesMisconfiguredIdentityProvider;
        _GenericErrorCodesMap["InvalidScheduledTaskType"] = GenericErrorCodesInvalidScheduledTaskType;
        _GenericErrorCodesMap["BillingInformationRequired"] = GenericErrorCodesBillingInformationRequired;
        _GenericErrorCodesMap["LimitedEditionItemUnavailable"] = GenericErrorCodesLimitedEditionItemUnavailable;
        _GenericErrorCodesMap["InvalidAdPlacementAndReward"] = GenericErrorCodesInvalidAdPlacementAndReward;
        _GenericErrorCodesMap["AllAdPlacementViewsAlreadyConsumed"] = GenericErrorCodesAllAdPlacementViewsAlreadyConsumed;
        _GenericErrorCodesMap["GoogleOAuthNotConfiguredForTitle"] = GenericErrorCodesGoogleOAuthNotConfiguredForTitle;
        _GenericErrorCodesMap["GoogleOAuthError"] = GenericErrorCodesGoogleOAuthError;
        _GenericErrorCodesMap["UserNotFriend"] = GenericErrorCodesUserNotFriend;
        _GenericErrorCodesMap["InvalidSignature"] = GenericErrorCodesInvalidSignature;
        _GenericErrorCodesMap["InvalidPublicKey"] = GenericErrorCodesInvalidPublicKey;
        _GenericErrorCodesMap["GoogleOAuthNoIdTokenIncludedInResponse"] = GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse;
        _GenericErrorCodesMap["StatisticUpdateInProgress"] = GenericErrorCodesStatisticUpdateInProgress;
        _GenericErrorCodesMap["LeaderboardVersionNotAvailable"] = GenericErrorCodesLeaderboardVersionNotAvailable;
        _GenericErrorCodesMap["StatisticAlreadyHasPrizeTable"] = GenericErrorCodesStatisticAlreadyHasPrizeTable;
        _GenericErrorCodesMap["PrizeTableHasOverlappingRanks"] = GenericErrorCodesPrizeTableHasOverlappingRanks;
        _GenericErrorCodesMap["PrizeTableHasMissingRanks"] = GenericErrorCodesPrizeTableHasMissingRanks;
        _GenericErrorCodesMap["PrizeTableRankStartsAtZero"] = GenericErrorCodesPrizeTableRankStartsAtZero;
        _GenericErrorCodesMap["InvalidStatistic"] = GenericErrorCodesInvalidStatistic;
        _GenericErrorCodesMap["ExpressionParseFailure"] = GenericErrorCodesExpressionParseFailure;
        _GenericErrorCodesMap["ExpressionInvokeFailure"] = GenericErrorCodesExpressionInvokeFailure;
        _GenericErrorCodesMap["ExpressionTooLong"] = GenericErrorCodesExpressionTooLong;
        _GenericErrorCodesMap["DataUpdateRateExceeded"] = GenericErrorCodesDataUpdateRateExceeded;
        _GenericErrorCodesMap["RestrictedEmailDomain"] = GenericErrorCodesRestrictedEmailDomain;
        _GenericErrorCodesMap["EncryptionKeyDisabled"] = GenericErrorCodesEncryptionKeyDisabled;
        _GenericErrorCodesMap["EncryptionKeyMissing"] = GenericErrorCodesEncryptionKeyMissing;
        _GenericErrorCodesMap["EncryptionKeyBroken"] = GenericErrorCodesEncryptionKeyBroken;
        _GenericErrorCodesMap["NoSharedSecretKeyConfigured"] = GenericErrorCodesNoSharedSecretKeyConfigured;
        _GenericErrorCodesMap["SecretKeyNotFound"] = GenericErrorCodesSecretKeyNotFound;
        _GenericErrorCodesMap["PlayerSecretAlreadyConfigured"] = GenericErrorCodesPlayerSecretAlreadyConfigured;
        _GenericErrorCodesMap["APIRequestsDisabledForTitle"] = GenericErrorCodesAPIRequestsDisabledForTitle;
        _GenericErrorCodesMap["InvalidSharedSecretKey"] = GenericErrorCodesInvalidSharedSecretKey;
        _GenericErrorCodesMap["PrizeTableHasNoRanks"] = GenericErrorCodesPrizeTableHasNoRanks;
        _GenericErrorCodesMap["ProfileDoesNotExist"] = GenericErrorCodesProfileDoesNotExist;
        _GenericErrorCodesMap["ContentS3OriginBucketNotConfigured"] = GenericErrorCodesContentS3OriginBucketNotConfigured;
        _GenericErrorCodesMap["InvalidEnvironmentForReceipt"] = GenericErrorCodesInvalidEnvironmentForReceipt;
        _GenericErrorCodesMap["EncryptedRequestNotAllowed"] = GenericErrorCodesEncryptedRequestNotAllowed;
        _GenericErrorCodesMap["SignedRequestNotAllowed"] = GenericErrorCodesSignedRequestNotAllowed;
        _GenericErrorCodesMap["RequestViewConstraintParamsNotAllowed"] = GenericErrorCodesRequestViewConstraintParamsNotAllowed;
        _GenericErrorCodesMap["BadPartnerConfiguration"] = GenericErrorCodesBadPartnerConfiguration;
        _GenericErrorCodesMap["XboxBPCertificateFailure"] = GenericErrorCodesXboxBPCertificateFailure;
        _GenericErrorCodesMap["XboxXASSExchangeFailure"] = GenericErrorCodesXboxXASSExchangeFailure;
        _GenericErrorCodesMap["InvalidEntityId"] = GenericErrorCodesInvalidEntityId;
        _GenericErrorCodesMap["StatisticValueAggregationOverflow"] = GenericErrorCodesStatisticValueAggregationOverflow;
        _GenericErrorCodesMap["EmailMessageFromAddressIsMissing"] = GenericErrorCodesEmailMessageFromAddressIsMissing;
        _GenericErrorCodesMap["EmailMessageToAddressIsMissing"] = GenericErrorCodesEmailMessageToAddressIsMissing;
        _GenericErrorCodesMap["SmtpServerAuthenticationError"] = GenericErrorCodesSmtpServerAuthenticationError;
        _GenericErrorCodesMap["SmtpServerLimitExceeded"] = GenericErrorCodesSmtpServerLimitExceeded;
        _GenericErrorCodesMap["SmtpServerInsufficientStorage"] = GenericErrorCodesSmtpServerInsufficientStorage;
        _GenericErrorCodesMap["SmtpServerCommunicationError"] = GenericErrorCodesSmtpServerCommunicationError;
        _GenericErrorCodesMap["SmtpServerGeneralFailure"] = GenericErrorCodesSmtpServerGeneralFailure;
        _GenericErrorCodesMap["EmailClientTimeout"] = GenericErrorCodesEmailClientTimeout;
        _GenericErrorCodesMap["EmailClientCanceledTask"] = GenericErrorCodesEmailClientCanceledTask;
        _GenericErrorCodesMap["EmailTemplateMissing"] = GenericErrorCodesEmailTemplateMissing;
        _GenericErrorCodesMap["InvalidHostForTitleId"] = GenericErrorCodesInvalidHostForTitleId;
        _GenericErrorCodesMap["EmailConfirmationTokenDoesNotExist"] = GenericErrorCodesEmailConfirmationTokenDoesNotExist;
        _GenericErrorCodesMap["EmailConfirmationTokenExpired"] = GenericErrorCodesEmailConfirmationTokenExpired;
        _GenericErrorCodesMap["AccountDeleted"] = GenericErrorCodesAccountDeleted;
        _GenericErrorCodesMap["PlayerSecretNotConfigured"] = GenericErrorCodesPlayerSecretNotConfigured;
        _GenericErrorCodesMap["InvalidSignatureTime"] = GenericErrorCodesInvalidSignatureTime;
        _GenericErrorCodesMap["NoContactEmailAddressFound"] = GenericErrorCodesNoContactEmailAddressFound;
        _GenericErrorCodesMap["InvalidAuthToken"] = GenericErrorCodesInvalidAuthToken;
        _GenericErrorCodesMap["AuthTokenDoesNotExist"] = GenericErrorCodesAuthTokenDoesNotExist;
        _GenericErrorCodesMap["AuthTokenExpired"] = GenericErrorCodesAuthTokenExpired;
        _GenericErrorCodesMap["AuthTokenAlreadyUsedToResetPassword"] = GenericErrorCodesAuthTokenAlreadyUsedToResetPassword;
        _GenericErrorCodesMap["MembershipNameTooLong"] = GenericErrorCodesMembershipNameTooLong;
        _GenericErrorCodesMap["MembershipNotFound"] = GenericErrorCodesMembershipNotFound;
        _GenericErrorCodesMap["GoogleServiceAccountInvalid"] = GenericErrorCodesGoogleServiceAccountInvalid;
        _GenericErrorCodesMap["GoogleServiceAccountParseFailure"] = GenericErrorCodesGoogleServiceAccountParseFailure;
        _GenericErrorCodesMap["EntityTokenMissing"] = GenericErrorCodesEntityTokenMissing;
        _GenericErrorCodesMap["EntityTokenInvalid"] = GenericErrorCodesEntityTokenInvalid;
        _GenericErrorCodesMap["EntityTokenExpired"] = GenericErrorCodesEntityTokenExpired;
        _GenericErrorCodesMap["EntityTokenRevoked"] = GenericErrorCodesEntityTokenRevoked;
        _GenericErrorCodesMap["InvalidProductForSubscription"] = GenericErrorCodesInvalidProductForSubscription;
        _GenericErrorCodesMap["XboxInaccessible"] = GenericErrorCodesXboxInaccessible;
        _GenericErrorCodesMap["SubscriptionAlreadyTaken"] = GenericErrorCodesSubscriptionAlreadyTaken;
        _GenericErrorCodesMap["SmtpAddonNotEnabled"] = GenericErrorCodesSmtpAddonNotEnabled;
        _GenericErrorCodesMap["APIConcurrentRequestLimitExceeded"] = GenericErrorCodesAPIConcurrentRequestLimitExceeded;
        _GenericErrorCodesMap["XboxRejectedXSTSExchangeRequest"] = GenericErrorCodesXboxRejectedXSTSExchangeRequest;
        _GenericErrorCodesMap["VariableNotDefined"] = GenericErrorCodesVariableNotDefined;
        _GenericErrorCodesMap["TemplateVersionNotDefined"] = GenericErrorCodesTemplateVersionNotDefined;
        _GenericErrorCodesMap["FileTooLarge"] = GenericErrorCodesFileTooLarge;
        _GenericErrorCodesMap["TitleDeleted"] = GenericErrorCodesTitleDeleted;
        _GenericErrorCodesMap["TitleContainsUserAccounts"] = GenericErrorCodesTitleContainsUserAccounts;
        _GenericErrorCodesMap["TitleDeletionPlayerCleanupFailure"] = GenericErrorCodesTitleDeletionPlayerCleanupFailure;
        _GenericErrorCodesMap["EntityFileOperationPending"] = GenericErrorCodesEntityFileOperationPending;
        _GenericErrorCodesMap["NoEntityFileOperationPending"] = GenericErrorCodesNoEntityFileOperationPending;
        _GenericErrorCodesMap["EntityProfileVersionMismatch"] = GenericErrorCodesEntityProfileVersionMismatch;
        _GenericErrorCodesMap["TemplateVersionTooOld"] = GenericErrorCodesTemplateVersionTooOld;
        _GenericErrorCodesMap["MembershipDefinitionInUse"] = GenericErrorCodesMembershipDefinitionInUse;
        _GenericErrorCodesMap["PaymentPageNotConfigured"] = GenericErrorCodesPaymentPageNotConfigured;
        _GenericErrorCodesMap["FailedLoginAttemptRateLimitExceeded"] = GenericErrorCodesFailedLoginAttemptRateLimitExceeded;
        _GenericErrorCodesMap["EntityBlockedByGroup"] = GenericErrorCodesEntityBlockedByGroup;
        _GenericErrorCodesMap["RoleDoesNotExist"] = GenericErrorCodesRoleDoesNotExist;
        _GenericErrorCodesMap["EntityIsAlreadyMember"] = GenericErrorCodesEntityIsAlreadyMember;
        _GenericErrorCodesMap["DuplicateRoleId"] = GenericErrorCodesDuplicateRoleId;
        _GenericErrorCodesMap["GroupInvitationNotFound"] = GenericErrorCodesGroupInvitationNotFound;
        _GenericErrorCodesMap["GroupApplicationNotFound"] = GenericErrorCodesGroupApplicationNotFound;
        _GenericErrorCodesMap["OutstandingInvitationAcceptedInstead"] = GenericErrorCodesOutstandingInvitationAcceptedInstead;
        _GenericErrorCodesMap["OutstandingApplicationAcceptedInstead"] = GenericErrorCodesOutstandingApplicationAcceptedInstead;
        _GenericErrorCodesMap["RoleIsGroupDefaultMember"] = GenericErrorCodesRoleIsGroupDefaultMember;
        _GenericErrorCodesMap["RoleIsGroupAdmin"] = GenericErrorCodesRoleIsGroupAdmin;
        _GenericErrorCodesMap["RoleNameNotAvailable"] = GenericErrorCodesRoleNameNotAvailable;
        _GenericErrorCodesMap["GroupNameNotAvailable"] = GenericErrorCodesGroupNameNotAvailable;
        _GenericErrorCodesMap["EmailReportAlreadySent"] = GenericErrorCodesEmailReportAlreadySent;
        _GenericErrorCodesMap["EmailReportRecipientBlacklisted"] = GenericErrorCodesEmailReportRecipientBlacklisted;
        _GenericErrorCodesMap["EventNamespaceNotAllowed"] = GenericErrorCodesEventNamespaceNotAllowed;
        _GenericErrorCodesMap["EventEntityNotAllowed"] = GenericErrorCodesEventEntityNotAllowed;
        _GenericErrorCodesMap["InvalidEntityType"] = GenericErrorCodesInvalidEntityType;
        _GenericErrorCodesMap["NullTokenResultFromAad"] = GenericErrorCodesNullTokenResultFromAad;
        _GenericErrorCodesMap["InvalidTokenResultFromAad"] = GenericErrorCodesInvalidTokenResultFromAad;
        _GenericErrorCodesMap["NoValidCertificateForAad"] = GenericErrorCodesNoValidCertificateForAad;
        _GenericErrorCodesMap["InvalidCertificateForAad"] = GenericErrorCodesInvalidCertificateForAad;
        _GenericErrorCodesMap["DuplicateDropTableId"] = GenericErrorCodesDuplicateDropTableId;
        _GenericErrorCodesMap["MultiplayerServerError"] = GenericErrorCodesMultiplayerServerError;
        _GenericErrorCodesMap["MultiplayerServerTooManyRequests"] = GenericErrorCodesMultiplayerServerTooManyRequests;
        _GenericErrorCodesMap["MultiplayerServerNoContent"] = GenericErrorCodesMultiplayerServerNoContent;
        _GenericErrorCodesMap["MultiplayerServerBadRequest"] = GenericErrorCodesMultiplayerServerBadRequest;
        _GenericErrorCodesMap["MultiplayerServerUnauthorized"] = GenericErrorCodesMultiplayerServerUnauthorized;
        _GenericErrorCodesMap["MultiplayerServerForbidden"] = GenericErrorCodesMultiplayerServerForbidden;
        _GenericErrorCodesMap["MultiplayerServerNotFound"] = GenericErrorCodesMultiplayerServerNotFound;
        _GenericErrorCodesMap["MultiplayerServerConflict"] = GenericErrorCodesMultiplayerServerConflict;
        _GenericErrorCodesMap["MultiplayerServerInternalServerError"] = GenericErrorCodesMultiplayerServerInternalServerError;
        _GenericErrorCodesMap["MultiplayerServerUnavailable"] = GenericErrorCodesMultiplayerServerUnavailable;
        _GenericErrorCodesMap["ExplicitContentDetected"] = GenericErrorCodesExplicitContentDetected;
        _GenericErrorCodesMap["PIIContentDetected"] = GenericErrorCodesPIIContentDetected;
        _GenericErrorCodesMap["InvalidScheduledTaskParameter"] = GenericErrorCodesInvalidScheduledTaskParameter;
        _GenericErrorCodesMap["PerEntityEventRateLimitExceeded"] = GenericErrorCodesPerEntityEventRateLimitExceeded;
        _GenericErrorCodesMap["TitleDefaultLanguageNotSet"] = GenericErrorCodesTitleDefaultLanguageNotSet;
        _GenericErrorCodesMap["EmailTemplateMissingDefaultVersion"] = GenericErrorCodesEmailTemplateMissingDefaultVersion;
        _GenericErrorCodesMap["FacebookInstantGamesIdNotLinked"] = GenericErrorCodesFacebookInstantGamesIdNotLinked;
        _GenericErrorCodesMap["InvalidFacebookInstantGamesSignature"] = GenericErrorCodesInvalidFacebookInstantGamesSignature;
        _GenericErrorCodesMap["FacebookInstantGamesAuthNotConfiguredForTitle"] = GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle;
        _GenericErrorCodesMap["EntityProfileConstraintValidationFailed"] = GenericErrorCodesEntityProfileConstraintValidationFailed;
        _GenericErrorCodesMap["TelemetryIngestionKeyPending"] = GenericErrorCodesTelemetryIngestionKeyPending;
        _GenericErrorCodesMap["TelemetryIngestionKeyNotFound"] = GenericErrorCodesTelemetryIngestionKeyNotFound;
        _GenericErrorCodesMap["StatisticTagRequired"] = GenericErrorCodesStatisticTagRequired;
        _GenericErrorCodesMap["StatisticTagInvalid"] = GenericErrorCodesStatisticTagInvalid;
        _GenericErrorCodesMap["DataIntegrityError"] = GenericErrorCodesDataIntegrityError;
        _GenericErrorCodesMap["VirtualCurrencyCannotBeSetToOlderVersion"] = GenericErrorCodesVirtualCurrencyCannotBeSetToOlderVersion;
        _GenericErrorCodesMap["VirtualCurrencyMustBeWithinIntegerRange"] = GenericErrorCodesVirtualCurrencyMustBeWithinIntegerRange;
        _GenericErrorCodesMap["EmailTemplateInvalidSyntax"] = GenericErrorCodesEmailTemplateInvalidSyntax;
        _GenericErrorCodesMap["EmailTemplateMissingCallback"] = GenericErrorCodesEmailTemplateMissingCallback;
        _GenericErrorCodesMap["PushNotificationTemplateInvalidPayload"] = GenericErrorCodesPushNotificationTemplateInvalidPayload;
        _GenericErrorCodesMap["InvalidLocalizedPushNotificationLanguage"] = GenericErrorCodesInvalidLocalizedPushNotificationLanguage;
        _GenericErrorCodesMap["MissingLocalizedPushNotificationMessage"] = GenericErrorCodesMissingLocalizedPushNotificationMessage;
        _GenericErrorCodesMap["PushNotificationTemplateMissingPlatformPayload"] = GenericErrorCodesPushNotificationTemplateMissingPlatformPayload;
        _GenericErrorCodesMap["PushNotificationTemplatePayloadContainsInvalidJson"] = GenericErrorCodesPushNotificationTemplatePayloadContainsInvalidJson;
        _GenericErrorCodesMap["PushNotificationTemplateContainsInvalidIosPayload"] = GenericErrorCodesPushNotificationTemplateContainsInvalidIosPayload;
        _GenericErrorCodesMap["PushNotificationTemplateContainsInvalidAndroidPayload"] = GenericErrorCodesPushNotificationTemplateContainsInvalidAndroidPayload;
        _GenericErrorCodesMap["PushNotificationTemplateIosPayloadMissingNotificationBody"] = GenericErrorCodesPushNotificationTemplateIosPayloadMissingNotificationBody;
        _GenericErrorCodesMap["PushNotificationTemplateAndroidPayloadMissingNotificationBody"] = GenericErrorCodesPushNotificationTemplateAndroidPayloadMissingNotificationBody;
        _GenericErrorCodesMap["PushNotificationTemplateNotFound"] = GenericErrorCodesPushNotificationTemplateNotFound;
        _GenericErrorCodesMap["PushNotificationTemplateMissingDefaultVersion"] = GenericErrorCodesPushNotificationTemplateMissingDefaultVersion;
        _GenericErrorCodesMap["PushNotificationTemplateInvalidSyntax"] = GenericErrorCodesPushNotificationTemplateInvalidSyntax;
        _GenericErrorCodesMap["PushNotificationTemplateNoCustomPayloadForV1"] = GenericErrorCodesPushNotificationTemplateNoCustomPayloadForV1;
        _GenericErrorCodesMap["NoLeaderboardForStatistic"] = GenericErrorCodesNoLeaderboardForStatistic;
        _GenericErrorCodesMap["TitleNewsMissingDefaultLanguage"] = GenericErrorCodesTitleNewsMissingDefaultLanguage;
        _GenericErrorCodesMap["TitleNewsNotFound"] = GenericErrorCodesTitleNewsNotFound;
        _GenericErrorCodesMap["TitleNewsDuplicateLanguage"] = GenericErrorCodesTitleNewsDuplicateLanguage;
        _GenericErrorCodesMap["TitleNewsMissingTitleOrBody"] = GenericErrorCodesTitleNewsMissingTitleOrBody;
        _GenericErrorCodesMap["TitleNewsInvalidLanguage"] = GenericErrorCodesTitleNewsInvalidLanguage;
        _GenericErrorCodesMap["EmailRecipientBlacklisted"] = GenericErrorCodesEmailRecipientBlacklisted;
        _GenericErrorCodesMap["InvalidGameCenterAuthRequest"] = GenericErrorCodesInvalidGameCenterAuthRequest;
        _GenericErrorCodesMap["GameCenterAuthenticationFailed"] = GenericErrorCodesGameCenterAuthenticationFailed;
        _GenericErrorCodesMap["MatchmakingEntityInvalid"] = GenericErrorCodesMatchmakingEntityInvalid;
        _GenericErrorCodesMap["MatchmakingPlayerAttributesInvalid"] = GenericErrorCodesMatchmakingPlayerAttributesInvalid;
        _GenericErrorCodesMap["MatchmakingCreateTicketRequestMissing"] = GenericErrorCodesMatchmakingCreateTicketRequestMissing;
        _GenericErrorCodesMap["MatchmakingCreateTicketCreatorMissing"] = GenericErrorCodesMatchmakingCreateTicketCreatorMissing;
        _GenericErrorCodesMap["MatchmakingCreateTicketCreatorIdMissing"] = GenericErrorCodesMatchmakingCreateTicketCreatorIdMissing;
        _GenericErrorCodesMap["MatchmakingCreateTicketMemberListMissing"] = GenericErrorCodesMatchmakingCreateTicketMemberListMissing;
        _GenericErrorCodesMap["MatchmakingCreateTicketGiveUpAfterInvalid"] = GenericErrorCodesMatchmakingCreateTicketGiveUpAfterInvalid;
        _GenericErrorCodesMap["MatchmakingTicketIdMissing"] = GenericErrorCodesMatchmakingTicketIdMissing;
        _GenericErrorCodesMap["MatchmakingMatchIdMissing"] = GenericErrorCodesMatchmakingMatchIdMissing;
        _GenericErrorCodesMap["MatchmakingMatchIdIdMissing"] = GenericErrorCodesMatchmakingMatchIdIdMissing;
        _GenericErrorCodesMap["MatchmakingQueueNameMissing"] = GenericErrorCodesMatchmakingQueueNameMissing;
        _GenericErrorCodesMap["MatchmakingTitleIdMissing"] = GenericErrorCodesMatchmakingTitleIdMissing;
        _GenericErrorCodesMap["MatchmakingTicketIdIdMissing"] = GenericErrorCodesMatchmakingTicketIdIdMissing;
        _GenericErrorCodesMap["MatchmakingPlayerIdMissing"] = GenericErrorCodesMatchmakingPlayerIdMissing;
        _GenericErrorCodesMap["MatchmakingJoinTicketPlayerMissing"] = GenericErrorCodesMatchmakingJoinTicketPlayerMissing;
        _GenericErrorCodesMap["MatchmakingQueueConfigNotFound"] = GenericErrorCodesMatchmakingQueueConfigNotFound;
        _GenericErrorCodesMap["MatchmakingMatchNotFound"] = GenericErrorCodesMatchmakingMatchNotFound;
        _GenericErrorCodesMap["MatchmakingTicketNotFound"] = GenericErrorCodesMatchmakingTicketNotFound;
        _GenericErrorCodesMap["MatchmakingCreateTicketServerIdentityInvalid"] = GenericErrorCodesMatchmakingCreateTicketServerIdentityInvalid;
        _GenericErrorCodesMap["MatchmakingCreateTicketClientIdentityInvalid"] = GenericErrorCodesMatchmakingCreateTicketClientIdentityInvalid;
        _GenericErrorCodesMap["MatchmakingGetTicketPlayerMismatch"] = GenericErrorCodesMatchmakingGetTicketPlayerMismatch;
        _GenericErrorCodesMap["MatchmakingJoinTicketServerIdentityInvalid"] = GenericErrorCodesMatchmakingJoinTicketServerIdentityInvalid;
        _GenericErrorCodesMap["MatchmakingJoinTicketPlayerIdentityMismatch"] = GenericErrorCodesMatchmakingJoinTicketPlayerIdentityMismatch;
        _GenericErrorCodesMap["MatchmakingCancelTicketServerIdentityInvalid"] = GenericErrorCodesMatchmakingCancelTicketServerIdentityInvalid;
        _GenericErrorCodesMap["MatchmakingCancelTicketPlayerIdentityMismatch"] = GenericErrorCodesMatchmakingCancelTicketPlayerIdentityMismatch;
        _GenericErrorCodesMap["MatchmakingGetMatchIdentityMismatch"] = GenericErrorCodesMatchmakingGetMatchIdentityMismatch;
        _GenericErrorCodesMap["MatchmakingPlayerIdentityMismatch"] = GenericErrorCodesMatchmakingPlayerIdentityMismatch;
        _GenericErrorCodesMap["MatchmakingAlreadyJoinedTicket"] = GenericErrorCodesMatchmakingAlreadyJoinedTicket;
        _GenericErrorCodesMap["MatchmakingTicketAlreadyCompleted"] = GenericErrorCodesMatchmakingTicketAlreadyCompleted;
        _GenericErrorCodesMap["MatchmakingClientTimeout"] = GenericErrorCodesMatchmakingClientTimeout;
        _GenericErrorCodesMap["MatchmakingQueueConfigInvalid"] = GenericErrorCodesMatchmakingQueueConfigInvalid;
        _GenericErrorCodesMap["MatchmakingMemberProfileInvalid"] = GenericErrorCodesMatchmakingMemberProfileInvalid;
        _GenericErrorCodesMap["WriteAttemptedDuringExport"] = GenericErrorCodesWriteAttemptedDuringExport;
        _GenericErrorCodesMap["NintendoSwitchDeviceIdNotLinked"] = GenericErrorCodesNintendoSwitchDeviceIdNotLinked;
        _GenericErrorCodesMap["MatchmakingNotEnabled"] = GenericErrorCodesMatchmakingNotEnabled;
        _GenericErrorCodesMap["MatchmakingGetStatisticsIdentityInvalid"] = GenericErrorCodesMatchmakingGetStatisticsIdentityInvalid;
        _GenericErrorCodesMap["MatchmakingBucketOwnerNotFound"] = GenericErrorCodesMatchmakingBucketOwnerNotFound;
        _GenericErrorCodesMap["CannotEnableMultiplayerServersForTitle"] = GenericErrorCodesCannotEnableMultiplayerServersForTitle;
        _GenericErrorCodesMap["MatchmakingCancelAllTicketsUnauthorized"] = GenericErrorCodesMatchmakingCancelAllTicketsUnauthorized;
        _GenericErrorCodesMap["MatchmakingListTicketsUnauthorized"] = GenericErrorCodesMatchmakingListTicketsUnauthorized;
        _GenericErrorCodesMap["MatchmakingPlayerAttributesTooLarge"] = GenericErrorCodesMatchmakingPlayerAttributesTooLarge;
        _GenericErrorCodesMap["MatchmakingNumberOfPlayersInTicketTooLarge"] = GenericErrorCodesMatchmakingNumberOfPlayersInTicketTooLarge;
        _GenericErrorCodesMap["MatchmakingMatchTotalAttributeIsNegative"] = GenericErrorCodesMatchmakingMatchTotalAttributeIsNegative;
        _GenericErrorCodesMap["MatchmakingAttributeTypeInvalid"] = GenericErrorCodesMatchmakingAttributeTypeInvalid;
        _GenericErrorCodesMap["MatchmakingMatchTotalAttributeTooLarge"] = GenericErrorCodesMatchmakingMatchTotalAttributeTooLarge;
        _GenericErrorCodesMap["MatchmakingMatchTotalAttributeSumTooLarge"] = GenericErrorCodesMatchmakingMatchTotalAttributeSumTooLarge;
        _GenericErrorCodesMap["MatchmakingTicketUnmatchable"] = GenericErrorCodesMatchmakingTicketUnmatchable;
        _GenericErrorCodesMap["MatchmakingCommonRegionMissing"] = GenericErrorCodesMatchmakingCommonRegionMissing;
        _GenericErrorCodesMap["MatchmakingLatencyMeasurementMissing"] = GenericErrorCodesMatchmakingLatencyMeasurementMissing;
        _GenericErrorCodesMap["MatchmakingStatisticsNotFound"] = GenericErrorCodesMatchmakingStatisticsNotFound;
        _GenericErrorCodesMap["MatchmakingPlayerHasNotJoinedTicket"] = GenericErrorCodesMatchmakingPlayerHasNotJoinedTicket;
        _GenericErrorCodesMap["CannotEnablePartiesForTitle"] = GenericErrorCodesCannotEnablePartiesForTitle;
        _GenericErrorCodesMap["PartyError"] = GenericErrorCodesPartyError;
        _GenericErrorCodesMap["PartyRequests"] = GenericErrorCodesPartyRequests;
        _GenericErrorCodesMap["PartyNoContent"] = GenericErrorCodesPartyNoContent;
        _GenericErrorCodesMap["PartyBadRequest"] = GenericErrorCodesPartyBadRequest;
        _GenericErrorCodesMap["PartyUnauthorized"] = GenericErrorCodesPartyUnauthorized;
        _GenericErrorCodesMap["PartyForbidden"] = GenericErrorCodesPartyForbidden;
        _GenericErrorCodesMap["PartyNotFound"] = GenericErrorCodesPartyNotFound;
        _GenericErrorCodesMap["PartyConflict"] = GenericErrorCodesPartyConflict;
        _GenericErrorCodesMap["PartyInternalServerError"] = GenericErrorCodesPartyInternalServerError;
        _GenericErrorCodesMap["PartyUnavailable"] = GenericErrorCodesPartyUnavailable;
        _GenericErrorCodesMap["PartyTooManyRequests"] = GenericErrorCodesPartyTooManyRequests;
        _GenericErrorCodesMap["TitleConfigNotFound"] = GenericErrorCodesTitleConfigNotFound;
        _GenericErrorCodesMap["TitleConfigUpdateConflict"] = GenericErrorCodesTitleConfigUpdateConflict;
        _GenericErrorCodesMap["TitleConfigSerializationError"] = GenericErrorCodesTitleConfigSerializationError;
        _GenericErrorCodesMap["CatalogEntityInvalid"] = GenericErrorCodesCatalogEntityInvalid;
        _GenericErrorCodesMap["CatalogTitleIdMissing"] = GenericErrorCodesCatalogTitleIdMissing;
        _GenericErrorCodesMap["CatalogPlayerIdMissing"] = GenericErrorCodesCatalogPlayerIdMissing;
        _GenericErrorCodesMap["CatalogClientIdentityInvalid"] = GenericErrorCodesCatalogClientIdentityInvalid;
        _GenericErrorCodesMap["CatalogOneOrMoreFilesInvalid"] = GenericErrorCodesCatalogOneOrMoreFilesInvalid;
        _GenericErrorCodesMap["CatalogItemMetadataInvalid"] = GenericErrorCodesCatalogItemMetadataInvalid;
        _GenericErrorCodesMap["CatalogItemIdInvalid"] = GenericErrorCodesCatalogItemIdInvalid;
        _GenericErrorCodesMap["CatalogSearchParameterInvalid"] = GenericErrorCodesCatalogSearchParameterInvalid;
        _GenericErrorCodesMap["CatalogFeatureDisabled"] = GenericErrorCodesCatalogFeatureDisabled;
        _GenericErrorCodesMap["CatalogConfigMissing"] = GenericErrorCodesCatalogConfigMissing;
        _GenericErrorCodesMap["CatalogConfigTooManyContentTypes"] = GenericErrorCodesCatalogConfigTooManyContentTypes;
        _GenericErrorCodesMap["CatalogConfigContentTypeTooLong"] = GenericErrorCodesCatalogConfigContentTypeTooLong;
        _GenericErrorCodesMap["CatalogConfigTooManyTags"] = GenericErrorCodesCatalogConfigTooManyTags;
        _GenericErrorCodesMap["CatalogConfigTagTooLong"] = GenericErrorCodesCatalogConfigTagTooLong;

    }

    auto output = _GenericErrorCodesMap.find(obj.GetString());
    if (output != _GenericErrorCodesMap.end())
        return output->second;

    return GenericErrorCodesSuccess; // Basically critical fail
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
    if (ABTestParent.length() > 0) { writer.String("ABTestParent"); writer.String(ABTestParent.c_str()); }
    writer.String("Id"); writer.String(Id.c_str());
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    writer.EndObject();
}

bool GetSegmentResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ABTestParent_member = obj.FindMember("ABTestParent");
    if (ABTestParent_member != obj.MemberEnd() && !ABTestParent_member->value.IsNull()) ABTestParent = ABTestParent_member->value.GetString();
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

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
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Uint(IfChangedFromDataVersion); }
    if (!Keys.empty()) {
        writer.String("Keys");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GetCharacterDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
    if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();
    const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
    if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
    if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
    writer.EndObject();
}

bool UserDataRecord::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
    if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
    const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
    if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

    return true;
}

GetCharacterDataResult::~GetCharacterDataResult()
{

}

void GetCharacterDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (!Data.empty()) {
        writer.String("Data");
        writer.StartObject();
        for (std::map<std::string, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("DataVersion"); writer.Uint(DataVersion);
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.EndObject();
}

bool GetCharacterDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetCharacterInventoryRequest::~GetCharacterInventoryRequest()
{

}

void GetCharacterInventoryRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GetCharacterInventoryRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
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

GetCharacterInventoryResult::~GetCharacterInventoryResult()
{

}

void GetCharacterInventoryResult::writeJSON(PFStringJsonWriter& writer)
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
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
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
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
    writer.String("StartPosition"); writer.Int(StartPosition);
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.EndObject();
}

bool GetCharacterLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
    const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

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
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GetCharacterStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetCharacterStatisticsResult::~GetCharacterStatisticsResult()
{

}

void GetCharacterStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (!CharacterStatistics.empty()) {
        writer.String("CharacterStatistics");
        writer.StartObject();
        for (std::map<std::string, Int32>::iterator iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.Int(iter->second);
        }
        writer.EndObject();
    }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.EndObject();
}

bool GetCharacterStatisticsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
    if (CharacterStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
            CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetContentDownloadUrlRequest::~GetContentDownloadUrlRequest()
{

}

void GetContentDownloadUrlRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (HttpMethod.length() > 0) { writer.String("HttpMethod"); writer.String(HttpMethod.c_str()); }
    writer.String("Key"); writer.String(Key.c_str());
    if (ThruCDN.notNull()) { writer.String("ThruCDN"); writer.Bool(ThruCDN); }
    writer.EndObject();
}

bool GetContentDownloadUrlRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator HttpMethod_member = obj.FindMember("HttpMethod");
    if (HttpMethod_member != obj.MemberEnd() && !HttpMethod_member->value.IsNull()) HttpMethod = HttpMethod_member->value.GetString();
    const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
    if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
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

PlayerProfileViewConstraints::~PlayerProfileViewConstraints()
{

}

void PlayerProfileViewConstraints::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ShowAvatarUrl"); writer.Bool(ShowAvatarUrl);
    writer.String("ShowBannedUntil"); writer.Bool(ShowBannedUntil);
    writer.String("ShowCampaignAttributions"); writer.Bool(ShowCampaignAttributions);
    writer.String("ShowContactEmailAddresses"); writer.Bool(ShowContactEmailAddresses);
    writer.String("ShowCreated"); writer.Bool(ShowCreated);
    writer.String("ShowDisplayName"); writer.Bool(ShowDisplayName);
    writer.String("ShowLastLogin"); writer.Bool(ShowLastLogin);
    writer.String("ShowLinkedAccounts"); writer.Bool(ShowLinkedAccounts);
    writer.String("ShowLocations"); writer.Bool(ShowLocations);
    writer.String("ShowMemberships"); writer.Bool(ShowMemberships);
    writer.String("ShowOrigination"); writer.Bool(ShowOrigination);
    writer.String("ShowPushNotificationRegistrations"); writer.Bool(ShowPushNotificationRegistrations);
    writer.String("ShowStatistics"); writer.Bool(ShowStatistics);
    writer.String("ShowTags"); writer.Bool(ShowTags);
    writer.String("ShowTotalValueToDateInUsd"); writer.Bool(ShowTotalValueToDateInUsd);
    writer.String("ShowValuesToDate"); writer.Bool(ShowValuesToDate);
    writer.EndObject();
}

bool PlayerProfileViewConstraints::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ShowAvatarUrl_member = obj.FindMember("ShowAvatarUrl");
    if (ShowAvatarUrl_member != obj.MemberEnd() && !ShowAvatarUrl_member->value.IsNull()) ShowAvatarUrl = ShowAvatarUrl_member->value.GetBool();
    const Value::ConstMemberIterator ShowBannedUntil_member = obj.FindMember("ShowBannedUntil");
    if (ShowBannedUntil_member != obj.MemberEnd() && !ShowBannedUntil_member->value.IsNull()) ShowBannedUntil = ShowBannedUntil_member->value.GetBool();
    const Value::ConstMemberIterator ShowCampaignAttributions_member = obj.FindMember("ShowCampaignAttributions");
    if (ShowCampaignAttributions_member != obj.MemberEnd() && !ShowCampaignAttributions_member->value.IsNull()) ShowCampaignAttributions = ShowCampaignAttributions_member->value.GetBool();
    const Value::ConstMemberIterator ShowContactEmailAddresses_member = obj.FindMember("ShowContactEmailAddresses");
    if (ShowContactEmailAddresses_member != obj.MemberEnd() && !ShowContactEmailAddresses_member->value.IsNull()) ShowContactEmailAddresses = ShowContactEmailAddresses_member->value.GetBool();
    const Value::ConstMemberIterator ShowCreated_member = obj.FindMember("ShowCreated");
    if (ShowCreated_member != obj.MemberEnd() && !ShowCreated_member->value.IsNull()) ShowCreated = ShowCreated_member->value.GetBool();
    const Value::ConstMemberIterator ShowDisplayName_member = obj.FindMember("ShowDisplayName");
    if (ShowDisplayName_member != obj.MemberEnd() && !ShowDisplayName_member->value.IsNull()) ShowDisplayName = ShowDisplayName_member->value.GetBool();
    const Value::ConstMemberIterator ShowLastLogin_member = obj.FindMember("ShowLastLogin");
    if (ShowLastLogin_member != obj.MemberEnd() && !ShowLastLogin_member->value.IsNull()) ShowLastLogin = ShowLastLogin_member->value.GetBool();
    const Value::ConstMemberIterator ShowLinkedAccounts_member = obj.FindMember("ShowLinkedAccounts");
    if (ShowLinkedAccounts_member != obj.MemberEnd() && !ShowLinkedAccounts_member->value.IsNull()) ShowLinkedAccounts = ShowLinkedAccounts_member->value.GetBool();
    const Value::ConstMemberIterator ShowLocations_member = obj.FindMember("ShowLocations");
    if (ShowLocations_member != obj.MemberEnd() && !ShowLocations_member->value.IsNull()) ShowLocations = ShowLocations_member->value.GetBool();
    const Value::ConstMemberIterator ShowMemberships_member = obj.FindMember("ShowMemberships");
    if (ShowMemberships_member != obj.MemberEnd() && !ShowMemberships_member->value.IsNull()) ShowMemberships = ShowMemberships_member->value.GetBool();
    const Value::ConstMemberIterator ShowOrigination_member = obj.FindMember("ShowOrigination");
    if (ShowOrigination_member != obj.MemberEnd() && !ShowOrigination_member->value.IsNull()) ShowOrigination = ShowOrigination_member->value.GetBool();
    const Value::ConstMemberIterator ShowPushNotificationRegistrations_member = obj.FindMember("ShowPushNotificationRegistrations");
    if (ShowPushNotificationRegistrations_member != obj.MemberEnd() && !ShowPushNotificationRegistrations_member->value.IsNull()) ShowPushNotificationRegistrations = ShowPushNotificationRegistrations_member->value.GetBool();
    const Value::ConstMemberIterator ShowStatistics_member = obj.FindMember("ShowStatistics");
    if (ShowStatistics_member != obj.MemberEnd() && !ShowStatistics_member->value.IsNull()) ShowStatistics = ShowStatistics_member->value.GetBool();
    const Value::ConstMemberIterator ShowTags_member = obj.FindMember("ShowTags");
    if (ShowTags_member != obj.MemberEnd() && !ShowTags_member->value.IsNull()) ShowTags = ShowTags_member->value.GetBool();
    const Value::ConstMemberIterator ShowTotalValueToDateInUsd_member = obj.FindMember("ShowTotalValueToDateInUsd");
    if (ShowTotalValueToDateInUsd_member != obj.MemberEnd() && !ShowTotalValueToDateInUsd_member->value.IsNull()) ShowTotalValueToDateInUsd = ShowTotalValueToDateInUsd_member->value.GetBool();
    const Value::ConstMemberIterator ShowValuesToDate_member = obj.FindMember("ShowValuesToDate");
    if (ShowValuesToDate_member != obj.MemberEnd() && !ShowValuesToDate_member->value.IsNull()) ShowValuesToDate = ShowValuesToDate_member->value.GetBool();

    return true;
}

GetFriendLeaderboardRequest::~GetFriendLeaderboardRequest()
{
    if (ProfileConstraints != NULL) delete ProfileConstraints;

}

void GetFriendLeaderboardRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (IncludeFacebookFriends.notNull()) { writer.String("IncludeFacebookFriends"); writer.Bool(IncludeFacebookFriends); }
    if (IncludeSteamFriends.notNull()) { writer.String("IncludeSteamFriends"); writer.Bool(IncludeSteamFriends); }
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (ProfileConstraints != NULL) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
    writer.String("StartPosition"); writer.Int(StartPosition);
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
    if (XboxToken.length() > 0) { writer.String("XboxToken"); writer.String(XboxToken.c_str()); }
    writer.EndObject();
}

bool GetFriendLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
    if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
    const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
    if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
    if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
    const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::ConstMemberIterator XboxToken_member = obj.FindMember("XboxToken");
    if (XboxToken_member != obj.MemberEnd() && !XboxToken_member->value.IsNull()) XboxToken = XboxToken_member->value.GetString();

    return true;
}

GetFriendsListRequest::~GetFriendsListRequest()
{
    if (ProfileConstraints != NULL) delete ProfileConstraints;

}

void GetFriendsListRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (IncludeFacebookFriends.notNull()) { writer.String("IncludeFacebookFriends"); writer.Bool(IncludeFacebookFriends); }
    if (IncludeSteamFriends.notNull()) { writer.String("IncludeSteamFriends"); writer.Bool(IncludeSteamFriends); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (ProfileConstraints != NULL) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
    if (XboxToken.length() > 0) { writer.String("XboxToken"); writer.String(XboxToken.c_str()); }
    writer.EndObject();
}

bool GetFriendsListRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
    if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
    const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
    if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
    if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
    const Value::ConstMemberIterator XboxToken_member = obj.FindMember("XboxToken");
    if (XboxToken_member != obj.MemberEnd() && !XboxToken_member->value.IsNull()) XboxToken = XboxToken_member->value.GetString();

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
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.EndObject();
}

bool GetLeaderboardAroundCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

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
    if (ProfileConstraints != NULL) delete ProfileConstraints;

}

void GetLeaderboardAroundUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (ProfileConstraints != NULL) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
    writer.EndObject();
}

bool GetLeaderboardAroundUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
    if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

    return true;
}

PlayerLeaderboardEntry::~PlayerLeaderboardEntry()
{
    if (Profile != NULL) delete Profile;

}

void PlayerLeaderboardEntry::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.String("Position"); writer.Int(Position);
    if (Profile != NULL) { writer.String("Profile"); Profile->writeJSON(writer); }
    writer.String("StatValue"); writer.Int(StatValue);
    writer.EndObject();
}

bool PlayerLeaderboardEntry::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
    if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();
    const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
    if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new PlayerProfileModel(Profile_member->value);
    const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
    if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();

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
    if (NextReset.notNull()) { writer.String("NextReset"); writeDatetime(NextReset, writer); }
    writer.String("Version"); writer.Int(Version);
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
    const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
    if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

    return true;
}

GetLeaderboardForUsersCharactersRequest::~GetLeaderboardForUsersCharactersRequest()
{

}

void GetLeaderboardForUsersCharactersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.EndObject();
}

bool GetLeaderboardForUsersCharactersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

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
    if (ProfileConstraints != NULL) delete ProfileConstraints;

}

void GetLeaderboardRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
    if (ProfileConstraints != NULL) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
    writer.String("StartPosition"); writer.Int(StartPosition);
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
    writer.EndObject();
}

bool GetLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
    if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
    const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
    if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
    const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
    if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

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
    if (NextReset.notNull()) { writer.String("NextReset"); writeDatetime(NextReset, writer); }
    writer.String("Version"); writer.Int(Version);
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
    const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
    if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();

    return true;
}

GetPlayerCombinedInfoRequestParams::~GetPlayerCombinedInfoRequestParams()
{
    if (ProfileConstraints != NULL) delete ProfileConstraints;

}

void GetPlayerCombinedInfoRequestParams::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("GetCharacterInventories"); writer.Bool(GetCharacterInventories);
    writer.String("GetCharacterList"); writer.Bool(GetCharacterList);
    writer.String("GetPlayerProfile"); writer.Bool(GetPlayerProfile);
    writer.String("GetPlayerStatistics"); writer.Bool(GetPlayerStatistics);
    writer.String("GetTitleData"); writer.Bool(GetTitleData);
    writer.String("GetUserAccountInfo"); writer.Bool(GetUserAccountInfo);
    writer.String("GetUserData"); writer.Bool(GetUserData);
    writer.String("GetUserInventory"); writer.Bool(GetUserInventory);
    writer.String("GetUserReadOnlyData"); writer.Bool(GetUserReadOnlyData);
    writer.String("GetUserVirtualCurrency"); writer.Bool(GetUserVirtualCurrency);
    if (!PlayerStatisticNames.empty()) {
        writer.String("PlayerStatisticNames");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = PlayerStatisticNames.begin(); iter != PlayerStatisticNames.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (ProfileConstraints != NULL) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
    if (!TitleDataKeys.empty()) {
        writer.String("TitleDataKeys");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = TitleDataKeys.begin(); iter != TitleDataKeys.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (!UserDataKeys.empty()) {
        writer.String("UserDataKeys");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = UserDataKeys.begin(); iter != UserDataKeys.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    if (!UserReadOnlyDataKeys.empty()) {
        writer.String("UserReadOnlyDataKeys");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = UserReadOnlyDataKeys.begin(); iter != UserReadOnlyDataKeys.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetPlayerCombinedInfoRequestParams::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GetCharacterInventories_member = obj.FindMember("GetCharacterInventories");
    if (GetCharacterInventories_member != obj.MemberEnd() && !GetCharacterInventories_member->value.IsNull()) GetCharacterInventories = GetCharacterInventories_member->value.GetBool();
    const Value::ConstMemberIterator GetCharacterList_member = obj.FindMember("GetCharacterList");
    if (GetCharacterList_member != obj.MemberEnd() && !GetCharacterList_member->value.IsNull()) GetCharacterList = GetCharacterList_member->value.GetBool();
    const Value::ConstMemberIterator GetPlayerProfile_member = obj.FindMember("GetPlayerProfile");
    if (GetPlayerProfile_member != obj.MemberEnd() && !GetPlayerProfile_member->value.IsNull()) GetPlayerProfile = GetPlayerProfile_member->value.GetBool();
    const Value::ConstMemberIterator GetPlayerStatistics_member = obj.FindMember("GetPlayerStatistics");
    if (GetPlayerStatistics_member != obj.MemberEnd() && !GetPlayerStatistics_member->value.IsNull()) GetPlayerStatistics = GetPlayerStatistics_member->value.GetBool();
    const Value::ConstMemberIterator GetTitleData_member = obj.FindMember("GetTitleData");
    if (GetTitleData_member != obj.MemberEnd() && !GetTitleData_member->value.IsNull()) GetTitleData = GetTitleData_member->value.GetBool();
    const Value::ConstMemberIterator GetUserAccountInfo_member = obj.FindMember("GetUserAccountInfo");
    if (GetUserAccountInfo_member != obj.MemberEnd() && !GetUserAccountInfo_member->value.IsNull()) GetUserAccountInfo = GetUserAccountInfo_member->value.GetBool();
    const Value::ConstMemberIterator GetUserData_member = obj.FindMember("GetUserData");
    if (GetUserData_member != obj.MemberEnd() && !GetUserData_member->value.IsNull()) GetUserData = GetUserData_member->value.GetBool();
    const Value::ConstMemberIterator GetUserInventory_member = obj.FindMember("GetUserInventory");
    if (GetUserInventory_member != obj.MemberEnd() && !GetUserInventory_member->value.IsNull()) GetUserInventory = GetUserInventory_member->value.GetBool();
    const Value::ConstMemberIterator GetUserReadOnlyData_member = obj.FindMember("GetUserReadOnlyData");
    if (GetUserReadOnlyData_member != obj.MemberEnd() && !GetUserReadOnlyData_member->value.IsNull()) GetUserReadOnlyData = GetUserReadOnlyData_member->value.GetBool();
    const Value::ConstMemberIterator GetUserVirtualCurrency_member = obj.FindMember("GetUserVirtualCurrency");
    if (GetUserVirtualCurrency_member != obj.MemberEnd() && !GetUserVirtualCurrency_member->value.IsNull()) GetUserVirtualCurrency = GetUserVirtualCurrency_member->value.GetBool();
    const Value::ConstMemberIterator PlayerStatisticNames_member = obj.FindMember("PlayerStatisticNames");
    if (PlayerStatisticNames_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatisticNames_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatisticNames.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
    if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);
    const Value::ConstMemberIterator TitleDataKeys_member = obj.FindMember("TitleDataKeys");
    if (TitleDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TitleDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TitleDataKeys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator UserDataKeys_member = obj.FindMember("UserDataKeys");
    if (UserDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserDataKeys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator UserReadOnlyDataKeys_member = obj.FindMember("UserReadOnlyDataKeys");
    if (UserReadOnlyDataKeys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserReadOnlyDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserReadOnlyDataKeys.push_back(memberList[i].GetString());
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
    writer.String("InfoRequestParameters"); InfoRequestParameters.writeJSON(writer);
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GetPlayerCombinedInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
    if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    if (PlayerProfile != NULL) delete PlayerProfile;

}

void GetPlayerCombinedInfoResultPayload::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AccountInfo != NULL) { writer.String("AccountInfo"); AccountInfo->writeJSON(writer); }
    if (!CharacterInventories.empty()) {
        writer.String("CharacterInventories");
        writer.StartArray();
        for (std::list<CharacterInventory>::iterator iter = CharacterInventories.begin(); iter != CharacterInventories.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!CharacterList.empty()) {
        writer.String("CharacterList");
        writer.StartArray();
        for (std::list<CharacterResult>::iterator iter = CharacterList.begin(); iter != CharacterList.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (PlayerProfile != NULL) { writer.String("PlayerProfile"); PlayerProfile->writeJSON(writer); }
    if (!PlayerStatistics.empty()) {
        writer.String("PlayerStatistics");
        writer.StartArray();
        for (std::list<StatisticValue>::iterator iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) {
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
    if (!UserData.empty()) {
        writer.String("UserData");
        writer.StartObject();
        for (std::map<std::string, UserDataRecord>::iterator iter = UserData.begin(); iter != UserData.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("UserDataVersion"); writer.Uint(UserDataVersion);
    if (!UserInventory.empty()) {
        writer.String("UserInventory");
        writer.StartArray();
        for (std::list<ItemInstance>::iterator iter = UserInventory.begin(); iter != UserInventory.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!UserReadOnlyData.empty()) {
        writer.String("UserReadOnlyData");
        writer.StartObject();
        for (std::map<std::string, UserDataRecord>::iterator iter = UserReadOnlyData.begin(); iter != UserReadOnlyData.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("UserReadOnlyDataVersion"); writer.Uint(UserReadOnlyDataVersion);
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
    writer.EndObject();
}

bool GetPlayerCombinedInfoResultPayload::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AccountInfo_member = obj.FindMember("AccountInfo");
    if (AccountInfo_member != obj.MemberEnd() && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);
    const Value::ConstMemberIterator CharacterInventories_member = obj.FindMember("CharacterInventories");
    if (CharacterInventories_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = CharacterInventories_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            CharacterInventories.push_back(CharacterInventory(memberList[i]));
        }
    }
    const Value::ConstMemberIterator CharacterList_member = obj.FindMember("CharacterList");
    if (CharacterList_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = CharacterList_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            CharacterList.push_back(CharacterResult(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
    if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = new PlayerProfileModel(PlayerProfile_member->value);
    const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
    if (PlayerStatistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatistics.push_back(StatisticValue(memberList[i]));
        }
    }
    const Value::ConstMemberIterator TitleData_member = obj.FindMember("TitleData");
    if (TitleData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = TitleData_member->value.MemberBegin(); iter != TitleData_member->value.MemberEnd(); ++iter) {
            TitleData[iter->name.GetString()] = iter->value.GetString();
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
    const Value::ConstMemberIterator UserInventory_member = obj.FindMember("UserInventory");
    if (UserInventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = UserInventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserInventory.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::ConstMemberIterator UserReadOnlyData_member = obj.FindMember("UserReadOnlyData");
    if (UserReadOnlyData_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = UserReadOnlyData_member->value.MemberBegin(); iter != UserReadOnlyData_member->value.MemberEnd(); ++iter) {
            UserReadOnlyData[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::ConstMemberIterator UserReadOnlyDataVersion_member = obj.FindMember("UserReadOnlyDataVersion");
    if (UserReadOnlyDataVersion_member != obj.MemberEnd() && !UserReadOnlyDataVersion_member->value.IsNull()) UserReadOnlyDataVersion = UserReadOnlyDataVersion_member->value.GetUint();
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

    return true;
}

GetPlayerCombinedInfoResult::~GetPlayerCombinedInfoResult()
{
    if (InfoResultPayload != NULL) delete InfoResultPayload;

}

void GetPlayerCombinedInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (InfoResultPayload != NULL) { writer.String("InfoResultPayload"); InfoResultPayload->writeJSON(writer); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.EndObject();
}

bool GetPlayerCombinedInfoResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator InfoResultPayload_member = obj.FindMember("InfoResultPayload");
    if (InfoResultPayload_member != obj.MemberEnd() && !InfoResultPayload_member->value.IsNull()) InfoResultPayload = new GetPlayerCombinedInfoResultPayload(InfoResultPayload_member->value);
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetPlayerProfileRequest::~GetPlayerProfileRequest()
{
    if (ProfileConstraints != NULL) delete ProfileConstraints;

}

void GetPlayerProfileRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (ProfileConstraints != NULL) { writer.String("ProfileConstraints"); ProfileConstraints->writeJSON(writer); }
    writer.EndObject();
}

bool GetPlayerProfileRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
    if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

    return true;
}

GetPlayerProfileResult::~GetPlayerProfileResult()
{
    if (PlayerProfile != NULL) delete PlayerProfile;

}

void GetPlayerProfileResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PlayerProfile != NULL) { writer.String("PlayerProfile"); PlayerProfile->writeJSON(writer); }
    writer.EndObject();
}

bool GetPlayerProfileResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
    if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = new PlayerProfileModel(PlayerProfile_member->value);

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
    if (ContinuationToken.length() > 0) { writer.String("ContinuationToken"); writer.String(ContinuationToken.c_str()); }
    if (MaxBatchSize.notNull()) { writer.String("MaxBatchSize"); writer.Uint(MaxBatchSize); }
    if (SecondsToLive.notNull()) { writer.String("SecondsToLive"); writer.Uint(SecondsToLive); }
    writer.String("SegmentId"); writer.String(SegmentId.c_str());
    writer.EndObject();
}

bool GetPlayersInSegmentRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ContinuationToken_member = obj.FindMember("ContinuationToken");
    if (ContinuationToken_member != obj.MemberEnd() && !ContinuationToken_member->value.IsNull()) ContinuationToken = ContinuationToken_member->value.GetString();
    const Value::ConstMemberIterator MaxBatchSize_member = obj.FindMember("MaxBatchSize");
    if (MaxBatchSize_member != obj.MemberEnd() && !MaxBatchSize_member->value.IsNull()) MaxBatchSize = MaxBatchSize_member->value.GetUint();
    const Value::ConstMemberIterator SecondsToLive_member = obj.FindMember("SecondsToLive");
    if (SecondsToLive_member != obj.MemberEnd() && !SecondsToLive_member->value.IsNull()) SecondsToLive = SecondsToLive_member->value.GetUint();
    const Value::ConstMemberIterator SegmentId_member = obj.FindMember("SegmentId");
    if (SegmentId_member != obj.MemberEnd() && !SegmentId_member->value.IsNull()) SegmentId = SegmentId_member->value.GetString();

    return true;
}

PlayerLinkedAccount::~PlayerLinkedAccount()
{

}

void PlayerLinkedAccount::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    if (Platform.notNull()) { writer.String("Platform"); writeLoginIdentityProviderEnumJSON(Platform, writer); }
    if (PlatformUserId.length() > 0) { writer.String("PlatformUserId"); writer.String(PlatformUserId.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    writer.EndObject();
}

bool PlayerLinkedAccount::readFromValue(const rapidjson::Value& obj)
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

PlayerLocation::~PlayerLocation()
{

}

void PlayerLocation::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (City.length() > 0) { writer.String("City"); writer.String(City.c_str()); }
    writer.String("ContinentCode"); writeContinentCodeEnumJSON(pfContinentCode, writer);
    writer.String("CountryCode"); writeCountryCodeEnumJSON(pfCountryCode, writer);
    if (Latitude.notNull()) { writer.String("Latitude"); writer.Double(Latitude); }
    if (Longitude.notNull()) { writer.String("Longitude"); writer.Double(Longitude); }
    writer.EndObject();
}

bool PlayerLocation::readFromValue(const rapidjson::Value& obj)
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

PlayerStatistic::~PlayerStatistic()
{

}

void PlayerStatistic::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Id.length() > 0) { writer.String("Id"); writer.String(Id.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    writer.String("StatisticValue"); writer.Int(StatisticValue);
    writer.String("StatisticVersion"); writer.Int(StatisticVersion);
    writer.EndObject();
}

bool PlayerStatistic::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
    if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator StatisticValue_member = obj.FindMember("StatisticValue");
    if (StatisticValue_member != obj.MemberEnd() && !StatisticValue_member->value.IsNull()) StatisticValue = StatisticValue_member->value.GetInt();
    const Value::ConstMemberIterator StatisticVersion_member = obj.FindMember("StatisticVersion");
    if (StatisticVersion_member != obj.MemberEnd() && !StatisticVersion_member->value.IsNull()) StatisticVersion = StatisticVersion_member->value.GetInt();

    return true;
}

PushNotificationRegistration::~PushNotificationRegistration()
{

}

void PushNotificationRegistration::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (NotificationEndpointARN.length() > 0) { writer.String("NotificationEndpointARN"); writer.String(NotificationEndpointARN.c_str()); }
    if (Platform.notNull()) { writer.String("Platform"); writePushNotificationPlatformEnumJSON(Platform, writer); }
    writer.EndObject();
}

bool PushNotificationRegistration::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator NotificationEndpointARN_member = obj.FindMember("NotificationEndpointARN");
    if (NotificationEndpointARN_member != obj.MemberEnd() && !NotificationEndpointARN_member->value.IsNull()) NotificationEndpointARN = NotificationEndpointARN_member->value.GetString();
    const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
    if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushNotificationPlatformFromValue(Platform_member->value);

    return true;
}

PlayerProfile::~PlayerProfile()
{

}

void PlayerProfile::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!AdCampaignAttributions.empty()) {
        writer.String("AdCampaignAttributions");
        writer.StartArray();
        for (std::list<AdCampaignAttribution>::iterator iter = AdCampaignAttributions.begin(); iter != AdCampaignAttributions.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (AvatarUrl.length() > 0) { writer.String("AvatarUrl"); writer.String(AvatarUrl.c_str()); }
    if (BannedUntil.notNull()) { writer.String("BannedUntil"); writeDatetime(BannedUntil, writer); }
    if (!ContactEmailAddresses.empty()) {
        writer.String("ContactEmailAddresses");
        writer.StartArray();
        for (std::list<ContactEmailInfo>::iterator iter = ContactEmailAddresses.begin(); iter != ContactEmailAddresses.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (Created.notNull()) { writer.String("Created"); writeDatetime(Created, writer); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
    if (!LinkedAccounts.empty()) {
        writer.String("LinkedAccounts");
        writer.StartArray();
        for (std::list<PlayerLinkedAccount>::iterator iter = LinkedAccounts.begin(); iter != LinkedAccounts.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Locations.empty()) {
        writer.String("Locations");
        writer.StartObject();
        for (std::map<std::string, PlayerLocation>::iterator iter = Locations.begin(); iter != Locations.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    if (Origination.notNull()) { writer.String("Origination"); writeLoginIdentityProviderEnumJSON(Origination, writer); }
    if (PlayerId.length() > 0) { writer.String("PlayerId"); writer.String(PlayerId.c_str()); }
    if (!PlayerStatistics.empty()) {
        writer.String("PlayerStatistics");
        writer.StartArray();
        for (std::list<PlayerStatistic>::iterator iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (PublisherId.length() > 0) { writer.String("PublisherId"); writer.String(PublisherId.c_str()); }
    if (!PushNotificationRegistrations.empty()) {
        writer.String("PushNotificationRegistrations");
        writer.StartArray();
        for (std::list<PushNotificationRegistration>::iterator iter = PushNotificationRegistrations.begin(); iter != PushNotificationRegistrations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Statistics.empty()) {
        writer.String("Statistics");
        writer.StartObject();
        for (std::map<std::string, Int32>::iterator iter = Statistics.begin(); iter != Statistics.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.Int(iter->second);
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
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    if (TotalValueToDateInUSD.notNull()) { writer.String("TotalValueToDateInUSD"); writer.Uint(TotalValueToDateInUSD); }
    if (!ValuesToDate.empty()) {
        writer.String("ValuesToDate");
        writer.StartObject();
        for (std::map<std::string, Uint32>::iterator iter = ValuesToDate.begin(); iter != ValuesToDate.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.Uint(iter->second);
        }
        writer.EndObject();
    }
    if (!VirtualCurrencyBalances.empty()) {
        writer.String("VirtualCurrencyBalances");
        writer.StartObject();
        for (std::map<std::string, Int32>::iterator iter = VirtualCurrencyBalances.begin(); iter != VirtualCurrencyBalances.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.Int(iter->second);
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool PlayerProfile::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AdCampaignAttributions_member = obj.FindMember("AdCampaignAttributions");
    if (AdCampaignAttributions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AdCampaignAttributions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AdCampaignAttributions.push_back(AdCampaignAttribution(memberList[i]));
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
            ContactEmailAddresses.push_back(ContactEmailInfo(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
    if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
    const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
    if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
    const Value::ConstMemberIterator LinkedAccounts_member = obj.FindMember("LinkedAccounts");
    if (LinkedAccounts_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = LinkedAccounts_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            LinkedAccounts.push_back(PlayerLinkedAccount(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Locations_member = obj.FindMember("Locations");
    if (Locations_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Locations_member->value.MemberBegin(); iter != Locations_member->value.MemberEnd(); ++iter) {
            Locations[iter->name.GetString()] = PlayerLocation(iter->value);
        }
    }
    const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
    if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readLoginIdentityProviderFromValue(Origination_member->value);
    const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
    if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
    const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
    if (PlayerStatistics_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerStatistics_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerStatistics.push_back(PlayerStatistic(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PublisherId_member = obj.FindMember("PublisherId");
    if (PublisherId_member != obj.MemberEnd() && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();
    const Value::ConstMemberIterator PushNotificationRegistrations_member = obj.FindMember("PushNotificationRegistrations");
    if (PushNotificationRegistrations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PushNotificationRegistrations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PushNotificationRegistrations.push_back(PushNotificationRegistration(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
    if (Statistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Statistics_member->value.MemberBegin(); iter != Statistics_member->value.MemberEnd(); ++iter) {
            Statistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::ConstMemberIterator TotalValueToDateInUSD_member = obj.FindMember("TotalValueToDateInUSD");
    if (TotalValueToDateInUSD_member != obj.MemberEnd() && !TotalValueToDateInUSD_member->value.IsNull()) TotalValueToDateInUSD = TotalValueToDateInUSD_member->value.GetUint();
    const Value::ConstMemberIterator ValuesToDate_member = obj.FindMember("ValuesToDate");
    if (ValuesToDate_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = ValuesToDate_member->value.MemberBegin(); iter != ValuesToDate_member->value.MemberEnd(); ++iter) {
            ValuesToDate[iter->name.GetString()] = iter->value.GetUint();
        }
    }
    const Value::ConstMemberIterator VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
    if (VirtualCurrencyBalances_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyBalances_member->value.MemberBegin(); iter != VirtualCurrencyBalances_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyBalances[iter->name.GetString()] = iter->value.GetInt();
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
    if (ContinuationToken.length() > 0) { writer.String("ContinuationToken"); writer.String(ContinuationToken.c_str()); }
    if (!PlayerProfiles.empty()) {
        writer.String("PlayerProfiles");
        writer.StartArray();
        for (std::list<PlayerProfile>::iterator iter = PlayerProfiles.begin(); iter != PlayerProfiles.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.String("ProfilesInSegment"); writer.Int(ProfilesInSegment);
    writer.EndObject();
}

bool GetPlayersInSegmentResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ContinuationToken_member = obj.FindMember("ContinuationToken");
    if (ContinuationToken_member != obj.MemberEnd() && !ContinuationToken_member->value.IsNull()) ContinuationToken = ContinuationToken_member->value.GetString();
    const Value::ConstMemberIterator PlayerProfiles_member = obj.FindMember("PlayerProfiles");
    if (PlayerProfiles_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayerProfiles_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerProfiles.push_back(PlayerProfile(memberList[i]));
        }
    }
    const Value::ConstMemberIterator ProfilesInSegment_member = obj.FindMember("ProfilesInSegment");
    if (ProfilesInSegment_member != obj.MemberEnd() && !ProfilesInSegment_member->value.IsNull()) ProfilesInSegment = ProfilesInSegment_member->value.GetInt();

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
    writer.String("ActivationTime"); writeDatetime(ActivationTime, writer);
    if (DeactivationTime.notNull()) { writer.String("DeactivationTime"); writeDatetime(DeactivationTime, writer); }
    if (ScheduledActivationTime.notNull()) { writer.String("ScheduledActivationTime"); writeDatetime(ScheduledActivationTime, writer); }
    if (ScheduledDeactivationTime.notNull()) { writer.String("ScheduledDeactivationTime"); writeDatetime(ScheduledDeactivationTime, writer); }
    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
    writer.String("Version"); writer.Uint(Version);
    writer.EndObject();
}

bool PlayerStatisticVersion::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ActivationTime_member = obj.FindMember("ActivationTime");
    if (ActivationTime_member != obj.MemberEnd() && !ActivationTime_member->value.IsNull()) ActivationTime = readDatetime(ActivationTime_member->value);
    const Value::ConstMemberIterator DeactivationTime_member = obj.FindMember("DeactivationTime");
    if (DeactivationTime_member != obj.MemberEnd() && !DeactivationTime_member->value.IsNull()) DeactivationTime = readDatetime(DeactivationTime_member->value);
    const Value::ConstMemberIterator ScheduledActivationTime_member = obj.FindMember("ScheduledActivationTime");
    if (ScheduledActivationTime_member != obj.MemberEnd() && !ScheduledActivationTime_member->value.IsNull()) ScheduledActivationTime = readDatetime(ScheduledActivationTime_member->value);
    const Value::ConstMemberIterator ScheduledDeactivationTime_member = obj.FindMember("ScheduledDeactivationTime");
    if (ScheduledDeactivationTime_member != obj.MemberEnd() && !ScheduledDeactivationTime_member->value.IsNull()) ScheduledDeactivationTime = readDatetime(ScheduledDeactivationTime_member->value);
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

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
    if (Namespace.length() > 0) { writer.String("Namespace"); writer.String(Namespace.c_str()); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GetPlayerTagsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Namespace_member = obj.FindMember("Namespace");
    if (Namespace_member != obj.MemberEnd() && !Namespace_member->value.IsNull()) Namespace = Namespace_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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

GetPlayFabIDsFromFacebookInstantGamesIdsRequest::~GetPlayFabIDsFromFacebookInstantGamesIdsRequest()
{

}

void GetPlayFabIDsFromFacebookInstantGamesIdsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("FacebookInstantGamesIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = FacebookInstantGamesIds.begin(); iter != FacebookInstantGamesIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.EndObject();
}

bool GetPlayFabIDsFromFacebookInstantGamesIdsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FacebookInstantGamesIds_member = obj.FindMember("FacebookInstantGamesIds");
    if (FacebookInstantGamesIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = FacebookInstantGamesIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            FacebookInstantGamesIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetPlayFabIDsFromFacebookInstantGamesIdsResult::~GetPlayFabIDsFromFacebookInstantGamesIdsResult()
{

}

void GetPlayFabIDsFromFacebookInstantGamesIdsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Data.empty()) {
        writer.String("Data");
        writer.StartArray();
        for (std::list<FacebookInstantGamesPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetPlayFabIDsFromFacebookInstantGamesIdsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(FacebookInstantGamesPlayFabIdPair(memberList[i]));
        }
    }

    return true;
}

GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest::~GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest()
{

}

void GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("NintendoSwitchDeviceIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = NintendoSwitchDeviceIds.begin(); iter != NintendoSwitchDeviceIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.EndObject();
}

bool GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator NintendoSwitchDeviceIds_member = obj.FindMember("NintendoSwitchDeviceIds");
    if (NintendoSwitchDeviceIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = NintendoSwitchDeviceIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            NintendoSwitchDeviceIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

NintendoSwitchPlayFabIdPair::~NintendoSwitchPlayFabIdPair()
{

}

void NintendoSwitchPlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (NintendoSwitchDeviceId.length() > 0) { writer.String("NintendoSwitchDeviceId"); writer.String(NintendoSwitchDeviceId.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.EndObject();
}

bool NintendoSwitchPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator NintendoSwitchDeviceId_member = obj.FindMember("NintendoSwitchDeviceId");
    if (NintendoSwitchDeviceId_member != obj.MemberEnd() && !NintendoSwitchDeviceId_member->value.IsNull()) NintendoSwitchDeviceId = NintendoSwitchDeviceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetPlayFabIDsFromNintendoSwitchDeviceIdsResult::~GetPlayFabIDsFromNintendoSwitchDeviceIdsResult()
{

}

void GetPlayFabIDsFromNintendoSwitchDeviceIdsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Data.empty()) {
        writer.String("Data");
        writer.StartArray();
        for (std::list<NintendoSwitchPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetPlayFabIDsFromNintendoSwitchDeviceIdsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(NintendoSwitchPlayFabIdPair(memberList[i]));
        }
    }

    return true;
}

GetPlayFabIDsFromPSNAccountIDsRequest::~GetPlayFabIDsFromPSNAccountIDsRequest()
{

}

void GetPlayFabIDsFromPSNAccountIDsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (IssuerId.notNull()) { writer.String("IssuerId"); writer.Int(IssuerId); }
    writer.String("PSNAccountIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PSNAccountIDs.begin(); iter != PSNAccountIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.EndObject();
}

bool GetPlayFabIDsFromPSNAccountIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IssuerId_member = obj.FindMember("IssuerId");
    if (IssuerId_member != obj.MemberEnd() && !IssuerId_member->value.IsNull()) IssuerId = IssuerId_member->value.GetInt();
    const Value::ConstMemberIterator PSNAccountIDs_member = obj.FindMember("PSNAccountIDs");
    if (PSNAccountIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PSNAccountIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PSNAccountIDs.push_back(memberList[i].GetString());
        }
    }

    return true;
}

PSNAccountPlayFabIdPair::~PSNAccountPlayFabIdPair()
{

}

void PSNAccountPlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (PSNAccountId.length() > 0) { writer.String("PSNAccountId"); writer.String(PSNAccountId.c_str()); }
    writer.EndObject();
}

bool PSNAccountPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator PSNAccountId_member = obj.FindMember("PSNAccountId");
    if (PSNAccountId_member != obj.MemberEnd() && !PSNAccountId_member->value.IsNull()) PSNAccountId = PSNAccountId_member->value.GetString();

    return true;
}

GetPlayFabIDsFromPSNAccountIDsResult::~GetPlayFabIDsFromPSNAccountIDsResult()
{

}

void GetPlayFabIDsFromPSNAccountIDsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Data.empty()) {
        writer.String("Data");
        writer.StartArray();
        for (std::list<PSNAccountPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetPlayFabIDsFromPSNAccountIDsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(PSNAccountPlayFabIdPair(memberList[i]));
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
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (SteamStringId.length() > 0) { writer.String("SteamStringId"); writer.String(SteamStringId.c_str()); }
    writer.EndObject();
}

bool SteamPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator SteamStringId_member = obj.FindMember("SteamStringId");
    if (SteamStringId_member != obj.MemberEnd() && !SteamStringId_member->value.IsNull()) SteamStringId = SteamStringId_member->value.GetString();

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

GetPlayFabIDsFromXboxLiveIDsRequest::~GetPlayFabIDsFromXboxLiveIDsRequest()
{

}

void GetPlayFabIDsFromXboxLiveIDsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Sandbox.length() > 0) { writer.String("Sandbox"); writer.String(Sandbox.c_str()); }
    writer.String("XboxLiveAccountIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = XboxLiveAccountIDs.begin(); iter != XboxLiveAccountIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.EndObject();
}

bool GetPlayFabIDsFromXboxLiveIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Sandbox_member = obj.FindMember("Sandbox");
    if (Sandbox_member != obj.MemberEnd() && !Sandbox_member->value.IsNull()) Sandbox = Sandbox_member->value.GetString();
    const Value::ConstMemberIterator XboxLiveAccountIDs_member = obj.FindMember("XboxLiveAccountIDs");
    if (XboxLiveAccountIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = XboxLiveAccountIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            XboxLiveAccountIDs.push_back(memberList[i].GetString());
        }
    }

    return true;
}

XboxLiveAccountPlayFabIdPair::~XboxLiveAccountPlayFabIdPair()
{

}

void XboxLiveAccountPlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (XboxLiveAccountId.length() > 0) { writer.String("XboxLiveAccountId"); writer.String(XboxLiveAccountId.c_str()); }
    writer.EndObject();
}

bool XboxLiveAccountPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator XboxLiveAccountId_member = obj.FindMember("XboxLiveAccountId");
    if (XboxLiveAccountId_member != obj.MemberEnd() && !XboxLiveAccountId_member->value.IsNull()) XboxLiveAccountId = XboxLiveAccountId_member->value.GetString();

    return true;
}

GetPlayFabIDsFromXboxLiveIDsResult::~GetPlayFabIDsFromXboxLiveIDsResult()
{

}

void GetPlayFabIDsFromXboxLiveIDsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Data.empty()) {
        writer.String("Data");
        writer.StartArray();
        for (std::list<XboxLiveAccountPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetPlayFabIDsFromXboxLiveIDsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(XboxLiveAccountPlayFabIdPair(memberList[i]));
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
    writer.String("ResultItem"); writer.String(ResultItem.c_str());
    writer.String("ResultItemType"); writeResultTableNodeTypeEnumJSON(ResultItemType, writer);
    writer.String("Weight"); writer.Int(Weight);
    writer.EndObject();
}

bool ResultTableNode::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ResultItem_member = obj.FindMember("ResultItem");
    if (ResultItem_member != obj.MemberEnd() && !ResultItem_member->value.IsNull()) ResultItem = ResultItem_member->value.GetString();
    const Value::ConstMemberIterator ResultItemType_member = obj.FindMember("ResultItemType");
    if (ResultItemType_member != obj.MemberEnd() && !ResultItemType_member->value.IsNull()) ResultItemType = readResultTableNodeTypeFromValue(ResultItemType_member->value);
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
    writer.String("Nodes");
    writer.StartArray();
    for (std::list<ResultTableNode>::iterator iter = Nodes.begin(); iter != Nodes.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.String("TableId"); writer.String(TableId.c_str());
    writer.EndObject();
}

bool RandomResultTableListing::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator Nodes_member = obj.FindMember("Nodes");
    if (Nodes_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Nodes_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Nodes.push_back(ResultTableNode(memberList[i]));
        }
    }
    const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
    if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();

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

GetServerCustomIDsFromPlayFabIDsRequest::~GetServerCustomIDsFromPlayFabIDsRequest()
{

}

void GetServerCustomIDsFromPlayFabIDsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("PlayFabIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayFabIDs.begin(); iter != PlayFabIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.EndObject();
}

bool GetServerCustomIDsFromPlayFabIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabIDs_member = obj.FindMember("PlayFabIDs");
    if (PlayFabIDs_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIDs.push_back(memberList[i].GetString());
        }
    }

    return true;
}

ServerCustomIDPlayFabIDPair::~ServerCustomIDPlayFabIDPair()
{

}

void ServerCustomIDPlayFabIDPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (ServerCustomId.length() > 0) { writer.String("ServerCustomId"); writer.String(ServerCustomId.c_str()); }
    writer.EndObject();
}

bool ServerCustomIDPlayFabIDPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ServerCustomId_member = obj.FindMember("ServerCustomId");
    if (ServerCustomId_member != obj.MemberEnd() && !ServerCustomId_member->value.IsNull()) ServerCustomId = ServerCustomId_member->value.GetString();

    return true;
}

GetServerCustomIDsFromPlayFabIDsResult::~GetServerCustomIDsFromPlayFabIDsResult()
{

}

void GetServerCustomIDsFromPlayFabIDsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Data.empty()) {
        writer.String("Data");
        writer.StartArray();
        for (std::list<ServerCustomIDPlayFabIDPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetServerCustomIDsFromPlayFabIDsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(ServerCustomIDPlayFabIDPair(memberList[i]));
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
    if (GetMembers.notNull()) { writer.String("GetMembers"); writer.Bool(GetMembers); }
    if (!Keys.empty()) {
        writer.String("Keys");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
    writer.EndObject();
}

bool GetSharedGroupDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GetMembers_member = obj.FindMember("GetMembers");
    if (GetMembers_member != obj.MemberEnd() && !GetMembers_member->value.IsNull()) GetMembers = GetMembers_member->value.GetBool();
    const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

    return true;
}

SharedGroupDataRecord::~SharedGroupDataRecord()
{

}

void SharedGroupDataRecord::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
    if (LastUpdatedBy.length() > 0) { writer.String("LastUpdatedBy"); writer.String(LastUpdatedBy.c_str()); }
    if (Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
    if (Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
    writer.EndObject();
}

bool SharedGroupDataRecord::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
    if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
    const Value::ConstMemberIterator LastUpdatedBy_member = obj.FindMember("LastUpdatedBy");
    if (LastUpdatedBy_member != obj.MemberEnd() && !LastUpdatedBy_member->value.IsNull()) LastUpdatedBy = LastUpdatedBy_member->value.GetString();
    const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
    if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

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
    if (Body.length() > 0) { writer.String("Body"); writer.String(Body.c_str()); }
    if (NewsId.length() > 0) { writer.String("NewsId"); writer.String(NewsId.c_str()); }
    writer.String("Timestamp"); writeDatetime(Timestamp, writer);
    if (Title.length() > 0) { writer.String("Title"); writer.String(Title.c_str()); }
    writer.EndObject();
}

bool TitleNewsItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd() && !Body_member->value.IsNull()) Body = Body_member->value.GetString();
    const Value::ConstMemberIterator NewsId_member = obj.FindMember("NewsId");
    if (NewsId_member != obj.MemberEnd() && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
    if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();

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
    if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Uint(IfChangedFromDataVersion); }
    if (!Keys.empty()) {
        writer.String("Keys");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GetUserDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
    if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();
    const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
    if (Keys_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetUserDataResult::~GetUserDataResult()
{

}

void GetUserDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Data.empty()) {
        writer.String("Data");
        writer.StartObject();
        for (std::map<std::string, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("DataVersion"); writer.Uint(DataVersion);
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.EndObject();
}

bool GetUserDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    if (!Inventory.empty()) {
        writer.String("Inventory");
        writer.StartArray();
        for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
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
    const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
    if (Inventory_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Inventory_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Inventory.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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

GrantCharacterToUserRequest::~GrantCharacterToUserRequest()
{

}

void GrantCharacterToUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("CharacterName"); writer.String(CharacterName.c_str());
    writer.String("CharacterType"); writer.String(CharacterType.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GrantCharacterToUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
    const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
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
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
    if (RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
    writer.String("Result"); writer.Bool(Result);
    if (UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
    writer.String("UnitPrice"); writer.Uint(UnitPrice);
    if (UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
    writer.EndObject();
}

bool GrantedItemInstance::readFromValue(const rapidjson::Value& obj)
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
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
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
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
    if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
    const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
    const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
    if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();
    const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
    if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
    const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
    if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
    const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
    if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();

    return true;
}

GrantItemsToCharacterRequest::~GrantItemsToCharacterRequest()
{

}

void GrantItemsToCharacterRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (!ItemIds.empty()) {
        writer.String("ItemIds");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = ItemIds.begin(); iter != ItemIds.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GrantItemsToCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemIds_member = obj.FindMember("ItemIds");
    if (ItemIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("ItemIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = ItemIds.begin(); iter != ItemIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool GrantItemsToUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator ItemIds_member = obj.FindMember("ItemIds");
    if (ItemIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    writer.String("ItemId"); writer.String(ItemId.c_str());
    if (!KeysToRemove.empty()) {
        writer.String("KeysToRemove");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool ItemGrant::readFromValue(const rapidjson::Value& obj)
{
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
    const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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

LinkXboxAccountRequest::~LinkXboxAccountRequest()
{

}

void LinkXboxAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ForceLink.notNull()) { writer.String("ForceLink"); writer.Bool(ForceLink); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("XboxToken"); writer.String(XboxToken.c_str());
    writer.EndObject();
}

bool LinkXboxAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
    if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator XboxToken_member = obj.FindMember("XboxToken");
    if (XboxToken_member != obj.MemberEnd() && !XboxToken_member->value.IsNull()) XboxToken = XboxToken_member->value.GetString();

    return true;
}

LinkXboxAccountResult::~LinkXboxAccountResult()
{

}

void LinkXboxAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool LinkXboxAccountResult::readFromValue(const rapidjson::Value& obj)
{

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

LoginWithServerCustomIdRequest::~LoginWithServerCustomIdRequest()
{
    if (InfoRequestParameters != NULL) delete InfoRequestParameters;

}

void LoginWithServerCustomIdRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }
    if (InfoRequestParameters != NULL) { writer.String("InfoRequestParameters"); InfoRequestParameters->writeJSON(writer); }
    if (PlayerSecret.length() > 0) { writer.String("PlayerSecret"); writer.String(PlayerSecret.c_str()); }
    if (ServerCustomId.length() > 0) { writer.String("ServerCustomId"); writer.String(ServerCustomId.c_str()); }
    writer.EndObject();
}

bool LoginWithServerCustomIdRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
    const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
    if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
    const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
    if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
    const Value::ConstMemberIterator ServerCustomId_member = obj.FindMember("ServerCustomId");
    if (ServerCustomId_member != obj.MemberEnd() && !ServerCustomId_member->value.IsNull()) ServerCustomId = ServerCustomId_member->value.GetString();

    return true;
}

LoginWithXboxRequest::~LoginWithXboxRequest()
{
    if (InfoRequestParameters != NULL) delete InfoRequestParameters;

}

void LoginWithXboxRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }
    if (InfoRequestParameters != NULL) { writer.String("InfoRequestParameters"); InfoRequestParameters->writeJSON(writer); }
    writer.String("XboxToken"); writer.String(XboxToken.c_str());
    writer.EndObject();
}

bool LoginWithXboxRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
    const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
    if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
    const Value::ConstMemberIterator XboxToken_member = obj.FindMember("XboxToken");
    if (XboxToken_member != obj.MemberEnd() && !XboxToken_member->value.IsNull()) XboxToken = XboxToken_member->value.GetString();

    return true;
}

ModifyCharacterVirtualCurrencyResult::~ModifyCharacterVirtualCurrencyResult()
{

}

void ModifyCharacterVirtualCurrencyResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Balance"); writer.Int(Balance);
    if (VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
    writer.EndObject();
}

bool ModifyCharacterVirtualCurrencyResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
    if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

    return true;
}

ModifyItemUsesRequest::~ModifyItemUsesRequest()
{

}

void ModifyItemUsesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("UsesToAdd"); writer.Int(UsesToAdd);
    writer.EndObject();
}

bool ModifyItemUsesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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
    writer.String("Balance"); writer.Int(Balance);
    writer.String("BalanceChange"); writer.Int(BalanceChange);
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
    writer.EndObject();
}

bool ModifyUserVirtualCurrencyResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
    if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();
    const Value::ConstMemberIterator BalanceChange_member = obj.FindMember("BalanceChange");
    if (BalanceChange_member != obj.MemberEnd() && !BalanceChange_member->value.IsNull()) BalanceChange = BalanceChange_member->value.GetInt();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

    return true;
}

MoveItemToCharacterFromCharacterRequest::~MoveItemToCharacterFromCharacterRequest()
{

}

void MoveItemToCharacterFromCharacterRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("GivingCharacterId"); writer.String(GivingCharacterId.c_str());
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("ReceivingCharacterId"); writer.String(ReceivingCharacterId.c_str());
    writer.EndObject();
}

bool MoveItemToCharacterFromCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GivingCharacterId_member = obj.FindMember("GivingCharacterId");
    if (GivingCharacterId_member != obj.MemberEnd() && !GivingCharacterId_member->value.IsNull()) GivingCharacterId = GivingCharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator ReceivingCharacterId_member = obj.FindMember("ReceivingCharacterId");
    if (ReceivingCharacterId_member != obj.MemberEnd() && !ReceivingCharacterId_member->value.IsNull()) ReceivingCharacterId = ReceivingCharacterId_member->value.GetString();

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
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool MoveItemToCharacterFromUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool MoveItemToUserFromCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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

PushNotificationPackage::~PushNotificationPackage()
{

}

void PushNotificationPackage::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Badge"); writer.Int(Badge);
    if (CustomData.length() > 0) { writer.String("CustomData"); writer.String(CustomData.c_str()); }
    if (Icon.length() > 0) { writer.String("Icon"); writer.String(Icon.c_str()); }
    writer.String("Message"); writer.String(Message.c_str());
    if (Sound.length() > 0) { writer.String("Sound"); writer.String(Sound.c_str()); }
    writer.String("Title"); writer.String(Title.c_str());
    writer.EndObject();
}

bool PushNotificationPackage::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Badge_member = obj.FindMember("Badge");
    if (Badge_member != obj.MemberEnd() && !Badge_member->value.IsNull()) Badge = Badge_member->value.GetInt();
    const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
    if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = CustomData_member->value.GetString();
    const Value::ConstMemberIterator Icon_member = obj.FindMember("Icon");
    if (Icon_member != obj.MemberEnd() && !Icon_member->value.IsNull()) Icon = Icon_member->value.GetString();
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator Sound_member = obj.FindMember("Sound");
    if (Sound_member != obj.MemberEnd() && !Sound_member->value.IsNull()) Sound = Sound_member->value.GetString();
    const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
    if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();

    return true;
}

RedeemCouponRequest::~RedeemCouponRequest()
{

}

void RedeemCouponRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("CouponCode"); writer.String(CouponCode.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool RedeemCouponRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CouponCode_member = obj.FindMember("CouponCode");
    if (CouponCode_member != obj.MemberEnd() && !CouponCode_member->value.IsNull()) CouponCode = CouponCode_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    writer.String("LobbyId"); writer.String(LobbyId.c_str());
    writer.String("Ticket"); writer.String(Ticket.c_str());
    writer.EndObject();
}

bool RedeemMatchmakerTicketRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator Ticket_member = obj.FindMember("Ticket");
    if (Ticket_member != obj.MemberEnd() && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();

    return true;
}

RedeemMatchmakerTicketResult::~RedeemMatchmakerTicketResult()
{
    if (UserInfo != NULL) delete UserInfo;

}

void RedeemMatchmakerTicketResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Error.length() > 0) { writer.String("Error"); writer.String(Error.c_str()); }
    writer.String("TicketIsValid"); writer.Bool(TicketIsValid);
    if (UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
    writer.EndObject();
}

bool RedeemMatchmakerTicketResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
    const Value::ConstMemberIterator TicketIsValid_member = obj.FindMember("TicketIsValid");
    if (TicketIsValid_member != obj.MemberEnd() && !TicketIsValid_member->value.IsNull()) TicketIsValid = TicketIsValid_member->value.GetBool();
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
    writer.String("Build"); writer.String(Build.c_str());
    writer.String("GameMode"); writer.String(GameMode.c_str());
    if (LobbyId.length() > 0) { writer.String("LobbyId"); writer.String(LobbyId.c_str()); }
    writer.String("Region"); writeRegionEnumJSON(pfRegion, writer);
    if (ServerIPV4Address.length() > 0) { writer.String("ServerIPV4Address"); writer.String(ServerIPV4Address.c_str()); }
    if (ServerIPV6Address.length() > 0) { writer.String("ServerIPV6Address"); writer.String(ServerIPV6Address.c_str()); }
    writer.String("ServerPort"); writer.String(ServerPort.c_str());
    if (ServerPublicDNSName.length() > 0) { writer.String("ServerPublicDNSName"); writer.String(ServerPublicDNSName.c_str()); }
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
    const Value::ConstMemberIterator Build_member = obj.FindMember("Build");
    if (Build_member != obj.MemberEnd() && !Build_member->value.IsNull()) Build = Build_member->value.GetString();
    const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
    if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator ServerIPV4Address_member = obj.FindMember("ServerIPV4Address");
    if (ServerIPV4Address_member != obj.MemberEnd() && !ServerIPV4Address_member->value.IsNull()) ServerIPV4Address = ServerIPV4Address_member->value.GetString();
    const Value::ConstMemberIterator ServerIPV6Address_member = obj.FindMember("ServerIPV6Address");
    if (ServerIPV6Address_member != obj.MemberEnd() && !ServerIPV6Address_member->value.IsNull()) ServerIPV6Address = ServerIPV6Address_member->value.GetString();
    const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
    if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetString();
    const Value::ConstMemberIterator ServerPublicDNSName_member = obj.FindMember("ServerPublicDNSName");
    if (ServerPublicDNSName_member != obj.MemberEnd() && !ServerPublicDNSName_member->value.IsNull()) ServerPublicDNSName = ServerPublicDNSName_member->value.GetString();
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
    writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
    writer.EndObject();
}

bool RemoveSharedGroupMembersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
    if (PlayFabIds_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PlayFabIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayFabIds.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

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
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    writer.String("ReporteeId"); writer.String(ReporteeId.c_str());
    writer.String("ReporterId"); writer.String(ReporterId.c_str());
    writer.EndObject();
}

bool ReportPlayerServerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
    if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    const Value::ConstMemberIterator ReporteeId_member = obj.FindMember("ReporteeId");
    if (ReporteeId_member != obj.MemberEnd() && !ReporteeId_member->value.IsNull()) ReporteeId = ReporteeId_member->value.GetString();
    const Value::ConstMemberIterator ReporterId_member = obj.FindMember("ReporterId");
    if (ReporterId_member != obj.MemberEnd() && !ReporterId_member->value.IsNull()) ReporterId = ReporterId_member->value.GetString();

    return true;
}

ReportPlayerServerResult::~ReportPlayerServerResult()
{

}

void ReportPlayerServerResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("SubmissionsRemaining"); writer.Int(SubmissionsRemaining);
    writer.EndObject();
}

bool ReportPlayerServerResult::readFromValue(const rapidjson::Value& obj)
{
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

RevokeInventoryItem::~RevokeInventoryItem()
{

}

void RevokeInventoryItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool RevokeInventoryItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

RevokeInventoryItemRequest::~RevokeInventoryItemRequest()
{

}

void RevokeInventoryItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool RevokeInventoryItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

RevokeInventoryItemsRequest::~RevokeInventoryItemsRequest()
{

}

void RevokeInventoryItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Items");
    writer.StartArray();
    for (std::list<RevokeInventoryItem>::iterator iter = Items.begin(); iter != Items.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.EndObject();
}

bool RevokeInventoryItemsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Items_member = obj.FindMember("Items");
    if (Items_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Items_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Items.push_back(RevokeInventoryItem(memberList[i]));
        }
    }

    return true;
}

RevokeItemError::~RevokeItemError()
{
    if (Item != NULL) delete Item;

}

void RevokeItemError::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Error.notNull()) { writer.String("Error"); writeGenericErrorCodesEnumJSON(Error, writer); }
    if (Item != NULL) { writer.String("Item"); Item->writeJSON(writer); }
    writer.EndObject();
}

bool RevokeItemError::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
    if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = readGenericErrorCodesFromValue(Error_member->value);
    const Value::ConstMemberIterator Item_member = obj.FindMember("Item");
    if (Item_member != obj.MemberEnd() && !Item_member->value.IsNull()) Item = new RevokeInventoryItem(Item_member->value);

    return true;
}

RevokeInventoryItemsResult::~RevokeInventoryItemsResult()
{

}

void RevokeInventoryItemsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Errors.empty()) {
        writer.String("Errors");
        writer.StartArray();
        for (std::list<RevokeItemError>::iterator iter = Errors.begin(); iter != Errors.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool RevokeInventoryItemsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Errors_member = obj.FindMember("Errors");
    if (Errors_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Errors_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Errors.push_back(RevokeItemError(memberList[i]));
        }
    }

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

SendCustomAccountRecoveryEmailRequest::~SendCustomAccountRecoveryEmailRequest()
{

}

void SendCustomAccountRecoveryEmailRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    writer.String("EmailTemplateId"); writer.String(EmailTemplateId.c_str());
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    writer.EndObject();
}

bool SendCustomAccountRecoveryEmailRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
    if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::ConstMemberIterator EmailTemplateId_member = obj.FindMember("EmailTemplateId");
    if (EmailTemplateId_member != obj.MemberEnd() && !EmailTemplateId_member->value.IsNull()) EmailTemplateId = EmailTemplateId_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

    return true;
}

SendCustomAccountRecoveryEmailResult::~SendCustomAccountRecoveryEmailResult()
{

}

void SendCustomAccountRecoveryEmailResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool SendCustomAccountRecoveryEmailResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SendEmailFromTemplateRequest::~SendEmailFromTemplateRequest()
{

}

void SendEmailFromTemplateRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("EmailTemplateId"); writer.String(EmailTemplateId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool SendEmailFromTemplateRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator EmailTemplateId_member = obj.FindMember("EmailTemplateId");
    if (EmailTemplateId_member != obj.MemberEnd() && !EmailTemplateId_member->value.IsNull()) EmailTemplateId = EmailTemplateId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

SendEmailFromTemplateResult::~SendEmailFromTemplateResult()
{

}

void SendEmailFromTemplateResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool SendEmailFromTemplateResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

SendPushNotificationRequest::~SendPushNotificationRequest()
{
    if (Package != NULL) delete Package;

}

void SendPushNotificationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!AdvancedPlatformDelivery.empty()) {
        writer.String("AdvancedPlatformDelivery");
        writer.StartArray();
        for (std::list<AdvancedPushPlatformMsg>::iterator iter = AdvancedPlatformDelivery.begin(); iter != AdvancedPlatformDelivery.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (Message.length() > 0) { writer.String("Message"); writer.String(Message.c_str()); }
    if (Package != NULL) { writer.String("Package"); Package->writeJSON(writer); }
    writer.String("Recipient"); writer.String(Recipient.c_str());
    if (Subject.length() > 0) { writer.String("Subject"); writer.String(Subject.c_str()); }
    if (!TargetPlatforms.empty()) {
        writer.String("TargetPlatforms");
        writer.StartArray();
        for (std::list<PushNotificationPlatform>::iterator iter = TargetPlatforms.begin(); iter != TargetPlatforms.end(); iter++) {
            writePushNotificationPlatformEnumJSON(*iter, writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool SendPushNotificationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AdvancedPlatformDelivery_member = obj.FindMember("AdvancedPlatformDelivery");
    if (AdvancedPlatformDelivery_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AdvancedPlatformDelivery_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AdvancedPlatformDelivery.push_back(AdvancedPushPlatformMsg(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
    if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
    const Value::ConstMemberIterator Package_member = obj.FindMember("Package");
    if (Package_member != obj.MemberEnd() && !Package_member->value.IsNull()) Package = new PushNotificationPackage(Package_member->value);
    const Value::ConstMemberIterator Recipient_member = obj.FindMember("Recipient");
    if (Recipient_member != obj.MemberEnd() && !Recipient_member->value.IsNull()) Recipient = Recipient_member->value.GetString();
    const Value::ConstMemberIterator Subject_member = obj.FindMember("Subject");
    if (Subject_member != obj.MemberEnd() && !Subject_member->value.IsNull()) Subject = Subject_member->value.GetString();
    const Value::ConstMemberIterator TargetPlatforms_member = obj.FindMember("TargetPlatforms");
    if (TargetPlatforms_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = TargetPlatforms_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            TargetPlatforms.push_back(readPushNotificationPlatformFromValue(memberList[i]));
        }
    }

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

UserSettings::~UserSettings()
{

}

void UserSettings::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("GatherDeviceInfo"); writer.Bool(GatherDeviceInfo);
    writer.String("GatherFocusInfo"); writer.Bool(GatherFocusInfo);
    writer.String("NeedsAttribution"); writer.Bool(NeedsAttribution);
    writer.EndObject();
}

bool UserSettings::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GatherDeviceInfo_member = obj.FindMember("GatherDeviceInfo");
    if (GatherDeviceInfo_member != obj.MemberEnd() && !GatherDeviceInfo_member->value.IsNull()) GatherDeviceInfo = GatherDeviceInfo_member->value.GetBool();
    const Value::ConstMemberIterator GatherFocusInfo_member = obj.FindMember("GatherFocusInfo");
    if (GatherFocusInfo_member != obj.MemberEnd() && !GatherFocusInfo_member->value.IsNull()) GatherFocusInfo = GatherFocusInfo_member->value.GetBool();
    const Value::ConstMemberIterator NeedsAttribution_member = obj.FindMember("NeedsAttribution");
    if (NeedsAttribution_member != obj.MemberEnd() && !NeedsAttribution_member->value.IsNull()) NeedsAttribution = NeedsAttribution_member->value.GetBool();

    return true;
}

ServerLoginResult::~ServerLoginResult()
{
    if (EntityToken != NULL) delete EntityToken;
    if (InfoResultPayload != NULL) delete InfoResultPayload;
    if (SettingsForUser != NULL) delete SettingsForUser;

}

void ServerLoginResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (EntityToken != NULL) { writer.String("EntityToken"); EntityToken->writeJSON(writer); }
    if (InfoResultPayload != NULL) { writer.String("InfoResultPayload"); InfoResultPayload->writeJSON(writer); }
    if (LastLoginTime.notNull()) { writer.String("LastLoginTime"); writeDatetime(LastLoginTime, writer); }
    writer.String("NewlyCreated"); writer.Bool(NewlyCreated);
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (SessionTicket.length() > 0) { writer.String("SessionTicket"); writer.String(SessionTicket.c_str()); }
    if (SettingsForUser != NULL) { writer.String("SettingsForUser"); SettingsForUser->writeJSON(writer); }
    writer.EndObject();
}

bool ServerLoginResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator EntityToken_member = obj.FindMember("EntityToken");
    if (EntityToken_member != obj.MemberEnd() && !EntityToken_member->value.IsNull()) EntityToken = new EntityTokenResponse(EntityToken_member->value);
    const Value::ConstMemberIterator InfoResultPayload_member = obj.FindMember("InfoResultPayload");
    if (InfoResultPayload_member != obj.MemberEnd() && !InfoResultPayload_member->value.IsNull()) InfoResultPayload = new GetPlayerCombinedInfoResultPayload(InfoResultPayload_member->value);
    const Value::ConstMemberIterator LastLoginTime_member = obj.FindMember("LastLoginTime");
    if (LastLoginTime_member != obj.MemberEnd() && !LastLoginTime_member->value.IsNull()) LastLoginTime = readDatetime(LastLoginTime_member->value);
    const Value::ConstMemberIterator NewlyCreated_member = obj.FindMember("NewlyCreated");
    if (NewlyCreated_member != obj.MemberEnd() && !NewlyCreated_member->value.IsNull()) NewlyCreated = NewlyCreated_member->value.GetBool();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator SessionTicket_member = obj.FindMember("SessionTicket");
    if (SessionTicket_member != obj.MemberEnd() && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();
    const Value::ConstMemberIterator SettingsForUser_member = obj.FindMember("SettingsForUser");
    if (SettingsForUser_member != obj.MemberEnd() && !SettingsForUser_member->value.IsNull()) SettingsForUser = new UserSettings(SettingsForUser_member->value);

    return true;
}

SetFriendTagsRequest::~SetFriendTagsRequest()
{

}

void SetFriendTagsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("Tags");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    writer.EndObject();
}

bool SetFriendTagsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
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

SetGameServerInstanceDataRequest::~SetGameServerInstanceDataRequest()
{

}

void SetGameServerInstanceDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("GameServerData"); writer.String(GameServerData.c_str());
    writer.String("LobbyId"); writer.String(LobbyId.c_str());
    writer.EndObject();
}

bool SetGameServerInstanceDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GameServerData_member = obj.FindMember("GameServerData");
    if (GameServerData_member != obj.MemberEnd() && !GameServerData_member->value.IsNull()) GameServerData = GameServerData_member->value.GetString();
    const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

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

SetPlayerSecretRequest::~SetPlayerSecretRequest()
{

}

void SetPlayerSecretRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("PlayerSecret"); writer.String(PlayerSecret.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool SetPlayerSecretRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
    if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

SetPlayerSecretResult::~SetPlayerSecretResult()
{

}

void SetPlayerSecretResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool SetPlayerSecretResult::readFromValue(const rapidjson::Value& obj)
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
    writer.String("Value"); writer.Int(Value);
    if (Version.notNull()) { writer.String("Version"); writer.Uint(Version); }
    writer.EndObject();
}

bool StatisticUpdate::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
    if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
    const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
    if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

    return true;
}

SubtractCharacterVirtualCurrencyRequest::~SubtractCharacterVirtualCurrencyRequest()
{

}

void SubtractCharacterVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Amount"); writer.Int(Amount);
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.EndObject();
}

bool SubtractCharacterVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
    if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

    return true;
}

SubtractUserVirtualCurrencyRequest::~SubtractUserVirtualCurrencyRequest()
{

}

void SubtractUserVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Amount"); writer.Int(Amount);
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.EndObject();
}

bool SubtractUserVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
    if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();

    return true;
}

UnlinkXboxAccountRequest::~UnlinkXboxAccountRequest()
{

}

void UnlinkXboxAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.String("XboxToken"); writer.String(XboxToken.c_str());
    writer.EndObject();
}

bool UnlinkXboxAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator XboxToken_member = obj.FindMember("XboxToken");
    if (XboxToken_member != obj.MemberEnd() && !XboxToken_member->value.IsNull()) XboxToken = XboxToken_member->value.GetString();

    return true;
}

UnlinkXboxAccountResult::~UnlinkXboxAccountResult()
{

}

void UnlinkXboxAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool UnlinkXboxAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlockContainerInstanceRequest::~UnlockContainerInstanceRequest()
{

}

void UnlockContainerInstanceRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ContainerItemInstanceId"); writer.String(ContainerItemInstanceId.c_str());
    if (KeyItemInstanceId.length() > 0) { writer.String("KeyItemInstanceId"); writer.String(KeyItemInstanceId.c_str()); }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UnlockContainerInstanceRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ContainerItemInstanceId_member = obj.FindMember("ContainerItemInstanceId");
    if (ContainerItemInstanceId_member != obj.MemberEnd() && !ContainerItemInstanceId_member->value.IsNull()) ContainerItemInstanceId = ContainerItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator KeyItemInstanceId_member = obj.FindMember("KeyItemInstanceId");
    if (KeyItemInstanceId_member != obj.MemberEnd() && !KeyItemInstanceId_member->value.IsNull()) KeyItemInstanceId = KeyItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

UnlockContainerItemRequest::~UnlockContainerItemRequest()
{

}

void UnlockContainerItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    writer.String("ContainerItemId"); writer.String(ContainerItemId.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UnlockContainerItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator ContainerItemId_member = obj.FindMember("ContainerItemId");
    if (ContainerItemId_member != obj.MemberEnd() && !ContainerItemId_member->value.IsNull()) ContainerItemId = ContainerItemId_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

UnlockContainerItemResult::~UnlockContainerItemResult()
{

}

void UnlockContainerItemResult::writeJSON(PFStringJsonWriter& writer)
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
    if (UnlockedItemInstanceId.length() > 0) { writer.String("UnlockedItemInstanceId"); writer.String(UnlockedItemInstanceId.c_str()); }
    if (UnlockedWithItemInstanceId.length() > 0) { writer.String("UnlockedWithItemInstanceId"); writer.String(UnlockedWithItemInstanceId.c_str()); }
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
    const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
    if (GrantedItems_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GrantedItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GrantedItems.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::ConstMemberIterator UnlockedItemInstanceId_member = obj.FindMember("UnlockedItemInstanceId");
    if (UnlockedItemInstanceId_member != obj.MemberEnd() && !UnlockedItemInstanceId_member->value.IsNull()) UnlockedItemInstanceId = UnlockedItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator UnlockedWithItemInstanceId_member = obj.FindMember("UnlockedWithItemInstanceId");
    if (UnlockedWithItemInstanceId_member != obj.MemberEnd() && !UnlockedWithItemInstanceId_member->value.IsNull()) UnlockedWithItemInstanceId = UnlockedWithItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetUint();
        }
    }

    return true;
}

UpdateAvatarUrlRequest::~UpdateAvatarUrlRequest()
{

}

void UpdateAvatarUrlRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ImageUrl"); writer.String(ImageUrl.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UpdateAvatarUrlRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ImageUrl_member = obj.FindMember("ImageUrl");
    if (ImageUrl_member != obj.MemberEnd() && !ImageUrl_member->value.IsNull()) ImageUrl = ImageUrl_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

UpdateBanRequest::~UpdateBanRequest()
{

}

void UpdateBanRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Active.notNull()) { writer.String("Active"); writer.Bool(Active); }
    writer.String("BanId"); writer.String(BanId.c_str());
    if (Expires.notNull()) { writer.String("Expires"); writeDatetime(Expires, writer); }
    if (IPAddress.length() > 0) { writer.String("IPAddress"); writer.String(IPAddress.c_str()); }
    if (MACAddress.length() > 0) { writer.String("MACAddress"); writer.String(MACAddress.c_str()); }
    if (Permanent.notNull()) { writer.String("Permanent"); writer.Bool(Permanent); }
    if (Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
    writer.EndObject();
}

bool UpdateBanRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
    if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();
    const Value::ConstMemberIterator BanId_member = obj.FindMember("BanId");
    if (BanId_member != obj.MemberEnd() && !BanId_member->value.IsNull()) BanId = BanId_member->value.GetString();
    const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
    if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
    const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
    if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
    const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
    if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
    const Value::ConstMemberIterator Permanent_member = obj.FindMember("Permanent");
    if (Permanent_member != obj.MemberEnd() && !Permanent_member->value.IsNull()) Permanent = Permanent_member->value.GetBool();
    const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
    if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();

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
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UpdateCharacterDataRequest::readFromValue(const rapidjson::Value& obj)
{
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
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (!CharacterStatistics.empty()) {
        writer.String("CharacterStatistics");
        writer.StartObject();
        for (std::map<std::string, Int32>::iterator iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.Int(iter->second);
        }
        writer.EndObject();
    }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UpdateCharacterStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
    if (CharacterStatistics_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
            CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    if (ForceUpdate.notNull()) { writer.String("ForceUpdate"); writer.Bool(ForceUpdate); }
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
    const Value::ConstMemberIterator ForceUpdate_member = obj.FindMember("ForceUpdate");
    if (ForceUpdate_member != obj.MemberEnd() && !ForceUpdate_member->value.IsNull()) ForceUpdate = ForceUpdate_member->value.GetBool();
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
    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
    writer.EndObject();
}

bool UpdateSharedGroupDataRequest::readFromValue(const rapidjson::Value& obj)
{
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
    const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
    if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

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
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UpdateUserDataRequest::readFromValue(const rapidjson::Value& obj)
{
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
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UpdateUserInternalDataRequest::readFromValue(const rapidjson::Value& obj)
{
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
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

UpdateUserInventoryItemDataRequest::~UpdateUserInventoryItemDataRequest()
{

}

void UpdateUserInventoryItemDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (!Data.empty()) {
        writer.String("Data");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    if (!KeysToRemove.empty()) {
        writer.String("KeysToRemove");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    writer.EndObject();
}

bool UpdateUserInventoryItemDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
    if (Data_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
    if (KeysToRemove_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = KeysToRemove_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            KeysToRemove.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    if (!Body.empty()) {
        writer.String("Body");
        writer.StartObject();
        for (std::map<std::string, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    writer.String("EventName"); writer.String(EventName.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    writer.EndObject();
}

bool WriteServerCharacterEventRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }
    const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
    if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);

    return true;
}

WriteServerPlayerEventRequest::~WriteServerPlayerEventRequest()
{

}

void WriteServerPlayerEventRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Body.empty()) {
        writer.String("Body");
        writer.StartObject();
        for (std::map<std::string, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("EventName"); writer.String(EventName.c_str());
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    writer.EndObject();
}

bool WriteServerPlayerEventRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }
    const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
    if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);

    return true;
}

WriteTitleEventRequest::~WriteTitleEventRequest()
{

}

void WriteTitleEventRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Body.empty()) {
        writer.String("Body");
        writer.StartObject();
        for (std::map<std::string, MultitypeVar>::iterator iter = Body.begin(); iter != Body.end(); ++iter) {
            writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
        }
        writer.EndObject();
    }
    writer.String("EventName"); writer.String(EventName.c_str());
    if (Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
    writer.EndObject();
}

bool WriteTitleEventRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
    if (Body_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
            Body[iter->name.GetString()] = MultitypeVar(iter->value);
        }
    }
    const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
    if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
    const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
    if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);

    return true;
}

