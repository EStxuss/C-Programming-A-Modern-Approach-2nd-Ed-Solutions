// converts a 24 hour format time to 12 hour format

#include <stdio.h>

int main(void) {
    printf("Enter a 24-hour time: ");
    int hour24 = 0, minute = 0;
    scanf("%d : %d", &hour24, &minute);

    int hour12 = hour24 % 12;
    if (hour12 == 0)
        hour12 = 12;

    printf("The 12-hour time equivalent is: %d:%.2d", hour12, minute);
    if (hour24 >= 0 && hour24 < 12)
        printf(" AM\n");
    else
        printf(" PM\n");

    return 0;
}
