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
		PlayFabErrorBuildNotFound = 1031,
		PlayFabErrorPlayerNotInGame = 1032,
		PlayFabErrorInvalidTicket = 1033,
		PlayFabErrorInvalidDeveloper = 1034,
		PlayFabErrorInvalidOrderInfo = 1035,
		PlayFabErrorRegistrationIncomplete = 1036,
		PlayFabErrorInvalidPlatform = 1037,
		PlayFabErrorUnknownError = 1038,
		PlayFabErrorSteamApplicationNotOwned = 1039,
		PlayFabErrorWrongSteamAccount = 1040,
		PlayFabErrorTitleNotActivated = 1041,
		PlayFabErrorRegistrationSessionNotFound = 1042,
		PlayFabErrorNoSuchMod = 1043,
		PlayFabErrorFileNotFound = 1044,
		PlayFabErrorDuplicateEmail = 1045,
		PlayFabErrorItemNotFound = 1046,
		PlayFabErrorItemNotOwned = 1047,
		PlayFabErrorItemNotRecycleable = 1048,
		PlayFabErrorItemNotAffordable = 1049,
		PlayFabErrorInvalidVirtualCurrency = 1050,
		PlayFabErrorWrongVirtualCurrency = 1051,
		PlayFabErrorWrongPrice = 1052,
		PlayFabErrorNonPositiveValue = 1053,
		PlayFabErrorInvalidRegion = 1054,
		PlayFabErrorRegionAtCapacity = 1055,
		PlayFabErrorServerFailedToStart = 1056,
		PlayFabErrorNameNotAvailable = 1057,
		PlayFabErrorInsufficientFunds = 1058,
		PlayFabErrorInvalidDeviceID = 1059,
		PlayFabErrorInvalidPushNotificationToken = 1060,
		PlayFabErrorNoRemainingUses = 1061,
		PlayFabErrorInvalidPaymentProvider = 1062,
		PlayFabErrorPurchaseInitializationFailure = 1063,
		PlayFabErrorDuplicateUsername = 1064,
		PlayFabErrorInvalidBuyerInfo = 1065,
		PlayFabErrorNoGameModeParamsSet = 1066,
		PlayFabErrorTooLong = 1067,
		PlayFabErrorReservedWord = 1068,
		PlayFabErrorInvalidBodyValue = 1069,
		PlayFabErrorInvalidRequest = 1070,
		PlayFabErrorReservedEvent = 1071,
		PlayFabErrorInvalidUserStatistics = 1072
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