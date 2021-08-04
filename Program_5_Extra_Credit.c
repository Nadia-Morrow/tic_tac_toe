/* This program is written by Nadia Morrow for CS 1310 V. This is 
*Program 4. This is a C program that enables one or two players to 
*play tic-tac-toe.
*Start Date: Oct. 21, 2020
*Last Motified: Oct. 22,2020
*/

#include <stdio.h>

char ttt[3][3];
int moveCount = 0;
int win = 0;
int move;
int row;
int column;
char player;
int numPlayers;

//Prints the Tic-Tac-Toe Board
void printBoard(void)
{
	printf("This is what the tic-tac-toe board looks like.\n");
	printf("       Board               Key    \n"); 
	printf("  %c  *  %c  *  %c    1  *  2  *  3  \n", ttt[0][0],ttt[0][1],ttt[0][2]);  //prints a board that references the first row in array
	printf("  %c  *  %c  *  %c    4  *  5  *  6  \n", ttt[1][0],ttt[1][1],ttt[1][2]);  //prints a board that references the middle row in array
	printf("  %c  *  %c  *  %c    7  *  8  *  9  \n", ttt[2][0],ttt[2][1],ttt[2][2]);  //prints a board that references the last row in array
}

//Determines whether move is valid
void validMove(void)
{
	int flag = 0;
	while (flag == 0) {
		if (player == 'X') 
		{
			printf("Player 1 \n");
		}
		else
		{
			printf("Player 2 \n");
		}
		printf("Choose your space: ");
		scanf("%d", &move);
		switch (move){
			case 1:
				row = 0;
				column = 0;
				break;
			case 2:
				row = 0;
				column = 1;
				break;
			case 3:
				row = 0;
				column = 2;
				break;
			case 4:
				row = 1;
				column = 0;
				break;
			case 5:
				row = 1;
				column = 1;
				break;
			case 6:
				row = 1;
				column = 2;
				break;
			case 7:
				row = 2;
				column = 0;
				break;
			case 8:
				row = 2;
				column = 1;
				break;
			case 9:
				row = 2;
				column = 2;
				break;
			default:
				 printf("Hun, this is not a choice. Choose again.");
				 
		}
		if ((ttt[row][column]==' ') && (move >= 1) && (move <= 9)){
			ttt[row][column] = player;
			moveCount ++;
			flag = 1;
		
		}
		else {
			printf("You selected a square that has already been played. Try one more time.\n");
		}
	}
}

//creates a clear board
void blankBoard(void){
	for(row = 0; row < 3;++row){
		for(column = 0; column < 3; ++column){
			ttt[row][column] = ' ';
		}
	}
}

//changes players
void changePlayer(void) {
	if (player == 'X'){
		player = 'O';
	}
	else{
		player = 'X';
	}
}

//checks the board to see who wins
void checkWin (void){
	if (ttt[0][0] == 'X' && ttt[0][1] == 'X' && ttt[0][2] == 'X'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][0] == 'O' && ttt[0][1] == 'O' && ttt[0][2] == 'O'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[1][0] == 'X' && ttt[1][1] == 'X' && ttt[1][2] == 'X'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[1][0] == 'O' && ttt[1][1] == 'O' && ttt[1][2] == 'O'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[2][0] == 'X' && ttt[2][1] == 'X' && ttt[2][2] == 'X'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][0] == 'X' && ttt[1][0] == 'X' && ttt[2][0] == 'X'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][0] == 'O' && ttt[1][0] == 'O' && ttt[2][0] == 'O'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][1] == 'X' && ttt[1][1] == 'X' && ttt[2][1] == 'X'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][1] == 'O' && ttt[1][1] == 'O' && ttt[2][1] == 'O'){	
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][2] == 'X' && ttt[1][2] == 'X' && ttt[2][2] == 'X'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][2] == 'O' && ttt[1][2] == 'O' && ttt[2][2] == 'O'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][0] == 'X' && ttt[1][1] == 'X' && ttt[2][2] == 'X'){	
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][0] == 'O' && ttt[1][1] == 'O' && ttt[2][2] == 'O'){	
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][2] == 'X' && ttt[1][1] == 'X' && ttt[2][0] == 'X'){
		win = 1;
		printf("Player %c won!!\n", player);
	}else if(ttt[0][2] == 'O' && ttt[1][1] == 'O' && ttt[2][0] == 'O'){
		win = 1;
		printf("Player %c won!!\n", player);
	}
	else if (moveCount == 9)  {
			printf("We have got chicken scratch! :O\n");
		}
	} 


//resets the game
void resetGame (void) {
	blankBoard();
	moveCount = 0;
	win = 0;
}

//Picks random number for computer player
void pickRandomNum(void){
	srand(time(NULL));
	move = 1 + (rand()% 9);
}

//Checking validity of computer choosen move
void computerValidMove(void){
	int flag = 0;
	while (flag == 0) {
		switch (move) {
			case 1:
				row = 0;
				column = 0;
				break;
			case 2:
				row = 0;
				column = 1;
				break;
			case 3:
				row = 0;
				column = 2;
				break;
			case 4:
				row = 1;
				column = 0;
				break;
			case 5:
				row = 1;
				column = 1;
				break;
			case 6:
				row = 1;
				column = 2;
				break;
			case 7:
				row = 2;
				column = 0;
				break;
			case 8:
				row = 2;
				column = 1;
				break;
			case 9:
				row = 2;
				column = 2;
				break;
			default:
				printf(" ");
		}
		if (ttt[row][column] == ' '){
			ttt[row][column] = player;
			moveCount ++;
			flag = 1;
		}
		else {
			pickRandomNum();
		}
		
	}
}

void main (void)
{
	char stillPlaying = 'y';
	player = 'X';
	blankBoard();
	printf("Welcome to Nadia's Tic-Tac-Toe Game. :)\n");
	printf("The rules are simple. \nIf you get your character in three consecutive spaces, diagnoally,veritcally or horizontally, then you win. \nIf neither player wins then the game is chicken scratch(better known as a tie). \nEvery spot can only have one X or O. Play fair and have fun!\n");
	printf("How many players are there? ");
	scanf("%d", &numPlayers);
		while (numPlayers != 1 && numPlayers != 2)
		{
			printf("This game only supports 1 or 2 players. Choose again: ");
			scanf("%d", &numPlayers);
		}
		while (stillPlaying == 'y' && moveCount < 9)
		 {
			resetGame();
			while (win == 0 && moveCount < 9) 
			{
				if (numPlayers == 1)
				{
					printBoard();
					if (player == 'O')
					{
						pickRandomNum();
						computerValidMove();
					}
					else 
					{
						validMove();
					}
					checkWin();
					changePlayer();
				}
				else 
				{
					printBoard();
					validMove();
					checkWin();
					changePlayer();
				}
			}
			printf("Would you like to play again? Choose y for yes and n for no: ");
			scanf(" %c", &stillPlaying);
		}

}

