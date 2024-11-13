#include <iostream>
#include "memory_check.h"
#include "hook_detection.h"
#include "file_integrity.h"
#include "system_check.h"
#include "process_check.h"
#include "integrity_hash.h"
#include "keylogger_check.h"
#include "network_check.h"
#include "registry_check.h"
#include "disk_check.h"
#include "antivirus_check.h"
#include "debugger_check.h"
#include "stealth_check.h"
#include "driver_check.h"
#include "file_monitor.h"

extern "C" bool check_memory_integrity();
extern "C" bool check_registry_for_cheats();
extern "C" bool check_for_suspicious_drivers();
extern "C" bool check_running_processes();
extern "C" bool check_file_integrity();
extern "C" bool check_network_activity();

int main() {
    if (!check_file_integrity()) {
        std::cout << "File integrity check failed!\n";
        return -1;
    }

    if (!check_memory_integrity()) {
        std::cout << "Memory manipulation detected!\n";
        return -1;
    }

    if (detect_hooks()) {
        std::cout << "Hooks detected!\n";
        return -1;
    }

    if (!check_system_integrity()) {
        std::cout << "System integrity check failed!\n";
        return -1;
    }

    if (!check_running_processes()) {
        std::cout << "Cheat processes detected!\n";
        return -1;
    }

    if (!check_file_hash()) {
        std::cout << "File hash mismatch detected!\n";
        return -1;
    }

    if (!check_for_keylogger()) {
        std::cout << "Keylogger detected!\n";
        return -1;
    }

    if (!check_network_activity()) {
        std::cout << "Suspicious network activity detected!\n";
        return -1;
    }

    if (!check_registry_for_cheats()) {
        std::cout << "Registry contains cheat entries!\n";
        return -1;
    }

    if (!check_for_suspicious_drives()) {
        std::cout << "Suspicious drives detected!\n";
        return -1;
    }

    if (!check_for_antivirus()) {
        std::cout << "No antivirus found!\n";
        return -1;
    }

    if (!check_for_debugger()) {
        std::cout << "Debugger detected!\n";
        return -1;
    }

    if (!check_for_hidden_processes()) {
        std::cout << "Hidden processes detected!\n";
        return -1;
    }

    if (!check_for_suspicious_drivers()) {
        std::cout << "Suspicious drivers detected!\n";
        return -1;
    }

    if (!monitor_critical_files()) {
        std::cout << "Critical file modification detected!\n";
        return -1;
    }

    std::cout << "No cheats detected.\n";
    return 0;
}