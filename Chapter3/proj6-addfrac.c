//user enters two fractions separated by plus side and gives the sum as a fraction

#include <stdio.h>

int main(void){
    printf("Enter two fractions separated by a plus sign: ");
    int denom1 = 0, numer1 = 0, denom2 = 0, numer2 = 0;

    scanf("%d / %d + %d / %d", &numer1, &denom1, &numer2, &denom2);

    int numerAns = numer1 * denom2 + numer2 * denom1;
    int denomAns = denom1 * denom2;

    printf("The sum is %d/%d\n", numerAns, denomAns);

    return 0;
}
