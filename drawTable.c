#include "drawTable.h"
#include <stdio.h>
#include <stdlib.h>
// Printa na tela o tabuleiro
void drawTable(char table[3][3]) {
	int i, j;
	
    // Loop responsavel pela impressão do tabuleiro
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf(" %c ", table[i][j]);
		}
		
		printf("\r\n");
	}
}
