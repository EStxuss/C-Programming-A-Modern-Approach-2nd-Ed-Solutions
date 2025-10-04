// converts 12 hour time to 24 hour time

#include <ctype.h>
#include <stdio.h>

int main(void) {
    int hour12, hour24, min;
    char indic;

    printf("Enter a 12-hour time: ");
    scanf(" %d : %d", &hour12, &min);

    while ((indic = toupper(getchar())) != 'A' && indic != 'P')
        ;

    hour24 = (indic == 'A') ? hour12 % 12 : hour12 % 12 + 12;

    printf("24-hour time equivalent: %d:%.2d\n", hour24, min);

    return 0;
}
