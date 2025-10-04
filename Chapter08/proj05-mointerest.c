// compounds monthly interest starting at $100

#include <stdio.h>

int main(void) {
    float interestInput;
    int years;
    printf("Enter interest rate: ");
    scanf("%f", &interestInput);

    printf("Enter number of years: ");
    scanf("%d", &years);

    float value[5] = {100.0f, 100.0f, 100.0f, 100.0f, 100.0f};
    float interestRt[5] = {interestInput / 100, (interestInput + 1) / 100,
                           (interestInput + 2) / 100, (interestInput + 3) / 100,
                           (interestInput + 4) / 100};

    printf("\nYears%8.1f%%%11.1f%%%11.1f%%%11.1f%%%11.1f%%\n",
           interestRt[0] * 100, interestRt[1] * 100, interestRt[2] * 100,
           interestRt[3] * 100, interestRt[4] * 100);
    for (int i = 0; i < years; ++i) {
        printf("%3d", i + 1);
        for (int j = 0; j < 5; ++j) {
            for (int mo = 0; mo < 12; ++mo) {
                value[j] += value[j] * (interestRt[j] / 12);
            }
            printf("%12.2f", value[j]);
        }
        printf("\n");
    }

    return 0;
}
