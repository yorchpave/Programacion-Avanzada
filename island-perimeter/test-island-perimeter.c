#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "island-perimeter.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int tests_run = 0;
static char * test_unit() {
	int island[4][4] = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
	int rows = 4, cols = 4, i;
	int **island_pointer;
	island_pointer = (int **) malloc(sizeof(int *) * rows);
	for (i = 0; i < rows; i++) {
		island_pointer[i] = (int *) malloc(sizeof(int) * cols);
		island_pointer[i] = island[i];
	}
	int expected = 16;
	int result = island_perimeter(island_pointer, rows, cols);
	mu_assert("Wrong Perimeter.", result == expected);
	return 0;
}

static char * all_tests() {
	mu_run_test(test_unit);
	return 0;
}
int main(int argc, char **argv) {
	char *result = all_tests();
	if (result != 0) {
		printf("-_-_-_-_-_-_-_,------,      o \n");
		printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
		printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
		printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
		printf(KRED "✗ %s\n" RESET, result);
	}
	else {
		printf("-_-_-_-_-_-_-_,------,      o \n");
		printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
		printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
		printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
		printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
	}
	printf("Tests run: %d\n", tests_run);
	return result != 0;
}
