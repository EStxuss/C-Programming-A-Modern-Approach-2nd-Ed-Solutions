// outputs number of bytes of different types for an implementation

#include <stdio.h>

int main(void) {
    printf("Sizes of types for your system:\nint: %zu\nshort: %zu\nlong: "
           "%zu\nfloat: %zu\ndouble: %zu\nlong double: %zu\n",
           sizeof(int), sizeof(short), sizeof(long), sizeof(float),
           sizeof(double), sizeof(long double));

    return 0;
}
