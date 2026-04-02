// takes a text file name as a cli arg and outputs how many characters, words,
// lines it contains

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: counts filename\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Couldn't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int chars, words, lines;
    chars = words = lines = 0;

    while (getc(fp) != EOF)
        ++chars;
    fseek(fp, 0L, SEEK_SET);

    while (!feof(fp)) {
        if (fscanf(fp, "%*s") != EOF)
            ++words;
    }
    fseek(fp, 0L, SEEK_SET);

    while (!feof(fp)) {
        fscanf(fp, "%*[^\n]%*c");
        ++lines;
    }

    printf("Chars: %d\nWords: %d\nLines: %d\n", chars, words, lines);

    return 0;
}