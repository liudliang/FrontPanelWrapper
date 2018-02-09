//---------------------------------------------------------
// Created by Suraj Chakravarthi Raja for FrontPanelWrapper
// Distributed under the MIT License.
//---------------------------------------------------------

#include <iostream>
#include "FrontPanelWrapper.h"

using namespace std;

int main(int argc, char **argv) {
    cout<<"Hello World!\n";
    FrontPanelWrapper a(98);
    int temp = a.test;
    cout<<"This test has the wrapper initialized to "<<temp<<endl;
    return 0;
}

