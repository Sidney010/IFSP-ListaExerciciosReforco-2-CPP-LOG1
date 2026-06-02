/************************************************************************************************
* Autor: 				Sidney Campos Aragão													*
* Data:		30/05/2026																			*
* Versão:	1.0																					*
* Objetivo:																						*
*		 4) Criar um programa em C que cadastre de alunos com nome, matrícula e 3 notas			*
*			Cálculo da média e situação (Aprovado ou Reprovado, média acima de 6,0);			*
*			Salvamento e leitura de arquivo (alunos.txt);										*
*			Busca de aluno pelo número da matrícula.											*
*			Ordenação de todos os alunos por nome em ordem alfabética (usando strcmp).			*
*			Apresenta apenas quem foi aprovado ou reprovado.									*
*				Menu com as seguintes (switch/case):											*
*					1- Cadastro de alunos														*
*					2- Listagem de todos os alunos												*
*					3- Busca por matrícula														*
*					4- Ordenação alfabética														*
*					5- Relatório aprovados e reprovados											*
*					6- Sair																		*
************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 100 //constante

typedef struct {
    int matricula;
    char nome[80];
    float notas[3];
    float media;
    char situacao[12]; // "Aprovado" ou "Reprovado"
} Aluno;

// Cadastro de Alunos
void cadastrarAluno(Aluno *lista, int *total) {
    if (*total >= MAX_ALUNOS) {
        printf("\n[ERRO] Limite maximo de alunos atingido!\n");
        return;
    }

    printf("\n=========================================\n");
    printf("            CADASTRO DE ALUNO            \n");
    printf("=========================================\n");

    printf("Numero da Matricula: ");
    scanf("%d", &lista[*total].matricula);

    printf("Nome do aluno: ");
    scanf(" %[^\n]", lista[*total].nome);

    float somaNotas = 0.0;
    for (int i = 0; i < 3; i++) {
        printf("Digite a %dª nota: ", i + 1);
        scanf("%f", &lista[*total].notas[i]);
        somaNotas += lista[*total].notas[i];
    }

    // Calcula a média e define a situação do aluno
    lista[*total].media = somaNotas / 3.0;
    if (lista[*total].media >= 6.0) {
        strcpy(lista[*total].situacao, "Aprovado");
    } else {
        strcpy(lista[*total].situacao, "Reprovado");
    }

    (*total)++;
    printf("\nAluno cadastrado com sucesso!\n");
}

// Listagem de Todos os Alunos
void listarTodosAlunos(Aluno *lista, int total) {
    if (total == 0) {
        printf("\nNenhum aluno cadastrado na memoria.\n");
        return;
    }

    printf("\n====================================================================\n");
    printf("                     LISTA GERAL DE ALUNOS                          \n");
    printf("====================================================================\n");
    printf("%-10s | %-20s | %-15s | %-10s\n", "MATRICULA", "NOME", "NOTAS", "MEDIA");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("%-10d | %-20s | [%.1f, %.1f, %.1f] | %-10.2f\n", 
               lista[i].matricula, 
               lista[i].nome, 
               lista[i].notas[0], lista[i].notas[1], lista[i].notas[2], 
               lista[i].media);
    }
    printf("====================================================================\n");
}

// Busca por Matrícula
void buscarPorMatricula(Aluno *lista, int total) {
    int matBusca;
    int encontrado = 0;

    printf("\nDigite o numero da matricula para busca: ");
    scanf("%d", &matBusca);

    for (int i = 0; i < total; i++) {
        if (lista[i].matricula == matBusca) {
            printf("\n--- ALUNO ENCONTRADO ---\n");
            printf("Matricula: %d\n", lista[i].matricula);
            printf("Nome: %s\n", lista[i].nome);
            printf("Notas: %.1f, %.1f, %.1f\n", lista[i].notas[0], lista[i].notas[1], lista[i].notas[2]);
            printf("Media: %.2f\n", lista[i].media);
            printf("Situacao: %s\n", lista[i].situacao);
            printf("------------------------\n");
            encontrado = 1;
            break; // Como a matrícula é única, podemos parar o laço
        }
    }

    if (!encontrado) {
        printf("\n[AVISO] Aluno com matricula %d nao encontrado.\n", matBusca);
    }
}

// Ordenação Alfabética por Nome (Bubble Sort com strcmp)
void ordenarPorNome(Aluno *lista, int total) {
    Aluno temp;

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (strcmp(lista[i].nome, lista[j].nome) > 0) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
    printf("\nAlunos ordenados por ordem alfabetica com sucesso!\n");
}

// Aprovados e Reprovados
void relatorioSituacao(Aluno *lista, int total) {
    if (total == 0) {
        printf("\nNenhum aluno cadastrado na memoria.\n");
        return;
    }

    int opcaoRelatorio;
    printf("\nQual relatorio deseja visualizar?\n");
    printf("1 - Apenas Aprovados\n");
    printf("2 - Apenas Reprovados\n");
    printf("Escolha: ");
    scanf("%d", &opcaoRelatorio);

    printf("\n====================================================================\n");
    if (opcaoRelatorio == 1) {
        printf("                     RELATORIO: ALUNOS APROVADOS                    \n");
    } else {
        printf("                     RELATORIO: ALUNOS REPROVADOS                   \n");
    }
    printf("====================================================================\n");
    printf("%-10s | %-20s | %-10s | %-10s\n", "MATRICULA", "NOME", "MEDIA", "SITUACAO");
    printf("--------------------------------------------------------------------\n");

    int cont = 0;
    for (int i = 0; i < total; i++) {
        if ((opcaoRelatorio == 1 && strcmp(lista[i].situacao, "Aprovado") == 0) ||
            (opcaoRelatorio == 2 && strcmp(lista[i].situacao, "Reprovado") == 0)) {
            
            printf("%-10d | %-20s | %-10.2f | %-10s\n", 
                   lista[i].matricula, lista[i].nome, lista[i].media, lista[i].situacao);
            cont++;
        }
    }

    if (cont == 0) {
        printf("Nenhum aluno nesta situacao.\n");
    }
    printf("====================================================================\n");
}

// Manipulação de Arquivo (Salvamento Automático)
void salvarArquivo(Aluno *lista, int total) {
    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) return;

    fprintf(arquivo, "%d\n", total);
    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%d;%s;%.1f;%.1f;%.1f;%.2f;%s\n", 
                lista[i].matricula, lista[i].nome, 
                lista[i].notas[0], lista[i].notas[1], lista[i].notas[2], 
                lista[i].media, lista[i].situacao);
    }
    fclose(arquivo);
}

void lerArquivo(Aluno *lista, int *total) {
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        *total = 0;
        return;
    }

    if (fscanf(arquivo, "%d\n", total) != 1) {
        *total = 0;
    }

    for (int i = 0; i < *total; i++) {
        fscanf(arquivo, "%d;[^;];%f;%f;%f;%f;%[^\n]\n", 
               &lista[i].matricula, lista[i].nome, 
               &lista[i].notas[0], &lista[i].notas[1], &lista[i].notas[2], 
               &lista[i].media, lista[i].situacao);
    }
    fclose(arquivo);
}

int main() {
    Aluno escola[MAX_ALUNOS];
    int totalAlunos = 0;
    int opcao = 0;

    // Carrega os dados automaticamente do arquivo ao abrir o programa
    lerArquivo(escola, &totalAlunos);

    do {
        printf("\n========== SISTEMA ESCOLAR ==========\n");
        printf("1 - Cadastro de alunos\n");
        printf("2 - Listagem de todos os alunos\n");
        printf("3 - Busca por matricula\n");
        printf("4 - Ordenacao alfabetica\n");
        printf("5 - Relatorio aprovados e reprovados\n");
        printf("6 - Sair (e Salvar)\n");
        printf("=====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarAluno(escola, &totalAlunos);
                break;
            case 2:
                listarTodosAlunos(escola, totalAlunos);
                break;
            case 3:
                buscarPorMatricula(escola, totalAlunos);
                break;
            case 4:
                ordenarPorNome(escola, totalAlunos);
                break;
            case 5:
                relatorioSituacao(escola, totalAlunos);
                break;
            case 6:
                salvarArquivo(escola, totalAlunos);
                printf("\nDados salvos em 'alunos.txt'. Fechando programa...\n");
                break;
            default:
                printf("\n[AVISO] Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 6);

}

