LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c merge_trees.c
	 gcc -c main.c
	 gcc -o merge_trees.exe merge_trees.o main.o $(LIB)

test_merge_trees: clean
	 gcc -c merge_trees.c
	 gcc -c test_merge_trees.c
	 gcc -o test_merge_trees.exe merge_trees.o test_merge_trees.o
	 ./test_merge_trees.exe

test:	 test_merge_trees

clean:
	 rm *.out *.o *.exe || exit 0

merge_trees: clean
	 gcc -c merge_trees.c
	 gcc -c main.c
	 gcc -o merge_trees.exe merge_trees.o main.o $(LIB)

run: merge_trees
	 ./merge_trees.exe

runtest: merge_trees
./integrationtest.tcl ./merge_trees.exe
