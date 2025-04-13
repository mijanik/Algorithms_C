#include <stdio.h>
#include "reverse_linked_list.h"

char find_first_not_duplicate(char* string, int size) {

    // ilość wystąpień każdego chara -> indeks tablicy odpowiada kodowi ASCII chara
    int counts[256];

    // liczenie ile dana litera występuje razy
    for (int i = 0; i < size; i++) {
        int char_index = string[i];
        ++counts[char_index];
    }

    // iterowanie po stringu jeszcze raz
    for (int i = 0; i < size; i++) {
        if (counts[string[i]] == 1) {
            return string[i]; // jeśli dana litera występuje dokładnie raz, zwróć ją
        }
    }

    return 'a'; // żadna litera nie występuje jeden raz
}


int main(void) {
    printf("%c\n", find_first_not_duplicate("google", 6));

    reverse_linked_list_test();

    return 0;
}