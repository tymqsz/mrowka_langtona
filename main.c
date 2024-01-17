#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

#include "board_io.h"
#include "data.h"
#include "movement.h"


int main(int argc, char** argv){
	/* deklaracja zmiennych i czytanie argumentow */
	board_t* board;
	FILE* f;	
	int bounds_reached;

	int rows = argc > 1 ? atoi(argv[1]) : 40;
	int cols = argc > 2 ? atoi(argv[2]) : 40;
	int iter = argc > 3 ? atoi(argv[3]) : 1000;
	char* rotation = argc > 4 ? argv[4] : "up";
	char* fname_prefix = argc > 5 ? argv[5]: "test";
	int percentage = argc > 6 ? argv[6]: 101;

//propozycja getopta
	int rows = 40;
	int cols = 40;
	int iter = 1000;
	char* rotation = "up";
	char* fname_prefix = "test";
	int percentage = 101;
	//w dalszym kodzie mozna zalozyc, ze jezeli percentage>100 to funkcja z procentem nie bedzie wykonywana

	int c;

	opterr = 0;

	while ((c = getopt (argc, argv, "abc:")) != -1)
		switch (c)
      		{
			case 'rows':
        			rowsvalue = optarg;
        			break;
			
      			case 'cols':
        			colsvalue = optarg;
        			break;
			
      			case 'iter':
        			itervalue = optarg;
        			break;
			
      			case 'rotation':
        			rotationvalue = optarg;
        			break;
			
      			case 'fname_prefix':
        			fname_prefixvalue = optarg;
        			break;
			
      			case 'percentage':
        			percentagevalue = optarg;
        			break;
			
      			case '?':
        			if (optopt == 'c')
          				fprintf (stderr, "Opcja -%c wymaga argumentu.\n", optopt);
        			else if (isprint (optopt))
          				fprintf (stderr, "Nieznana opcja `-%c'.\n", optopt);
				else
          				fprintf (stderr, "Nieznana opcja `\\x%x'.\n", optopt);
        				return 1;
      			default:
        			abort ();
      		}
//koniec getopta

	/* tworzenie nowego folderu o nazwie 
	   podanego prefixu w istniejacym
	   folderze "output_files" */
	char* directory = malloc(50);
	char* out_file = malloc(100);
	strcpy(directory, "output_files/");
	
	/* jesli folder nie istnieje
	   zostanie utworzony */
	mkdir(directory, S_IRWXU);
	
	strcat(directory, fname_prefix);
	mkdir(directory, S_IRWXU);

	
	/* inicjalizacja planszy oraz
	   symulacja ruchow i zapisywanie
	   stanow w petli */
	board = init_board(board, rows, cols, rotation);
	
	for(int i = 0; i < iter; i++){
		/* formatowanie nazwy pliku wyjsciowego */
		sprintf(out_file, "%s/%s_%03d.txt", directory, fname_prefix, i);
		f = fopen(out_file, "w");

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
	free(out_file);
	free(directory);
	free_board(board);
	return 0;
}
