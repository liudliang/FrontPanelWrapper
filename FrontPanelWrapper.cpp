//
// Created by surajcha on 2/8/18.
//

#include <iostream>
#include <okFrontPanelDLL.h>
#include "FrontPanelWrapper.h"

/*!\relates FrontPanelWrapper
 * \fn int fpLibraryCheck()
 * Checks to see if the OpalKelly FrontPanel dynamic library has been loaded.
 *
 * @return Returns 0 if the okFrontPanel driver is present and loaded. Else, the returned value is -1.
 */
int fpLibraryCheck() {
    using namespace std;
    char dll_date[32], dll_time[32];
    if(FALSE == okFrontPanelDLL_LoadLib(nullptr)){
        cerr<<"FrontPanelWrapper: ERROR: Could not load the FrontPanel library!\n";
        return 1;
    }
    okFrontPanelDLL_GetVersion(dll_date, dll_time);
    cout<<"FrontPanelWrapper: OK_FrontPanel library loaded. Build Date: " << dll_date <<"\tBuild Time: "<< dll_time << endl << endl;
    return 0;
}

/*!\relates FrontPanelWrapper
 * \fn int fpErrorParser(ok_ErrorCode fp_ErrorCode)
 * A basic error code parser that handles all documented OpalKelly FrontPanel error codes.
 * This function accepts error codes and outputs relevant text in the 'stderr' stream.
 * It also returns the error code, type-casted as an integer.
 *
 * @param fp_ErrorCode The error code is passed as a parameter here.
 * It is typically an integer type-casted to 'ok_ErrorCode' type.
 * @return The error code input in the parameter, type-casted as an integer.
 */
int fpErrorParser(okCFrontPanel::ErrorCode fp_ErrorCode) {
    using namespace std;
    switch(fp_ErrorCode) {
        case okCFrontPanel::ErrorCode::Failed :
            cerr<< "OK_FrontPanel: ERROR: Operation Failed!\n";
            break;
        case okCFrontPanel::ErrorCode::Timeout :
            cerr<< "OK_FrontPanel: ERROR: Operation timed out!\n";
            break;
        case okCFrontPanel::ErrorCode::DoneNotHigh :
            cerr<< "OK_FrontPanel: ERROR: 'Done signal is not logic high!\n";
            break;
        case okCFrontPanel::ErrorCode::TransferError :
            cerr<< "OK_FrontPanel: ERROR: Data transfer has failed!\n";
            break;
        case okCFrontPanel::ErrorCode::CommunicationError :
            cerr<< "OK_FrontPanel: ERROR: Communication error!\n";
            break;
        case okCFrontPanel::ErrorCode::InvalidBitstream :
            cerr<< "OK_FrontPanel: ERROR: Invalid bitstream selected for upload!\n";
            break;
        case okCFrontPanel::ErrorCode::FileError :
            cerr<< "OK_FrontPanel: ERROR: File error!\n";
            break;
        case okCFrontPanel::ErrorCode::DeviceNotOpen :
            cerr<< "OK_FrontPanel: ERROR: Device not open!\n";
            break;
        case okCFrontPanel::ErrorCode::InvalidEndpoint :
            cerr<< "OK_FrontPanel: ERROR: FPGA endpoint invalid!\n";
            break;
        case okCFrontPanel::ErrorCode::InvalidBlockSize :
            cerr<< "OK_FrontPanel: ERROR: Data transfer block size invalid!\n";
            break;
        case okCFrontPanel::ErrorCode::I2CRestrictedAddress :
            cerr<< "OK_FrontPanel: ERROR: I2C address is restricted\n";
            break;
        case okCFrontPanel::ErrorCode::I2CBitError :
            cerr<< "OK_FrontPanel: ERROR: Bit error(s) on the I2C bus!\n";
            break;
        case okCFrontPanel::ErrorCode::I2CNack :
            cerr<< "OK_FrontPanel: ERROR: NACK received on the I2C bus!\n";
            break;
        case okCFrontPanel::ErrorCode::I2CUnknownStatus :
            cerr<< "OK_FrontPanel: ERROR: I2C device status unknown!\n";
            break;
        case okCFrontPanel::ErrorCode::UnsupportedFeature :
            cerr<< "OK_FrontPanel: ERROR: Feature not supported!\n";
            break;
        case okCFrontPanel::ErrorCode::FIFOUnderflow :
            cerr<< "OK_FrontPanel: ERROR: Data transfer FIFO underflow!\n";
            break;
        case okCFrontPanel::ErrorCode::FIFOOverflow :
            cerr<< "OK_FrontPanel: ERROR: Data transfer FIFO overflow!\n";
            break;
        case okCFrontPanel::ErrorCode::DataAlignmentError :
            cerr<< "OK_FrontPanel: ERROR: Alignment error in data transfer!\n";
            break;
        case okCFrontPanel::ErrorCode::InvalidResetProfile :
            cerr<< "OK_FrontPanel: ERROR: Invalid reset profile!\n";
            break;
        case okCFrontPanel::ErrorCode::InvalidParameter :
            cerr<< "OK_FrontPanel: ERROR: Invalid parameter(s)!\n";
            break;
        default:
            break;
    }

    return (int) fp_ErrorCode;
}

