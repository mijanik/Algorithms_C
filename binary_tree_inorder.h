//
// Created by Milosz on 2025-05-03.
//

#ifndef BINARY_TREE_INORDER_H
#define BINARY_TREE_INORDER_H
#include <stdlib.h>


//Definition for a binary tree node.
 struct TreeNode {int val;
  struct TreeNode *left;
  struct TreeNode *right;
 };

// Given the root of a binary tree, return the inorder traversal of its nodes' values.
// Note: The returned array must be malloced, assume caller calls free().

void inorderTraversalRecursive(struct TreeNode* root, int* traversal, int* traversalSize) {
    if (root == NULL || traversal == NULL || traversalSize == NULL) return;

    // Najpierw lewa strona
    if (root->left != NULL) {
        inorderTraversalRecursive(root->left, traversal, traversalSize);
    }

    // Później środek
    traversal[*traversalSize] = root->val;
    (*traversalSize)++;

    // Na końcu prawa
    if (root->right != NULL) {
        inorderTraversalRecursive(root->right, traversal, traversalSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL || returnSize == NULL) {
        if (returnSize != NULL) *returnSize = 0;
        return NULL;
    }
    // Alokacja pamięci na zwracany traversal - zakładamy jej zwalnianie
    int* traversal = malloc(100* sizeof(int));
    *returnSize = 0;

    inorderTraversalRecursive(root, traversal, returnSize);

    return traversal;
}

#endif //BINARY_TREE_INORDER_H
