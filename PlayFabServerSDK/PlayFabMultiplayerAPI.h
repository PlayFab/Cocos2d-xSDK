#ifndef PLAYFAB_MULTIPLAYERAPI_H_
#define PLAYFAB_MULTIPLAYERAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabMultiplayerDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabMultiplayerAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void CancelAllMatchmakingTicketsForPlayer(MultiplayerModels::CancelAllMatchmakingTicketsForPlayerRequest& request, ProcessApiCallback<MultiplayerModels::CancelAllMatchmakingTicketsForPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CancelMatchmakingTicket(MultiplayerModels::CancelMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CancelMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateBuildAlias(MultiplayerModels::CreateBuildAliasRequest& request, ProcessApiCallback<MultiplayerModels::BuildAliasDetailsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateBuildWithCustomContainer(MultiplayerModels::CreateBuildWithCustomContainerRequest& request, ProcessApiCallback<MultiplayerModels::CreateBuildWithCustomContainerResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateBuildWithManagedContainer(MultiplayerModels::CreateBuildWithManagedContainerRequest& request, ProcessApiCallback<MultiplayerModels::CreateBuildWithManagedContainerResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateMatchmakingTicket(MultiplayerModels::CreateMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CreateMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateRemoteUser(MultiplayerModels::CreateRemoteUserRequest& request, ProcessApiCallback<MultiplayerModels::CreateRemoteUserResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateServerMatchmakingTicket(MultiplayerModels::CreateServerMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::CreateMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteAsset(MultiplayerModels::DeleteAssetRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteBuild(MultiplayerModels::DeleteBuildRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteBuildAlias(MultiplayerModels::DeleteBuildAliasRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteCertificate(MultiplayerModels::DeleteCertificateRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteRemoteUser(MultiplayerModels::DeleteRemoteUserRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void EnableMultiplayerServersForTitle(ProcessApiCallback<MultiplayerModels::EnableMultiplayerServersForTitleResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetAssetUploadUrl(MultiplayerModels::GetAssetUploadUrlRequest& request, ProcessApiCallback<MultiplayerModels::GetAssetUploadUrlResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetBuild(MultiplayerModels::GetBuildRequest& request, ProcessApiCallback<MultiplayerModels::GetBuildResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetBuildAlias(MultiplayerModels::GetBuildAliasRequest& request, ProcessApiCallback<MultiplayerModels::BuildAliasDetailsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetContainerRegistryCredentials(ProcessApiCallback<MultiplayerModels::GetContainerRegistryCredentialsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMatch(MultiplayerModels::GetMatchRequest& request, ProcessApiCallback<MultiplayerModels::GetMatchResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMatchmakingTicket(MultiplayerModels::GetMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::GetMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMultiplayerServerDetails(MultiplayerModels::GetMultiplayerServerDetailsRequest& request, ProcessApiCallback<MultiplayerModels::GetMultiplayerServerDetailsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMultiplayerServerLogs(MultiplayerModels::GetMultiplayerServerLogsRequest& request, ProcessApiCallback<MultiplayerModels::GetMultiplayerServerLogsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetQueueStatistics(MultiplayerModels::GetQueueStatisticsRequest& request, ProcessApiCallback<MultiplayerModels::GetQueueStatisticsResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetRemoteLoginEndpoint(MultiplayerModels::GetRemoteLoginEndpointRequest& request, ProcessApiCallback<MultiplayerModels::GetRemoteLoginEndpointResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleEnabledForMultiplayerServersStatus(ProcessApiCallback<MultiplayerModels::GetTitleEnabledForMultiplayerServersStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleMultiplayerServersQuotas(ProcessApiCallback<MultiplayerModels::GetTitleMultiplayerServersQuotasResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void JoinMatchmakingTicket(MultiplayerModels::JoinMatchmakingTicketRequest& request, ProcessApiCallback<MultiplayerModels::JoinMatchmakingTicketResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListArchivedMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListAssetSummaries(MultiplayerModels::ListAssetSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListAssetSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListBuildAliases(ProcessApiCallback<MultiplayerModels::ListBuildAliasesForTitleResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListBuildSummaries(MultiplayerModels::ListBuildSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListBuildSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListCertificateSummaries(MultiplayerModels::ListCertificateSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListCertificateSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListContainerImages(MultiplayerModels::ListContainerImagesRequest& request, ProcessApiCallback<MultiplayerModels::ListContainerImagesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListContainerImageTags(MultiplayerModels::ListContainerImageTagsRequest& request, ProcessApiCallback<MultiplayerModels::ListContainerImageTagsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListMatchmakingTicketsForPlayer(MultiplayerModels::ListMatchmakingTicketsForPlayerRequest& request, ProcessApiCallback<MultiplayerModels::ListMatchmakingTicketsForPlayerResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListPartyQosServers(MultiplayerModels::ListPartyQosServersRequest& request, ProcessApiCallback<MultiplayerModels::ListPartyQosServersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListQosServers(ProcessApiCallback<MultiplayerModels::ListQosServersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListQosServersForTitle(ProcessApiCallback<MultiplayerModels::ListQosServersForTitleResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListVirtualMachineSummaries(MultiplayerModels::ListVirtualMachineSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListVirtualMachineSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RequestMultiplayerServer(MultiplayerModels::RequestMultiplayerServerRequest& request, ProcessApiCallback<MultiplayerModels::RequestMultiplayerServerResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RolloverContainerRegistryCredentials(ProcessApiCallback<MultiplayerModels::RolloverContainerRegistryCredentialsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ShutdownMultiplayerServer(MultiplayerModels::ShutdownMultiplayerServerRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UntagContainerImage(MultiplayerModels::UntagContainerImageRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateBuildAlias(MultiplayerModels::UpdateBuildAliasRequest& request, ProcessApiCallback<MultiplayerModels::BuildAliasDetailsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateBuildRegions(MultiplayerModels::UpdateBuildRegionsRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UploadCertificate(MultiplayerModels::UploadCertificateRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabMultiplayerAPI();

        // ------------ Generated result handlers
        static void OnCancelAllMatchmakingTicketsForPlayerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCancelMatchmakingTicketResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateBuildAliasResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateBuildWithCustomContainerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateBuildWithManagedContainerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateMatchmakingTicketResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateRemoteUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateServerMatchmakingTicketResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteAssetResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteBuildResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteBuildAliasResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteCertificateResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteRemoteUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnEnableMultiplayerServersForTitleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetAssetUploadUrlResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetBuildResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetBuildAliasResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetContainerRegistryCredentialsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetMatchResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetMatchmakingTicketResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetMultiplayerServerDetailsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetMultiplayerServerLogsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetQueueStatisticsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetRemoteLoginEndpointResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleEnabledForMultiplayerServersStatusResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleMultiplayerServersQuotasResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnJoinMatchmakingTicketResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListArchivedMultiplayerServersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListAssetSummariesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListBuildAliasesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListBuildSummariesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListCertificateSummariesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListContainerImagesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListContainerImageTagsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListMatchmakingTicketsForPlayerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListMultiplayerServersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListPartyQosServersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListQosServersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListQosServersForTitleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListVirtualMachineSummariesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRequestMultiplayerServerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRolloverContainerRegistryCredentialsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnShutdownMultiplayerServerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUntagContainerImageResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateBuildAliasResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateBuildRegionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUploadCertificateResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
