#include<stdio.h>
#include<stdlib.h>

#include "data.h"

void print_board(board_t* board){
	for(int y = 0; y < board->rows; y++){
		for(int x = 0; x < board->cols; x++){
			if(y == board->ant_y && x == board->ant_x)
				printf("%s", board->ant_sign);
			else
				printf("%s", board->color[y][x]);
		}
		printf("\n");
	}
}
