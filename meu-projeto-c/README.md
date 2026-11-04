# Sistema de Carteira de Investimentos — CP3

## Descrição do Projeto
Este projeto foi desenvolvido como parte dos Checkpoints da disciplina. O sistema simula uma carteira de investimentos acessíveis com foco em **inclusão financeira**, alinhado ao Objetivo de Desenvolvimento Sustentável **ODS 8.10 da ONU** (ferramentas que aproximam do mercado quem está fora dele). O software permite gerenciar múltiplos ativos financeiros utilizando estruturas de dados em C (`struct` e vetores), ordenação por rentabilidade, simulador educativo de investimentos e relatórios detalhados com persistência completa de dados em arquivo texto.

## Público-Alvo
- Investidores iniciantes e pessoas que buscam gerenciar seus primeiros ativos de forma simples.
- Estudantes e entusiastas de programação interessados em ferramentas de educação e inclusão financeira.

## Funcionalidades
- **Cadastrar Ativo:** Permite registrar novos ativos informando nome, categoria, quantidade, preço de compra e preço atual.
- **Listar Ativos:** Exibe todos os ativos cadastrados na carteira com seus respectivos valores atuais e rentabilidades individuais.
- **Calcular Valor Total:** Apresenta o montante financeiro total acumulado na carteira de investimentos.
- **Calcular Rentabilidade Geral:** Exibe o percentual de rentabilidade global da carteira com base nos preços de compra e preços atuais dos ativos.
- **Ordenar por Rentabilidade:** Organiza a carteira do melhor para o pior desempenho utilizando algoritmos de ordenação sobre os vetores de structs.
- **Simulador Educativo:** Simula o valor total da carteira aplicado mês a mês ao longo de 12 meses em opções acessíveis (Poupança, Tesouro Selic e CDB), explicando rentabilidade e risco de forma simples.
- **Relatório Final:** Exibe a carteira ordenada, valor total, rentabilidade geral, lucro/prejuízo total e um parágrafo sobre o impacto social (ODS 8.10).
- **Persistência de Dados:** Salva e recarrega automaticamente os dados da carteira entre diferentes execuções do programa através do arquivo `carteira.txt`.

## Tecnologias Utilizadas
- **Linguagem C** (Padrão C99 ou superior)
- **Manipulação de Arquivos** (`fopen`, `fprintf`, `fscanf`, `fclose`)
- **Alocação e Estruturas de Dados** (`struct`, vetores)
- **Modularização de Código** (Arquivos `.h` e `.c` separados nas pastas `src/` e `include/`)

## Requisitos Mínimos
- Compilador de C compatível com GCC (MinGW no Windows, GCC no Linux/macOS).
- Estrutura de pastas configurada corretamente no ambiente de desenvolvimento.

## Vídeo de Demonstração
- **Link do Vídeo (YouTube):** [https://youtu.be/bXO3D9BUsbY](https://youtu.be/bXO3D9BUsbY)

## Desenvolvedores 
- Nome: Guilherme Ciatti — RGM: 47440325
- Nome: Luyde Amorim Cerqueira — RGM: 49746952
- Nome: Gabriel Silva — RGM: 48827894
- Nome: Luiz Carlos — RGM: 48007226
- Nome: Flávia Ellen — RGM: 40600106


## Instruções para Compilação e Execução

### 1. Estrutura de Pastas Esperada
Certifique-se de que o seu projeto possui a seguinte organização:
```text
meu-projeto-c/
├── src/
│   ├── main.c
│   ├── funcoes.c
│   └── modulo.c
├── include/
│   ├── funcoes.h
│   └── modulo.h
├── data/
│   └── carteira.txt
└── README.md
