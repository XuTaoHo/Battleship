

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"battleship.h"
#include"matrix.h"

struct _ship {
  int dir, row, col;
  double size;
};

int SetShip(ship * s, double ship_size, int size_of_board, char name[]) {
  int row_store, err, col_store, errr, dir_store, errrr ;
  char row_store_char, e;
  
  if (!s || !board_size) return -1;
  
  printf("You are entering coordinates for the ship %s\n", name);
  printf("Please enter row and column coordinate of first point of %s: ", name);
  
  err = scanf("%c", &row_store_char);
  errr = scanf("%d", &col_store);
  printf("\nYou entered row %c and column %d\n", row_store_char, col_store);
  row_store = row_store_char - 'A' + 1;
  
  printf("\nRow %d\n", row_store);
  
  while (e != '\n') {
    err = scanf("%c", &e);
  }
  
  printf("\nPlease enter direction of %s (0 for up, 1 for right, 2 for down, and 3 for left): ", name);
  errrr = scanf("%d", &dir_store);
    
  err = scanf("%c", &e);
  printf("Not here1\n");
  
  while ((dir_store == 0 && row_store <= ship_size - 1) ||
	 (dir_store == 1 && col_store >= size_of_board - (ship_size - 1)) ||
	 (dir_store == 2 && row_store >= size_of_board - (ship_size - 1)) ||
	 (dir_store == 3 && col_store <= ship_size - 1)) {
    	
    printf("You entered coordinates outside of the bounds of the board. Please re-enter coordinates to stay within the bounds\n");
    printf("Please enter column and row coordinate of first point of %s: ", name);
  err = scanf("%c", &row_store_char);
  errr = scanf("%d", &col_store);
  row_store = row_store_char - 'A' + 1;
  

  while (e != '\n') {
    err = scanf("%c", &e);
  }
  
  printf("\nPlease enter direction of %s (0 for up, 1 for right, 2 for down, and 3 for left): ", name);
  errrr = scanf("%d", &dir_store);

  while (e != '\n') {
    err = scanf("%c", &e);
  }
  }
  // }
  printf("Maybe here\n");
  s->dir = dir_store; s->col = col_store; s->row = row_store; s->size = ship_size;
  printf("Maybe here1\n");
  return 0;
}

int CopyShip( ship * temp, ship * s) {
  s->size = temp->size;
  s->col = temp->col;
  s->row = temp->row;
  s->dir = temp->dir;

  return 0;
}

int NewShip(double ship_size,  int size_of_board, ship * s) {
  srand(time(0));

  s->size = ship_size;
  s->row = (rand() % size_of_board) + 1;
  s->col = (rand() % size_of_board) + 1;
  //I define up as 0, right as 1, down as 2, and left as 3
  s->dir = rand() % 4;

  while ((s->dir == 0 && s->row <= s->size - 1) ||
	 (s->dir == 1 && s->col >= size_of_board - (s->size - 1)) ||
	 (s->dir == 2 && s->row >= size_of_board - (s->size - 1)) ||
	 (s->dir == 3 && s->col <= s->size - 1)) {
  s->row = (rand() % size_of_board) + 1;
  s->col = (rand() % size_of_board) + 1;
  //I define up as 0, right as 1, down as 2, and left as 3
  s->dir = rand() % 4;
  }
  return 0;
    }

