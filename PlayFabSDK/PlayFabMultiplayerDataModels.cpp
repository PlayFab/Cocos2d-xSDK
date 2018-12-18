#include "PlayFabMultiplayerDataModels.h"

using namespace PlayFab;
using namespace PlayFab::MultiplayerModels;
using namespace rapidjson;


AssetReference::~AssetReference()
{

}

void AssetReference::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (FileName.length() > 0) { writer.String("FileName"); writer.String(FileName.c_str()); }
    if (MountPath.length() > 0) { writer.String("MountPath"); writer.String(MountPath.c_str()); }
    writer.EndObject();
}

bool AssetReference::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
    const Value::ConstMemberIterator MountPath_member = obj.FindMember("MountPath");
    if (MountPath_member != obj.MemberEnd() && !MountPath_member->value.IsNull()) MountPath = MountPath_member->value.GetString();

    return true;
}

AssetReferenceParams::~AssetReferenceParams()
{

}

void AssetReferenceParams::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("FileName"); writer.String(FileName.c_str());
    writer.String("MountPath"); writer.String(MountPath.c_str());
    writer.EndObject();
}

bool AssetReferenceParams::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
    const Value::ConstMemberIterator MountPath_member = obj.FindMember("MountPath");
    if (MountPath_member != obj.MemberEnd() && !MountPath_member->value.IsNull()) MountPath = MountPath_member->value.GetString();

    return true;
}

AssetSummary::~AssetSummary()
{

}

void AssetSummary::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (FileName.length() > 0) { writer.String("FileName"); writer.String(FileName.c_str()); }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool AssetSummary::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}
void PlayFab::MultiplayerModels::writeAzureRegionEnumJSON(AzureRegion enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case AzureRegionAustraliaEast: writer.String("AustraliaEast"); break;
    case AzureRegionAustraliaSoutheast: writer.String("AustraliaSoutheast"); break;
    case AzureRegionBrazilSouth: writer.String("BrazilSouth"); break;
    case AzureRegionCentralUs: writer.String("CentralUs"); break;
    case AzureRegionEastAsia: writer.String("EastAsia"); break;
    case AzureRegionEastUs: writer.String("EastUs"); break;
    case AzureRegionEastUs2: writer.String("EastUs2"); break;
    case AzureRegionJapanEast: writer.String("JapanEast"); break;
    case AzureRegionJapanWest: writer.String("JapanWest"); break;
    case AzureRegionNorthCentralUs: writer.String("NorthCentralUs"); break;
    case AzureRegionNorthEurope: writer.String("NorthEurope"); break;
    case AzureRegionSouthCentralUs: writer.String("SouthCentralUs"); break;
    case AzureRegionSoutheastAsia: writer.String("SoutheastAsia"); break;
    case AzureRegionWestEurope: writer.String("WestEurope"); break;
    case AzureRegionWestUs: writer.String("WestUs"); break;

    }
}

AzureRegion PlayFab::MultiplayerModels::readAzureRegionFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, AzureRegion> _AzureRegionMap;
    if (_AzureRegionMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _AzureRegionMap["AustraliaEast"] = AzureRegionAustraliaEast;
        _AzureRegionMap["AustraliaSoutheast"] = AzureRegionAustraliaSoutheast;
        _AzureRegionMap["BrazilSouth"] = AzureRegionBrazilSouth;
        _AzureRegionMap["CentralUs"] = AzureRegionCentralUs;
        _AzureRegionMap["EastAsia"] = AzureRegionEastAsia;
        _AzureRegionMap["EastUs"] = AzureRegionEastUs;
        _AzureRegionMap["EastUs2"] = AzureRegionEastUs2;
        _AzureRegionMap["JapanEast"] = AzureRegionJapanEast;
        _AzureRegionMap["JapanWest"] = AzureRegionJapanWest;
        _AzureRegionMap["NorthCentralUs"] = AzureRegionNorthCentralUs;
        _AzureRegionMap["NorthEurope"] = AzureRegionNorthEurope;
        _AzureRegionMap["SouthCentralUs"] = AzureRegionSouthCentralUs;
        _AzureRegionMap["SoutheastAsia"] = AzureRegionSoutheastAsia;
        _AzureRegionMap["WestEurope"] = AzureRegionWestEurope;
        _AzureRegionMap["WestUs"] = AzureRegionWestUs;

    }

    auto output = _AzureRegionMap.find(obj.GetString());
    if (output != _AzureRegionMap.end())
        return output->second;

    return AzureRegionAustraliaEast; // Basically critical fail
}
void PlayFab::MultiplayerModels::writeAzureVmSizeEnumJSON(AzureVmSize enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case AzureVmSizeStandard_D1_v2: writer.String("Standard_D1_v2"); break;
    case AzureVmSizeStandard_D2_v2: writer.String("Standard_D2_v2"); break;
    case AzureVmSizeStandard_D3_v2: writer.String("Standard_D3_v2"); break;
    case AzureVmSizeStandard_D4_v2: writer.String("Standard_D4_v2"); break;
    case AzureVmSizeStandard_D5_v2: writer.String("Standard_D5_v2"); break;
    case AzureVmSizeStandard_A1_v2: writer.String("Standard_A1_v2"); break;
    case AzureVmSizeStandard_A2_v2: writer.String("Standard_A2_v2"); break;
    case AzureVmSizeStandard_A4_v2: writer.String("Standard_A4_v2"); break;
    case AzureVmSizeStandard_A8_v2: writer.String("Standard_A8_v2"); break;
    case AzureVmSizeStandard_F1: writer.String("Standard_F1"); break;
    case AzureVmSizeStandard_F2: writer.String("Standard_F2"); break;
    case AzureVmSizeStandard_F4: writer.String("Standard_F4"); break;
    case AzureVmSizeStandard_F8: writer.String("Standard_F8"); break;
    case AzureVmSizeStandard_F16: writer.String("Standard_F16"); break;
    case AzureVmSizeStandard_F2s_v2: writer.String("Standard_F2s_v2"); break;
    case AzureVmSizeStandard_F4s_v2: writer.String("Standard_F4s_v2"); break;
    case AzureVmSizeStandard_F8s_v2: writer.String("Standard_F8s_v2"); break;
    case AzureVmSizeStandard_F16s_v2: writer.String("Standard_F16s_v2"); break;
    case AzureVmSizeStandard_A1: writer.String("Standard_A1"); break;
    case AzureVmSizeStandard_A2: writer.String("Standard_A2"); break;
    case AzureVmSizeStandard_A3: writer.String("Standard_A3"); break;
    case AzureVmSizeStandard_A4: writer.String("Standard_A4"); break;

    }
}

AzureVmSize PlayFab::MultiplayerModels::readAzureVmSizeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, AzureVmSize> _AzureVmSizeMap;
    if (_AzureVmSizeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _AzureVmSizeMap["Standard_D1_v2"] = AzureVmSizeStandard_D1_v2;
        _AzureVmSizeMap["Standard_D2_v2"] = AzureVmSizeStandard_D2_v2;
        _AzureVmSizeMap["Standard_D3_v2"] = AzureVmSizeStandard_D3_v2;
        _AzureVmSizeMap["Standard_D4_v2"] = AzureVmSizeStandard_D4_v2;
        _AzureVmSizeMap["Standard_D5_v2"] = AzureVmSizeStandard_D5_v2;
        _AzureVmSizeMap["Standard_A1_v2"] = AzureVmSizeStandard_A1_v2;
        _AzureVmSizeMap["Standard_A2_v2"] = AzureVmSizeStandard_A2_v2;
        _AzureVmSizeMap["Standard_A4_v2"] = AzureVmSizeStandard_A4_v2;
        _AzureVmSizeMap["Standard_A8_v2"] = AzureVmSizeStandard_A8_v2;
        _AzureVmSizeMap["Standard_F1"] = AzureVmSizeStandard_F1;
        _AzureVmSizeMap["Standard_F2"] = AzureVmSizeStandard_F2;
        _AzureVmSizeMap["Standard_F4"] = AzureVmSizeStandard_F4;
        _AzureVmSizeMap["Standard_F8"] = AzureVmSizeStandard_F8;
        _AzureVmSizeMap["Standard_F16"] = AzureVmSizeStandard_F16;
        _AzureVmSizeMap["Standard_F2s_v2"] = AzureVmSizeStandard_F2s_v2;
        _AzureVmSizeMap["Standard_F4s_v2"] = AzureVmSizeStandard_F4s_v2;
        _AzureVmSizeMap["Standard_F8s_v2"] = AzureVmSizeStandard_F8s_v2;
        _AzureVmSizeMap["Standard_F16s_v2"] = AzureVmSizeStandard_F16s_v2;
        _AzureVmSizeMap["Standard_A1"] = AzureVmSizeStandard_A1;
        _AzureVmSizeMap["Standard_A2"] = AzureVmSizeStandard_A2;
        _AzureVmSizeMap["Standard_A3"] = AzureVmSizeStandard_A3;
        _AzureVmSizeMap["Standard_A4"] = AzureVmSizeStandard_A4;

    }

    auto output = _AzureVmSizeMap.find(obj.GetString());
    if (output != _AzureVmSizeMap.end())
        return output->second;

    return AzureVmSizeStandard_D1_v2; // Basically critical fail
}

BuildRegion::~BuildRegion()
{

}

void BuildRegion::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("MaxServers"); writer.Int(MaxServers);
    if (Region.notNull()) { writer.String("Region"); writeAzureRegionEnumJSON(Region, writer); }
    writer.String("StandbyServers"); writer.Int(StandbyServers);
    if (Status.length() > 0) { writer.String("Status"); writer.String(Status.c_str()); }
    writer.EndObject();
}

