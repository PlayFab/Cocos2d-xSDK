#ifndef PLAYFAB_ADMIN_DATA_MODELS_H_
#define PLAYFAB_ADMIN_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace AdminModels
    {
        struct AbortTaskInstanceRequest : public PlayFabBaseModel
        {
            std::string TaskInstanceId;

            AbortTaskInstanceRequest() :
                PlayFabBaseModel(),
                TaskInstanceId()
            {}

            AbortTaskInstanceRequest(const AbortTaskInstanceRequest& src) :
                PlayFabBaseModel(),
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
            std::string SegmentId;
            std::string ActionId;

            ActionsOnPlayersInSegmentTaskParameter() :
                PlayFabBaseModel(),
                SegmentId(),
                ActionId()
            {}

            ActionsOnPlayersInSegmentTaskParameter(const ActionsOnPlayersInSegmentTaskParameter& src) :
                PlayFabBaseModel(),
                SegmentId(src.SegmentId),
                ActionId(src.ActionId)
            {}

            ActionsOnPlayersInSegmentTaskParameter(const rapidjson::Value& obj) : ActionsOnPlayersInSegmentTaskParameter()
            {
                readFromValue(obj);
            }

            ~ActionsOnPlayersInSegmentTaskParameter();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct NameIdentifier : public PlayFabBaseModel
        {
            std::string Name;
            std::string Id;

            NameIdentifier() :
                PlayFabBaseModel(),
                Name(),
                Id()
            {}

            NameIdentifier(const NameIdentifier& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Id(src.Id)
            {}

            NameIdentifier(const rapidjson::Value& obj) : NameIdentifier()
            {
                readFromValue(obj);
            }

            ~NameIdentifier();

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
            TaskInstanceStatusPending
        };

        void writeTaskInstanceStatusEnumJSON(TaskInstanceStatus enumVal, PFStringJsonWriter& writer);
        TaskInstanceStatus readTaskInstanceStatusFromValue(const rapidjson::Value& obj);

        struct ActionsOnPlayersInSegmentTaskSummary : public PlayFabBaseModel
        {
            std::string TaskInstanceId;
            NameIdentifier* TaskIdentifier;
            time_t StartedAt;
            OptionalTime CompletedAt;
            Boxed<TaskInstanceStatus> Status;
            OptionalDouble PercentComplete;
            OptionalDouble EstimatedSecondsRemaining;
            std::string ScheduledByUserId;
            std::string ErrorMessage;
            OptionalBool ErrorWasFatal;
            OptionalInt32 TotalPlayersInSegment;
            OptionalInt32 TotalPlayersProcessed;

            ActionsOnPlayersInSegmentTaskSummary() :
                PlayFabBaseModel(),
                TaskInstanceId(),
                TaskIdentifier(NULL),
                StartedAt(0),
                CompletedAt(),
                Status(),
                PercentComplete(),
                EstimatedSecondsRemaining(),
                ScheduledByUserId(),
                ErrorMessage(),
                ErrorWasFatal(),
                TotalPlayersInSegment(),
                TotalPlayersProcessed()
            {}

            ActionsOnPlayersInSegmentTaskSummary(const ActionsOnPlayersInSegmentTaskSummary& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : NULL),
                StartedAt(src.StartedAt),
                CompletedAt(src.CompletedAt),
                Status(src.Status),
                PercentComplete(src.PercentComplete),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                ScheduledByUserId(src.ScheduledByUserId),
                ErrorMessage(src.ErrorMessage),
                ErrorWasFatal(src.ErrorWasFatal),
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
            std::string Platform;
            std::string CampaignId;
            time_t AttributedAt;

            AdCampaignAttribution() :
                PlayFabBaseModel(),
                Platform(),
                CampaignId(),
                AttributedAt(0)
            {}

            AdCampaignAttribution(const AdCampaignAttribution& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                CampaignId(src.CampaignId),
                AttributedAt(src.AttributedAt)
            {}

            AdCampaignAttribution(const rapidjson::Value& obj) : AdCampaignAttribution()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttribution();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AddNewsRequest : public PlayFabBaseModel
        {
            OptionalTime Timestamp;
            std::string Title;
            std::string Body;

            AddNewsRequest() :
                PlayFabBaseModel(),
                Timestamp(),
                Title(),
                Body()
            {}

            AddNewsRequest(const AddNewsRequest& src) :
                PlayFabBaseModel(),
                Timestamp(src.Timestamp),
                Title(src.Title),
                Body(src.Body)
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
            std::string PlayFabId;
            std::string TagName;

            AddPlayerTagRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                TagName()
            {}

            AddPlayerTagRequest(const AddPlayerTagRequest& src) :
                PlayFabBaseModel(),
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
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string ExecutablePath;
            std::list<Region> ActiveRegions;
            std::string Comment;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;

            AddServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId(),
                CommandLineTemplate(),
                ExecutablePath(),
                ActiveRegions(),
                Comment(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0)
            {}

            AddServerBuildRequest(const AddServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                ActiveRegions(src.ActiveRegions),
                Comment(src.Comment),
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
            std::string BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            std::string CommandLineTemplate;
            std::string ExecutablePath;
            std::string Comment;
            time_t Timestamp;
            std::string TitleId;
            Boxed<GameBuildStatus> Status;

            AddServerBuildResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status()
            {}

            AddServerBuildResult(const AddServerBuildResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status)
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
            std::string PlayFabId;
            std::string VirtualCurrency;
            Int32 Amount;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                Amount(0)
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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

        struct VirtualCurrencyData : public PlayFabBaseModel
        {
            std::string CurrencyCode;
            std::string DisplayName;
            OptionalInt32 InitialDeposit;
            OptionalInt32 RechargeRate;
            OptionalInt32 RechargeMax;

            VirtualCurrencyData() :
                PlayFabBaseModel(),
                CurrencyCode(),
                DisplayName(),
                InitialDeposit(),
                RechargeRate(),
                RechargeMax()
            {}

            VirtualCurrencyData(const VirtualCurrencyData& src) :
                PlayFabBaseModel(),
                CurrencyCode(src.CurrencyCode),
                DisplayName(src.DisplayName),
                InitialDeposit(src.InitialDeposit),
                RechargeRate(src.RechargeRate),
                RechargeMax(src.RechargeMax)
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

        struct BanInfo : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string BanId;
            std::string IPAddress;
            std::string MACAddress;
            OptionalTime Created;
            OptionalTime Expires;
            std::string Reason;
            bool Active;

            BanInfo() :
                PlayFabBaseModel(),
                PlayFabId(),
                BanId(),
                IPAddress(),
                MACAddress(),
                Created(),
                Expires(),
                Reason(),
                Active(false)
            {}

            BanInfo(const BanInfo& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                BanId(src.BanId),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Created(src.Created),
                Expires(src.Expires),
                Reason(src.Reason),
                Active(src.Active)
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
            std::string PlayFabId;
            std::string IPAddress;
            std::string MACAddress;
            std::string Reason;
            OptionalUint32 DurationInHours;

            BanRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                IPAddress(),
                MACAddress(),
                Reason(),
                DurationInHours()
            {}

            BanRequest(const BanRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Reason(src.Reason),
                DurationInHours(src.DurationInHours)
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

            BanUsersRequest() :
                PlayFabBaseModel(),
                Bans()
            {}

            BanUsersRequest(const BanUsersRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans)
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
            bool IsLimitedEdition;
            Int32 InitialLimitedEditionCount;

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
                ItemImageUrl(),
                IsLimitedEdition(false),
                InitialLimitedEditionCount(0)
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
                ItemImageUrl(src.ItemImageUrl),
                IsLimitedEdition(src.IsLimitedEdition),
                InitialLimitedEditionCount(src.InitialLimitedEditionCount)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CloudScriptFile : public PlayFabBaseModel
        {
            std::string Filename;
            std::string FileContents;

            CloudScriptFile() :
                PlayFabBaseModel(),
                Filename(),
                FileContents()
            {}

            CloudScriptFile(const CloudScriptFile& src) :
                PlayFabBaseModel(),
                Filename(src.Filename),
                FileContents(src.FileContents)
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
            std::string FunctionName;
            MultitypeVar Argument;

            CloudScriptTaskParameter() :
                PlayFabBaseModel(),
                FunctionName(),
                Argument()
            {}

            CloudScriptTaskParameter(const CloudScriptTaskParameter& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                Argument(src.Argument)
            {}

            CloudScriptTaskParameter(const rapidjson::Value& obj) : CloudScriptTaskParameter()
            {
                readFromValue(obj);
            }

            ~CloudScriptTaskParameter();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct LogStatement : public PlayFabBaseModel
        {
            std::string Level;
            std::string Message;
            MultitypeVar Data;

            LogStatement() :
                PlayFabBaseModel(),
                Level(),
                Message(),
                Data()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Level(src.Level),
                Message(src.Message),
                Data(src.Data)
            {}

            LogStatement(const rapidjson::Value& obj) : LogStatement()
            {
                readFromValue(obj);
            }

            ~LogStatement();

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

        struct ExecuteCloudScriptResult : public PlayFabBaseModel
        {
            std::string FunctionName;
            Int32 Revision;
            MultitypeVar FunctionResult;
            std::list<LogStatement> Logs;
            double ExecutionTimeSeconds;
            double ProcessorTimeSeconds;
            Uint32 MemoryConsumedBytes;
            Int32 APIRequestsIssued;
            Int32 HttpRequestsIssued;
            ScriptExecutionError* Error;

            ExecuteCloudScriptResult() :
                PlayFabBaseModel(),
                FunctionName(),
                Revision(0),
                FunctionResult(),
                Logs(),
                ExecutionTimeSeconds(0),
                ProcessorTimeSeconds(0),
                MemoryConsumedBytes(0),
                APIRequestsIssued(0),
                HttpRequestsIssued(0),
                Error(NULL)
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                Revision(src.Revision),
                FunctionResult(src.FunctionResult),
                Logs(src.Logs),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                APIRequestsIssued(src.APIRequestsIssued),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Error(src.Error ? new ScriptExecutionError(*src.Error) : NULL)
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
            std::string TaskInstanceId;
            NameIdentifier* TaskIdentifier;
            time_t StartedAt;
            OptionalTime CompletedAt;
            Boxed<TaskInstanceStatus> Status;
            OptionalDouble PercentComplete;
            OptionalDouble EstimatedSecondsRemaining;
            std::string ScheduledByUserId;
            ExecuteCloudScriptResult* Result;

            CloudScriptTaskSummary() :
                PlayFabBaseModel(),
                TaskInstanceId(),
                TaskIdentifier(NULL),
                StartedAt(0),
                CompletedAt(),
                Status(),
                PercentComplete(),
                EstimatedSecondsRemaining(),
                ScheduledByUserId(),
                Result(NULL)
            {}

            CloudScriptTaskSummary(const CloudScriptTaskSummary& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : NULL),
                StartedAt(src.StartedAt),
                CompletedAt(src.CompletedAt),
                Status(src.Status),
                PercentComplete(src.PercentComplete),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                ScheduledByUserId(src.ScheduledByUserId),
                Result(src.Result ? new ExecuteCloudScriptResult(*src.Result) : NULL)
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
            Int32 Version;
            Int32 PublishedRevision;
            Int32 LatestRevision;

            CloudScriptVersionStatus() :
                PlayFabBaseModel(),
                Version(0),
                PublishedRevision(0),
                LatestRevision(0)
            {}

            CloudScriptVersionStatus(const CloudScriptVersionStatus& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                PublishedRevision(src.PublishedRevision),
                LatestRevision(src.LatestRevision)
            {}

            CloudScriptVersionStatus(const rapidjson::Value& obj) : CloudScriptVersionStatus()
            {
                readFromValue(obj);
            }

            ~CloudScriptVersionStatus();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ContentInfo : public PlayFabBaseModel
        {
            std::string Key;
            Uint32 Size;
            time_t LastModified;

            ContentInfo() :
                PlayFabBaseModel(),
                Key(),
                Size(0),
                LastModified(0)
            {}

            ContentInfo(const ContentInfo& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Size(src.Size),
                LastModified(src.LastModified)
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
            std::string Name;
            std::string Description;
            std::string Schedule;
            bool IsActive;
            ActionsOnPlayersInSegmentTaskParameter Parameter;

            CreateActionsOnPlayerSegmentTaskRequest() :
                PlayFabBaseModel(),
                Name(),
                Description(),
                Schedule(),
                IsActive(false),
                Parameter()
            {}

            CreateActionsOnPlayerSegmentTaskRequest(const CreateActionsOnPlayerSegmentTaskRequest& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Description(src.Description),
                Schedule(src.Schedule),
                IsActive(src.IsActive),
                Parameter(src.Parameter)
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
            std::string Name;
            std::string Description;
            std::string Schedule;
            bool IsActive;
            CloudScriptTaskParameter Parameter;

            CreateCloudScriptTaskRequest() :
                PlayFabBaseModel(),
                Name(),
                Description(),
                Schedule(),
                IsActive(false),
                Parameter()
            {}

            CreateCloudScriptTaskRequest(const CreateCloudScriptTaskRequest& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Description(src.Description),
                Schedule(src.Schedule),
                IsActive(src.IsActive),
                Parameter(src.Parameter)
            {}

            CreateCloudScriptTaskRequest(const rapidjson::Value& obj) : CreateCloudScriptTaskRequest()
            {
                readFromValue(obj);
            }

            ~CreateCloudScriptTaskRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

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

        enum StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        void writeStatisticAggregationMethodEnumJSON(StatisticAggregationMethod enumVal, PFStringJsonWriter& writer);
        StatisticAggregationMethod readStatisticAggregationMethodFromValue(const rapidjson::Value& obj);

        struct CreatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            CreatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            CreatePlayerStatisticDefinitionRequest(const CreatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
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
            std::string StatisticName;
            Uint32 CurrentVersion;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            PlayerStatisticDefinition() :
                PlayFabBaseModel(),
                StatisticName(),
                CurrentVersion(0),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            PlayerStatisticDefinition(const PlayerStatisticDefinition& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                CurrentVersion(src.CurrentVersion),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
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

        struct DeleteStoreRequest : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::string StoreId;

            DeleteStoreRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId()
            {}

            DeleteStoreRequest(const DeleteStoreRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
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

        struct DeleteUsersRequest : public PlayFabBaseModel
        {
            std::list<std::string> PlayFabIds;
            std::string TitleId;

            DeleteUsersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                TitleId()
            {}

            DeleteUsersRequest(const DeleteUsersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                TitleId(src.TitleId)
            {}

            DeleteUsersRequest(const rapidjson::Value& obj) : DeleteUsersRequest()
            {
                readFromValue(obj);
            }

            ~DeleteUsersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteUsersResult : public PlayFabBaseModel
        {

            DeleteUsersResult() :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const DeleteUsersResult& src) :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const rapidjson::Value& obj) : DeleteUsersResult()
            {
                readFromValue(obj);
            }

            ~DeleteUsersResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum EffectType
        {
            EffectTypeAllow
        };

        void writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer);
        EffectType readEffectTypeFromValue(const rapidjson::Value& obj);

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

        struct GameModeInfo : public PlayFabBaseModel
        {
            std::string Gamemode;
            Uint32 MinPlayerCount;
            Uint32 MaxPlayerCount;
            OptionalBool StartOpen;

            GameModeInfo() :
                PlayFabBaseModel(),
                Gamemode(),
                MinPlayerCount(0),
                MaxPlayerCount(0),
                StartOpen()
            {}

            GameModeInfo(const GameModeInfo& src) :
                PlayFabBaseModel(),
                Gamemode(src.Gamemode),
                MinPlayerCount(src.MinPlayerCount),
                MaxPlayerCount(src.MaxPlayerCount),
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

        struct GetActionGroupResult : public PlayFabBaseModel
        {
            std::string Name;
            std::string Id;

            GetActionGroupResult() :
                PlayFabBaseModel(),
                Name(),
                Id()
            {}

            GetActionGroupResult(const GetActionGroupResult& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Id(src.Id)
            {}

            GetActionGroupResult(const rapidjson::Value& obj) : GetActionGroupResult()
            {
                readFromValue(obj);
            }

            ~GetActionGroupResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetActionsOnPlayersInSegmentTaskInstanceResult : public PlayFabBaseModel
        {
            ActionsOnPlayersInSegmentTaskSummary* Summary;
            ActionsOnPlayersInSegmentTaskParameter* Parameter;

            GetActionsOnPlayersInSegmentTaskInstanceResult() :
                PlayFabBaseModel(),
                Summary(NULL),
                Parameter(NULL)
            {}

            GetActionsOnPlayersInSegmentTaskInstanceResult(const GetActionsOnPlayersInSegmentTaskInstanceResult& src) :
                PlayFabBaseModel(),
                Summary(src.Summary ? new ActionsOnPlayersInSegmentTaskSummary(*src.Summary) : NULL),
                Parameter(src.Parameter ? new ActionsOnPlayersInSegmentTaskParameter(*src.Parameter) : NULL)
            {}

            GetActionsOnPlayersInSegmentTaskInstanceResult(const rapidjson::Value& obj) : GetActionsOnPlayersInSegmentTaskInstanceResult()
            {
                readFromValue(obj);
            }

            ~GetActionsOnPlayersInSegmentTaskInstanceResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAllActionGroupsRequest : public PlayFabBaseModel
        {

            GetAllActionGroupsRequest() :
                PlayFabBaseModel()
            {}

            GetAllActionGroupsRequest(const GetAllActionGroupsRequest& src) :
                PlayFabBaseModel()
            {}

            GetAllActionGroupsRequest(const rapidjson::Value& obj) : GetAllActionGroupsRequest()
            {
                readFromValue(obj);
            }

            ~GetAllActionGroupsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAllActionGroupsResult : public PlayFabBaseModel
        {
            std::list<GetActionGroupResult> ActionGroups;

            GetAllActionGroupsResult() :
                PlayFabBaseModel(),
                ActionGroups()
            {}

            GetAllActionGroupsResult(const GetAllActionGroupsResult& src) :
                PlayFabBaseModel(),
                ActionGroups(src.ActionGroups)
            {}

            GetAllActionGroupsResult(const rapidjson::Value& obj) : GetAllActionGroupsResult()
            {
                readFromValue(obj);
            }

            ~GetAllActionGroupsResult();

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
            std::string Id;
            std::string Name;
            std::string ABTestParent;

            GetSegmentResult() :
                PlayFabBaseModel(),
                Id(),
                Name(),
                ABTestParent()
            {}

            GetSegmentResult(const GetSegmentResult& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name),
                ABTestParent(src.ABTestParent)
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
            OptionalInt32 Version;
            OptionalInt32 Revision;

            GetCloudScriptRevisionRequest() :
                PlayFabBaseModel(),
                Version(),
                Revision()
            {}

            GetCloudScriptRevisionRequest(const GetCloudScriptRevisionRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
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
            Int32 Version;
            Int32 Revision;
            time_t CreatedAt;
            std::list<CloudScriptFile> Files;
            bool IsPublished;

            GetCloudScriptRevisionResult() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0),
                CreatedAt(0),
                Files(),
                IsPublished(false)
            {}

            GetCloudScriptRevisionResult(const GetCloudScriptRevisionResult& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision),
                CreatedAt(src.CreatedAt),
                Files(src.Files),
                IsPublished(src.IsPublished)
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
            CloudScriptTaskSummary* Summary;
            CloudScriptTaskParameter* Parameter;

            GetCloudScriptTaskInstanceResult() :
                PlayFabBaseModel(),
                Summary(NULL),
                Parameter(NULL)
            {}

            GetCloudScriptTaskInstanceResult(const GetCloudScriptTaskInstanceResult& src) :
                PlayFabBaseModel(),
                Summary(src.Summary ? new CloudScriptTaskSummary(*src.Summary) : NULL),
                Parameter(src.Parameter ? new CloudScriptTaskParameter(*src.Parameter) : NULL)
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
            Int32 ItemCount;
            Uint32 TotalSize;
            std::list<ContentInfo> Contents;

            GetContentListResult() :
                PlayFabBaseModel(),
                ItemCount(0),
                TotalSize(0),
                Contents()
            {}

            GetContentListResult(const GetContentListResult& src) :
                PlayFabBaseModel(),
                ItemCount(src.ItemCount),
                TotalSize(src.TotalSize),
                Contents(src.Contents)
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
            std::string Key;
            std::string ContentType;

            GetContentUploadUrlRequest() :
                PlayFabBaseModel(),
                Key(),
                ContentType()
            {}

            GetContentUploadUrlRequest(const GetContentUploadUrlRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                ContentType(src.ContentType)
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
            std::string ReportName;
            Int32 Year;
            Int32 Month;
            Int32 Day;

            GetDataReportRequest() :
                PlayFabBaseModel(),
                ReportName(),
                Year(0),
                Month(0),
                Day(0)
            {}

            GetDataReportRequest(const GetDataReportRequest& src) :
                PlayFabBaseModel(),
                ReportName(src.ReportName),
                Year(src.Year),
                Month(src.Month),
                Day(src.Day)
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
            std::string LobbyId;
            std::string TitleId;
            time_t StartTime;
            OptionalTime EndTime;
            std::string Mode;
            std::string BuildVersion;
            Boxed<Region> pfRegion;
            std::list<std::string> Players;
            std::string ServerAddress;
            Uint32 ServerPort;

            GetMatchmakerGameInfoResult() :
                PlayFabBaseModel(),
                LobbyId(),
                TitleId(),
                StartTime(0),
                EndTime(),
                Mode(),
                BuildVersion(),
                pfRegion(),
                Players(),
                ServerAddress(),
                ServerPort(0)
            {}

            GetMatchmakerGameInfoResult(const GetMatchmakerGameInfoResult& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                TitleId(src.TitleId),
                StartTime(src.StartTime),
                EndTime(src.EndTime),
                Mode(src.Mode),
                BuildVersion(src.BuildVersion),
                pfRegion(src.pfRegion),
                Players(src.Players),
                ServerAddress(src.ServerAddress),
                ServerPort(src.ServerPort)
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

        struct GetPlayersInSegmentRequest : public PlayFabBaseModel
        {
            std::string SegmentId;
            OptionalUint32 SecondsToLive;
            OptionalUint32 MaxBatchSize;
            std::string ContinuationToken;

            GetPlayersInSegmentRequest() :
                PlayFabBaseModel(),
                SegmentId(),
                SecondsToLive(),
                MaxBatchSize(),
                ContinuationToken()
            {}

            GetPlayersInSegmentRequest(const GetPlayersInSegmentRequest& src) :
                PlayFabBaseModel(),
                SegmentId(src.SegmentId),
                SecondsToLive(src.SecondsToLive),
                MaxBatchSize(src.MaxBatchSize),
                ContinuationToken(src.ContinuationToken)
            {}

            GetPlayersInSegmentRequest(const rapidjson::Value& obj) : GetPlayersInSegmentRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentRequest();

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
            LoginIdentityProviderTwitch
        };

        void writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer);
        LoginIdentityProvider readLoginIdentityProviderFromValue(const rapidjson::Value& obj);

        struct PlayerLocation : public PlayFabBaseModel
        {
            ContinentCode pfContinentCode;
            CountryCode pfCountryCode;
            std::string City;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            PlayerLocation() :
                PlayFabBaseModel(),
                pfContinentCode(),
                pfCountryCode(),
                City(),
                Latitude(),
                Longitude()
            {}

            PlayerLocation(const PlayerLocation& src) :
                PlayFabBaseModel(),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                City(src.City),
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

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        void writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer);
        PushNotificationPlatform readPushNotificationPlatformFromValue(const rapidjson::Value& obj);

        struct PushNotificationRegistration : public PlayFabBaseModel
        {
            Boxed<PushNotificationPlatform> Platform;
            std::string NotificationEndpointARN;

            PushNotificationRegistration() :
                PlayFabBaseModel(),
                Platform(),
                NotificationEndpointARN()
            {}

            PushNotificationRegistration(const PushNotificationRegistration& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                NotificationEndpointARN(src.NotificationEndpointARN)
            {}

            PushNotificationRegistration(const rapidjson::Value& obj) : PushNotificationRegistration()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistration();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerLinkedAccount : public PlayFabBaseModel
        {
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;
            std::string Email;

            PlayerLinkedAccount() :
                PlayFabBaseModel(),
                Platform(),
                PlatformUserId(),
                Username(),
                Email()
            {}

            PlayerLinkedAccount(const PlayerLinkedAccount& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username),
                Email(src.Email)
            {}

            PlayerLinkedAccount(const rapidjson::Value& obj) : PlayerLinkedAccount()
            {
                readFromValue(obj);
            }

            ~PlayerLinkedAccount();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerStatistic : public PlayFabBaseModel
        {
            std::string Id;
            Int32 StatisticVersion;
            Int32 StatisticValue;
            std::string Name;

            PlayerStatistic() :
                PlayFabBaseModel(),
                Id(),
                StatisticVersion(0),
                StatisticValue(0),
                Name()
            {}

            PlayerStatistic(const PlayerStatistic& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                StatisticVersion(src.StatisticVersion),
                StatisticValue(src.StatisticValue),
                Name(src.Name)
            {}

            PlayerStatistic(const rapidjson::Value& obj) : PlayerStatistic()
            {
                readFromValue(obj);
            }

            ~PlayerStatistic();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PlayerProfile : public PlayFabBaseModel
        {
            std::string PlayerId;
            std::string TitleId;
            std::string DisplayName;
            std::string PublisherId;
            Boxed<LoginIdentityProvider> Origination;
            OptionalTime Created;
            OptionalTime LastLogin;
            OptionalTime BannedUntil;
            std::map<std::string, Int32> Statistics;
            OptionalUint32 TotalValueToDateInUSD;
            std::map<std::string, Uint32> ValuesToDate;
            std::list<std::string> Tags;
            std::map<std::string, PlayerLocation> Locations;
            std::map<std::string, Int32> VirtualCurrencyBalances;
            std::list<AdCampaignAttribution> AdCampaignAttributions;
            std::list<PushNotificationRegistration> PushNotificationRegistrations;
            std::list<PlayerLinkedAccount> LinkedAccounts;
            std::list<PlayerStatistic> PlayerStatistics;

            PlayerProfile() :
                PlayFabBaseModel(),
                PlayerId(),
                TitleId(),
                DisplayName(),
                PublisherId(),
                Origination(),
                Created(),
                LastLogin(),
                BannedUntil(),
                Statistics(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                Tags(),
                Locations(),
                VirtualCurrencyBalances(),
                AdCampaignAttributions(),
                PushNotificationRegistrations(),
                LinkedAccounts(),
                PlayerStatistics()
            {}

            PlayerProfile(const PlayerProfile& src) :
                PlayFabBaseModel(),
                PlayerId(src.PlayerId),
                TitleId(src.TitleId),
                DisplayName(src.DisplayName),
                PublisherId(src.PublisherId),
                Origination(src.Origination),
                Created(src.Created),
                LastLogin(src.LastLogin),
                BannedUntil(src.BannedUntil),
                Statistics(src.Statistics),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                Tags(src.Tags),
                Locations(src.Locations),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances),
                AdCampaignAttributions(src.AdCampaignAttributions),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                LinkedAccounts(src.LinkedAccounts),
                PlayerStatistics(src.PlayerStatistics)
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
            Int32 ProfilesInSegment;
            std::string ContinuationToken;
            std::list<PlayerProfile> PlayerProfiles;

            GetPlayersInSegmentResult() :
                PlayFabBaseModel(),
                ProfilesInSegment(0),
                ContinuationToken(),
                PlayerProfiles()
            {}

            GetPlayersInSegmentResult(const GetPlayersInSegmentResult& src) :
                PlayFabBaseModel(),
                ProfilesInSegment(src.ProfilesInSegment),
                ContinuationToken(src.ContinuationToken),
                PlayerProfiles(src.PlayerProfiles)
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
            std::string PlayFabId;

            GetPlayersSegmentsRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetPlayersSegmentsRequest(const GetPlayersSegmentsRequest& src) :
                PlayFabBaseModel(),
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
            std::string StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabBaseModel(),
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

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            std::string StatisticName;
            Uint32 Version;
            OptionalTime ScheduledActivationTime;
            time_t ActivationTime;
            OptionalTime ScheduledDeactivationTime;
            OptionalTime DeactivationTime;
            Boxed<StatisticVersionArchivalStatus> ArchivalStatus;
            std::string ArchiveDownloadUrl;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0),
                ScheduledActivationTime(),
                ActivationTime(0),
                ScheduledDeactivationTime(),
                DeactivationTime(),
                ArchivalStatus(),
                ArchiveDownloadUrl()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ActivationTime(src.ActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                DeactivationTime(src.DeactivationTime),
                ArchivalStatus(src.ArchivalStatus),
                ArchiveDownloadUrl(src.ArchiveDownloadUrl)
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
            std::string PlayFabId;
            std::string Namespace;

            GetPlayerTagsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Namespace()
            {}

            GetPlayerTagsRequest(const GetPlayerTagsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Namespace(src.Namespace)
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
            std::string Resource;
            std::string Action;
            EffectType Effect;
            std::string Principal;
            std::string Comment;

            PermissionStatement() :
                PlayFabBaseModel(),
                Resource(),
                Action(),
                Effect(),
                Principal(),
                Comment()
            {}

            PermissionStatement(const PermissionStatement& src) :
                PlayFabBaseModel(),
                Resource(src.Resource),
                Action(src.Action),
                Effect(src.Effect),
                Principal(src.Principal),
                Comment(src.Comment)
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
            ResultTableNodeType ResultItemType;
            std::string ResultItem;
            Int32 Weight;

            ResultTableNode() :
                PlayFabBaseModel(),
                ResultItemType(),
                ResultItem(),
                Weight(0)
            {}

            ResultTableNode(const ResultTableNode& src) :
                PlayFabBaseModel(),
                ResultItemType(src.ResultItemType),
                ResultItem(src.ResultItem),
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
            std::string TableId;
            std::list<ResultTableNode> Nodes;

            RandomResultTableListing() :
                PlayFabBaseModel(),
                CatalogVersion(),
                TableId(),
                Nodes()
            {}

            RandomResultTableListing(const RandomResultTableListing& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                TableId(src.TableId),
                Nodes(src.Nodes)
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
            std::string BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            std::string Comment;
            time_t Timestamp;
            std::string TitleId;
            Boxed<GameBuildStatus> Status;
            std::string ErrorMessage;

            GetServerBuildInfoResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status(),
                ErrorMessage()
            {}

            GetServerBuildInfoResult(const GetServerBuildInfoResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status),
                ErrorMessage(src.ErrorMessage)
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

        struct StoreItem : public PlayFabBaseModel
        {
            std::string ItemId;
            std::map<std::string, Uint32> VirtualCurrencyPrices;
            std::map<std::string, Uint32> RealCurrencyPrices;
            MultitypeVar CustomData;
            OptionalUint32 DisplayPosition;

            StoreItem() :
                PlayFabBaseModel(),
                ItemId(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices(),
                CustomData(),
                DisplayPosition()
            {}

            StoreItem(const StoreItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices),
                CustomData(src.CustomData),
                DisplayPosition(src.DisplayPosition)
            {}

            StoreItem(const rapidjson::Value& obj) : StoreItem()
            {
                readFromValue(obj);
            }

            ~StoreItem();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum SourceType
        {
            SourceTypeAdmin,
            SourceTypeBackEnd,
            SourceTypeGameClient,
            SourceTypeGameServer,
            SourceTypePartner
        };

        void writeSourceTypeEnumJSON(SourceType enumVal, PFStringJsonWriter& writer);
        SourceType readSourceTypeFromValue(const rapidjson::Value& obj);

        struct StoreMarketingModel : public PlayFabBaseModel
        {
            std::string DisplayName;
            std::string Description;
            MultitypeVar Metadata;

            StoreMarketingModel() :
                PlayFabBaseModel(),
                DisplayName(),
                Description(),
                Metadata()
            {}

            StoreMarketingModel(const StoreMarketingModel& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Description(src.Description),
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

        struct GetStoreItemsResult : public PlayFabBaseModel
        {
            std::list<StoreItem> Store;
            Boxed<SourceType> Source;
            std::string CatalogVersion;
            std::string StoreId;
            StoreMarketingModel* MarketingData;

            GetStoreItemsResult() :
                PlayFabBaseModel(),
                Store(),
                Source(),
                CatalogVersion(),
                StoreId(),
                MarketingData(NULL)
            {}

            GetStoreItemsResult(const GetStoreItemsResult& src) :
                PlayFabBaseModel(),
                Store(src.Store),
                Source(src.Source),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                MarketingData(src.MarketingData ? new StoreMarketingModel(*src.MarketingData) : NULL)
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
            NameIdentifier* TaskIdentifier;
            Boxed<TaskInstanceStatus> StatusFilter;
            OptionalTime StartedAtRangeFrom;
            OptionalTime StartedAtRangeTo;

            GetTaskInstancesRequest() :
                PlayFabBaseModel(),
                TaskIdentifier(NULL),
                StatusFilter(),
                StartedAtRangeFrom(),
                StartedAtRangeTo()
            {}

            GetTaskInstancesRequest(const GetTaskInstancesRequest& src) :
                PlayFabBaseModel(),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : NULL),
                StatusFilter(src.StatusFilter),
                StartedAtRangeFrom(src.StartedAtRangeFrom),
                StartedAtRangeTo(src.StartedAtRangeTo)
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
            ScheduledTaskTypeActionsOnPlayerSegment
        };

        void writeScheduledTaskTypeEnumJSON(ScheduledTaskType enumVal, PFStringJsonWriter& writer);
        ScheduledTaskType readScheduledTaskTypeFromValue(const rapidjson::Value& obj);

        struct TaskInstanceBasicSummary : public PlayFabBaseModel
        {
            std::string TaskInstanceId;
            NameIdentifier* TaskIdentifier;
            time_t StartedAt;
            OptionalTime CompletedAt;
            Boxed<TaskInstanceStatus> Status;
            OptionalDouble PercentComplete;
            OptionalDouble EstimatedSecondsRemaining;
            std::string ScheduledByUserId;
            Boxed<ScheduledTaskType> Type;

            TaskInstanceBasicSummary() :
                PlayFabBaseModel(),
                TaskInstanceId(),
                TaskIdentifier(NULL),
                StartedAt(0),
                CompletedAt(),
                Status(),
                PercentComplete(),
                EstimatedSecondsRemaining(),
                ScheduledByUserId(),
                Type()
            {}

            TaskInstanceBasicSummary(const TaskInstanceBasicSummary& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : NULL),
                StartedAt(src.StartedAt),
                CompletedAt(src.CompletedAt),
                Status(src.Status),
                PercentComplete(src.PercentComplete),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                ScheduledByUserId(src.ScheduledByUserId),
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
            std::string TaskId;
            std::string Name;
            std::string Description;
            std::string Schedule;
            bool IsActive;
            Boxed<ScheduledTaskType> Type;
            MultitypeVar Parameter;
            OptionalTime LastRunTime;
            OptionalTime NextRunTime;

            ScheduledTask() :
                PlayFabBaseModel(),
                TaskId(),
                Name(),
                Description(),
                Schedule(),
                IsActive(false),
                Type(),
                Parameter(),
                LastRunTime(),
                NextRunTime()
            {}

            ScheduledTask(const ScheduledTask& src) :
                PlayFabBaseModel(),
                TaskId(src.TaskId),
                Name(src.Name),
                Description(src.Description),
                Schedule(src.Schedule),
                IsActive(src.IsActive),
                Type(src.Type),
                Parameter(src.Parameter),
                LastRunTime(src.LastRunTime),
                NextRunTime(src.NextRunTime)
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
            std::string PlayFabId;
            std::list<std::string> Keys;
            OptionalUint32 IfChangedFromDataVersion;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Keys(),
                IfChangedFromDataVersion()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Keys(src.Keys),
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

        struct GetUserDataResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            Uint32 DataVersion;
            std::map<std::string, UserDataRecord> Data;

            GetUserDataResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                DataVersion(0),
                Data()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DataVersion(src.DataVersion),
                Data(src.Data)
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
            std::string PlayFabId;

            GetUserInventoryRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel(),
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

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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

        struct GrantedItemInstance : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string CharacterId;
            bool Result;
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

            GrantedItemInstance() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Result(false),
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

            GrantedItemInstance(const GrantedItemInstance& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Result(src.Result),
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
            std::string PlayFabId;
            std::string ItemId;
            std::string Annotation;
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;

            ItemGrant() :
                PlayFabBaseModel(),
                PlayFabId(),
                ItemId(),
                Annotation(),
                CharacterId(),
                Data(),
                KeysToRemove()
            {}

            ItemGrant(const ItemGrant& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ItemId(src.ItemId),
                Annotation(src.Annotation),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove)
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
            std::list<ItemGrant> ItemGrants;

            GrantItemsToUsersRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                ItemGrants()
            {}

            GrantItemsToUsersRequest(const GrantItemsToUsersRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
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

        struct IncrementPlayerStatisticVersionRequest : public PlayFabBaseModel
        {
            std::string StatisticName;

            IncrementPlayerStatisticVersionRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            IncrementPlayerStatisticVersionRequest(const IncrementPlayerStatisticVersionRequest& src) :
                PlayFabBaseModel(),
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
            std::string PlayFabId;
            std::string Email;
            std::string Username;
            std::string TitleDisplayName;

            LookupUserAccountInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Email(),
                Username(),
                TitleDisplayName()
            {}

            LookupUserAccountInfoRequest(const LookupUserAccountInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Email(src.Email),
                Username(src.Username),
                TitleDisplayName(src.TitleDisplayName)
            {}

            LookupUserAccountInfoRequest(const rapidjson::Value& obj) : LookupUserAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~LookupUserAccountInfoRequest();

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
            UserOriginationTwitch
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

        struct UserGoogleInfo : public PlayFabBaseModel
        {
            std::string GoogleId;
            std::string GoogleEmail;
            std::string GoogleLocale;
            std::string GoogleGender;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleId(),
                GoogleEmail(),
                GoogleLocale(),
                GoogleGender()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                GoogleEmail(src.GoogleEmail),
                GoogleLocale(src.GoogleLocale),
                GoogleGender(src.GoogleGender)
            {}

            UserGoogleInfo(const rapidjson::Value& obj) : UserGoogleInfo()
            {
                readFromValue(obj);
            }

            ~UserGoogleInfo();

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
            UserIosDeviceInfo* IosDeviceInfo;
            UserAndroidDeviceInfo* AndroidDeviceInfo;
            UserKongregateInfo* KongregateInfo;
            UserTwitchInfo* TwitchInfo;
            UserPsnInfo* PsnInfo;
            UserGoogleInfo* GoogleInfo;
            UserXboxInfo* XboxInfo;
            UserCustomIdInfo* CustomIdInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                PlayFabId(),
                Created(0),
                Username(),
                TitleInfo(NULL),
                PrivateInfo(NULL),
                FacebookInfo(NULL),
                SteamInfo(NULL),
                GameCenterInfo(NULL),
                IosDeviceInfo(NULL),
                AndroidDeviceInfo(NULL),
                KongregateInfo(NULL),
                TwitchInfo(NULL),
                PsnInfo(NULL),
                GoogleInfo(NULL),
                XboxInfo(NULL),
                CustomIdInfo(NULL)
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
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : NULL),
                IosDeviceInfo(src.IosDeviceInfo ? new UserIosDeviceInfo(*src.IosDeviceInfo) : NULL),
                AndroidDeviceInfo(src.AndroidDeviceInfo ? new UserAndroidDeviceInfo(*src.AndroidDeviceInfo) : NULL),
                KongregateInfo(src.KongregateInfo ? new UserKongregateInfo(*src.KongregateInfo) : NULL),
                TwitchInfo(src.TwitchInfo ? new UserTwitchInfo(*src.TwitchInfo) : NULL),
                PsnInfo(src.PsnInfo ? new UserPsnInfo(*src.PsnInfo) : NULL),
                GoogleInfo(src.GoogleInfo ? new UserGoogleInfo(*src.GoogleInfo) : NULL),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : NULL),
                CustomIdInfo(src.CustomIdInfo ? new UserCustomIdInfo(*src.CustomIdInfo) : NULL)
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
            std::string BuildId;
            OptionalTime Timestamp;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            std::string CommandLineTemplate;
            std::string ExecutablePath;
            std::string Comment;

            ModifyServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId(),
                Timestamp(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment()
            {}

            ModifyServerBuildRequest(const ModifyServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                Timestamp(src.Timestamp),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment)
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
            std::string BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            std::string CommandLineTemplate;
            std::string ExecutablePath;
            std::string Comment;
            time_t Timestamp;
            std::string TitleId;
            Boxed<GameBuildStatus> Status;

            ModifyServerBuildResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status()
            {}

            ModifyServerBuildResult(const ModifyServerBuildResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status)
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

        struct RandomResultTable : public PlayFabBaseModel
        {
            std::string TableId;
            std::list<ResultTableNode> Nodes;

            RandomResultTable() :
                PlayFabBaseModel(),
                TableId(),
                Nodes()
            {}

            RandomResultTable(const RandomResultTable& src) :
                PlayFabBaseModel(),
                TableId(src.TableId),
                Nodes(src.Nodes)
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
            std::string PlayFabId;
            std::string OrderId;
            std::string Reason;

            RefundPurchaseRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                OrderId(),
                Reason()
            {}

            RefundPurchaseRequest(const RefundPurchaseRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                OrderId(src.OrderId),
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
            std::string PlayFabId;
            std::string TagName;

            RemovePlayerTagRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                TagName()
            {}

            RemovePlayerTagRequest(const RemovePlayerTagRequest& src) :
                PlayFabBaseModel(),
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
            std::string PlayFabId;
            std::string CharacterId;

            ResetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId()
            {}

            ResetCharacterStatisticsRequest(const ResetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId)
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

        struct UserCredentials : public PlayFabBaseModel
        {
            std::string Username;

            UserCredentials() :
                PlayFabBaseModel(),
                Username()
            {}

            UserCredentials(const UserCredentials& src) :
                PlayFabBaseModel(),
                Username(src.Username)
            {}

            UserCredentials(const rapidjson::Value& obj) : UserCredentials()
            {
                readFromValue(obj);
            }

            ~UserCredentials();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResetUsersRequest : public PlayFabBaseModel
        {
            std::list<UserCredentials> Users;

            ResetUsersRequest() :
                PlayFabBaseModel(),
                Users()
            {}

            ResetUsersRequest(const ResetUsersRequest& src) :
                PlayFabBaseModel(),
                Users(src.Users)
            {}

            ResetUsersRequest(const rapidjson::Value& obj) : ResetUsersRequest()
            {
                readFromValue(obj);
            }

            ~ResetUsersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ResetUserStatisticsRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;

            ResetUserStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            ResetUserStatisticsRequest(const ResetUserStatisticsRequest& src) :
                PlayFabBaseModel(),
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
            std::string PlayFabId;
            std::string OrderId;
            std::string Reason;
            ResolutionOutcome Outcome;

            ResolvePurchaseDisputeRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                OrderId(),
                Reason(),
                Outcome()
            {}

            ResolvePurchaseDisputeRequest(const ResolvePurchaseDisputeRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                OrderId(src.OrderId),
                Reason(src.Reason),
                Outcome(src.Outcome)
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

        struct RevokeInventoryItemRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string CharacterId;
            std::string ItemInstanceId;

            RevokeInventoryItemRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ItemInstanceId()
            {}

            RevokeInventoryItemRequest(const RevokeInventoryItemRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId)
            {}

            RevokeInventoryItemRequest(const rapidjson::Value& obj) : RevokeInventoryItemRequest()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItemRequest();

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
            NameIdentifier* Identifier;

            RunTaskRequest() :
                PlayFabBaseModel(),
                Identifier(NULL)
            {}

            RunTaskRequest(const RunTaskRequest& src) :
                PlayFabBaseModel(),
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
            std::string Email;

            SendAccountRecoveryEmailRequest() :
                PlayFabBaseModel(),
                Email()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email)
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

        struct SetPublishedRevisionRequest : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 Revision;

            SetPublishedRevisionRequest() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0)
            {}

            SetPublishedRevisionRequest(const SetPublishedRevisionRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
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
            std::string Name;
            std::string Platform;
            std::string Key;
            std::string Credential;
            bool OverwriteOldARN;

            SetupPushNotificationRequest() :
                PlayFabBaseModel(),
                Name(),
                Platform(),
                Key(),
                Credential(),
                OverwriteOldARN(false)
            {}

            SetupPushNotificationRequest(const SetupPushNotificationRequest& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Platform(src.Platform),
                Key(src.Key),
                Credential(src.Credential),
                OverwriteOldARN(src.OverwriteOldARN)
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

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string VirtualCurrency;
            Int32 Amount;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                Amount(0)
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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

        struct UpdateBanRequest : public PlayFabBaseModel
        {
            std::string BanId;
            std::string Reason;
            OptionalTime Expires;
            std::string IPAddress;
            std::string MACAddress;
            OptionalBool Permanent;
            OptionalBool Active;

            UpdateBanRequest() :
                PlayFabBaseModel(),
                BanId(),
                Reason(),
                Expires(),
                IPAddress(),
                MACAddress(),
                Permanent(),
                Active()
            {}

            UpdateBanRequest(const UpdateBanRequest& src) :
                PlayFabBaseModel(),
                BanId(src.BanId),
                Reason(src.Reason),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Permanent(src.Permanent),
                Active(src.Active)
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
            std::string CatalogVersion;
            OptionalBool SetAsDefaultCatalog;
            std::list<CatalogItem> Catalog;

            UpdateCatalogItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                SetAsDefaultCatalog(),
                Catalog()
            {}

            UpdateCatalogItemsRequest(const UpdateCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                SetAsDefaultCatalog(src.SetAsDefaultCatalog),
                Catalog(src.Catalog)
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
            std::list<CloudScriptFile> Files;
            bool Publish;
            std::string DeveloperPlayFabId;

            UpdateCloudScriptRequest() :
                PlayFabBaseModel(),
                Files(),
                Publish(false),
                DeveloperPlayFabId()
            {}

            UpdateCloudScriptRequest(const UpdateCloudScriptRequest& src) :
                PlayFabBaseModel(),
                Files(src.Files),
                Publish(src.Publish),
                DeveloperPlayFabId(src.DeveloperPlayFabId)
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
            Int32 Version;
            Int32 Revision;

            UpdateCloudScriptResult() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0)
            {}

            UpdateCloudScriptResult(const UpdateCloudScriptResult& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
            {}

            UpdateCloudScriptResult(const rapidjson::Value& obj) : UpdateCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~UpdateCloudScriptResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            UpdatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            UpdatePlayerStatisticDefinitionRequest(const UpdatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
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
            std::string PolicyName;
            std::list<PermissionStatement> Statements;
            bool OverwritePolicy;

            UpdatePolicyRequest() :
                PlayFabBaseModel(),
                PolicyName(),
                Statements(),
                OverwritePolicy(false)
            {}

            UpdatePolicyRequest(const UpdatePolicyRequest& src) :
                PlayFabBaseModel(),
                PolicyName(src.PolicyName),
                Statements(src.Statements),
                OverwritePolicy(src.OverwritePolicy)
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
            std::list<RandomResultTable> Tables;

            UpdateRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Tables()
            {}

            UpdateRandomResultTablesRequest(const UpdateRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
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
            std::string StoreId;
            StoreMarketingModel* MarketingData;
            std::list<StoreItem> Store;

            UpdateStoreItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId(),
                MarketingData(NULL),
                Store()
            {}

            UpdateStoreItemsRequest(const UpdateStoreItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                MarketingData(src.MarketingData ? new StoreMarketingModel(*src.MarketingData) : NULL),
                Store(src.Store)
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
            NameIdentifier* Identifier;
            std::string Name;
            std::string Description;
            std::string Schedule;
            bool IsActive;
            ScheduledTaskType Type;
            MultitypeVar Parameter;

            UpdateTaskRequest() :
                PlayFabBaseModel(),
                Identifier(NULL),
                Name(),
                Description(),
                Schedule(),
                IsActive(false),
                Type(),
                Parameter()
            {}

            UpdateTaskRequest(const UpdateTaskRequest& src) :
                PlayFabBaseModel(),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : NULL),
                Name(src.Name),
                Description(src.Description),
                Schedule(src.Schedule),
                IsActive(src.IsActive),
                Type(src.Type),
                Parameter(src.Parameter)
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
            std::string PlayFabId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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

        struct UpdateUserInternalDataRequest : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;

            UpdateUserInternalDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Data(),
                KeysToRemove()
            {}

            UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove)
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
            std::string PlayFabId;
            std::string DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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


    }
}

#endif
