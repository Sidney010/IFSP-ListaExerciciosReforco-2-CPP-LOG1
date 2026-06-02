/************************************************************************************************
* Autor: 				Sidney Campos Aragão													*
* Data:		30/05/2026																			*
* Versão:	1.0																					*
* Objetivo:																						*
*			4)- Criar um programa em C que cadastre funcionários de uma empresa, com nome,		*
*			idade e salário. Opções do menu:													*
*				Cadastro																		*
*				Salvamento e leitura de arquivo (func.txt);										*
*				Busca de funcionário pela idade.												*
*				Ordenação de todos os funcionários por nome em ordem alfabética (usando strcmp).*
*				Sair																			*
************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FUNC 100 // constante

typedef struct {
	int id;
	char nome[80];
	int idade;
	float salario;
} Funcionario;

//Cadastro
void cadastrar(Funcionario *lista, int *total) {
	if (*total >= MAX_FUNC) {
		printf("\n[ERRO] Limite maximo de funcionarios atingido!\n");
		return;
	}
	
	printf("\n=========================================\n");
	printf("               CADASTRO                  \n");
	printf("=========================================\n");
	
	lista[*total].id = *total + 1; // ID  sequencial
	
	printf("Nome do funcionario: ");
	scanf(" %[^\n]", lista[*total].nome);
	
	printf("Idade: ");
	scanf("%d", &lista[*total].idade);
	
	printf("Salario (R$): ");
	scanf("%f", &lista[*total].salario);
	
	(*total)++; // Contador de funcionários
	printf("\nFuncionario cadastrado com sucesso!\n");
}

// Salvamento em Arquivo
void salvarArquivo(Funcionario *lista, int total) {
	FILE *arquivo = fopen("func.txt", "w"); // escrita 
	if (arquivo == NULL) {
		printf("\n[ERRO] Nao foi possivel criar/abrir o arquivo func.txt\n");
		return;
	}
	
	// Grava o total de funcionários na primeira linha para facilitar a leitura depois
	fprintf(arquivo, "%d\n", total);
	
	for (int i = 0; i < total; i++) {
		fprintf(arquivo, "%d;%s;%d;%.2f\n", lista[i].id, lista[i].nome, lista[i].idade, lista[i].salario);
	}
	
	fclose(arquivo);
	printf("\nDados salvos com sucesso no arquivo 'func.txt'!\n");
}

// Leitura de Arquivo
void lerArquivo(Funcionario *lista, int *total) {
	FILE *arquivo = fopen("func.txt", "r");
	if (arquivo == NULL) {
		printf("\n[AVISO] Arquivo 'func.txt' nao encontrado. Iniciando banco de dados vazio.\n");
		return;
	}
	
	// Lê quantos registros existem gravados
	if (fscanf(arquivo, "%d\n", total) != 1) {
		*total = 0;
	}
	
	for (int i = 0; i < *total; i++) {
		// Lê os dados formatados separados por ponto e vírgula
		fscanf(arquivo, "%d;%[^;];%d;%f\n", &lista[i].id, lista[i].nome, &lista[i].idade, &lista[i].salario);
	}
	
	fclose(arquivo);
	printf("\nArquivo 'func.txt' carregado com sucesso! (%d cadastros encontrados)\n", *total);
}

// Busca por Idade
void buscarPorIdade(Funcionario *lista, int total) {
	int idadeBusca;
	int encontrado = 0;
	
	printf("\nDigite a idade para busca: ");
	scanf("%d", &idadeBusca);
	
	printf("\n--- RESULTADOS DA BUSCA ---\n");
	for (int i = 0; i < total; i++) {
		if (lista[i].idade == idadeBusca) {
			printf("ID: %d | Nome: %s | Salario: R$ %.2f\n", lista[i].id, lista[i].nome, lista[i].salario);
			encontrado = 1;
		}
	}
	
	if (!encontrado) {
		printf("Nenhum funcionario encontrado com %d anos.\n", idadeBusca);
	}
	printf("---------------------------\n");
}

// Ordenação Alfabética por Nome (Bubble Sort com strcmp)
void ordenarPorNome(Funcionario *lista, int total) {
	Funcionario temp;
	
	for (int i = 0; i < total - 1; i++) {
		for (int j = i + 1; j < total; j++) {
			// strcmp retorna um valor > 0 se a primeira string for alfabeticamente maior que a segunda
			if (strcmp(lista[i].nome, lista[j].nome) > 0) {
				// Troca a struct inteira de posição
				temp = lista[i];
				lista[i] = lista[j];
				lista[j] = temp;
			}
		}
	}
	printf("\nFuncionarios ordenados com sucesso por ordem alfabetica!\n");
}

// Função exibir a lista na tela
void listarTodos(Funcionario *lista, int total) {
	if (total == 0) {
		printf("\nNenhum funcionario cadastrado na memoria.\n");
		return;
	}
	printf("\n--- LISTA ATUAL DE FUNCIONARIOS ---\n");
	for (int i = 0; i < total; i++) {
		printf("ID: %d | Nome: %-20s | Idade: %d | Salario: R$ %.2f\n", lista[i].id, lista[i].nome, lista[i].idade, lista[i].salario);
	}
	printf("-----------------------------------\n");
}

int main() {
	Funcionario bancoDados[MAX_FUNC];
	int totalFuncionarios = 0;
	int opcao = 0;
	
	// Carrega dados salvos anteriormente de forma automática ao abrir o programa
	lerArquivo(bancoDados, &totalFuncionarios);
	
	do {
		printf("\n========== MENU XYZ ==========\n");
		printf("1 - Cadastrar Funcionario\n");
		printf("2 - Salvar Dados (func.txt)\n");
		printf("3 - Buscar por Idade\n");
		printf("4 - Ordenar por Nome (Alfabetica)\n");
		printf("5 - Listar Todos na Memoria\n");
		printf("6 - Sair\n");
		printf("==============================\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				cadastrar(bancoDados, &totalFuncionarios);
				break;
			case 2:
				salvarArquivo(bancoDados, totalFuncionarios);
				break;
			case 3:
				buscarPorIdade(bancoDados, totalFuncionarios);
				break;
			case 4:
				ordenarPorNome(bancoDados, totalFuncionarios);
				break;
			case 5:
				listarTodos(bancoDados, totalFuncionarios);
				break;
			case 6:
				printf("\nSaindo do sistema...\n");
				break;
			default:
				printf("\n[AVISO] Opcao invalida! Tente novamente.\n");
		}
	} while (opcao != 6);
	

}
