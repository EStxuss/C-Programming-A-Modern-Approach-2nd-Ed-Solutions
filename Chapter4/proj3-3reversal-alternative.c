// alternative implementation of the 3 digit reversal in project 2

#include <stdio.h>

int main(void){
    printf("Enter a 3 digit number: ");

    int hundreds = 0, tens = 0, ones = 0;
    scanf("%1d%1d%1d", &hundreds, &tens, &ones);

    printf("The reversal is: %d%d%d\n", ones, tens, hundreds);

    return 0;
}
