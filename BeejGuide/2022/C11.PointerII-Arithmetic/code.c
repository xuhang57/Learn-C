// Math on Pointers, notably addition and subtraction

int a[5] = {11, 22, 33, 44, 55};
int *p = &a[0]; // Or "int *p = a;" works as well

printf("%d\n", *p); // Prints 11
printf("%d\n", *(p + 1)); // Prints 22!!

// Array/Pointer Equivalence
int b;
a[b] == *(a + b);

int my_strlen(char *s);

char s[] = "Antelops";
char *t = "Wombats";

printf("%d\n", my_strlen(s)); // Works!
printf("%d\n", my_strlen(t)); // Works, too!

// void pointers
void *memcpy(void *s1, void *s2, size_t n);
// This function copies n bytes of memory starting from address s1 into the memory starting at address s2

#include <stdio.h>
#include <string.h>

// The power of "void". You can write functions that do not care about the type and is still able to do things with it
int main(void)
{
    char s[] = "Goats!";
    char t[100];

    memcpy(t, s, 7); // Copy 7 bytes, including the NULL terminator!
    printf("%s\n", t); // "Goats!"

    int a[] = {11, 22, 33};
    int b[3];

    memcpy(b, a, 3 * sizeof(int)); // Copy 3 ints of data
    // we have to specify how many bytes to copy, and an int is more than one byte
    printf("%d\n", b[1]); // prints 22
}

// Deep down, you convert the void* to another type before you use it
void * my_memcpy(void *dest, void *src, int byte_count)
{
    // Convert void's to char's
    char *s = src, *d = dest;

    // now that we have char's, we can dereferenceand copy them
    while (byte_count--) {
        *d++ = *s++; // post-increment so that both d and s move to the next byte after the assignment is made
    }

    // Most of these functions return the destination, just in case that's useful to the caller
    return dest;
}


