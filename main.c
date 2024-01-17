#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<ctype.h>

#include "board_io.h"
#include "data.h"
#include "movement.h"

#define MAX_DIR_LEN 200

int main(int argc, char** argv){
	/* deklaracja zmiennych i czytanie argumentow */
	board_t* board;
	FILE* f;	
	int bounds_reached;

	int rows = 40;
    int cols = 40;
    int iter = 1000;
    char* rotation = "up";
    char* out_file = "iter";
    int percentage = 101;  
	char* in_file = "none";
	int flag_rows = 0, flag_cols = 0;
	int c;

    while ((c = getopt(argc, argv, "r:c:g:a:i:p:o:")) != -1) {
        switch (c) {
            case 'r':
                rows = atoi(optarg);
				flag_rows = 1;
                break;

	        case 'c':
                cols = atoi(optarg);
				flag_cols = 1;
                break;

            case 'g':
                iter = atoi(optarg);
                break;

            case 'a':
                rotation = optarg;
                break;

            case 'o':
                out_file = optarg;
                break;

            case 'p':
                percentage = atoi(optarg);
                break;
			case 'i':
				in_file = optarg;
				break;
				
            case '?':
                if (optopt == 'r' || optopt == 'c' || optopt == 'i' || optopt == 'o' || optopt == 'f' || optopt == 'p') {
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                } else if (isprint(optopt)) {
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                } else {
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                }
                return 1;

            default:
                abort();
        }
    }

	/* tworzenie nowego folderu o nazwie 
	   podanego prefixu w istniejacym
	   folderze "output_files" */
	char* directory = malloc(MAX_DIR_LEN);
	char* output = malloc(MAX_DIR_LEN);
	char* in_dir = malloc(MAX_DIR_LEN);
	strcpy(directory, "output_files/");
	
	/* jesli folder nie istnieje
	   zostanie utworzony */
	mkdir(directory, S_IRWXU);
	
	strcat(directory, out_file);
	mkdir(directory, S_IRWXU);

	
	/* inicjalizacja planszy oraz
	   symulacja ruchow i zapisywanie
	   stanow w petli */
	board = init_board(board, rows, cols, rotation);
	if(strcmp(in_file, "none") != 0){
		if(!flag_rows || !flag_cols){
			printf("size of input board not specified, \nplease include -r and -c flags\n");
			return -1;
		}
		
		strcpy(in_dir, "input_files/");
		strcat(in_dir, in_file);
		FILE* file = fopen(in_dir, "r");

		if(file == NULL){
			printf("file %s doesnt exist\n", in_dir);
			return -1;
		}

		read_from_file(file, board);
	}

	for(int i = 0; i < iter; i++){
		/* formatowanie nazwy pliku wyjsciowego */
		sprintf(output, "%s/%s_%03d.txt", directory, out_file, i);
		f = fopen(output, "w");

		print_to_file(f, board);
		
		/* ruch i sprawdzenie jego poprawnosci */
		bounds_reached = move(board);
		if(bounds_reached){
			printf("bounds reached\n");
			fclose(f);
			break;
		}

		fclose(f);
	}


	/* zwolnienie pamieci */
	free(output);
	free(in_dir);
	free(directory);
	free_board(board);
	return 0;
}
