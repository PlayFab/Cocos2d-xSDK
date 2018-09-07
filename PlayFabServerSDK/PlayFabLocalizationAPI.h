#ifndef PLAYFAB_LOCALIZATIONAPI_H_
#define PLAYFAB_LOCALIZATIONAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabLocalizationDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabLocalizationAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void GetLanguageList(ProcessApiCallback<LocalizationModels::GetLanguageListResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabLocalizationAPI();

        // ------------ Generated result handlers
        static void OnGetLanguageListResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
