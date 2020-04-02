#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

char table[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char playerChar = 'X', winner, *currentPlayer = &playerChar;
int inputNumber, rounds = 0;
bool end = false;

void drawTable() {
	int i, j;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf(" %c ", table[i][j]);
		}
		
		printf("\r\n");
	}
}

void switchPlayer() {
	if (*currentPlayer == 'X')
		*currentPlayer = 'O';
	else
		*currentPlayer = 'X';
}

void askForInput() {
	printf("Type in the number of the slot: ");
	scanf("%d", &inputNumber);
}

void handleInputInTable(int x, int y) {
	if (table[x][y] == 'X' || table[x][y] == 'O') {
		return;
	}
	else {
		table[x][y] = *currentPlayer;
		switchPlayer();
		rounds++;
	}
}

void handleInput() {
	switch(inputNumber) {
		case 1:
			handleInputInTable(0,0);
		break;
		case 2:
			handleInputInTable(0,1);
		break;
		case 3:
			handleInputInTable(0,2);
		break;
		case 4:
			handleInputInTable(1,0);
		break;
		case 5:
			handleInputInTable(1,1);
		break;
		case 6:
			handleInputInTable(1,2);
		break;
		case 7:
			handleInputInTable(2,0);
		break;
		case 8:
			handleInputInTable(2,1);
		break;
		case 9:
			handleInputInTable(2,2);
		break;
	}
}

void congratulations() {
	system("cls");
	drawTable();
	printf("Congratulations! %c is the Winner", winner);
}

void endMessage() {
	system("cls");
	printf("Tie \r\n");
}

void checkWinner() {	
	if (table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
		end = true;
		winner = table[0][0];
		congratulations();
		return;
	}
	
	if (table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
		end = true;
		winner = table[0][2];
		congratulations();
		return;
	}
	
	int i;
	
	for (i = 0; i < 3; i++) {
		if (table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
			end = true;
			winner = table[i][0];
			congratulations();
			return;
		}
		
		if (table[0][i] == table[1][i] && table[1][i] == table[2][i]) {
			end = true;
			winner = table[0][i];
			congratulations();
			return;
		}
	}
	
	if (rounds == 9) {
		end = true;
		endMessage();
	}
}

void gameLoop() {
	while(end == false) {
		system("cls");
		drawTable();
		askForInput();
		handleInput();
		checkWinner();
	}
}

int main() {
	gameLoop();
}