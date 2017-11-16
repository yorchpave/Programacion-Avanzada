#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "fizzbuzz.h"

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
    int * size = (int *) malloc(sizeof(int));
    char ** result = fizzbuzz(15, size);
    int i = 0;
	mu_assert("Wrong output 14", result != NULL && strcmp(result[14], "FizzBuzz") == 0);
	mu_assert("Wrong output 5", result != NULL && strcmp(result[5], "Fizz") == 0);
	mu_assert("Wrong output 4", result != NULL && strcmp(result[4], "Buzz") == 0);
	mu_assert("Wrong output 9", result != NULL && strcmp(result[9], "Buzz") == 0);
	mu_assert("Wrong output 8", result != NULL && strcmp(result[8], "Fizz") == 0);
	mu_assert("Wrong output 7", result != NULL && strcmp(result[7], "8") == 0);
    free(size);
    free(result);
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
