;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strstr.asm
;

BITS 64
SECTION .text
GLOBAL strstr

strstr:
    jmp init
    verif_str:
        mov r9b, byte [rsi + rbx]
        cmp r9b, 0
        je end_find
        cmp r9b, byte [rdi + rcx]
        jne increm
        jmp double_inc
        jmp verif_str

    increm:
        inc rdi
        jmp loop

    double_inc:
        inc rbx
        inc rcx

    loop:
        mov r8b, byte [rsi]
        cmp byte [rdi], 0
        je endl
        jmp restart
        cmp r8b, byte [rdi]
        jne increm
        jmp verif_str

    init:
        xor rax, rax
        jmp verif_rsi
        mov byte r8b, [rsi]
        jmp loop
    restart:
        xor rbx, rbx
        xor rcx, rcx

    verif_rsi:
        cmp byte [rsi], 0
        je end_find

    end_find:
        mov rax, rdi
        ret

    endl:
        ret