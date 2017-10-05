#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "keyboard_row.h"

/** can_be_formed
  * Receives two char * (strings) and returns whether the first char * can be
  * formed with the letters in the second char *, repetition is allowed.
  * @param:
  *  word: the message that was formed
  *  magazine: the letters that are available
  * @return:
  *  int: 1 | 0
*/
int can_be_formed(char * word, char * row) {
    char * copy_word;
    copy_word = strdup(word);
    char * current;
    int i;
    for (current = row; *current != '\0'; current++) {
        for (i = 0; copy_word[i] != '\0'; i++) {
            if (tolower(*current) == tolower(copy_word[i])) {
                copy_word[i] = '*';
            }
        }
    }
    // printf("Word: %s, Copy_word: %s\n", word, copy_word);
    for (i = 0; copy_word[i] != '\0'; i++) {
        if(copy_word[i] != ' ' && copy_word[i] != '*') {
            free(copy_word);
            return 0;
        }
    }
    free(copy_word);
    return 1;
}

/** find_words
  * Receives an array of char * (strings) and a pointer to the size of the
  * result. It returns the words that can be formed using only a row of the
  * standard US Keyboard layout.
  * Notes:
  *   - You may use one character in the keyboard more than once.
  *   - You may assume the input string will only contain letters of alphabet.

  * @param:
  *  words: the input array of char *
  *  words_size: the size of the char ** words
  *  return_size: the direction in memory in which to save the result's size.
  * @return:
  *  char **: the words that can be formed.
*/
char** find_words (char** words, int words_size, int* return_size) {
    if (words == NULL || return_size == NULL) {
        return NULL;
    }
    char first_row[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    char second_row[9] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    char third_row[7] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    int *formed_array = (int *) calloc(words_size, sizeof(int));

    char **result_array;
    int result_counter = 0;

    char first_char;
    int i, j;
    int size_first = 10;
    int size_second = 9;
    int size_third = 7;
    int result;

    for (i = 0; i < words_size; i++) {
        first_char = tolower(words[i][0]);

        // Traverse the three rows at the same time to see which row matches
        // the first character.
        for (j = 0; j < size_first; j++) {
            if (j < size_second) {
                if (first_char == second_row[j]) {
                    result = can_be_formed(words[i], second_row);
                    if (result) {
                        result_counter++;
                        formed_array[i] = 1;
                        break;
                    } else {
                        formed_array[i] = 0;
                    }

                    break;
                }
            }
            if (j < size_third) {
                if (first_char == third_row[j]) {
                    result = can_be_formed(words[i], third_row);
                    if (result) {
                        result_counter++;
                        formed_array[i] = 1;
                    } else {
                        formed_array[i] = 0;
                    }

                    break;
                }
            }

            if (first_char == first_row[j]) {
                result = can_be_formed(words[i], first_row);
                if (result) {
                    result_counter++;
                    formed_array[i] = 1;
                } else {
                    formed_array[i] = 0;
                }

                break;
            }
        }
    }

    result_array = (char **) malloc(result_counter * sizeof(char *));
    for (i = 0, j = 0; i < words_size && j < result_counter; i++) {
        if (formed_array[i]) {
            result_array[j] = malloc(256 * sizeof(char));
            strcpy(result_array[j], words[i]);
            j++;
        }
    }
    *return_size = result_counter;

    return result_array;
}
