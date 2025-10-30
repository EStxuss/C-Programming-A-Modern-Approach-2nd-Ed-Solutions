// asks for two dates and outputs which date is earlier

#include <stdbool.h>
#include <stdio.h>

#define STR_SIZE 8

struct Date {
    int month;
    int day;
    int year;
    char str[STR_SIZE + 1];
};

int compareDates(struct Date firstDate, struct Date secondDate);
void stringifyDate(struct Date date, char dateStr[]);

int main(void) {
    struct Date firstDate, secondDate;

    printf("Enter the first date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &firstDate.month, &firstDate.day, &firstDate.year);
    stringifyDate(firstDate, firstDate.str);

    printf("Enter the second date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &secondDate.month, &secondDate.day, &secondDate.year);
    stringifyDate(secondDate, secondDate.str);

    int result = compareDates(firstDate, secondDate);
    char *earlierDateStr = (result == -1) ? firstDate.str : secondDate.str;
    char *laterDateStr =
        (earlierDateStr == firstDate.str) ? secondDate.str : firstDate.str;

    if (result == 0)
        printf("%s is the same date as %s\n", earlierDateStr, laterDateStr);
    else
        printf("%s is an earlier date than %s\n", earlierDateStr, laterDateStr);

    return 0;
}

int compareDates(struct Date firstDate, struct Date secondDate) {
    if (firstDate.year == secondDate.year &&
        firstDate.month == secondDate.month && firstDate.day == secondDate.day)
        return 0;
    else if (firstDate.year < secondDate.year)
        return -1;
    else if (firstDate.year == secondDate.year &&
             firstDate.month < secondDate.month)
        return -1;
    else if (firstDate.year == secondDate.year &&
             firstDate.month == secondDate.month &&
             firstDate.day < secondDate.day)
        return -1;
    else
        return 1;
}

void stringifyDate(struct Date date, char dateStr[]) {
    snprintf(dateStr, STR_SIZE + 1, "%.2d/%.2d/%.2d", date.month, date.day,
             date.year);
}
