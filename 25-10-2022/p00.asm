section .text

; equivale a um return 0;
global _start

_start:
    mov rax, 60
    ; xor rdi, rdi
    mov rdi, 55
    syscall