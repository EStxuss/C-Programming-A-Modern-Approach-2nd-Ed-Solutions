// calculates volume of a sphere with radius entered by user

#include <stdio.h>

#define PI 3.14159f
#define FRACTION (4.0f / 3.0f)

int main(void) {
    float r = 0;
    printf("Enter a radius of a sphere: ");
    scanf("%f", &r);
    float vol = FRACTION * PI * r * r * r;
    printf("Volume of sphere with %.2f radius: %.2f\n", r, vol);

    return 0;
}
