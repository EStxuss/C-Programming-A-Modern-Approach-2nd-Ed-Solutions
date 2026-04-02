// prompts user for filename of file containing a message and ecrypts and
// outputs it to a file with .enc extension

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR2(x) #x
#define STR1(x) STR2(x)

#define MAX_FILENAME_LEN 100
#define EXT_LEN 4

int main(void) {
    printf("Enter filename containing message: ");

    char filename[MAX_FILENAME_LEN + 1];
    int nFilename = scanf("%" STR1(MAX_FILENAME_LEN) "s", filename);
    if (nFilename == 0) {
        fprintf(stderr, "Unable to read filename from the user\n");
        exit(EXIT_FAILURE);
    }

    FILE *fpIn = fopen(filename, "r");
    if (fpIn == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char filenameOut[MAX_FILENAME_LEN + EXT_LEN + 1];
    strcpy(filenameOut, filename);
    strcat(filenameOut, ".enc");

    FILE *fpOut = fopen(filenameOut, "w");
    if (fpOut == NULL) {
        fprintf(stderr, "Couldn't open file %s for writing\n", filenameOut);
        exit(EXIT_FAILURE);
    }

    int shiftAmt = -1;
    int retries = 3;

    do {
        printf("Enter a shift amount (1-25): ");
        int n = scanf("%d", &shiftAmt);
        if (n == 1 && (shiftAmt >= 1 && shiftAmt <= 25))
            break;
    } while (--retries);
    if (shiftAmt == -1) {
        fprintf(stderr, "Didn't get a valid shift amount from user\n");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = getc(fpIn)) != EOF) {
        if (isalpha(ch)) {
            if (islower(ch))
                ch = 'a' + (((ch - 'a') + shiftAmt) % 26);
            else
                ch = 'A' + (((ch - 'A') + shiftAmt) % 26);
        }
        if ((putc(ch, fpOut)) == EOF) {
            fprintf(stderr, "Couldn't write char to file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fpIn);
    fclose(fpOut);

    return 0;
}
