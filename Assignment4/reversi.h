#ifndef REVERSI_REVERSI_H
#define REVERSI_REVERSI_H
#include <iostream>
using namespace std;

typedef enum {
	Empty, //0
	Black, //1
	White, //2

}choose;

class Othello{
public:
	choose **mat;
	choose change;
	int getSize(int s);
	void MakeBoard(int size);
	void PrintBoard();
	int WalkandTurn(int row, int col, int playernum);
	void setChessman(int col, int row);
	int EmptyOrNot();
private:
	int Size;

};

#endif //REVERSI_REVERSI_H