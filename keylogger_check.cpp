#include <iostream>
#include <windows.h>

bool check_for_keylogger() {
    HWND hwnd = GetForegroundWindow();
    char windowTitle[256];
    GetWindowText(hwnd, windowTitle, sizeof(windowTitle));

    if (strstr(windowTitle, "Keylogger") != nullptr) {
        return false;
    }

    return true;
}