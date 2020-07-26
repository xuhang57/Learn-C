#include <stdio.h>

/* Declare the type */
struct stuff {
    int val;
    float b;
};

struct antelope {
    int val;
    float something;
};

struct mutantfrog {
    int num_legs;
    int num_eyes;
};

void build_frog(struct mutantfrog *f) {
    f->num_legs = 5;
    f->num_eyes = 3;
}

int main(void) {
    struct stuff s;

    s.val = 11;
    s.b = 3.14;

    printf("The val field in s is: %d\n", s.val);

    struct antelope a;
    struct antelope *b; /* a pointer to a struct antelope */

    b = &a; /* let's point b at a */
    a.val = 110;  /* normal usage */

    /* since b is a pointer, we have to dereference it before we can use it */

    (*b).val = 111;
    
    /* however, it looks bad and we can do the following */
    b->val = 111; /* exactly the same as above */

    struct mutantfrog luke;

    build_frog(&luke); /* passing a pointer to the struct */

    printf("leg count: %d\n", luke.num_legs);
    printf("eye count: %d\n", luke.num_eyes);

    return 0;
}


/*
People usually pass a pointer to the structure into the function so that it does not have to call various arguments.

Every parameter without fail gets copied on the stack (!!!) when you call a function. Therefore, if you have a huge
struct such as 100,000 bytes in size, it's going to copy that onto the stack when you pass it, which is not efficient.

Even though the pointer has to be copied onto the stack as well, it should be relatively small and it works faster.
The rule basically is: if you have a struct, use the dot operator; if you have a pointer to a struct, use the arrow (->)

*/