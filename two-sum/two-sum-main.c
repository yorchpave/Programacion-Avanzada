#include <stdio.h>
#include <stdlib.h>
#include "two_sum.h"

int main (int argc, char ** argv) {
    int nums[] = {-1, -2, -3, -4, -5};
    int target = -8, num_size = 5;
    int *result = two_sum(nums, num_size, target);
    if(result != NULL && nums[result[0]] + nums[result[1]] == target) {
        printf("[%d, %d] = %d \n", result[0], result[1], nums[result[0]] + nums[result[1]]);
        printf("It was true! \n");
    } else {
        printf("It lied! The MACHINE lied! \n");
    }
    free(result);
    return 0;
}
