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

int fpEnumerate() {
    okCFrontPanel dev;
    int devCount = dev.GetDeviceCount();
    for (int i = 0; i<devCount; i++) {
        std::cout << "Device [" << i << "]: Model: " << dev.GetDeviceListModel(i) << "(Serial: " << dev.GetDeviceListSerial(i) << ")\n";
    }
    return devCount;
}


