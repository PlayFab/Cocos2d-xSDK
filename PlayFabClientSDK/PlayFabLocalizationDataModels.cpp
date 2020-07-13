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
    if (!CustomTags.empty()) {
        writer.String("CustomTags");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = CustomTags.begin(); iter != CustomTags.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool GetLanguageListRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CustomTags_member = obj.FindMember("CustomTags");
    if (CustomTags_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = CustomTags_member->value.MemberBegin(); iter != CustomTags_member->value.MemberEnd(); ++iter) {
            CustomTags[iter->name.GetString()] = iter->value.GetString();
        }
    }

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

