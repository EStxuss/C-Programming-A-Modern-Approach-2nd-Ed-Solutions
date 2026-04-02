// outputs income tax based on income input

#include <stdio.h>

float incomeTax(float income);

int main(void) {
    printf("Enter your taxable income: ");

    float income;
    scanf("%f", &income);

    printf("The tax due is: %.2f\n", incomeTax(income));

    return 0;
}

float incomeTax(float income) {
    float taxDue;

    if (income < 750.00f)
        taxDue = income * 0.01f;
    else if (income < 2250.00f)
        taxDue = 7.50f + ((income - 750.00f) * 0.02f);
    else if (income < 3750.00f)
        taxDue = 37.50f + ((income - 2250.00f) * 0.03f);
    else if (income < 5250.00f)
        taxDue = 82.50f + ((income - 3750.00f) * 0.04f);
    else if (income <= 7000.00f)
        taxDue = 142.50f + ((income - 5250.00f) * 0.05f);
    else
        taxDue = 230.00f + ((income - 7000.00f) * 0.06f);

    return taxDue;
}
