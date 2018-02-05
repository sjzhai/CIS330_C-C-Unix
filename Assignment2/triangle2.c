#include <stdio.h>
#include <stdlib.h>

/* Allocate a triangle of height "height" (a 2-D array of int) */
void allocateNumberTriangle(const int height, int ***triangle){
	int i;
	*triangle = (int **) malloc ( height * sizeof(int *));
	for (i = 0; i < 2 * height + 1; i++) {
		(*triangle)[i] = (int *) malloc ( height * sizeof(int) );
	}
}
/* Initialize the 2-D triangle array */
void initializeNumberTriangle(const int height, int **triangle){
	int i, j;
	for (i = 0; i < height; i++) {
		for (j = 0; j < 2 * i + 1; j++) {
			triangle[i][j] = j;
		}
	}
}
/* Print a formatted triangle */
void printNumberTriangle(const int height, int **triangle){
	int i, j, k;
	for (i = 0; i < height; i++) {
		for(k = 1; k < 10-2*i; k++){
            putchar(' ');
        }
		for (j = 0; j < 2 * i + 1; j++) {
			printf("%d ", triangle[i][j]);
		}
		printf("\n");
	}
}
/* Free the memory for the 2-D triangle array */
void deallocateNumberTriangle(const int height, int ***triangle){
	int i;
	for (i = 0; i < height; i++) {
		free((*triangle)[i]);
	}
	free(*triangle);
}