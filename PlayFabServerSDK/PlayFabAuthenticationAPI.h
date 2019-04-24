#ifndef PLAYFAB_AUTHENTICATIONAPI_H_
#define PLAYFAB_AUTHENTICATIONAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabAuthenticationDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabAuthenticationAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void ActivateKey(AuthenticationModels::ActivateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::ActivateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateKey(AuthenticationModels::CreateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::CreateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeactivateKey(AuthenticationModels::DeactivateAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::DeactivateAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteKey(AuthenticationModels::DeleteAPIKeyRequest& request, ProcessApiCallback<AuthenticationModels::DeleteAPIKeyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetKeys(AuthenticationModels::GetAPIKeysRequest& request, ProcessApiCallback<AuthenticationModels::GetAPIKeysResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabAuthenticationAPI();

        // ------------ Generated result handlers
        static void OnActivateKeyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateKeyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeactivateKeyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteKeyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetEntityTokenResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetKeysResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
