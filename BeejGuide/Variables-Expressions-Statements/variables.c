#include <stdio.h>


/* C is a strongly-typed language so you have to declare the type */
int main(void) {
    int i;
    float f;

    i = 2;
    i = i + 3;
    i++; // add one to i (post-increment)
    ++i; // add one to i (pre-increment)

    int j = 10;
    /* conditions */
    if (j > 10) {
        printf("Yes, j is greater than 10\n");
    } else {
        printf("j is less than 10\n");
    }

    i = 0;
    while (i < 10) {
        printf("i is now %d\n", i);
        i++;
    }
    printf("All done!\n");

    do {
        printf("do-while: i is %d\n", i);
        i++;
    } while (i < 20);
    printf("do-while done\n");


    int w;
    for(w=0; w<10; w++) {
        printf("w is %d\n");
    }

    for(;;) {
        printf("run forever");
    }
}

