#include "csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Aluno** csv_ler(const char *caminho, size_t *n) {
    FILE *f = fopen(caminho, "r");
    if (!f) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    char linha[256];

    // pula o cabeçalho
    if (!fgets(linha, sizeof(linha), f)) {
        fclose(f); exit(2);
    }
    // conta quantas linhas tem
    size_t count = 0;
    while (fgets(linha, sizeof(linha), f))
        count++;

    // volta pro início depois do cabeçalho
    rewind(f);
    if (!fgets(linha, sizeof(linha), f)) {
        fclose(f); exit(2);
    }
    

    // aloca os structs e o array de ponteiros
    Aluno *buffer = aligned_alloc(64, (count + 1) * sizeof(Aluno));
    Aluno **ptrs  = malloc((count + 1) * sizeof(Aluno*));

    // lê cada linha e preenche o buffer
    size_t i = 0;
    while (fgets(linha, sizeof(linha), f)) {
        char *tok = strtok(linha, ",");
        buffer[i].id = (uint32_t) strtoul(tok, NULL, 10);

        tok = strtok(NULL, ",");
        strncpy(buffer[i].nome, tok, 51);
        buffer[i].nome[51] = '\0';

        tok = strtok(NULL, ",\n");
        buffer[i].nota = strtof(tok, NULL);

        buffer[i]._padding = 0;
        ptrs[i] = &buffer[i];
        i++;
    }

    fclose(f);
    *n = i;
    return ptrs;
}

void csv_escrever(const char *caminho, Aluno **ptrs, size_t n) {
    FILE *f = fopen(caminho, "w");
    if (!f) {
        perror("Erro ao criar arquivo");
        exit(3);
    }

    fprintf(f, "id,nome,nota\n");
    for (size_t i = 0; i < n; i++) {
        fprintf(f, "%u,%s,%.2f\n",
            ptrs[i]->id,
            ptrs[i]->nome,
            ptrs[i]->nota);
    }

    fclose(f);
}

void csv_liberar(Aluno **ptrs, Aluno *buffer) {
    free(buffer);
    free(ptrs);
}