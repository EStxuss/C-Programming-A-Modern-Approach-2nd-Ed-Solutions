// does xor encryption on a file passed as a cli arg

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: xor inputfile outputfile\n");
        exit(EXIT_FAILURE);
    }

    FILE *inputFile, *outputFile;
    if ((inputFile = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Couldn't open input file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    } else if ((outputFile = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Couldn't open output file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    int orig_char, new_char;
    while ((orig_char = getc(inputFile)) != EOF) {
        new_char = orig_char ^ KEY;
        putc(new_char, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}