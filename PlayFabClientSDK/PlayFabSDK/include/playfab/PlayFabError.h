#ifndef PLAYFAB_PLAYFABERROR_H_
#define PLAYFAB_PLAYFABERROR_H_

#include <string>
#include <map>

namespace PlayFab
{

    enum PlayFabErrorCode
    {
        PlayFabErrorHostnameNotFound=1,
        PlayFabErrorConnectionTimeout,
        PlayFabErrorConnectionRefused,
        PlayFabErrorSocketError,
		PlayFabErrorSuccess = 0,
		PlayFabErrorInvalidParams = 1000,
		PlayFabErrorAccountNotFound = 1001,
		PlayFabErrorAccountBanned = 1002,
		PlayFabErrorInvalidUsernameOrPassword = 1003,
		PlayFabErrorInvalidTitleId = 1004,
		PlayFabErrorInvalidEmailAddress = 1005,
		PlayFabErrorEmailAddressNotAvailable = 1006,
		PlayFabErrorInvalidUsername = 1007,
		PlayFabErrorInvalidPassword = 1008,
		PlayFabErrorUsernameNotAvailable = 1009,
		PlayFabErrorInvalidSteamTicket = 1010,
		PlayFabErrorAccountAlreadyLinked = 1011,
		PlayFabErrorLinkedAccountAlreadyClaimed = 1012,
		PlayFabErrorInvalidFacebookToken = 1013,
		PlayFabErrorAccountNotLinked = 1014,
		PlayFabErrorFailedByPaymentProvider = 1015,
		PlayFabErrorCouponCodeNotFound = 1016,
		PlayFabErrorInvalidContainerItem = 1017,
		PlayFabErrorContainerNotOwned = 1018,
		PlayFabErrorKeyNotOwned = 1019,
		PlayFabErrorInvalidItemIdInTable = 1020,
		PlayFabErrorInvalidReceipt = 1021,
		PlayFabErrorReceiptAlreadyUsed = 1022,
		PlayFabErrorReceiptCancelled = 1023,
		PlayFabErrorGameNotFound = 1024,
		PlayFabErrorGameModeNotFound = 1025,
		PlayFabErrorInvalidGoogleToken = 1026,
		PlayFabErrorUserIsNotPartOfDeveloper = 1027,
		PlayFabErrorInvalidTitleForDeveloper = 1028,
		PlayFabErrorTitleNameConflicts = 1029,
		PlayFabErrorUserisNotValid = 1030,
		PlayFabErrorValueAlreadyExists = 1031,
		PlayFabErrorBuildNotFound = 1032,
		PlayFabErrorPlayerNotInGame = 1033,
		PlayFabErrorInvalidTicket = 1034,
		PlayFabErrorInvalidDeveloper = 1035,
		PlayFabErrorInvalidOrderInfo = 1036,
		PlayFabErrorRegistrationIncomplete = 1037,
		PlayFabErrorInvalidPlatform = 1038,
		PlayFabErrorUnknownError = 1039,
		PlayFabErrorSteamApplicationNotOwned = 1040,
		PlayFabErrorWrongSteamAccount = 1041,
		PlayFabErrorTitleNotActivated = 1042,
		PlayFabErrorRegistrationSessionNotFound = 1043,
		PlayFabErrorNoSuchMod = 1044,
		PlayFabErrorFileNotFound = 1045,
		PlayFabErrorDuplicateEmail = 1046,
		PlayFabErrorItemNotFound = 1047,
		PlayFabErrorItemNotOwned = 1048,
		PlayFabErrorItemNotRecycleable = 1049,
		PlayFabErrorItemNotAffordable = 1050,
		PlayFabErrorInvalidVirtualCurrency = 1051,
		PlayFabErrorWrongVirtualCurrency = 1052,
		PlayFabErrorWrongPrice = 1053,
		PlayFabErrorNonPositiveValue = 1054,
		PlayFabErrorInvalidRegion = 1055,
		PlayFabErrorRegionAtCapacity = 1056,
		PlayFabErrorServerFailedToStart = 1057,
		PlayFabErrorNameNotAvailable = 1058,
		PlayFabErrorInsufficientFunds = 1059,
		PlayFabErrorInvalidDeviceID = 1060,
		PlayFabErrorInvalidPushNotificationToken = 1061,
		PlayFabErrorNoRemainingUses = 1062,
		PlayFabErrorInvalidPaymentProvider = 1063,
		PlayFabErrorPurchaseInitializationFailure = 1064,
		PlayFabErrorDuplicateUsername = 1065,
		PlayFabErrorInvalidBuyerInfo = 1066,
		PlayFabErrorNoGameModeParamsSet = 1067,
		PlayFabErrorBodyTooLarge = 1068,
		PlayFabErrorReservedWordInBody = 1069,
		PlayFabErrorInvalidTypeInBody = 1070,
		PlayFabErrorInvalidRequest = 1071,
		PlayFabErrorReservedEventName = 1072,
		PlayFabErrorInvalidUserStatistics = 1073,
		PlayFabErrorNotAuthenticated = 1074,
		PlayFabErrorStreamAlreadyExists = 1075,
		PlayFabErrorErrorCreatingStream = 1076,
		PlayFabErrorStreamNotFound = 1077,
		PlayFabErrorInvalidAccount = 1078,
		PlayFabErrorPurchaseDoesNotExist = 1080,
		PlayFabErrorInvalidPurchaseTransactionStatus = 1081,
		PlayFabErrorAPINotEnabledForGameClientAccess = 1082,
		PlayFabErrorNoPushNotificationARNForTitle = 1083,
		PlayFabErrorBuildAlreadyExists = 1084,
		PlayFabErrorBuildPackageDoesNotExist = 1085,
		PlayFabErrorBuildIsActive = 1086,
		PlayFabErrorCustomAnalyticsEventsNotEnabledForTitle = 1087,
		PlayFabErrorInvalidSharedGroupId = 1088,
		PlayFabErrorNotAuthorized = 1089,
		PlayFabErrorMissingTitleGoogleProperties = 1090
    };

    struct PlayFabError
    {
        int HttpCode;
        std::string HttpStatus;
        int ErrorCode;
        std::string ErrorName;
        std::string ErrorMessage;
        std::multimap< std::string, std::string > ErrorDetails;
    };


    typedef void(*ErrorCallback)(PlayFabError& error, void* userData);
}
#endif