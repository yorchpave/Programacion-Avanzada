LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c island-perimeter.c
	 gcc -c main.c
	 gcc -o island-perimeter.exe island-perimeter.o main.o $(LIB)

test_island-perimeter: clean
	 gcc -c island-perimeter.c
	 gcc -c test_island-perimeter.c
	 gcc -o test_island-perimeter.exe island-perimeter.o test_island-perimeter.o
	 ./test_island-perimeter.exe

test:	 test_island-perimeter

clean:
	 rm *.out *.o *.exe || exit 0

island-perimeter: clean
	 gcc -c island-perimeter.c
	 gcc -c main.c
	 gcc -o island-perimeter.exe island-perimeter.o main.o $(LIB)

run: island-perimeter
	 ./island-perimeter.exe

runtest: island-perimeter
	 ./integrationtest.tcl ./island-perimeter.exe

