;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strlen.asm

bits 64
section .text
global strlen
strlen:
    xor rax, rax
    loop:
        cmp BYTE[rdi + rax], 0
        je endl
        inc rax
        jmp loop
    endl:
        ret
