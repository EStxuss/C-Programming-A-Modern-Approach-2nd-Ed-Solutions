// user enters positive numbers and outputs largest of the numbers entered
// program terminates when 0 or negative number is entered

#include <stdio.h>

int main(void) {
    float input = 1.0f;
    float largest = 0.0f;
    while (input > 0.0f) {
        printf("Enter a number: ");
        scanf("%f", &input);
        if (input > largest)
            largest = input;
    }

    printf("The largest number entered was %.2f\n", largest);

    return 0;
}
