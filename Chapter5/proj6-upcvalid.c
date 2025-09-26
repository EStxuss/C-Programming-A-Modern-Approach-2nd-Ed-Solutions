// takes upc number input and outputs if the upc is valid

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int a1, b1, b2, b3, b4, b5, c1, c2, c3, c4, c5, d1;
    a1 = b1 = b2 = b3 = b4 = b5 = c1 = c2 = c3 = c4 = c5 = d1 = -1;
    printf("Enter a UPC number: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &a1, &b1, &b2, &b3, &b4, &b5,
          &c1, &c2, &c3, &c4, &c5, &d1);

    int sum1 = a1 + b2 + b4 + c1 + c3 + c5;
    int sum2 = b1 + b3 + b5 + c2 + c4;
    int checkCompute = 9 - (((sum1 * 3 + sum2) - 1) % 10);

    bool checkMatch = checkCompute == d1;

    switch (checkMatch) {
    case true:
        printf("VALID\n");
        break;
    case false:
        printf("INVALID\n");
        break;
    }

    return 0;
}
