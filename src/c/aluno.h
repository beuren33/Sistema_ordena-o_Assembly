#ifndef ALUNO_H
#define ALUNO_H

#include <stdint.h>
#include <stddef.h>

typedef struct __attribute__((packed)) {
    uint32_t id;
    char     nome[52];
    float    nota;
    uint32_t _padding;
} Aluno;
_Static_assert(sizeof(Aluno) == 64, "Aluno deve ter 64 bytes");
_Static_assert(offsetof(Aluno, id) == 0, "id deve estar no offset 0");
_Static_assert(offsetof(Aluno, nome) == 4, "nome deve estar no offset 4");
_Static_assert(offsetof(Aluno, nota) == 56, "nota deve estar no offset 56");
#endif
