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
        static void GetEntityToken(AuthenticationModels::GetEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ValidateEntityToken(AuthenticationModels::ValidateEntityTokenRequest& request, ProcessApiCallback<AuthenticationModels::ValidateEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabAuthenticationAPI();

        // ------------ Generated result handlers
        static void OnGetEntityTokenResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnValidateEntityTokenResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
