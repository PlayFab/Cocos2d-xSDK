#ifndef PLAYFAB_DATAAPI_H_
#define PLAYFAB_DATAAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabDataDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabDataAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void AbortFileUploads(DataModels::AbortFileUploadsRequest& request, ProcessApiCallback<DataModels::AbortFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteFiles(DataModels::DeleteFilesRequest& request, ProcessApiCallback<DataModels::DeleteFilesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void FinalizeFileUploads(DataModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetFiles(DataModels::GetFilesRequest& request, ProcessApiCallback<DataModels::GetFilesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetObjects(DataModels::GetObjectsRequest& request, ProcessApiCallback<DataModels::GetObjectsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void InitiateFileUploads(DataModels::InitiateFileUploadsRequest& request, ProcessApiCallback<DataModels::InitiateFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetObjects(DataModels::SetObjectsRequest& request, ProcessApiCallback<DataModels::SetObjectsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabDataAPI();

        // ------------ Generated result handlers
        static void OnAbortFileUploadsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteFilesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnFinalizeFileUploadsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetFilesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetObjectsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnInitiateFileUploadsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetObjectsResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
