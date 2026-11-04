#include <stdio.h>
#include "funcoes.h"
#include "modulo.h"

int main() {
    Ativo carteira[MAX_ATIVOS];
    int total = 0;
    int opcao;
    const char *filename = "data/carteira.txt";

    carregarCarteira(carteira, &total, filename);

    do {
        printf("\n=== CARTEIRA DE INVESTIMENTOS ===\n");
        printf("1. Cadastrar ativo\n");
        printf("2. Listar ativos\n");
        printf("3. Valor total da carteira\n");
        printf("4. Rentabilidade geral\n");
        printf("5. Ordenar por rentabilidade\n");
        printf("6. Simulador educativo\n");
        printf("7. Relatorio final\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAtivo(carteira, &total);
                salvarCarteira(carteira, total, filename);
                break;
            case 2:
                listarAtivos(carteira, total);
                break;
            case 3:
                calcularValorTotal(carteira, total);
                break;
            case 4:
                calcularRentabilidadeGeral(carteira, total);
                break;
            case 5:
                ordenarCarteira(carteira, total);
            	break;
            case 6: {
  				  double valorInicial;
    				valorInicial = calcularValorTotal(carteira, total);
    				simularInvestimentos(valorInicial);
  					break;
			}
            case 7:
                gerarRelatorioFinal(carteira, total);
                break;
            case 0:
	            salvarCarteira(carteira, total, filename);
	            printf("Encerrando programa...\n");
	            break;
	        default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
