#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i;
    float f;
    char *s = "Hello World"; // char * ("char pointer") is the string type

    i = 3;
    f = 2.0;

    printf("%s i = %d and f = %f!\n", s, i, f);

    // Historically, C didn't have a Boolean type, and some might argue it is doesn't
    // In C, 0 means "false", and non-zero means "true"
    bool x = true;
    if (x) {
        printf("x is true!\n");
    }

    // C also includes the ternary operator, an expression whose value depends on the result of a conditional embedded in it
    int y;
    y += x > 10? 17: 37;

    // Pre and Post Increment and Decrement
    i++; // Add one to i (post-increment)
    i--; // Subtract one from i (post-decrement)
    ++i;
    --i;

    int j;
    i = 10;
    j = 5 + i++; // Compute 5 + i, then increment i
    printf("%d, %d\n", i, j); // Prints 11, 15

    i = 10;
    j = 5 + ++i; // Increment i, then compute 5 + i
    printf("%d, %d\n", i, j); // Prints 11, 16

    // sizeof
    int a = 999;
    // %zu is the format specifier for type size_t

    printf("%zu\n", sizeof a); // Prints 4 on my system
    printf("%zu\n", sizeof(2 + 7)); // Prints 4 on my system
    printf("%zu\n", sizeof 3.14); // Prints 8 on my system
    // If you need to print out negative size_t values, use %zd
    printf("%zu\n", sizeof(int)); // Prints 4 on my system
    printf("%zu\n", sizeof(char)); // Prints 1 on all systems

    // Flow Control
    int i = 99;
    if (i == 10) {
        printf("i is 10!\n");
    } else if (i == 20) {
        printf("i is 20!\n");
    } else if (i == 99) {
        printf("i is 99! My favorite\n");
        printf("I can't tell you how happy I am.\n");
        printf("Really.\n");
    } else {
        printf("i is some crazy number I've never heard of.\n");
    }

    do {
        printf("do-while: i is %d\n", i);
        i++;
    } while (i < 10);

    for (i = 0; i < 10; i++) {
        printf("i is %d\n", i);
    }

    for (i = 0, j = 999; i < 10; i++, j--) {
        printf("%d, %d\n", i, j);
    }

    for(;;) { // "forever"
        printf("I will print this again and again and again\n" );
        printf("for all eternity until the heat-death of the universe.\n");
        printf("Or until you hit CTRL-C.\n");
    }

    int goat_count;
    printf("Enter a goat count:");
    scanf("%d, &goat_count");

    switch(goat_count) {
        case 0:
            printf("You have no goats\n");
            break;
        case 1:
            printf("You have a singular goat\n");
            break;
        default:
            printf("You have bona fide plethora of goats!\n");
            break;
    }
}
