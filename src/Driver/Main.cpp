#include "StdAfx.h"

//
// Entry point for the driver
//

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT driverObject, PUNICODE_STRING /*registryPath*/)
{
    // Call some C++ standard library functionality to ensure they work
    std::array<char, 16> buffer{};
    std::ranges::fill(buffer, 'A');

    driverObject->DriverUnload = [](PDRIVER_OBJECT){};
    return STATUS_SUCCESS;
}
