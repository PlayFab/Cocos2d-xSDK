
#include "playfab/PlayFabServerDataModels.h"

using namespace PlayFab;
using namespace PlayFab::ServerModels;
using namespace rapidjson;



AddSharedGroupMembersRequest::~AddSharedGroupMembersRequest()
{
	
}

void AddSharedGroupMembersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
	
	if(!PlayFabIds.empty()) {
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
	if (SharedGroupId_member != NULL) SharedGroupId = SharedGroupId_member->value.GetString();
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
	if (VirtualCurrency_member != NULL) VirtualCurrency = VirtualCurrency_member->value.GetString();
	
	const Value::Member* Amount_member = obj.FindMember("Amount");
	if (Amount_member != NULL) Amount = Amount_member->value.GetInt();
	
	
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
	if (SessionTicket_member != NULL) SessionTicket = SessionTicket_member->value.GetString();
	
	
	return true;
}


void PlayFab::ServerModels::writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
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
	}
}

UserOrigination PlayFab::ServerModels::readUserOriginationFromValue(const rapidjson::Value& obj)
{
	std::string enumStr = obj.GetString();
	if(enumStr == "Organic")
		return UserOriginationOrganic;
	else if(enumStr == "Steam")
		return UserOriginationSteam;
	else if(enumStr == "Google")
		return UserOriginationGoogle;
	else if(enumStr == "Amazon")
		return UserOriginationAmazon;
	else if(enumStr == "Facebook")
		return UserOriginationFacebook;
	else if(enumStr == "Kongregate")
		return UserOriginationKongregate;
	else if(enumStr == "GamersFirst")
		return UserOriginationGamersFirst;
	else if(enumStr == "Unknown")
		return UserOriginationUnknown;
	else if(enumStr == "IOS")
		return UserOriginationIOS;
	else if(enumStr == "LoadTest")
		return UserOriginationLoadTest;
	else if(enumStr == "Android")
		return UserOriginationAndroid;
	else if(enumStr == "PSN")
		return UserOriginationPSN;
	else if(enumStr == "GameCenter")
		return UserOriginationGameCenter;
	
	return UserOriginationOrganic;
}


UserTitleInfo::~UserTitleInfo()
{
	
}

void UserTitleInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
	
	if(Origination.notNull()) { writer.String("Origination"); writeUserOriginationEnumJSON(Origination, writer); }
	
	writer.String("Created"); writeDatetime(Created, writer);
	
	if(LastLogin.notNull()) { writer.String("LastLogin"); writeDatetime(LastLogin, writer); }
	
	if(FirstLogin.notNull()) { writer.String("FirstLogin"); writeDatetime(FirstLogin, writer); }
	
	if(isBanned.notNull()) { writer.String("isBanned"); writer.Bool(isBanned); }
	
	
	writer.EndObject();
}

bool UserTitleInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
	if (DisplayName_member != NULL) DisplayName = DisplayName_member->value.GetString();
	
	const Value::Member* Origination_member = obj.FindMember("Origination");
	if (Origination_member != NULL) Origination = readUserOriginationFromValue(Origination_member->value);
	
	const Value::Member* Created_member = obj.FindMember("Created");
	if (Created_member != NULL) Created = readDatetime(Created_member->value);
	
	const Value::Member* LastLogin_member = obj.FindMember("LastLogin");
	if (LastLogin_member != NULL) LastLogin = readDatetime(LastLogin_member->value);
	
	const Value::Member* FirstLogin_member = obj.FindMember("FirstLogin");
	if (FirstLogin_member != NULL) FirstLogin = readDatetime(FirstLogin_member->value);
	
	const Value::Member* isBanned_member = obj.FindMember("isBanned");
	if (isBanned_member != NULL) isBanned = isBanned_member->value.GetBool();
	
	
	return true;
}


UserPrivateAccountInfo::~UserPrivateAccountInfo()
{
	
}

void UserPrivateAccountInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
	
	
	writer.EndObject();
}

bool UserPrivateAccountInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Email_member = obj.FindMember("Email");
	if (Email_member != NULL) Email = Email_member->value.GetString();
	
	
	return true;
}


UserFacebookInfo::~UserFacebookInfo()
{
	
}

void UserFacebookInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(FacebookId.length() > 0) { writer.String("FacebookId"); writer.String(FacebookId.c_str()); }
	
	
	writer.EndObject();
}

bool UserFacebookInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* FacebookId_member = obj.FindMember("FacebookId");
	if (FacebookId_member != NULL) FacebookId = FacebookId_member->value.GetString();
	
	
	return true;
}


void PlayFab::ServerModels::writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
	{
		
		case CurrencyUSD: writer.String("USD"); break;
		case CurrencyGBP: writer.String("GBP"); break;
		case CurrencyEUR: writer.String("EUR"); break;
		case CurrencyRUB: writer.String("RUB"); break;
		case CurrencyBRL: writer.String("BRL"); break;
		case CurrencyCIS: writer.String("CIS"); break;
		case CurrencyCAD: writer.String("CAD"); break;
	}
}

Currency PlayFab::ServerModels::readCurrencyFromValue(const rapidjson::Value& obj)
{
	std::string enumStr = obj.GetString();
	if(enumStr == "USD")
		return CurrencyUSD;
	else if(enumStr == "GBP")
		return CurrencyGBP;
	else if(enumStr == "EUR")
		return CurrencyEUR;
	else if(enumStr == "RUB")
		return CurrencyRUB;
	else if(enumStr == "BRL")
		return CurrencyBRL;
	else if(enumStr == "CIS")
		return CurrencyCIS;
	else if(enumStr == "CAD")
		return CurrencyCAD;
	
	return CurrencyUSD;
}


void PlayFab::ServerModels::writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
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
	std::string enumStr = obj.GetString();
	if(enumStr == "None")
		return TitleActivationStatusNone;
	else if(enumStr == "ActivatedTitleKey")
		return TitleActivationStatusActivatedTitleKey;
	else if(enumStr == "PendingSteam")
		return TitleActivationStatusPendingSteam;
	else if(enumStr == "ActivatedSteam")
		return TitleActivationStatusActivatedSteam;
	else if(enumStr == "RevokedSteam")
		return TitleActivationStatusRevokedSteam;
	
	return TitleActivationStatusNone;
}


