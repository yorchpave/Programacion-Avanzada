#include <stdio.h>
#include <stdlib.h>
#include "minunit.h"
#include "merge_trees.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int tests_run = 0;
static char * test_unit() {
	struct TreeNode *treeA = (struct TreeNode *) malloc(sizeof(struct TreeNode));
	struct TreeNode *treeB = (struct TreeNode *) malloc(sizeof(struct TreeNode));

	treeA->val = 1;
	treeA->left = (struct TreeNode *) malloc(sizeof(struct TreeNode));
	treeA->left->val = 3;
	treeA->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	treeA->right->val = 2;
	treeA->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	treeA->left->left->val = 5;

	treeB->val = 2;
	treeB->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	treeB->left->val = 1;
	treeB->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	treeB->right->val = 3;
	treeB->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	treeB->left->right->val = 4;
	treeB->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	treeB->right->right->val = 7;

	struct TreeNode *treeC = mergeTrees(treeA, treeB);
	mu_assert("Root", treeC->val == 3);
	mu_assert("First child left", treeC->left->val == 4);
	mu_assert("First child right", treeC->right->val == 5);
	mu_assert("Second child left left", treeC->left->left->val == 5);
	mu_assert("Second child left right", treeC->left->right->val == 4);
	mu_assert("Second child right right", treeC->right->right->val == 7);

	printTree(treeC, 0);
	return 0;
}

static char * all_tests() {
	mu_run_test(test_unit);
	return 0;
}
int main(int argc, char **argv) {
	char *result = all_tests();
	if (result != 0) {
		printf("-_-_-_-_-_-_-_,------,      o \n");
		printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
		printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
		printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
		printf(KRED "✗ %s\n" RESET, result);
	}
	else {
		printf("-_-_-_-_-_-_-_,------,      o \n");
		printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
		printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
		printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
		printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
	}
	printf("Tests run: %d\n", tests_run);
	return result != 0;
}
