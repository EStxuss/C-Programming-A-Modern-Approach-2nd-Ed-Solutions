#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    struct tm inputTime = {0};
    int daysLater = 0;

    printf("Enter a month, day and year (MM-DD-YYYY): ");
    scanf(" %d-%d-%d", &inputTime.tm_mon, &inputTime.tm_mday,
          &inputTime.tm_year);

    inputTime.tm_mon--;
    inputTime.tm_year -= 1900;

    printf("Enter days later amount: ");
    scanf(" %d", &daysLater);

    inputTime.tm_mday += daysLater;
    if (mktime(&inputTime) == -1) {
        fprintf(stderr, "mktime failed\n");
        exit(EXIT_FAILURE);
    }

    char updatedTimeStr[30];
    strftime(updatedTimeStr, sizeof(updatedTimeStr) - 1, "%m-%d-%Y",
             &inputTime);

    printf("Updated date: %s\n", updatedTimeStr);

    return 0;
}