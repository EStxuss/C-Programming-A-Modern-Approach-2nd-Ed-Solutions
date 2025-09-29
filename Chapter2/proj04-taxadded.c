// adds a 5% tax to amount user inputs

#include <stdio.h>

int main(void) {
    float beforeTax = 0.0f;
    printf("Enter a dollar amount $*.xx: ");
    scanf("%f", &beforeTax);
    float afterTax = beforeTax + beforeTax * 0.05;
    printf("The amount after 5%% tax added is: %.2f\n", afterTax);

    return 0;
}
