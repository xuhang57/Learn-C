#include <stdio.h>

int main(void)
{
    int i;
    float f[4]; // Declare an array of 4 floats

    f[0] = 3.14159; // Indexing starts of 0, of course
    f[1] = 1.41421;
    f[2] = 1.61803;
    f[3] = 2.71828;

    for (i = 0; i < 4; i++) {
        printf("%f\n", f[i]);
    }

    int x[12]; // 12 ints
    printf("%zu\n", sizeof x); // 48 total bytes

    int i;
    int a[5] = {22, 11, 33, 44, 55}; // Initialize with these values

    for (i = 0; i < 5; i++) {
        printf("%d\n", a[i]);
    }

    int a[100] = {0};
    int a[] = {22, 37, 3490}; // Left the size off

    int a[10];
    int b[2][3];
    int c[4][5][6];

    int a[2][5] = {
        {0,1,2,3,4},
        {5,6,7,8,9}
    };

    // All of these are identical
    // void times2(int *a, int len); // most popular
    // void times3(int a[], int len);
    // void times4(int a[5], int len);
}
