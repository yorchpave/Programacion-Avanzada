struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void printTree(struct TreeNode *, int);

struct TreeNode * mergeTrees(struct TreeNode *, struct TreeNode *);

void mergeTreesWork(struct TreeNode *, struct TreeNode *, struct TreeNode *);
