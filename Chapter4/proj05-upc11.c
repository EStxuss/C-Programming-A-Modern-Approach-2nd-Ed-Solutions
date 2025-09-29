// reads first 11 upc digits at one time and outputs check digit

#include <stdio.h>

int main(void) {
    printf("Enter the first 11 digits of the UPC: ");

    int sum1n1, sum1n2, sum1n3, sum1n4, sum1n5, sum1n6;
    int sum2n1, sum2n2, sum2n3, sum2n4, sum2n5;
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &sum1n1, &sum2n1, &sum1n2,
          &sum2n2, &sum1n3, &sum2n3, &sum1n4, &sum2n4, &sum1n5, &sum2n5,
          &sum1n6);

    int sum1 = sum1n1 + sum1n2 + sum1n3 + sum1n4 + sum1n5 + sum1n6;
    int sum2 = sum2n1 + sum2n2 + sum2n3 + sum2n4 + sum2n5;
    int total = 3 * sum1 + sum2;

    int checkDig = 9 - ((total - 1) % 10);
    printf("Check digit: %d\n", checkDig);

    return 0;
}
