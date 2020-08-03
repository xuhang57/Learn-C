#include <stdio.h>

struct creature {
    float x;
    float y;
};

void execute_behavior(struct creature *c) {
    /* does nothing */
}

int main(void) {
    int i;
    struct creature guys[12];

    /* initialize them */
    for (i = 0; i < 12; i++) {
        guys[i].x = (float) i; /* (float) is a "cast" -- it changes the type */
        guys[i].y = (float) i;
    }

    /* loop forever */
    for(;;) {
        for (i = 0; i < 12; i++) {
            execute_behavior(&(guys[i]));
        }

        for (i = 0; i < 12; i++) {
            printf("creature %d: (%.2f, %.2f)\n", i, guys[i].x, guys[i].y);
        }
    }
    return 0;
}