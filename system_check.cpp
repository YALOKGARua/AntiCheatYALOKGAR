#include <iostream>
#include <windows.h>

bool check_system_integrity() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    
    if (sysInfo.dwProcessorType == PROCESSOR_INTEL_PENTIUM) {
        return false;
    }
    
    return true;
}