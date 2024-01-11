#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

#include "board_io.h"
#include "data.h"
#include "movement.h"

int main(){
	board_t* board;
	char* out_file = malloc(100);
	FILE* f;	
	int bounds_reached;
	
	char* fname_prefix = "test";
	char* directory = malloc(50);
	strcpy(directory, "output_files/");
	strcat(directory, fname_prefix);

	int status = mkdir(directory, S_IRWXU);
	if(status != 0){
		printf("unable to mkdir\n");
		return -1;
	}

	board = init_board(board, 80, 80);
	
	for(int i = 0; i < 10000; i++){
		sprintf(out_file, "%s/%s_%d.txt", directory, fname_prefix, i);
		f = fopen(out_file, "w");
		print_to_file(f, board);
		//usleep(100000);
		bounds_reached = move(board);
		if(bounds_reached){
			printf("bounds reached\n");
			fclose(f);
			break;
		}
		fclose(f);
	}

	
	free_board(board);
	return 0;
}
