#include <stdio.h>
#include <stdlib.h>

#include "board_io.h"
#include "data.h"
#include "movement.h"
#include<unistd.h>

int main(){
	board_t* board;
	board = init_board(board, 75, 75);
	
	print_board(board);
	
	for(int i = 0; i < 100000; i++){
		usleep(50000);
		move(board);
		print_board(board);

	}

	
	free_board(board);
	return 0;
}
