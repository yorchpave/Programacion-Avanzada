#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "ransom_note.h"

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

static char * test_construct_0 () {
    char * ransom_note_test = "help me pls";
    char * magazine_test = "";
    int result = can_construct(ransom_note_test, magazine_test);
    mu_assert("Error, empty magazine should be false.", result == 0);
    return 0;
}

static char * test_construct_1 () {
    char * ransom_note_test_2 = "";
    char * magazine_test_2 = "aabcde";
    int result_2 = can_construct(ransom_note_test_2, magazine_test_2);
    mu_assert("Error, empty magazine should be false.", result_2 == 1);
    return 0;
}

static char * test_construct_2 () {
    char  * ransom_note_test = "hola amigoso";
    char * magazine_test = "alohsogmioa";
    int result = can_construct(ransom_note_test, magazine_test);
    mu_assert("Error, this result should be true.", result == 1);
    return 0;
}

static char * test_construct_3 () {
    char  * ransom_note_test = "hablar contigo";
    char * magazine_test = "saludosamigo";
    int result = can_construct(ransom_note_test, magazine_test);
    mu_assert("Error, this result should be false.", result == 0);
    return 0;
}

static char * test_construct_4 () {
    char  * ransom_note_test = "hablar contigo";
    char * magazine_test = "a";
    int result = can_construct(ransom_note_test, magazine_test);
    mu_assert("Error, this magazine can't form the ransom note", result == 0);
    return 0;
}

static char * test_construct_5 () {
    char  * ransom_note_test = "hola";
    char * magazine_test = "alo";
    int result = can_construct(ransom_note_test, magazine_test);
    mu_assert("Error, this magazine can't form the ransom note", result == 0);
    return 0;
}

static char * test_construct_6 () {
    char  * ransom_note_test = "sdjbfdkfglsk asdfdsdfgdgddfvcbd";
    char * magazine_test = "sdjbfdkfglsk";
    int result = can_construct(ransom_note_test, magazine_test);
    mu_assert("Error, this magazine can't form the ransom note", result == 0);
    return 0;
}

static char * all_tests () {
	mu_run_test(test_construct_0);
	mu_run_test(test_construct_1);
	mu_run_test(test_construct_2);
	mu_run_test(test_construct_3);
	mu_run_test(test_construct_4);
	mu_run_test(test_construct_5);
	mu_run_test(test_construct_6);
    return 0;
}

int main (int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
      printf("-_-_-_-_-_-_-_,------,      o \n");
      printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
      printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
      printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
      printf(KRED "✗ %s \n" RESET, result);
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
