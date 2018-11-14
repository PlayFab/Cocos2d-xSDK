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
        static void CreateBuildWithCustomContainer(MultiplayerModels::CreateBuildWithCustomContainerRequest& request, ProcessApiCallback<MultiplayerModels::CreateBuildWithCustomContainerResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateBuildWithManagedContainer(MultiplayerModels::CreateBuildWithManagedContainerRequest& request, ProcessApiCallback<MultiplayerModels::CreateBuildWithManagedContainerResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateRemoteUser(MultiplayerModels::CreateRemoteUserRequest& request, ProcessApiCallback<MultiplayerModels::CreateRemoteUserResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteAsset(MultiplayerModels::DeleteAssetRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteBuild(MultiplayerModels::DeleteBuildRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteCertificate(MultiplayerModels::DeleteCertificateRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteRemoteUser(MultiplayerModels::DeleteRemoteUserRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void EnableMultiplayerServersForTitle(ProcessApiCallback<MultiplayerModels::EnableMultiplayerServersForTitleResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetAssetUploadUrl(MultiplayerModels::GetAssetUploadUrlRequest& request, ProcessApiCallback<MultiplayerModels::GetAssetUploadUrlResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetBuild(MultiplayerModels::GetBuildRequest& request, ProcessApiCallback<MultiplayerModels::GetBuildResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetContainerRegistryCredentials(ProcessApiCallback<MultiplayerModels::GetContainerRegistryCredentialsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetMultiplayerServerDetails(MultiplayerModels::GetMultiplayerServerDetailsRequest& request, ProcessApiCallback<MultiplayerModels::GetMultiplayerServerDetailsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetRemoteLoginEndpoint(MultiplayerModels::GetRemoteLoginEndpointRequest& request, ProcessApiCallback<MultiplayerModels::GetRemoteLoginEndpointResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitleEnabledForMultiplayerServersStatus(ProcessApiCallback<MultiplayerModels::GetTitleEnabledForMultiplayerServersStatusResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListArchivedMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListAssetSummaries(MultiplayerModels::ListAssetSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListAssetSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListBuildSummaries(MultiplayerModels::ListBuildSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListBuildSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListCertificateSummaries(MultiplayerModels::ListCertificateSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListCertificateSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListContainerImages(MultiplayerModels::ListContainerImagesRequest& request, ProcessApiCallback<MultiplayerModels::ListContainerImagesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListContainerImageTags(MultiplayerModels::ListContainerImageTagsRequest& request, ProcessApiCallback<MultiplayerModels::ListContainerImageTagsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListMultiplayerServers(MultiplayerModels::ListMultiplayerServersRequest& request, ProcessApiCallback<MultiplayerModels::ListMultiplayerServersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListQosServers(ProcessApiCallback<MultiplayerModels::ListQosServersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListVirtualMachineSummaries(MultiplayerModels::ListVirtualMachineSummariesRequest& request, ProcessApiCallback<MultiplayerModels::ListVirtualMachineSummariesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RequestMultiplayerServer(MultiplayerModels::RequestMultiplayerServerRequest& request, ProcessApiCallback<MultiplayerModels::RequestMultiplayerServerResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RolloverContainerRegistryCredentials(ProcessApiCallback<MultiplayerModels::RolloverContainerRegistryCredentialsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ShutdownMultiplayerServer(MultiplayerModels::ShutdownMultiplayerServerRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateBuildRegions(MultiplayerModels::UpdateBuildRegionsRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UploadCertificate(MultiplayerModels::UploadCertificateRequest& request, ProcessApiCallback<MultiplayerModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabMultiplayerAPI();

        // ------------ Generated result handlers
        static void OnCreateBuildWithCustomContainerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateBuildWithManagedContainerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateRemoteUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteAssetResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteBuildResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteCertificateResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteRemoteUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnEnableMultiplayerServersForTitleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetAssetUploadUrlResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetBuildResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetContainerRegistryCredentialsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetMultiplayerServerDetailsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetRemoteLoginEndpointResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitleEnabledForMultiplayerServersStatusResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListArchivedMultiplayerServersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListAssetSummariesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListBuildSummariesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListCertificateSummariesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListContainerImagesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListContainerImageTagsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListMultiplayerServersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListQosServersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListVirtualMachineSummariesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRequestMultiplayerServerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRolloverContainerRegistryCredentialsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnShutdownMultiplayerServerResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateBuildRegionsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUploadCertificateResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
