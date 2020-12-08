#include "treelib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Tree* make_new_tree() {
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;
	tree->size = 0;
	return tree;
}

void add_to_tree(Tree* tree, int d) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = d;
	node->left = NULL;
	node->right = NULL;
	if (tree->root == NULL || tree->size == 0) {
		tree->root = node;
		tree->size++;
	} 
	else {
		TreeNode* current = tree->root;
		int count = 0;
		while (1) {
			if (current->left == NULL) {
				current->left = node;
				tree->size++;
				return;
			}
			else if (current->right == NULL) {
				current->right = node;
				tree->size++;
				return;
			}
			else {
				current = (count++ % 2 == 0) ? current->left : current->right;
			}
		}
	}
}

TreeNode* set_nodes_random(int val, int size) {
        TreeNode* root = set_random_root(val);
        TreeNode* current = root;
        for (int i = 1; i < size - 1; ++i) {
                TreeNode* left = (TreeNode*)malloc(sizeof(TreeNode));
                TreeNode* right = (TreeNode*)malloc(sizeof(TreeNode));
                left->data = (rand() % size) + 1; 
                right->data = (rand() % size) + 1;
                current->left = left;
                current->right = right;
                if (i % 2 == 0) {
                        current = left;
                        right->left = NULL;
                        right->right = NULL;
                }
                else {

                        current = right;
                        left->left = NULL;
                        left->right = NULL;
                }
                current = (i % 2 == 0) ? left : right;
        }
        current->left = NULL;
        current->right = NULL;
        return root;
}

TreeNode* set_random_root(int val) {
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        return root;
}

void print_nodes(TreeNode* node, int k) {
        if (node == NULL) return;
        if (node->data == k) {
                val_found = 1;
                val_ptr = node;
        }
        print_nodes(node->left, k);
        printf("Node Value = %d\nAddress %p\n\n", node->data, node);
        print_nodes(node->right, k);
}

void test_tree() {
        Tree* tree = make_new_tree();
	int n, k;
        srand((unsigned)time(0));
        printf("------------JDG TREE------------\n");
        printf("How Many Nodes In The Graph? -> ");
        scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int i = 0;
		printf("Enter Values -> ");
		scanf("%d", &i);
		puts("");
		add_to_tree(tree, i);	
	}
	print_nodes(tree->root, 69);
	/*
        printf("Value To Search For? -> ");
        scanf("%d", &k);
        print_nodes(set_nodes_random(5, n), k);
        if (val_found){
                 printf("Your Value %d Was Found!\n", k);
                 printf("At Node %p!\n", val_ptr); // prolly can use the int's addrss
        }
        else printf("Your Value %d Was Not Found :(\n", k);
	*/
}

