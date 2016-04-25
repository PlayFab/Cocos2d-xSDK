#ifndef PLAYFAB_MATCHMAKERAPI_H_
#define PLAYFAB_MATCHMAKERAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabMatchmakerDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabMatchmakerAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = void(*)(const ResType& result, void* userData);

        // ------------ Generated API calls
        static void AuthUser(MatchmakerModels::AuthUserRequest& request, ProcessApiCallback<MatchmakerModels::AuthUserResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, ProcessApiCallback<MatchmakerModels::PlayerJoinedResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, ProcessApiCallback<MatchmakerModels::PlayerLeftResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void StartGame(MatchmakerModels::StartGameRequest& request, ProcessApiCallback<MatchmakerModels::StartGameResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UserInfo(MatchmakerModels::UserInfoRequest& request, ProcessApiCallback<MatchmakerModels::UserInfoResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabMatchmakerAPI();

        // ------------ Generated result handlers
        static void OnAuthUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPlayerJoinedResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnStartGameResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUserInfoResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
