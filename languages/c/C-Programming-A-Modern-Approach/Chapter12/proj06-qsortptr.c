// quicksort but using pointers instead of indices

#include <stdio.h>

#define SIZE 10

void quickSort(int *low, int *high);
int *partition(int *low, int *high);

int main(void) {
    printf("Enter %d integers: ", SIZE);
    int nums[SIZE] = {0};
    for (int *p = nums; p < nums + SIZE; ++p)
        scanf("%d", p);

    quickSort(nums, nums + SIZE - 1);

    printf("Sorted: ");
    for (int *p = nums; p < nums + SIZE; ++p)
        printf("%d ", *p);

    return 0;
}

void quickSort(int *low, int *high) {
    if (low >= high)
        return;

    int *middle = partition(low, high);
    quickSort(low, middle - 1);
    quickSort(middle + 1, high);
}

int *partition(int *low, int *high) {
    int *piv = high;
    high -= 1;
    while (low <= high) {
        if (*high <= *piv) {
            int tmp = *low;
            *low++ = *high;
            *high = tmp;
        } else
            --high;
    }

    int tmp = *piv;
    *piv = *low;
    *low = tmp;

    return low;
}
