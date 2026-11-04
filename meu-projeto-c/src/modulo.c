#include <stdio.h>
#include "modulo.h"

void carregarCarteira(Ativo carteira[], int *total, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        *total = 0;
        return;
    }

    *total = 0;
    while (fscanf(file, " %49[^;];%49[^;];%d;%f;%f", 
                  carteira[*total].nome, 
                  carteira[*total].categoria, 
                  &carteira[*total].quantidade, 
                  &carteira[*total].precoCompra, 
                  &carteira[*total].precoAtual) == 5) {
        (*total)++;
        if (*total >= MAX_ATIVOS) {
            break;
        }
    }

    fclose(file);
}

void salvarCarteira(Ativo carteira[], int total, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    int i;
    for (i = 0; i < total; i++) {
        fprintf(file, "%s;%s;%d;%.2f;%.2f\n", 
                carteira[i].nome, 
                carteira[i].categoria, 
                carteira[i].quantidade, 
                carteira[i].precoCompra, 
                carteira[i].precoAtual);
    }

    fclose(file);
}
