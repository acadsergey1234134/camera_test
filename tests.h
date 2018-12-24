#ifndef TESTS_H
#define TESTS_H

#include <string>

#include "videodev1.h"
#include "videodev2.h"



void PrintHelp();

void TestGetDeviceNames(bool bVerbose);
void TesOpenCloseDevice(bool bVerbose);
void TestCapabilities(bool bVerbose);
void TestCapabilities2(bool bVerbose);

#endif // TESTS_H
