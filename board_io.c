#include<stdio.h>
#include<stdlib.h>

#include "data.h"

void print_to_file(FILE* f, board_t* board){
	/* pierwszy wiersz */
	fprintf(f, "%s", LINE_DOWN_RIGHT);
	for(int i = 0; i < board->cols; i++)
		fprintf(f, "%s", LINE_HORIZONTAL);
	fprintf(f, "%s", LINE_DOWN_LEFT);
	
	/* reszta wierszy */
	for(int y = 1; y < board->rows-1; y++){
		fprintf(f, "\n%s", LINE_VERTICAL);
		for(int x = 0; x < board->cols; x++){
			if(y == board->ant_y && x == board->ant_x)
				fprintf(f, "%s", board->ant_sign);
			else
				fprintf(f, "%s", board->color[y][x]);
		}
		fprintf(f, "%s", LINE_VERTICAL);
	}

	/* ostatni wiersz */
	fprintf(f, "\n%s", LINE_UP_RIGHT);
	for(int i = 0; i < board->cols; i++)
		fprintf(f, "%s", LINE_HORIZONTAL);
	fprintf(f, "%s\n", LINE_UP_LEFT);
}
