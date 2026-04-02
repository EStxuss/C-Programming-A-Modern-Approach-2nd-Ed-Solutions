// reverses a three digit number

#include <stdio.h>

int main(void) {
    printf("Enter a 3 digit number: ");

    int inputNum = 0;
    scanf("%d", &inputNum);

    int hundreds = inputNum / 100;
    int tens = (inputNum / 10) % 10;
    int ones = (inputNum % 100) % 10;

    printf("The reversal is: %d%d%d\n", ones, tens, hundreds);

    return 0;
}
