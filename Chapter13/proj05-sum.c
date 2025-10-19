// adds up the command line argument integers

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *p = argv[argc - 1];
    int total = 0;
    while (p != *argv) {
        total += atoi(p--);
    }

    printf("The sum is: %d\n", total);

    return 0;
}
