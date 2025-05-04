//
// Created by Milosz on 2025-05-03.
//

#ifndef SEARCH_INSERT_POS_H
#define SEARCH_INSERT_POS_H

//Given a sorted array of distinct integers and a target value, return the index if the target is found.
//If not, return the index where it would be if it were inserted in order.

int searchInsert(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= target)
            return i;
    }
    return numsSize;
}

#endif //SEARCH_INSERT_POS_H
