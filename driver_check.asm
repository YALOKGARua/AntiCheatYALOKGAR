section .data
    driver_path db "C:\\Windows\\System32\\cheat_driver.sys", 0
    driver_attr dd 0

section .text
global _check_for_suspicious_drivers

_check_for_suspicious_drivers:
    push dword driver_path
    call GetFileAttributesA

    test eax, eax
    jnz .found

    xor eax, eax
    ret

.found:
    mov eax, 1
    ret