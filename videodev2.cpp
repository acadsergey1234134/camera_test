#include "videodev2.h"

//linux
#include <errno.h>
#include <fcntl.h>
#include <linux/videodev2.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>

#include <iostream>
#include <string>

namespace linux_videodev2  {

static int xioctl(int fd, int request, void *arg)
{
    int r;

    do r = ioctl (fd, request, arg);
    while (-1 == r && EINTR == errno);

    return r;
}

void GetCapability(bool /*bVerbose*/, const std::string& sDeviceName, int fd)
{
    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << ">>>" << std::endl;

    struct v4l2_capability caps = {};
    if (-1 == xioctl(fd, VIDIOC_QUERYCAP, &caps)) {
        std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']'
                  << " sDeviceName:" << sDeviceName
                  << " fd:" << fd << std::endl
                  << std::endl;

    }

    int verMaj = (caps.version>>16) && 0xff;
    int verMin = (caps.version>>24) && 0xff;

    std::cout << " sDeviceName:" << sDeviceName
              << " fd:" << fd << std::endl
              << " Driver:" <<  caps.driver << std::endl
              << " Card:" << caps.card << std::endl
              << " Bus:" <<  caps.bus_info << std::endl
              << " Version:"<< verMaj << "." << verMin << std::endl
              << " Capabilities:" << std::hex << "0x"<< caps.capabilities
              << std::endl;

    std::cout << '[' << __PRETTY_FUNCTION__ <<  ':' << __LINE__ << ']' << "<<<" << std::endl;
}

} //namespace linux_videodev2



