#include <iostream>
#include <windows.h>

bool check_registry_for_cheats() {
    HKEY hKey;
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, "", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return false;
    }

    if (RegOpenKeyEx(HKEY_CURRENT_USER, "", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return false;
    }

    return true;
}