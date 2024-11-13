#include <iostream>
#include <windows.h>

bool check_for_debugger() {
    if (IsDebuggerPresent()) {
        return false;
    }

    return true;
}