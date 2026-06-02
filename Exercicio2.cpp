/************************************************************************************************
* Autor: 				Sidney Campos Aragão													*
* Data:		30/05/2026																			*
* Versão:	1.0																					*
* Objetivo:																						*
*			2)- A empresa XYZ decidiu conceder um aumento de salários a seus funcionários de	*
*			acordo com a tabela abaixo:															*
*				SALÁRIO ATUAL (R$) ÍNDICE DE AUMENTO 0,00 – 400,00 15% 401,00 – 700,00			*
*				12% 701,00 – 1000,00 10% 1001,00 – 1800,00 7% 1801,00 – 2500,00 4% ACIMA		*
*				DE 2500,00 SEM AUMENTO															*
*			Escrever um algoritmo que lê, para cada funcionário, o seu nome e o seu salário		*
* 			atual. Após receber estes dados, o algoritmo calcula o novo salário e escreve na 	*
*			tela as	seguintes informações: ? nome do funcionário ? % de aumento ? salário atual *
*			? novo salário 																		*
************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[50];
    float salarioAtual, novoSalario;
    float percentual = 0.0;

    // Entrada de dados
    printf("Digite o nome do funcionario: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite o salario atual (R$): ");
    scanf("%f", &salarioAtual);

    // Determina do percentual de aumento com base na tabela
    if (salarioAtual >= 0.0 && salarioAtual <= 400.0) {
        percentual = 15.0;
    } 
    else if (salarioAtual > 400.0 && salarioAtual <= 700.0) {
        percentual = 12.0;
    } 
    else if (salarioAtual > 700.0 && salarioAtual <= 1000.0) {
        percentual = 10.0;
    } 
    else if (salarioAtual > 1000.0 && salarioAtual <= 1800.0) {
        percentual = 7.0;
    } 
    else if (salarioAtual > 1800.0 && salarioAtual <= 2500.0) {
        percentual = 4.0;
    } 
    else {
        percentual = 0.0; // Acima de 2500.00 sem aumento
    }

    // Calculo do novo salário
    novoSalario = salarioAtual + (salarioAtual * (percentual / 100.0));

    // Exibi dos resultados formatados
    printf("\n=========================================\n");
    printf("                REAJUSTE               \n");
    printf("=========================================\n");
    printf("Nome do funcionario: %s\n", nome);
    printf("Percentual de aumento: %.0f%%\n", percentual);
    printf("Salario atual: R$ %.2f\n", salarioAtual);
    printf("Novo salario:   R$ %.2f\n", novoSalario);
    printf("=========================================\n");

}
