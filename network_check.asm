section .data
    server_ip db "127.0.0.1", 0
    server_port dw 8080

section .text
global _check_network_activity

_check_network_activity:
    push dword server_port
    push dword server_ip
    push dword 0
    call socket

    test eax, eax
    jnz .network_found

    xor eax, eax
    ret

.network_found:
    mov eax, 1
    ret