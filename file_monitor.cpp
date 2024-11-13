#include <iostream>
#include <windows.h>

bool monitor_critical_files() {
    const char* file_paths[] = {
        "C:\\Program Files\\Game\\game.exe",
        "C:\\Program Files\\Game\\game_data.dat"
    };

    for (int i = 0; i < 2; ++i) {
        DWORD attributes = GetFileAttributes(file_paths[i]);
        if (attributes == INVALID_FILE_ATTRIBUTES || (attributes & FILE_ATTRIBUTE_DIRECTORY)) {
            return false;
        }
    }

    return true;
}