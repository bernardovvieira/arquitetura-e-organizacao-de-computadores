%include	'util.asm/util.asm'

section		.text
global		_start

_start:
    mov    rdi, 1
    .while:
        cmp   rdi, 0
        jng   .fim
        lea   rdi, [msg1]
        call  printstr
        call  readint
        mov   rdi, rax
        call  impares
        jmp   .while
    .fim:
        call printa

impares:
    mov   dx, 0
    mov   r12, rdi
    mov   r13, 2
    div   r13
    cmp   dx, 0
    jng   .fimc
    inc   r14
    .fimc:
        ret
        
printa:
    lea   rdi, [msg2]
    call  printstr
    mov   rdi, r14
    call  printint
    call  endl
    call  exit0

section .data 
    msg1:   db  "Informe um número: ", 0
    msg2:   db  "A quantidade de números ímpares lidos foi ", 0