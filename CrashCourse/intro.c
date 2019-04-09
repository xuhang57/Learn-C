/* includes the text of the file as part of our file to be compiled */

#include <stdio.h>

int main() {
    /* ['A', 'B', 'C', '\0'] */
    /* ptr is a pointer which holds the memory address of the first character in the string */
    char *ptr = "ABC";

    char *str = "ABC";
    char str1[] = "ABC";
    char str2[] = {'A', 'B', 'C', '\0'};

    /* Due to C's grammer, an int* or any pointer is not actually its own type. You have to precede each pointer var. with an asterisk. */
    int *ptr3, *ptr4;

    *ptr3 = 0; // writes some memory

    char *ptr5 = "Hello"; // ptr5 holds the memory location of "H"
    ptr5 += 2; // ptr now points to the first 'l'

    /* if an int is 4 bytes, then ptr + 1 points to 4 bytes after whatever ptr is pointing at */
    char *ptr6 = "ABCDEFGH";
    int *bna = (int *) ptr6;
    bna += 1; // iterate by one integer space
    ptr = (char *) bna;
    /* printf calls write (system call) */
    /* printf includes an internal buffer so, to increase performance, printf may not call write everytime you call printf. */
    printf("%s", ptr); // only "EFGH" is printed 

    /* A pointer without a type (void). Void pointers are used when either a datatype is unknown or interfacing C code with other programming language */
    void *give_me_space = malloc(10);
    /* Does not require a cast because C automatically promotes void* to its appropriate type */
    /* gcc/clang will let you do arithmetic on a void pointer, treating it as a char pointer but do not do this because it may not work with other compiler */
    void *string = give_me_space;

    int num1 = 10;
    printf("%d". num1);

    int *ptr7 = (int *) malloc(sizeof(int));
    *ptr = 10;
    printf("%p\n", ptr7); // prints the addr. pointed to by the pointer
    printf("%p\n", &ptr); // prints the addr of pointer
    printf("%d\n", *ptr); // prints the integer content of the pointer

    char *str3 = (char *) malloc(256 * sizeof(char));
    strcpy(str, "Hello There!");
    printf("%p\n", str3); // print the addr in the heap
    printf("%s\n", str3);

    char ary[] = "Hello";
    char *ptr = "Hello";

    strcpy(ary, "World"); // OK
    strcpy(ptr, "World"); // Segment Fault

    printf("%d", sizeof(ary)); // 5 chars + zero byte = 6 bytes
    printf("%d", sizeof(ptr)); // same as sizeof(char *) which returns the number bytes required for a pointer


    /* something is static means it exists for the lifetime of the process, which static var. are not in the heap or stack */
    static int num2 = 10;

    /* allocate memory on the heap */
    int *space = malloc(sizeof(int) * 10);
    /* un-allocate memory on heap */
    /* double free error: attempt to free the same allocation twice */
    free(space);

    /* declares an alias for a type */
    typedef float real;
    real gravity = 10;

    /* often used with structs to reduce the visual clutter of having to write struct as part of the type */
    typedef struct link link_t;

    /* declares a function type comparator that accepts two void* params and returns an integer */
    typedef int (*comparator)(void*, void*);
    comparator gt = greater_than;

    return 0;
}

int greater_than(void *a, void *b) {
        return a > b;
}

void mystrcpy(char *dest, char *src) {
    while( *src ) {
        *dest = *src;
        src++;
        dest++;
    }
    /* while ((*dest++ = *src++)) {}; */
}

char* mystrdup(char *source) {
    /* use strlen+1 to find the zero byte */
    char *p = (char *) malloc (strlen(source) + 1);
    strcpy(p, source);
    return p;
}

