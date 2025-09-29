// outputs flight whose departure is closest to the input time

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

    int inputHr, inputMin, inputTotal;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &inputHr, &inputMin);
    inputTotal = inputHr * 60 + inputMin;

    int diff1, diff2, diff3, diff4, diff5, diff6, diff7, diff8, wrap, between;
    between = (inputTotal > dep1) ? inputTotal - dep1 : dep1 - inputTotal;
    wrap = (inputTotal > dep1) ? (24 * 60 - inputTotal) + dep1
                               : (24 * 60 - dep1) + inputTotal;
    diff1 = (between > wrap) ? wrap : between;

    between = (inputTotal > dep2) ? inputTotal - dep2 : dep2 - inputTotal;
    wrap = (inputTotal > dep2) ? (24 * 60 - inputTotal) + dep2
                               : (24 * 60 - dep2) + inputTotal;
    diff2 = (between > wrap) ? wrap : between;

    between = (inputTotal > dep3) ? inputTotal - dep3 : dep3 - inputTotal;
    wrap = (inputTotal > dep3) ? (24 * 60 - inputTotal) + dep3
                               : (24 * 60 - dep3) + inputTotal;
    diff3 = (between > wrap) ? wrap : between;

    between = (inputTotal > dep4) ? inputTotal - dep4 : dep4 - inputTotal;
    wrap = (inputTotal > dep4) ? (24 * 60 - inputTotal) + dep4
                               : (24 * 60 - dep4) + inputTotal;
    diff4 = (between > wrap) ? wrap : between;

    between = (inputTotal > dep5) ? inputTotal - dep5 : dep5 - inputTotal;
    wrap = (inputTotal > dep5) ? (24 * 60 - inputTotal) + dep5
                               : (24 * 60 - dep5) + inputTotal;
    diff5 = (between > wrap) ? wrap : between;

    between = (inputTotal > dep6) ? inputTotal - dep6 : dep6 - inputTotal;
    wrap = (inputTotal > dep6) ? (24 * 60 - inputTotal) + dep6
                               : (24 * 60 - dep6) + inputTotal;
    diff6 = (between > wrap) ? wrap : between;

    between = (inputTotal > dep7) ? inputTotal - dep7 : dep7 - inputTotal;
    wrap = (inputTotal > dep7) ? (24 * 60 - inputTotal) + dep7
                               : (24 * 60 - dep7) + inputTotal;
    diff7 = (between > wrap) ? wrap : between;

    between = (inputTotal > dep8) ? inputTotal - dep8 : dep8 - inputTotal;
    wrap = (inputTotal > dep8) ? (24 * 60 - inputTotal) + dep8
                               : (24 * 60 - dep8) + inputTotal;
    diff8 = (between > wrap) ? wrap : between;

    int closest = diff1;
    int closestDep = dep1;
    int closestArr = arr1;
    if (diff2 < closest) {
        closest = diff2;
        closestDep = dep2;
        closestArr = arr2;
    }
    if (diff3 < closest) {
        closest = diff3;
        closestDep = dep3;
        closestArr = arr3;
    }
    if (diff4 < closest) {
        closest = diff4;
        closestDep = dep4;
        closestArr = arr4;
    }
    if (diff5 < closest) {
        closest = diff5;
        closestDep = dep5;
        closestArr = arr5;
    }
    if (diff6 < closest) {
        closest = diff6;
        closestDep = dep6;
        closestArr = arr6;
    }
    if (diff7 < closest) {
        closest = diff7;
        closestDep = dep7;
        closestArr = arr7;
    }
    if (diff8 < closest) {
        closest = diff8;
        closestDep = dep8;
        closestArr = arr8;
    }

    bool depAM = closestDep / 60 >= 0 && closestDep / 60 < 12;
    bool arrAM = closestArr / 60 >= 0 && closestArr / 60 < 12;
    int closestDepHr = (closestDep / 60) % 12;
    int closestArrHr = (closestArr / 60) % 12;
    if (closestDepHr == 0)
        closestDepHr = 12;
    if (closestArrHr == 0)
        closestArrHr = 12;
    int closestDepMin = closestDep % 60;
    int closestArrMin = closestArr % 60;

    if (depAM && arrAM)
        printf("Closest departure time is %d:%.2d a.m., arriving at %d:%.2d "
               "a.m.\n",
               closestDepHr, closestDepMin, closestArrHr, closestArrMin);
    else if (!depAM && arrAM)
        printf("Closest departure time is %d:%.2d p.m., arriving at %d:%.2d "
               "a.m.\n",
               closestDepHr, closestDepMin, closestArrHr, closestArrMin);
    else if (depAM && !arrAM)
        printf("Closest departure time is %d:%.2d a.m., arriving at %d:%.2d "
               "p.m.\n",
               closestDepHr, closestDepMin, closestArrHr, closestArrMin);
    else
        printf("Closest departure time is %d:%.2d p.m., arriving at %d:%.2d "
               "p.m.\n",
               closestDepHr, closestDepMin, closestArrHr, closestArrMin);

    return 0;
}
