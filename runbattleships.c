#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"battleship.h"
#include"matrix.h"

int main(int argc,char const * const argv[] ) {
  printf("Welcome to Battleships, the game where you virtually kill thousands of innocent sailors just because they happened to be on the ship opposite of yours!\n\n");
  if(argc != 4) {
    printf("Please enter in 3 positive integers into the command line for board size, maximum number of shots, and players (1/2). For example, please type ./runbattleships 6 12 1\n");
    return -1;
  }

  matrix * board;
  int size_of_board = 0;int shots = 0; int err = 0; int mode = 0;

  err = sscanf(argv[1], "%d", &size_of_board);
  if (err == 0) {
       printf("Please enter an integer\n");
       return -1;
}
  err = board_size(&size_of_board);
  if (err == -1) return -1;

  err = sscanf(argv[2], "%d", &shots);
  if (err == 0) {
       printf("Please enter an integer\n");
       return -1;
}

  err = sscanf(argv[3], "%d", &mode);
  if(err == 0) {
    printf("Please enter an integer\n");
    return -1;
  }

  if (mode == 1) {
  err = board_shots(&shots, size_of_board);
  if(err == -1) return -1;

  board = newMatrix(size_of_board, size_of_board);

  ship * submarine; ship * cruiser; ship * battleship; ship * carrier;
  carrier = malloc(sizeof(carrier));
  submarine = malloc(sizeof(submarine));
  cruiser = malloc(sizeof(cruiser));
  battleship = malloc(sizeof(battleship));

  err = NewShip(2, size_of_board, submarine);
  err = overboard(size_of_board, submarine, board, 0);
  printf("Submarine placed\n");
  printMatrix(board);

  err = NewShip(3, size_of_board, cruiser);
  err = overboard(size_of_board, cruiser, board, 0);
  printf("Cruiser placed\n");
  double store;
 
  for (int i = 1; i < size_of_board; i++) {
    for (int j = 1; j < size_of_board; j++) {
      err = getElement(board, i, j, &store);
      if (store == 3) err = setElement(board, i, j, 3.5);
    }
    }
  printMatrix(board);
    
  err = NewShip(3, size_of_board, battleship);
  err = overboard(size_of_board, battleship, board, 0);
  printf("Battleship placed\n");
  printMatrix(board);
  
  err = NewShip(4, size_of_board, carrier);
  err = overboard(size_of_board, carrier, board, 0);
  printf("Carrier placed\n");
  printMatrix(board);

  printf("Finished plotting\n");
    
  matrix * userBoard;
  userBoard = newMatrix(size_of_board, size_of_board);

  round_ships(shots, userBoard, board, size_of_board);
  }

  if (mode == 2) {
    ship * sub1, *sub2, *cruiser1, *cruiser2, *battleship1, *battleship2, *carrier1, *carrier2;
    matrix * board1, *board2, *userMatrix1, *userMatrix2;
    
    sub1 = malloc(sizeof(sub1)); sub2 = malloc(sizeof(sub2)); cruiser1 = malloc(sizeof(cruiser1)); cruiser2 = malloc(sizeof(cruiser2));
    battleship1 = malloc(sizeof(battleship1)); battleship2 = malloc(sizeof(battleship2));
    carrier1 = malloc(sizeof(carrier1)); carrier2 = malloc(sizeof(carrier2));
    
    board1 = newMatrix(size_of_board, size_of_board); board2 = newMatrix(size_of_board, size_of_board);
    userMatrix1 = newMatrix(size_of_board, size_of_board); userMatrix2 = newMatrix(size_of_board, size_of_board);
    
    printMatrix_shots(userMatrix1, size_of_board);
    err = SetShip(sub1, 2, size_of_board, "submarine 1");
    err = overboard_manual(size_of_board, sub1, board1, 0, "submarine 1");
    printf("2 = submarine, 3 = battleship, 3.5 = cruiser, 4 = carrier\n");
    
    printMatrix_shots(userMatrix1, size_of_board);
    printMatrix(board1);
    err = SetShip(cruiser1, 3, size_of_board, "cruiser 1");
    err = overboard_manual(size_of_board, cruiser1, board1, 0, "cruiser 1");
    printf("2 = submarine, 3 = battleship, 3.5 = cruiser, 4 = carrier\n");

    double store;
     for (int i = 1; i < size_of_board; i++) {
    for (int j = 1; j < size_of_board; j++) {
      err = getElement(board1, i, j, &store);
      if (store == 3) err = setElement(board1, i, j, 3.5);
    }
    }
     
    printMatrix_shots(userMatrix1, size_of_board);
    printMatrix(board1);
    err = SetShip(battleship1, 3, size_of_board, "battleship 1");
    err = overboard_manual(size_of_board, battleship1, board1, 0, "battleship 1");
    printf("2 = submarine, 3 = battleship, 3.5 = cruiser, 4 = carrier\n");

    printMatrix_shots(userMatrix1, size_of_board);
    printMatrix(board1);
    err = SetShip(carrier1, 4, size_of_board, "carrier 1");
    err = overboard_manual(size_of_board, carrier1, board1, 0, "carrier 1");
    printf("2 = submarine, 3 = battleship, 3.5 = cruiser, 4 = carrier\n");
    
    printMatrix_shots(userMatrix1, size_of_board);
    printMatrix(board1);
    
    printMatrix_shots(userMatrix2, size_of_board);
    printMatrix(board2);
    err = SetShip(sub2, 2, size_of_board, "submarine 2");
    err = overboard_manual(size_of_board, sub2, board2, 0, "submarine 2");
    printf("2 = submarine, 3 = battleship, 3.5 = cruiser, 4 = carrier\n");

    printMatrix_shots(userMatrix2, size_of_board);
    printMatrix(board2);
    err = SetShip(cruiser2, 3, size_of_board, "cruiser 2");
    err = overboard_manual(size_of_board, cruiser2, board2, 0, "cruiser 2");
    printf("2 = submarine, 3 = battleship, 3.5 = cruiser, 4 = carrier\n");

     for (int i = 1; i < size_of_board; i++) {
    for (int j = 1; j < size_of_board; j++) {
      err = getElement(board2, i, j, &store);
      if (store == 3) err = setElement(board2, i, j, 3.5);
    }
    }
     
    printMatrix_shots(userMatrix2, size_of_board);
    printMatrix(board2);
    err = SetShip(battleship2, 3, size_of_board, "battleship 2");
    err = overboard_manual(size_of_board, battleship2, board2, 0, "battleship2");
    printf("2 = submarine, 3 = battleship, 3.5 = cruiser, 4 = carrier\n");

    printMatrix_shots(userMatrix2, size_of_board);
    printMatrix(board2);
    err = SetShip(carrier2, 4, size_of_board, "carrier2");
    err = overboard_manual(size_of_board, carrier2, board2, 0, "carrier2");
    printf("2 = submarine, 3 = battleship, 3.5 = cruiser, 4 = carrier\n");

    printMatrix_shots(userMatrix2, size_of_board);
    printMatrix(board2);

    round_ships_manual(shots, userMatrix1, userMatrix2, board1, board2, size_of_board);
  }
  return 0;
}

