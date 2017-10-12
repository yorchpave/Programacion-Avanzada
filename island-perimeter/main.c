#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "island-perimeter.h"

#define print_debug(msg) do { \
	char * value = getenv("ISLAND_DEBUG");\
	if (value != NULL && !strcmp(value, "t")) printf("%s", msg);\
} while(0);

/* Add function signatures here */

int main(int argc, char **argv) {
	
	int **island;
	int col, row, i, j;
	char message[200];
	char * row_tok;
	char row_message[101];
	char delim[2] = ",";

	printf("Size of row: ");
	scanf("%d", &row);
	printf("Size of col: ");
	scanf("%d", &col);
	
	sprintf(message, "col = %d, row = %d\n", col, row);
	print_debug(message);

	island = (int **) malloc(sizeof(int *) * row);
	for (i = 0; i < row; i++) {
		island[i] = (int *) malloc(sizeof(int *) * col);
		j = 0;
		printf("island %d:\n", i);
		scanf("%s", row_message);
		row_tok = strtok(row_message, delim);
		while(row_tok != NULL) {
			if (j >= col) {
				printf("Invalid row!\n");
				return 0;
			}
			island[i][j++] = atoi(row_tok);
			row_tok = strtok(NULL, delim);
		}
	}
	sprintf(message, "\n");
	print_debug(message);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			sprintf(message, "%d ", island[i][j]);
			print_debug(message);
		}
		sprintf(message, "\n");
		print_debug(message);
	}

	sprintf(message, "\n");
	print_debug(message);

	int perimeter = island_perimeter(island, row, col);
	printf("Perimeter = %d\n", perimeter);

	// Free-ing memory.
	for (i = 0; i < row; i++) {
		free(island[i]);
	}
	free(island);

    return 0;
}
