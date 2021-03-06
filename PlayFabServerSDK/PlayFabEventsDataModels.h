#ifndef PLAYFAB_EVENTS_DATA_MODELS_H_
#define PLAYFAB_EVENTS_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace EventsModels
    {
        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            std::string Type;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type)
            {}

            EntityKey(const rapidjson::Value& obj) : EntityKey()
            {
                readFromValue(obj);
            }

            ~EntityKey();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EventContents : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey* Entity;
            std::string EventNamespace;
            std::string Name;
            std::string OriginalId;
            OptionalTime OriginalTimestamp;
            MultitypeVar Payload;
            std::string PayloadJSON;

            EventContents() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(NULL),
                EventNamespace(),
                Name(),
                OriginalId(),
                OriginalTimestamp(),
                Payload(),
                PayloadJSON()
            {}

            EventContents(const EventContents& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                EventNamespace(src.EventNamespace),
                Name(src.Name),
                OriginalId(src.OriginalId),
                OriginalTimestamp(src.OriginalTimestamp),
                Payload(src.Payload),
                PayloadJSON(src.PayloadJSON)
            {}

            EventContents(const rapidjson::Value& obj) : EventContents()
            {
                readFromValue(obj);
            }

            ~EventContents();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteEventsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            std::list<EventContents> Events;

            WriteEventsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Events()
            {}

            WriteEventsRequest(const WriteEventsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Events(src.Events)
            {}

            WriteEventsRequest(const rapidjson::Value& obj) : WriteEventsRequest()
            {
                readFromValue(obj);
            }

            ~WriteEventsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct WriteEventsResponse : public PlayFabBaseModel
        {
            std::list<std::string> AssignedEventIds;

            WriteEventsResponse() :
                PlayFabBaseModel(),
                AssignedEventIds()
            {}

            WriteEventsResponse(const WriteEventsResponse& src) :
                PlayFabBaseModel(),
                AssignedEventIds(src.AssignedEventIds)
            {}

            WriteEventsResponse(const rapidjson::Value& obj) : WriteEventsResponse()
            {
                readFromValue(obj);
            }

            ~WriteEventsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
