//
// Created by Milosz on 2025-04-13.
//

#include "balanced_tree.h"


// Given a binary tree, determine if it is height-balanced.

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
    return new_tree_node;
}

void delete_tree(TreeNode_t* root) {
    if (root == NULL) return;

    // najpierw usuwam dzieci
    delete_tree(root->left);
    delete_tree(root->right);

    free(root); // a później bieżący
}

// Funkcja do sprawdzania wysokości drzewa i jego zbalansowania
// Zwraca wysokość.
// Przyjmuje wskaźnik do korzenia drzewa i wskaźnik do balansu (którego wartość zmienia).
int get_tree_height(TreeNode_t* root, int* balance) {
    if (root == NULL) return 0;
    int left_height = 0;
    int right_height = 0;

    // sprawdź wysokość i balans drzew po lewej i po prawej stronie
    if (root->left != NULL) {
        left_height = get_tree_height(root->left, balance);
    }
    if (root->right != NULL) {
        right_height = get_tree_height(root->right, balance);
    }

    //printf("DEBUG: Left height: %d, right height: %d\n", left_height, right_height);

    // sprawdź balans z perspektywy bieżącego roota -> 1 = jest OK; 0 = niezbalansowane,
    // jeśli już jakieś było niezbalansowane to nawet nie trzeba sprawdzać
    if (balance != NULL && *balance != 0)
        *balance = (abs(left_height-right_height) <= 1);

    // if (balance != NULL)
    //     printf("DEBUG: Balance: %d\n", *balance);

    // nie ma już kolejnych gałęzi - wysokość aktualnego drzewa to 1
    if (root->left == NULL && root->right == NULL) return 1; // w sumie to niepotrzebne, poniżej to wystarczy

    // wysokość drzewa to jego najdłuższa gałąź
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

int is_balanced(TreeNode_t* root) {
    if (root == NULL) return 1;
    int balance = 1;
    get_tree_height(root, &balance);
    return balance;
}

///////////////////////////////////////////////////////////////////

void test_get_tree_height() {
    // Test 1: Puste drzewo
    TreeNode_t* root1 = NULL;
    int h1 = get_tree_height(root1, NULL);
    if (h1 == 0) {
        printf("Test 1 passed (empty tree).\n");
    } else {
        printf("Test 1 failed: got %d, expected 0.\n", h1);
    }

    // Test 2: Jednowęzłowe drzewo
    TreeNode_t* root2 = malloc(sizeof(TreeNode_t));
    root2->left = NULL;
    root2->right = NULL;
    int h2 = get_tree_height(root2, NULL);
    if (h2 == 1) {
        printf("Test 2 passed (single node).\n");
    } else {
        printf("Test 2 failed: got %d, expected 1.\n", h2);
    }
    free(root2);

    // Test 3: Małe drzewo binarne (pełne)
    TreeNode_t* root3 = malloc(sizeof(TreeNode_t));
    TreeNode_t* n3_left = malloc(sizeof(TreeNode_t));
    TreeNode_t* n3_right = malloc(sizeof(TreeNode_t));
    root3->left = n3_left;
    root3->right = n3_right;
    n3_left->left = NULL;
    n3_left->right = NULL;
    n3_right->left = NULL;
    n3_right->right = NULL;
    int h3 = get_tree_height(root3, NULL);
    if (h3 == 2) {
        printf("Test 3 passed (full binary tree).\n");
    } else {
        printf("Test 3 failed: got %d, expected 2.\n", h3);
    }
    free(n3_left);
    free(n3_right);
    free(root3);

    // Test 4: Niezbalansowane drzewo (głębokie w lewo)
    TreeNode_t* root4 = malloc(sizeof(TreeNode_t));
    TreeNode_t* l1 = malloc(sizeof(TreeNode_t));
    TreeNode_t* l2 = malloc(sizeof(TreeNode_t));
    root4->left = l1;
    root4->right = NULL;
    l1->left = l2;
    l1->right = NULL;
    l2->left = NULL;
    l2->right = NULL;
    int h4 = get_tree_height(root4, NULL);
    if (h4 == 3) {
        printf("Test 4 passed (left-skewed).\n");
    } else {
        printf("Test 4 failed: got %d, expected 3.\n", h4);
    }
    free(l2);
    free(l1);
    free(root4);
}


void test_case_unbalanced_deep_left() {
    // [1,2,2,3,3,NULL,NULL,4,4]

    TreeNode_t* root = create_treenode(1);
    root->left = create_treenode(2);
    root->right = create_treenode(2);

    root->left->left = create_treenode(3);
    root->left->right = create_treenode(3);

    root->left->left->left = create_treenode(4);
    root->left->left->right = create_treenode(4);

    printf("Test - Deep unbalanced left subtree:\n");

    if (!is_balanced(root)) {
        printf("Test passed (correctly detected unbalanced tree).\n\n");
    } else {
        printf("Test failed (should be unbalanced).\n\n");
    }

    delete_tree(root);
}

void test_case_symmetric_but_unbalanced() {
    // [1,2,2,3,NULL,NULL,3,4,NULL,NULL,4]

    TreeNode_t* root = create_treenode(1);
    root->left = create_treenode(2);
    root->right = create_treenode(2);

    root->left->right = create_treenode(3);
    root->left->right->right = create_treenode(4);

    root->right->right = create_treenode(3);
    root->right->right->right = create_treenode(4);

    printf("Test - Symmetric but unbalanced:\n");

    if (!is_balanced(root)) {
        printf("Test passed (correctly detected unbalanced tree).\n\n");
    } else {
        printf("Test failed (should be unbalanced).\n\n");
    }

    delete_tree(root);
}
