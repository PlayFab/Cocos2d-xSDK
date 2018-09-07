#include "PlayFabLocalizationDataModels.h"

using namespace PlayFab;
using namespace PlayFab::LocalizationModels;
using namespace rapidjson;


GetLanguageListRequest::~GetLanguageListRequest()
{

}

void GetLanguageListRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool GetLanguageListRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetLanguageListResponse::~GetLanguageListResponse()
{

}

void GetLanguageListResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!LanguageList.empty()) {
        writer.String("LanguageList");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = LanguageList.begin(); iter != LanguageList.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool GetLanguageListResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator LanguageList_member = obj.FindMember("LanguageList");
    if (LanguageList_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = LanguageList_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            LanguageList.push_back(memberList[i].GetString());
        }
    }

    return true;
}

