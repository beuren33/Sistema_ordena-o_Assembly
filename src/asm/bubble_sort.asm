%define ALUNO_OFF_ID 0
%define ALUNO_SIZE   64

section .text
global bubble_sort_id_asc

bubble_sort_id_asc:
    cmp rsi, 1
    jbe .fim
    mov r10, rsi
    dec r10
.outer:
    xor r11d, r11d
    xor rcx, rcx
.inner:
    cmp rcx, r10
    jae .fim_inner
    mov r8, [rdi + rcx*8]
    mov r9, [rdi + rcx*8 + 8]
    mov eax, [r8 + ALUNO_OFF_ID]
    mov edx, [r9 + ALUNO_OFF_ID]
    cmp eax, edx
    jbe .nao_troca
    mov [rdi + rcx*8], r9
    mov [rdi + rcx*8 + 8], r8
    mov r11d, 1
.nao_troca:
    inc rcx
    jmp .inner
.fim_inner:
    test r11d, r11d
    jz .fim
    dec r10
    jnz .outer
.fim:
    ret
