// Função que parabeniza o ganhador
void congratulations(char table[3][3], char currentPlayerName[20]) {
	system("cls");
	drawTable(table);
	printf("Congratulations! %s is the Winner", currentPlayerName);
}

// Função que imprime na tela caso a partida não tenha nenhum ganhador
void endMessage() {
	system("cls");
	printf("Tie \r\n");
}
