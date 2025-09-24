// Takes a number input and outputs how many digits the number has

#include <stdio.h>

int main(void){
    printf("Enter a number with <= 4 digits: ");
    int inputNum = 0;
    scanf("%d", &inputNum);

    if(inputNum < 0) inputNum *= -1;
    if(inputNum < 10)
	printf("The number has one digit\n");
    else if(inputNum < 100)
	printf("The number has two digits\n");
    else if(inputNum < 1000)
	printf("The number has three digits\n");
    else if(inputNum < 10000)
	printf("The number has four digits\n");
    else
	printf("The number falls outside the allowable range\n");

    return 0;
}
