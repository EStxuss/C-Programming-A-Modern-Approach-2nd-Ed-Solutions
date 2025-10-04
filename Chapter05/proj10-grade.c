// takes a number grade and outputs the letter grade

#include <stdio.h>

int main(void) {
    int numGrade;
    printf("Enter a numerical grade: ");
    scanf("%d", &numGrade);

    int firstDig = numGrade / 10;
    char letterGrade = 'Z';
    switch (firstDig) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        letterGrade = 'F';
        break;
    case 6:
        letterGrade = 'D';
        break;
    case 7:
        letterGrade = 'C';
        break;
    case 8:
        letterGrade = 'B';
        break;
    case 9:
    case 10:
        letterGrade = 'A';
        break;
    }
    if (letterGrade == 'Z')
        printf("Unrecognized numerical grade\n");
    else
        printf("Letter grade: %c\n", letterGrade);

    return 0;
}
