#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

bool check_running_processes() {
    PROCESSENTRY32 process;
    process.dwSize = sizeof(PROCESSENTRY32);
    
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    Process32First(snapshot, &process);
    do {
        if (strstr(process.szExeFile, "") != nullptr) {
            CloseHandle(snapshot);
            return false;
        }
    } while (Process32Next(snapshot, &process));

    CloseHandle(snapshot);
    return true;
}