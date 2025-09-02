// calculates money owned on a loan after the first three monthly payments

#include <stdio.h>

int main(void){
    float loanStart = 0.0f;
    printf("Enter amount of loan: ");
    scanf("%f", &loanStart);

    float yrInterestRt = 0.0f;
    printf("Enter the yearly interest rate percentage: ");
    scanf("%f", &yrInterestRt);
    float moInterestRt = yrInterestRt / 12 / 100;

    
    float moPayment = 0.0f;
    printf("Enter your monthly payment: ");
    scanf("%f", &moPayment);

    float firstMoBal = loanStart - moPayment;
    firstMoBal += loanStart * moInterestRt;
    float secondMoBal = firstMoBal - moPayment;
    secondMoBal += firstMoBal * moInterestRt;
    float thirdMoBal = secondMoBal - moPayment;
    thirdMoBal += secondMoBal * moInterestRt;

    printf("Your loan balance is %.2f after the first month\n", firstMoBal);
    printf("Your loan balance is %.2f after the second month\n", secondMoBal);
    printf("Your loan balance is %.2f after the third month\n", thirdMoBal);

    return 0;
}
