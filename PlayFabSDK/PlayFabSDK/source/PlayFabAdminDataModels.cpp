
#include "playfab/PlayFabAdminDataModels.h"

using namespace PlayFab;
using namespace PlayFab::AdminModels;
using namespace rapidjson;



AddNewsRequest::~AddNewsRequest()
{
	
}

void AddNewsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
	
	writer.String("Title"); writer.String(Title.c_str());
	
	writer.String("Body"); writer.String(Body.c_str());
	
	
	writer.EndObject();
}

bool AddNewsRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL) Timestamp = readDatetime(Timestamp_member->value);
	
	const Value::Member* Title_member = obj.FindMember("Title");
	if (Title_member != NULL) Title = Title_member->value.GetString();
	
	const Value::Member* Body_member = obj.FindMember("Body");
	if (Body_member != NULL) Body = Body_member->value.GetString();
	
	
	return true;
}


AddNewsResult::~AddNewsResult()
{
	
}

void AddNewsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(NewsId.length() > 0) { writer.String("NewsId"); writer.String(NewsId.c_str()); }
	
	
	writer.EndObject();
}

bool AddNewsResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* NewsId_member = obj.FindMember("NewsId");
	if (NewsId_member != NULL) NewsId = NewsId_member->value.GetString();
	
	
	return true;
}


AddServerBuildRequest::~AddServerBuildRequest()
{
	
}

void AddServerBuildRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("BuildId"); writer.String(BuildId.c_str());
	
	writer.String("Active"); writer.Bool(Active);
	
	writer.String("DedicatedServerEligible"); writer.Bool(DedicatedServerEligible);
	
	if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
	
	
	writer.EndObject();
}

bool AddServerBuildRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL) BuildId = BuildId_member->value.GetString();
	
	const Value::Member* Active_member = obj.FindMember("Active");
	if (Active_member != NULL) Active = Active_member->value.GetBool();
	
	const Value::Member* DedicatedServerEligible_member = obj.FindMember("DedicatedServerEligible");
	if (DedicatedServerEligible_member != NULL) DedicatedServerEligible = DedicatedServerEligible_member->value.GetBool();
	
	const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(memberList[i].GetString());
		}
	}
	
	const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL) Comment = Comment_member->value.GetString();
	
	
	return true;
}


void PlayFab::AdminModels::writeGameBuildStatusEnumJSON(GameBuildStatus enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
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
	std::string enumStr = obj.GetString();
	if(enumStr == "Available")
		return GameBuildStatusAvailable;
	else if(enumStr == "Validating")
		return GameBuildStatusValidating;
	else if(enumStr == "InvalidBuildPackage")
		return GameBuildStatusInvalidBuildPackage;
	else if(enumStr == "Processing")
		return GameBuildStatusProcessing;
	else if(enumStr == "FailedToProcess")
		return GameBuildStatusFailedToProcess;
	
	return GameBuildStatusAvailable;
}


AddServerBuildResult::~AddServerBuildResult()
{
	
}

void AddServerBuildResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
	
	writer.String("Active"); writer.Bool(Active);
	
	if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
	
	writer.String("Timestamp"); writeDatetime(Timestamp, writer);
	
	if(TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
	
	if(Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
	
	
	writer.EndObject();
}

bool AddServerBuildResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL) BuildId = BuildId_member->value.GetString();
	
	const Value::Member* Active_member = obj.FindMember("Active");
	if (Active_member != NULL) Active = Active_member->value.GetBool();
	
	const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(memberList[i].GetString());
		}
	}
	
	const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL) Comment = Comment_member->value.GetString();
	
	const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL) Timestamp = readDatetime(Timestamp_member->value);
	
	const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL) TitleId = TitleId_member->value.GetString();
	
	const Value::Member* Status_member = obj.FindMember("Status");
	if (Status_member != NULL) Status = readGameBuildStatusFromValue(Status_member->value);
	
	
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


AddVirtualCurrencyTypesRequest::~AddVirtualCurrencyTypesRequest()
{
	
}

void AddVirtualCurrencyTypesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("VirtualCurrencyIds");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = VirtualCurrencyIds.begin(); iter != VirtualCurrencyIds.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	
	
	
	writer.EndObject();
}

bool AddVirtualCurrencyTypesRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* VirtualCurrencyIds_member = obj.FindMember("VirtualCurrencyIds");
	if (VirtualCurrencyIds_member != NULL) {
		const rapidjson::Value& memberList = VirtualCurrencyIds_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			VirtualCurrencyIds.push_back(memberList[i].GetString());
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
	
	if(ReleaseDate.notNull()) { writer.String("ReleaseDate"); writeDatetime(ReleaseDate, writer); }
	
	if(ExpirationDate.notNull()) { writer.String("ExpirationDate"); writeDatetime(ExpirationDate, writer); }
	
	if(IsFree.notNull()) { writer.String("IsFree"); writer.Bool(IsFree); }
	
	if(NotForSale.notNull()) { writer.String("NotForSale"); writer.Bool(NotForSale); }
	
	if(NotForTrade.notNull()) { writer.String("NotForTrade"); writer.Bool(NotForTrade); }
	
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
	
	const Value::Member* ReleaseDate_member = obj.FindMember("ReleaseDate");
	if (ReleaseDate_member != NULL) ReleaseDate = readDatetime(ReleaseDate_member->value);
	
	const Value::Member* ExpirationDate_member = obj.FindMember("ExpirationDate");
	if (ExpirationDate_member != NULL) ExpirationDate = readDatetime(ExpirationDate_member->value);
	
	const Value::Member* IsFree_member = obj.FindMember("IsFree");
	if (IsFree_member != NULL) IsFree = IsFree_member->value.GetBool();
	
	const Value::Member* NotForSale_member = obj.FindMember("NotForSale");
	if (NotForSale_member != NULL) NotForSale = NotForSale_member->value.GetBool();
	
	const Value::Member* NotForTrade_member = obj.FindMember("NotForTrade");
	if (NotForTrade_member != NULL) NotForTrade = NotForTrade_member->value.GetBool();
	
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


void PlayFab::AdminModels::writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
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

Currency PlayFab::AdminModels::readCurrencyFromValue(const rapidjson::Value& obj)
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


GameModeInfo::~GameModeInfo()
{
	
}

void GameModeInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("Gamemode"); writer.String(Gamemode.c_str());
	
	writer.String("MinPlayerCount"); writer.Uint(MinPlayerCount);
	
	writer.String("MaxPlayerCount"); writer.Uint(MaxPlayerCount);
	
	writer.String("PerfCostPerGame"); writer.Double(PerfCostPerGame);
	
	
	writer.EndObject();
}

bool GameModeInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Gamemode_member = obj.FindMember("Gamemode");
	if (Gamemode_member != NULL) Gamemode = Gamemode_member->value.GetString();
	
	const Value::Member* MinPlayerCount_member = obj.FindMember("MinPlayerCount");
	if (MinPlayerCount_member != NULL) MinPlayerCount = MinPlayerCount_member->value.GetUint();
	
	const Value::Member* MaxPlayerCount_member = obj.FindMember("MaxPlayerCount");
	if (MaxPlayerCount_member != NULL) MaxPlayerCount = MaxPlayerCount_member->value.GetUint();
	
	const Value::Member* PerfCostPerGame_member = obj.FindMember("PerfCostPerGame");
	if (PerfCostPerGame_member != NULL) PerfCostPerGame = (float)PerfCostPerGame_member->value.GetDouble();
	
	
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
	
	const Value::Member* LobbyId_member = obj.FindMember("LobbyId");
	if (LobbyId_member != NULL) LobbyId = LobbyId_member->value.GetString();
	
	
	return true;
}