bool BuildRegion::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator MaxServers_member = obj.FindMember("MaxServers");
    if (MaxServers_member != obj.MemberEnd() && !MaxServers_member->value.IsNull()) MaxServers = MaxServers_member->value.GetInt();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator StandbyServers_member = obj.FindMember("StandbyServers");
    if (StandbyServers_member != obj.MemberEnd() && !StandbyServers_member->value.IsNull()) StandbyServers = StandbyServers_member->value.GetInt();
    const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
    if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = Status_member->value.GetString();

    return true;
}

BuildRegionParams::~BuildRegionParams()
{

}

void BuildRegionParams::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("MaxServers"); writer.Int(MaxServers);
    writer.String("Region"); writeAzureRegionEnumJSON(Region, writer);
    writer.String("StandbyServers"); writer.Int(StandbyServers);
    writer.EndObject();
}

bool BuildRegionParams::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator MaxServers_member = obj.FindMember("MaxServers");
    if (MaxServers_member != obj.MemberEnd() && !MaxServers_member->value.IsNull()) MaxServers = MaxServers_member->value.GetInt();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator StandbyServers_member = obj.FindMember("StandbyServers");
    if (StandbyServers_member != obj.MemberEnd() && !StandbyServers_member->value.IsNull()) StandbyServers = StandbyServers_member->value.GetInt();

    return true;
}

BuildSummary::~BuildSummary()
{

}

void BuildSummary::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    if (BuildName.length() > 0) { writer.String("BuildName"); writer.String(BuildName.c_str()); }
    if (CreationTime.notNull()) { writer.String("CreationTime"); writeDatetime(CreationTime, writer); }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.EndObject();
}

bool BuildSummary::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator BuildName_member = obj.FindMember("BuildName");
    if (BuildName_member != obj.MemberEnd() && !BuildName_member->value.IsNull()) BuildName = BuildName_member->value.GetString();
    const Value::ConstMemberIterator CreationTime_member = obj.FindMember("CreationTime");
    if (CreationTime_member != obj.MemberEnd() && !CreationTime_member->value.IsNull()) CreationTime = readDatetime(CreationTime_member->value);
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = iter->value.GetString();
        }
    }

    return true;
}

Certificate::~Certificate()
{

}

void Certificate::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Base64EncodedValue"); writer.String(Base64EncodedValue.c_str());
    writer.String("Name"); writer.String(Name.c_str());
    if (Password.length() > 0) { writer.String("Password"); writer.String(Password.c_str()); }
    writer.EndObject();
}

bool Certificate::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Base64EncodedValue_member = obj.FindMember("Base64EncodedValue");
    if (Base64EncodedValue_member != obj.MemberEnd() && !Base64EncodedValue_member->value.IsNull()) Base64EncodedValue = Base64EncodedValue_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
    if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

    return true;
}

CertificateSummary::~CertificateSummary()
{

}

void CertificateSummary::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    if (Thumbprint.length() > 0) { writer.String("Thumbprint"); writer.String(Thumbprint.c_str()); }
    writer.EndObject();
}

bool CertificateSummary::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator Thumbprint_member = obj.FindMember("Thumbprint");
    if (Thumbprint_member != obj.MemberEnd() && !Thumbprint_member->value.IsNull()) Thumbprint = Thumbprint_member->value.GetString();

    return true;
}

ConnectedPlayer::~ConnectedPlayer()
{

}

void ConnectedPlayer::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PlayerId.length() > 0) { writer.String("PlayerId"); writer.String(PlayerId.c_str()); }
    writer.EndObject();
}

bool ConnectedPlayer::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
    if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();

    return true;
}
void PlayFab::MultiplayerModels::writeContainerFlavorEnumJSON(ContainerFlavor enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case ContainerFlavorManagedWindowsServerCore: writer.String("ManagedWindowsServerCore"); break;
    case ContainerFlavorCustomLinux: writer.String("CustomLinux"); break;
    case ContainerFlavorManagedWindowsServerCorePreview: writer.String("ManagedWindowsServerCorePreview"); break;

    }
}

ContainerFlavor PlayFab::MultiplayerModels::readContainerFlavorFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, ContainerFlavor> _ContainerFlavorMap;
    if (_ContainerFlavorMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _ContainerFlavorMap["ManagedWindowsServerCore"] = ContainerFlavorManagedWindowsServerCore;
        _ContainerFlavorMap["CustomLinux"] = ContainerFlavorCustomLinux;
        _ContainerFlavorMap["ManagedWindowsServerCorePreview"] = ContainerFlavorManagedWindowsServerCorePreview;

    }

    auto output = _ContainerFlavorMap.find(obj.GetString());
    if (output != _ContainerFlavorMap.end())
        return output->second;

    return ContainerFlavorManagedWindowsServerCore; // Basically critical fail
}

ContainerImageReference::~ContainerImageReference()
{

}

void ContainerImageReference::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("ImageName"); writer.String(ImageName.c_str());
    if (Tag.length() > 0) { writer.String("Tag"); writer.String(Tag.c_str()); }
    writer.EndObject();
}

bool ContainerImageReference::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ImageName_member = obj.FindMember("ImageName");
    if (ImageName_member != obj.MemberEnd() && !ImageName_member->value.IsNull()) ImageName = ImageName_member->value.GetString();
    const Value::ConstMemberIterator Tag_member = obj.FindMember("Tag");
    if (Tag_member != obj.MemberEnd() && !Tag_member->value.IsNull()) Tag = Tag_member->value.GetString();

    return true;
}

GameCertificateReferenceParams::~GameCertificateReferenceParams()
{

}

void GameCertificateReferenceParams::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("GsdkAlias"); writer.String(GsdkAlias.c_str());
    writer.String("Name"); writer.String(Name.c_str());
    writer.EndObject();
}

bool GameCertificateReferenceParams::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GsdkAlias_member = obj.FindMember("GsdkAlias");
    if (GsdkAlias_member != obj.MemberEnd() && !GsdkAlias_member->value.IsNull()) GsdkAlias = GsdkAlias_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

    return true;
}
void PlayFab::MultiplayerModels::writeProtocolTypeEnumJSON(ProtocolType enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case ProtocolTypeTCP: writer.String("TCP"); break;
    case ProtocolTypeUDP: writer.String("UDP"); break;

    }
}

ProtocolType PlayFab::MultiplayerModels::readProtocolTypeFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, ProtocolType> _ProtocolTypeMap;
    if (_ProtocolTypeMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _ProtocolTypeMap["TCP"] = ProtocolTypeTCP;
        _ProtocolTypeMap["UDP"] = ProtocolTypeUDP;

    }

    auto output = _ProtocolTypeMap.find(obj.GetString());
    if (output != _ProtocolTypeMap.end())
        return output->second;

    return ProtocolTypeTCP; // Basically critical fail
}

Port::~Port()
{

}

void Port::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Name"); writer.String(Name.c_str());
    writer.String("Num"); writer.Int(Num);
    writer.String("Protocol"); writeProtocolTypeEnumJSON(Protocol, writer);
    writer.EndObject();
}

bool Port::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
    const Value::ConstMemberIterator Num_member = obj.FindMember("Num");
    if (Num_member != obj.MemberEnd() && !Num_member->value.IsNull()) Num = Num_member->value.GetInt();
    const Value::ConstMemberIterator Protocol_member = obj.FindMember("Protocol");
    if (Protocol_member != obj.MemberEnd() && !Protocol_member->value.IsNull()) Protocol = readProtocolTypeFromValue(Protocol_member->value);

    return true;
}

CreateBuildWithCustomContainerRequest::~CreateBuildWithCustomContainerRequest()
{

}

void CreateBuildWithCustomContainerRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildName"); writer.String(BuildName.c_str());
    if (pfContainerFlavor.notNull()) { writer.String("ContainerFlavor"); writeContainerFlavorEnumJSON(pfContainerFlavor, writer); }
    writer.String("ContainerRepositoryName"); writer.String(ContainerRepositoryName.c_str());
    if (ContainerRunCommand.length() > 0) { writer.String("ContainerRunCommand"); writer.String(ContainerRunCommand.c_str()); }
    if (ContainerTag.length() > 0) { writer.String("ContainerTag"); writer.String(ContainerTag.c_str()); }
    if (!GameAssetReferences.empty()) {
        writer.String("GameAssetReferences");
        writer.StartArray();
        for (std::list<AssetReferenceParams>::iterator iter = GameAssetReferences.begin(); iter != GameAssetReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!GameCertificateReferences.empty()) {
        writer.String("GameCertificateReferences");
        writer.StartArray();
        for (std::list<GameCertificateReferenceParams>::iterator iter = GameCertificateReferences.begin(); iter != GameCertificateReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("MultiplayerServerCountPerVm"); writer.Int(MultiplayerServerCountPerVm);
    writer.String("Ports");
    writer.StartArray();
    for (std::list<Port>::iterator iter = Ports.begin(); iter != Ports.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.String("RegionConfigurations");
    writer.StartArray();
    for (std::list<BuildRegionParams>::iterator iter = RegionConfigurations.begin(); iter != RegionConfigurations.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    if (VmSize.notNull()) { writer.String("VmSize"); writeAzureVmSizeEnumJSON(VmSize, writer); }
    writer.EndObject();
}

bool CreateBuildWithCustomContainerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildName_member = obj.FindMember("BuildName");
    if (BuildName_member != obj.MemberEnd() && !BuildName_member->value.IsNull()) BuildName = BuildName_member->value.GetString();
    const Value::ConstMemberIterator ContainerFlavor_member = obj.FindMember("ContainerFlavor");
    if (ContainerFlavor_member != obj.MemberEnd() && !ContainerFlavor_member->value.IsNull()) pfContainerFlavor = readContainerFlavorFromValue(ContainerFlavor_member->value);
    const Value::ConstMemberIterator ContainerRepositoryName_member = obj.FindMember("ContainerRepositoryName");
    if (ContainerRepositoryName_member != obj.MemberEnd() && !ContainerRepositoryName_member->value.IsNull()) ContainerRepositoryName = ContainerRepositoryName_member->value.GetString();
    const Value::ConstMemberIterator ContainerRunCommand_member = obj.FindMember("ContainerRunCommand");
    if (ContainerRunCommand_member != obj.MemberEnd() && !ContainerRunCommand_member->value.IsNull()) ContainerRunCommand = ContainerRunCommand_member->value.GetString();
    const Value::ConstMemberIterator ContainerTag_member = obj.FindMember("ContainerTag");
    if (ContainerTag_member != obj.MemberEnd() && !ContainerTag_member->value.IsNull()) ContainerTag = ContainerTag_member->value.GetString();
    const Value::ConstMemberIterator GameAssetReferences_member = obj.FindMember("GameAssetReferences");
    if (GameAssetReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameAssetReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameAssetReferences.push_back(AssetReferenceParams(memberList[i]));
        }
    }
    const Value::ConstMemberIterator GameCertificateReferences_member = obj.FindMember("GameCertificateReferences");
    if (GameCertificateReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameCertificateReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameCertificateReferences.push_back(GameCertificateReferenceParams(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator MultiplayerServerCountPerVm_member = obj.FindMember("MultiplayerServerCountPerVm");
    if (MultiplayerServerCountPerVm_member != obj.MemberEnd() && !MultiplayerServerCountPerVm_member->value.IsNull()) MultiplayerServerCountPerVm = MultiplayerServerCountPerVm_member->value.GetInt();
    const Value::ConstMemberIterator Ports_member = obj.FindMember("Ports");
    if (Ports_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Ports_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Ports.push_back(Port(memberList[i]));
        }
    }
    const Value::ConstMemberIterator RegionConfigurations_member = obj.FindMember("RegionConfigurations");
    if (RegionConfigurations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = RegionConfigurations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            RegionConfigurations.push_back(BuildRegionParams(memberList[i]));
        }
    }
    const Value::ConstMemberIterator VmSize_member = obj.FindMember("VmSize");
    if (VmSize_member != obj.MemberEnd() && !VmSize_member->value.IsNull()) VmSize = readAzureVmSizeFromValue(VmSize_member->value);

    return true;
}

GameCertificateReference::~GameCertificateReference()
{

}

void GameCertificateReference::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (GsdkAlias.length() > 0) { writer.String("GsdkAlias"); writer.String(GsdkAlias.c_str()); }
    if (Name.length() > 0) { writer.String("Name"); writer.String(Name.c_str()); }
    writer.EndObject();
}

bool GameCertificateReference::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GsdkAlias_member = obj.FindMember("GsdkAlias");
    if (GsdkAlias_member != obj.MemberEnd() && !GsdkAlias_member->value.IsNull()) GsdkAlias = GsdkAlias_member->value.GetString();
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

    return true;
}

CreateBuildWithCustomContainerResponse::~CreateBuildWithCustomContainerResponse()
{
    if (CustomGameContainerImage != NULL) delete CustomGameContainerImage;

}

void CreateBuildWithCustomContainerResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    if (BuildName.length() > 0) { writer.String("BuildName"); writer.String(BuildName.c_str()); }
    if (pfContainerFlavor.notNull()) { writer.String("ContainerFlavor"); writeContainerFlavorEnumJSON(pfContainerFlavor, writer); }
    if (ContainerRunCommand.length() > 0) { writer.String("ContainerRunCommand"); writer.String(ContainerRunCommand.c_str()); }
    if (CreationTime.notNull()) { writer.String("CreationTime"); writeDatetime(CreationTime, writer); }
    if (CustomGameContainerImage != NULL) { writer.String("CustomGameContainerImage"); CustomGameContainerImage->writeJSON(writer); }
    if (!GameAssetReferences.empty()) {
        writer.String("GameAssetReferences");
        writer.StartArray();
        for (std::list<AssetReference>::iterator iter = GameAssetReferences.begin(); iter != GameAssetReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!GameCertificateReferences.empty()) {
        writer.String("GameCertificateReferences");
        writer.StartArray();
        for (std::list<GameCertificateReference>::iterator iter = GameCertificateReferences.begin(); iter != GameCertificateReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("MultiplayerServerCountPerVm"); writer.Int(MultiplayerServerCountPerVm);
    if (!Ports.empty()) {
        writer.String("Ports");
        writer.StartArray();
        for (std::list<Port>::iterator iter = Ports.begin(); iter != Ports.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!RegionConfigurations.empty()) {
        writer.String("RegionConfigurations");
        writer.StartArray();
        for (std::list<BuildRegion>::iterator iter = RegionConfigurations.begin(); iter != RegionConfigurations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (VmSize.notNull()) { writer.String("VmSize"); writeAzureVmSizeEnumJSON(VmSize, writer); }
    writer.EndObject();
}

bool CreateBuildWithCustomContainerResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator BuildName_member = obj.FindMember("BuildName");
    if (BuildName_member != obj.MemberEnd() && !BuildName_member->value.IsNull()) BuildName = BuildName_member->value.GetString();
    const Value::ConstMemberIterator ContainerFlavor_member = obj.FindMember("ContainerFlavor");
    if (ContainerFlavor_member != obj.MemberEnd() && !ContainerFlavor_member->value.IsNull()) pfContainerFlavor = readContainerFlavorFromValue(ContainerFlavor_member->value);
    const Value::ConstMemberIterator ContainerRunCommand_member = obj.FindMember("ContainerRunCommand");
    if (ContainerRunCommand_member != obj.MemberEnd() && !ContainerRunCommand_member->value.IsNull()) ContainerRunCommand = ContainerRunCommand_member->value.GetString();
    const Value::ConstMemberIterator CreationTime_member = obj.FindMember("CreationTime");
    if (CreationTime_member != obj.MemberEnd() && !CreationTime_member->value.IsNull()) CreationTime = readDatetime(CreationTime_member->value);
    const Value::ConstMemberIterator CustomGameContainerImage_member = obj.FindMember("CustomGameContainerImage");
    if (CustomGameContainerImage_member != obj.MemberEnd() && !CustomGameContainerImage_member->value.IsNull()) CustomGameContainerImage = new ContainerImageReference(CustomGameContainerImage_member->value);
    const Value::ConstMemberIterator GameAssetReferences_member = obj.FindMember("GameAssetReferences");
    if (GameAssetReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameAssetReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameAssetReferences.push_back(AssetReference(memberList[i]));
        }
    }
    const Value::ConstMemberIterator GameCertificateReferences_member = obj.FindMember("GameCertificateReferences");
    if (GameCertificateReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameCertificateReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameCertificateReferences.push_back(GameCertificateReference(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator MultiplayerServerCountPerVm_member = obj.FindMember("MultiplayerServerCountPerVm");
    if (MultiplayerServerCountPerVm_member != obj.MemberEnd() && !MultiplayerServerCountPerVm_member->value.IsNull()) MultiplayerServerCountPerVm = MultiplayerServerCountPerVm_member->value.GetInt();
    const Value::ConstMemberIterator Ports_member = obj.FindMember("Ports");
    if (Ports_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Ports_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Ports.push_back(Port(memberList[i]));
        }
    }
    const Value::ConstMemberIterator RegionConfigurations_member = obj.FindMember("RegionConfigurations");
    if (RegionConfigurations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = RegionConfigurations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            RegionConfigurations.push_back(BuildRegion(memberList[i]));
        }
    }
    const Value::ConstMemberIterator VmSize_member = obj.FindMember("VmSize");
    if (VmSize_member != obj.MemberEnd() && !VmSize_member->value.IsNull()) VmSize = readAzureVmSizeFromValue(VmSize_member->value);

    return true;
}

CreateBuildWithManagedContainerRequest::~CreateBuildWithManagedContainerRequest()
{

}

void CreateBuildWithManagedContainerRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildName"); writer.String(BuildName.c_str());
    if (pfContainerFlavor.notNull()) { writer.String("ContainerFlavor"); writeContainerFlavorEnumJSON(pfContainerFlavor, writer); }
    writer.String("GameAssetReferences");
    writer.StartArray();
    for (std::list<AssetReferenceParams>::iterator iter = GameAssetReferences.begin(); iter != GameAssetReferences.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    if (!GameCertificateReferences.empty()) {
        writer.String("GameCertificateReferences");
        writer.StartArray();
        for (std::list<GameCertificateReferenceParams>::iterator iter = GameCertificateReferences.begin(); iter != GameCertificateReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("MultiplayerServerCountPerVm"); writer.Int(MultiplayerServerCountPerVm);
    writer.String("Ports");
    writer.StartArray();
    for (std::list<Port>::iterator iter = Ports.begin(); iter != Ports.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.String("RegionConfigurations");
    writer.StartArray();
    for (std::list<BuildRegionParams>::iterator iter = RegionConfigurations.begin(); iter != RegionConfigurations.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.String("StartMultiplayerServerCommand"); writer.String(StartMultiplayerServerCommand.c_str());
    if (VmSize.notNull()) { writer.String("VmSize"); writeAzureVmSizeEnumJSON(VmSize, writer); }
    writer.EndObject();
}

bool CreateBuildWithManagedContainerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildName_member = obj.FindMember("BuildName");
    if (BuildName_member != obj.MemberEnd() && !BuildName_member->value.IsNull()) BuildName = BuildName_member->value.GetString();
    const Value::ConstMemberIterator ContainerFlavor_member = obj.FindMember("ContainerFlavor");
    if (ContainerFlavor_member != obj.MemberEnd() && !ContainerFlavor_member->value.IsNull()) pfContainerFlavor = readContainerFlavorFromValue(ContainerFlavor_member->value);
    const Value::ConstMemberIterator GameAssetReferences_member = obj.FindMember("GameAssetReferences");
    if (GameAssetReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameAssetReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameAssetReferences.push_back(AssetReferenceParams(memberList[i]));
        }
    }
    const Value::ConstMemberIterator GameCertificateReferences_member = obj.FindMember("GameCertificateReferences");
    if (GameCertificateReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameCertificateReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameCertificateReferences.push_back(GameCertificateReferenceParams(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator MultiplayerServerCountPerVm_member = obj.FindMember("MultiplayerServerCountPerVm");
    if (MultiplayerServerCountPerVm_member != obj.MemberEnd() && !MultiplayerServerCountPerVm_member->value.IsNull()) MultiplayerServerCountPerVm = MultiplayerServerCountPerVm_member->value.GetInt();
    const Value::ConstMemberIterator Ports_member = obj.FindMember("Ports");
    if (Ports_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Ports_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Ports.push_back(Port(memberList[i]));
        }
    }
    const Value::ConstMemberIterator RegionConfigurations_member = obj.FindMember("RegionConfigurations");
    if (RegionConfigurations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = RegionConfigurations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            RegionConfigurations.push_back(BuildRegionParams(memberList[i]));
        }
    }
    const Value::ConstMemberIterator StartMultiplayerServerCommand_member = obj.FindMember("StartMultiplayerServerCommand");
    if (StartMultiplayerServerCommand_member != obj.MemberEnd() && !StartMultiplayerServerCommand_member->value.IsNull()) StartMultiplayerServerCommand = StartMultiplayerServerCommand_member->value.GetString();
    const Value::ConstMemberIterator VmSize_member = obj.FindMember("VmSize");
    if (VmSize_member != obj.MemberEnd() && !VmSize_member->value.IsNull()) VmSize = readAzureVmSizeFromValue(VmSize_member->value);

    return true;
}

CreateBuildWithManagedContainerResponse::~CreateBuildWithManagedContainerResponse()
{

}

void CreateBuildWithManagedContainerResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    if (BuildName.length() > 0) { writer.String("BuildName"); writer.String(BuildName.c_str()); }
    if (pfContainerFlavor.notNull()) { writer.String("ContainerFlavor"); writeContainerFlavorEnumJSON(pfContainerFlavor, writer); }
    if (CreationTime.notNull()) { writer.String("CreationTime"); writeDatetime(CreationTime, writer); }
    if (!GameAssetReferences.empty()) {
        writer.String("GameAssetReferences");
        writer.StartArray();
        for (std::list<AssetReference>::iterator iter = GameAssetReferences.begin(); iter != GameAssetReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!GameCertificateReferences.empty()) {
        writer.String("GameCertificateReferences");
        writer.StartArray();
        for (std::list<GameCertificateReference>::iterator iter = GameCertificateReferences.begin(); iter != GameCertificateReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("MultiplayerServerCountPerVm"); writer.Int(MultiplayerServerCountPerVm);
    if (!Ports.empty()) {
        writer.String("Ports");
        writer.StartArray();
        for (std::list<Port>::iterator iter = Ports.begin(); iter != Ports.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!RegionConfigurations.empty()) {
        writer.String("RegionConfigurations");
        writer.StartArray();
        for (std::list<BuildRegion>::iterator iter = RegionConfigurations.begin(); iter != RegionConfigurations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (StartMultiplayerServerCommand.length() > 0) { writer.String("StartMultiplayerServerCommand"); writer.String(StartMultiplayerServerCommand.c_str()); }
    if (VmSize.notNull()) { writer.String("VmSize"); writeAzureVmSizeEnumJSON(VmSize, writer); }
    writer.EndObject();
}

bool CreateBuildWithManagedContainerResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator BuildName_member = obj.FindMember("BuildName");
    if (BuildName_member != obj.MemberEnd() && !BuildName_member->value.IsNull()) BuildName = BuildName_member->value.GetString();
    const Value::ConstMemberIterator ContainerFlavor_member = obj.FindMember("ContainerFlavor");
    if (ContainerFlavor_member != obj.MemberEnd() && !ContainerFlavor_member->value.IsNull()) pfContainerFlavor = readContainerFlavorFromValue(ContainerFlavor_member->value);
    const Value::ConstMemberIterator CreationTime_member = obj.FindMember("CreationTime");
    if (CreationTime_member != obj.MemberEnd() && !CreationTime_member->value.IsNull()) CreationTime = readDatetime(CreationTime_member->value);
    const Value::ConstMemberIterator GameAssetReferences_member = obj.FindMember("GameAssetReferences");
    if (GameAssetReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameAssetReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameAssetReferences.push_back(AssetReference(memberList[i]));
        }
    }
    const Value::ConstMemberIterator GameCertificateReferences_member = obj.FindMember("GameCertificateReferences");
    if (GameCertificateReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameCertificateReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameCertificateReferences.push_back(GameCertificateReference(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator MultiplayerServerCountPerVm_member = obj.FindMember("MultiplayerServerCountPerVm");
    if (MultiplayerServerCountPerVm_member != obj.MemberEnd() && !MultiplayerServerCountPerVm_member->value.IsNull()) MultiplayerServerCountPerVm = MultiplayerServerCountPerVm_member->value.GetInt();
    const Value::ConstMemberIterator Ports_member = obj.FindMember("Ports");
    if (Ports_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Ports_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Ports.push_back(Port(memberList[i]));
        }
    }
    const Value::ConstMemberIterator RegionConfigurations_member = obj.FindMember("RegionConfigurations");
    if (RegionConfigurations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = RegionConfigurations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            RegionConfigurations.push_back(BuildRegion(memberList[i]));
        }
    }
    const Value::ConstMemberIterator StartMultiplayerServerCommand_member = obj.FindMember("StartMultiplayerServerCommand");
    if (StartMultiplayerServerCommand_member != obj.MemberEnd() && !StartMultiplayerServerCommand_member->value.IsNull()) StartMultiplayerServerCommand = StartMultiplayerServerCommand_member->value.GetString();
    const Value::ConstMemberIterator VmSize_member = obj.FindMember("VmSize");
    if (VmSize_member != obj.MemberEnd() && !VmSize_member->value.IsNull()) VmSize = readAzureVmSizeFromValue(VmSize_member->value);

    return true;
}

CreateRemoteUserRequest::~CreateRemoteUserRequest()
{

}

void CreateRemoteUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    if (ExpirationTime.notNull()) { writer.String("ExpirationTime"); writeDatetime(ExpirationTime, writer); }
    writer.String("Region"); writeAzureRegionEnumJSON(Region, writer);
    writer.String("Username"); writer.String(Username.c_str());
    writer.String("VmId"); writer.String(VmId.c_str());
    writer.EndObject();
}

bool CreateRemoteUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator ExpirationTime_member = obj.FindMember("ExpirationTime");
    if (ExpirationTime_member != obj.MemberEnd() && !ExpirationTime_member->value.IsNull()) ExpirationTime = readDatetime(ExpirationTime_member->value);
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator VmId_member = obj.FindMember("VmId");
    if (VmId_member != obj.MemberEnd() && !VmId_member->value.IsNull()) VmId = VmId_member->value.GetString();

    return true;
}

CreateRemoteUserResponse::~CreateRemoteUserResponse()
{

}

void CreateRemoteUserResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ExpirationTime.notNull()) { writer.String("ExpirationTime"); writeDatetime(ExpirationTime, writer); }
    if (Password.length() > 0) { writer.String("Password"); writer.String(Password.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    writer.EndObject();
}

bool CreateRemoteUserResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ExpirationTime_member = obj.FindMember("ExpirationTime");
    if (ExpirationTime_member != obj.MemberEnd() && !ExpirationTime_member->value.IsNull()) ExpirationTime = readDatetime(ExpirationTime_member->value);
    const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
    if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

    return true;
}

DeleteAssetRequest::~DeleteAssetRequest()
{

}

void DeleteAssetRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("FileName"); writer.String(FileName.c_str());
    writer.EndObject();
}

bool DeleteAssetRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();

    return true;
}

DeleteBuildRequest::~DeleteBuildRequest()
{

}

void DeleteBuildRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    writer.EndObject();
}

bool DeleteBuildRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

    return true;
}

DeleteCertificateRequest::~DeleteCertificateRequest()
{

}

void DeleteCertificateRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("Name"); writer.String(Name.c_str());
    writer.EndObject();
}

bool DeleteCertificateRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
    if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

    return true;
}

DeleteRemoteUserRequest::~DeleteRemoteUserRequest()
{

}

void DeleteRemoteUserRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    writer.String("Region"); writeAzureRegionEnumJSON(Region, writer);
    writer.String("Username"); writer.String(Username.c_str());
    writer.String("VmId"); writer.String(VmId.c_str());
    writer.EndObject();
}

bool DeleteRemoteUserRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
    const Value::ConstMemberIterator VmId_member = obj.FindMember("VmId");
    if (VmId_member != obj.MemberEnd() && !VmId_member->value.IsNull()) VmId = VmId_member->value.GetString();

    return true;
}

EmptyResponse::~EmptyResponse()
{

}

void EmptyResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool EmptyResponse::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

EnableMultiplayerServersForTitleRequest::~EnableMultiplayerServersForTitleRequest()
{

}

void EnableMultiplayerServersForTitleRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool EnableMultiplayerServersForTitleRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}
void PlayFab::MultiplayerModels::writeTitleMultiplayerServerEnabledStatusEnumJSON(TitleMultiplayerServerEnabledStatus enumVal, PFStringJsonWriter& writer)
{
    switch (enumVal)
    {
    case TitleMultiplayerServerEnabledStatusInitializing: writer.String("Initializing"); break;
    case TitleMultiplayerServerEnabledStatusEnabled: writer.String("Enabled"); break;
    case TitleMultiplayerServerEnabledStatusDisabled: writer.String("Disabled"); break;

    }
}

