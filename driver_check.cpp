#include <iostream>
#include <windows.h>

bool check_for_suspicious_drivers() {
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        char driverName[256];
        DWORD index = 0;
        while (RegEnumKeyEx(hKey, index++, driverName, nullptr, nullptr, nullptr, nullptr, nullptr) == ERROR_SUCCESS) {
            if (strstr(driverName, "cheat") != nullptr) {
                RegCloseKey(hKey);
                return false;
            }
        }
    }

    return true;
}