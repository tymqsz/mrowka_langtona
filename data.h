#ifndef DATA_H_INC
#define DATA_H_INC

#include <stdlib.h>

#include "signs.h"

typedef struct{
	/* podstawowe zmienne okreslajace:
		- wielkosc planszy
		- kolory pol
		- pozycje i kolor mrowki */
	int rows, cols;
	char*** color;
	int ant_x, ant_y;
	char* ant_sign;
	int ant_move_x, ant_move_y;
	
	/* zmienne pozwalajace na prostsza 
	   rotacje i zmiane koloru mrowki */
	int color_index;
	int rotation_index;
} board_t;

board_t* init_board(board_t*, int, int, char*);

board_t* init_board_with_percentage(board_t* new, int rows, int cols, char* ant_dir, int black_percentage);

void free_board(board_t*);

#endif
