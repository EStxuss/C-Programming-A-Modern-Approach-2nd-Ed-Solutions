// generates random numbers that are between [0, INT_MAX / 2] and
// puts them in numbers.txt

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "numbers.txt"
#define PER_LINE 25

int main(void) {
    srand(time(NULL));

    FILE *fpOut = fopen(FILE_NAME, "w");
    if (fpOut == NULL) {
        fprintf(stderr, "Couldn't open write file " FILE_NAME);
        exit(EXIT_FAILURE);
    }

    printf("How many numbers to generate? ");
    int numAmt;
    scanf("%d", &numAmt);

    int lineCount;
    while (numAmt > 0) {
        lineCount = (numAmt < PER_LINE) ? numAmt : PER_LINE;
        for (int i = 0; i < lineCount; ++i) {
            if (fprintf(fpOut, "%d ", rand() % (INT_MAX / 2 + 1)) < 0) {
                fprintf(stderr, "Error writing a number to file\n");
                exit(EXIT_FAILURE);
            }
        }
        numAmt -= lineCount;
        fprintf(fpOut, "\n");
    }

    if (feof(fpOut) || ferror(fpOut)) {
        fprintf(stderr,
                "WARNING: There was problems writing to file " FILE_NAME);
        exit(EXIT_FAILURE);
    }

    if (fclose(fpOut) == EOF) {
        fprintf(stderr, "WARNING: " FILE_NAME " error on close\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}