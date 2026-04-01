// prints the number of days between two entered dates

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    struct tm date1 = {0}, date2 = {0};

    printf("Enter date 1 (MM-DD-YYYY): ");
    int read =
        scanf(" %d-%d-%d", &date1.tm_mon, &date1.tm_mday, &date1.tm_year);
    printf("Enter date 2 (MM-DD-YYYY): ");
    read += scanf(" %d-%d-%d", &date2.tm_mon, &date2.tm_mday, &date2.tm_year);

    if (read != 6) {
        printf("Couldn't read dates\n");
        exit(EXIT_FAILURE);
    }

    time_t time1, time2;
    if (((time1 = mktime(&date1)) == -1) || ((time2 = mktime(&date2)) == -1)) {
        fprintf(stderr, "mktime failed\n");
        exit(EXIT_FAILURE);
    }

    int diffDays = (int)(difftime(time1, time2) / 60 / 60 / 24);
    diffDays = (diffDays < 0) ? diffDays * -1 : diffDays;

    printf("There are %d days between.\n", diffDays);

    return 0;
}