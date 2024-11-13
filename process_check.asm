section .data
    process_name db "cheat_program.exe", 0
    hSnapshot dd 0
    pe32 PROCESSENTRY32

section .text
global _check_running_processes

_check_running_processes:
    push dword TH32CS_SNAPPROCESS
    call CreateToolhelp32Snapshot

    mov [hSnapshot], eax
    push dword 0
    call Process32First

.loop_processes:
    mov eax, [pe32.szExeFile]
    cmp eax, process_name
    je .found

    push dword [hSnapshot]
    call Process32Next
    test eax, eax
    jnz .loop_processes

    xor eax, eax
    ret

.found:
    mov eax, 1
    ret