int overboard(int size_of_board, ship * s, matrix * board, int if_3) {
  //if_3 should only be 1 if the ship is a cruiser. If not, if_3 should be 0
  double previous;
  int counter;
  double limit;
  
    limit = s->size;
    
  while (1) {
    counter = 0;
    //first checks the direction of the ship
    if (s->dir == 0) {
      //checks if there was already a ship where the function wants to put a ship
      for (double i = 0; i < limit; i++) {
	getElement(board, s->row - i, s->col, &previous);
       if (previous != 0) {
	 //if so, roll a new ship placement and direction
	NewShip(s->size, size_of_board, s);
	break;
      }
      }

       if (previous == 0) {
	 //if there wasn't a ship, plot the point and increase the counter
	 for (double i = 0; i < limit; i++) {
	   if (if_3 == 1) setElement(board, s->row - (i - .5), s->col, s->size);
	   else setElement(board, s->row - (i - .5), s->col, s->size);
	 counter++;
    }
    }
    }
    
    
    if (s->dir == 1) {
      for (double i = 0; i < limit; i++) {
       getElement(board, s->row, s->col + i, &previous);
       if (previous != 0) {
	 NewShip(s->size, size_of_board, s);
	break;
      }
      }

       if (previous == 0) {
	 for (double i = .5; i < limit; i++) {
	   if (if_3 == 1) setElement(board, s->row - i, s->col, s->size);
	 else setElement(board, s->row, s->col + i, s->size);
	 counter++;
    }
    }
    }
    
    if (s->dir == 2) {
      for (double i = 0; i < limit; i++) {
      getElement(board, s->row + i, s->col, &previous);
       if (previous != 0) {
	NewShip(s->size, size_of_board, s);
	break;
      }
      }

       if (previous == 0) {
	 for (double i = 0; i < limit; i++) {
	   if (if_3 == 1) setElement(board, s->row - i, s->col, s->size);
	 else setElement(board, s->row + i, s->col, s->size);
	 counter++;
    }
    }
    }
    
    if (s->dir == 3) {
      for (double i = 0; i < limit; i++) {
      getElement(board, s->row, s->col - i, &previous);
       if (previous != 0) {
	NewShip(s->size, size_of_board, s);
	break;
      }
      }

       if (previous == 0) {
	 for (double i = 0; i < limit; i++) {
	   if(if_3 == 1) setElement(board, s->row - i, s->col, s->size);
	 else setElement(board, s->row, s->col - i, s->size);
	 counter++;
    }
  }
    }
  if (counter == s->size) break;
  }
  return 0;
}

int overboard_manual(int size_of_board, ship * s, matrix * board, int if_3, char name[]) {
  //if_3 should only be 1 if the ship is a cruiser. If not, if_3 should be 0
  double previous;
  int counter;
  double limit;
  
    limit = s->size;
    
  while (1) {
    counter = 0;
    //first checks the direction of the ship
    if (s->dir == 0) {
      //checks if there was already a ship where the function wants to put a ship
      for (double i = 0; i < limit; i++) {
	getElement(board, s->row - i, s->col, &previous);
       if (previous != 0) {
	 //if so, roll a new ship placement and direction
	 SetShip(s, s->size,  size_of_board, name);
	break;
      }
      }

       if (previous == 0) {
	 //if there wasn't a ship, plot the point and increase the counter
	 for (double i = 0; i < limit; i++) {
	   if (if_3 == 1) setElement(board, s->row - (i - .5), s->col, s->size);
	   else setElement(board, s->row - (i - .5), s->col, s->size);
	 counter++;
    }
    }
    }
    
    
    if (s->dir == 1) {
      for (double i = 0; i < limit; i++) {
       getElement(board, s->row, s->col + i, &previous);
       if (previous != 0) {
	 SetShip(s, s->size,  size_of_board, name);
	break;
      }
      }

       if (previous == 0) {
	 for (double i = .5; i < limit; i++) {
	   if (if_3 == 1) setElement(board, s->row - i, s->col, s->size);
	 else setElement(board, s->row, s->col + i, s->size);
	 counter++;
    }
    }
    }
    
    if (s->dir == 2) {
      for (double i = 0; i < limit; i++) {
      getElement(board, s->row + i, s->col, &previous);
       if (previous != 0) {
	SetShip(s, s->size,  size_of_board, name);
	break;
      }
      }

       if (previous == 0) {
	 for (double i = 0; i < limit; i++) {
	   if (if_3 == 1) setElement(board, s->row - i, s->col, s->size);
	 else setElement(board, s->row + i, s->col, s->size);
	 counter++;
    }
    }
    }
    
    if (s->dir == 3) {
      for (double i = 0; i < limit; i++) {
      getElement(board, s->row, s->col - i, &previous);
       if (previous != 0) {
	SetShip(s, s->size,  size_of_board, name);
	break;
      }
      }

       if (previous == 0) {
	 for (double i = 0; i < limit; i++) {
	   if(if_3 == 1) setElement(board, s->row - i, s->col, s->size);
	 else setElement(board, s->row, s->col - i, s->size);
	 counter++;
    }
  }
    }
  if (counter == s->size) break;
  }
  return 0;
}

