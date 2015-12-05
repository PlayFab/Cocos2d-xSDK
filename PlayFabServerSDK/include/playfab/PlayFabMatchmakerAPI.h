#ifndef PLAYFAB_MATCHMAKERAPI_H_
#define PLAYFAB_MATCHMAKERAPI_H_

#include "playfab/IHttpRequester.h"
#include "playfab/PlayFabError.h"
#include "playfab/PlayFabMatchmakerDataModels.h"
#include "playfab/PlayFabSettings.h"
#include <string>

namespace PlayFab
{
    class PlayFabMatchmakerAPI
    {
    public:
        typedef void(*AuthUserCallback)(MatchmakerModels::AuthUserResponse& result, void* userData);
        typedef void(*PlayerJoinedCallback)(MatchmakerModels::PlayerJoinedResponse& result, void* userData);
        typedef void(*PlayerLeftCallback)(MatchmakerModels::PlayerLeftResponse& result, void* userData);
        typedef void(*StartGameCallback)(MatchmakerModels::StartGameResponse& result, void* userData);
        typedef void(*UserInfoCallback)(MatchmakerModels::UserInfoResponse& result, void* userData);

        static size_t Update();

        // ------------ Generated API calls
        static void AuthUser(MatchmakerModels::AuthUserRequest& request, AuthUserCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PlayerJoined(MatchmakerModels::PlayerJoinedRequest& request, PlayerJoinedCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void PlayerLeft(MatchmakerModels::PlayerLeftRequest& request, PlayerLeftCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void StartGame(MatchmakerModels::StartGameRequest& request, StartGameCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UserInfo(MatchmakerModels::UserInfoRequest& request, UserInfoCallback callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabMatchmakerAPI();

        // ------------ Generated result handlers
        static void OnAuthUserResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPlayerJoinedResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnPlayerLeftResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnStartGameResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUserInfoResult(int httpStatus, HttpRequest* request, void* userData);

        static IHttpRequester* mHttpRequester;
    };
};
#endif