UserSteamInfo::~UserSteamInfo()
{
	
}

void UserSteamInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
	
	if(SteamCountry.length() > 0) { writer.String("SteamCountry"); writer.String(SteamCountry.c_str()); }
	
	if(SteamCurrency.notNull()) { writer.String("SteamCurrency"); writeCurrencyEnumJSON(SteamCurrency, writer); }
	
	if(SteamActivationStatus.notNull()) { writer.String("SteamActivationStatus"); writeTitleActivationStatusEnumJSON(SteamActivationStatus, writer); }
	
	
	writer.EndObject();
}

bool UserSteamInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* SteamId_member = obj.FindMember("SteamId");
	if (SteamId_member != NULL) SteamId = SteamId_member->value.GetString();
	
	const Value::Member* SteamCountry_member = obj.FindMember("SteamCountry");
	if (SteamCountry_member != NULL) SteamCountry = SteamCountry_member->value.GetString();
	
	const Value::Member* SteamCurrency_member = obj.FindMember("SteamCurrency");
	if (SteamCurrency_member != NULL) SteamCurrency = readCurrencyFromValue(SteamCurrency_member->value);
	
	const Value::Member* SteamActivationStatus_member = obj.FindMember("SteamActivationStatus");
	if (SteamActivationStatus_member != NULL) SteamActivationStatus = readTitleActivationStatusFromValue(SteamActivationStatus_member->value);
	
	
	return true;
}


UserGameCenterInfo::~UserGameCenterInfo()
{
	
}

void UserGameCenterInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(GameCenterId.length() > 0) { writer.String("GameCenterId"); writer.String(GameCenterId.c_str()); }
	
	
	writer.EndObject();
}

bool UserGameCenterInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* GameCenterId_member = obj.FindMember("GameCenterId");
	if (GameCenterId_member != NULL) GameCenterId = GameCenterId_member->value.GetString();
	
	
	return true;
}


UserAccountInfo::~UserAccountInfo()
{
	if(TitleInfo != NULL) delete TitleInfo;
	if(PrivateInfo != NULL) delete PrivateInfo;
	if(FacebookInfo != NULL) delete FacebookInfo;
	if(SteamInfo != NULL) delete SteamInfo;
	if(GameCenterInfo != NULL) delete GameCenterInfo;
	
}

void UserAccountInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	writer.String("Created"); writeDatetime(Created, writer);
	
	if(Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
	
	if(TitleInfo != NULL) { writer.String("TitleInfo"); TitleInfo->writeJSON(writer); }
	
	if(PrivateInfo != NULL) { writer.String("PrivateInfo"); PrivateInfo->writeJSON(writer); }
	
	if(FacebookInfo != NULL) { writer.String("FacebookInfo"); FacebookInfo->writeJSON(writer); }
	
	if(SteamInfo != NULL) { writer.String("SteamInfo"); SteamInfo->writeJSON(writer); }
	
	if(GameCenterInfo != NULL) { writer.String("GameCenterInfo"); GameCenterInfo->writeJSON(writer); }
	
	
	writer.EndObject();
}

bool UserAccountInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* Created_member = obj.FindMember("Created");
	if (Created_member != NULL) Created = readDatetime(Created_member->value);
	
	const Value::Member* Username_member = obj.FindMember("Username");
	if (Username_member != NULL) Username = Username_member->value.GetString();
	
	const Value::Member* TitleInfo_member = obj.FindMember("TitleInfo");
	if (TitleInfo_member != NULL) TitleInfo = new UserTitleInfo(TitleInfo_member->value);
	
	const Value::Member* PrivateInfo_member = obj.FindMember("PrivateInfo");
	if (PrivateInfo_member != NULL) PrivateInfo = new UserPrivateAccountInfo(PrivateInfo_member->value);
	
	const Value::Member* FacebookInfo_member = obj.FindMember("FacebookInfo");
	if (FacebookInfo_member != NULL) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
	
	const Value::Member* SteamInfo_member = obj.FindMember("SteamInfo");
	if (SteamInfo_member != NULL) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
	
	const Value::Member* GameCenterInfo_member = obj.FindMember("GameCenterInfo");
	if (GameCenterInfo_member != NULL) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
	
	
	return true;
}


AuthenticateSessionTicketResult::~AuthenticateSessionTicketResult()
{
	if(UserInfo != NULL) delete UserInfo;
	
}

void AuthenticateSessionTicketResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
	
	
	writer.EndObject();
}

bool AuthenticateSessionTicketResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* UserInfo_member = obj.FindMember("UserInfo");
	if (UserInfo_member != NULL) UserInfo = new UserAccountInfo(UserInfo_member->value);
	
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* AchievementName_member = obj.FindMember("AchievementName");
	if (AchievementName_member != NULL) AchievementName = AchievementName_member->value.GetString();
	
	const Value::Member* Result_member = obj.FindMember("Result");
	if (Result_member != NULL) Result = Result_member->value.GetBool();
	
	
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

	
	if(!AchievementResults.empty()) {
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

	
	if(UsageCount.notNull()) { writer.String("UsageCount"); writer.Uint(UsageCount); }
	
	if(UsagePeriod.notNull()) { writer.String("UsagePeriod"); writer.Uint(UsagePeriod); }
	
	if(UsagePeriodGroup.length() > 0) { writer.String("UsagePeriodGroup"); writer.String(UsagePeriodGroup.c_str()); }
	
	
	writer.EndObject();
}

bool CatalogItemConsumableInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* UsageCount_member = obj.FindMember("UsageCount");
	if (UsageCount_member != NULL) UsageCount = UsageCount_member->value.GetUint();
	
	const Value::Member* UsagePeriod_member = obj.FindMember("UsagePeriod");
	if (UsagePeriod_member != NULL) UsagePeriod = UsagePeriod_member->value.GetUint();
	
	const Value::Member* UsagePeriodGroup_member = obj.FindMember("UsagePeriodGroup");
	if (UsagePeriodGroup_member != NULL) UsagePeriodGroup = UsagePeriodGroup_member->value.GetString();
	
	
	return true;
}


