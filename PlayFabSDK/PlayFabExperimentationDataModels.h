#ifndef PLAYFAB_EXPERIMENTATION_DATA_MODELS_H_
#define PLAYFAB_EXPERIMENTATION_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ExperimentationModels
    {
        enum AnalysisTaskState
        {
            AnalysisTaskStateWaiting,
            AnalysisTaskStateReadyForSubmission,
            AnalysisTaskStateSubmittingToPipeline,
            AnalysisTaskStateRunning,
            AnalysisTaskStateCompleted,
            AnalysisTaskStateFailed,
            AnalysisTaskStateCanceled
        };

        void writeAnalysisTaskStateEnumJSON(AnalysisTaskState enumVal, PFStringJsonWriter& writer);
        AnalysisTaskState readAnalysisTaskStateFromValue(const rapidjson::Value& obj);

        enum ExperimentType
        {
            ExperimentTypeActive,
            ExperimentTypeSnapshot
        };

        void writeExperimentTypeEnumJSON(ExperimentType enumVal, PFStringJsonWriter& writer);
        ExperimentType readExperimentTypeFromValue(const rapidjson::Value& obj);

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

        struct Variant : public PlayFabBaseModel
        {
            std::string Description;
            std::string Id;
            bool IsControl;
            std::string Name;
            Uint32 TrafficPercentage;
            std::list<Variable> Variables;

            Variant() :
                PlayFabBaseModel(),
                Description(),
                Id(),
                IsControl(false),
                Name(),
                TrafficPercentage(0),
                Variables()
            {}

            Variant(const Variant& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                Id(src.Id),
                IsControl(src.IsControl),
                Name(src.Name),
                TrafficPercentage(src.TrafficPercentage),
                Variables(src.Variables)
            {}

            Variant(const rapidjson::Value& obj) : Variant()
            {
                readFromValue(obj);
            }

            ~Variant();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateExperimentRequest : public PlayFabBaseModel
        {
            std::string Description;
            Uint32 Duration;
            Boxed<ExperimentType> pfExperimentType;
            std::string Name;
            std::string SegmentId;
            time_t StartDate;
            std::list<std::string> TitlePlayerAccountTestIds;
            std::list<Variant> Variants;

            CreateExperimentRequest() :
                PlayFabBaseModel(),
                Description(),
                Duration(0),
                pfExperimentType(),
                Name(),
                SegmentId(),
                StartDate(0),
                TitlePlayerAccountTestIds(),
                Variants()
            {}

            CreateExperimentRequest(const CreateExperimentRequest& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                Duration(src.Duration),
                pfExperimentType(src.pfExperimentType),
                Name(src.Name),
                SegmentId(src.SegmentId),
                StartDate(src.StartDate),
                TitlePlayerAccountTestIds(src.TitlePlayerAccountTestIds),
                Variants(src.Variants)
            {}

            CreateExperimentRequest(const rapidjson::Value& obj) : CreateExperimentRequest()
            {
                readFromValue(obj);
            }

            ~CreateExperimentRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateExperimentResult : public PlayFabBaseModel
        {
            std::string ExperimentId;

            CreateExperimentResult() :
                PlayFabBaseModel(),
                ExperimentId()
            {}

            CreateExperimentResult(const CreateExperimentResult& src) :
                PlayFabBaseModel(),
                ExperimentId(src.ExperimentId)
            {}

            CreateExperimentResult(const rapidjson::Value& obj) : CreateExperimentResult()
            {
                readFromValue(obj);
            }

            ~CreateExperimentResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteExperimentRequest : public PlayFabBaseModel
        {
            std::string ExperimentId;

            DeleteExperimentRequest() :
                PlayFabBaseModel(),
                ExperimentId()
            {}

            DeleteExperimentRequest(const DeleteExperimentRequest& src) :
                PlayFabBaseModel(),
                ExperimentId(src.ExperimentId)
            {}

            DeleteExperimentRequest(const rapidjson::Value& obj) : DeleteExperimentRequest()
            {
                readFromValue(obj);
            }

            ~DeleteExperimentRequest();

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

        enum ExperimentState
        {
            ExperimentStateNew,
            ExperimentStateStarted,
            ExperimentStateStopped,
            ExperimentStateDeleted
        };

        void writeExperimentStateEnumJSON(ExperimentState enumVal, PFStringJsonWriter& writer);
        ExperimentState readExperimentStateFromValue(const rapidjson::Value& obj);

        struct Experiment : public PlayFabBaseModel
        {
            std::string Description;
            Uint32 Duration;
            Boxed<ExperimentType> pfExperimentType;
            std::string Id;
            std::string Name;
            std::string SegmentId;
            time_t StartDate;
            Boxed<ExperimentState> State;
            std::list<std::string> TitlePlayerAccountTestIds;
            std::list<Variant> Variants;

            Experiment() :
                PlayFabBaseModel(),
                Description(),
                Duration(0),
                pfExperimentType(),
                Id(),
                Name(),
                SegmentId(),
                StartDate(0),
                State(),
                TitlePlayerAccountTestIds(),
                Variants()
            {}

            Experiment(const Experiment& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                Duration(src.Duration),
                pfExperimentType(src.pfExperimentType),
                Id(src.Id),
                Name(src.Name),
                SegmentId(src.SegmentId),
                StartDate(src.StartDate),
                State(src.State),
                TitlePlayerAccountTestIds(src.TitlePlayerAccountTestIds),
                Variants(src.Variants)
            {}

            Experiment(const rapidjson::Value& obj) : Experiment()
            {
                readFromValue(obj);
            }

            ~Experiment();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetExperimentsRequest : public PlayFabBaseModel
        {

            GetExperimentsRequest() :
                PlayFabBaseModel()
            {}

            GetExperimentsRequest(const GetExperimentsRequest& src) :
                PlayFabBaseModel()
            {}

            GetExperimentsRequest(const rapidjson::Value& obj) : GetExperimentsRequest()
            {
                readFromValue(obj);
            }

            ~GetExperimentsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetExperimentsResult : public PlayFabBaseModel
        {
            std::list<Experiment> Experiments;

            GetExperimentsResult() :
                PlayFabBaseModel(),
                Experiments()
            {}

            GetExperimentsResult(const GetExperimentsResult& src) :
                PlayFabBaseModel(),
                Experiments(src.Experiments)
            {}

            GetExperimentsResult(const rapidjson::Value& obj) : GetExperimentsResult()
            {
                readFromValue(obj);
            }

            ~GetExperimentsResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLatestScorecardRequest : public PlayFabBaseModel
        {
            std::string ExperimentId;

            GetLatestScorecardRequest() :
                PlayFabBaseModel(),
                ExperimentId()
            {}

            GetLatestScorecardRequest(const GetLatestScorecardRequest& src) :
                PlayFabBaseModel(),
                ExperimentId(src.ExperimentId)
            {}

            GetLatestScorecardRequest(const rapidjson::Value& obj) : GetLatestScorecardRequest()
            {
                readFromValue(obj);
            }

            ~GetLatestScorecardRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct MetricData : public PlayFabBaseModel
        {
            double ConfidenceIntervalEnd;
            double ConfidenceIntervalStart;
            float DeltaAbsoluteChange;
            float DeltaRelativeChange;
            std::string InternalName;
            std::string Movement;
            std::string Name;
            float PMove;
            float PValue;
            float PValueThreshold;
            std::string StatSigLevel;
            float StdDev;
            float Value;

            MetricData() :
                PlayFabBaseModel(),
                ConfidenceIntervalEnd(0),
                ConfidenceIntervalStart(0),
                DeltaAbsoluteChange(0),
                DeltaRelativeChange(0),
                InternalName(),
                Movement(),
                Name(),
                PMove(0),
                PValue(0),
                PValueThreshold(0),
                StatSigLevel(),
                StdDev(0),
                Value(0)
            {}

            MetricData(const MetricData& src) :
                PlayFabBaseModel(),
                ConfidenceIntervalEnd(src.ConfidenceIntervalEnd),
                ConfidenceIntervalStart(src.ConfidenceIntervalStart),
                DeltaAbsoluteChange(src.DeltaAbsoluteChange),
                DeltaRelativeChange(src.DeltaRelativeChange),
                InternalName(src.InternalName),
                Movement(src.Movement),
                Name(src.Name),
                PMove(src.PMove),
                PValue(src.PValue),
                PValueThreshold(src.PValueThreshold),
                StatSigLevel(src.StatSigLevel),
                StdDev(src.StdDev),
                Value(src.Value)
            {}

            MetricData(const rapidjson::Value& obj) : MetricData()
            {
                readFromValue(obj);
            }

            ~MetricData();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ScorecardDataRow : public PlayFabBaseModel
        {
            bool IsControl;
            std::map<std::string, MetricData> MetricDataRows;
            Uint32 PlayerCount;
            std::string VariantName;

            ScorecardDataRow() :
                PlayFabBaseModel(),
                IsControl(false),
                MetricDataRows(),
                PlayerCount(0),
                VariantName()
            {}

            ScorecardDataRow(const ScorecardDataRow& src) :
                PlayFabBaseModel(),
                IsControl(src.IsControl),
                MetricDataRows(src.MetricDataRows),
                PlayerCount(src.PlayerCount),
                VariantName(src.VariantName)
            {}

            ScorecardDataRow(const rapidjson::Value& obj) : ScorecardDataRow()
            {
                readFromValue(obj);
            }

            ~ScorecardDataRow();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct Scorecard : public PlayFabBaseModel
        {
            std::string DateGenerated;
            std::string Duration;
            double EventsProcessed;
            std::string ExperimentId;
            std::string ExperimentName;
            Boxed<AnalysisTaskState> LatestJobStatus;
            bool SampleRatioMismatch;
            std::list<ScorecardDataRow> ScorecardDataRows;

            Scorecard() :
                PlayFabBaseModel(),
                DateGenerated(),
                Duration(),
                EventsProcessed(0),
                ExperimentId(),
                ExperimentName(),
                LatestJobStatus(),
                SampleRatioMismatch(false),
                ScorecardDataRows()
            {}

            Scorecard(const Scorecard& src) :
                PlayFabBaseModel(),
                DateGenerated(src.DateGenerated),
                Duration(src.Duration),
                EventsProcessed(src.EventsProcessed),
                ExperimentId(src.ExperimentId),
                ExperimentName(src.ExperimentName),
                LatestJobStatus(src.LatestJobStatus),
                SampleRatioMismatch(src.SampleRatioMismatch),
                ScorecardDataRows(src.ScorecardDataRows)
            {}

            Scorecard(const rapidjson::Value& obj) : Scorecard()
            {
                readFromValue(obj);
            }

            ~Scorecard();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLatestScorecardResult : public PlayFabBaseModel
        {
            Scorecard* pfScorecard;

            GetLatestScorecardResult() :
                PlayFabBaseModel(),
                pfScorecard(NULL)
            {}

            GetLatestScorecardResult(const GetLatestScorecardResult& src) :
                PlayFabBaseModel(),
                pfScorecard(src.pfScorecard ? new Scorecard(*src.pfScorecard) : NULL)
            {}

            GetLatestScorecardResult(const rapidjson::Value& obj) : GetLatestScorecardResult()
            {
                readFromValue(obj);
            }

            ~GetLatestScorecardResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTreatmentAssignmentRequest : public PlayFabBaseModel
        {
            EntityKey* Entity;

            GetTreatmentAssignmentRequest() :
                PlayFabBaseModel(),
                Entity(NULL)
            {}

            GetTreatmentAssignmentRequest(const GetTreatmentAssignmentRequest& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL)
            {}

            GetTreatmentAssignmentRequest(const rapidjson::Value& obj) : GetTreatmentAssignmentRequest()
            {
                readFromValue(obj);
            }

            ~GetTreatmentAssignmentRequest();

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

        struct GetTreatmentAssignmentResult : public PlayFabBaseModel
        {
            TreatmentAssignment* pfTreatmentAssignment;

            GetTreatmentAssignmentResult() :
                PlayFabBaseModel(),
                pfTreatmentAssignment(NULL)
            {}

            GetTreatmentAssignmentResult(const GetTreatmentAssignmentResult& src) :
                PlayFabBaseModel(),
                pfTreatmentAssignment(src.pfTreatmentAssignment ? new TreatmentAssignment(*src.pfTreatmentAssignment) : NULL)
            {}

            GetTreatmentAssignmentResult(const rapidjson::Value& obj) : GetTreatmentAssignmentResult()
            {
                readFromValue(obj);
            }

            ~GetTreatmentAssignmentResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StartExperimentRequest : public PlayFabBaseModel
        {
            std::string ExperimentId;

            StartExperimentRequest() :
                PlayFabBaseModel(),
                ExperimentId()
            {}

            StartExperimentRequest(const StartExperimentRequest& src) :
                PlayFabBaseModel(),
                ExperimentId(src.ExperimentId)
            {}

            StartExperimentRequest(const rapidjson::Value& obj) : StartExperimentRequest()
            {
                readFromValue(obj);
            }

            ~StartExperimentRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct StopExperimentRequest : public PlayFabBaseModel
        {
            std::string ExperimentId;

            StopExperimentRequest() :
                PlayFabBaseModel(),
                ExperimentId()
            {}

            StopExperimentRequest(const StopExperimentRequest& src) :
                PlayFabBaseModel(),
                ExperimentId(src.ExperimentId)
            {}

            StopExperimentRequest(const rapidjson::Value& obj) : StopExperimentRequest()
            {
                readFromValue(obj);
            }

            ~StopExperimentRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateExperimentRequest : public PlayFabBaseModel
        {
            std::string Description;
            Uint32 Duration;
            Boxed<ExperimentType> pfExperimentType;
            std::string Id;
            std::string Name;
            std::string SegmentId;
            time_t StartDate;
            std::list<std::string> TitlePlayerAccountTestIds;
            std::list<Variant> Variants;

            UpdateExperimentRequest() :
                PlayFabBaseModel(),
                Description(),
                Duration(0),
                pfExperimentType(),
                Id(),
                Name(),
                SegmentId(),
                StartDate(0),
                TitlePlayerAccountTestIds(),
                Variants()
            {}

            UpdateExperimentRequest(const UpdateExperimentRequest& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                Duration(src.Duration),
                pfExperimentType(src.pfExperimentType),
                Id(src.Id),
                Name(src.Name),
                SegmentId(src.SegmentId),
                StartDate(src.StartDate),
                TitlePlayerAccountTestIds(src.TitlePlayerAccountTestIds),
                Variants(src.Variants)
            {}

            UpdateExperimentRequest(const rapidjson::Value& obj) : UpdateExperimentRequest()
            {
                readFromValue(obj);
            }

            ~UpdateExperimentRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
