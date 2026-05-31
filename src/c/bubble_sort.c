#include "aluno.h"
#include <stddef.h>

void bubble_sort_c(Aluno **ptrs, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        int trocou = 0;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (ptrs[j]->id > ptrs[j + 1]->id) {
                Aluno *temp = ptrs[j];
                ptrs[j] = ptrs[j + 1];
                ptrs[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) {
            break; // se nao houve troca o array ja esta ordenado
        }
    }
}