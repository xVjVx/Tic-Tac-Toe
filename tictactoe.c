#include <stdio.h>
#include <stdlib.h>

const char player_1 = 'X';
const char player_2 = 'O';

/* Show the lenght of the line */
void line(){
	printf("---+---+---\n");
}

/* Show game table */
void game_table(char* game_array){
	printf(" %c | %c | %c\n", game_array[6], game_array[7], game_array[8]);
	line();
	printf(" %c | %c | %c\n", game_array[3], game_array[4], game_array[5]);
	line();
	printf(" %c | %c | %c\n", game_array[0], game_array[1], game_array[2]);

	printf("Player 1(X), PLayer 2(O)\n");
}

void player_turn(char* game_array, char player){

	int choice = -1;
	int scanf_result;
	char buffer[16];

	while (1){
		if (fgets(buffer, 16, stdin) == NULL){
			printf("Game terminated.\n");
			exit(1);
		}
		scanf_result = sscanf(buffer, "%d", &choice);
		if (scanf_result != 1){
			printf("Invalid value, choose a number 1-9: ");
		}else if (choice <= 0 || choice > 9){
			printf("Invalid value, choose a number 1-9: ");
		}else if (game_array[choice-1] != ' '){
			printf("Cell already full, try again: ");
		}else{
			break;
		}
	}

	if (choice == 1){
		game_array[0] = player;
	}
	else if (choice == 2){
		game_array[1] = player;
	}
	else if (choice == 3){
		game_array[2] = player;
	}
	else if (choice == 4){
		game_array[3] = player;
	}
	else if (choice == 5){
		game_array[4] = player;
	} 
	else if (choice == 6){
		game_array[5] = player;
	}
	else if (choice == 7){
		game_array[6] = player;
	}
	else if (choice == 8){
		game_array[7] = player;
	} 
	else if (choice == 9){
		game_array[8] = player;
	}        
}

char check_winner(char* game_array){
	if (game_array[0] != ' ' && game_array[0] == game_array[1] && game_array[1] == game_array[2]){
		return game_array[0];
	}
	if (game_array[3] != ' ' && game_array[3] == game_array[4] && game_array[4] == game_array[5]){
		return game_array[3];
	}
	if (game_array[6] != ' ' && game_array[6] == game_array[7] && game_array[7] == game_array[8]){
		return game_array[6];
	}
	if (game_array[0] != ' ' && game_array[0] == game_array[3] && game_array[3] == game_array[6]){
		return game_array[0];
	}
	if (game_array[1] != ' ' && game_array[1] == game_array[4] && game_array[4] == game_array[7]){
		return game_array[1];
	}
	if (game_array[2] != ' ' && game_array[2] == game_array[5] && game_array[5] == game_array[8]){
		return game_array[2];
	}
	if (game_array[0] != ' ' && game_array[0] == game_array[4] && game_array[4] == game_array[8]){
		return game_array[0];
	}
	if (game_array[2] != ' ' && game_array[2] == game_array[4] && game_array[4] == game_array[6]){
		return game_array[2];
	}
	return ' ';
}

int check_draw(char* game_array){

	int i = 0;

	while(i < 9){
		if (game_array[i] == ' '){
			return 0;
		}
		i++;
	}
	return 1;
}

int main(){

	char game_array[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char player = player_2;
	char winner = ' ';

	printf("Welcome to the Tic Tac Toe game!\n\n");

	while (winner == ' '){
		game_table(game_array);
		if (player == player_1){
			player = player_2;
			printf("Player 2 (O): ");
		}else{
			player = player_1;
			printf("Player 1 (X): ");
		}
		player_turn(game_array,player);
		winner = check_winner(game_array);
		if (check_draw(game_array)){
			winner = '=';
		}	    
	}
	game_table(game_array);
	if (winner == '='){
		printf("Draw!");	    
	}else{
		printf("Player %c won the game!\n", winner);
	}
}
