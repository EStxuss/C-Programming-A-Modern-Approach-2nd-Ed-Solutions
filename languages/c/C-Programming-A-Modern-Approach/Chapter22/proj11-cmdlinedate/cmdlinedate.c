// takes a date as a command line argument in the form mm/dd/yyyy or mm-dd-yyyy
// and outputs it in "month day, year" form or prints error if its not the right
// form

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *mos[12] = {"January",   "February", "March",    "April",
                           "May",       "June",     "July",     "August",
                           "September", "October",  "November", "December"};

    if (argc < 2) {
        printf("Usage: date mm/dd/yyyy or date mm-dd-yyyy\n");
        exit(EXIT_FAILURE);
    }

    int month, day, year;
    int n = sscanf(argv[1], "%2d/%2d/%d", &month, &day, &year);

    if (n != 3)
        n = sscanf(argv[1], "%2d-%2d-%d", &month, &day, &year);

    if (n != 3) {
        printf("Date entered wasn't in the correct format.\n");
        exit(EXIT_FAILURE);
    }
    if (!(day >= 1 && day <= 31) || !(month >= 1 && month <= 12)) {
        printf("Invalid date\n");
        exit(EXIT_FAILURE);
    }

    printf("%s %d, %d\n", mos[month - 1], day, year);

    return EXIT_SUCCESS;
}