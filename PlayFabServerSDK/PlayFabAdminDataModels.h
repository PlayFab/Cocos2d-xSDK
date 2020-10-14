#ifndef PLAYFAB_ADMIN_DATA_MODELS_H_
#define PLAYFAB_ADMIN_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace AdminModels
    {
        struct AbortTaskInstanceRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string TaskInstanceId;

            AbortTaskInstanceRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                TaskInstanceId()
            {}

            AbortTaskInstanceRequest(const AbortTaskInstanceRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                TaskInstanceId(src.TaskInstanceId)
            {}

            AbortTaskInstanceRequest(const rapidjson::Value& obj) : AbortTaskInstanceRequest()
            {
                readFromValue(obj);
            }

            ~AbortTaskInstanceRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ActionsOnPlayersInSegmentTaskParameter : public PlayFabBaseModel
        {
            std::string ActionId;
            std::string SegmentId;

            ActionsOnPlayersInSegmentTaskParameter() :
                PlayFabBaseModel(),
                ActionId(),
                SegmentId()
            {}

            ActionsOnPlayersInSegmentTaskParameter(const ActionsOnPlayersInSegmentTaskParameter& src) :
                PlayFabBaseModel(),
                ActionId(src.ActionId),
                SegmentId(src.SegmentId)
            {}

            ActionsOnPlayersInSegmentTaskParameter(const rapidjson::Value& obj) : ActionsOnPlayersInSegmentTaskParameter()
            {
                readFromValue(obj);
            }

            ~ActionsOnPlayersInSegmentTaskParameter();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum TaskInstanceStatus
        {
            TaskInstanceStatusSucceeded,
            TaskInstanceStatusStarting,
            TaskInstanceStatusInProgress,
            TaskInstanceStatusFailed,
            TaskInstanceStatusAborted,
            TaskInstanceStatusStalled
        };

        void writeTaskInstanceStatusEnumJSON(TaskInstanceStatus enumVal, PFStringJsonWriter& writer);
        TaskInstanceStatus readTaskInstanceStatusFromValue(const rapidjson::Value& obj);

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

        struct ActionsOnPlayersInSegmentTaskSummary : public PlayFabBaseModel
        {
            OptionalTime CompletedAt;
            std::string ErrorMessage;
            OptionalBool ErrorWasFatal;
            OptionalDouble EstimatedSecondsRemaining;
            OptionalDouble PercentComplete;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            NameIdentifier* TaskIdentifier;
            std::string TaskInstanceId;
            OptionalInt32 TotalPlayersInSegment;
            OptionalInt32 TotalPlayersProcessed;

            ActionsOnPlayersInSegmentTaskSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                ErrorMessage(),
                ErrorWasFatal(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                ScheduledByUserId(),
                StartedAt(0),
                Status(),
                TaskIdentifier(NULL),
                TaskInstanceId(),
                TotalPlayersInSegment(),
                TotalPlayersProcessed()
            {}

            ActionsOnPlayersInSegmentTaskSummary(const ActionsOnPlayersInSegmentTaskSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                ErrorMessage(src.ErrorMessage),
                ErrorWasFatal(src.ErrorWasFatal),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : NULL),
                TaskInstanceId(src.TaskInstanceId),
                TotalPlayersInSegment(src.TotalPlayersInSegment),
                TotalPlayersProcessed(src.TotalPlayersProcessed)
            {}

            ActionsOnPlayersInSegmentTaskSummary(const rapidjson::Value& obj) : ActionsOnPlayersInSegmentTaskSummary()
            {
                readFromValue(obj);
            }

            ~ActionsOnPlayersInSegmentTaskSummary();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AdCampaignAttribution : public PlayFabBaseModel
        {
            time_t AttributedAt;
            std::string CampaignId;
            std::string Platform;

            AdCampaignAttribution() :
                PlayFabBaseModel(),
                AttributedAt(0),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttribution(const AdCampaignAttribution& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            AdCampaignAttribution(const rapidjson::Value& obj) : AdCampaignAttribution()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttribution();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

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

        struct AddLocalizedNewsRequest : public PlayFabBaseModel
        {
            std::string Body;
            std::map<std::string, std::string> CustomTags;
            std::string Language;
            std::string NewsId;
            std::string Title;

            AddLocalizedNewsRequest() :
                PlayFabBaseModel(),
                Body(),
                CustomTags(),
                Language(),
                NewsId(),
                Title()
            {}

            AddLocalizedNewsRequest(const AddLocalizedNewsRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                CustomTags(src.CustomTags),
                Language(src.Language),
                NewsId(src.NewsId),
                Title(src.Title)
            {}

            AddLocalizedNewsRequest(const rapidjson::Value& obj) : AddLocalizedNewsRequest()
            {
                readFromValue(obj);
            }

            ~AddLocalizedNewsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddLocalizedNewsResult : public PlayFabBaseModel
        {

            AddLocalizedNewsResult() :
                PlayFabBaseModel()
            {}

            AddLocalizedNewsResult(const AddLocalizedNewsResult& src) :
                PlayFabBaseModel()
            {}

            AddLocalizedNewsResult(const rapidjson::Value& obj) : AddLocalizedNewsResult()
            {
                readFromValue(obj);
            }

            ~AddLocalizedNewsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddNewsRequest : public PlayFabBaseModel
        {
            std::string Body;
            std::map<std::string, std::string> CustomTags;
            OptionalTime Timestamp;
            std::string Title;

            AddNewsRequest() :
                PlayFabBaseModel(),
                Body(),
                CustomTags(),
                Timestamp(),
                Title()
            {}

            AddNewsRequest(const AddNewsRequest& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                CustomTags(src.CustomTags),
                Timestamp(src.Timestamp),
                Title(src.Title)
            {}

            AddNewsRequest(const rapidjson::Value& obj) : AddNewsRequest()
            {
                readFromValue(obj);
            }

            ~AddNewsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddNewsResult : public PlayFabBaseModel
        {
            std::string NewsId;

            AddNewsResult() :
                PlayFabBaseModel(),
                NewsId()
            {}

            AddNewsResult(const AddNewsResult& src) :
                PlayFabBaseModel(),
                NewsId(src.NewsId)
            {}

            AddNewsResult(const rapidjson::Value& obj) : AddNewsResult()
            {
                readFromValue(obj);
            }

            ~AddNewsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddPlayerTagRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string PlayFabId;
            std::string TagName;

            AddPlayerTagRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                PlayFabId(),
                TagName()
            {}

            AddPlayerTagRequest(const AddPlayerTagRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            AddPlayerTagRequest(const rapidjson::Value& obj) : AddPlayerTagRequest()
            {
                readFromValue(obj);
            }

            ~AddPlayerTagRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddPlayerTagResult : public PlayFabBaseModel
        {

            AddPlayerTagResult() :
                PlayFabBaseModel()
            {}

            AddPlayerTagResult(const AddPlayerTagResult& src) :
                PlayFabBaseModel()
            {}

            AddPlayerTagResult(const rapidjson::Value& obj) : AddPlayerTagResult()
            {
                readFromValue(obj);
            }

            ~AddPlayerTagResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

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

        struct AddServerBuildRequest : public PlayFabBaseModel
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::map<std::string, std::string> CustomTags;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;

            AddServerBuildRequest() :
                PlayFabBaseModel(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                CustomTags(),
                ExecutablePath(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0)
            {}

            AddServerBuildRequest(const AddServerBuildRequest& src) :
                PlayFabBaseModel(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                CustomTags(src.CustomTags),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots)
            {}

            AddServerBuildRequest(const rapidjson::Value& obj) : AddServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~AddServerBuildRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum GameBuildStatus
        {
            GameBuildStatusAvailable,
            GameBuildStatusValidating,
            GameBuildStatusInvalidBuildPackage,
            GameBuildStatusProcessing,
            GameBuildStatusFailedToProcess
        };

        void writeGameBuildStatusEnumJSON(GameBuildStatus enumVal, PFStringJsonWriter& writer);
        GameBuildStatus readGameBuildStatusFromValue(const rapidjson::Value& obj);

        struct AddServerBuildResult : public PlayFabBaseModel
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            AddServerBuildResult() :
                PlayFabBaseModel(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                Status(),
                Timestamp(0),
                TitleId()
            {}

            AddServerBuildResult(const AddServerBuildResult& src) :
                PlayFabBaseModel(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            AddServerBuildResult(const rapidjson::Value& obj) : AddServerBuildResult()
            {
                readFromValue(obj);
            }

            ~AddServerBuildResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Int32 Amount;
            std::map<std::string, std::string> CustomTags;
            std::string PlayFabId;
            std::string VirtualCurrency;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                CustomTags(),
                PlayFabId(),
                VirtualCurrency()
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId),
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

        struct VirtualCurrencyData : public PlayFabBaseModel
        {
            std::string CurrencyCode;
            std::string DisplayName;
            OptionalInt32 InitialDeposit;
            OptionalInt32 RechargeMax;
            OptionalInt32 RechargeRate;

            VirtualCurrencyData() :
                PlayFabBaseModel(),
                CurrencyCode(),
                DisplayName(),
                InitialDeposit(),
                RechargeMax(),
                RechargeRate()
            {}

            VirtualCurrencyData(const VirtualCurrencyData& src) :
                PlayFabBaseModel(),
                CurrencyCode(src.CurrencyCode),
                DisplayName(src.DisplayName),
                InitialDeposit(src.InitialDeposit),
                RechargeMax(src.RechargeMax),
                RechargeRate(src.RechargeRate)
            {}

            VirtualCurrencyData(const rapidjson::Value& obj) : VirtualCurrencyData()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyData();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddVirtualCurrencyTypesRequest : public PlayFabBaseModel
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            AddVirtualCurrencyTypesRequest() :
                PlayFabBaseModel(),
                VirtualCurrencies()
            {}

            AddVirtualCurrencyTypesRequest(const AddVirtualCurrencyTypesRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            AddVirtualCurrencyTypesRequest(const rapidjson::Value& obj) : AddVirtualCurrencyTypesRequest()
            {
                readFromValue(obj);
            }

            ~AddVirtualCurrencyTypesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum Conditionals
        {
            ConditionalsAny,
            ConditionalsTrue,
            ConditionalsFalse
        };

        void writeConditionalsEnumJSON(Conditionals enumVal, PFStringJsonWriter& writer);
        Conditionals readConditionalsFromValue(const rapidjson::Value& obj);

        struct ApiCondition : public PlayFabBaseModel
        {
            Boxed<Conditionals> HasSignatureOrEncryption;

            ApiCondition() :
                PlayFabBaseModel(),
                HasSignatureOrEncryption()
            {}

            ApiCondition(const ApiCondition& src) :
                PlayFabBaseModel(),
                HasSignatureOrEncryption(src.HasSignatureOrEncryption)
            {}

            ApiCondition(const rapidjson::Value& obj) : ApiCondition()
            {
                readFromValue(obj);
            }

            ~ApiCondition();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum AuthTokenType
        {
            AuthTokenTypeEmail
        };

        void writeAuthTokenTypeEnumJSON(AuthTokenType enumVal, PFStringJsonWriter& writer);
        AuthTokenType readAuthTokenTypeFromValue(const rapidjson::Value& obj);

        struct BanInfo : public PlayFabBaseModel
        {
            bool Active;
            std::string BanId;
            OptionalTime Created;
            OptionalTime Expires;
            std::string IPAddress;
            std::string MACAddress;
            std::string PlayFabId;
            std::string Reason;

            BanInfo() :
                PlayFabBaseModel(),
                Active(false),
                BanId(),
                Created(),
                Expires(),
                IPAddress(),
                MACAddress(),
                PlayFabId(),
                Reason()
            {}

            BanInfo(const BanInfo& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                BanId(src.BanId),
                Created(src.Created),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            BanInfo(const rapidjson::Value& obj) : BanInfo()
            {
                readFromValue(obj);
            }

            ~BanInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BanRequest : public PlayFabBaseModel
        {
            OptionalUint32 DurationInHours;
            std::string IPAddress;
            std::string MACAddress;
            std::string PlayFabId;
            std::string Reason;

            BanRequest() :
                PlayFabBaseModel(),
                DurationInHours(),
                IPAddress(),
                MACAddress(),
                PlayFabId(),
                Reason()
            {}

            BanRequest(const BanRequest& src) :
                PlayFabBaseModel(),
                DurationInHours(src.DurationInHours),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            BanRequest(const rapidjson::Value& obj) : BanRequest()
            {
                readFromValue(obj);
            }

            ~BanRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BanUsersRequest : public PlayFabBaseModel
        {
            std::list<BanRequest> Bans;
            std::map<std::string, std::string> CustomTags;

            BanUsersRequest() :
                PlayFabBaseModel(),
                Bans(),
                CustomTags()
            {}

            BanUsersRequest(const BanUsersRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans),
                CustomTags(src.CustomTags)
            {}

            BanUsersRequest(const rapidjson::Value& obj) : BanUsersRequest()
            {
                readFromValue(obj);
            }

            ~BanUsersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BanUsersResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            BanUsersResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            BanUsersResult(const BanUsersResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            BanUsersResult(const rapidjson::Value& obj) : BanUsersResult()
            {
                readFromValue(obj);
            }

            ~BanUsersResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BlankResult : public PlayFabBaseModel
        {

            BlankResult() :
                PlayFabBaseModel()
            {}

            BlankResult(const BlankResult& src) :
                PlayFabBaseModel()
            {}

            BlankResult(const rapidjson::Value& obj) : BlankResult()
            {
                readFromValue(obj);
            }

            ~BlankResult();

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

        struct CheckLimitedEditionItemAvailabilityRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string ItemId;

            CheckLimitedEditionItemAvailabilityRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                ItemId()
            {}

            CheckLimitedEditionItemAvailabilityRequest(const CheckLimitedEditionItemAvailabilityRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                ItemId(src.ItemId)
            {}

            CheckLimitedEditionItemAvailabilityRequest(const rapidjson::Value& obj) : CheckLimitedEditionItemAvailabilityRequest()
            {
                readFromValue(obj);
            }

            ~CheckLimitedEditionItemAvailabilityRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CheckLimitedEditionItemAvailabilityResult : public PlayFabBaseModel
        {
            Int32 Amount;

            CheckLimitedEditionItemAvailabilityResult() :
                PlayFabBaseModel(),
                Amount(0)
            {}

            CheckLimitedEditionItemAvailabilityResult(const CheckLimitedEditionItemAvailabilityResult& src) :
                PlayFabBaseModel(),
                Amount(src.Amount)
            {}

            CheckLimitedEditionItemAvailabilityResult(const rapidjson::Value& obj) : CheckLimitedEditionItemAvailabilityResult()
            {
                readFromValue(obj);
            }

            ~CheckLimitedEditionItemAvailabilityResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CloudScriptFile : public PlayFabBaseModel
        {
            std::string FileContents;
            std::string Filename;

            CloudScriptFile() :
                PlayFabBaseModel(),
                FileContents(),
                Filename()
            {}

            CloudScriptFile(const CloudScriptFile& src) :
                PlayFabBaseModel(),
                FileContents(src.FileContents),
                Filename(src.Filename)
            {}

            CloudScriptFile(const rapidjson::Value& obj) : CloudScriptFile()
            {
                readFromValue(obj);
            }

            ~CloudScriptFile();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CloudScriptTaskParameter : public PlayFabBaseModel
        {
            MultitypeVar Argument;
            std::string FunctionName;

            CloudScriptTaskParameter() :
                PlayFabBaseModel(),
                Argument(),
                FunctionName()
            {}

            CloudScriptTaskParameter(const CloudScriptTaskParameter& src) :
                PlayFabBaseModel(),
                Argument(src.Argument),
                FunctionName(src.FunctionName)
            {}

            CloudScriptTaskParameter(const rapidjson::Value& obj) : CloudScriptTaskParameter()
            {
                readFromValue(obj);
            }

            ~CloudScriptTaskParameter();

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

        struct CloudScriptTaskSummary : public PlayFabBaseModel
        {
            OptionalTime CompletedAt;
            OptionalDouble EstimatedSecondsRemaining;
            OptionalDouble PercentComplete;
            ExecuteCloudScriptResult* Result;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            NameIdentifier* TaskIdentifier;
            std::string TaskInstanceId;

            CloudScriptTaskSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                Result(NULL),
                ScheduledByUserId(),
                StartedAt(0),
                Status(),
                TaskIdentifier(NULL),
                TaskInstanceId()
            {}

            CloudScriptTaskSummary(const CloudScriptTaskSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                Result(src.Result ? new ExecuteCloudScriptResult(*src.Result) : NULL),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : NULL),
                TaskInstanceId(src.TaskInstanceId)
            {}

            CloudScriptTaskSummary(const rapidjson::Value& obj) : CloudScriptTaskSummary()
            {
                readFromValue(obj);
            }

            ~CloudScriptTaskSummary();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CloudScriptVersionStatus : public PlayFabBaseModel
        {
            Int32 LatestRevision;
            Int32 PublishedRevision;
            Int32 Version;

            CloudScriptVersionStatus() :
                PlayFabBaseModel(),
                LatestRevision(0),
                PublishedRevision(0),
                Version(0)
            {}

            CloudScriptVersionStatus(const CloudScriptVersionStatus& src) :
                PlayFabBaseModel(),
                LatestRevision(src.LatestRevision),
                PublishedRevision(src.PublishedRevision),
                Version(src.Version)
            {}

            CloudScriptVersionStatus(const rapidjson::Value& obj) : CloudScriptVersionStatus()
            {
                readFromValue(obj);
            }

            ~CloudScriptVersionStatus();

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

        struct ContactEmailInfo : public PlayFabBaseModel
        {
            std::string EmailAddress;
            std::string Name;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfo() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name(),
                VerificationStatus()
            {}

            ContactEmailInfo(const ContactEmailInfo& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name),
                VerificationStatus(src.VerificationStatus)
            {}

            ContactEmailInfo(const rapidjson::Value& obj) : ContactEmailInfo()
            {
                readFromValue(obj);
            }

            ~ContactEmailInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

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

        struct ContentInfo : public PlayFabBaseModel
        {
            std::string Key;
            time_t LastModified;
            Uint32 Size;

            ContentInfo() :
                PlayFabBaseModel(),
                Key(),
                LastModified(0),
                Size(0)
            {}

            ContentInfo(const ContentInfo& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            ContentInfo(const rapidjson::Value& obj) : ContentInfo()
            {
                readFromValue(obj);
            }

            ~ContentInfo();

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

        struct CreateActionsOnPlayerSegmentTaskRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string Description;
            bool IsActive;
            std::string Name;
            ActionsOnPlayersInSegmentTaskParameter Parameter;
            std::string Schedule;

            CreateActionsOnPlayerSegmentTaskRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Description(),
                IsActive(false),
                Name(),
                Parameter(),
                Schedule()
            {}

            CreateActionsOnPlayerSegmentTaskRequest(const CreateActionsOnPlayerSegmentTaskRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Description(src.Description),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule)
            {}

            CreateActionsOnPlayerSegmentTaskRequest(const rapidjson::Value& obj) : CreateActionsOnPlayerSegmentTaskRequest()
            {
                readFromValue(obj);
            }

            ~CreateActionsOnPlayerSegmentTaskRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateCloudScriptTaskRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string Description;
            bool IsActive;
            std::string Name;
            CloudScriptTaskParameter Parameter;
            std::string Schedule;

            CreateCloudScriptTaskRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Description(),
                IsActive(false),
                Name(),
                Parameter(),
                Schedule()
            {}

            CreateCloudScriptTaskRequest(const CreateCloudScriptTaskRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Description(src.Description),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule)
            {}

            CreateCloudScriptTaskRequest(const rapidjson::Value& obj) : CreateCloudScriptTaskRequest()
            {
                readFromValue(obj);
            }

            ~CreateCloudScriptTaskRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsScalingTaskParameter : public PlayFabBaseModel
        {
            Int32 Level;

            InsightsScalingTaskParameter() :
                PlayFabBaseModel(),
                Level(0)
            {}

            InsightsScalingTaskParameter(const InsightsScalingTaskParameter& src) :
                PlayFabBaseModel(),
                Level(src.Level)
            {}

            InsightsScalingTaskParameter(const rapidjson::Value& obj) : InsightsScalingTaskParameter()
            {
                readFromValue(obj);
            }

            ~InsightsScalingTaskParameter();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateInsightsScheduledScalingTaskRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string Description;
            bool IsActive;
            std::string Name;
            InsightsScalingTaskParameter Parameter;
            std::string Schedule;

            CreateInsightsScheduledScalingTaskRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Description(),
                IsActive(false),
                Name(),
                Parameter(),
                Schedule()
            {}

            CreateInsightsScheduledScalingTaskRequest(const CreateInsightsScheduledScalingTaskRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Description(src.Description),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule)
            {}

            CreateInsightsScheduledScalingTaskRequest(const rapidjson::Value& obj) : CreateInsightsScheduledScalingTaskRequest()
            {
                readFromValue(obj);
            }

            ~CreateInsightsScheduledScalingTaskRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct OpenIdIssuerInformation : public PlayFabBaseModel
        {
            std::string AuthorizationUrl;
            std::string Issuer;
            MultitypeVar JsonWebKeySet;
            std::string TokenUrl;

            OpenIdIssuerInformation() :
                PlayFabBaseModel(),
                AuthorizationUrl(),
                Issuer(),
                JsonWebKeySet(),
                TokenUrl()
            {}

            OpenIdIssuerInformation(const OpenIdIssuerInformation& src) :
                PlayFabBaseModel(),
                AuthorizationUrl(src.AuthorizationUrl),
                Issuer(src.Issuer),
                JsonWebKeySet(src.JsonWebKeySet),
                TokenUrl(src.TokenUrl)
            {}

            OpenIdIssuerInformation(const rapidjson::Value& obj) : OpenIdIssuerInformation()
            {
                readFromValue(obj);
            }

            ~OpenIdIssuerInformation();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateOpenIdConnectionRequest : public PlayFabBaseModel
        {
            std::string ClientId;
            std::string ClientSecret;
            std::string ConnectionId;
            std::string IssuerDiscoveryUrl;
            OpenIdIssuerInformation* IssuerInformation;

            CreateOpenIdConnectionRequest() :
                PlayFabBaseModel(),
                ClientId(),
                ClientSecret(),
                ConnectionId(),
                IssuerDiscoveryUrl(),
                IssuerInformation(NULL)
            {}

            CreateOpenIdConnectionRequest(const CreateOpenIdConnectionRequest& src) :
                PlayFabBaseModel(),
                ClientId(src.ClientId),
                ClientSecret(src.ClientSecret),
                ConnectionId(src.ConnectionId),
                IssuerDiscoveryUrl(src.IssuerDiscoveryUrl),
                IssuerInformation(src.IssuerInformation ? new OpenIdIssuerInformation(*src.IssuerInformation) : NULL)
            {}

            CreateOpenIdConnectionRequest(const rapidjson::Value& obj) : CreateOpenIdConnectionRequest()
            {
                readFromValue(obj);
            }

            ~CreateOpenIdConnectionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreatePlayerSharedSecretRequest : public PlayFabBaseModel
        {
            std::string FriendlyName;

            CreatePlayerSharedSecretRequest() :
                PlayFabBaseModel(),
                FriendlyName()
            {}

            CreatePlayerSharedSecretRequest(const CreatePlayerSharedSecretRequest& src) :
                PlayFabBaseModel(),
                FriendlyName(src.FriendlyName)
            {}

            CreatePlayerSharedSecretRequest(const rapidjson::Value& obj) : CreatePlayerSharedSecretRequest()
            {
                readFromValue(obj);
            }

            ~CreatePlayerSharedSecretRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreatePlayerSharedSecretResult : public PlayFabBaseModel
        {
            std::string SecretKey;

            CreatePlayerSharedSecretResult() :
                PlayFabBaseModel(),
                SecretKey()
            {}

            CreatePlayerSharedSecretResult(const CreatePlayerSharedSecretResult& src) :
                PlayFabBaseModel(),
                SecretKey(src.SecretKey)
            {}

            CreatePlayerSharedSecretResult(const rapidjson::Value& obj) : CreatePlayerSharedSecretResult()
            {
                readFromValue(obj);
            }

            ~CreatePlayerSharedSecretResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        void writeStatisticAggregationMethodEnumJSON(StatisticAggregationMethod enumVal, PFStringJsonWriter& writer);
        StatisticAggregationMethod readStatisticAggregationMethodFromValue(const rapidjson::Value& obj);

        enum StatisticResetIntervalOption
        {
            StatisticResetIntervalOptionNever,
            StatisticResetIntervalOptionHour,
            StatisticResetIntervalOptionDay,
            StatisticResetIntervalOptionWeek,
            StatisticResetIntervalOptionMonth
        };

        void writeStatisticResetIntervalOptionEnumJSON(StatisticResetIntervalOption enumVal, PFStringJsonWriter& writer);
        StatisticResetIntervalOption readStatisticResetIntervalOptionFromValue(const rapidjson::Value& obj);

        struct CreatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            std::map<std::string, std::string> CustomTags;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            CreatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                AggregationMethod(),
                CustomTags(),
                StatisticName(),
                VersionChangeInterval()
            {}

            CreatePlayerStatisticDefinitionRequest(const CreatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                AggregationMethod(src.AggregationMethod),
                CustomTags(src.CustomTags),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            CreatePlayerStatisticDefinitionRequest(const rapidjson::Value& obj) : CreatePlayerStatisticDefinitionRequest()
            {
                readFromValue(obj);
            }

            ~CreatePlayerStatisticDefinitionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerStatisticDefinition : public PlayFabBaseModel
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            Uint32 CurrentVersion;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            PlayerStatisticDefinition() :
                PlayFabBaseModel(),
                AggregationMethod(),
                CurrentVersion(0),
                StatisticName(),
                VersionChangeInterval()
            {}

            PlayerStatisticDefinition(const PlayerStatisticDefinition& src) :
                PlayFabBaseModel(),
                AggregationMethod(src.AggregationMethod),
                CurrentVersion(src.CurrentVersion),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            PlayerStatisticDefinition(const rapidjson::Value& obj) : PlayerStatisticDefinition()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticDefinition();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreatePlayerStatisticDefinitionResult : public PlayFabBaseModel
        {
            PlayerStatisticDefinition* Statistic;

            CreatePlayerStatisticDefinitionResult() :
                PlayFabBaseModel(),
                Statistic(NULL)
            {}

            CreatePlayerStatisticDefinitionResult(const CreatePlayerStatisticDefinitionResult& src) :
                PlayFabBaseModel(),
                Statistic(src.Statistic ? new PlayerStatisticDefinition(*src.Statistic) : NULL)
            {}

            CreatePlayerStatisticDefinitionResult(const rapidjson::Value& obj) : CreatePlayerStatisticDefinitionResult()
            {
                readFromValue(obj);
            }

            ~CreatePlayerStatisticDefinitionResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateTaskResult : public PlayFabBaseModel
        {
            std::string TaskId;

            CreateTaskResult() :
                PlayFabBaseModel(),
                TaskId()
            {}

            CreateTaskResult(const CreateTaskResult& src) :
                PlayFabBaseModel(),
                TaskId(src.TaskId)
            {}

            CreateTaskResult(const rapidjson::Value& obj) : CreateTaskResult()
            {
                readFromValue(obj);
            }

            ~CreateTaskResult();

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

        struct DeleteContentRequest : public PlayFabBaseModel
        {
            std::string Key;

            DeleteContentRequest() :
                PlayFabBaseModel(),
                Key()
            {}

            DeleteContentRequest(const DeleteContentRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key)
            {}

            DeleteContentRequest(const rapidjson::Value& obj) : DeleteContentRequest()
            {
                readFromValue(obj);
            }

            ~DeleteContentRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteMasterPlayerAccountRequest : public PlayFabBaseModel
        {
            std::string MetaData;
            std::string PlayFabId;

            DeleteMasterPlayerAccountRequest() :
                PlayFabBaseModel(),
                MetaData(),
                PlayFabId()
            {}

            DeleteMasterPlayerAccountRequest(const DeleteMasterPlayerAccountRequest& src) :
                PlayFabBaseModel(),
                MetaData(src.MetaData),
                PlayFabId(src.PlayFabId)
            {}

            DeleteMasterPlayerAccountRequest(const rapidjson::Value& obj) : DeleteMasterPlayerAccountRequest()
            {
                readFromValue(obj);
            }

            ~DeleteMasterPlayerAccountRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteMasterPlayerAccountResult : public PlayFabBaseModel
        {
            std::string JobReceiptId;
            std::list<std::string> TitleIds;

            DeleteMasterPlayerAccountResult() :
                PlayFabBaseModel(),
                JobReceiptId(),
                TitleIds()
            {}

            DeleteMasterPlayerAccountResult(const DeleteMasterPlayerAccountResult& src) :
                PlayFabBaseModel(),
                JobReceiptId(src.JobReceiptId),
                TitleIds(src.TitleIds)
            {}

            DeleteMasterPlayerAccountResult(const rapidjson::Value& obj) : DeleteMasterPlayerAccountResult()
            {
                readFromValue(obj);
            }

            ~DeleteMasterPlayerAccountResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteOpenIdConnectionRequest : public PlayFabBaseModel
        {
            std::string ConnectionId;

            DeleteOpenIdConnectionRequest() :
                PlayFabBaseModel(),
                ConnectionId()
            {}

            DeleteOpenIdConnectionRequest(const DeleteOpenIdConnectionRequest& src) :
                PlayFabBaseModel(),
                ConnectionId(src.ConnectionId)
            {}

            DeleteOpenIdConnectionRequest(const rapidjson::Value& obj) : DeleteOpenIdConnectionRequest()
            {
                readFromValue(obj);
            }

            ~DeleteOpenIdConnectionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeletePlayerRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            DeletePlayerRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            DeletePlayerRequest(const DeletePlayerRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            DeletePlayerRequest(const rapidjson::Value& obj) : DeletePlayerRequest()
            {
                readFromValue(obj);
            }

            ~DeletePlayerRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeletePlayerResult : public PlayFabBaseModel
        {

            DeletePlayerResult() :
                PlayFabBaseModel()
            {}

            DeletePlayerResult(const DeletePlayerResult& src) :
                PlayFabBaseModel()
            {}

            DeletePlayerResult(const rapidjson::Value& obj) : DeletePlayerResult()
            {
                readFromValue(obj);
            }

            ~DeletePlayerResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeletePlayerSharedSecretRequest : public PlayFabBaseModel
        {
            std::string SecretKey;

            DeletePlayerSharedSecretRequest() :
                PlayFabBaseModel(),
                SecretKey()
            {}

            DeletePlayerSharedSecretRequest(const DeletePlayerSharedSecretRequest& src) :
                PlayFabBaseModel(),
                SecretKey(src.SecretKey)
            {}

            DeletePlayerSharedSecretRequest(const rapidjson::Value& obj) : DeletePlayerSharedSecretRequest()
            {
                readFromValue(obj);
            }

            ~DeletePlayerSharedSecretRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeletePlayerSharedSecretResult : public PlayFabBaseModel
        {

            DeletePlayerSharedSecretResult() :
                PlayFabBaseModel()
            {}

            DeletePlayerSharedSecretResult(const DeletePlayerSharedSecretResult& src) :
                PlayFabBaseModel()
            {}

            DeletePlayerSharedSecretResult(const rapidjson::Value& obj) : DeletePlayerSharedSecretResult()
            {
                readFromValue(obj);
            }

            ~DeletePlayerSharedSecretResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteStoreRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomTags;
            std::string StoreId;

            DeleteStoreRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CustomTags(),
                StoreId()
            {}

            DeleteStoreRequest(const DeleteStoreRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
                StoreId(src.StoreId)
            {}

            DeleteStoreRequest(const rapidjson::Value& obj) : DeleteStoreRequest()
            {
                readFromValue(obj);
            }

            ~DeleteStoreRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteStoreResult : public PlayFabBaseModel
        {

            DeleteStoreResult() :
                PlayFabBaseModel()
            {}

            DeleteStoreResult(const DeleteStoreResult& src) :
                PlayFabBaseModel()
            {}

            DeleteStoreResult(const rapidjson::Value& obj) : DeleteStoreResult()
            {
                readFromValue(obj);
            }

            ~DeleteStoreResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteTaskRequest : public PlayFabBaseModel
        {
            NameIdentifier* Identifier;

            DeleteTaskRequest() :
                PlayFabBaseModel(),
                Identifier(NULL)
            {}

            DeleteTaskRequest(const DeleteTaskRequest& src) :
                PlayFabBaseModel(),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : NULL)
            {}

            DeleteTaskRequest(const rapidjson::Value& obj) : DeleteTaskRequest()
            {
                readFromValue(obj);
            }

            ~DeleteTaskRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteTitleDataOverrideRequest : public PlayFabBaseModel
        {
            std::string OverrideLabel;

            DeleteTitleDataOverrideRequest() :
                PlayFabBaseModel(),
                OverrideLabel()
            {}

            DeleteTitleDataOverrideRequest(const DeleteTitleDataOverrideRequest& src) :
                PlayFabBaseModel(),
                OverrideLabel(src.OverrideLabel)
            {}

            DeleteTitleDataOverrideRequest(const rapidjson::Value& obj) : DeleteTitleDataOverrideRequest()
            {
                readFromValue(obj);
            }

            ~DeleteTitleDataOverrideRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteTitleDataOverrideResult : public PlayFabBaseModel
        {

            DeleteTitleDataOverrideResult() :
                PlayFabBaseModel()
            {}

            DeleteTitleDataOverrideResult(const DeleteTitleDataOverrideResult& src) :
                PlayFabBaseModel()
            {}

            DeleteTitleDataOverrideResult(const rapidjson::Value& obj) : DeleteTitleDataOverrideResult()
            {
                readFromValue(obj);
            }

            ~DeleteTitleDataOverrideResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteTitleRequest : public PlayFabBaseModel
        {

            DeleteTitleRequest() :
                PlayFabBaseModel()
            {}

            DeleteTitleRequest(const DeleteTitleRequest& src) :
                PlayFabBaseModel()
            {}

            DeleteTitleRequest(const rapidjson::Value& obj) : DeleteTitleRequest()
            {
                readFromValue(obj);
            }

            ~DeleteTitleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteTitleResult : public PlayFabBaseModel
        {

            DeleteTitleResult() :
                PlayFabBaseModel()
            {}

            DeleteTitleResult(const DeleteTitleResult& src) :
                PlayFabBaseModel()
            {}

            DeleteTitleResult(const rapidjson::Value& obj) : DeleteTitleResult()
            {
                readFromValue(obj);
            }

            ~DeleteTitleResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        void writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer);
        EffectType readEffectTypeFromValue(const rapidjson::Value& obj);

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

        struct ExportMasterPlayerDataRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            ExportMasterPlayerDataRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            ExportMasterPlayerDataRequest(const ExportMasterPlayerDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            ExportMasterPlayerDataRequest(const rapidjson::Value& obj) : ExportMasterPlayerDataRequest()
            {
                readFromValue(obj);
            }

            ~ExportMasterPlayerDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ExportMasterPlayerDataResult : public PlayFabBaseModel
        {
            std::string JobReceiptId;

            ExportMasterPlayerDataResult() :
                PlayFabBaseModel(),
                JobReceiptId()
            {}

            ExportMasterPlayerDataResult(const ExportMasterPlayerDataResult& src) :
                PlayFabBaseModel(),
                JobReceiptId(src.JobReceiptId)
            {}

            ExportMasterPlayerDataResult(const rapidjson::Value& obj) : ExportMasterPlayerDataResult()
            {
                readFromValue(obj);
            }

            ~ExportMasterPlayerDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GameModeInfo : public PlayFabBaseModel
        {
            std::string Gamemode;
            Uint32 MaxPlayerCount;
            Uint32 MinPlayerCount;
            OptionalBool StartOpen;

            GameModeInfo() :
                PlayFabBaseModel(),
                Gamemode(),
                MaxPlayerCount(0),
                MinPlayerCount(0),
                StartOpen()
            {}

            GameModeInfo(const GameModeInfo& src) :
                PlayFabBaseModel(),
                Gamemode(src.Gamemode),
                MaxPlayerCount(src.MaxPlayerCount),
                MinPlayerCount(src.MinPlayerCount),
                StartOpen(src.StartOpen)
            {}

            GameModeInfo(const rapidjson::Value& obj) : GameModeInfo()
            {
                readFromValue(obj);
            }

            ~GameModeInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum GenericErrorCodes
        {
            GenericErrorCodesSuccess,
            GenericErrorCodesUnkownError,
            GenericErrorCodesInvalidParams,
            GenericErrorCodesAccountNotFound,
            GenericErrorCodesAccountBanned,
            GenericErrorCodesInvalidUsernameOrPassword,
            GenericErrorCodesInvalidTitleId,
            GenericErrorCodesInvalidEmailAddress,
            GenericErrorCodesEmailAddressNotAvailable,
            GenericErrorCodesInvalidUsername,
            GenericErrorCodesInvalidPassword,
            GenericErrorCodesUsernameNotAvailable,
            GenericErrorCodesInvalidSteamTicket,
            GenericErrorCodesAccountAlreadyLinked,
            GenericErrorCodesLinkedAccountAlreadyClaimed,
            GenericErrorCodesInvalidFacebookToken,
            GenericErrorCodesAccountNotLinked,
            GenericErrorCodesFailedByPaymentProvider,
            GenericErrorCodesCouponCodeNotFound,
            GenericErrorCodesInvalidContainerItem,
            GenericErrorCodesContainerNotOwned,
            GenericErrorCodesKeyNotOwned,
            GenericErrorCodesInvalidItemIdInTable,
            GenericErrorCodesInvalidReceipt,
            GenericErrorCodesReceiptAlreadyUsed,
            GenericErrorCodesReceiptCancelled,
            GenericErrorCodesGameNotFound,
            GenericErrorCodesGameModeNotFound,
            GenericErrorCodesInvalidGoogleToken,
            GenericErrorCodesUserIsNotPartOfDeveloper,
            GenericErrorCodesInvalidTitleForDeveloper,
            GenericErrorCodesTitleNameConflicts,
            GenericErrorCodesUserisNotValid,
            GenericErrorCodesValueAlreadyExists,
            GenericErrorCodesBuildNotFound,
            GenericErrorCodesPlayerNotInGame,
            GenericErrorCodesInvalidTicket,
            GenericErrorCodesInvalidDeveloper,
            GenericErrorCodesInvalidOrderInfo,
            GenericErrorCodesRegistrationIncomplete,
            GenericErrorCodesInvalidPlatform,
            GenericErrorCodesUnknownError,
            GenericErrorCodesSteamApplicationNotOwned,
            GenericErrorCodesWrongSteamAccount,
            GenericErrorCodesTitleNotActivated,
            GenericErrorCodesRegistrationSessionNotFound,
            GenericErrorCodesNoSuchMod,
            GenericErrorCodesFileNotFound,
            GenericErrorCodesDuplicateEmail,
            GenericErrorCodesItemNotFound,
            GenericErrorCodesItemNotOwned,
            GenericErrorCodesItemNotRecycleable,
            GenericErrorCodesItemNotAffordable,
            GenericErrorCodesInvalidVirtualCurrency,
            GenericErrorCodesWrongVirtualCurrency,
            GenericErrorCodesWrongPrice,
            GenericErrorCodesNonPositiveValue,
            GenericErrorCodesInvalidRegion,
            GenericErrorCodesRegionAtCapacity,
            GenericErrorCodesServerFailedToStart,
            GenericErrorCodesNameNotAvailable,
            GenericErrorCodesInsufficientFunds,
            GenericErrorCodesInvalidDeviceID,
            GenericErrorCodesInvalidPushNotificationToken,
            GenericErrorCodesNoRemainingUses,
            GenericErrorCodesInvalidPaymentProvider,
            GenericErrorCodesPurchaseInitializationFailure,
            GenericErrorCodesDuplicateUsername,
            GenericErrorCodesInvalidBuyerInfo,
            GenericErrorCodesNoGameModeParamsSet,
            GenericErrorCodesBodyTooLarge,
            GenericErrorCodesReservedWordInBody,
            GenericErrorCodesInvalidTypeInBody,
            GenericErrorCodesInvalidRequest,
            GenericErrorCodesReservedEventName,
            GenericErrorCodesInvalidUserStatistics,
            GenericErrorCodesNotAuthenticated,
            GenericErrorCodesStreamAlreadyExists,
            GenericErrorCodesErrorCreatingStream,
            GenericErrorCodesStreamNotFound,
            GenericErrorCodesInvalidAccount,
            GenericErrorCodesPurchaseDoesNotExist,
            GenericErrorCodesInvalidPurchaseTransactionStatus,
            GenericErrorCodesAPINotEnabledForGameClientAccess,
            GenericErrorCodesNoPushNotificationARNForTitle,
            GenericErrorCodesBuildAlreadyExists,
            GenericErrorCodesBuildPackageDoesNotExist,
            GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle,
            GenericErrorCodesInvalidSharedGroupId,
            GenericErrorCodesNotAuthorized,
            GenericErrorCodesMissingTitleGoogleProperties,
            GenericErrorCodesInvalidItemProperties,
            GenericErrorCodesInvalidPSNAuthCode,
            GenericErrorCodesInvalidItemId,
            GenericErrorCodesPushNotEnabledForAccount,
            GenericErrorCodesPushServiceError,
            GenericErrorCodesReceiptDoesNotContainInAppItems,
            GenericErrorCodesReceiptContainsMultipleInAppItems,
            GenericErrorCodesInvalidBundleID,
            GenericErrorCodesJavascriptException,
            GenericErrorCodesInvalidSessionTicket,
            GenericErrorCodesUnableToConnectToDatabase,
            GenericErrorCodesInternalServerError,
            GenericErrorCodesInvalidReportDate,
            GenericErrorCodesReportNotAvailable,
            GenericErrorCodesDatabaseThroughputExceeded,
            GenericErrorCodesInvalidGameTicket,
            GenericErrorCodesExpiredGameTicket,
            GenericErrorCodesGameTicketDoesNotMatchLobby,
            GenericErrorCodesLinkedDeviceAlreadyClaimed,
            GenericErrorCodesDeviceAlreadyLinked,
            GenericErrorCodesDeviceNotLinked,
            GenericErrorCodesPartialFailure,
            GenericErrorCodesPublisherNotSet,
            GenericErrorCodesServiceUnavailable,
            GenericErrorCodesVersionNotFound,
            GenericErrorCodesRevisionNotFound,
            GenericErrorCodesInvalidPublisherId,
            GenericErrorCodesDownstreamServiceUnavailable,
            GenericErrorCodesAPINotIncludedInTitleUsageTier,
            GenericErrorCodesDAULimitExceeded,
            GenericErrorCodesAPIRequestLimitExceeded,
            GenericErrorCodesInvalidAPIEndpoint,
            GenericErrorCodesBuildNotAvailable,
            GenericErrorCodesConcurrentEditError,
            GenericErrorCodesContentNotFound,
            GenericErrorCodesCharacterNotFound,
            GenericErrorCodesCloudScriptNotFound,
            GenericErrorCodesContentQuotaExceeded,
            GenericErrorCodesInvalidCharacterStatistics,
            GenericErrorCodesPhotonNotEnabledForTitle,
            GenericErrorCodesPhotonApplicationNotFound,
            GenericErrorCodesPhotonApplicationNotAssociatedWithTitle,
            GenericErrorCodesInvalidEmailOrPassword,
            GenericErrorCodesFacebookAPIError,
            GenericErrorCodesInvalidContentType,
            GenericErrorCodesKeyLengthExceeded,
            GenericErrorCodesDataLengthExceeded,
            GenericErrorCodesTooManyKeys,
            GenericErrorCodesFreeTierCannotHaveVirtualCurrency,
            GenericErrorCodesMissingAmazonSharedKey,
            GenericErrorCodesAmazonValidationError,
            GenericErrorCodesInvalidPSNIssuerId,
            GenericErrorCodesPSNInaccessible,
            GenericErrorCodesExpiredAuthToken,
            GenericErrorCodesFailedToGetEntitlements,
            GenericErrorCodesFailedToConsumeEntitlement,
            GenericErrorCodesTradeAcceptingUserNotAllowed,
            GenericErrorCodesTradeInventoryItemIsAssignedToCharacter,
            GenericErrorCodesTradeInventoryItemIsBundle,
            GenericErrorCodesTradeStatusNotValidForCancelling,
            GenericErrorCodesTradeStatusNotValidForAccepting,
            GenericErrorCodesTradeDoesNotExist,
            GenericErrorCodesTradeCancelled,
            GenericErrorCodesTradeAlreadyFilled,
            GenericErrorCodesTradeWaitForStatusTimeout,
            GenericErrorCodesTradeInventoryItemExpired,
            GenericErrorCodesTradeMissingOfferedAndAcceptedItems,
            GenericErrorCodesTradeAcceptedItemIsBundle,
            GenericErrorCodesTradeAcceptedItemIsStackable,
            GenericErrorCodesTradeInventoryItemInvalidStatus,
            GenericErrorCodesTradeAcceptedCatalogItemInvalid,
            GenericErrorCodesTradeAllowedUsersInvalid,
            GenericErrorCodesTradeInventoryItemDoesNotExist,
            GenericErrorCodesTradeInventoryItemIsConsumed,
            GenericErrorCodesTradeInventoryItemIsStackable,
            GenericErrorCodesTradeAcceptedItemsMismatch,
            GenericErrorCodesInvalidKongregateToken,
            GenericErrorCodesFeatureNotConfiguredForTitle,
            GenericErrorCodesNoMatchingCatalogItemForReceipt,
            GenericErrorCodesInvalidCurrencyCode,
            GenericErrorCodesNoRealMoneyPriceForCatalogItem,
            GenericErrorCodesTradeInventoryItemIsNotTradable,
            GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable,
            GenericErrorCodesUsersAlreadyFriends,
            GenericErrorCodesLinkedIdentifierAlreadyClaimed,
            GenericErrorCodesCustomIdNotLinked,
            GenericErrorCodesTotalDataSizeExceeded,
            GenericErrorCodesDeleteKeyConflict,
            GenericErrorCodesInvalidXboxLiveToken,
            GenericErrorCodesExpiredXboxLiveToken,
            GenericErrorCodesResettableStatisticVersionRequired,
            GenericErrorCodesNotAuthorizedByTitle,
            GenericErrorCodesNoPartnerEnabled,
            GenericErrorCodesInvalidPartnerResponse,
            GenericErrorCodesAPINotEnabledForGameServerAccess,
            GenericErrorCodesStatisticNotFound,
            GenericErrorCodesStatisticNameConflict,
            GenericErrorCodesStatisticVersionClosedForWrites,
            GenericErrorCodesStatisticVersionInvalid,
            GenericErrorCodesAPIClientRequestRateLimitExceeded,
            GenericErrorCodesInvalidJSONContent,
            GenericErrorCodesInvalidDropTable,
            GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval,
            GenericErrorCodesStatisticCountLimitExceeded,
            GenericErrorCodesStatisticVersionIncrementRateExceeded,
            GenericErrorCodesContainerKeyInvalid,
            GenericErrorCodesCloudScriptExecutionTimeLimitExceeded,
            GenericErrorCodesNoWritePermissionsForEvent,
            GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded,
            GenericErrorCodesCloudScriptAPIRequestCountExceeded,
            GenericErrorCodesCloudScriptAPIRequestError,
            GenericErrorCodesCloudScriptHTTPRequestError,
            GenericErrorCodesInsufficientGuildRole,
            GenericErrorCodesGuildNotFound,
            GenericErrorCodesOverLimit,
            GenericErrorCodesEventNotFound,
            GenericErrorCodesInvalidEventField,
            GenericErrorCodesInvalidEventName,
            GenericErrorCodesCatalogNotConfigured,
            GenericErrorCodesOperationNotSupportedForPlatform,
            GenericErrorCodesSegmentNotFound,
            GenericErrorCodesStoreNotFound,
            GenericErrorCodesInvalidStatisticName,
            GenericErrorCodesTitleNotQualifiedForLimit,
            GenericErrorCodesInvalidServiceLimitLevel,
            GenericErrorCodesServiceLimitLevelInTransition,
            GenericErrorCodesCouponAlreadyRedeemed,
            GenericErrorCodesGameServerBuildSizeLimitExceeded,
            GenericErrorCodesGameServerBuildCountLimitExceeded,
            GenericErrorCodesVirtualCurrencyCountLimitExceeded,
            GenericErrorCodesVirtualCurrencyCodeExists,
            GenericErrorCodesTitleNewsItemCountLimitExceeded,
            GenericErrorCodesInvalidTwitchToken,
            GenericErrorCodesTwitchResponseError,
            GenericErrorCodesProfaneDisplayName,
            GenericErrorCodesUserAlreadyAdded,
            GenericErrorCodesInvalidVirtualCurrencyCode,
            GenericErrorCodesVirtualCurrencyCannotBeDeleted,
            GenericErrorCodesIdentifierAlreadyClaimed,
            GenericErrorCodesIdentifierNotLinked,
            GenericErrorCodesInvalidContinuationToken,
            GenericErrorCodesExpiredContinuationToken,
            GenericErrorCodesInvalidSegment,
            GenericErrorCodesInvalidSessionId,
            GenericErrorCodesSessionLogNotFound,
            GenericErrorCodesInvalidSearchTerm,
            GenericErrorCodesTwoFactorAuthenticationTokenRequired,
            GenericErrorCodesGameServerHostCountLimitExceeded,
            GenericErrorCodesPlayerTagCountLimitExceeded,
            GenericErrorCodesRequestAlreadyRunning,
            GenericErrorCodesActionGroupNotFound,
            GenericErrorCodesMaximumSegmentBulkActionJobsRunning,
            GenericErrorCodesNoActionsOnPlayersInSegmentJob,
            GenericErrorCodesDuplicateStatisticName,
            GenericErrorCodesScheduledTaskNameConflict,
            GenericErrorCodesScheduledTaskCreateConflict,
            GenericErrorCodesInvalidScheduledTaskName,
            GenericErrorCodesInvalidTaskSchedule,
            GenericErrorCodesSteamNotEnabledForTitle,
            GenericErrorCodesLimitNotAnUpgradeOption,
            GenericErrorCodesNoSecretKeyEnabledForCloudScript,
            GenericErrorCodesTaskNotFound,
            GenericErrorCodesTaskInstanceNotFound,
            GenericErrorCodesInvalidIdentityProviderId,
            GenericErrorCodesMisconfiguredIdentityProvider,
            GenericErrorCodesInvalidScheduledTaskType,
            GenericErrorCodesBillingInformationRequired,
            GenericErrorCodesLimitedEditionItemUnavailable,
            GenericErrorCodesInvalidAdPlacementAndReward,
            GenericErrorCodesAllAdPlacementViewsAlreadyConsumed,
            GenericErrorCodesGoogleOAuthNotConfiguredForTitle,
            GenericErrorCodesGoogleOAuthError,
            GenericErrorCodesUserNotFriend,
            GenericErrorCodesInvalidSignature,
            GenericErrorCodesInvalidPublicKey,
            GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse,
            GenericErrorCodesStatisticUpdateInProgress,
            GenericErrorCodesLeaderboardVersionNotAvailable,
            GenericErrorCodesStatisticAlreadyHasPrizeTable,
            GenericErrorCodesPrizeTableHasOverlappingRanks,
            GenericErrorCodesPrizeTableHasMissingRanks,
            GenericErrorCodesPrizeTableRankStartsAtZero,
            GenericErrorCodesInvalidStatistic,
            GenericErrorCodesExpressionParseFailure,
            GenericErrorCodesExpressionInvokeFailure,
            GenericErrorCodesExpressionTooLong,
            GenericErrorCodesDataUpdateRateExceeded,
            GenericErrorCodesRestrictedEmailDomain,
            GenericErrorCodesEncryptionKeyDisabled,
            GenericErrorCodesEncryptionKeyMissing,
            GenericErrorCodesEncryptionKeyBroken,
            GenericErrorCodesNoSharedSecretKeyConfigured,
            GenericErrorCodesSecretKeyNotFound,
            GenericErrorCodesPlayerSecretAlreadyConfigured,
            GenericErrorCodesAPIRequestsDisabledForTitle,
            GenericErrorCodesInvalidSharedSecretKey,
            GenericErrorCodesPrizeTableHasNoRanks,
            GenericErrorCodesProfileDoesNotExist,
            GenericErrorCodesContentS3OriginBucketNotConfigured,
            GenericErrorCodesInvalidEnvironmentForReceipt,
            GenericErrorCodesEncryptedRequestNotAllowed,
            GenericErrorCodesSignedRequestNotAllowed,
            GenericErrorCodesRequestViewConstraintParamsNotAllowed,
            GenericErrorCodesBadPartnerConfiguration,
            GenericErrorCodesXboxBPCertificateFailure,
            GenericErrorCodesXboxXASSExchangeFailure,
            GenericErrorCodesInvalidEntityId,
            GenericErrorCodesStatisticValueAggregationOverflow,
            GenericErrorCodesEmailMessageFromAddressIsMissing,
            GenericErrorCodesEmailMessageToAddressIsMissing,
            GenericErrorCodesSmtpServerAuthenticationError,
            GenericErrorCodesSmtpServerLimitExceeded,
            GenericErrorCodesSmtpServerInsufficientStorage,
            GenericErrorCodesSmtpServerCommunicationError,
            GenericErrorCodesSmtpServerGeneralFailure,
            GenericErrorCodesEmailClientTimeout,
            GenericErrorCodesEmailClientCanceledTask,
            GenericErrorCodesEmailTemplateMissing,
            GenericErrorCodesInvalidHostForTitleId,
            GenericErrorCodesEmailConfirmationTokenDoesNotExist,
            GenericErrorCodesEmailConfirmationTokenExpired,
            GenericErrorCodesAccountDeleted,
            GenericErrorCodesPlayerSecretNotConfigured,
            GenericErrorCodesInvalidSignatureTime,
            GenericErrorCodesNoContactEmailAddressFound,
            GenericErrorCodesInvalidAuthToken,
            GenericErrorCodesAuthTokenDoesNotExist,
            GenericErrorCodesAuthTokenExpired,
            GenericErrorCodesAuthTokenAlreadyUsedToResetPassword,
            GenericErrorCodesMembershipNameTooLong,
            GenericErrorCodesMembershipNotFound,
            GenericErrorCodesGoogleServiceAccountInvalid,
            GenericErrorCodesGoogleServiceAccountParseFailure,
            GenericErrorCodesEntityTokenMissing,
            GenericErrorCodesEntityTokenInvalid,
            GenericErrorCodesEntityTokenExpired,
            GenericErrorCodesEntityTokenRevoked,
            GenericErrorCodesInvalidProductForSubscription,
            GenericErrorCodesXboxInaccessible,
            GenericErrorCodesSubscriptionAlreadyTaken,
            GenericErrorCodesSmtpAddonNotEnabled,
            GenericErrorCodesAPIConcurrentRequestLimitExceeded,
            GenericErrorCodesXboxRejectedXSTSExchangeRequest,
            GenericErrorCodesVariableNotDefined,
            GenericErrorCodesTemplateVersionNotDefined,
            GenericErrorCodesFileTooLarge,
            GenericErrorCodesTitleDeleted,
            GenericErrorCodesTitleContainsUserAccounts,
            GenericErrorCodesTitleDeletionPlayerCleanupFailure,
            GenericErrorCodesEntityFileOperationPending,
            GenericErrorCodesNoEntityFileOperationPending,
            GenericErrorCodesEntityProfileVersionMismatch,
            GenericErrorCodesTemplateVersionTooOld,
            GenericErrorCodesMembershipDefinitionInUse,
            GenericErrorCodesPaymentPageNotConfigured,
            GenericErrorCodesFailedLoginAttemptRateLimitExceeded,
            GenericErrorCodesEntityBlockedByGroup,
            GenericErrorCodesRoleDoesNotExist,
            GenericErrorCodesEntityIsAlreadyMember,
            GenericErrorCodesDuplicateRoleId,
            GenericErrorCodesGroupInvitationNotFound,
            GenericErrorCodesGroupApplicationNotFound,
            GenericErrorCodesOutstandingInvitationAcceptedInstead,
            GenericErrorCodesOutstandingApplicationAcceptedInstead,
            GenericErrorCodesRoleIsGroupDefaultMember,
            GenericErrorCodesRoleIsGroupAdmin,
            GenericErrorCodesRoleNameNotAvailable,
            GenericErrorCodesGroupNameNotAvailable,
            GenericErrorCodesEmailReportAlreadySent,
            GenericErrorCodesEmailReportRecipientBlacklisted,
            GenericErrorCodesEventNamespaceNotAllowed,
            GenericErrorCodesEventEntityNotAllowed,
            GenericErrorCodesInvalidEntityType,
            GenericErrorCodesNullTokenResultFromAad,
            GenericErrorCodesInvalidTokenResultFromAad,
            GenericErrorCodesNoValidCertificateForAad,
            GenericErrorCodesInvalidCertificateForAad,
            GenericErrorCodesDuplicateDropTableId,
            GenericErrorCodesMultiplayerServerError,
            GenericErrorCodesMultiplayerServerTooManyRequests,
            GenericErrorCodesMultiplayerServerNoContent,
            GenericErrorCodesMultiplayerServerBadRequest,
            GenericErrorCodesMultiplayerServerUnauthorized,
            GenericErrorCodesMultiplayerServerForbidden,
            GenericErrorCodesMultiplayerServerNotFound,
            GenericErrorCodesMultiplayerServerConflict,
            GenericErrorCodesMultiplayerServerInternalServerError,
            GenericErrorCodesMultiplayerServerUnavailable,
            GenericErrorCodesExplicitContentDetected,
            GenericErrorCodesPIIContentDetected,
            GenericErrorCodesInvalidScheduledTaskParameter,
            GenericErrorCodesPerEntityEventRateLimitExceeded,
            GenericErrorCodesTitleDefaultLanguageNotSet,
            GenericErrorCodesEmailTemplateMissingDefaultVersion,
            GenericErrorCodesFacebookInstantGamesIdNotLinked,
            GenericErrorCodesInvalidFacebookInstantGamesSignature,
            GenericErrorCodesFacebookInstantGamesAuthNotConfiguredForTitle,
            GenericErrorCodesEntityProfileConstraintValidationFailed,
            GenericErrorCodesTelemetryIngestionKeyPending,
            GenericErrorCodesTelemetryIngestionKeyNotFound,
            GenericErrorCodesStatisticChildNameInvalid,
            GenericErrorCodesDataIntegrityError,
            GenericErrorCodesVirtualCurrencyCannotBeSetToOlderVersion,
            GenericErrorCodesVirtualCurrencyMustBeWithinIntegerRange,
            GenericErrorCodesEmailTemplateInvalidSyntax,
            GenericErrorCodesEmailTemplateMissingCallback,
            GenericErrorCodesPushNotificationTemplateInvalidPayload,
            GenericErrorCodesInvalidLocalizedPushNotificationLanguage,
            GenericErrorCodesMissingLocalizedPushNotificationMessage,
            GenericErrorCodesPushNotificationTemplateMissingPlatformPayload,
            GenericErrorCodesPushNotificationTemplatePayloadContainsInvalidJson,
            GenericErrorCodesPushNotificationTemplateContainsInvalidIosPayload,
            GenericErrorCodesPushNotificationTemplateContainsInvalidAndroidPayload,
            GenericErrorCodesPushNotificationTemplateIosPayloadMissingNotificationBody,
            GenericErrorCodesPushNotificationTemplateAndroidPayloadMissingNotificationBody,
            GenericErrorCodesPushNotificationTemplateNotFound,
            GenericErrorCodesPushNotificationTemplateMissingDefaultVersion,
            GenericErrorCodesPushNotificationTemplateInvalidSyntax,
            GenericErrorCodesPushNotificationTemplateNoCustomPayloadForV1,
            GenericErrorCodesNoLeaderboardForStatistic,
            GenericErrorCodesTitleNewsMissingDefaultLanguage,
            GenericErrorCodesTitleNewsNotFound,
            GenericErrorCodesTitleNewsDuplicateLanguage,
            GenericErrorCodesTitleNewsMissingTitleOrBody,
            GenericErrorCodesTitleNewsInvalidLanguage,
            GenericErrorCodesEmailRecipientBlacklisted,
            GenericErrorCodesInvalidGameCenterAuthRequest,
            GenericErrorCodesGameCenterAuthenticationFailed,
            GenericErrorCodesCannotEnablePartiesForTitle,
            GenericErrorCodesPartyError,
            GenericErrorCodesPartyRequests,
            GenericErrorCodesPartyNoContent,
            GenericErrorCodesPartyBadRequest,
            GenericErrorCodesPartyUnauthorized,
            GenericErrorCodesPartyForbidden,
            GenericErrorCodesPartyNotFound,
            GenericErrorCodesPartyConflict,
            GenericErrorCodesPartyInternalServerError,
            GenericErrorCodesPartyUnavailable,
            GenericErrorCodesPartyTooManyRequests,
            GenericErrorCodesPushNotificationTemplateMissingName,
            GenericErrorCodesCannotEnableMultiplayerServersForTitle,
            GenericErrorCodesWriteAttemptedDuringExport,
            GenericErrorCodesMultiplayerServerTitleQuotaCoresExceeded,
            GenericErrorCodesAutomationRuleNotFound,
            GenericErrorCodesEntityAPIKeyLimitExceeded,
            GenericErrorCodesEntityAPIKeyNotFound,
            GenericErrorCodesEntityAPIKeyOrSecretInvalid,
            GenericErrorCodesEconomyServiceUnavailable,
            GenericErrorCodesEconomyServiceInternalError,
            GenericErrorCodesQueryRateLimitExceeded,
            GenericErrorCodesEntityAPIKeyCreationDisabledForEntity,
            GenericErrorCodesForbiddenByEntityPolicy,
            GenericErrorCodesUpdateInventoryRateLimitExceeded,
            GenericErrorCodesStudioCreationRateLimited,
            GenericErrorCodesStudioCreationInProgress,
            GenericErrorCodesDuplicateStudioName,
            GenericErrorCodesStudioNotFound,
            GenericErrorCodesStudioDeleted,
            GenericErrorCodesStudioDeactivated,
            GenericErrorCodesStudioActivated,
            GenericErrorCodesTitleCreationRateLimited,
            GenericErrorCodesTitleCreationInProgress,
            GenericErrorCodesDuplicateTitleName,
            GenericErrorCodesTitleActivationRateLimited,
            GenericErrorCodesTitleActivationInProgress,
            GenericErrorCodesTitleDeactivated,
            GenericErrorCodesTitleActivated,
            GenericErrorCodesCloudScriptAzureFunctionsExecutionTimeLimitExceeded,
            GenericErrorCodesCloudScriptAzureFunctionsArgumentSizeExceeded,
            GenericErrorCodesCloudScriptAzureFunctionsReturnSizeExceeded,
            GenericErrorCodesCloudScriptAzureFunctionsHTTPRequestError,
            GenericErrorCodesVirtualCurrencyBetaGetError,
            GenericErrorCodesVirtualCurrencyBetaCreateError,
            GenericErrorCodesVirtualCurrencyBetaInitialDepositSaveError,
            GenericErrorCodesVirtualCurrencyBetaSaveError,
            GenericErrorCodesVirtualCurrencyBetaDeleteError,
            GenericErrorCodesVirtualCurrencyBetaRestoreError,
            GenericErrorCodesVirtualCurrencyBetaSaveConflict,
            GenericErrorCodesVirtualCurrencyBetaUpdateError,
            GenericErrorCodesInsightsManagementDatabaseNotFound,
            GenericErrorCodesInsightsManagementOperationNotFound,
            GenericErrorCodesInsightsManagementErrorPendingOperationExists,
            GenericErrorCodesInsightsManagementSetPerformanceLevelInvalidParameter,
            GenericErrorCodesInsightsManagementSetStorageRetentionInvalidParameter,
            GenericErrorCodesInsightsManagementGetStorageUsageInvalidParameter,
            GenericErrorCodesInsightsManagementGetOperationStatusInvalidParameter,
            GenericErrorCodesDuplicatePurchaseTransactionId,
            GenericErrorCodesEvaluationModePlayerCountExceeded,
            GenericErrorCodesGetPlayersInSegmentRateLimitExceeded,
            GenericErrorCodesCloudScriptFunctionNameSizeExceeded,
            GenericErrorCodesInsightsManagementTitleInEvaluationMode,
            GenericErrorCodesCloudScriptAzureFunctionsQueueRequestError,
            GenericErrorCodesEvaluationModeTitleCountExceeded,
            GenericErrorCodesInsightsManagementTitleNotInFlight,
            GenericErrorCodesLimitNotFound,
            GenericErrorCodesLimitNotAvailableViaAPI,
            GenericErrorCodesInsightsManagementSetStorageRetentionBelowMinimum,
            GenericErrorCodesInsightsManagementSetStorageRetentionAboveMaximum,
            GenericErrorCodesAppleNotEnabledForTitle,
            GenericErrorCodesInsightsManagementNewActiveEventExportLimitInvalid,
            GenericErrorCodesInsightsManagementSetPerformanceRateLimited,
            GenericErrorCodesPartyRequestsThrottledFromRateLimiter,
            GenericErrorCodesXboxServiceTooManyRequests,
            GenericErrorCodesNintendoSwitchNotEnabledForTitle,
            GenericErrorCodesRequestMultiplayerServersThrottledFromRateLimiter,
            GenericErrorCodesTitleDataOverrideNotFound,
            GenericErrorCodesDuplicateKeys,
            GenericErrorCodesWasNotCreatedWithCloudRoot,
            GenericErrorCodesLegacyMultiplayerServersDeprecated,
            GenericErrorCodesMatchmakingEntityInvalid,
            GenericErrorCodesMatchmakingPlayerAttributesInvalid,
            GenericErrorCodesMatchmakingQueueNotFound,
            GenericErrorCodesMatchmakingMatchNotFound,
            GenericErrorCodesMatchmakingTicketNotFound,
            GenericErrorCodesMatchmakingAlreadyJoinedTicket,
            GenericErrorCodesMatchmakingTicketAlreadyCompleted,
            GenericErrorCodesMatchmakingQueueConfigInvalid,
            GenericErrorCodesMatchmakingMemberProfileInvalid,
            GenericErrorCodesNintendoSwitchDeviceIdNotLinked,
            GenericErrorCodesMatchmakingNotEnabled,
            GenericErrorCodesMatchmakingPlayerAttributesTooLarge,
            GenericErrorCodesMatchmakingNumberOfPlayersInTicketTooLarge,
            GenericErrorCodesMatchmakingAttributeInvalid,
            GenericErrorCodesMatchmakingPlayerHasNotJoinedTicket,
            GenericErrorCodesMatchmakingRateLimitExceeded,
            GenericErrorCodesMatchmakingTicketMembershipLimitExceeded,
            GenericErrorCodesMatchmakingUnauthorized,
            GenericErrorCodesMatchmakingQueueLimitExceeded,
            GenericErrorCodesMatchmakingRequestTypeMismatch,
            GenericErrorCodesMatchmakingBadRequest,
            GenericErrorCodesTitleConfigNotFound,
            GenericErrorCodesTitleConfigUpdateConflict,
            GenericErrorCodesTitleConfigSerializationError,
            GenericErrorCodesCatalogEntityInvalid,
            GenericErrorCodesCatalogTitleIdMissing,
            GenericErrorCodesCatalogPlayerIdMissing,
            GenericErrorCodesCatalogClientIdentityInvalid,
            GenericErrorCodesCatalogOneOrMoreFilesInvalid,
            GenericErrorCodesCatalogItemMetadataInvalid,
            GenericErrorCodesCatalogItemIdInvalid,
            GenericErrorCodesCatalogSearchParameterInvalid,
            GenericErrorCodesCatalogFeatureDisabled,
            GenericErrorCodesCatalogConfigInvalid,
            GenericErrorCodesCatalogUnauthorized,
            GenericErrorCodesCatalogItemTypeInvalid,
            GenericErrorCodesCatalogBadRequest,
            GenericErrorCodesCatalogTooManyRequests,
            GenericErrorCodesExportInvalidStatusUpdate,
            GenericErrorCodesExportInvalidPrefix,
            GenericErrorCodesExportBlobContainerDoesNotExist,
            GenericErrorCodesExportNotFound,
            GenericErrorCodesExportCouldNotUpdate,
            GenericErrorCodesExportInvalidStorageType,
            GenericErrorCodesExportAmazonBucketDoesNotExist,
            GenericErrorCodesExportInvalidBlobStorage,
            GenericErrorCodesExportKustoException,
            GenericErrorCodesExportKustoConnectionFailed,
            GenericErrorCodesExportUnknownError,
            GenericErrorCodesExportCantEditPendingExport,
            GenericErrorCodesExportLimitExports,
            GenericErrorCodesExportLimitEvents,
            GenericErrorCodesExportInvalidPartitionStatusModification,
            GenericErrorCodesExportCouldNotCreate,
            GenericErrorCodesExportNoBackingDatabaseFound,
            GenericErrorCodesExportCouldNotDelete,
            GenericErrorCodesExportCannotDetermineEventQuery,
            GenericErrorCodesExportInvalidQuerySchemaModification,
            GenericErrorCodesExportQuerySchemaMissingRequiredColumns,
            GenericErrorCodesExportCannotParseQuery,
            GenericErrorCodesExportControlCommandsNotAllowed,
            GenericErrorCodesExportQueryMissingTableReference,
            GenericErrorCodesTitleNotEnabledForParty,
            GenericErrorCodesPartyVersionNotFound,
            GenericErrorCodesMultiplayerServerBuildReferencedByMatchmakingQueue,
            GenericErrorCodesExperimentationExperimentStopped,
            GenericErrorCodesExperimentationExperimentRunning,
            GenericErrorCodesExperimentationExperimentNotFound,
            GenericErrorCodesExperimentationExperimentNeverStarted,
            GenericErrorCodesExperimentationExperimentDeleted,
            GenericErrorCodesExperimentationClientTimeout,
            GenericErrorCodesExperimentationInvalidVariantConfiguration,
            GenericErrorCodesExperimentationInvalidVariableConfiguration,
            GenericErrorCodesExperimentInvalidId,
            GenericErrorCodesExperimentationNoScorecard,
            GenericErrorCodesExperimentationTreatmentAssignmentFailed,
            GenericErrorCodesExperimentationTreatmentAssignmentDisabled,
            GenericErrorCodesExperimentationInvalidDuration,
            GenericErrorCodesExperimentationMaxExperimentsReached,
            GenericErrorCodesExperimentationExperimentSchedulingInProgress,
            GenericErrorCodesExperimentationInvalidEndDate,
            GenericErrorCodesExperimentationInvalidStartDate,
            GenericErrorCodesExperimentationMaxDurationExceeded,
            GenericErrorCodesExperimentationExclusionGroupNotFound,
            GenericErrorCodesExperimentationExclusionGroupInsufficientCapacity,
            GenericErrorCodesExperimentationExclusionGroupCannotDelete,
            GenericErrorCodesExperimentationExclusionGroupInvalidTrafficAllocation,
            GenericErrorCodesMaxActionDepthExceeded,
            GenericErrorCodesTitleNotOnUpdatedPricingPlan,
            GenericErrorCodesSegmentManagementTitleNotInFlight,
            GenericErrorCodesSegmentManagementNoExpressionTree,
            GenericErrorCodesSegmentManagementTriggerActionCountOverLimit,
            GenericErrorCodesSegmentManagementSegmentCountOverLimit,
            GenericErrorCodesSegmentManagementInvalidSegmentId,
            GenericErrorCodesSegmentManagementInvalidInput,
            GenericErrorCodesSegmentManagementInvalidSegmentName,
            GenericErrorCodesSnapshotNotFound
        };

        void writeGenericErrorCodesEnumJSON(GenericErrorCodes enumVal, PFStringJsonWriter& writer);
        GenericErrorCodes readGenericErrorCodesFromValue(const rapidjson::Value& obj);

        struct GetActionsOnPlayersInSegmentTaskInstanceResult : public PlayFabBaseModel
        {
            ActionsOnPlayersInSegmentTaskParameter* Parameter;
            ActionsOnPlayersInSegmentTaskSummary* Summary;

            GetActionsOnPlayersInSegmentTaskInstanceResult() :
                PlayFabBaseModel(),
                Parameter(NULL),
                Summary(NULL)
            {}

            GetActionsOnPlayersInSegmentTaskInstanceResult(const GetActionsOnPlayersInSegmentTaskInstanceResult& src) :
                PlayFabBaseModel(),
                Parameter(src.Parameter ? new ActionsOnPlayersInSegmentTaskParameter(*src.Parameter) : NULL),
                Summary(src.Summary ? new ActionsOnPlayersInSegmentTaskSummary(*src.Summary) : NULL)
            {}

            GetActionsOnPlayersInSegmentTaskInstanceResult(const rapidjson::Value& obj) : GetActionsOnPlayersInSegmentTaskInstanceResult()
            {
                readFromValue(obj);
            }

            ~GetActionsOnPlayersInSegmentTaskInstanceResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAllSegmentsRequest : public PlayFabBaseModel
        {

            GetAllSegmentsRequest() :
                PlayFabBaseModel()
            {}

            GetAllSegmentsRequest(const GetAllSegmentsRequest& src) :
                PlayFabBaseModel()
            {}

            GetAllSegmentsRequest(const rapidjson::Value& obj) : GetAllSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetAllSegmentsRequest();

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

        struct GetAllSegmentsResult : public PlayFabBaseModel
        {
            std::list<GetSegmentResult> Segments;

            GetAllSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetAllSegmentsResult(const GetAllSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetAllSegmentsResult(const rapidjson::Value& obj) : GetAllSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetAllSegmentsResult();

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

        struct GetCloudScriptRevisionRequest : public PlayFabBaseModel
        {
            OptionalInt32 Revision;
            OptionalInt32 Version;

            GetCloudScriptRevisionRequest() :
                PlayFabBaseModel(),
                Revision(),
                Version()
            {}

            GetCloudScriptRevisionRequest(const GetCloudScriptRevisionRequest& src) :
                PlayFabBaseModel(),
                Revision(src.Revision),
                Version(src.Version)
            {}

            GetCloudScriptRevisionRequest(const rapidjson::Value& obj) : GetCloudScriptRevisionRequest()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptRevisionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCloudScriptRevisionResult : public PlayFabBaseModel
        {
            time_t CreatedAt;
            std::list<CloudScriptFile> Files;
            bool IsPublished;
            Int32 Revision;
            Int32 Version;

            GetCloudScriptRevisionResult() :
                PlayFabBaseModel(),
                CreatedAt(0),
                Files(),
                IsPublished(false),
                Revision(0),
                Version(0)
            {}

            GetCloudScriptRevisionResult(const GetCloudScriptRevisionResult& src) :
                PlayFabBaseModel(),
                CreatedAt(src.CreatedAt),
                Files(src.Files),
                IsPublished(src.IsPublished),
                Revision(src.Revision),
                Version(src.Version)
            {}

            GetCloudScriptRevisionResult(const rapidjson::Value& obj) : GetCloudScriptRevisionResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptRevisionResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCloudScriptTaskInstanceResult : public PlayFabBaseModel
        {
            CloudScriptTaskParameter* Parameter;
            CloudScriptTaskSummary* Summary;

            GetCloudScriptTaskInstanceResult() :
                PlayFabBaseModel(),
                Parameter(NULL),
                Summary(NULL)
            {}

            GetCloudScriptTaskInstanceResult(const GetCloudScriptTaskInstanceResult& src) :
                PlayFabBaseModel(),
                Parameter(src.Parameter ? new CloudScriptTaskParameter(*src.Parameter) : NULL),
                Summary(src.Summary ? new CloudScriptTaskSummary(*src.Summary) : NULL)
            {}

            GetCloudScriptTaskInstanceResult(const rapidjson::Value& obj) : GetCloudScriptTaskInstanceResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptTaskInstanceResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCloudScriptVersionsRequest : public PlayFabBaseModel
        {

            GetCloudScriptVersionsRequest() :
                PlayFabBaseModel()
            {}

            GetCloudScriptVersionsRequest(const GetCloudScriptVersionsRequest& src) :
                PlayFabBaseModel()
            {}

            GetCloudScriptVersionsRequest(const rapidjson::Value& obj) : GetCloudScriptVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptVersionsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetCloudScriptVersionsResult : public PlayFabBaseModel
        {
            std::list<CloudScriptVersionStatus> Versions;

            GetCloudScriptVersionsResult() :
                PlayFabBaseModel(),
                Versions()
            {}

            GetCloudScriptVersionsResult(const GetCloudScriptVersionsResult& src) :
                PlayFabBaseModel(),
                Versions(src.Versions)
            {}

            GetCloudScriptVersionsResult(const rapidjson::Value& obj) : GetCloudScriptVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptVersionsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContentListRequest : public PlayFabBaseModel
        {
            std::string Prefix;

            GetContentListRequest() :
                PlayFabBaseModel(),
                Prefix()
            {}

            GetContentListRequest(const GetContentListRequest& src) :
                PlayFabBaseModel(),
                Prefix(src.Prefix)
            {}

            GetContentListRequest(const rapidjson::Value& obj) : GetContentListRequest()
            {
                readFromValue(obj);
            }

            ~GetContentListRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContentListResult : public PlayFabBaseModel
        {
            std::list<ContentInfo> Contents;
            Int32 ItemCount;
            Uint32 TotalSize;

            GetContentListResult() :
                PlayFabBaseModel(),
                Contents(),
                ItemCount(0),
                TotalSize(0)
            {}

            GetContentListResult(const GetContentListResult& src) :
                PlayFabBaseModel(),
                Contents(src.Contents),
                ItemCount(src.ItemCount),
                TotalSize(src.TotalSize)
            {}

            GetContentListResult(const rapidjson::Value& obj) : GetContentListResult()
            {
                readFromValue(obj);
            }

            ~GetContentListResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContentUploadUrlRequest : public PlayFabBaseModel
        {
            std::string ContentType;
            std::string Key;

            GetContentUploadUrlRequest() :
                PlayFabBaseModel(),
                ContentType(),
                Key()
            {}

            GetContentUploadUrlRequest(const GetContentUploadUrlRequest& src) :
                PlayFabBaseModel(),
                ContentType(src.ContentType),
                Key(src.Key)
            {}

            GetContentUploadUrlRequest(const rapidjson::Value& obj) : GetContentUploadUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetContentUploadUrlRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContentUploadUrlResult : public PlayFabBaseModel
        {
            std::string URL;

            GetContentUploadUrlResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetContentUploadUrlResult(const GetContentUploadUrlResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetContentUploadUrlResult(const rapidjson::Value& obj) : GetContentUploadUrlResult()
            {
                readFromValue(obj);
            }

            ~GetContentUploadUrlResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetDataReportRequest : public PlayFabBaseModel
        {
            Int32 Day;
            Int32 Month;
            std::string ReportName;
            Int32 Year;

            GetDataReportRequest() :
                PlayFabBaseModel(),
                Day(0),
                Month(0),
                ReportName(),
                Year(0)
            {}

            GetDataReportRequest(const GetDataReportRequest& src) :
                PlayFabBaseModel(),
                Day(src.Day),
                Month(src.Month),
                ReportName(src.ReportName),
                Year(src.Year)
            {}

            GetDataReportRequest(const rapidjson::Value& obj) : GetDataReportRequest()
            {
                readFromValue(obj);
            }

            ~GetDataReportRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetDataReportResult : public PlayFabBaseModel
        {
            std::string DownloadUrl;

            GetDataReportResult() :
                PlayFabBaseModel(),
                DownloadUrl()
            {}

            GetDataReportResult(const GetDataReportResult& src) :
                PlayFabBaseModel(),
                DownloadUrl(src.DownloadUrl)
            {}

            GetDataReportResult(const rapidjson::Value& obj) : GetDataReportResult()
            {
                readFromValue(obj);
            }

            ~GetDataReportResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetMatchmakerGameInfoRequest : public PlayFabBaseModel
        {
            std::string LobbyId;

            GetMatchmakerGameInfoRequest() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            GetMatchmakerGameInfoRequest(const GetMatchmakerGameInfoRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            GetMatchmakerGameInfoRequest(const rapidjson::Value& obj) : GetMatchmakerGameInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetMatchmakerGameInfoResult : public PlayFabBaseModel
        {
            std::string BuildVersion;
            OptionalTime EndTime;
            std::string LobbyId;
            std::string Mode;
            std::list<std::string> Players;
            Boxed<Region> pfRegion;
            std::string ServerIPV4Address;
            std::string ServerIPV6Address;
            Uint32 ServerPort;
            std::string ServerPublicDNSName;
            time_t StartTime;
            std::string TitleId;

            GetMatchmakerGameInfoResult() :
                PlayFabBaseModel(),
                BuildVersion(),
                EndTime(),
                LobbyId(),
                Mode(),
                Players(),
                pfRegion(),
                ServerIPV4Address(),
                ServerIPV6Address(),
                ServerPort(0),
                ServerPublicDNSName(),
                StartTime(0),
                TitleId()
            {}

            GetMatchmakerGameInfoResult(const GetMatchmakerGameInfoResult& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                EndTime(src.EndTime),
                LobbyId(src.LobbyId),
                Mode(src.Mode),
                Players(src.Players),
                pfRegion(src.pfRegion),
                ServerIPV4Address(src.ServerIPV4Address),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                ServerPublicDNSName(src.ServerPublicDNSName),
                StartTime(src.StartTime),
                TitleId(src.TitleId)
            {}

            GetMatchmakerGameInfoResult(const rapidjson::Value& obj) : GetMatchmakerGameInfoResult()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameInfoResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetMatchmakerGameModesRequest : public PlayFabBaseModel
        {
            std::string BuildVersion;

            GetMatchmakerGameModesRequest() :
                PlayFabBaseModel(),
                BuildVersion()
            {}

            GetMatchmakerGameModesRequest(const GetMatchmakerGameModesRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion)
            {}

            GetMatchmakerGameModesRequest(const rapidjson::Value& obj) : GetMatchmakerGameModesRequest()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameModesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetMatchmakerGameModesResult : public PlayFabBaseModel
        {
            std::list<GameModeInfo> GameModes;

            GetMatchmakerGameModesResult() :
                PlayFabBaseModel(),
                GameModes()
            {}

            GetMatchmakerGameModesResult(const GetMatchmakerGameModesResult& src) :
                PlayFabBaseModel(),
                GameModes(src.GameModes)
            {}

            GetMatchmakerGameModesResult(const rapidjson::Value& obj) : GetMatchmakerGameModesResult()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameModesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayedTitleListRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            GetPlayedTitleListRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetPlayedTitleListRequest(const GetPlayedTitleListRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayedTitleListRequest(const rapidjson::Value& obj) : GetPlayedTitleListRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayedTitleListRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayedTitleListResult : public PlayFabBaseModel
        {
            std::list<std::string> TitleIds;

            GetPlayedTitleListResult() :
                PlayFabBaseModel(),
                TitleIds()
            {}

            GetPlayedTitleListResult(const GetPlayedTitleListResult& src) :
                PlayFabBaseModel(),
                TitleIds(src.TitleIds)
            {}

            GetPlayedTitleListResult(const rapidjson::Value& obj) : GetPlayedTitleListResult()
            {
                readFromValue(obj);
            }

            ~GetPlayedTitleListResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerIdFromAuthTokenRequest : public PlayFabBaseModel
        {
            std::string Token;
            AuthTokenType TokenType;

            GetPlayerIdFromAuthTokenRequest() :
                PlayFabBaseModel(),
                Token(),
                TokenType()
            {}

            GetPlayerIdFromAuthTokenRequest(const GetPlayerIdFromAuthTokenRequest& src) :
                PlayFabBaseModel(),
                Token(src.Token),
                TokenType(src.TokenType)
            {}

            GetPlayerIdFromAuthTokenRequest(const rapidjson::Value& obj) : GetPlayerIdFromAuthTokenRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerIdFromAuthTokenRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerIdFromAuthTokenResult : public PlayFabBaseModel
        {
            std::string PlayFabId;

            GetPlayerIdFromAuthTokenResult() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetPlayerIdFromAuthTokenResult(const GetPlayerIdFromAuthTokenResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayerIdFromAuthTokenResult(const rapidjson::Value& obj) : GetPlayerIdFromAuthTokenResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerIdFromAuthTokenResult();

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

        struct GetPlayerSharedSecretsRequest : public PlayFabBaseModel
        {

            GetPlayerSharedSecretsRequest() :
                PlayFabBaseModel()
            {}

            GetPlayerSharedSecretsRequest(const GetPlayerSharedSecretsRequest& src) :
                PlayFabBaseModel()
            {}

            GetPlayerSharedSecretsRequest(const rapidjson::Value& obj) : GetPlayerSharedSecretsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerSharedSecretsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SharedSecret : public PlayFabBaseModel
        {
            bool Disabled;
            std::string FriendlyName;
            std::string SecretKey;

            SharedSecret() :
                PlayFabBaseModel(),
                Disabled(false),
                FriendlyName(),
                SecretKey()
            {}

            SharedSecret(const SharedSecret& src) :
                PlayFabBaseModel(),
                Disabled(src.Disabled),
                FriendlyName(src.FriendlyName),
                SecretKey(src.SecretKey)
            {}

            SharedSecret(const rapidjson::Value& obj) : SharedSecret()
            {
                readFromValue(obj);
            }

            ~SharedSecret();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerSharedSecretsResult : public PlayFabBaseModel
        {
            std::list<SharedSecret> SharedSecrets;

            GetPlayerSharedSecretsResult() :
                PlayFabBaseModel(),
                SharedSecrets()
            {}

            GetPlayerSharedSecretsResult(const GetPlayerSharedSecretsResult& src) :
                PlayFabBaseModel(),
                SharedSecrets(src.SharedSecrets)
            {}

            GetPlayerSharedSecretsResult(const rapidjson::Value& obj) : GetPlayerSharedSecretsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerSharedSecretsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayersInSegmentRequest : public PlayFabBaseModel
        {
            std::string ContinuationToken;
            std::map<std::string, std::string> CustomTags;
            OptionalUint32 MaxBatchSize;
            OptionalUint32 SecondsToLive;
            std::string SegmentId;

            GetPlayersInSegmentRequest() :
                PlayFabBaseModel(),
                ContinuationToken(),
                CustomTags(),
                MaxBatchSize(),
                SecondsToLive(),
                SegmentId()
            {}

            GetPlayersInSegmentRequest(const GetPlayersInSegmentRequest& src) :
                PlayFabBaseModel(),
                ContinuationToken(src.ContinuationToken),
                CustomTags(src.CustomTags),
                MaxBatchSize(src.MaxBatchSize),
                SecondsToLive(src.SecondsToLive),
                SegmentId(src.SegmentId)
            {}

            GetPlayersInSegmentRequest(const rapidjson::Value& obj) : GetPlayersInSegmentRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLinkedAccount : public PlayFabBaseModel
        {
            std::string Email;
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;

            PlayerLinkedAccount() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            PlayerLinkedAccount(const PlayerLinkedAccount& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            PlayerLinkedAccount(const rapidjson::Value& obj) : PlayerLinkedAccount()
            {
                readFromValue(obj);
            }

            ~PlayerLinkedAccount();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLocation : public PlayFabBaseModel
        {
            std::string City;
            ContinentCode pfContinentCode;
            CountryCode pfCountryCode;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            PlayerLocation() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            PlayerLocation(const PlayerLocation& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            PlayerLocation(const rapidjson::Value& obj) : PlayerLocation()
            {
                readFromValue(obj);
            }

            ~PlayerLocation();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerStatistic : public PlayFabBaseModel
        {
            std::string Id;
            std::string Name;
            Int32 StatisticValue;
            Int32 StatisticVersion;

            PlayerStatistic() :
                PlayFabBaseModel(),
                Id(),
                Name(),
                StatisticValue(0),
                StatisticVersion(0)
            {}

            PlayerStatistic(const PlayerStatistic& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name),
                StatisticValue(src.StatisticValue),
                StatisticVersion(src.StatisticVersion)
            {}

            PlayerStatistic(const rapidjson::Value& obj) : PlayerStatistic()
            {
                readFromValue(obj);
            }

            ~PlayerStatistic();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PushNotificationRegistration : public PlayFabBaseModel
        {
            std::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistration() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistration(const PushNotificationRegistration& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            PushNotificationRegistration(const rapidjson::Value& obj) : PushNotificationRegistration()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistration();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerProfile : public PlayFabBaseModel
        {
            std::list<AdCampaignAttribution> AdCampaignAttributions;
            std::string AvatarUrl;
            OptionalTime BannedUntil;
            std::list<ContactEmailInfo> ContactEmailAddresses;
            OptionalTime Created;
            std::string DisplayName;
            OptionalTime LastLogin;
            std::list<PlayerLinkedAccount> LinkedAccounts;
            std::map<std::string, PlayerLocation> Locations;
            Boxed<LoginIdentityProvider> Origination;
            std::list<std::string> PlayerExperimentVariants;
            std::string PlayerId;
            std::list<PlayerStatistic> PlayerStatistics;
            std::string PublisherId;
            std::list<PushNotificationRegistration> PushNotificationRegistrations;
            std::map<std::string, Int32> Statistics;
            std::list<std::string> Tags;
            std::string TitleId;
            OptionalUint32 TotalValueToDateInUSD;
            std::map<std::string, Uint32> ValuesToDate;
            std::map<std::string, Int32> VirtualCurrencyBalances;

            PlayerProfile() :
                PlayFabBaseModel(),
                AdCampaignAttributions(),
                AvatarUrl(),
                BannedUntil(),
                ContactEmailAddresses(),
                Created(),
                DisplayName(),
                LastLogin(),
                LinkedAccounts(),
                Locations(),
                Origination(),
                PlayerExperimentVariants(),
                PlayerId(),
                PlayerStatistics(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                VirtualCurrencyBalances()
            {}

            PlayerProfile(const PlayerProfile& src) :
                PlayFabBaseModel(),
                AdCampaignAttributions(src.AdCampaignAttributions),
                AvatarUrl(src.AvatarUrl),
                BannedUntil(src.BannedUntil),
                ContactEmailAddresses(src.ContactEmailAddresses),
                Created(src.Created),
                DisplayName(src.DisplayName),
                LastLogin(src.LastLogin),
                LinkedAccounts(src.LinkedAccounts),
                Locations(src.Locations),
                Origination(src.Origination),
                PlayerExperimentVariants(src.PlayerExperimentVariants),
                PlayerId(src.PlayerId),
                PlayerStatistics(src.PlayerStatistics),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            PlayerProfile(const rapidjson::Value& obj) : PlayerProfile()
            {
                readFromValue(obj);
            }

            ~PlayerProfile();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayersInSegmentResult : public PlayFabBaseModel
        {
            std::string ContinuationToken;
            std::list<PlayerProfile> PlayerProfiles;
            Int32 ProfilesInSegment;

            GetPlayersInSegmentResult() :
                PlayFabBaseModel(),
                ContinuationToken(),
                PlayerProfiles(),
                ProfilesInSegment(0)
            {}

            GetPlayersInSegmentResult(const GetPlayersInSegmentResult& src) :
                PlayFabBaseModel(),
                ContinuationToken(src.ContinuationToken),
                PlayerProfiles(src.PlayerProfiles),
                ProfilesInSegment(src.ProfilesInSegment)
            {}

            GetPlayersInSegmentResult(const rapidjson::Value& obj) : GetPlayersInSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayersSegmentsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string PlayFabId;

            GetPlayersSegmentsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                PlayFabId()
            {}

            GetPlayersSegmentsRequest(const GetPlayersSegmentsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayersSegmentsRequest(const rapidjson::Value& obj) : GetPlayersSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersSegmentsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticDefinitionsRequest : public PlayFabBaseModel
        {

            GetPlayerStatisticDefinitionsRequest() :
                PlayFabBaseModel()
            {}

            GetPlayerStatisticDefinitionsRequest(const GetPlayerStatisticDefinitionsRequest& src) :
                PlayFabBaseModel()
            {}

            GetPlayerStatisticDefinitionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticDefinitionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticDefinitionsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPlayerStatisticDefinitionsResult : public PlayFabBaseModel
        {
            std::list<PlayerStatisticDefinition> Statistics;

            GetPlayerStatisticDefinitionsResult() :
                PlayFabBaseModel(),
                Statistics()
            {}

            GetPlayerStatisticDefinitionsResult(const GetPlayerStatisticDefinitionsResult& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            GetPlayerStatisticDefinitionsResult(const rapidjson::Value& obj) : GetPlayerStatisticDefinitionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticDefinitionsResult();

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

        enum StatisticVersionStatus
        {
            StatisticVersionStatusActive,
            StatisticVersionStatusSnapshotPending,
            StatisticVersionStatusSnapshot,
            StatisticVersionStatusArchivalPending,
            StatisticVersionStatusArchived
        };

        void writeStatisticVersionStatusEnumJSON(StatisticVersionStatus enumVal, PFStringJsonWriter& writer);
        StatisticVersionStatus readStatisticVersionStatusFromValue(const rapidjson::Value& obj);

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            time_t ActivationTime;
            std::string ArchiveDownloadUrl;
            OptionalTime DeactivationTime;
            OptionalTime ScheduledActivationTime;
            OptionalTime ScheduledDeactivationTime;
            std::string StatisticName;
            Boxed<StatisticVersionStatus> Status;
            Uint32 Version;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                ActivationTime(0),
                ArchiveDownloadUrl(),
                DeactivationTime(),
                ScheduledActivationTime(),
                ScheduledDeactivationTime(),
                StatisticName(),
                Status(),
                Version(0)
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                ActivationTime(src.ActivationTime),
                ArchiveDownloadUrl(src.ArchiveDownloadUrl),
                DeactivationTime(src.DeactivationTime),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                StatisticName(src.StatisticName),
                Status(src.Status),
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

        struct GetPolicyRequest : public PlayFabBaseModel
        {
            std::string PolicyName;

            GetPolicyRequest() :
                PlayFabBaseModel(),
                PolicyName()
            {}

            GetPolicyRequest(const GetPolicyRequest& src) :
                PlayFabBaseModel(),
                PolicyName(src.PolicyName)
            {}

            GetPolicyRequest(const rapidjson::Value& obj) : GetPolicyRequest()
            {
                readFromValue(obj);
            }

            ~GetPolicyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PermissionStatement : public PlayFabBaseModel
        {
            std::string Action;
            ApiCondition* ApiConditions;
            std::string Comment;
            EffectType Effect;
            std::string Principal;
            std::string Resource;

            PermissionStatement() :
                PlayFabBaseModel(),
                Action(),
                ApiConditions(NULL),
                Comment(),
                Effect(),
                Principal(),
                Resource()
            {}

            PermissionStatement(const PermissionStatement& src) :
                PlayFabBaseModel(),
                Action(src.Action),
                ApiConditions(src.ApiConditions ? new ApiCondition(*src.ApiConditions) : NULL),
                Comment(src.Comment),
                Effect(src.Effect),
                Principal(src.Principal),
                Resource(src.Resource)
            {}

            PermissionStatement(const rapidjson::Value& obj) : PermissionStatement()
            {
                readFromValue(obj);
            }

            ~PermissionStatement();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetPolicyResponse : public PlayFabBaseModel
        {
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            GetPolicyResponse() :
                PlayFabBaseModel(),
                PolicyName(),
                Statements()
            {}

            GetPolicyResponse(const GetPolicyResponse& src) :
                PlayFabBaseModel(),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            GetPolicyResponse(const rapidjson::Value& obj) : GetPolicyResponse()
            {
                readFromValue(obj);
            }

            ~GetPolicyResponse();

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

        struct GetRandomResultTablesRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;

            GetRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion()
            {}

            GetRandomResultTablesRequest(const GetRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion)
            {}

            GetRandomResultTablesRequest(const rapidjson::Value& obj) : GetRandomResultTablesRequest()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        void writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer);
        ResultTableNodeType readResultTableNodeTypeFromValue(const rapidjson::Value& obj);

        struct ResultTableNode : public PlayFabBaseModel
        {
            std::string ResultItem;
            ResultTableNodeType ResultItemType;
            Int32 Weight;

            ResultTableNode() :
                PlayFabBaseModel(),
                ResultItem(),
                ResultItemType(),
                Weight(0)
            {}

            ResultTableNode(const ResultTableNode& src) :
                PlayFabBaseModel(),
                ResultItem(src.ResultItem),
                ResultItemType(src.ResultItemType),
                Weight(src.Weight)
            {}

            ResultTableNode(const rapidjson::Value& obj) : ResultTableNode()
            {
                readFromValue(obj);
            }

            ~ResultTableNode();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RandomResultTableListing : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::list<ResultTableNode> Nodes;
            std::string TableId;

            RandomResultTableListing() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Nodes(),
                TableId()
            {}

            RandomResultTableListing(const RandomResultTableListing& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                Nodes(src.Nodes),
                TableId(src.TableId)
            {}

            RandomResultTableListing(const rapidjson::Value& obj) : RandomResultTableListing()
            {
                readFromValue(obj);
            }

            ~RandomResultTableListing();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetRandomResultTablesResult : public PlayFabBaseModel
        {
            std::map<std::string, RandomResultTableListing> Tables;

            GetRandomResultTablesResult() :
                PlayFabBaseModel(),
                Tables()
            {}

            GetRandomResultTablesResult(const GetRandomResultTablesResult& src) :
                PlayFabBaseModel(),
                Tables(src.Tables)
            {}

            GetRandomResultTablesResult(const rapidjson::Value& obj) : GetRandomResultTablesResult()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetServerBuildInfoRequest : public PlayFabBaseModel
        {
            std::string BuildId;

            GetServerBuildInfoRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            GetServerBuildInfoRequest(const GetServerBuildInfoRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            GetServerBuildInfoRequest(const rapidjson::Value& obj) : GetServerBuildInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetServerBuildInfoRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetServerBuildInfoResult : public PlayFabBaseModel
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string Comment;
            std::string ErrorMessage;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            GetServerBuildInfoResult() :
                PlayFabBaseModel(),
                ActiveRegions(),
                BuildId(),
                Comment(),
                ErrorMessage(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                Status(),
                Timestamp(0),
                TitleId()
            {}

            GetServerBuildInfoResult(const GetServerBuildInfoResult& src) :
                PlayFabBaseModel(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                Comment(src.Comment),
                ErrorMessage(src.ErrorMessage),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            GetServerBuildInfoResult(const rapidjson::Value& obj) : GetServerBuildInfoResult()
            {
                readFromValue(obj);
            }

            ~GetServerBuildInfoResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetServerBuildUploadURLRequest : public PlayFabBaseModel
        {
            std::string BuildId;

            GetServerBuildUploadURLRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            GetServerBuildUploadURLRequest(const GetServerBuildUploadURLRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            GetServerBuildUploadURLRequest(const rapidjson::Value& obj) : GetServerBuildUploadURLRequest()
            {
                readFromValue(obj);
            }

            ~GetServerBuildUploadURLRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetServerBuildUploadURLResult : public PlayFabBaseModel
        {
            std::string URL;

            GetServerBuildUploadURLResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetServerBuildUploadURLResult(const GetServerBuildUploadURLResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetServerBuildUploadURLResult(const rapidjson::Value& obj) : GetServerBuildUploadURLResult()
            {
                readFromValue(obj);
            }

            ~GetServerBuildUploadURLResult();

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

        struct GetTaskInstanceRequest : public PlayFabBaseModel
        {
            std::string TaskInstanceId;

            GetTaskInstanceRequest() :
                PlayFabBaseModel(),
                TaskInstanceId()
            {}

            GetTaskInstanceRequest(const GetTaskInstanceRequest& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            GetTaskInstanceRequest(const rapidjson::Value& obj) : GetTaskInstanceRequest()
            {
                readFromValue(obj);
            }

            ~GetTaskInstanceRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTaskInstancesRequest : public PlayFabBaseModel
        {
            OptionalTime StartedAtRangeFrom;
            OptionalTime StartedAtRangeTo;
            Boxed<TaskInstanceStatus> StatusFilter;
            NameIdentifier* TaskIdentifier;

            GetTaskInstancesRequest() :
                PlayFabBaseModel(),
                StartedAtRangeFrom(),
                StartedAtRangeTo(),
                StatusFilter(),
                TaskIdentifier(NULL)
            {}

            GetTaskInstancesRequest(const GetTaskInstancesRequest& src) :
                PlayFabBaseModel(),
                StartedAtRangeFrom(src.StartedAtRangeFrom),
                StartedAtRangeTo(src.StartedAtRangeTo),
                StatusFilter(src.StatusFilter),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : NULL)
            {}

            GetTaskInstancesRequest(const rapidjson::Value& obj) : GetTaskInstancesRequest()
            {
                readFromValue(obj);
            }

            ~GetTaskInstancesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum ScheduledTaskType
        {
            ScheduledTaskTypeCloudScript,
            ScheduledTaskTypeActionsOnPlayerSegment,
            ScheduledTaskTypeCloudScriptAzureFunctions,
            ScheduledTaskTypeInsightsScheduledScaling
        };

        void writeScheduledTaskTypeEnumJSON(ScheduledTaskType enumVal, PFStringJsonWriter& writer);
        ScheduledTaskType readScheduledTaskTypeFromValue(const rapidjson::Value& obj);

        struct TaskInstanceBasicSummary : public PlayFabBaseModel
        {
            OptionalTime CompletedAt;
            std::string ErrorMessage;
            OptionalDouble EstimatedSecondsRemaining;
            OptionalDouble PercentComplete;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            NameIdentifier* TaskIdentifier;
            std::string TaskInstanceId;
            Boxed<ScheduledTaskType> Type;

            TaskInstanceBasicSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                ErrorMessage(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                ScheduledByUserId(),
                StartedAt(0),
                Status(),
                TaskIdentifier(NULL),
                TaskInstanceId(),
                Type()
            {}

            TaskInstanceBasicSummary(const TaskInstanceBasicSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                ErrorMessage(src.ErrorMessage),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : NULL),
                TaskInstanceId(src.TaskInstanceId),
                Type(src.Type)
            {}

            TaskInstanceBasicSummary(const rapidjson::Value& obj) : TaskInstanceBasicSummary()
            {
                readFromValue(obj);
            }

            ~TaskInstanceBasicSummary();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTaskInstancesResult : public PlayFabBaseModel
        {
            std::list<TaskInstanceBasicSummary> Summaries;

            GetTaskInstancesResult() :
                PlayFabBaseModel(),
                Summaries()
            {}

            GetTaskInstancesResult(const GetTaskInstancesResult& src) :
                PlayFabBaseModel(),
                Summaries(src.Summaries)
            {}

            GetTaskInstancesResult(const rapidjson::Value& obj) : GetTaskInstancesResult()
            {
                readFromValue(obj);
            }

            ~GetTaskInstancesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTasksRequest : public PlayFabBaseModel
        {
            NameIdentifier* Identifier;

            GetTasksRequest() :
                PlayFabBaseModel(),
                Identifier(NULL)
            {}

            GetTasksRequest(const GetTasksRequest& src) :
                PlayFabBaseModel(),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : NULL)
            {}

            GetTasksRequest(const rapidjson::Value& obj) : GetTasksRequest()
            {
                readFromValue(obj);
            }

            ~GetTasksRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ScheduledTask : public PlayFabBaseModel
        {
            std::string Description;
            bool IsActive;
            OptionalTime LastRunTime;
            std::string Name;
            OptionalTime NextRunTime;
            MultitypeVar Parameter;
            std::string Schedule;
            std::string TaskId;
            Boxed<ScheduledTaskType> Type;

            ScheduledTask() :
                PlayFabBaseModel(),
                Description(),
                IsActive(false),
                LastRunTime(),
                Name(),
                NextRunTime(),
                Parameter(),
                Schedule(),
                TaskId(),
                Type()
            {}

            ScheduledTask(const ScheduledTask& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                IsActive(src.IsActive),
                LastRunTime(src.LastRunTime),
                Name(src.Name),
                NextRunTime(src.NextRunTime),
                Parameter(src.Parameter),
                Schedule(src.Schedule),
                TaskId(src.TaskId),
                Type(src.Type)
            {}

            ScheduledTask(const rapidjson::Value& obj) : ScheduledTask()
            {
                readFromValue(obj);
            }

            ~ScheduledTask();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTasksResult : public PlayFabBaseModel
        {
            std::list<ScheduledTask> Tasks;

            GetTasksResult() :
                PlayFabBaseModel(),
                Tasks()
            {}

            GetTasksResult(const GetTasksResult& src) :
                PlayFabBaseModel(),
                Tasks(src.Tasks)
            {}

            GetTasksResult(const rapidjson::Value& obj) : GetTasksResult()
            {
                readFromValue(obj);
            }

            ~GetTasksResult();

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

        struct GetUserBansRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            GetUserBansRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserBansRequest(const GetUserBansRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetUserBansRequest(const rapidjson::Value& obj) : GetUserBansRequest()
            {
                readFromValue(obj);
            }

            ~GetUserBansRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetUserBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            GetUserBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            GetUserBansResult(const GetUserBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            GetUserBansResult(const rapidjson::Value& obj) : GetUserBansResult()
            {
                readFromValue(obj);
            }

            ~GetUserBansResult();

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

        struct GetUserDataResult : public PlayFabBaseModel
        {
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;
            std::string PlayFabId;

            GetUserDataResult() :
                PlayFabBaseModel(),
                Data(),
                DataVersion(0),
                PlayFabId()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                DataVersion(src.DataVersion),
                PlayFabId(src.PlayFabId)
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
            std::string PlayFabId;

            GetUserInventoryRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                PlayFabId()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId)
            {}

            GetUserInventoryRequest(const rapidjson::Value& obj) : GetUserInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryRequest();

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

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
            std::list<ItemInstance> Inventory;
            std::string PlayFabId;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                Inventory(),
                PlayFabId(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                Inventory(src.Inventory),
                PlayFabId(src.PlayFabId),
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

        struct GrantedItemInstance : public PlayFabBaseModel
        {
            std::string Annotation;
            std::list<std::string> BundleContents;
            std::string BundleParent;
            std::string CatalogVersion;
            std::string CharacterId;
            std::map<std::string, std::string> CustomData;
            std::string DisplayName;
            OptionalTime Expiration;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            std::string PlayFabId;
            OptionalTime PurchaseDate;
            OptionalInt32 RemainingUses;
            bool Result;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            OptionalInt32 UsesIncrementedBy;

            GrantedItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CharacterId(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PlayFabId(),
                PurchaseDate(),
                RemainingUses(),
                Result(false),
                UnitCurrency(),
                UnitPrice(0),
                UsesIncrementedBy()
            {}

            GrantedItemInstance(const GrantedItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                Result(src.Result),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
            {}

            GrantedItemInstance(const rapidjson::Value& obj) : GrantedItemInstance()
            {
                readFromValue(obj);
            }

            ~GrantedItemInstance();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ItemGrant : public PlayFabBaseModel
        {
            std::string Annotation;
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::string ItemId;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            ItemGrant() :
                PlayFabBaseModel(),
                Annotation(),
                CharacterId(),
                Data(),
                ItemId(),
                KeysToRemove(),
                PlayFabId()
            {}

            ItemGrant(const ItemGrant& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                CharacterId(src.CharacterId),
                Data(src.Data),
                ItemId(src.ItemId),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            ItemGrant(const rapidjson::Value& obj) : ItemGrant()
            {
                readFromValue(obj);
            }

            ~ItemGrant();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GrantItemsToUsersRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomTags;
            std::list<ItemGrant> ItemGrants;

            GrantItemsToUsersRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CustomTags(),
                ItemGrants()
            {}

            GrantItemsToUsersRequest(const GrantItemsToUsersRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
                ItemGrants(src.ItemGrants)
            {}

            GrantItemsToUsersRequest(const rapidjson::Value& obj) : GrantItemsToUsersRequest()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUsersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GrantItemsToUsersResult : public PlayFabBaseModel
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToUsersResult() :
                PlayFabBaseModel(),
                ItemGrantResults()
            {}

            GrantItemsToUsersResult(const GrantItemsToUsersResult& src) :
                PlayFabBaseModel(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            GrantItemsToUsersResult(const rapidjson::Value& obj) : GrantItemsToUsersResult()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUsersResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct IncrementLimitedEditionItemAvailabilityRequest : public PlayFabBaseModel
        {
            Int32 Amount;
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomTags;
            std::string ItemId;

            IncrementLimitedEditionItemAvailabilityRequest() :
                PlayFabBaseModel(),
                Amount(0),
                CatalogVersion(),
                CustomTags(),
                ItemId()
            {}

            IncrementLimitedEditionItemAvailabilityRequest(const IncrementLimitedEditionItemAvailabilityRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
                ItemId(src.ItemId)
            {}

            IncrementLimitedEditionItemAvailabilityRequest(const rapidjson::Value& obj) : IncrementLimitedEditionItemAvailabilityRequest()
            {
                readFromValue(obj);
            }

            ~IncrementLimitedEditionItemAvailabilityRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct IncrementLimitedEditionItemAvailabilityResult : public PlayFabBaseModel
        {

            IncrementLimitedEditionItemAvailabilityResult() :
                PlayFabBaseModel()
            {}

            IncrementLimitedEditionItemAvailabilityResult(const IncrementLimitedEditionItemAvailabilityResult& src) :
                PlayFabBaseModel()
            {}

            IncrementLimitedEditionItemAvailabilityResult(const rapidjson::Value& obj) : IncrementLimitedEditionItemAvailabilityResult()
            {
                readFromValue(obj);
            }

            ~IncrementLimitedEditionItemAvailabilityResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct IncrementPlayerStatisticVersionRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string StatisticName;

            IncrementPlayerStatisticVersionRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                StatisticName()
            {}

            IncrementPlayerStatisticVersionRequest(const IncrementPlayerStatisticVersionRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                StatisticName(src.StatisticName)
            {}

            IncrementPlayerStatisticVersionRequest(const rapidjson::Value& obj) : IncrementPlayerStatisticVersionRequest()
            {
                readFromValue(obj);
            }

            ~IncrementPlayerStatisticVersionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct IncrementPlayerStatisticVersionResult : public PlayFabBaseModel
        {
            PlayerStatisticVersion* StatisticVersion;

            IncrementPlayerStatisticVersionResult() :
                PlayFabBaseModel(),
                StatisticVersion(NULL)
            {}

            IncrementPlayerStatisticVersionResult(const IncrementPlayerStatisticVersionResult& src) :
                PlayFabBaseModel(),
                StatisticVersion(src.StatisticVersion ? new PlayerStatisticVersion(*src.StatisticVersion) : NULL)
            {}

            IncrementPlayerStatisticVersionResult(const rapidjson::Value& obj) : IncrementPlayerStatisticVersionResult()
            {
                readFromValue(obj);
            }

            ~IncrementPlayerStatisticVersionResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListBuildsRequest : public PlayFabBaseModel
        {

            ListBuildsRequest() :
                PlayFabBaseModel()
            {}

            ListBuildsRequest(const ListBuildsRequest& src) :
                PlayFabBaseModel()
            {}

            ListBuildsRequest(const rapidjson::Value& obj) : ListBuildsRequest()
            {
                readFromValue(obj);
            }

            ~ListBuildsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListBuildsResult : public PlayFabBaseModel
        {
            std::list<GetServerBuildInfoResult> Builds;

            ListBuildsResult() :
                PlayFabBaseModel(),
                Builds()
            {}

            ListBuildsResult(const ListBuildsResult& src) :
                PlayFabBaseModel(),
                Builds(src.Builds)
            {}

            ListBuildsResult(const rapidjson::Value& obj) : ListBuildsResult()
            {
                readFromValue(obj);
            }

            ~ListBuildsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListOpenIdConnectionRequest : public PlayFabBaseModel
        {

            ListOpenIdConnectionRequest() :
                PlayFabBaseModel()
            {}

            ListOpenIdConnectionRequest(const ListOpenIdConnectionRequest& src) :
                PlayFabBaseModel()
            {}

            ListOpenIdConnectionRequest(const rapidjson::Value& obj) : ListOpenIdConnectionRequest()
            {
                readFromValue(obj);
            }

            ~ListOpenIdConnectionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct OpenIdConnection : public PlayFabBaseModel
        {
            std::string ClientId;
            std::string ClientSecret;
            std::string ConnectionId;
            bool DiscoverConfiguration;
            OpenIdIssuerInformation* IssuerInformation;

            OpenIdConnection() :
                PlayFabBaseModel(),
                ClientId(),
                ClientSecret(),
                ConnectionId(),
                DiscoverConfiguration(false),
                IssuerInformation(NULL)
            {}

            OpenIdConnection(const OpenIdConnection& src) :
                PlayFabBaseModel(),
                ClientId(src.ClientId),
                ClientSecret(src.ClientSecret),
                ConnectionId(src.ConnectionId),
                DiscoverConfiguration(src.DiscoverConfiguration),
                IssuerInformation(src.IssuerInformation ? new OpenIdIssuerInformation(*src.IssuerInformation) : NULL)
            {}

            OpenIdConnection(const rapidjson::Value& obj) : OpenIdConnection()
            {
                readFromValue(obj);
            }

            ~OpenIdConnection();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListOpenIdConnectionResponse : public PlayFabBaseModel
        {
            std::list<OpenIdConnection> Connections;

            ListOpenIdConnectionResponse() :
                PlayFabBaseModel(),
                Connections()
            {}

            ListOpenIdConnectionResponse(const ListOpenIdConnectionResponse& src) :
                PlayFabBaseModel(),
                Connections(src.Connections)
            {}

            ListOpenIdConnectionResponse(const rapidjson::Value& obj) : ListOpenIdConnectionResponse()
            {
                readFromValue(obj);
            }

            ~ListOpenIdConnectionResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListVirtualCurrencyTypesRequest : public PlayFabBaseModel
        {

            ListVirtualCurrencyTypesRequest() :
                PlayFabBaseModel()
            {}

            ListVirtualCurrencyTypesRequest(const ListVirtualCurrencyTypesRequest& src) :
                PlayFabBaseModel()
            {}

            ListVirtualCurrencyTypesRequest(const rapidjson::Value& obj) : ListVirtualCurrencyTypesRequest()
            {
                readFromValue(obj);
            }

            ~ListVirtualCurrencyTypesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListVirtualCurrencyTypesResult : public PlayFabBaseModel
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            ListVirtualCurrencyTypesResult() :
                PlayFabBaseModel(),
                VirtualCurrencies()
            {}

            ListVirtualCurrencyTypesResult(const ListVirtualCurrencyTypesResult& src) :
                PlayFabBaseModel(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ListVirtualCurrencyTypesResult(const rapidjson::Value& obj) : ListVirtualCurrencyTypesResult()
            {
                readFromValue(obj);
            }

            ~ListVirtualCurrencyTypesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LookupUserAccountInfoRequest : public PlayFabBaseModel
        {
            std::string Email;
            std::string PlayFabId;
            std::string TitleDisplayName;
            std::string Username;

            LookupUserAccountInfoRequest() :
                PlayFabBaseModel(),
                Email(),
                PlayFabId(),
                TitleDisplayName(),
                Username()
            {}

            LookupUserAccountInfoRequest(const LookupUserAccountInfoRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                PlayFabId(src.PlayFabId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            LookupUserAccountInfoRequest(const rapidjson::Value& obj) : LookupUserAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~LookupUserAccountInfoRequest();

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

        struct LookupUserAccountInfoResult : public PlayFabBaseModel
        {
            UserAccountInfo* UserInfo;

            LookupUserAccountInfoResult() :
                PlayFabBaseModel(),
                UserInfo(NULL)
            {}

            LookupUserAccountInfoResult(const LookupUserAccountInfoResult& src) :
                PlayFabBaseModel(),
                UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : NULL)
            {}

            LookupUserAccountInfoResult(const rapidjson::Value& obj) : LookupUserAccountInfoResult()
            {
                readFromValue(obj);
            }

            ~LookupUserAccountInfoResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ModifyMatchmakerGameModesRequest : public PlayFabBaseModel
        {
            std::string BuildVersion;
            std::list<GameModeInfo> GameModes;

            ModifyMatchmakerGameModesRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameModes()
            {}

            ModifyMatchmakerGameModesRequest(const ModifyMatchmakerGameModesRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameModes(src.GameModes)
            {}

            ModifyMatchmakerGameModesRequest(const rapidjson::Value& obj) : ModifyMatchmakerGameModesRequest()
            {
                readFromValue(obj);
            }

            ~ModifyMatchmakerGameModesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ModifyMatchmakerGameModesResult : public PlayFabBaseModel
        {

            ModifyMatchmakerGameModesResult() :
                PlayFabBaseModel()
            {}

            ModifyMatchmakerGameModesResult(const ModifyMatchmakerGameModesResult& src) :
                PlayFabBaseModel()
            {}

            ModifyMatchmakerGameModesResult(const rapidjson::Value& obj) : ModifyMatchmakerGameModesResult()
            {
                readFromValue(obj);
            }

            ~ModifyMatchmakerGameModesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ModifyServerBuildRequest : public PlayFabBaseModel
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::map<std::string, std::string> CustomTags;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            OptionalTime Timestamp;

            ModifyServerBuildRequest() :
                PlayFabBaseModel(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                CustomTags(),
                ExecutablePath(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                Timestamp()
            {}

            ModifyServerBuildRequest(const ModifyServerBuildRequest& src) :
                PlayFabBaseModel(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                CustomTags(src.CustomTags),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Timestamp(src.Timestamp)
            {}

            ModifyServerBuildRequest(const rapidjson::Value& obj) : ModifyServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~ModifyServerBuildRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ModifyServerBuildResult : public PlayFabBaseModel
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            ModifyServerBuildResult() :
                PlayFabBaseModel(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                Status(),
                Timestamp(0),
                TitleId()
            {}

            ModifyServerBuildResult(const ModifyServerBuildResult& src) :
                PlayFabBaseModel(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            ModifyServerBuildResult(const rapidjson::Value& obj) : ModifyServerBuildResult()
            {
                readFromValue(obj);
            }

            ~ModifyServerBuildResult();

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

        enum PushSetupPlatform
        {
            PushSetupPlatformGCM,
            PushSetupPlatformAPNS,
            PushSetupPlatformAPNS_SANDBOX
        };

        void writePushSetupPlatformEnumJSON(PushSetupPlatform enumVal, PFStringJsonWriter& writer);
        PushSetupPlatform readPushSetupPlatformFromValue(const rapidjson::Value& obj);

        struct RandomResultTable : public PlayFabBaseModel
        {
            std::list<ResultTableNode> Nodes;
            std::string TableId;

            RandomResultTable() :
                PlayFabBaseModel(),
                Nodes(),
                TableId()
            {}

            RandomResultTable(const RandomResultTable& src) :
                PlayFabBaseModel(),
                Nodes(src.Nodes),
                TableId(src.TableId)
            {}

            RandomResultTable(const rapidjson::Value& obj) : RandomResultTable()
            {
                readFromValue(obj);
            }

            ~RandomResultTable();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RefundPurchaseRequest : public PlayFabBaseModel
        {
            std::string OrderId;
            std::string PlayFabId;
            std::string Reason;

            RefundPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId(),
                PlayFabId(),
                Reason()
            {}

            RefundPurchaseRequest(const RefundPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            RefundPurchaseRequest(const rapidjson::Value& obj) : RefundPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~RefundPurchaseRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RefundPurchaseResponse : public PlayFabBaseModel
        {
            std::string PurchaseStatus;

            RefundPurchaseResponse() :
                PlayFabBaseModel(),
                PurchaseStatus()
            {}

            RefundPurchaseResponse(const RefundPurchaseResponse& src) :
                PlayFabBaseModel(),
                PurchaseStatus(src.PurchaseStatus)
            {}

            RefundPurchaseResponse(const rapidjson::Value& obj) : RefundPurchaseResponse()
            {
                readFromValue(obj);
            }

            ~RefundPurchaseResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemovePlayerTagRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string PlayFabId;
            std::string TagName;

            RemovePlayerTagRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                PlayFabId(),
                TagName()
            {}

            RemovePlayerTagRequest(const RemovePlayerTagRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            RemovePlayerTagRequest(const rapidjson::Value& obj) : RemovePlayerTagRequest()
            {
                readFromValue(obj);
            }

            ~RemovePlayerTagRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemovePlayerTagResult : public PlayFabBaseModel
        {

            RemovePlayerTagResult() :
                PlayFabBaseModel()
            {}

            RemovePlayerTagResult(const RemovePlayerTagResult& src) :
                PlayFabBaseModel()
            {}

            RemovePlayerTagResult(const rapidjson::Value& obj) : RemovePlayerTagResult()
            {
                readFromValue(obj);
            }

            ~RemovePlayerTagResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveServerBuildRequest : public PlayFabBaseModel
        {
            std::string BuildId;

            RemoveServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            RemoveServerBuildRequest(const RemoveServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            RemoveServerBuildRequest(const rapidjson::Value& obj) : RemoveServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~RemoveServerBuildRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveServerBuildResult : public PlayFabBaseModel
        {

            RemoveServerBuildResult() :
                PlayFabBaseModel()
            {}

            RemoveServerBuildResult(const RemoveServerBuildResult& src) :
                PlayFabBaseModel()
            {}

            RemoveServerBuildResult(const rapidjson::Value& obj) : RemoveServerBuildResult()
            {
                readFromValue(obj);
            }

            ~RemoveServerBuildResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RemoveVirtualCurrencyTypesRequest : public PlayFabBaseModel
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            RemoveVirtualCurrencyTypesRequest() :
                PlayFabBaseModel(),
                VirtualCurrencies()
            {}

            RemoveVirtualCurrencyTypesRequest(const RemoveVirtualCurrencyTypesRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            RemoveVirtualCurrencyTypesRequest(const rapidjson::Value& obj) : RemoveVirtualCurrencyTypesRequest()
            {
                readFromValue(obj);
            }

            ~RemoveVirtualCurrencyTypesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResetCharacterStatisticsRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::map<std::string, std::string> CustomTags;
            std::string PlayFabId;

            ResetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CustomTags(),
                PlayFabId()
            {}

            ResetCharacterStatisticsRequest(const ResetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId)
            {}

            ResetCharacterStatisticsRequest(const rapidjson::Value& obj) : ResetCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~ResetCharacterStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResetCharacterStatisticsResult : public PlayFabBaseModel
        {

            ResetCharacterStatisticsResult() :
                PlayFabBaseModel()
            {}

            ResetCharacterStatisticsResult(const ResetCharacterStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            ResetCharacterStatisticsResult(const rapidjson::Value& obj) : ResetCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~ResetCharacterStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResetPasswordRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string Password;
            std::string Token;

            ResetPasswordRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Password(),
                Token()
            {}

            ResetPasswordRequest(const ResetPasswordRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Password(src.Password),
                Token(src.Token)
            {}

            ResetPasswordRequest(const rapidjson::Value& obj) : ResetPasswordRequest()
            {
                readFromValue(obj);
            }

            ~ResetPasswordRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResetPasswordResult : public PlayFabBaseModel
        {

            ResetPasswordResult() :
                PlayFabBaseModel()
            {}

            ResetPasswordResult(const ResetPasswordResult& src) :
                PlayFabBaseModel()
            {}

            ResetPasswordResult(const rapidjson::Value& obj) : ResetPasswordResult()
            {
                readFromValue(obj);
            }

            ~ResetPasswordResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResetUserStatisticsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string PlayFabId;

            ResetUserStatisticsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                PlayFabId()
            {}

            ResetUserStatisticsRequest(const ResetUserStatisticsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId)
            {}

            ResetUserStatisticsRequest(const rapidjson::Value& obj) : ResetUserStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~ResetUserStatisticsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResetUserStatisticsResult : public PlayFabBaseModel
        {

            ResetUserStatisticsResult() :
                PlayFabBaseModel()
            {}

            ResetUserStatisticsResult(const ResetUserStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            ResetUserStatisticsResult(const rapidjson::Value& obj) : ResetUserStatisticsResult()
            {
                readFromValue(obj);
            }

            ~ResetUserStatisticsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum ResolutionOutcome
        {
            ResolutionOutcomeRevoke,
            ResolutionOutcomeReinstate,
            ResolutionOutcomeManual
        };

        void writeResolutionOutcomeEnumJSON(ResolutionOutcome enumVal, PFStringJsonWriter& writer);
        ResolutionOutcome readResolutionOutcomeFromValue(const rapidjson::Value& obj);

        struct ResolvePurchaseDisputeRequest : public PlayFabBaseModel
        {
            std::string OrderId;
            ResolutionOutcome Outcome;
            std::string PlayFabId;
            std::string Reason;

            ResolvePurchaseDisputeRequest() :
                PlayFabBaseModel(),
                OrderId(),
                Outcome(),
                PlayFabId(),
                Reason()
            {}

            ResolvePurchaseDisputeRequest(const ResolvePurchaseDisputeRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                Outcome(src.Outcome),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ResolvePurchaseDisputeRequest(const rapidjson::Value& obj) : ResolvePurchaseDisputeRequest()
            {
                readFromValue(obj);
            }

            ~ResolvePurchaseDisputeRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResolvePurchaseDisputeResponse : public PlayFabBaseModel
        {
            std::string PurchaseStatus;

            ResolvePurchaseDisputeResponse() :
                PlayFabBaseModel(),
                PurchaseStatus()
            {}

            ResolvePurchaseDisputeResponse(const ResolvePurchaseDisputeResponse& src) :
                PlayFabBaseModel(),
                PurchaseStatus(src.PurchaseStatus)
            {}

            ResolvePurchaseDisputeResponse(const rapidjson::Value& obj) : ResolvePurchaseDisputeResponse()
            {
                readFromValue(obj);
            }

            ~ResolvePurchaseDisputeResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeAllBansForUserRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            RevokeAllBansForUserRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            RevokeAllBansForUserRequest(const RevokeAllBansForUserRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            RevokeAllBansForUserRequest(const rapidjson::Value& obj) : RevokeAllBansForUserRequest()
            {
                readFromValue(obj);
            }

            ~RevokeAllBansForUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeAllBansForUserResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            RevokeAllBansForUserResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            RevokeAllBansForUserResult(const RevokeAllBansForUserResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            RevokeAllBansForUserResult(const rapidjson::Value& obj) : RevokeAllBansForUserResult()
            {
                readFromValue(obj);
            }

            ~RevokeAllBansForUserResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeBansRequest : public PlayFabBaseModel
        {
            std::list<std::string> BanIds;

            RevokeBansRequest() :
                PlayFabBaseModel(),
                BanIds()
            {}

            RevokeBansRequest(const RevokeBansRequest& src) :
                PlayFabBaseModel(),
                BanIds(src.BanIds)
            {}

            RevokeBansRequest(const rapidjson::Value& obj) : RevokeBansRequest()
            {
                readFromValue(obj);
            }

            ~RevokeBansRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            RevokeBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            RevokeBansResult(const RevokeBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            RevokeBansResult(const rapidjson::Value& obj) : RevokeBansResult()
            {
                readFromValue(obj);
            }

            ~RevokeBansResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeInventoryItem : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            RevokeInventoryItem() :
                PlayFabBaseModel(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            RevokeInventoryItem(const RevokeInventoryItem& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            RevokeInventoryItem(const rapidjson::Value& obj) : RevokeInventoryItem()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeInventoryItemRequest : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            RevokeInventoryItemRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            RevokeInventoryItemRequest(const RevokeInventoryItemRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            RevokeInventoryItemRequest(const rapidjson::Value& obj) : RevokeInventoryItemRequest()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItemRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeInventoryItemsRequest : public PlayFabBaseModel
        {
            std::list<RevokeInventoryItem> Items;

            RevokeInventoryItemsRequest() :
                PlayFabBaseModel(),
                Items()
            {}

            RevokeInventoryItemsRequest(const RevokeInventoryItemsRequest& src) :
                PlayFabBaseModel(),
                Items(src.Items)
            {}

            RevokeInventoryItemsRequest(const rapidjson::Value& obj) : RevokeInventoryItemsRequest()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItemsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeItemError : public PlayFabBaseModel
        {
            Boxed<GenericErrorCodes> Error;
            RevokeInventoryItem* Item;

            RevokeItemError() :
                PlayFabBaseModel(),
                Error(),
                Item(NULL)
            {}

            RevokeItemError(const RevokeItemError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Item(src.Item ? new RevokeInventoryItem(*src.Item) : NULL)
            {}

            RevokeItemError(const rapidjson::Value& obj) : RevokeItemError()
            {
                readFromValue(obj);
            }

            ~RevokeItemError();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeInventoryItemsResult : public PlayFabBaseModel
        {
            std::list<RevokeItemError> Errors;

            RevokeInventoryItemsResult() :
                PlayFabBaseModel(),
                Errors()
            {}

            RevokeInventoryItemsResult(const RevokeInventoryItemsResult& src) :
                PlayFabBaseModel(),
                Errors(src.Errors)
            {}

            RevokeInventoryItemsResult(const rapidjson::Value& obj) : RevokeInventoryItemsResult()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItemsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RevokeInventoryResult : public PlayFabBaseModel
        {

            RevokeInventoryResult() :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const RevokeInventoryResult& src) :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const rapidjson::Value& obj) : RevokeInventoryResult()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RunTaskRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            NameIdentifier* Identifier;

            RunTaskRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Identifier(NULL)
            {}

            RunTaskRequest(const RunTaskRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : NULL)
            {}

            RunTaskRequest(const rapidjson::Value& obj) : RunTaskRequest()
            {
                readFromValue(obj);
            }

            ~RunTaskRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RunTaskResult : public PlayFabBaseModel
        {
            std::string TaskInstanceId;

            RunTaskResult() :
                PlayFabBaseModel(),
                TaskInstanceId()
            {}

            RunTaskResult(const RunTaskResult& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            RunTaskResult(const rapidjson::Value& obj) : RunTaskResult()
            {
                readFromValue(obj);
            }

            ~RunTaskResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string Email;
            std::string EmailTemplateId;

            SendAccountRecoveryEmailRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Email(),
                EmailTemplateId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Email(src.Email),
                EmailTemplateId(src.EmailTemplateId)
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

        struct SetPlayerSecretRequest : public PlayFabBaseModel
        {
            std::string PlayerSecret;
            std::string PlayFabId;

            SetPlayerSecretRequest() :
                PlayFabBaseModel(),
                PlayerSecret(),
                PlayFabId()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabBaseModel(),
                PlayerSecret(src.PlayerSecret),
                PlayFabId(src.PlayFabId)
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

        struct SetPublishedRevisionRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            Int32 Revision;
            Int32 Version;

            SetPublishedRevisionRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Revision(0),
                Version(0)
            {}

            SetPublishedRevisionRequest(const SetPublishedRevisionRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Revision(src.Revision),
                Version(src.Version)
            {}

            SetPublishedRevisionRequest(const rapidjson::Value& obj) : SetPublishedRevisionRequest()
            {
                readFromValue(obj);
            }

            ~SetPublishedRevisionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetPublishedRevisionResult : public PlayFabBaseModel
        {

            SetPublishedRevisionResult() :
                PlayFabBaseModel()
            {}

            SetPublishedRevisionResult(const SetPublishedRevisionResult& src) :
                PlayFabBaseModel()
            {}

            SetPublishedRevisionResult(const rapidjson::Value& obj) : SetPublishedRevisionResult()
            {
                readFromValue(obj);
            }

            ~SetPublishedRevisionResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetPublisherDataRequest : public PlayFabBaseModel
        {
            std::string Key;
            std::string Value;

            SetPublisherDataRequest() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            SetPublisherDataRequest(const SetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            SetPublisherDataRequest(const rapidjson::Value& obj) : SetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~SetPublisherDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetPublisherDataResult : public PlayFabBaseModel
        {

            SetPublisherDataResult() :
                PlayFabBaseModel()
            {}

            SetPublisherDataResult(const SetPublisherDataResult& src) :
                PlayFabBaseModel()
            {}

            SetPublisherDataResult(const rapidjson::Value& obj) : SetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~SetPublisherDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct TitleDataKeyValue : public PlayFabBaseModel
        {
            std::string Key;
            std::string Value;

            TitleDataKeyValue() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            TitleDataKeyValue(const TitleDataKeyValue& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            TitleDataKeyValue(const rapidjson::Value& obj) : TitleDataKeyValue()
            {
                readFromValue(obj);
            }

            ~TitleDataKeyValue();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetTitleDataAndOverridesRequest : public PlayFabBaseModel
        {
            std::list<TitleDataKeyValue> KeyValues;
            std::string OverrideLabel;

            SetTitleDataAndOverridesRequest() :
                PlayFabBaseModel(),
                KeyValues(),
                OverrideLabel()
            {}

            SetTitleDataAndOverridesRequest(const SetTitleDataAndOverridesRequest& src) :
                PlayFabBaseModel(),
                KeyValues(src.KeyValues),
                OverrideLabel(src.OverrideLabel)
            {}

            SetTitleDataAndOverridesRequest(const rapidjson::Value& obj) : SetTitleDataAndOverridesRequest()
            {
                readFromValue(obj);
            }

            ~SetTitleDataAndOverridesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetTitleDataAndOverridesResult : public PlayFabBaseModel
        {

            SetTitleDataAndOverridesResult() :
                PlayFabBaseModel()
            {}

            SetTitleDataAndOverridesResult(const SetTitleDataAndOverridesResult& src) :
                PlayFabBaseModel()
            {}

            SetTitleDataAndOverridesResult(const rapidjson::Value& obj) : SetTitleDataAndOverridesResult()
            {
                readFromValue(obj);
            }

            ~SetTitleDataAndOverridesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetTitleDataRequest : public PlayFabBaseModel
        {
            std::string Key;
            std::string Value;

            SetTitleDataRequest() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            SetTitleDataRequest(const SetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            SetTitleDataRequest(const rapidjson::Value& obj) : SetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~SetTitleDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetTitleDataResult : public PlayFabBaseModel
        {

            SetTitleDataResult() :
                PlayFabBaseModel()
            {}

            SetTitleDataResult(const SetTitleDataResult& src) :
                PlayFabBaseModel()
            {}

            SetTitleDataResult(const rapidjson::Value& obj) : SetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~SetTitleDataResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetupPushNotificationRequest : public PlayFabBaseModel
        {
            std::string Credential;
            std::string Key;
            std::string Name;
            bool OverwriteOldARN;
            PushSetupPlatform Platform;

            SetupPushNotificationRequest() :
                PlayFabBaseModel(),
                Credential(),
                Key(),
                Name(),
                OverwriteOldARN(false),
                Platform()
            {}

            SetupPushNotificationRequest(const SetupPushNotificationRequest& src) :
                PlayFabBaseModel(),
                Credential(src.Credential),
                Key(src.Key),
                Name(src.Name),
                OverwriteOldARN(src.OverwriteOldARN),
                Platform(src.Platform)
            {}

            SetupPushNotificationRequest(const rapidjson::Value& obj) : SetupPushNotificationRequest()
            {
                readFromValue(obj);
            }

            ~SetupPushNotificationRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetupPushNotificationResult : public PlayFabBaseModel
        {
            std::string ARN;

            SetupPushNotificationResult() :
                PlayFabBaseModel(),
                ARN()
            {}

            SetupPushNotificationResult(const SetupPushNotificationResult& src) :
                PlayFabBaseModel(),
                ARN(src.ARN)
            {}

            SetupPushNotificationResult(const rapidjson::Value& obj) : SetupPushNotificationResult()
            {
                readFromValue(obj);
            }

            ~SetupPushNotificationResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum StatisticVersionArchivalStatus
        {
            StatisticVersionArchivalStatusNotScheduled,
            StatisticVersionArchivalStatusScheduled,
            StatisticVersionArchivalStatusQueued,
            StatisticVersionArchivalStatusInProgress,
            StatisticVersionArchivalStatusComplete
        };

        void writeStatisticVersionArchivalStatusEnumJSON(StatisticVersionArchivalStatus enumVal, PFStringJsonWriter& writer);
        StatisticVersionArchivalStatus readStatisticVersionArchivalStatusFromValue(const rapidjson::Value& obj);

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            Int32 Amount;
            std::map<std::string, std::string> CustomTags;
            std::string PlayFabId;
            std::string VirtualCurrency;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                Amount(0),
                CustomTags(),
                PlayFabId(),
                VirtualCurrency()
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                Amount(src.Amount),
                CustomTags(src.CustomTags),
                PlayFabId(src.PlayFabId),
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

        struct UpdateBanRequest : public PlayFabBaseModel
        {
            OptionalBool Active;
            std::string BanId;
            OptionalTime Expires;
            std::string IPAddress;
            std::string MACAddress;
            OptionalBool Permanent;
            std::string Reason;

            UpdateBanRequest() :
                PlayFabBaseModel(),
                Active(),
                BanId(),
                Expires(),
                IPAddress(),
                MACAddress(),
                Permanent(),
                Reason()
            {}

            UpdateBanRequest(const UpdateBanRequest& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                BanId(src.BanId),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Permanent(src.Permanent),
                Reason(src.Reason)
            {}

            UpdateBanRequest(const rapidjson::Value& obj) : UpdateBanRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBanRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateBansRequest : public PlayFabBaseModel
        {
            std::list<UpdateBanRequest> Bans;

            UpdateBansRequest() :
                PlayFabBaseModel(),
                Bans()
            {}

            UpdateBansRequest(const UpdateBansRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans)
            {}

            UpdateBansRequest(const rapidjson::Value& obj) : UpdateBansRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBansRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            UpdateBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            UpdateBansResult(const UpdateBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            UpdateBansResult(const rapidjson::Value& obj) : UpdateBansResult()
            {
                readFromValue(obj);
            }

            ~UpdateBansResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCatalogItemsRequest : public PlayFabBaseModel
        {
            std::list<CatalogItem> Catalog;
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomTags;
            OptionalBool SetAsDefaultCatalog;

            UpdateCatalogItemsRequest() :
                PlayFabBaseModel(),
                Catalog(),
                CatalogVersion(),
                CustomTags(),
                SetAsDefaultCatalog()
            {}

            UpdateCatalogItemsRequest(const UpdateCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                Catalog(src.Catalog),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
                SetAsDefaultCatalog(src.SetAsDefaultCatalog)
            {}

            UpdateCatalogItemsRequest(const rapidjson::Value& obj) : UpdateCatalogItemsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCatalogItemsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCatalogItemsResult : public PlayFabBaseModel
        {

            UpdateCatalogItemsResult() :
                PlayFabBaseModel()
            {}

            UpdateCatalogItemsResult(const UpdateCatalogItemsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateCatalogItemsResult(const rapidjson::Value& obj) : UpdateCatalogItemsResult()
            {
                readFromValue(obj);
            }

            ~UpdateCatalogItemsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCloudScriptRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string DeveloperPlayFabId;
            std::list<CloudScriptFile> Files;
            bool Publish;

            UpdateCloudScriptRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                DeveloperPlayFabId(),
                Files(),
                Publish(false)
            {}

            UpdateCloudScriptRequest(const UpdateCloudScriptRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                DeveloperPlayFabId(src.DeveloperPlayFabId),
                Files(src.Files),
                Publish(src.Publish)
            {}

            UpdateCloudScriptRequest(const rapidjson::Value& obj) : UpdateCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCloudScriptRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateCloudScriptResult : public PlayFabBaseModel
        {
            Int32 Revision;
            Int32 Version;

            UpdateCloudScriptResult() :
                PlayFabBaseModel(),
                Revision(0),
                Version(0)
            {}

            UpdateCloudScriptResult(const UpdateCloudScriptResult& src) :
                PlayFabBaseModel(),
                Revision(src.Revision),
                Version(src.Version)
            {}

            UpdateCloudScriptResult(const rapidjson::Value& obj) : UpdateCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~UpdateCloudScriptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateOpenIdConnectionRequest : public PlayFabBaseModel
        {
            std::string ClientId;
            std::string ClientSecret;
            std::string ConnectionId;
            std::string IssuerDiscoveryUrl;
            OpenIdIssuerInformation* IssuerInformation;

            UpdateOpenIdConnectionRequest() :
                PlayFabBaseModel(),
                ClientId(),
                ClientSecret(),
                ConnectionId(),
                IssuerDiscoveryUrl(),
                IssuerInformation(NULL)
            {}

            UpdateOpenIdConnectionRequest(const UpdateOpenIdConnectionRequest& src) :
                PlayFabBaseModel(),
                ClientId(src.ClientId),
                ClientSecret(src.ClientSecret),
                ConnectionId(src.ConnectionId),
                IssuerDiscoveryUrl(src.IssuerDiscoveryUrl),
                IssuerInformation(src.IssuerInformation ? new OpenIdIssuerInformation(*src.IssuerInformation) : NULL)
            {}

            UpdateOpenIdConnectionRequest(const rapidjson::Value& obj) : UpdateOpenIdConnectionRequest()
            {
                readFromValue(obj);
            }

            ~UpdateOpenIdConnectionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerSharedSecretRequest : public PlayFabBaseModel
        {
            bool Disabled;
            std::string FriendlyName;
            std::string SecretKey;

            UpdatePlayerSharedSecretRequest() :
                PlayFabBaseModel(),
                Disabled(false),
                FriendlyName(),
                SecretKey()
            {}

            UpdatePlayerSharedSecretRequest(const UpdatePlayerSharedSecretRequest& src) :
                PlayFabBaseModel(),
                Disabled(src.Disabled),
                FriendlyName(src.FriendlyName),
                SecretKey(src.SecretKey)
            {}

            UpdatePlayerSharedSecretRequest(const rapidjson::Value& obj) : UpdatePlayerSharedSecretRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerSharedSecretRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerSharedSecretResult : public PlayFabBaseModel
        {

            UpdatePlayerSharedSecretResult() :
                PlayFabBaseModel()
            {}

            UpdatePlayerSharedSecretResult(const UpdatePlayerSharedSecretResult& src) :
                PlayFabBaseModel()
            {}

            UpdatePlayerSharedSecretResult(const rapidjson::Value& obj) : UpdatePlayerSharedSecretResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerSharedSecretResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            UpdatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                AggregationMethod(),
                StatisticName(),
                VersionChangeInterval()
            {}

            UpdatePlayerStatisticDefinitionRequest(const UpdatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                AggregationMethod(src.AggregationMethod),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            UpdatePlayerStatisticDefinitionRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticDefinitionRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticDefinitionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerStatisticDefinitionResult : public PlayFabBaseModel
        {
            PlayerStatisticDefinition* Statistic;

            UpdatePlayerStatisticDefinitionResult() :
                PlayFabBaseModel(),
                Statistic(NULL)
            {}

            UpdatePlayerStatisticDefinitionResult(const UpdatePlayerStatisticDefinitionResult& src) :
                PlayFabBaseModel(),
                Statistic(src.Statistic ? new PlayerStatisticDefinition(*src.Statistic) : NULL)
            {}

            UpdatePlayerStatisticDefinitionResult(const rapidjson::Value& obj) : UpdatePlayerStatisticDefinitionResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticDefinitionResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePolicyRequest : public PlayFabBaseModel
        {
            bool OverwritePolicy;
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            UpdatePolicyRequest() :
                PlayFabBaseModel(),
                OverwritePolicy(false),
                PolicyName(),
                Statements()
            {}

            UpdatePolicyRequest(const UpdatePolicyRequest& src) :
                PlayFabBaseModel(),
                OverwritePolicy(src.OverwritePolicy),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            UpdatePolicyRequest(const rapidjson::Value& obj) : UpdatePolicyRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePolicyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePolicyResponse : public PlayFabBaseModel
        {
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            UpdatePolicyResponse() :
                PlayFabBaseModel(),
                PolicyName(),
                Statements()
            {}

            UpdatePolicyResponse(const UpdatePolicyResponse& src) :
                PlayFabBaseModel(),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            UpdatePolicyResponse(const rapidjson::Value& obj) : UpdatePolicyResponse()
            {
                readFromValue(obj);
            }

            ~UpdatePolicyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateRandomResultTablesRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomTags;
            std::list<RandomResultTable> Tables;

            UpdateRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CustomTags(),
                Tables()
            {}

            UpdateRandomResultTablesRequest(const UpdateRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
                Tables(src.Tables)
            {}

            UpdateRandomResultTablesRequest(const rapidjson::Value& obj) : UpdateRandomResultTablesRequest()
            {
                readFromValue(obj);
            }

            ~UpdateRandomResultTablesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateRandomResultTablesResult : public PlayFabBaseModel
        {

            UpdateRandomResultTablesResult() :
                PlayFabBaseModel()
            {}

            UpdateRandomResultTablesResult(const UpdateRandomResultTablesResult& src) :
                PlayFabBaseModel()
            {}

            UpdateRandomResultTablesResult(const rapidjson::Value& obj) : UpdateRandomResultTablesResult()
            {
                readFromValue(obj);
            }

            ~UpdateRandomResultTablesResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateStoreItemsRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomTags;
            StoreMarketingModel* MarketingData;
            std::list<StoreItem> Store;
            std::string StoreId;

            UpdateStoreItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                CustomTags(),
                MarketingData(NULL),
                Store(),
                StoreId()
            {}

            UpdateStoreItemsRequest(const UpdateStoreItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                CustomTags(src.CustomTags),
                MarketingData(src.MarketingData ? new StoreMarketingModel(*src.MarketingData) : NULL),
                Store(src.Store),
                StoreId(src.StoreId)
            {}

            UpdateStoreItemsRequest(const rapidjson::Value& obj) : UpdateStoreItemsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateStoreItemsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateStoreItemsResult : public PlayFabBaseModel
        {

            UpdateStoreItemsResult() :
                PlayFabBaseModel()
            {}

            UpdateStoreItemsResult(const UpdateStoreItemsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateStoreItemsResult(const rapidjson::Value& obj) : UpdateStoreItemsResult()
            {
                readFromValue(obj);
            }

            ~UpdateStoreItemsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateTaskRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string Description;
            NameIdentifier* Identifier;
            bool IsActive;
            std::string Name;
            MultitypeVar Parameter;
            std::string Schedule;
            ScheduledTaskType Type;

            UpdateTaskRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Description(),
                Identifier(NULL),
                IsActive(false),
                Name(),
                Parameter(),
                Schedule(),
                Type()
            {}

            UpdateTaskRequest(const UpdateTaskRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Description(src.Description),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : NULL),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule),
                Type(src.Type)
            {}

            UpdateTaskRequest(const rapidjson::Value& obj) : UpdateTaskRequest()
            {
                readFromValue(obj);
            }

            ~UpdateTaskRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserDataRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string PlayFabId;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Data(),
                KeysToRemove(),
                Permission(),
                PlayFabId()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                PlayFabId(src.PlayFabId)
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

        struct UpdateUserInternalDataRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            UpdateUserInternalDataRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Data(),
                KeysToRemove(),
                PlayFabId()
            {}

            UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            UpdateUserInternalDataRequest(const rapidjson::Value& obj) : UpdateUserInternalDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserInternalDataRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateUserTitleDisplayNameRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string DisplayName;
            std::string PlayFabId;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                DisplayName(),
                PlayFabId()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId)
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


    }
}

#endif