TitleMultiplayerServerEnabledStatus PlayFab::MultiplayerModels::readTitleMultiplayerServerEnabledStatusFromValue(const rapidjson::Value& obj)
{
    static std::map<std::string, TitleMultiplayerServerEnabledStatus> _TitleMultiplayerServerEnabledStatusMap;
    if (_TitleMultiplayerServerEnabledStatusMap.size() == 0)
    {
        // Auto-generate the map on the first use
        _TitleMultiplayerServerEnabledStatusMap["Initializing"] = TitleMultiplayerServerEnabledStatusInitializing;
        _TitleMultiplayerServerEnabledStatusMap["Enabled"] = TitleMultiplayerServerEnabledStatusEnabled;
        _TitleMultiplayerServerEnabledStatusMap["Disabled"] = TitleMultiplayerServerEnabledStatusDisabled;

    }

    auto output = _TitleMultiplayerServerEnabledStatusMap.find(obj.GetString());
    if (output != _TitleMultiplayerServerEnabledStatusMap.end())
        return output->second;

    return TitleMultiplayerServerEnabledStatusInitializing; // Basically critical fail
}

EnableMultiplayerServersForTitleResponse::~EnableMultiplayerServersForTitleResponse()
{

}

void EnableMultiplayerServersForTitleResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Status.notNull()) { writer.String("Status"); writeTitleMultiplayerServerEnabledStatusEnumJSON(Status, writer); }
    writer.EndObject();
}

bool EnableMultiplayerServersForTitleResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
    if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTitleMultiplayerServerEnabledStatusFromValue(Status_member->value);

    return true;
}

GetAssetUploadUrlRequest::~GetAssetUploadUrlRequest()
{

}

void GetAssetUploadUrlRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("FileName"); writer.String(FileName.c_str());
    writer.EndObject();
}

bool GetAssetUploadUrlRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();

    return true;
}

GetAssetUploadUrlResponse::~GetAssetUploadUrlResponse()
{

}

void GetAssetUploadUrlResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (AssetUploadUrl.length() > 0) { writer.String("AssetUploadUrl"); writer.String(AssetUploadUrl.c_str()); }
    if (FileName.length() > 0) { writer.String("FileName"); writer.String(FileName.c_str()); }
    writer.EndObject();
}

bool GetAssetUploadUrlResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AssetUploadUrl_member = obj.FindMember("AssetUploadUrl");
    if (AssetUploadUrl_member != obj.MemberEnd() && !AssetUploadUrl_member->value.IsNull()) AssetUploadUrl = AssetUploadUrl_member->value.GetString();
    const Value::ConstMemberIterator FileName_member = obj.FindMember("FileName");
    if (FileName_member != obj.MemberEnd() && !FileName_member->value.IsNull()) FileName = FileName_member->value.GetString();

    return true;
}

GetBuildRequest::~GetBuildRequest()
{

}

void GetBuildRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    writer.EndObject();
}

bool GetBuildRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

    return true;
}

GetBuildResponse::~GetBuildResponse()
{
    if (CustomGameContainerImage != NULL) delete CustomGameContainerImage;

}

void GetBuildResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (BuildId.length() > 0) { writer.String("BuildId"); writer.String(BuildId.c_str()); }
    if (BuildName.length() > 0) { writer.String("BuildName"); writer.String(BuildName.c_str()); }
    if (BuildStatus.length() > 0) { writer.String("BuildStatus"); writer.String(BuildStatus.c_str()); }
    if (pfContainerFlavor.notNull()) { writer.String("ContainerFlavor"); writeContainerFlavorEnumJSON(pfContainerFlavor, writer); }
    if (ContainerRunCommand.length() > 0) { writer.String("ContainerRunCommand"); writer.String(ContainerRunCommand.c_str()); }
    if (CreationTime.notNull()) { writer.String("CreationTime"); writeDatetime(CreationTime, writer); }
    if (CustomGameContainerImage != NULL) { writer.String("CustomGameContainerImage"); CustomGameContainerImage->writeJSON(writer); }
    if (!GameAssetReferences.empty()) {
        writer.String("GameAssetReferences");
        writer.StartArray();
        for (std::list<AssetReference>::iterator iter = GameAssetReferences.begin(); iter != GameAssetReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!GameCertificateReferences.empty()) {
        writer.String("GameCertificateReferences");
        writer.StartArray();
        for (std::list<GameCertificateReference>::iterator iter = GameCertificateReferences.begin(); iter != GameCertificateReferences.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!Metadata.empty()) {
        writer.String("Metadata");
        writer.StartObject();
        for (std::map<std::string, std::string>::iterator iter = Metadata.begin(); iter != Metadata.end(); ++iter) {
            writer.String(iter->first.c_str()); writer.String(iter->second.c_str());
        }
        writer.EndObject();
    }
    writer.String("MultiplayerServerCountPerVm"); writer.Int(MultiplayerServerCountPerVm);
    if (!Ports.empty()) {
        writer.String("Ports");
        writer.StartArray();
        for (std::list<Port>::iterator iter = Ports.begin(); iter != Ports.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (!RegionConfigurations.empty()) {
        writer.String("RegionConfigurations");
        writer.StartArray();
        for (std::list<BuildRegion>::iterator iter = RegionConfigurations.begin(); iter != RegionConfigurations.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (StartMultiplayerServerCommand.length() > 0) { writer.String("StartMultiplayerServerCommand"); writer.String(StartMultiplayerServerCommand.c_str()); }
    if (VmSize.notNull()) { writer.String("VmSize"); writeAzureVmSizeEnumJSON(VmSize, writer); }
    writer.EndObject();
}

bool GetBuildResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator BuildName_member = obj.FindMember("BuildName");
    if (BuildName_member != obj.MemberEnd() && !BuildName_member->value.IsNull()) BuildName = BuildName_member->value.GetString();
    const Value::ConstMemberIterator BuildStatus_member = obj.FindMember("BuildStatus");
    if (BuildStatus_member != obj.MemberEnd() && !BuildStatus_member->value.IsNull()) BuildStatus = BuildStatus_member->value.GetString();
    const Value::ConstMemberIterator ContainerFlavor_member = obj.FindMember("ContainerFlavor");
    if (ContainerFlavor_member != obj.MemberEnd() && !ContainerFlavor_member->value.IsNull()) pfContainerFlavor = readContainerFlavorFromValue(ContainerFlavor_member->value);
    const Value::ConstMemberIterator ContainerRunCommand_member = obj.FindMember("ContainerRunCommand");
    if (ContainerRunCommand_member != obj.MemberEnd() && !ContainerRunCommand_member->value.IsNull()) ContainerRunCommand = ContainerRunCommand_member->value.GetString();
    const Value::ConstMemberIterator CreationTime_member = obj.FindMember("CreationTime");
    if (CreationTime_member != obj.MemberEnd() && !CreationTime_member->value.IsNull()) CreationTime = readDatetime(CreationTime_member->value);
    const Value::ConstMemberIterator CustomGameContainerImage_member = obj.FindMember("CustomGameContainerImage");
    if (CustomGameContainerImage_member != obj.MemberEnd() && !CustomGameContainerImage_member->value.IsNull()) CustomGameContainerImage = new ContainerImageReference(CustomGameContainerImage_member->value);
    const Value::ConstMemberIterator GameAssetReferences_member = obj.FindMember("GameAssetReferences");
    if (GameAssetReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameAssetReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameAssetReferences.push_back(AssetReference(memberList[i]));
        }
    }
    const Value::ConstMemberIterator GameCertificateReferences_member = obj.FindMember("GameCertificateReferences");
    if (GameCertificateReferences_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = GameCertificateReferences_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            GameCertificateReferences.push_back(GameCertificateReference(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
    if (Metadata_member != obj.MemberEnd()) {
        for (Value::ConstMemberIterator iter = Metadata_member->value.MemberBegin(); iter != Metadata_member->value.MemberEnd(); ++iter) {
            Metadata[iter->name.GetString()] = iter->value.GetString();
        }
    }
    const Value::ConstMemberIterator MultiplayerServerCountPerVm_member = obj.FindMember("MultiplayerServerCountPerVm");
    if (MultiplayerServerCountPerVm_member != obj.MemberEnd() && !MultiplayerServerCountPerVm_member->value.IsNull()) MultiplayerServerCountPerVm = MultiplayerServerCountPerVm_member->value.GetInt();
    const Value::ConstMemberIterator Ports_member = obj.FindMember("Ports");
    if (Ports_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Ports_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Ports.push_back(Port(memberList[i]));
        }
    }
    const Value::ConstMemberIterator RegionConfigurations_member = obj.FindMember("RegionConfigurations");
    if (RegionConfigurations_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = RegionConfigurations_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            RegionConfigurations.push_back(BuildRegion(memberList[i]));
        }
    }
    const Value::ConstMemberIterator StartMultiplayerServerCommand_member = obj.FindMember("StartMultiplayerServerCommand");
    if (StartMultiplayerServerCommand_member != obj.MemberEnd() && !StartMultiplayerServerCommand_member->value.IsNull()) StartMultiplayerServerCommand = StartMultiplayerServerCommand_member->value.GetString();
    const Value::ConstMemberIterator VmSize_member = obj.FindMember("VmSize");
    if (VmSize_member != obj.MemberEnd() && !VmSize_member->value.IsNull()) VmSize = readAzureVmSizeFromValue(VmSize_member->value);

    return true;
}

GetContainerRegistryCredentialsRequest::~GetContainerRegistryCredentialsRequest()
{

}

void GetContainerRegistryCredentialsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool GetContainerRegistryCredentialsRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetContainerRegistryCredentialsResponse::~GetContainerRegistryCredentialsResponse()
{

}

void GetContainerRegistryCredentialsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DnsName.length() > 0) { writer.String("DnsName"); writer.String(DnsName.c_str()); }
    if (Password.length() > 0) { writer.String("Password"); writer.String(Password.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    writer.EndObject();
}

bool GetContainerRegistryCredentialsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DnsName_member = obj.FindMember("DnsName");
    if (DnsName_member != obj.MemberEnd() && !DnsName_member->value.IsNull()) DnsName = DnsName_member->value.GetString();
    const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
    if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

    return true;
}

GetMultiplayerServerDetailsRequest::~GetMultiplayerServerDetailsRequest()
{

}

void GetMultiplayerServerDetailsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    writer.String("Region"); writeAzureRegionEnumJSON(Region, writer);
    writer.String("SessionId"); writer.String(SessionId.c_str());
    writer.EndObject();
}

bool GetMultiplayerServerDetailsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator SessionId_member = obj.FindMember("SessionId");
    if (SessionId_member != obj.MemberEnd() && !SessionId_member->value.IsNull()) SessionId = SessionId_member->value.GetString();

    return true;
}

GetMultiplayerServerDetailsResponse::~GetMultiplayerServerDetailsResponse()
{

}

void GetMultiplayerServerDetailsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!ConnectedPlayers.empty()) {
        writer.String("ConnectedPlayers");
        writer.StartArray();
        for (std::list<ConnectedPlayer>::iterator iter = ConnectedPlayers.begin(); iter != ConnectedPlayers.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (FQDN.length() > 0) { writer.String("FQDN"); writer.String(FQDN.c_str()); }
    if (IPV4Address.length() > 0) { writer.String("IPV4Address"); writer.String(IPV4Address.c_str()); }
    if (LastStateTransitionTime.notNull()) { writer.String("LastStateTransitionTime"); writeDatetime(LastStateTransitionTime, writer); }
    if (!Ports.empty()) {
        writer.String("Ports");
        writer.StartArray();
        for (std::list<Port>::iterator iter = Ports.begin(); iter != Ports.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (Region.notNull()) { writer.String("Region"); writeAzureRegionEnumJSON(Region, writer); }
    if (ServerId.length() > 0) { writer.String("ServerId"); writer.String(ServerId.c_str()); }
    if (SessionId.length() > 0) { writer.String("SessionId"); writer.String(SessionId.c_str()); }
    if (State.length() > 0) { writer.String("State"); writer.String(State.c_str()); }
    if (VmId.length() > 0) { writer.String("VmId"); writer.String(VmId.c_str()); }
    writer.EndObject();
}

bool GetMultiplayerServerDetailsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ConnectedPlayers_member = obj.FindMember("ConnectedPlayers");
    if (ConnectedPlayers_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ConnectedPlayers_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ConnectedPlayers.push_back(ConnectedPlayer(memberList[i]));
        }
    }
    const Value::ConstMemberIterator FQDN_member = obj.FindMember("FQDN");
    if (FQDN_member != obj.MemberEnd() && !FQDN_member->value.IsNull()) FQDN = FQDN_member->value.GetString();
    const Value::ConstMemberIterator IPV4Address_member = obj.FindMember("IPV4Address");
    if (IPV4Address_member != obj.MemberEnd() && !IPV4Address_member->value.IsNull()) IPV4Address = IPV4Address_member->value.GetString();
    const Value::ConstMemberIterator LastStateTransitionTime_member = obj.FindMember("LastStateTransitionTime");
    if (LastStateTransitionTime_member != obj.MemberEnd() && !LastStateTransitionTime_member->value.IsNull()) LastStateTransitionTime = readDatetime(LastStateTransitionTime_member->value);
    const Value::ConstMemberIterator Ports_member = obj.FindMember("Ports");
    if (Ports_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Ports_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Ports.push_back(Port(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator ServerId_member = obj.FindMember("ServerId");
    if (ServerId_member != obj.MemberEnd() && !ServerId_member->value.IsNull()) ServerId = ServerId_member->value.GetString();
    const Value::ConstMemberIterator SessionId_member = obj.FindMember("SessionId");
    if (SessionId_member != obj.MemberEnd() && !SessionId_member->value.IsNull()) SessionId = SessionId_member->value.GetString();
    const Value::ConstMemberIterator State_member = obj.FindMember("State");
    if (State_member != obj.MemberEnd() && !State_member->value.IsNull()) State = State_member->value.GetString();
    const Value::ConstMemberIterator VmId_member = obj.FindMember("VmId");
    if (VmId_member != obj.MemberEnd() && !VmId_member->value.IsNull()) VmId = VmId_member->value.GetString();

    return true;
}

GetRemoteLoginEndpointRequest::~GetRemoteLoginEndpointRequest()
{

}

void GetRemoteLoginEndpointRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    writer.String("Region"); writeAzureRegionEnumJSON(Region, writer);
    writer.String("VmId"); writer.String(VmId.c_str());
    writer.EndObject();
}

bool GetRemoteLoginEndpointRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator VmId_member = obj.FindMember("VmId");
    if (VmId_member != obj.MemberEnd() && !VmId_member->value.IsNull()) VmId = VmId_member->value.GetString();

    return true;
}

GetRemoteLoginEndpointResponse::~GetRemoteLoginEndpointResponse()
{

}

void GetRemoteLoginEndpointResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (IPV4Address.length() > 0) { writer.String("IPV4Address"); writer.String(IPV4Address.c_str()); }
    writer.String("Port"); writer.Int(Port);
    writer.EndObject();
}

bool GetRemoteLoginEndpointResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator IPV4Address_member = obj.FindMember("IPV4Address");
    if (IPV4Address_member != obj.MemberEnd() && !IPV4Address_member->value.IsNull()) IPV4Address = IPV4Address_member->value.GetString();
    const Value::ConstMemberIterator Port_member = obj.FindMember("Port");
    if (Port_member != obj.MemberEnd() && !Port_member->value.IsNull()) Port = Port_member->value.GetInt();

    return true;
}

GetTitleEnabledForMultiplayerServersStatusRequest::~GetTitleEnabledForMultiplayerServersStatusRequest()
{

}

void GetTitleEnabledForMultiplayerServersStatusRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool GetTitleEnabledForMultiplayerServersStatusRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

GetTitleEnabledForMultiplayerServersStatusResponse::~GetTitleEnabledForMultiplayerServersStatusResponse()
{

}

void GetTitleEnabledForMultiplayerServersStatusResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Status.notNull()) { writer.String("Status"); writeTitleMultiplayerServerEnabledStatusEnumJSON(Status, writer); }
    writer.EndObject();
}

bool GetTitleEnabledForMultiplayerServersStatusResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
    if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTitleMultiplayerServerEnabledStatusFromValue(Status_member->value);

    return true;
}

ListAssetSummariesRequest::~ListAssetSummariesRequest()
{

}

void ListAssetSummariesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PageSize.notNull()) { writer.String("PageSize"); writer.Int(PageSize); }
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListAssetSummariesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListAssetSummariesResponse::~ListAssetSummariesResponse()
{

}

void ListAssetSummariesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!AssetSummaries.empty()) {
        writer.String("AssetSummaries");
        writer.StartArray();
        for (std::list<AssetSummary>::iterator iter = AssetSummaries.begin(); iter != AssetSummaries.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.String("PageSize"); writer.Int(PageSize);
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListAssetSummariesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator AssetSummaries_member = obj.FindMember("AssetSummaries");
    if (AssetSummaries_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = AssetSummaries_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            AssetSummaries.push_back(AssetSummary(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListBuildSummariesRequest::~ListBuildSummariesRequest()
{

}

void ListBuildSummariesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PageSize.notNull()) { writer.String("PageSize"); writer.Int(PageSize); }
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListBuildSummariesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListBuildSummariesResponse::~ListBuildSummariesResponse()
{

}

void ListBuildSummariesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!BuildSummaries.empty()) {
        writer.String("BuildSummaries");
        writer.StartArray();
        for (std::list<BuildSummary>::iterator iter = BuildSummaries.begin(); iter != BuildSummaries.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.String("PageSize"); writer.Int(PageSize);
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListBuildSummariesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildSummaries_member = obj.FindMember("BuildSummaries");
    if (BuildSummaries_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BuildSummaries_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BuildSummaries.push_back(BuildSummary(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListCertificateSummariesRequest::~ListCertificateSummariesRequest()
{

}

void ListCertificateSummariesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PageSize.notNull()) { writer.String("PageSize"); writer.Int(PageSize); }
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListCertificateSummariesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListCertificateSummariesResponse::~ListCertificateSummariesResponse()
{

}

void ListCertificateSummariesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!CertificateSummaries.empty()) {
        writer.String("CertificateSummaries");
        writer.StartArray();
        for (std::list<CertificateSummary>::iterator iter = CertificateSummaries.begin(); iter != CertificateSummaries.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.String("PageSize"); writer.Int(PageSize);
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListCertificateSummariesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator CertificateSummaries_member = obj.FindMember("CertificateSummaries");
    if (CertificateSummaries_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = CertificateSummaries_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            CertificateSummaries.push_back(CertificateSummary(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListContainerImagesRequest::~ListContainerImagesRequest()
{

}

void ListContainerImagesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (PageSize.notNull()) { writer.String("PageSize"); writer.Int(PageSize); }
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListContainerImagesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListContainerImagesResponse::~ListContainerImagesResponse()
{

}

void ListContainerImagesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Images.empty()) {
        writer.String("Images");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = Images.begin(); iter != Images.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("PageSize"); writer.Int(PageSize);
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListContainerImagesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Images_member = obj.FindMember("Images");
    if (Images_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Images_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Images.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListContainerImageTagsRequest::~ListContainerImageTagsRequest()
{

}

void ListContainerImageTagsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (ImageName.length() > 0) { writer.String("ImageName"); writer.String(ImageName.c_str()); }
    writer.EndObject();
}

bool ListContainerImageTagsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ImageName_member = obj.FindMember("ImageName");
    if (ImageName_member != obj.MemberEnd() && !ImageName_member->value.IsNull()) ImageName = ImageName_member->value.GetString();

    return true;
}

ListContainerImageTagsResponse::~ListContainerImageTagsResponse()
{

}

void ListContainerImageTagsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!Tags.empty()) {
        writer.String("Tags");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListContainerImageTagsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
    if (Tags_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Tags_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Tags.push_back(memberList[i].GetString());
        }
    }

    return true;
}

ListMultiplayerServersRequest::~ListMultiplayerServersRequest()
{

}

void ListMultiplayerServersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    if (PageSize.notNull()) { writer.String("PageSize"); writer.Int(PageSize); }
    writer.String("Region"); writeAzureRegionEnumJSON(Region, writer);
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListMultiplayerServersRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

MultiplayerServerSummary::~MultiplayerServerSummary()
{

}

void MultiplayerServerSummary::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!ConnectedPlayers.empty()) {
        writer.String("ConnectedPlayers");
        writer.StartArray();
        for (std::list<ConnectedPlayer>::iterator iter = ConnectedPlayers.begin(); iter != ConnectedPlayers.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (LastStateTransitionTime.notNull()) { writer.String("LastStateTransitionTime"); writeDatetime(LastStateTransitionTime, writer); }
    if (Region.notNull()) { writer.String("Region"); writeAzureRegionEnumJSON(Region, writer); }
    if (ServerId.length() > 0) { writer.String("ServerId"); writer.String(ServerId.c_str()); }
    if (SessionId.length() > 0) { writer.String("SessionId"); writer.String(SessionId.c_str()); }
    if (State.length() > 0) { writer.String("State"); writer.String(State.c_str()); }
    if (VmId.length() > 0) { writer.String("VmId"); writer.String(VmId.c_str()); }
    writer.EndObject();
}

bool MultiplayerServerSummary::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ConnectedPlayers_member = obj.FindMember("ConnectedPlayers");
    if (ConnectedPlayers_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ConnectedPlayers_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ConnectedPlayers.push_back(ConnectedPlayer(memberList[i]));
        }
    }
    const Value::ConstMemberIterator LastStateTransitionTime_member = obj.FindMember("LastStateTransitionTime");
    if (LastStateTransitionTime_member != obj.MemberEnd() && !LastStateTransitionTime_member->value.IsNull()) LastStateTransitionTime = readDatetime(LastStateTransitionTime_member->value);
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator ServerId_member = obj.FindMember("ServerId");
    if (ServerId_member != obj.MemberEnd() && !ServerId_member->value.IsNull()) ServerId = ServerId_member->value.GetString();
    const Value::ConstMemberIterator SessionId_member = obj.FindMember("SessionId");
    if (SessionId_member != obj.MemberEnd() && !SessionId_member->value.IsNull()) SessionId = SessionId_member->value.GetString();
    const Value::ConstMemberIterator State_member = obj.FindMember("State");
    if (State_member != obj.MemberEnd() && !State_member->value.IsNull()) State = State_member->value.GetString();
    const Value::ConstMemberIterator VmId_member = obj.FindMember("VmId");
    if (VmId_member != obj.MemberEnd() && !VmId_member->value.IsNull()) VmId = VmId_member->value.GetString();

    return true;
}

ListMultiplayerServersResponse::~ListMultiplayerServersResponse()
{

}

void ListMultiplayerServersResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!MultiplayerServerSummaries.empty()) {
        writer.String("MultiplayerServerSummaries");
        writer.StartArray();
        for (std::list<MultiplayerServerSummary>::iterator iter = MultiplayerServerSummaries.begin(); iter != MultiplayerServerSummaries.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.String("PageSize"); writer.Int(PageSize);
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListMultiplayerServersResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator MultiplayerServerSummaries_member = obj.FindMember("MultiplayerServerSummaries");
    if (MultiplayerServerSummaries_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = MultiplayerServerSummaries_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            MultiplayerServerSummaries.push_back(MultiplayerServerSummary(memberList[i]));
        }
    }
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListQosServersRequest::~ListQosServersRequest()
{

}

void ListQosServersRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool ListQosServersRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

QosServer::~QosServer()
{

}

void QosServer::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (Region.notNull()) { writer.String("Region"); writeAzureRegionEnumJSON(Region, writer); }
    if (ServerUrl.length() > 0) { writer.String("ServerUrl"); writer.String(ServerUrl.c_str()); }
    writer.EndObject();
}

bool QosServer::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator ServerUrl_member = obj.FindMember("ServerUrl");
    if (ServerUrl_member != obj.MemberEnd() && !ServerUrl_member->value.IsNull()) ServerUrl = ServerUrl_member->value.GetString();

    return true;
}

ListQosServersResponse::~ListQosServersResponse()
{

}

void ListQosServersResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("PageSize"); writer.Int(PageSize);
    if (!QosServers.empty()) {
        writer.String("QosServers");
        writer.StartArray();
        for (std::list<QosServer>::iterator iter = QosServers.begin(); iter != QosServers.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListQosServersResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator QosServers_member = obj.FindMember("QosServers");
    if (QosServers_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = QosServers_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            QosServers.push_back(QosServer(memberList[i]));
        }
    }
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

ListVirtualMachineSummariesRequest::~ListVirtualMachineSummariesRequest()
{

}

void ListVirtualMachineSummariesRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    if (PageSize.notNull()) { writer.String("PageSize"); writer.Int(PageSize); }
    writer.String("Region"); writeAzureRegionEnumJSON(Region, writer);
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    writer.EndObject();
}

bool ListVirtualMachineSummariesRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();

    return true;
}

VirtualMachineSummary::~VirtualMachineSummary()
{

}

void VirtualMachineSummary::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (HealthStatus.length() > 0) { writer.String("HealthStatus"); writer.String(HealthStatus.c_str()); }
    if (State.length() > 0) { writer.String("State"); writer.String(State.c_str()); }
    if (VmId.length() > 0) { writer.String("VmId"); writer.String(VmId.c_str()); }
    writer.EndObject();
}

bool VirtualMachineSummary::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator HealthStatus_member = obj.FindMember("HealthStatus");
    if (HealthStatus_member != obj.MemberEnd() && !HealthStatus_member->value.IsNull()) HealthStatus = HealthStatus_member->value.GetString();
    const Value::ConstMemberIterator State_member = obj.FindMember("State");
    if (State_member != obj.MemberEnd() && !State_member->value.IsNull()) State = State_member->value.GetString();
    const Value::ConstMemberIterator VmId_member = obj.FindMember("VmId");
    if (VmId_member != obj.MemberEnd() && !VmId_member->value.IsNull()) VmId = VmId_member->value.GetString();

    return true;
}

ListVirtualMachineSummariesResponse::~ListVirtualMachineSummariesResponse()
{

}

void ListVirtualMachineSummariesResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("PageSize"); writer.Int(PageSize);
    if (SkipToken.length() > 0) { writer.String("SkipToken"); writer.String(SkipToken.c_str()); }
    if (!VirtualMachines.empty()) {
        writer.String("VirtualMachines");
        writer.StartArray();
        for (std::list<VirtualMachineSummary>::iterator iter = VirtualMachines.begin(); iter != VirtualMachines.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    writer.EndObject();
}

bool ListVirtualMachineSummariesResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator PageSize_member = obj.FindMember("PageSize");
    if (PageSize_member != obj.MemberEnd() && !PageSize_member->value.IsNull()) PageSize = PageSize_member->value.GetInt();
    const Value::ConstMemberIterator SkipToken_member = obj.FindMember("SkipToken");
    if (SkipToken_member != obj.MemberEnd() && !SkipToken_member->value.IsNull()) SkipToken = SkipToken_member->value.GetString();
    const Value::ConstMemberIterator VirtualMachines_member = obj.FindMember("VirtualMachines");
    if (VirtualMachines_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = VirtualMachines_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            VirtualMachines.push_back(VirtualMachineSummary(memberList[i]));
        }
    }

    return true;
}

