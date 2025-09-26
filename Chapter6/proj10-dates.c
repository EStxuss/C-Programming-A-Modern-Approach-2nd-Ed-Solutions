// asks for two dates and outputs which date is earlier

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int earlyD, earlyM, earlyY, inputD, inputM, inputY;
    bool noDate = true;
    for (;;) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%d", &inputM, &inputD, &inputY);
        if (!inputM && !inputD && !inputY)
            break;
        if (noDate) {
            earlyM = inputM;
            earlyD = inputD;
            earlyY = inputY;
            noDate = false;
        } else {
            bool earlier = false;
            if (inputY < earlyY)
                earlier = true;
            else if (inputY == earlyY && inputM < earlyM)
                earlier = true;
            else if (inputY == earlyY && inputM == earlyM && inputD < earlyD)
                earlier = true;
            if (earlier) {
                earlyM = inputM;
                earlyD = inputD;
                earlyY = inputY;
            }
        }
    }

    if (!noDate)
        printf("%.2d/%.2d/%.2d is the earliest date.\n", earlyM, earlyD,
               earlyY);

    return 0;
}
