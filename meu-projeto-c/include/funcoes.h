#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_ATIVOS 100

#define TAXA_POUPANCA 0.005
#define TAXA_TESOURO  0.008
#define TAXA_CDB      0.009

#define MESES 12

typedef struct {
    char nome[50];
    char categoria[50];
    int quantidade;
    float precoCompra;
    float precoAtual;
} Ativo;

void cadastrarAtivo(Ativo carteira[], int *total);
void listarAtivos(Ativo carteira[], int total);
double calcularValorTotal(Ativo carteira[], int total);
void calcularRentabilidadeGeral(Ativo carteira[], int total);
void ordenarCarteira(Ativo carteira[], int total);
void simularInvestimentos(double valorInicial);
void gerarRelatorioFinal(Ativo carteira[], int total);

#endif
