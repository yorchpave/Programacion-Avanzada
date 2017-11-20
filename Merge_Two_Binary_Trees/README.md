
# Merge two binary trees

## Problem Description
The problem I'm given is the following:

```
"Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree."
```

Here's an example input and output:

```
Input: 
	Tree 1                     Tree 2

          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  

Output: 
Merged tree:

                          3
                         / \
                        4   5
                       / \   \ 
                      5   4   7

```

## Approach to solving the problem

My first thought is to traverse both trees, if both trees match in having an element, create a new node with the sum of both values. Then go to the left subtree, do the same procedure, then go the right subtree, and so on.

For example, given the following struct for a TreeNode:

```
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
```

Pseudocode for the solution would be:

```
void mergeTrees (struct TreeNode *treeA, struct TreeNode *treeB, struct TreeNode *treeC) {
    if (treeA != NULL || treeB != NULL) {

        if (treeA == NULL) {
            treeC->val = treeB->val;

            treeC->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            mergeTrees(treeA, treeB->left, treeC->left);
            treeC->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            mergeTrees(treeA, treeB->right, treeC->right);

        } else if (treeB == NULL ) {
            treeC->val = treeA->val;

            treeC->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            mergeTrees(treeA->left, treeB, treeC->left);
            treeC->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            mergeTrees(treeA->right, treeB, treeC->right);

        } else {
            treeC->val = treeA->val + treeB->val

            treeC->left = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            mergeTrees(treeA->left, treeB->left, treeC->left);
            treeC->right = (struct TreeNode*) malloc(sizeof(struct TreeNode));
            mergeTrees(treeA->right, treeB->right, treeC->right);

        }
    else {
        return;
    }
}
```

This solution uses recursion to simulate the "hanging" of the state of each tree, A and B at that point. With the first example, I would start at the root and work around both trees in the following order:

```
The asterisk marks where the tree is pointed at.

Point a)

	Tree 1                     Tree 2

          1*                        2*                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7

    New Tree:
          3*
         /
       NULL             

First the algorithm would see both roots 1 and 2 and save their sum in a New Tree and allocate memory for its left child, and carry the recursion to that point.

Now the trees point to these points:

Point b)

	Tree 1                     Tree 2

          1                         2                             
         / \                       / \                            
        3*  2                     1*  3                        
       /                           \   \                      
      5                             4   7 

    New Tree:
          3
         /
        4*

And because both trees at that point have a value, the algorithm sums and we have the following tree.

Then we go to the left of that point because at least one of the trees isn't NULL at that point, but the one that is NULL we can forget about, for now:

Point c)

	Tree 1                     Tree 2

          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                         / \   \                      
      5*                        *   4   7

    New Tree:
          3
         /
        4
       /
      5*

Because on of the trees is NULL at this point, we use the value of the other tree to populate the New Tree.

Now both of the trees would point to NULL, so we go back to the point where there was a right subtree in either of the trees, that would be Point b) and go to the right from there.

Point d)

	Tree 1                     Tree 2

          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       / \                         \   \                      
      5   *                         4*  7

    New Tree:
          3
         /
        4
       / \
      5   4*

Because there is a value only at Tree 2, the algorithm takes that and makes the New Tree's value be that.

At this moment, there isn't a value in either tree in either direction, so we go back, again, to when there was a value to the right of whichever tree, that would be Point a) and we take a right from there.

Point e)

	Tree 1                     Tree 2

          1                         2                             
         / \                       / \                            
        3   2*                    1   3*                       
       /                           \   \                      
      5                             4   7

    New Tree:
          3
         / \
        4   5*
       / \
      5   4

At this point there's only one direction to take, right in Tree 2, so we take that and assign the value of Tree 2 at that point to the New Tree.

Point f)

	Tree 1                     Tree 2

          1                         2                             
         / \                       / \                            
        3   2                     1   3                       
       /     \                     \   \                      
      5       *                     4   7*

    New Tree:
          3
         / \
        4   5
       / \   \
      5   4   7*

At this point there aren't any values that aren't NULL, so the algorithm ends and returns the root of the new tree.
```

This algorithms complexity is O(n), where n is the number of nodes in the bigger tree.

## Compilation instructions

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

