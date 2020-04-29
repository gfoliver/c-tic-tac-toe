#include <stdio.h>
#include "setPlayerNames.h"

//Função responsável pela "setagem" dos nomes dos jogadores

void setPlayerNames(char playerNames[2][20], char currentPlayerName[20]){
    // Variável para o loop seguinte
	int i;
    // Loop que pega o input do nome dos jogadores
	for (i = 0; i < 2; i++) {
		printf("Player %d, type in your name: ", i + 1);
		scanf("%s", playerNames[i]);
		fflush(stdin);
	}
	
    // Guarda a string informada anteriormente na variável currentPlayerName
	for (i = 0; i < 20; i++) {
		currentPlayerName[i] = playerNames[0][i];
	}
}
