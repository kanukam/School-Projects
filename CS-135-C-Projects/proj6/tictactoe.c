//Name:tictactoe.c
//Author:Kennedy Anukam
//Purpose:Tic Tac Toe Game
//Created:10/20/2018
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include <stdlib.h>
#define SIZE 4

void display_table(char board[SIZE][SIZE]);
void clear_table(char board[SIZE][SIZE]);
void get_player1_move(char board[SIZE][SIZE],int row,int column);
void update_table(char board[SIZE][SIZE]);
void generate_player2_move(char board[SIZE][SIZE],int row,int column);
bool check_table_full(char board[SIZE][SIZE]);
bool check_legal_option(char board[SIZE][SIZE],int row,int column);
bool check_end_of_game(char board[SIZE][SIZE]);
int check_three_in_a_row(char board[SIZE][SIZE]);
void print_winner(char board[SIZE][SIZE]);

int main ()
{
//Declare the tic-tac-toe board
char board[SIZE][SIZE];
//The row and column of the move for either player 1 or 2
int row, col;
//Clear the table
clear_table(board);
//Display the table
display_table(board);
do
{
	//Have player 1 enter their move
	get_player1_move(board, row, col);
	//Generate player 2 move
	generate_player2_move(board, row, col);
	//Do this while the game hasn't ended
}while(check_end_of_game(board) == false);
//After the game is over, print who won
print_winner(board);
return 0;
}
//displays the board and prints a space as a dash, O's with a space and X's with a space
void display_table(char board[SIZE][SIZE])
{ 	
	printf("The current state of the game is: \n");
	for(int i = 1;i < SIZE;i++)
	{
		for(int j = 1;j < SIZE;j++)
		{
			if(board[i][j] == ' ')
			{
				printf("_ ");
			}
			else if(board[i][j] == 'O')
			{
				printf("O ");
			}
			else if(board[i][j] == 'X')
			{
				printf("X ");
			}
		}
	printf("\n");
	}
	
}
//Initializes all spaces to empty to begin
void clear_table(char board[SIZE][SIZE])
{
	for(int i = 1;i < SIZE;i++)
	{
		for(int j = 1;j < SIZE;j++)
		{
			board[i][j]=' ';
		}
	}
}
// Sees if table is full or not
bool check_table_full(char board[SIZE][SIZE])
{
	for(int i=1;i<SIZE;i++)
	{
		for(int j=1;j<SIZE;j++)
		{
			if(board[i][j]==' ')
			{
				return false;
			}
		}
	}
	return true;
}
//Updates Player 1 and 2s move with O or X
void update_table(char board[SIZE][SIZE])
{
	for(int i = 1;i < SIZE;i++)
	{
		for(int j = 1;j < SIZE;j++)
		{
			if(board[i][j] == 'z')
			{
				board[i][j]='O';
			}
			else if(board[i][j] == 'p')
			{
				board[i][j]='X';
			}
		}
	}
}
//sees if array space is empty or not, returns true or false
bool check_legal_option(char board[SIZE][SIZE],int row,int column)
{
	return board[row][column]==' '?true:false;
}	
//three in a row,correlated with check end of game
int check_three_in_a_row(char board[SIZE][SIZE])
{
	int row;
	int column;
	//Checks Horizontally
	for(row=1;row<SIZE;row++)
	{
			if((board[row][1] == 'O') && (board[row][2] == 'O') && (board[row][3] == 'O'))
			{
				return 1;
			}
			else if((board[row][1] == 'X') && (board[row][2] == 'X') && (board[row][3] == 'X'))
			{
				return 2;
			}
	}
	//Checks Vertically
	for(column=1;column<SIZE;column++)
	{
		if((board[1][column] == 'O') && (board[2][column] == 'O') && (board[3][column] == 'O'))
		{
			return 1;
		}
		else if((board[1][column] == 'X') && (board[2][column] == 'X') && (board[3][column] == 'X'))
		{
			return 2;
		}
	}
	//Diagnolly
	if((board[1][1] == 'O') && (board[2][2] == 'O') && (board[3][3] == 'O'))
	{
		return 1;
	}
	else if((board[1][1] == 'X') && (board[2][2] == 'X') && (board[3][3] == 'X'))
	{
		return 2;
	}
	//Second Diagnol
	else if((board[1][3] == 'O') && (board[2][2] == 'O') && (board[3][1] == 'O'))
	{
		return 1;
	}
	else if((board[1][3] == 'X') && (board[2][2] == 'X') && (board[3][1] == 'X'))
	{
		return 2;
	}
	return 0;
	
}
//Player 2(computer)
void generate_player2_move(char board[SIZE][SIZE],int row,int column)
{
	if(check_end_of_game(board) == false)
	{
		srand((unsigned) time(NULL));
		row= rand() % SIZE;
		column= rand() % SIZE;
		while(check_legal_option(board,row,column)== false)
		{
			row= rand() % SIZE;
			column= rand() % SIZE;
		}       
		printf("Player 2 has entered [row, col]: %d,%d\n",row,column);
		board[row][column]='p';
		update_table(board);
		display_table(board);
	}
}
// conditions that can end the gamw
bool check_end_of_game(char board[SIZE][SIZE])
{
	if(check_table_full(board) == true || check_three_in_a_row(board) == 1 || check_three_in_a_row(board) == 2)
	{
		return true;
	}
	else if(check_three_in_a_row(board) == 0 || check_table_full(board) == false)
	{
		return false;
	}
}	
//player 1(user)
void get_player1_move(char board[SIZE][SIZE],int row,int column)
{
	if(check_end_of_game(board) == false)
	{
		printf("Player 1 enter your selection [row, col]: ");
		scanf("%d,%d",&row,&column);
		while(check_legal_option(board,row,column)== false)
		{
			printf("Player 1 enter your selection [row, col]: ");
			scanf("%d,%d",&row,&column);
		}
		board[row][column]='z';
		update_table(board);
		display_table(board);
	} 
}
void print_winner(char board[SIZE][SIZE])
{
	if(check_three_in_a_row(board)== 1)
	{
		printf("Congratulations, Player 1 wins!\n");
	}
	else if(check_three_in_a_row(board)== 2)
	{
		printf("Congratulations, Player 2 wins!\n");
	}
	else if(check_three_in_a_row(board)== 0 && check_end_of_game(board) == true)
	{
		printf("Game over, no player wins.\n");
	}
}
	