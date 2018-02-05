#include <stdio.h>
#include <stdlib.h>
#include "reversi.h"

void MakeBoard(int size, choose*** mat) {
	int i, j;

	*mat = (choose **) malloc ( size * sizeof(int *));
	for (i = 0; i < size; i++) {
		(*mat)[i] = (choose *) malloc ( size * sizeof(int) );
		for (j = 0; j < size; j++) {
			(*mat)[i][j] = Empty;
		}
	}
	int left = (size / 2) - 1;
	int right = left + 1;
	int up = (size / 2) - 1;
	int down = up + 1;
	(*mat)[up][right] = White;
	(*mat)[up][left] = Black;
    (*mat)[down][left] = White;
    (*mat)[down][right] = Black;
}

void PrintBoard(int size, choose*** mat){
	int i, j, k;
	printf("  ");
	for(i = 0; i < size; i++){
		printf("%d ", i);
	}
	printf("\n");
	
	for (i = 0; i < size; i++) {
		printf("%d ", i);
		for(j = 0; j < size; j++) {
			printf("%u ", (*mat)[i][j]);
		}
		printf("\n");
	}
}

void turnBlackWhite(choose*** mat, int col, int row, choose player){
	if(player == Black){
		(*mat)[col][row] = Black;
	}else{
		(*mat)[col][row] = White;
	}
}
//this function is to change the color of eight sides.
void changeColor(choose*** mat, int col, int row, choose player, int size){
	int i, j;

	if((*mat)[col][row-1] != player){ //change color of left side.
		if((*mat)[col][row-1] != Empty){
			for(i = row-1; i >= 0; i--){
				if((*mat)[col][i] == player){
					for(j = row; j > i; j--){
						turnBlackWhite(mat, col, j, player);
					}
				}
			}	
		}
	}
	if((*mat)[col][row+1] != player){ //change color of right side.
		if((*mat)[col][row+1] != Empty){
			for(i = row+1; i < size; i++){
				if((*mat)[col][i] == player){
					for(j = row; j < i; j++){
						turnBlackWhite(mat, col, j, player);
					}
				}
			}
		}
	}
	if((*mat)[col-1][row] != player){ //change color of upper side.
		if((*mat)[col-1][row] != Empty){
			for(i = col; i >= 0; i--){
				if((*mat)[i][row] == player){
					for(j = col; j > i; j--){
						turnBlackWhite(mat, j, row, player);
					}
				}
			}
		}
	}
	if((*mat)[col+1][row] != player){ //change color of down side.
		if((*mat)[col+1][row] != Empty){
			for(i = col+1; i < size; i++){
				if((*mat)[i][row] == player){
					for(j = col; j < i; j++){
						turnBlackWhite(mat, j, row, player);
					}
				}
			}
		}
	}
	//calculate lesser value for column and row. 
	int lesser, newcol, newrow, diffCol, diffRow, till;
	if(col == row){
		lesser = col;
	}else if(row < col){
		lesser = row;
	}else{
		lesser = col;
	}
	newcol = col-1;
	newrow = row-1;
	if((*mat)[newcol][newrow] != player){ //change color of upper left side.
		if((*mat)[newcol][newrow] != Empty){
			for(i = lesser-1; i >= 0; i--){
				if((*mat)[col][row] == player){
					for(j = col; j < i; j++){
						turnBlackWhite(mat, col, j, player);
					}
					col--;
					row--;
				}
			}
		}
	}
	if((*mat)[col-1][row+1] != player){ //change color of upper right side.
		if((*mat)[col-1][row+1] != Empty){
			for(i = row+1; i < size; i++){
				if((*mat)[col][row] == player){
					for(j = col; j < i; j++){
						turnBlackWhite(mat, j, row, player);
					}
					col--;
					row++;
				}
			}
		}
	}
	if((*mat)[col+1][row-1] != player){ //change color of low left side.
		if((*mat)[col+1][row-1] != Empty){
			for(i = lesser-1; i >= 0; i--){
				if((*mat)[col][row] == player){
					for(j = col; j < i; j++){
						turnBlackWhite(mat, col, j, player);
					}
					col++;
					row--;
				}
			}
		}
	}
	if((*mat)[col+1][row+1] != player){ //change color of low right side.
		if((*mat)[col+1][row+1] != Empty){
			for(i = lesser+1; i < size; i++){
				if((*mat)[col][row] == player){
					for(j = col; j < i; j++){
						turnBlackWhite(mat, j, row, player);
					}
					col++;
					row++;
				}
			}
		}
	}
}
int Walk(choose*** mat, int col, int row, choose player, int size){
	int control = 0;
	int i, lesser;
	if(col >= 0 && col < size && row >= 0 && row < size){
		//determine that place is empty
		if((*mat)[col][row] == Empty){
			//To the left
			//determine this place to left has no same color.
			if((*mat)[col][row-1] != player){
				if((*mat)[col][row-1] != Empty){
					for(i = row-1; i >= 0; i--){
						if((*mat)[col][i] == player){
							control = 1;
						}
					}
				}
			}
			//To the right
			//determine this place to right has no same color.
			if((*mat)[col][row+1] != player){
				if((*mat)[col][row+1] != Empty){
					for(i = row+1; i < size; i++){
						if((*mat)[col][i] == player){
							control = 1;
						}
					}
				}
			}
			//To the up
			//determine this place to up has no same color.
			if((*mat)[col-1][row] != player){
				if((*mat)[col-1][row] != Empty){
					for(i = col-1; i >= 0; i--){
						if((*mat)[i][row] == player){
							control = 1;
						}
					}
				}
			}
			//To the down
			//determine this place to down has no same color.
			if((*mat)[col+1][row] != player){
				if((*mat)[col+1][row] != Empty){
					for(i = col+1; i < size; i++){
						if((*mat)[i][row] == player){
							control = 1;
						}
					}
				}
			}
			//calculate lesser value for column and row. 
			if(col == row){
				lesser = col;
			}else if(row < col){
				lesser = row;
			}else{
				lesser = col;
			}
			//upper left
			if((*mat)[col-1][row-1] != player){
				if((*mat)[col-1][row-1] != Empty){
					for(i = lesser-1; i >= 0; i--){
						if((*mat)[col][row] == player){
							col--;
							row--;
						}
						control = 1;
					}
				}
			}
			//upper right
			if((*mat)[col-1][row+1] != player){
				if((*mat)[col-1][row+1] != Empty){
					for(i = lesser+1; i < size; i++){
						if((*mat)[col][row] == player){
							col--;
							row++;
						}
						control = 1;
					}
				}
			}
			//low left
			if((*mat)[col+1][row-1] != player){
				if((*mat)[col+1][row-1] != Empty){
					for(i = lesser-1; i >= 0; i--){
						if((*mat)[col][row] == player){
							col++;
							row--;
						}
						control = 1;
					}
				}
			}
			//low right
			if((*mat)[col+1][row+1] != player){
				if((*mat)[col+1][row+1] != Empty){
					for(i = lesser+1; i < size; i++){
						if((*mat)[col][row] == player){
							col++;
							row++;
						}
						control = 1;
					}
				}
			}
		}
	}
	if(control == 1){
		(*mat)[col][row] = player;
		changeColor(mat, col, row, player, size);
		return control;
	}	
	return control;
}
//determine the matrix whether has place to put chess pieces.
int EmptyOrNot(int size, choose*** mat){
	int isEmpty = 1; //value 1 is true, value 0 is false.
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; i++)
		if((*mat)[i][j] == Empty){
			return isEmpty;
		}
	}
	isEmpty = 0;
	return isEmpty;
}

