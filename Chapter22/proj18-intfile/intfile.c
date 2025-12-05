// takes a file as a cli arg that has <= 10,000 integers seperated by spaces and
// outputs the min, max and median found

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_INTS 10000

int compareInts(const void *num1, const void *num2);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: intfile inputfile\n");
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    FILE *fpIn = fopen(filename, "r");
    if (fpIn == NULL) {
        fprintf(stderr, "Couldn't open read file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    struct {
        int *arr;
        int size, capacity;
    } nums;

    nums.capacity = 50;
    nums.size = 0;
    nums.arr = malloc(sizeof(int) * nums.capacity);
    if (nums.arr == NULL) {
        fprintf(stderr, "Unable to allocate memory for numbers array\n");
        exit(EXIT_FAILURE);
    }

    int n, ch;
    while (!feof(fpIn) && nums.size < MAX_FILE_INTS) {
        n = fscanf(fpIn, "%d", &nums.arr[nums.size]);
        if (n == 0) {
            fprintf(stderr, "WARNING: Failed to read a number\n");
            continue;
        } else if (n == EOF)
            break;
        else {
            if (nums.arr[nums.size] > INT_MAX / 2)
                fprintf(stderr,
                        "WARNING: Found number that might cause overflow\n");
            nums.size++;
        }
        // resizing
        if (nums.size == nums.capacity && nums.capacity != MAX_FILE_INTS) {
            nums.capacity =
                (nums.capacity * 2 > 10000) ? 10000 : nums.capacity * 2;

            nums.arr = realloc(nums.arr, nums.capacity * sizeof(int));
            if (nums.arr == NULL) {
                fprintf(stderr, "Couldn't resize numbers array\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    if (nums.size == 0) {
        printf("There were no integers found\n");
        exit(EXIT_SUCCESS);
    }

    qsort(nums.arr, nums.size, sizeof(int), compareInts);

    int min = nums.arr[0], max = nums.arr[nums.size - 1];

    int mid;
    if (nums.size % 2 == 0) {
        int l = nums.arr[(nums.size - 1) / 2];
        int r = nums.arr[(nums.size - 1) / 2 + 1];
        mid = (l + r) / 2;
    } else {
        mid = nums.arr[nums.size / 2];
    }

    printf("Found %d integers in file %s\n", nums.size, filename);
    printf("Smallest: %d\nLargest: %d\nMedian: %d\n", min, max, mid);

    free(nums.arr);
    fclose(fpIn);

    return EXIT_SUCCESS;
}

int compareInts(const void *num1, const void *num2) {
    return *((const int *)num1) - *((const int *)num2);
}