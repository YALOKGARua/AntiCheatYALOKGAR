#include <iostream>
#include <windows.h>

bool check_for_hidden_processes() {
    PROCESSENTRY32 process;
    process.dwSize = sizeof(PROCESSENTRY32);
    
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    Process32First(snapshot, &process);
    do {
        if (process.szExeFile[0] == '\0') {
            CloseHandle(snapshot);
            return false;
        }
    } while (Process32Next(snapshot, &process));

    CloseHandle(snapshot);
    return true;
}