int main() {
	int size;
	int col, row, setNum;
	choose **mat;
	printf("Please enter size of board: ");
	scanf("%d", &size);
	MakeBoard(size, &mat);
	PrintBoard(size, &mat);

	choose change = Black;
	while(EmptyOrNot(size, &mat) == 1){ //when the board has place to put chess.
		if(change == White){
			printf("Player White(2) turn, input 2 numbers (0-%d) for row and column: ", size-1);
			scanf("%d %d", &col, &row);
			setNum = Walk(&mat, col, row, change, size);
			if(setNum == 1){
				PrintBoard(size, &mat);
			}else{//if entered number is invalid, request for input again.
				while(setNum == 0){
					printf("Player White(2) turn, input 2 numbers (0-%d) for row and column: ", size-1);
					scanf("%d %d", &col, &row);
					setNum = Walk(&mat, col, row, change, size);
				}
			}
			change = Black;
		}else{
			printf("Player Black(1) turn, input 2 numbers (0-%d) for row and column: ", size-1);
			scanf("%d %d", &col, &row);
			setNum = Walk(&mat, col, row, change, size);
			if(setNum == 1){
				PrintBoard(size, &mat);
			}else{
				while(setNum == 0){
					printf("Player Black(1) turn, input 2 numbers (0-%d) for row and column: ", size-1);
					scanf("%d %d", &col, &row);
					setNum = Walk(&mat, col, row, change, size);
				}
			}
			change = White;
		}
	}

    printf("game over!");
    printf("\n");
    int black = 0;
    int white = 0;
    for (int i = 0; i < size; i++){
        
        for (int j = 0; j < size; j++){
            if (mat[i][j] == 1){
            	black++;
            }
            if (mat[i][j] == 2){
            	white++;
            }
        }
    }
    if (black > white){
        printf("black wins!");
    }
    else if (Black < white){
        printf("white wins!");
    }
    else{printf("no one wins!");}
	
	return 0;
}