void PlayFab::AdminModels::writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
	{
		
		case RegionUSWest: writer.String("USWest"); break;
		case RegionUSCentral: writer.String("USCentral"); break;
		case RegionUSEast: writer.String("USEast"); break;
		case RegionEUWest: writer.String("EUWest"); break;
		case RegionAPSouthEast: writer.String("APSouthEast"); break;
		case RegionAPNorthEast: writer.String("APNorthEast"); break;
		case RegionSAEast: writer.String("SAEast"); break;
		case RegionAustralia: writer.String("Australia"); break;
		case RegionChina: writer.String("China"); break;
		case RegionUberLan: writer.String("UberLan"); break;
	}
}

Region PlayFab::AdminModels::readRegionFromValue(const rapidjson::Value& obj)
{
	std::string enumStr = obj.GetString();
	if(enumStr == "USWest")
		return RegionUSWest;
	else if(enumStr == "USCentral")
		return RegionUSCentral;
	else if(enumStr == "USEast")
		return RegionUSEast;
	else if(enumStr == "EUWest")
		return RegionEUWest;
	else if(enumStr == "APSouthEast")
		return RegionAPSouthEast;
	else if(enumStr == "APNorthEast")
		return RegionAPNorthEast;
	else if(enumStr == "SAEast")
		return RegionSAEast;
	else if(enumStr == "Australia")
		return RegionAustralia;
	else if(enumStr == "China")
		return RegionChina;
	else if(enumStr == "UberLan")
		return RegionUberLan;
	
	return RegionUSWest;
}


GetMatchmakerGameInfoResult::~GetMatchmakerGameInfoResult()
{
	
}

void GetMatchmakerGameInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(LobbyId.length() > 0) { writer.String("LobbyId"); writer.String(LobbyId.c_str()); }
	
	if(TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
	
	writer.String("StartTime"); writeDatetime(StartTime, writer);
	
	if(EndTime.notNull()) { writer.String("EndTime"); writeDatetime(EndTime, writer); }
	
	if(Mode.length() > 0) { writer.String("Mode"); writer.String(Mode.c_str()); }
	
	if(BuildVersion.length() > 0) { writer.String("BuildVersion"); writer.String(BuildVersion.c_str()); }
	
	if(Region.notNull()) { writer.String("Region"); writeRegionEnumJSON(Region, writer); }
	
	if(!Players.empty()) {
	writer.String("Players");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = Players.begin(); iter != Players.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(ServerAddress.length() > 0) { writer.String("ServerAddress"); writer.String(ServerAddress.c_str()); }
	
	writer.String("ServerPort"); writer.Uint(ServerPort);
	
	
	writer.EndObject();
}

bool GetMatchmakerGameInfoResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* LobbyId_member = obj.FindMember("LobbyId");
	if (LobbyId_member != NULL) LobbyId = LobbyId_member->value.GetString();
	
	const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL) TitleId = TitleId_member->value.GetString();
	
	const Value::Member* StartTime_member = obj.FindMember("StartTime");
	if (StartTime_member != NULL) StartTime = readDatetime(StartTime_member->value);
	
	const Value::Member* EndTime_member = obj.FindMember("EndTime");
	if (EndTime_member != NULL) EndTime = readDatetime(EndTime_member->value);
	
	const Value::Member* Mode_member = obj.FindMember("Mode");
	if (Mode_member != NULL) Mode = Mode_member->value.GetString();
	
	const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
	if (BuildVersion_member != NULL) BuildVersion = BuildVersion_member->value.GetString();
	
	const Value::Member* Region_member = obj.FindMember("Region");
	if (Region_member != NULL) Region = readRegionFromValue(Region_member->value);
	
	const Value::Member* Players_member = obj.FindMember("Players");
	if (Players_member != NULL) {
		const rapidjson::Value& memberList = Players_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			Players.push_back(memberList[i].GetString());
		}
	}
	
	const Value::Member* ServerAddress_member = obj.FindMember("ServerAddress");
	if (ServerAddress_member != NULL) ServerAddress = ServerAddress_member->value.GetString();
	
	const Value::Member* ServerPort_member = obj.FindMember("ServerPort");
	if (ServerPort_member != NULL) ServerPort = ServerPort_member->value.GetUint();
	
	
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
	
	const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
	if (BuildVersion_member != NULL) BuildVersion = BuildVersion_member->value.GetString();
	
	
	return true;
}


