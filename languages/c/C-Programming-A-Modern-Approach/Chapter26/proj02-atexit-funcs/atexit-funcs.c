// program to test order of execution of atexit registered functions

#include <stdio.h>
#include <stdlib.h>

void firstOutput(void) { printf("That's all,"); }

void secondOutput(void) { printf(" folks!\n"); }

int main(void) {
    atexit(secondOutput);
    atexit(firstOutput);

    return 0;
}