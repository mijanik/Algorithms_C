//
// Created by Milosz on 2025-04-13.
//

#include "reverse_linked_list.h"

typedef struct Node{
    int value;
    struct Node* prev;
    struct Node* next;
} Node_t;

Node_t* create_node(const int value) {
    Node_t* new_node = malloc(sizeof(Node_t));
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// usuwanie pojedynczego node
void delete_node(Node_t* node) {
    free(node);
}

// Usuwanie całej listy zaczynając od head
void delete_list(Node_t* head) {
    Node_t* current = head;
    while (current != NULL) {
        Node_t* temp = current->next;
        free(current);
        current = temp;
    }
}

// Funkcja do wypisywania listy od początku
void print_list(Node_t* head) {
    Node_t* current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next) printf(" <-> ");
        current = current->next;
    }
    printf("]\n");
}


Node_t* reverseList(Node_t* head) {
    // Pusta lista
    if (head == NULL) return NULL;

    // bieżący element listy, po której iterujemy
    Node_t* current = head;

    while (current->next != NULL) {
        Node_t *temp = current->prev;  // tymczasowy element do przechowania prev
        current->prev = current->next; // poprzedni to teraz następny
        current->next = temp;          // a następny to poprzedni
        current = current->prev;       // kolejny element (czyli w nowej kolejności poprzedni)
    }

    // ostatni element listy jest teraz pierwszym
    current->next = current->prev;
    current->prev = NULL;
    return current;
}

void reverse_linked_list_test() {
    // Test 1: Lista z 3 elementami
    Node_t* n1 = create_node(1);
    Node_t* n2 = create_node(2);
    Node_t* n3 = create_node(3);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    printf("Test 1 - Original list:\n");
    print_list(n1);

    Node_t* reversed = reverseList(n1);
    printf("Test 1 - Reversed list:\n");
    print_list(reversed);

    if (reversed && reversed->value == 3 && reversed->next->value == 2 && reversed->next->next->value == 1) {
        printf("Test 1 passed.\n\n");
    } else {
        printf("Test 1 failed.\n\n");
    }

    // Test 2: Lista jednoelementowa
    Node_t* single = create_node(42);
    reversed = reverseList(single);
    printf("Test 2 - Single node reversed:\n");
    print_list(reversed);

    if (reversed && reversed->value == 42 && reversed->next == NULL && reversed->prev == NULL) {
        printf("Test 2 passed.\n\n");
    } else {
        printf("Test 2 failed.\n\n");
    }

    // Test 3: Lista pusta
    reversed = reverseList(NULL);
    printf("Test 3 - Empty list reversed:\n");
    if (reversed == NULL) {
        printf("Test 3 passed.\n\n");
    } else {
        printf("Test 3 failed.\n\n");
    }

    delete_node(n1);
    delete_node(n2);
    delete_node(n3);
}