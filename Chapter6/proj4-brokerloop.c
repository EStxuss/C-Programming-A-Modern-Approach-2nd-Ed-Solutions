// outputs commision for a given trade value until user enters 0

#include <stdio.h>

int main(void){
    float tradeVal;
    printf("Enter value of trade: ");
    scanf("%f", &tradeVal);

    float commision = 0.0f;
    while(tradeVal != 0.0f){
	if(tradeVal < 2500.00f)
	    commision = 30.00f + tradeVal * 0.017f;
	else if(tradeVal < 6250.00f)
	    commision = 56.00f + tradeVal * 0.0066f;
	else if(tradeVal < 20000.00f)
	    commision = 76.00f + tradeVal * 0.0034f;
	else if(tradeVal < 50000.00f)
	    commision = 100.00f + tradeVal * 0.0022f;
	else if(tradeVal <= 500000.00f)
	    commision = 155.00f + tradeVal * 0.0011f;
	else
	    commision = 255.00f + tradeVal * 0.0009f;

	printf("Commision: $%.2f\n", commision);
	printf("Enter value of trade: ");
	scanf("%f", &tradeVal);
    }

    return 0;
}
