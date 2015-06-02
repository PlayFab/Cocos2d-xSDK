
#include "playfab/PlayFabMatchmakerDataModels.h"

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
	
	const Value::Member* AuthorizationTicket_member = obj.FindMember("AuthorizationTicket");
	if (AuthorizationTicket_member != NULL) AuthorizationTicket = AuthorizationTicket_member->value.GetString();
	
	
	return true;
}


AuthUserResponse::~AuthUserResponse()
{
	
}

void AuthUserResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("Authorized"); writer.Bool(Authorized);
	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	
	writer.EndObject();
}

bool AuthUserResponse::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Authorized_member = obj.FindMember("Authorized");
	if (Authorized_member != NULL) Authorized = Authorized_member->value.GetBool();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	
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
	
	if(!CustomData.empty()) {
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
	
	const Value::Member* CustomData_member = obj.FindMember("CustomData");
	if (CustomData_member != NULL) {
		for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
			CustomData[iter->name.GetString()] = iter->value.GetString();
		}
	}
	
	
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
	
	const Value::Member* LobbyId_member = obj.FindMember("LobbyId");
	if (LobbyId_member != NULL) LobbyId = LobbyId_member->value.GetString();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	
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
	
	const Value::Member* LobbyId_member = obj.FindMember("LobbyId");
	if (LobbyId_member != NULL) LobbyId = LobbyId_member->value.GetString();
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	
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
	switch(enumVal)
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
	std::string enumStr = obj.GetString();
	if(enumStr == "USCentral")
		return RegionUSCentral;
	else if(enumStr == "USEast")
		return RegionUSEast;
	else if(enumStr == "EUWest")
		return RegionEUWest;
	else if(enumStr == "Singapore")
		return RegionSingapore;
	else if(enumStr == "Japan")
		return RegionJapan;
	else if(enumStr == "Brazil")
		return RegionBrazil;
	else if(enumStr == "Australia")
		return RegionAustralia;
	
	return RegionUSCentral;
}


StartGameRequest::~StartGameRequest()
{
	
}

void StartGameRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("Build"); writer.String(Build.c_str());
	
	writer.String("Region"); writeRegionEnumJSON(Region, writer);
	
	writer.String("GameMode"); writer.String(GameMode.c_str());
	
	if(CustomCommandLineData.length() > 0) { writer.String("CustomCommandLineData"); writer.String(CustomCommandLineData.c_str()); }
	
	writer.String("ExternalMatchmakerEventEndpoint"); writer.String(ExternalMatchmakerEventEndpoint.c_str());
	
	
	writer.EndObject();
}

bool StartGameRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Build_member = obj.FindMember("Build");
	if (Build_member != NULL) Build = Build_member->value.GetString();
	
	const Value::Member* Region_member = obj.FindMember("Region");
	if (Region_member != NULL) Region = readRegionFromValue(Region_member->value);
	
	const Value::Member* GameMode_member = obj.FindMember("GameMode");
	if (GameMode_member != NULL) GameMode = GameMode_member->value.GetString();
	
	const Value::Member* CustomCommandLineData_member = obj.FindMember("CustomCommandLineData");
	if (CustomCommandLineData_member != NULL) CustomCommandLineData = CustomCommandLineData_member->value.GetString();
	
	const Value::Member* ExternalMatchmakerEventEndpoint_member = obj.FindMember("ExternalMatchmakerEventEndpoint");
	if (ExternalMatchmakerEventEndpoint_member != NULL) ExternalMatchmakerEventEndpoint = ExternalMatchmakerEventEndpoint_member->value.GetString();
	
	
	return true;
}


StartGameResponse::~StartGameResponse()
{
	
}

void StartGameResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(GameID.length() > 0) { writer.String("GameID"); writer.String(GameID.c_str()); }
	
	if(ServerHostname.length() > 0) { writer.String("ServerHostname"); writer.String(ServerHostname.c_str()); }
	
	writer.String("ServerPort"); writer.Uint(ServerPort);
	
	
	writer.EndObject();
}

bool StartGameResponse::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* GameID_member = obj.FindMember("GameID");
	if (GameID_member != NULL) GameID = GameID_member->value.GetString();
	
	const Value::Member* ServerHostname_member = obj.FindMember("ServerHostname");
	if (ServerHostname_member != NULL) ServerHostname = ServerHostname_member->value.GetString();
	
	const Value::Member* ServerPort_member = obj.FindMember("ServerPort");
	if (ServerPort_member != NULL) ServerPort = ServerPort_member->value.GetUint();
	
	
	return true;
}


UserInfoRequest::~UserInfoRequest()
{
	
}

void UserInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
	
	writer.String("MinCatalogVersion"); writer.Int(MinCatalogVersion);
	
	
	writer.EndObject();
}

bool UserInfoRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* MinCatalogVersion_member = obj.FindMember("MinCatalogVersion");
	if (MinCatalogVersion_member != NULL) MinCatalogVersion = MinCatalogVersion_member->value.GetInt();
	
	
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
	if (SecondsToRecharge_member != NULL) SecondsToRecharge = SecondsToRecharge_member->value.GetInt();
	
	const Value::Member* RechargeTime_member = obj.FindMember("RechargeTime");
	if (RechargeTime_member != NULL) RechargeTime = readDatetime(RechargeTime_member->value);
	
	const Value::Member* RechargeMax_member = obj.FindMember("RechargeMax");
	if (RechargeMax_member != NULL) RechargeMax = RechargeMax_member->value.GetInt();
	
	
	return true;
}


UserInfoResponse::~UserInfoResponse()
{
	
}

void UserInfoResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	if(Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
	
	if(TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
	
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
	
	if(!VirtualCurrencyRechargeTimes.empty()) {
	writer.String("VirtualCurrencyRechargeTimes");
	writer.StartObject();
	for (std::map<std::string, VirtualCurrencyRechargeTime>::iterator iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) {
		writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
	}
	writer.EndObject();
	}
	
	writer.String("IsDeveloper"); writer.Bool(IsDeveloper);
	
	if(SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
	
	
	writer.EndObject();
}

bool UserInfoResponse::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* Username_member = obj.FindMember("Username");
	if (Username_member != NULL) Username = Username_member->value.GetString();
	
	const Value::Member* TitleDisplayName_member = obj.FindMember("TitleDisplayName");
	if (TitleDisplayName_member != NULL) TitleDisplayName = TitleDisplayName_member->value.GetString();
	
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
	
	const Value::Member* IsDeveloper_member = obj.FindMember("IsDeveloper");
	if (IsDeveloper_member != NULL) IsDeveloper = IsDeveloper_member->value.GetBool();
	
	const Value::Member* SteamId_member = obj.FindMember("SteamId");
	if (SteamId_member != NULL) SteamId = SteamId_member->value.GetString();
	
	
	return true;
}




