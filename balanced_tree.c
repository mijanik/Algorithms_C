//
// Created by Milosz on 2025-04-13.
//
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode_t;

TreeNode_t* create_treenode(const int value) {
    TreeNode_t* new_tree_node = malloc(sizeof(TreeNode_t));
    new_tree_node->value = value;
    new_tree_node->left = NULL;
    new_tree_node->right = NULL;
}

void delete_tree(TreeNode_t* root) {
    if (root == NULL) return;

    // najpierw usuwam dzieci
    delete_tree(root->left);
    delete_tree(root->right);

    free(root); // a później bieżący
}