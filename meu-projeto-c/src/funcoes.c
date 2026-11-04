#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void cadastrarAtivo(Ativo carteira[], int *total) {
    if (*total >= MAX_ATIVOS) {
        printf("Limite de ativos atingido!\n");
        return;
    }

    printf("Nome do ativo: ");
    scanf(" %[^\n]", carteira[*total].nome);
    printf("Categoria: ");
    scanf(" %[^\n]", carteira[*total].categoria);
    printf("Quantidade: ");
    scanf("%d", &carteira[*total].quantidade);
    printf("Preco de compra: ");
    scanf("%f", &carteira[*total].precoCompra);
    printf("Preco atual: ");
    scanf("%f", &carteira[*total].precoAtual);

    (*total)++;
    printf("Ativo cadastrado com sucesso!\n");
}

void listarAtivos(Ativo carteira[], int total) {
    if (total == 0) {
        printf("Nenhum ativo cadastrado na carteira.\n");
        return;
    }

    printf("\n=== Carteira ===\n");
    int i;
    for (i = 0; i < total; i++) {
        float valorAtualAtivo = carteira[i].quantidade * carteira[i].precoAtual;
        float custoAtivo = carteira[i].quantidade * carteira[i].precoCompra;
        float rentabilidadeAtivo = 0.0;
        
        if (custoAtivo > 0) {
            rentabilidadeAtivo = ((valorAtualAtivo - custoAtivo) / custoAtivo) * 100.0;
        }

        printf("%d. %s - %s - %d unidades - R$ %.2f\n", 
            i + 1, 
            carteira[i].nome, 
            carteira[i].categoria, 
            carteira[i].quantidade, 
            carteira[i].precoAtual
        );
        printf("Valor atual: R$ %.2f\n", valorAtualAtivo);
        printf("Rentabilidade: %.2f%%\n\n", rentabilidadeAtivo);
    }
}

double calcularValorTotal(Ativo carteira[], int total) {
    float valorTotal = 0.0;
    int i;
    for (i = 0; i < total; i++) {
        valorTotal += carteira[i].quantidade * carteira[i].precoAtual;
    }
    printf("Valor total da carteira: R$ %.2f\n", valorTotal);
    
    return valorTotal;
}

void calcularRentabilidadeGeral(Ativo carteira[], int total) {
    float custoTotal = 0.0;
    float valorAtualTotal = 0.0;
    int i;

    for (i = 0; i < total; i++) {
        custoTotal += carteira[i].quantidade * carteira[i].precoCompra;
        valorAtualTotal += carteira[i].quantidade * carteira[i].precoAtual;
    }

    if (custoTotal == 0.0) {
        printf("Rentabilidade geral: 0.00%%\n");
        return;
    }

    float rentabilidadeGeral = ((valorAtualTotal - custoTotal) / custoTotal) * 100.0;
    printf("Rentabilidade geral: %.2f%%\n", rentabilidadeGeral);
}

void ordenarCarteira(Ativo carteira[], int total) {
	if (total < 2) {
    	printf("Nao ha ativos suficientes para ordenar.\n");
    	return;
	}
	
	int i, j;

	for (i = 0; i < total - 1; i++) {

    	for (j = 0; j < total - 1 - i; j++) {
	
    	float custoEsquerda = carteira[j].quantidade * carteira[j].precoCompra;
		float valorAtualEsquerda = carteira[j].quantidade * carteira[j].precoAtual;
		float rentabilidadeEsquerda = 0.0;
		
		if (custoEsquerda > 0) {
    		rentabilidadeEsquerda = ((valorAtualEsquerda - custoEsquerda) / custoEsquerda) * 100.0;
			}
			
		float custoDireita = carteira[j + 1].quantidade * carteira[j + 1].precoCompra;
		float valorAtualDireita = carteira[j + 1].quantidade * carteira[j + 1].precoAtual;
		float rentabilidadeDireita = 0.0;

		if (custoDireita > 0) {
    		rentabilidadeDireita = ((valorAtualDireita - custoDireita) / custoDireita) * 100.0;
			}
			
		if (rentabilidadeEsquerda < rentabilidadeDireita) {
			Ativo temporario;
			
			temporario = carteira[j];
			carteira[j] = carteira[j + 1];
			carteira[j + 1] = temporario;
			}	
   		}
	}
		printf("Carteira ordenada por rentabilidade!\n");
}

