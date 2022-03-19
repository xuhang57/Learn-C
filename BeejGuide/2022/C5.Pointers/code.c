#include <stdio.h>

int main(void)
{
    int i = 0;
    printf("The value of i is %d\n", i);
    printf("And its address is %p\n", (void *)&i);

    // %p expects the argument to be a pointer to void so we cast it to make the complier happy

    int i; // i's type is "int"
    int *p; // p's type is "pointer to an int", or "int-pointer"
    p = &i; // p is assigned the address of i, p now points to i

    i = 10;
    *p = 20; // the thing p points to (i) is now 20

    printf("i is %d\n", i); // prints "20"
    printf("i is %d\n", *p); // "20", dereference-p is the same as i

    int i = 10;
    int *j = &i;
    increment(j);
    printf("i is %d\n", i); // prints "11"

    // NULL pointer
    int *p;
    p = NULL; // cannot be dereferenced, result in a crash

    int *p, q; // p is a pointer to an int; q is just an int
    int* p, q; // p is a pointer to an int; q is just an int
}

void increment(int *p)
{
    *p = *p + 1; // add one to the thing p points to
}
