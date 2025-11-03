#include "qsort.h"

int partition(int lo, int hi, struct part parts[]) {
    int pIdx = hi--;
    while (lo <= hi) {
        if (parts[hi].number <= parts[pIdx].number) {
            struct part tmp = parts[hi];
            parts[hi] = parts[lo];
            parts[lo++] = tmp;
        } else
            --hi;
    }
    struct part tmp = parts[pIdx];
    parts[pIdx] = parts[lo];
    parts[lo] = tmp;
    return lo;
}

void quicksort(int lo, int hi, struct part parts[]) {
    if (lo >= hi)
        return;

    int middle = partition(lo, hi, parts);
    quicksort(lo, middle - 1, parts);
    quicksort(middle + 1, hi, parts);
}
