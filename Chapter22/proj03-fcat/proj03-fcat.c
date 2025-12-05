// takes file name command line arguments and outputs their content to the
// console

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: fcat file1 file2 ...\n");
        exit(EXIT_FAILURE);
    }

    char *buf;
    if ((buf = malloc(BUF_SIZE)) == NULL) {
        fprintf(stderr, "Failed to allocate space for char buffer\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    int writeFlag;
    for (int i = 1; i < argc; ++i) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "\n\nCouldn't open file %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while (!feof(fp)) {
            if (fgets(buf, BUF_SIZE, fp) == NULL)
                break;
            if ((writeFlag = fputs(buf, stdout)) == EOF) {
                fprintf(stderr, "Failed to write to console\n");
                exit(EXIT_FAILURE);
            }
        }

        fclose(fp);
    }

    free(buf);

    return 0;
}