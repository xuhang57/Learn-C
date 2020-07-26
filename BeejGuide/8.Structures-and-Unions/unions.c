#include <stdio.h>

struct variable {
    int type;

    union {
        int i;
        float f;
        char *s;
    } data;
};

void print_variable(struct variable *v) {
    switch(v->type) {
    case 0:
        printf("%d\n", v->data.i);
        break;
    case 1:
        printf("%f\n", v->data.f);
        break;
    case 2:
        printf("%s\n", v->data.s);
        break;
    }
}

int main(void) {
    struct variable v;

    v.type = 1;
    v.data.f = 0.8;

    print_variable(&v);

    return 0;
}

/*
Unions are very much the as the structs. An important difference is this: unions share the same memory
space for all their members.

The reason to use union is to save memory in a struct-like construct when you know you won't be using the
fields at the same time. If you want to store data and its type, you could store the type as an int (or an enum)
and store the data in a union

*/