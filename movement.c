#include<stdio.h>
#include<string.h>

#include "data.h"
#include "signs.h"
#include "movement.h"

/* wektor przechowujacy symbol mrowki ktorego:
   pierwszy wymiar - okreslenie koloru,
   drugi wymiar - okreslenie rotacji  */
char ant_status[2][4][MAX_SIGN_LEN] = {
	ANT_UP_WHITE, ANT_RIGHT_WHITE, ANT_DOWN_WHITE, ANT_LEFT_WHITE,
	ANT_UP_BLACK, ANT_RIGHT_BLACK, ANT_DOWN_BLACK, ANT_LEFT_BLACK
};

/* wektor przechowujacy informacje o ruchu mrowki
   kolejno dla pozycji UP, RIGHT, DOWN, LEFT,
   np. move_xy[0] = [0, -1]:
	   mrowka ruszy sie o 0 w osi x, o -1 w osi y */
int move_xy[4][2] = {
	0, -1,
	1, 0,
	0, 1,
	-1, 0
};

int move(board_t* board){
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
	
	if(board->ant_x < 0 || board->ant_x > board->cols-1 ||
	   board->ant_y < 0 || board->ant_y > board->rows-1)
		return 1;
	// zmiana koloru mrowki
	change_ant_color(board);
	

	free(dir);
	free(prev_color);

	return 0;
}

void rotate_ant(board_t* board, char* dir){
	if(strcmp(dir, "right") == 0){
		board->rotation_index += 1;
		board->rotation_index %= 4;
	}
	else{
		board->rotation_index -= 1;
		if(board->rotation_index == -1)
			board->rotation_index += 4;
	}

	strcpy(board->ant_sign, ant_status[board->color_index][board->rotation_index]);

	board->ant_move_x = move_xy[board->rotation_index][0];
	board->ant_move_y = move_xy[board->rotation_index][1];
}

void change_ant_color(board_t* board){
	char* square_color = board->color[board->ant_y][board->ant_x];

	if(strcmp(square_color, SQUARE_BLACK) == 0 && board->color_index != 1 ||
	   strcmp(square_color, SQUARE_WHITE) == 0 && board->color_index != 0){
		if(board->color_index == 0)
			board->color_index = 1;
		else
			board->color_index = 0;

		strcpy(board->ant_sign, ant_status[board->color_index][board->rotation_index]);
	}
}
