// reads from a file containing the format item,price,mm/dd/yyyy and outputs the
// data in columns

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: cols inputfile\n");
        exit(EXIT_FAILURE);
    }

    struct {
        int number, month, day, year;
        float price;
    } line;

    FILE *fpIn;
    if ((fpIn = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");

    int n;
    do {
        n = fscanf(fpIn, "%d,%f,%2d/%2d/%d%*c", &line.number, &line.price,
                   &line.month, &line.day, &line.year);
        if (n == 0 || n == EOF)
            break;
        if (n < 5) {
            fprintf(stderr,
                    "WARNING: A partial entry was read from the file\n");
            for (int i = 0; i < n; ++i) {
                switch (i) {
                case 1:
                    printf("%d\t\t", line.number);
                    break;
                case 2:
                    printf("$%7.2f\t", line.price);
                    break;
                    // didn't get full date so just dont print any of it
                }
            }
        }
        printf("%d\t\t$%7.2f\t%.2d/%.2d/%d\n", line.number, line.price,
               line.month, line.day, line.year);
    } while (!feof(fpIn));

    fclose(fpIn);

    return EXIT_SUCCESS;
}
