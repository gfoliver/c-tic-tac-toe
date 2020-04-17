#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

// Variavel responsavel pelos campos do tabuleiro (3 linhas e 3 colunas)
char table[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

char playerChar = 'X', winner, *currentPlayer = &playerChar, playerNames[2][20], currentPlayerName[20];
// playerChar = marca��o para o jogo
// winner = guardar� o nome do jogador ganhador para imprimir o nome dele no final do jogo
// currentPlayer = ponteiro para a marca��o
// playerNames = vari�vel respons�vel de armazenar o nome dos dois jogadores
// currentPlayerName = vari�vel que armazena o nome do jogador para exibir no final do jogo, se a rodada 
// for par ele � setado com o nome do primeiro jogador, se for �mpar � setado com o nome do segundo jogador

int inputNumber, rounds = 0;
// inputNumber = valor informado pelo jogador, se refere ao campo do tabuleiro
// rounds = n� de rodadas

// Variavel responsavel pelo fim do jogo
bool end = false;

//Fun��o respons�vel pela "setagem" dos nomes dos jogadores
void setPlayerNames(){
    // Vari�vel para o loop seguinte
	int i;

    // Loop que pega o input do nome dos jogadores
	for (i = 0; i < 2; i++) {
		printf("Player %d, type in your name: ", i + 1);
		scanf("%s", playerNames[i]);
	}
	
    // Guarda a string informada anteriormente na vari�vel currentPlayerName
	for (i = 0; i < 20; i++) {
		currentPlayerName[i] = playerNames[0][i];
	}
}

// Printa na tela o tabuleiro
void drawTable() {
	int i, j;
	
    // Loop responsavel pela impress�o do tabuleiro
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf(" %c ", table[i][j]);
		}
		
		printf("\r\n");
	}
}

// Fun��o responsavel por controlar as rodadas
void switchPlayer() {
	if (*currentPlayer == 'X')
		*currentPlayer = 'O';
	else
		*currentPlayer = 'X';

	int i;

    // Jogador n� 1 sempre jogar� em rodadas pares
    // Jogador n� 2 sempre jogar� em rodadas �mpares
	if (rounds % 2 == 0)
		for (i = 0; i < 20; i++)            
			currentPlayerName[i] = playerNames[0][i];
	else
		for (i = 0; i < 20; i++)
			currentPlayerName[i] = playerNames[1][i];
}

// Fun��o respons�vel pela entrada do jogador
void askForInput() {
    // Pede pelo input do jogador
	printf("%s Type in the number of the slot: ", currentPlayerName);
    // Recebe input
	scanf("%d", &inputNumber);
    // Chama fun��o que pega o input recebido e verifica com os campos do tabuleiro
	handleInput();
}

// Fun��o verifica se o campo do tabuleiro j� foi escolhido anteriormente
void handleInputInTable(int x, int y) {
    // Caso o campo seja 'X' ou 'O'...
	if (table[x][y] == 'X' || table[x][y] == 'O') {
        // ... � chamada a fun��o que vai pedir para o jogador informar o campo novamente
		askForInput();
	}
    // Caso n�o tenha sido escolhido ainda, o campo recebe a marca��o do jogador (X ou O)
	else {
		table[x][y] = *currentPlayer;
		rounds++;
	}
}

// Fun��o que verifica o campo do tabuleiro conforme o input mandado pelo jogador
void handleInput() {
    // Switch recebe valor da vari�vel chamada na fun��o "AskForInput"
	switch(inputNumber) {
		case 1:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(0,0);
		break;
		case 2:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(0,1);
		break;
		case 3:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(0,2);
		break;
		case 4:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(1,0);
		break;
		case 5:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(1,1);
		break;
		case 6:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(1,2);
		break;
		case 7:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(2,0);
		break;
		case 8:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(2,1);
		break;
		case 9:
            // Chama fun��o que vai verificar se o campo n�o foi escolhido anteriormente
			handleInputInTable(2,2);
		break;
		default:
		break;
	}
}

// Fun��o que parabeniza o ganhador
void congratulations() {
	system("cls");
	drawTable();
	printf("Congratulations! %s is the Winner", currentPlayerName);
}

// Fun��o que imprime na tela caso a partida n�o tenha nenhum ganhador
void endMessage() {
	system("cls");
	printf("Tie \r\n");
}

// Fun��o que verifica se algum jogador ganhou a partida
void checkWinner() {
    // Verifica se o valor dos campos da diagonal s�o iguais, se forem encerra a partida
	if (table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
		end = true;
		winner = table[0][0];
		congratulations();
		return;
	}

	// Verifica se o valor dos campos da outra diagonal s�o iguais, se forem encerra a partida
	if (table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
		end = true;
		winner = table[0][2];
		congratulations();
		return;
	}
	
	int i;
	
    // Faz a verifica��o das colunas e das linhas, se uma coluna ou uma linha 
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
	
    // Se a vari�vel de rodada chegar a 9, encerra o jogo e informa que foi empate
	if (rounds == 9) {
		end = true;
		endMessage();
	}
}

// Fun��o principal respons�vel pela chamada das fun��es que v�o construir o jogo
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
