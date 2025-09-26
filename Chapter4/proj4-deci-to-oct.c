// takes decimal number input and outputs the octal conversion

#include <stdio.h>

int main(void) {
    printf("Enter a number between 0 and 32767: ");

    int deciInput = 0;
    scanf("%d", &deciInput);

    int first, second, third, fourth, fifth;
    first = second = third = fourth = fifth = 0;
    fifth = deciInput % 8;
    deciInput /= 8;
    fourth = deciInput % 8;
    deciInput /= 8;
    third = deciInput % 8;
    deciInput /= 8;
    second = deciInput % 8;
    deciInput /= 8;
    first = deciInput % 8;

    printf("Your number in octal is: %d%d%d%d%d\n", first, second, third,
           fourth, fifth);

    return 0;
}
