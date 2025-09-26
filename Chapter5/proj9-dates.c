// asks for two dates and outputs which date is earlier

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int m1, d1, y1, m2, d2, y2;
    printf("Enter the first date (mm/dd/yy): ");
    scanf("%d / %d / %d", &m1, &d1, &y1);

    printf("Enter the second date (mm/dd/yy): ");
    scanf("%d / %d / %d", &m2, &d2, &y2);

    bool firstEarlier = false;
    bool sameDate = y1 == y2 && m1 == m2 && d1 == d2;
    if (sameDate)
        printf("They are the same date\n");
    else {
        if (y1 < y2)
            firstEarlier = true;
        else if (y1 == y2 && m1 < m2)
            firstEarlier = true;
        if (y1 == y2 && m1 == m2 && d1 < d2)
            firstEarlier = true;
    }

    if (firstEarlier)
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", m1, d1, y1,
               m2, d2, y2);
    else
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", m2, d2, y2,
               m1, d1, y1);

    return 0;
}