CatalogItemContainerInfo::~CatalogItemContainerInfo()
{
	
}

void CatalogItemContainerInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(KeyItemId.length() > 0) { writer.String("KeyItemId"); writer.String(KeyItemId.c_str()); }
	
	if(!ItemContents.empty()) {
	writer.String("ItemContents");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = ItemContents.begin(); iter != ItemContents.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(!ResultTableContents.empty()) {
	writer.String("ResultTableContents");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = ResultTableContents.begin(); iter != ResultTableContents.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(!VirtualCurrencyContents.empty()) {
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
	if (KeyItemId_member != NULL) KeyItemId = KeyItemId_member->value.GetString();
	
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

	
	if(!BundledItems.empty()) {
	writer.String("BundledItems");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = BundledItems.begin(); iter != BundledItems.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(!BundledResultTables.empty()) {
	writer.String("BundledResultTables");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = BundledResultTables.begin(); iter != BundledResultTables.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(!BundledVirtualCurrencies.empty()) {
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
	if(Consumable != NULL) delete Consumable;
	if(Container != NULL) delete Container;
	if(Bundle != NULL) delete Bundle;
	
}

void CatalogItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("ItemId"); writer.String(ItemId.c_str());
	
	if(ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
	if(DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
	
	if(Description.length() > 0) { writer.String("Description"); writer.String(Description.c_str()); }
	
	if(!VirtualCurrencyPrices.empty()) {
	writer.String("VirtualCurrencyPrices");
	writer.StartObject();
	for (std::map<std::string, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
		writer.String(iter->first.c_str()); writer.Uint(iter->second);
	}
	writer.EndObject();
	}
	
	if(!RealCurrencyPrices.empty()) {
	writer.String("RealCurrencyPrices");
	writer.StartObject();
	for (std::map<std::string, Uint32>::iterator iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
		writer.String(iter->first.c_str()); writer.Uint(iter->second);
	}
	writer.EndObject();
	}
	
	if(!Tags.empty()) {
	writer.String("Tags");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(CustomData.length() > 0) { writer.String("CustomData"); writer.String(CustomData.c_str()); }
	
	if(!GrantedIfPlayerHas.empty()) {
	writer.String("GrantedIfPlayerHas");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = GrantedIfPlayerHas.begin(); iter != GrantedIfPlayerHas.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(Consumable != NULL) { writer.String("Consumable"); Consumable->writeJSON(writer); }
	
	if(Container != NULL) { writer.String("Container"); Container->writeJSON(writer); }
	
	if(Bundle != NULL) { writer.String("Bundle"); Bundle->writeJSON(writer); }
	
	
	writer.EndObject();
}

bool CatalogItem::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* ItemId_member = obj.FindMember("ItemId");
	if (ItemId_member != NULL) ItemId = ItemId_member->value.GetString();
	
	const Value::Member* ItemClass_member = obj.FindMember("ItemClass");
	if (ItemClass_member != NULL) ItemClass = ItemClass_member->value.GetString();
	
	const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
	const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
	if (DisplayName_member != NULL) DisplayName = DisplayName_member->value.GetString();
	
	const Value::Member* Description_member = obj.FindMember("Description");
	if (Description_member != NULL) Description = Description_member->value.GetString();
	
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
	if (CustomData_member != NULL) CustomData = CustomData_member->value.GetString();
	
	const Value::Member* GrantedIfPlayerHas_member = obj.FindMember("GrantedIfPlayerHas");
	if (GrantedIfPlayerHas_member != NULL) {
		const rapidjson::Value& memberList = GrantedIfPlayerHas_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			GrantedIfPlayerHas.push_back(memberList[i].GetString());
		}
	}
	
	const Value::Member* Consumable_member = obj.FindMember("Consumable");
	if (Consumable_member != NULL) Consumable = new CatalogItemConsumableInfo(Consumable_member->value);
	
	const Value::Member* Container_member = obj.FindMember("Container");
	if (Container_member != NULL) Container = new CatalogItemContainerInfo(Container_member->value);
	
	const Value::Member* Bundle_member = obj.FindMember("Bundle");
	if (Bundle_member != NULL) Bundle = new CatalogItemBundleInfo(Bundle_member->value);
	
	
	return true;
}


CharacterLeaderboardEntry::~CharacterLeaderboardEntry()
{
	
}

void CharacterLeaderboardEntry::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	if(CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
	
	if(CharacterName.length() > 0) { writer.String("CharacterName"); writer.String(CharacterName.c_str()); }
	
	if(DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
	
	if(CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
	
	writer.String("StatValue"); writer.Int(StatValue);
	
	writer.String("Position"); writer.Int(Position);
	
	
	writer.EndObject();
}

bool CharacterLeaderboardEntry::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* CharacterName_member = obj.FindMember("CharacterName");
	if (CharacterName_member != NULL) CharacterName = CharacterName_member->value.GetString();
	
	const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
	if (DisplayName_member != NULL) DisplayName = DisplayName_member->value.GetString();
	
	const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
	if (CharacterType_member != NULL) CharacterType = CharacterType_member->value.GetString();
	
	const Value::Member* StatValue_member = obj.FindMember("StatValue");
	if (StatValue_member != NULL) StatValue = StatValue_member->value.GetInt();
	
	const Value::Member* Position_member = obj.FindMember("Position");
	if (Position_member != NULL) Position = Position_member->value.GetInt();
	
	
	return true;
}


CharacterResult::~CharacterResult()
{
	
}

void CharacterResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
	
	if(CharacterName.length() > 0) { writer.String("CharacterName"); writer.String(CharacterName.c_str()); }
	
	if(CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
	
	
	writer.EndObject();
}

bool CharacterResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* CharacterName_member = obj.FindMember("CharacterName");
	if (CharacterName_member != NULL) CharacterName = CharacterName_member->value.GetString();
	
	const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
	if (CharacterType_member != NULL) CharacterType = CharacterType_member->value.GetString();
	
	
	return true;
}


CreateSharedGroupRequest::~CreateSharedGroupRequest()
{
	
}

void CreateSharedGroupRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }
	
	
	writer.EndObject();
}

bool CreateSharedGroupRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
	if (SharedGroupId_member != NULL) SharedGroupId = SharedGroupId_member->value.GetString();
	
	
	return true;
}


CreateSharedGroupResult::~CreateSharedGroupResult()
{
	
}

void CreateSharedGroupResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }
	
	
	writer.EndObject();
}

bool CreateSharedGroupResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
	if (SharedGroupId_member != NULL) SharedGroupId = SharedGroupId_member->value.GetString();
	
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* SaveCharacterInventory_member = obj.FindMember("SaveCharacterInventory");
	if (SaveCharacterInventory_member != NULL) SaveCharacterInventory = SaveCharacterInventory_member->value.GetBool();
	
	
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

	
	if(SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }
	
	
	writer.EndObject();
}

