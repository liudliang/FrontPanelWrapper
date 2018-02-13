//---------------------------------------------------------
// Created by Suraj Chakravarthi Raja for FrontPanelWrapper
// Distributed under the MIT License.
//---------------------------------------------------------

#include <iostream>
#include <okFrontPanelDLL.h>
#include "FrontPanelWrapper.h"

using namespace std;

int main(int argc, char **argv) {
    cout<<"Hello World!\n";
    fpLibraryCheck();
    fpErrorParser((ok_ErrorCode)-1, (std::string)"Testing! Testing! 1... 2... 3... Check!");
    return 0;
}

