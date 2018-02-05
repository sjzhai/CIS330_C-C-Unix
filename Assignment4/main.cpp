
#include "reversi.h"
using namespace std;

int main() {
    int size, col, row;
    int run = 1;
	Othello othello;
    cout << "Please enter size of board: ";
    cin >> size;
	othello.getSize(size);
    othello.change = Black;
    othello.MakeBoard(size);
    othello.PrintBoard();
    int counter = 0;
    while(run){
    	char *text = "";
    	if (othello.EmptyOrNot() != 1) {

            othello.change = (choose) (3 - othello.change);

            if(othello.change == 2){
            	text = "☺";
            }
            else if (othello.change == 1){
            	text = "☻";
            }

            cout << "Player " << text << " turn, please input 2 numbers for row and column: " << endl;
            if (othello.EmptyOrNot() != 1) {
                break;
            }
        }
        counter++;
        if(othello.change == 2){
        	text = "☺";
        }
        else if (othello.change == 1){
        	text = "☻";
        }

    	cout << "Player " << text << " turn, please input 2 numbers for row and column: ";
    	cin >> row;
    	cin >> col;
    	othello.setChessman(col,row);
        othello.PrintBoard();
    }
    
    int black = 0;
    int white = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (othello.mat[i][j] == 2){
            	white++;
            }
            if (othello.mat[i][j] == 1){
            	black++;
            }
        }
    }
    if (black > white){
        cout << "black wins!"<< " ";
    }
    else if (black < white){
        cout<< "white wins!"<< " ";
    }
    else{
    	cout << "no one wins!"<< " ";
    }

    return 0;
}