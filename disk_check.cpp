#include <iostream>
#include <windows.h>

bool check_for_suspicious_drives() {
    char drive[4] = "C:\\";
    for (int i = 0; i < 26; ++i) {
        drive[0] = 'A' + i;
        if (GetDriveType(drive) == DRIVE_REMOTE) {
            return false;
        }
    }
    return true;
}