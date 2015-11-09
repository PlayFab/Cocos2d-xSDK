#include "playfab/PlayFabClientDataModels.h"

using namespace PlayFab;
using namespace PlayFab::ClientModels;
using namespace rapidjson;


AcceptTradeRequest::~AcceptTradeRequest()
{

}

void AcceptTradeRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("OfferingPlayerId"); writer.String(OfferingPlayerId.c_str());
    writer.String("TradeId"); writer.String(TradeId.c_str());
    if (!AcceptedInventoryInstanceIds.empty()) {
    writer.String("AcceptedInventoryInstanceIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = AcceptedInventoryInstanceIds.begin(); iter != AcceptedInventoryInstanceIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool AcceptTradeRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
    if (OfferingPlayerId_member != NULL && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
    const Value::Member* TradeId_member = obj.FindMember("TradeId");
    if (TradeId_member != NULL && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();
    const Value::Member* AcceptedInventoryInstanceIds_member = obj.FindMember("AcceptedInventoryInstanceIds");
    if (AcceptedInventoryInstanceIds_member != NULL) {
        const rapidjson::Value& memberList = AcceptedInventoryInstanceIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AcceptedInventoryInstanceIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}
void PlayFab::ClientModels::writeTradeStatusEnumJSON(TradeStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case TradeStatusInvalid: writer.String("Invalid"); break;
    case TradeStatusOpening: writer.String("Opening"); break;
    case TradeStatusOpen: writer.String("Open"); break;
    case TradeStatusAccepting: writer.String("Accepting"); break;
    case TradeStatusAccepted: writer.String("Accepted"); break;
    case TradeStatusFilled: writer.String("Filled"); break;
    case TradeStatusCancelled: writer.String("Cancelled"); break;

    }
}

TradeStatus PlayFab::ClientModels::readTradeStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, TradeStatus> _TradeStatusMap;
    if (_TradeStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _TradeStatusMap["Invalid"] = TradeStatusInvalid;
        _TradeStatusMap["Opening"] = TradeStatusOpening;
        _TradeStatusMap["Open"] = TradeStatusOpen;
        _TradeStatusMap["Accepting"] = TradeStatusAccepting;
        _TradeStatusMap["Accepted"] = TradeStatusAccepted;
        _TradeStatusMap["Filled"] = TradeStatusFilled;
        _TradeStatusMap["Cancelled"] = TradeStatusCancelled;

    }

    auto output = _TradeStatusMap.find(obj.GetString());
    if (output != _TradeStatusMap.end())
        return output->second;

    return TradeStatusInvalid; // Basically critical fail
}

TradeInfo::~TradeInfo()
{

}

void TradeInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Status.notNull()) { writer.String("Status"); writeTradeStatusEnumJSON(Status, writer); }
    if (TradeId.length() > 0) { writer.String("TradeId"); writer.String(TradeId.c_str()); }
    if (OfferingPlayerId.length() > 0) { writer.String("OfferingPlayerId"); writer.String(OfferingPlayerId.c_str()); }
    if (!OfferedInventoryInstanceIds.empty()) {
    writer.String("OfferedInventoryInstanceIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = OfferedInventoryInstanceIds.begin(); iter != OfferedInventoryInstanceIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!OfferedCatalogItemIds.empty()) {
    writer.String("OfferedCatalogItemIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = OfferedCatalogItemIds.begin(); iter != OfferedCatalogItemIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!RequestedCatalogItemIds.empty()) {
    writer.String("RequestedCatalogItemIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = RequestedCatalogItemIds.begin(); iter != RequestedCatalogItemIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!AllowedPlayerIds.empty()) {
    writer.String("AllowedPlayerIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = AllowedPlayerIds.begin(); iter != AllowedPlayerIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (AcceptedPlayerId.length() > 0) { writer.String("AcceptedPlayerId"); writer.String(AcceptedPlayerId.c_str()); }
    if (!AcceptedInventoryInstanceIds.empty()) {
    writer.String("AcceptedInventoryInstanceIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = AcceptedInventoryInstanceIds.begin(); iter != AcceptedInventoryInstanceIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (OpenedAt.notNull()) { writer.String("OpenedAt"); writeDatetime(OpenedAt, writer); }
    if (FilledAt.notNull()) { writer.String("FilledAt"); writeDatetime(FilledAt, writer); }
    if (CancelledAt.notNull()) { writer.String("CancelledAt"); writeDatetime(CancelledAt, writer); }
    if (InvalidatedAt.notNull()) { writer.String("InvalidatedAt"); writeDatetime(InvalidatedAt, writer); }

    writer.EndObject();
}

bool TradeInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Status_member = obj.FindMember("Status");
    if (Status_member != NULL && !Status_member->value.IsNull()) Status = readTradeStatusFromValue(Status_member->value);
    const Value::Member* TradeId_member = obj.FindMember("TradeId");
    if (TradeId_member != NULL && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();
    const Value::Member* OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
    if (OfferingPlayerId_member != NULL && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
    const Value::Member* OfferedInventoryInstanceIds_member = obj.FindMember("OfferedInventoryInstanceIds");
    if (OfferedInventoryInstanceIds_member != NULL) {
        const rapidjson::Value& memberList = OfferedInventoryInstanceIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            OfferedInventoryInstanceIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* OfferedCatalogItemIds_member = obj.FindMember("OfferedCatalogItemIds");
    if (OfferedCatalogItemIds_member != NULL) {
        const rapidjson::Value& memberList = OfferedCatalogItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            OfferedCatalogItemIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* RequestedCatalogItemIds_member = obj.FindMember("RequestedCatalogItemIds");
    if (RequestedCatalogItemIds_member != NULL) {
        const rapidjson::Value& memberList = RequestedCatalogItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            RequestedCatalogItemIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* AllowedPlayerIds_member = obj.FindMember("AllowedPlayerIds");
    if (AllowedPlayerIds_member != NULL) {
        const rapidjson::Value& memberList = AllowedPlayerIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AllowedPlayerIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* AcceptedPlayerId_member = obj.FindMember("AcceptedPlayerId");
    if (AcceptedPlayerId_member != NULL && !AcceptedPlayerId_member->value.IsNull()) AcceptedPlayerId = AcceptedPlayerId_member->value.GetString();
    const Value::Member* AcceptedInventoryInstanceIds_member = obj.FindMember("AcceptedInventoryInstanceIds");
    if (AcceptedInventoryInstanceIds_member != NULL) {
        const rapidjson::Value& memberList = AcceptedInventoryInstanceIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AcceptedInventoryInstanceIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* OpenedAt_member = obj.FindMember("OpenedAt");
    if (OpenedAt_member != NULL && !OpenedAt_member->value.IsNull()) OpenedAt = readDatetime(OpenedAt_member->value);
    const Value::Member* FilledAt_member = obj.FindMember("FilledAt");
    if (FilledAt_member != NULL && !FilledAt_member->value.IsNull()) FilledAt = readDatetime(FilledAt_member->value);
    const Value::Member* CancelledAt_member = obj.FindMember("CancelledAt");
    if (CancelledAt_member != NULL && !CancelledAt_member->value.IsNull()) CancelledAt = readDatetime(CancelledAt_member->value);
    const Value::Member* InvalidatedAt_member = obj.FindMember("InvalidatedAt");
    if (InvalidatedAt_member != NULL && !InvalidatedAt_member->value.IsNull()) InvalidatedAt = readDatetime(InvalidatedAt_member->value);

    return true;
}

AcceptTradeResponse::~AcceptTradeResponse()
{
    if (Trade != NULL) delete Trade;

}

void AcceptTradeResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Trade != NULL) { writer.String("Trade"); Trade->writeJSON(writer); }

    writer.EndObject();
}

bool AcceptTradeResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Trade_member = obj.FindMember("Trade");
    if (Trade_member != NULL && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

    return true;
}

AddFriendRequest::~AddFriendRequest()
{

}

void AddFriendRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (FriendPlayFabId.length() > 0) { writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str()); }
    if (FriendUsername.length() > 0) { writer.String("FriendUsername"); writer.String(FriendUsername.c_str()); }
    if (FriendEmail.length() > 0) { writer.String("FriendEmail"); writer.String(FriendEmail.c_str()); }
    if (FriendTitleDisplayName.length() > 0) { writer.String("FriendTitleDisplayName"); writer.String(FriendTitleDisplayName.c_str()); }

    writer.EndObject();
}

bool AddFriendRequest::readFromValue(const rapidjson::Value& obj)
{
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

AddFriendResult::~AddFriendResult()
{

}

void AddFriendResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Created"); writer.Bool(Created);

    writer.EndObject();
}

bool AddFriendResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Created_member = obj.FindMember("Created");
    if (Created_member != NULL && !Created_member->value.IsNull()) Created = Created_member->value.GetBool();

    return true;
}

AddSharedGroupMembersRequest::~AddSharedGroupMembersRequest()
{

}

void AddSharedGroupMembersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
    writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

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

AddUsernamePasswordRequest::~AddUsernamePasswordRequest()
{

}

void AddUsernamePasswordRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Username"); writer.String(Username.c_str());
    writer.String("Email"); writer.String(Email.c_str());
    writer.String("Password"); writer.String(Password.c_str());

    writer.EndObject();
}

bool AddUsernamePasswordRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::Member* Email_member = obj.FindMember("Email");
    if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::Member* Password_member = obj.FindMember("Password");
    if (Password_member != NULL && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

    return true;
}

AddUsernamePasswordResult::~AddUsernamePasswordResult()
{

}

void AddUsernamePasswordResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }

    writer.EndObject();
}

bool AddUsernamePasswordResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

    return true;
}

AddUserVirtualCurrencyRequest::~AddUserVirtualCurrencyRequest()
{

}

void AddUserVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.String("Amount"); writer.Int(Amount);

    writer.EndObject();
}

bool AddUserVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* Amount_member = obj.FindMember("Amount");
    if (Amount_member != NULL && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

    return true;
}

AndroidDevicePushNotificationRegistrationRequest::~AndroidDevicePushNotificationRegistrationRequest()
{

}

void AndroidDevicePushNotificationRegistrationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("DeviceToken"); writer.String(DeviceToken.c_str());
    if (SendPushNotificationConfirmation.notNull()) { writer.String("SendPushNotificationConfirmation"); writer.Bool(SendPushNotificationConfirmation); }
    if (ConfirmationMessege.length() > 0) { writer.String("ConfirmationMessege"); writer.String(ConfirmationMessege.c_str()); }

    writer.EndObject();
}

bool AndroidDevicePushNotificationRegistrationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* DeviceToken_member = obj.FindMember("DeviceToken");
    if (DeviceToken_member != NULL && !DeviceToken_member->value.IsNull()) DeviceToken = DeviceToken_member->value.GetString();
    const Value::Member* SendPushNotificationConfirmation_member = obj.FindMember("SendPushNotificationConfirmation");
    if (SendPushNotificationConfirmation_member != NULL && !SendPushNotificationConfirmation_member->value.IsNull()) SendPushNotificationConfirmation = SendPushNotificationConfirmation_member->value.GetBool();
    const Value::Member* ConfirmationMessege_member = obj.FindMember("ConfirmationMessege");
    if (ConfirmationMessege_member != NULL && !ConfirmationMessege_member->value.IsNull()) ConfirmationMessege = ConfirmationMessege_member->value.GetString();

    return true;
}

AndroidDevicePushNotificationRegistrationResult::~AndroidDevicePushNotificationRegistrationResult()
{

}

void AndroidDevicePushNotificationRegistrationResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool AndroidDevicePushNotificationRegistrationResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

CancelTradeRequest::~CancelTradeRequest()
{

}

void CancelTradeRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TradeId"); writer.String(TradeId.c_str());

    writer.EndObject();
}

bool CancelTradeRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TradeId_member = obj.FindMember("TradeId");
    if (TradeId_member != NULL && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();

    return true;
}

CancelTradeResponse::~CancelTradeResponse()
{
    if (Trade != NULL) delete Trade;

}

void CancelTradeResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Trade != NULL) { writer.String("Trade"); Trade->writeJSON(writer); }

    writer.EndObject();
}

bool CancelTradeResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Trade_member = obj.FindMember("Trade");
    if (Trade_member != NULL && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

    return true;
}

CartItem::~CartItem()
{

}

