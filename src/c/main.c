#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aluno.h"
#include "csv.h"

extern void bubble_sort_id_asc(Aluno **ptrs, size_t n);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <entrada.csv> <saida.csv>\n", argv[0]);
        return 1;
    }

    size_t n;
    Aluno **ptrs = csv_ler(argv[1], &n);
    Aluno *buffer = ptrs[0];

    printf("Lidos %zu alunos.\n", n);

    struct timespec t0, t1;
    clock_gettime(CLOCK_MONOTONIC, &t0);

    bubble_sort_id_asc(ptrs, n);

    clock_gettime(CLOCK_MONOTONIC, &t1);

    double ms = (t1.tv_sec - t0.tv_sec) * 1000.0
            + (t1.tv_nsec - t0.tv_nsec) / 1000000.0;

    printf("Tempo: %.2f ms\n", ms);

    csv_escrever(argv[2], ptrs, n);
    csv_liberar(ptrs, buffer);

    return 0;
}