bool DeleteSharedGroupRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
	if (SharedGroupId_member != NULL) SharedGroupId = SharedGroupId_member->value.GetString();
	
	
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


GetCatalogItemsRequest::~GetCatalogItemsRequest()
{
	
}

void GetCatalogItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
	
	writer.EndObject();
}

bool GetCatalogItemsRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
	
	return true;
}


GetCatalogItemsResult::~GetCatalogItemsResult()
{
	
}

void GetCatalogItemsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Catalog.empty()) {
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
	
	if(!Keys.empty()) {
	writer.String("Keys");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	
	writer.EndObject();
}

bool GetCharacterDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* Keys_member = obj.FindMember("Keys");
	if (Keys_member != NULL) {
		const rapidjson::Value& memberList = Keys_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			Keys.push_back(memberList[i].GetString());
		}
	}
	
	
	return true;
}


void PlayFab::ServerModels::writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
	{
		
		case UserDataPermissionPrivate: writer.String("Private"); break;
		case UserDataPermissionPublic: writer.String("Public"); break;
	}
}

UserDataPermission PlayFab::ServerModels::readUserDataPermissionFromValue(const rapidjson::Value& obj)
{
	std::string enumStr = obj.GetString();
	if(enumStr == "Private")
		return UserDataPermissionPrivate;
	else if(enumStr == "Public")
		return UserDataPermissionPublic;
	
	return UserDataPermissionPrivate;
}


UserDataRecord::~UserDataRecord()
{
	
}

void UserDataRecord::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
	
	writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
	
	if(Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
	
	
	writer.EndObject();
}

bool UserDataRecord::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Value_member = obj.FindMember("Value");
	if (Value_member != NULL) Value = Value_member->value.GetString();
	
	const Value::Member* LastUpdated_member = obj.FindMember("LastUpdated");
	if (LastUpdated_member != NULL) LastUpdated = readDatetime(LastUpdated_member->value);
	
	const Value::Member* Permission_member = obj.FindMember("Permission");
	if (Permission_member != NULL) Permission = readUserDataPermissionFromValue(Permission_member->value);
	
	
	return true;
}


GetCharacterDataResult::~GetCharacterDataResult()
{
	
}

void GetCharacterDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
	
	if(!Data.empty()) {
	writer.String("Data");
	writer.StartObject();
	for (std::map<std::string, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
		writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
	}
	writer.EndObject();
	}
	
	
	writer.EndObject();
}

bool GetCharacterDataResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* Data_member = obj.FindMember("Data");
	if (Data_member != NULL) {
		for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
			Data[iter->name.GetString()] = UserDataRecord(iter->value);
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
	
	if(CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
	
	writer.String("StatisticName"); writer.String(StatisticName.c_str());
	
	writer.String("StartPosition"); writer.Int(StartPosition);
	
	writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
	
	
	writer.EndObject();
}

bool GetCharacterLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
	if (CharacterType_member != NULL) CharacterType = CharacterType_member->value.GetString();
	
	const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
	if (StatisticName_member != NULL) StatisticName = StatisticName_member->value.GetString();
	
	const Value::Member* StartPosition_member = obj.FindMember("StartPosition");
	if (StartPosition_member != NULL) StartPosition = StartPosition_member->value.GetInt();
	
	const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
	if (MaxResultsCount_member != NULL) MaxResultsCount = MaxResultsCount_member->value.GetInt();
	
	
	return true;
}


GetCharacterLeaderboardResult::~GetCharacterLeaderboardResult()
{
	
}

void GetCharacterLeaderboardResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Leaderboard.empty()) {
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	
	return true;
}


GetCharacterStatisticsResult::~GetCharacterStatisticsResult()
{
	
}

void GetCharacterStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!CharacterStatistics.empty()) {
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
	
	if(HttpMethod.length() > 0) { writer.String("HttpMethod"); writer.String(HttpMethod.c_str()); }
	
	if(ThruCDN.notNull()) { writer.String("ThruCDN"); writer.Bool(ThruCDN); }
	
	
	writer.EndObject();
}

bool GetContentDownloadUrlRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Key_member = obj.FindMember("Key");
	if (Key_member != NULL) Key = Key_member->value.GetString();
	
	const Value::Member* HttpMethod_member = obj.FindMember("HttpMethod");
	if (HttpMethod_member != NULL) HttpMethod = HttpMethod_member->value.GetString();
	
	const Value::Member* ThruCDN_member = obj.FindMember("ThruCDN");
	if (ThruCDN_member != NULL) ThruCDN = ThruCDN_member->value.GetBool();
	
	
	return true;
}


GetContentDownloadUrlResult::~GetContentDownloadUrlResult()
{
	
}

void GetContentDownloadUrlResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }
	
	
	writer.EndObject();
}

bool GetContentDownloadUrlResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* URL_member = obj.FindMember("URL");
	if (URL_member != NULL) URL = URL_member->value.GetString();
	
	
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
	
	if(CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
	
	writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
	
	
	writer.EndObject();
}

bool GetLeaderboardAroundCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
	if (StatisticName_member != NULL) StatisticName = StatisticName_member->value.GetString();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
	if (CharacterType_member != NULL) CharacterType = CharacterType_member->value.GetString();
	
	const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
	if (MaxResultsCount_member != NULL) MaxResultsCount = MaxResultsCount_member->value.GetInt();
	
	
	return true;
}


