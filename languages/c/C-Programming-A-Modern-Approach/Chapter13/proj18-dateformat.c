// outputs month day, year from mm/dd/yyyy input

#include <stdio.h>

int main(void) {
    char *month[12] = {"January",   "February", "March",    "April",
                       "May",       "June",     "July",     "August",
                       "September", "October",  "November", "December"};

    int mo, day, year;
    do {
        printf("Enter a date (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &mo, &day, &year);
    } while (mo < 1 || mo > 12);

    printf("You entered the date %s %d, %d\n", month[mo - 1], day, year);

    return 0;
}
