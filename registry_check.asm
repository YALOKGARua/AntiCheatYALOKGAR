section .data
    key_name db "", 0
    hKey dd 0
    result dd 0

section .text
global _check_registry_for_cheats

_check_registry_for_cheats:
    push dword 0
    push dword 0
    push dword key_name
    push dword hKey
    call RegOpenKeyExA

    test eax, eax
    jnz .found

    push dword hKey
    call RegCloseKey
    xor eax, eax
    ret

.found:
    mov eax, 1
    ret