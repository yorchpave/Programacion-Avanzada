// Problem from LeetCode at https://leetcode.com/problems/two-sum/description/

#include <stdlib.h>
#include "two_sum.h"

int * two_sum (int * nums, int num_size, int target) {
    // You have to check each combination in case of negative numbers.
    int i, j;
    int * result = (int *) calloc(2, sizeof(int));
    for (i = 0; i < num_size - 1; i++) {
        for (j = i + 1; j < num_size; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i; result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}
