/************************************************************************************************
* Autor: 				Sidney Campos Aragão													*
* Data:		30/05/2026																			*
* Versão:	1.0																					*
* Objetivo:																						*
*			3)- Escreva um programa para ler N (Enquanto o usuário desejar) valores fornecidos	*
*			pelo usuário e:																		*
*				a-) calcular a média aritmética entre eles.										*
*				b-) verificar qual é o maior e menor elemento entre os elementos lidos.			*
*				c-) verificar a qual faixa o elemento pertence.									*
*					Faixa 1 – Elementos < 0														*
*					Faixa 2 – Elementos >=0 e < 15												*
*					Faixa 3 – Elementos >=15 e < 100											*
*					Faixa 4 – Elementos >= 1000													*
*					Faixa 5 – Elementos >= 101 e < 1000											*
*				Contabilizar - O total de elementos por faixa - O total da faixa				*
*				e-) verificar quais deles são pares ou ímpares									*
*				f-) contabilizar - Total de Pares e o total de Ímpares							*
*				O programa deverá ser executado enquanto o usuário desejar						*
************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
	// Variaveis
    int numero;
    int total = 0;
    int soma = 0;
    int maior, menor;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;
    int totalPares = 0, totalImpares = 0;   
    
    char continuar = 's';

    printf("---- PROCESSADOR DE NUMEROS ----\n");

    while (continuar == 's' || continuar == 'S') {
        printf("\nDigite um numero inteiro: ");
        scanf("%d", &numero);

        // Maior e Menor elemento
        if (total == 0) {
            // Se for o primeiro número lido, ele é o maior e o menor ao mesmo tempo
            maior = numero;
            menor = numero;
        } else {
            if (numero > maior) maior = numero;
            if (numero < menor) menor = numero;
        }

        // Média aritmética
        soma += numero;
        total++;

        // Verificação de Par ou Ímpar
        if (numero % 2 == 0) {
            printf("O numero %d: PAR\n", numero);
            totalPares++;
        } else {
            printf("O numero %d: IMPAR\n", numero);
            totalImpares++;
        }

        // Classificação por Faixas
        if (numero < 0) {
            printf("Pertence a: Faixa 1 (Elementos < 0)\n");
            f1++;
        } 
        else if (numero >= 0 && numero < 15) {
            printf("Pertence a: Faixa 2 (Elementos >= 0 e < 15)\n");
            f2++;
        } 
        else if (numero >= 15 && numero < 100) {
            printf("Pertence a: Faixa 3 (Elementos >= 15 e < 100)\n");
            f3++;
        } 
        else if (numero >= 1000) {
            printf("Pertence a: Faixa 4 (Elementos >= 1000)\n");
            f4++;
        } 
        else { 
            printf("Pertence a: Faixa 5 (Elementos >= 100 e < 1000)\n");
            f5++;
        }

        printf("\nDeseja inserir outro numero? (s/n): ");
        scanf(" %c", &continuar); // O espaço antes de %c limpa o buffer do 'Enter'
    }

    // Exibir o resultado
    if (total > 0) {
        float media = soma / total;

        printf("\n=========================================\n");
        printf("                RESULTADO                  \n");
        printf("=========================================\n");
        printf("A) Media aritmetica: %.2f\n", media);
        printf("B) Maior elemento: %d\n", maior);
        printf("   Menor elemento: %d\n", menor);
        printf("C) e D) Total de elementos por faixa:\n");
        printf("    Faixa 1 (< 0): %d\n", f1);
        printf("    Faixa 2 (>= 0 e < 15): %d\n", f2);
        printf("    Faixa 3 (>= 15 e < 100): %d\n", f3);
        printf("    Faixa 5 (>= 100 e < 1000): %d\n", f5);
        printf("    Faixa 4 (>= 1000): %d\n", f4);
        printf("E) e F) Total de numeros Pares: %d\n", totalPares);
        printf("   		Total de numeros Impares: %d\n", totalImpares);
        printf("=========================================\n");
    } else {
        printf("\nNenhum numero foi digitado.\n");
    }

}
