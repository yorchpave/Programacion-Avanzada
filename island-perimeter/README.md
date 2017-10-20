
# Island Perimeter

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:
```
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
```
![island_image](https://leetcode.com/static/images/problemset/island.png)

[Leetcode page](https://leetcode.com/problems/island-perimeter/description/)

### How to compile
```bash
make run
```

### How to run test
```bash
make test
```

### How to debug the program
```bash
gcc -g name_of_file.c -o name_of_file
gdb name_of_file
```

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
```bash
gcc -c module1.c # This command generates module1.o
gcc -c program-that-depends-of-module1.c
gcc -o program.out module1.o program-that-depends-of-module1.o
./program.out
```
