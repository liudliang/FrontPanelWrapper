//
// Created by surajcha on 2/8/18.
//

#ifndef FRONTPANELWRAPPER_FRONTPANELWRAPPER_H
#define FRONTPANELWRAPPER_FRONTPANELWRAPPER_H

#include <iostream>
#include <okFrontPanelDLL.h>

int fpLibraryCheck();
int fpErrorParser(ok_ErrorCode fp_ErrorCode);
int fpErrorParser(ok_ErrorCode fp_ErrorCode, std::string userMSG);

class FrontPanelWrapper {
private:

public:

};


#endif //FRONTPANELWRAPPER_FRONTPANELWRAPPER_H

/* **********************************************************
 * This is a list of the FrontPanel error codes for reference
 * **********************************************************

typedef enum {
    ok_NoError                    = 0,
    ok_Failed                     = -1,
    ok_Timeout                    = -2,
    ok_DoneNotHigh                = -3,
    ok_TransferError              = -4,
    ok_CommunicationError         = -5,
    ok_InvalidBitstream           = -6,
    ok_FileError                  = -7,
    ok_DeviceNotOpen              = -8,
    ok_InvalidEndpoint            = -9,
    ok_InvalidBlockSize           = -10,
    ok_I2CRestrictedAddress       = -11,
    ok_I2CBitError                = -12,
    ok_I2CNack                    = -13,
    ok_I2CUnknownStatus           = -14,
    ok_UnsupportedFeature         = -15,
    ok_FIFOUnderflow              = -16,
    ok_FIFOOverflow               = -17,
    ok_DataAlignmentError         = -18,
    ok_InvalidResetProfile        = -19,
    ok_InvalidParameter           = -20
} ok_ErrorCode;
*/

/* *************************************************************
 * This is a list of the FrontPanel board ID codes for reference
 * *************************************************************

typedef enum {
    ok_brdUnknown = 0,
    ok_brdXEM3001v1 = 1,
    ok_brdXEM3001v2 = 2,
    ok_brdXEM3010 = 3,
    ok_brdXEM3005 = 4,
    ok_brdXEM3001CL = 5,
    ok_brdXEM3020 = 6,
    ok_brdXEM3050 = 7,
    ok_brdXEM9002 = 8,
    ok_brdXEM3001RB = 9,
    ok_brdXEM5010 = 10,
    ok_brdXEM6110LX45 = 11,
    ok_brdXEM6110LX150 = 15,
    ok_brdXEM6001 = 12,
    ok_brdXEM6010LX45 = 13,
    ok_brdXEM6010LX150 = 14,
    ok_brdXEM6006LX9 = 16,
    ok_brdXEM6006LX16 = 17,
    ok_brdXEM6006LX25 = 18,
    ok_brdXEM5010LX110 = 19,
    ok_brdZEM4310=20,
    ok_brdXEM6310LX45=21,
    ok_brdXEM6310LX150=22,
    ok_brdXEM6110v2LX45=23,
    ok_brdXEM6110v2LX150=24,
    ok_brdXEM6002LX9=25,
    ok_brdXEM6310MTLX45T=26,
    ok_brdXEM6320LX130T=27,
    ok_brdXEM7350K70T=28,
    ok_brdXEM7350K160T=29,
    ok_brdXEM7350K410T=30,
    ok_brdXEM6310MTLX150T=31,
    ok_brdZEM5305A2 = 32,
    ok_brdZEM5305A7 = 33,
    ok_brdXEM7001A15 = 34,
    ok_brdXEM7001A35 = 35,
    ok_brdXEM7360K160T = 36,
    ok_brdXEM7360K410T = 37,
    ok_brdZEM5310A4 = 38,
    ok_brdZEM5310A7 = 39,
    ok_brdZEM5370A5 = 40,
    ok_brdXEM7010A50 = 41,
    ok_brdXEM7010A200 = 42,
    ok_brdXEM7310A75 = 43,
    ok_brdXEM7310A200 = 44
} ok_BoardModel;
*/