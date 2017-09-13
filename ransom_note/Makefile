all:
	 gcc -c ransom_note.c
	 gcc -c main.c
	 gcc -o main.exe ransom_note.o main.o

test_ransom_note: clean
	 gcc -c ransom_note.c
	 gcc -c test_ransom_note.c
	 gcc -o test_ransom_note.exe ransom_note.o test_ransom_note.o
	 ./test_ransom_note.exe

test:	 test_ransom_note

clean:
	 rm *.out *.o *.exe *.gch || exit 0

run:
	 gcc -c ransom_note.c
	 gcc -c main.c
	 gcc -o main.exe ransom_note.o main.o
./main.exe
