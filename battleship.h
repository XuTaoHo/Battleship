#ifndef BATTLESHIPS_H_
#define BATTLESHIPS_H_

#include"matrix.h"

typedef struct _ship ship;
int round_ships_manual(int shots, matrix * userMatrix1, matrix * userMatrix2, matrix * Board1, matrix * Board2, int size_of_board);
int overboard_manual(int size_of_board, ship * s, matrix * board, int if_3, char name[]);
int SetShip( ship * s, double ship_size, int size_of_board, char name[]);
int NewShip(double ship_size, int size_of_board, ship * s);
int overboard(int size_of_board, ship * s, matrix * board, int if_3);
int board_size(int * c);
int CopyShip(ship * temp, ship * s);
int board_shots(int * c, int const max_shots);
int printMatrix_shots(matrix const * mtx, int board_size);
int round_ships(int shots, matrix * userBoard, matrix * Board, int size_of_board);

#endif
