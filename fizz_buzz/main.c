#include <stdlib.h>
#include <stdio.h>
#include "fizzbuzz.h"

int main(int argc, char **argv) {
    int n;
    printf("Value of n: "); scanf("%d", &n);
    int * size = (int *) malloc(sizeof(int));
    char ** result = fizzbuzz(n, size);
    int i = 0;
    for (i = 0; i < *size; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
