// quicksort but using pointers instead of indices

#include "quicksort.h"
#include <stdio.h>

#define SIZE 10

int main(void) {
    printf("Enter %d integers: ", SIZE);
    int nums[SIZE] = {0};
    for (int *p = nums; p < nums + SIZE; ++p)
        scanf("%d", p);

    quickSort(nums, nums + SIZE - 1);

    printf("Sorted: ");
    for (int *p = nums; p < nums + SIZE; ++p)
        printf("%d ", *p);
    printf("\n");

    return 0;
}