void CartItem::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (ItemId.length() > 0) { writer.String("ItemId"); writer.String(ItemId.c_str()); }
    if (ItemClass.length() > 0) { writer.String("ItemClass"); writer.String(ItemClass.c_str()); }
    if (ItemInstanceId.length() > 0) { writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str()); }
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
    if (!VCAmount.empty()) {
    writer.String("VCAmount");
    writer.StartObject();
    for (std::map<std::string, Uint32>::iterator iter = VCAmount.begin(); iter != VCAmount.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Uint(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool CartItem::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::Member* ItemClass_member = obj.FindMember("ItemClass");
    if (ItemClass_member != NULL && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
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
    const Value::Member* VCAmount_member = obj.FindMember("VCAmount");
    if (VCAmount_member != NULL) {
        for (Value::ConstMemberIterator iter = VCAmount_member->value.MemberBegin(); iter != VCAmount_member->value.MemberEnd(); ++iter) {
            VCAmount[iter->name.GetString()] = iter->value.GetUint();
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

ConfirmPurchaseRequest::~ConfirmPurchaseRequest()
{

}

void ConfirmPurchaseRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("OrderId"); writer.String(OrderId.c_str());

    writer.EndObject();
}

bool ConfirmPurchaseRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
    if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();

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

ConfirmPurchaseResult::~ConfirmPurchaseResult()
{

}

void ConfirmPurchaseResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (OrderId.length() > 0) { writer.String("OrderId"); writer.String(OrderId.c_str()); }
    writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer);
    if (!Items.empty()) {
    writer.String("Items");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Items.begin(); iter != Items.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool ConfirmPurchaseResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
    if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
    const Value::Member* PurchaseDate_member = obj.FindMember("PurchaseDate");
    if (PurchaseDate_member != NULL && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
    const Value::Member* Items_member = obj.FindMember("Items");
    if (Items_member != NULL) {
        const rapidjson::Value& memberList = Items_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Items.push_back(ItemInstance(memberList[i]));
        }
    }

    return true;
}

ConsumeItemRequest::~ConsumeItemRequest()
{

}

void ConsumeItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ItemInstanceId"); writer.String(ItemInstanceId.c_str());
    writer.String("ConsumeCount"); writer.Int(ConsumeCount);
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }

    writer.EndObject();
}

bool ConsumeItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::Member* ConsumeCount_member = obj.FindMember("ConsumeCount");
    if (ConsumeCount_member != NULL && !ConsumeCount_member->value.IsNull()) ConsumeCount = ConsumeCount_member->value.GetInt();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

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
    const Value::Member* ItemInstanceId_member = obj.FindMember("ItemInstanceId");
    if (ItemInstanceId_member != NULL && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
    const Value::Member* RemainingUses_member = obj.FindMember("RemainingUses");
    if (RemainingUses_member != NULL && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();

    return true;
}

ConsumePSNEntitlementsRequest::~ConsumePSNEntitlementsRequest()
{

}

void ConsumePSNEntitlementsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("ServiceLabel"); writer.Int(ServiceLabel);

    writer.EndObject();
}

bool ConsumePSNEntitlementsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* ServiceLabel_member = obj.FindMember("ServiceLabel");
    if (ServiceLabel_member != NULL && !ServiceLabel_member->value.IsNull()) ServiceLabel = ServiceLabel_member->value.GetInt();

    return true;
}

ConsumePSNEntitlementsResult::~ConsumePSNEntitlementsResult()
{

}

void ConsumePSNEntitlementsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!ItemsGranted.empty()) {
    writer.String("ItemsGranted");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = ItemsGranted.begin(); iter != ItemsGranted.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool ConsumePSNEntitlementsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ItemsGranted_member = obj.FindMember("ItemsGranted");
    if (ItemsGranted_member != NULL) {
        const rapidjson::Value& memberList = ItemsGranted_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ItemsGranted.push_back(ItemInstance(memberList[i]));
        }
    }

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
void PlayFab::ClientModels::writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
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

Currency PlayFab::ClientModels::readCurrencyFromValue(const rapidjson::Value& obj)
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
void PlayFab::ClientModels::writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
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

Region PlayFab::ClientModels::readRegionFromValue(const rapidjson::Value& obj)
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

CurrentGamesRequest::~CurrentGamesRequest()
{

}

void CurrentGamesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (pfRegion.notNull()) { writer.String("Region"); writeRegionEnumJSON(pfRegion, writer); }
    if (BuildVersion.length() > 0) { writer.String("BuildVersion"); writer.String(BuildVersion.c_str()); }
    if (GameMode.length() > 0) { writer.String("GameMode"); writer.String(GameMode.c_str()); }
    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }

    writer.EndObject();
}

bool CurrentGamesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Region_member = obj.FindMember("Region");
    if (Region_member != NULL && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
    if (BuildVersion_member != NULL && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    const Value::Member* GameMode_member = obj.FindMember("GameMode");
    if (GameMode_member != NULL && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

    return true;
}

GameInfo::~GameInfo()
{

}

void GameInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (pfRegion.notNull()) { writer.String("Region"); writeRegionEnumJSON(pfRegion, writer); }
    if (LobbyID.length() > 0) { writer.String("LobbyID"); writer.String(LobbyID.c_str()); }
    if (BuildVersion.length() > 0) { writer.String("BuildVersion"); writer.String(BuildVersion.c_str()); }
    if (GameMode.length() > 0) { writer.String("GameMode"); writer.String(GameMode.c_str()); }
    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
    if (MaxPlayers.notNull()) { writer.String("MaxPlayers"); writer.Int(MaxPlayers); }
    if (!PlayerUserIds.empty()) {
    writer.String("PlayerUserIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayerUserIds.begin(); iter != PlayerUserIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    writer.String("RunTime"); writer.Uint(RunTime);
    if (GameServerState.length() > 0) { writer.String("GameServerState"); writer.String(GameServerState.c_str()); }

    writer.EndObject();
}

bool GameInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Region_member = obj.FindMember("Region");
    if (Region_member != NULL && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    const Value::Member* LobbyID_member = obj.FindMember("LobbyID");
    if (LobbyID_member != NULL && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
    const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
    if (BuildVersion_member != NULL && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    const Value::Member* GameMode_member = obj.FindMember("GameMode");
    if (GameMode_member != NULL && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* MaxPlayers_member = obj.FindMember("MaxPlayers");
    if (MaxPlayers_member != NULL && !MaxPlayers_member->value.IsNull()) MaxPlayers = MaxPlayers_member->value.GetInt();
    const Value::Member* PlayerUserIds_member = obj.FindMember("PlayerUserIds");
    if (PlayerUserIds_member != NULL) {
        const rapidjson::Value& memberList = PlayerUserIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PlayerUserIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* RunTime_member = obj.FindMember("RunTime");
    if (RunTime_member != NULL && !RunTime_member->value.IsNull()) RunTime = RunTime_member->value.GetUint();
    const Value::Member* GameServerState_member = obj.FindMember("GameServerState");
    if (GameServerState_member != NULL && !GameServerState_member->value.IsNull()) GameServerState = GameServerState_member->value.GetString();

    return true;
}

CurrentGamesResult::~CurrentGamesResult()
{

}

void CurrentGamesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Games.empty()) {
    writer.String("Games");
    writer.StartArray();
    for (std::list<GameInfo>::iterator iter = Games.begin(); iter != Games.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    writer.String("PlayerCount"); writer.Int(PlayerCount);
    writer.String("GameCount"); writer.Int(GameCount);

    writer.EndObject();
}

bool CurrentGamesResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Games_member = obj.FindMember("Games");
    if (Games_member != NULL) {
        const rapidjson::Value& memberList = Games_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Games.push_back(GameInfo(memberList[i]));
        }
    }
    const Value::Member* PlayerCount_member = obj.FindMember("PlayerCount");
    if (PlayerCount_member != NULL && !PlayerCount_member->value.IsNull()) PlayerCount = PlayerCount_member->value.GetInt();
    const Value::Member* GameCount_member = obj.FindMember("GameCount");
    if (GameCount_member != NULL && !GameCount_member->value.IsNull()) GameCount = GameCount_member->value.GetInt();

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
void PlayFab::ClientModels::writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
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

TitleActivationStatus PlayFab::ClientModels::readTitleActivationStatusFromValue(const rapidjson::Value& obj)
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

GameCenterPlayFabIdPair::~GameCenterPlayFabIdPair()
{

}

void GameCenterPlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (GameCenterId.length() > 0) { writer.String("GameCenterId"); writer.String(GameCenterId.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }

    writer.EndObject();
}

bool GameCenterPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* GameCenterId_member = obj.FindMember("GameCenterId");
    if (GameCenterId_member != NULL && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GameServerRegionsRequest::~GameServerRegionsRequest()
{

}

void GameServerRegionsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildVersion"); writer.String(BuildVersion.c_str());
    if (TitleId.length() > 0) { writer.String("TitleId"); writer.String(TitleId.c_str()); }

    writer.EndObject();
}

bool GameServerRegionsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
    if (BuildVersion_member != NULL && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

    return true;
}

RegionInfo::~RegionInfo()
{

}

void RegionInfo::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (pfRegion.notNull()) { writer.String("Region"); writeRegionEnumJSON(pfRegion, writer); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    writer.String("Available"); writer.Bool(Available);
    if (PingUrl.length() > 0) { writer.String("PingUrl"); writer.String(PingUrl.c_str()); }

    writer.EndObject();
}

bool RegionInfo::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Region_member = obj.FindMember("Region");
    if (Region_member != NULL && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    const Value::Member* Name_member = obj.FindMember("Name");
    if (Name_member != NULL && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::Member* Available_member = obj.FindMember("Available");
    if (Available_member != NULL && !Available_member->value.IsNull()) Available = Available_member->value.GetBool();
    const Value::Member* PingUrl_member = obj.FindMember("PingUrl");
    if (PingUrl_member != NULL && !PingUrl_member->value.IsNull()) PingUrl = PingUrl_member->value.GetString();

    return true;
}

GameServerRegionsResult::~GameServerRegionsResult()
{

}

void GameServerRegionsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Regions.empty()) {
    writer.String("Regions");
    writer.StartArray();
    for (std::list<RegionInfo>::iterator iter = Regions.begin(); iter != Regions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GameServerRegionsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Regions_member = obj.FindMember("Regions");
    if (Regions_member != NULL) {
        const rapidjson::Value& memberList = Regions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Regions.push_back(RegionInfo(memberList[i]));
        }
    }

    return true;
}

GetAccountInfoRequest::~GetAccountInfoRequest()
{

}

void GetAccountInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }

    writer.EndObject();
}

bool GetAccountInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::Member* Email_member = obj.FindMember("Email");
    if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::Member* TitleDisplayName_member = obj.FindMember("TitleDisplayName");
    if (TitleDisplayName_member != NULL && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();

    return true;
}
void PlayFab::ClientModels::writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
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

    }
}

UserOrigination PlayFab::ClientModels::readUserOriginationFromValue(const rapidjson::Value& obj)
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

GetAccountInfoResult::~GetAccountInfoResult()
{
    if (AccountInfo != NULL) delete AccountInfo;

}

void GetAccountInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (AccountInfo != NULL) { writer.String("AccountInfo"); AccountInfo->writeJSON(writer); }

    writer.EndObject();
}

bool GetAccountInfoResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* AccountInfo_member = obj.FindMember("AccountInfo");
    if (AccountInfo_member != NULL && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);

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

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
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
void PlayFab::ClientModels::writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case UserDataPermissionPrivate: writer.String("Private"); break;
    case UserDataPermissionPublic: writer.String("Public"); break;

    }
}

UserDataPermission PlayFab::ClientModels::readUserDataPermissionFromValue(const rapidjson::Value& obj)
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

    writer.EndObject();
}

bool GetCharacterDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::Member* DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != NULL && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

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

    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("StartPosition"); writer.Int(StartPosition);
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetCharacterLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
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

GetCloudScriptUrlRequest::~GetCloudScriptUrlRequest()
{

}

void GetCloudScriptUrlRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Version.notNull()) { writer.String("Version"); writer.Int(Version); }
    if (Testing.notNull()) { writer.String("Testing"); writer.Bool(Testing); }

    writer.EndObject();
}

bool GetCloudScriptUrlRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Version_member = obj.FindMember("Version");
    if (Version_member != NULL && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::Member* Testing_member = obj.FindMember("Testing");
    if (Testing_member != NULL && !Testing_member->value.IsNull()) Testing = Testing_member->value.GetBool();

    return true;
}

GetCloudScriptUrlResult::~GetCloudScriptUrlResult()
{

}

void GetCloudScriptUrlResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Url.length() > 0) { writer.String("Url"); writer.String(Url.c_str()); }

    writer.EndObject();
}

bool GetCloudScriptUrlResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Url_member = obj.FindMember("Url");
    if (Url_member != NULL && !Url_member->value.IsNull()) Url = Url_member->value.GetString();

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

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("StartPosition"); writer.Int(StartPosition);
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);
    if (IncludeSteamFriends.notNull()) { writer.String("IncludeSteamFriends"); writer.Bool(IncludeSteamFriends); }
    if (IncludeFacebookFriends.notNull()) { writer.String("IncludeFacebookFriends"); writer.Bool(IncludeFacebookFriends); }

    writer.EndObject();
}

bool GetFriendLeaderboardRequest::readFromValue(const rapidjson::Value& obj)
{
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

    if (IncludeSteamFriends.notNull()) { writer.String("IncludeSteamFriends"); writer.Bool(IncludeSteamFriends); }
    if (IncludeFacebookFriends.notNull()) { writer.String("IncludeFacebookFriends"); writer.Bool(IncludeFacebookFriends); }

    writer.EndObject();
}

