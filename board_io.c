#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<string.h>

#include "data.h"
#include "board_io.h"

char ant[2][4][MAX_SIGN_LEN] = {
	ANT_UP_WHITE, ANT_RIGHT_WHITE, ANT_DOWN_WHITE, ANT_LEFT_WHITE,
	ANT_UP_BLACK, ANT_RIGHT_BLACK, ANT_DOWN_BLACK, ANT_LEFT_BLACK
};

void read_from_file(FILE* f, board_t* board) {
    int rows = board->rows, cols = board->cols;
    int n = 0;
    int l = 0;
	int y, x;

    setlocale(LC_ALL, "C.UTF-8");
    wint_t wint;

    while ((wint = fgetwc(f)) != WEOF) {
        wchar_t wchar[2];
        wchar[0] = (wchar_t)wint;
        wchar[1] = L'\0';

        char buff[MB_CUR_MAX];
        if (wcstombs(buff, wchar, sizeof(buff)) == (size_t)-1) {
            perror("Conversion error.\n");
            exit(1);
        }
	
		
		if (strcmp(buff, "\n") == 0)
			continue;
        else if (n < cols + 1 || n > (cols + 2) * (rows + 1)) {
            n++;
            continue;
        } 
		else if (n % (cols + 2) == 0 || n % (cols + 2) == (cols+1)) {
            n++;
            continue;
        }
		
		y = l / cols;
		x = l % cols;

		update_cell(y, x, buff, board);

        l++;
        n++;
    }
}

void update_cell(int y, int x, char* sign, board_t* board){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			if(strcmp(sign, ant[i][j]) == 0){
				strcpy(board->ant_sign, ant[i][j]);
				board->color_index = i;
				board->rotation_index = j;
				board->ant_x = x;
				board->ant_y = y;
				return;
			}
		}
	}

	if(strcmp(sign, SQUARE_BLACK) == 0)
		strcpy(board->color[y][x], SQUARE_BLACK);
}

void print_to_file(FILE* f, board_t* board){
	/* pierwszy wiersz */
	fprintf(f, "%s", LINE_DOWN_RIGHT);
	for(int i = 0; i < board->cols; i++)
		fprintf(f, "%s", LINE_HORIZONTAL);
	fprintf(f, "%s", LINE_DOWN_LEFT);
	
	/* reszta wierszy */
	for(int y = 0; y < board->rows; y++){
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
