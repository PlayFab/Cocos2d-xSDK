#ifndef PLAYFAB_EVENTS_DATA_MODELS_H_
#define PLAYFAB_EVENTS_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace EventsModels
    {
        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup,
            EntityTypesservice
        };

        void writeEntityTypesEnumJSON(EntityTypes enumVal, PFStringJsonWriter& writer);
        EntityTypes readEntityTypesFromValue(const rapidjson::Value& obj);

        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            Boxed<EntityTypes> Type;
            std::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
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
            EntityKey Entity;
            std::string EventNamespace;
            std::string Name;
            std::string OriginalId;
            OptionalTime OriginalTimestamp;
            MultitypeVar Payload;
            std::string PayloadJSON;

            EventContents() :
                PlayFabBaseModel(),
                Entity(),
                EventNamespace(),
                Name(),
                OriginalId(),
                OriginalTimestamp(),
                Payload(),
                PayloadJSON()
            {}

            EventContents(const EventContents& src) :
                PlayFabBaseModel(),
                Entity(src.Entity),
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
            std::list<EventContents> Events;

            WriteEventsRequest() :
                PlayFabBaseModel(),
                Events()
            {}

            WriteEventsRequest(const WriteEventsRequest& src) :
                PlayFabBaseModel(),
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
