#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "data.h"
#include "signs.h"

board_t* init_board(board_t* new, int rows, int cols){
	new = malloc(sizeof(*new));
	
	new->rows = rows;
	new->cols = cols;

	new->color = malloc(sizeof(char**) * rows);
	for(int i = 0; i < rows; i++){
		new->color[i] = malloc(sizeof(char*) * cols);
		for(int j = 0; j < cols; j++){
			new->color[i][j] = malloc(10);
			strcpy(new->color[i][j], SQUARE_WHITE);
		}
	}

	new->ant_x = cols / 2;
	new->ant_y = rows / 2;
	
	new->ant_sign = malloc(MAX_SIGN_LEN);
	strcpy(new->ant_sign, ANT_UP_WHITE);
	
	new->ant_move_x = 0;
	new->ant_move_y = -1;

	return new;
}

void free_board(board_t* board){
	for(int i = 0; i < board->rows; i++){
		for(int j = 0; j < board->cols; j++){
			free(board->color[i][j]);
		}
		free(board->color[i]);
	}
	free(board->color);

	free(board->ant_sign);
	free(board);
}
