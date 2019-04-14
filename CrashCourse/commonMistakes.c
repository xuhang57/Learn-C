#include <stdio.h>

// macro
#define safer_free(p) { free(p); (p) = NULL;}

struct User {
    char name[100];
};

typedef struct User user_t;

int main() {

    // we only allocate enough bytes to hold a pointer, but the struct here
    //user_t *user = (user_t *) malloc(sizeof (user_t *));
    user_t *user = (user_t *) malloc(sizeof (user_t));


    char array[] = "Hi!"; //array contains a mutable copy
    strcpy(array, "OK");

    char *ptr = "Cannot change me"; // ptr points to some immutable memory
    strcpy(ptr, "will not work");

    /* String literals are character arrays stored in the code segment of the program, which is immutable */
    char *str1 = "this is lucas";
    char *str2 = "this is lucas";
    str1 == str2; // true since they point to the same memory addr

    /* char arrays, however, contain deep copies of string literals assigned to them */
    char ary1[] = "today is a good day";
    char ary2[] = "today is a good day";
    ary1 == ary2; // false
    &ary1[0] == &ary2[0]; // false

    int i = 10; array[10];
    /* Buffer Over/Underflow */
    for(; i>=0; i--) {
        array[i] = i;
    } // C does not perform bounds-checking on array accesses


    char *p = malloc(10);
    free(p);
    /* double free error */
    free(p);


    /* dangling pointer */
    char *t = malloc(10);
    strcpy(p, "hello!");
    free(p);
    strcpy(p, "world"); // accessing freed memory result in undefined behavior

    char *line = NULL;
    size_t linecap = 0;
    char *string[3];

    // assume stdin contains "1\n2\n3\n"
    for (size_t t = 0; i < 3; ++i) {
        string[i] = getline(&line, &linecap, stdin) >= 0 ? line : "";
        /* we could do this */
        string[i] = getline(&line, &linecap, stdin) >= 0 ? strdup(line) : ""; // deep copy of the buffer
    } // getline reuses a buffer, all pointers in the string array are actually pointing to the same memory

    /* this prints "3\n3\n3" */
    for(size_t i = 3; i--;) { // i = 2, 1, 0
        printf("%s", string[i]);
    }


    int flag = 1;
    switch(flag) {
        case 1:
            printf("i am printed\n");
            break;
        case 2:
            printf("me too\n");
            break;
        case 3:
            printf("me three\n");
            break; // not need

    }

    return 0;
}

/* Automatic variables are bound to stack memory only as long as they are in scope */
int *f() {
    int result = 42;
    static int imok;
    int *p;
    {
        int x = result;
        p = &x;
    }
    // imok = *p // not ok, x has already gone out of scope
    // return &result // not okay, result will go out of scope after the function returns
    return &imok; // OK since static variable are not on the stack
}

char *strdup(const char *input) {
    char *copy;
    copy = malloc(sizeof (char *)); // allocates a space for a pointer
    copy = malloc(strlen(input)); // no space for the null bype
    copy = malloc(strlen(strlen(input)+1));
    strcpy(copy, input); // strcpy will provide the null terminator
    return copy;
}

/* automatic(stack) variables and heap memory obtained with malloc are not initialized to zero by default */
void myfunc() {
    char array[10];
    char *p = malloc(10);
    printf("%s %s\n", array, p); //undefined behavior
}