GetLeaderboardAroundCharacterResult::~GetLeaderboardAroundCharacterResult()
{
	
}

void GetLeaderboardAroundCharacterResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Leaderboard.empty()) {
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
	if (StatisticName_member != NULL) StatisticName = StatisticName_member->value.GetString();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
	if (MaxResultsCount_member != NULL) MaxResultsCount = MaxResultsCount_member->value.GetInt();
	
	
	return true;
}


PlayerLeaderboardEntry::~PlayerLeaderboardEntry()
{
	
}

void PlayerLeaderboardEntry::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	if(DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
	
	writer.String("StatValue"); writer.Int(StatValue);
	
	writer.String("Position"); writer.Int(Position);
	
	
	writer.EndObject();
}

bool PlayerLeaderboardEntry::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
	if (DisplayName_member != NULL) DisplayName = DisplayName_member->value.GetString();
	
	const Value::Member* StatValue_member = obj.FindMember("StatValue");
	if (StatValue_member != NULL) StatValue = StatValue_member->value.GetInt();
	
	const Value::Member* Position_member = obj.FindMember("Position");
	if (Position_member != NULL) Position = Position_member->value.GetInt();
	
	
	return true;
}


GetLeaderboardAroundUserResult::~GetLeaderboardAroundUserResult()
{
	
}

void GetLeaderboardAroundUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Leaderboard.empty()) {
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
	if (StatisticName_member != NULL) StatisticName = StatisticName_member->value.GetString();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
	if (MaxResultsCount_member != NULL) MaxResultsCount = MaxResultsCount_member->value.GetInt();
	
	
	return true;
}


GetLeaderboardForUsersCharactersResult::~GetLeaderboardForUsersCharactersResult()
{
	
}

void GetLeaderboardForUsersCharactersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Leaderboard.empty()) {
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
	if (StatisticName_member != NULL) StatisticName = StatisticName_member->value.GetString();
	
	const Value::Member* StartPosition_member = obj.FindMember("StartPosition");
	if (StartPosition_member != NULL) StartPosition = StartPosition_member->value.GetInt();
	
	const Value::Member* MaxResultsCount_member = obj.FindMember("MaxResultsCount");
	if (MaxResultsCount_member != NULL) MaxResultsCount = MaxResultsCount_member->value.GetInt();
	
	
	return true;
}


GetLeaderboardResult::~GetLeaderboardResult()
{
	
}

void GetLeaderboardResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Leaderboard.empty()) {
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

	
	if(!Data.empty()) {
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

	
	if(SharedGroupId.length() > 0) { writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str()); }
	
	if(!Keys.empty()) {
	writer.String("Keys");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(GetMembers.notNull()) { writer.String("GetMembers"); writer.Bool(GetMembers); }
	
	
	writer.EndObject();
}

bool GetSharedGroupDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
	if (SharedGroupId_member != NULL) SharedGroupId = SharedGroupId_member->value.GetString();
	
	const Value::Member* Keys_member = obj.FindMember("Keys");
	if (Keys_member != NULL) {
		const rapidjson::Value& memberList = Keys_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			Keys.push_back(memberList[i].GetString());
		}
	}
	
	const Value::Member* GetMembers_member = obj.FindMember("GetMembers");
	if (GetMembers_member != NULL) GetMembers = GetMembers_member->value.GetBool();
	
	
	return true;
}


SharedGroupDataRecord::~SharedGroupDataRecord()
{
	
}

void SharedGroupDataRecord::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
	
	if(LastUpdatedBy.length() > 0) { writer.String("LastUpdatedBy"); writer.String(LastUpdatedBy.c_str()); }
	
	writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
	
	if(Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
	
	
	writer.EndObject();
}

bool SharedGroupDataRecord::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Value_member = obj.FindMember("Value");
	if (Value_member != NULL) Value = Value_member->value.GetString();
	
	const Value::Member* LastUpdatedBy_member = obj.FindMember("LastUpdatedBy");
	if (LastUpdatedBy_member != NULL) LastUpdatedBy = LastUpdatedBy_member->value.GetString();
	
	const Value::Member* LastUpdated_member = obj.FindMember("LastUpdated");
	if (LastUpdated_member != NULL) LastUpdated = readDatetime(LastUpdated_member->value);
	
	const Value::Member* Permission_member = obj.FindMember("Permission");
	if (Permission_member != NULL) Permission = readUserDataPermissionFromValue(Permission_member->value);
	
	
	return true;
}


GetSharedGroupDataResult::~GetSharedGroupDataResult()
{
	
}

void GetSharedGroupDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Data.empty()) {
	writer.String("Data");
	writer.StartObject();
	for (std::map<std::string, SharedGroupDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
		writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
	}
	writer.EndObject();
	}
	
	if(!Members.empty()) {
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

	
	writer.String("Keys");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	
	
	
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

	
	if(!Data.empty()) {
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	
	return true;
}


GetUserAccountInfoResult::~GetUserAccountInfoResult()
{
	if(UserInfo != NULL) delete UserInfo;
	
}

void GetUserAccountInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
	
	
	writer.EndObject();
}

bool GetUserAccountInfoResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* UserInfo_member = obj.FindMember("UserInfo");
	if (UserInfo_member != NULL) UserInfo = new UserAccountInfo(UserInfo_member->value);
	
	
	return true;
}


GetUserDataRequest::~GetUserDataRequest()
{
	
}

void GetUserDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
	
	if(!Keys.empty()) {
	writer.String("Keys");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	
	writer.EndObject();
}

bool GetUserDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* Keys_member = obj.FindMember("Keys");
	if (Keys_member != NULL) {
		const rapidjson::Value& memberList = Keys_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			Keys.push_back(memberList[i].GetString());
		}
	}
	
	
	return true;
}


GetUserDataResult::~GetUserDataResult()
{
	
}

void GetUserDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	if(!Data.empty()) {
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
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
	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
	
	writer.EndObject();
}

bool GetUserInventoryRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
	
	return true;
}


ItemInstance::~ItemInstance()
{
	
}

