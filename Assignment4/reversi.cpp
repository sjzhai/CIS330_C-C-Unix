

#include "reversi.h"
		
void Othello::MakeBoard(int size){
    int i, j;
    Size = size;
    mat = new choose *[Size];
    for (i = 0; i < Size; i++) {
        mat[i] = new choose[Size];
    }

	for (i = 0; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			mat[i][j] = Empty;
		}
	}
	int left = (Size / 2) - 1;
	int right = left + 1;
	int up = (Size / 2) - 1;
	int down = up + 1;
	mat[up][right] = White;
	mat[up][left] = Black;
    mat[down][left] = White;
    mat[down][right] = Black;
}

int Othello::getSize(int s){
	Size = s;
	return Size;
}

void Othello::PrintBoard(){
	int i, j;
	cout << "  ";
	for(i = 0; i < Size; i++){
		cout << i << " ";
	}
	cout << "\n";

	for(i = 0; i < Size; i++){
		cout << i << " ";
		for(j = 0; j < Size; j++){
			if(mat[i][j] == Black){
				cout << "☻" << " "; //black(1)
			}else if(mat[i][j] == White){
				cout  << "☺" << " "; //white(2)
			}else{
				cout << "□" << " "; //empty(0)
			}
		}
		cout << "\n";
	}
}

