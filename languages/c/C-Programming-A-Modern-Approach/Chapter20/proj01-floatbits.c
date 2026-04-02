#include <stdio.h>

int main(void) {
    union {
        float f;
        struct {
            unsigned int frac : 23;
            unsigned int expo : 8;
            unsigned int sign : 1;
        } fBits;
    } floatU;

    floatU.fBits.frac = 0;
    floatU.fBits.expo = 128;
    floatU.fBits.sign = 1;

    printf("%f\n", floatU.f);

    return 0;
}