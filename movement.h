#ifndef MOVE_H_INC
#define MOVE_H_INC

void move(board_t* board);

int is_black(board_t* board, int row, int col);

void rotate_ant(board_t* board, char* dir);

void change_ant_color(board_t* board);

#endif
