#ifndef DATA_H_INC
#define DATA_H_INC

#include <stdlib.h>

typedef struct{
	int rows, cols;
	char*** color;
	int ant_x, ant_y;
	char* ant_sign;
	int ant_move_x, ant_move_y;
} board_t;

board_t* init_board(board_t*, int, int);

void free_board(board_t*);

#endif