GetMatchmakerGameModesResult::~GetMatchmakerGameModesResult()
{
	
}

void GetMatchmakerGameModesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!GameModes.empty()) {
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
	
	const Value::Member* GameModes_member = obj.FindMember("GameModes");
	if (GameModes_member != NULL) {
		const rapidjson::Value& memberList = GameModes_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			GameModes.push_back(GameModeInfo(memberList[i]));
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

	
	
	writer.EndObject();
}

bool GetRandomResultTablesRequest::readFromValue(const rapidjson::Value& obj)
{
	
	
	return true;
}


void PlayFab::AdminModels::writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
	{
		
		case ResultTableNodeTypeItemId: writer.String("ItemId"); break;
		case ResultTableNodeTypeTableId: writer.String("TableId"); break;
	}
}

ResultTableNodeType PlayFab::AdminModels::readResultTableNodeTypeFromValue(const rapidjson::Value& obj)
{
	std::string enumStr = obj.GetString();
	if(enumStr == "ItemId")
		return ResultTableNodeTypeItemId;
	else if(enumStr == "TableId")
		return ResultTableNodeTypeTableId;
	
	return ResultTableNodeTypeItemId;
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
	
	const Value::Member* ResultItemType_member = obj.FindMember("ResultItemType");
	if (ResultItemType_member != NULL) ResultItemType = readResultTableNodeTypeFromValue(ResultItemType_member->value);
	
	const Value::Member* ResultItem_member = obj.FindMember("ResultItem");
	if (ResultItem_member != NULL) ResultItem = ResultItem_member->value.GetString();
	
	const Value::Member* Weight_member = obj.FindMember("Weight");
	if (Weight_member != NULL) Weight = Weight_member->value.GetInt();
	
	
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
	
	const Value::Member* TableId_member = obj.FindMember("TableId");
	if (TableId_member != NULL) TableId = TableId_member->value.GetString();
	
	const Value::Member* Nodes_member = obj.FindMember("Nodes");
	if (Nodes_member != NULL) {
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

	
	if(!Tables.empty()) {
	writer.String("Tables");
	writer.StartObject();
	for (std::map<std::string, RandomResultTable>::iterator iter = Tables.begin(); iter != Tables.end(); ++iter) {
		writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
	}
	writer.EndObject();
	}
	
	
	writer.EndObject();
}

bool GetRandomResultTablesResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Tables_member = obj.FindMember("Tables");
	if (Tables_member != NULL) {
		for (Value::ConstMemberIterator iter = Tables_member->value.MemberBegin(); iter != Tables_member->value.MemberEnd(); ++iter) {
			Tables[iter->name.GetString()] = RandomResultTable(iter->value);
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
	
	const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL) BuildId = BuildId_member->value.GetString();
	
	
	return true;
}


GetServerBuildInfoResult::~GetServerBuildInfoResult()
{
	
}

void GetServerBuildInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
	
	writer.String("Active"); writer.Bool(Active);
	
	if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
	
	writer.String("Timestamp"); writeDatetime(Timestamp, writer);
	
	if(TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
	
	if(Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
	
	
	writer.EndObject();
}

bool GetServerBuildInfoResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL) BuildId = BuildId_member->value.GetString();
	
	const Value::Member* Active_member = obj.FindMember("Active");
	if (Active_member != NULL) Active = Active_member->value.GetBool();
	
	const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(memberList[i].GetString());
		}
	}
	
	const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL) Comment = Comment_member->value.GetString();
	
	const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL) Timestamp = readDatetime(Timestamp_member->value);
	
	const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL) TitleId = TitleId_member->value.GetString();
	
	const Value::Member* Status_member = obj.FindMember("Status");
	if (Status_member != NULL) Status = readGameBuildStatusFromValue(Status_member->value);
	
	
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
	
	const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL) BuildId = BuildId_member->value.GetString();
	
	
	return true;
}


