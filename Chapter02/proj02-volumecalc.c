// calculates volume of a sphere with 10m radius

#include <stdio.h>

#define PI 3.14159f
#define FRACTION (4.0f / 3.0f)

int main(void) {
    int r = 10;
    float vol = FRACTION * PI * r * r * r;
    printf("Volume of sphere with 10m radius: %.2f\n", vol);

    return 0;
}
