#ifndef PLAYFAB_DATA_DATA_MODELS_H_
#define PLAYFAB_DATA_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace DataModels
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

        struct AbortFileUploadsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            std::list<std::string> FileNames;
            OptionalInt32 ProfileVersion;

            AbortFileUploadsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            AbortFileUploadsRequest(const AbortFileUploadsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            AbortFileUploadsRequest(const rapidjson::Value& obj) : AbortFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~AbortFileUploadsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AbortFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;

            AbortFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                ProfileVersion(0)
            {}

            AbortFileUploadsResponse(const AbortFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                ProfileVersion(src.ProfileVersion)
            {}

            AbortFileUploadsResponse(const rapidjson::Value& obj) : AbortFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~AbortFileUploadsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteFilesRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            std::list<std::string> FileNames;
            OptionalInt32 ProfileVersion;

            DeleteFilesRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            DeleteFilesRequest(const DeleteFilesRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            DeleteFilesRequest(const rapidjson::Value& obj) : DeleteFilesRequest()
            {
                readFromValue(obj);
            }

            ~DeleteFilesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteFilesResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;

            DeleteFilesResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                ProfileVersion(0)
            {}

            DeleteFilesResponse(const DeleteFilesResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                ProfileVersion(src.ProfileVersion)
            {}

            DeleteFilesResponse(const rapidjson::Value& obj) : DeleteFilesResponse()
            {
                readFromValue(obj);
            }

            ~DeleteFilesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FinalizeFileUploadsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            std::list<std::string> FileNames;

            FinalizeFileUploadsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                FileNames()
            {}

            FinalizeFileUploadsRequest(const FinalizeFileUploadsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                FileNames(src.FileNames)
            {}

            FinalizeFileUploadsRequest(const rapidjson::Value& obj) : FinalizeFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~FinalizeFileUploadsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFileMetadata : public PlayFabBaseModel
        {
            std::string Checksum;
            std::string DownloadUrl;
            std::string FileName;
            time_t LastModified;
            Int32 Size;

            GetFileMetadata() :
                PlayFabBaseModel(),
                Checksum(),
                DownloadUrl(),
                FileName(),
                LastModified(0),
                Size(0)
            {}

            GetFileMetadata(const GetFileMetadata& src) :
                PlayFabBaseModel(),
                Checksum(src.Checksum),
                DownloadUrl(src.DownloadUrl),
                FileName(src.FileName),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            GetFileMetadata(const rapidjson::Value& obj) : GetFileMetadata()
            {
                readFromValue(obj);
            }

            ~GetFileMetadata();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct FinalizeFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<std::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            FinalizeFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Metadata(),
                ProfileVersion(0)
            {}

            FinalizeFileUploadsResponse(const FinalizeFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            FinalizeFileUploadsResponse(const rapidjson::Value& obj) : FinalizeFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~FinalizeFileUploadsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFilesRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;

            GetFilesRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity()
            {}

            GetFilesRequest(const GetFilesRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity)
            {}

            GetFilesRequest(const rapidjson::Value& obj) : GetFilesRequest()
            {
                readFromValue(obj);
            }

            ~GetFilesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetFilesResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<std::string, GetFileMetadata> Metadata;
            Int32 ProfileVersion;

            GetFilesResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Metadata(),
                ProfileVersion(0)
            {}

            GetFilesResponse(const GetFilesResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Metadata(src.Metadata),
                ProfileVersion(src.ProfileVersion)
            {}

            GetFilesResponse(const rapidjson::Value& obj) : GetFilesResponse()
            {
                readFromValue(obj);
            }

            ~GetFilesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetObjectsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            OptionalBool EscapeObject;

            GetObjectsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                EscapeObject()
            {}

            GetObjectsRequest(const GetObjectsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                EscapeObject(src.EscapeObject)
            {}

            GetObjectsRequest(const rapidjson::Value& obj) : GetObjectsRequest()
            {
                readFromValue(obj);
            }

            ~GetObjectsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ObjectResult : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            ObjectResult() :
                PlayFabBaseModel(),
                DataObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            ObjectResult(const ObjectResult& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            ObjectResult(const rapidjson::Value& obj) : ObjectResult()
            {
                readFromValue(obj);
            }

            ~ObjectResult();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetObjectsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            std::map<std::string, ObjectResult> Objects;
            Int32 ProfileVersion;

            GetObjectsResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                Objects(),
                ProfileVersion(0)
            {}

            GetObjectsResponse(const GetObjectsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                Objects(src.Objects),
                ProfileVersion(src.ProfileVersion)
            {}

            GetObjectsResponse(const rapidjson::Value& obj) : GetObjectsResponse()
            {
                readFromValue(obj);
            }

            ~GetObjectsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InitiateFileUploadMetadata : public PlayFabBaseModel
        {
            std::string FileName;
            std::string UploadUrl;

            InitiateFileUploadMetadata() :
                PlayFabBaseModel(),
                FileName(),
                UploadUrl()
            {}

            InitiateFileUploadMetadata(const InitiateFileUploadMetadata& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                UploadUrl(src.UploadUrl)
            {}

            InitiateFileUploadMetadata(const rapidjson::Value& obj) : InitiateFileUploadMetadata()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadMetadata();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InitiateFileUploadsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            std::list<std::string> FileNames;
            OptionalInt32 ProfileVersion;

            InitiateFileUploadsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                FileNames(),
                ProfileVersion()
            {}

            InitiateFileUploadsRequest(const InitiateFileUploadsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                FileNames(src.FileNames),
                ProfileVersion(src.ProfileVersion)
            {}

            InitiateFileUploadsRequest(const rapidjson::Value& obj) : InitiateFileUploadsRequest()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct InitiateFileUploadsResponse : public PlayFabBaseModel
        {
            EntityKey* Entity;
            Int32 ProfileVersion;
            std::list<InitiateFileUploadMetadata> UploadDetails;

            InitiateFileUploadsResponse() :
                PlayFabBaseModel(),
                Entity(NULL),
                ProfileVersion(0),
                UploadDetails()
            {}

            InitiateFileUploadsResponse(const InitiateFileUploadsResponse& src) :
                PlayFabBaseModel(),
                Entity(src.Entity ? new EntityKey(*src.Entity) : NULL),
                ProfileVersion(src.ProfileVersion),
                UploadDetails(src.UploadDetails)
            {}

            InitiateFileUploadsResponse(const rapidjson::Value& obj) : InitiateFileUploadsResponse()
            {
                readFromValue(obj);
            }

            ~InitiateFileUploadsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum OperationTypes
        {
            OperationTypesCreated,
            OperationTypesUpdated,
            OperationTypesDeleted,
            OperationTypesNone
        };

        void writeOperationTypesEnumJSON(OperationTypes enumVal, PFStringJsonWriter& writer);
        OperationTypes readOperationTypesFromValue(const rapidjson::Value& obj);

        struct SetObject : public PlayFabBaseModel
        {
            MultitypeVar DataObject;
            OptionalBool DeleteObject;
            std::string EscapedDataObject;
            std::string ObjectName;

            SetObject() :
                PlayFabBaseModel(),
                DataObject(),
                DeleteObject(),
                EscapedDataObject(),
                ObjectName()
            {}

            SetObject(const SetObject& src) :
                PlayFabBaseModel(),
                DataObject(src.DataObject),
                DeleteObject(src.DeleteObject),
                EscapedDataObject(src.EscapedDataObject),
                ObjectName(src.ObjectName)
            {}

            SetObject(const rapidjson::Value& obj) : SetObject()
            {
                readFromValue(obj);
            }

            ~SetObject();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetObjectInfo : public PlayFabBaseModel
        {
            std::string ObjectName;
            std::string OperationReason;
            Boxed<OperationTypes> SetResult;

            SetObjectInfo() :
                PlayFabBaseModel(),
                ObjectName(),
                OperationReason(),
                SetResult()
            {}

            SetObjectInfo(const SetObjectInfo& src) :
                PlayFabBaseModel(),
                ObjectName(src.ObjectName),
                OperationReason(src.OperationReason),
                SetResult(src.SetResult)
            {}

            SetObjectInfo(const rapidjson::Value& obj) : SetObjectInfo()
            {
                readFromValue(obj);
            }

            ~SetObjectInfo();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetObjectsRequest : public PlayFabBaseModel
        {
            std::map<std::string, std::string> CustomTags;
            EntityKey Entity;
            OptionalInt32 ExpectedProfileVersion;
            std::list<SetObject> Objects;

            SetObjectsRequest() :
                PlayFabBaseModel(),
                CustomTags(),
                Entity(),
                ExpectedProfileVersion(),
                Objects()
            {}

            SetObjectsRequest(const SetObjectsRequest& src) :
                PlayFabBaseModel(),
                CustomTags(src.CustomTags),
                Entity(src.Entity),
                ExpectedProfileVersion(src.ExpectedProfileVersion),
                Objects(src.Objects)
            {}

            SetObjectsRequest(const rapidjson::Value& obj) : SetObjectsRequest()
            {
                readFromValue(obj);
            }

            ~SetObjectsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct SetObjectsResponse : public PlayFabBaseModel
        {
            Int32 ProfileVersion;
            std::list<SetObjectInfo> SetResults;

            SetObjectsResponse() :
                PlayFabBaseModel(),
                ProfileVersion(0),
                SetResults()
            {}

            SetObjectsResponse(const SetObjectsResponse& src) :
                PlayFabBaseModel(),
                ProfileVersion(src.ProfileVersion),
                SetResults(src.SetResults)
            {}

            SetObjectsResponse(const rapidjson::Value& obj) : SetObjectsResponse()
            {
                readFromValue(obj);
            }

            ~SetObjectsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif
