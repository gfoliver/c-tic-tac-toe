#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// Variavel responsavel pelos campos do tabuleiro (3 linhas e 3 colunas)
char table[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

char playerChar = 'X', winner, *currentPlayer = &playerChar, playerNames[2][20], currentPlayerName[20];
// playerChar = marcação para o jogo
// winner = guardará o nome do jogador ganhador para imprimir o nome dele no final do jogo
// currentPlayer = ponteiro para a marcação
// playerNames = variável responsável de armazenar o nome dos dois jogadores
// currentPlayerName = variável que armazena o nome do jogador para exibir no final do jogo, se a rodada 
// for par ele é setado com o nome do primeiro jogador, se for ímpar é setado com o nome do segundo jogador

int inputNumber, rounds = 0;
// inputNumber = valor informado pelo jogador, se refere ao campo do tabuleiro
// rounds = n° de rodadas

// Variavel responsavel pelo fim do jogo
bool end = false;

//Função responsá¡vel pela "setagem" dos nomes dos jogadores
void setPlayerNames(){
    // Variável para o loop seguinte
	int i;

    // Loop que pega o input do nome dos jogadores
	for (i = 0; i < 2; i++) {
		printf("Player %d, type in your name: ", i + 1);
		scanf("%s", playerNames[i]);
	}
	
    // Guarda a string informada anteriormente na variável currentPlayerName
	for (i = 0; i < 20; i++) {
		currentPlayerName[i] = playerNames[0][i];
	}
}

// Printa na tela o tabuleiro
void drawTable() {
	int i, j;
	
    // Loop responsavel pela impressão do tabuleiro
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf(" %c ", table[i][j]);
		}
		
		printf("\r\n");
	}
}

// Função responsavel por controlar as rodadas
void switchPlayer() {
	if (*currentPlayer == 'X')
		*currentPlayer = 'O';
	else
		*currentPlayer = 'X';

	int i;

    // Jogador n° 1 sempre jogará em rodadas pares
    // Jogador n° 2 sempre jogará em rodadas ímpares
	if (rounds % 2 == 0)
		for (i = 0; i < 20; i++)            
			currentPlayerName[i] = playerNames[0][i];
	else
		for (i = 0; i < 20; i++)
			currentPlayerName[i] = playerNames[1][i];
}

// Função responsável pela entrada do jogador
void askForInput() {
    // Pede pelo input do jogador
	printf("%s Type in the number of the slot: ", currentPlayerName);
    // Recebe input
	scanf("%d", &inputNumber);
    // Chama função que pega o input recebido e verifica com os campos do tabuleiro
	handleInput();
}

// Função verifica se o campo do tabuleiro já foi escolhido anteriormente
void handleInputInTable(int x, int y) {
    // Caso o campo seja 'X' ou 'O'...
	if (table[x][y] == 'X' || table[x][y] == 'O') {
        // ... é chamada a função que vai pedir para o jogador informar o campo novamente
		askForInput();
	}
    // Caso não tenha sido escolhido ainda, o campo recebe a marcação do jogador (X ou O)
	else {
		table[x][y] = *currentPlayer;
		rounds++;
	}
}

// Função que verifica o campo do tabuleiro conforme o input mandado pelo jogador
void handleInput() {
    // Switch recebe valor da variável chamada na função "AskForInput"
	switch(inputNumber) {
		case 1:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(0,0);
		break;
		case 2:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(0,1);
		break;
		case 3:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(0,2);
		break;
		case 4:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(1,0);
		break;
		case 5:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(1,1);
		break;
		case 6:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(1,2);
		break;
		case 7:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(2,0);
		break;
		case 8:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(2,1);
		break;
		case 9:
            // Chama função que vai verificar se o campo não foi escolhido anteriormente
			handleInputInTable(2,2);
		break;
		default:
		break;
	}
}

// Função que parabeniza o ganhador
void congratulations() {
	system("cls");
	drawTable();
	printf("Congratulations! %s is the Winner", currentPlayerName);
}

// Função que imprime na tela caso a partida não tenha nenhum ganhador
void endMessage() {
	system("cls");
	printf("Tie \r\n");
}

// Função que verifica se algum jogador ganhou a partida
void checkWinner() {
    // Verifica se o valor dos campos da diagonal são iguais, se forem encerra a partida
	if (table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
		end = true;
		winner = table[0][0];
		congratulations();
		return;
	}

	// Verifica se o valor dos campos da outra diagonal são iguais, se forem encerra a partida
	if (table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
		end = true;
		winner = table[0][2];
		congratulations();
		return;
	}
	
	int i;
	
    // Faz a verificação das colunas e das linhas, se uma coluna ou uma linha 
    // tiver 3 valores iguais (X ou O), encerra a partida e mostra o ganhador.
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
	
    // Se a variável de rodada chegar a 9, encerra o jogo e informa que foi empate
	if (rounds == 9) {
		end = true;
		endMessage();
	}
}

// Função principal responsável pela chamada das funções que vão construir o jogo
void gameLoop() {
	while(end == false) {
		system("cls");
		
		if (rounds == 0)
            // "Setagem" dos nomes
			setPlayerNames();
		
		system("cls");
        // Mostra tabuleiro
		drawTable();
        // Pede por valor referente ao campo do tabuleiro
		askForInput();
        // Verifica se alguem ganhou
		checkWinner();
        // Muda de rodada
		switchPlayer();
	}
}

int main() {
	gameLoop();
}