GetServerBuildUploadURLResult::~GetServerBuildUploadURLResult()
{
	
}

void GetServerBuildUploadURLResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }
	
	
	writer.EndObject();
}

bool GetServerBuildUploadURLResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* URL_member = obj.FindMember("URL");
	if (URL_member != NULL) URL = URL_member->value.GetString();
	
	
	return true;
}


GetStoreItemsRequest::~GetStoreItemsRequest()
{
	
}

void GetStoreItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("StoreId"); writer.String(StoreId.c_str());
	
	
	writer.EndObject();
}

bool GetStoreItemsRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* StoreId_member = obj.FindMember("StoreId");
	if (StoreId_member != NULL) StoreId = StoreId_member->value.GetString();
	
	
	return true;
}


StoreItem::~StoreItem()
{
	
}

void StoreItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("ItemId"); writer.String(ItemId.c_str());
	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
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
	
	
	writer.EndObject();
}

bool StoreItem::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* ItemId_member = obj.FindMember("ItemId");
	if (ItemId_member != NULL) ItemId = ItemId_member->value.GetString();
	
	const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
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
	
	
	return true;
}


GetStoreItemsResult::~GetStoreItemsResult()
{
	
}

void GetStoreItemsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Store.empty()) {
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
	
	const Value::Member* Store_member = obj.FindMember("Store");
	if (Store_member != NULL) {
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


GetUserDataRequest::~GetUserDataRequest()
{
	
}

void GetUserDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
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


void PlayFab::AdminModels::writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
{
	switch(enumVal)
	{
		
		case UserDataPermissionPrivate: writer.String("Private"); break;
		case UserDataPermissionPublic: writer.String("Public"); break;
	}
}

UserDataPermission PlayFab::AdminModels::readUserDataPermissionFromValue(const rapidjson::Value& obj)
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
	
	if(RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Uint(RemainingUses); }
	
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
	if (RemainingUses_member != NULL) RemainingUses = RemainingUses_member->value.GetUint();
	
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


ItemGrant::~ItemGrant()
{
	
}

void ItemGrant::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
	
	writer.String("ItemId"); writer.String(ItemId.c_str());
	
	if(Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
	
	
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
	
	
	return true;
}


GrantItemsToUsersRequest::~GrantItemsToUsersRequest()
{
	
}

void GrantItemsToUsersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
	if(!ItemGrants.empty()) {
	writer.String("ItemGrants");
	writer.StartArray();
	for (std::list<ItemGrant>::iterator iter = ItemGrants.begin(); iter != ItemGrants.end(); iter++) {
		iter->writeJSON(writer);
	}
	writer.EndArray();
	 }
	
	
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

	
	if(!Builds.empty()) {
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
	
	const Value::Member* Builds_member = obj.FindMember("Builds");
	if (Builds_member != NULL) {
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

	
	if(!VirtualCurrencyIds.empty()) {
	writer.String("VirtualCurrencyIds");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = VirtualCurrencyIds.begin(); iter != VirtualCurrencyIds.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	
	writer.EndObject();
}

bool ListVirtualCurrencyTypesResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* VirtualCurrencyIds_member = obj.FindMember("VirtualCurrencyIds");
	if (VirtualCurrencyIds_member != NULL) {
		const rapidjson::Value& memberList = VirtualCurrencyIds_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			VirtualCurrencyIds.push_back(memberList[i].GetString());
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

	
	if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
	
	if(Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
	
	if(Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
	
	if(TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
	
	
	writer.EndObject();
}

bool LookupUserAccountInfoRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* Email_member = obj.FindMember("Email");
	if (Email_member != NULL) Email = Email_member->value.GetString();
	
	const Value::Member* Username_member = obj.FindMember("Username");
	if (Username_member != NULL) Username = Username_member->value.GetString();
	
	const Value::Member* TitleDisplayName_member = obj.FindMember("TitleDisplayName");
	if (TitleDisplayName_member != NULL) TitleDisplayName = TitleDisplayName_member->value.GetString();
	
	
	return true;
}


void PlayFab::AdminModels::writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
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
	}
}

UserOrigination PlayFab::AdminModels::readUserOriginationFromValue(const rapidjson::Value& obj)
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
	
	if(FacebookUsername.length() > 0) { writer.String("FacebookUsername"); writer.String(FacebookUsername.c_str()); }
	
	if(FacebookDisplayname.length() > 0) { writer.String("FacebookDisplayname"); writer.String(FacebookDisplayname.c_str()); }
	
	
	writer.EndObject();
}

bool UserFacebookInfo::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* FacebookId_member = obj.FindMember("FacebookId");
	if (FacebookId_member != NULL) FacebookId = FacebookId_member->value.GetString();
	
	const Value::Member* FacebookUsername_member = obj.FindMember("FacebookUsername");
	if (FacebookUsername_member != NULL) FacebookUsername = FacebookUsername_member->value.GetString();
	
	const Value::Member* FacebookDisplayname_member = obj.FindMember("FacebookDisplayname");
	if (FacebookDisplayname_member != NULL) FacebookDisplayname = FacebookDisplayname_member->value.GetString();
	
	
	return true;
}


void PlayFab::AdminModels::writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
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

TitleActivationStatus PlayFab::AdminModels::readTitleActivationStatusFromValue(const rapidjson::Value& obj)
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


LookupUserAccountInfoResult::~LookupUserAccountInfoResult()
{
	if(UserInfo != NULL) delete UserInfo;
	
}

void LookupUserAccountInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(UserInfo != NULL) { writer.String("UserInfo"); UserInfo->writeJSON(writer); }
	
	
	writer.EndObject();
}

bool LookupUserAccountInfoResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* UserInfo_member = obj.FindMember("UserInfo");
	if (UserInfo_member != NULL) UserInfo = new UserAccountInfo(UserInfo_member->value);
	
	
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
	
	const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
	if (BuildVersion_member != NULL) BuildVersion = BuildVersion_member->value.GetString();
	
	const Value::Member* GameModes_member = obj.FindMember("GameModes");
	if (GameModes_member != NULL) {
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
	
	if(Timestamp.notNull()) { writer.String("Timestamp"); writeDatetime(Timestamp, writer); }
	
	if(Active.notNull()) { writer.String("Active"); writer.Bool(Active); }
	
	if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
	
	
	writer.EndObject();
}

bool ModifyServerBuildRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL) BuildId = BuildId_member->value.GetString();
	
	const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL) Timestamp = readDatetime(Timestamp_member->value);
	
	const Value::Member* Active_member = obj.FindMember("Active");
	if (Active_member != NULL) Active = Active_member->value.GetBool();
	
	const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(memberList[i].GetString());
		}
	}
	
	const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL) Comment = Comment_member->value.GetString();
	
	
	return true;
}


