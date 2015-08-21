
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
	if (Timestamp_member != NULL && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    
    const Value::Member* Title_member = obj.FindMember("Title");
	if (Title_member != NULL && !Title_member->value.IsNull()) Title = Title_member->value.GetString();
    
    const Value::Member* Body_member = obj.FindMember("Body");
	if (Body_member != NULL && !Body_member->value.IsNull()) Body = Body_member->value.GetString();
    
    
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
	if (NewsId_member != NULL && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();
    
    
    return true;
}


void PlayFab::AdminModels::writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
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
    
    if(CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
    
    if(ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
    
    if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writeRegionEnumJSON(*iter, writer);
	}
	writer.EndArray();
	 }
    
    if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    
    
    writer.EndObject();
}

bool AddServerBuildRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    
    const Value::Member* CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
	if (CommandLineTemplate_member != NULL && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
    
    const Value::Member* ExecutablePath_member = obj.FindMember("ExecutablePath");
	if (ExecutablePath_member != NULL && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
    
    const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(readRegionFromValue(memberList[i]));
		}
	}
    
    const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    
    const Value::Member* MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
	if (MaxGamesPerHost_member != NULL && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    
    
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

    
    if(BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    
    if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writeRegionEnumJSON(*iter, writer);
	}
	writer.EndArray();
	 }
    
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    
    if(CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
    
    if(ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
    
    if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    
    writer.String("Timestamp"); writeDatetime(Timestamp, writer);
    
    if(TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    
    if(Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
    
    
    writer.EndObject();
}

bool AddServerBuildResult::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    
    const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(readRegionFromValue(memberList[i]));
		}
	}
    
    const Value::Member* MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
	if (MaxGamesPerHost_member != NULL && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    
    const Value::Member* CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
	if (CommandLineTemplate_member != NULL && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
    
    const Value::Member* ExecutablePath_member = obj.FindMember("ExecutablePath");
	if (ExecutablePath_member != NULL && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
    
    const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    
    const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    
    const Value::Member* Status_member = obj.FindMember("Status");
	if (Status_member != NULL && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);
    
    
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


VirtualCurrencyData::~VirtualCurrencyData()
{
    
}

void VirtualCurrencyData::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    writer.String("CurrencyCode"); writer.String(CurrencyCode.c_str());
    
    if(DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    
    if(InitialDeposit.notNull()) { writer.String("InitialDeposit"); writer.Int(InitialDeposit); }
    
    if(RechargeRate.notNull()) { writer.String("RechargeRate"); writer.Int(RechargeRate); }
    
    if(RechargeMax.notNull()) { writer.String("RechargeMax"); writer.Int(RechargeMax); }
    
    
    writer.EndObject();
}

bool VirtualCurrencyData::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* CurrencyCode_member = obj.FindMember("CurrencyCode");
	if (CurrencyCode_member != NULL && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
    
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
	if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    
    const Value::Member* InitialDeposit_member = obj.FindMember("InitialDeposit");
	if (InitialDeposit_member != NULL && !InitialDeposit_member->value.IsNull()) InitialDeposit = InitialDeposit_member->value.GetInt();
    
    const Value::Member* RechargeRate_member = obj.FindMember("RechargeRate");
	if (RechargeRate_member != NULL && !RechargeRate_member->value.IsNull()) RechargeRate = RechargeRate_member->value.GetInt();
    
    const Value::Member* RechargeMax_member = obj.FindMember("RechargeMax");
	if (RechargeMax_member != NULL && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();
    
    
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
    
    const Value::Member* VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
	if (VirtualCurrencies_member != NULL) {
		const rapidjson::Value& memberList = VirtualCurrencies_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
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
    
    if(Consumable != NULL) { writer.String("Consumable"); Consumable->writeJSON(writer); }
    
    if(Container != NULL) { writer.String("Container"); Container->writeJSON(writer); }
    
    if(Bundle != NULL) { writer.String("Bundle"); Bundle->writeJSON(writer); }
    
    writer.String("CanBecomeCharacter"); writer.Bool(CanBecomeCharacter);
    
    writer.String("IsStackable"); writer.Bool(IsStackable);
    
    writer.String("IsTradable"); writer.Bool(IsTradable);
    
    
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
    
    const Value::Member* Filename_member = obj.FindMember("Filename");
	if (Filename_member != NULL && !Filename_member->value.IsNull()) Filename = Filename_member->value.GetString();
    
    const Value::Member* FileContents_member = obj.FindMember("FileContents");
	if (FileContents_member != NULL && !FileContents_member->value.IsNull()) FileContents = FileContents_member->value.GetString();
    
    
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
    
    const Value::Member* Version_member = obj.FindMember("Version");
	if (Version_member != NULL && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    
    const Value::Member* PublishedRevision_member = obj.FindMember("PublishedRevision");
	if (PublishedRevision_member != NULL && !PublishedRevision_member->value.IsNull()) PublishedRevision = PublishedRevision_member->value.GetInt();
    
    const Value::Member* LatestRevision_member = obj.FindMember("LatestRevision");
	if (LatestRevision_member != NULL && !LatestRevision_member->value.IsNull()) LatestRevision = LatestRevision_member->value.GetInt();
    
    
    return true;
}


ContentInfo::~ContentInfo()
{
    
}

void ContentInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(Key.length() > 0) { writer.String("Key"); writer.String(Key.c_str()); }
    
    writer.String("Size"); writer.Int64(Size);
    
    writer.String("LastModified"); writeDatetime(LastModified, writer);
    
    
    writer.EndObject();
}

bool ContentInfo::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* Key_member = obj.FindMember("Key");
	if (Key_member != NULL && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    
    const Value::Member* Size_member = obj.FindMember("Size");
	if (Size_member != NULL && !Size_member->value.IsNull()) Size = Size_member->value.GetInt64();
    
    const Value::Member* LastModified_member = obj.FindMember("LastModified");
	if (LastModified_member != NULL && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);
    
    
    return true;
}


void PlayFab::AdminModels::writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
{
    switch(enumVal)
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
    
    const Value::Member* Key_member = obj.FindMember("Key");
	if (Key_member != NULL && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    
    
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


GameModeInfo::~GameModeInfo()
{
    
}

void GameModeInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    writer.String("Gamemode"); writer.String(Gamemode.c_str());
    
    writer.String("MinPlayerCount"); writer.Uint(MinPlayerCount);
    
    writer.String("MaxPlayerCount"); writer.Uint(MaxPlayerCount);
    
    
    writer.EndObject();
}

bool GameModeInfo::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* Gamemode_member = obj.FindMember("Gamemode");
	if (Gamemode_member != NULL && !Gamemode_member->value.IsNull()) Gamemode = Gamemode_member->value.GetString();
    
    const Value::Member* MinPlayerCount_member = obj.FindMember("MinPlayerCount");
	if (MinPlayerCount_member != NULL && !MinPlayerCount_member->value.IsNull()) MinPlayerCount = MinPlayerCount_member->value.GetUint();
    
    const Value::Member* MaxPlayerCount_member = obj.FindMember("MaxPlayerCount");
	if (MaxPlayerCount_member != NULL && !MaxPlayerCount_member->value.IsNull()) MaxPlayerCount = MaxPlayerCount_member->value.GetUint();
    
    
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
	if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    
    
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


GetCloudScriptRevisionRequest::~GetCloudScriptRevisionRequest()
{
    
}

void GetCloudScriptRevisionRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(Version.notNull()) { writer.String("Version"); writer.Int(Version); }
    
    if(Revision.notNull()) { writer.String("Revision"); writer.Int(Revision); }
    
    
    writer.EndObject();
}

bool GetCloudScriptRevisionRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* Version_member = obj.FindMember("Version");
	if (Version_member != NULL && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    
    const Value::Member* Revision_member = obj.FindMember("Revision");
	if (Revision_member != NULL && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
    
    
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
    
    if(!Files.empty()) {
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
    
    const Value::Member* Version_member = obj.FindMember("Version");
	if (Version_member != NULL && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    
    const Value::Member* Revision_member = obj.FindMember("Revision");
	if (Revision_member != NULL && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
    
    const Value::Member* CreatedAt_member = obj.FindMember("CreatedAt");
	if (CreatedAt_member != NULL && !CreatedAt_member->value.IsNull()) CreatedAt = readDatetime(CreatedAt_member->value);
    
    const Value::Member* Files_member = obj.FindMember("Files");
	if (Files_member != NULL) {
		const rapidjson::Value& memberList = Files_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			Files.push_back(CloudScriptFile(memberList[i]));
		}
	}
    
    const Value::Member* IsPublished_member = obj.FindMember("IsPublished");
	if (IsPublished_member != NULL && !IsPublished_member->value.IsNull()) IsPublished = IsPublished_member->value.GetBool();
    
    
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

    
    if(!Versions.empty()) {
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
    
    const Value::Member* Versions_member = obj.FindMember("Versions");
	if (Versions_member != NULL) {
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

    
    if(Prefix.length() > 0) { writer.String("Prefix"); writer.String(Prefix.c_str()); }
    
    
    writer.EndObject();
}

bool GetContentListRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* Prefix_member = obj.FindMember("Prefix");
	if (Prefix_member != NULL && !Prefix_member->value.IsNull()) Prefix = Prefix_member->value.GetString();
    
    
    return true;
}


GetContentListResult::~GetContentListResult()
{
    
}

void GetContentListResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    writer.String("ItemCount"); writer.Int64(ItemCount);
    
    writer.String("TotalSize"); writer.Int64(TotalSize);
    
    if(!Contents.empty()) {
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
    
    const Value::Member* ItemCount_member = obj.FindMember("ItemCount");
	if (ItemCount_member != NULL && !ItemCount_member->value.IsNull()) ItemCount = ItemCount_member->value.GetInt64();
    
    const Value::Member* TotalSize_member = obj.FindMember("TotalSize");
	if (TotalSize_member != NULL && !TotalSize_member->value.IsNull()) TotalSize = TotalSize_member->value.GetInt64();
    
    const Value::Member* Contents_member = obj.FindMember("Contents");
	if (Contents_member != NULL) {
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
    
    if(ContentType.length() > 0) { writer.String("ContentType"); writer.String(ContentType.c_str()); }
    
    
    writer.EndObject();
}

bool GetContentUploadUrlRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* Key_member = obj.FindMember("Key");
	if (Key_member != NULL && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    
    const Value::Member* ContentType_member = obj.FindMember("ContentType");
	if (ContentType_member != NULL && !ContentType_member->value.IsNull()) ContentType = ContentType_member->value.GetString();
    
    
    return true;
}


GetContentUploadUrlResult::~GetContentUploadUrlResult()
{
    
}

void GetContentUploadUrlResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(URL.length() > 0) { writer.String("URL"); writer.String(URL.c_str()); }
    
    
    writer.EndObject();
}

bool GetContentUploadUrlResult::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* URL_member = obj.FindMember("URL");
	if (URL_member != NULL && !URL_member->value.IsNull()) URL = URL_member->value.GetString();
    
    
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
    
    const Value::Member* ReportName_member = obj.FindMember("ReportName");
	if (ReportName_member != NULL && !ReportName_member->value.IsNull()) ReportName = ReportName_member->value.GetString();
    
    const Value::Member* Year_member = obj.FindMember("Year");
	if (Year_member != NULL && !Year_member->value.IsNull()) Year = Year_member->value.GetInt();
    
    const Value::Member* Month_member = obj.FindMember("Month");
	if (Month_member != NULL && !Month_member->value.IsNull()) Month = Month_member->value.GetInt();
    
    const Value::Member* Day_member = obj.FindMember("Day");
	if (Day_member != NULL && !Day_member->value.IsNull()) Day = Day_member->value.GetInt();
    
    
    return true;
}


GetDataReportResult::~GetDataReportResult()
{
    
}

void GetDataReportResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(DownloadUrl.length() > 0) { writer.String("DownloadUrl"); writer.String(DownloadUrl.c_str()); }
    
    
    writer.EndObject();
}

bool GetDataReportResult::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* DownloadUrl_member = obj.FindMember("DownloadUrl");
	if (DownloadUrl_member != NULL && !DownloadUrl_member->value.IsNull()) DownloadUrl = DownloadUrl_member->value.GetString();
    
    
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
	if (LobbyId_member != NULL && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    
    
    return true;
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
    
    if(pfRegion.notNull()) { writer.String("Region"); writeRegionEnumJSON(pfRegion, writer); }
    
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
	if (LobbyId_member != NULL && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    
    const Value::Member* StartTime_member = obj.FindMember("StartTime");
	if (StartTime_member != NULL && !StartTime_member->value.IsNull()) StartTime = readDatetime(StartTime_member->value);
    
    const Value::Member* EndTime_member = obj.FindMember("EndTime");
	if (EndTime_member != NULL && !EndTime_member->value.IsNull()) EndTime = readDatetime(EndTime_member->value);
    
    const Value::Member* Mode_member = obj.FindMember("Mode");
	if (Mode_member != NULL && !Mode_member->value.IsNull()) Mode = Mode_member->value.GetString();
    
    const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
	if (BuildVersion_member != NULL && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    
    const Value::Member* Region_member = obj.FindMember("Region");
	if (Region_member != NULL && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    
    const Value::Member* Players_member = obj.FindMember("Players");
	if (Players_member != NULL) {
		const rapidjson::Value& memberList = Players_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			Players.push_back(memberList[i].GetString());
		}
	}
    
    const Value::Member* ServerAddress_member = obj.FindMember("ServerAddress");
	if (ServerAddress_member != NULL && !ServerAddress_member->value.IsNull()) ServerAddress = ServerAddress_member->value.GetString();
    
    const Value::Member* ServerPort_member = obj.FindMember("ServerPort");
	if (ServerPort_member != NULL && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetUint();
    
    
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
	if (BuildVersion_member != NULL && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    
    
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


GetRandomResultTablesRequest::~GetRandomResultTablesRequest()
{
    
}

void GetRandomResultTablesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    
    
    writer.EndObject();
}

bool GetRandomResultTablesRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    
    
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
    
    const Value::Member* ResultItemType_member = obj.FindMember("ResultItemType");
	if (ResultItemType_member != NULL && !ResultItemType_member->value.IsNull()) ResultItemType = readResultTableNodeTypeFromValue(ResultItemType_member->value);
    
    const Value::Member* ResultItem_member = obj.FindMember("ResultItem");
	if (ResultItem_member != NULL && !ResultItem_member->value.IsNull()) ResultItem = ResultItem_member->value.GetString();
    
    const Value::Member* Weight_member = obj.FindMember("Weight");
	if (Weight_member != NULL && !Weight_member->value.IsNull()) Weight = Weight_member->value.GetInt();
    
    
    return true;
}


RandomResultTableListing::~RandomResultTableListing()
{
    
}

void RandomResultTableListing::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    
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
    
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    
    const Value::Member* TableId_member = obj.FindMember("TableId");
	if (TableId_member != NULL && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
    
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
	for (std::map<std::string, RandomResultTableListing>::iterator iter = Tables.begin(); iter != Tables.end(); ++iter) {
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
    
    const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    
    
    return true;
}


GetServerBuildInfoResult::~GetServerBuildInfoResult()
{
    
}

void GetServerBuildInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    
    if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writeRegionEnumJSON(*iter, writer);
	}
	writer.EndArray();
	 }
    
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    
    if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    
    writer.String("Timestamp"); writeDatetime(Timestamp, writer);
    
    if(TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    
    if(Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
    
    if(ErrorMessage.length() > 0) { writer.String("ErrorMessage"); writer.String(ErrorMessage.c_str()); }
    
    
    writer.EndObject();
}

bool GetServerBuildInfoResult::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    
    const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(readRegionFromValue(memberList[i]));
		}
	}
    
    const Value::Member* MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
	if (MaxGamesPerHost_member != NULL && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    
    const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    
    const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    
    const Value::Member* Status_member = obj.FindMember("Status");
	if (Status_member != NULL && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);
    
    const Value::Member* ErrorMessage_member = obj.FindMember("ErrorMessage");
	if (ErrorMessage_member != NULL && !ErrorMessage_member->value.IsNull()) ErrorMessage = ErrorMessage_member->value.GetString();
    
    
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
	if (BuildId_member != NULL && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    
    
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
	if (URL_member != NULL && !URL_member->value.IsNull()) URL = URL_member->value.GetString();
    
    
    return true;
}


GetStoreItemsRequest::~GetStoreItemsRequest()
{
    
}

void GetStoreItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    
    writer.String("StoreId"); writer.String(StoreId.c_str());
    
    
    writer.EndObject();
}

bool GetStoreItemsRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    
    const Value::Member* StoreId_member = obj.FindMember("StoreId");
	if (StoreId_member != NULL && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
    
    
    return true;
}


StoreItem::~StoreItem()
{
    
}

void StoreItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    writer.String("ItemId"); writer.String(ItemId.c_str());
    
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
	if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    
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

    
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    
    if(!Keys.empty()) {
	writer.String("Keys");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
    
    if(IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Int(IfChangedFromDataVersion); }
    
    
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

    
    if(Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
    
    writer.String("LastUpdated"); writeDatetime(LastUpdated, writer);
    
    if(Permission.notNull()) { writer.String("Permission"); writeUserDataPermissionEnumJSON(Permission, writer); }
    
    
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


GetUserDataResult::~GetUserDataResult()
{
    
}

void GetUserDataResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    
    writer.String("DataVersion"); writer.Uint(DataVersion);
    
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
    
    if(UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
    
    if(Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    
    if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    
    if(BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
    
    if(DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    
    if(UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
    
    writer.String("UnitPrice"); writer.Uint(UnitPrice);
    
    if(!BundleContents.empty()) {
	writer.String("BundleContents");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
    
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
    
    if(!VirtualCurrencyRechargeTimes.empty()) {
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


GrantedItemInstance::~GrantedItemInstance()
{
    
}

void GrantedItemInstance::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    
    if(CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    
    writer.String("Result"); writer.Bool(Result);
    
    if(ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
    
    if(ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
    
    if(ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
    
    if(PurchaseDate.notNull()) { writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer); }
    
    if(Expiration.notNull()) { writer.String("Expiration"); writeDatetime(Expiration, writer); }
    
    if(RemainingUses.notNull()) { writer.String("RemainingUses"); writer.Int(RemainingUses); }
    
    if(UsesIncrementedBy.notNull()) { writer.String("UsesIncrementedBy"); writer.Int(UsesIncrementedBy); }
    
    if(Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    
    if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    
    if(BundleParent.length() > 0) { writer.String("BundleParent"); writer.String(BundleParent.c_str()); }
    
    if(DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    
    if(UnitCurrency.length() > 0) { writer.String("UnitCurrency"); writer.String(UnitCurrency.c_str()); }
    
    writer.String("UnitPrice"); writer.Uint(UnitPrice);
    
    if(!BundleContents.empty()) {
	writer.String("BundleContents");
	writer.StartArray();
	for (std::list<std::string>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
		writer.String(iter->c_str());
	}
	writer.EndArray();
	 }
    
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

    
    if(!ItemGrantResults.empty()) {
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

    
    if(!VirtualCurrencies.empty()) {
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
    
    const Value::Member* VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
	if (VirtualCurrencies_member != NULL) {
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

    
    if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    
    if(Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    
    if(Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    
    if(TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
    
    
    writer.EndObject();
}

bool LookupUserAccountInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
    const Value::Member* Email_member = obj.FindMember("Email");
	if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    
    const Value::Member* Username_member = obj.FindMember("Username");
	if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    
    const Value::Member* TitleDisplayName_member = obj.FindMember("TitleDisplayName");
	if (TitleDisplayName_member != NULL && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
    
    
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
        case UserOriginationPSN: writer.String("PSN"); break;
        case UserOriginationGameCenter: writer.String("GameCenter"); break;
        case UserOriginationCustomId: writer.String("CustomId"); break;
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

    
    if(Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    
    
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

    
    if(FacebookId.length() > 0) { writer.String("FacebookId"); writer.String(FacebookId.c_str()); }
    
    if(FullName.length() > 0) { writer.String("FullName"); writer.String(FullName.c_str()); }
    
    
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

    
    if(SteamId.length() > 0) { writer.String("SteamId"); writer.String(SteamId.c_str()); }
    
    if(SteamCountry.length() > 0) { writer.String("SteamCountry"); writer.String(SteamCountry.c_str()); }
    
    if(SteamCurrency.notNull()) { writer.String("SteamCurrency"); writeCurrencyEnumJSON(SteamCurrency, writer); }
    
    if(SteamActivationStatus.notNull()) { writer.String("SteamActivationStatus"); writeTitleActivationStatusEnumJSON(SteamActivationStatus, writer); }
    
    
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

    
    if(GameCenterId.length() > 0) { writer.String("GameCenterId"); writer.String(GameCenterId.c_str()); }
    
    
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
	if (UserInfo_member != NULL && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);
    
    
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
	if (BuildVersion_member != NULL && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    
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
    
    if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writeRegionEnumJSON(*iter, writer);
	}
	writer.EndArray();
	 }
    
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    
    if(CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
    
    if(ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
    
    if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    
    
    writer.EndObject();
}

bool ModifyServerBuildRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    
    const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    
    const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(readRegionFromValue(memberList[i]));
		}
	}
    
    const Value::Member* MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
	if (MaxGamesPerHost_member != NULL && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    
    const Value::Member* CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
	if (CommandLineTemplate_member != NULL && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
    
    const Value::Member* ExecutablePath_member = obj.FindMember("ExecutablePath");
	if (ExecutablePath_member != NULL && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
    
    const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    
    
    return true;
}


ModifyServerBuildResult::~ModifyServerBuildResult()
{
    
}

void ModifyServerBuildResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    
    if(!ActiveRegions.empty()) {
	writer.String("ActiveRegions");
	writer.StartArray();
	for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
		writeRegionEnumJSON(*iter, writer);
	}
	writer.EndArray();
	 }
    
    writer.String("MaxGamesPerHost"); writer.Int(MaxGamesPerHost);
    
    if(CommandLineTemplate.length() > 0) { writer.String("CommandLineTemplate"); writer.String(CommandLineTemplate.c_str()); }
    
    if(ExecutablePath.length() > 0) { writer.String("ExecutablePath"); writer.String(ExecutablePath.c_str()); }
    
    if(Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }
    
    writer.String("Timestamp"); writeDatetime(Timestamp, writer);
    
    if(TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }
    
    if(Status.notNull()) { writer.String("Status"); writeGameBuildStatusEnumJSON(Status, writer); }
    
    
    writer.EndObject();
}

bool ModifyServerBuildResult::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* BuildId_member = obj.FindMember("BuildId");
	if (BuildId_member != NULL && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    
    const Value::Member* ActiveRegions_member = obj.FindMember("ActiveRegions");
	if (ActiveRegions_member != NULL) {
		const rapidjson::Value& memberList = ActiveRegions_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			ActiveRegions.push_back(readRegionFromValue(memberList[i]));
		}
	}
    
    const Value::Member* MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
	if (MaxGamesPerHost_member != NULL && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
    
    const Value::Member* CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
	if (CommandLineTemplate_member != NULL && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
    
    const Value::Member* ExecutablePath_member = obj.FindMember("ExecutablePath");
	if (ExecutablePath_member != NULL && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
    
    const Value::Member* Comment_member = obj.FindMember("Comment");
	if (Comment_member != NULL && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
    
    const Value::Member* Timestamp_member = obj.FindMember("Timestamp");
	if (Timestamp_member != NULL && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
    
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
	if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    
    const Value::Member* Status_member = obj.FindMember("Status");
	if (Status_member != NULL && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);
    
    
    return true;
}


ModifyUserVirtualCurrencyResult::~ModifyUserVirtualCurrencyResult()
{
    
}

void ModifyUserVirtualCurrencyResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    
    if(VirtualCurrency.length() > 0) { writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str()); }
    
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
	if (TableId_member != NULL && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
    
    const Value::Member* Nodes_member = obj.FindMember("Nodes");
	if (Nodes_member != NULL) {
		const rapidjson::Value& memberList = Nodes_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			Nodes.push_back(ResultTableNode(memberList[i]));
		}
	}
    
    
    return true;
}


RefundPurchaseRequest::~RefundPurchaseRequest()
{
    
}

void RefundPurchaseRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    
    writer.String("OrderId"); writer.String(OrderId.c_str());
    
    if(Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
    
    
    writer.EndObject();
}

bool RefundPurchaseRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
	if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
    
    const Value::Member* Reason_member = obj.FindMember("Reason");
	if (Reason_member != NULL && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
    
    
    return true;
}


RefundPurchaseResponse::~RefundPurchaseResponse()
{
    
}

void RefundPurchaseResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(PurchaseStatus.length() > 0) { writer.String("PurchaseStatus"); writer.String(PurchaseStatus.c_str()); }
    
    
    writer.EndObject();
}

bool RefundPurchaseResponse::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* PurchaseStatus_member = obj.FindMember("PurchaseStatus");
	if (PurchaseStatus_member != NULL && !PurchaseStatus_member->value.IsNull()) PurchaseStatus = PurchaseStatus_member->value.GetString();
    
    
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
	if (BuildId_member != NULL && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    
    
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
    
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
	if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    
    
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
    
    const Value::Member* Username_member = obj.FindMember("Username");
	if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    
    const Value::Member* Password_member = obj.FindMember("Password");
	if (Password_member != NULL && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
    
    
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
    
    const Value::Member* Users_member = obj.FindMember("Users");
	if (Users_member != NULL) {
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
    
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
    
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


void PlayFab::AdminModels::writeResolutionOutcomeEnumJSON(ResolutionOutcome enumVal, PFStringJsonWriter& writer)
{
    switch(enumVal)
    {
        
        case ResolutionOutcomeRevoke: writer.String("Revoke"); break;
        case ResolutionOutcomeReinstate: writer.String("Reinstate"); break;
        case ResolutionOutcomeManual: writer.String("Manual"); break;
    }
}

ResolutionOutcome PlayFab::AdminModels::readResolutionOutcomeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, ResolutionOutcome> _ResolutionOutcomeMap;
    if (_ResolutionOutcomeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _ResolutionOutcomeMap["Revoke"] = ResolutionOutcomeRevoke;
        _ResolutionOutcomeMap["Reinstate"] = ResolutionOutcomeReinstate;
        _ResolutionOutcomeMap["Manual"] = ResolutionOutcomeManual;

    }

    auto output = _ResolutionOutcomeMap.find(obj.GetString());
    if (output != _ResolutionOutcomeMap.end())
        return output->second;

    return ResolutionOutcomeRevoke; // Basically critical fail
}


ResolvePurchaseDisputeRequest::~ResolvePurchaseDisputeRequest()
{
    
}

void ResolvePurchaseDisputeRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    writer.String("PlayFabId"); writer.String(PlayFabId.c_str());
    
    writer.String("OrderId"); writer.String(OrderId.c_str());
    
    if(Reason.length() > 0) { writer.String("Reason"); writer.String(Reason.c_str()); }
    
    writer.String("Outcome"); writeResolutionOutcomeEnumJSON(Outcome, writer);
    
    
    writer.EndObject();
}

bool ResolvePurchaseDisputeRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
	if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
    
    const Value::Member* Reason_member = obj.FindMember("Reason");
	if (Reason_member != NULL && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
    
    const Value::Member* Outcome_member = obj.FindMember("Outcome");
	if (Outcome_member != NULL && !Outcome_member->value.IsNull()) Outcome = readResolutionOutcomeFromValue(Outcome_member->value);
    
    
    return true;
}


ResolvePurchaseDisputeResponse::~ResolvePurchaseDisputeResponse()
{
    
}

void ResolvePurchaseDisputeResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(PurchaseStatus.length() > 0) { writer.String("PurchaseStatus"); writer.String(PurchaseStatus.c_str()); }
    
    
    writer.EndObject();
}

bool ResolvePurchaseDisputeResponse::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* PurchaseStatus_member = obj.FindMember("PurchaseStatus");
	if (PurchaseStatus_member != NULL && !PurchaseStatus_member->value.IsNull()) PurchaseStatus = PurchaseStatus_member->value.GetString();
    
    
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
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
	if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    
    
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
	if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    
    
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
    
    const Value::Member* Version_member = obj.FindMember("Version");
	if (Version_member != NULL && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    
    const Value::Member* Revision_member = obj.FindMember("Revision");
	if (Revision_member != NULL && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
    
    
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
    
    if(Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
    
    
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
    
    if(Value.length() > 0) { writer.String("Value"); writer.String(Value.c_str()); }
    
    
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
	if (Name_member != NULL && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    
    const Value::Member* Platform_member = obj.FindMember("Platform");
	if (Platform_member != NULL && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();
    
    const Value::Member* Key_member = obj.FindMember("Key");
	if (Key_member != NULL && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
    
    const Value::Member* Credential_member = obj.FindMember("Credential");
	if (Credential_member != NULL && !Credential_member->value.IsNull()) Credential = Credential_member->value.GetString();
    
    const Value::Member* OverwriteOldARN_member = obj.FindMember("OverwriteOldARN");
	if (OverwriteOldARN_member != NULL && !OverwriteOldARN_member->value.IsNull()) OverwriteOldARN = OverwriteOldARN_member->value.GetBool();
    
    
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
	if (ARN_member != NULL && !ARN_member->value.IsNull()) ARN = ARN_member->value.GetString();
    
    
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
	if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    
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


UpdateCloudScriptRequest::~UpdateCloudScriptRequest()
{
    
}

void UpdateCloudScriptRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(Version.notNull()) { writer.String("Version"); writer.Int(Version); }
    
    writer.String("Files");
	writer.StartArray();
	for (std::list<CloudScriptFile>::iterator iter = Files.begin(); iter != Files.end(); iter++) {
		iter->writeJSON(writer);
	}
	writer.EndArray();
	
    
    
    writer.EndObject();
}

bool UpdateCloudScriptRequest::readFromValue(const rapidjson::Value& obj)
{
    
    const Value::Member* Version_member = obj.FindMember("Version");
	if (Version_member != NULL && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    
    const Value::Member* Files_member = obj.FindMember("Files");
	if (Files_member != NULL) {
		const rapidjson::Value& memberList = Files_member->value;
		for (SizeType i = 0; i < memberList.Size(); i++) {
			Files.push_back(CloudScriptFile(memberList[i]));
		}
	}
    
    
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
    
    const Value::Member* Version_member = obj.FindMember("Version");
	if (Version_member != NULL && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    
    const Value::Member* Revision_member = obj.FindMember("Revision");
	if (Revision_member != NULL && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
    
    
    return true;
}


UpdateRandomResultTablesRequest::~UpdateRandomResultTablesRequest()
{
    
}

void UpdateRandomResultTablesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    
    if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    
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
    
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    
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

    
    if(CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    
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
    
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
	if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    
    const Value::Member* StoreId_member = obj.FindMember("StoreId");
	if (StoreId_member != NULL && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
    
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
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
    const Value::Member* Data_member = obj.FindMember("Data");
	if (Data_member != NULL) {
		for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
			Data[iter->name.GetString()] = iter->value.GetString();
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
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
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
	if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
	if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    
    
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
	if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    
    
    return true;
}