/*!\relates FrontPanelWrapper
 * \fn int fpErrorParser(ok_ErrorCode fp_ErrorCode, std::string userMSG)
 * A wrapper for the basic 'fpErrorParser(ok_ErrorCode)' function.
 * Adds support for a custom text message to be displayed along with the text interpretation of the error code.
 *
 * @param fp_ErrorCode
 * @param userMSG
 * @return
 */
int fpErrorParser(okCFrontPanel::ErrorCode fp_ErrorCode, std::string userMSG) {
    if( (userMSG.length() > 1) && ((int)fp_ErrorCode != (int)okCFrontPanel::ErrorCode::NoError) ) {
        std::cerr<<std::endl<<"FrontPanelWrapper: ERROR: "<<userMSG<<"\n\t\t";
    }
    return fpErrorParser(fp_ErrorCode);
}


std::string fpBoardParser(okCFrontPanel::BoardModel fp_ModelCode) {
    using namespace std;
    string boardName;
    switch(fp_ModelCode) {
        case okCFrontPanel::BoardModel::brdUnknown : // 0
            boardName = "Board unknown";
            break;
        case okCFrontPanel::BoardModel::brdXEM3001v1 : // 1
            boardName = "XEM3001v1";
            break;
        case okCFrontPanel::BoardModel::brdXEM3001v2 : // 2
            boardName = "XEM3001v2";
            break;
        case okCFrontPanel::BoardModel::brdXEM3010 : // 3
            boardName = "XEM3010";
            break;
        case okCFrontPanel::BoardModel::brdXEM3005 : // 4
            boardName = "XEM3005";
            break;
        case okCFrontPanel::BoardModel::brdXEM3001CL : // 5
            boardName = "XEM3001CL";
            break;
        case okCFrontPanel::BoardModel::brdXEM3020 : // 6
            boardName = "XEM3020";
            break;
        case okCFrontPanel::BoardModel::brdXEM3050 : // 7
            boardName = "XEM3050";
            break;
        case okCFrontPanel::BoardModel::brdXEM9002 : // 8
            boardName = "XEM9002";
            break;
        case okCFrontPanel::BoardModel::brdXEM3001RB : // 9
            boardName = "XEM3001RB";
            break;
        case okCFrontPanel::BoardModel::brdXEM5010 : // 10
            boardName = "XEM5010";
            break;
        case okCFrontPanel::BoardModel::brdXEM6110LX45 : // 11
            boardName = "XEM6110-LX45";
            break;
        case okCFrontPanel::BoardModel::brdXEM6110LX150 : // 15
            boardName = "XEM6110-LX150";
            break;
        case okCFrontPanel::BoardModel::brdXEM6001 : // 12
            boardName = "XEM6001";
            break;
        case okCFrontPanel::BoardModel::brdXEM6010LX45 : // 13
            boardName = "XEM6010-LX45";
            break;
        case okCFrontPanel::BoardModel::brdXEM6010LX150 : // 14
            boardName = "XEM6010-LX150";
            break;
        case okCFrontPanel::BoardModel::brdXEM6006LX9 : // 16
            boardName = "XEM6006-LX9";
            break;
        case okCFrontPanel::BoardModel::brdXEM6006LX16 : // 17
            boardName = "XEM6006-LX16";
            break;
        case okCFrontPanel::BoardModel::brdXEM6006LX25 : // 18
            boardName = "XEM6006-LX25";
            break;
        case okCFrontPanel::BoardModel::brdXEM5010LX110 : // 19
            boardName = "XEM5010-LX110";
            break;
        case okCFrontPanel::BoardModel::brdZEM4310 : // 20
            boardName = "ZEM4310";
            break;
        case okCFrontPanel::BoardModel::brdXEM6310LX45 : // 21
            boardName = "XEM6310-LX45";
            break;
        case okCFrontPanel::BoardModel::brdXEM6310LX150 : // 22
            boardName = "XEM6310-LX150";
            break;
        case okCFrontPanel::BoardModel::brdXEM6110v2LX45 : // 23
            boardName = "XEM6110v2-LX45";
            break;
        case okCFrontPanel::BoardModel::brdXEM6110v2LX150 : // 24
            boardName = "XEM6110v2-LX150";
            break;
        case okCFrontPanel::BoardModel::brdXEM6002LX9 : // 25
            boardName = "XEM6002-LX9";
            break;
        case okCFrontPanel::BoardModel::brdXEM6310MTLX45T : // 26
            boardName = "XEM6310MT-LX45T";
            break;
        case okCFrontPanel::BoardModel::brdXEM6320LX130T : // 27
            boardName = "XEM6320-LX130T";
            break;
        case okCFrontPanel::BoardModel::brdXEM7350K70T : // 28
            boardName = "XEM7350-K70T";
            break;
        case okCFrontPanel::BoardModel::brdXEM7350K160T : // 29
            boardName = "XEM7350-K160T";
            break;
        case okCFrontPanel::BoardModel::brdXEM7350K410T : // 30
            boardName = "XEM7350-K410T";
            break;
        case okCFrontPanel::BoardModel::brdXEM6310MTLX150T : // 31
            boardName = "XEM6310MT-LX150T";
            break;
        case okCFrontPanel::BoardModel::brdZEM5305A2 : // 32
            boardName = "ZEM5305-A2";
            break;
        case okCFrontPanel::BoardModel::brdZEM5305A7 : // 33
            boardName = "ZEM5305-A7";
            break;
        case okCFrontPanel::BoardModel::brdXEM7001A15 : // 34
            boardName = "XEM7001-A15";
            break;
        case okCFrontPanel::BoardModel::brdXEM7001A35 : // 35
            boardName = "XEM7001-A35";
            break;
        case okCFrontPanel::BoardModel::brdXEM7360K160T : // 36
            boardName = "XEM7360-K160T";
            break;
        case okCFrontPanel::BoardModel::brdXEM7360K410T : // 37
            boardName = "XEM7360-K410T";
            break;
        case okCFrontPanel::BoardModel::brdZEM5310A4 : // 38
            boardName = "ZEM5310-A4";
            break;
        case okCFrontPanel::BoardModel::brdZEM5310A7 : // 39
            boardName = "ZEM5310-A7";
            break;
        case okCFrontPanel::BoardModel::brdZEM5370A5 : // 40
            boardName = "ZEM5370-A5";
            break;
        case okCFrontPanel::BoardModel::brdXEM7010A50 : // 41
            boardName = "XEM7010-A50";
            break;
        case okCFrontPanel::BoardModel::brdXEM7010A200 : // 42
            boardName = "XEM7010-A200";
            break;
        case okCFrontPanel::BoardModel::brdXEM7310A75 : // 43
            boardName = "XEM7310-A75";
            break;
        case okCFrontPanel::BoardModel::brdXEM7310A200 : // 44
            boardName = "XEM7310-A200";
            break;
        default:
            boardName = "Board code unknown";
            cerr<<"FrontPanelWrapper: WARNING: Board code is unknown...\n";
            break;
    }

    return boardName;
}

int fpEnumerate() {
    okCFrontPanel dev;
    int devCount = dev.GetDeviceCount();
    okCFrontPanel::BoardModel boardCode;
    for (int i = 0; i<devCount; i++) {
        boardCode = dev.GetDeviceListModel(i);
        std::cout << "Device " << i << ": " << fpBoardParser(boardCode) << " [Board code: " << boardCode << " , Serial: " << dev.GetDeviceListSerial(i) << "]\n";
    }
    return devCount;
}



