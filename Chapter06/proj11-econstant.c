// approximates the math constant e with input number of terms

#include <stdio.h>

int main(void) {
    int adds;
    printf("Enter the number of additions to approximate constant e: ");
    scanf("%d", &adds);

    int denom = 1;
    float eVal = 1.0f;
    for (int i = 1; i <= adds; ++i) {
        denom *= i;
        eVal += 1.0f / (denom);
    }

    printf("Approximation of e: %.8f\n", eVal);

    return 0;
}