bool GetFriendsListRequest::readFromValue(const rapidjson::Value& obj)
{
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
    writer.String("CharacterId"); writer.String(CharacterId.c_str());
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetLeaderboardAroundCharacterRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
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

GetLeaderboardAroundCurrentUserRequest::~GetLeaderboardAroundCurrentUserRequest()
{

}

void GetLeaderboardAroundCurrentUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StatisticName"); writer.String(StatisticName.c_str());
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetLeaderboardAroundCurrentUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
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

GetLeaderboardAroundCurrentUserResult::~GetLeaderboardAroundCurrentUserResult()
{

}

void GetLeaderboardAroundCurrentUserResult::writeJSON(PFStringJsonWriter& writer)
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

bool GetLeaderboardAroundCurrentUserResult::readFromValue(const rapidjson::Value& obj)
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
    writer.String("MaxResultsCount"); writer.Int(MaxResultsCount);

    writer.EndObject();
}

bool GetLeaderboardForUsersCharactersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
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

GetPhotonAuthenticationTokenRequest::~GetPhotonAuthenticationTokenRequest()
{

}

void GetPhotonAuthenticationTokenRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("PhotonApplicationId"); writer.String(PhotonApplicationId.c_str());

    writer.EndObject();
}

bool GetPhotonAuthenticationTokenRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PhotonApplicationId_member = obj.FindMember("PhotonApplicationId");
    if (PhotonApplicationId_member != NULL && !PhotonApplicationId_member->value.IsNull()) PhotonApplicationId = PhotonApplicationId_member->value.GetString();

    return true;
}

GetPhotonAuthenticationTokenResult::~GetPhotonAuthenticationTokenResult()
{

}

void GetPhotonAuthenticationTokenResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PhotonCustomAuthenticationToken.length() > 0) { writer.String("PhotonCustomAuthenticationToken"); writer.String(PhotonCustomAuthenticationToken.c_str()); }

    writer.EndObject();
}

bool GetPhotonAuthenticationTokenResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PhotonCustomAuthenticationToken_member = obj.FindMember("PhotonCustomAuthenticationToken");
    if (PhotonCustomAuthenticationToken_member != NULL && !PhotonCustomAuthenticationToken_member->value.IsNull()) PhotonCustomAuthenticationToken = PhotonCustomAuthenticationToken_member->value.GetString();

    return true;
}

GetPlayerTradesRequest::~GetPlayerTradesRequest()
{

}

void GetPlayerTradesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (StatusFilter.notNull()) { writer.String("StatusFilter"); writeTradeStatusEnumJSON(StatusFilter, writer); }

    writer.EndObject();
}

bool GetPlayerTradesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* StatusFilter_member = obj.FindMember("StatusFilter");
    if (StatusFilter_member != NULL && !StatusFilter_member->value.IsNull()) StatusFilter = readTradeStatusFromValue(StatusFilter_member->value);

    return true;
}

GetPlayerTradesResponse::~GetPlayerTradesResponse()
{

}

void GetPlayerTradesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!OpenedTrades.empty()) {
    writer.String("OpenedTrades");
    writer.StartArray();
    for (std::list<TradeInfo>::iterator iter = OpenedTrades.begin(); iter != OpenedTrades.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!AcceptedTrades.empty()) {
    writer.String("AcceptedTrades");
    writer.StartArray();
    for (std::list<TradeInfo>::iterator iter = AcceptedTrades.begin(); iter != AcceptedTrades.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayerTradesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OpenedTrades_member = obj.FindMember("OpenedTrades");
    if (OpenedTrades_member != NULL) {
        const rapidjson::Value& memberList = OpenedTrades_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            OpenedTrades.push_back(TradeInfo(memberList[i]));
        }
    }
    const Value::Member* AcceptedTrades_member = obj.FindMember("AcceptedTrades");
    if (AcceptedTrades_member != NULL) {
        const rapidjson::Value& memberList = AcceptedTrades_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AcceptedTrades.push_back(TradeInfo(memberList[i]));
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

GetPlayFabIDsFromGameCenterIDsRequest::~GetPlayFabIDsFromGameCenterIDsRequest()
{

}

void GetPlayFabIDsFromGameCenterIDsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("GameCenterIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = GameCenterIDs.begin(); iter != GameCenterIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GetPlayFabIDsFromGameCenterIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* GameCenterIDs_member = obj.FindMember("GameCenterIDs");
    if (GameCenterIDs_member != NULL) {
        const rapidjson::Value& memberList = GameCenterIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameCenterIDs.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetPlayFabIDsFromGameCenterIDsResult::~GetPlayFabIDsFromGameCenterIDsResult()
{

}

void GetPlayFabIDsFromGameCenterIDsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Data.empty()) {
    writer.String("Data");
    writer.StartArray();
    for (std::list<GameCenterPlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayFabIDsFromGameCenterIDsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(GameCenterPlayFabIdPair(memberList[i]));
        }
    }

    return true;
}

GetPlayFabIDsFromGoogleIDsRequest::~GetPlayFabIDsFromGoogleIDsRequest()
{

}

void GetPlayFabIDsFromGoogleIDsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("GoogleIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = GoogleIDs.begin(); iter != GoogleIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GetPlayFabIDsFromGoogleIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* GoogleIDs_member = obj.FindMember("GoogleIDs");
    if (GoogleIDs_member != NULL) {
        const rapidjson::Value& memberList = GoogleIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GoogleIDs.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GooglePlayFabIdPair::~GooglePlayFabIdPair()
{

}

void GooglePlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (GoogleId.length() > 0) { writer.String("GoogleId"); writer.String(GoogleId.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }

    writer.EndObject();
}

bool GooglePlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* GoogleId_member = obj.FindMember("GoogleId");
    if (GoogleId_member != NULL && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

    return true;
}

GetPlayFabIDsFromGoogleIDsResult::~GetPlayFabIDsFromGoogleIDsResult()
{

}

void GetPlayFabIDsFromGoogleIDsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Data.empty()) {
    writer.String("Data");
    writer.StartArray();
    for (std::list<GooglePlayFabIdPair>::iterator iter = Data.begin(); iter != Data.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPlayFabIDsFromGoogleIDsResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        const rapidjson::Value& memberList = Data_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Data.push_back(GooglePlayFabIdPair(memberList[i]));
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

    writer.String("PSNAccountIDs");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PSNAccountIDs.begin(); iter != PSNAccountIDs.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    
    if (IssuerId.notNull()) { writer.String("IssuerId"); writer.Int(IssuerId); }

    writer.EndObject();
}

bool GetPlayFabIDsFromPSNAccountIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PSNAccountIDs_member = obj.FindMember("PSNAccountIDs");
    if (PSNAccountIDs_member != NULL) {
        const rapidjson::Value& memberList = PSNAccountIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PSNAccountIDs.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* IssuerId_member = obj.FindMember("IssuerId");
    if (IssuerId_member != NULL && !IssuerId_member->value.IsNull()) IssuerId = IssuerId_member->value.GetInt();

    return true;
}

PSNAccountPlayFabIdPair::~PSNAccountPlayFabIdPair()
{

}

void PSNAccountPlayFabIdPair::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PSNAccountId.length() > 0) { writer.String("PSNAccountId"); writer.String(PSNAccountId.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }

    writer.EndObject();
}

bool PSNAccountPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PSNAccountId_member = obj.FindMember("PSNAccountId");
    if (PSNAccountId_member != NULL && !PSNAccountId_member->value.IsNull()) PSNAccountId = PSNAccountId_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
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

    writer.String("SteamIDs");
    writer.StartArray();
    for (std::list<Uint64>::iterator iter = SteamIDs.begin(); iter != SteamIDs.end(); iter++) {
        writer.Uint64(*iter);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool GetPlayFabIDsFromSteamIDsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* SteamIDs_member = obj.FindMember("SteamIDs");
    if (SteamIDs_member != NULL) {
        const rapidjson::Value& memberList = SteamIDs_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            SteamIDs.push_back(memberList[i].GetUint64());
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
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }

    writer.EndObject();
}

bool SteamPlayFabIdPair::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* SteamId_member = obj.FindMember("SteamId");
    if (SteamId_member != NULL && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetUint64();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

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
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
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

GetPurchaseRequest::~GetPurchaseRequest()
{

}

void GetPurchaseRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("OrderId"); writer.String(OrderId.c_str());

    writer.EndObject();
}

bool GetPurchaseRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
    if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();

    return true;
}

GetPurchaseResult::~GetPurchaseResult()
{

}

void GetPurchaseResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (OrderId.length() > 0) { writer.String("OrderId"); writer.String(OrderId.c_str()); }
    if (PaymentProvider.length() > 0) { writer.String("PaymentProvider"); writer.String(PaymentProvider.c_str()); }
    if (TransactionId.length() > 0) { writer.String("TransactionId"); writer.String(TransactionId.c_str()); }
    if (TransactionStatus.length() > 0) { writer.String("TransactionStatus"); writer.String(TransactionStatus.c_str()); }
    writer.String("PurchaseDate"); writeDatetime(PurchaseDate, writer);
    if (!Items.empty()) {
    writer.String("Items");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Items.begin(); iter != Items.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetPurchaseResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
    if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
    const Value::Member* PaymentProvider_member = obj.FindMember("PaymentProvider");
    if (PaymentProvider_member != NULL && !PaymentProvider_member->value.IsNull()) PaymentProvider = PaymentProvider_member->value.GetString();
    const Value::Member* TransactionId_member = obj.FindMember("TransactionId");
    if (TransactionId_member != NULL && !TransactionId_member->value.IsNull()) TransactionId = TransactionId_member->value.GetString();
    const Value::Member* TransactionStatus_member = obj.FindMember("TransactionStatus");
    if (TransactionStatus_member != NULL && !TransactionStatus_member->value.IsNull()) TransactionStatus = TransactionStatus_member->value.GetString();
    const Value::Member* PurchaseDate_member = obj.FindMember("PurchaseDate");
    if (PurchaseDate_member != NULL && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
    const Value::Member* Items_member = obj.FindMember("Items");
    if (Items_member != NULL) {
        const rapidjson::Value& memberList = Items_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Items.push_back(ItemInstance(memberList[i]));
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

    writer.String("SharedGroupId"); writer.String(SharedGroupId.c_str());
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

GetStoreItemsRequest::~GetStoreItemsRequest()
{

}

void GetStoreItemsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("StoreId"); writer.String(StoreId.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool GetStoreItemsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* StoreId_member = obj.FindMember("StoreId");
    if (StoreId_member != NULL && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

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

GetTradeStatusRequest::~GetTradeStatusRequest()
{

}

void GetTradeStatusRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("OfferingPlayerId"); writer.String(OfferingPlayerId.c_str());
    writer.String("TradeId"); writer.String(TradeId.c_str());

    writer.EndObject();
}

bool GetTradeStatusRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
    if (OfferingPlayerId_member != NULL && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
    const Value::Member* TradeId_member = obj.FindMember("TradeId");
    if (TradeId_member != NULL && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();

    return true;
}

GetTradeStatusResponse::~GetTradeStatusResponse()
{
    if (Trade != NULL) delete Trade;

}

void GetTradeStatusResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Trade != NULL) { writer.String("Trade"); Trade->writeJSON(writer); }

    writer.EndObject();
}

bool GetTradeStatusResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Trade_member = obj.FindMember("Trade");
    if (Trade_member != NULL && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

    return true;
}

GetUserCombinedInfoRequest::~GetUserCombinedInfoRequest()
{

}

void GetUserCombinedInfoRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    if (TitleDisplayName.length() > 0) { writer.String("TitleDisplayName"); writer.String(TitleDisplayName.c_str()); }
    if (GetAccountInfo.notNull()) { writer.String("GetAccountInfo"); writer.Bool(GetAccountInfo); }
    if (GetInventory.notNull()) { writer.String("GetInventory"); writer.Bool(GetInventory); }
    if (GetVirtualCurrency.notNull()) { writer.String("GetVirtualCurrency"); writer.Bool(GetVirtualCurrency); }
    if (GetUserData.notNull()) { writer.String("GetUserData"); writer.Bool(GetUserData); }
    if (!UserDataKeys.empty()) {
    writer.String("UserDataKeys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = UserDataKeys.begin(); iter != UserDataKeys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (GetReadOnlyData.notNull()) { writer.String("GetReadOnlyData"); writer.Bool(GetReadOnlyData); }
    if (!ReadOnlyDataKeys.empty()) {
    writer.String("ReadOnlyDataKeys");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = ReadOnlyDataKeys.begin(); iter != ReadOnlyDataKeys.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool GetUserCombinedInfoRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::Member* Email_member = obj.FindMember("Email");
    if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::Member* TitleDisplayName_member = obj.FindMember("TitleDisplayName");
    if (TitleDisplayName_member != NULL && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
    const Value::Member* GetAccountInfo_member = obj.FindMember("GetAccountInfo");
    if (GetAccountInfo_member != NULL && !GetAccountInfo_member->value.IsNull()) GetAccountInfo = GetAccountInfo_member->value.GetBool();
    const Value::Member* GetInventory_member = obj.FindMember("GetInventory");
    if (GetInventory_member != NULL && !GetInventory_member->value.IsNull()) GetInventory = GetInventory_member->value.GetBool();
    const Value::Member* GetVirtualCurrency_member = obj.FindMember("GetVirtualCurrency");
    if (GetVirtualCurrency_member != NULL && !GetVirtualCurrency_member->value.IsNull()) GetVirtualCurrency = GetVirtualCurrency_member->value.GetBool();
    const Value::Member* GetUserData_member = obj.FindMember("GetUserData");
    if (GetUserData_member != NULL && !GetUserData_member->value.IsNull()) GetUserData = GetUserData_member->value.GetBool();
    const Value::Member* UserDataKeys_member = obj.FindMember("UserDataKeys");
    if (UserDataKeys_member != NULL) {
        const rapidjson::Value& memberList = UserDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UserDataKeys.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* GetReadOnlyData_member = obj.FindMember("GetReadOnlyData");
    if (GetReadOnlyData_member != NULL && !GetReadOnlyData_member->value.IsNull()) GetReadOnlyData = GetReadOnlyData_member->value.GetBool();
    const Value::Member* ReadOnlyDataKeys_member = obj.FindMember("ReadOnlyDataKeys");
    if (ReadOnlyDataKeys_member != NULL) {
        const rapidjson::Value& memberList = ReadOnlyDataKeys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ReadOnlyDataKeys.push_back(memberList[i].GetString());
        }
    }

    return true;
}

GetUserCombinedInfoResult::~GetUserCombinedInfoResult()
{
    if (AccountInfo != NULL) delete AccountInfo;

}

void GetUserCombinedInfoResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (AccountInfo != NULL) { writer.String("AccountInfo"); AccountInfo->writeJSON(writer); }
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
    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
    writer.String("DataVersion"); writer.Uint(DataVersion);
    if (!ReadOnlyData.empty()) {
    writer.String("ReadOnlyData");
    writer.StartObject();
    for (std::map<std::string, UserDataRecord>::iterator iter = ReadOnlyData.begin(); iter != ReadOnlyData.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
    writer.String("ReadOnlyDataVersion"); writer.Uint(ReadOnlyDataVersion);

    writer.EndObject();
}

bool GetUserCombinedInfoResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* AccountInfo_member = obj.FindMember("AccountInfo");
    if (AccountInfo_member != NULL && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);
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
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::Member* DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != NULL && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
    const Value::Member* ReadOnlyData_member = obj.FindMember("ReadOnlyData");
    if (ReadOnlyData_member != NULL) {
        for (Value::ConstMemberIterator iter = ReadOnlyData_member->value.MemberBegin(); iter != ReadOnlyData_member->value.MemberEnd(); ++iter) {
            ReadOnlyData[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::Member* ReadOnlyDataVersion_member = obj.FindMember("ReadOnlyDataVersion");
    if (ReadOnlyDataVersion_member != NULL && !ReadOnlyDataVersion_member->value.IsNull()) ReadOnlyDataVersion = ReadOnlyDataVersion_member->value.GetUint();

    return true;
}

GetUserDataRequest::~GetUserDataRequest()
{

}

void GetUserDataRequest::writeJSON(PFStringJsonWriter& writer)
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
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (IfChangedFromDataVersion.notNull()) { writer.String("IfChangedFromDataVersion"); writer.Int(IfChangedFromDataVersion); }

    writer.EndObject();
}

bool GetUserDataRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Keys_member = obj.FindMember("Keys");
    if (Keys_member != NULL) {
        const rapidjson::Value& memberList = Keys_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Keys.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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

    if (!Data.empty()) {
    writer.String("Data");
    writer.StartObject();
    for (std::map<std::string, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
        writer.String(iter->first.c_str()); iter->second.writeJSON(writer);
    }
    writer.EndObject();
     }
    writer.String("DataVersion"); writer.Uint(DataVersion);

    writer.EndObject();
}

bool GetUserDataResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Data_member = obj.FindMember("Data");
    if (Data_member != NULL) {
        for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
            Data[iter->name.GetString()] = UserDataRecord(iter->value);
        }
    }
    const Value::Member* DataVersion_member = obj.FindMember("DataVersion");
    if (DataVersion_member != NULL && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

    return true;
}

GetUserInventoryRequest::~GetUserInventoryRequest()
{

}

void GetUserInventoryRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool GetUserInventoryRequest::readFromValue(const rapidjson::Value& obj)
{

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


    writer.EndObject();
}

bool GetUserStatisticsRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetUserStatisticsResult::~GetUserStatisticsResult()
{

}

void GetUserStatisticsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

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

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("ItemId"); writer.String(ItemId.c_str());
    writer.String("CharacterName"); writer.String(CharacterName.c_str());

    writer.EndObject();
}

bool GrantCharacterToUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::Member* CharacterName_member = obj.FindMember("CharacterName");
    if (CharacterName_member != NULL && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();

    return true;
}

GrantCharacterToUserResult::~GrantCharacterToUserResult()
{

}

void GrantCharacterToUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (CharacterType.length() > 0) { writer.String("CharacterType"); writer.String(CharacterType.c_str()); }
    writer.String("Result"); writer.Bool(Result);

    writer.EndObject();
}

bool GrantCharacterToUserResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CharacterType_member = obj.FindMember("CharacterType");
    if (CharacterType_member != NULL && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
    const Value::Member* Result_member = obj.FindMember("Result");
    if (Result_member != NULL && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();

    return true;
}

ItemPuchaseRequest::~ItemPuchaseRequest()
{

}

void ItemPuchaseRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ItemId"); writer.String(ItemId.c_str());
    writer.String("Quantity"); writer.Uint(Quantity);
    if (Annotation.length() > 0) { writer.String("Annotation"); writer.String(Annotation.c_str()); }
    if (!UpgradeFromItems.empty()) {
    writer.String("UpgradeFromItems");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = UpgradeFromItems.begin(); iter != UpgradeFromItems.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool ItemPuchaseRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::Member* Quantity_member = obj.FindMember("Quantity");
    if (Quantity_member != NULL && !Quantity_member->value.IsNull()) Quantity = Quantity_member->value.GetUint();
    const Value::Member* Annotation_member = obj.FindMember("Annotation");
    if (Annotation_member != NULL && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
    const Value::Member* UpgradeFromItems_member = obj.FindMember("UpgradeFromItems");
    if (UpgradeFromItems_member != NULL) {
        const rapidjson::Value& memberList = UpgradeFromItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            UpgradeFromItems.push_back(memberList[i].GetString());
        }
    }

    return true;
}

LinkAndroidDeviceIDRequest::~LinkAndroidDeviceIDRequest()
{

}

void LinkAndroidDeviceIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("AndroidDeviceId"); writer.String(AndroidDeviceId.c_str());
    if (OS.length() > 0) { writer.String("OS"); writer.String(OS.c_str()); }
    if (AndroidDevice.length() > 0) { writer.String("AndroidDevice"); writer.String(AndroidDevice.c_str()); }

    writer.EndObject();
}

bool LinkAndroidDeviceIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
    if (AndroidDeviceId_member != NULL && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();
    const Value::Member* OS_member = obj.FindMember("OS");
    if (OS_member != NULL && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
    const Value::Member* AndroidDevice_member = obj.FindMember("AndroidDevice");
    if (AndroidDevice_member != NULL && !AndroidDevice_member->value.IsNull()) AndroidDevice = AndroidDevice_member->value.GetString();

    return true;
}

LinkAndroidDeviceIDResult::~LinkAndroidDeviceIDResult()
{

}

void LinkAndroidDeviceIDResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkAndroidDeviceIDResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LinkCustomIDRequest::~LinkCustomIDRequest()
{

}

void LinkCustomIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("CustomId"); writer.String(CustomId.c_str());

    writer.EndObject();
}

bool LinkCustomIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* CustomId_member = obj.FindMember("CustomId");
    if (CustomId_member != NULL && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

    return true;
}

LinkCustomIDResult::~LinkCustomIDResult()
{

}

void LinkCustomIDResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkCustomIDResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LinkFacebookAccountRequest::~LinkFacebookAccountRequest()
{

}

void LinkFacebookAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("AccessToken"); writer.String(AccessToken.c_str());
    if (ForceLink.notNull()) { writer.String("ForceLink"); writer.Bool(ForceLink); }

    writer.EndObject();
}

bool LinkFacebookAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* AccessToken_member = obj.FindMember("AccessToken");
    if (AccessToken_member != NULL && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
    const Value::Member* ForceLink_member = obj.FindMember("ForceLink");
    if (ForceLink_member != NULL && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

    return true;
}

LinkFacebookAccountResult::~LinkFacebookAccountResult()
{

}

void LinkFacebookAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkFacebookAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LinkGameCenterAccountRequest::~LinkGameCenterAccountRequest()
{

}

void LinkGameCenterAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("GameCenterId"); writer.String(GameCenterId.c_str());

    writer.EndObject();
}

bool LinkGameCenterAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* GameCenterId_member = obj.FindMember("GameCenterId");
    if (GameCenterId_member != NULL && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();

    return true;
}

LinkGameCenterAccountResult::~LinkGameCenterAccountResult()
{

}

void LinkGameCenterAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkGameCenterAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LinkGoogleAccountRequest::~LinkGoogleAccountRequest()
{

}

void LinkGoogleAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("AccessToken"); writer.String(AccessToken.c_str());

    writer.EndObject();
}

bool LinkGoogleAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* AccessToken_member = obj.FindMember("AccessToken");
    if (AccessToken_member != NULL && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();

    return true;
}

LinkGoogleAccountResult::~LinkGoogleAccountResult()
{

}

void LinkGoogleAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkGoogleAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LinkIOSDeviceIDRequest::~LinkIOSDeviceIDRequest()
{

}

void LinkIOSDeviceIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("DeviceId"); writer.String(DeviceId.c_str());
    if (OS.length() > 0) { writer.String("OS"); writer.String(OS.c_str()); }
    if (DeviceModel.length() > 0) { writer.String("DeviceModel"); writer.String(DeviceModel.c_str()); }

    writer.EndObject();
}

bool LinkIOSDeviceIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* DeviceId_member = obj.FindMember("DeviceId");
    if (DeviceId_member != NULL && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();
    const Value::Member* OS_member = obj.FindMember("OS");
    if (OS_member != NULL && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
    const Value::Member* DeviceModel_member = obj.FindMember("DeviceModel");
    if (DeviceModel_member != NULL && !DeviceModel_member->value.IsNull()) DeviceModel = DeviceModel_member->value.GetString();

    return true;
}

LinkIOSDeviceIDResult::~LinkIOSDeviceIDResult()
{

}

void LinkIOSDeviceIDResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkIOSDeviceIDResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LinkKongregateAccountRequest::~LinkKongregateAccountRequest()
{

}

void LinkKongregateAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("KongregateId"); writer.String(KongregateId.c_str());
    writer.String("AuthTicket"); writer.String(AuthTicket.c_str());

    writer.EndObject();
}

bool LinkKongregateAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* KongregateId_member = obj.FindMember("KongregateId");
    if (KongregateId_member != NULL && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
    const Value::Member* AuthTicket_member = obj.FindMember("AuthTicket");
    if (AuthTicket_member != NULL && !AuthTicket_member->value.IsNull()) AuthTicket = AuthTicket_member->value.GetString();

    return true;
}

LinkKongregateAccountResult::~LinkKongregateAccountResult()
{

}

void LinkKongregateAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkKongregateAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LinkPSNAccountRequest::~LinkPSNAccountRequest()
{

}

void LinkPSNAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("AuthCode"); writer.String(AuthCode.c_str());
    writer.String("RedirectUri"); writer.String(RedirectUri.c_str());
    if (IssuerId.notNull()) { writer.String("IssuerId"); writer.Int(IssuerId); }

    writer.EndObject();
}

bool LinkPSNAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* AuthCode_member = obj.FindMember("AuthCode");
    if (AuthCode_member != NULL && !AuthCode_member->value.IsNull()) AuthCode = AuthCode_member->value.GetString();
    const Value::Member* RedirectUri_member = obj.FindMember("RedirectUri");
    if (RedirectUri_member != NULL && !RedirectUri_member->value.IsNull()) RedirectUri = RedirectUri_member->value.GetString();
    const Value::Member* IssuerId_member = obj.FindMember("IssuerId");
    if (IssuerId_member != NULL && !IssuerId_member->value.IsNull()) IssuerId = IssuerId_member->value.GetInt();

    return true;
}

LinkPSNAccountResult::~LinkPSNAccountResult()
{

}

void LinkPSNAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkPSNAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

LinkSteamAccountRequest::~LinkSteamAccountRequest()
{

}

void LinkSteamAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("SteamTicket"); writer.String(SteamTicket.c_str());

    writer.EndObject();
}

bool LinkSteamAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* SteamTicket_member = obj.FindMember("SteamTicket");
    if (SteamTicket_member != NULL && !SteamTicket_member->value.IsNull()) SteamTicket = SteamTicket_member->value.GetString();

    return true;
}

LinkSteamAccountResult::~LinkSteamAccountResult()
{

}

void LinkSteamAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool LinkSteamAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

ListUsersCharactersRequest::~ListUsersCharactersRequest()
{

}

void ListUsersCharactersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }

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

