#include <stdio.h>
#include <stdlib.h>
typedef enum {
	Empty, //0
	Black, //1
	White, //2

}choose;

typedef struct {
	choose change;
	choose** mat;
}Board;

void MakeBoard(int size, choose*** mat);
void PrintBoard(int size, choose*** mat);
void turnBlackWhite(choose*** mat, int col, int row, choose player);
void changeColor(choose*** mat, int col, int row, choose player, int size);
int Walk(choose*** mat, int col, int row, choose player, int size);
