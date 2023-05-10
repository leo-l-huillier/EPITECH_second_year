;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strcmp.asm
;

section .text
global strcmp
strcmp:
    xor rcx, rcx
    xor rax, rax

    loop:
        cmp BYTE[rdi + rcx], 0
        je modif
        cmp BYTE[rsi + rcx], 0
        je modif
        mov r8b, BYTE[rsi + rcx]
        cmp BYTE[rdi + rcx], r8b
        jne modif
        inc rcx
        jmp loop

    modif: ;nouvelle fonction
        mov al, BYTE[rdi + rcx]
        sub al, BYTE[rsi + rcx]
        movsx rax, al
        ret