int board_size(int *c) {
  int err = 0;

      if(*c >= 5 && *c <= 20) {
       printf("The board is a %d by %d board\n", *c, *c);
       return 0;
  }
      

     if(*c < 5){
       printf("Please enter an integer larger than 4\n");
       return -1;
     }
     
     if(*c > 20){
       printf("Please enter an integer smaller than 21\n");
       return -1;
     }
}

int board_shots(int * c, int const max_shots) {
  int err = 0;
  
     if(*c >= 8 && *c <= (max_shots * max_shots) - 1) {
       printf("There are %d total shots\n", *c);
       return 0;
  }
     if (*c < 12) {
       printf("Please enter an integer greater than 11\n");
       return -1;
  }

     if (*c > (max_shots * max_shots) - 1) {
       printf("Please enter an integer smaller than %d\n", (max_shots * max_shots) - 1);
       return -1;
     }
}

int printMatrix_shots (matrix const * mtx, int board_size) {
  int row, col; double store;

  if (!mtx) return -1;
  printf("  ");
  for (col = 1; col <= board_size; col++) {
    printf("%d ", col);
  }
  printf("\n");
  for (row = 1; row <= board_size; row++) {
    printf("%c ", 'A' + (row - 1));
    for (col = 1; col <= board_size; col++) {
      getElement(mtx, row, col, &store);
      if (store == 0) printf("~ ");
      if (store == 1) printf("X ");
      if (store == -1) printf("O ");
    }
    /* separate rows by newlines */
    printf("\n");
  }
  return 0;
}

  
  

int round_ships(int shots, matrix * userBoard, matrix * Board, int size_of_board){
  int hit_counter = 12;
  int y, x; char g; double p, q; char e = 'a';
  int sub_count = 0; int cruiser_count = 0; int battleship_count = 0; int carrier_count = 0;int err; int errr;
  while (shots > 0 && hit_counter > 0) {
    
      printMatrix_shots(userBoard, size_of_board);
        printf("You have %d shots remaining. Enter in the row letter than the column number. Take your next shot:",shots);
	
	err = scanf("%c", &g); printf("You entered row %c\n", g);
     	errr = scanf("%d", &y); printf("You entered column %d\n", y);
	
	if (err == 0 || errr == 0) {
	  while (err == 0 || errr == 0) {
      
	scanf("%c", &e);
	  
        printf("\nPlease re-enter point with an appropriate corrosponding uppercase letter to indicate row and number to indicate column: ");
	err = scanf("%c", &g); printf("You entered row %c\n", g);
        errr = scanf("%d", &y); printf("You entered column %d\n");

        }
	}
	
        x = (g - ('A'-1));
	getElement(Board,x,y,&p);
	getElement(userBoard,x,y,&q);
	if ( x < 0 || x > size_of_board || y < 0 || y > size_of_board) {
	  printf("Out of Bounds. Please re-enter coordinates\n");
	}
	else {
	if (q == 1 || q == -1) {
	  printf("You've already shot there, but that's still a miss\n");
	  shots--;
	}

	if (q == 0) {
	if (p ==2) {
	setElement(userBoard,x,y,1);
        hit_counter--;
        shots--;
        printf("It's a hit!\n");
	  printf("Submarine was hit\n");
	  sub_count++;
	  if (sub_count == 2) printf("Submarine has been sunk\n");
        }

	if (p == 3.5) {
	setElement(userBoard,x,y,1);
        hit_counter--;
        shots--;
        printf("It's a hit!\n");
	  printf("Cruiser was hit\n");
	  cruiser_count++;
	  if (cruiser_count == 3) printf("Cruiser has been sunk\n");
	}

	if (p == 3) {
	setElement(userBoard,x,y,1);
        hit_counter--;
        shots--;
        printf("It's a hit!\n");
	  printf("Battleship was hit\n");
	  battleship_count++;
	  if (battleship_count == 3) printf("Battleship had been sunk\n");
	}

	if (p == 4) {
	  setElement(userBoard,x,y,1);
        hit_counter--;
        shots--;
        printf("It's a hit!\n");
	  printf("Carrier has been hit\n");
	  carrier_count++;
	  if (carrier_count == 4) printf("Carrier has been sunk\n");
	}
	
	if (p == 0) {
        setElement(userBoard,x,y,-1);
        printf( "Ah darn, it's a miss!\n");
	shots--;
	    }
	}
	}
	   err = scanf("%c", &e);

  }
    if (shots == 0){
      printf("Looks like you're out of shots, better luck next time!\n");
      return 0;
    }
    if (hit_counter == 0){
      printf("Congrats! It looks like you've sunken all four ships! You Win\n");
      return 0;
    }
}

