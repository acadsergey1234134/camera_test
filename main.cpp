#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>

#include "tests.h"

int main(int argc, char *argv[])
{
    bool bHelp = argc < 2;
    bool bVerbose = false;
    bool bTestGetDeviceNames = false;
    bool bTestOpenclose = false;
    bool bGetCapability2 = false;

    for (int arg = 0; arg < argc; ++arg) {
        std::string option = argv[arg];
        if (("-h" == option) || ("-help" == option) || ("--help" == option))  {
            bHelp = true;
        }

        if (kOptionVerbose == option) {
            bVerbose = true;
        }

        if (kOptionDeviceNames == option) {
            bTestGetDeviceNames = true;
        }

        if (kOptionOpenClose == option) {
            bTestOpenclose = true;
        }

        if (kGetCapability2 == option) {
            bGetCapability2 = true;
        }
    }

    bHelp = (!bTestOpenclose)
            && (!bTestGetDeviceNames)
            && (!bGetCapability2);

    if (bVerbose) {
        for (int arg = 0; arg < argc; ++arg) {
            std::cout << "arg:" << arg << " value:" << argv[arg] << std::endl;
        }
    }

    if(bHelp) {
        PrintHelp();
    } else {

        if (bTestGetDeviceNames) {
            TestGetDeviceNames(bVerbose);
        }

        if (bTestOpenclose) {
            TesOpenCloseDevice(bVerbose);
        }

        if (bGetCapability2) {
            TestCapabilities(bVerbose);
        }
    }
    return 0;
}
