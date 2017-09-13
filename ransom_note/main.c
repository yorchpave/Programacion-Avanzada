#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ransom_note.h"

/* Add function signatures here */

int main(int argc, char **argv) {
    /* Start your code here */
    printf("Hello from main\n");

    char * note = "help me pls";
    char * magazine = "slpemhel";
    int result = can_construct(note, magazine);
    printf("Result is: %d\n", result);
    return 0;
}
