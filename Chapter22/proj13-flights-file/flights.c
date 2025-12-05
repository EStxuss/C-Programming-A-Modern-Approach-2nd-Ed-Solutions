// gets flight departure/arrival times from flights.dat and outuputs the flight
// thats closest to the input time

#include <stdio.h>
#include <stdlib.h>

struct Flight {
    int depHr, depMin;
    int arrHr, arrMin;
    int depTotalMins, arrTotalMins;
};

struct FlightArray {
    struct Flight *arr;
    int size;
    int capacity;
};

int findClosestFlight(int inputMidnight, const struct FlightArray flights);

int main(void) {

    FILE *fp = fopen("flights.dat", "r");
    if (fp == NULL) {
        fprintf(stderr, "Couldn't open flights.dat\n");
        exit(EXIT_FAILURE);
    }

    struct FlightArray flights;
    flights.capacity = 10;
    flights.size = 0;
    flights.arr = malloc(flights.capacity * sizeof(struct Flight));

    struct Flight buf;
    int n;
    // read flights info from file
    while (!feof(fp)) {
        n = fscanf(fp, "%d:%d%d:%d%*c", &buf.depHr, &buf.depMin, &buf.arrHr,
                   &buf.arrMin);

        if (n != 0 && n < 4) {
            fprintf(stderr,
                    "WARNING: Read a partial flight entry. Stopped reading "
                    "after %d flight entries\n",
                    flights.size);
            break;
        } else if (n == 0)
            break;

        // array resizing
        if (flights.size == flights.capacity) {
            flights.capacity *= 2;
            flights.arr =
                realloc(flights.arr, sizeof(struct Flight) * flights.capacity);
            if (flights.arr == NULL) {
                fprintf(
                    stderr,
                    "Couldn't reallocate the flights array during resizing\n");
                exit(EXIT_FAILURE);
            }
        }

        buf.depTotalMins = buf.depHr * 60 + buf.depMin;
        buf.arrTotalMins = buf.arrHr * 60 + buf.arrMin;

        flights.arr[flights.size++] = buf;
    }

    if (flights.size == 0) {
        fprintf(stderr, "Flights array contains no flight information\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter a 24-hour time: ");

    int inputHr, inputMin, inputMidnight;
    int inputN = scanf("%d :%d", &inputHr, &inputMin);
    if (inputN != 2) {
        fprintf(stderr, "Error reading input\n");
        exit(EXIT_FAILURE);
    }
    inputMidnight = inputHr * 60 + inputMin;

    int closestFlightIdx = findClosestFlight(inputMidnight, flights);

    // convert to 12 hour time
    int ansDepHr = (flights.arr[closestFlightIdx].depTotalMins / 60);
    int ansDepMin = (flights.arr[closestFlightIdx].depTotalMins % 60);
    char ansDepIndic = (ansDepHr >= 12) ? 'p' : 'a';
    ansDepHr = (ansDepHr % 12 == 0) ? 12 : ansDepHr % 12;

    int ansArrHr = (flights.arr[closestFlightIdx].arrTotalMins / 60);
    int ansArrMin = (flights.arr[closestFlightIdx].arrTotalMins % 60);
    char ansArrIndic = (ansArrHr >= 12) ? 'p' : 'a';
    ansArrHr = (ansArrHr % 12 == 0) ? 12 : ansArrHr % 12;

    printf("Closest departure is %d:%.2d %c.m, arriving at %d:%.2d %c.m\n",
           ansDepHr, ansDepMin, ansDepIndic, ansArrHr, ansArrMin, ansArrIndic);

    return EXIT_SUCCESS;
}

// returns the idx of the closest flight in the array
int findClosestFlight(int inputMidnight, const struct FlightArray flights) {
    int closestFlightIdx = -1, wrap, direct, diff, lowestDiff;

    for (int i = 0; i < flights.size; ++i) {
        wrap = (flights.arr[i].depTotalMins > inputMidnight)
                   ? 1440 - flights.arr[i].depTotalMins + inputMidnight
                   : 1440 - inputMidnight + flights.arr[i].depTotalMins;

        // direct
        direct = abs(flights.arr[i].depTotalMins - inputMidnight); // direct

        diff = (wrap < direct) ? wrap : direct;

        if (closestFlightIdx == -1 || diff < lowestDiff) {
            closestFlightIdx = i;
            lowestDiff = diff;
        }
    }

    return closestFlightIdx;
}