// 4 integer input and outputs the largest and smallest of the 4 int

#include <stdio.h>

int main(void) {
    printf("Enter 4 integers: ");
    int num1, num2, num3, num4;
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

    int minFound, maxFound;
    if (num1 > num2) {
        minFound = num2;
        maxFound = num1;
    } else {
        minFound = num1;
        maxFound = num2;
    }
    if (num3 > maxFound)
        maxFound = num3;
    else if (num3 < minFound)
        minFound = num3;
    if (num4 > maxFound)
        maxFound = num4;
    else if (num4 < minFound)
        minFound = num4;

    printf("Largest: %d\nSmallest: %d\n", maxFound, minFound);

    return 0;
}
