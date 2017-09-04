
#include <stdio.h>
#include "last_word_len.h"

int main(int argc, char **argv) {
    //char * phrase = "Hola mundo como estamos hoy";
    char * phrase = "Hola";
    int len = last_word_len(phrase, 4);
    printf("De la frase: \"%s\" la última palabra tiene longitud: %d\n", phrase, len);

    return 0;
}
