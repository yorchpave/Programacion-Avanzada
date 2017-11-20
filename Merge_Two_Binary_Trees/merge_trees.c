#include <stdlib.h>
#include <stdio.h>
#include "merge_trees.h"

void printTree(struct TreeNode *tree, int level) {
    if (tree == NULL) {
        return;
    } else {
        printTree(tree->right, level + 1);

        for (int i = 0; i < level; i++) {
            printf("   ");
        }
        printf("%d\n", tree->val);

        printTree(tree->left, level + 1);
    }
}

struct TreeNode * mergeTrees(struct TreeNode * treeA, struct TreeNode *treeB) {
    struct TreeNode * treeC = (struct TreeNode *) malloc(sizeof(struct TreeNode));

    mergeTreesWork(treeA, treeB, treeC);

    return treeC;
}

void mergeTreesWork(struct TreeNode *treeA, struct TreeNode *treeB, struct TreeNode *treeC) {
    if (treeA != NULL || treeB != NULL) {
        if (treeA == NULL) {
            treeC->val = treeB->val;

            treeC->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            mergeTreesWork(treeA, treeB->left, treeC->left);
            treeC->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            mergeTreesWork(treeA, treeB->right, treeC->right);
        } else if (treeB == NULL) {
            treeC->val = treeA->val;

            treeC->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            mergeTreesWork(treeA->left, treeB, treeC->left);
            treeC->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            mergeTreesWork(treeA->right, treeB, treeC->right);
        } else {
            treeC->val = treeA->val + treeB->val;

            treeC->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            mergeTreesWork(treeA->left, treeB->left, treeC->left);
            treeC->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            mergeTreesWork(treeA->right, treeB->right, treeC->right);
        }
    }
    else {
        return;
    }
}
