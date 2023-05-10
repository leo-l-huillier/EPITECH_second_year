;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; memset.asm
;

section .text
global memset

memset:
    xor rcx, rcx
    xor rax, rax
    mov r10, rdi

    loop:
        cmp rcx, rdx
        jge end
        mov BYTE[rdi], sil
        inc rcx
        inc rdi
        jmp loop

    end:
        mov rax, r10
        ret