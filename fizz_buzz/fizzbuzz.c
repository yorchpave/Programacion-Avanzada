#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fizzbuzz.h"

char ** fizzbuzz (int n, int * return_size) {
    int i;
    char print[11];
    char ** result = (char **) malloc(sizeof(char * ) * n);
    for (i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            if (i % 5 != 0) {
                strcpy(print, "Fizz");
                result[i - 1] = (char *) malloc(sizeof(char) * 5);
            }
            else if (i % 3 != 0) {
                strcpy(print, "Buzz");
                result[i - 1] = (char *) malloc(sizeof(char) * 5);
            }
            else {
                strcpy(print, "FizzBuzz");
                result[i - 1] = (char *) malloc(sizeof(char) * 9);
            }
        }
        else {
            sprintf(print, "%d", i);
            result[i - 1] = (char *) malloc(sizeof(char) * strlen(print));
        }
        strcpy(result[i - 1], print);
    }
    *return_size = n;
    return result;
}
