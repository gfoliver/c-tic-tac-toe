#include "messages.h"
#include <stdio.h>
#include <stdlib.h>
// Fun��o que parabeniza o ganhador
void congratulations(char table[3][3], char currentPlayerName[20]) {
	system("cls");
	drawTable(table);
	printf("Congratulations! %s is the Winner", currentPlayerName);
}

// Fun��o que imprime na tela caso a partida n�o tenha nenhum ganhador
void endMessage() {
	system("cls");
	printf("Tie \r\n");
}
