#ifndef PLAYFAB_CLIENT_DATA_MODELS_H_
#define PLAYFAB_CLIENT_DATA_MODELS_H_

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ClientModels
    {
        struct AcceptTradeRequest : public PlayFabBaseModel
        {
            std::string OfferingPlayerId;
            std::string TradeId;
            std::list<std::string> AcceptedInventoryInstanceIds;

            AcceptTradeRequest() :
                PlayFabBaseModel(),
                OfferingPlayerId(),
                TradeId(),
                AcceptedInventoryInstanceIds()
            {}

            AcceptTradeRequest(const AcceptTradeRequest& src) :
                PlayFabBaseModel(),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds)
            {}

            AcceptTradeRequest(const rapidjson::Value& obj) : AcceptTradeRequest()
            {
                readFromValue(obj);
            }

            ~AcceptTradeRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum TradeStatus
        {
            TradeStatusInvalid,
            TradeStatusOpening,
            TradeStatusOpen,
            TradeStatusAccepting,
            TradeStatusAccepted,
            TradeStatusFilled,
            TradeStatusCancelled
        };

        void writeTradeStatusEnumJSON(TradeStatus enumVal, PFStringJsonWriter& writer);
        TradeStatus readTradeStatusFromValue(const rapidjson::Value& obj);

        struct TradeInfo : public PlayFabBaseModel
        {
            Boxed<TradeStatus> Status;
            std::string TradeId;
            std::string OfferingPlayerId;
            std::list<std::string> OfferedInventoryInstanceIds;
            std::list<std::string> OfferedCatalogItemIds;
            std::list<std::string> RequestedCatalogItemIds;
            std::list<std::string> AllowedPlayerIds;
            std::string AcceptedPlayerId;
            std::list<std::string> AcceptedInventoryInstanceIds;
            OptionalTime OpenedAt;
            OptionalTime FilledAt;
            OptionalTime CancelledAt;
            OptionalTime InvalidatedAt;

            TradeInfo() :
                PlayFabBaseModel(),
                Status(),
                TradeId(),
                OfferingPlayerId(),
                OfferedInventoryInstanceIds(),
                OfferedCatalogItemIds(),
                RequestedCatalogItemIds(),
                AllowedPlayerIds(),
                AcceptedPlayerId(),
                AcceptedInventoryInstanceIds(),
                OpenedAt(),
                FilledAt(),
                CancelledAt(),
                InvalidatedAt()
            {}

            TradeInfo(const TradeInfo& src) :
                PlayFabBaseModel(),
                Status(src.Status),
                TradeId(src.TradeId),
                OfferingPlayerId(src.OfferingPlayerId),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                OfferedCatalogItemIds(src.OfferedCatalogItemIds),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds),
                AllowedPlayerIds(src.AllowedPlayerIds),
                AcceptedPlayerId(src.AcceptedPlayerId),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                OpenedAt(src.OpenedAt),
                FilledAt(src.FilledAt),
                CancelledAt(src.CancelledAt),
                InvalidatedAt(src.InvalidatedAt)
            {}

            TradeInfo(const rapidjson::Value& obj) : TradeInfo()
            {
                readFromValue(obj);
            }

            ~TradeInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AcceptTradeResponse : public PlayFabBaseModel
        {
            TradeInfo* Trade;

            AcceptTradeResponse() :
                PlayFabBaseModel(),
                Trade(NULL)
            {}

            AcceptTradeResponse(const AcceptTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : NULL)
            {}

            AcceptTradeResponse(const rapidjson::Value& obj) : AcceptTradeResponse()
            {
                readFromValue(obj);
            }

            ~AcceptTradeResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddFriendRequest : public PlayFabBaseModel
        {
            std::string FriendPlayFabId;
            std::string FriendUsername;
            std::string FriendEmail;
            std::string FriendTitleDisplayName;

            AddFriendRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                FriendUsername(),
                FriendEmail(),
                FriendTitleDisplayName()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendUsername(src.FriendUsername),
                FriendEmail(src.FriendEmail),
                FriendTitleDisplayName(src.FriendTitleDisplayName)
            {}

            AddFriendRequest(const rapidjson::Value& obj) : AddFriendRequest()
            {
                readFromValue(obj);
            }

            ~AddFriendRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddFriendResult : public PlayFabBaseModel
        {
            bool Created;

            AddFriendResult() :
                PlayFabBaseModel(),
                Created(false)
            {}

            AddFriendResult(const AddFriendResult& src) :
                PlayFabBaseModel(),
                Created(src.Created)
            {}

            AddFriendResult(const rapidjson::Value& obj) : AddFriendResult()
            {
                readFromValue(obj);
            }

            ~AddFriendResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddSharedGroupMembersRequest : public PlayFabBaseModel
        {
            std::string SharedGroupId;
            std::list<std::string> PlayFabIds;

            AddSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                PlayFabIds()
            {}

            AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                PlayFabIds(src.PlayFabIds)
            {}

            AddSharedGroupMembersRequest(const rapidjson::Value& obj) : AddSharedGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~AddSharedGroupMembersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddSharedGroupMembersResult : public PlayFabBaseModel
        {

            AddSharedGroupMembersResult() :
                PlayFabBaseModel()
            {}

            AddSharedGroupMembersResult(const AddSharedGroupMembersResult& src) :
                PlayFabBaseModel()
            {}

            AddSharedGroupMembersResult(const rapidjson::Value& obj) : AddSharedGroupMembersResult()
            {
                readFromValue(obj);
            }

            ~AddSharedGroupMembersResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddUsernamePasswordRequest : public PlayFabBaseModel
        {
            std::string Username;
            std::string Email;
            std::string Password;

            AddUsernamePasswordRequest() :
                PlayFabBaseModel(),
                Username(),
                Email(),
                Password()
            {}

            AddUsernamePasswordRequest(const AddUsernamePasswordRequest& src) :
                PlayFabBaseModel(),
                Username(src.Username),
                Email(src.Email),
                Password(src.Password)
            {}

            AddUsernamePasswordRequest(const rapidjson::Value& obj) : AddUsernamePasswordRequest()
            {
                readFromValue(obj);
            }

            ~AddUsernamePasswordRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddUsernamePasswordResult : public PlayFabBaseModel
        {
            std::string Username;

            AddUsernamePasswordResult() :
                PlayFabBaseModel(),
                Username()
            {}

            AddUsernamePasswordResult(const AddUsernamePasswordResult& src) :
                PlayFabBaseModel(),
                Username(src.Username)
            {}

            AddUsernamePasswordResult(const rapidjson::Value& obj) : AddUsernamePasswordResult()
            {
                readFromValue(obj);
            }

            ~AddUsernamePasswordResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            std::string VirtualCurrency;
            Int32 Amount;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                VirtualCurrency(),
                Amount(0)
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            AddUserVirtualCurrencyRequest(const rapidjson::Value& obj) : AddUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddUserVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AndroidDevicePushNotificationRegistrationRequest : public PlayFabBaseModel
        {
            std::string DeviceToken;
            OptionalBool SendPushNotificationConfirmation;
            std::string ConfirmationMessege;

            AndroidDevicePushNotificationRegistrationRequest() :
                PlayFabBaseModel(),
                DeviceToken(),
                SendPushNotificationConfirmation(),
                ConfirmationMessege()
            {}

            AndroidDevicePushNotificationRegistrationRequest(const AndroidDevicePushNotificationRegistrationRequest& src) :
                PlayFabBaseModel(),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation),
                ConfirmationMessege(src.ConfirmationMessege)
            {}

            AndroidDevicePushNotificationRegistrationRequest(const rapidjson::Value& obj) : AndroidDevicePushNotificationRegistrationRequest()
            {
                readFromValue(obj);
            }

            ~AndroidDevicePushNotificationRegistrationRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AndroidDevicePushNotificationRegistrationResult : public PlayFabBaseModel
        {

            AndroidDevicePushNotificationRegistrationResult() :
                PlayFabBaseModel()
            {}

            AndroidDevicePushNotificationRegistrationResult(const AndroidDevicePushNotificationRegistrationResult& src) :
                PlayFabBaseModel()
            {}

            AndroidDevicePushNotificationRegistrationResult(const rapidjson::Value& obj) : AndroidDevicePushNotificationRegistrationResult()
            {
                readFromValue(obj);
            }

            ~AndroidDevicePushNotificationRegistrationResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AttributeInstallRequest : public PlayFabBaseModel
        {
            std::string Idfa;
            std::string Android_Id;

            AttributeInstallRequest() :
                PlayFabBaseModel(),
                Idfa(),
                Android_Id()
            {}

            AttributeInstallRequest(const AttributeInstallRequest& src) :
                PlayFabBaseModel(),
                Idfa(src.Idfa),
                Android_Id(src.Android_Id)
            {}

            AttributeInstallRequest(const rapidjson::Value& obj) : AttributeInstallRequest()
            {
                readFromValue(obj);
            }

            ~AttributeInstallRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AttributeInstallResult : public PlayFabBaseModel
        {

            AttributeInstallResult() :
                PlayFabBaseModel()
            {}

            AttributeInstallResult(const AttributeInstallResult& src) :
                PlayFabBaseModel()
            {}

            AttributeInstallResult(const rapidjson::Value& obj) : AttributeInstallResult()
            {
                readFromValue(obj);
            }

            ~AttributeInstallResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CancelTradeRequest : public PlayFabBaseModel
        {
            std::string TradeId;

            CancelTradeRequest() :
                PlayFabBaseModel(),
                TradeId()
            {}

            CancelTradeRequest(const CancelTradeRequest& src) :
                PlayFabBaseModel(),
                TradeId(src.TradeId)
            {}

            CancelTradeRequest(const rapidjson::Value& obj) : CancelTradeRequest()
            {
                readFromValue(obj);
            }

            ~CancelTradeRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CancelTradeResponse : public PlayFabBaseModel
        {
            TradeInfo* Trade;

            CancelTradeResponse() :
                PlayFabBaseModel(),
                Trade(NULL)
            {}

            CancelTradeResponse(const CancelTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : NULL)
            {}

            CancelTradeResponse(const rapidjson::Value& obj) : CancelTradeResponse()
            {
                readFromValue(obj);
            }

            ~CancelTradeResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CartItem : public PlayFabBaseModel
        {
            std::string ItemId;
            std::string ItemClass;
            std::string ItemInstanceId;
            std::string DisplayName;
            std::string Description;
            std::map<std::string, Uint32> VirtualCurrencyPrices;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::map<std::string, Uint32> VCAmount;

            CartItem() :
                PlayFabBaseModel(),
                ItemId(),
                ItemClass(),
                ItemInstanceId(),
                DisplayName(),
                Description(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices(),
                VCAmount()
            {}

            CartItem(const CartItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemClass(src.ItemClass),
                ItemInstanceId(src.ItemInstanceId),
                DisplayName(src.DisplayName),
                Description(src.Description),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VCAmount(src.VCAmount)
            {}

            CartItem(const rapidjson::Value& obj) : CartItem()
            {
                readFromValue(obj);
            }

            ~CartItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CatalogItemConsumableInfo : public PlayFabBaseModel
        {
            OptionalUint32 UsageCount;
            OptionalUint32 UsagePeriod;
            std::string UsagePeriodGroup;

            CatalogItemConsumableInfo() :
                PlayFabBaseModel(),
                UsageCount(),
                UsagePeriod(),
                UsagePeriodGroup()
            {}

            CatalogItemConsumableInfo(const CatalogItemConsumableInfo& src) :
                PlayFabBaseModel(),
                UsageCount(src.UsageCount),
                UsagePeriod(src.UsagePeriod),
                UsagePeriodGroup(src.UsagePeriodGroup)
            {}

            CatalogItemConsumableInfo(const rapidjson::Value& obj) : CatalogItemConsumableInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemConsumableInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CatalogItemContainerInfo : public PlayFabBaseModel
        {
            std::string KeyItemId;
            std::list<std::string> ItemContents;
            std::list<std::string> ResultTableContents;
            std::map<std::string, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                KeyItemId(),
                ItemContents(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                KeyItemId(src.KeyItemId),
                ItemContents(src.ItemContents),
                ResultTableContents(src.ResultTableContents),
                VirtualCurrencyContents(src.VirtualCurrencyContents)
            {}

            CatalogItemContainerInfo(const rapidjson::Value& obj) : CatalogItemContainerInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemContainerInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CatalogItemBundleInfo : public PlayFabBaseModel
        {
            std::list<std::string> BundledItems;
            std::list<std::string> BundledResultTables;
            std::map<std::string, Uint32> BundledVirtualCurrencies;

            CatalogItemBundleInfo() :
                PlayFabBaseModel(),
                BundledItems(),
                BundledResultTables(),
                BundledVirtualCurrencies()
            {}

            CatalogItemBundleInfo(const CatalogItemBundleInfo& src) :
                PlayFabBaseModel(),
                BundledItems(src.BundledItems),
                BundledResultTables(src.BundledResultTables),
                BundledVirtualCurrencies(src.BundledVirtualCurrencies)
            {}

            CatalogItemBundleInfo(const rapidjson::Value& obj) : CatalogItemBundleInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemBundleInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CatalogItem : public PlayFabBaseModel
        {
            std::string ItemId;
            std::string ItemClass;
            std::string CatalogVersion;
            std::string DisplayName;
            std::string Description;
            std::map<std::string, Uint32> VirtualCurrencyPrices;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::list<std::string> Tags;
            std::string CustomData;
            CatalogItemConsumableInfo* Consumable;
            CatalogItemContainerInfo* Container;
            CatalogItemBundleInfo* Bundle;
            bool CanBecomeCharacter;
            bool IsStackable;
            bool IsTradable;
            std::string ItemImageUrl;

            CatalogItem() :
                PlayFabBaseModel(),
                ItemId(),
                ItemClass(),
                CatalogVersion(),
                DisplayName(),
                Description(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices(),
                Tags(),
                CustomData(),
                Consumable(NULL),
                Container(NULL),
                Bundle(NULL),
                CanBecomeCharacter(false),
                IsStackable(false),
                IsTradable(false),
                ItemImageUrl()
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemClass(src.ItemClass),
                CatalogVersion(src.CatalogVersion),
                DisplayName(src.DisplayName),
                Description(src.Description),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                CustomData(src.CustomData),
                Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : NULL),
                Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : NULL),
                Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : NULL),
                CanBecomeCharacter(src.CanBecomeCharacter),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemImageUrl(src.ItemImageUrl)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CharacterLeaderboardEntry : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string CharacterId;
            std::string CharacterName;
            std::string DisplayName;
            std::string CharacterType;
            Int32 StatValue;
            Int32 Position;

            CharacterLeaderboardEntry() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                CharacterName(),
                DisplayName(),
                CharacterType(),
                StatValue(0),
                Position(0)
            {}

            CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                DisplayName(src.DisplayName),
                CharacterType(src.CharacterType),
                StatValue(src.StatValue),
                Position(src.Position)
            {}

            CharacterLeaderboardEntry(const rapidjson::Value& obj) : CharacterLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~CharacterLeaderboardEntry();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CharacterResult : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string CharacterName;
            std::string CharacterType;

            CharacterResult() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType()
            {}

            CharacterResult(const CharacterResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType)
            {}

            CharacterResult(const rapidjson::Value& obj) : CharacterResult()
            {
                readFromValue(obj);
            }

            ~CharacterResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConfirmPurchaseRequest : public PlayFabBaseModel
        {
            std::string OrderId;

            ConfirmPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId()
            {}

            ConfirmPurchaseRequest(const ConfirmPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId)
            {}

            ConfirmPurchaseRequest(const rapidjson::Value& obj) : ConfirmPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ConfirmPurchaseRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ItemInstance : public PlayFabBaseModel
        {
            std::string ItemId;
            std::string ItemInstanceId;
            std::string ItemClass;
            OptionalTime PurchaseDate;
            OptionalTime Expiration;
            OptionalInt32 RemainingUses;
            OptionalInt32 UsesIncrementedBy;
            std::string Annotation;
            std::string CatalogVersion;
            std::string BundleParent;
            std::string DisplayName;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            std::list<std::string> BundleContents;
            std::map<std::string, std::string> CustomData;

            ItemInstance() :
                PlayFabBaseModel(),
                ItemId(),
                ItemInstanceId(),
                ItemClass(),
                PurchaseDate(),
                Expiration(),
                RemainingUses(),
                UsesIncrementedBy(),
                Annotation(),
                CatalogVersion(),
                BundleParent(),
                DisplayName(),
                UnitCurrency(),
                UnitPrice(0),
                BundleContents(),
                CustomData()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                ItemClass(src.ItemClass),
                PurchaseDate(src.PurchaseDate),
                Expiration(src.Expiration),
                RemainingUses(src.RemainingUses),
                UsesIncrementedBy(src.UsesIncrementedBy),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                BundleParent(src.BundleParent),
                DisplayName(src.DisplayName),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                BundleContents(src.BundleContents),
                CustomData(src.CustomData)
            {}

            ItemInstance(const rapidjson::Value& obj) : ItemInstance()
            {
                readFromValue(obj);
            }

            ~ItemInstance();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConfirmPurchaseResult : public PlayFabBaseModel
        {
            std::string OrderId;
            time_t PurchaseDate;
            std::list<ItemInstance> Items;

            ConfirmPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                PurchaseDate(0),
                Items()
            {}

            ConfirmPurchaseResult(const ConfirmPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                PurchaseDate(src.PurchaseDate),
                Items(src.Items)
            {}

            ConfirmPurchaseResult(const rapidjson::Value& obj) : ConfirmPurchaseResult()
            {
                readFromValue(obj);
            }

            ~ConfirmPurchaseResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConsumeItemRequest : public PlayFabBaseModel
        {
            std::string ItemInstanceId;
            Int32 ConsumeCount;
            std::string CharacterId;

            ConsumeItemRequest() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                ConsumeCount(0),
                CharacterId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                ConsumeCount(src.ConsumeCount),
                CharacterId(src.CharacterId)
            {}

            ConsumeItemRequest(const rapidjson::Value& obj) : ConsumeItemRequest()
            {
                readFromValue(obj);
            }

            ~ConsumeItemRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConsumeItemResult : public PlayFabBaseModel
        {
            std::string ItemInstanceId;
            Int32 RemainingUses;

            ConsumeItemResult() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                RemainingUses(0)
            {}

            ConsumeItemResult(const ConsumeItemResult& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ConsumeItemResult(const rapidjson::Value& obj) : ConsumeItemResult()
            {
                readFromValue(obj);
            }

            ~ConsumeItemResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConsumePSNEntitlementsRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            Int32 ServiceLabel;

            ConsumePSNEntitlementsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                ServiceLabel(0)
            {}

            ConsumePSNEntitlementsRequest(const ConsumePSNEntitlementsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                ServiceLabel(src.ServiceLabel)
            {}

            ConsumePSNEntitlementsRequest(const rapidjson::Value& obj) : ConsumePSNEntitlementsRequest()
            {
                readFromValue(obj);
            }

            ~ConsumePSNEntitlementsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConsumePSNEntitlementsResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> ItemsGranted;

            ConsumePSNEntitlementsResult() :
                PlayFabBaseModel(),
                ItemsGranted()
            {}

            ConsumePSNEntitlementsResult(const ConsumePSNEntitlementsResult& src) :
                PlayFabBaseModel(),
                ItemsGranted(src.ItemsGranted)
            {}

            ConsumePSNEntitlementsResult(const rapidjson::Value& obj) : ConsumePSNEntitlementsResult()
            {
                readFromValue(obj);
            }

            ~ConsumePSNEntitlementsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateSharedGroupRequest : public PlayFabBaseModel
        {
            std::string SharedGroupId;

            CreateSharedGroupRequest() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            CreateSharedGroupRequest(const CreateSharedGroupRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            CreateSharedGroupRequest(const rapidjson::Value& obj) : CreateSharedGroupRequest()
            {
                readFromValue(obj);
            }

            ~CreateSharedGroupRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateSharedGroupResult : public PlayFabBaseModel
        {
            std::string SharedGroupId;

            CreateSharedGroupResult() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            CreateSharedGroupResult(const CreateSharedGroupResult& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            CreateSharedGroupResult(const rapidjson::Value& obj) : CreateSharedGroupResult()
            {
                readFromValue(obj);
            }

            ~CreateSharedGroupResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum Currency
        {
            CurrencyAED,
            CurrencyAFN,
            CurrencyALL,
            CurrencyAMD,
            CurrencyANG,
            CurrencyAOA,
            CurrencyARS,
            CurrencyAUD,
            CurrencyAWG,
            CurrencyAZN,
            CurrencyBAM,
            CurrencyBBD,
            CurrencyBDT,
            CurrencyBGN,
            CurrencyBHD,
            CurrencyBIF,
            CurrencyBMD,
            CurrencyBND,
            CurrencyBOB,
            CurrencyBRL,
            CurrencyBSD,
            CurrencyBTN,
            CurrencyBWP,
            CurrencyBYR,
            CurrencyBZD,
            CurrencyCAD,
            CurrencyCDF,
            CurrencyCHF,
            CurrencyCLP,
            CurrencyCNY,
            CurrencyCOP,
            CurrencyCRC,
            CurrencyCUC,
            CurrencyCUP,
            CurrencyCVE,
            CurrencyCZK,
            CurrencyDJF,
            CurrencyDKK,
            CurrencyDOP,
            CurrencyDZD,
            CurrencyEGP,
            CurrencyERN,
            CurrencyETB,
            CurrencyEUR,
            CurrencyFJD,
            CurrencyFKP,
            CurrencyGBP,
            CurrencyGEL,
            CurrencyGGP,
            CurrencyGHS,
            CurrencyGIP,
            CurrencyGMD,
            CurrencyGNF,
            CurrencyGTQ,
            CurrencyGYD,
            CurrencyHKD,
            CurrencyHNL,
            CurrencyHRK,
            CurrencyHTG,
            CurrencyHUF,
            CurrencyIDR,
            CurrencyILS,
            CurrencyIMP,
            CurrencyINR,
            CurrencyIQD,
            CurrencyIRR,
            CurrencyISK,
            CurrencyJEP,
            CurrencyJMD,
            CurrencyJOD,
            CurrencyJPY,
            CurrencyKES,
            CurrencyKGS,
            CurrencyKHR,
            CurrencyKMF,
            CurrencyKPW,
            CurrencyKRW,
            CurrencyKWD,
            CurrencyKYD,
            CurrencyKZT,
            CurrencyLAK,
            CurrencyLBP,
            CurrencyLKR,
            CurrencyLRD,
            CurrencyLSL,
            CurrencyLYD,
            CurrencyMAD,
            CurrencyMDL,
            CurrencyMGA,
            CurrencyMKD,
            CurrencyMMK,
            CurrencyMNT,
            CurrencyMOP,
            CurrencyMRO,
            CurrencyMUR,
            CurrencyMVR,
            CurrencyMWK,
            CurrencyMXN,
            CurrencyMYR,
            CurrencyMZN,
            CurrencyNAD,
            CurrencyNGN,
            CurrencyNIO,
            CurrencyNOK,
            CurrencyNPR,
            CurrencyNZD,
            CurrencyOMR,
            CurrencyPAB,
            CurrencyPEN,
            CurrencyPGK,
            CurrencyPHP,
            CurrencyPKR,
            CurrencyPLN,
            CurrencyPYG,
            CurrencyQAR,
            CurrencyRON,
            CurrencyRSD,
            CurrencyRUB,
            CurrencyRWF,
            CurrencySAR,
            CurrencySBD,
            CurrencySCR,
            CurrencySDG,
            CurrencySEK,
            CurrencySGD,
            CurrencySHP,
            CurrencySLL,
            CurrencySOS,
            CurrencySPL,
            CurrencySRD,
            CurrencySTD,
            CurrencySVC,
            CurrencySYP,
            CurrencySZL,
            CurrencyTHB,
            CurrencyTJS,
            CurrencyTMT,
            CurrencyTND,
            CurrencyTOP,
            CurrencyTRY,
            CurrencyTTD,
            CurrencyTVD,
            CurrencyTWD,
            CurrencyTZS,
            CurrencyUAH,
            CurrencyUGX,
            CurrencyUSD,
            CurrencyUYU,
            CurrencyUZS,
            CurrencyVEF,
            CurrencyVND,
            CurrencyVUV,
            CurrencyWST,
            CurrencyXAF,
            CurrencyXCD,
            CurrencyXDR,
            CurrencyXOF,
            CurrencyXPF,
            CurrencyYER,
            CurrencyZAR,
            CurrencyZMW,
            CurrencyZWD
        };

        void writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer);
        Currency readCurrencyFromValue(const rapidjson::Value& obj);

        enum Region
        {
            RegionUSCentral,
            RegionUSEast,
            RegionEUWest,
            RegionSingapore,
            RegionJapan,
            RegionBrazil,
            RegionAustralia
        };

        void writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer);
        Region readRegionFromValue(const rapidjson::Value& obj);

        struct CurrentGamesRequest : public PlayFabBaseModel
        {
            Boxed<Region> pfRegion;
            std::string BuildVersion;
            std::string GameMode;
            std::string StatisticName;

            CurrentGamesRequest() :
                PlayFabBaseModel(),
                pfRegion(),
                BuildVersion(),
                GameMode(),
                StatisticName()
            {}

            CurrentGamesRequest(const CurrentGamesRequest& src) :
                PlayFabBaseModel(),
                pfRegion(src.pfRegion),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                StatisticName(src.StatisticName)
            {}

            CurrentGamesRequest(const rapidjson::Value& obj) : CurrentGamesRequest()
            {
                readFromValue(obj);
            }

            ~CurrentGamesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GameInfo : public PlayFabBaseModel
        {
            Boxed<Region> pfRegion;
            std::string LobbyID;
            std::string BuildVersion;
            std::string GameMode;
            std::string StatisticName;
            OptionalInt32 MaxPlayers;
            std::list<std::string> PlayerUserIds;
            Uint32 RunTime;
            std::string GameServerState;

            GameInfo() :
                PlayFabBaseModel(),
                pfRegion(),
                LobbyID(),
                BuildVersion(),
                GameMode(),
                StatisticName(),
                MaxPlayers(),
                PlayerUserIds(),
                RunTime(0),
                GameServerState()
            {}

            GameInfo(const GameInfo& src) :
                PlayFabBaseModel(),
                pfRegion(src.pfRegion),
                LobbyID(src.LobbyID),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                StatisticName(src.StatisticName),
                MaxPlayers(src.MaxPlayers),
                PlayerUserIds(src.PlayerUserIds),
                RunTime(src.RunTime),
                GameServerState(src.GameServerState)
            {}

            GameInfo(const rapidjson::Value& obj) : GameInfo()
            {
                readFromValue(obj);
            }

            ~GameInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CurrentGamesResult : public PlayFabBaseModel
        {
            std::list<GameInfo> Games;
            Int32 PlayerCount;
            Int32 GameCount;

            CurrentGamesResult() :
                PlayFabBaseModel(),
                Games(),
                PlayerCount(0),
                GameCount(0)
            {}

            CurrentGamesResult(const CurrentGamesResult& src) :
                PlayFabBaseModel(),
                Games(src.Games),
                PlayerCount(src.PlayerCount),
                GameCount(src.GameCount)
            {}

            CurrentGamesResult(const rapidjson::Value& obj) : CurrentGamesResult()
            {
                readFromValue(obj);
            }

            ~CurrentGamesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EmptyResult : public PlayFabBaseModel
        {

            EmptyResult() :
                PlayFabBaseModel()
            {}

            EmptyResult(const EmptyResult& src) :
                PlayFabBaseModel()
            {}

            EmptyResult(const rapidjson::Value& obj) : EmptyResult()
            {
                readFromValue(obj);
            }

            ~EmptyResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FacebookPlayFabIdPair : public PlayFabBaseModel
        {
            std::string FacebookId;
            std::string PlayFabId;

            FacebookPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookId(),
                PlayFabId()
            {}

            FacebookPlayFabIdPair(const FacebookPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                PlayFabId(src.PlayFabId)
            {}

            FacebookPlayFabIdPair(const rapidjson::Value& obj) : FacebookPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~FacebookPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserFacebookInfo : public PlayFabBaseModel
        {
            std::string FacebookId;
            std::string FullName;

            UserFacebookInfo() :
                PlayFabBaseModel(),
                FacebookId(),
                FullName()
            {}

            UserFacebookInfo(const UserFacebookInfo& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                FullName(src.FullName)
            {}

            UserFacebookInfo(const rapidjson::Value& obj) : UserFacebookInfo()
            {
                readFromValue(obj);
            }

            ~UserFacebookInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        void writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer);
        TitleActivationStatus readTitleActivationStatusFromValue(const rapidjson::Value& obj);

        struct UserSteamInfo : public PlayFabBaseModel
        {
            std::string SteamId;
            std::string SteamCountry;
            Boxed<Currency> SteamCurrency;
            Boxed<TitleActivationStatus> SteamActivationStatus;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamId(),
                SteamCountry(),
                SteamCurrency(),
                SteamActivationStatus()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamId(src.SteamId),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamActivationStatus(src.SteamActivationStatus)
            {}

            UserSteamInfo(const rapidjson::Value& obj) : UserSteamInfo()
            {
                readFromValue(obj);
            }

            ~UserSteamInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserGameCenterInfo : public PlayFabBaseModel
        {
            std::string GameCenterId;

            UserGameCenterInfo() :
                PlayFabBaseModel(),
                GameCenterId()
            {}

            UserGameCenterInfo(const UserGameCenterInfo& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId)
            {}

            UserGameCenterInfo(const rapidjson::Value& obj) : UserGameCenterInfo()
            {
                readFromValue(obj);
            }

            ~UserGameCenterInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FriendInfo : public PlayFabBaseModel
        {
            std::string FriendPlayFabId;
            std::string Username;
            std::string TitleDisplayName;
            std::list<std::string> Tags;
            std::string CurrentMatchmakerLobbyId;
            UserFacebookInfo* FacebookInfo;
            UserSteamInfo* SteamInfo;
            UserGameCenterInfo* GameCenterInfo;

            FriendInfo() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                Username(),
                TitleDisplayName(),
                Tags(),
                CurrentMatchmakerLobbyId(),
                FacebookInfo(NULL),
                SteamInfo(NULL),
                GameCenterInfo(NULL)
            {}

            FriendInfo(const FriendInfo& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                Username(src.Username),
                TitleDisplayName(src.TitleDisplayName),
                Tags(src.Tags),
                CurrentMatchmakerLobbyId(src.CurrentMatchmakerLobbyId),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : NULL),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : NULL),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL)
            {}

            FriendInfo(const rapidjson::Value& obj) : FriendInfo()
            {
                readFromValue(obj);
            }

            ~FriendInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GameCenterPlayFabIdPair : public PlayFabBaseModel
        {
            std::string GameCenterId;
            std::string PlayFabId;

            GameCenterPlayFabIdPair() :
                PlayFabBaseModel(),
                GameCenterId(),
                PlayFabId()
            {}

            GameCenterPlayFabIdPair(const GameCenterPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId),
                PlayFabId(src.PlayFabId)
            {}

            GameCenterPlayFabIdPair(const rapidjson::Value& obj) : GameCenterPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GameCenterPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GameServerRegionsRequest : public PlayFabBaseModel
        {
            std::string BuildVersion;
            std::string TitleId;

            GameServerRegionsRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                TitleId()
            {}

            GameServerRegionsRequest(const GameServerRegionsRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                TitleId(src.TitleId)
            {}

            GameServerRegionsRequest(const rapidjson::Value& obj) : GameServerRegionsRequest()
            {
                readFromValue(obj);
            }

            ~GameServerRegionsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegionInfo : public PlayFabBaseModel
        {
            Boxed<Region> pfRegion;
            std::string Name;
            bool Available;
            std::string PingUrl;

            RegionInfo() :
                PlayFabBaseModel(),
                pfRegion(),
                Name(),
                Available(false),
                PingUrl()
            {}

            RegionInfo(const RegionInfo& src) :
                PlayFabBaseModel(),
                pfRegion(src.pfRegion),
                Name(src.Name),
                Available(src.Available),
                PingUrl(src.PingUrl)
            {}

            RegionInfo(const rapidjson::Value& obj) : RegionInfo()
            {
                readFromValue(obj);
            }

            ~RegionInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GameServerRegionsResult : public PlayFabBaseModel
        {
            std::list<RegionInfo> Regions;

            GameServerRegionsResult() :
                PlayFabBaseModel(),
                Regions()
            {}

            GameServerRegionsResult(const GameServerRegionsResult& src) :
                PlayFabBaseModel(),
                Regions(src.Regions)
            {}

            GameServerRegionsResult(const rapidjson::Value& obj) : GameServerRegionsResult()
            {
                readFromValue(obj);
            }

            ~GameServerRegionsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAccountInfoRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string Username;
            std::string Email;
            std::string TitleDisplayName;

            GetAccountInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Username(),
                Email(),
                TitleDisplayName()
            {}

            GetAccountInfoRequest(const GetAccountInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Username(src.Username),
                Email(src.Email),
                TitleDisplayName(src.TitleDisplayName)
            {}

            GetAccountInfoRequest(const rapidjson::Value& obj) : GetAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetAccountInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum UserOrigination
        {
            UserOriginationOrganic,
            UserOriginationSteam,
            UserOriginationGoogle,
            UserOriginationAmazon,
            UserOriginationFacebook,
            UserOriginationKongregate,
            UserOriginationGamersFirst,
            UserOriginationUnknown,
            UserOriginationIOS,
            UserOriginationLoadTest,
            UserOriginationAndroid,
            UserOriginationPSN,
            UserOriginationGameCenter,
            UserOriginationCustomId,
            UserOriginationXboxLive
        };

        void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer);
        UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj);

        struct UserTitleInfo : public PlayFabBaseModel
        {
            std::string DisplayName;
            Boxed<UserOrigination> Origination;
            time_t Created;
            OptionalTime LastLogin;
            OptionalTime FirstLogin;
            OptionalBool isBanned;

            UserTitleInfo() :
                PlayFabBaseModel(),
                DisplayName(),
                Origination(),
                Created(0),
                LastLogin(),
                FirstLogin(),
                isBanned()
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Origination(src.Origination),
                Created(src.Created),
                LastLogin(src.LastLogin),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned)
            {}

            UserTitleInfo(const rapidjson::Value& obj) : UserTitleInfo()
            {
                readFromValue(obj);
            }

            ~UserTitleInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserPrivateAccountInfo : public PlayFabBaseModel
        {
            std::string Email;

            UserPrivateAccountInfo() :
                PlayFabBaseModel(),
                Email()
            {}

            UserPrivateAccountInfo(const UserPrivateAccountInfo& src) :
                PlayFabBaseModel(),
                Email(src.Email)
            {}

            UserPrivateAccountInfo(const rapidjson::Value& obj) : UserPrivateAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserPrivateAccountInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            std::string PlayFabId;
            time_t Created;
            std::string Username;
            UserTitleInfo* TitleInfo;
            UserPrivateAccountInfo* PrivateInfo;
            UserFacebookInfo* FacebookInfo;
            UserSteamInfo* SteamInfo;
            UserGameCenterInfo* GameCenterInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                PlayFabId(),
                Created(0),
                Username(),
                TitleInfo(NULL),
                PrivateInfo(NULL),
                FacebookInfo(NULL),
                SteamInfo(NULL),
                GameCenterInfo(NULL)
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Created(src.Created),
                Username(src.Username),
                TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : NULL),
                PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : NULL),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : NULL),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : NULL),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL)
            {}

            UserAccountInfo(const rapidjson::Value& obj) : UserAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserAccountInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAccountInfoResult : public PlayFabBaseModel
        {
            UserAccountInfo* AccountInfo;

            GetAccountInfoResult() :
                PlayFabBaseModel(),
                AccountInfo(NULL)
            {}

            GetAccountInfoResult(const GetAccountInfoResult& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : NULL)
            {}

            GetAccountInfoResult(const rapidjson::Value& obj) : GetAccountInfoResult()
            {
                readFromValue(obj);
            }

            ~GetAccountInfoResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCatalogItemsRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;

            GetCatalogItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion()
            {}

            GetCatalogItemsRequest(const GetCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion)
            {}

            GetCatalogItemsRequest(const rapidjson::Value& obj) : GetCatalogItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCatalogItemsResult : public PlayFabBaseModel
        {
            std::list<CatalogItem> Catalog;

            GetCatalogItemsResult() :
                PlayFabBaseModel(),
                Catalog()
            {}

            GetCatalogItemsResult(const GetCatalogItemsResult& src) :
                PlayFabBaseModel(),
                Catalog(src.Catalog)
            {}

            GetCatalogItemsResult(const rapidjson::Value& obj) : GetCatalogItemsResult()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterDataRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string CharacterId;
            std::list<std::string> Keys;
            OptionalInt32 IfChangedFromDataVersion;

            GetCharacterDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Keys(),
                IfChangedFromDataVersion()
            {}

            GetCharacterDataRequest(const GetCharacterDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Keys(src.Keys),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion)
            {}

            GetCharacterDataRequest(const rapidjson::Value& obj) : GetCharacterDataRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        void writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer);
        UserDataPermission readUserDataPermissionFromValue(const rapidjson::Value& obj);

        struct UserDataRecord : public PlayFabBaseModel
        {
            std::string Value;
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;

            UserDataRecord() :
                PlayFabBaseModel(),
                Value(),
                LastUpdated(0),
                Permission()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                Value(src.Value),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission)
            {}

            UserDataRecord(const rapidjson::Value& obj) : UserDataRecord()
            {
                readFromValue(obj);
            }

            ~UserDataRecord();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterDataResult : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetCharacterDataResult() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                DataVersion(0)
            {}

            GetCharacterDataResult(const GetCharacterDataResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            GetCharacterDataResult(const rapidjson::Value& obj) : GetCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterInventoryRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string CharacterId;
            std::string CatalogVersion;

            GetCharacterInventoryRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                CatalogVersion()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                CatalogVersion(src.CatalogVersion)
            {}

            GetCharacterInventoryRequest(const rapidjson::Value& obj) : GetCharacterInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
            Int32 SecondsToRecharge;
            time_t RechargeTime;
            Int32 RechargeMax;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                SecondsToRecharge(0),
                RechargeTime(0),
                RechargeMax(0)
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                SecondsToRecharge(src.SecondsToRecharge),
                RechargeTime(src.RechargeTime),
                RechargeMax(src.RechargeMax)
            {}

            VirtualCurrencyRechargeTime(const rapidjson::Value& obj) : VirtualCurrencyRechargeTime()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyRechargeTime();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterInventoryResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string CharacterId;
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetCharacterInventoryResult(const rapidjson::Value& obj) : GetCharacterInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterLeaderboardRequest : public PlayFabBaseModel
        {
            std::string CharacterType;
            std::string StatisticName;
            Int32 StartPosition;
            Int32 MaxResultsCount;

            GetCharacterLeaderboardRequest() :
                PlayFabBaseModel(),
                CharacterType(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount(0)
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabBaseModel(),
                CharacterType(src.CharacterType),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetCharacterLeaderboardRequest(const rapidjson::Value& obj) : GetCharacterLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterLeaderboardRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterLeaderboardResult : public PlayFabBaseModel
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetCharacterLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetCharacterLeaderboardResult(const GetCharacterLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetCharacterLeaderboardResult(const rapidjson::Value& obj) : GetCharacterLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterLeaderboardResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCloudScriptUrlRequest : public PlayFabBaseModel
        {
            OptionalInt32 Version;
            OptionalBool Testing;

            GetCloudScriptUrlRequest() :
                PlayFabBaseModel(),
                Version(),
                Testing()
            {}

            GetCloudScriptUrlRequest(const GetCloudScriptUrlRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Testing(src.Testing)
            {}

            GetCloudScriptUrlRequest(const rapidjson::Value& obj) : GetCloudScriptUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptUrlRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCloudScriptUrlResult : public PlayFabBaseModel
        {
            std::string Url;

            GetCloudScriptUrlResult() :
                PlayFabBaseModel(),
                Url()
            {}

            GetCloudScriptUrlResult(const GetCloudScriptUrlResult& src) :
                PlayFabBaseModel(),
                Url(src.Url)
            {}

            GetCloudScriptUrlResult(const rapidjson::Value& obj) : GetCloudScriptUrlResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptUrlResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContentDownloadUrlRequest : public PlayFabBaseModel
        {
            std::string Key;
            std::string HttpMethod;
            OptionalBool ThruCDN;

            GetContentDownloadUrlRequest() :
                PlayFabBaseModel(),
                Key(),
                HttpMethod(),
                ThruCDN()
            {}

            GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                HttpMethod(src.HttpMethod),
                ThruCDN(src.ThruCDN)
            {}

            GetContentDownloadUrlRequest(const rapidjson::Value& obj) : GetContentDownloadUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetContentDownloadUrlRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContentDownloadUrlResult : public PlayFabBaseModel
        {
            std::string URL;

            GetContentDownloadUrlResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetContentDownloadUrlResult(const GetContentDownloadUrlResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetContentDownloadUrlResult(const rapidjson::Value& obj) : GetContentDownloadUrlResult()
            {
                readFromValue(obj);
            }

            ~GetContentDownloadUrlResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendLeaderboardAroundCurrentUserRequest : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 MaxResultsCount;
            OptionalBool IncludeSteamFriends;
            OptionalBool IncludeFacebookFriends;

            GetFriendLeaderboardAroundCurrentUserRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                MaxResultsCount(0),
                IncludeSteamFriends(),
                IncludeFacebookFriends()
            {}

            GetFriendLeaderboardAroundCurrentUserRequest(const GetFriendLeaderboardAroundCurrentUserRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                MaxResultsCount(src.MaxResultsCount),
                IncludeSteamFriends(src.IncludeSteamFriends),
                IncludeFacebookFriends(src.IncludeFacebookFriends)
            {}

            GetFriendLeaderboardAroundCurrentUserRequest(const rapidjson::Value& obj) : GetFriendLeaderboardAroundCurrentUserRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardAroundCurrentUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLeaderboardEntry : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string DisplayName;
            Int32 StatValue;
            Int32 Position;

            PlayerLeaderboardEntry() :
                PlayFabBaseModel(),
                PlayFabId(),
                DisplayName(),
                StatValue(0),
                Position(0)
            {}

            PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DisplayName(src.DisplayName),
                StatValue(src.StatValue),
                Position(src.Position)
            {}

            PlayerLeaderboardEntry(const rapidjson::Value& obj) : PlayerLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~PlayerLeaderboardEntry();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendLeaderboardAroundCurrentUserResult : public PlayFabBaseModel
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;

            GetFriendLeaderboardAroundCurrentUserResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetFriendLeaderboardAroundCurrentUserResult(const GetFriendLeaderboardAroundCurrentUserResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetFriendLeaderboardAroundCurrentUserResult(const rapidjson::Value& obj) : GetFriendLeaderboardAroundCurrentUserResult()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardAroundCurrentUserResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendLeaderboardRequest : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 StartPosition;
            Int32 MaxResultsCount;
            OptionalBool IncludeSteamFriends;
            OptionalBool IncludeFacebookFriends;

            GetFriendLeaderboardRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount(0),
                IncludeSteamFriends(),
                IncludeFacebookFriends()
            {}

            GetFriendLeaderboardRequest(const GetFriendLeaderboardRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount),
                IncludeSteamFriends(src.IncludeSteamFriends),
                IncludeFacebookFriends(src.IncludeFacebookFriends)
            {}

            GetFriendLeaderboardRequest(const rapidjson::Value& obj) : GetFriendLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendsListRequest : public PlayFabBaseModel
        {
            OptionalBool IncludeSteamFriends;
            OptionalBool IncludeFacebookFriends;

            GetFriendsListRequest() :
                PlayFabBaseModel(),
                IncludeSteamFriends(),
                IncludeFacebookFriends()
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabBaseModel(),
                IncludeSteamFriends(src.IncludeSteamFriends),
                IncludeFacebookFriends(src.IncludeFacebookFriends)
            {}

            GetFriendsListRequest(const rapidjson::Value& obj) : GetFriendsListRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendsListRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendsListResult : public PlayFabBaseModel
        {
            std::list<FriendInfo> Friends;

            GetFriendsListResult() :
                PlayFabBaseModel(),
                Friends()
            {}

            GetFriendsListResult(const GetFriendsListResult& src) :
                PlayFabBaseModel(),
                Friends(src.Friends)
            {}

            GetFriendsListResult(const rapidjson::Value& obj) : GetFriendsListResult()
            {
                readFromValue(obj);
            }

            ~GetFriendsListResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardAroundCharacterRequest : public PlayFabBaseModel
        {
            std::string StatisticName;
            std::string CharacterId;
            std::string CharacterType;
            Int32 MaxResultsCount;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(0)
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetLeaderboardAroundCharacterRequest(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCharacterRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardAroundCharacterResult : public PlayFabBaseModel
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetLeaderboardAroundCharacterResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardAroundCharacterResult(const GetLeaderboardAroundCharacterResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardAroundCharacterResult(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCharacterResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardAroundCurrentUserRequest : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 MaxResultsCount;

            GetLeaderboardAroundCurrentUserRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                MaxResultsCount(0)
            {}

            GetLeaderboardAroundCurrentUserRequest(const GetLeaderboardAroundCurrentUserRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetLeaderboardAroundCurrentUserRequest(const rapidjson::Value& obj) : GetLeaderboardAroundCurrentUserRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCurrentUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardAroundCurrentUserResult : public PlayFabBaseModel
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;

            GetLeaderboardAroundCurrentUserResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardAroundCurrentUserResult(const GetLeaderboardAroundCurrentUserResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardAroundCurrentUserResult(const rapidjson::Value& obj) : GetLeaderboardAroundCurrentUserResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCurrentUserResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardForUsersCharactersRequest : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 MaxResultsCount;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                MaxResultsCount(0)
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetLeaderboardForUsersCharactersRequest(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardForUsersCharactersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardForUsersCharactersResult : public PlayFabBaseModel
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetLeaderboardForUsersCharactersResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardForUsersCharactersResult(const GetLeaderboardForUsersCharactersResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardForUsersCharactersResult(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardForUsersCharactersResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardRequest : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 StartPosition;
            Int32 MaxResultsCount;

            GetLeaderboardRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount(0)
            {}

            GetLeaderboardRequest(const GetLeaderboardRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetLeaderboardRequest(const rapidjson::Value& obj) : GetLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardResult : public PlayFabBaseModel
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;

            GetLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardResult(const GetLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardResult(const rapidjson::Value& obj) : GetLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPhotonAuthenticationTokenRequest : public PlayFabBaseModel
        {
            std::string PhotonApplicationId;

            GetPhotonAuthenticationTokenRequest() :
                PlayFabBaseModel(),
                PhotonApplicationId()
            {}

            GetPhotonAuthenticationTokenRequest(const GetPhotonAuthenticationTokenRequest& src) :
                PlayFabBaseModel(),
                PhotonApplicationId(src.PhotonApplicationId)
            {}

            GetPhotonAuthenticationTokenRequest(const rapidjson::Value& obj) : GetPhotonAuthenticationTokenRequest()
            {
                readFromValue(obj);
            }

            ~GetPhotonAuthenticationTokenRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPhotonAuthenticationTokenResult : public PlayFabBaseModel
        {
            std::string PhotonCustomAuthenticationToken;

            GetPhotonAuthenticationTokenResult() :
                PlayFabBaseModel(),
                PhotonCustomAuthenticationToken()
            {}

            GetPhotonAuthenticationTokenResult(const GetPhotonAuthenticationTokenResult& src) :
                PlayFabBaseModel(),
                PhotonCustomAuthenticationToken(src.PhotonCustomAuthenticationToken)
            {}

            GetPhotonAuthenticationTokenResult(const rapidjson::Value& obj) : GetPhotonAuthenticationTokenResult()
            {
                readFromValue(obj);
            }

            ~GetPhotonAuthenticationTokenResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticsRequest : public PlayFabBaseModel
        {
            std::list<std::string> StatisticNames;

            GetPlayerStatisticsRequest() :
                PlayFabBaseModel(),
                StatisticNames()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                StatisticNames(src.StatisticNames)
            {}

            GetPlayerStatisticsRequest(const rapidjson::Value& obj) : GetPlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StatisticValue : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 Value;
            std::string Version;

            StatisticValue() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version()
            {}

            StatisticValue(const StatisticValue& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticValue(const rapidjson::Value& obj) : StatisticValue()
            {
                readFromValue(obj);
            }

            ~StatisticValue();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticsResult : public PlayFabBaseModel
        {
            std::list<StatisticValue> Statistics;

            GetPlayerStatisticsResult() :
                PlayFabBaseModel(),
                Statistics()
            {}

            GetPlayerStatisticsResult(const GetPlayerStatisticsResult& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            GetPlayerStatisticsResult(const rapidjson::Value& obj) : GetPlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerTradesRequest : public PlayFabBaseModel
        {
            Boxed<TradeStatus> StatusFilter;

            GetPlayerTradesRequest() :
                PlayFabBaseModel(),
                StatusFilter()
            {}

            GetPlayerTradesRequest(const GetPlayerTradesRequest& src) :
                PlayFabBaseModel(),
                StatusFilter(src.StatusFilter)
            {}

            GetPlayerTradesRequest(const rapidjson::Value& obj) : GetPlayerTradesRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerTradesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerTradesResponse : public PlayFabBaseModel
        {
            std::list<TradeInfo> OpenedTrades;
            std::list<TradeInfo> AcceptedTrades;

            GetPlayerTradesResponse() :
                PlayFabBaseModel(),
                OpenedTrades(),
                AcceptedTrades()
            {}

            GetPlayerTradesResponse(const GetPlayerTradesResponse& src) :
                PlayFabBaseModel(),
                OpenedTrades(src.OpenedTrades),
                AcceptedTrades(src.AcceptedTrades)
            {}

            GetPlayerTradesResponse(const rapidjson::Value& obj) : GetPlayerTradesResponse()
            {
                readFromValue(obj);
            }

            ~GetPlayerTradesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromFacebookIDsRequest : public PlayFabBaseModel
        {
            std::list<std::string> FacebookIDs;

            GetPlayFabIDsFromFacebookIDsRequest() :
                PlayFabBaseModel(),
                FacebookIDs()
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const GetPlayFabIDsFromFacebookIDsRequest& src) :
                PlayFabBaseModel(),
                FacebookIDs(src.FacebookIDs)
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromFacebookIDsResult : public PlayFabBaseModel
        {
            std::list<FacebookPlayFabIdPair> Data;

            GetPlayFabIDsFromFacebookIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromFacebookIDsResult(const GetPlayFabIDsFromFacebookIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromFacebookIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromGameCenterIDsRequest : public PlayFabBaseModel
        {
            std::list<std::string> GameCenterIDs;

            GetPlayFabIDsFromGameCenterIDsRequest() :
                PlayFabBaseModel(),
                GameCenterIDs()
            {}

            GetPlayFabIDsFromGameCenterIDsRequest(const GetPlayFabIDsFromGameCenterIDsRequest& src) :
                PlayFabBaseModel(),
                GameCenterIDs(src.GameCenterIDs)
            {}

            GetPlayFabIDsFromGameCenterIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGameCenterIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGameCenterIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromGameCenterIDsResult : public PlayFabBaseModel
        {
            std::list<GameCenterPlayFabIdPair> Data;

            GetPlayFabIDsFromGameCenterIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGameCenterIDsResult(const GetPlayFabIDsFromGameCenterIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGameCenterIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGameCenterIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGameCenterIDsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromGoogleIDsRequest : public PlayFabBaseModel
        {
            std::list<std::string> GoogleIDs;

            GetPlayFabIDsFromGoogleIDsRequest() :
                PlayFabBaseModel(),
                GoogleIDs()
            {}

            GetPlayFabIDsFromGoogleIDsRequest(const GetPlayFabIDsFromGoogleIDsRequest& src) :
                PlayFabBaseModel(),
                GoogleIDs(src.GoogleIDs)
            {}

            GetPlayFabIDsFromGoogleIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGoogleIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGoogleIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GooglePlayFabIdPair : public PlayFabBaseModel
        {
            std::string GoogleId;
            std::string PlayFabId;

            GooglePlayFabIdPair() :
                PlayFabBaseModel(),
                GoogleId(),
                PlayFabId()
            {}

            GooglePlayFabIdPair(const GooglePlayFabIdPair& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                PlayFabId(src.PlayFabId)
            {}

            GooglePlayFabIdPair(const rapidjson::Value& obj) : GooglePlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GooglePlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromGoogleIDsResult : public PlayFabBaseModel
        {
            std::list<GooglePlayFabIdPair> Data;

            GetPlayFabIDsFromGoogleIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGoogleIDsResult(const GetPlayFabIDsFromGoogleIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGoogleIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGoogleIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGoogleIDsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromPSNAccountIDsRequest : public PlayFabBaseModel
        {
            std::list<std::string> PSNAccountIDs;
            OptionalInt32 IssuerId;

            GetPlayFabIDsFromPSNAccountIDsRequest() :
                PlayFabBaseModel(),
                PSNAccountIDs(),
                IssuerId()
            {}

            GetPlayFabIDsFromPSNAccountIDsRequest(const GetPlayFabIDsFromPSNAccountIDsRequest& src) :
                PlayFabBaseModel(),
                PSNAccountIDs(src.PSNAccountIDs),
                IssuerId(src.IssuerId)
            {}

            GetPlayFabIDsFromPSNAccountIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromPSNAccountIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromPSNAccountIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PSNAccountPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PSNAccountId;
            std::string PlayFabId;

            PSNAccountPlayFabIdPair() :
                PlayFabBaseModel(),
                PSNAccountId(),
                PlayFabId()
            {}

            PSNAccountPlayFabIdPair(const PSNAccountPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PSNAccountId(src.PSNAccountId),
                PlayFabId(src.PlayFabId)
            {}

            PSNAccountPlayFabIdPair(const rapidjson::Value& obj) : PSNAccountPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~PSNAccountPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromPSNAccountIDsResult : public PlayFabBaseModel
        {
            std::list<PSNAccountPlayFabIdPair> Data;

            GetPlayFabIDsFromPSNAccountIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromPSNAccountIDsResult(const GetPlayFabIDsFromPSNAccountIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromPSNAccountIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromPSNAccountIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromPSNAccountIDsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromSteamIDsRequest : public PlayFabBaseModel
        {
            std::list<Uint64> SteamIDs;

            GetPlayFabIDsFromSteamIDsRequest() :
                PlayFabBaseModel(),
                SteamIDs()
            {}

            GetPlayFabIDsFromSteamIDsRequest(const GetPlayFabIDsFromSteamIDsRequest& src) :
                PlayFabBaseModel(),
                SteamIDs(src.SteamIDs)
            {}

            GetPlayFabIDsFromSteamIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SteamPlayFabIdPair : public PlayFabBaseModel
        {
            Uint64 SteamId;
            std::string PlayFabId;

            SteamPlayFabIdPair() :
                PlayFabBaseModel(),
                SteamId(0),
                PlayFabId()
            {}

            SteamPlayFabIdPair(const SteamPlayFabIdPair& src) :
                PlayFabBaseModel(),
                SteamId(src.SteamId),
                PlayFabId(src.PlayFabId)
            {}

            SteamPlayFabIdPair(const rapidjson::Value& obj) : SteamPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~SteamPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromSteamIDsResult : public PlayFabBaseModel
        {
            std::list<SteamPlayFabIdPair> Data;

            GetPlayFabIDsFromSteamIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromSteamIDsResult(const GetPlayFabIDsFromSteamIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromSteamIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPublisherDataRequest : public PlayFabBaseModel
        {
            std::list<std::string> Keys;

            GetPublisherDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetPublisherDataRequest(const GetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetPublisherDataRequest(const rapidjson::Value& obj) : GetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPublisherDataResult : public PlayFabBaseModel
        {
            std::map<std::string, std::string> Data;

            GetPublisherDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPublisherDataResult(const GetPublisherDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPublisherDataResult(const rapidjson::Value& obj) : GetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPurchaseRequest : public PlayFabBaseModel
        {
            std::string OrderId;

            GetPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId()
            {}

            GetPurchaseRequest(const GetPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId)
            {}

            GetPurchaseRequest(const rapidjson::Value& obj) : GetPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~GetPurchaseRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPurchaseResult : public PlayFabBaseModel
        {
            std::string OrderId;
            std::string PaymentProvider;
            std::string TransactionId;
            std::string TransactionStatus;
            time_t PurchaseDate;
            std::list<ItemInstance> Items;

            GetPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                PaymentProvider(),
                TransactionId(),
                TransactionStatus(),
                PurchaseDate(0),
                Items()
            {}

            GetPurchaseResult(const GetPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                PaymentProvider(src.PaymentProvider),
                TransactionId(src.TransactionId),
                TransactionStatus(src.TransactionStatus),
                PurchaseDate(src.PurchaseDate),
                Items(src.Items)
            {}

            GetPurchaseResult(const rapidjson::Value& obj) : GetPurchaseResult()
            {
                readFromValue(obj);
            }

            ~GetPurchaseResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetSharedGroupDataRequest : public PlayFabBaseModel
        {
            std::string SharedGroupId;
            std::list<std::string> Keys;
            OptionalBool GetMembers;

            GetSharedGroupDataRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                Keys(),
                GetMembers()
            {}

            GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                Keys(src.Keys),
                GetMembers(src.GetMembers)
            {}

            GetSharedGroupDataRequest(const rapidjson::Value& obj) : GetSharedGroupDataRequest()
            {
                readFromValue(obj);
            }

            ~GetSharedGroupDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SharedGroupDataRecord : public PlayFabBaseModel
        {
            std::string Value;
            std::string LastUpdatedBy;
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;

            SharedGroupDataRecord() :
                PlayFabBaseModel(),
                Value(),
                LastUpdatedBy(),
                LastUpdated(0),
                Permission()
            {}

            SharedGroupDataRecord(const SharedGroupDataRecord& src) :
                PlayFabBaseModel(),
                Value(src.Value),
                LastUpdatedBy(src.LastUpdatedBy),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission)
            {}

            SharedGroupDataRecord(const rapidjson::Value& obj) : SharedGroupDataRecord()
            {
                readFromValue(obj);
            }

            ~SharedGroupDataRecord();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetSharedGroupDataResult : public PlayFabBaseModel
        {
            std::map<std::string, SharedGroupDataRecord> Data;
            std::list<std::string> Members;

            GetSharedGroupDataResult() :
                PlayFabBaseModel(),
                Data(),
                Members()
            {}

            GetSharedGroupDataResult(const GetSharedGroupDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Members(src.Members)
            {}

            GetSharedGroupDataResult(const rapidjson::Value& obj) : GetSharedGroupDataResult()
            {
                readFromValue(obj);
            }

            ~GetSharedGroupDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetStoreItemsRequest : public PlayFabBaseModel
        {
            std::string StoreId;
            std::string CatalogVersion;

            GetStoreItemsRequest() :
                PlayFabBaseModel(),
                StoreId(),
                CatalogVersion()
            {}

            GetStoreItemsRequest(const GetStoreItemsRequest& src) :
                PlayFabBaseModel(),
                StoreId(src.StoreId),
                CatalogVersion(src.CatalogVersion)
            {}

            GetStoreItemsRequest(const rapidjson::Value& obj) : GetStoreItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StoreItem : public PlayFabBaseModel
        {
            std::string ItemId;
            std::map<std::string, Uint32> VirtualCurrencyPrices;
            std::map<std::string, Uint32> RealCurrencyPrices;

            StoreItem() :
                PlayFabBaseModel(),
                ItemId(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices()
            {}

            StoreItem(const StoreItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices)
            {}

            StoreItem(const rapidjson::Value& obj) : StoreItem()
            {
                readFromValue(obj);
            }

            ~StoreItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetStoreItemsResult : public PlayFabBaseModel
        {
            std::list<StoreItem> Store;

            GetStoreItemsResult() :
                PlayFabBaseModel(),
                Store()
            {}

            GetStoreItemsResult(const GetStoreItemsResult& src) :
                PlayFabBaseModel(),
                Store(src.Store)
            {}

            GetStoreItemsResult(const rapidjson::Value& obj) : GetStoreItemsResult()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitleDataRequest : public PlayFabBaseModel
        {
            std::list<std::string> Keys;

            GetTitleDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetTitleDataRequest(const GetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetTitleDataRequest(const rapidjson::Value& obj) : GetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitleDataResult : public PlayFabBaseModel
        {
            std::map<std::string, std::string> Data;

            GetTitleDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetTitleDataResult(const GetTitleDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetTitleDataResult(const rapidjson::Value& obj) : GetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~GetTitleDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitleNewsRequest : public PlayFabBaseModel
        {
            OptionalInt32 Count;

            GetTitleNewsRequest() :
                PlayFabBaseModel(),
                Count()
            {}

            GetTitleNewsRequest(const GetTitleNewsRequest& src) :
                PlayFabBaseModel(),
                Count(src.Count)
            {}

            GetTitleNewsRequest(const rapidjson::Value& obj) : GetTitleNewsRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct TitleNewsItem : public PlayFabBaseModel
        {
            time_t Timestamp;
            std::string NewsId;
            std::string Title;
            std::string Body;

            TitleNewsItem() :
                PlayFabBaseModel(),
                Timestamp(0),
                NewsId(),
                Title(),
                Body()
            {}

            TitleNewsItem(const TitleNewsItem& src) :
                PlayFabBaseModel(),
                Timestamp(src.Timestamp),
                NewsId(src.NewsId),
                Title(src.Title),
                Body(src.Body)
            {}

            TitleNewsItem(const rapidjson::Value& obj) : TitleNewsItem()
            {
                readFromValue(obj);
            }

            ~TitleNewsItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitleNewsResult : public PlayFabBaseModel
        {
            std::list<TitleNewsItem> News;

            GetTitleNewsResult() :
                PlayFabBaseModel(),
                News()
            {}

            GetTitleNewsResult(const GetTitleNewsResult& src) :
                PlayFabBaseModel(),
                News(src.News)
            {}

            GetTitleNewsResult(const rapidjson::Value& obj) : GetTitleNewsResult()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTradeStatusRequest : public PlayFabBaseModel
        {
            std::string OfferingPlayerId;
            std::string TradeId;

            GetTradeStatusRequest() :
                PlayFabBaseModel(),
                OfferingPlayerId(),
                TradeId()
            {}

            GetTradeStatusRequest(const GetTradeStatusRequest& src) :
                PlayFabBaseModel(),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
            {}

            GetTradeStatusRequest(const rapidjson::Value& obj) : GetTradeStatusRequest()
            {
                readFromValue(obj);
            }

            ~GetTradeStatusRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTradeStatusResponse : public PlayFabBaseModel
        {
            TradeInfo* Trade;

            GetTradeStatusResponse() :
                PlayFabBaseModel(),
                Trade(NULL)
            {}

            GetTradeStatusResponse(const GetTradeStatusResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : NULL)
            {}

            GetTradeStatusResponse(const rapidjson::Value& obj) : GetTradeStatusResponse()
            {
                readFromValue(obj);
            }

            ~GetTradeStatusResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserCombinedInfoRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string Username;
            std::string Email;
            std::string TitleDisplayName;
            OptionalBool GetAccountInfo;
            OptionalBool GetInventory;
            OptionalBool GetVirtualCurrency;
            OptionalBool GetUserData;
            std::list<std::string> UserDataKeys;
            OptionalBool GetReadOnlyData;
            std::list<std::string> ReadOnlyDataKeys;

            GetUserCombinedInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Username(),
                Email(),
                TitleDisplayName(),
                GetAccountInfo(),
                GetInventory(),
                GetVirtualCurrency(),
                GetUserData(),
                UserDataKeys(),
                GetReadOnlyData(),
                ReadOnlyDataKeys()
            {}

            GetUserCombinedInfoRequest(const GetUserCombinedInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Username(src.Username),
                Email(src.Email),
                TitleDisplayName(src.TitleDisplayName),
                GetAccountInfo(src.GetAccountInfo),
                GetInventory(src.GetInventory),
                GetVirtualCurrency(src.GetVirtualCurrency),
                GetUserData(src.GetUserData),
                UserDataKeys(src.UserDataKeys),
                GetReadOnlyData(src.GetReadOnlyData),
                ReadOnlyDataKeys(src.ReadOnlyDataKeys)
            {}

            GetUserCombinedInfoRequest(const rapidjson::Value& obj) : GetUserCombinedInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetUserCombinedInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserCombinedInfoResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            UserAccountInfo* AccountInfo;
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;
            std::map<std::string, UserDataRecord> ReadOnlyData;
            Uint32 ReadOnlyDataVersion;

            GetUserCombinedInfoResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                AccountInfo(NULL),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes(),
                Data(),
                DataVersion(0),
                ReadOnlyData(),
                ReadOnlyDataVersion(0)
            {}

            GetUserCombinedInfoResult(const GetUserCombinedInfoResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : NULL),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes),
                Data(src.Data),
                DataVersion(src.DataVersion),
                ReadOnlyData(src.ReadOnlyData),
                ReadOnlyDataVersion(src.ReadOnlyDataVersion)
            {}

            GetUserCombinedInfoResult(const rapidjson::Value& obj) : GetUserCombinedInfoResult()
            {
                readFromValue(obj);
            }

            ~GetUserCombinedInfoResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserDataRequest : public PlayFabBaseModel
        {
            std::list<std::string> Keys;
            std::string PlayFabId;
            OptionalInt32 IfChangedFromDataVersion;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                Keys(),
                PlayFabId(),
                IfChangedFromDataVersion()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion)
            {}

            GetUserDataRequest(const rapidjson::Value& obj) : GetUserDataRequest()
            {
                readFromValue(obj);
            }

            ~GetUserDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserDataResult : public PlayFabBaseModel
        {
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetUserDataResult() :
                PlayFabBaseModel(),
                Data(),
                DataVersion(0)
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            GetUserDataResult(const rapidjson::Value& obj) : GetUserDataResult()
            {
                readFromValue(obj);
            }

            ~GetUserDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserInventoryRequest : public PlayFabBaseModel
        {

            GetUserInventoryRequest() :
                PlayFabBaseModel()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel()
            {}

            GetUserInventoryRequest(const rapidjson::Value& obj) : GetUserInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetUserInventoryResult(const rapidjson::Value& obj) : GetUserInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserStatisticsRequest : public PlayFabBaseModel
        {

            GetUserStatisticsRequest() :
                PlayFabBaseModel()
            {}

            GetUserStatisticsRequest(const GetUserStatisticsRequest& src) :
                PlayFabBaseModel()
            {}

            GetUserStatisticsRequest(const rapidjson::Value& obj) : GetUserStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetUserStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserStatisticsResult : public PlayFabBaseModel
        {
            std::map<std::string, Int32> UserStatistics;

            GetUserStatisticsResult() :
                PlayFabBaseModel(),
                UserStatistics()
            {}

            GetUserStatisticsResult(const GetUserStatisticsResult& src) :
                PlayFabBaseModel(),
                UserStatistics(src.UserStatistics)
            {}

            GetUserStatisticsResult(const rapidjson::Value& obj) : GetUserStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetUserStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GrantCharacterToUserRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string ItemId;
            std::string CharacterName;

            GrantCharacterToUserRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                ItemId(),
                CharacterName()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                ItemId(src.ItemId),
                CharacterName(src.CharacterName)
            {}

            GrantCharacterToUserRequest(const rapidjson::Value& obj) : GrantCharacterToUserRequest()
            {
                readFromValue(obj);
            }

            ~GrantCharacterToUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GrantCharacterToUserResult : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string CharacterType;
            bool Result;

            GrantCharacterToUserResult() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterType(),
                Result(false)
            {}

            GrantCharacterToUserResult(const GrantCharacterToUserResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                Result(src.Result)
            {}

            GrantCharacterToUserResult(const rapidjson::Value& obj) : GrantCharacterToUserResult()
            {
                readFromValue(obj);
            }

            ~GrantCharacterToUserResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ItemPuchaseRequest : public PlayFabBaseModel
        {
            std::string ItemId;
            Uint32 Quantity;
            std::string Annotation;
            std::list<std::string> UpgradeFromItems;

            ItemPuchaseRequest() :
                PlayFabBaseModel(),
                ItemId(),
                Quantity(0),
                Annotation(),
                UpgradeFromItems()
            {}

            ItemPuchaseRequest(const ItemPuchaseRequest& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                Quantity(src.Quantity),
                Annotation(src.Annotation),
                UpgradeFromItems(src.UpgradeFromItems)
            {}

            ItemPuchaseRequest(const rapidjson::Value& obj) : ItemPuchaseRequest()
            {
                readFromValue(obj);
            }

            ~ItemPuchaseRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkAndroidDeviceIDRequest : public PlayFabBaseModel
        {
            std::string AndroidDeviceId;
            std::string OS;
            std::string AndroidDevice;

            LinkAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDeviceId(),
                OS(),
                AndroidDevice()
            {}

            LinkAndroidDeviceIDRequest(const LinkAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId),
                OS(src.OS),
                AndroidDevice(src.AndroidDevice)
            {}

            LinkAndroidDeviceIDRequest(const rapidjson::Value& obj) : LinkAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkAndroidDeviceIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkAndroidDeviceIDResult : public PlayFabBaseModel
        {

            LinkAndroidDeviceIDResult() :
                PlayFabBaseModel()
            {}

            LinkAndroidDeviceIDResult(const LinkAndroidDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkAndroidDeviceIDResult(const rapidjson::Value& obj) : LinkAndroidDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~LinkAndroidDeviceIDResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkCustomIDRequest : public PlayFabBaseModel
        {
            std::string CustomId;

            LinkCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId()
            {}

            LinkCustomIDRequest(const LinkCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            LinkCustomIDRequest(const rapidjson::Value& obj) : LinkCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkCustomIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkCustomIDResult : public PlayFabBaseModel
        {

            LinkCustomIDResult() :
                PlayFabBaseModel()
            {}

            LinkCustomIDResult(const LinkCustomIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkCustomIDResult(const rapidjson::Value& obj) : LinkCustomIDResult()
            {
                readFromValue(obj);
            }

            ~LinkCustomIDResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkFacebookAccountRequest : public PlayFabBaseModel
        {
            std::string AccessToken;
            OptionalBool ForceLink;

            LinkFacebookAccountRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                ForceLink()
            {}

            LinkFacebookAccountRequest(const LinkFacebookAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            LinkFacebookAccountRequest(const rapidjson::Value& obj) : LinkFacebookAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkFacebookAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkFacebookAccountResult : public PlayFabBaseModel
        {

            LinkFacebookAccountResult() :
                PlayFabBaseModel()
            {}

            LinkFacebookAccountResult(const LinkFacebookAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkFacebookAccountResult(const rapidjson::Value& obj) : LinkFacebookAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkFacebookAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkGameCenterAccountRequest : public PlayFabBaseModel
        {
            std::string GameCenterId;

            LinkGameCenterAccountRequest() :
                PlayFabBaseModel(),
                GameCenterId()
            {}

            LinkGameCenterAccountRequest(const LinkGameCenterAccountRequest& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId)
            {}

            LinkGameCenterAccountRequest(const rapidjson::Value& obj) : LinkGameCenterAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkGameCenterAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkGameCenterAccountResult : public PlayFabBaseModel
        {

            LinkGameCenterAccountResult() :
                PlayFabBaseModel()
            {}

            LinkGameCenterAccountResult(const LinkGameCenterAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkGameCenterAccountResult(const rapidjson::Value& obj) : LinkGameCenterAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkGameCenterAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkGoogleAccountRequest : public PlayFabBaseModel
        {
            std::string AccessToken;

            LinkGoogleAccountRequest() :
                PlayFabBaseModel(),
                AccessToken()
            {}

            LinkGoogleAccountRequest(const LinkGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken)
            {}

            LinkGoogleAccountRequest(const rapidjson::Value& obj) : LinkGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkGoogleAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkGoogleAccountResult : public PlayFabBaseModel
        {

            LinkGoogleAccountResult() :
                PlayFabBaseModel()
            {}

            LinkGoogleAccountResult(const LinkGoogleAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkGoogleAccountResult(const rapidjson::Value& obj) : LinkGoogleAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkGoogleAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkIOSDeviceIDRequest : public PlayFabBaseModel
        {
            std::string DeviceId;
            std::string OS;
            std::string DeviceModel;

            LinkIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                DeviceId(),
                OS(),
                DeviceModel()
            {}

            LinkIOSDeviceIDRequest(const LinkIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                DeviceId(src.DeviceId),
                OS(src.OS),
                DeviceModel(src.DeviceModel)
            {}

            LinkIOSDeviceIDRequest(const rapidjson::Value& obj) : LinkIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkIOSDeviceIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkIOSDeviceIDResult : public PlayFabBaseModel
        {

            LinkIOSDeviceIDResult() :
                PlayFabBaseModel()
            {}

            LinkIOSDeviceIDResult(const LinkIOSDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkIOSDeviceIDResult(const rapidjson::Value& obj) : LinkIOSDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~LinkIOSDeviceIDResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkKongregateAccountRequest : public PlayFabBaseModel
        {
            std::string KongregateId;
            std::string AuthTicket;

            LinkKongregateAccountRequest() :
                PlayFabBaseModel(),
                KongregateId(),
                AuthTicket()
            {}

            LinkKongregateAccountRequest(const LinkKongregateAccountRequest& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                AuthTicket(src.AuthTicket)
            {}

            LinkKongregateAccountRequest(const rapidjson::Value& obj) : LinkKongregateAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkKongregateAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkKongregateAccountResult : public PlayFabBaseModel
        {

            LinkKongregateAccountResult() :
                PlayFabBaseModel()
            {}

            LinkKongregateAccountResult(const LinkKongregateAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkKongregateAccountResult(const rapidjson::Value& obj) : LinkKongregateAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkKongregateAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkPSNAccountRequest : public PlayFabBaseModel
        {
            std::string AuthCode;
            std::string RedirectUri;
            OptionalInt32 IssuerId;

            LinkPSNAccountRequest() :
                PlayFabBaseModel(),
                AuthCode(),
                RedirectUri(),
                IssuerId()
            {}

            LinkPSNAccountRequest(const LinkPSNAccountRequest& src) :
                PlayFabBaseModel(),
                AuthCode(src.AuthCode),
                RedirectUri(src.RedirectUri),
                IssuerId(src.IssuerId)
            {}

            LinkPSNAccountRequest(const rapidjson::Value& obj) : LinkPSNAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkPSNAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkPSNAccountResult : public PlayFabBaseModel
        {

            LinkPSNAccountResult() :
                PlayFabBaseModel()
            {}

            LinkPSNAccountResult(const LinkPSNAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkPSNAccountResult(const rapidjson::Value& obj) : LinkPSNAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkPSNAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkSteamAccountRequest : public PlayFabBaseModel
        {
            std::string SteamTicket;

            LinkSteamAccountRequest() :
                PlayFabBaseModel(),
                SteamTicket()
            {}

            LinkSteamAccountRequest(const LinkSteamAccountRequest& src) :
                PlayFabBaseModel(),
                SteamTicket(src.SteamTicket)
            {}

            LinkSteamAccountRequest(const rapidjson::Value& obj) : LinkSteamAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkSteamAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkSteamAccountResult : public PlayFabBaseModel
        {

            LinkSteamAccountResult() :
                PlayFabBaseModel()
            {}

            LinkSteamAccountResult(const LinkSteamAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkSteamAccountResult(const rapidjson::Value& obj) : LinkSteamAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkSteamAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkXboxAccountRequest : public PlayFabBaseModel
        {
            std::string XboxToken;

            LinkXboxAccountRequest() :
                PlayFabBaseModel(),
                XboxToken()
            {}

            LinkXboxAccountRequest(const LinkXboxAccountRequest& src) :
                PlayFabBaseModel(),
                XboxToken(src.XboxToken)
            {}

            LinkXboxAccountRequest(const rapidjson::Value& obj) : LinkXboxAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkXboxAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkXboxAccountResult : public PlayFabBaseModel
        {

            LinkXboxAccountResult() :
                PlayFabBaseModel()
            {}

            LinkXboxAccountResult(const LinkXboxAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkXboxAccountResult(const rapidjson::Value& obj) : LinkXboxAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkXboxAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListUsersCharactersRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            ListUsersCharactersRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            ListUsersCharactersRequest(const ListUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            ListUsersCharactersRequest(const rapidjson::Value& obj) : ListUsersCharactersRequest()
            {
                readFromValue(obj);
            }

            ~ListUsersCharactersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListUsersCharactersResult : public PlayFabBaseModel
        {
            std::list<CharacterResult> Characters;

            ListUsersCharactersResult() :
                PlayFabBaseModel(),
                Characters()
            {}

            ListUsersCharactersResult(const ListUsersCharactersResult& src) :
                PlayFabBaseModel(),
                Characters(src.Characters)
            {}

            ListUsersCharactersResult(const rapidjson::Value& obj) : ListUsersCharactersResult()
            {
                readFromValue(obj);
            }

            ~ListUsersCharactersResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LogEventRequest : public PlayFabBaseModel
        {
            OptionalTime Timestamp;
            std::string EventName;
            std::map<std::string, MultitypeVar> Body;
            bool ProfileSetEvent;

            LogEventRequest() :
                PlayFabBaseModel(),
                Timestamp(),
                EventName(),
                Body(),
                ProfileSetEvent(false)
            {}

            LogEventRequest(const LogEventRequest& src) :
                PlayFabBaseModel(),
                Timestamp(src.Timestamp),
                EventName(src.EventName),
                Body(src.Body),
                ProfileSetEvent(src.ProfileSetEvent)
            {}

            LogEventRequest(const rapidjson::Value& obj) : LogEventRequest()
            {
                readFromValue(obj);
            }

            ~LogEventRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LogEventResult : public PlayFabBaseModel
        {

            LogEventResult() :
                PlayFabBaseModel()
            {}

            LogEventResult(const LogEventResult& src) :
                PlayFabBaseModel()
            {}

            LogEventResult(const rapidjson::Value& obj) : LogEventResult()
            {
                readFromValue(obj);
            }

            ~LogEventResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserSettings : public PlayFabBaseModel
        {
            bool NeedsAttribution;

            UserSettings() :
                PlayFabBaseModel(),
                NeedsAttribution(false)
            {}

            UserSettings(const UserSettings& src) :
                PlayFabBaseModel(),
                NeedsAttribution(src.NeedsAttribution)
            {}

            UserSettings(const rapidjson::Value& obj) : UserSettings()
            {
                readFromValue(obj);
            }

            ~UserSettings();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginResult : public PlayFabBaseModel
        {
            std::string SessionTicket;
            std::string PlayFabId;
            bool NewlyCreated;
            UserSettings* SettingsForUser;

            LoginResult() :
                PlayFabBaseModel(),
                SessionTicket(),
                PlayFabId(),
                NewlyCreated(false),
                SettingsForUser(NULL)
            {}

            LoginResult(const LoginResult& src) :
                PlayFabBaseModel(),
                SessionTicket(src.SessionTicket),
                PlayFabId(src.PlayFabId),
                NewlyCreated(src.NewlyCreated),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : NULL)
            {}

            LoginResult(const rapidjson::Value& obj) : LoginResult()
            {
                readFromValue(obj);
            }

            ~LoginResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithAndroidDeviceIDRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string AndroidDeviceId;
            std::string OS;
            std::string AndroidDevice;
            OptionalBool CreateAccount;

            LoginWithAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                TitleId(),
                AndroidDeviceId(),
                OS(),
                AndroidDevice(),
                CreateAccount()
            {}

            LoginWithAndroidDeviceIDRequest(const LoginWithAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                AndroidDeviceId(src.AndroidDeviceId),
                OS(src.OS),
                AndroidDevice(src.AndroidDevice),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithAndroidDeviceIDRequest(const rapidjson::Value& obj) : LoginWithAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithAndroidDeviceIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithCustomIDRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string CustomId;
            OptionalBool CreateAccount;

            LoginWithCustomIDRequest() :
                PlayFabBaseModel(),
                TitleId(),
                CustomId(),
                CreateAccount()
            {}

            LoginWithCustomIDRequest(const LoginWithCustomIDRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                CustomId(src.CustomId),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithCustomIDRequest(const rapidjson::Value& obj) : LoginWithCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithCustomIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithEmailAddressRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string Email;
            std::string Password;

            LoginWithEmailAddressRequest() :
                PlayFabBaseModel(),
                TitleId(),
                Email(),
                Password()
            {}

            LoginWithEmailAddressRequest(const LoginWithEmailAddressRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                Email(src.Email),
                Password(src.Password)
            {}

            LoginWithEmailAddressRequest(const rapidjson::Value& obj) : LoginWithEmailAddressRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithEmailAddressRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithFacebookRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string AccessToken;
            OptionalBool CreateAccount;

            LoginWithFacebookRequest() :
                PlayFabBaseModel(),
                TitleId(),
                AccessToken(),
                CreateAccount()
            {}

            LoginWithFacebookRequest(const LoginWithFacebookRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithFacebookRequest(const rapidjson::Value& obj) : LoginWithFacebookRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithFacebookRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithGameCenterRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string PlayerId;
            OptionalBool CreateAccount;

            LoginWithGameCenterRequest() :
                PlayFabBaseModel(),
                TitleId(),
                PlayerId(),
                CreateAccount()
            {}

            LoginWithGameCenterRequest(const LoginWithGameCenterRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                PlayerId(src.PlayerId),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithGameCenterRequest(const rapidjson::Value& obj) : LoginWithGameCenterRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithGameCenterRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithGoogleAccountRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string AccessToken;
            OptionalBool CreateAccount;
            std::string PublisherId;

            LoginWithGoogleAccountRequest() :
                PlayFabBaseModel(),
                TitleId(),
                AccessToken(),
                CreateAccount(),
                PublisherId()
            {}

            LoginWithGoogleAccountRequest(const LoginWithGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                PublisherId(src.PublisherId)
            {}

            LoginWithGoogleAccountRequest(const rapidjson::Value& obj) : LoginWithGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithGoogleAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithIOSDeviceIDRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string DeviceId;
            std::string OS;
            std::string DeviceModel;
            OptionalBool CreateAccount;

            LoginWithIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                TitleId(),
                DeviceId(),
                OS(),
                DeviceModel(),
                CreateAccount()
            {}

            LoginWithIOSDeviceIDRequest(const LoginWithIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                DeviceId(src.DeviceId),
                OS(src.OS),
                DeviceModel(src.DeviceModel),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithIOSDeviceIDRequest(const rapidjson::Value& obj) : LoginWithIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithIOSDeviceIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithKongregateRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string KongregateId;
            std::string AuthTicket;
            OptionalBool CreateAccount;

            LoginWithKongregateRequest() :
                PlayFabBaseModel(),
                TitleId(),
                KongregateId(),
                AuthTicket(),
                CreateAccount()
            {}

            LoginWithKongregateRequest(const LoginWithKongregateRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                KongregateId(src.KongregateId),
                AuthTicket(src.AuthTicket),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithKongregateRequest(const rapidjson::Value& obj) : LoginWithKongregateRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithKongregateRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithPlayFabRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string Username;
            std::string Password;

            LoginWithPlayFabRequest() :
                PlayFabBaseModel(),
                TitleId(),
                Username(),
                Password()
            {}

            LoginWithPlayFabRequest(const LoginWithPlayFabRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                Username(src.Username),
                Password(src.Password)
            {}

            LoginWithPlayFabRequest(const rapidjson::Value& obj) : LoginWithPlayFabRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithPlayFabRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithPSNRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string AuthCode;
            std::string RedirectUri;
            OptionalInt32 IssuerId;
            OptionalBool CreateAccount;

            LoginWithPSNRequest() :
                PlayFabBaseModel(),
                TitleId(),
                AuthCode(),
                RedirectUri(),
                IssuerId(),
                CreateAccount()
            {}

            LoginWithPSNRequest(const LoginWithPSNRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                AuthCode(src.AuthCode),
                RedirectUri(src.RedirectUri),
                IssuerId(src.IssuerId),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithPSNRequest(const rapidjson::Value& obj) : LoginWithPSNRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithPSNRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithSteamRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string SteamTicket;
            OptionalBool CreateAccount;

            LoginWithSteamRequest() :
                PlayFabBaseModel(),
                TitleId(),
                SteamTicket(),
                CreateAccount()
            {}

            LoginWithSteamRequest(const LoginWithSteamRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                SteamTicket(src.SteamTicket),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithSteamRequest(const rapidjson::Value& obj) : LoginWithSteamRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithSteamRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithXboxRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string XboxToken;
            OptionalBool CreateAccount;

            LoginWithXboxRequest() :
                PlayFabBaseModel(),
                TitleId(),
                XboxToken(),
                CreateAccount()
            {}

            LoginWithXboxRequest(const LoginWithXboxRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                XboxToken(src.XboxToken),
                CreateAccount(src.CreateAccount)
            {}

            LoginWithXboxRequest(const rapidjson::Value& obj) : LoginWithXboxRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithXboxRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct MatchmakeRequest : public PlayFabBaseModel
        {
            std::string BuildVersion;
            Boxed<Region> pfRegion;
            std::string GameMode;
            std::string LobbyId;
            std::string StatisticName;
            std::string CharacterId;
            OptionalBool EnableQueue;

            MatchmakeRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                pfRegion(),
                GameMode(),
                LobbyId(),
                StatisticName(),
                CharacterId(),
                EnableQueue()
            {}

            MatchmakeRequest(const MatchmakeRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                pfRegion(src.pfRegion),
                GameMode(src.GameMode),
                LobbyId(src.LobbyId),
                StatisticName(src.StatisticName),
                CharacterId(src.CharacterId),
                EnableQueue(src.EnableQueue)
            {}

            MatchmakeRequest(const rapidjson::Value& obj) : MatchmakeRequest()
            {
                readFromValue(obj);
            }

            ~MatchmakeRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum MatchmakeStatus
        {
            MatchmakeStatusComplete,
            MatchmakeStatusWaiting,
            MatchmakeStatusGameNotFound
        };

        void writeMatchmakeStatusEnumJSON(MatchmakeStatus enumVal, PFStringJsonWriter& writer);
        MatchmakeStatus readMatchmakeStatusFromValue(const rapidjson::Value& obj);

        struct MatchmakeResult : public PlayFabBaseModel
        {
            std::string LobbyID;
            std::string ServerHostname;
            OptionalInt32 ServerPort;
            std::string Ticket;
            std::string Expires;
            OptionalInt32 PollWaitTimeMS;
            Boxed<MatchmakeStatus> Status;

            MatchmakeResult() :
                PlayFabBaseModel(),
                LobbyID(),
                ServerHostname(),
                ServerPort(),
                Ticket(),
                Expires(),
                PollWaitTimeMS(),
                Status()
            {}

            MatchmakeResult(const MatchmakeResult& src) :
                PlayFabBaseModel(),
                LobbyID(src.LobbyID),
                ServerHostname(src.ServerHostname),
                ServerPort(src.ServerPort),
                Ticket(src.Ticket),
                Expires(src.Expires),
                PollWaitTimeMS(src.PollWaitTimeMS),
                Status(src.Status)
            {}

            MatchmakeResult(const rapidjson::Value& obj) : MatchmakeResult()
            {
                readFromValue(obj);
            }

            ~MatchmakeResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ModifyUserVirtualCurrencyResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string VirtualCurrency;
            Int32 BalanceChange;
            Int32 Balance;

            ModifyUserVirtualCurrencyResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                BalanceChange(0),
                Balance(0)
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                BalanceChange(src.BalanceChange),
                Balance(src.Balance)
            {}

            ModifyUserVirtualCurrencyResult(const rapidjson::Value& obj) : ModifyUserVirtualCurrencyResult()
            {
                readFromValue(obj);
            }

            ~ModifyUserVirtualCurrencyResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct OpenTradeRequest : public PlayFabBaseModel
        {
            std::list<std::string> OfferedInventoryInstanceIds;
            std::list<std::string> RequestedCatalogItemIds;
            std::list<std::string> AllowedPlayerIds;

            OpenTradeRequest() :
                PlayFabBaseModel(),
                OfferedInventoryInstanceIds(),
                RequestedCatalogItemIds(),
                AllowedPlayerIds()
            {}

            OpenTradeRequest(const OpenTradeRequest& src) :
                PlayFabBaseModel(),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds),
                AllowedPlayerIds(src.AllowedPlayerIds)
            {}

            OpenTradeRequest(const rapidjson::Value& obj) : OpenTradeRequest()
            {
                readFromValue(obj);
            }

            ~OpenTradeRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct OpenTradeResponse : public PlayFabBaseModel
        {
            TradeInfo* Trade;

            OpenTradeResponse() :
                PlayFabBaseModel(),
                Trade(NULL)
            {}

            OpenTradeResponse(const OpenTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : NULL)
            {}

            OpenTradeResponse(const rapidjson::Value& obj) : OpenTradeResponse()
            {
                readFromValue(obj);
            }

            ~OpenTradeResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PayForPurchaseRequest : public PlayFabBaseModel
        {
            std::string OrderId;
            std::string ProviderName;
            std::string Currency;
            std::string ProviderTransactionId;

            PayForPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId(),
                ProviderName(),
                Currency(),
                ProviderTransactionId()
            {}

            PayForPurchaseRequest(const PayForPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                ProviderName(src.ProviderName),
                Currency(src.Currency),
                ProviderTransactionId(src.ProviderTransactionId)
            {}

            PayForPurchaseRequest(const rapidjson::Value& obj) : PayForPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~PayForPurchaseRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum TransactionStatus
        {
            TransactionStatusCreateCart,
            TransactionStatusInit,
            TransactionStatusApproved,
            TransactionStatusSucceeded,
            TransactionStatusFailedByProvider,
            TransactionStatusDisputePending,
            TransactionStatusRefundPending,
            TransactionStatusRefunded,
            TransactionStatusRefundFailed,
            TransactionStatusChargedBack,
            TransactionStatusFailedByUber,
            TransactionStatusFailedByPlayFab,
            TransactionStatusRevoked,
            TransactionStatusTradePending,
            TransactionStatusTraded,
            TransactionStatusUpgraded,
            TransactionStatusStackPending,
            TransactionStatusStacked,
            TransactionStatusOther,
            TransactionStatusFailed
        };

        void writeTransactionStatusEnumJSON(TransactionStatus enumVal, PFStringJsonWriter& writer);
        TransactionStatus readTransactionStatusFromValue(const rapidjson::Value& obj);

        struct PayForPurchaseResult : public PlayFabBaseModel
        {
            std::string OrderId;
            Boxed<TransactionStatus> Status;
            std::map<std::string, Int32> VCAmount;
            std::string PurchaseCurrency;
            Uint32 PurchasePrice;
            Uint32 CreditApplied;
            std::string ProviderData;
            std::string PurchaseConfirmationPageURL;
            std::map<std::string, Int32> VirtualCurrency;

            PayForPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                Status(),
                VCAmount(),
                PurchaseCurrency(),
                PurchasePrice(0),
                CreditApplied(0),
                ProviderData(),
                PurchaseConfirmationPageURL(),
                VirtualCurrency()
            {}

            PayForPurchaseResult(const PayForPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                Status(src.Status),
                VCAmount(src.VCAmount),
                PurchaseCurrency(src.PurchaseCurrency),
                PurchasePrice(src.PurchasePrice),
                CreditApplied(src.CreditApplied),
                ProviderData(src.ProviderData),
                PurchaseConfirmationPageURL(src.PurchaseConfirmationPageURL),
                VirtualCurrency(src.VirtualCurrency)
            {}

            PayForPurchaseResult(const rapidjson::Value& obj) : PayForPurchaseResult()
            {
                readFromValue(obj);
            }

            ~PayForPurchaseResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PaymentOption : public PlayFabBaseModel
        {
            std::string Currency;
            std::string ProviderName;
            Uint32 Price;
            Uint32 StoreCredit;

            PaymentOption() :
                PlayFabBaseModel(),
                Currency(),
                ProviderName(),
                Price(0),
                StoreCredit(0)
            {}

            PaymentOption(const PaymentOption& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                ProviderName(src.ProviderName),
                Price(src.Price),
                StoreCredit(src.StoreCredit)
            {}

            PaymentOption(const rapidjson::Value& obj) : PaymentOption()
            {
                readFromValue(obj);
            }

            ~PaymentOption();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PurchaseItemRequest : public PlayFabBaseModel
        {
            std::string ItemId;
            std::string VirtualCurrency;
            Int32 Price;
            std::string CatalogVersion;
            std::string StoreId;
            std::string CharacterId;

            PurchaseItemRequest() :
                PlayFabBaseModel(),
                ItemId(),
                VirtualCurrency(),
                Price(0),
                CatalogVersion(),
                StoreId(),
                CharacterId()
            {}

            PurchaseItemRequest(const PurchaseItemRequest& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                VirtualCurrency(src.VirtualCurrency),
                Price(src.Price),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                CharacterId(src.CharacterId)
            {}

            PurchaseItemRequest(const rapidjson::Value& obj) : PurchaseItemRequest()
            {
                readFromValue(obj);
            }

            ~PurchaseItemRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PurchaseItemResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> Items;

            PurchaseItemResult() :
                PlayFabBaseModel(),
                Items()
            {}

            PurchaseItemResult(const PurchaseItemResult& src) :
                PlayFabBaseModel(),
                Items(src.Items)
            {}

            PurchaseItemResult(const rapidjson::Value& obj) : PurchaseItemResult()
            {
                readFromValue(obj);
            }

            ~PurchaseItemResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RedeemCouponRequest : public PlayFabBaseModel
        {
            std::string CouponCode;
            std::string CatalogVersion;

            RedeemCouponRequest() :
                PlayFabBaseModel(),
                CouponCode(),
                CatalogVersion()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabBaseModel(),
                CouponCode(src.CouponCode),
                CatalogVersion(src.CatalogVersion)
            {}

            RedeemCouponRequest(const rapidjson::Value& obj) : RedeemCouponRequest()
            {
                readFromValue(obj);
            }

            ~RedeemCouponRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RedeemCouponResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> GrantedItems;

            RedeemCouponResult() :
                PlayFabBaseModel(),
                GrantedItems()
            {}

            RedeemCouponResult(const RedeemCouponResult& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems)
            {}

            RedeemCouponResult(const rapidjson::Value& obj) : RedeemCouponResult()
            {
                readFromValue(obj);
            }

            ~RedeemCouponResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RefreshPSNAuthTokenRequest : public PlayFabBaseModel
        {
            std::string AuthCode;
            std::string RedirectUri;
            OptionalInt32 IssuerId;

            RefreshPSNAuthTokenRequest() :
                PlayFabBaseModel(),
                AuthCode(),
                RedirectUri(),
                IssuerId()
            {}

            RefreshPSNAuthTokenRequest(const RefreshPSNAuthTokenRequest& src) :
                PlayFabBaseModel(),
                AuthCode(src.AuthCode),
                RedirectUri(src.RedirectUri),
                IssuerId(src.IssuerId)
            {}

            RefreshPSNAuthTokenRequest(const rapidjson::Value& obj) : RefreshPSNAuthTokenRequest()
            {
                readFromValue(obj);
            }

            ~RefreshPSNAuthTokenRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegisterForIOSPushNotificationRequest : public PlayFabBaseModel
        {
            std::string DeviceToken;
            OptionalBool SendPushNotificationConfirmation;
            std::string ConfirmationMessage;

            RegisterForIOSPushNotificationRequest() :
                PlayFabBaseModel(),
                DeviceToken(),
                SendPushNotificationConfirmation(),
                ConfirmationMessage()
            {}

            RegisterForIOSPushNotificationRequest(const RegisterForIOSPushNotificationRequest& src) :
                PlayFabBaseModel(),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation),
                ConfirmationMessage(src.ConfirmationMessage)
            {}

            RegisterForIOSPushNotificationRequest(const rapidjson::Value& obj) : RegisterForIOSPushNotificationRequest()
            {
                readFromValue(obj);
            }

            ~RegisterForIOSPushNotificationRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegisterForIOSPushNotificationResult : public PlayFabBaseModel
        {

            RegisterForIOSPushNotificationResult() :
                PlayFabBaseModel()
            {}

            RegisterForIOSPushNotificationResult(const RegisterForIOSPushNotificationResult& src) :
                PlayFabBaseModel()
            {}

            RegisterForIOSPushNotificationResult(const rapidjson::Value& obj) : RegisterForIOSPushNotificationResult()
            {
                readFromValue(obj);
            }

            ~RegisterForIOSPushNotificationResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegisterPlayFabUserRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string Username;
            std::string Email;
            std::string Password;
            OptionalBool RequireBothUsernameAndEmail;
            std::string DisplayName;
            std::string Origination;

            RegisterPlayFabUserRequest() :
                PlayFabBaseModel(),
                TitleId(),
                Username(),
                Email(),
                Password(),
                RequireBothUsernameAndEmail(),
                DisplayName(),
                Origination()
            {}

            RegisterPlayFabUserRequest(const RegisterPlayFabUserRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                Username(src.Username),
                Email(src.Email),
                Password(src.Password),
                RequireBothUsernameAndEmail(src.RequireBothUsernameAndEmail),
                DisplayName(src.DisplayName),
                Origination(src.Origination)
            {}

            RegisterPlayFabUserRequest(const rapidjson::Value& obj) : RegisterPlayFabUserRequest()
            {
                readFromValue(obj);
            }

            ~RegisterPlayFabUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegisterPlayFabUserResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string SessionTicket;
            std::string Username;
            UserSettings* SettingsForUser;

            RegisterPlayFabUserResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                SessionTicket(),
                Username(),
                SettingsForUser(NULL)
            {}

            RegisterPlayFabUserResult(const RegisterPlayFabUserResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                Username(src.Username),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : NULL)
            {}

            RegisterPlayFabUserResult(const rapidjson::Value& obj) : RegisterPlayFabUserResult()
            {
                readFromValue(obj);
            }

            ~RegisterPlayFabUserResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveFriendRequest : public PlayFabBaseModel
        {
            std::string FriendPlayFabId;

            RemoveFriendRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId()
            {}

            RemoveFriendRequest(const RemoveFriendRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId)
            {}

            RemoveFriendRequest(const rapidjson::Value& obj) : RemoveFriendRequest()
            {
                readFromValue(obj);
            }

            ~RemoveFriendRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveFriendResult : public PlayFabBaseModel
        {

            RemoveFriendResult() :
                PlayFabBaseModel()
            {}

            RemoveFriendResult(const RemoveFriendResult& src) :
                PlayFabBaseModel()
            {}

            RemoveFriendResult(const rapidjson::Value& obj) : RemoveFriendResult()
            {
                readFromValue(obj);
            }

            ~RemoveFriendResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveSharedGroupMembersRequest : public PlayFabBaseModel
        {
            std::string SharedGroupId;
            std::list<std::string> PlayFabIds;

            RemoveSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                PlayFabIds()
            {}

            RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                PlayFabIds(src.PlayFabIds)
            {}

            RemoveSharedGroupMembersRequest(const rapidjson::Value& obj) : RemoveSharedGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~RemoveSharedGroupMembersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveSharedGroupMembersResult : public PlayFabBaseModel
        {

            RemoveSharedGroupMembersResult() :
                PlayFabBaseModel()
            {}

            RemoveSharedGroupMembersResult(const RemoveSharedGroupMembersResult& src) :
                PlayFabBaseModel()
            {}

            RemoveSharedGroupMembersResult(const rapidjson::Value& obj) : RemoveSharedGroupMembersResult()
            {
                readFromValue(obj);
            }

            ~RemoveSharedGroupMembersResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ReportPlayerClientRequest : public PlayFabBaseModel
        {
            std::string ReporteeId;
            std::string Comment;

            ReportPlayerClientRequest() :
                PlayFabBaseModel(),
                ReporteeId(),
                Comment()
            {}

            ReportPlayerClientRequest(const ReportPlayerClientRequest& src) :
                PlayFabBaseModel(),
                ReporteeId(src.ReporteeId),
                Comment(src.Comment)
            {}

            ReportPlayerClientRequest(const rapidjson::Value& obj) : ReportPlayerClientRequest()
            {
                readFromValue(obj);
            }

            ~ReportPlayerClientRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ReportPlayerClientResult : public PlayFabBaseModel
        {
            bool Updated;
            Int32 SubmissionsRemaining;

            ReportPlayerClientResult() :
                PlayFabBaseModel(),
                Updated(false),
                SubmissionsRemaining(0)
            {}

            ReportPlayerClientResult(const ReportPlayerClientResult& src) :
                PlayFabBaseModel(),
                Updated(src.Updated),
                SubmissionsRemaining(src.SubmissionsRemaining)
            {}

            ReportPlayerClientResult(const rapidjson::Value& obj) : ReportPlayerClientResult()
            {
                readFromValue(obj);
            }

            ~ReportPlayerClientResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RestoreIOSPurchasesRequest : public PlayFabBaseModel
        {
            std::string ReceiptData;

            RestoreIOSPurchasesRequest() :
                PlayFabBaseModel(),
                ReceiptData()
            {}

            RestoreIOSPurchasesRequest(const RestoreIOSPurchasesRequest& src) :
                PlayFabBaseModel(),
                ReceiptData(src.ReceiptData)
            {}

            RestoreIOSPurchasesRequest(const rapidjson::Value& obj) : RestoreIOSPurchasesRequest()
            {
                readFromValue(obj);
            }

            ~RestoreIOSPurchasesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RestoreIOSPurchasesResult : public PlayFabBaseModel
        {

            RestoreIOSPurchasesResult() :
                PlayFabBaseModel()
            {}

            RestoreIOSPurchasesResult(const RestoreIOSPurchasesResult& src) :
                PlayFabBaseModel()
            {}

            RestoreIOSPurchasesResult(const rapidjson::Value& obj) : RestoreIOSPurchasesResult()
            {
                readFromValue(obj);
            }

            ~RestoreIOSPurchasesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RunCloudScriptRequest : public PlayFabBaseModel
        {
            std::string ActionId;
            MultitypeVar Params;
            std::string ParamsEncoded;

            RunCloudScriptRequest() :
                PlayFabBaseModel(),
                ActionId(),
                Params(),
                ParamsEncoded()
            {}

            RunCloudScriptRequest(const RunCloudScriptRequest& src) :
                PlayFabBaseModel(),
                ActionId(src.ActionId),
                Params(src.Params),
                ParamsEncoded(src.ParamsEncoded)
            {}

            RunCloudScriptRequest(const rapidjson::Value& obj) : RunCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~RunCloudScriptRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RunCloudScriptResult : public PlayFabBaseModel
        {
            std::string ActionId;
            Int32 Version;
            Int32 Revision;
            MultitypeVar Results;
            std::string ResultsEncoded;
            std::string ActionLog;
            double ExecutionTime;

            RunCloudScriptResult() :
                PlayFabBaseModel(),
                ActionId(),
                Version(0),
                Revision(0),
                Results(),
                ResultsEncoded(),
                ActionLog(),
                ExecutionTime(0)
            {}

            RunCloudScriptResult(const RunCloudScriptResult& src) :
                PlayFabBaseModel(),
                ActionId(src.ActionId),
                Version(src.Version),
                Revision(src.Revision),
                Results(src.Results),
                ResultsEncoded(src.ResultsEncoded),
                ActionLog(src.ActionLog),
                ExecutionTime(src.ExecutionTime)
            {}

            RunCloudScriptResult(const rapidjson::Value& obj) : RunCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~RunCloudScriptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabBaseModel
        {
            std::string Email;
            std::string TitleId;
            std::string PublisherId;

            SendAccountRecoveryEmailRequest() :
                PlayFabBaseModel(),
                Email(),
                TitleId(),
                PublisherId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                TitleId(src.TitleId),
                PublisherId(src.PublisherId)
            {}

            SendAccountRecoveryEmailRequest(const rapidjson::Value& obj) : SendAccountRecoveryEmailRequest()
            {
                readFromValue(obj);
            }

            ~SendAccountRecoveryEmailRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SendAccountRecoveryEmailResult : public PlayFabBaseModel
        {

            SendAccountRecoveryEmailResult() :
                PlayFabBaseModel()
            {}

            SendAccountRecoveryEmailResult(const SendAccountRecoveryEmailResult& src) :
                PlayFabBaseModel()
            {}

            SendAccountRecoveryEmailResult(const rapidjson::Value& obj) : SendAccountRecoveryEmailResult()
            {
                readFromValue(obj);
            }

            ~SendAccountRecoveryEmailResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetFriendTagsRequest : public PlayFabBaseModel
        {
            std::string FriendPlayFabId;
            std::list<std::string> Tags;

            SetFriendTagsRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                Tags()
            {}

            SetFriendTagsRequest(const SetFriendTagsRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                Tags(src.Tags)
            {}

            SetFriendTagsRequest(const rapidjson::Value& obj) : SetFriendTagsRequest()
            {
                readFromValue(obj);
            }

            ~SetFriendTagsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetFriendTagsResult : public PlayFabBaseModel
        {

            SetFriendTagsResult() :
                PlayFabBaseModel()
            {}

            SetFriendTagsResult(const SetFriendTagsResult& src) :
                PlayFabBaseModel()
            {}

            SetFriendTagsResult(const rapidjson::Value& obj) : SetFriendTagsResult()
            {
                readFromValue(obj);
            }

            ~SetFriendTagsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StartGameRequest : public PlayFabBaseModel
        {
            std::string BuildVersion;
            Region pfRegion;
            std::string GameMode;
            std::string StatisticName;
            std::string CharacterId;
            std::string CustomCommandLineData;

            StartGameRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                pfRegion(),
                GameMode(),
                StatisticName(),
                CharacterId(),
                CustomCommandLineData()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                pfRegion(src.pfRegion),
                GameMode(src.GameMode),
                StatisticName(src.StatisticName),
                CharacterId(src.CharacterId),
                CustomCommandLineData(src.CustomCommandLineData)
            {}

            StartGameRequest(const rapidjson::Value& obj) : StartGameRequest()
            {
                readFromValue(obj);
            }

            ~StartGameRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StartGameResult : public PlayFabBaseModel
        {
            std::string LobbyID;
            std::string ServerHostname;
            OptionalInt32 ServerPort;
            std::string Ticket;
            std::string Expires;
            std::string Password;

            StartGameResult() :
                PlayFabBaseModel(),
                LobbyID(),
                ServerHostname(),
                ServerPort(),
                Ticket(),
                Expires(),
                Password()
            {}

            StartGameResult(const StartGameResult& src) :
                PlayFabBaseModel(),
                LobbyID(src.LobbyID),
                ServerHostname(src.ServerHostname),
                ServerPort(src.ServerPort),
                Ticket(src.Ticket),
                Expires(src.Expires),
                Password(src.Password)
            {}

            StartGameResult(const rapidjson::Value& obj) : StartGameResult()
            {
                readFromValue(obj);
            }

            ~StartGameResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StartPurchaseRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string StoreId;
            std::list<ItemPuchaseRequest> Items;

            StartPurchaseRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId(),
                Items()
            {}

            StartPurchaseRequest(const StartPurchaseRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                Items(src.Items)
            {}

            StartPurchaseRequest(const rapidjson::Value& obj) : StartPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~StartPurchaseRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StartPurchaseResult : public PlayFabBaseModel
        {
            std::string OrderId;
            std::list<CartItem> Contents;
            std::list<PaymentOption> PaymentOptions;
            std::map<std::string, Int32> VirtualCurrencyBalances;

            StartPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                Contents(),
                PaymentOptions(),
                VirtualCurrencyBalances()
            {}

            StartPurchaseResult(const StartPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                Contents(src.Contents),
                PaymentOptions(src.PaymentOptions),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            StartPurchaseResult(const rapidjson::Value& obj) : StartPurchaseResult()
            {
                readFromValue(obj);
            }

            ~StartPurchaseResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StatisticUpdate : public PlayFabBaseModel
        {
            std::string StatisticName;
            std::string Version;
            Int32 Value;

            StatisticUpdate() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(),
                Value(0)
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version),
                Value(src.Value)
            {}

            StatisticUpdate(const rapidjson::Value& obj) : StatisticUpdate()
            {
                readFromValue(obj);
            }

            ~StatisticUpdate();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            std::string VirtualCurrency;
            Int32 Amount;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                VirtualCurrency(),
                Amount(0)
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            SubtractUserVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~SubtractUserVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkAndroidDeviceIDRequest : public PlayFabBaseModel
        {
            std::string AndroidDeviceId;

            UnlinkAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UnlinkAndroidDeviceIDRequest(const UnlinkAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UnlinkAndroidDeviceIDRequest(const rapidjson::Value& obj) : UnlinkAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkAndroidDeviceIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkAndroidDeviceIDResult : public PlayFabBaseModel
        {

            UnlinkAndroidDeviceIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkAndroidDeviceIDResult(const UnlinkAndroidDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkAndroidDeviceIDResult(const rapidjson::Value& obj) : UnlinkAndroidDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkAndroidDeviceIDResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkCustomIDRequest : public PlayFabBaseModel
        {
            std::string CustomId;

            UnlinkCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UnlinkCustomIDRequest(const UnlinkCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UnlinkCustomIDRequest(const rapidjson::Value& obj) : UnlinkCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkCustomIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkCustomIDResult : public PlayFabBaseModel
        {

            UnlinkCustomIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkCustomIDResult(const UnlinkCustomIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkCustomIDResult(const rapidjson::Value& obj) : UnlinkCustomIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkCustomIDResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkFacebookAccountRequest : public PlayFabBaseModel
        {

            UnlinkFacebookAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountRequest(const UnlinkFacebookAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountRequest(const rapidjson::Value& obj) : UnlinkFacebookAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkFacebookAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkFacebookAccountResult : public PlayFabBaseModel
        {

            UnlinkFacebookAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountResult(const UnlinkFacebookAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountResult(const rapidjson::Value& obj) : UnlinkFacebookAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkFacebookAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkGameCenterAccountRequest : public PlayFabBaseModel
        {

            UnlinkGameCenterAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountRequest(const UnlinkGameCenterAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountRequest(const rapidjson::Value& obj) : UnlinkGameCenterAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkGameCenterAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkGameCenterAccountResult : public PlayFabBaseModel
        {

            UnlinkGameCenterAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountResult(const UnlinkGameCenterAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountResult(const rapidjson::Value& obj) : UnlinkGameCenterAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkGameCenterAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkGoogleAccountRequest : public PlayFabBaseModel
        {

            UnlinkGoogleAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountRequest(const UnlinkGoogleAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountRequest(const rapidjson::Value& obj) : UnlinkGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkGoogleAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkGoogleAccountResult : public PlayFabBaseModel
        {

            UnlinkGoogleAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountResult(const UnlinkGoogleAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountResult(const rapidjson::Value& obj) : UnlinkGoogleAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkGoogleAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkIOSDeviceIDRequest : public PlayFabBaseModel
        {
            std::string DeviceId;

            UnlinkIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                DeviceId()
            {}

            UnlinkIOSDeviceIDRequest(const UnlinkIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                DeviceId(src.DeviceId)
            {}

            UnlinkIOSDeviceIDRequest(const rapidjson::Value& obj) : UnlinkIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkIOSDeviceIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkIOSDeviceIDResult : public PlayFabBaseModel
        {

            UnlinkIOSDeviceIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkIOSDeviceIDResult(const UnlinkIOSDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkIOSDeviceIDResult(const rapidjson::Value& obj) : UnlinkIOSDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkIOSDeviceIDResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkKongregateAccountRequest : public PlayFabBaseModel
        {

            UnlinkKongregateAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountRequest(const UnlinkKongregateAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountRequest(const rapidjson::Value& obj) : UnlinkKongregateAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkKongregateAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkKongregateAccountResult : public PlayFabBaseModel
        {

            UnlinkKongregateAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountResult(const UnlinkKongregateAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountResult(const rapidjson::Value& obj) : UnlinkKongregateAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkKongregateAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkPSNAccountRequest : public PlayFabBaseModel
        {

            UnlinkPSNAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkPSNAccountRequest(const UnlinkPSNAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkPSNAccountRequest(const rapidjson::Value& obj) : UnlinkPSNAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkPSNAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkPSNAccountResult : public PlayFabBaseModel
        {

            UnlinkPSNAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkPSNAccountResult(const UnlinkPSNAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkPSNAccountResult(const rapidjson::Value& obj) : UnlinkPSNAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkPSNAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkSteamAccountRequest : public PlayFabBaseModel
        {

            UnlinkSteamAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountRequest(const UnlinkSteamAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountRequest(const rapidjson::Value& obj) : UnlinkSteamAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkSteamAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkSteamAccountResult : public PlayFabBaseModel
        {

            UnlinkSteamAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountResult(const UnlinkSteamAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountResult(const rapidjson::Value& obj) : UnlinkSteamAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkSteamAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkXboxAccountRequest : public PlayFabBaseModel
        {
            std::string XboxToken;

            UnlinkXboxAccountRequest() :
                PlayFabBaseModel(),
                XboxToken()
            {}

            UnlinkXboxAccountRequest(const UnlinkXboxAccountRequest& src) :
                PlayFabBaseModel(),
                XboxToken(src.XboxToken)
            {}

            UnlinkXboxAccountRequest(const rapidjson::Value& obj) : UnlinkXboxAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkXboxAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkXboxAccountResult : public PlayFabBaseModel
        {

            UnlinkXboxAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkXboxAccountResult(const UnlinkXboxAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkXboxAccountResult(const rapidjson::Value& obj) : UnlinkXboxAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkXboxAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlockContainerItemRequest : public PlayFabBaseModel
        {
            std::string ContainerItemId;
            std::string CatalogVersion;
            std::string CharacterId;

            UnlockContainerItemRequest() :
                PlayFabBaseModel(),
                ContainerItemId(),
                CatalogVersion(),
                CharacterId()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabBaseModel(),
                ContainerItemId(src.ContainerItemId),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId)
            {}

            UnlockContainerItemRequest(const rapidjson::Value& obj) : UnlockContainerItemRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlockContainerItemResult : public PlayFabBaseModel
        {
            std::string UnlockedItemInstanceId;
            std::string UnlockedWithItemInstanceId;
            std::list<ItemInstance> GrantedItems;
            std::map<std::string, Uint32> VirtualCurrency;

            UnlockContainerItemResult() :
                PlayFabBaseModel(),
                UnlockedItemInstanceId(),
                UnlockedWithItemInstanceId(),
                GrantedItems(),
                VirtualCurrency()
            {}

            UnlockContainerItemResult(const UnlockContainerItemResult& src) :
                PlayFabBaseModel(),
                UnlockedItemInstanceId(src.UnlockedItemInstanceId),
                UnlockedWithItemInstanceId(src.UnlockedWithItemInstanceId),
                GrantedItems(src.GrantedItems),
                VirtualCurrency(src.VirtualCurrency)
            {}

            UnlockContainerItemResult(const rapidjson::Value& obj) : UnlockContainerItemResult()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCharacterDataRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateCharacterDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateCharacterDataRequest(const rapidjson::Value& obj) : UpdateCharacterDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCharacterDataResult : public PlayFabBaseModel
        {
            Uint32 DataVersion;

            UpdateCharacterDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateCharacterDataResult(const UpdateCharacterDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateCharacterDataResult(const rapidjson::Value& obj) : UpdateCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerStatisticsRequest : public PlayFabBaseModel
        {
            std::list<StatisticUpdate> Statistics;

            UpdatePlayerStatisticsRequest() :
                PlayFabBaseModel(),
                Statistics()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            UpdatePlayerStatisticsRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerStatisticsResult : public PlayFabBaseModel
        {

            UpdatePlayerStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const UpdatePlayerStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const rapidjson::Value& obj) : UpdatePlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateSharedGroupDataRequest : public PlayFabBaseModel
        {
            std::string SharedGroupId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateSharedGroupDataRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateSharedGroupDataRequest(const rapidjson::Value& obj) : UpdateSharedGroupDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateSharedGroupDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateSharedGroupDataResult : public PlayFabBaseModel
        {

            UpdateSharedGroupDataResult() :
                PlayFabBaseModel()
            {}

            UpdateSharedGroupDataResult(const UpdateSharedGroupDataResult& src) :
                PlayFabBaseModel()
            {}

            UpdateSharedGroupDataResult(const rapidjson::Value& obj) : UpdateSharedGroupDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateSharedGroupDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserDataRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateUserDataRequest(const rapidjson::Value& obj) : UpdateUserDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserDataResult : public PlayFabBaseModel
        {
            Uint32 DataVersion;

            UpdateUserDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateUserDataResult(const UpdateUserDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateUserDataResult(const rapidjson::Value& obj) : UpdateUserDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserStatisticsRequest : public PlayFabBaseModel
        {
            std::map<std::string, Int32> UserStatistics;

            UpdateUserStatisticsRequest() :
                PlayFabBaseModel(),
                UserStatistics()
            {}

            UpdateUserStatisticsRequest(const UpdateUserStatisticsRequest& src) :
                PlayFabBaseModel(),
                UserStatistics(src.UserStatistics)
            {}

            UpdateUserStatisticsRequest(const rapidjson::Value& obj) : UpdateUserStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserStatisticsResult : public PlayFabBaseModel
        {

            UpdateUserStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdateUserStatisticsResult(const UpdateUserStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateUserStatisticsResult(const rapidjson::Value& obj) : UpdateUserStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserTitleDisplayNameRequest : public PlayFabBaseModel
        {
            std::string DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabBaseModel(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName)
            {}

            UpdateUserTitleDisplayNameRequest(const rapidjson::Value& obj) : UpdateUserTitleDisplayNameRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserTitleDisplayNameRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserTitleDisplayNameResult : public PlayFabBaseModel
        {
            std::string DisplayName;

            UpdateUserTitleDisplayNameResult() :
                PlayFabBaseModel(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameResult(const UpdateUserTitleDisplayNameResult& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName)
            {}

            UpdateUserTitleDisplayNameResult(const rapidjson::Value& obj) : UpdateUserTitleDisplayNameResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserTitleDisplayNameResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateAmazonReceiptRequest : public PlayFabBaseModel
        {
            std::string ReceiptId;
            std::string UserId;
            std::string CatalogVersion;
            std::string CurrencyCode;
            Int32 PurchasePrice;

            ValidateAmazonReceiptRequest() :
                PlayFabBaseModel(),
                ReceiptId(),
                UserId(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(0)
            {}

            ValidateAmazonReceiptRequest(const ValidateAmazonReceiptRequest& src) :
                PlayFabBaseModel(),
                ReceiptId(src.ReceiptId),
                UserId(src.UserId),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice)
            {}

            ValidateAmazonReceiptRequest(const rapidjson::Value& obj) : ValidateAmazonReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateAmazonReceiptRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateAmazonReceiptResult : public PlayFabBaseModel
        {

            ValidateAmazonReceiptResult() :
                PlayFabBaseModel()
            {}

            ValidateAmazonReceiptResult(const ValidateAmazonReceiptResult& src) :
                PlayFabBaseModel()
            {}

            ValidateAmazonReceiptResult(const rapidjson::Value& obj) : ValidateAmazonReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateAmazonReceiptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateGooglePlayPurchaseRequest : public PlayFabBaseModel
        {
            std::string ReceiptJson;
            std::string Signature;
            std::string CurrencyCode;
            OptionalUint32 PurchasePrice;

            ValidateGooglePlayPurchaseRequest() :
                PlayFabBaseModel(),
                ReceiptJson(),
                Signature(),
                CurrencyCode(),
                PurchasePrice()
            {}

            ValidateGooglePlayPurchaseRequest(const ValidateGooglePlayPurchaseRequest& src) :
                PlayFabBaseModel(),
                ReceiptJson(src.ReceiptJson),
                Signature(src.Signature),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice)
            {}

            ValidateGooglePlayPurchaseRequest(const rapidjson::Value& obj) : ValidateGooglePlayPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ValidateGooglePlayPurchaseRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateGooglePlayPurchaseResult : public PlayFabBaseModel
        {

            ValidateGooglePlayPurchaseResult() :
                PlayFabBaseModel()
            {}

            ValidateGooglePlayPurchaseResult(const ValidateGooglePlayPurchaseResult& src) :
                PlayFabBaseModel()
            {}

            ValidateGooglePlayPurchaseResult(const rapidjson::Value& obj) : ValidateGooglePlayPurchaseResult()
            {
                readFromValue(obj);
            }

            ~ValidateGooglePlayPurchaseResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateIOSReceiptRequest : public PlayFabBaseModel
        {
            std::string ReceiptData;
            std::string CurrencyCode;
            Int32 PurchasePrice;

            ValidateIOSReceiptRequest() :
                PlayFabBaseModel(),
                ReceiptData(),
                CurrencyCode(),
                PurchasePrice(0)
            {}

            ValidateIOSReceiptRequest(const ValidateIOSReceiptRequest& src) :
                PlayFabBaseModel(),
                ReceiptData(src.ReceiptData),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice)
            {}

            ValidateIOSReceiptRequest(const rapidjson::Value& obj) : ValidateIOSReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateIOSReceiptRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateIOSReceiptResult : public PlayFabBaseModel
        {

            ValidateIOSReceiptResult() :
                PlayFabBaseModel()
            {}

            ValidateIOSReceiptResult(const ValidateIOSReceiptResult& src) :
                PlayFabBaseModel()
            {}

            ValidateIOSReceiptResult(const rapidjson::Value& obj) : ValidateIOSReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateIOSReceiptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