RequestMultiplayerServerRequest::~RequestMultiplayerServerRequest()
{

}

void RequestMultiplayerServerRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    if (!InitialPlayers.empty()) {
        writer.String("InitialPlayers");
        writer.StartArray();
        for (std::list<std::string>::iterator iter = InitialPlayers.begin(); iter != InitialPlayers.end(); iter++) {
            writer.String(iter->c_str());
        }
        writer.EndArray();
    }
    writer.String("PreferredRegions");
    writer.StartArray();
    for (std::list<AzureRegion>::iterator iter = PreferredRegions.begin(); iter != PreferredRegions.end(); iter++) {
        writeAzureRegionEnumJSON(*iter, writer);
    }
    writer.EndArray();
    if (SessionCookie.length() > 0) { writer.String("SessionCookie"); writer.String(SessionCookie.c_str()); }
    writer.String("SessionId"); writer.String(SessionId.c_str());
    writer.EndObject();
}

bool RequestMultiplayerServerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator InitialPlayers_member = obj.FindMember("InitialPlayers");
    if (InitialPlayers_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = InitialPlayers_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            InitialPlayers.push_back(memberList[i].GetString());
        }
    }
    const Value::ConstMemberIterator PreferredRegions_member = obj.FindMember("PreferredRegions");
    if (PreferredRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = PreferredRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            PreferredRegions.push_back(readAzureRegionFromValue(memberList[i]));
        }
    }
    const Value::ConstMemberIterator SessionCookie_member = obj.FindMember("SessionCookie");
    if (SessionCookie_member != obj.MemberEnd() && !SessionCookie_member->value.IsNull()) SessionCookie = SessionCookie_member->value.GetString();
    const Value::ConstMemberIterator SessionId_member = obj.FindMember("SessionId");
    if (SessionId_member != obj.MemberEnd() && !SessionId_member->value.IsNull()) SessionId = SessionId_member->value.GetString();

    return true;
}

RequestMultiplayerServerResponse::~RequestMultiplayerServerResponse()
{

}

void RequestMultiplayerServerResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (!ConnectedPlayers.empty()) {
        writer.String("ConnectedPlayers");
        writer.StartArray();
        for (std::list<ConnectedPlayer>::iterator iter = ConnectedPlayers.begin(); iter != ConnectedPlayers.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (FQDN.length() > 0) { writer.String("FQDN"); writer.String(FQDN.c_str()); }
    if (IPV4Address.length() > 0) { writer.String("IPV4Address"); writer.String(IPV4Address.c_str()); }
    if (LastStateTransitionTime.notNull()) { writer.String("LastStateTransitionTime"); writeDatetime(LastStateTransitionTime, writer); }
    if (!Ports.empty()) {
        writer.String("Ports");
        writer.StartArray();
        for (std::list<Port>::iterator iter = Ports.begin(); iter != Ports.end(); iter++) {
            iter->writeJSON(writer);
        }
        writer.EndArray();
    }
    if (Region.notNull()) { writer.String("Region"); writeAzureRegionEnumJSON(Region, writer); }
    if (ServerId.length() > 0) { writer.String("ServerId"); writer.String(ServerId.c_str()); }
    if (SessionId.length() > 0) { writer.String("SessionId"); writer.String(SessionId.c_str()); }
    if (State.length() > 0) { writer.String("State"); writer.String(State.c_str()); }
    if (VmId.length() > 0) { writer.String("VmId"); writer.String(VmId.c_str()); }
    writer.EndObject();
}

bool RequestMultiplayerServerResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator ConnectedPlayers_member = obj.FindMember("ConnectedPlayers");
    if (ConnectedPlayers_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = ConnectedPlayers_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            ConnectedPlayers.push_back(ConnectedPlayer(memberList[i]));
        }
    }
    const Value::ConstMemberIterator FQDN_member = obj.FindMember("FQDN");
    if (FQDN_member != obj.MemberEnd() && !FQDN_member->value.IsNull()) FQDN = FQDN_member->value.GetString();
    const Value::ConstMemberIterator IPV4Address_member = obj.FindMember("IPV4Address");
    if (IPV4Address_member != obj.MemberEnd() && !IPV4Address_member->value.IsNull()) IPV4Address = IPV4Address_member->value.GetString();
    const Value::ConstMemberIterator LastStateTransitionTime_member = obj.FindMember("LastStateTransitionTime");
    if (LastStateTransitionTime_member != obj.MemberEnd() && !LastStateTransitionTime_member->value.IsNull()) LastStateTransitionTime = readDatetime(LastStateTransitionTime_member->value);
    const Value::ConstMemberIterator Ports_member = obj.FindMember("Ports");
    if (Ports_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = Ports_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            Ports.push_back(Port(memberList[i]));
        }
    }
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator ServerId_member = obj.FindMember("ServerId");
    if (ServerId_member != obj.MemberEnd() && !ServerId_member->value.IsNull()) ServerId = ServerId_member->value.GetString();
    const Value::ConstMemberIterator SessionId_member = obj.FindMember("SessionId");
    if (SessionId_member != obj.MemberEnd() && !SessionId_member->value.IsNull()) SessionId = SessionId_member->value.GetString();
    const Value::ConstMemberIterator State_member = obj.FindMember("State");
    if (State_member != obj.MemberEnd() && !State_member->value.IsNull()) State = State_member->value.GetString();
    const Value::ConstMemberIterator VmId_member = obj.FindMember("VmId");
    if (VmId_member != obj.MemberEnd() && !VmId_member->value.IsNull()) VmId = VmId_member->value.GetString();

    return true;
}

RolloverContainerRegistryCredentialsRequest::~RolloverContainerRegistryCredentialsRequest()
{

}

void RolloverContainerRegistryCredentialsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.EndObject();
}

bool RolloverContainerRegistryCredentialsRequest::readFromValue(const rapidjson::Value& obj)
{

    return true;
}

RolloverContainerRegistryCredentialsResponse::~RolloverContainerRegistryCredentialsResponse()
{

}

void RolloverContainerRegistryCredentialsResponse::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    if (DnsName.length() > 0) { writer.String("DnsName"); writer.String(DnsName.c_str()); }
    if (Password.length() > 0) { writer.String("Password"); writer.String(Password.c_str()); }
    if (Username.length() > 0) { writer.String("Username"); writer.String(Username.c_str()); }
    writer.EndObject();
}

bool RolloverContainerRegistryCredentialsResponse::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator DnsName_member = obj.FindMember("DnsName");
    if (DnsName_member != obj.MemberEnd() && !DnsName_member->value.IsNull()) DnsName = DnsName_member->value.GetString();
    const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
    if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
    const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
    if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

    return true;
}

ShutdownMultiplayerServerRequest::~ShutdownMultiplayerServerRequest()
{

}

void ShutdownMultiplayerServerRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    writer.String("Region"); writeAzureRegionEnumJSON(Region, writer);
    writer.String("SessionId"); writer.String(SessionId.c_str());
    writer.EndObject();
}

bool ShutdownMultiplayerServerRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
    if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) Region = readAzureRegionFromValue(Region_member->value);
    const Value::ConstMemberIterator SessionId_member = obj.FindMember("SessionId");
    if (SessionId_member != obj.MemberEnd() && !SessionId_member->value.IsNull()) SessionId = SessionId_member->value.GetString();

    return true;
}

UpdateBuildRegionsRequest::~UpdateBuildRegionsRequest()
{

}

void UpdateBuildRegionsRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("BuildId"); writer.String(BuildId.c_str());
    writer.String("BuildRegions");
    writer.StartArray();
    for (std::list<BuildRegionParams>::iterator iter = BuildRegions.begin(); iter != BuildRegions.end(); iter++) {
        iter->writeJSON(writer);
    }
    writer.EndArray();
    writer.EndObject();
}

bool UpdateBuildRegionsRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
    if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
    const Value::ConstMemberIterator BuildRegions_member = obj.FindMember("BuildRegions");
    if (BuildRegions_member != obj.MemberEnd()) {
        const rapidjson::Value& memberList = BuildRegions_member->value;
        for (SizeType i = 0; i < memberList.Size(); i++) {
            BuildRegions.push_back(BuildRegionParams(memberList[i]));
        }
    }

    return true;
}

UploadCertificateRequest::~UploadCertificateRequest()
{

}

void UploadCertificateRequest::writeJSON(PFStringJsonWriter& writer)
{
    writer.StartObject();
    writer.String("GameCertificate"); GameCertificate.writeJSON(writer);
    writer.EndObject();
}

bool UploadCertificateRequest::readFromValue(const rapidjson::Value& obj)
{
    const Value::ConstMemberIterator GameCertificate_member = obj.FindMember("GameCertificate");
    if (GameCertificate_member != obj.MemberEnd() && !GameCertificate_member->value.IsNull()) GameCertificate = Certificate(GameCertificate_member->value);

    return true;
}

