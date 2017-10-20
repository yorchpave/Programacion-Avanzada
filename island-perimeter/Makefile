LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c island_perimeter.c
	 gcc -c main.c
	 gcc -o island_perimeter.exe island_perimeter.o main.o $(LIB)

test_island_perimeter: clean
	 gcc -c island_perimeter.c
	 gcc -c test_island_perimeter.c
	 gcc -o test_island_perimeter.exe island_perimeter.o test_island_perimeter.o
	 ./test_island_perimeter.exe

test:	 test_island_perimeter

clean:
	 rm *.out *.o *.exe || exit 0

island_perimeter: clean
	 gcc -c island_perimeter.c
	 gcc -c main.c
	 gcc -o island_perimeter.exe island_perimeter.o main.o $(LIB)

run: island_perimeter
	 ./island_perimeter.exe

runtest: island_perimeter
	 ./integrationtest.tcl ./island_perimeter.exe

