#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


#include "data.h"
#include "signs.h"
#include "movement.h"

board_t* init_board(board_t* new, int rows, int cols, char* ant_dir){
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

	new->color_index = 0;
	new->rotation_index = 0;
	

	/* ustawianie pozycji wyjsciowej mrowki */
	if(strcmp(ant_dir, "right") == 0)
		rotate_ant(new, "right");
	else if(strcmp(ant_dir, "left") == 0)
		rotate_ant(new, "left");
	else if(strcmp(ant_dir, "down") == 0){
		rotate_ant(new, "right");
		rotate_ant(new, "right");
	}

	return new;
}

board_t* init_board_with_percentage(board_t* new, int rows, int cols, char* ant_dir, int black_percentage){
    new = init_board(new, rows, cols, ant_dir);

    srand(time(NULL));

    int total_cells = rows * cols;
    int black_cells = (black_percentage * total_cells) / 100;

    while (black_cells > 0) {
        
        //wybiera losowo wspolrzedne komorki
        int random_row = rand() % rows;
        int random_col = rand() % cols;

        //sprawdza czy losowo wybrana komorka jest biala, jezeli tak zamienia ja na czarna
        if (strcmp(new->color[random_row][random_col], SQUARE_WHITE) == 0) {
            strcpy(new->color[random_row][random_col], SQUARE_BLACK);
            black_cells--;
        }
    }

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
