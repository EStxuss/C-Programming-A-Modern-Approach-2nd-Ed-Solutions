// finds closest flight departure time to input time

#include <stdio.h>
#include <stdlib.h>

#define FLIGHTS 8

int main(void) {
    const struct Flight {
        int dep;
        int arr;
    } flights[8] = {{8 * 60, 10 * 60 + 16},       {9 * 60 + 43, 11 * 60 + 52},
                    {11 * 60 + 19, 13 * 60 + 31}, {12 * 60 + 47, 15 * 60},
                    {14 * 60, 16 * 60 + 8},       {15 * 60 + 45, 17 * 60 + 55},
                    {19 * 60, 21 * 60 + 20},      {21 * 60 + 45, 23 * 60 + 58}};

    int inputHr, inputMin, inputMidnight;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &inputHr, &inputMin);
    inputMidnight = inputHr * 60 + inputMin;

    int closestIdx = -1, currDiff, closestDiff, tmpDiff;

    for (int i = 0; i < FLIGHTS; ++i) {
        currDiff = 1440 - flights[i].dep + inputMidnight;
        tmpDiff = abs(flights[i].dep - inputMidnight);
        if (tmpDiff < currDiff)
            currDiff = tmpDiff;

        if (closestIdx == -1 || currDiff < closestDiff) {
            closestIdx = i;
            closestDiff = currDiff;
        }
    }

    int ansDepHr = (flights[closestIdx].dep / 60);
    int ansDepMin = (flights[closestIdx].dep % 60);
    char ansDepIndic = (ansDepHr >= 12) ? 'p' : 'a';
    ansDepHr = (ansDepHr % 12 == 0) ? 12 : ansDepHr % 12;

    int ansArrHr = (flights[closestIdx].arr / 60);
    int ansArrMin = (flights[closestIdx].arr % 60);
    char ansArrIndic = (ansArrHr >= 12) ? 'p' : 'a';
    ansArrHr = (ansArrHr % 12 == 0) ? 12 : ansArrHr % 12;

    printf("Closest departure is %d:%.2d %c.m, arriving at %d:%.2d %c.m\n",
           ansDepHr, ansDepMin, ansDepIndic, ansArrHr, ansArrMin, ansArrIndic);

    return 0;
}