int round_ships_manual(int shots, matrix * userBoard1, matrix * userBoard2, matrix * Board1, matrix * Board2, int size_of_board){
  int hit_counter1 = 12; int hit_counter2 = 12; int shots1 = shots; int shots2 = shots;
  int y, x; char g; double p, q; char e = 'a';
  int sub_count1 = 0; int cruiser_count1 = 0; int battleship_count1 = 0; int carrier_count1 = 0;
  int sub_count2 = 0; int cruiser_count2 = 0; int battleship_count2 = 0; int carrier_count2 = 0;

  int err; int errr;
  int turn = 1;
  while ((shots1 > 0  || shots2 > 0) && hit_counter1 > 0 && hit_counter2 > 0) {
    
    if (turn == 1) {
      printMatrix_shots(userBoard1, size_of_board);
	printf("Player 1, please enter your shots\n");
        printf("You have %d shots remaining. Enter in the row letter than the column number. Take your next shot:",shots1);
	
	err = scanf("%c", &g); printf("You entered row %c\n", g);
     	errr = scanf("%d", &y); printf("You entered column %d\n", y);
	
	if (err == 0 || errr == 0) {
	  while (err == 0 || errr == 0) {
	   
	scanf("%c", &e);
       
	  
        printf("\nPlease re-enter point with an appropriate corrosponding uppercase letter to indicate row and number to indicate column: ");
	err = scanf("%c", &g); printf("You entered row %c\n", g);
        errr = scanf("%d", &y); printf("You entered column %d\n", y);

        }
	}
	
        x = (g - ('A'-1));
	getElement(Board2,x,y,&p);
	getElement(userBoard1,x,y,&q);
	
	if ( x < 0 || x > size_of_board || y < 0 || y > size_of_board) {
	  printf("Out of Bounds. Please re-enter coordinates\n");
	}
	else {
	if (q == 1 || q == -1) {
	  printf("You've already shot there, but that's still a miss\n");
	  shots1--;
	}

	if (q == 0) {
	  
	if (p ==2) {
	setElement(userBoard1,x,y,1);
        hit_counter1--;
        shots1--;
        printf("It's a hit!\n");
	  printf("Submarine was hit\n");
	  sub_count1++;
	  if (sub_count1 == 2) printf("Submarine 2 has been sunk\n");
        }

	if (p == 3.5) {
	setElement(userBoard1,x,y,1);
        hit_counter1--;
        shots1--;
        printf("It's a hit!\n");
	  printf("Cruiser was hit\n");
	  cruiser_count1++;
	  if (cruiser_count1 == 3) printf("Cruiser 2 has been sunk\n");
	}

	if (p == 3) {
	setElement(userBoard1,x,y,1);
        hit_counter1--;
        shots1--;
        printf("It's a hit!\n");
	  printf("Battleship was hit\n");
	  battleship_count1++;
	  if (battleship_count1 == 3) printf("Battleship 2 had been sunk\n");
	}

	if (p == 4) {
	  setElement(userBoard1,x,y,1);
        hit_counter1--;
        shots1--;
        printf("It's a hit!\n");
	  printf("Carrier has been hit\n");
	  carrier_count1++;
	  if (carrier_count1 == 4) printf("Carrier 2 has been sunk\n");
	}
	
	if (p == 0) {
        setElement(userBoard1,x,y,-1);
        printf( "Ah darn, it's a miss!\n");
	shots1--;
	    }
	}
	}
	turn = 2;
	scanf("%c", &e);
    }
	if (turn == 2) {
	  printMatrix_shots(userBoard2, size_of_board);
	printf("Player 2, please enter your shots\n");
        printf("You have %d shots remaining. Enter in the row letter than the column number. Take your next shot:",shots2);
	
	err = scanf("%c", &g); printf("You entered row %c\n", g);
     	errr = scanf("%d", &y); printf("You entered column %d\n", y);
	
	if (err == 0 || errr == 0) {
	  while (err == 0 || errr == 0) {
      
	scanf("%c", &e);
	  
        printf("\nPlease re-enter point with an appropriate corrosponding uppercase letter to indicate row and number to indicate column: ");
	err = scanf("%c", &g); printf("You entered row %c\n", g);
        errr = scanf("%d", &y); printf("You entered column %d\n", y);

        }
	}
	
        x = (g - ('A'-1));
	getElement(Board1,x,y,&p);
	getElement(userBoard2,x,y,&q);
	if ( x < 0 || x > size_of_board || y < 0 || y > size_of_board) {
	  printf("Out of Bounds. Please re-enter coordinates\n");
	}
	else {
	if (q == 1 || q == -1) {
	  printf("You've already shot there, but that's still a miss\n");
	  shots2--;
	}

	if (q == 0) {
	if (p ==2) {
	setElement(userBoard2,x,y,1);
        hit_counter2--;
        shots2--;
        printf("It's a hit!\n");
	  printf("Submarine 1 was hit\n");
	  sub_count2++;
	  if (sub_count2 == 2) printf("Submarine 1 has been sunk\n");
        }

	if (p == 3.5) {
	setElement(userBoard2,x,y,1);
        hit_counter2--;
        shots2--;
        printf("It's a hit!\n");
	  printf("Cruiser 1 was hit\n");
	  cruiser_count2++;
	  if (cruiser_count2 == 3) printf("Cruiser 1 has been sunk\n");
	}

	if (p == 3) {
	setElement(userBoard2,x,y,1);
        hit_counter2--;
        shots2--;
        printf("It's a hit!\n");
	  printf("Battleship 1 was hit\n");
	  battleship_count2++;
	  if (battleship_count2 == 3) printf("Battleship 1 had been sunk\n");
	}

	if (p == 4) {
	  setElement(userBoard2,x,y,1);
        hit_counter2--;
        shots2--;
        printf("It's a hit!\n");
	  printf("Carrier 1 has been hit\n");
	  carrier_count2++;
	  if (carrier_count2 == 4) printf("Carrier 1 has been sunk\n");
	}
	
	if (p == 0) {
        setElement(userBoard2,x,y,-1);
        printf( "Ah darn, it's a miss!\n");
	shots2--;
	    }
	}
	}
	turn = 1;
	scanf("%c", &e);
	}
	  
  }
    if (shots1 == 0 && shots2 == 0){
      printf("Looks like you're both out of shots, better luck next time!\n");
      return 0;
    }
    if (hit_counter1 == 0){
      printf("Congrats Player 1! It looks like you've sunken all four ships! You Win\n");
      return 0;
    }
    if (hit_counter2 == 0) {
      printf("Congrats! Player 2! It looks like you've sunken all four ships! You WIn\n");
      return 0;
    }
}

    

    

