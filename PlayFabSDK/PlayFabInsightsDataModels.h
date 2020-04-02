#ifndef PLAYFAB_INSIGHTS_DATA_MODELS_H_
#define PLAYFAB_INSIGHTS_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace InsightsModels
    {
        struct InsightsEmptyRequest : public PlayFabBaseModel
        {

            InsightsEmptyRequest() :
                PlayFabBaseModel()
            {}

            InsightsEmptyRequest(const InsightsEmptyRequest& src) :
                PlayFabBaseModel()
            {}

            InsightsEmptyRequest(const rapidjson::Value& obj) : InsightsEmptyRequest()
            {
                readFromValue(obj);
            }

            ~InsightsEmptyRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsPerformanceLevel : public PlayFabBaseModel
        {
            Int32 ActiveEventExports;
            Int32 CacheSizeMB;
            Int32 Concurrency;
            double CreditsPerMinute;
            Int32 EventsPerSecond;
            Int32 Level;
            Int32 MaxMemoryPerQueryMB;
            Int32 VirtualCpuCores;

            InsightsPerformanceLevel() :
                PlayFabBaseModel(),
                ActiveEventExports(0),
                CacheSizeMB(0),
                Concurrency(0),
                CreditsPerMinute(0),
                EventsPerSecond(0),
                Level(0),
                MaxMemoryPerQueryMB(0),
                VirtualCpuCores(0)
            {}

            InsightsPerformanceLevel(const InsightsPerformanceLevel& src) :
                PlayFabBaseModel(),
                ActiveEventExports(src.ActiveEventExports),
                CacheSizeMB(src.CacheSizeMB),
                Concurrency(src.Concurrency),
                CreditsPerMinute(src.CreditsPerMinute),
                EventsPerSecond(src.EventsPerSecond),
                Level(src.Level),
                MaxMemoryPerQueryMB(src.MaxMemoryPerQueryMB),
                VirtualCpuCores(src.VirtualCpuCores)
            {}

            InsightsPerformanceLevel(const rapidjson::Value& obj) : InsightsPerformanceLevel()
            {
                readFromValue(obj);
            }

            ~InsightsPerformanceLevel();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsGetLimitsResponse : public PlayFabBaseModel
        {
            Int32 DefaultPerformanceLevel;
            Int32 DefaultStorageRetentionDays;
            Int32 StorageMaxRetentionDays;
            Int32 StorageMinRetentionDays;
            std::list<InsightsPerformanceLevel> SubMeters;

            InsightsGetLimitsResponse() :
                PlayFabBaseModel(),
                DefaultPerformanceLevel(0),
                DefaultStorageRetentionDays(0),
                StorageMaxRetentionDays(0),
                StorageMinRetentionDays(0),
                SubMeters()
            {}

            InsightsGetLimitsResponse(const InsightsGetLimitsResponse& src) :
                PlayFabBaseModel(),
                DefaultPerformanceLevel(src.DefaultPerformanceLevel),
                DefaultStorageRetentionDays(src.DefaultStorageRetentionDays),
                StorageMaxRetentionDays(src.StorageMaxRetentionDays),
                StorageMinRetentionDays(src.StorageMinRetentionDays),
                SubMeters(src.SubMeters)
            {}

            InsightsGetLimitsResponse(const rapidjson::Value& obj) : InsightsGetLimitsResponse()
            {
                readFromValue(obj);
            }

            ~InsightsGetLimitsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsGetOperationStatusResponse : public PlayFabBaseModel
        {
            std::string Message;
            time_t OperationCompletedTime;
            std::string OperationId;
            time_t OperationLastUpdated;
            time_t OperationStartedTime;
            std::string OperationType;
            Int32 OperationValue;
            std::string Status;

            InsightsGetOperationStatusResponse() :
                PlayFabBaseModel(),
                Message(),
                OperationCompletedTime(0),
                OperationId(),
                OperationLastUpdated(0),
                OperationStartedTime(0),
                OperationType(),
                OperationValue(0),
                Status()
            {}

            InsightsGetOperationStatusResponse(const InsightsGetOperationStatusResponse& src) :
                PlayFabBaseModel(),
                Message(src.Message),
                OperationCompletedTime(src.OperationCompletedTime),
                OperationId(src.OperationId),
                OperationLastUpdated(src.OperationLastUpdated),
                OperationStartedTime(src.OperationStartedTime),
                OperationType(src.OperationType),
                OperationValue(src.OperationValue),
                Status(src.Status)
            {}

            InsightsGetOperationStatusResponse(const rapidjson::Value& obj) : InsightsGetOperationStatusResponse()
            {
                readFromValue(obj);
            }

            ~InsightsGetOperationStatusResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsGetDetailsResponse : public PlayFabBaseModel
        {
            Uint32 DataUsageMb;
            std::string ErrorMessage;
            InsightsGetLimitsResponse* Limits;
            std::list<InsightsGetOperationStatusResponse> PendingOperations;
            Int32 PerformanceLevel;
            Int32 RetentionDays;

            InsightsGetDetailsResponse() :
                PlayFabBaseModel(),
                DataUsageMb(0),
                ErrorMessage(),
                Limits(NULL),
                PendingOperations(),
                PerformanceLevel(0),
                RetentionDays(0)
            {}

            InsightsGetDetailsResponse(const InsightsGetDetailsResponse& src) :
                PlayFabBaseModel(),
                DataUsageMb(src.DataUsageMb),
                ErrorMessage(src.ErrorMessage),
                Limits(src.Limits ? new InsightsGetLimitsResponse(*src.Limits) : NULL),
                PendingOperations(src.PendingOperations),
                PerformanceLevel(src.PerformanceLevel),
                RetentionDays(src.RetentionDays)
            {}

            InsightsGetDetailsResponse(const rapidjson::Value& obj) : InsightsGetDetailsResponse()
            {
                readFromValue(obj);
            }

            ~InsightsGetDetailsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsGetOperationStatusRequest : public PlayFabBaseModel
        {
            std::string OperationId;

            InsightsGetOperationStatusRequest() :
                PlayFabBaseModel(),
                OperationId()
            {}

            InsightsGetOperationStatusRequest(const InsightsGetOperationStatusRequest& src) :
                PlayFabBaseModel(),
                OperationId(src.OperationId)
            {}

            InsightsGetOperationStatusRequest(const rapidjson::Value& obj) : InsightsGetOperationStatusRequest()
            {
                readFromValue(obj);
            }

            ~InsightsGetOperationStatusRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsGetPendingOperationsRequest : public PlayFabBaseModel
        {
            std::string OperationType;

            InsightsGetPendingOperationsRequest() :
                PlayFabBaseModel(),
                OperationType()
            {}

            InsightsGetPendingOperationsRequest(const InsightsGetPendingOperationsRequest& src) :
                PlayFabBaseModel(),
                OperationType(src.OperationType)
            {}

            InsightsGetPendingOperationsRequest(const rapidjson::Value& obj) : InsightsGetPendingOperationsRequest()
            {
                readFromValue(obj);
            }

            ~InsightsGetPendingOperationsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsGetPendingOperationsResponse : public PlayFabBaseModel
        {
            std::list<InsightsGetOperationStatusResponse> PendingOperations;

            InsightsGetPendingOperationsResponse() :
                PlayFabBaseModel(),
                PendingOperations()
            {}

            InsightsGetPendingOperationsResponse(const InsightsGetPendingOperationsResponse& src) :
                PlayFabBaseModel(),
                PendingOperations(src.PendingOperations)
            {}

            InsightsGetPendingOperationsResponse(const rapidjson::Value& obj) : InsightsGetPendingOperationsResponse()
            {
                readFromValue(obj);
            }

            ~InsightsGetPendingOperationsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsOperationResponse : public PlayFabBaseModel
        {
            std::string Message;
            std::string OperationId;
            std::string OperationType;

            InsightsOperationResponse() :
                PlayFabBaseModel(),
                Message(),
                OperationId(),
                OperationType()
            {}

            InsightsOperationResponse(const InsightsOperationResponse& src) :
                PlayFabBaseModel(),
                Message(src.Message),
                OperationId(src.OperationId),
                OperationType(src.OperationType)
            {}

            InsightsOperationResponse(const rapidjson::Value& obj) : InsightsOperationResponse()
            {
                readFromValue(obj);
            }

            ~InsightsOperationResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsSetPerformanceRequest : public PlayFabBaseModel
        {
            Int32 PerformanceLevel;

            InsightsSetPerformanceRequest() :
                PlayFabBaseModel(),
                PerformanceLevel(0)
            {}

            InsightsSetPerformanceRequest(const InsightsSetPerformanceRequest& src) :
                PlayFabBaseModel(),
                PerformanceLevel(src.PerformanceLevel)
            {}

            InsightsSetPerformanceRequest(const rapidjson::Value& obj) : InsightsSetPerformanceRequest()
            {
                readFromValue(obj);
            }

            ~InsightsSetPerformanceRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InsightsSetStorageRetentionRequest : public PlayFabBaseModel
        {
            Int32 RetentionDays;

            InsightsSetStorageRetentionRequest() :
                PlayFabBaseModel(),
                RetentionDays(0)
            {}

            InsightsSetStorageRetentionRequest(const InsightsSetStorageRetentionRequest& src) :
                PlayFabBaseModel(),
                RetentionDays(src.RetentionDays)
            {}

            InsightsSetStorageRetentionRequest(const rapidjson::Value& obj) : InsightsSetStorageRetentionRequest()
            {
                readFromValue(obj);
            }

            ~InsightsSetStorageRetentionRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