LoginResult::~LoginResult()
{

}

void LoginResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (SessionTicket.length() > 0) { writer.String("SessionTicket"); writer.String(SessionTicket.c_str()); }
    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    writer.String("NewlyCreated"); writer.Bool(NewlyCreated);

    writer.EndObject();
}

bool LoginResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* SessionTicket_member = obj.FindMember("SessionTicket");
    if (SessionTicket_member != NULL && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* NewlyCreated_member = obj.FindMember("NewlyCreated");
    if (NewlyCreated_member != NULL && !NewlyCreated_member->value.IsNull()) NewlyCreated = NewlyCreated_member->value.GetBool();

    return true;
}

LoginWithAndroidDeviceIDRequest::~LoginWithAndroidDeviceIDRequest()
{

}

void LoginWithAndroidDeviceIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("AndroidDeviceId"); writer.String(AndroidDeviceId.c_str());
    if (OS.length() > 0) { writer.String("OS"); writer.String(OS.c_str()); }
    if (AndroidDevice.length() > 0) { writer.String("AndroidDevice"); writer.String(AndroidDevice.c_str()); }
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }

    writer.EndObject();
}

bool LoginWithAndroidDeviceIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
    if (AndroidDeviceId_member != NULL && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();
    const Value::Member* OS_member = obj.FindMember("OS");
    if (OS_member != NULL && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
    const Value::Member* AndroidDevice_member = obj.FindMember("AndroidDevice");
    if (AndroidDevice_member != NULL && !AndroidDevice_member->value.IsNull()) AndroidDevice = AndroidDevice_member->value.GetString();
    const Value::Member* CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != NULL && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();

    return true;
}

LoginWithCustomIDRequest::~LoginWithCustomIDRequest()
{

}

void LoginWithCustomIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("CustomId"); writer.String(CustomId.c_str());
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }

    writer.EndObject();
}

bool LoginWithCustomIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* CustomId_member = obj.FindMember("CustomId");
    if (CustomId_member != NULL && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();
    const Value::Member* CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != NULL && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();

    return true;
}

LoginWithEmailAddressRequest::~LoginWithEmailAddressRequest()
{

}

void LoginWithEmailAddressRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("Email"); writer.String(Email.c_str());
    writer.String("Password"); writer.String(Password.c_str());

    writer.EndObject();
}

bool LoginWithEmailAddressRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* Email_member = obj.FindMember("Email");
    if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::Member* Password_member = obj.FindMember("Password");
    if (Password_member != NULL && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

    return true;
}

LoginWithFacebookRequest::~LoginWithFacebookRequest()
{

}

void LoginWithFacebookRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("AccessToken"); writer.String(AccessToken.c_str());
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }

    writer.EndObject();
}

bool LoginWithFacebookRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* AccessToken_member = obj.FindMember("AccessToken");
    if (AccessToken_member != NULL && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
    const Value::Member* CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != NULL && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();

    return true;
}

LoginWithGoogleAccountRequest::~LoginWithGoogleAccountRequest()
{

}

void LoginWithGoogleAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("AccessToken"); writer.String(AccessToken.c_str());
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }
    if (PublisherId.length() > 0) { writer.String("PublisherId"); writer.String(PublisherId.c_str()); }

    writer.EndObject();
}

bool LoginWithGoogleAccountRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* AccessToken_member = obj.FindMember("AccessToken");
    if (AccessToken_member != NULL && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
    const Value::Member* CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != NULL && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
    const Value::Member* PublisherId_member = obj.FindMember("PublisherId");
    if (PublisherId_member != NULL && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();

    return true;
}

LoginWithIOSDeviceIDRequest::~LoginWithIOSDeviceIDRequest()
{

}

void LoginWithIOSDeviceIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("DeviceId"); writer.String(DeviceId.c_str());
    if (OS.length() > 0) { writer.String("OS"); writer.String(OS.c_str()); }
    if (DeviceModel.length() > 0) { writer.String("DeviceModel"); writer.String(DeviceModel.c_str()); }
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }

    writer.EndObject();
}

bool LoginWithIOSDeviceIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* DeviceId_member = obj.FindMember("DeviceId");
    if (DeviceId_member != NULL && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();
    const Value::Member* OS_member = obj.FindMember("OS");
    if (OS_member != NULL && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
    const Value::Member* DeviceModel_member = obj.FindMember("DeviceModel");
    if (DeviceModel_member != NULL && !DeviceModel_member->value.IsNull()) DeviceModel = DeviceModel_member->value.GetString();
    const Value::Member* CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != NULL && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();

    return true;
}

LoginWithKongregateRequest::~LoginWithKongregateRequest()
{

}

void LoginWithKongregateRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("KongregateId"); writer.String(KongregateId.c_str());
    writer.String("AuthTicket"); writer.String(AuthTicket.c_str());
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }

    writer.EndObject();
}

bool LoginWithKongregateRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* KongregateId_member = obj.FindMember("KongregateId");
    if (KongregateId_member != NULL && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
    const Value::Member* AuthTicket_member = obj.FindMember("AuthTicket");
    if (AuthTicket_member != NULL && !AuthTicket_member->value.IsNull()) AuthTicket = AuthTicket_member->value.GetString();
    const Value::Member* CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != NULL && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();

    return true;
}

LoginWithPlayFabRequest::~LoginWithPlayFabRequest()
{

}

void LoginWithPlayFabRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("Username"); writer.String(Username.c_str());
    writer.String("Password"); writer.String(Password.c_str());

    writer.EndObject();
}

bool LoginWithPlayFabRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::Member* Password_member = obj.FindMember("Password");
    if (Password_member != NULL && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

    return true;
}

LoginWithPSNRequest::~LoginWithPSNRequest()
{

}

void LoginWithPSNRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("AuthCode"); writer.String(AuthCode.c_str());
    writer.String("RedirectUri"); writer.String(RedirectUri.c_str());
    if (IssuerId.notNull()) { writer.String("IssuerId"); writer.Int(IssuerId); }
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }

    writer.EndObject();
}

bool LoginWithPSNRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* AuthCode_member = obj.FindMember("AuthCode");
    if (AuthCode_member != NULL && !AuthCode_member->value.IsNull()) AuthCode = AuthCode_member->value.GetString();
    const Value::Member* RedirectUri_member = obj.FindMember("RedirectUri");
    if (RedirectUri_member != NULL && !RedirectUri_member->value.IsNull()) RedirectUri = RedirectUri_member->value.GetString();
    const Value::Member* IssuerId_member = obj.FindMember("IssuerId");
    if (IssuerId_member != NULL && !IssuerId_member->value.IsNull()) IssuerId = IssuerId_member->value.GetInt();
    const Value::Member* CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != NULL && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();

    return true;
}

LoginWithSteamRequest::~LoginWithSteamRequest()
{

}

void LoginWithSteamRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    writer.String("SteamTicket"); writer.String(SteamTicket.c_str());
    if (CreateAccount.notNull()) { writer.String("CreateAccount"); writer.Bool(CreateAccount); }

    writer.EndObject();
}

bool LoginWithSteamRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* SteamTicket_member = obj.FindMember("SteamTicket");
    if (SteamTicket_member != NULL && !SteamTicket_member->value.IsNull()) SteamTicket = SteamTicket_member->value.GetString();
    const Value::Member* CreateAccount_member = obj.FindMember("CreateAccount");
    if (CreateAccount_member != NULL && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();

    return true;
}

MatchmakeRequest::~MatchmakeRequest()
{

}

void MatchmakeRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (BuildVersion.length() > 0) { writer.String("BuildVersion"); writer.String(BuildVersion.c_str()); }
    if (pfRegion.notNull()) { writer.String("Region"); writeRegionEnumJSON(pfRegion, writer); }
    if (GameMode.length() > 0) { writer.String("GameMode"); writer.String(GameMode.c_str()); }
    if (LobbyId.length() > 0) { writer.String("LobbyId"); writer.String(LobbyId.c_str()); }
    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (EnableQueue.notNull()) { writer.String("EnableQueue"); writer.Bool(EnableQueue); }

    writer.EndObject();
}

bool MatchmakeRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
    if (BuildVersion_member != NULL && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    const Value::Member* Region_member = obj.FindMember("Region");
    if (Region_member != NULL && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    const Value::Member* GameMode_member = obj.FindMember("GameMode");
    if (GameMode_member != NULL && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
    const Value::Member* LobbyId_member = obj.FindMember("LobbyId");
    if (LobbyId_member != NULL && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* EnableQueue_member = obj.FindMember("EnableQueue");
    if (EnableQueue_member != NULL && !EnableQueue_member->value.IsNull()) EnableQueue = EnableQueue_member->value.GetBool();

    return true;
}
void PlayFab::ClientModels::writeMatchmakeStatusEnumJSON(MatchmakeStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case MatchmakeStatusComplete: writer.String("Complete"); break;
    case MatchmakeStatusWaiting: writer.String("Waiting"); break;
    case MatchmakeStatusGameNotFound: writer.String("GameNotFound"); break;

    }
}

MatchmakeStatus PlayFab::ClientModels::readMatchmakeStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, MatchmakeStatus> _MatchmakeStatusMap;
    if (_MatchmakeStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _MatchmakeStatusMap["Complete"] = MatchmakeStatusComplete;
        _MatchmakeStatusMap["Waiting"] = MatchmakeStatusWaiting;
        _MatchmakeStatusMap["GameNotFound"] = MatchmakeStatusGameNotFound;

    }

    auto output = _MatchmakeStatusMap.find(obj.GetString());
    if (output != _MatchmakeStatusMap.end())
        return output->second;

    return MatchmakeStatusComplete; // Basically critical fail
}

MatchmakeResult::~MatchmakeResult()
{

}

void MatchmakeResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (LobbyID.length() > 0) { writer.String("LobbyID"); writer.String(LobbyID.c_str()); }
    if (ServerHostname.length() > 0) { writer.String("ServerHostname"); writer.String(ServerHostname.c_str()); }
    if (ServerPort.notNull()) { writer.String("ServerPort"); writer.Int(ServerPort); }
    if (Ticket.length() > 0) { writer.String("Ticket"); writer.String(Ticket.c_str()); }
    if (Expires.length() > 0) { writer.String("Expires"); writer.String(Expires.c_str()); }
    if (PollWaitTimeMS.notNull()) { writer.String("PollWaitTimeMS"); writer.Int(PollWaitTimeMS); }
    if (Status.notNull()) { writer.String("Status"); writeMatchmakeStatusEnumJSON(Status, writer); }

    writer.EndObject();
}

