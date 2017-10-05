all:
	 gcc -c keyboard_row.c
	 gcc -c main.c
	 gcc -o main.exe keyboard_row.o main.o

test_keyboard_row: clean
	 gcc -c keyboard_row.c
	 gcc -c test_keyboard_row.c
	 gcc -o test_keyboard_row.exe keyboard_row.o test_keyboard_row.o
	 ./test_keyboard_row.exe

test:	 test_keyboard_row

clean:
	 rm *.out *.o *.exe *.gch || exit 0

run:
	 gcc -c keyboard_row.c
	 gcc -c main.c
	 gcc -o main.exe keyboard_row.o main.o
	 ./main.exe
