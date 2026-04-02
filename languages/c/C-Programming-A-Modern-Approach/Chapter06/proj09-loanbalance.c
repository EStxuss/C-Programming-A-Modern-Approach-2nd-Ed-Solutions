// calculates money owned on a loan after an input amount of payments

#include <stdio.h>

int main(void) {
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

    int numPayments;
    printf("Display how many payments? ");
    scanf("%d", &numPayments);

    float runningBal = loanStart, prevBal;
    for (int payNum = 1; payNum <= numPayments && runningBal > 0.0f; ++payNum) {
        prevBal = runningBal;
        runningBal = prevBal - moPayment;
        runningBal += prevBal * moInterestRt;
        printf("Loan balance after payment %d: %.2f\n", payNum, runningBal);
    }

    return 0;
}
