// takes input of the form dd/mm/yyyy and outputs yyyyddmm

#include <stdio.h>

int main(void) {
    printf("Enter a date dd/mm/yyyy: ");

    int day = 0, month = 0, year = 0;

    scanf("%d/%d/%d", &day, &month, &year);

    printf("You entered the date %d%.2d%.2d\n", year, day, month);

    return 0;
}
