#include "quicksort.h"

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
