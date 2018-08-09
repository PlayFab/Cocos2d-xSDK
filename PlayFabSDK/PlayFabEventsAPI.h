#ifndef PLAYFAB_EVENTSAPI_H_
#define PLAYFAB_EVENTSAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabEventsDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabEventsAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void WriteEvents(EventsModels::WriteEventsRequest& request, ProcessApiCallback<EventsModels::WriteEventsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabEventsAPI();

        // ------------ Generated result handlers
        static void OnWriteEventsResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
