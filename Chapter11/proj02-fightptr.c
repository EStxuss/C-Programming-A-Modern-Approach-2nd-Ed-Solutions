// finds closest flight departure time to input time

#include <stdio.h>
#include <stdlib.h>

#define FLIGHTS 8

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime);

int dep[FLIGHTS] = {8 * 60,  9 * 60 + 43,  11 * 60 + 19, 12 * 60 + 47,
                    14 * 60, 15 * 60 + 45, 19 * 60,      21 * 60 + 45};
int arr[FLIGHTS] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60,
                    16 * 60 + 8,  17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58};

int main(void) {

    int inputHr, inputMin, inputMidnight;
    printf("Enter a 24-hour time: ");
    scanf(" %d : %d", &inputHr, &inputMin);
    inputMidnight = inputHr * 60 + inputMin;

    int closestDepMidnight, closestArrMidnight;
    findClosestFlight(inputMidnight, &closestDepMidnight, &closestArrMidnight);

    // convert to 12 hour time
    int ansDepHr = (closestDepMidnight / 60);
    int ansDepMin = (closestDepMidnight % 60);
    char ansDepIndic = (ansDepHr >= 12) ? 'p' : 'a';
    ansDepHr = (ansDepHr % 12 == 0) ? 12 : ansDepHr % 12;

    int ansArrHr = (closestArrMidnight / 60);
    int ansArrMin = (closestArrMidnight % 60);
    char ansArrIndic = (ansArrHr >= 12) ? 'p' : 'a';
    ansArrHr = (ansArrHr % 12 == 0) ? 12 : ansArrHr % 12;

    printf("Closest departure is %d:%.2d %c.m, arriving at %d:%.2d %c.m\n",
           ansDepHr, ansDepMin, ansDepIndic, ansArrHr, ansArrMin, ansArrIndic);

    return 0;
}

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime) {
    int closestFlightIdx = -1, diff, lowestDiff;

    for (int i = 0; i < FLIGHTS; ++i) {
        diff = 1440 - dep[i] + desiredTime;  // wrap
        int tmp = abs(dep[i] - desiredTime); // direct
        if (tmp < diff)
            diff = tmp;

        if (closestFlightIdx == -1 || diff < lowestDiff) {
            closestFlightIdx = i;
            lowestDiff = diff;
        }
    }

    *departureTime = dep[closestFlightIdx];
    *arrivalTime = arr[closestFlightIdx];
}
