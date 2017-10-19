#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "add-digits.h"

int addDigits(unsigned int n){
  return 1 + ((n - 1) % 9);
}
