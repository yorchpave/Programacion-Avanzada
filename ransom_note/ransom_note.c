#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ransom_note.h"

/** canConstruct
  * Receives two char * (strings) and returns whether the first char * can be
  * formed with the letters in the second char *
  * @param:
  *  ransom_note: the message that was formed
  *  magazine: the letters that are available
  * @return:
  *  int: 1 | 0
*/
int can_construct(char * ransom_note, char * magazine) {
    char * copy_ransom;
    copy_ransom = strdup(ransom_note);
    char * current;
    int i;
    for (current = magazine; *current != '\0'; current++) {
        for (i = 0; copy_ransom[i] != '\0'; i++) {
            if(*current == copy_ransom[i]) {
                copy_ransom[i] = '*';
                break;
            }
        }
    }
    for (i = 0; copy_ransom[i] != '\0'; i++) {
        if(copy_ransom[i] != ' ' && copy_ransom[i] != '*') {
            free(copy_ransom);
            return 0;
        }
    }
    free(copy_ransom);
    return 1;
}
