// user enters 1 - 16 in any order and they are formatted to a 4x4 square
// the row, column and diagnol sums are printed afterwards

#include <stdio.h>

int main(void) {
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &b1, &b2, &b3,
          &b4, &c1, &c2, &c3, &c4, &d1, &d2, &d3, &d4);

    printf(
        "%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n",
        a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4);

    int rs1 = a1 + a2 + a3 + a4;
    int rs2 = b1 + b2 + b3 + b4;
    int rs3 = c1 + c2 + c3 + c4;
    int rs4 = d1 + d2 + d3 + d4;

    int cs1 = a1 + b1 + c1 + d1;
    int cs2 = a2 + b2 + c2 + d2;
    int cs3 = a3 + b3 + c3 + d3;
    int cs4 = a4 + b4 + c4 + d4;

    int dia1 = a1 + b2 + c3 + d4;
    int dia2 = a4 + b3 + c2 + d1;

    printf("Row Sums: %d %d %d %d\nColumn Sums: %d %d %d %d\nDiagnol Sums: %d "
           "%d\n",
           rs1, rs2, rs3, rs4, cs1, cs2, cs3, cs4, dia1, dia2);

    return 0;
}
