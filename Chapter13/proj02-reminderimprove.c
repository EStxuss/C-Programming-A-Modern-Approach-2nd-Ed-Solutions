// adds functionality to the remind.c program of section 13.5:
// (a) print an error msg and ignore a reminder whose day falls outside the
// range 0 <= day <= 31
// (b) adds a 24 hour time to the reminder which affects the sorting
// (c) the reminder list is for the year so the days have the form month/day

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60    /* max length of reminder message */

int read_line(char str[], int n);
int main(void) {
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char c, day_time_str[12], msg_str[MSG_LEN + 1];
    int day, month, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter reminder ( mm/dd hh:mm message ): ");
        scanf("%2d/%2d", &month, &day);
        if (day == 0 || month == 0)
            break;
        else if (day < 0 || day > 31 || month < 1 || month > 12) {
            while ((c = getchar()) != '\n') // clear rest of line
                ;
            printf("Day not valid\n");
            continue;
        }

        int hour, min;
        scanf("%2d : %2d", &hour, &min);

        sprintf(day_time_str, "%2d/%2.2d %2d:%2.2d", month, day, hour, min);

        read_line(msg_str, MSG_LEN);
        for (i = 0; i < num_remind; i++)
            if (strcmp(day_time_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);
        strcpy(reminders[i], day_time_str);
        strcat(reminders[i], msg_str);
        num_remind++;
    }
    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
