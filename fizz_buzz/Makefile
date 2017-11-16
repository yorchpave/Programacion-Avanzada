LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c fizzbuzz.c
	 gcc -c main.c
	 gcc -o fizzbuzz.exe fizzbuzz.o main.o $(LIB)

test_fizzbuzz: clean
	 gcc -c fizzbuzz.c
	 gcc -c test_fizzbuzz.c
	 gcc -o test_fizzbuzz.exe fizzbuzz.o test_fizzbuzz.o
	 ./test_fizzbuzz.exe

test:	 test_fizzbuzz

clean:
	 rm *.out *.o *.exe || exit 0

fizzbuzz: clean
	 gcc -c fizzbuzz.c
	 gcc -c main.c
	 gcc -o fizzbuzz.exe fizzbuzz.o main.o $(LIB)

run: fizzbuzz
	 ./fizzbuzz.exe

runtest: fizzbuzz
./integrationtest.tcl ./fizzbuzz.exe
