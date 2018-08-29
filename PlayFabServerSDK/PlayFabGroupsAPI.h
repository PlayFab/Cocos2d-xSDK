#ifndef PLAYFAB_GROUPSAPI_H_
#define PLAYFAB_GROUPSAPI_H_

#include "IHttpRequester.h"
#include "PlayFabError.h"
#include "PlayFabGroupsDataModels.h"
#include <string>

namespace PlayFab
{
    class PlayFabGroupsAPI
    {
    public:
        template<typename ResType> using ProcessApiCallback = std::function<void(const ResType& result, void* userData)>;

        // ------------ Generated API calls
        static void AcceptGroupApplication(GroupsModels::AcceptGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AcceptGroupInvitation(GroupsModels::AcceptGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void AddMembers(GroupsModels::AddMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ApplyToGroup(GroupsModels::ApplyToGroupRequest& request, ProcessApiCallback<GroupsModels::ApplyToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void BlockEntity(GroupsModels::BlockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ChangeMemberRole(GroupsModels::ChangeMemberRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateGroup(GroupsModels::CreateGroupRequest& request, ProcessApiCallback<GroupsModels::CreateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void CreateRole(GroupsModels::CreateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::CreateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteGroup(GroupsModels::DeleteGroupRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void DeleteRole(GroupsModels::DeleteRoleRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void GetGroup(GroupsModels::GetGroupRequest& request, ProcessApiCallback<GroupsModels::GetGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void InviteToGroup(GroupsModels::InviteToGroupRequest& request, ProcessApiCallback<GroupsModels::InviteToGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void IsMember(GroupsModels::IsMemberRequest& request, ProcessApiCallback<GroupsModels::IsMemberResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListGroupApplications(GroupsModels::ListGroupApplicationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupApplicationsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListGroupBlocks(GroupsModels::ListGroupBlocksRequest& request, ProcessApiCallback<GroupsModels::ListGroupBlocksResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListGroupInvitations(GroupsModels::ListGroupInvitationsRequest& request, ProcessApiCallback<GroupsModels::ListGroupInvitationsResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListGroupMembers(GroupsModels::ListGroupMembersRequest& request, ProcessApiCallback<GroupsModels::ListGroupMembersResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListMembership(GroupsModels::ListMembershipRequest& request, ProcessApiCallback<GroupsModels::ListMembershipResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void ListMembershipOpportunities(GroupsModels::ListMembershipOpportunitiesRequest& request, ProcessApiCallback<GroupsModels::ListMembershipOpportunitiesResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveGroupApplication(GroupsModels::RemoveGroupApplicationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveGroupInvitation(GroupsModels::RemoveGroupInvitationRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void RemoveMembers(GroupsModels::RemoveMembersRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UnblockEntity(GroupsModels::UnblockEntityRequest& request, ProcessApiCallback<GroupsModels::EmptyResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateGroup(GroupsModels::UpdateGroupRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);
        static void UpdateRole(GroupsModels::UpdateGroupRoleRequest& request, ProcessApiCallback<GroupsModels::UpdateGroupRoleResponse> callback, ErrorCallback errorCallback = nullptr, void* userData = nullptr);

    private:
        // ------------ Private constructor, to enforce all-static class
        PlayFabGroupsAPI();

        // ------------ Generated result handlers
        static void OnAcceptGroupApplicationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAcceptGroupInvitationResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnAddMembersResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnApplyToGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnBlockEntityResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnChangeMemberRoleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnCreateRoleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnDeleteRoleResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnGetGroupResult(int httpStatus, HttpRequest* request, void* userData);
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
        static void OnUnblockEntityResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateGroupResult(int httpStatus, HttpRequest* request, void* userData);
        static void OnUpdateRoleResult(int httpStatus, HttpRequest* request, void* userData);
    };
};
#endif
