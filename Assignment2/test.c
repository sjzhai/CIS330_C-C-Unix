#include <stdio.h>
#include "triangle.h"

int main(){
    int **triangle;
    int num;
    const int maxSize = 32;
	char userInput[maxSize];
    
	print5Triangle();

    printf("Please enter the hight of the triangle [1-5]: ");

	fgets( userInput, maxSize, stdin );

	while (userInput[0] < '1' || userInput[0] > '5' ) {
		
		printf("Please enter the hight of the triangle [1-5]: ");
    	fgets( userInput, maxSize, stdin );
	}

	num = userInput[0] - '0';

    allocateNumberTriangle((const int)num, &triangle);
    initializeNumberTriangle((const int)num, triangle);
    printNumberTriangle((const int)num, triangle);
    deallocateNumberTriangle((const int)num, &triangle);
    return 0;
}
