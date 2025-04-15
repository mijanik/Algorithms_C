#include <stdlib.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    // alokowanie pamięci na wynik
    *returnSize = 2;
    int* result = malloc(2*sizeof(int));

    for (int i = 0; i < numsSize; i++) { // iterowanie po pierwszej połowie liczb
        for (int j = i; j < numsSize; j++) {              // iterowanie po liczbach, ale zaczynając od i (unikanie powtórzeń)
            if ((nums[i] + nums[j] == target) && i != j) { // jeśli suma się zgadza i to nie jest ten sam indeks
                result[0] = i; // zapisywanie indeksów do wyniku
                result[1] = j;
                return result;
            }
        }
    }

    // Żadna para nie zostanie pominięta,
    // nie sprawdzasz par dwukrotnie w odwrotnej kolejności,
    // i != j nadal zabezpiecza przed zsumowaniem tego samego indeksu.
    // Możesz zrobić j = i + 1, wtedy i != j nie będzie potrzebne, bo nigdy nie trafi na siebie

    // jeśli nie znajdziesz — można zwrócić NULL albo ustawić *returnSize = 0
    *returnSize = 0;
    free(result);
    return NULL;
}


