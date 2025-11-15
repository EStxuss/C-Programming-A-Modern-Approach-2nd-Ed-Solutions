// On my system it put a 24 bit hole between the char a member and the start of
// the b int array and everything else was contiguous with the total struct size
// being 128 bits

#include <stddef.h>
#include <stdio.h>

int main(void) {
    struct s {
        char a;
        int b[2];
        float c;
    } s1;

    printf("char a info:\nsize: %d bits\noffset: %d bits\n\n", sizeof(s1.a) * 8,
           offsetof(struct s, a) * 8);

    printf("int b[2] info:\nsize: %d bits\noffset: %d bits\n\n",
           sizeof(s1.b) * 8, offsetof(struct s, b) * 8);

    printf("float c info:\nsize: %d bits\noffset: %d bits\n\n",
           sizeof(s1.c) * 8, offsetof(struct s, c) * 8);

    printf("total struct size: %d bits\n\n", sizeof(s1) * 8);

    return 0;
}