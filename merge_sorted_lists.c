#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Funkcja pomocnicza do tworzenia nowego węzła listy
static struct ListNode* create_node(int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Funkcja pomocnicza do tworzenia listy z tablicy
struct ListNode* create_list_from_array(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = create_node(arr[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = create_node(arr[i]);
        current = current->next;
    }
    return head;
}

// Funkcja pomocnicza do wypisywania listy
static void print_list(struct ListNode* head) {
    printf("[");
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("]\n");
}


// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list.
// The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode* current_list1 = list1; // aktualna pozycja na liście 1
    struct ListNode* current_list2 = list2; // aktualna pozycja na liście 2
    struct ListNode* new_head;              // początek nowej listy

    // wyznaczanie nowego początku i przesuwanie pozycji adekwatnej listy
    if (current_list1->val < current_list2->val) {
        new_head = current_list1;
        current_list1 = current_list1->next;
    }
    else {
        new_head = current_list2;
        current_list2 = current_list2->next;
    }

    // aktualna pozycja nowej listy
    struct ListNode *current = new_head;

    while (current_list1 != NULL || current_list2 != NULL) {
        if ((current_list1 != NULL && current_list2 != NULL && current_list1->val < current_list2->val)
            || current_list2 == NULL) {
            // jeśli element list1 < list2 lub list2 już się skończyła to dodaj element list1
            current->next = current_list1;
            current_list1 = current_list1->next;
            current = current->next;
        }
        else if ((current_list1 != NULL && current_list2 != NULL && current_list1->val >= current_list2->val)
            || current_list1 == NULL) {
            // jeśli element list1 >= list2 lub list1 już się skończyła to dodaj element list2
            current->next = current_list2;
            current_list2 = current_list2->next;
            current = current->next;
        }
    }

    return new_head;
}

// Funkcja testująca
void test_merge_lists() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    struct ListNode* list1 = create_list_from_array(arr1, 3);
    struct ListNode* list2 = create_list_from_array(arr2, 3);

    printf("List 1: ");
    print_list(list1);
    printf("List 2: ");
    print_list(list2);

    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    print_list(merged);

    // Oczekiwany wynik: [1 -> 1 -> 2 -> 3 -> 4 -> 4]
}