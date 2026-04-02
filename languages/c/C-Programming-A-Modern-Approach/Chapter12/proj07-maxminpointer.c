// maxmin.c from section 11.4 where the max and min element of an array are
// found but modified so that a pointer is used to track position in array

#include <stdio.h>

#define SIZE 10

void maxMin(int *const min, int *const max, int n, int nums[n]);

int main(void) {
    printf("Enter %d integers: ", SIZE);
    int nums[SIZE] = {0};
    for (int *p = nums; p < nums + SIZE; ++p)
        scanf("%d", p);

    int min, max;
    maxMin(&min, &max, SIZE, nums);

    printf("The largest was: %d\nThe smallest was: %d\n", max, min);

    return 0;
}

void maxMin(int *const min, int *const max, int n, int nums[n]) {
    *min = (*nums > *(nums + 1)) ? *(nums + 1) : *nums;
    *max = (*nums > *(nums + 1)) ? *nums : *(nums + 1);

    for (int *p = nums + 2; p < nums + n; ++p) {
        if (*p < *min)
            *min = *p;
        else if (*p > *max)
            *max = *p;
    }
}