int Othello::WalkandTurn(int row, int col, int playernum) {
	int i, j;
	row--;
	col--;
	int size = Size - 1;
	choose present = change;
	if(mat[row][col] == Empty){
		
		//left(L)
		int countLeft = 0; //find steps to same color.
		int toLeft = col - 1; 
		if(toLeft < 0){
			countLeft = 0;
		}else{
			while(mat[row][toLeft] != present){
				if(mat[row][toLeft] == Empty){
					countLeft = 0;
					break;
				}
				countLeft++;
				toLeft--;
				if(toLeft < 0){
					countLeft = 0;
					break;
				}
			}
		}

		//right(R)
		int countRight = 0; //find steps to same color.
		int toRight = col + 1; 
		if(toRight > size){
			countRight = 0;
		}else{
			while(mat[row][toRight] != present){
				if(mat[row][toRight] == Empty){
					countRight = 0;
					break;
				}
				countRight++;
				toRight++;
				if(toRight > size){
					countRight = 0;
					break;
				}
			}
		}

		//up(U)
		int countUp = 0; //find steps to same color.
		int toUp = row - 1; 
		if(toUp < 0){
			countUp = 0;
		}else{
			while(mat[toUp][col] != present){
				if(mat[toUp][col] == Empty){
					countUp = 0;
					break;
				}
				countUp++;
				toUp--;
				if(toUp < 0){
					countUp = 0;
					break;
				}
			}
		}

		//down(D)
		int countDown = 0; //find steps to same color.
		int toDown = row + 1; 
		if(toDown > size){
			countDown = 0;
		}else{
			while (mat[toDown][col] != present){
                if (mat[toDown][col] == Empty){
                	countDown = 0;
                	break;
                }
                countDown++;
                toDown++;
                if (toDown > size){
                    countDown = 0;
                    break;
                }
            }
		}

		//upper left(UL)
		int countUpperLeft = 0; //find steps to same color.
		int colUL = col - 1;
		int rowUL = row - 1;
		if (rowUL < 0 || colUL < 0){
			countUpperLeft = 0;
		}else{
			while(mat[rowUL][colUL] != present){
				if(mat[rowUL][colUL] == Empty){
					countUpperLeft = 0;
					break;
				}
				countUpperLeft++;
				rowUL--;
				colUL--;
				if (rowUL <0 ||colUL <0){
            		countUpperLeft = 0;
            		break;
        		}
			}
		}

		//upper right(UR)
		int countUpperRight = 0; //find steps to same color.
		int colUR = col + 1;
		int rowUR = row - 1;
		if (rowUR < 0 || colUR > size){
			countUpperRight = 0;
		}else{
			while(mat[rowUR][colUR] != present){
				if(mat[rowUR][colUR] == Empty){
					countUpperRight = 0;
					break;
				}
				countUpperRight++;
				rowUR--;
				colUR--;
				if (rowUR < 0 ||colUR > size){
            		countUpperRight = 0;
            		break;
        		}
			}
		}
		
		//down left(DL)
		int countDownLeft = 0; //find steps to same color.
		int colDL = col - 1;
		int rowDL = row + 1;
		if (rowDL > size || colDL < 0){
			countDownLeft = 0;
		}else{
			while(mat[rowDL][colDL] != present){
				if(mat[rowDL][colDL] == Empty){
					countDownLeft = 0;
					break;
				}
				countDownLeft++;
				rowDL++;
				colDL--;
				if (rowDL > size ||colDL <0){
            		countDownLeft = 0;
            		break;
        		}
			}
		}

		//down right(DR)
		int countDownRight = 0; //find steps to same color.
		int colDR = col + 1;
		int rowDR = row + 1;
		if (rowDR > size || colDR > size){
			countDownRight = 0;
		}else{
			while(mat[rowDR][colDR] != present){
				if(mat[rowDR][colDR] == Empty){
					countDownRight = 0;
					break;
				}
				countDownRight++;
				rowDR++;
				colDR++;
				if (rowDR > size ||colDR > size){
            		countDownRight = 0;
            		break;
        		}
			}
		}

		int total = countLeft + countRight + countUp + countDown + countDownRight + countDownLeft + countUpperRight + countUpperLeft;
		if(playernum == 1){

			if(total > 0){
				//change color left.
				toLeft = col;
				for(i = 0; i < countLeft; i++){
					toLeft--;
					mat[row][toLeft] = present;
				}

				//change color right.
				toRight = col;
				for(i = 0; i < countRight; i++){
					toRight++;
					mat[row][toRight] = present;
				}

				//change color up.
				toUp = row;
	            for (i = 0; i < countUp; i++) {
	                toUp--;
	                mat[toUp][col] = present;
	            }

				//change color down.
	            toDown = row;
	            for (i = 0; i < countDown; i++) {
	                toDown++;
	                mat[toDown][col] = present;
	            }

	            //change color upper left(UL).
	            rowUL = row;
	            colUL = col;
	            for (int i = 0; i < countUpperLeft; i++) {
	                rowUL--;
	                colUL--;
	                mat[rowUL][colUL] = present;
	            }

				//change color upper right(UR).
				rowUR = row;
	            colUR = col;
	            for (i = 0; i < countUpperRight; i++){
	                rowUR--;
	                colUR++;
	                mat[rowUR][colUR] = present;
	            }

				//change color down left(DL).
				rowDL = row;
	            colDL = col;
	            for (i = 0; i < countDownLeft; i++) {
	                rowDL++;
	                colDL--;
	                mat[rowDL][colDL] = present;
	            }

				//change color down right(DR).
				rowDR = row;
	            colDR = col;
	            for (int i = 0; i < countDownRight; i++) {
	                rowDR++;
	                colDR++;
	                mat[rowDR][colDR] = present;
	            }
	            return 1;
			}
			return 2;
		}
		if(playernum == 0){
            if (total > 0 ){
                return 3;
            }
            return 4;
        }
        return 0;
	}
	return 0;
}

void Othello::setChessman(int col, int row){
	int result = WalkandTurn(col, row, 1);
	mat[row][col] = change;
	if(result == 1){
		mat[row-1][col-1] = change;
		int turn = 3 - change;
		if(turn == 1){
			change = Black;
		}else if(turn == 2){
			change = White;
		}
	}
	
}

int Othello::EmptyOrNot(){
	int i, j;
    int Num = 0;
    int count = 0;
    for (i = 0; i < Size; i++){
        for (j = 0; j < Size; j++){
            Num++;
            if (mat[i][j] == Empty){
                int det = WalkandTurn(i + 1, j + 1, 0);
                if (det == 3){
                	count++;
                }
            }
        }
    }
    if (count > 0){
    	return 1;
    }
    else{ 
    	return 0;
    }
}