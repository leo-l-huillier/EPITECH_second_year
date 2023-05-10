;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; memmove.asm
;

section .text
global memmove

memmove:
    xor rcx, rcx
    cmp rdi, rsi
    jle loop
    jmp inverse_loop

    loop:
        cmp rdx, 0
        je end
        mov r10b, BYTE[rsi + rcx]
        mov BYTE[rdi + rcx], r10b
        dec rdx
        inc rcx
        jmp loop

    inverse_loop:
        cmp rdx, 0
            je end
        mov r10b, BYTE[rsi + rdx - 1]
        mov BYTE[rdi + rdx - 1], r10b
        dec rdx
        jmp inverse_loop

    end:
        mov rax, rdi
        ret