ModifyServerBuildResult::~ModifyServerBuildResult()
{
	
}

void ModifyServerBuildResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
	
	writer.String("Active"); writer.Bool(Active);
	
	if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
	
	if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
	
	writer.String("Timestamp"); writeDatetime(Timestamp, writer);
	
	if(TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
	
	if(Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
	
	
	writer.EndObject();
}

bool ModifyServerBuildResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL) BuildId = BuildId_member->value.GetString();
	
	const Value::Member* Active_member = obj.FindMember("Active");
	if (Active_member != NULL) Active = Active_member->value.GetBool();
	
	const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(memberList[i].GetString());
		}
	}
	
	const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL) Comment = Comment_member->value.GetString();
	
	const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL) Timestamp = readDatetime(Timestamp_member->value);
	
	const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL) TitleId = TitleId_member->value.GetString();
	
	const Value::Member* Status_member = obj.FindMember("Status");
	if (Status_member != NULL) Status = readGameBuildStatusFromValue(Status_member->value);
	
	
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
	
	const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL) BuildId = BuildId_member->value.GetString();
	
	
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
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	
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


RevokeInventoryItemRequest::~RevokeInventoryItemRequest()
{
	
}

void RevokeInventoryItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
	
	writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
	
	
	writer.EndObject();
}

