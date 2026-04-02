#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int intComp(const void *num1, const void *num2) {
    return *((int *)num1) - *((int *)num2);
}

int main(void) {
    FILE *fOut = fopen("output.txt", "w");
    if (!fOut) {
        fprintf(stderr, "Couldn't open file\n");
        exit(EXIT_FAILURE);
    }

    int *arrThousand = malloc(sizeof(int) * 1000);
    int *arrTThousand = malloc(sizeof(int) * 10000);
    int *arrHThousand = malloc(sizeof(int) * 100000);

    if (arrThousand == NULL || arrTThousand == NULL || arrHThousand == NULL) {
        fprintf(stderr, "Failed to allocate arrays\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0, j = 1000; i < 1000; ++i, --j)
        arrThousand[i] = j;
    for (int i = 0, j = 10000; i < 10000; ++i, --j)
        arrTThousand[i] = j;
    for (int i = 0, j = 100000; i < 100000; ++i, --j)
        arrHThousand[i] = j;

    clock_t start = clock();
    qsort(arrThousand, 1000, sizeof(int), intComp);
    clock_t end = clock();
    long double secThousand = (end - start) / (long double)CLOCKS_PER_SEC;

    start = clock();
    qsort(arrTThousand, 10000, sizeof(int), intComp);
    end = clock();
    long double secTThousand = (end - start) / (long double)CLOCKS_PER_SEC;

    start = clock();
    qsort(arrHThousand, 100000, sizeof(int), intComp);
    end = clock();
    long double secHThousand = (end - start) / (long double)CLOCKS_PER_SEC;

    fprintf(fOut,
            "Sort times:\n1000 elements: %Lf seconds\n10,000 elements: %Lf "
            "seconds\n100,000 elements: %Lf seconds",
            secThousand, secTThousand, secHThousand);

    return 0;
}
