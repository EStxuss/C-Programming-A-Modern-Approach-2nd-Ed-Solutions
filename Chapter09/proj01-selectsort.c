// sorts an array by finding the largest element in each pass

#include <stdio.h>

#define MAX_SIZE 100

void selectionSort(int n, int a[n]);

int main(void) {
    printf("Enter a series of integers: ");

    int size = 0, nums[MAX_SIZE];
    char c = '\0';
    for (int i = 0; i < MAX_SIZE && c != '\n'; ++i, c = getchar()) {
        scanf("%d", &nums[i]);
        ++size;
    }

    selectionSort(size, nums);

    printf("Sorted numbers: ");
    for (int i = 0; i < size; ++i)
        printf("%d  ", nums[i]);
    printf("\n");

    return 0;
}

void selectionSort(int n, int a[n]) {
    if (n == 1)
        return;

    int largestIdx = 0;
    for (int i = 1; i < n; ++i)
        if (a[i] > a[largestIdx])
            largestIdx = i;

    int tmp = a[n - 1];
    a[n - 1] = a[largestIdx];
    a[largestIdx] = tmp;

    selectionSort(n - 1, a);
}
