//
// Created by Milosz on 2025-04-13.
//

#ifndef REVERSE_LINKED__LIST_H
#define REVERSE_LINKED__LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int value;
    struct Node* prev;
    struct Node* next;
} Node_t;

Node_t* create_node(const int value);

void delete_node(Node_t* node);

void delete_list(Node_t* head);

void print_list(Node_t* head);

Node_t* reverseList(Node_t* head);

void reverse_linked_list_test();

#endif //REVERSE_LINKED__LIST_H
