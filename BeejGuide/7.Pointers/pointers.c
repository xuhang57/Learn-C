#include <stdio.h>

// Note that it accepts a pointer to an int
void increment(int *p) {
  *p = *p + 1;
}

int main(void) {
    int i = 10;

    printf("The value of i is %d, and its address is %p\n", i, &i);

    /* Pointer Type */
    int j;
    int *p; // p's type is pointer to an int, or int-pointer

    p = &j; // p now points to i

    /* Dereferencing */

    int i;
    int p;

    p = &i;

    i = 10;
    *p = 20; // i now == 20

    printf("i is %d\n", i); // prints "20"
    printf("i is %d\n", *p); // "20"  --> dereference p is the same as i

    /* PAssing Pointers as Parameters */

    int i = 10;
    printf("i is %d\n", i);  // prints 10
    increment(&i); // address-of, turns it to a pointer
    printf("i is %d\n", i); // prints 11

    return 0;
}

/*

Depends on your system. A `long` is often eight bytes (64-bits). You can use the sizeof() operator to determine how many bytes of memory a certain type uses.

A pointer variable is a variable that points to an address of another variable. We use the `address of` operator (Namely, an ampersand: &) to find the address
of the data.

A pointer, also known as an address,  is sometimes also called a reference. "A reference to a variable".

increment(int *p) is accepting a pointer to int. And this is `Pass By Reference` which is default in Java/Python. In C, you have to be explicit.

*/