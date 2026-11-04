#ifndef MODULO_H
#define MODULO_H

#include "funcoes.h"

void carregarCarteira(Ativo carteira[], int *total, const char *filename);
void salvarCarteira(Ativo carteira[], int total, const char *filename);

#endif
