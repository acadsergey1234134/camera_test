#include "tests.h"

//linux
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>
#include <string>

void PrintHelp()
{
std::cout << " Command line options:" << std::endl
          << kOptionVerbose << ": verbose mode" << std::endl
          << kOptionDeviceNames << ": list device names" << std::endl
          << kOptionOpenClose << ": open - close all the available video devices" << std::endl
          << kGetCapability << ": get video devices capabilities" << std::endl
          << kGetCapability2 << ": get video devices capabilities ver 2" << std::endl;
}

void TestGetDeviceNames(bool bVerbose)
{
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << ">>>" << std::endl;
    TDeviceNames deviceNames;
    linux_videodev::GetDeviceNames(bVerbose, deviceNames);
    for(TDeviceNames::const_iterator it(deviceNames.begin()); it != deviceNames.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << "<<<" << std::endl;
}

void TesOpenCloseDevice(bool /*bVerbose*/)
{
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << ">>>" << std::endl;
    TDeviceNames deviceNames;
    linux_videodev::GetDeviceNames(false, deviceNames);
    for(TDeviceNames::const_iterator it(deviceNames.begin()); it != deviceNames.end(); ++it) {
        std::string sName(*it);
        std::cout << sName;
        int fd =  open(sName.c_str(), O_RDWR);
        if (fd == -1) {
            std::cout << " ERR: open():" << fd << std::endl;
        } else {
            std::cout << " open():" << fd << std::endl;
            int res = close(fd);
            if(0 == res) {
                std::cout << " close():" << res << std::endl;
            } else {
                std::cout << "ERR: close():" << res << std::endl;
            }
        }
    }
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << "<<<" << std::endl;
}

void TestCapabilities(bool /*bVerbose*/)
{
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << ">>>" << std::endl;
    TDeviceNames deviceNames;
    linux_videodev::GetDeviceNames(false, deviceNames);
    for(TDeviceNames::const_iterator it(deviceNames.begin()); it != deviceNames.end(); ++it) {
        std::string sName(*it);
        std::cout << sName;
        int fd =  open(sName.c_str(), O_RDWR);
        if (fd == -1) {
            std::cout << " ERR: open():" << fd << std::endl;
        } else {
            std::cout << " open():" << fd << std::endl;

            std::cout << " NOT IMPL" << fd << std::endl;
            //linux_videodev2::GetCapability(bVerbose, sName, fd);
            int res = close(fd);
            if(0 == res) {
                std::cout << " close():" << res << std::endl;
            } else {
                std::cout << "ERR: close():" << res << std::endl;
            }
        }
    }
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << "<<<" << std::endl;
}

void TestCapabilities2(bool bVerbose)
{
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << ">>>" << std::endl;
    TDeviceNames deviceNames;
    linux_videodev::GetDeviceNames(false, deviceNames);
    for(TDeviceNames::const_iterator it(deviceNames.begin()); it != deviceNames.end(); ++it) {
        std::string sName(*it);
        std::cout << sName;
        int fd =  open(sName.c_str(), O_RDWR);
        if (fd == -1) {
            std::cout << " ERR: open():" << fd << std::endl;
        } else {
            std::cout << " open():" << fd << std::endl;
            linux_videodev2::GetCapability(bVerbose, sName, fd);
            int res = close(fd);
            if(0 == res) {
                std::cout << " close():" << res << std::endl;
            } else {
                std::cout << "ERR: close():" << res << std::endl;
            }
        }
    }
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << "<<<" << std::endl;
}
