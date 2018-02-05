#include <stdio.h>
#include <stdlib.h>
#include "mountain.h"
/* Print a mountain consisting of numPeaks triangles.
 * @param numPeaks: number of mountain peaks
 * @param heights: an array of heights with numPeak elements
 * @param triangles: an array of triangles
 */

int Max(const int numPeaks, int *heights){
	int maxHeight = heights[0];
	for(int i = 1;i < numPeaks;i++){
    	if(heights[i] > maxHeight){
      		maxHeight = heights[i];
    	}
  	}
  	return maxHeight;
}

void printNumberMountain(const int numPeaks, int *heights, int ***triangles){
	
	int i, j, nrow, newHeight, width,sp;
	//find max number from all heights.
	int maxPeak = Max(numPeaks, heights);
	int row_length = 0;

	for(nrow = 1; nrow <= maxPeak; nrow++){
		for(j = 0; j < numPeaks; j++){
			int newHeight = heights[j];
			width = 2 * newHeight - 1;

			//determine the spaces before the mountains.
			if(nrow <= maxPeak - newHeight){ 
				for(j = 0; j < width; j++){
	            	printf(" "); //space
	          	}
	        }else{ 
	        	width = maxPeak - nrow;
	        	for(int sp = 1; sp <= width; sp++){
	        		printf(" "); //space
	        	}

	          	int diff = (maxPeak - newHeight);
	          	int total = 2 * (nrow - diff) - 1;
	          	while(row_length < total){
            		printf("%d", (*triangles)[nrow - 1][row_length]);
            		row_length++;
          		}

          		for(int sp = 1; sp <= width; sp++){
            		printf(" ");
          		}
	          	row_length = 0;
	        }
		}
		printf("\n");
	}
}

int main(){
	int num_peak, i, j;
	int **triangle;

	printf("Please enter the number of peaks [1-5]: ");
	scanf("%d", &num_peak); 
	int height[num_peak - 1];
	printf("Please enter the heights of the peaks [each should be between 1 and 5]: ");
	for(i = 0; i < num_peak; i++){
		scanf("%d", &height[i]);
	}

	int maxPeak = Max((const int)num_peak, height);
	//Triangle Allocation and Initialize.
	int length = 0;
	for(i = 0; i < num_peak; i++){
		length += (2 * height[i] + 1);
	}
	triangle = (int **) malloc(maxPeak * sizeof(int*));
  	for (i = 0; i < maxPeak; i++){
  		triangle[i] = (int *) malloc(length * sizeof(int));
  		for(j = 0; j < length; j++){
  			triangle[i][j] = j;
  		}
  	}
	printNumberMountain((const int)num_peak, height, &triangle);

	/* Free the memory for the 2-D triangle array */
	for (i = 0; i < maxPeak; i++) {
		free(triangle[i]);
	}
	free(triangle);

	return 0;
}