all:
	 gcc -c Reverse_String.c
	 gcc -c main.c
	 gcc -o main.exe Reverse_String.o main.o

test_Reverse_String: clean
	 gcc -c Reverse_String.c
	 gcc -c test_Reverse_String.c
	 gcc -o test_Reverse_String.exe Reverse_String.o test_Reverse_String.o
	 ./test_Reverse_String.exe

test:	 test_Reverse_String

clean:
	 rm *.out *.o *.exe *.gch || exit 0

run:
	 gcc -c Reverse_String.c
	 gcc -c main.c
	 gcc -o main.exe Reverse_String.o main.o
	 ./main.exe
