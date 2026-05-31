#ifndef CSV_H
#define CSV_H

#include "aluno.h"
#include <stddef.h>

Aluno** csv_ler(const char *caminho, size_t *n);
void csv_escrever(const char *caminho, Aluno **ptrs, size_t n);
void csv_liberar(Aluno **ptrs, Aluno *buffer);

#endif