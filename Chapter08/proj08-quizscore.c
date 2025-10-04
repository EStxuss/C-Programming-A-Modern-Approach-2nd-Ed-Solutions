// gives scores, avgs, totals for 5 quiz scores from 5 students

#include <stdio.h>

int main(void) {
    int score[5][5];
    printf("Student   1  2  3  4  5\n");
    for (int quiz = 0; quiz < 5; ++quiz) {
        printf("Quiz %d:  ", quiz + 1);
        for (int student = 0; student < 5; ++student)
            scanf("%d", &score[quiz][student]);
    }

    int total[5] = {0};
    for (int student = 0; student < 5; ++student) {
        for (int quiz = 0; quiz < 5; ++quiz)
            total[student] += score[quiz][student];
    }

    for (int student = 0; student < 5; ++student) {
        printf("\nStudent %d total: %d\n", student + 1, total[student]);
        printf("Student %d average: %d\n", student + 1, total[student] / 5);
    }

    int quizLow[5];
    int quizHigh[5];
    int quizTotal[5] = {0};
    int testScore;
    for (int quiz = 0; quiz < 5; ++quiz) {
        for (int student = 0; student < 5; ++student) {
            testScore = score[quiz][student];
            if (student == 0) {
                quizLow[quiz] = testScore;
                quizHigh[quiz] = testScore;
                quizTotal[quiz] = testScore;
                continue;
            }
            if (testScore < quizLow[quiz])
                quizLow[quiz] = testScore;
            if (testScore > quizHigh[quiz])
                quizHigh[quiz] = testScore;
            quizTotal[quiz] += testScore;
        }
    }

    for (int quiz = 0; quiz < 5; ++quiz) {
        printf("\nQuiz %d Lowest Score: %d", quiz + 1, quizLow[quiz]);
        printf("\nQuiz %d Highest Score: %d", quiz + 1, quizHigh[quiz]);
        printf("\nQuiz %d Average Score: %d\n", quiz + 1, quizTotal[quiz] / 5);
    }

    return 0;
}
