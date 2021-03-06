#ifndef PLAYFAB_CLIENT_DATA_MODELS_H_
#define PLAYFAB_CLIENT_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ClientModels
    {
        struct AcceptTradeRequest : public PlayFabBaseModel
        {
            std::list<std::string> AcceptedInventoryInstanceIds;
            std::string OfferingPlayerId;
            std::string TradeId;

            AcceptTradeRequest() :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(),
                OfferingPlayerId(),
                TradeId()
            {}

            AcceptTradeRequest(const AcceptTradeRequest& src) :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
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
            std::list<std::string> AcceptedInventoryInstanceIds;
            std::string AcceptedPlayerId;
            std::list<std::string> AllowedPlayerIds;
            OptionalTime CancelledAt;
            OptionalTime FilledAt;
            OptionalTime InvalidatedAt;
            std::list<std::string> OfferedCatalogItemIds;
            std::list<std::string> OfferedInventoryInstanceIds;
            std::string OfferingPlayerId;
            OptionalTime OpenedAt;
            std::list<std::string> RequestedCatalogItemIds;
            Boxed<TradeStatus> Status;
            std::string TradeId;

            TradeInfo() :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(),
                AcceptedPlayerId(),
                AllowedPlayerIds(),
                CancelledAt(),
                FilledAt(),
                InvalidatedAt(),
                OfferedCatalogItemIds(),
                OfferedInventoryInstanceIds(),
                OfferingPlayerId(),
                OpenedAt(),
                RequestedCatalogItemIds(),
                Status(),
                TradeId()
            {}

            TradeInfo(const TradeInfo& src) :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                AcceptedPlayerId(src.AcceptedPlayerId),
                AllowedPlayerIds(src.AllowedPlayerIds),
                CancelledAt(src.CancelledAt),
                FilledAt(src.FilledAt),
                InvalidatedAt(src.InvalidatedAt),
                OfferedCatalogItemIds(src.OfferedCatalogItemIds),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                OfferingPlayerId(src.OfferingPlayerId),
                OpenedAt(src.OpenedAt),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds),
                Status(src.Status),
                TradeId(src.TradeId)
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

        enum AdActivity
        {
            AdActivityOpened,
            AdActivityClosed,
            AdActivityStart,
            AdActivityEnd
        };

        void writeAdActivityEnumJSON(AdActivity enumVal, PFStringJsonWriter& writer);
        AdActivity readAdActivityFromValue(const rapidjson::Value& obj);

        struct AdCampaignAttributionModel : public PlayFabBaseModel
        {
            time_t AttributedAt;
            std::string CampaignId;
            std::string Platform;

            AdCampaignAttributionModel() :
                PlayFabBaseModel(),
                AttributedAt(0),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttributionModel(const AdCampaignAttributionModel& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            AdCampaignAttributionModel(const rapidjson::Value& obj) : AdCampaignAttributionModel()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttributionModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddFriendRequest : public PlayFabBaseModel
        {
            std::string FriendEmail;
            std::string FriendPlayFabId;
            std::string FriendTitleDisplayName;
            std::string FriendUsername;

            AddFriendRequest() :
                PlayFabBaseModel(),
                FriendEmail(),
                FriendPlayFabId(),
                FriendTitleDisplayName(),
                FriendUsername()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabBaseModel(),
                FriendEmail(src.FriendEmail),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendTitleDisplayName(src.FriendTitleDisplayName),
                FriendUsername(src.FriendUsername)
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

        struct GenericServiceId : public PlayFabBaseModel
        {
            std::string ServiceName;
            std::string UserId;

            GenericServiceId() :
                PlayFabBaseModel(),
                ServiceName(),
                UserId()
            {}

            GenericServiceId(const GenericServiceId& src) :
                PlayFabBaseModel(),
                ServiceName(src.ServiceName),
                UserId(src.UserId)
            {}

            GenericServiceId(const rapidjson::Value& obj) : GenericServiceId()
            {
                readFromValue(obj);
            }

            ~GenericServiceId();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddGenericIDRequest : public PlayFabBaseModel
        {
            GenericServiceId GenericId;

            AddGenericIDRequest() :
                PlayFabBaseModel(),
                GenericId()
            {}

            AddGenericIDRequest(const AddGenericIDRequest& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId)
            {}

            AddGenericIDRequest(const rapidjson::Value& obj) : AddGenericIDRequest()
            {
                readFromValue(obj);
            }

            ~AddGenericIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddGenericIDResult : public PlayFabBaseModel
        {

            AddGenericIDResult() :
                PlayFabBaseModel()
            {}

            AddGenericIDResult(const AddGenericIDResult& src) :
                PlayFabBaseModel()
            {}

            AddGenericIDResult(const rapidjson::Value& obj) : AddGenericIDResult()
            {
                readFromValue(obj);
            }

            ~AddGenericIDResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddOrUpdateContactEmailRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string EmailAddress;

            AddOrUpdateContactEmailRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                EmailAddress()
            {}

            AddOrUpdateContactEmailRequest(const AddOrUpdateContactEmailRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                EmailAddress(src.EmailAddress)
            {}

            AddOrUpdateContactEmailRequest(const rapidjson::Value& obj) : AddOrUpdateContactEmailRequest()
            {
                readFromValue(obj);
            }

            ~AddOrUpdateContactEmailRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddOrUpdateContactEmailResult : public PlayFabBaseModel
        {

            AddOrUpdateContactEmailResult() :
                PlayFabBaseModel()
            {}

            AddOrUpdateContactEmailResult(const AddOrUpdateContactEmailResult& src) :
                PlayFabBaseModel()
            {}

            AddOrUpdateContactEmailResult(const rapidjson::Value& obj) : AddOrUpdateContactEmailResult()
            {
                readFromValue(obj);
            }

            ~AddOrUpdateContactEmailResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddSharedGroupMembersRequest : public PlayFabBaseModel
        {
            std::list<std::string> PlayFabIds;
            std::string SharedGroupId;

            AddSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                SharedGroupId()
            {}

            AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
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
            std::map<std::string, std::string> CustomTags;
            std::string Email;
            std::string Password;
            std::string Username;

            AddUsernamePasswordRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Email(),
                Password(),
                Username()
            {}

            AddUsernamePasswordRequest(const AddUsernamePasswordRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Email(src.Email),
                Password(src.Password),
                Username(src.Username)
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
            Int32 Amount;
            std::map<std::string, std::string> CustomTags;
            std::string VirtualCurrency;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                CustomTags(),
                VirtualCurrency()
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                CustomTags(src.CustomTags),
                VirtualCurrency(src.VirtualCurrency)
            {}

            AddUserVirtualCurrencyRequest(const rapidjson::Value& obj) : AddUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddUserVirtualCurrencyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AdPlacementDetails : public PlayFabBaseModel
        {
            std::string PlacementId;
            std::string PlacementName;
            OptionalInt32 PlacementViewsRemaining;
            OptionalDouble PlacementViewsResetMinutes;
            std::string RewardAssetUrl;
            std::string RewardDescription;
            std::string RewardId;
            std::string RewardName;

            AdPlacementDetails() :
                PlayFabBaseModel(),
                PlacementId(),
                PlacementName(),
                PlacementViewsRemaining(),
                PlacementViewsResetMinutes(),
                RewardAssetUrl(),
                RewardDescription(),
                RewardId(),
                RewardName()
            {}

            AdPlacementDetails(const AdPlacementDetails& src) :
                PlayFabBaseModel(),
                PlacementId(src.PlacementId),
                PlacementName(src.PlacementName),
                PlacementViewsRemaining(src.PlacementViewsRemaining),
                PlacementViewsResetMinutes(src.PlacementViewsResetMinutes),
                RewardAssetUrl(src.RewardAssetUrl),
                RewardDescription(src.RewardDescription),
                RewardId(src.RewardId),
                RewardName(src.RewardName)
            {}

            AdPlacementDetails(const rapidjson::Value& obj) : AdPlacementDetails()
            {
                readFromValue(obj);
            }

            ~AdPlacementDetails();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AdRewardItemGranted : public PlayFabBaseModel
        {
            std::string CatalogId;
            std::string DisplayName;
            std::string InstanceId;
            std::string ItemId;

            AdRewardItemGranted() :
                PlayFabBaseModel(),
                CatalogId(),
                DisplayName(),
                InstanceId(),
                ItemId()
            {}

            AdRewardItemGranted(const AdRewardItemGranted& src) :
                PlayFabBaseModel(),
                CatalogId(src.CatalogId),
                DisplayName(src.DisplayName),
                InstanceId(src.InstanceId),
                ItemId(src.ItemId)
            {}

            AdRewardItemGranted(const rapidjson::Value& obj) : AdRewardItemGranted()
            {
                readFromValue(obj);
            }

            ~AdRewardItemGranted();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AdRewardResults : public PlayFabBaseModel
        {
            std::list<AdRewardItemGranted> GrantedItems;
            std::map<std::string, Int32> GrantedVirtualCurrencies;
            std::map<std::string, Int32> IncrementedStatistics;

            AdRewardResults() :
                PlayFabBaseModel(),
                GrantedItems(),
                GrantedVirtualCurrencies(),
                IncrementedStatistics()
            {}

            AdRewardResults(const AdRewardResults& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems),
                GrantedVirtualCurrencies(src.GrantedVirtualCurrencies),
                IncrementedStatistics(src.IncrementedStatistics)
            {}

            AdRewardResults(const rapidjson::Value& obj) : AdRewardResults()
            {
                readFromValue(obj);
            }

            ~AdRewardResults();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AndroidDevicePushNotificationRegistrationRequest : public PlayFabBaseModel
        {
            std::string ConfirmationMessage;
            std::string DeviceToken;
            OptionalBool SendPushNotificationConfirmation;

            AndroidDevicePushNotificationRegistrationRequest() :
                PlayFabBaseModel(),
                ConfirmationMessage(),
                DeviceToken(),
                SendPushNotificationConfirmation()
            {}

            AndroidDevicePushNotificationRegistrationRequest(const AndroidDevicePushNotificationRegistrationRequest& src) :
                PlayFabBaseModel(),
                ConfirmationMessage(src.ConfirmationMessage),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation)
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
            std::string Adid;
            std::string Idfa;

            AttributeInstallRequest() :
                PlayFabBaseModel(),
                Adid(),
                Idfa()
            {}

            AttributeInstallRequest(const AttributeInstallRequest& src) :
                PlayFabBaseModel(),
                Adid(src.Adid),
                Idfa(src.Idfa)
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
            std::string Description;
            std::string DisplayName;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::map<std::string, Uint32> VCAmount;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            CartItem() :
                PlayFabBaseModel(),
                Description(),
                DisplayName(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                RealCurrencyPrices(),
                VCAmount(),
                VirtualCurrencyPrices()
            {}

            CartItem(const CartItem& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                DisplayName(src.DisplayName),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VCAmount(src.VCAmount),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            CartItem(const rapidjson::Value& obj) : CartItem()
            {
                readFromValue(obj);
            }

            ~CartItem();

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
            std::list<std::string> ItemContents;
            std::string KeyItemId;
            std::list<std::string> ResultTableContents;
            std::map<std::string, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                ItemContents(),
                KeyItemId(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                ItemContents(src.ItemContents),
                KeyItemId(src.KeyItemId),
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

        struct CatalogItem : public PlayFabBaseModel
        {
            CatalogItemBundleInfo* Bundle;
            bool CanBecomeCharacter;
            std::string CatalogVersion;
            CatalogItemConsumableInfo* Consumable;
            CatalogItemContainerInfo* Container;
            std::string CustomData;
            std::string Description;
            std::string DisplayName;
            Int32 InitialLimitedEditionCount;
            bool IsLimitedEdition;
            bool IsStackable;
            bool IsTradable;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemImageUrl;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::list<std::string> Tags;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            CatalogItem() :
                PlayFabBaseModel(),
                Bundle(NULL),
                CanBecomeCharacter(false),
                CatalogVersion(),
                Consumable(NULL),
                Container(NULL),
                CustomData(),
                Description(),
                DisplayName(),
                InitialLimitedEditionCount(0),
                IsLimitedEdition(false),
                IsStackable(false),
                IsTradable(false),
                ItemClass(),
                ItemId(),
                ItemImageUrl(),
                RealCurrencyPrices(),
                Tags(),
                VirtualCurrencyPrices()
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : NULL),
                CanBecomeCharacter(src.CanBecomeCharacter),
                CatalogVersion(src.CatalogVersion),
                Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : NULL),
                Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : NULL),
                CustomData(src.CustomData),
                Description(src.Description),
                DisplayName(src.DisplayName),
                InitialLimitedEditionCount(src.InitialLimitedEditionCount),
                IsLimitedEdition(src.IsLimitedEdition),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemImageUrl(src.ItemImageUrl),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ItemInstance : public PlayFabBaseModel
        {
            std::string Annotation;
            std::list<std::string> BundleContents;
            std::string BundleParent;
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomData;
            std::string DisplayName;
            OptionalTime Expiration;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            OptionalTime PurchaseDate;
            OptionalInt32 RemainingUses;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            OptionalInt32 UsesIncrementedBy;

            ItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PurchaseDate(),
                RemainingUses(),
                UnitCurrency(),
                UnitPrice(0),
                UsesIncrementedBy()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
            {}

            ItemInstance(const rapidjson::Value& obj) : ItemInstance()
            {
                readFromValue(obj);
            }

            ~ItemInstance();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CharacterInventory : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::list<ItemInstance> Inventory;

            CharacterInventory() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory()
            {}

            CharacterInventory(const CharacterInventory& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory)
            {}

            CharacterInventory(const rapidjson::Value& obj) : CharacterInventory()
            {
                readFromValue(obj);
            }

            ~CharacterInventory();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CharacterLeaderboardEntry : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string CharacterName;
            std::string CharacterType;
            std::string DisplayName;
            std::string PlayFabId;
            Int32 Position;
            Int32 StatValue;

            CharacterLeaderboardEntry() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType(),
                DisplayName(),
                PlayFabId(),
                Position(0),
                StatValue(0)
            {}

            CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                StatValue(src.StatValue)
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

        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        void writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer);
        CloudScriptRevisionOption readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj);

        struct Container_Dictionary_String_String : public PlayFabBaseModel
        {
            std::map<std::string, std::string> Data;

            Container_Dictionary_String_String() :
                PlayFabBaseModel(),
                Data()
            {}

            Container_Dictionary_String_String(const Container_Dictionary_String_String& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            Container_Dictionary_String_String(const rapidjson::Value& obj) : Container_Dictionary_String_String()
            {
                readFromValue(obj);
            }

            ~Container_Dictionary_String_String();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CollectionFilter : public PlayFabBaseModel
        {
            std::list<Container_Dictionary_String_String> Excludes;
            std::list<Container_Dictionary_String_String> Includes;

            CollectionFilter() :
                PlayFabBaseModel(),
                Excludes(),
                Includes()
            {}

            CollectionFilter(const CollectionFilter& src) :
                PlayFabBaseModel(),
                Excludes(src.Excludes),
                Includes(src.Includes)
            {}

            CollectionFilter(const rapidjson::Value& obj) : CollectionFilter()
            {
                readFromValue(obj);
            }

            ~CollectionFilter();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConfirmPurchaseRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string OrderId;

            ConfirmPurchaseRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                OrderId()
            {}

            ConfirmPurchaseRequest(const ConfirmPurchaseRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
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

        struct ConfirmPurchaseResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> Items;
            std::string OrderId;
            time_t PurchaseDate;

            ConfirmPurchaseResult() :
                PlayFabBaseModel(),
                Items(),
                OrderId(),
                PurchaseDate(0)
            {}

            ConfirmPurchaseResult(const ConfirmPurchaseResult& src) :
                PlayFabBaseModel(),
                Items(src.Items),
                OrderId(src.OrderId),
                PurchaseDate(src.PurchaseDate)
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
            std::string CharacterId;
            Int32 ConsumeCount;
            std::map<std::string, std::string> CustomTags;
            std::string ItemInstanceId;

            ConsumeItemRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                ConsumeCount(0),
                CustomTags(),
                ItemInstanceId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ConsumeCount(src.ConsumeCount),
                CustomTags(src.CustomTags),
                ItemInstanceId(src.ItemInstanceId)
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
            std::map<std::string, std::string> CustomTags;
            Int32 ServiceLabel;

            ConsumePSNEntitlementsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CustomTags(),
                ServiceLabel(0)
            {}

            ConsumePSNEntitlementsRequest(const ConsumePSNEntitlementsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
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

        struct ConsumeXboxEntitlementsRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomTags;
            std::string XboxToken;

            ConsumeXboxEntitlementsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CustomTags(),
                XboxToken()
            {}

            ConsumeXboxEntitlementsRequest(const ConsumeXboxEntitlementsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
                XboxToken(src.XboxToken)
            {}

            ConsumeXboxEntitlementsRequest(const rapidjson::Value& obj) : ConsumeXboxEntitlementsRequest()
            {
                readFromValue(obj);
            }

            ~ConsumeXboxEntitlementsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConsumeXboxEntitlementsResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> Items;

            ConsumeXboxEntitlementsResult() :
                PlayFabBaseModel(),
                Items()
            {}

            ConsumeXboxEntitlementsResult(const ConsumeXboxEntitlementsResult& src) :
                PlayFabBaseModel(),
                Items(src.Items)
            {}

            ConsumeXboxEntitlementsResult(const rapidjson::Value& obj) : ConsumeXboxEntitlementsResult()
            {
                readFromValue(obj);
            }

            ~ConsumeXboxEntitlementsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum EmailVerificationStatus
        {
            EmailVerificationStatusUnverified,
            EmailVerificationStatusPending,
            EmailVerificationStatusConfirmed
        };

        void writeEmailVerificationStatusEnumJSON(EmailVerificationStatus enumVal, PFStringJsonWriter& writer);
        EmailVerificationStatus readEmailVerificationStatusFromValue(const rapidjson::Value& obj);

        struct ContactEmailInfoModel : public PlayFabBaseModel
        {
            std::string EmailAddress;
            std::string Name;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfoModel() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name(),
                VerificationStatus()
            {}

            ContactEmailInfoModel(const ContactEmailInfoModel& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name),
                VerificationStatus(src.VerificationStatus)
            {}

            ContactEmailInfoModel(const rapidjson::Value& obj) : ContactEmailInfoModel()
            {
                readFromValue(obj);
            }

            ~ContactEmailInfoModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum ContinentCode
        {
            ContinentCodeAF,
            ContinentCodeAN,
            ContinentCodeAS,
            ContinentCodeEU,
            ContinentCodeNA,
            ContinentCodeOC,
            ContinentCodeSA
        };

        void writeContinentCodeEnumJSON(ContinentCode enumVal, PFStringJsonWriter& writer);
        ContinentCode readContinentCodeFromValue(const rapidjson::Value& obj);

        enum CountryCode
        {
            CountryCodeAF,
            CountryCodeAX,
            CountryCodeAL,
            CountryCodeDZ,
            CountryCodeAS,
            CountryCodeAD,
            CountryCodeAO,
            CountryCodeAI,
            CountryCodeAQ,
            CountryCodeAG,
            CountryCodeAR,
            CountryCodeAM,
            CountryCodeAW,
            CountryCodeAU,
            CountryCodeAT,
            CountryCodeAZ,
            CountryCodeBS,
            CountryCodeBH,
            CountryCodeBD,
            CountryCodeBB,
            CountryCodeBY,
            CountryCodeBE,
            CountryCodeBZ,
            CountryCodeBJ,
            CountryCodeBM,
            CountryCodeBT,
            CountryCodeBO,
            CountryCodeBQ,
            CountryCodeBA,
            CountryCodeBW,
            CountryCodeBV,
            CountryCodeBR,
            CountryCodeIO,
            CountryCodeBN,
            CountryCodeBG,
            CountryCodeBF,
            CountryCodeBI,
            CountryCodeKH,
            CountryCodeCM,
            CountryCodeCA,
            CountryCodeCV,
            CountryCodeKY,
            CountryCodeCF,
            CountryCodeTD,
            CountryCodeCL,
            CountryCodeCN,
            CountryCodeCX,
            CountryCodeCC,
            CountryCodeCO,
            CountryCodeKM,
            CountryCodeCG,
            CountryCodeCD,
            CountryCodeCK,
            CountryCodeCR,
            CountryCodeCI,
            CountryCodeHR,
            CountryCodeCU,
            CountryCodeCW,
            CountryCodeCY,
            CountryCodeCZ,
            CountryCodeDK,
            CountryCodeDJ,
            CountryCodeDM,
            CountryCodeDO,
            CountryCodeEC,
            CountryCodeEG,
            CountryCodeSV,
            CountryCodeGQ,
            CountryCodeER,
            CountryCodeEE,
            CountryCodeET,
            CountryCodeFK,
            CountryCodeFO,
            CountryCodeFJ,
            CountryCodeFI,
            CountryCodeFR,
            CountryCodeGF,
            CountryCodePF,
            CountryCodeTF,
            CountryCodeGA,
            CountryCodeGM,
            CountryCodeGE,
            CountryCodeDE,
            CountryCodeGH,
            CountryCodeGI,
            CountryCodeGR,
            CountryCodeGL,
            CountryCodeGD,
            CountryCodeGP,
            CountryCodeGU,
            CountryCodeGT,
            CountryCodeGG,
            CountryCodeGN,
            CountryCodeGW,
            CountryCodeGY,
            CountryCodeHT,
            CountryCodeHM,
            CountryCodeVA,
            CountryCodeHN,
            CountryCodeHK,
            CountryCodeHU,
            CountryCodeIS,
            CountryCodeIN,
            CountryCodeID,
            CountryCodeIR,
            CountryCodeIQ,
            CountryCodeIE,
            CountryCodeIM,
            CountryCodeIL,
            CountryCodeIT,
            CountryCodeJM,
            CountryCodeJP,
            CountryCodeJE,
            CountryCodeJO,
            CountryCodeKZ,
            CountryCodeKE,
            CountryCodeKI,
            CountryCodeKP,
            CountryCodeKR,
            CountryCodeKW,
            CountryCodeKG,
            CountryCodeLA,
            CountryCodeLV,
            CountryCodeLB,
            CountryCodeLS,
            CountryCodeLR,
            CountryCodeLY,
            CountryCodeLI,
            CountryCodeLT,
            CountryCodeLU,
            CountryCodeMO,
            CountryCodeMK,
            CountryCodeMG,
            CountryCodeMW,
            CountryCodeMY,
            CountryCodeMV,
            CountryCodeML,
            CountryCodeMT,
            CountryCodeMH,
            CountryCodeMQ,
            CountryCodeMR,
            CountryCodeMU,
            CountryCodeYT,
            CountryCodeMX,
            CountryCodeFM,
            CountryCodeMD,
            CountryCodeMC,
            CountryCodeMN,
            CountryCodeME,
            CountryCodeMS,
            CountryCodeMA,
            CountryCodeMZ,
            CountryCodeMM,
            CountryCodeNA,
            CountryCodeNR,
            CountryCodeNP,
            CountryCodeNL,
            CountryCodeNC,
            CountryCodeNZ,
            CountryCodeNI,
            CountryCodeNE,
            CountryCodeNG,
            CountryCodeNU,
            CountryCodeNF,
            CountryCodeMP,
            CountryCodeNO,
            CountryCodeOM,
            CountryCodePK,
            CountryCodePW,
            CountryCodePS,
            CountryCodePA,
            CountryCodePG,
            CountryCodePY,
            CountryCodePE,
            CountryCodePH,
            CountryCodePN,
            CountryCodePL,
            CountryCodePT,
            CountryCodePR,
            CountryCodeQA,
            CountryCodeRE,
            CountryCodeRO,
            CountryCodeRU,
            CountryCodeRW,
            CountryCodeBL,
            CountryCodeSH,
            CountryCodeKN,
            CountryCodeLC,
            CountryCodeMF,
            CountryCodePM,
            CountryCodeVC,
            CountryCodeWS,
            CountryCodeSM,
            CountryCodeST,
            CountryCodeSA,
            CountryCodeSN,
            CountryCodeRS,
            CountryCodeSC,
            CountryCodeSL,
            CountryCodeSG,
            CountryCodeSX,
            CountryCodeSK,
            CountryCodeSI,
            CountryCodeSB,
            CountryCodeSO,
            CountryCodeZA,
            CountryCodeGS,
            CountryCodeSS,
            CountryCodeES,
            CountryCodeLK,
            CountryCodeSD,
            CountryCodeSR,
            CountryCodeSJ,
            CountryCodeSZ,
            CountryCodeSE,
            CountryCodeCH,
            CountryCodeSY,
            CountryCodeTW,
            CountryCodeTJ,
            CountryCodeTZ,
            CountryCodeTH,
            CountryCodeTL,
            CountryCodeTG,
            CountryCodeTK,
            CountryCodeTO,
            CountryCodeTT,
            CountryCodeTN,
            CountryCodeTR,
            CountryCodeTM,
            CountryCodeTC,
            CountryCodeTV,
            CountryCodeUG,
            CountryCodeUA,
            CountryCodeAE,
            CountryCodeGB,
            CountryCodeUS,
            CountryCodeUM,
            CountryCodeUY,
            CountryCodeUZ,
            CountryCodeVU,
            CountryCodeVE,
            CountryCodeVN,
            CountryCodeVG,
            CountryCodeVI,
            CountryCodeWF,
            CountryCodeEH,
            CountryCodeYE,
            CountryCodeZM,
            CountryCodeZW
        };

        void writeCountryCodeEnumJSON(CountryCode enumVal, PFStringJsonWriter& writer);
        CountryCode readCountryCodeFromValue(const rapidjson::Value& obj);

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
            std::string BuildVersion;
            std::string GameMode;
            Boxed<Region> pfRegion;
            std::string StatisticName;
            CollectionFilter* TagFilter;

            CurrentGamesRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameMode(),
                pfRegion(),
                StatisticName(),
                TagFilter(NULL)
            {}

            CurrentGamesRequest(const CurrentGamesRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter ? new CollectionFilter(*src.TagFilter) : NULL)
            {}

            CurrentGamesRequest(const rapidjson::Value& obj) : CurrentGamesRequest()
            {
                readFromValue(obj);
            }

            ~CurrentGamesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum GameInstanceState
        {
            GameInstanceStateOpen,
            GameInstanceStateClosed
        };

        void writeGameInstanceStateEnumJSON(GameInstanceState enumVal, PFStringJsonWriter& writer);
        GameInstanceState readGameInstanceStateFromValue(const rapidjson::Value& obj);

        struct GameInfo : public PlayFabBaseModel
        {
            std::string BuildVersion;
            std::string GameMode;
            std::string GameServerData;
            Boxed<GameInstanceState> GameServerStateEnum;
            OptionalTime LastHeartbeat;
            std::string LobbyID;
            OptionalInt32 MaxPlayers;
            std::list<std::string> PlayerUserIds;
            Boxed<Region> pfRegion;
            Uint32 RunTime;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            OptionalInt32 ServerPort;
            std::string ServerPublicDNSName;
            std::string StatisticName;
            std::map<std::string, std::string> Tags;

            GameInfo() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameMode(),
                GameServerData(),
                GameServerStateEnum(),
                LastHeartbeat(),
                LobbyID(),
                MaxPlayers(),
                PlayerUserIds(),
                pfRegion(),
                RunTime(0),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(),
                ServerPublicDNSName(),
                StatisticName(),
                Tags()
            {}

            GameInfo(const GameInfo& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                GameServerData(src.GameServerData),
                GameServerStateEnum(src.GameServerStateEnum),
                LastHeartbeat(src.LastHeartbeat),
                LobbyID(src.LobbyID),
                MaxPlayers(src.MaxPlayers),
                PlayerUserIds(src.PlayerUserIds),
                pfRegion(src.pfRegion),
                RunTime(src.RunTime),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                StatisticName(src.StatisticName),
                Tags(src.Tags)
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
            Int32 GameCount;
            std::list<GameInfo> Games;
            Int32 PlayerCount;

            CurrentGamesResult() :
                PlayFabBaseModel(),
                GameCount(0),
                Games(),
                PlayerCount(0)
            {}

            CurrentGamesResult(const CurrentGamesResult& src) :
                PlayFabBaseModel(),
                GameCount(src.GameCount),
                Games(src.Games),
                PlayerCount(src.PlayerCount)
            {}

            CurrentGamesResult(const rapidjson::Value& obj) : CurrentGamesResult()
            {
                readFromValue(obj);
            }

            ~CurrentGamesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeviceInfoRequest : public PlayFabBaseModel
        {
            std::map<std::string, MultitypeVar> Info;

            DeviceInfoRequest() :
                PlayFabBaseModel(),
                Info()
            {}

            DeviceInfoRequest(const DeviceInfoRequest& src) :
                PlayFabBaseModel(),
                Info(src.Info)
            {}

            DeviceInfoRequest(const rapidjson::Value& obj) : DeviceInfoRequest()
            {
                readFromValue(obj);
            }

            ~DeviceInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EmptyResponse : public PlayFabBaseModel
        {

            EmptyResponse() :
                PlayFabBaseModel()
            {}

            EmptyResponse(const EmptyResponse& src) :
                PlayFabBaseModel()
            {}

            EmptyResponse(const rapidjson::Value& obj) : EmptyResponse()
            {
                readFromValue(obj);
            }

            ~EmptyResponse();

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

        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            std::string Type;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type)
            {}

            EntityKey(const rapidjson::Value& obj) : EntityKey()
            {
                readFromValue(obj);
            }

            ~EntityKey();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EntityTokenResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::string EntityToken;
            OptionalTime TokenExpiration;

            EntityTokenResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                EntityToken(),
                TokenExpiration()
            {}

            EntityTokenResponse(const EntityTokenResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            EntityTokenResponse(const rapidjson::Value& obj) : EntityTokenResponse()
            {
                readFromValue(obj);
            }

            ~EntityTokenResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ExecuteCloudScriptRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string FunctionName;
            MultitypeVar FunctionParameter;
            OptionalBool GeneratePlayStreamEvent;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            OptionalInt32 SpecificRevision;

            ExecuteCloudScriptRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteCloudScriptRequest(const ExecuteCloudScriptRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ExecuteCloudScriptRequest(const rapidjson::Value& obj) : ExecuteCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
            std::string Error;
            std::string Message;
            std::string StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ScriptExecutionError(const rapidjson::Value& obj) : ScriptExecutionError()
            {
                readFromValue(obj);
            }

            ~ScriptExecutionError();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LogStatement : public PlayFabBaseModel
        {
            MultitypeVar Data;
            std::string Level;
            std::string Message;

            LogStatement() :
                PlayFabBaseModel(),
                Data(),
                Level(),
                Message()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Level(src.Level),
                Message(src.Message)
            {}

            LogStatement(const rapidjson::Value& obj) : LogStatement()
            {
                readFromValue(obj);
            }

            ~LogStatement();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ExecuteCloudScriptResult : public PlayFabBaseModel
        {
            Int32 APIRequestsIssued;
            ScriptExecutionError* Error;
            double ExecutionTimeSeconds;
            std::string FunctionName;
            MultitypeVar FunctionResult;
            OptionalBool FunctionResultTooLarge;
            Int32 HttpRequestsIssued;
            std::list<LogStatement> Logs;
            OptionalBool LogsTooLarge;
            Uint32 MemoryConsumedBytes;
            double ProcessorTimeSeconds;
            Int32 Revision;

            ExecuteCloudScriptResult() :
                PlayFabBaseModel(),
                APIRequestsIssued(0),
                Error(NULL),
                ExecutionTimeSeconds(0),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge(),
                HttpRequestsIssued(0),
                Logs(),
                LogsTooLarge(),
                MemoryConsumedBytes(0),
                ProcessorTimeSeconds(0),
                Revision(0)
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabBaseModel(),
                APIRequestsIssued(src.APIRequestsIssued),
                Error(src.Error ? new ScriptExecutionError(*src.Error) : NULL),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                Revision(src.Revision)
            {}

            ExecuteCloudScriptResult(const rapidjson::Value& obj) : ExecuteCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FacebookInstantGamesPlayFabIdPair : public PlayFabBaseModel
        {
            std::string FacebookInstantGamesId;
            std::string PlayFabId;

            FacebookInstantGamesPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookInstantGamesId(),
                PlayFabId()
            {}

            FacebookInstantGamesPlayFabIdPair(const FacebookInstantGamesPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookInstantGamesId(src.FacebookInstantGamesId),
                PlayFabId(src.PlayFabId)
            {}

            FacebookInstantGamesPlayFabIdPair(const rapidjson::Value& obj) : FacebookInstantGamesPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~FacebookInstantGamesPlayFabIdPair();

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

        enum LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello,
            LoginIdentityProviderGameServer,
            LoginIdentityProviderCustomServer,
            LoginIdentityProviderNintendoSwitch,
            LoginIdentityProviderFacebookInstantGames,
            LoginIdentityProviderOpenIdConnect,
            LoginIdentityProviderApple,
            LoginIdentityProviderNintendoSwitchAccount
        };

        void writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer);
        LoginIdentityProvider readLoginIdentityProviderFromValue(const rapidjson::Value& obj);

        struct LinkedPlatformAccountModel : public PlayFabBaseModel
        {
            std::string Email;
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;

            LinkedPlatformAccountModel() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            LinkedPlatformAccountModel(const LinkedPlatformAccountModel& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            LinkedPlatformAccountModel(const rapidjson::Value& obj) : LinkedPlatformAccountModel()
            {
                readFromValue(obj);
            }

            ~LinkedPlatformAccountModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LocationModel : public PlayFabBaseModel
        {
            std::string City;
            Boxed<ContinentCode> pfContinentCode;
            Boxed<CountryCode> pfCountryCode;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            LocationModel() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            LocationModel(const LocationModel& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            LocationModel(const rapidjson::Value& obj) : LocationModel()
            {
                readFromValue(obj);
            }

            ~LocationModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum SubscriptionProviderStatus
        {
            SubscriptionProviderStatusNoError,
            SubscriptionProviderStatusCancelled,
            SubscriptionProviderStatusUnknownError,
            SubscriptionProviderStatusBillingError,
            SubscriptionProviderStatusProductUnavailable,
            SubscriptionProviderStatusCustomerDidNotAcceptPriceChange,
            SubscriptionProviderStatusFreeTrial,
            SubscriptionProviderStatusPaymentPending
        };

        void writeSubscriptionProviderStatusEnumJSON(SubscriptionProviderStatus enumVal, PFStringJsonWriter& writer);
        SubscriptionProviderStatus readSubscriptionProviderStatusFromValue(const rapidjson::Value& obj);

        struct SubscriptionModel : public PlayFabBaseModel
        {
            time_t Expiration;
            time_t InitialSubscriptionTime;
            bool IsActive;
            Boxed<SubscriptionProviderStatus> Status;
            std::string SubscriptionId;
            std::string SubscriptionItemId;
            std::string SubscriptionProvider;

            SubscriptionModel() :
                PlayFabBaseModel(),
                Expiration(0),
                InitialSubscriptionTime(0),
                IsActive(false),
                Status(),
                SubscriptionId(),
                SubscriptionItemId(),
                SubscriptionProvider()
            {}

            SubscriptionModel(const SubscriptionModel& src) :
                PlayFabBaseModel(),
                Expiration(src.Expiration),
                InitialSubscriptionTime(src.InitialSubscriptionTime),
                IsActive(src.IsActive),
                Status(src.Status),
                SubscriptionId(src.SubscriptionId),
                SubscriptionItemId(src.SubscriptionItemId),
                SubscriptionProvider(src.SubscriptionProvider)
            {}

            SubscriptionModel(const rapidjson::Value& obj) : SubscriptionModel()
            {
                readFromValue(obj);
            }

            ~SubscriptionModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct MembershipModel : public PlayFabBaseModel
        {
            bool IsActive;
            time_t MembershipExpiration;
            std::string MembershipId;
            OptionalTime OverrideExpiration;
            std::list<SubscriptionModel> Subscriptions;

            MembershipModel() :
                PlayFabBaseModel(),
                IsActive(false),
                MembershipExpiration(0),
                MembershipId(),
                OverrideExpiration(),
                Subscriptions()
            {}

            MembershipModel(const MembershipModel& src) :
                PlayFabBaseModel(),
                IsActive(src.IsActive),
                MembershipExpiration(src.MembershipExpiration),
                MembershipId(src.MembershipId),
                OverrideExpiration(src.OverrideExpiration),
                Subscriptions(src.Subscriptions)
            {}

            MembershipModel(const rapidjson::Value& obj) : MembershipModel()
            {
                readFromValue(obj);
            }

            ~MembershipModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        void writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer);
        PushNotificationPlatform readPushNotificationPlatformFromValue(const rapidjson::Value& obj);

        struct PushNotificationRegistrationModel : public PlayFabBaseModel
        {
            std::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistrationModel() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistrationModel(const PushNotificationRegistrationModel& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            PushNotificationRegistrationModel(const rapidjson::Value& obj) : PushNotificationRegistrationModel()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistrationModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StatisticModel : public PlayFabBaseModel
        {
            std::string Name;
            Int32 Value;
            Int32 Version;

            StatisticModel() :
                PlayFabBaseModel(),
                Name(),
                Value(0),
                Version(0)
            {}

            StatisticModel(const StatisticModel& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticModel(const rapidjson::Value& obj) : StatisticModel()
            {
                readFromValue(obj);
            }

            ~StatisticModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct TagModel : public PlayFabBaseModel
        {
            std::string TagValue;

            TagModel() :
                PlayFabBaseModel(),
                TagValue()
            {}

            TagModel(const TagModel& src) :
                PlayFabBaseModel(),
                TagValue(src.TagValue)
            {}

            TagModel(const rapidjson::Value& obj) : TagModel()
            {
                readFromValue(obj);
            }

            ~TagModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValueToDateModel : public PlayFabBaseModel
        {
            std::string Currency;
            Uint32 TotalValue;
            std::string TotalValueAsDecimal;

            ValueToDateModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(0),
                TotalValueAsDecimal()
            {}

            ValueToDateModel(const ValueToDateModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue),
                TotalValueAsDecimal(src.TotalValueAsDecimal)
            {}

            ValueToDateModel(const rapidjson::Value& obj) : ValueToDateModel()
            {
                readFromValue(obj);
            }

            ~ValueToDateModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerProfileModel : public PlayFabBaseModel
        {
            std::list<AdCampaignAttributionModel> AdCampaignAttributions;
            std::string AvatarUrl;
            OptionalTime BannedUntil;
            std::list<ContactEmailInfoModel> ContactEmailAddresses;
            OptionalTime Created;
            std::string DisplayName;
            std::list<std::string> ExperimentVariants;
            OptionalTime LastLogin;
            std::list<LinkedPlatformAccountModel> LinkedAccounts;
            std::list<LocationModel> Locations;
            std::list<MembershipModel> Memberships;
            Boxed<LoginIdentityProvider> Origination;
            std::string PlayerId;
            std::string PublisherId;
            std::list<PushNotificationRegistrationModel> PushNotificationRegistrations;
            std::list<StatisticModel> Statistics;
            std::list<TagModel> Tags;
            std::string TitleId;
            OptionalUint32 TotalValueToDateInUSD;
            std::list<ValueToDateModel> ValuesToDate;

            PlayerProfileModel() :
                PlayFabBaseModel(),
                AdCampaignAttributions(),
                AvatarUrl(),
                BannedUntil(),
                ContactEmailAddresses(),
                Created(),
                DisplayName(),
                ExperimentVariants(),
                LastLogin(),
                LinkedAccounts(),
                Locations(),
                Memberships(),
                Origination(),
                PlayerId(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate()
            {}

            PlayerProfileModel(const PlayerProfileModel& src) :
                PlayFabBaseModel(),
                AdCampaignAttributions(src.AdCampaignAttributions),
                AvatarUrl(src.AvatarUrl),
                BannedUntil(src.BannedUntil),
                ContactEmailAddresses(src.ContactEmailAddresses),
                Created(src.Created),
                DisplayName(src.DisplayName),
                ExperimentVariants(src.ExperimentVariants),
                LastLogin(src.LastLogin),
                LinkedAccounts(src.LinkedAccounts),
                Locations(src.Locations),
                Memberships(src.Memberships),
                Origination(src.Origination),
                PlayerId(src.PlayerId),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate)
            {}

            PlayerProfileModel(const rapidjson::Value& obj) : PlayerProfileModel()
            {
                readFromValue(obj);
            }

            ~PlayerProfileModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserPsnInfo : public PlayFabBaseModel
        {
            std::string PsnAccountId;
            std::string PsnOnlineId;

            UserPsnInfo() :
                PlayFabBaseModel(),
                PsnAccountId(),
                PsnOnlineId()
            {}

            UserPsnInfo(const UserPsnInfo& src) :
                PlayFabBaseModel(),
                PsnAccountId(src.PsnAccountId),
                PsnOnlineId(src.PsnOnlineId)
            {}

            UserPsnInfo(const rapidjson::Value& obj) : UserPsnInfo()
            {
                readFromValue(obj);
            }

            ~UserPsnInfo();

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
            Boxed<TitleActivationStatus> SteamActivationStatus;
            std::string SteamCountry;
            Boxed<Currency> SteamCurrency;
            std::string SteamId;
            std::string SteamName;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamActivationStatus(),
                SteamCountry(),
                SteamCurrency(),
                SteamId(),
                SteamName()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamActivationStatus(src.SteamActivationStatus),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamId(src.SteamId),
                SteamName(src.SteamName)
            {}

            UserSteamInfo(const rapidjson::Value& obj) : UserSteamInfo()
            {
                readFromValue(obj);
            }

            ~UserSteamInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserXboxInfo : public PlayFabBaseModel
        {
            std::string XboxUserId;

            UserXboxInfo() :
                PlayFabBaseModel(),
                XboxUserId()
            {}

            UserXboxInfo(const UserXboxInfo& src) :
                PlayFabBaseModel(),
                XboxUserId(src.XboxUserId)
            {}

            UserXboxInfo(const rapidjson::Value& obj) : UserXboxInfo()
            {
                readFromValue(obj);
            }

            ~UserXboxInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FriendInfo : public PlayFabBaseModel
        {
            UserFacebookInfo* FacebookInfo;
            std::string FriendPlayFabId;
            UserGameCenterInfo* GameCenterInfo;
            PlayerProfileModel* Profile;
            UserPsnInfo* PSNInfo;
            UserSteamInfo* SteamInfo;
            std::list<std::string> Tags;
            std::string TitleDisplayName;
            std::string Username;
            UserXboxInfo* XboxInfo;

            FriendInfo() :
                PlayFabBaseModel(),
                FacebookInfo(NULL),
                FriendPlayFabId(),
                GameCenterInfo(NULL),
                Profile(NULL),
                PSNInfo(NULL),
                SteamInfo(NULL),
                Tags(),
                TitleDisplayName(),
                Username(),
                XboxInfo(NULL)
            {}

            FriendInfo(const FriendInfo& src) :
                PlayFabBaseModel(),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : NULL),
                FriendPlayFabId(src.FriendPlayFabId),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : NULL),
                PSNInfo(src.PSNInfo ? new UserPsnInfo(*src.PSNInfo) : NULL),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : NULL),
                Tags(src.Tags),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : NULL)
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
            bool Available;
            std::string Name;
            std::string PingUrl;
            Boxed<Region> pfRegion;

            RegionInfo() :
                PlayFabBaseModel(),
                Available(false),
                Name(),
                PingUrl(),
                pfRegion()
            {}

            RegionInfo(const RegionInfo& src) :
                PlayFabBaseModel(),
                Available(src.Available),
                Name(src.Name),
                PingUrl(src.PingUrl),
                pfRegion(src.pfRegion)
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

        struct GenericPlayFabIdPair : public PlayFabBaseModel
        {
            GenericServiceId* GenericId;
            std::string PlayFabId;

            GenericPlayFabIdPair() :
                PlayFabBaseModel(),
                GenericId(NULL),
                PlayFabId()
            {}

            GenericPlayFabIdPair(const GenericPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId ? new GenericServiceId(*src.GenericId) : NULL),
                PlayFabId(src.PlayFabId)
            {}

            GenericPlayFabIdPair(const rapidjson::Value& obj) : GenericPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GenericPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAccountInfoRequest : public PlayFabBaseModel
        {
            std::string Email;
            std::string PlayFabId;
            std::string TitleDisplayName;
            std::string Username;

            GetAccountInfoRequest() :
                PlayFabBaseModel(),
                Email(),
                PlayFabId(),
                TitleDisplayName(),
                Username()
            {}

            GetAccountInfoRequest(const GetAccountInfoRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                PlayFabId(src.PlayFabId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            GetAccountInfoRequest(const rapidjson::Value& obj) : GetAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetAccountInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserAndroidDeviceInfo : public PlayFabBaseModel
        {
            std::string AndroidDeviceId;

            UserAndroidDeviceInfo() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UserAndroidDeviceInfo(const UserAndroidDeviceInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UserAndroidDeviceInfo(const rapidjson::Value& obj) : UserAndroidDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserAndroidDeviceInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserAppleIdInfo : public PlayFabBaseModel
        {
            std::string AppleSubjectId;

            UserAppleIdInfo() :
                PlayFabBaseModel(),
                AppleSubjectId()
            {}

            UserAppleIdInfo(const UserAppleIdInfo& src) :
                PlayFabBaseModel(),
                AppleSubjectId(src.AppleSubjectId)
            {}

            UserAppleIdInfo(const rapidjson::Value& obj) : UserAppleIdInfo()
            {
                readFromValue(obj);
            }

            ~UserAppleIdInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserCustomIdInfo : public PlayFabBaseModel
        {
            std::string CustomId;

            UserCustomIdInfo() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UserCustomIdInfo(const UserCustomIdInfo& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UserCustomIdInfo(const rapidjson::Value& obj) : UserCustomIdInfo()
            {
                readFromValue(obj);
            }

            ~UserCustomIdInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserFacebookInstantGamesIdInfo : public PlayFabBaseModel
        {
            std::string FacebookInstantGamesId;

            UserFacebookInstantGamesIdInfo() :
                PlayFabBaseModel(),
                FacebookInstantGamesId()
            {}

            UserFacebookInstantGamesIdInfo(const UserFacebookInstantGamesIdInfo& src) :
                PlayFabBaseModel(),
                FacebookInstantGamesId(src.FacebookInstantGamesId)
            {}

            UserFacebookInstantGamesIdInfo(const rapidjson::Value& obj) : UserFacebookInstantGamesIdInfo()
            {
                readFromValue(obj);
            }

            ~UserFacebookInstantGamesIdInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserGoogleInfo : public PlayFabBaseModel
        {
            std::string GoogleEmail;
            std::string GoogleGender;
            std::string GoogleId;
            std::string GoogleLocale;
            std::string GoogleName;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleEmail(),
                GoogleGender(),
                GoogleId(),
                GoogleLocale(),
                GoogleName()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleEmail(src.GoogleEmail),
                GoogleGender(src.GoogleGender),
                GoogleId(src.GoogleId),
                GoogleLocale(src.GoogleLocale),
                GoogleName(src.GoogleName)
            {}

            UserGoogleInfo(const rapidjson::Value& obj) : UserGoogleInfo()
            {
                readFromValue(obj);
            }

            ~UserGoogleInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
            std::string IosDeviceId;

            UserIosDeviceInfo() :
                PlayFabBaseModel(),
                IosDeviceId()
            {}

            UserIosDeviceInfo(const UserIosDeviceInfo& src) :
                PlayFabBaseModel(),
                IosDeviceId(src.IosDeviceId)
            {}

            UserIosDeviceInfo(const rapidjson::Value& obj) : UserIosDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserIosDeviceInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserKongregateInfo : public PlayFabBaseModel
        {
            std::string KongregateId;
            std::string KongregateName;

            UserKongregateInfo() :
                PlayFabBaseModel(),
                KongregateId(),
                KongregateName()
            {}

            UserKongregateInfo(const UserKongregateInfo& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                KongregateName(src.KongregateName)
            {}

            UserKongregateInfo(const rapidjson::Value& obj) : UserKongregateInfo()
            {
                readFromValue(obj);
            }

            ~UserKongregateInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserNintendoSwitchAccountIdInfo : public PlayFabBaseModel
        {
            std::string NintendoSwitchAccountSubjectId;

            UserNintendoSwitchAccountIdInfo() :
                PlayFabBaseModel(),
                NintendoSwitchAccountSubjectId()
            {}

            UserNintendoSwitchAccountIdInfo(const UserNintendoSwitchAccountIdInfo& src) :
                PlayFabBaseModel(),
                NintendoSwitchAccountSubjectId(src.NintendoSwitchAccountSubjectId)
            {}

            UserNintendoSwitchAccountIdInfo(const rapidjson::Value& obj) : UserNintendoSwitchAccountIdInfo()
            {
                readFromValue(obj);
            }

            ~UserNintendoSwitchAccountIdInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserNintendoSwitchDeviceIdInfo : public PlayFabBaseModel
        {
            std::string NintendoSwitchDeviceId;

            UserNintendoSwitchDeviceIdInfo() :
                PlayFabBaseModel(),
                NintendoSwitchDeviceId()
            {}

            UserNintendoSwitchDeviceIdInfo(const UserNintendoSwitchDeviceIdInfo& src) :
                PlayFabBaseModel(),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId)
            {}

            UserNintendoSwitchDeviceIdInfo(const rapidjson::Value& obj) : UserNintendoSwitchDeviceIdInfo()
            {
                readFromValue(obj);
            }

            ~UserNintendoSwitchDeviceIdInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserOpenIdInfo : public PlayFabBaseModel
        {
            std::string ConnectionId;
            std::string Issuer;
            std::string Subject;

            UserOpenIdInfo() :
                PlayFabBaseModel(),
                ConnectionId(),
                Issuer(),
                Subject()
            {}

            UserOpenIdInfo(const UserOpenIdInfo& src) :
                PlayFabBaseModel(),
                ConnectionId(src.ConnectionId),
                Issuer(src.Issuer),
                Subject(src.Subject)
            {}

            UserOpenIdInfo(const rapidjson::Value& obj) : UserOpenIdInfo()
            {
                readFromValue(obj);
            }

            ~UserOpenIdInfo();

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
            UserOriginationXboxLive,
            UserOriginationParse,
            UserOriginationTwitch,
            UserOriginationWindowsHello,
            UserOriginationServerCustomId,
            UserOriginationNintendoSwitchDeviceId,
            UserOriginationFacebookInstantGamesId,
            UserOriginationOpenIdConnect,
            UserOriginationApple,
            UserOriginationNintendoSwitchAccount
        };

        void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer);
        UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj);

        struct UserTitleInfo : public PlayFabBaseModel
        {
            std::string AvatarUrl;
            time_t Created;
            std::string DisplayName;
            OptionalTime FirstLogin;
            OptionalBool isBanned;
            OptionalTime LastLogin;
            Boxed<UserOrigination> Origination;
            EntityKey* TitlePlayerAccount;

            UserTitleInfo() :
                PlayFabBaseModel(),
                AvatarUrl(),
                Created(0),
                DisplayName(),
                FirstLogin(),
                isBanned(),
                LastLogin(),
                Origination(),
                TitlePlayerAccount(NULL)
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                AvatarUrl(src.AvatarUrl),
                Created(src.Created),
                DisplayName(src.DisplayName),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned),
                LastLogin(src.LastLogin),
                Origination(src.Origination),
                TitlePlayerAccount(src.TitlePlayerAccount ? new EntityKey(*src.TitlePlayerAccount) : NULL)
            {}

            UserTitleInfo(const rapidjson::Value& obj) : UserTitleInfo()
            {
                readFromValue(obj);
            }

            ~UserTitleInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserTwitchInfo : public PlayFabBaseModel
        {
            std::string TwitchId;
            std::string TwitchUserName;

            UserTwitchInfo() :
                PlayFabBaseModel(),
                TwitchId(),
                TwitchUserName()
            {}

            UserTwitchInfo(const UserTwitchInfo& src) :
                PlayFabBaseModel(),
                TwitchId(src.TwitchId),
                TwitchUserName(src.TwitchUserName)
            {}

            UserTwitchInfo(const rapidjson::Value& obj) : UserTwitchInfo()
            {
                readFromValue(obj);
            }

            ~UserTwitchInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserWindowsHelloInfo : public PlayFabBaseModel
        {
            std::string WindowsHelloDeviceName;
            std::string WindowsHelloPublicKeyHash;

            UserWindowsHelloInfo() :
                PlayFabBaseModel(),
                WindowsHelloDeviceName(),
                WindowsHelloPublicKeyHash()
            {}

            UserWindowsHelloInfo(const UserWindowsHelloInfo& src) :
                PlayFabBaseModel(),
                WindowsHelloDeviceName(src.WindowsHelloDeviceName),
                WindowsHelloPublicKeyHash(src.WindowsHelloPublicKeyHash)
            {}

            UserWindowsHelloInfo(const rapidjson::Value& obj) : UserWindowsHelloInfo()
            {
                readFromValue(obj);
            }

            ~UserWindowsHelloInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            UserAndroidDeviceInfo* AndroidDeviceInfo;
            UserAppleIdInfo* AppleAccountInfo;
            time_t Created;
            UserCustomIdInfo* CustomIdInfo;
            UserFacebookInfo* FacebookInfo;
            UserFacebookInstantGamesIdInfo* FacebookInstantGamesIdInfo;
            UserGameCenterInfo* GameCenterInfo;
            UserGoogleInfo* GoogleInfo;
            UserIosDeviceInfo* IosDeviceInfo;
            UserKongregateInfo* KongregateInfo;
            UserNintendoSwitchAccountIdInfo* NintendoSwitchAccountInfo;
            UserNintendoSwitchDeviceIdInfo* NintendoSwitchDeviceIdInfo;
            std::list<UserOpenIdInfo> OpenIdInfo;
            std::string PlayFabId;
            UserPrivateAccountInfo* PrivateInfo;
            UserPsnInfo* PsnInfo;
            UserSteamInfo* SteamInfo;
            UserTitleInfo* TitleInfo;
            UserTwitchInfo* TwitchInfo;
            std::string Username;
            UserWindowsHelloInfo* WindowsHelloInfo;
            UserXboxInfo* XboxInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                AndroidDeviceInfo(NULL),
                AppleAccountInfo(NULL),
                Created(0),
                CustomIdInfo(NULL),
                FacebookInfo(NULL),
                FacebookInstantGamesIdInfo(NULL),
                GameCenterInfo(NULL),
                GoogleInfo(NULL),
                IosDeviceInfo(NULL),
                KongregateInfo(NULL),
                NintendoSwitchAccountInfo(NULL),
                NintendoSwitchDeviceIdInfo(NULL),
                OpenIdInfo(),
                PlayFabId(),
                PrivateInfo(NULL),
                PsnInfo(NULL),
                SteamInfo(NULL),
                TitleInfo(NULL),
                TwitchInfo(NULL),
                Username(),
                WindowsHelloInfo(NULL),
                XboxInfo(NULL)
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceInfo(src.AndroidDeviceInfo ? new UserAndroidDeviceInfo(*src.AndroidDeviceInfo) : NULL),
                AppleAccountInfo(src.AppleAccountInfo ? new UserAppleIdInfo(*src.AppleAccountInfo) : NULL),
                Created(src.Created),
                CustomIdInfo(src.CustomIdInfo ? new UserCustomIdInfo(*src.CustomIdInfo) : NULL),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : NULL),
                FacebookInstantGamesIdInfo(src.FacebookInstantGamesIdInfo ? new UserFacebookInstantGamesIdInfo(*src.FacebookInstantGamesIdInfo) : NULL),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL),
                GoogleInfo(src.GoogleInfo ? new UserGoogleInfo(*src.GoogleInfo) : NULL),
                IosDeviceInfo(src.IosDeviceInfo ? new UserIosDeviceInfo(*src.IosDeviceInfo) : NULL),
                KongregateInfo(src.KongregateInfo ? new UserKongregateInfo(*src.KongregateInfo) : NULL),
                NintendoSwitchAccountInfo(src.NintendoSwitchAccountInfo ? new UserNintendoSwitchAccountIdInfo(*src.NintendoSwitchAccountInfo) : NULL),
                NintendoSwitchDeviceIdInfo(src.NintendoSwitchDeviceIdInfo ? new UserNintendoSwitchDeviceIdInfo(*src.NintendoSwitchDeviceIdInfo) : NULL),
                OpenIdInfo(src.OpenIdInfo),
                PlayFabId(src.PlayFabId),
                PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : NULL),
                PsnInfo(src.PsnInfo ? new UserPsnInfo(*src.PsnInfo) : NULL),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : NULL),
                TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : NULL),
                TwitchInfo(src.TwitchInfo ? new UserTwitchInfo(*src.TwitchInfo) : NULL),
                Username(src.Username),
                WindowsHelloInfo(src.WindowsHelloInfo ? new UserWindowsHelloInfo(*src.WindowsHelloInfo) : NULL),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : NULL)
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

        struct NameIdentifier : public PlayFabBaseModel
        {
            std::string Id;
            std::string Name;

            NameIdentifier() :
                PlayFabBaseModel(),
                Id(),
                Name()
            {}

            NameIdentifier(const NameIdentifier& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name)
            {}

            NameIdentifier(const rapidjson::Value& obj) : NameIdentifier()
            {
                readFromValue(obj);
            }

            ~NameIdentifier();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAdPlacementsRequest : public PlayFabBaseModel
        {
            std::string AppId;
            NameIdentifier* Identifier;

            GetAdPlacementsRequest() :
                PlayFabBaseModel(),
                AppId(),
                Identifier(NULL)
            {}

            GetAdPlacementsRequest(const GetAdPlacementsRequest& src) :
                PlayFabBaseModel(),
                AppId(src.AppId),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : NULL)
            {}

            GetAdPlacementsRequest(const rapidjson::Value& obj) : GetAdPlacementsRequest()
            {
                readFromValue(obj);
            }

            ~GetAdPlacementsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAdPlacementsResult : public PlayFabBaseModel
        {
            std::list<AdPlacementDetails> AdPlacements;

            GetAdPlacementsResult() :
                PlayFabBaseModel(),
                AdPlacements()
            {}

            GetAdPlacementsResult(const GetAdPlacementsResult& src) :
                PlayFabBaseModel(),
                AdPlacements(src.AdPlacements)
            {}

            GetAdPlacementsResult(const rapidjson::Value& obj) : GetAdPlacementsResult()
            {
                readFromValue(obj);
            }

            ~GetAdPlacementsResult();

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
            std::string CharacterId;
            OptionalUint32 IfChangedFromDataVersion;
            std::list<std::string> Keys;
            std::string PlayFabId;

            GetCharacterDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetCharacterDataRequest(const GetCharacterDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
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
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;
            std::string Value;

            UserDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(0),
                Permission(),
                Value()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission),
                Value(src.Value)
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
            std::string CatalogVersion;
            std::string CharacterId;
            std::map<std::string, std::string> CustomTags;

            GetCharacterInventoryRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                CustomTags()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CustomTags(src.CustomTags)
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
            Int32 RechargeMax;
            time_t RechargeTime;
            Int32 SecondsToRecharge;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                RechargeMax(0),
                RechargeTime(0),
                SecondsToRecharge(0)
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                RechargeMax(src.RechargeMax),
                RechargeTime(src.RechargeTime),
                SecondsToRecharge(src.SecondsToRecharge)
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
            std::string CharacterId;
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabBaseModel(),
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
            OptionalInt32 MaxResultsCount;
            Int32 StartPosition;
            std::string StatisticName;

            GetCharacterLeaderboardRequest() :
                PlayFabBaseModel(),
                CharacterType(),
                MaxResultsCount(),
                StartPosition(0),
                StatisticName()
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabBaseModel(),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName)
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

        struct GetCharacterStatisticsRequest : public PlayFabBaseModel
        {
            std::string CharacterId;

            GetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId()
            {}

            GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId)
            {}

            GetCharacterStatisticsRequest(const rapidjson::Value& obj) : GetCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCharacterStatisticsResult : public PlayFabBaseModel
        {
            std::map<std::string, Int32> CharacterStatistics;

            GetCharacterStatisticsResult() :
                PlayFabBaseModel(),
                CharacterStatistics()
            {}

            GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
                PlayFabBaseModel(),
                CharacterStatistics(src.CharacterStatistics)
            {}

            GetCharacterStatisticsResult(const rapidjson::Value& obj) : GetCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContentDownloadUrlRequest : public PlayFabBaseModel
        {
            std::string HttpMethod;
            std::string Key;
            OptionalBool ThruCDN;

            GetContentDownloadUrlRequest() :
                PlayFabBaseModel(),
                HttpMethod(),
                Key(),
                ThruCDN()
            {}

            GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
                PlayFabBaseModel(),
                HttpMethod(src.HttpMethod),
                Key(src.Key),
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

        struct PlayerProfileViewConstraints : public PlayFabBaseModel
        {
            bool ShowAvatarUrl;
            bool ShowBannedUntil;
            bool ShowCampaignAttributions;
            bool ShowContactEmailAddresses;
            bool ShowCreated;
            bool ShowDisplayName;
            bool ShowExperimentVariants;
            bool ShowLastLogin;
            bool ShowLinkedAccounts;
            bool ShowLocations;
            bool ShowMemberships;
            bool ShowOrigination;
            bool ShowPushNotificationRegistrations;
            bool ShowStatistics;
            bool ShowTags;
            bool ShowTotalValueToDateInUsd;
            bool ShowValuesToDate;

            PlayerProfileViewConstraints() :
                PlayFabBaseModel(),
                ShowAvatarUrl(false),
                ShowBannedUntil(false),
                ShowCampaignAttributions(false),
                ShowContactEmailAddresses(false),
                ShowCreated(false),
                ShowDisplayName(false),
                ShowExperimentVariants(false),
                ShowLastLogin(false),
                ShowLinkedAccounts(false),
                ShowLocations(false),
                ShowMemberships(false),
                ShowOrigination(false),
                ShowPushNotificationRegistrations(false),
                ShowStatistics(false),
                ShowTags(false),
                ShowTotalValueToDateInUsd(false),
                ShowValuesToDate(false)
            {}

            PlayerProfileViewConstraints(const PlayerProfileViewConstraints& src) :
                PlayFabBaseModel(),
                ShowAvatarUrl(src.ShowAvatarUrl),
                ShowBannedUntil(src.ShowBannedUntil),
                ShowCampaignAttributions(src.ShowCampaignAttributions),
                ShowContactEmailAddresses(src.ShowContactEmailAddresses),
                ShowCreated(src.ShowCreated),
                ShowDisplayName(src.ShowDisplayName),
                ShowExperimentVariants(src.ShowExperimentVariants),
                ShowLastLogin(src.ShowLastLogin),
                ShowLinkedAccounts(src.ShowLinkedAccounts),
                ShowLocations(src.ShowLocations),
                ShowMemberships(src.ShowMemberships),
                ShowOrigination(src.ShowOrigination),
                ShowPushNotificationRegistrations(src.ShowPushNotificationRegistrations),
                ShowStatistics(src.ShowStatistics),
                ShowTags(src.ShowTags),
                ShowTotalValueToDateInUsd(src.ShowTotalValueToDateInUsd),
                ShowValuesToDate(src.ShowValuesToDate)
            {}

            PlayerProfileViewConstraints(const rapidjson::Value& obj) : PlayerProfileViewConstraints()
            {
                readFromValue(obj);
            }

            ~PlayerProfileViewConstraints();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendLeaderboardAroundPlayerRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            OptionalBool IncludeFacebookFriends;
            OptionalBool IncludeSteamFriends;
            OptionalInt32 MaxResultsCount;
            std::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;
            std::string StatisticName;
            OptionalInt32 Version;
            std::string XboxToken;

            GetFriendLeaderboardAroundPlayerRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(NULL),
                StatisticName(),
                Version(),
                XboxToken()
            {}

            GetFriendLeaderboardAroundPlayerRequest(const GetFriendLeaderboardAroundPlayerRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                StatisticName(src.StatisticName),
                Version(src.Version),
                XboxToken(src.XboxToken)
            {}

            GetFriendLeaderboardAroundPlayerRequest(const rapidjson::Value& obj) : GetFriendLeaderboardAroundPlayerRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardAroundPlayerRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLeaderboardEntry : public PlayFabBaseModel
        {
            std::string DisplayName;
            std::string PlayFabId;
            Int32 Position;
            PlayerProfileModel* Profile;
            Int32 StatValue;

            PlayerLeaderboardEntry() :
                PlayFabBaseModel(),
                DisplayName(),
                PlayFabId(),
                Position(0),
                Profile(NULL),
                StatValue(0)
            {}

            PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : NULL),
                StatValue(src.StatValue)
            {}

            PlayerLeaderboardEntry(const rapidjson::Value& obj) : PlayerLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~PlayerLeaderboardEntry();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendLeaderboardAroundPlayerResult : public PlayFabBaseModel
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            OptionalTime NextReset;
            Int32 Version;

            GetFriendLeaderboardAroundPlayerResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                NextReset(),
                Version(0)
            {}

            GetFriendLeaderboardAroundPlayerResult(const GetFriendLeaderboardAroundPlayerResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            GetFriendLeaderboardAroundPlayerResult(const rapidjson::Value& obj) : GetFriendLeaderboardAroundPlayerResult()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardAroundPlayerResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFriendLeaderboardRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            OptionalBool IncludeFacebookFriends;
            OptionalBool IncludeSteamFriends;
            OptionalInt32 MaxResultsCount;
            PlayerProfileViewConstraints* ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            OptionalInt32 Version;
            std::string XboxToken;

            GetFriendLeaderboardRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                ProfileConstraints(NULL),
                StartPosition(0),
                StatisticName(),
                Version(),
                XboxToken()
            {}

            GetFriendLeaderboardRequest(const GetFriendLeaderboardRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version),
                XboxToken(src.XboxToken)
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
            std::map<std::string, std::string> CustomTags;
            OptionalBool IncludeFacebookFriends;
            OptionalBool IncludeSteamFriends;
            PlayerProfileViewConstraints* ProfileConstraints;
            std::string XboxToken;

            GetFriendsListRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                ProfileConstraints(NULL),
                XboxToken()
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                XboxToken(src.XboxToken)
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
            std::string CharacterId;
            std::string CharacterType;
            OptionalInt32 MaxResultsCount;
            std::string StatisticName;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(),
                StatisticName()
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StatisticName(src.StatisticName)
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

        struct GetLeaderboardAroundPlayerRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            OptionalInt32 MaxResultsCount;
            std::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;
            std::string StatisticName;
            OptionalInt32 Version;

            GetLeaderboardAroundPlayerRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(NULL),
                StatisticName(),
                Version()
            {}

            GetLeaderboardAroundPlayerRequest(const GetLeaderboardAroundPlayerRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            GetLeaderboardAroundPlayerRequest(const rapidjson::Value& obj) : GetLeaderboardAroundPlayerRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundPlayerRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardAroundPlayerResult : public PlayFabBaseModel
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            OptionalTime NextReset;
            Int32 Version;

            GetLeaderboardAroundPlayerResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                NextReset(),
                Version(0)
            {}

            GetLeaderboardAroundPlayerResult(const GetLeaderboardAroundPlayerResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            GetLeaderboardAroundPlayerResult(const rapidjson::Value& obj) : GetLeaderboardAroundPlayerResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundPlayerResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLeaderboardForUsersCharactersRequest : public PlayFabBaseModel
        {
            Int32 MaxResultsCount;
            std::string StatisticName;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabBaseModel(),
                MaxResultsCount(0),
                StatisticName()
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                MaxResultsCount(src.MaxResultsCount),
                StatisticName(src.StatisticName)
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
            std::map<std::string, std::string> CustomTags;
            OptionalInt32 MaxResultsCount;
            PlayerProfileViewConstraints* ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            OptionalInt32 Version;

            GetLeaderboardRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                MaxResultsCount(),
                ProfileConstraints(NULL),
                StartPosition(0),
                StatisticName(),
                Version()
            {}

            GetLeaderboardRequest(const GetLeaderboardRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version)
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
            OptionalTime NextReset;
            Int32 Version;

            GetLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                NextReset(),
                Version(0)
            {}

            GetLeaderboardResult(const GetLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            GetLeaderboardResult(const rapidjson::Value& obj) : GetLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPaymentTokenRequest : public PlayFabBaseModel
        {
            std::string TokenProvider;

            GetPaymentTokenRequest() :
                PlayFabBaseModel(),
                TokenProvider()
            {}

            GetPaymentTokenRequest(const GetPaymentTokenRequest& src) :
                PlayFabBaseModel(),
                TokenProvider(src.TokenProvider)
            {}

            GetPaymentTokenRequest(const rapidjson::Value& obj) : GetPaymentTokenRequest()
            {
                readFromValue(obj);
            }

            ~GetPaymentTokenRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPaymentTokenResult : public PlayFabBaseModel
        {
            std::string OrderId;
            std::string ProviderToken;

            GetPaymentTokenResult() :
                PlayFabBaseModel(),
                OrderId(),
                ProviderToken()
            {}

            GetPaymentTokenResult(const GetPaymentTokenResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                ProviderToken(src.ProviderToken)
            {}

            GetPaymentTokenResult(const rapidjson::Value& obj) : GetPaymentTokenResult()
            {
                readFromValue(obj);
            }

            ~GetPaymentTokenResult();

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

        struct GetPlayerCombinedInfoRequestParams : public PlayFabBaseModel
        {
            bool GetCharacterInventories;
            bool GetCharacterList;
            bool GetPlayerProfile;
            bool GetPlayerStatistics;
            bool GetTitleData;
            bool GetUserAccountInfo;
            bool GetUserData;
            bool GetUserInventory;
            bool GetUserReadOnlyData;
            bool GetUserVirtualCurrency;
            std::list<std::string> PlayerStatisticNames;
            PlayerProfileViewConstraints* ProfileConstraints;
            std::list<std::string> TitleDataKeys;
            std::list<std::string> UserDataKeys;
            std::list<std::string> UserReadOnlyDataKeys;

            GetPlayerCombinedInfoRequestParams() :
                PlayFabBaseModel(),
                GetCharacterInventories(false),
                GetCharacterList(false),
                GetPlayerProfile(false),
                GetPlayerStatistics(false),
                GetTitleData(false),
                GetUserAccountInfo(false),
                GetUserData(false),
                GetUserInventory(false),
                GetUserReadOnlyData(false),
                GetUserVirtualCurrency(false),
                PlayerStatisticNames(),
                ProfileConstraints(NULL),
                TitleDataKeys(),
                UserDataKeys(),
                UserReadOnlyDataKeys()
            {}

            GetPlayerCombinedInfoRequestParams(const GetPlayerCombinedInfoRequestParams& src) :
                PlayFabBaseModel(),
                GetCharacterInventories(src.GetCharacterInventories),
                GetCharacterList(src.GetCharacterList),
                GetPlayerProfile(src.GetPlayerProfile),
                GetPlayerStatistics(src.GetPlayerStatistics),
                GetTitleData(src.GetTitleData),
                GetUserAccountInfo(src.GetUserAccountInfo),
                GetUserData(src.GetUserData),
                GetUserInventory(src.GetUserInventory),
                GetUserReadOnlyData(src.GetUserReadOnlyData),
                GetUserVirtualCurrency(src.GetUserVirtualCurrency),
                PlayerStatisticNames(src.PlayerStatisticNames),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL),
                TitleDataKeys(src.TitleDataKeys),
                UserDataKeys(src.UserDataKeys),
                UserReadOnlyDataKeys(src.UserReadOnlyDataKeys)
            {}

            GetPlayerCombinedInfoRequestParams(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequestParams()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequestParams();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerCombinedInfoRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            GetPlayerCombinedInfoRequestParams InfoRequestParameters;
            std::string PlayFabId;

            GetPlayerCombinedInfoRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                InfoRequestParameters(),
                PlayFabId()
            {}

            GetPlayerCombinedInfoRequest(const GetPlayerCombinedInfoRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                InfoRequestParameters(src.InfoRequestParameters),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerCombinedInfoRequest(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StatisticValue : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 Value;
            Uint32 Version;

            StatisticValue() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version(0)
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

        struct GetPlayerCombinedInfoResultPayload : public PlayFabBaseModel
        {
            UserAccountInfo* AccountInfo;
            std::list<CharacterInventory> CharacterInventories;
            std::list<CharacterResult> CharacterList;
            PlayerProfileModel* PlayerProfile;
            std::list<StatisticValue> PlayerStatistics;
            std::map<std::string, std::string> TitleData;
            std::map<std::string, UserDataRecord> UserData;
            Uint32 UserDataVersion;
            std::list<ItemInstance> UserInventory;
            std::map<std::string, UserDataRecord> UserReadOnlyData;
            Uint32 UserReadOnlyDataVersion;
            std::map<std::string, Int32> UserVirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> UserVirtualCurrencyRechargeTimes;

            GetPlayerCombinedInfoResultPayload() :
                PlayFabBaseModel(),
                AccountInfo(NULL),
                CharacterInventories(),
                CharacterList(),
                PlayerProfile(NULL),
                PlayerStatistics(),
                TitleData(),
                UserData(),
                UserDataVersion(0),
                UserInventory(),
                UserReadOnlyData(),
                UserReadOnlyDataVersion(0),
                UserVirtualCurrency(),
                UserVirtualCurrencyRechargeTimes()
            {}

            GetPlayerCombinedInfoResultPayload(const GetPlayerCombinedInfoResultPayload& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : NULL),
                CharacterInventories(src.CharacterInventories),
                CharacterList(src.CharacterList),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : NULL),
                PlayerStatistics(src.PlayerStatistics),
                TitleData(src.TitleData),
                UserData(src.UserData),
                UserDataVersion(src.UserDataVersion),
                UserInventory(src.UserInventory),
                UserReadOnlyData(src.UserReadOnlyData),
                UserReadOnlyDataVersion(src.UserReadOnlyDataVersion),
                UserVirtualCurrency(src.UserVirtualCurrency),
                UserVirtualCurrencyRechargeTimes(src.UserVirtualCurrencyRechargeTimes)
            {}

            GetPlayerCombinedInfoResultPayload(const rapidjson::Value& obj) : GetPlayerCombinedInfoResultPayload()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResultPayload();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerCombinedInfoResult : public PlayFabBaseModel
        {
            GetPlayerCombinedInfoResultPayload* InfoResultPayload;
            std::string PlayFabId;

            GetPlayerCombinedInfoResult() :
                PlayFabBaseModel(),
                InfoResultPayload(NULL),
                PlayFabId()
            {}

            GetPlayerCombinedInfoResult(const GetPlayerCombinedInfoResult& src) :
                PlayFabBaseModel(),
                InfoResultPayload(src.InfoResultPayload ? new GetPlayerCombinedInfoResultPayload(*src.InfoResultPayload) : NULL),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerCombinedInfoResult(const rapidjson::Value& obj) : GetPlayerCombinedInfoResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerProfileRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetPlayerProfileRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                PlayFabId(),
                ProfileConstraints(NULL)
            {}

            GetPlayerProfileRequest(const GetPlayerProfileRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : NULL)
            {}

            GetPlayerProfileRequest(const rapidjson::Value& obj) : GetPlayerProfileRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerProfileResult : public PlayFabBaseModel
        {
            PlayerProfileModel* PlayerProfile;

            GetPlayerProfileResult() :
                PlayFabBaseModel(),
                PlayerProfile(NULL)
            {}

            GetPlayerProfileResult(const GetPlayerProfileResult& src) :
                PlayFabBaseModel(),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : NULL)
            {}

            GetPlayerProfileResult(const rapidjson::Value& obj) : GetPlayerProfileResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerSegmentsRequest : public PlayFabBaseModel
        {

            GetPlayerSegmentsRequest() :
                PlayFabBaseModel()
            {}

            GetPlayerSegmentsRequest(const GetPlayerSegmentsRequest& src) :
                PlayFabBaseModel()
            {}

            GetPlayerSegmentsRequest(const rapidjson::Value& obj) : GetPlayerSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerSegmentsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetSegmentResult : public PlayFabBaseModel
        {
            std::string ABTestParent;
            std::string Id;
            std::string Name;

            GetSegmentResult() :
                PlayFabBaseModel(),
                ABTestParent(),
                Id(),
                Name()
            {}

            GetSegmentResult(const GetSegmentResult& src) :
                PlayFabBaseModel(),
                ABTestParent(src.ABTestParent),
                Id(src.Id),
                Name(src.Name)
            {}

            GetSegmentResult(const rapidjson::Value& obj) : GetSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetSegmentResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerSegmentsResult : public PlayFabBaseModel
        {
            std::list<GetSegmentResult> Segments;

            GetPlayerSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetPlayerSegmentsResult(const GetPlayerSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetPlayerSegmentsResult(const rapidjson::Value& obj) : GetPlayerSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerSegmentsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StatisticNameVersion : public PlayFabBaseModel
        {
            std::string StatisticName;
            Uint32 Version;

            StatisticNameVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0)
            {}

            StatisticNameVersion(const StatisticNameVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            StatisticNameVersion(const rapidjson::Value& obj) : StatisticNameVersion()
            {
                readFromValue(obj);
            }

            ~StatisticNameVersion();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::list<std::string> StatisticNames;
            std::list<StatisticNameVersion> StatisticNameVersions;

            GetPlayerStatisticsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                StatisticNames(),
                StatisticNameVersions()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                StatisticNames(src.StatisticNames),
                StatisticNameVersions(src.StatisticNameVersions)
            {}

            GetPlayerStatisticsRequest(const rapidjson::Value& obj) : GetPlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsRequest();

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

        struct GetPlayerStatisticVersionsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                StatisticName(src.StatisticName)
            {}

            GetPlayerStatisticVersionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            time_t ActivationTime;
            OptionalTime DeactivationTime;
            OptionalTime ScheduledActivationTime;
            OptionalTime ScheduledDeactivationTime;
            std::string StatisticName;
            Uint32 Version;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                ActivationTime(0),
                DeactivationTime(),
                ScheduledActivationTime(),
                ScheduledDeactivationTime(),
                StatisticName(),
                Version(0)
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                ActivationTime(src.ActivationTime),
                DeactivationTime(src.DeactivationTime),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            PlayerStatisticVersion(const rapidjson::Value& obj) : PlayerStatisticVersion()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticVersion();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabBaseModel
        {
            std::list<PlayerStatisticVersion> StatisticVersions;

            GetPlayerStatisticVersionsResult() :
                PlayFabBaseModel(),
                StatisticVersions()
            {}

            GetPlayerStatisticVersionsResult(const GetPlayerStatisticVersionsResult& src) :
                PlayFabBaseModel(),
                StatisticVersions(src.StatisticVersions)
            {}

            GetPlayerStatisticVersionsResult(const rapidjson::Value& obj) : GetPlayerStatisticVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerTagsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string Namespace;
            std::string PlayFabId;

            GetPlayerTagsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Namespace(),
                PlayFabId()
            {}

            GetPlayerTagsRequest(const GetPlayerTagsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Namespace(src.Namespace),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerTagsRequest(const rapidjson::Value& obj) : GetPlayerTagsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerTagsResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::list<std::string> Tags;

            GetPlayerTagsResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Tags()
            {}

            GetPlayerTagsResult(const GetPlayerTagsResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            GetPlayerTagsResult(const rapidjson::Value& obj) : GetPlayerTagsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsResult();

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
            std::list<TradeInfo> AcceptedTrades;
            std::list<TradeInfo> OpenedTrades;

            GetPlayerTradesResponse() :
                PlayFabBaseModel(),
                AcceptedTrades(),
                OpenedTrades()
            {}

            GetPlayerTradesResponse(const GetPlayerTradesResponse& src) :
                PlayFabBaseModel(),
                AcceptedTrades(src.AcceptedTrades),
                OpenedTrades(src.OpenedTrades)
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

        struct GetPlayFabIDsFromFacebookInstantGamesIdsRequest : public PlayFabBaseModel
        {
            std::list<std::string> FacebookInstantGamesIds;

            GetPlayFabIDsFromFacebookInstantGamesIdsRequest() :
                PlayFabBaseModel(),
                FacebookInstantGamesIds()
            {}

            GetPlayFabIDsFromFacebookInstantGamesIdsRequest(const GetPlayFabIDsFromFacebookInstantGamesIdsRequest& src) :
                PlayFabBaseModel(),
                FacebookInstantGamesIds(src.FacebookInstantGamesIds)
            {}

            GetPlayFabIDsFromFacebookInstantGamesIdsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookInstantGamesIdsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookInstantGamesIdsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromFacebookInstantGamesIdsResult : public PlayFabBaseModel
        {
            std::list<FacebookInstantGamesPlayFabIdPair> Data;

            GetPlayFabIDsFromFacebookInstantGamesIdsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromFacebookInstantGamesIdsResult(const GetPlayFabIDsFromFacebookInstantGamesIdsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromFacebookInstantGamesIdsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookInstantGamesIdsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookInstantGamesIdsResult();

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

        struct GetPlayFabIDsFromGenericIDsRequest : public PlayFabBaseModel
        {
            std::list<GenericServiceId> GenericIDs;

            GetPlayFabIDsFromGenericIDsRequest() :
                PlayFabBaseModel(),
                GenericIDs()
            {}

            GetPlayFabIDsFromGenericIDsRequest(const GetPlayFabIDsFromGenericIDsRequest& src) :
                PlayFabBaseModel(),
                GenericIDs(src.GenericIDs)
            {}

            GetPlayFabIDsFromGenericIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGenericIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGenericIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromGenericIDsResult : public PlayFabBaseModel
        {
            std::list<GenericPlayFabIdPair> Data;

            GetPlayFabIDsFromGenericIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGenericIDsResult(const GetPlayFabIDsFromGenericIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGenericIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGenericIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGenericIDsResult();

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

        struct GetPlayFabIDsFromKongregateIDsRequest : public PlayFabBaseModel
        {
            std::list<std::string> KongregateIDs;

            GetPlayFabIDsFromKongregateIDsRequest() :
                PlayFabBaseModel(),
                KongregateIDs()
            {}

            GetPlayFabIDsFromKongregateIDsRequest(const GetPlayFabIDsFromKongregateIDsRequest& src) :
                PlayFabBaseModel(),
                KongregateIDs(src.KongregateIDs)
            {}

            GetPlayFabIDsFromKongregateIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromKongregateIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromKongregateIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct KongregatePlayFabIdPair : public PlayFabBaseModel
        {
            std::string KongregateId;
            std::string PlayFabId;

            KongregatePlayFabIdPair() :
                PlayFabBaseModel(),
                KongregateId(),
                PlayFabId()
            {}

            KongregatePlayFabIdPair(const KongregatePlayFabIdPair& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                PlayFabId(src.PlayFabId)
            {}

            KongregatePlayFabIdPair(const rapidjson::Value& obj) : KongregatePlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~KongregatePlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromKongregateIDsResult : public PlayFabBaseModel
        {
            std::list<KongregatePlayFabIdPair> Data;

            GetPlayFabIDsFromKongregateIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromKongregateIDsResult(const GetPlayFabIDsFromKongregateIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromKongregateIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromKongregateIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromKongregateIDsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest : public PlayFabBaseModel
        {
            std::list<std::string> NintendoSwitchDeviceIds;

            GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest() :
                PlayFabBaseModel(),
                NintendoSwitchDeviceIds()
            {}

            GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(const GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& src) :
                PlayFabBaseModel(),
                NintendoSwitchDeviceIds(src.NintendoSwitchDeviceIds)
            {}

            GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromNintendoSwitchDeviceIdsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct NintendoSwitchPlayFabIdPair : public PlayFabBaseModel
        {
            std::string NintendoSwitchDeviceId;
            std::string PlayFabId;

            NintendoSwitchPlayFabIdPair() :
                PlayFabBaseModel(),
                NintendoSwitchDeviceId(),
                PlayFabId()
            {}

            NintendoSwitchPlayFabIdPair(const NintendoSwitchPlayFabIdPair& src) :
                PlayFabBaseModel(),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId),
                PlayFabId(src.PlayFabId)
            {}

            NintendoSwitchPlayFabIdPair(const rapidjson::Value& obj) : NintendoSwitchPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~NintendoSwitchPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromNintendoSwitchDeviceIdsResult : public PlayFabBaseModel
        {
            std::list<NintendoSwitchPlayFabIdPair> Data;

            GetPlayFabIDsFromNintendoSwitchDeviceIdsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromNintendoSwitchDeviceIdsResult(const GetPlayFabIDsFromNintendoSwitchDeviceIdsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromNintendoSwitchDeviceIdsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromNintendoSwitchDeviceIdsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromNintendoSwitchDeviceIdsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromPSNAccountIDsRequest : public PlayFabBaseModel
        {
            OptionalInt32 IssuerId;
            std::list<std::string> PSNAccountIDs;

            GetPlayFabIDsFromPSNAccountIDsRequest() :
                PlayFabBaseModel(),
                IssuerId(),
                PSNAccountIDs()
            {}

            GetPlayFabIDsFromPSNAccountIDsRequest(const GetPlayFabIDsFromPSNAccountIDsRequest& src) :
                PlayFabBaseModel(),
                IssuerId(src.IssuerId),
                PSNAccountIDs(src.PSNAccountIDs)
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
            std::string PlayFabId;
            std::string PSNAccountId;

            PSNAccountPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                PSNAccountId()
            {}

            PSNAccountPlayFabIdPair(const PSNAccountPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                PSNAccountId(src.PSNAccountId)
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
            std::list<std::string> SteamStringIDs;

            GetPlayFabIDsFromSteamIDsRequest() :
                PlayFabBaseModel(),
                SteamStringIDs()
            {}

            GetPlayFabIDsFromSteamIDsRequest(const GetPlayFabIDsFromSteamIDsRequest& src) :
                PlayFabBaseModel(),
                SteamStringIDs(src.SteamStringIDs)
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
            std::string PlayFabId;
            std::string SteamStringId;

            SteamPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                SteamStringId()
            {}

            SteamPlayFabIdPair(const SteamPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                SteamStringId(src.SteamStringId)
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

        struct GetPlayFabIDsFromTwitchIDsRequest : public PlayFabBaseModel
        {
            std::list<std::string> TwitchIds;

            GetPlayFabIDsFromTwitchIDsRequest() :
                PlayFabBaseModel(),
                TwitchIds()
            {}

            GetPlayFabIDsFromTwitchIDsRequest(const GetPlayFabIDsFromTwitchIDsRequest& src) :
                PlayFabBaseModel(),
                TwitchIds(src.TwitchIds)
            {}

            GetPlayFabIDsFromTwitchIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromTwitchIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromTwitchIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct TwitchPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string TwitchId;

            TwitchPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                TwitchId()
            {}

            TwitchPlayFabIdPair(const TwitchPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TwitchId(src.TwitchId)
            {}

            TwitchPlayFabIdPair(const rapidjson::Value& obj) : TwitchPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~TwitchPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromTwitchIDsResult : public PlayFabBaseModel
        {
            std::list<TwitchPlayFabIdPair> Data;

            GetPlayFabIDsFromTwitchIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromTwitchIDsResult(const GetPlayFabIDsFromTwitchIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromTwitchIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromTwitchIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromTwitchIDsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromXboxLiveIDsRequest : public PlayFabBaseModel
        {
            std::string Sandbox;
            std::list<std::string> XboxLiveAccountIDs;

            GetPlayFabIDsFromXboxLiveIDsRequest() :
                PlayFabBaseModel(),
                Sandbox(),
                XboxLiveAccountIDs()
            {}

            GetPlayFabIDsFromXboxLiveIDsRequest(const GetPlayFabIDsFromXboxLiveIDsRequest& src) :
                PlayFabBaseModel(),
                Sandbox(src.Sandbox),
                XboxLiveAccountIDs(src.XboxLiveAccountIDs)
            {}

            GetPlayFabIDsFromXboxLiveIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromXboxLiveIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromXboxLiveIDsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct XboxLiveAccountPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string XboxLiveAccountId;

            XboxLiveAccountPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                XboxLiveAccountId()
            {}

            XboxLiveAccountPlayFabIdPair(const XboxLiveAccountPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                XboxLiveAccountId(src.XboxLiveAccountId)
            {}

            XboxLiveAccountPlayFabIdPair(const rapidjson::Value& obj) : XboxLiveAccountPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~XboxLiveAccountPlayFabIdPair();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayFabIDsFromXboxLiveIDsResult : public PlayFabBaseModel
        {
            std::list<XboxLiveAccountPlayFabIdPair> Data;

            GetPlayFabIDsFromXboxLiveIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromXboxLiveIDsResult(const GetPlayFabIDsFromXboxLiveIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromXboxLiveIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromXboxLiveIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromXboxLiveIDsResult();

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
            time_t PurchaseDate;
            std::string TransactionId;
            std::string TransactionStatus;

            GetPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                PaymentProvider(),
                PurchaseDate(0),
                TransactionId(),
                TransactionStatus()
            {}

            GetPurchaseResult(const GetPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                PaymentProvider(src.PaymentProvider),
                PurchaseDate(src.PurchaseDate),
                TransactionId(src.TransactionId),
                TransactionStatus(src.TransactionStatus)
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
            OptionalBool GetMembers;
            std::list<std::string> Keys;
            std::string SharedGroupId;

            GetSharedGroupDataRequest() :
                PlayFabBaseModel(),
                GetMembers(),
                Keys(),
                SharedGroupId()
            {}

            GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                GetMembers(src.GetMembers),
                Keys(src.Keys),
                SharedGroupId(src.SharedGroupId)
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
            time_t LastUpdated;
            std::string LastUpdatedBy;
            Boxed<UserDataPermission> Permission;
            std::string Value;

            SharedGroupDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(0),
                LastUpdatedBy(),
                Permission(),
                Value()
            {}

            SharedGroupDataRecord(const SharedGroupDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                LastUpdatedBy(src.LastUpdatedBy),
                Permission(src.Permission),
                Value(src.Value)
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
            std::string CatalogVersion;
            std::string StoreId;

            GetStoreItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId()
            {}

            GetStoreItemsRequest(const GetStoreItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            GetStoreItemsRequest(const rapidjson::Value& obj) : GetStoreItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StoreMarketingModel : public PlayFabBaseModel
        {
            std::string Description;
            std::string DisplayName;
            MultitypeVar Metadata;

            StoreMarketingModel() :
                PlayFabBaseModel(),
                Description(),
                DisplayName(),
                Metadata()
            {}

            StoreMarketingModel(const StoreMarketingModel& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                DisplayName(src.DisplayName),
                Metadata(src.Metadata)
            {}

            StoreMarketingModel(const rapidjson::Value& obj) : StoreMarketingModel()
            {
                readFromValue(obj);
            }

            ~StoreMarketingModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum SourceType
        {
            SourceTypeAdmin,
            SourceTypeBackEnd,
            SourceTypeGameClient,
            SourceTypeGameServer,
            SourceTypePartner,
            SourceTypeCustom,
            SourceTypeAPI
        };

        void writeSourceTypeEnumJSON(SourceType enumVal, PFStringJsonWriter& writer);
        SourceType readSourceTypeFromValue(const rapidjson::Value& obj);

        struct StoreItem : public PlayFabBaseModel
        {
            MultitypeVar CustomData;
            OptionalUint32 DisplayPosition;
            std::string ItemId;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            StoreItem() :
                PlayFabBaseModel(),
                CustomData(),
                DisplayPosition(),
                ItemId(),
                RealCurrencyPrices(),
                VirtualCurrencyPrices()
            {}

            StoreItem(const StoreItem& src) :
                PlayFabBaseModel(),
                CustomData(src.CustomData),
                DisplayPosition(src.DisplayPosition),
                ItemId(src.ItemId),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
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
            std::string CatalogVersion;
            StoreMarketingModel* MarketingData;
            Boxed<SourceType> Source;
            std::list<StoreItem> Store;
            std::string StoreId;

            GetStoreItemsResult() :
                PlayFabBaseModel(),
                CatalogVersion(),
                MarketingData(NULL),
                Source(),
                Store(),
                StoreId()
            {}

            GetStoreItemsResult(const GetStoreItemsResult& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                MarketingData(src.MarketingData ? new StoreMarketingModel(*src.MarketingData) : NULL),
                Source(src.Source),
                Store(src.Store),
                StoreId(src.StoreId)
            {}

            GetStoreItemsResult(const rapidjson::Value& obj) : GetStoreItemsResult()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTimeRequest : public PlayFabBaseModel
        {

            GetTimeRequest() :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const GetTimeRequest& src) :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const rapidjson::Value& obj) : GetTimeRequest()
            {
                readFromValue(obj);
            }

            ~GetTimeRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTimeResult : public PlayFabBaseModel
        {
            time_t Time;

            GetTimeResult() :
                PlayFabBaseModel(),
                Time(0)
            {}

            GetTimeResult(const GetTimeResult& src) :
                PlayFabBaseModel(),
                Time(src.Time)
            {}

            GetTimeResult(const rapidjson::Value& obj) : GetTimeResult()
            {
                readFromValue(obj);
            }

            ~GetTimeResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitleDataRequest : public PlayFabBaseModel
        {
            std::list<std::string> Keys;
            std::string OverrideLabel;

            GetTitleDataRequest() :
                PlayFabBaseModel(),
                Keys(),
                OverrideLabel()
            {}

            GetTitleDataRequest(const GetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys),
                OverrideLabel(src.OverrideLabel)
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
            std::string Body;
            std::string NewsId;
            time_t Timestamp;
            std::string Title;

            TitleNewsItem() :
                PlayFabBaseModel(),
                Body(),
                NewsId(),
                Timestamp(0),
                Title()
            {}

            TitleNewsItem(const TitleNewsItem& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                NewsId(src.NewsId),
                Timestamp(src.Timestamp),
                Title(src.Title)
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

        struct GetTitlePublicKeyRequest : public PlayFabBaseModel
        {
            std::string TitleId;
            std::string TitleSharedSecret;

            GetTitlePublicKeyRequest() :
                PlayFabBaseModel(),
                TitleId(),
                TitleSharedSecret()
            {}

            GetTitlePublicKeyRequest(const GetTitlePublicKeyRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                TitleSharedSecret(src.TitleSharedSecret)
            {}

            GetTitlePublicKeyRequest(const rapidjson::Value& obj) : GetTitlePublicKeyRequest()
            {
                readFromValue(obj);
            }

            ~GetTitlePublicKeyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitlePublicKeyResult : public PlayFabBaseModel
        {
            std::string RSAPublicKey;

            GetTitlePublicKeyResult() :
                PlayFabBaseModel(),
                RSAPublicKey()
            {}

            GetTitlePublicKeyResult(const GetTitlePublicKeyResult& src) :
                PlayFabBaseModel(),
                RSAPublicKey(src.RSAPublicKey)
            {}

            GetTitlePublicKeyResult(const rapidjson::Value& obj) : GetTitlePublicKeyResult()
            {
                readFromValue(obj);
            }

            ~GetTitlePublicKeyResult();

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

        struct GetUserDataRequest : public PlayFabBaseModel
        {
            OptionalUint32 IfChangedFromDataVersion;
            std::list<std::string> Keys;
            std::string PlayFabId;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
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
            std::map<std::string, std::string> CustomTags;

            GetUserInventoryRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
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

        struct GetWindowsHelloChallengeRequest : public PlayFabBaseModel
        {
            std::string PublicKeyHint;
            std::string TitleId;

            GetWindowsHelloChallengeRequest() :
                PlayFabBaseModel(),
                PublicKeyHint(),
                TitleId()
            {}

            GetWindowsHelloChallengeRequest(const GetWindowsHelloChallengeRequest& src) :
                PlayFabBaseModel(),
                PublicKeyHint(src.PublicKeyHint),
                TitleId(src.TitleId)
            {}

            GetWindowsHelloChallengeRequest(const rapidjson::Value& obj) : GetWindowsHelloChallengeRequest()
            {
                readFromValue(obj);
            }

            ~GetWindowsHelloChallengeRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetWindowsHelloChallengeResponse : public PlayFabBaseModel
        {
            std::string Challenge;

            GetWindowsHelloChallengeResponse() :
                PlayFabBaseModel(),
                Challenge()
            {}

            GetWindowsHelloChallengeResponse(const GetWindowsHelloChallengeResponse& src) :
                PlayFabBaseModel(),
                Challenge(src.Challenge)
            {}

            GetWindowsHelloChallengeResponse(const rapidjson::Value& obj) : GetWindowsHelloChallengeResponse()
            {
                readFromValue(obj);
            }

            ~GetWindowsHelloChallengeResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GrantCharacterToUserRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CharacterName;
            std::map<std::string, std::string> CustomTags;
            std::string ItemId;

            GrantCharacterToUserRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterName(),
                CustomTags(),
                ItemId()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterName(src.CharacterName),
                CustomTags(src.CustomTags),
                ItemId(src.ItemId)
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

        struct ItemPurchaseRequest : public PlayFabBaseModel
        {
            std::string Annotation;
            std::string ItemId;
            Uint32 Quantity;
            std::list<std::string> UpgradeFromItems;

            ItemPurchaseRequest() :
                PlayFabBaseModel(),
                Annotation(),
                ItemId(),
                Quantity(0),
                UpgradeFromItems()
            {}

            ItemPurchaseRequest(const ItemPurchaseRequest& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                ItemId(src.ItemId),
                Quantity(src.Quantity),
                UpgradeFromItems(src.UpgradeFromItems)
            {}

            ItemPurchaseRequest(const rapidjson::Value& obj) : ItemPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ItemPurchaseRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkAndroidDeviceIDRequest : public PlayFabBaseModel
        {
            std::string AndroidDevice;
            std::string AndroidDeviceId;
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string OS;

            LinkAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDevice(),
                AndroidDeviceId(),
                CustomTags(),
                ForceLink(),
                OS()
            {}

            LinkAndroidDeviceIDRequest(const LinkAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDevice(src.AndroidDevice),
                AndroidDeviceId(src.AndroidDeviceId),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                OS(src.OS)
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

        struct LinkAppleRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string IdentityToken;

            LinkAppleRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                ForceLink(),
                IdentityToken()
            {}

            LinkAppleRequest(const LinkAppleRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                IdentityToken(src.IdentityToken)
            {}

            LinkAppleRequest(const rapidjson::Value& obj) : LinkAppleRequest()
            {
                readFromValue(obj);
            }

            ~LinkAppleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkCustomIDRequest : public PlayFabBaseModel
        {
            std::string CustomId;
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;

            LinkCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId(),
                CustomTags(),
                ForceLink()
            {}

            LinkCustomIDRequest(const LinkCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink)
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
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;

            LinkFacebookAccountRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CustomTags(),
                ForceLink()
            {}

            LinkFacebookAccountRequest(const LinkFacebookAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CustomTags(src.CustomTags),
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

        struct LinkFacebookInstantGamesIdRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string FacebookInstantGamesSignature;
            OptionalBool ForceLink;

            LinkFacebookInstantGamesIdRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                FacebookInstantGamesSignature(),
                ForceLink()
            {}

            LinkFacebookInstantGamesIdRequest(const LinkFacebookInstantGamesIdRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                FacebookInstantGamesSignature(src.FacebookInstantGamesSignature),
                ForceLink(src.ForceLink)
            {}

            LinkFacebookInstantGamesIdRequest(const rapidjson::Value& obj) : LinkFacebookInstantGamesIdRequest()
            {
                readFromValue(obj);
            }

            ~LinkFacebookInstantGamesIdRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkFacebookInstantGamesIdResult : public PlayFabBaseModel
        {

            LinkFacebookInstantGamesIdResult() :
                PlayFabBaseModel()
            {}

            LinkFacebookInstantGamesIdResult(const LinkFacebookInstantGamesIdResult& src) :
                PlayFabBaseModel()
            {}

            LinkFacebookInstantGamesIdResult(const rapidjson::Value& obj) : LinkFacebookInstantGamesIdResult()
            {
                readFromValue(obj);
            }

            ~LinkFacebookInstantGamesIdResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkGameCenterAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string GameCenterId;
            std::string PublicKeyUrl;
            std::string Salt;
            std::string Signature;
            std::string Timestamp;

            LinkGameCenterAccountRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                ForceLink(),
                GameCenterId(),
                PublicKeyUrl(),
                Salt(),
                Signature(),
                Timestamp()
            {}

            LinkGameCenterAccountRequest(const LinkGameCenterAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                GameCenterId(src.GameCenterId),
                PublicKeyUrl(src.PublicKeyUrl),
                Salt(src.Salt),
                Signature(src.Signature),
                Timestamp(src.Timestamp)
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
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string ServerAuthCode;

            LinkGoogleAccountRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                ForceLink(),
                ServerAuthCode()
            {}

            LinkGoogleAccountRequest(const LinkGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                ServerAuthCode(src.ServerAuthCode)
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
            std::map<std::string, std::string> CustomTags;
            std::string DeviceId;
            std::string DeviceModel;
            OptionalBool ForceLink;
            std::string OS;

            LinkIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                DeviceId(),
                DeviceModel(),
                ForceLink(),
                OS()
            {}

            LinkIOSDeviceIDRequest(const LinkIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                DeviceId(src.DeviceId),
                DeviceModel(src.DeviceModel),
                ForceLink(src.ForceLink),
                OS(src.OS)
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
            std::string AuthTicket;
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string KongregateId;

            LinkKongregateAccountRequest() :
                PlayFabBaseModel(),
                AuthTicket(),
                CustomTags(),
                ForceLink(),
                KongregateId()
            {}

            LinkKongregateAccountRequest(const LinkKongregateAccountRequest& src) :
                PlayFabBaseModel(),
                AuthTicket(src.AuthTicket),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                KongregateId(src.KongregateId)
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

        struct LinkNintendoServiceAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string IdentityToken;

            LinkNintendoServiceAccountRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                ForceLink(),
                IdentityToken()
            {}

            LinkNintendoServiceAccountRequest(const LinkNintendoServiceAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                IdentityToken(src.IdentityToken)
            {}

            LinkNintendoServiceAccountRequest(const rapidjson::Value& obj) : LinkNintendoServiceAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkNintendoServiceAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkNintendoSwitchDeviceIdRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string NintendoSwitchDeviceId;

            LinkNintendoSwitchDeviceIdRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                ForceLink(),
                NintendoSwitchDeviceId()
            {}

            LinkNintendoSwitchDeviceIdRequest(const LinkNintendoSwitchDeviceIdRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId)
            {}

            LinkNintendoSwitchDeviceIdRequest(const rapidjson::Value& obj) : LinkNintendoSwitchDeviceIdRequest()
            {
                readFromValue(obj);
            }

            ~LinkNintendoSwitchDeviceIdRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkNintendoSwitchDeviceIdResult : public PlayFabBaseModel
        {

            LinkNintendoSwitchDeviceIdResult() :
                PlayFabBaseModel()
            {}

            LinkNintendoSwitchDeviceIdResult(const LinkNintendoSwitchDeviceIdResult& src) :
                PlayFabBaseModel()
            {}

            LinkNintendoSwitchDeviceIdResult(const rapidjson::Value& obj) : LinkNintendoSwitchDeviceIdResult()
            {
                readFromValue(obj);
            }

            ~LinkNintendoSwitchDeviceIdResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkOpenIdConnectRequest : public PlayFabBaseModel
        {
            std::string ConnectionId;
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string IdToken;

            LinkOpenIdConnectRequest() :
                PlayFabBaseModel(),
                ConnectionId(),
                CustomTags(),
                ForceLink(),
                IdToken()
            {}

            LinkOpenIdConnectRequest(const LinkOpenIdConnectRequest& src) :
                PlayFabBaseModel(),
                ConnectionId(src.ConnectionId),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                IdToken(src.IdToken)
            {}

            LinkOpenIdConnectRequest(const rapidjson::Value& obj) : LinkOpenIdConnectRequest()
            {
                readFromValue(obj);
            }

            ~LinkOpenIdConnectRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkPSNAccountRequest : public PlayFabBaseModel
        {
            std::string AuthCode;
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            OptionalInt32 IssuerId;
            std::string RedirectUri;

            LinkPSNAccountRequest() :
                PlayFabBaseModel(),
                AuthCode(),
                CustomTags(),
                ForceLink(),
                IssuerId(),
                RedirectUri()
            {}

            LinkPSNAccountRequest(const LinkPSNAccountRequest& src) :
                PlayFabBaseModel(),
                AuthCode(src.AuthCode),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
                IssuerId(src.IssuerId),
                RedirectUri(src.RedirectUri)
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
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string SteamTicket;

            LinkSteamAccountRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                ForceLink(),
                SteamTicket()
            {}

            LinkSteamAccountRequest(const LinkSteamAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
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

        struct LinkTwitchAccountRequest : public PlayFabBaseModel
        {
            std::string AccessToken;
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;

            LinkTwitchAccountRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CustomTags(),
                ForceLink()
            {}

            LinkTwitchAccountRequest(const LinkTwitchAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink)
            {}

            LinkTwitchAccountRequest(const rapidjson::Value& obj) : LinkTwitchAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkTwitchAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkTwitchAccountResult : public PlayFabBaseModel
        {

            LinkTwitchAccountResult() :
                PlayFabBaseModel()
            {}

            LinkTwitchAccountResult(const LinkTwitchAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkTwitchAccountResult(const rapidjson::Value& obj) : LinkTwitchAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkTwitchAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkWindowsHelloAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string DeviceName;
            OptionalBool ForceLink;
            std::string PublicKey;
            std::string UserName;

            LinkWindowsHelloAccountRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                DeviceName(),
                ForceLink(),
                PublicKey(),
                UserName()
            {}

            LinkWindowsHelloAccountRequest(const LinkWindowsHelloAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                DeviceName(src.DeviceName),
                ForceLink(src.ForceLink),
                PublicKey(src.PublicKey),
                UserName(src.UserName)
            {}

            LinkWindowsHelloAccountRequest(const rapidjson::Value& obj) : LinkWindowsHelloAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkWindowsHelloAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkWindowsHelloAccountResponse : public PlayFabBaseModel
        {

            LinkWindowsHelloAccountResponse() :
                PlayFabBaseModel()
            {}

            LinkWindowsHelloAccountResponse(const LinkWindowsHelloAccountResponse& src) :
                PlayFabBaseModel()
            {}

            LinkWindowsHelloAccountResponse(const rapidjson::Value& obj) : LinkWindowsHelloAccountResponse()
            {
                readFromValue(obj);
            }

            ~LinkWindowsHelloAccountResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LinkXboxAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            OptionalBool ForceLink;
            std::string XboxToken;

            LinkXboxAccountRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                ForceLink(),
                XboxToken()
            {}

            LinkXboxAccountRequest(const LinkXboxAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                ForceLink(src.ForceLink),
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

        struct UserSettings : public PlayFabBaseModel
        {
            bool GatherDeviceInfo;
            bool GatherFocusInfo;
            bool NeedsAttribution;

            UserSettings() :
                PlayFabBaseModel(),
                GatherDeviceInfo(false),
                GatherFocusInfo(false),
                NeedsAttribution(false)
            {}

            UserSettings(const UserSettings& src) :
                PlayFabBaseModel(),
                GatherDeviceInfo(src.GatherDeviceInfo),
                GatherFocusInfo(src.GatherFocusInfo),
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

        struct Variable : public PlayFabBaseModel
        {
            std::string Name;
            std::string Value;

            Variable() :
                PlayFabBaseModel(),
                Name(),
                Value()
            {}

            Variable(const Variable& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Value(src.Value)
            {}

            Variable(const rapidjson::Value& obj) : Variable()
            {
                readFromValue(obj);
            }

            ~Variable();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct TreatmentAssignment : public PlayFabBaseModel
        {
            std::list<Variable> Variables;
            std::list<std::string> Variants;

            TreatmentAssignment() :
                PlayFabBaseModel(),
                Variables(),
                Variants()
            {}

            TreatmentAssignment(const TreatmentAssignment& src) :
                PlayFabBaseModel(),
                Variables(src.Variables),
                Variants(src.Variants)
            {}

            TreatmentAssignment(const rapidjson::Value& obj) : TreatmentAssignment()
            {
                readFromValue(obj);
            }

            ~TreatmentAssignment();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginResult : public PlayFabBaseModel
        {
            EntityTokenResponse* EntityToken;
            GetPlayerCombinedInfoResultPayload* InfoResultPayload;
            OptionalTime LastLoginTime;
            bool NewlyCreated;
            std::string PlayFabId;
            std::string SessionTicket;
            UserSettings* SettingsForUser;
            TreatmentAssignment* pfTreatmentAssignment;

            LoginResult() :
                PlayFabBaseModel(),
                EntityToken(NULL),
                InfoResultPayload(NULL),
                LastLoginTime(),
                NewlyCreated(false),
                PlayFabId(),
                SessionTicket(),
                SettingsForUser(NULL),
                pfTreatmentAssignment(NULL)
            {}

            LoginResult(const LoginResult& src) :
                PlayFabBaseModel(),
                EntityToken(src.EntityToken ? new EntityTokenResponse(*src.EntityToken) : NULL),
                InfoResultPayload(src.InfoResultPayload ? new GetPlayerCombinedInfoResultPayload(*src.InfoResultPayload) : NULL),
                LastLoginTime(src.LastLoginTime),
                NewlyCreated(src.NewlyCreated),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : NULL),
                pfTreatmentAssignment(src.pfTreatmentAssignment ? new TreatmentAssignment(*src.pfTreatmentAssignment) : NULL)
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
            std::string AndroidDevice;
            std::string AndroidDeviceId;
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string OS;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDevice(),
                AndroidDeviceId(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                OS(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithAndroidDeviceIDRequest(const LoginWithAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDevice(src.AndroidDevice),
                AndroidDeviceId(src.AndroidDeviceId),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                OS(src.OS),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithAndroidDeviceIDRequest(const rapidjson::Value& obj) : LoginWithAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithAndroidDeviceIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithAppleRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            std::string IdentityToken;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithAppleRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                IdentityToken(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithAppleRequest(const LoginWithAppleRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                IdentityToken(src.IdentityToken),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithAppleRequest(const rapidjson::Value& obj) : LoginWithAppleRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithAppleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithCustomIDRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            std::string CustomId;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithCustomIDRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomId(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithCustomIDRequest(const LoginWithCustomIDRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomId(src.CustomId),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
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
            std::map<std::string, std::string> CustomTags;
            std::string Email;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string Password;
            std::string TitleId;

            LoginWithEmailAddressRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Email(),
                InfoRequestParameters(NULL),
                Password(),
                TitleId()
            {}

            LoginWithEmailAddressRequest(const LoginWithEmailAddressRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Email(src.Email),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                Password(src.Password),
                TitleId(src.TitleId)
            {}

            LoginWithEmailAddressRequest(const rapidjson::Value& obj) : LoginWithEmailAddressRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithEmailAddressRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithFacebookInstantGamesIdRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            std::string FacebookInstantGamesSignature;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithFacebookInstantGamesIdRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                FacebookInstantGamesSignature(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithFacebookInstantGamesIdRequest(const LoginWithFacebookInstantGamesIdRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                FacebookInstantGamesSignature(src.FacebookInstantGamesSignature),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithFacebookInstantGamesIdRequest(const rapidjson::Value& obj) : LoginWithFacebookInstantGamesIdRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithFacebookInstantGamesIdRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithFacebookRequest : public PlayFabBaseModel
        {
            std::string AccessToken;
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithFacebookRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithFacebookRequest(const LoginWithFacebookRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
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
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerId;
            std::string PlayerSecret;
            std::string PublicKeyUrl;
            std::string Salt;
            std::string Signature;
            std::string Timestamp;
            std::string TitleId;

            LoginWithGameCenterRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                PlayerId(),
                PlayerSecret(),
                PublicKeyUrl(),
                Salt(),
                Signature(),
                Timestamp(),
                TitleId()
            {}

            LoginWithGameCenterRequest(const LoginWithGameCenterRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerId(src.PlayerId),
                PlayerSecret(src.PlayerSecret),
                PublicKeyUrl(src.PublicKeyUrl),
                Salt(src.Salt),
                Signature(src.Signature),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
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
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string ServerAuthCode;
            std::string TitleId;

            LoginWithGoogleAccountRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                ServerAuthCode(),
                TitleId()
            {}

            LoginWithGoogleAccountRequest(const LoginWithGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                ServerAuthCode(src.ServerAuthCode),
                TitleId(src.TitleId)
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
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string DeviceId;
            std::string DeviceModel;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string OS;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                DeviceId(),
                DeviceModel(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                OS(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithIOSDeviceIDRequest(const LoginWithIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                DeviceId(src.DeviceId),
                DeviceModel(src.DeviceModel),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                OS(src.OS),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
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
            std::string AuthTicket;
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string KongregateId;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithKongregateRequest() :
                PlayFabBaseModel(),
                AuthTicket(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                KongregateId(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithKongregateRequest(const LoginWithKongregateRequest& src) :
                PlayFabBaseModel(),
                AuthTicket(src.AuthTicket),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                KongregateId(src.KongregateId),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithKongregateRequest(const rapidjson::Value& obj) : LoginWithKongregateRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithKongregateRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithNintendoServiceAccountRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            std::string IdentityToken;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithNintendoServiceAccountRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                IdentityToken(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithNintendoServiceAccountRequest(const LoginWithNintendoServiceAccountRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                IdentityToken(src.IdentityToken),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithNintendoServiceAccountRequest(const rapidjson::Value& obj) : LoginWithNintendoServiceAccountRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithNintendoServiceAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithNintendoSwitchDeviceIdRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string NintendoSwitchDeviceId;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithNintendoSwitchDeviceIdRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                NintendoSwitchDeviceId(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithNintendoSwitchDeviceIdRequest(const LoginWithNintendoSwitchDeviceIdRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithNintendoSwitchDeviceIdRequest(const rapidjson::Value& obj) : LoginWithNintendoSwitchDeviceIdRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithNintendoSwitchDeviceIdRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithOpenIdConnectRequest : public PlayFabBaseModel
        {
            std::string ConnectionId;
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            std::string IdToken;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithOpenIdConnectRequest() :
                PlayFabBaseModel(),
                ConnectionId(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                IdToken(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithOpenIdConnectRequest(const LoginWithOpenIdConnectRequest& src) :
                PlayFabBaseModel(),
                ConnectionId(src.ConnectionId),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                IdToken(src.IdToken),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithOpenIdConnectRequest(const rapidjson::Value& obj) : LoginWithOpenIdConnectRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithOpenIdConnectRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithPlayFabRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string Password;
            std::string TitleId;
            std::string Username;

            LoginWithPlayFabRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                InfoRequestParameters(NULL),
                Password(),
                TitleId(),
                Username()
            {}

            LoginWithPlayFabRequest(const LoginWithPlayFabRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                Password(src.Password),
                TitleId(src.TitleId),
                Username(src.Username)
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
            std::string AuthCode;
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            OptionalInt32 IssuerId;
            std::string PlayerSecret;
            std::string RedirectUri;
            std::string TitleId;

            LoginWithPSNRequest() :
                PlayFabBaseModel(),
                AuthCode(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                IssuerId(),
                PlayerSecret(),
                RedirectUri(),
                TitleId()
            {}

            LoginWithPSNRequest(const LoginWithPSNRequest& src) :
                PlayFabBaseModel(),
                AuthCode(src.AuthCode),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                IssuerId(src.IssuerId),
                PlayerSecret(src.PlayerSecret),
                RedirectUri(src.RedirectUri),
                TitleId(src.TitleId)
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
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string SteamTicket;
            std::string TitleId;

            LoginWithSteamRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                SteamTicket(),
                TitleId()
            {}

            LoginWithSteamRequest(const LoginWithSteamRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                SteamTicket(src.SteamTicket),
                TitleId(src.TitleId)
            {}

            LoginWithSteamRequest(const rapidjson::Value& obj) : LoginWithSteamRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithSteamRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithTwitchRequest : public PlayFabBaseModel
        {
            std::string AccessToken;
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithTwitchRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithTwitchRequest(const LoginWithTwitchRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            LoginWithTwitchRequest(const rapidjson::Value& obj) : LoginWithTwitchRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithTwitchRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithWindowsHelloRequest : public PlayFabBaseModel
        {
            std::string ChallengeSignature;
            std::map<std::string, std::string> CustomTags;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PublicKeyHint;
            std::string TitleId;

            LoginWithWindowsHelloRequest() :
                PlayFabBaseModel(),
                ChallengeSignature(),
                CustomTags(),
                InfoRequestParameters(NULL),
                PublicKeyHint(),
                TitleId()
            {}

            LoginWithWindowsHelloRequest(const LoginWithWindowsHelloRequest& src) :
                PlayFabBaseModel(),
                ChallengeSignature(src.ChallengeSignature),
                CustomTags(src.CustomTags),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PublicKeyHint(src.PublicKeyHint),
                TitleId(src.TitleId)
            {}

            LoginWithWindowsHelloRequest(const rapidjson::Value& obj) : LoginWithWindowsHelloRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithWindowsHelloRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LoginWithXboxRequest : public PlayFabBaseModel
        {
            OptionalBool CreateAccount;
            std::map<std::string, std::string> CustomTags;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string TitleId;
            std::string XboxToken;

            LoginWithXboxRequest() :
                PlayFabBaseModel(),
                CreateAccount(),
                CustomTags(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                TitleId(),
                XboxToken()
            {}

            LoginWithXboxRequest(const LoginWithXboxRequest& src) :
                PlayFabBaseModel(),
                CreateAccount(src.CreateAccount),
                CustomTags(src.CustomTags),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId),
                XboxToken(src.XboxToken)
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
            std::string CharacterId;
            std::map<std::string, std::string> CustomTags;
            std::string GameMode;
            std::string LobbyId;
            Boxed<Region> pfRegion;
            OptionalBool StartNewIfNoneFound;
            std::string StatisticName;
            CollectionFilter* TagFilter;

            MatchmakeRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                CharacterId(),
                CustomTags(),
                GameMode(),
                LobbyId(),
                pfRegion(),
                StartNewIfNoneFound(),
                StatisticName(),
                TagFilter(NULL)
            {}

            MatchmakeRequest(const MatchmakeRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                CharacterId(src.CharacterId),
                CustomTags(src.CustomTags),
                GameMode(src.GameMode),
                LobbyId(src.LobbyId),
                pfRegion(src.pfRegion),
                StartNewIfNoneFound(src.StartNewIfNoneFound),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter ? new CollectionFilter(*src.TagFilter) : NULL)
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
            MatchmakeStatusGameNotFound,
            MatchmakeStatusNoAvailableSlots,
            MatchmakeStatusSessionClosed
        };

        void writeMatchmakeStatusEnumJSON(MatchmakeStatus enumVal, PFStringJsonWriter& writer);
        MatchmakeStatus readMatchmakeStatusFromValue(const rapidjson::Value& obj);

        struct MatchmakeResult : public PlayFabBaseModel
        {
            std::string Expires;
            std::string LobbyID;
            OptionalInt32 PollWaitTimeMS;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            OptionalInt32 ServerPort;
            std::string ServerPublicDNSName;
            Boxed<MatchmakeStatus> Status;
            std::string Ticket;

            MatchmakeResult() :
                PlayFabBaseModel(),
                Expires(),
                LobbyID(),
                PollWaitTimeMS(),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(),
                ServerPublicDNSName(),
                Status(),
                Ticket()
            {}

            MatchmakeResult(const MatchmakeResult& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                LobbyID(src.LobbyID),
                PollWaitTimeMS(src.PollWaitTimeMS),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                Status(src.Status),
                Ticket(src.Ticket)
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
            Int32 Balance;
            Int32 BalanceChange;
            std::string PlayFabId;
            std::string VirtualCurrency;

            ModifyUserVirtualCurrencyResult() :
                PlayFabBaseModel(),
                Balance(0),
                BalanceChange(0),
                PlayFabId(),
                VirtualCurrency()
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                Balance(src.Balance),
                BalanceChange(src.BalanceChange),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
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
            std::list<std::string> AllowedPlayerIds;
            std::list<std::string> OfferedInventoryInstanceIds;
            std::list<std::string> RequestedCatalogItemIds;

            OpenTradeRequest() :
                PlayFabBaseModel(),
                AllowedPlayerIds(),
                OfferedInventoryInstanceIds(),
                RequestedCatalogItemIds()
            {}

            OpenTradeRequest(const OpenTradeRequest& src) :
                PlayFabBaseModel(),
                AllowedPlayerIds(src.AllowedPlayerIds),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds)
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
            std::string Currency;
            std::map<std::string, std::string> CustomTags;
            std::string OrderId;
            std::string ProviderName;
            std::string ProviderTransactionId;

            PayForPurchaseRequest() :
                PlayFabBaseModel(),
                Currency(),
                CustomTags(),
                OrderId(),
                ProviderName(),
                ProviderTransactionId()
            {}

            PayForPurchaseRequest(const PayForPurchaseRequest& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                CustomTags(src.CustomTags),
                OrderId(src.OrderId),
                ProviderName(src.ProviderName),
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
            Uint32 CreditApplied;
            std::string OrderId;
            std::string ProviderData;
            std::string ProviderToken;
            std::string PurchaseConfirmationPageURL;
            std::string PurchaseCurrency;
            Uint32 PurchasePrice;
            Boxed<TransactionStatus> Status;
            std::map<std::string, Int32> VCAmount;
            std::map<std::string, Int32> VirtualCurrency;

            PayForPurchaseResult() :
                PlayFabBaseModel(),
                CreditApplied(0),
                OrderId(),
                ProviderData(),
                ProviderToken(),
                PurchaseConfirmationPageURL(),
                PurchaseCurrency(),
                PurchasePrice(0),
                Status(),
                VCAmount(),
                VirtualCurrency()
            {}

            PayForPurchaseResult(const PayForPurchaseResult& src) :
                PlayFabBaseModel(),
                CreditApplied(src.CreditApplied),
                OrderId(src.OrderId),
                ProviderData(src.ProviderData),
                ProviderToken(src.ProviderToken),
                PurchaseConfirmationPageURL(src.PurchaseConfirmationPageURL),
                PurchaseCurrency(src.PurchaseCurrency),
                PurchasePrice(src.PurchasePrice),
                Status(src.Status),
                VCAmount(src.VCAmount),
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
            Uint32 Price;
            std::string ProviderName;
            Uint32 StoreCredit;

            PaymentOption() :
                PlayFabBaseModel(),
                Currency(),
                Price(0),
                ProviderName(),
                StoreCredit(0)
            {}

            PaymentOption(const PaymentOption& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                Price(src.Price),
                ProviderName(src.ProviderName),
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
            std::string CatalogVersion;
            std::string CharacterId;
            std::map<std::string, std::string> CustomTags;
            std::string ItemId;
            Int32 Price;
            std::string StoreId;
            std::string VirtualCurrency;

            PurchaseItemRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                CustomTags(),
                ItemId(),
                Price(0),
                StoreId(),
                VirtualCurrency()
            {}

            PurchaseItemRequest(const PurchaseItemRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CustomTags(src.CustomTags),
                ItemId(src.ItemId),
                Price(src.Price),
                StoreId(src.StoreId),
                VirtualCurrency(src.VirtualCurrency)
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

        struct PurchaseReceiptFulfillment : public PlayFabBaseModel
        {
            std::list<ItemInstance> FulfilledItems;
            std::string RecordedPriceSource;
            std::string RecordedTransactionCurrency;
            OptionalUint32 RecordedTransactionTotal;

            PurchaseReceiptFulfillment() :
                PlayFabBaseModel(),
                FulfilledItems(),
                RecordedPriceSource(),
                RecordedTransactionCurrency(),
                RecordedTransactionTotal()
            {}

            PurchaseReceiptFulfillment(const PurchaseReceiptFulfillment& src) :
                PlayFabBaseModel(),
                FulfilledItems(src.FulfilledItems),
                RecordedPriceSource(src.RecordedPriceSource),
                RecordedTransactionCurrency(src.RecordedTransactionCurrency),
                RecordedTransactionTotal(src.RecordedTransactionTotal)
            {}

            PurchaseReceiptFulfillment(const rapidjson::Value& obj) : PurchaseReceiptFulfillment()
            {
                readFromValue(obj);
            }

            ~PurchaseReceiptFulfillment();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RedeemCouponRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string CouponCode;
            std::map<std::string, std::string> CustomTags;

            RedeemCouponRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                CouponCode(),
                CustomTags()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CouponCode(src.CouponCode),
                CustomTags(src.CustomTags)
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
            OptionalInt32 IssuerId;
            std::string RedirectUri;

            RefreshPSNAuthTokenRequest() :
                PlayFabBaseModel(),
                AuthCode(),
                IssuerId(),
                RedirectUri()
            {}

            RefreshPSNAuthTokenRequest(const RefreshPSNAuthTokenRequest& src) :
                PlayFabBaseModel(),
                AuthCode(src.AuthCode),
                IssuerId(src.IssuerId),
                RedirectUri(src.RedirectUri)
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
            std::string ConfirmationMessage;
            std::string DeviceToken;
            OptionalBool SendPushNotificationConfirmation;

            RegisterForIOSPushNotificationRequest() :
                PlayFabBaseModel(),
                ConfirmationMessage(),
                DeviceToken(),
                SendPushNotificationConfirmation()
            {}

            RegisterForIOSPushNotificationRequest(const RegisterForIOSPushNotificationRequest& src) :
                PlayFabBaseModel(),
                ConfirmationMessage(src.ConfirmationMessage),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation)
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
            std::map<std::string, std::string> CustomTags;
            std::string DisplayName;
            std::string Email;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string Password;
            std::string PlayerSecret;
            OptionalBool RequireBothUsernameAndEmail;
            std::string TitleId;
            std::string Username;

            RegisterPlayFabUserRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                DisplayName(),
                Email(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                Password(),
                PlayerSecret(),
                RequireBothUsernameAndEmail(),
                TitleId(),
                Username()
            {}

            RegisterPlayFabUserRequest(const RegisterPlayFabUserRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                DisplayName(src.DisplayName),
                Email(src.Email),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                Password(src.Password),
                PlayerSecret(src.PlayerSecret),
                RequireBothUsernameAndEmail(src.RequireBothUsernameAndEmail),
                TitleId(src.TitleId),
                Username(src.Username)
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
            EntityTokenResponse* EntityToken;
            std::string PlayFabId;
            std::string SessionTicket;
            UserSettings* SettingsForUser;
            std::string Username;

            RegisterPlayFabUserResult() :
                PlayFabBaseModel(),
                EntityToken(NULL),
                PlayFabId(),
                SessionTicket(),
                SettingsForUser(NULL),
                Username()
            {}

            RegisterPlayFabUserResult(const RegisterPlayFabUserResult& src) :
                PlayFabBaseModel(),
                EntityToken(src.EntityToken ? new EntityTokenResponse(*src.EntityToken) : NULL),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : NULL),
                Username(src.Username)
            {}

            RegisterPlayFabUserResult(const rapidjson::Value& obj) : RegisterPlayFabUserResult()
            {
                readFromValue(obj);
            }

            ~RegisterPlayFabUserResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegisterWithWindowsHelloRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string DeviceName;
            std::string EncryptedRequest;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            std::string PlayerSecret;
            std::string PublicKey;
            std::string TitleId;
            std::string UserName;

            RegisterWithWindowsHelloRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                DeviceName(),
                EncryptedRequest(),
                InfoRequestParameters(NULL),
                PlayerSecret(),
                PublicKey(),
                TitleId(),
                UserName()
            {}

            RegisterWithWindowsHelloRequest(const RegisterWithWindowsHelloRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                DeviceName(src.DeviceName),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : NULL),
                PlayerSecret(src.PlayerSecret),
                PublicKey(src.PublicKey),
                TitleId(src.TitleId),
                UserName(src.UserName)
            {}

            RegisterWithWindowsHelloRequest(const rapidjson::Value& obj) : RegisterWithWindowsHelloRequest()
            {
                readFromValue(obj);
            }

            ~RegisterWithWindowsHelloRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveContactEmailRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;

            RemoveContactEmailRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            RemoveContactEmailRequest(const RemoveContactEmailRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
            {}

            RemoveContactEmailRequest(const rapidjson::Value& obj) : RemoveContactEmailRequest()
            {
                readFromValue(obj);
            }

            ~RemoveContactEmailRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveContactEmailResult : public PlayFabBaseModel
        {

            RemoveContactEmailResult() :
                PlayFabBaseModel()
            {}

            RemoveContactEmailResult(const RemoveContactEmailResult& src) :
                PlayFabBaseModel()
            {}

            RemoveContactEmailResult(const rapidjson::Value& obj) : RemoveContactEmailResult()
            {
                readFromValue(obj);
            }

            ~RemoveContactEmailResult();

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

        struct RemoveGenericIDRequest : public PlayFabBaseModel
        {
            GenericServiceId GenericId;

            RemoveGenericIDRequest() :
                PlayFabBaseModel(),
                GenericId()
            {}

            RemoveGenericIDRequest(const RemoveGenericIDRequest& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId)
            {}

            RemoveGenericIDRequest(const rapidjson::Value& obj) : RemoveGenericIDRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGenericIDRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveGenericIDResult : public PlayFabBaseModel
        {

            RemoveGenericIDResult() :
                PlayFabBaseModel()
            {}

            RemoveGenericIDResult(const RemoveGenericIDResult& src) :
                PlayFabBaseModel()
            {}

            RemoveGenericIDResult(const rapidjson::Value& obj) : RemoveGenericIDResult()
            {
                readFromValue(obj);
            }

            ~RemoveGenericIDResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveSharedGroupMembersRequest : public PlayFabBaseModel
        {
            std::list<std::string> PlayFabIds;
            std::string SharedGroupId;

            RemoveSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                SharedGroupId()
            {}

            RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
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

        struct ReportAdActivityRequest : public PlayFabBaseModel
        {
            AdActivity Activity;
            std::map<std::string, std::string> CustomTags;
            std::string PlacementId;
            std::string RewardId;

            ReportAdActivityRequest() :
                PlayFabBaseModel(),
                Activity(),
                CustomTags(),
                PlacementId(),
                RewardId()
            {}

            ReportAdActivityRequest(const ReportAdActivityRequest& src) :
                PlayFabBaseModel(),
                Activity(src.Activity),
                CustomTags(src.CustomTags),
                PlacementId(src.PlacementId),
                RewardId(src.RewardId)
            {}

            ReportAdActivityRequest(const rapidjson::Value& obj) : ReportAdActivityRequest()
            {
                readFromValue(obj);
            }

            ~ReportAdActivityRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ReportAdActivityResult : public PlayFabBaseModel
        {

            ReportAdActivityResult() :
                PlayFabBaseModel()
            {}

            ReportAdActivityResult(const ReportAdActivityResult& src) :
                PlayFabBaseModel()
            {}

            ReportAdActivityResult(const rapidjson::Value& obj) : ReportAdActivityResult()
            {
                readFromValue(obj);
            }

            ~ReportAdActivityResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ReportPlayerClientRequest : public PlayFabBaseModel
        {
            std::string Comment;
            std::map<std::string, std::string> CustomTags;
            std::string ReporteeId;

            ReportPlayerClientRequest() :
                PlayFabBaseModel(),
                Comment(),
                CustomTags(),
                ReporteeId()
            {}

            ReportPlayerClientRequest(const ReportPlayerClientRequest& src) :
                PlayFabBaseModel(),
                Comment(src.Comment),
                CustomTags(src.CustomTags),
                ReporteeId(src.ReporteeId)
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
            Int32 SubmissionsRemaining;

            ReportPlayerClientResult() :
                PlayFabBaseModel(),
                SubmissionsRemaining(0)
            {}

            ReportPlayerClientResult(const ReportPlayerClientResult& src) :
                PlayFabBaseModel(),
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
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomTags;
            std::string ReceiptData;

            RestoreIOSPurchasesRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CustomTags(),
                ReceiptData()
            {}

            RestoreIOSPurchasesRequest(const RestoreIOSPurchasesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
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
            std::list<PurchaseReceiptFulfillment> Fulfillments;

            RestoreIOSPurchasesResult() :
                PlayFabBaseModel(),
                Fulfillments()
            {}

            RestoreIOSPurchasesResult(const RestoreIOSPurchasesResult& src) :
                PlayFabBaseModel(),
                Fulfillments(src.Fulfillments)
            {}

            RestoreIOSPurchasesResult(const rapidjson::Value& obj) : RestoreIOSPurchasesResult()
            {
                readFromValue(obj);
            }

            ~RestoreIOSPurchasesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RewardAdActivityRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string PlacementId;
            std::string RewardId;

            RewardAdActivityRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                PlacementId(),
                RewardId()
            {}

            RewardAdActivityRequest(const RewardAdActivityRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                PlacementId(src.PlacementId),
                RewardId(src.RewardId)
            {}

            RewardAdActivityRequest(const rapidjson::Value& obj) : RewardAdActivityRequest()
            {
                readFromValue(obj);
            }

            ~RewardAdActivityRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RewardAdActivityResult : public PlayFabBaseModel
        {
            std::string AdActivityEventId;
            std::list<std::string> DebugResults;
            std::string PlacementId;
            std::string PlacementName;
            OptionalInt32 PlacementViewsRemaining;
            OptionalDouble PlacementViewsResetMinutes;
            AdRewardResults* RewardResults;

            RewardAdActivityResult() :
                PlayFabBaseModel(),
                AdActivityEventId(),
                DebugResults(),
                PlacementId(),
                PlacementName(),
                PlacementViewsRemaining(),
                PlacementViewsResetMinutes(),
                RewardResults(NULL)
            {}

            RewardAdActivityResult(const RewardAdActivityResult& src) :
                PlayFabBaseModel(),
                AdActivityEventId(src.AdActivityEventId),
                DebugResults(src.DebugResults),
                PlacementId(src.PlacementId),
                PlacementName(src.PlacementName),
                PlacementViewsRemaining(src.PlacementViewsRemaining),
                PlacementViewsResetMinutes(src.PlacementViewsResetMinutes),
                RewardResults(src.RewardResults ? new AdRewardResults(*src.RewardResults) : NULL)
            {}

            RewardAdActivityResult(const rapidjson::Value& obj) : RewardAdActivityResult()
            {
                readFromValue(obj);
            }

            ~RewardAdActivityResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string Email;
            std::string EmailTemplateId;
            std::string TitleId;

            SendAccountRecoveryEmailRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Email(),
                EmailTemplateId(),
                TitleId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Email(src.Email),
                EmailTemplateId(src.EmailTemplateId),
                TitleId(src.TitleId)
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

        struct SetPlayerSecretRequest : public PlayFabBaseModel
        {
            std::string EncryptedRequest;
            std::string PlayerSecret;

            SetPlayerSecretRequest() :
                PlayFabBaseModel(),
                EncryptedRequest(),
                PlayerSecret()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabBaseModel(),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret)
            {}

            SetPlayerSecretRequest(const rapidjson::Value& obj) : SetPlayerSecretRequest()
            {
                readFromValue(obj);
            }

            ~SetPlayerSecretRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetPlayerSecretResult : public PlayFabBaseModel
        {

            SetPlayerSecretResult() :
                PlayFabBaseModel()
            {}

            SetPlayerSecretResult(const SetPlayerSecretResult& src) :
                PlayFabBaseModel()
            {}

            SetPlayerSecretResult(const rapidjson::Value& obj) : SetPlayerSecretResult()
            {
                readFromValue(obj);
            }

            ~SetPlayerSecretResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StartGameRequest : public PlayFabBaseModel
        {
            std::string BuildVersion;
            std::string CharacterId;
            std::string CustomCommandLineData;
            std::map<std::string, std::string> CustomTags;
            std::string GameMode;
            Region pfRegion;
            std::string StatisticName;

            StartGameRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                CharacterId(),
                CustomCommandLineData(),
                CustomTags(),
                GameMode(),
                pfRegion(),
                StatisticName()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                CharacterId(src.CharacterId),
                CustomCommandLineData(src.CustomCommandLineData),
                CustomTags(src.CustomTags),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion),
                StatisticName(src.StatisticName)
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
            std::string Expires;
            std::string LobbyID;
            std::string Password;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            OptionalInt32 ServerPort;
            std::string ServerPublicDNSName;
            std::string Ticket;

            StartGameResult() :
                PlayFabBaseModel(),
                Expires(),
                LobbyID(),
                Password(),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(),
                ServerPublicDNSName(),
                Ticket()
            {}

            StartGameResult(const StartGameResult& src) :
                PlayFabBaseModel(),
                Expires(src.Expires),
                LobbyID(src.LobbyID),
                Password(src.Password),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                Ticket(src.Ticket)
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
            std::map<std::string, std::string> CustomTags;
            std::list<ItemPurchaseRequest> Items;
            std::string StoreId;

            StartPurchaseRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CustomTags(),
                Items(),
                StoreId()
            {}

            StartPurchaseRequest(const StartPurchaseRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
                Items(src.Items),
                StoreId(src.StoreId)
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
            std::list<CartItem> Contents;
            std::string OrderId;
            std::list<PaymentOption> PaymentOptions;
            std::map<std::string, Int32> VirtualCurrencyBalances;

            StartPurchaseResult() :
                PlayFabBaseModel(),
                Contents(),
                OrderId(),
                PaymentOptions(),
                VirtualCurrencyBalances()
            {}

            StartPurchaseResult(const StartPurchaseResult& src) :
                PlayFabBaseModel(),
                Contents(src.Contents),
                OrderId(src.OrderId),
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
            Int32 Value;
            OptionalUint32 Version;

            StatisticUpdate() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version()
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
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
            Int32 Amount;
            std::map<std::string, std::string> CustomTags;
            std::string VirtualCurrency;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                CustomTags(),
                VirtualCurrency()
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                CustomTags(src.CustomTags),
                VirtualCurrency(src.VirtualCurrency)
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
            std::map<std::string, std::string> CustomTags;

            UnlinkAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDeviceId(),
                CustomTags()
            {}

            UnlinkAndroidDeviceIDRequest(const UnlinkAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId),
                CustomTags(src.CustomTags)
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

        struct UnlinkAppleRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;

            UnlinkAppleRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkAppleRequest(const UnlinkAppleRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
            {}

            UnlinkAppleRequest(const rapidjson::Value& obj) : UnlinkAppleRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkAppleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkCustomIDRequest : public PlayFabBaseModel
        {
            std::string CustomId;
            std::map<std::string, std::string> CustomTags;

            UnlinkCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId(),
                CustomTags()
            {}

            UnlinkCustomIDRequest(const UnlinkCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId),
                CustomTags(src.CustomTags)
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
            std::map<std::string, std::string> CustomTags;

            UnlinkFacebookAccountRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkFacebookAccountRequest(const UnlinkFacebookAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
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

        struct UnlinkFacebookInstantGamesIdRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string FacebookInstantGamesId;

            UnlinkFacebookInstantGamesIdRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                FacebookInstantGamesId()
            {}

            UnlinkFacebookInstantGamesIdRequest(const UnlinkFacebookInstantGamesIdRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                FacebookInstantGamesId(src.FacebookInstantGamesId)
            {}

            UnlinkFacebookInstantGamesIdRequest(const rapidjson::Value& obj) : UnlinkFacebookInstantGamesIdRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkFacebookInstantGamesIdRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkFacebookInstantGamesIdResult : public PlayFabBaseModel
        {

            UnlinkFacebookInstantGamesIdResult() :
                PlayFabBaseModel()
            {}

            UnlinkFacebookInstantGamesIdResult(const UnlinkFacebookInstantGamesIdResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkFacebookInstantGamesIdResult(const rapidjson::Value& obj) : UnlinkFacebookInstantGamesIdResult()
            {
                readFromValue(obj);
            }

            ~UnlinkFacebookInstantGamesIdResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkGameCenterAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;

            UnlinkGameCenterAccountRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkGameCenterAccountRequest(const UnlinkGameCenterAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
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
            std::map<std::string, std::string> CustomTags;

            UnlinkGoogleAccountRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkGoogleAccountRequest(const UnlinkGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
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
            std::map<std::string, std::string> CustomTags;
            std::string DeviceId;

            UnlinkIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                DeviceId()
            {}

            UnlinkIOSDeviceIDRequest(const UnlinkIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
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
            std::map<std::string, std::string> CustomTags;

            UnlinkKongregateAccountRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkKongregateAccountRequest(const UnlinkKongregateAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
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

        struct UnlinkNintendoServiceAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;

            UnlinkNintendoServiceAccountRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkNintendoServiceAccountRequest(const UnlinkNintendoServiceAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
            {}

            UnlinkNintendoServiceAccountRequest(const rapidjson::Value& obj) : UnlinkNintendoServiceAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkNintendoServiceAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkNintendoSwitchDeviceIdRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string NintendoSwitchDeviceId;

            UnlinkNintendoSwitchDeviceIdRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                NintendoSwitchDeviceId()
            {}

            UnlinkNintendoSwitchDeviceIdRequest(const UnlinkNintendoSwitchDeviceIdRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                NintendoSwitchDeviceId(src.NintendoSwitchDeviceId)
            {}

            UnlinkNintendoSwitchDeviceIdRequest(const rapidjson::Value& obj) : UnlinkNintendoSwitchDeviceIdRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkNintendoSwitchDeviceIdRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkNintendoSwitchDeviceIdResult : public PlayFabBaseModel
        {

            UnlinkNintendoSwitchDeviceIdResult() :
                PlayFabBaseModel()
            {}

            UnlinkNintendoSwitchDeviceIdResult(const UnlinkNintendoSwitchDeviceIdResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkNintendoSwitchDeviceIdResult(const rapidjson::Value& obj) : UnlinkNintendoSwitchDeviceIdResult()
            {
                readFromValue(obj);
            }

            ~UnlinkNintendoSwitchDeviceIdResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkOpenIdConnectRequest : public PlayFabBaseModel
        {
            std::string ConnectionId;
            std::map<std::string, std::string> CustomTags;

            UnlinkOpenIdConnectRequest() :
                PlayFabBaseModel(),
                ConnectionId(),
                CustomTags()
            {}

            UnlinkOpenIdConnectRequest(const UnlinkOpenIdConnectRequest& src) :
                PlayFabBaseModel(),
                ConnectionId(src.ConnectionId),
                CustomTags(src.CustomTags)
            {}

            UnlinkOpenIdConnectRequest(const rapidjson::Value& obj) : UnlinkOpenIdConnectRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkOpenIdConnectRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkPSNAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;

            UnlinkPSNAccountRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkPSNAccountRequest(const UnlinkPSNAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
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
            std::map<std::string, std::string> CustomTags;

            UnlinkSteamAccountRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkSteamAccountRequest(const UnlinkSteamAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
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

        struct UnlinkTwitchAccountRequest : public PlayFabBaseModel
        {
            std::string AccessToken;
            std::map<std::string, std::string> CustomTags;

            UnlinkTwitchAccountRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CustomTags()
            {}

            UnlinkTwitchAccountRequest(const UnlinkTwitchAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CustomTags(src.CustomTags)
            {}

            UnlinkTwitchAccountRequest(const rapidjson::Value& obj) : UnlinkTwitchAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkTwitchAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkTwitchAccountResult : public PlayFabBaseModel
        {

            UnlinkTwitchAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountResult(const UnlinkTwitchAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountResult(const rapidjson::Value& obj) : UnlinkTwitchAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkTwitchAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkWindowsHelloAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string PublicKeyHint;

            UnlinkWindowsHelloAccountRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                PublicKeyHint()
            {}

            UnlinkWindowsHelloAccountRequest(const UnlinkWindowsHelloAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                PublicKeyHint(src.PublicKeyHint)
            {}

            UnlinkWindowsHelloAccountRequest(const rapidjson::Value& obj) : UnlinkWindowsHelloAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkWindowsHelloAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkWindowsHelloAccountResponse : public PlayFabBaseModel
        {

            UnlinkWindowsHelloAccountResponse() :
                PlayFabBaseModel()
            {}

            UnlinkWindowsHelloAccountResponse(const UnlinkWindowsHelloAccountResponse& src) :
                PlayFabBaseModel()
            {}

            UnlinkWindowsHelloAccountResponse(const rapidjson::Value& obj) : UnlinkWindowsHelloAccountResponse()
            {
                readFromValue(obj);
            }

            ~UnlinkWindowsHelloAccountResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlinkXboxAccountRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;

            UnlinkXboxAccountRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            UnlinkXboxAccountRequest(const UnlinkXboxAccountRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
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

        struct UnlockContainerInstanceRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemInstanceId;
            std::map<std::string, std::string> CustomTags;
            std::string KeyItemInstanceId;

            UnlockContainerInstanceRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemInstanceId(),
                CustomTags(),
                KeyItemInstanceId()
            {}

            UnlockContainerInstanceRequest(const UnlockContainerInstanceRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemInstanceId(src.ContainerItemInstanceId),
                CustomTags(src.CustomTags),
                KeyItemInstanceId(src.KeyItemInstanceId)
            {}

            UnlockContainerInstanceRequest(const rapidjson::Value& obj) : UnlockContainerInstanceRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerInstanceRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UnlockContainerItemRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemId;
            std::map<std::string, std::string> CustomTags;

            UnlockContainerItemRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemId(),
                CustomTags()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemId(src.ContainerItemId),
                CustomTags(src.CustomTags)
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
            std::list<ItemInstance> GrantedItems;
            std::string UnlockedItemInstanceId;
            std::string UnlockedWithItemInstanceId;
            std::map<std::string, Uint32> VirtualCurrency;

            UnlockContainerItemResult() :
                PlayFabBaseModel(),
                GrantedItems(),
                UnlockedItemInstanceId(),
                UnlockedWithItemInstanceId(),
                VirtualCurrency()
            {}

            UnlockContainerItemResult(const UnlockContainerItemResult& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems),
                UnlockedItemInstanceId(src.UnlockedItemInstanceId),
                UnlockedWithItemInstanceId(src.UnlockedWithItemInstanceId),
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

        struct UpdateAvatarUrlRequest : public PlayFabBaseModel
        {
            std::string ImageUrl;

            UpdateAvatarUrlRequest() :
                PlayFabBaseModel(),
                ImageUrl()
            {}

            UpdateAvatarUrlRequest(const UpdateAvatarUrlRequest& src) :
                PlayFabBaseModel(),
                ImageUrl(src.ImageUrl)
            {}

            UpdateAvatarUrlRequest(const rapidjson::Value& obj) : UpdateAvatarUrlRequest()
            {
                readFromValue(obj);
            }

            ~UpdateAvatarUrlRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCharacterDataRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateCharacterDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CustomTags(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CustomTags(src.CustomTags),
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

        struct UpdateCharacterStatisticsRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::map<std::string, Int32> CharacterStatistics;
            std::map<std::string, std::string> CustomTags;

            UpdateCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterStatistics(),
                CustomTags()
            {}

            UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics),
                CustomTags(src.CustomTags)
            {}

            UpdateCharacterStatisticsRequest(const rapidjson::Value& obj) : UpdateCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCharacterStatisticsResult : public PlayFabBaseModel
        {

            UpdateCharacterStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdateCharacterStatisticsResult(const UpdateCharacterStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateCharacterStatisticsResult(const rapidjson::Value& obj) : UpdateCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerStatisticsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::list<StatisticUpdate> Statistics;

            UpdatePlayerStatisticsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Statistics()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
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
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string SharedGroupId;

            UpdateSharedGroupDataRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Data(),
                KeysToRemove(),
                Permission(),
                SharedGroupId()
            {}

            UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                SharedGroupId(src.SharedGroupId)
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
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
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

        struct UpdateUserTitleDisplayNameRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
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
            std::string CatalogVersion;
            std::string CurrencyCode;
            std::map<std::string, std::string> CustomTags;
            Int32 PurchasePrice;
            std::string ReceiptId;
            std::string UserId;

            ValidateAmazonReceiptRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CurrencyCode(),
                CustomTags(),
                PurchasePrice(0),
                ReceiptId(),
                UserId()
            {}

            ValidateAmazonReceiptRequest(const ValidateAmazonReceiptRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                CustomTags(src.CustomTags),
                PurchasePrice(src.PurchasePrice),
                ReceiptId(src.ReceiptId),
                UserId(src.UserId)
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
            std::list<PurchaseReceiptFulfillment> Fulfillments;

            ValidateAmazonReceiptResult() :
                PlayFabBaseModel(),
                Fulfillments()
            {}

            ValidateAmazonReceiptResult(const ValidateAmazonReceiptResult& src) :
                PlayFabBaseModel(),
                Fulfillments(src.Fulfillments)
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
            std::string CatalogVersion;
            std::string CurrencyCode;
            std::map<std::string, std::string> CustomTags;
            OptionalUint32 PurchasePrice;
            std::string ReceiptJson;
            std::string Signature;

            ValidateGooglePlayPurchaseRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CurrencyCode(),
                CustomTags(),
                PurchasePrice(),
                ReceiptJson(),
                Signature()
            {}

            ValidateGooglePlayPurchaseRequest(const ValidateGooglePlayPurchaseRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                CustomTags(src.CustomTags),
                PurchasePrice(src.PurchasePrice),
                ReceiptJson(src.ReceiptJson),
                Signature(src.Signature)
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
            std::list<PurchaseReceiptFulfillment> Fulfillments;

            ValidateGooglePlayPurchaseResult() :
                PlayFabBaseModel(),
                Fulfillments()
            {}

            ValidateGooglePlayPurchaseResult(const ValidateGooglePlayPurchaseResult& src) :
                PlayFabBaseModel(),
                Fulfillments(src.Fulfillments)
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
            std::string CatalogVersion;
            std::string CurrencyCode;
            std::map<std::string, std::string> CustomTags;
            Int32 PurchasePrice;
            std::string ReceiptData;

            ValidateIOSReceiptRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CurrencyCode(),
                CustomTags(),
                PurchasePrice(0),
                ReceiptData()
            {}

            ValidateIOSReceiptRequest(const ValidateIOSReceiptRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                CustomTags(src.CustomTags),
                PurchasePrice(src.PurchasePrice),
                ReceiptData(src.ReceiptData)
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
            std::list<PurchaseReceiptFulfillment> Fulfillments;

            ValidateIOSReceiptResult() :
                PlayFabBaseModel(),
                Fulfillments()
            {}

            ValidateIOSReceiptResult(const ValidateIOSReceiptResult& src) :
                PlayFabBaseModel(),
                Fulfillments(src.Fulfillments)
            {}

            ValidateIOSReceiptResult(const rapidjson::Value& obj) : ValidateIOSReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateIOSReceiptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateWindowsReceiptRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string CurrencyCode;
            std::map<std::string, std::string> CustomTags;
            Uint32 PurchasePrice;
            std::string Receipt;

            ValidateWindowsReceiptRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CurrencyCode(),
                CustomTags(),
                PurchasePrice(0),
                Receipt()
            {}

            ValidateWindowsReceiptRequest(const ValidateWindowsReceiptRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                CustomTags(src.CustomTags),
                PurchasePrice(src.PurchasePrice),
                Receipt(src.Receipt)
            {}

            ValidateWindowsReceiptRequest(const rapidjson::Value& obj) : ValidateWindowsReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateWindowsReceiptRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ValidateWindowsReceiptResult : public PlayFabBaseModel
        {
            std::list<PurchaseReceiptFulfillment> Fulfillments;

            ValidateWindowsReceiptResult() :
                PlayFabBaseModel(),
                Fulfillments()
            {}

            ValidateWindowsReceiptResult(const ValidateWindowsReceiptResult& src) :
                PlayFabBaseModel(),
                Fulfillments(src.Fulfillments)
            {}

            ValidateWindowsReceiptResult(const rapidjson::Value& obj) : ValidateWindowsReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateWindowsReceiptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteClientCharacterEventRequest : public PlayFabBaseModel
        {
            std::map<std::string, MultitypeVar> Body;
            std::string CharacterId;
            std::map<std::string, std::string> CustomTags;
            std::string EventName;
            OptionalTime Timestamp;

            WriteClientCharacterEventRequest() :
                PlayFabBaseModel(),
                Body(),
                CharacterId(),
                CustomTags(),
                EventName(),
                Timestamp()
            {}

            WriteClientCharacterEventRequest(const WriteClientCharacterEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                CharacterId(src.CharacterId),
                CustomTags(src.CustomTags),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            WriteClientCharacterEventRequest(const rapidjson::Value& obj) : WriteClientCharacterEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteClientCharacterEventRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteClientPlayerEventRequest : public PlayFabBaseModel
        {
            std::map<std::string, MultitypeVar> Body;
            std::map<std::string, std::string> CustomTags;
            std::string EventName;
            OptionalTime Timestamp;

            WriteClientPlayerEventRequest() :
                PlayFabBaseModel(),
                Body(),
                CustomTags(),
                EventName(),
                Timestamp()
            {}

            WriteClientPlayerEventRequest(const WriteClientPlayerEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                CustomTags(src.CustomTags),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            WriteClientPlayerEventRequest(const rapidjson::Value& obj) : WriteClientPlayerEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteClientPlayerEventRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteEventResponse : public PlayFabBaseModel
        {
            std::string EventId;

            WriteEventResponse() :
                PlayFabBaseModel(),
                EventId()
            {}

            WriteEventResponse(const WriteEventResponse& src) :
                PlayFabBaseModel(),
                EventId(src.EventId)
            {}

            WriteEventResponse(const rapidjson::Value& obj) : WriteEventResponse()
            {
                readFromValue(obj);
            }

            ~WriteEventResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteTitleEventRequest : public PlayFabBaseModel
        {
            std::map<std::string, MultitypeVar> Body;
            std::map<std::string, std::string> CustomTags;
            std::string EventName;
            OptionalTime Timestamp;

            WriteTitleEventRequest() :
                PlayFabBaseModel(),
                Body(),
                CustomTags(),
                EventName(),
                Timestamp()
            {}

            WriteTitleEventRequest(const WriteTitleEventRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                CustomTags(src.CustomTags),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            WriteTitleEventRequest(const rapidjson::Value& obj) : WriteTitleEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteTitleEventRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
