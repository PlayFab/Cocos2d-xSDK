#ifndef PLAYFAB_PROFILESAPI_H_
#define PLAYFAB_PROFILESAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabProfilesDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabProfilesAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void GetGlobalPolicy(ProcessApiCallback<ProfilesModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetProfile(ProfilesModels::GetEntityProfileRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetProfiles(ProfilesModels::GetEntityProfilesRequest& request, ProcessApiCallback<ProfilesModels::GetEntityProfilesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetTitlePlayersFromMasterPlayerAccountIds(ProfilesModels::GetTitlePlayersFromMasterPlayerAccountIdsRequest& request, ProcessApiCallback<ProfilesModels::GetTitlePlayersFromMasterPlayerAccountIdsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetGlobalPolicy(ProfilesModels::SetGlobalPolicyRequest& request, ProcessApiCallback<ProfilesModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetProfileLanguage(ProfilesModels::SetProfileLanguageRequest& request, ProcessApiCallback<ProfilesModels::SetProfileLanguageResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetProfilePolicy(ProfilesModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<ProfilesModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabProfilesAPI();

        // ------------ Generated result handlers
        static void OnGetGlobalPolicyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetProfileResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetProfilesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetTitlePlayersFromMasterPlayerAccountIdsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetGlobalPolicyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetProfileLanguageResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetProfilePolicyResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
