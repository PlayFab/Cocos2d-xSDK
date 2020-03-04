#ifndef PLAYFAB_EXPERIMENTATIONAPI_H_
#define PLAYFAB_EXPERIMENTATIONAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabExperimentationDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabExperimentationAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void CreateExperiment(ExperimentationModels::CreateExperimentRequest& request, ProcessApiCallback<ExperimentationModels::CreateExperimentResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteExperiment(ExperimentationModels::DeleteExperimentRequest& request, ProcessApiCallback<ExperimentationModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetExperiments(ProcessApiCallback<ExperimentationModels::GetExperimentsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetLatestScorecard(ExperimentationModels::GetLatestScorecardRequest& request, ProcessApiCallback<ExperimentationModels::GetLatestScorecardResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTreatmentAssignment(ExperimentationModels::GetTreatmentAssignmentRequest& request, ProcessApiCallback<ExperimentationModels::GetTreatmentAssignmentResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void StartExperiment(ExperimentationModels::StartExperimentRequest& request, ProcessApiCallback<ExperimentationModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void StopExperiment(ExperimentationModels::StopExperimentRequest& request, ProcessApiCallback<ExperimentationModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateExperiment(ExperimentationModels::UpdateExperimentRequest& request, ProcessApiCallback<ExperimentationModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabExperimentationAPI();

        // ------------ Generated result handlers
        static void OnCreateExperimentResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteExperimentResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetExperimentsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetLatestScorecardResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTreatmentAssignmentResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnStartExperimentResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnStopExperimentResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateExperimentResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
