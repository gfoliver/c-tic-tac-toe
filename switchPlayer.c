// Fun��o responsavel por controlar as rodadas
void switchPlayer(char *currentPlayer, char currentPlayerName[20], char playerNames[2][20], int rounds) {
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