void ItemInstance::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
	
	if(ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
	
	if(ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
	
	if(PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
	
	if(Expiration.notNull()) { writer.String("Expiration"); writeDatetime(Expiration, writer); }
	
	if(RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
	
	if(Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
	if(BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
	
	
	writer.EndObject();
}

bool ItemInstance::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* ItemId_member = obj.FindMember("ItemId");
	if (ItemId_member != NULL) ItemId = ItemId_member->value.GetString();
	
	const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL) ItemInstanceId = ItemInstanceId_member->value.GetString();
	
	const Value::Member* ItemClass_member = obj.FindMember("ItemClass");
	if (ItemClass_member != NULL) ItemClass = ItemClass_member->value.GetString();
	
	const Value::Member* PurchaseDate_member = obj.FindMember("PurchaseDate");
	if (PurchaseDate_member != NULL) PurchaseDate = readDatetime(PurchaseDate_member->value);
	
	const Value::Member* Expiration_member = obj.FindMember("Expiration");
	if (Expiration_member != NULL) Expiration = readDatetime(Expiration_member->value);
	
	const Value::Member* RemainingUses_member = obj.FindMember("RemainingUses");
	if (RemainingUses_member != NULL) RemainingUses = RemainingUses_member->value.GetInt();
	
	const Value::Member* Annotation_member = obj.FindMember("Annotation");
	if (Annotation_member != NULL) Annotation = Annotation_member->value.GetString();
	
	const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
	const Value::Member* BundleParent_member = obj.FindMember("BundleParent");
	if (BundleParent_member != NULL) BundleParent = BundleParent_member->value.GetString();
	
	
	return true;
}


GetUserInventoryResult::~GetUserInventoryResult()
{
	
}

void GetUserInventoryResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Inventory.empty()) {
	writer.String("Inventory");
	writer.StartArray();
	for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
		iter->writeJSON(writer);
	}
	writer.EndArray();
	 }
	
	if(!VirtualCurrency.empty()) {
	writer.String("VirtualCurrency");
	writer.StartObject();
	for (std::map<std::string, Int32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
		writer.String(iter->first.c_str()); writer.Int(iter->second);
	}
	writer.EndObject();
	}
	
	
	writer.EndObject();
}

bool GetUserInventoryResult::readFromValue(const rapidjson::Value& obj)
{
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	
	return true;
}


GetUserStatisticsResult::~GetUserStatisticsResult()
{
	
}

void GetUserStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!UserStatistics.empty()) {
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterName_member = obj.FindMember("CharacterName");
	if (CharacterName_member != NULL) CharacterName = CharacterName_member->value.GetString();
	
	const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
	if (CharacterType_member != NULL) CharacterType = CharacterType_member->value.GetString();
	
	
	return true;
}


GrantCharacterToUserResult::~GrantCharacterToUserResult()
{
	
}

void GrantCharacterToUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
	
	
	writer.EndObject();
}

bool GrantCharacterToUserResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	
	return true;
}


GrantItemsToCharacterRequest::~GrantItemsToCharacterRequest()
{
	
}

void GrantItemsToCharacterRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
	writer.String("CharacterId"); writer.String(CharacterId.c_str());
	
	writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
	
	if(Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
	
	if(!ItemIds.empty()) {
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
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* Annotation_member = obj.FindMember("Annotation");
	if (Annotation_member != NULL) Annotation = Annotation_member->value.GetString();
	
	const Value::Member* ItemIds_member = obj.FindMember("ItemIds");
	if (ItemIds_member != NULL) {
		const rapidjson::Value& memberList = ItemIds_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ItemIds.push_back(memberList[i].GetString());
		}
	}
	
	
	return true;
}


ItemGrantResult::~ItemGrantResult()
{
	
}

void ItemGrantResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	if(ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
	
	if(ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
	
	if(Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
	
	writer.String("Result"); writer.Bool(Result);
	
	if(CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
	
	
	writer.EndObject();
}

bool ItemGrantResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* ItemId_member = obj.FindMember("ItemId");
	if (ItemId_member != NULL) ItemId = ItemId_member->value.GetString();
	
	const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL) ItemInstanceId = ItemInstanceId_member->value.GetString();
	
	const Value::Member* Annotation_member = obj.FindMember("Annotation");
	if (Annotation_member != NULL) Annotation = Annotation_member->value.GetString();
	
	const Value::Member* Result_member = obj.FindMember("Result");
	if (Result_member != NULL) Result = Result_member->value.GetBool();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	
	return true;
}


GrantItemsToCharacterResult::~GrantItemsToCharacterResult()
{
	
}

void GrantItemsToCharacterResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!ItemGrantResults.empty()) {
	writer.String("ItemGrantResults");
	writer.StartArray();
	for (std::list<ItemGrantResult>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
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
			ItemGrantResults.push_back(ItemGrantResult(memberList[i]));
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

	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	if(Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
	
	if(!ItemIds.empty()) {
	writer.String("ItemIds");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = ItemIds.begin(); iter != ItemIds.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	
	writer.EndObject();
}

bool GrantItemsToUserRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* Annotation_member = obj.FindMember("Annotation");
	if (Annotation_member != NULL) Annotation = Annotation_member->value.GetString();
	
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

	
	if(!ItemGrantResults.empty()) {
	writer.String("ItemGrantResults");
	writer.StartArray();
	for (std::list<ItemGrantResult>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
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
			ItemGrantResults.push_back(ItemGrantResult(memberList[i]));
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
	
	if(Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
	
	if(CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
	
	
	writer.EndObject();
}

bool ItemGrant::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* ItemId_member = obj.FindMember("ItemId");
	if (ItemId_member != NULL) ItemId = ItemId_member->value.GetString();
	
	const Value::Member* Annotation_member = obj.FindMember("Annotation");
	if (Annotation_member != NULL) Annotation = Annotation_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	
	return true;
}


GrantItemsToUsersRequest::~GrantItemsToUsersRequest()
{
	
}

void GrantItemsToUsersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
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
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
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

	
	if(!ItemGrantResults.empty()) {
	writer.String("ItemGrantResults");
	writer.StartArray();
	for (std::list<ItemGrantResult>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
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
			ItemGrantResults.push_back(ItemGrantResult(memberList[i]));
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	
	return true;
}


ListUsersCharactersResult::~ListUsersCharactersResult()
{
	
}

void ListUsersCharactersResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Characters.empty()) {
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

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	if(EntityId.length() > 0) { writer.String("EntityId"); writer.String(EntityId.c_str()); }
	
	if(EntityType.length() > 0) { writer.String("EntityType"); writer.String(EntityType.c_str()); }
	
	if(Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
	
	if(EventName.length() > 0) { writer.String("EventName"); writer.String(EventName.c_str()); }
	
	if(!Body.empty()) {
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* EntityId_member = obj.FindMember("EntityId");
	if (EntityId_member != NULL) EntityId = EntityId_member->value.GetString();
	
	const Value::Member* EntityType_member = obj.FindMember("EntityType");
	if (EntityType_member != NULL) EntityType = EntityType_member->value.GetString();
	
	const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL) Timestamp = readDatetime(Timestamp_member->value);
	
	const Value::Member* EventName_member = obj.FindMember("EventName");
	if (EventName_member != NULL) EventName = EventName_member->value.GetString();
	
	const Value::Member* Body_member = obj.FindMember("Body");
	if (Body_member != NULL) {
		for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
			Body[iter->name.GetString()] = MultitypeVar(iter->value);
		}
	}
	
	const Value::Member* ProfileSetEvent_member = obj.FindMember("ProfileSetEvent");
	if (ProfileSetEvent_member != NULL) ProfileSetEvent = ProfileSetEvent_member->value.GetBool();
	
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL) ItemInstanceId = ItemInstanceId_member->value.GetString();
	
	const Value::Member* UsesToAdd_member = obj.FindMember("UsesToAdd");
	if (UsesToAdd_member != NULL) UsesToAdd = UsesToAdd_member->value.GetInt();
	
	
	return true;
}


ModifyItemUsesResult::~ModifyItemUsesResult()
{
	
}

void ModifyItemUsesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
	
	writer.String("RemainingUses"); writer.Int(RemainingUses);
	
	
	writer.EndObject();
}

bool ModifyItemUsesResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL) ItemInstanceId = ItemInstanceId_member->value.GetString();
	
	const Value::Member* RemainingUses_member = obj.FindMember("RemainingUses");
	if (RemainingUses_member != NULL) RemainingUses = RemainingUses_member->value.GetInt();
	
	
	return true;
}


ModifyUserVirtualCurrencyResult::~ModifyUserVirtualCurrencyResult()
{
	
}

void ModifyUserVirtualCurrencyResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
	
	writer.String("Balance"); writer.Int(Balance);
	
	
	writer.EndObject();
}

bool ModifyUserVirtualCurrencyResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
	if (VirtualCurrency_member != NULL) VirtualCurrency = VirtualCurrency_member->value.GetString();
	
	const Value::Member* Balance_member = obj.FindMember("Balance");
	if (Balance_member != NULL) Balance = Balance_member->value.GetInt();
	
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* GivingCharacterId_member = obj.FindMember("GivingCharacterId");
	if (GivingCharacterId_member != NULL) GivingCharacterId = GivingCharacterId_member->value.GetString();
	
	const Value::Member* ReceivingCharacterId_member = obj.FindMember("ReceivingCharacterId");
	if (ReceivingCharacterId_member != NULL) ReceivingCharacterId = ReceivingCharacterId_member->value.GetString();
	
	const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL) ItemInstanceId = ItemInstanceId_member->value.GetString();
	
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL) ItemInstanceId = ItemInstanceId_member->value.GetString();
	
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL) ItemInstanceId = ItemInstanceId_member->value.GetString();
	
	
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
	if (LobbyId_member != NULL) LobbyId = LobbyId_member->value.GetString();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	
	return true;
}


void PlayFab::ServerModels::writePlayerConnectionStateEnumJSON(PlayerConnectionState enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
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
	std::string enumStr = obj.GetString();
	if(enumStr == "Unassigned")
		return PlayerConnectionStateUnassigned;
	else if(enumStr == "Connecting")
		return PlayerConnectionStateConnecting;
	else if(enumStr == "Participating")
		return PlayerConnectionStateParticipating;
	else if(enumStr == "Participated")
		return PlayerConnectionStateParticipated;
	else if(enumStr == "Reconnecting")
		return PlayerConnectionStateReconnecting;
	
	return PlayerConnectionStateUnassigned;
}


NotifyMatchmakerPlayerLeftResult::~NotifyMatchmakerPlayerLeftResult()
{
	
}

void NotifyMatchmakerPlayerLeftResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(PlayerState.notNull()) { writer.String("PlayerState"); writePlayerConnectionStateEnumJSON(PlayerState, writer); }
	
	
	writer.EndObject();
}

bool NotifyMatchmakerPlayerLeftResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayerState_member = obj.FindMember("PlayerState");
	if (PlayerState_member != NULL) PlayerState = readPlayerConnectionStateFromValue(PlayerState_member->value);
	
	
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
	if (Ticket_member != NULL) Ticket = Ticket_member->value.GetString();
	
	const Value::Member* LobbyId_member = obj.FindMember("LobbyId");
	if (LobbyId_member != NULL) LobbyId = LobbyId_member->value.GetString();
	
	
	return true;
}


RedeemMatchmakerTicketResult::~RedeemMatchmakerTicketResult()
{
	if(UserInfo != NULL) delete UserInfo;
	
}

void RedeemMatchmakerTicketResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("TicketIsValid"); writer.Bool(TicketIsValid);
	
	if(Error.length() > 0) { writer.String("Error"); writer.String(Error.c_str()); }
	
	if(UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
	
	
	writer.EndObject();
}

bool RedeemMatchmakerTicketResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* TicketIsValid_member = obj.FindMember("TicketIsValid");
	if (TicketIsValid_member != NULL) TicketIsValid = TicketIsValid_member->value.GetBool();
	
	const Value::Member* Error_member = obj.FindMember("Error");
	if (Error_member != NULL) Error = Error_member->value.GetString();
	
	const Value::Member* UserInfo_member = obj.FindMember("UserInfo");
	if (UserInfo_member != NULL) UserInfo = new UserAccountInfo(UserInfo_member->value);
	
	
	return true;
}


