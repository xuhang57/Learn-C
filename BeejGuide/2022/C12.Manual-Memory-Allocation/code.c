// Allocating and Deallocating, malloc() and free()

int *p = malloc(sizeof(int));

*p = 12; // Store something here;

printf("%d\n", *p); // Print it: 12

free(p); // All done with that memory

//*p = 3490 // ERROR: undefined behavior! Use after free()

// int *p = malloc(sizeof *p) // *p is an int, so name as sizeof(int)

// Allocating Space for an Array
char *p = malloc(3490); // 3490 chars (String)

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Allocate space for 10 ints
    int *p = malloc(sizeof(int) * 10);

    // Assign them values 0-45;
    for (int i = 0; i < 10; i++)
        p[i] = i * 5;

    // Print all values 0, 5, 10, ... 45
    for (int i = 0; i < 10; i++)
        printf("%d\n", p[i]);

    // Free the space
    free(p);
}

// Alternative: calloc()
// Allocate space for 10 ints with calloc(), initialized to 0:
int *p = calloc(sizeof(int), 10);

// Allocate space for 10 ints with malloc(), initialized to 0:
int *q = malloc(sizeof(int) * 10);
memset(q, 0, sizeof(int) * 10);  // set to 0

// Changing Allocated Size with realloc()
num_floats *= 2;

np = realloc(p, num_floats); // WRONG: need bytes, not number of elements

np = realloc(p, num_floats * sizeof(float));


