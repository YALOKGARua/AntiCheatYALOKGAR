section .data
    file_path db "C:\\Program Files\\Game\\game.exe", 0
    expected_hash db "1234567890abcdef", 0

section .text
global _check_file_integrity

_check_file_integrity:
    push dword file_path
    call CreateFileA

    test eax, eax
    jz .file_not_found

    push dword 0
    push dword 0
    push dword eax
    call ReadFile

    push dword eax
    push dword expected_hash
    call CompareHashes

    test eax, eax
    jnz .file_integrity_failed

    xor eax, eax
    ret

.file_not_found:
    mov eax, 1
    ret

.file_integrity_failed:
    mov eax, 2
    ret