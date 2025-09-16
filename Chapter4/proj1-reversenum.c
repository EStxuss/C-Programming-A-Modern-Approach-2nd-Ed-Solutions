// takes a double digit number as input and outputs that number reversed

#include <stdio.h>

int main(void){
    printf("Enter a double digit number: ");

    int inputNum = 0;
    scanf("%d", &inputNum);

    int ones = inputNum % 10;
    int tens = inputNum / 10;
    printf("The reversal is: %d%d\n", ones, tens);

    return 0;
}
