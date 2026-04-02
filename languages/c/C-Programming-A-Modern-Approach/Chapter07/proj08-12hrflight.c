// reads a 12 hour time and outputs closest departure time flight

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int dep1, arr1, dep2, arr2, dep3, arr3, dep4, arr4, dep5, arr5, dep6, arr6,
        dep7, arr7, dep8, arr8;
    dep1 = 8 * 60;
    arr1 = 10 * 60 + 16;
    dep2 = 9 * 60 + 43;
    arr2 = 11 * 60 + 52;
    dep3 = 11 * 60 + 19;
    arr3 = 13 * 60 + 31;
    dep4 = 12 * 60 + 47;
    arr4 = 15 * 60;
    dep5 = 14 * 60;
    arr5 = 16 * 60 + 8;
    dep6 = 15 * 60 + 45;
    arr6 = 17 * 60 + 55;
    dep7 = 19 * 60;
    arr7 = 21 * 60 + 20;
    dep8 = 21 * 60 + 45;
    arr8 = 23 * 60 + 58;

    int inputHr, inputMin;
    char indic;
    printf("Enter a 12-hour time: ");
    scanf(" %d : %d", &inputHr, &inputMin);

    while ((indic = toupper(getchar())) != 'A' && indic != 'P')
        ;

    int input24Hr = (indic == 'A') ? inputHr % 12 : inputHr % 12 + 12;
    int fromMidnight = input24Hr * 60 + inputMin;

    printf("%d\n", fromMidnight);

    int depAns, arrAns;
    if (fromMidnight >= (dep7 + (dep8 - dep7) / 2) ||
        fromMidnight <= ((dep8 + (24 * 60 - dep8 + dep1) / 2) % (24 * 60))) {
        depAns = dep8;
        arrAns = arr8;
    } else if (fromMidnight <= (dep1 + (dep2 - dep1) / 2)) {
        depAns = dep1;
        arrAns = arr1;
    } else if (fromMidnight <= (dep2 + (dep3 - dep2) / 2)) {
        depAns = dep2;
        arrAns = arr2;
    } else if (fromMidnight <= (dep3 + (dep4 - dep3) / 2)) {
        depAns = dep3;
        arrAns = arr3;
    } else if (fromMidnight <= (dep4 + (dep5 - dep4) / 2)) {
        depAns = dep4;
        arrAns = arr4;
    } else if (fromMidnight <= (dep5 + (dep6 - dep5) / 2)) {
        depAns = dep5;
        arrAns = arr5;
    } else if (fromMidnight < (dep6 + (dep7 - dep6) / 2)) {
        depAns = dep6;
        arrAns = arr6;
    } else if (fromMidnight < (dep7 + (dep8 - dep7) / 2)) {
        depAns = dep7;
        arrAns = arr7;
    }

    int depAnsHr = depAns / 60;
    int depAnsMin = depAns % 60;
    int arrAnsHr = arrAns / 60;
    int arrAnsMin = arrAns % 60;

    bool depPm = false;
    bool arrPm = false;
    if (depAnsHr >= 12)
        depPm = true;
    if (arrAnsHr >= 12)
        arrPm = true;
    depAnsHr = (depAnsHr % 12 == 0) ? 12 : depAnsHr % 12;
    arrAnsHr = (arrAnsHr % 12 == 0) ? 12 : arrAnsHr % 12;
    char depIndic, arrIndic;
    depIndic = (depPm) ? 'p' : 'a';
    arrIndic = (arrPm) ? 'p' : 'a';

    printf("Closest departure time is %d:%.2d %c.m., arriving at %d:%.2d "
           "%c.m.\n",
           depAnsHr, depAnsMin, depIndic, arrAnsHr, arrAnsMin, arrIndic);

    return 0;
}
