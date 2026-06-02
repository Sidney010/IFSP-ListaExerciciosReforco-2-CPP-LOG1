/************************************************************************************************
* Autor: 				Sidney Campos Aragão													*
* Data:		30/05/2026																			*
* Versão:	1.0																					*
* Objetivo:																						*
*			1)- Um aluno de computação está organizando um bolão de futebol. Segundo suas		*
*		regras, os apostadores informam o placar do jogo e ganham 10 pontos se acertarem o		*
*		vencedor ou se foi empate e ganham mais 5 pontos para o placar de cada time que			*
*		acertarem. Exemplo: se o placar do jogo foi 3x2, são 0 pontos se o placar apostado foi	*
*		0x1; 5 pontos para os placares apostados 0x2 ou 3x5; 10 pontos para o placar			*
*		apostado 1x0; ou 20 pontos para o placar exato de 3x2. Faça um programa que				*
*		requisita do usuário o placar apostado e depois o placar do jogo e informa quantos		*
*		pontos o apostador fez. 																*
************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int apostaA, apostaB;
    int realA, realB;
    int pontos = 0;

    // Placar apostado
    printf("---- SEU PALPITE ----\n");
    printf("Gols do Time A: ");
    scanf("%d", &apostaA);
    printf("Gols do Time B: ");
    scanf("%d", &apostaB);

    // Placar real do jogo
    printf("\n---- PLACAR REAL DO JOGO ----\n");
    printf("Gols do Time A: ");
    scanf("%d", &realA);
    printf("Gols do Time B: ");
    scanf("%d", &realB);

    // Regra 1: Acertar o vencedor ou empate (10 pontos)
    // Caso 1: Vitória do Time A
    if ((realA > realB) && (apostaA > apostaB)) {
        pontos += 10;
    }
    // Caso 2: Vitória do Time B
    else if ((realB > realA) && (apostaB > apostaA)) {
        pontos += 10;
    }
    // Caso 3: Empate
    else if ((realA == realB) && (apostaA == apostaB)) {
        pontos += 10;
    }

    // Regra 2: Acertar os gols isolados de cada time (+5 pontos cada)
    if (apostaA == realA) {
        pontos += 5;
    }
    if (apostaB == realB) {
        pontos += 5;
    }

    // Exibir resultado final
    printf("\n-----------------------------------------\n");
    printf("Placar Apostado: %dx%d | Placar Real: %dx%d\n", apostaA, apostaB, realA, realB);
    printf("Total de pontos conquistados: %d pontos!\n", pontos);
    printf("-----------------------------------------\n");

    
}