void simularInvestimentos(double valorInicial) {

    double poupanca = valorInicial;
    double tesouro = valorInicial;
    double cdb = valorInicial;

    int mes;

    for (mes = 1; mes <= MESES; mes++) {

        poupanca *= (1 + TAXA_POUPANCA);

        tesouro *= (1 + TAXA_TESOURO);

        cdb *= (1 + TAXA_CDB);
    }

    printf("\n=== SIMULADOR EDUCATIVO ===\n");

    printf("E se os R$ %.2f da sua carteira ficassem\n investidos por 12 meses em cada opcao?\n", valorInicial);

    printf("POUPANCA (0.50%%/mes): R$ %.2f (+R$ %.2f)\n",
           poupanca, poupanca - valorInicial);

    printf("TESOURO SELIC (0.80%%/mes): R$ %.2f (+R$ %.2f)\n",
           tesouro, tesouro - valorInicial);

    printf("CDB 110%% CDI (0.90%%/mes): R$ %.2f (+R$ %.2f)\n\n",
           cdb, cdb - valorInicial);
    
	printf("O que isso significa?\n- Poupanca: rende menos, mas e o investimento mais conhecido.\n- Tesouro Selic: garantido pelo Tesouro Nacional, rende mais que a poupanca e aceita aplicacoes a partir de R$ 150,00.\n- CDB: rende mais e e coberto pelo FGC ate R$ 250 mil, verifique a liquidez — alguns travam o dinheiro por um prazo.\n");      
}

void gerarRelatorioFinal(Ativo carteira[], int total) {
    if (total == 0) {
        printf("Nenhum ativo cadastrado para gerar o relatorio.\n");
        return;
    }

    ordenarCarteira(carteira, total);

    printf("\n=== RELATORIO FINAL DA CARTEIRA ===\n");
    int i;
    float valorTotalCarteira = 0.0;
    float custoTotalCarteira = 0.0;

    for (i = 0; i < total; i++) {
        float valorAtualAtivo = carteira[i].quantidade * carteira[i].precoAtual;
        float custoAtivo = carteira[i].quantidade * carteira[i].precoCompra;
        float rentabilidadeAtivo = 0.0;

        if (custoAtivo > 0) {
            rentabilidadeAtivo = ((valorAtualAtivo - custoAtivo) / custoAtivo) * 100.0;
        }

        valorTotalCarteira += valorAtualAtivo;
        custoTotalCarteira += custoAtivo;

        printf("%d. %s - %s - Rentabilidade: %.2f%%\n", i + 1, carteira[i].nome, carteira[i].categoria, rentabilidadeAtivo);
    }

    float rentabilidadeGeral = 0.0;
    if (custoTotalCarteira > 0) {
        rentabilidadeGeral = ((valorTotalCarteira - custoTotalCarteira) / custoTotalCarteira) * 100.0;
    }

    float lucroPrejuizo = valorTotalCarteira - custoTotalCarteira;

    printf("\nValor total: R$ %.2f\n", valorTotalCarteira);
    printf("Rentabilidade geral: %.2f%%\n", rentabilidadeGeral);
    printf("Lucro/prejuizo total: R$ %.2f\n", lucroPrejuizo);

    printf("\n--- Impacto Social (ODS 8.10) ---\n");
    printf("Este sistema promove a inclusao financeira ao democratizar o acesso a simulacoes e informacoes de investimentos, aproximando ferramentas de mercado a populacoes que historicamente estao fora dele, fortalecendo a capacidade de instituicoes financeiras e o acesso universal a servicos economicos.\n");
}
