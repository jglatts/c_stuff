#ifndef TREELIB_H
#define TREELIB_H

typedef struct  TreeNode {
        int data;
        struct TreeNode* left;
        struct TreeNode* right;
} TreeNode;

typedef struct Tree {
	TreeNode* root;
	int size;
} Tree;

Tree* make_new_tree();
TreeNode* set_random_root(int);
TreeNode* set_nodes_random(int, int);
TreeNode* set_children_nodes(int, int);
TreeNode* val_ptr;
void add_to_tree(Tree*, int);
void print_nodes(TreeNode*, int);
void test_tree();
int val_found;

#endif // TREELIB_H
