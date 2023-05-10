;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; memcpy.asm
;

section .text
global memcpy
memcpy:
    jmp init
    loop:
        cmp rcx, rdx
        je endl
        mov r9b, BYTE[rsi]
        mov BYTE[rdi], r9b
        jmp increm
        jmp loop
    increm:
        inc rcx
        inc rdi
        inc rsi
    init:
        xor rcx, rcx
        xor rax, rax
        mov r8, rdi
    endl:
        mov rax, r8
        ret