# Anti-Cheat System (C++ and ASM)

This project is an **Anti-Cheat** system developed using **C++** and **Assembly**. The system aims to detect various types of cheats and malicious activities related to memory manipulation, suspicious drivers, process monitoring, file integrity, and network activities.

### Features
- **Memory Integrity Check**: Detects if any memory manipulation or cheat injection occurs.
- **Registry Check**: Scans the Windows registry for suspicious entries related to cheating software.
- **Suspicious Drivers Check**: Identifies potentially malicious or cheat-related drivers.
- **Running Process Check**: Monitors and identifies suspicious or cheating processes running on the system.
- **File Integrity Check**: Verifies the integrity of critical game files and detects tampering.
- **Network Activity Check**: Detects unusual or potentially malicious network activity associated with cheating.

### Project Structure
```
/anti_cheat_project
    /src
        main.cpp               # C++ entry point, where anti-cheat checks are performed
        memory_check.asm        # Assembly code for memory integrity checks
        registry_check.asm      # Assembly code for registry check
        process_check.asm       # Assembly code for process monitoring
        driver_check.asm        # Assembly code for checking suspicious drivers
        file_integrity_check.asm# Assembly code for file integrity check
        network_check.asm       # Assembly code for network activity check
    Makefile                    # Makefile to automate compilation
```

### Requirements

- **C++ Compiler** (e.g., `g++`)
- **NASM** (Netwide Assembler) to compile Assembly files
- **Windows Operating System** (for registry and driver checks, specific to Windows APIs)

### Getting Started

#### 1. Clone the repository

Clone this project to your local machine:
```bash
git clone https://github.com/yourusername/anti-cheat-system.git
cd anti-cheat-system
```

#### 2. Compile Assembly Files
Compile the `.asm` files into object files (`.obj`) using NASM:

```bash
nasm -f win32 memory_check.asm -o memory_check.obj
nasm -f win32 registry_check.asm -o registry_check.obj
nasm -f win32 process_check.asm -o process_check.obj
nasm -f win32 driver_check.asm -o driver_check.obj
nasm -f win32 file_integrity_check.asm -o file_integrity_check.obj
nasm -f win32 network_check.asm -o network_check.obj
```

#### 3. Compile C++ Code
Once the Assembly files are compiled, compile the C++ code along with the object files:

```bash
g++ main.cpp memory_check.obj registry_check.obj process_check.obj driver_check.obj file_integrity_check.obj network_check.obj -o anti_cheat.exe
```

#### 4. Run the Anti-Cheat System
Now you can run the anti-cheat executable:

```bash
./anti_cheat.exe
```

### How It Works

- The C++ `main.cpp` file serves as the entry point for the system. It calls various external functions implemented in Assembly to check different aspects of the system's integrity.
- Each check (memory, registry, process, etc.) is implemented as a separate function in Assembly for performance reasons.
- The functions are called from `main.cpp` using `extern "C"` declarations to ensure the correct linkage.

### Contributing

If you would like to contribute to the development of this Anti-Cheat system, feel free to fork this repository and submit a pull request. We welcome bug fixes, new feature requests, and improvements.

---

### Additional Notes

- This Anti-Cheat system is primarily designed for **Windows environments**, as it uses Windows API calls (e.g., `RegOpenKeyExA`, `CreateToolhelp32Snapshot`).
- The project may need to be extended to support other platforms, such as Linux or macOS, if required.