RemoveSharedGroupMembersRequest::~RemoveSharedGroupMembersRequest()
{
	
}

void RemoveSharedGroupMembersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
	
	if(!PlayFabIds.empty()) {
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
	if (SharedGroupId_member != NULL) SharedGroupId = SharedGroupId_member->value.GetString();
	
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
	
	if(TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
	
	if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
	
	
	writer.EndObject();
}

bool ReportPlayerServerRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* ReporterId_member = obj.FindMember("ReporterId");
	if (ReporterId_member != NULL) ReporterId = ReporterId_member->value.GetString();
	
	const Value::Member* ReporteeId_member = obj.FindMember("ReporteeId");
	if (ReporteeId_member != NULL) ReporteeId = ReporteeId_member->value.GetString();
	
	const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL) TitleId = TitleId_member->value.GetString();
	
	const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL) Comment = Comment_member->value.GetString();
	
	
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
	if (Updated_member != NULL) Updated = Updated_member->value.GetBool();
	
	const Value::Member* SubmissionsRemaining_member = obj.FindMember("SubmissionsRemaining");
	if (SubmissionsRemaining_member != NULL) SubmissionsRemaining = SubmissionsRemaining_member->value.GetInt();
	
	
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
	
	if(Subject.length() > 0) { writer.String("Subject"); writer.String(Subject.c_str()); }
	
	
	writer.EndObject();
}

bool SendPushNotificationRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Recipient_member = obj.FindMember("Recipient");
	if (Recipient_member != NULL) Recipient = Recipient_member->value.GetString();
	
	const Value::Member* Message_member = obj.FindMember("Message");
	if (Message_member != NULL) Message = Message_member->value.GetString();
	
	const Value::Member* Subject_member = obj.FindMember("Subject");
	if (Subject_member != NULL) Subject = Subject_member->value.GetString();
	
	
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
	
	if(Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
	
	
	writer.EndObject();
}

bool SetPublisherDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Key_member = obj.FindMember("Key");
	if (Key_member != NULL) Key = Key_member->value.GetString();
	
	const Value::Member* Value_member = obj.FindMember("Value");
	if (Value_member != NULL) Value = Value_member->value.GetString();
	
	
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
	
	if(Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
	
	
	writer.EndObject();
}

bool SetTitleDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Key_member = obj.FindMember("Key");
	if (Key_member != NULL) Key = Key_member->value.GetString();
	
	const Value::Member* Value_member = obj.FindMember("Value");
	if (Value_member != NULL) Value = Value_member->value.GetString();
	
	
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
	if (VirtualCurrency_member != NULL) VirtualCurrency = VirtualCurrency_member->value.GetString();
	
	const Value::Member* Amount_member = obj.FindMember("Amount");
	if (Amount_member != NULL) Amount = Amount_member->value.GetInt();
	
	
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
	
	if(!Data.empty()) {
	writer.String("Data");
	writer.StartObject();
	for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
		writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
	}
	writer.EndObject();
	}
	
	if(Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
	
	
	writer.EndObject();
}

bool UpdateCharacterDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
	const Value::Member* Data_member = obj.FindMember("Data");
	if (Data_member != NULL) {
		for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
			Data[iter->name.GetString()] = iter->value.GetString();
		}
	}
	
	const Value::Member* Permission_member = obj.FindMember("Permission");
	if (Permission_member != NULL) Permission = readUserDataPermissionFromValue(Permission_member->value);
	
	
	return true;
}


UpdateCharacterDataResult::~UpdateCharacterDataResult()
{
	
}

void UpdateCharacterDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	
	writer.EndObject();
}

bool UpdateCharacterDataResult::readFromValue(const rapidjson::Value& obj)
{
	
	
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
	
	if(!CharacterStatistics.empty()) {
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL) CharacterId = CharacterId_member->value.GetString();
	
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
	
	if(!Data.empty()) {
	writer.String("Data");
	writer.StartObject();
	for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
		writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
	}
	writer.EndObject();
	}
	
	if(Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
	
	
	writer.EndObject();
}

bool UpdateSharedGroupDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* SharedGroupId_member = obj.FindMember("SharedGroupId");
	if (SharedGroupId_member != NULL) SharedGroupId = SharedGroupId_member->value.GetString();
	
	const Value::Member* Data_member = obj.FindMember("Data");
	if (Data_member != NULL) {
		for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
			Data[iter->name.GetString()] = iter->value.GetString();
		}
	}
	
	const Value::Member* Permission_member = obj.FindMember("Permission");
	if (Permission_member != NULL) Permission = readUserDataPermissionFromValue(Permission_member->value);
	
	
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
	
	if(!Data.empty()) {
	writer.String("Data");
	writer.StartObject();
	for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
		writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
	}
	writer.EndObject();
	}
	
	if(Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
	
	
	writer.EndObject();
}

bool UpdateUserDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* Data_member = obj.FindMember("Data");
	if (Data_member != NULL) {
		for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
			Data[iter->name.GetString()] = iter->value.GetString();
		}
	}
	
	const Value::Member* Permission_member = obj.FindMember("Permission");
	if (Permission_member != NULL) Permission = readUserDataPermissionFromValue(Permission_member->value);
	
	
	return true;
}


UpdateUserDataResult::~UpdateUserDataResult()
{
	
}

void UpdateUserDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	
	writer.EndObject();
}

bool UpdateUserDataResult::readFromValue(const rapidjson::Value& obj)
{
	
	
	return true;
}


UpdateUserInternalDataRequest::~UpdateUserInternalDataRequest()
{
	
}

void UpdateUserInternalDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
	
	if(!Data.empty()) {
	writer.String("Data");
	writer.StartObject();
	for (std::map<std::string, std::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
		writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
	}
	writer.EndObject();
	}
	
	
	writer.EndObject();
}

bool UpdateUserInternalDataRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* Data_member = obj.FindMember("Data");
	if (Data_member != NULL) {
		for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
			Data[iter->name.GetString()] = iter->value.GetString();
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
	
	if(!UserStatistics.empty()) {
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
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
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