bool MatchmakeResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* LobbyID_member = obj.FindMember("LobbyID");
    if (LobbyID_member != NULL && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
    const Value::Member* ServerHostname_member = obj.FindMember("ServerHostname");
    if (ServerHostname_member != NULL && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
    const Value::Member* ServerPort_member = obj.FindMember("ServerPort");
    if (ServerPort_member != NULL && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetInt();
    const Value::Member* Ticket_member = obj.FindMember("Ticket");
    if (Ticket_member != NULL && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();
    const Value::Member* Expires_member = obj.FindMember("Expires");
    if (Expires_member != NULL && !Expires_member->value.IsNull()) Expires = Expires_member->value.GetString();
    const Value::Member* PollWaitTimeMS_member = obj.FindMember("PollWaitTimeMS");
    if (PollWaitTimeMS_member != NULL && !PollWaitTimeMS_member->value.IsNull()) PollWaitTimeMS = PollWaitTimeMS_member->value.GetInt();
    const Value::Member* Status_member = obj.FindMember("Status");
    if (Status_member != NULL && !Status_member->value.IsNull()) Status = readMatchmakeStatusFromValue(Status_member->value);

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

OpenTradeRequest::~OpenTradeRequest()
{

}

void OpenTradeRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!OfferedInventoryInstanceIds.empty()) {
    writer.String("OfferedInventoryInstanceIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = OfferedInventoryInstanceIds.begin(); iter != OfferedInventoryInstanceIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!RequestedCatalogItemIds.empty()) {
    writer.String("RequestedCatalogItemIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = RequestedCatalogItemIds.begin(); iter != RequestedCatalogItemIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }
    if (!AllowedPlayerIds.empty()) {
    writer.String("AllowedPlayerIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = AllowedPlayerIds.begin(); iter != AllowedPlayerIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool OpenTradeRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OfferedInventoryInstanceIds_member = obj.FindMember("OfferedInventoryInstanceIds");
    if (OfferedInventoryInstanceIds_member != NULL) {
        const rapidjson::Value& memberList = OfferedInventoryInstanceIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            OfferedInventoryInstanceIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* RequestedCatalogItemIds_member = obj.FindMember("RequestedCatalogItemIds");
    if (RequestedCatalogItemIds_member != NULL) {
        const rapidjson::Value& memberList = RequestedCatalogItemIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            RequestedCatalogItemIds.push_back(memberList[i].GetString());
        }
    }
    const Value::Member* AllowedPlayerIds_member = obj.FindMember("AllowedPlayerIds");
    if (AllowedPlayerIds_member != NULL) {
        const rapidjson::Value& memberList = AllowedPlayerIds_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AllowedPlayerIds.push_back(memberList[i].GetString());
        }
    }

    return true;
}

OpenTradeResponse::~OpenTradeResponse()
{
    if (Trade != NULL) delete Trade;

}

void OpenTradeResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Trade != NULL) { writer.String("Trade"); Trade->writeJSON(writer); }

    writer.EndObject();
}

bool OpenTradeResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Trade_member = obj.FindMember("Trade");
    if (Trade_member != NULL && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

    return true;
}

PayForPurchaseRequest::~PayForPurchaseRequest()
{

}

void PayForPurchaseRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("OrderId"); writer.String(OrderId.c_str());
    writer.String("ProviderName"); writer.String(ProviderName.c_str());
    writer.String("Currency"); writer.String(Currency.c_str());
    if (ProviderTransactionId.length() > 0) { writer.String("ProviderTransactionId"); writer.String(ProviderTransactionId.c_str()); }

    writer.EndObject();
}

bool PayForPurchaseRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
    if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
    const Value::Member* ProviderName_member = obj.FindMember("ProviderName");
    if (ProviderName_member != NULL && !ProviderName_member->value.IsNull()) ProviderName = ProviderName_member->value.GetString();
    const Value::Member* Currency_member = obj.FindMember("Currency");
    if (Currency_member != NULL && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
    const Value::Member* ProviderTransactionId_member = obj.FindMember("ProviderTransactionId");
    if (ProviderTransactionId_member != NULL && !ProviderTransactionId_member->value.IsNull()) ProviderTransactionId = ProviderTransactionId_member->value.GetString();

    return true;
}
void PlayFab::ClientModels::writeTransactionStatusEnumJSON(TransactionStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case TransactionStatusCreateCart: writer.String("CreateCart"); break;
    case TransactionStatusInit: writer.String("Init"); break;
    case TransactionStatusApproved: writer.String("Approved"); break;
    case TransactionStatusSucceeded: writer.String("Succeeded"); break;
    case TransactionStatusFailedByProvider: writer.String("FailedByProvider"); break;
    case TransactionStatusDisputePending: writer.String("DisputePending"); break;
    case TransactionStatusRefundPending: writer.String("RefundPending"); break;
    case TransactionStatusRefunded: writer.String("Refunded"); break;
    case TransactionStatusRefundFailed: writer.String("RefundFailed"); break;
    case TransactionStatusChargedBack: writer.String("ChargedBack"); break;
    case TransactionStatusFailedByUber: writer.String("FailedByUber"); break;
    case TransactionStatusFailedByPlayFab: writer.String("FailedByPlayFab"); break;
    case TransactionStatusRevoked: writer.String("Revoked"); break;
    case TransactionStatusTradePending: writer.String("TradePending"); break;
    case TransactionStatusTraded: writer.String("Traded"); break;
    case TransactionStatusUpgraded: writer.String("Upgraded"); break;
    case TransactionStatusStackPending: writer.String("StackPending"); break;
    case TransactionStatusStacked: writer.String("Stacked"); break;
    case TransactionStatusOther: writer.String("Other"); break;
    case TransactionStatusFailed: writer.String("Failed"); break;

    }
}

TransactionStatus PlayFab::ClientModels::readTransactionStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, TransactionStatus> _TransactionStatusMap;
    if (_TransactionStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _TransactionStatusMap["CreateCart"] = TransactionStatusCreateCart;
        _TransactionStatusMap["Init"] = TransactionStatusInit;
        _TransactionStatusMap["Approved"] = TransactionStatusApproved;
        _TransactionStatusMap["Succeeded"] = TransactionStatusSucceeded;
        _TransactionStatusMap["FailedByProvider"] = TransactionStatusFailedByProvider;
        _TransactionStatusMap["DisputePending"] = TransactionStatusDisputePending;
        _TransactionStatusMap["RefundPending"] = TransactionStatusRefundPending;
        _TransactionStatusMap["Refunded"] = TransactionStatusRefunded;
        _TransactionStatusMap["RefundFailed"] = TransactionStatusRefundFailed;
        _TransactionStatusMap["ChargedBack"] = TransactionStatusChargedBack;
        _TransactionStatusMap["FailedByUber"] = TransactionStatusFailedByUber;
        _TransactionStatusMap["FailedByPlayFab"] = TransactionStatusFailedByPlayFab;
        _TransactionStatusMap["Revoked"] = TransactionStatusRevoked;
        _TransactionStatusMap["TradePending"] = TransactionStatusTradePending;
        _TransactionStatusMap["Traded"] = TransactionStatusTraded;
        _TransactionStatusMap["Upgraded"] = TransactionStatusUpgraded;
        _TransactionStatusMap["StackPending"] = TransactionStatusStackPending;
        _TransactionStatusMap["Stacked"] = TransactionStatusStacked;
        _TransactionStatusMap["Other"] = TransactionStatusOther;
        _TransactionStatusMap["Failed"] = TransactionStatusFailed;

    }

    auto output = _TransactionStatusMap.find(obj.GetString());
    if (output != _TransactionStatusMap.end())
        return output->second;

    return TransactionStatusCreateCart; // Basically critical fail
}

PayForPurchaseResult::~PayForPurchaseResult()
{

}

void PayForPurchaseResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (OrderId.length() > 0) { writer.String("OrderId"); writer.String(OrderId.c_str()); }
    if (Status.notNull()) { writer.String("Status"); writeTransactionStatusEnumJSON(Status, writer); }
    if (!VCAmount.empty()) {
    writer.String("VCAmount");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = VCAmount.begin(); iter != VCAmount.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }
    if (PurchaseCurrency.length() > 0) { writer.String("PurchaseCurrency"); writer.String(PurchaseCurrency.c_str()); }
    writer.String("PurchasePrice"); writer.Uint(PurchasePrice);
    writer.String("CreditApplied"); writer.Uint(CreditApplied);
    if (ProviderData.length() > 0) { writer.String("ProviderData"); writer.String(ProviderData.c_str()); }
    if (PurchaseConfirmationPageURL.length() > 0) { writer.String("PurchaseConfirmationPageURL"); writer.String(PurchaseConfirmationPageURL.c_str()); }
    if (!VirtualCurrency.empty()) {
    writer.String("VirtualCurrency");
    writer.StartObject();
    for (std::map<std::string, Int32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
        writer.String(iter->first.c_str()); writer.Int(iter->second);
    }
    writer.EndObject();
     }

    writer.EndObject();
}

bool PayForPurchaseResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
    if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
    const Value::Member* Status_member = obj.FindMember("Status");
    if (Status_member != NULL && !Status_member->value.IsNull()) Status = readTransactionStatusFromValue(Status_member->value);
    const Value::Member* VCAmount_member = obj.FindMember("VCAmount");
    if (VCAmount_member != NULL) {
        for (Value::ConstMemberIterator iter = VCAmount_member->value.MemberBegin(); iter != VCAmount_member->value.MemberEnd(); ++iter) {
            VCAmount[iter->name.GetString()] = iter->value.GetInt();
        }
    }
    const Value::Member* PurchaseCurrency_member = obj.FindMember("PurchaseCurrency");
    if (PurchaseCurrency_member != NULL && !PurchaseCurrency_member->value.IsNull()) PurchaseCurrency = PurchaseCurrency_member->value.GetString();
    const Value::Member* PurchasePrice_member = obj.FindMember("PurchasePrice");
    if (PurchasePrice_member != NULL && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetUint();
    const Value::Member* CreditApplied_member = obj.FindMember("CreditApplied");
    if (CreditApplied_member != NULL && !CreditApplied_member->value.IsNull()) CreditApplied = CreditApplied_member->value.GetUint();
    const Value::Member* ProviderData_member = obj.FindMember("ProviderData");
    if (ProviderData_member != NULL && !ProviderData_member->value.IsNull()) ProviderData = ProviderData_member->value.GetString();
    const Value::Member* PurchaseConfirmationPageURL_member = obj.FindMember("PurchaseConfirmationPageURL");
    if (PurchaseConfirmationPageURL_member != NULL && !PurchaseConfirmationPageURL_member->value.IsNull()) PurchaseConfirmationPageURL = PurchaseConfirmationPageURL_member->value.GetString();
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
        }
    }

    return true;
}

PaymentOption::~PaymentOption()
{

}

void PaymentOption::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (Currency.length() > 0) { writer.String("Currency"); writer.String(Currency.c_str()); }
    if (ProviderName.length() > 0) { writer.String("ProviderName"); writer.String(ProviderName.c_str()); }
    writer.String("Price"); writer.Uint(Price);
    writer.String("StoreCredit"); writer.Uint(StoreCredit);

    writer.EndObject();
}

bool PaymentOption::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Currency_member = obj.FindMember("Currency");
    if (Currency_member != NULL && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
    const Value::Member* ProviderName_member = obj.FindMember("ProviderName");
    if (ProviderName_member != NULL && !ProviderName_member->value.IsNull()) ProviderName = ProviderName_member->value.GetString();
    const Value::Member* Price_member = obj.FindMember("Price");
    if (Price_member != NULL && !Price_member->value.IsNull()) Price = Price_member->value.GetUint();
    const Value::Member* StoreCredit_member = obj.FindMember("StoreCredit");
    if (StoreCredit_member != NULL && !StoreCredit_member->value.IsNull()) StoreCredit = StoreCredit_member->value.GetUint();

    return true;
}

PurchaseItemRequest::~PurchaseItemRequest()
{

}

void PurchaseItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ItemId"); writer.String(ItemId.c_str());
    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.String("Price"); writer.Int(Price);
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (StoreId.length() > 0) { writer.String("StoreId"); writer.String(StoreId.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }

    writer.EndObject();
}

bool PurchaseItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ItemId_member = obj.FindMember("ItemId");
    if (ItemId_member != NULL && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* Price_member = obj.FindMember("Price");
    if (Price_member != NULL && !Price_member->value.IsNull()) Price = Price_member->value.GetInt();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* StoreId_member = obj.FindMember("StoreId");
    if (StoreId_member != NULL && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

    return true;
}

PurchaseItemResult::~PurchaseItemResult()
{

}

void PurchaseItemResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (!Items.empty()) {
    writer.String("Items");
    writer.StartArray();
    for (std::list<ItemInstance>::iterator iter = Items.begin(); iter != Items.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }

    writer.EndObject();
}

bool PurchaseItemResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Items_member = obj.FindMember("Items");
    if (Items_member != NULL) {
        const rapidjson::Value& memberList = Items_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Items.push_back(ItemInstance(memberList[i]));
        }
    }

    return true;
}

RedeemCouponRequest::~RedeemCouponRequest()
{

}

void RedeemCouponRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("CouponCode"); writer.String(CouponCode.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }

    writer.EndObject();
}

bool RedeemCouponRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* CouponCode_member = obj.FindMember("CouponCode");
    if (CouponCode_member != NULL && !CouponCode_member->value.IsNull()) CouponCode = CouponCode_member->value.GetString();
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

RefreshPSNAuthTokenRequest::~RefreshPSNAuthTokenRequest()
{

}

void RefreshPSNAuthTokenRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("AuthCode"); writer.String(AuthCode.c_str());
    writer.String("RedirectUri"); writer.String(RedirectUri.c_str());
    if (IssuerId.notNull()) { writer.String("IssuerId"); writer.Int(IssuerId); }

    writer.EndObject();
}

bool RefreshPSNAuthTokenRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* AuthCode_member = obj.FindMember("AuthCode");
    if (AuthCode_member != NULL && !AuthCode_member->value.IsNull()) AuthCode = AuthCode_member->value.GetString();
    const Value::Member* RedirectUri_member = obj.FindMember("RedirectUri");
    if (RedirectUri_member != NULL && !RedirectUri_member->value.IsNull()) RedirectUri = RedirectUri_member->value.GetString();
    const Value::Member* IssuerId_member = obj.FindMember("IssuerId");
    if (IssuerId_member != NULL && !IssuerId_member->value.IsNull()) IssuerId = IssuerId_member->value.GetInt();

    return true;
}

RegisterForIOSPushNotificationRequest::~RegisterForIOSPushNotificationRequest()
{

}

void RegisterForIOSPushNotificationRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("DeviceToken"); writer.String(DeviceToken.c_str());
    if (SendPushNotificationConfirmation.notNull()) { writer.String("SendPushNotificationConfirmation"); writer.Bool(SendPushNotificationConfirmation); }
    if (ConfirmationMessage.length() > 0) { writer.String("ConfirmationMessage"); writer.String(ConfirmationMessage.c_str()); }

    writer.EndObject();
}

bool RegisterForIOSPushNotificationRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* DeviceToken_member = obj.FindMember("DeviceToken");
    if (DeviceToken_member != NULL && !DeviceToken_member->value.IsNull()) DeviceToken = DeviceToken_member->value.GetString();
    const Value::Member* SendPushNotificationConfirmation_member = obj.FindMember("SendPushNotificationConfirmation");
    if (SendPushNotificationConfirmation_member != NULL && !SendPushNotificationConfirmation_member->value.IsNull()) SendPushNotificationConfirmation = SendPushNotificationConfirmation_member->value.GetBool();
    const Value::Member* ConfirmationMessage_member = obj.FindMember("ConfirmationMessage");
    if (ConfirmationMessage_member != NULL && !ConfirmationMessage_member->value.IsNull()) ConfirmationMessage = ConfirmationMessage_member->value.GetString();

    return true;
}

RegisterForIOSPushNotificationResult::~RegisterForIOSPushNotificationResult()
{

}

void RegisterForIOSPushNotificationResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool RegisterForIOSPushNotificationResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

RegisterPlayFabUserRequest::~RegisterPlayFabUserRequest()
{

}

void RegisterPlayFabUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("TitleId"); writer.String(TitleId.c_str());
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    if (Email.length() > 0) { writer.String("Email"); writer.String(Email.c_str()); }
    writer.String("Password"); writer.String(Password.c_str());
    if (RequireBothUsernameAndEmail.notNull()) { writer.String("RequireBothUsernameAndEmail"); writer.Bool(RequireBothUsernameAndEmail); }
    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }
    if (Origination.length() > 0) { writer.String("Origination"); writer.String(Origination.c_str()); }

    writer.EndObject();
}

bool RegisterPlayFabUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::Member* Email_member = obj.FindMember("Email");
    if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::Member* Password_member = obj.FindMember("Password");
    if (Password_member != NULL && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
    const Value::Member* RequireBothUsernameAndEmail_member = obj.FindMember("RequireBothUsernameAndEmail");
    if (RequireBothUsernameAndEmail_member != NULL && !RequireBothUsernameAndEmail_member->value.IsNull()) RequireBothUsernameAndEmail = RequireBothUsernameAndEmail_member->value.GetBool();
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
    const Value::Member* Origination_member = obj.FindMember("Origination");
    if (Origination_member != NULL && !Origination_member->value.IsNull()) Origination = Origination_member->value.GetString();

    return true;
}

RegisterPlayFabUserResult::~RegisterPlayFabUserResult()
{

}

void RegisterPlayFabUserResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (PlayFabId.length() > 0) { writer.String("PlayFabId"); writer.String(PlayFabId.c_str()); }
    if (SessionTicket.length() > 0) { writer.String("SessionTicket"); writer.String(SessionTicket.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }

    writer.EndObject();
}

bool RegisterPlayFabUserResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* PlayFabId_member = obj.FindMember("PlayFabId");
    if (PlayFabId_member != NULL && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
    const Value::Member* SessionTicket_member = obj.FindMember("SessionTicket");
    if (SessionTicket_member != NULL && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();
    const Value::Member* Username_member = obj.FindMember("Username");
    if (Username_member != NULL && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

    return true;
}

RemoveFriendRequest::~RemoveFriendRequest()
{

}

void RemoveFriendRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str());

    writer.EndObject();
}

bool RemoveFriendRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != NULL && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();

    return true;
}

RemoveFriendResult::~RemoveFriendResult()
{

}

void RemoveFriendResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool RemoveFriendResult::readFromValue(const rapidjson::Value& obj)
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
    writer.String("PlayFabIds");
    writer.StartArray();
    for (std::list<std::string>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
        writer.String(iter->c_str());
    }
    writer.EndArray();
    

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

ReportPlayerClientRequest::~ReportPlayerClientRequest()
{

}

void ReportPlayerClientRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ReporteeId"); writer.String(ReporteeId.c_str());
    if (Comment.length() > 0) { writer.String("Comment"); writer.String(Comment.c_str()); }

    writer.EndObject();
}

bool ReportPlayerClientRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ReporteeId_member = obj.FindMember("ReporteeId");
    if (ReporteeId_member != NULL && !ReporteeId_member->value.IsNull()) ReporteeId = ReporteeId_member->value.GetString();
    const Value::Member* Comment_member = obj.FindMember("Comment");
    if (Comment_member != NULL && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();

    return true;
}

ReportPlayerClientResult::~ReportPlayerClientResult()
{

}

void ReportPlayerClientResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Updated"); writer.Bool(Updated);
    writer.String("SubmissionsRemaining"); writer.Int(SubmissionsRemaining);

    writer.EndObject();
}

bool ReportPlayerClientResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Updated_member = obj.FindMember("Updated");
    if (Updated_member != NULL && !Updated_member->value.IsNull()) Updated = Updated_member->value.GetBool();
    const Value::Member* SubmissionsRemaining_member = obj.FindMember("SubmissionsRemaining");
    if (SubmissionsRemaining_member != NULL && !SubmissionsRemaining_member->value.IsNull()) SubmissionsRemaining = SubmissionsRemaining_member->value.GetInt();

    return true;
}

RestoreIOSPurchasesRequest::~RestoreIOSPurchasesRequest()
{

}

void RestoreIOSPurchasesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ReceiptData"); writer.String(ReceiptData.c_str());

    writer.EndObject();
}

bool RestoreIOSPurchasesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ReceiptData_member = obj.FindMember("ReceiptData");
    if (ReceiptData_member != NULL && !ReceiptData_member->value.IsNull()) ReceiptData = ReceiptData_member->value.GetString();

    return true;
}

RestoreIOSPurchasesResult::~RestoreIOSPurchasesResult()
{

}

void RestoreIOSPurchasesResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool RestoreIOSPurchasesResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

RunCloudScriptRequest::~RunCloudScriptRequest()
{

}

void RunCloudScriptRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ActionId"); writer.String(ActionId.c_str());
    if (Params.notNull()) { writer.String("Params"); Params.writeJSON(writer); }
    if (ParamsEncoded.length() > 0) { writer.String("ParamsEncoded"); writer.String(ParamsEncoded.c_str()); }

    writer.EndObject();
}

bool RunCloudScriptRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ActionId_member = obj.FindMember("ActionId");
    if (ActionId_member != NULL && !ActionId_member->value.IsNull()) ActionId = ActionId_member->value.GetString();
    const Value::Member* Params_member = obj.FindMember("Params");
    if (Params_member != NULL && !Params_member->value.IsNull()) Params = MultitypeVar(Params_member->value);
    const Value::Member* ParamsEncoded_member = obj.FindMember("ParamsEncoded");
    if (ParamsEncoded_member != NULL && !ParamsEncoded_member->value.IsNull()) ParamsEncoded = ParamsEncoded_member->value.GetString();

    return true;
}

RunCloudScriptResult::~RunCloudScriptResult()
{

}

void RunCloudScriptResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (ActionId.length() > 0) { writer.String("ActionId"); writer.String(ActionId.c_str()); }
    writer.String("Version"); writer.Int(Version);
    writer.String("Revision"); writer.Int(Revision);
    if (Results.notNull()) { writer.String("Results"); Results.writeJSON(writer); }
    if (ResultsEncoded.length() > 0) { writer.String("ResultsEncoded"); writer.String(ResultsEncoded.c_str()); }
    if (ActionLog.length() > 0) { writer.String("ActionLog"); writer.String(ActionLog.c_str()); }
    writer.String("ExecutionTime"); writer.Double(ExecutionTime);

    writer.EndObject();
}

bool RunCloudScriptResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ActionId_member = obj.FindMember("ActionId");
    if (ActionId_member != NULL && !ActionId_member->value.IsNull()) ActionId = ActionId_member->value.GetString();
    const Value::Member* Version_member = obj.FindMember("Version");
    if (Version_member != NULL && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
    const Value::Member* Revision_member = obj.FindMember("Revision");
    if (Revision_member != NULL && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
    const Value::Member* Results_member = obj.FindMember("Results");
    if (Results_member != NULL && !Results_member->value.IsNull()) Results = MultitypeVar(Results_member->value);
    const Value::Member* ResultsEncoded_member = obj.FindMember("ResultsEncoded");
    if (ResultsEncoded_member != NULL && !ResultsEncoded_member->value.IsNull()) ResultsEncoded = ResultsEncoded_member->value.GetString();
    const Value::Member* ActionLog_member = obj.FindMember("ActionLog");
    if (ActionLog_member != NULL && !ActionLog_member->value.IsNull()) ActionLog = ActionLog_member->value.GetString();
    const Value::Member* ExecutionTime_member = obj.FindMember("ExecutionTime");
    if (ExecutionTime_member != NULL && !ExecutionTime_member->value.IsNull()) ExecutionTime = ExecutionTime_member->value.GetDouble();

    return true;
}

SendAccountRecoveryEmailRequest::~SendAccountRecoveryEmailRequest()
{

}

void SendAccountRecoveryEmailRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("Email"); writer.String(Email.c_str());
    writer.String("TitleId"); writer.String(TitleId.c_str());
    if (PublisherId.length() > 0) { writer.String("PublisherId"); writer.String(PublisherId.c_str()); }

    writer.EndObject();
}

bool SendAccountRecoveryEmailRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* Email_member = obj.FindMember("Email");
    if (Email_member != NULL && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
    const Value::Member* TitleId_member = obj.FindMember("TitleId");
    if (TitleId_member != NULL && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
    const Value::Member* PublisherId_member = obj.FindMember("PublisherId");
    if (PublisherId_member != NULL && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();

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

SetFriendTagsRequest::~SetFriendTagsRequest()
{

}

void SetFriendTagsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("FriendPlayFabId"); writer.String(FriendPlayFabId.c_str());
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
    const Value::Member* FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
    if (FriendPlayFabId_member != NULL && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
    const Value::Member* Tags_member = obj.FindMember("Tags");
    if (Tags_member != NULL) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }

    return true;
}

SetFriendTagsResult::~SetFriendTagsResult()
{

}

void SetFriendTagsResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool SetFriendTagsResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

StartGameRequest::~StartGameRequest()
{

}

void StartGameRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("BuildVersion"); writer.String(BuildVersion.c_str());
    writer.String("Region"); writeRegionEnumJSON(pfRegion, writer);
    writer.String("GameMode"); writer.String(GameMode.c_str());
    if (StatisticName.length() > 0) { writer.String("StatisticName"); writer.String(StatisticName.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }
    if (CustomCommandLineData.length() > 0) { writer.String("CustomCommandLineData"); writer.String(CustomCommandLineData.c_str()); }

    writer.EndObject();
}

bool StartGameRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* BuildVersion_member = obj.FindMember("BuildVersion");
    if (BuildVersion_member != NULL && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
    const Value::Member* Region_member = obj.FindMember("Region");
    if (Region_member != NULL && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
    const Value::Member* GameMode_member = obj.FindMember("GameMode");
    if (GameMode_member != NULL && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
    const Value::Member* StatisticName_member = obj.FindMember("StatisticName");
    if (StatisticName_member != NULL && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
    const Value::Member* CustomCommandLineData_member = obj.FindMember("CustomCommandLineData");
    if (CustomCommandLineData_member != NULL && !CustomCommandLineData_member->value.IsNull()) CustomCommandLineData = CustomCommandLineData_member->value.GetString();

    return true;
}

StartGameResult::~StartGameResult()
{

}

void StartGameResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (LobbyID.length() > 0) { writer.String("LobbyID"); writer.String(LobbyID.c_str()); }
    if (ServerHostname.length() > 0) { writer.String("ServerHostname"); writer.String(ServerHostname.c_str()); }
    if (ServerPort.notNull()) { writer.String("ServerPort"); writer.Int(ServerPort); }
    if (Ticket.length() > 0) { writer.String("Ticket"); writer.String(Ticket.c_str()); }
    if (Expires.length() > 0) { writer.String("Expires"); writer.String(Expires.c_str()); }
    if (Password.length() > 0) { writer.String("Password"); writer.String(Password.c_str()); }

    writer.EndObject();
}

bool StartGameResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* LobbyID_member = obj.FindMember("LobbyID");
    if (LobbyID_member != NULL && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
    const Value::Member* ServerHostname_member = obj.FindMember("ServerHostname");
    if (ServerHostname_member != NULL && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
    const Value::Member* ServerPort_member = obj.FindMember("ServerPort");
    if (ServerPort_member != NULL && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetInt();
    const Value::Member* Ticket_member = obj.FindMember("Ticket");
    if (Ticket_member != NULL && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();
    const Value::Member* Expires_member = obj.FindMember("Expires");
    if (Expires_member != NULL && !Expires_member->value.IsNull()) Expires = Expires_member->value.GetString();
    const Value::Member* Password_member = obj.FindMember("Password");
    if (Password_member != NULL && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

    return true;
}

StartPurchaseRequest::~StartPurchaseRequest()
{

}

void StartPurchaseRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (StoreId.length() > 0) { writer.String("StoreId"); writer.String(StoreId.c_str()); }
    writer.String("Items");
    writer.StartArray();
    for (std::list<ItemPuchaseRequest>::iterator iter = Items.begin(); iter != Items.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    

    writer.EndObject();
}

bool StartPurchaseRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* StoreId_member = obj.FindMember("StoreId");
    if (StoreId_member != NULL && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
    const Value::Member* Items_member = obj.FindMember("Items");
    if (Items_member != NULL) {
        const rapidjson::Value& memberList = Items_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Items.push_back(ItemPuchaseRequest(memberList[i]));
        }
    }

    return true;
}

StartPurchaseResult::~StartPurchaseResult()
{

}

void StartPurchaseResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (OrderId.length() > 0) { writer.String("OrderId"); writer.String(OrderId.c_str()); }
    if (!Contents.empty()) {
    writer.String("Contents");
    writer.StartArray();
    for (std::list<CartItem>::iterator iter = Contents.begin(); iter != Contents.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
     }
    if (!PaymentOptions.empty()) {
    writer.String("PaymentOptions");
    writer.StartArray();
    for (std::list<PaymentOption>::iterator iter = PaymentOptions.begin(); iter != PaymentOptions.end(); iter++) {
        iter->writeJSON(writer);
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

    writer.EndObject();
}

bool StartPurchaseResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* OrderId_member = obj.FindMember("OrderId");
    if (OrderId_member != NULL && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
    const Value::Member* Contents_member = obj.FindMember("Contents");
    if (Contents_member != NULL) {
        const rapidjson::Value& memberList = Contents_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Contents.push_back(CartItem(memberList[i]));
        }
    }
    const Value::Member* PaymentOptions_member = obj.FindMember("PaymentOptions");
    if (PaymentOptions_member != NULL) {
        const rapidjson::Value& memberList = PaymentOptions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PaymentOptions.push_back(PaymentOption(memberList[i]));
        }
    }
    const Value::Member* VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
    if (VirtualCurrencyBalances_member != NULL) {
        for (Value::ConstMemberIterator iter = VirtualCurrencyBalances_member->value.MemberBegin(); iter != VirtualCurrencyBalances_member->value.MemberEnd(); ++iter) {
            VirtualCurrencyBalances[iter->name.GetString()] = iter->value.GetInt();
        }
    }

    return true;
}

SubtractUserVirtualCurrencyRequest::~SubtractUserVirtualCurrencyRequest()
{

}

void SubtractUserVirtualCurrencyRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("VirtualCurrency"); writer.String(VirtualCurrency.c_str());
    writer.String("Amount"); writer.Int(Amount);

    writer.EndObject();
}

bool SubtractUserVirtualCurrencyRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
    const Value::Member* Amount_member = obj.FindMember("Amount");
    if (Amount_member != NULL && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

    return true;
}

UnlinkAndroidDeviceIDRequest::~UnlinkAndroidDeviceIDRequest()
{

}

void UnlinkAndroidDeviceIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (AndroidDeviceId.length() > 0) { writer.String("AndroidDeviceId"); writer.String(AndroidDeviceId.c_str()); }

    writer.EndObject();
}

bool UnlinkAndroidDeviceIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
    if (AndroidDeviceId_member != NULL && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();

    return true;
}

UnlinkAndroidDeviceIDResult::~UnlinkAndroidDeviceIDResult()
{

}

void UnlinkAndroidDeviceIDResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkAndroidDeviceIDResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkCustomIDRequest::~UnlinkCustomIDRequest()
{

}

void UnlinkCustomIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (CustomId.length() > 0) { writer.String("CustomId"); writer.String(CustomId.c_str()); }

    writer.EndObject();
}

bool UnlinkCustomIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* CustomId_member = obj.FindMember("CustomId");
    if (CustomId_member != NULL && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

    return true;
}

UnlinkCustomIDResult::~UnlinkCustomIDResult()
{

}

void UnlinkCustomIDResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkCustomIDResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkFacebookAccountRequest::~UnlinkFacebookAccountRequest()
{

}

void UnlinkFacebookAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkFacebookAccountRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkFacebookAccountResult::~UnlinkFacebookAccountResult()
{

}

void UnlinkFacebookAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkFacebookAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkGameCenterAccountRequest::~UnlinkGameCenterAccountRequest()
{

}

void UnlinkGameCenterAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkGameCenterAccountRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkGameCenterAccountResult::~UnlinkGameCenterAccountResult()
{

}

void UnlinkGameCenterAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkGameCenterAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkGoogleAccountRequest::~UnlinkGoogleAccountRequest()
{

}

void UnlinkGoogleAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkGoogleAccountRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkGoogleAccountResult::~UnlinkGoogleAccountResult()
{

}

void UnlinkGoogleAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkGoogleAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkIOSDeviceIDRequest::~UnlinkIOSDeviceIDRequest()
{

}

void UnlinkIOSDeviceIDRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    if (DeviceId.length() > 0) { writer.String("DeviceId"); writer.String(DeviceId.c_str()); }

    writer.EndObject();
}

bool UnlinkIOSDeviceIDRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* DeviceId_member = obj.FindMember("DeviceId");
    if (DeviceId_member != NULL && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();

    return true;
}

UnlinkIOSDeviceIDResult::~UnlinkIOSDeviceIDResult()
{

}

void UnlinkIOSDeviceIDResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkIOSDeviceIDResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkKongregateAccountRequest::~UnlinkKongregateAccountRequest()
{

}

void UnlinkKongregateAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkKongregateAccountRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkKongregateAccountResult::~UnlinkKongregateAccountResult()
{

}

void UnlinkKongregateAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkKongregateAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkPSNAccountRequest::~UnlinkPSNAccountRequest()
{

}

void UnlinkPSNAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkPSNAccountRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkPSNAccountResult::~UnlinkPSNAccountResult()
{

}

void UnlinkPSNAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkPSNAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkSteamAccountRequest::~UnlinkSteamAccountRequest()
{

}

void UnlinkSteamAccountRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkSteamAccountRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlinkSteamAccountResult::~UnlinkSteamAccountResult()
{

}

void UnlinkSteamAccountResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool UnlinkSteamAccountResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

UnlockContainerItemRequest::~UnlockContainerItemRequest()
{

}

void UnlockContainerItemRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ContainerItemId"); writer.String(ContainerItemId.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    if (CharacterId.length() > 0) { writer.String("CharacterId"); writer.String(CharacterId.c_str()); }

    writer.EndObject();
}

bool UnlockContainerItemRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ContainerItemId_member = obj.FindMember("ContainerItemId");
    if (ContainerItemId_member != NULL && !ContainerItemId_member->value.IsNull()) ContainerItemId = ContainerItemId_member->value.GetString();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* CharacterId_member = obj.FindMember("CharacterId");
    if (CharacterId_member != NULL && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

    return true;
}

UnlockContainerItemResult::~UnlockContainerItemResult()
{

}

void UnlockContainerItemResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("UnlockedItemInstanceId"); writer.String(UnlockedItemInstanceId.c_str());
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
    const Value::Member* UnlockedItemInstanceId_member = obj.FindMember("UnlockedItemInstanceId");
    if (UnlockedItemInstanceId_member != NULL && !UnlockedItemInstanceId_member->value.IsNull()) UnlockedItemInstanceId = UnlockedItemInstanceId_member->value.GetString();
    const Value::Member* UnlockedWithItemInstanceId_member = obj.FindMember("UnlockedWithItemInstanceId");
    if (UnlockedWithItemInstanceId_member != NULL && !UnlockedWithItemInstanceId_member->value.IsNull()) UnlockedWithItemInstanceId = UnlockedWithItemInstanceId_member->value.GetString();
    const Value::Member* GrantedItems_member = obj.FindMember("GrantedItems");
    if (GrantedItems_member != NULL) {
        const rapidjson::Value& memberList = GrantedItems_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GrantedItems.push_back(ItemInstance(memberList[i]));
        }
    }
    const Value::Member* VirtualCurrency_member = obj.FindMember("VirtualCurrency");
    if (VirtualCurrency_member != NULL) {
        for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
            VirtualCurrency[iter->name.GetString()] = iter->value.GetUint();
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

    writer.EndObject();
}

bool UpdateCharacterDataRequest::readFromValue(const rapidjson::Value& obj)
{
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

UpdateUserStatisticsRequest::~UpdateUserStatisticsRequest()
{

}

void UpdateUserStatisticsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

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

UpdateUserTitleDisplayNameRequest::~UpdateUserTitleDisplayNameRequest()
{

}

void UpdateUserTitleDisplayNameRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("DisplayName"); writer.String(DisplayName.c_str());

    writer.EndObject();
}

bool UpdateUserTitleDisplayNameRequest::readFromValue(const rapidjson::Value& obj)
{
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

    if (DisplayName.length() > 0) { writer.String("DisplayName"); writer.String(DisplayName.c_str()); }

    writer.EndObject();
}

bool UpdateUserTitleDisplayNameResult::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* DisplayName_member = obj.FindMember("DisplayName");
    if (DisplayName_member != NULL && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

    return true;
}

ValidateAmazonReceiptRequest::~ValidateAmazonReceiptRequest()
{

}

void ValidateAmazonReceiptRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ReceiptId"); writer.String(ReceiptId.c_str());
    writer.String("UserId"); writer.String(UserId.c_str());
    if (CatalogVersion.length() > 0) { writer.String("CatalogVersion"); writer.String(CatalogVersion.c_str()); }
    writer.String("CurrencyCode"); writer.String(CurrencyCode.c_str());
    writer.String("PurchasePrice"); writer.Int(PurchasePrice);

    writer.EndObject();
}

bool ValidateAmazonReceiptRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ReceiptId_member = obj.FindMember("ReceiptId");
    if (ReceiptId_member != NULL && !ReceiptId_member->value.IsNull()) ReceiptId = ReceiptId_member->value.GetString();
    const Value::Member* UserId_member = obj.FindMember("UserId");
    if (UserId_member != NULL && !UserId_member->value.IsNull()) UserId = UserId_member->value.GetString();
    const Value::Member* CatalogVersion_member = obj.FindMember("CatalogVersion");
    if (CatalogVersion_member != NULL && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
    const Value::Member* CurrencyCode_member = obj.FindMember("CurrencyCode");
    if (CurrencyCode_member != NULL && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
    const Value::Member* PurchasePrice_member = obj.FindMember("PurchasePrice");
    if (PurchasePrice_member != NULL && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetInt();

    return true;
}

ValidateAmazonReceiptResult::~ValidateAmazonReceiptResult()
{

}

void ValidateAmazonReceiptResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool ValidateAmazonReceiptResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

ValidateGooglePlayPurchaseRequest::~ValidateGooglePlayPurchaseRequest()
{

}

void ValidateGooglePlayPurchaseRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ReceiptJson"); writer.String(ReceiptJson.c_str());
    writer.String("Signature"); writer.String(Signature.c_str());
    if (CurrencyCode.length() > 0) { writer.String("CurrencyCode"); writer.String(CurrencyCode.c_str()); }
    if (PurchasePrice.notNull()) { writer.String("PurchasePrice"); writer.Uint(PurchasePrice); }

    writer.EndObject();
}

bool ValidateGooglePlayPurchaseRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ReceiptJson_member = obj.FindMember("ReceiptJson");
    if (ReceiptJson_member != NULL && !ReceiptJson_member->value.IsNull()) ReceiptJson = ReceiptJson_member->value.GetString();
    const Value::Member* Signature_member = obj.FindMember("Signature");
    if (Signature_member != NULL && !Signature_member->value.IsNull()) Signature = Signature_member->value.GetString();
    const Value::Member* CurrencyCode_member = obj.FindMember("CurrencyCode");
    if (CurrencyCode_member != NULL && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
    const Value::Member* PurchasePrice_member = obj.FindMember("PurchasePrice");
    if (PurchasePrice_member != NULL && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetUint();

    return true;
}

ValidateGooglePlayPurchaseResult::~ValidateGooglePlayPurchaseResult()
{

}

void ValidateGooglePlayPurchaseResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool ValidateGooglePlayPurchaseResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

ValidateIOSReceiptRequest::~ValidateIOSReceiptRequest()
{

}

void ValidateIOSReceiptRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();

    writer.String("ReceiptData"); writer.String(ReceiptData.c_str());
    writer.String("CurrencyCode"); writer.String(CurrencyCode.c_str());
    writer.String("PurchasePrice"); writer.Int(PurchasePrice);

    writer.EndObject();
}

bool ValidateIOSReceiptRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::Member* ReceiptData_member = obj.FindMember("ReceiptData");
    if (ReceiptData_member != NULL && !ReceiptData_member->value.IsNull()) ReceiptData = ReceiptData_member->value.GetString();
    const Value::Member* CurrencyCode_member = obj.FindMember("CurrencyCode");
    if (CurrencyCode_member != NULL && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
    const Value::Member* PurchasePrice_member = obj.FindMember("PurchasePrice");
    if (PurchasePrice_member != NULL && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetInt();

    return true;
}

ValidateIOSReceiptResult::~ValidateIOSReceiptResult()
{

}

void ValidateIOSReceiptResult::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();


    writer.EndObject();
}

bool ValidateIOSReceiptResult::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

