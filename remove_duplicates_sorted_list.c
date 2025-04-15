// Edytuje wejściową tablicę tak, że pierwsze x elementów nie ma duplikatów i jest dalej posortowane.
// Zwraca x, czyli rozmiar "nowej" tablicy.
// np [1, 2, 2, 2, 3, 5] -> [1, 2, 3, 5, ?, ?] ; x = 4
int removeDuplicates(int* nums, int numsSize) {
                         //                                 last_unique    current
                          //                                           V  V
    int last_unique = 0; // indeks ostatniej unikalnej cyfry np [1, 2, 3, 3, 4]

    for (int current = 0; current< numsSize; current++) {
        if (nums[current] != nums[last_unique]) { // jeśli bieżący element jest inny niż ostatni unikalny
            last_unique++;                        // zwiększamy indeks ostatniej unikalnej cyfry
            nums[last_unique] = nums[current];    // i nową cyfrę wpisujemy pod ten indeks
        }
        // jeśli current jest taki sam jak ostatni unikalny, to tylko current zwiększa się o 1 ->
    }
    return last_unique+1;
}