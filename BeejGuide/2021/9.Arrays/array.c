#include <stdio.h>

void init_array(int a[], int count) {
    int i;
    for (i = 0; i < count; i++) {
        a[i] = i * 10;
    }
}

int main(void) {
    int my_data[10];
    init_array(my_data, 10);

    return 0;
}


/*

When you have an array, leaving off the and square brackets gives you a "pointer" to the first element of the array.
You can use the address-of operator, but it actually results in a different pointer type, so it might not be what you expect
In fact, a pointer to the array that's getting copied onto the stack for the function call, not the entire array.

*/