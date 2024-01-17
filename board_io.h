#ifndef BOARD_IO_H_INC
#define BOARD_IO_H_INC

#include "data.h"

void print_to_file(FILE*, board_t*);

void read_from_file(FILE*, board_t*);

void update_cell(int, int, char*, board_t*);
#endif
