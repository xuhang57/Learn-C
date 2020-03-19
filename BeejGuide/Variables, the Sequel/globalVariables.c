#include <stdio.h>

/* this is a global variable */
int g = 10;

void aFunc(int x) {
    g = x; // this sets the global variable to the value of x
}

int main(void) {
    g = 10; // global variable is now 10
    afunc(20); // set g to 20
    printf("%d\n", g); // print 20 therefore

    return 0;
}

/*
A global variable is visible thoughout the entire file that it is defined in
(or declared in)

Globals go on heap rather than stack. They could be dangerous in large scale
projects in which there were a bazillion globals declared by a bazillion different
programmers. What if they named them the same thing?


*/