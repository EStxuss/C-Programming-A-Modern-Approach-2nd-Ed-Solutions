#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: uncompress filename.rle");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1] + (strlen(argv[1]) - 4), ".rle") != 0) {
        printf("The file %s is not a compressed file ending in .rle\n",
               argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *comprFp, *uncomprFp;
    if ((comprFp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Couldn't open file %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // input.txt
    const char *extStr = ".uncompress_file";
    char uncomprFilename[strlen(argv[1]) - 4 + strlen(extStr) + 1];
    strncpy(uncomprFilename, argv[1], strlen(argv[1]) - 4);
    uncomprFilename[strlen(argv[1]) - 4] = 0;
    strcat(uncomprFilename, extStr);

    if ((uncomprFp = fopen(uncomprFilename, "wb")) == NULL) {
        fprintf(stderr, "Couldn't open file %s for writing\n", uncomprFilename);
        exit(EXIT_FAILURE);
    }

    int count = getc(comprFp), ch = getc(comprFp);
    while (count != EOF || ch != EOF) {
        if (count != EOF && ch == EOF) {
            fprintf(stderr, "Found count but no matching byte\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < count; ++i)
            putc(ch, uncomprFp);

        count = getc(comprFp);
        ch = getc(comprFp);
    }

    return 0;
}