bool RevokeInventoryItemRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL) ItemInstanceId = ItemInstanceId_member->value.GetString();
	
	
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
	
	const Value::Member* Email_member = obj.FindMember("Email");
	if (Email_member != NULL) Email = Email_member->value.GetString();
	
	
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


SetTitleDataRequest::~SetTitleDataRequest()
{
	
}

void SetTitleDataRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("Key"); writer.String(Key.c_str());
	
	writer.String("Value"); writer.String(Value.c_str());
	
	
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


SetupPushNotificationRequest::~SetupPushNotificationRequest()
{
	
}

void SetupPushNotificationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	writer.String("Name"); writer.String(Name.c_str());
	
	writer.String("Platform"); writer.String(Platform.c_str());
	
	if(Key.length() > 0) { writer.String("Key"); writer.String(Key.c_str()); }
	
	writer.String("Credential"); writer.String(Credential.c_str());
	
	writer.String("OverwriteOldARN"); writer.Bool(OverwriteOldARN);
	
	
	writer.EndObject();
}

bool SetupPushNotificationRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* Name_member = obj.FindMember("Name");
	if (Name_member != NULL) Name = Name_member->value.GetString();
	
	const Value::Member* Platform_member = obj.FindMember("Platform");
	if (Platform_member != NULL) Platform = Platform_member->value.GetString();
	
	const Value::Member* Key_member = obj.FindMember("Key");
	if (Key_member != NULL) Key = Key_member->value.GetString();
	
	const Value::Member* Credential_member = obj.FindMember("Credential");
	if (Credential_member != NULL) Credential = Credential_member->value.GetString();
	
	const Value::Member* OverwriteOldARN_member = obj.FindMember("OverwriteOldARN");
	if (OverwriteOldARN_member != NULL) OverwriteOldARN = OverwriteOldARN_member->value.GetBool();
	
	
	return true;
}


SetupPushNotificationResult::~SetupPushNotificationResult()
{
	
}

void SetupPushNotificationResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(ARN.length() > 0) { writer.String("ARN"); writer.String(ARN.c_str()); }
	
	
	writer.EndObject();
}

bool SetupPushNotificationResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* ARN_member = obj.FindMember("ARN");
	if (ARN_member != NULL) ARN = ARN_member->value.GetString();
	
	
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


UpdateCatalogItemsRequest::~UpdateCatalogItemsRequest()
{
	
}

void UpdateCatalogItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
	
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

bool UpdateCatalogItemsRequest::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL) CatalogVersion = CatalogVersion_member->value.GetString();
	
	const Value::Member* Catalog_member = obj.FindMember("Catalog");
	if (Catalog_member != NULL) {
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


UpdateRandomResultTablesRequest::~UpdateRandomResultTablesRequest()
{
	
}

void UpdateRandomResultTablesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(!Tables.empty()) {
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
	
	const Value::Member* Tables_member = obj.FindMember("Tables");
	if (Tables_member != NULL) {
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

	
	writer.String("StoreId"); writer.String(StoreId.c_str());
	
	if(!Store.empty()) {
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
	
	const Value::Member* StoreId_member = obj.FindMember("StoreId");
	if (StoreId_member != NULL) StoreId = StoreId_member->value.GetString();
	
	const Value::Member* Store_member = obj.FindMember("Store");
	if (Store_member != NULL) {
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
	
	const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL) PlayFabId = PlayFabId_member->value.GetString();
	
	const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
	if (DisplayName_member != NULL) DisplayName = DisplayName_member->value.GetString();
	
	
	return true;
}


UpdateUserTitleDisplayNameResult::~UpdateUserTitleDisplayNameResult()
{
	
}

void UpdateUserTitleDisplayNameResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

	
	if(DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
	
	
	writer.EndObject();
}

bool UpdateUserTitleDisplayNameResult::readFromValue(const rapidjson::Value& obj)
{
	
	const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
	if (DisplayName_member != NULL) DisplayName = DisplayName_member->value.GetString();
	
	
	return true;
}




