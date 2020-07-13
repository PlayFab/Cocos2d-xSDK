#ifndef PLAYFAB_CLOUDSCRIPT_DATA_MODELS_H_
#define PLAYFAB_CLOUDSCRIPT_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace CloudScriptModels
    {
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

        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        void writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer);
        CloudScriptRevisionOption readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj);

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

        struct ExecuteEntityCloudScriptRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey* Entity;
            std::string FunctionName;
            MultitypeVar FunctionParameter;
            OptionalBool GeneratePlayStreamEvent;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            OptionalInt32 SpecificRevision;

            ExecuteEntityCloudScriptRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(NULL),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteEntityCloudScriptRequest(const ExecuteEntityCloudScriptRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ExecuteEntityCloudScriptRequest(const rapidjson::Value& obj) : ExecuteEntityCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~ExecuteEntityCloudScriptRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ExecuteFunctionRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey* Entity;
            std::string FunctionName;
            MultitypeVar FunctionParameter;
            OptionalBool GeneratePlayStreamEvent;

            ExecuteFunctionRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(NULL),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent()
            {}

            ExecuteFunctionRequest(const ExecuteFunctionRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent)
            {}

            ExecuteFunctionRequest(const rapidjson::Value& obj) : ExecuteFunctionRequest()
            {
                readFromValue(obj);
            }

            ~ExecuteFunctionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FunctionExecutionError : public PlayFabBaseModel
        {
            std::string Error;
            std::string Message;
            std::string StackTrace;

            FunctionExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            FunctionExecutionError(const FunctionExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            FunctionExecutionError(const rapidjson::Value& obj) : FunctionExecutionError()
            {
                readFromValue(obj);
            }

            ~FunctionExecutionError();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ExecuteFunctionResult : public PlayFabBaseModel
        {
            FunctionExecutionError* Error;
            Int32 ExecutionTimeMilliseconds;
            std::string FunctionName;
            MultitypeVar FunctionResult;
            OptionalBool FunctionResultTooLarge;

            ExecuteFunctionResult() :
                PlayFabBaseModel(),
                Error(NULL),
                ExecutionTimeMilliseconds(0),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge()
            {}

            ExecuteFunctionResult(const ExecuteFunctionResult& src) :
                PlayFabBaseModel(),
                Error(src.Error ? new FunctionExecutionError(*src.Error) : NULL),
                ExecutionTimeMilliseconds(src.ExecutionTimeMilliseconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge)
            {}

            ExecuteFunctionResult(const rapidjson::Value& obj) : ExecuteFunctionResult()
            {
                readFromValue(obj);
            }

            ~ExecuteFunctionResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FunctionModel : public PlayFabBaseModel
        {
            std::string FunctionAddress;
            std::string FunctionName;
            std::string TriggerType;

            FunctionModel() :
                PlayFabBaseModel(),
                FunctionAddress(),
                FunctionName(),
                TriggerType()
            {}

            FunctionModel(const FunctionModel& src) :
                PlayFabBaseModel(),
                FunctionAddress(src.FunctionAddress),
                FunctionName(src.FunctionName),
                TriggerType(src.TriggerType)
            {}

            FunctionModel(const rapidjson::Value& obj) : FunctionModel()
            {
                readFromValue(obj);
            }

            ~FunctionModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct HttpFunctionModel : public PlayFabBaseModel
        {
            std::string FunctionName;
            std::string FunctionUrl;

            HttpFunctionModel() :
                PlayFabBaseModel(),
                FunctionName(),
                FunctionUrl()
            {}

            HttpFunctionModel(const HttpFunctionModel& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                FunctionUrl(src.FunctionUrl)
            {}

            HttpFunctionModel(const rapidjson::Value& obj) : HttpFunctionModel()
            {
                readFromValue(obj);
            }

            ~HttpFunctionModel();

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

        struct ListFunctionsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;

            ListFunctionsRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            ListFunctionsRequest(const ListFunctionsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
            {}

            ListFunctionsRequest(const rapidjson::Value& obj) : ListFunctionsRequest()
            {
                readFromValue(obj);
            }

            ~ListFunctionsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListFunctionsResult : public PlayFabBaseModel
        {
            std::list<FunctionModel> Functions;

            ListFunctionsResult() :
                PlayFabBaseModel(),
                Functions()
            {}

            ListFunctionsResult(const ListFunctionsResult& src) :
                PlayFabBaseModel(),
                Functions(src.Functions)
            {}

            ListFunctionsResult(const rapidjson::Value& obj) : ListFunctionsResult()
            {
                readFromValue(obj);
            }

            ~ListFunctionsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListHttpFunctionsResult : public PlayFabBaseModel
        {
            std::list<HttpFunctionModel> Functions;

            ListHttpFunctionsResult() :
                PlayFabBaseModel(),
                Functions()
            {}

            ListHttpFunctionsResult(const ListHttpFunctionsResult& src) :
                PlayFabBaseModel(),
                Functions(src.Functions)
            {}

            ListHttpFunctionsResult(const rapidjson::Value& obj) : ListHttpFunctionsResult()
            {
                readFromValue(obj);
            }

            ~ListHttpFunctionsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct QueuedFunctionModel : public PlayFabBaseModel
        {
            std::string ConnectionString;
            std::string FunctionName;
            std::string QueueName;

            QueuedFunctionModel() :
                PlayFabBaseModel(),
                ConnectionString(),
                FunctionName(),
                QueueName()
            {}

            QueuedFunctionModel(const QueuedFunctionModel& src) :
                PlayFabBaseModel(),
                ConnectionString(src.ConnectionString),
                FunctionName(src.FunctionName),
                QueueName(src.QueueName)
            {}

            QueuedFunctionModel(const rapidjson::Value& obj) : QueuedFunctionModel()
            {
                readFromValue(obj);
            }

            ~QueuedFunctionModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListQueuedFunctionsResult : public PlayFabBaseModel
        {
            std::list<QueuedFunctionModel> Functions;

            ListQueuedFunctionsResult() :
                PlayFabBaseModel(),
                Functions()
            {}

            ListQueuedFunctionsResult(const ListQueuedFunctionsResult& src) :
                PlayFabBaseModel(),
                Functions(src.Functions)
            {}

            ListQueuedFunctionsResult(const rapidjson::Value& obj) : ListQueuedFunctionsResult()
            {
                readFromValue(obj);
            }

            ~ListQueuedFunctionsResult();

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

        struct PlayStreamEventEnvelopeModel : public PlayFabBaseModel
        {
            std::string EntityId;
            std::string EntityType;
            std::string EventData;
            std::string EventName;
            std::string EventNamespace;
            std::string EventSettings;

            PlayStreamEventEnvelopeModel() :
                PlayFabBaseModel(),
                EntityId(),
                EntityType(),
                EventData(),
                EventName(),
                EventNamespace(),
                EventSettings()
            {}

            PlayStreamEventEnvelopeModel(const PlayStreamEventEnvelopeModel& src) :
                PlayFabBaseModel(),
                EntityId(src.EntityId),
                EntityType(src.EntityType),
                EventData(src.EventData),
                EventName(src.EventName),
                EventNamespace(src.EventNamespace),
                EventSettings(src.EventSettings)
            {}

            PlayStreamEventEnvelopeModel(const rapidjson::Value& obj) : PlayStreamEventEnvelopeModel()
            {
                readFromValue(obj);
            }

            ~PlayStreamEventEnvelopeModel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PostFunctionResultForEntityTriggeredActionRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            ExecuteFunctionResult FunctionResult;

            PostFunctionResultForEntityTriggeredActionRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                FunctionResult()
            {}

            PostFunctionResultForEntityTriggeredActionRequest(const PostFunctionResultForEntityTriggeredActionRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                FunctionResult(src.FunctionResult)
            {}

            PostFunctionResultForEntityTriggeredActionRequest(const rapidjson::Value& obj) : PostFunctionResultForEntityTriggeredActionRequest()
            {
                readFromValue(obj);
            }

            ~PostFunctionResultForEntityTriggeredActionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PostFunctionResultForFunctionExecutionRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            ExecuteFunctionResult FunctionResult;

            PostFunctionResultForFunctionExecutionRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                FunctionResult()
            {}

            PostFunctionResultForFunctionExecutionRequest(const PostFunctionResultForFunctionExecutionRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                FunctionResult(src.FunctionResult)
            {}

            PostFunctionResultForFunctionExecutionRequest(const rapidjson::Value& obj) : PostFunctionResultForFunctionExecutionRequest()
            {
                readFromValue(obj);
            }

            ~PostFunctionResultForFunctionExecutionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PostFunctionResultForPlayerTriggeredActionRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey* Entity;
            ExecuteFunctionResult FunctionResult;
            PlayerProfileModel PlayerProfile;
            PlayStreamEventEnvelopeModel* PlayStreamEventEnvelope;

            PostFunctionResultForPlayerTriggeredActionRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(NULL),
                FunctionResult(),
                PlayerProfile(),
                PlayStreamEventEnvelope(NULL)
            {}

            PostFunctionResultForPlayerTriggeredActionRequest(const PostFunctionResultForPlayerTriggeredActionRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                FunctionResult(src.FunctionResult),
                PlayerProfile(src.PlayerProfile),
                PlayStreamEventEnvelope(src.PlayStreamEventEnvelope ? new PlayStreamEventEnvelopeModel(*src.PlayStreamEventEnvelope) : NULL)
            {}

            PostFunctionResultForPlayerTriggeredActionRequest(const rapidjson::Value& obj) : PostFunctionResultForPlayerTriggeredActionRequest()
            {
                readFromValue(obj);
            }

            ~PostFunctionResultForPlayerTriggeredActionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct PostFunctionResultForScheduledTaskRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            ExecuteFunctionResult FunctionResult;
            NameIdentifier ScheduledTaskId;

            PostFunctionResultForScheduledTaskRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                FunctionResult(),
                ScheduledTaskId()
            {}

            PostFunctionResultForScheduledTaskRequest(const PostFunctionResultForScheduledTaskRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                FunctionResult(src.FunctionResult),
                ScheduledTaskId(src.ScheduledTaskId)
            {}

            PostFunctionResultForScheduledTaskRequest(const rapidjson::Value& obj) : PostFunctionResultForScheduledTaskRequest()
            {
                readFromValue(obj);
            }

            ~PostFunctionResultForScheduledTaskRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegisterHttpFunctionRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string FunctionName;
            std::string FunctionUrl;

            RegisterHttpFunctionRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                FunctionName(),
                FunctionUrl()
            {}

            RegisterHttpFunctionRequest(const RegisterHttpFunctionRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                FunctionName(src.FunctionName),
                FunctionUrl(src.FunctionUrl)
            {}

            RegisterHttpFunctionRequest(const rapidjson::Value& obj) : RegisterHttpFunctionRequest()
            {
                readFromValue(obj);
            }

            ~RegisterHttpFunctionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RegisterQueuedFunctionRequest : public PlayFabBaseModel
        {
            std::string ConnectionString;
            std::map<std::string, std::string> CustomTags;
            std::string FunctionName;
            std::string QueueName;

            RegisterQueuedFunctionRequest() :
                PlayFabBaseModel(),
                ConnectionString(),
                CustomTags(),
                FunctionName(),
                QueueName()
            {}

            RegisterQueuedFunctionRequest(const RegisterQueuedFunctionRequest& src) :
                PlayFabBaseModel(),
                ConnectionString(src.ConnectionString),
                CustomTags(src.CustomTags),
                FunctionName(src.FunctionName),
                QueueName(src.QueueName)
            {}

            RegisterQueuedFunctionRequest(const rapidjson::Value& obj) : RegisterQueuedFunctionRequest()
            {
                readFromValue(obj);
            }

            ~RegisterQueuedFunctionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum TriggerType
        {
            TriggerTypeHTTP,
            TriggerTypeQueue
        };

        void writeTriggerTypeEnumJSON(TriggerType enumVal, PFStringJsonWriter& writer);
        TriggerType readTriggerTypeFromValue(const rapidjson::Value& obj);

        struct UnregisterFunctionRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::string FunctionName;

            UnregisterFunctionRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                FunctionName()
            {}

            UnregisterFunctionRequest(const UnregisterFunctionRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                FunctionName(src.FunctionName)
            {}

            UnregisterFunctionRequest(const rapidjson::Value& obj) : UnregisterFunctionRequest()
            {
                readFromValue(obj);
            }

            ~UnregisterFunctionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
