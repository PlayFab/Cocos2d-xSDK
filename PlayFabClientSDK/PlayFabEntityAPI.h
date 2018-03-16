#ifndef PLAYFAB_ENTITYAPI_H_
#define PLAYFAB_ENTITYAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabEntityDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabEntityAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void AbortFileUploads(EntityModels::AbortFileUploadsRequest& request, ProcessApiCallback<EntityModels::AbortFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AcceptGroupApplication(EntityModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AcceptGroupInvitation(EntityModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddMembers(EntityModels::AddMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ApplyToGroup(EntityModels::ApplyToGroupRequest& request, ProcessApiCallback<EntityModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void BlockEntity(EntityModels::BlockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ChangeMemberRole(EntityModels::ChangeMemberRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateGroup(EntityModels::CreateGroupRequest& request, ProcessApiCallback<EntityModels::CreateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateRole(EntityModels::CreateGroupRoleRequest& request, ProcessApiCallback<EntityModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteFiles(EntityModels::DeleteFilesRequest& request, ProcessApiCallback<EntityModels::DeleteFilesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteGroup(EntityModels::DeleteGroupRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteRole(EntityModels::DeleteRoleRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void FinalizeFileUploads(EntityModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<EntityModels::FinalizeFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetEntityToken(EntityModels::GetEntityTokenRequest& request, ProcessApiCallback<EntityModels::GetEntityTokenResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetFiles(EntityModels::GetFilesRequest& request, ProcessApiCallback<EntityModels::GetFilesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetGlobalPolicy(ProcessApiCallback<EntityModels::GetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetGroup(EntityModels::GetGroupRequest& request, ProcessApiCallback<EntityModels::GetGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetObjects(EntityModels::GetObjectsRequest& request, ProcessApiCallback<EntityModels::GetObjectsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetProfile(EntityModels::GetEntityProfileRequest& request, ProcessApiCallback<EntityModels::GetEntityProfileResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void InitiateFileUploads(EntityModels::InitiateFileUploadsRequest& request, ProcessApiCallback<EntityModels::InitiateFileUploadsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void InviteToGroup(EntityModels::InviteToGroupRequest& request, ProcessApiCallback<EntityModels::InviteToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void IsMember(EntityModels::IsMemberRequest& request, ProcessApiCallback<EntityModels::IsMemberResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListGroupApplications(EntityModels::ListGroupApplicationsRequest& request, ProcessApiCallback<EntityModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListGroupBlocks(EntityModels::ListGroupBlocksRequest& request, ProcessApiCallback<EntityModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListGroupInvitations(EntityModels::ListGroupInvitationsRequest& request, ProcessApiCallback<EntityModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListGroupMembers(EntityModels::ListGroupMembersRequest& request, ProcessApiCallback<EntityModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListMembership(EntityModels::ListMembershipRequest& request, ProcessApiCallback<EntityModels::ListMembershipResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListMembershipOpportunities(EntityModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<EntityModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveGroupApplication(EntityModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveGroupInvitation(EntityModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveMembers(EntityModels::RemoveMembersRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetGlobalPolicy(EntityModels::SetGlobalPolicyRequest& request, ProcessApiCallback<EntityModels::SetGlobalPolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetObjects(EntityModels::SetObjectsRequest& request, ProcessApiCallback<EntityModels::SetObjectsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void SetProfilePolicy(EntityModels::SetEntityProfilePolicyRequest& request, ProcessApiCallback<EntityModels::SetEntityProfilePolicyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnblockEntity(EntityModels::UnblockEntityRequest& request, ProcessApiCallback<EntityModels::EmptyResult> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateGroup(EntityModels::UpdateGroupRequest& request, ProcessApiCallback<EntityModels::UpdateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateRole(EntityModels::UpdateGroupRoleRequest& request, ProcessApiCallback<EntityModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabEntityAPI();

        // ------------ Generated result handlers
        static void OnAbortFileUploadsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAcceptGroupApplicationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAcceptGroupInvitationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddMembersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnApplyToGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnBlockEntityResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnChangeMemberRoleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateRoleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteFilesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteRoleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnFinalizeFileUploadsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetEntityTokenResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetFilesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetGlobalPolicyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetObjectsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetProfileResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnInitiateFileUploadsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnInviteToGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnIsMemberResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListGroupApplicationsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListGroupBlocksResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListGroupInvitationsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListGroupMembersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListMembershipResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnListMembershipOpportunitiesResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveGroupApplicationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveGroupInvitationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnRemoveMembersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetGlobalPolicyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetObjectsResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnSetProfilePolicyResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUnblockEntityResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateRoleResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
