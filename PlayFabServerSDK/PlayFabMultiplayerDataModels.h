#ifndef PLAYFAB_MULTIPLAYER_DATA_MODELS_H_
#define PLAYFAB_MULTIPLAYER_DATA_MODELS_H_

#include "PlayFabBaseModel.h"

namespace PlayFab
{
    namespace MultiplayerModels
    {
        struct AssetReference : public PlayFabBaseModel
        {
            std::string FileName;
            std::string MountPath;

            AssetReference() :
                PlayFabBaseModel(),
                FileName(),
                MountPath()
            {}

            AssetReference(const AssetReference& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                MountPath(src.MountPath)
            {}

            AssetReference(const rapidjson::Value& obj) : AssetReference()
            {
                readFromValue(obj);
            }

            ~AssetReference();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AssetReferenceParams : public PlayFabBaseModel
        {
            std::string FileName;
            std::string MountPath;

            AssetReferenceParams() :
                PlayFabBaseModel(),
                FileName(),
                MountPath()
            {}

            AssetReferenceParams(const AssetReferenceParams& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                MountPath(src.MountPath)
            {}

            AssetReferenceParams(const rapidjson::Value& obj) : AssetReferenceParams()
            {
                readFromValue(obj);
            }

            ~AssetReferenceParams();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct AssetSummary : public PlayFabBaseModel
        {
            std::string FileName;
            std::map<std::string, std::string> Metadata;

            AssetSummary() :
                PlayFabBaseModel(),
                FileName(),
                Metadata()
            {}

            AssetSummary(const AssetSummary& src) :
                PlayFabBaseModel(),
                FileName(src.FileName),
                Metadata(src.Metadata)
            {}

            AssetSummary(const rapidjson::Value& obj) : AssetSummary()
            {
                readFromValue(obj);
            }

            ~AssetSummary();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum AzureRegion
        {
            AzureRegionAustraliaEast,
            AzureRegionAustraliaSoutheast,
            AzureRegionBrazilSouth,
            AzureRegionCentralUs,
            AzureRegionEastAsia,
            AzureRegionEastUs,
            AzureRegionEastUs2,
            AzureRegionJapanEast,
            AzureRegionJapanWest,
            AzureRegionNorthCentralUs,
            AzureRegionNorthEurope,
            AzureRegionSouthCentralUs,
            AzureRegionSoutheastAsia,
            AzureRegionWestEurope,
            AzureRegionWestUs,
            AzureRegionChinaEast2,
            AzureRegionChinaNorth2
        };

        void writeAzureRegionEnumJSON(AzureRegion enumVal, PFStringJsonWriter& writer);
        AzureRegion readAzureRegionFromValue(const rapidjson::Value& obj);

        enum AzureVmSize
        {
            AzureVmSizeStandard_D1_v2,
            AzureVmSizeStandard_D2_v2,
            AzureVmSizeStandard_D3_v2,
            AzureVmSizeStandard_D4_v2,
            AzureVmSizeStandard_D5_v2,
            AzureVmSizeStandard_A1_v2,
            AzureVmSizeStandard_A2_v2,
            AzureVmSizeStandard_A4_v2,
            AzureVmSizeStandard_A8_v2,
            AzureVmSizeStandard_F1,
            AzureVmSizeStandard_F2,
            AzureVmSizeStandard_F4,
            AzureVmSizeStandard_F8,
            AzureVmSizeStandard_F16,
            AzureVmSizeStandard_F2s_v2,
            AzureVmSizeStandard_F4s_v2,
            AzureVmSizeStandard_F8s_v2,
            AzureVmSizeStandard_F16s_v2,
            AzureVmSizeStandard_A1,
            AzureVmSizeStandard_A2,
            AzureVmSizeStandard_A3,
            AzureVmSizeStandard_A4
        };

        void writeAzureVmSizeEnumJSON(AzureVmSize enumVal, PFStringJsonWriter& writer);
        AzureVmSize readAzureVmSizeFromValue(const rapidjson::Value& obj);

        struct CurrentServerStats : public PlayFabBaseModel
        {
            Int32 Active;
            Int32 Propping;
            Int32 StandingBy;
            Int32 Total;

            CurrentServerStats() :
                PlayFabBaseModel(),
                Active(0),
                Propping(0),
                StandingBy(0),
                Total(0)
            {}

            CurrentServerStats(const CurrentServerStats& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                Propping(src.Propping),
                StandingBy(src.StandingBy),
                Total(src.Total)
            {}

            CurrentServerStats(const rapidjson::Value& obj) : CurrentServerStats()
            {
                readFromValue(obj);
            }

            ~CurrentServerStats();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BuildRegion : public PlayFabBaseModel
        {
            CurrentServerStats* pfCurrentServerStats;
            Int32 MaxServers;
            Boxed<AzureRegion> Region;
            Int32 StandbyServers;
            std::string Status;

            BuildRegion() :
                PlayFabBaseModel(),
                pfCurrentServerStats(NULL),
                MaxServers(0),
                Region(),
                StandbyServers(0),
                Status()
            {}

            BuildRegion(const BuildRegion& src) :
                PlayFabBaseModel(),
                pfCurrentServerStats(src.pfCurrentServerStats ? new CurrentServerStats(*src.pfCurrentServerStats) : NULL),
                MaxServers(src.MaxServers),
                Region(src.Region),
                StandbyServers(src.StandbyServers),
                Status(src.Status)
            {}

            BuildRegion(const rapidjson::Value& obj) : BuildRegion()
            {
                readFromValue(obj);
            }

            ~BuildRegion();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BuildRegionParams : public PlayFabBaseModel
        {
            Int32 MaxServers;
            AzureRegion Region;
            Int32 StandbyServers;

            BuildRegionParams() :
                PlayFabBaseModel(),
                MaxServers(0),
                Region(),
                StandbyServers(0)
            {}

            BuildRegionParams(const BuildRegionParams& src) :
                PlayFabBaseModel(),
                MaxServers(src.MaxServers),
                Region(src.Region),
                StandbyServers(src.StandbyServers)
            {}

            BuildRegionParams(const rapidjson::Value& obj) : BuildRegionParams()
            {
                readFromValue(obj);
            }

            ~BuildRegionParams();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct BuildSummary : public PlayFabBaseModel
        {
            std::string BuildId;
            std::string BuildName;
            OptionalTime CreationTime;
            std::map<std::string, std::string> Metadata;

            BuildSummary() :
                PlayFabBaseModel(),
                BuildId(),
                BuildName(),
                CreationTime(),
                Metadata()
            {}

            BuildSummary(const BuildSummary& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                CreationTime(src.CreationTime),
                Metadata(src.Metadata)
            {}

            BuildSummary(const rapidjson::Value& obj) : BuildSummary()
            {
                readFromValue(obj);
            }

            ~BuildSummary();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct Certificate : public PlayFabBaseModel
        {
            std::string Base64EncodedValue;
            std::string Name;
            std::string Password;

            Certificate() :
                PlayFabBaseModel(),
                Base64EncodedValue(),
                Name(),
                Password()
            {}

            Certificate(const Certificate& src) :
                PlayFabBaseModel(),
                Base64EncodedValue(src.Base64EncodedValue),
                Name(src.Name),
                Password(src.Password)
            {}

            Certificate(const rapidjson::Value& obj) : Certificate()
            {
                readFromValue(obj);
            }

            ~Certificate();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CertificateSummary : public PlayFabBaseModel
        {
            std::string Name;
            std::string Thumbprint;

            CertificateSummary() :
                PlayFabBaseModel(),
                Name(),
                Thumbprint()
            {}

            CertificateSummary(const CertificateSummary& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Thumbprint(src.Thumbprint)
            {}

            CertificateSummary(const rapidjson::Value& obj) : CertificateSummary()
            {
                readFromValue(obj);
            }

            ~CertificateSummary();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ConnectedPlayer : public PlayFabBaseModel
        {
            std::string PlayerId;

            ConnectedPlayer() :
                PlayFabBaseModel(),
                PlayerId()
            {}

            ConnectedPlayer(const ConnectedPlayer& src) :
                PlayFabBaseModel(),
                PlayerId(src.PlayerId)
            {}

            ConnectedPlayer(const rapidjson::Value& obj) : ConnectedPlayer()
            {
                readFromValue(obj);
            }

            ~ConnectedPlayer();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum ContainerFlavor
        {
            ContainerFlavorManagedWindowsServerCore,
            ContainerFlavorCustomLinux,
            ContainerFlavorManagedWindowsServerCorePreview
        };

        void writeContainerFlavorEnumJSON(ContainerFlavor enumVal, PFStringJsonWriter& writer);
        ContainerFlavor readContainerFlavorFromValue(const rapidjson::Value& obj);

        struct ContainerImageReference : public PlayFabBaseModel
        {
            std::string ImageName;
            std::string Tag;

            ContainerImageReference() :
                PlayFabBaseModel(),
                ImageName(),
                Tag()
            {}

            ContainerImageReference(const ContainerImageReference& src) :
                PlayFabBaseModel(),
                ImageName(src.ImageName),
                Tag(src.Tag)
            {}

            ContainerImageReference(const rapidjson::Value& obj) : ContainerImageReference()
            {
                readFromValue(obj);
            }

            ~ContainerImageReference();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GameCertificateReferenceParams : public PlayFabBaseModel
        {
            std::string GsdkAlias;
            std::string Name;

            GameCertificateReferenceParams() :
                PlayFabBaseModel(),
                GsdkAlias(),
                Name()
            {}

            GameCertificateReferenceParams(const GameCertificateReferenceParams& src) :
                PlayFabBaseModel(),
                GsdkAlias(src.GsdkAlias),
                Name(src.Name)
            {}

            GameCertificateReferenceParams(const rapidjson::Value& obj) : GameCertificateReferenceParams()
            {
                readFromValue(obj);
            }

            ~GameCertificateReferenceParams();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum ProtocolType
        {
            ProtocolTypeTCP,
            ProtocolTypeUDP
        };

        void writeProtocolTypeEnumJSON(ProtocolType enumVal, PFStringJsonWriter& writer);
        ProtocolType readProtocolTypeFromValue(const rapidjson::Value& obj);

        struct Port : public PlayFabBaseModel
        {
            std::string Name;
            Int32 Num;
            ProtocolType Protocol;

            Port() :
                PlayFabBaseModel(),
                Name(),
                Num(0),
                Protocol()
            {}

            Port(const Port& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Num(src.Num),
                Protocol(src.Protocol)
            {}

            Port(const rapidjson::Value& obj) : Port()
            {
                readFromValue(obj);
            }

            ~Port();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateBuildWithCustomContainerRequest : public PlayFabBaseModel
        {
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::string ContainerRepositoryName;
            std::string ContainerRunCommand;
            std::string ContainerTag;
            std::list<AssetReferenceParams> GameAssetReferences;
            std::list<GameCertificateReferenceParams> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegionParams> RegionConfigurations;
            Boxed<AzureVmSize> VmSize;

            CreateBuildWithCustomContainerRequest() :
                PlayFabBaseModel(),
                BuildName(),
                pfContainerFlavor(),
                ContainerRepositoryName(),
                ContainerRunCommand(),
                ContainerTag(),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(0),
                Ports(),
                RegionConfigurations(),
                VmSize()
            {}

            CreateBuildWithCustomContainerRequest(const CreateBuildWithCustomContainerRequest& src) :
                PlayFabBaseModel(),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                ContainerRepositoryName(src.ContainerRepositoryName),
                ContainerRunCommand(src.ContainerRunCommand),
                ContainerTag(src.ContainerTag),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                VmSize(src.VmSize)
            {}

            CreateBuildWithCustomContainerRequest(const rapidjson::Value& obj) : CreateBuildWithCustomContainerRequest()
            {
                readFromValue(obj);
            }

            ~CreateBuildWithCustomContainerRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GameCertificateReference : public PlayFabBaseModel
        {
            std::string GsdkAlias;
            std::string Name;

            GameCertificateReference() :
                PlayFabBaseModel(),
                GsdkAlias(),
                Name()
            {}

            GameCertificateReference(const GameCertificateReference& src) :
                PlayFabBaseModel(),
                GsdkAlias(src.GsdkAlias),
                Name(src.Name)
            {}

            GameCertificateReference(const rapidjson::Value& obj) : GameCertificateReference()
            {
                readFromValue(obj);
            }

            ~GameCertificateReference();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateBuildWithCustomContainerResponse : public PlayFabBaseModel
        {
            std::string BuildId;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::string ContainerRunCommand;
            OptionalTime CreationTime;
            ContainerImageReference* CustomGameContainerImage;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            Boxed<AzureVmSize> VmSize;

            CreateBuildWithCustomContainerResponse() :
                PlayFabBaseModel(),
                BuildId(),
                BuildName(),
                pfContainerFlavor(),
                ContainerRunCommand(),
                CreationTime(),
                CustomGameContainerImage(NULL),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(0),
                Ports(),
                RegionConfigurations(),
                VmSize()
            {}

            CreateBuildWithCustomContainerResponse(const CreateBuildWithCustomContainerResponse& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                ContainerRunCommand(src.ContainerRunCommand),
                CreationTime(src.CreationTime),
                CustomGameContainerImage(src.CustomGameContainerImage ? new ContainerImageReference(*src.CustomGameContainerImage) : NULL),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                VmSize(src.VmSize)
            {}

            CreateBuildWithCustomContainerResponse(const rapidjson::Value& obj) : CreateBuildWithCustomContainerResponse()
            {
                readFromValue(obj);
            }

            ~CreateBuildWithCustomContainerResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateBuildWithManagedContainerRequest : public PlayFabBaseModel
        {
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::list<AssetReferenceParams> GameAssetReferences;
            std::list<GameCertificateReferenceParams> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegionParams> RegionConfigurations;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;

            CreateBuildWithManagedContainerRequest() :
                PlayFabBaseModel(),
                BuildName(),
                pfContainerFlavor(),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(0),
                Ports(),
                RegionConfigurations(),
                StartMultiplayerServerCommand(),
                VmSize()
            {}

            CreateBuildWithManagedContainerRequest(const CreateBuildWithManagedContainerRequest& src) :
                PlayFabBaseModel(),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            CreateBuildWithManagedContainerRequest(const rapidjson::Value& obj) : CreateBuildWithManagedContainerRequest()
            {
                readFromValue(obj);
            }

            ~CreateBuildWithManagedContainerRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateBuildWithManagedContainerResponse : public PlayFabBaseModel
        {
            std::string BuildId;
            std::string BuildName;
            Boxed<ContainerFlavor> pfContainerFlavor;
            OptionalTime CreationTime;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;

            CreateBuildWithManagedContainerResponse() :
                PlayFabBaseModel(),
                BuildId(),
                BuildName(),
                pfContainerFlavor(),
                CreationTime(),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(0),
                Ports(),
                RegionConfigurations(),
                StartMultiplayerServerCommand(),
                VmSize()
            {}

            CreateBuildWithManagedContainerResponse(const CreateBuildWithManagedContainerResponse& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                pfContainerFlavor(src.pfContainerFlavor),
                CreationTime(src.CreationTime),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            CreateBuildWithManagedContainerResponse(const rapidjson::Value& obj) : CreateBuildWithManagedContainerResponse()
            {
                readFromValue(obj);
            }

            ~CreateBuildWithManagedContainerResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateRemoteUserRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            OptionalTime ExpirationTime;
            AzureRegion Region;
            std::string Username;
            std::string VmId;

            CreateRemoteUserRequest() :
                PlayFabBaseModel(),
                BuildId(),
                ExpirationTime(),
                Region(),
                Username(),
                VmId()
            {}

            CreateRemoteUserRequest(const CreateRemoteUserRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ExpirationTime(src.ExpirationTime),
                Region(src.Region),
                Username(src.Username),
                VmId(src.VmId)
            {}

            CreateRemoteUserRequest(const rapidjson::Value& obj) : CreateRemoteUserRequest()
            {
                readFromValue(obj);
            }

            ~CreateRemoteUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct CreateRemoteUserResponse : public PlayFabBaseModel
        {
            OptionalTime ExpirationTime;
            std::string Password;
            std::string Username;

            CreateRemoteUserResponse() :
                PlayFabBaseModel(),
                ExpirationTime(),
                Password(),
                Username()
            {}

            CreateRemoteUserResponse(const CreateRemoteUserResponse& src) :
                PlayFabBaseModel(),
                ExpirationTime(src.ExpirationTime),
                Password(src.Password),
                Username(src.Username)
            {}

            CreateRemoteUserResponse(const rapidjson::Value& obj) : CreateRemoteUserResponse()
            {
                readFromValue(obj);
            }

            ~CreateRemoteUserResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteAssetRequest : public PlayFabBaseModel
        {
            std::string FileName;

            DeleteAssetRequest() :
                PlayFabBaseModel(),
                FileName()
            {}

            DeleteAssetRequest(const DeleteAssetRequest& src) :
                PlayFabBaseModel(),
                FileName(src.FileName)
            {}

            DeleteAssetRequest(const rapidjson::Value& obj) : DeleteAssetRequest()
            {
                readFromValue(obj);
            }

            ~DeleteAssetRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteBuildRequest : public PlayFabBaseModel
        {
            std::string BuildId;

            DeleteBuildRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            DeleteBuildRequest(const DeleteBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            DeleteBuildRequest(const rapidjson::Value& obj) : DeleteBuildRequest()
            {
                readFromValue(obj);
            }

            ~DeleteBuildRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteCertificateRequest : public PlayFabBaseModel
        {
            std::string Name;

            DeleteCertificateRequest() :
                PlayFabBaseModel(),
                Name()
            {}

            DeleteCertificateRequest(const DeleteCertificateRequest& src) :
                PlayFabBaseModel(),
                Name(src.Name)
            {}

            DeleteCertificateRequest(const rapidjson::Value& obj) : DeleteCertificateRequest()
            {
                readFromValue(obj);
            }

            ~DeleteCertificateRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct DeleteRemoteUserRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            AzureRegion Region;
            std::string Username;
            std::string VmId;

            DeleteRemoteUserRequest() :
                PlayFabBaseModel(),
                BuildId(),
                Region(),
                Username(),
                VmId()
            {}

            DeleteRemoteUserRequest(const DeleteRemoteUserRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                Region(src.Region),
                Username(src.Username),
                VmId(src.VmId)
            {}

            DeleteRemoteUserRequest(const rapidjson::Value& obj) : DeleteRemoteUserRequest()
            {
                readFromValue(obj);
            }

            ~DeleteRemoteUserRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EmptyResponse : public PlayFabBaseModel
        {

            EmptyResponse() :
                PlayFabBaseModel()
            {}

            EmptyResponse(const EmptyResponse& src) :
                PlayFabBaseModel()
            {}

            EmptyResponse(const rapidjson::Value& obj) : EmptyResponse()
            {
                readFromValue(obj);
            }

            ~EmptyResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct EnableMultiplayerServersForTitleRequest : public PlayFabBaseModel
        {

            EnableMultiplayerServersForTitleRequest() :
                PlayFabBaseModel()
            {}

            EnableMultiplayerServersForTitleRequest(const EnableMultiplayerServersForTitleRequest& src) :
                PlayFabBaseModel()
            {}

            EnableMultiplayerServersForTitleRequest(const rapidjson::Value& obj) : EnableMultiplayerServersForTitleRequest()
            {
                readFromValue(obj);
            }

            ~EnableMultiplayerServersForTitleRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        enum TitleMultiplayerServerEnabledStatus
        {
            TitleMultiplayerServerEnabledStatusInitializing,
            TitleMultiplayerServerEnabledStatusEnabled,
            TitleMultiplayerServerEnabledStatusDisabled
        };

        void writeTitleMultiplayerServerEnabledStatusEnumJSON(TitleMultiplayerServerEnabledStatus enumVal, PFStringJsonWriter& writer);
        TitleMultiplayerServerEnabledStatus readTitleMultiplayerServerEnabledStatusFromValue(const rapidjson::Value& obj);

        struct EnableMultiplayerServersForTitleResponse : public PlayFabBaseModel
        {
            Boxed<TitleMultiplayerServerEnabledStatus> Status;

            EnableMultiplayerServersForTitleResponse() :
                PlayFabBaseModel(),
                Status()
            {}

            EnableMultiplayerServersForTitleResponse(const EnableMultiplayerServersForTitleResponse& src) :
                PlayFabBaseModel(),
                Status(src.Status)
            {}

            EnableMultiplayerServersForTitleResponse(const rapidjson::Value& obj) : EnableMultiplayerServersForTitleResponse()
            {
                readFromValue(obj);
            }

            ~EnableMultiplayerServersForTitleResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAssetUploadUrlRequest : public PlayFabBaseModel
        {
            std::string FileName;

            GetAssetUploadUrlRequest() :
                PlayFabBaseModel(),
                FileName()
            {}

            GetAssetUploadUrlRequest(const GetAssetUploadUrlRequest& src) :
                PlayFabBaseModel(),
                FileName(src.FileName)
            {}

            GetAssetUploadUrlRequest(const rapidjson::Value& obj) : GetAssetUploadUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetAssetUploadUrlRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetAssetUploadUrlResponse : public PlayFabBaseModel
        {
            std::string AssetUploadUrl;
            std::string FileName;

            GetAssetUploadUrlResponse() :
                PlayFabBaseModel(),
                AssetUploadUrl(),
                FileName()
            {}

            GetAssetUploadUrlResponse(const GetAssetUploadUrlResponse& src) :
                PlayFabBaseModel(),
                AssetUploadUrl(src.AssetUploadUrl),
                FileName(src.FileName)
            {}

            GetAssetUploadUrlResponse(const rapidjson::Value& obj) : GetAssetUploadUrlResponse()
            {
                readFromValue(obj);
            }

            ~GetAssetUploadUrlResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetBuildRequest : public PlayFabBaseModel
        {
            std::string BuildId;

            GetBuildRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            GetBuildRequest(const GetBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            GetBuildRequest(const rapidjson::Value& obj) : GetBuildRequest()
            {
                readFromValue(obj);
            }

            ~GetBuildRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetBuildResponse : public PlayFabBaseModel
        {
            std::string BuildId;
            std::string BuildName;
            std::string BuildStatus;
            Boxed<ContainerFlavor> pfContainerFlavor;
            std::string ContainerRunCommand;
            OptionalTime CreationTime;
            ContainerImageReference* CustomGameContainerImage;
            std::list<AssetReference> GameAssetReferences;
            std::list<GameCertificateReference> GameCertificateReferences;
            std::map<std::string, std::string> Metadata;
            Int32 MultiplayerServerCountPerVm;
            std::list<Port> Ports;
            std::list<BuildRegion> RegionConfigurations;
            std::string StartMultiplayerServerCommand;
            Boxed<AzureVmSize> VmSize;

            GetBuildResponse() :
                PlayFabBaseModel(),
                BuildId(),
                BuildName(),
                BuildStatus(),
                pfContainerFlavor(),
                ContainerRunCommand(),
                CreationTime(),
                CustomGameContainerImage(NULL),
                GameAssetReferences(),
                GameCertificateReferences(),
                Metadata(),
                MultiplayerServerCountPerVm(0),
                Ports(),
                RegionConfigurations(),
                StartMultiplayerServerCommand(),
                VmSize()
            {}

            GetBuildResponse(const GetBuildResponse& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                BuildName(src.BuildName),
                BuildStatus(src.BuildStatus),
                pfContainerFlavor(src.pfContainerFlavor),
                ContainerRunCommand(src.ContainerRunCommand),
                CreationTime(src.CreationTime),
                CustomGameContainerImage(src.CustomGameContainerImage ? new ContainerImageReference(*src.CustomGameContainerImage) : NULL),
                GameAssetReferences(src.GameAssetReferences),
                GameCertificateReferences(src.GameCertificateReferences),
                Metadata(src.Metadata),
                MultiplayerServerCountPerVm(src.MultiplayerServerCountPerVm),
                Ports(src.Ports),
                RegionConfigurations(src.RegionConfigurations),
                StartMultiplayerServerCommand(src.StartMultiplayerServerCommand),
                VmSize(src.VmSize)
            {}

            GetBuildResponse(const rapidjson::Value& obj) : GetBuildResponse()
            {
                readFromValue(obj);
            }

            ~GetBuildResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContainerRegistryCredentialsRequest : public PlayFabBaseModel
        {

            GetContainerRegistryCredentialsRequest() :
                PlayFabBaseModel()
            {}

            GetContainerRegistryCredentialsRequest(const GetContainerRegistryCredentialsRequest& src) :
                PlayFabBaseModel()
            {}

            GetContainerRegistryCredentialsRequest(const rapidjson::Value& obj) : GetContainerRegistryCredentialsRequest()
            {
                readFromValue(obj);
            }

            ~GetContainerRegistryCredentialsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetContainerRegistryCredentialsResponse : public PlayFabBaseModel
        {
            std::string DnsName;
            std::string Password;
            std::string Username;

            GetContainerRegistryCredentialsResponse() :
                PlayFabBaseModel(),
                DnsName(),
                Password(),
                Username()
            {}

            GetContainerRegistryCredentialsResponse(const GetContainerRegistryCredentialsResponse& src) :
                PlayFabBaseModel(),
                DnsName(src.DnsName),
                Password(src.Password),
                Username(src.Username)
            {}

            GetContainerRegistryCredentialsResponse(const rapidjson::Value& obj) : GetContainerRegistryCredentialsResponse()
            {
                readFromValue(obj);
            }

            ~GetContainerRegistryCredentialsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetMultiplayerServerDetailsRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            AzureRegion Region;
            std::string SessionId;

            GetMultiplayerServerDetailsRequest() :
                PlayFabBaseModel(),
                BuildId(),
                Region(),
                SessionId()
            {}

            GetMultiplayerServerDetailsRequest(const GetMultiplayerServerDetailsRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                Region(src.Region),
                SessionId(src.SessionId)
            {}

            GetMultiplayerServerDetailsRequest(const rapidjson::Value& obj) : GetMultiplayerServerDetailsRequest()
            {
                readFromValue(obj);
            }

            ~GetMultiplayerServerDetailsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetMultiplayerServerDetailsResponse : public PlayFabBaseModel
        {
            std::list<ConnectedPlayer> ConnectedPlayers;
            std::string FQDN;
            std::string IPV4Address;
            OptionalTime LastStateTransitionTime;
            std::list<Port> Ports;
            Boxed<AzureRegion> Region;
            std::string ServerId;
            std::string SessionId;
            std::string State;
            std::string VmId;

            GetMultiplayerServerDetailsResponse() :
                PlayFabBaseModel(),
                ConnectedPlayers(),
                FQDN(),
                IPV4Address(),
                LastStateTransitionTime(),
                Ports(),
                Region(),
                ServerId(),
                SessionId(),
                State(),
                VmId()
            {}

            GetMultiplayerServerDetailsResponse(const GetMultiplayerServerDetailsResponse& src) :
                PlayFabBaseModel(),
                ConnectedPlayers(src.ConnectedPlayers),
                FQDN(src.FQDN),
                IPV4Address(src.IPV4Address),
                LastStateTransitionTime(src.LastStateTransitionTime),
                Ports(src.Ports),
                Region(src.Region),
                ServerId(src.ServerId),
                SessionId(src.SessionId),
                State(src.State),
                VmId(src.VmId)
            {}

            GetMultiplayerServerDetailsResponse(const rapidjson::Value& obj) : GetMultiplayerServerDetailsResponse()
            {
                readFromValue(obj);
            }

            ~GetMultiplayerServerDetailsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetRemoteLoginEndpointRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            AzureRegion Region;
            std::string VmId;

            GetRemoteLoginEndpointRequest() :
                PlayFabBaseModel(),
                BuildId(),
                Region(),
                VmId()
            {}

            GetRemoteLoginEndpointRequest(const GetRemoteLoginEndpointRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                Region(src.Region),
                VmId(src.VmId)
            {}

            GetRemoteLoginEndpointRequest(const rapidjson::Value& obj) : GetRemoteLoginEndpointRequest()
            {
                readFromValue(obj);
            }

            ~GetRemoteLoginEndpointRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetRemoteLoginEndpointResponse : public PlayFabBaseModel
        {
            std::string IPV4Address;
            Int32 Port;

            GetRemoteLoginEndpointResponse() :
                PlayFabBaseModel(),
                IPV4Address(),
                Port(0)
            {}

            GetRemoteLoginEndpointResponse(const GetRemoteLoginEndpointResponse& src) :
                PlayFabBaseModel(),
                IPV4Address(src.IPV4Address),
                Port(src.Port)
            {}

            GetRemoteLoginEndpointResponse(const rapidjson::Value& obj) : GetRemoteLoginEndpointResponse()
            {
                readFromValue(obj);
            }

            ~GetRemoteLoginEndpointResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitleEnabledForMultiplayerServersStatusRequest : public PlayFabBaseModel
        {

            GetTitleEnabledForMultiplayerServersStatusRequest() :
                PlayFabBaseModel()
            {}

            GetTitleEnabledForMultiplayerServersStatusRequest(const GetTitleEnabledForMultiplayerServersStatusRequest& src) :
                PlayFabBaseModel()
            {}

            GetTitleEnabledForMultiplayerServersStatusRequest(const rapidjson::Value& obj) : GetTitleEnabledForMultiplayerServersStatusRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleEnabledForMultiplayerServersStatusRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct GetTitleEnabledForMultiplayerServersStatusResponse : public PlayFabBaseModel
        {
            Boxed<TitleMultiplayerServerEnabledStatus> Status;

            GetTitleEnabledForMultiplayerServersStatusResponse() :
                PlayFabBaseModel(),
                Status()
            {}

            GetTitleEnabledForMultiplayerServersStatusResponse(const GetTitleEnabledForMultiplayerServersStatusResponse& src) :
                PlayFabBaseModel(),
                Status(src.Status)
            {}

            GetTitleEnabledForMultiplayerServersStatusResponse(const rapidjson::Value& obj) : GetTitleEnabledForMultiplayerServersStatusResponse()
            {
                readFromValue(obj);
            }

            ~GetTitleEnabledForMultiplayerServersStatusResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListAssetSummariesRequest : public PlayFabBaseModel
        {
            OptionalInt32 PageSize;
            std::string SkipToken;

            ListAssetSummariesRequest() :
                PlayFabBaseModel(),
                PageSize(),
                SkipToken()
            {}

            ListAssetSummariesRequest(const ListAssetSummariesRequest& src) :
                PlayFabBaseModel(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListAssetSummariesRequest(const rapidjson::Value& obj) : ListAssetSummariesRequest()
            {
                readFromValue(obj);
            }

            ~ListAssetSummariesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListAssetSummariesResponse : public PlayFabBaseModel
        {
            std::list<AssetSummary> AssetSummaries;
            Int32 PageSize;
            std::string SkipToken;

            ListAssetSummariesResponse() :
                PlayFabBaseModel(),
                AssetSummaries(),
                PageSize(0),
                SkipToken()
            {}

            ListAssetSummariesResponse(const ListAssetSummariesResponse& src) :
                PlayFabBaseModel(),
                AssetSummaries(src.AssetSummaries),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListAssetSummariesResponse(const rapidjson::Value& obj) : ListAssetSummariesResponse()
            {
                readFromValue(obj);
            }

            ~ListAssetSummariesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListBuildSummariesRequest : public PlayFabBaseModel
        {
            OptionalInt32 PageSize;
            std::string SkipToken;

            ListBuildSummariesRequest() :
                PlayFabBaseModel(),
                PageSize(),
                SkipToken()
            {}

            ListBuildSummariesRequest(const ListBuildSummariesRequest& src) :
                PlayFabBaseModel(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListBuildSummariesRequest(const rapidjson::Value& obj) : ListBuildSummariesRequest()
            {
                readFromValue(obj);
            }

            ~ListBuildSummariesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListBuildSummariesResponse : public PlayFabBaseModel
        {
            std::list<BuildSummary> BuildSummaries;
            Int32 PageSize;
            std::string SkipToken;

            ListBuildSummariesResponse() :
                PlayFabBaseModel(),
                BuildSummaries(),
                PageSize(0),
                SkipToken()
            {}

            ListBuildSummariesResponse(const ListBuildSummariesResponse& src) :
                PlayFabBaseModel(),
                BuildSummaries(src.BuildSummaries),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListBuildSummariesResponse(const rapidjson::Value& obj) : ListBuildSummariesResponse()
            {
                readFromValue(obj);
            }

            ~ListBuildSummariesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListCertificateSummariesRequest : public PlayFabBaseModel
        {
            OptionalInt32 PageSize;
            std::string SkipToken;

            ListCertificateSummariesRequest() :
                PlayFabBaseModel(),
                PageSize(),
                SkipToken()
            {}

            ListCertificateSummariesRequest(const ListCertificateSummariesRequest& src) :
                PlayFabBaseModel(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListCertificateSummariesRequest(const rapidjson::Value& obj) : ListCertificateSummariesRequest()
            {
                readFromValue(obj);
            }

            ~ListCertificateSummariesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListCertificateSummariesResponse : public PlayFabBaseModel
        {
            std::list<CertificateSummary> CertificateSummaries;
            Int32 PageSize;
            std::string SkipToken;

            ListCertificateSummariesResponse() :
                PlayFabBaseModel(),
                CertificateSummaries(),
                PageSize(0),
                SkipToken()
            {}

            ListCertificateSummariesResponse(const ListCertificateSummariesResponse& src) :
                PlayFabBaseModel(),
                CertificateSummaries(src.CertificateSummaries),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListCertificateSummariesResponse(const rapidjson::Value& obj) : ListCertificateSummariesResponse()
            {
                readFromValue(obj);
            }

            ~ListCertificateSummariesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListContainerImagesRequest : public PlayFabBaseModel
        {
            OptionalInt32 PageSize;
            std::string SkipToken;

            ListContainerImagesRequest() :
                PlayFabBaseModel(),
                PageSize(),
                SkipToken()
            {}

            ListContainerImagesRequest(const ListContainerImagesRequest& src) :
                PlayFabBaseModel(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListContainerImagesRequest(const rapidjson::Value& obj) : ListContainerImagesRequest()
            {
                readFromValue(obj);
            }

            ~ListContainerImagesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListContainerImagesResponse : public PlayFabBaseModel
        {
            std::list<std::string> Images;
            Int32 PageSize;
            std::string SkipToken;

            ListContainerImagesResponse() :
                PlayFabBaseModel(),
                Images(),
                PageSize(0),
                SkipToken()
            {}

            ListContainerImagesResponse(const ListContainerImagesResponse& src) :
                PlayFabBaseModel(),
                Images(src.Images),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListContainerImagesResponse(const rapidjson::Value& obj) : ListContainerImagesResponse()
            {
                readFromValue(obj);
            }

            ~ListContainerImagesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListContainerImageTagsRequest : public PlayFabBaseModel
        {
            std::string ImageName;

            ListContainerImageTagsRequest() :
                PlayFabBaseModel(),
                ImageName()
            {}

            ListContainerImageTagsRequest(const ListContainerImageTagsRequest& src) :
                PlayFabBaseModel(),
                ImageName(src.ImageName)
            {}

            ListContainerImageTagsRequest(const rapidjson::Value& obj) : ListContainerImageTagsRequest()
            {
                readFromValue(obj);
            }

            ~ListContainerImageTagsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListContainerImageTagsResponse : public PlayFabBaseModel
        {
            std::list<std::string> Tags;

            ListContainerImageTagsResponse() :
                PlayFabBaseModel(),
                Tags()
            {}

            ListContainerImageTagsResponse(const ListContainerImageTagsResponse& src) :
                PlayFabBaseModel(),
                Tags(src.Tags)
            {}

            ListContainerImageTagsResponse(const rapidjson::Value& obj) : ListContainerImageTagsResponse()
            {
                readFromValue(obj);
            }

            ~ListContainerImageTagsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListMultiplayerServersRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            OptionalInt32 PageSize;
            AzureRegion Region;
            std::string SkipToken;

            ListMultiplayerServersRequest() :
                PlayFabBaseModel(),
                BuildId(),
                PageSize(),
                Region(),
                SkipToken()
            {}

            ListMultiplayerServersRequest(const ListMultiplayerServersRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                PageSize(src.PageSize),
                Region(src.Region),
                SkipToken(src.SkipToken)
            {}

            ListMultiplayerServersRequest(const rapidjson::Value& obj) : ListMultiplayerServersRequest()
            {
                readFromValue(obj);
            }

            ~ListMultiplayerServersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct MultiplayerServerSummary : public PlayFabBaseModel
        {
            std::list<ConnectedPlayer> ConnectedPlayers;
            OptionalTime LastStateTransitionTime;
            Boxed<AzureRegion> Region;
            std::string ServerId;
            std::string SessionId;
            std::string State;
            std::string VmId;

            MultiplayerServerSummary() :
                PlayFabBaseModel(),
                ConnectedPlayers(),
                LastStateTransitionTime(),
                Region(),
                ServerId(),
                SessionId(),
                State(),
                VmId()
            {}

            MultiplayerServerSummary(const MultiplayerServerSummary& src) :
                PlayFabBaseModel(),
                ConnectedPlayers(src.ConnectedPlayers),
                LastStateTransitionTime(src.LastStateTransitionTime),
                Region(src.Region),
                ServerId(src.ServerId),
                SessionId(src.SessionId),
                State(src.State),
                VmId(src.VmId)
            {}

            MultiplayerServerSummary(const rapidjson::Value& obj) : MultiplayerServerSummary()
            {
                readFromValue(obj);
            }

            ~MultiplayerServerSummary();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListMultiplayerServersResponse : public PlayFabBaseModel
        {
            std::list<MultiplayerServerSummary> MultiplayerServerSummaries;
            Int32 PageSize;
            std::string SkipToken;

            ListMultiplayerServersResponse() :
                PlayFabBaseModel(),
                MultiplayerServerSummaries(),
                PageSize(0),
                SkipToken()
            {}

            ListMultiplayerServersResponse(const ListMultiplayerServersResponse& src) :
                PlayFabBaseModel(),
                MultiplayerServerSummaries(src.MultiplayerServerSummaries),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken)
            {}

            ListMultiplayerServersResponse(const rapidjson::Value& obj) : ListMultiplayerServersResponse()
            {
                readFromValue(obj);
            }

            ~ListMultiplayerServersResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListQosServersRequest : public PlayFabBaseModel
        {

            ListQosServersRequest() :
                PlayFabBaseModel()
            {}

            ListQosServersRequest(const ListQosServersRequest& src) :
                PlayFabBaseModel()
            {}

            ListQosServersRequest(const rapidjson::Value& obj) : ListQosServersRequest()
            {
                readFromValue(obj);
            }

            ~ListQosServersRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct QosServer : public PlayFabBaseModel
        {
            Boxed<AzureRegion> Region;
            std::string ServerUrl;

            QosServer() :
                PlayFabBaseModel(),
                Region(),
                ServerUrl()
            {}

            QosServer(const QosServer& src) :
                PlayFabBaseModel(),
                Region(src.Region),
                ServerUrl(src.ServerUrl)
            {}

            QosServer(const rapidjson::Value& obj) : QosServer()
            {
                readFromValue(obj);
            }

            ~QosServer();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListQosServersResponse : public PlayFabBaseModel
        {
            Int32 PageSize;
            std::list<QosServer> QosServers;
            std::string SkipToken;

            ListQosServersResponse() :
                PlayFabBaseModel(),
                PageSize(0),
                QosServers(),
                SkipToken()
            {}

            ListQosServersResponse(const ListQosServersResponse& src) :
                PlayFabBaseModel(),
                PageSize(src.PageSize),
                QosServers(src.QosServers),
                SkipToken(src.SkipToken)
            {}

            ListQosServersResponse(const rapidjson::Value& obj) : ListQosServersResponse()
            {
                readFromValue(obj);
            }

            ~ListQosServersResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListVirtualMachineSummariesRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            OptionalInt32 PageSize;
            AzureRegion Region;
            std::string SkipToken;

            ListVirtualMachineSummariesRequest() :
                PlayFabBaseModel(),
                BuildId(),
                PageSize(),
                Region(),
                SkipToken()
            {}

            ListVirtualMachineSummariesRequest(const ListVirtualMachineSummariesRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                PageSize(src.PageSize),
                Region(src.Region),
                SkipToken(src.SkipToken)
            {}

            ListVirtualMachineSummariesRequest(const rapidjson::Value& obj) : ListVirtualMachineSummariesRequest()
            {
                readFromValue(obj);
            }

            ~ListVirtualMachineSummariesRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct VirtualMachineSummary : public PlayFabBaseModel
        {
            std::string HealthStatus;
            std::string State;
            std::string VmId;

            VirtualMachineSummary() :
                PlayFabBaseModel(),
                HealthStatus(),
                State(),
                VmId()
            {}

            VirtualMachineSummary(const VirtualMachineSummary& src) :
                PlayFabBaseModel(),
                HealthStatus(src.HealthStatus),
                State(src.State),
                VmId(src.VmId)
            {}

            VirtualMachineSummary(const rapidjson::Value& obj) : VirtualMachineSummary()
            {
                readFromValue(obj);
            }

            ~VirtualMachineSummary();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ListVirtualMachineSummariesResponse : public PlayFabBaseModel
        {
            Int32 PageSize;
            std::string SkipToken;
            std::list<VirtualMachineSummary> VirtualMachines;

            ListVirtualMachineSummariesResponse() :
                PlayFabBaseModel(),
                PageSize(0),
                SkipToken(),
                VirtualMachines()
            {}

            ListVirtualMachineSummariesResponse(const ListVirtualMachineSummariesResponse& src) :
                PlayFabBaseModel(),
                PageSize(src.PageSize),
                SkipToken(src.SkipToken),
                VirtualMachines(src.VirtualMachines)
            {}

            ListVirtualMachineSummariesResponse(const rapidjson::Value& obj) : ListVirtualMachineSummariesResponse()
            {
                readFromValue(obj);
            }

            ~ListVirtualMachineSummariesResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RequestMultiplayerServerRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            std::list<std::string> InitialPlayers;
            std::list<AzureRegion> PreferredRegions;
            std::string SessionCookie;
            std::string SessionId;

            RequestMultiplayerServerRequest() :
                PlayFabBaseModel(),
                BuildId(),
                InitialPlayers(),
                PreferredRegions(),
                SessionCookie(),
                SessionId()
            {}

            RequestMultiplayerServerRequest(const RequestMultiplayerServerRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                InitialPlayers(src.InitialPlayers),
                PreferredRegions(src.PreferredRegions),
                SessionCookie(src.SessionCookie),
                SessionId(src.SessionId)
            {}

            RequestMultiplayerServerRequest(const rapidjson::Value& obj) : RequestMultiplayerServerRequest()
            {
                readFromValue(obj);
            }

            ~RequestMultiplayerServerRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RequestMultiplayerServerResponse : public PlayFabBaseModel
        {
            std::list<ConnectedPlayer> ConnectedPlayers;
            std::string FQDN;
            std::string IPV4Address;
            OptionalTime LastStateTransitionTime;
            std::list<Port> Ports;
            Boxed<AzureRegion> Region;
            std::string ServerId;
            std::string SessionId;
            std::string State;
            std::string VmId;

            RequestMultiplayerServerResponse() :
                PlayFabBaseModel(),
                ConnectedPlayers(),
                FQDN(),
                IPV4Address(),
                LastStateTransitionTime(),
                Ports(),
                Region(),
                ServerId(),
                SessionId(),
                State(),
                VmId()
            {}

            RequestMultiplayerServerResponse(const RequestMultiplayerServerResponse& src) :
                PlayFabBaseModel(),
                ConnectedPlayers(src.ConnectedPlayers),
                FQDN(src.FQDN),
                IPV4Address(src.IPV4Address),
                LastStateTransitionTime(src.LastStateTransitionTime),
                Ports(src.Ports),
                Region(src.Region),
                ServerId(src.ServerId),
                SessionId(src.SessionId),
                State(src.State),
                VmId(src.VmId)
            {}

            RequestMultiplayerServerResponse(const rapidjson::Value& obj) : RequestMultiplayerServerResponse()
            {
                readFromValue(obj);
            }

            ~RequestMultiplayerServerResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RolloverContainerRegistryCredentialsRequest : public PlayFabBaseModel
        {

            RolloverContainerRegistryCredentialsRequest() :
                PlayFabBaseModel()
            {}

            RolloverContainerRegistryCredentialsRequest(const RolloverContainerRegistryCredentialsRequest& src) :
                PlayFabBaseModel()
            {}

            RolloverContainerRegistryCredentialsRequest(const rapidjson::Value& obj) : RolloverContainerRegistryCredentialsRequest()
            {
                readFromValue(obj);
            }

            ~RolloverContainerRegistryCredentialsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct RolloverContainerRegistryCredentialsResponse : public PlayFabBaseModel
        {
            std::string DnsName;
            std::string Password;
            std::string Username;

            RolloverContainerRegistryCredentialsResponse() :
                PlayFabBaseModel(),
                DnsName(),
                Password(),
                Username()
            {}

            RolloverContainerRegistryCredentialsResponse(const RolloverContainerRegistryCredentialsResponse& src) :
                PlayFabBaseModel(),
                DnsName(src.DnsName),
                Password(src.Password),
                Username(src.Username)
            {}

            RolloverContainerRegistryCredentialsResponse(const rapidjson::Value& obj) : RolloverContainerRegistryCredentialsResponse()
            {
                readFromValue(obj);
            }

            ~RolloverContainerRegistryCredentialsResponse();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct ShutdownMultiplayerServerRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            AzureRegion Region;
            std::string SessionId;

            ShutdownMultiplayerServerRequest() :
                PlayFabBaseModel(),
                BuildId(),
                Region(),
                SessionId()
            {}

            ShutdownMultiplayerServerRequest(const ShutdownMultiplayerServerRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                Region(src.Region),
                SessionId(src.SessionId)
            {}

            ShutdownMultiplayerServerRequest(const rapidjson::Value& obj) : ShutdownMultiplayerServerRequest()
            {
                readFromValue(obj);
            }

            ~ShutdownMultiplayerServerRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UpdateBuildRegionsRequest : public PlayFabBaseModel
        {
            std::string BuildId;
            std::list<BuildRegionParams> BuildRegions;

            UpdateBuildRegionsRequest() :
                PlayFabBaseModel(),
                BuildId(),
                BuildRegions()
            {}

            UpdateBuildRegionsRequest(const UpdateBuildRegionsRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                BuildRegions(src.BuildRegions)
            {}

            UpdateBuildRegionsRequest(const rapidjson::Value& obj) : UpdateBuildRegionsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBuildRegionsRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };

        struct UploadCertificateRequest : public PlayFabBaseModel
        {
            Certificate GameCertificate;

            UploadCertificateRequest() :
                PlayFabBaseModel(),
                GameCertificate()
            {}

            UploadCertificateRequest(const UploadCertificateRequest& src) :
                PlayFabBaseModel(),
                GameCertificate(src.GameCertificate)
            {}

            UploadCertificateRequest(const rapidjson::Value& obj) : UploadCertificateRequest()
            {
                readFromValue(obj);
            }

            ~UploadCertificateRequest();

            void writeJSON(PFStringJsonWriter& writer);
            bool readFromValue(const rapidjson::Value& obj);
        };


    }
}

#endif