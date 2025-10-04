// outputs original commision and rival commision given stock trade info

#include <stdio.h>

int main(void) {
    printf("Enter the number of shares: ");
    int sharesNum = 0;
    scanf("%d", &sharesNum);

    printf("Enter the share price: ");
    float sharePrice = 0.0f;
    scanf("%f", &sharePrice);

    float tradePrice = sharePrice * sharesNum;
    float origCommision = 0.00f;
    if (tradePrice < 2500.00f)
        origCommision = 30.00f + tradePrice * 0.017f;
    else if (tradePrice < 6250.00f)
        origCommision = 56.00f + tradePrice * 0.0066f;
    else if (tradePrice < 20000.00f)
        origCommision = 76.00f + tradePrice * 0.0034f;
    else if (tradePrice < 50000.00f)
        origCommision = 100.00f + tradePrice * 0.0022f;
    else if (tradePrice < 500000.00f)
        origCommision = 155.00f + tradePrice * 0.0011f;
    else
        origCommision = 255.00f + tradePrice * 0.0009f;

    if (origCommision < 39.00f)
        origCommision = 39.00f;

    float rivalCommision = 0.00f;
    if (sharesNum < 2000)
        rivalCommision = 33.00f + 0.03f * sharesNum;
    else
        rivalCommision = 33.00f + 0.02f * sharesNum;

    printf("The commision will be: $%.2f\nA rival broker charges: $%.2f\n",
           origCommision, rivalCommision);

    return 0;
}
