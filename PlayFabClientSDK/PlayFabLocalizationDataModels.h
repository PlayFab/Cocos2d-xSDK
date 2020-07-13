#ifndef PLAYFAB_LOCALIZATION_DATA_MODELS_H_
#define PLAYFAB_LOCALIZATION_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace LocalizationModels
    {
        struct GetLanguageListRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;

            GetLanguageListRequest() :
                PlayFabBaseModel(),
                CustomTags()
            {}

            GetLanguageListRequest(const GetLanguageListRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags)
            {}

            GetLanguageListRequest(const rapidjson::Value& obj) : GetLanguageListRequest()
            {
                readFromValue(obj);
            }

            ~GetLanguageListRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetLanguageListResponse : public PlayFabBaseModel
        {
            std::list<std::string> LanguageList;

            GetLanguageListResponse() :
                PlayFabBaseModel(),
                LanguageList()
            {}

            GetLanguageListResponse(const GetLanguageListResponse& src) :
                PlayFabBaseModel(),
                LanguageList(src.LanguageList)
            {}

            GetLanguageListResponse(const rapidjson::Value& obj) : GetLanguageListResponse()
            {
                readFromValue(obj);
            }

            ~GetLanguageListResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
