#!/bin/bash

# Scafold for a basic c program. Receives two arguments, first is the folder,
# then is the module name.
# TODO: Add a program with a module. The module itself has
# to have a test and the program as well.
# TODO: bash c-scafold <program-name> <module-name>
# TODO: Find a good image for building the project
# TODO: Separate functions one to create modules and the other to create the project.
# both can be independent so module scafold can be reused without anyproblem in all the
# projects.
# TODO: When a module is created you have to verify if the test library is there. Also
# you have to display the information that user have to add you its building script.
# TODO: Add help command
# TODO: Refactor everything into functions
# TODO: Read the article about best practices in bash and implement it here.
# TODO: Add directory structure (src, test, dist)
# TODO: Change to use cammel case standard
# TODO: Add function to add another module, similar to hugo
# TODO: Add ifdef clausulles
# TODO: modify utest library to use errorMessage variable to print messages

PROJECT_NAME=$1
MODULE_NAME=$2

CURRENT_DIRECTORY=$(pwd)

if [[ -z "${PROJECT_NAME}" ]]; then
  echo "Please add the name of the project"
  exit
fi

if [[ -z "${MODULE_NAME}" ]]; then
  echo "Please add the name of the module"
  exit
fi

if [[ -d "${CURRENT_DIRECTORY}/${PROJECT_NAME}" ]]; then
  echo "The folder exists. Choose another name"
  exit
fi

mkdir "${CURRENT_DIRECTORY}/${PROJECT_NAME}"

cd "${CURRENT_DIRECTORY}/${PROJECT_NAME}"

touch "${MODULE_NAME}".c
touch "${MODULE_NAME}".h
touch minunit.h
touch test_${MODULE_NAME}.c
touch Makefile
touch main.c
touch README.md

echo "
# ${PROJECT_NAME}

### How to compile
\`\`\`bash
make run
\`\`\`

### How to run test
\`\`\`bash
make test
\`\`\`

### How to debug the program
\`\`\`bash
gcc -g name_of_file.c -o name_of_file
gdb name_of_file
\`\`\`

#### How to start the Program
* break main
* run - Execute the program
* next - Next Line
* print &i - Print the address of the variable
* print sizeof(int) - Print sizeof the int type
* x/4xb &i - Get the raw bytes of i. I want to examinate 4 values formatted as hex numerals. byte by byte
* ptype i - Tell me the type of c expression
* x/12xb &a - a is an array

### Linking stuff and generating the program

If you have modules you have to compile one by one
\`\`\`bash
gcc -c module1.c # This command generates module1.o
gcc -c program-that-depends-of-module1.c
gcc -o program.out module1.o program-that-depends-of-module1.o
./program.out
\`\`\`
" > README.md

echo "#include <stdlib.h>
#include <stdio.h>
#include \"${MODULE_NAME}.h\"
" > ${MODULE_NAME}.c

echo "#include <stdlib.h>
#include <stdio.h>
#include \"${MODULE_NAME}.h\"

/* Add function signatures here */

int main(int argc, char **argv) {
    /* Start your code here */
    printf(\"Hello from main\\n\");
    return 0;
}" > main.c

{
  echo "all:"
  # Make command complains about spaces :(
  # fix: http://stackoverflow.com/questions/525872/echo-tab-characters-in-bash-script
  # http://stackoverflow.com/questions/525872/echo-tab-characters-in-bash-script
  echo -e "\t gcc -c ${MODULE_NAME}.c"
  echo -e "\t gcc -c main.c"
  echo -e "\t gcc -o main.exe ${MODULE_NAME}.o main.o"
  echo ""

  echo "test_${MODULE_NAME}: clean"
  echo -e "\t gcc -c ${MODULE_NAME}.c"
  echo -e "\t gcc -c test_${MODULE_NAME}.c"
  echo -e "\t gcc -o test_${MODULE_NAME}.exe ${MODULE_NAME}.o test_${MODULE_NAME}.o"
  echo -e "\t ./test_${MODULE_NAME}.exe"
  echo ""

  echo -e "test:\t test_${MODULE_NAME}"
  echo ""

  echo "clean:"
  echo -e "\t rm *.out *.o *.exe *.gch || exit 0"
  echo ""

  echo "run:"
  echo -e "\t gcc -c ${MODULE_NAME}.c"
  echo -e "\t gcc -c main.c"
  echo -e "\t gcc -o main.exe ${MODULE_NAME}.o main.o"
  echo -e "\t ./main.exe"

} > Makefile

{
  echo '/* file: minunit.h */'
  echo '#define mu_assert(message, test) do { if (!(test)) return message; } while (0)'
  echo '#define mu_run_test(test) do { char *message = test(); tests_run++; \'
  echo 'if (message) return message; } while (0)'
  echo 'extern int tests_run;'
} >  minunit.h

{
  echo '#include <stdio.h>'
  echo '#include "minunit.h"'
  echo "#include \"${MODULE_NAME}.h\""
  echo ""
  echo '#define KNRM  "\x1B[0m"'
  echo '#define KRED  "\x1B[31m"'
  echo '#define KGRN  "\x1B[32m"'
  echo '#define KYEL  "\x1B[33m"'
  echo '#define KBLU  "\x1B[34m"'
  echo '#define KMAG  "\x1B[35m"'
  echo '#define KCYN  "\x1B[36m"'
  echo '#define KWHT  "\x1B[37m"'
  echo '#define RESET "\033[0m"'
  echo ""
  echo 'int tests_run = 0;'

  echo ""
  echo 'static char * test_unit() {'
  echo '    mu_assert("error, testUnit 1 != 1", 1 == 1);'
  echo '    return 0;'
  echo '}'

  echo ""
  echo 'static char * all_tests() {'
  echo '    mu_run_test(test_unit);'
  echo '    return 0;'
  echo '}'

  echo ""
  echo 'int main(int argc, char **argv) {'
  echo '    char *result = all_tests();'
  echo '    if (result != 0) {'
  echo '      printf("-_-_-_-_-_-_-_,------,      o \n");'
  echo '      printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");'
  echo '      printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");'
  echo '      printf("_-_-_-_-_-_-_- \"\"  \"\" \n");'
  echo '      printf(KRED "✗ %s \n" RESET, result);';
  echo '    }'
  echo '    else {'
  echo '      printf("-_-_-_-_-_-_-_,------,      o \n");'
  echo '      printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");'
  echo '      printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");'
  echo '      printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");'
  echo '      printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);'
  echo '    }'
  echo '    printf("Tests run: %d\n", tests_run);'
  echo '    return result != 0;'
  echo '}'

} > test_${MODULE_NAME}.c

echo 'Happy Coding!'
echo ''
tree ${CURRENT_DIRECTORY}/${PROJECT_NAME}
