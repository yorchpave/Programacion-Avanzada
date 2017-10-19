all:
	 gcc -c add-digits.c
	 gcc -c main.c
	 gcc -o main add-digits.o main.o

test_add-digits: clean
	 gcc -c add-digits.c
	 gcc -c test_add-digits.c
	 gcc -o test_add-digits.exe add-digits.o test_add-digits.o
	 ./test_add-digits.exe

test:	 test_add-digits

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c add-digits.c
	 gcc -c main.c
	 gcc -o main.exe add-digits.o main.o
./main
