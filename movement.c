#include<stdio.h>
#include<string.h>

#include "data.h"
#include "signs.h"
#include "movement.h"

void move(board_t* board){
	// zmiana koloru pola
	char* prev_color = malloc(MAX_SIGN_LEN);
	strcpy(prev_color, board->color[board->ant_y][board->ant_x]);

	if(strcmp(prev_color, SQUARE_BLACK) == 0)
		strcpy(board->color[board->ant_y][board->ant_x], SQUARE_WHITE);
	else
		strcpy(board->color[board->ant_y][board->ant_x], SQUARE_BLACK);
	
	// rotacja mrowki
	char* dir = malloc(6);
	if(strcmp(prev_color, SQUARE_WHITE) == 0)
		strcpy(dir, "right");
	else
		strcpy(dir, "left");
	
	rotate_ant(board, dir);
	
	// przesuniecie mrowki
	board->ant_x += board->ant_move_x;
	board->ant_y += board->ant_move_y;
	
	// zmiana koloru mrowki
	change_ant_color(board);
	

	free(dir);
	free(prev_color);
}

int is_black(board_t* board, int row, int col){
	if(strcmp(board->color[row][col], SQUARE_BLACK) == 0)
		return 1;
	return 0;
}

void rotate_ant(board_t* board, char* dir){
	// mam nadzieje ze da sie latwiej i ladniej 
	// stworzyc fajna liste

	char* ant = board->ant_sign;

	if(strcmp(dir, "right") == 0){
		if(strcmp(ant, ANT_UP_WHITE) == 0){
			strcpy(ant, ANT_RIGHT_WHITE);
			board->ant_move_y = 0;
			board->ant_move_x = 1;
		}
		else if(strcmp(ant, ANT_UP_BLACK) == 0){
			strcpy(ant, ANT_RIGHT_BLACK);
			board->ant_move_y = 0;
			board->ant_move_x = 1;
		}
		else if(strcmp(ant, ANT_RIGHT_WHITE) == 0){
			strcpy(ant, ANT_DOWN_WHITE);
			board->ant_move_y = 1;
			board->ant_move_x = 0;
		}
		else if(strcmp(ant, ANT_RIGHT_BLACK) == 0){
			strcpy(ant, ANT_DOWN_BLACK);
			board->ant_move_y = 1;
			board->ant_move_x = 0;
		}
		else if(strcmp(ant, ANT_DOWN_WHITE) == 0){
			strcpy(ant, ANT_LEFT_WHITE);
			board->ant_move_y = 0;
			board->ant_move_x = -1;
		}
		else if(strcmp(ant, ANT_DOWN_BLACK) == 0){
			strcpy(ant, ANT_LEFT_BLACK);
			board->ant_move_y = 0;
			board->ant_move_x = -1;
		}
		else if(strcmp(ant, ANT_LEFT_WHITE) == 0){
			strcpy(ant, ANT_UP_WHITE);
			board->ant_move_y = -1;
			board->ant_move_x = 0;
		}
		else if(strcmp(ant, ANT_LEFT_BLACK) == 0){
			strcpy(ant, ANT_UP_BLACK);
			board->ant_move_y = -1;
			board->ant_move_x = 0;
		}
	}
	else{
		if(strcmp(ant, ANT_UP_WHITE) == 0){
			strcpy(ant, ANT_LEFT_WHITE);
			board->ant_move_y = 0;
			board->ant_move_x = -1;
		}
		else if(strcmp(ant, ANT_UP_BLACK) == 0){
			strcpy(ant, ANT_LEFT_BLACK);

			board->ant_move_y = 0;
			board->ant_move_x = -1;
		}
		else if(strcmp(ant, ANT_RIGHT_WHITE) == 0){
			strcpy(ant, ANT_UP_WHITE);
			board->ant_move_y = -1;
			board->ant_move_x = 0;
		}
		else if(strcmp(ant, ANT_RIGHT_BLACK) == 0){
			strcpy(ant, ANT_UP_BLACK);
			board->ant_move_y = -1;
			board->ant_move_x = 0;
		}
		else if(strcmp(ant, ANT_DOWN_WHITE) == 0){
			strcpy(ant, ANT_RIGHT_WHITE);
			board->ant_move_y = 0;
			board->ant_move_x = 1;
		}
		else if(strcmp(ant, ANT_DOWN_BLACK) == 0){
			strcpy(ant, ANT_RIGHT_BLACK);
			board->ant_move_y = 0;
			board->ant_move_x = 1;
		}
		else if(strcmp(ant, ANT_LEFT_WHITE) == 0){
			strcpy(ant, ANT_DOWN_WHITE);
			board->ant_move_y = 1;
			board->ant_move_x = 0;
		}
		else if(strcmp(ant, ANT_LEFT_BLACK) == 0){
			strcpy(ant, ANT_DOWN_BLACK);
			board->ant_move_y = 1;
			board->ant_move_x = 0;
		}
	}
}

void change_ant_color(board_t* board){
	char* ant = board->ant_sign;
	
	if(strcmp(board->color[board->ant_y][board->ant_x], SQUARE_BLACK) == 0){
		if(strcmp(ant, ANT_UP_WHITE) == 0){
			strcpy(ant, ANT_UP_BLACK);
		}
		else if(strcmp(ant, ANT_RIGHT_WHITE) == 0){
			strcpy(ant, ANT_RIGHT_BLACK);
		}
		else if(strcmp(ant, ANT_DOWN_WHITE) == 0){
			strcpy(ant, ANT_DOWN_BLACK);
		}
		else if(strcmp(ant, ANT_LEFT_WHITE) == 0){
			strcpy(ant, ANT_LEFT_BLACK);
		}
	}
	else{
		if(strcmp(ant, ANT_UP_BLACK) == 0){
			strcpy(ant, ANT_UP_WHITE);
		}
		else if(strcmp(ant, ANT_RIGHT_BLACK) == 0){
			strcpy(ant, ANT_RIGHT_WHITE);
		}
		else if(strcmp(ant, ANT_DOWN_BLACK) == 0){
			strcpy(ant, ANT_DOWN_WHITE);
		}
		else if(strcmp(ant, ANT_LEFT_BLACK) == 0){
			strcpy(ant, ANT_LEFT_WHITE);
		}
	}
}
