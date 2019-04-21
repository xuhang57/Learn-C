#include <stdio.h>
#include <string.h>

/* a struct is just a piece of contiguous memory. Just like an array, a struct has enough space to keep all of its members
   but unlike an array, it can store different types */
struct contact {
    char firstname[20];
    char lastname[20];
    unsigned int phone;
};

struct contact lucas;

/* define a struct */
typedef struct contact contact;
contact lucas;

// &lucas // 0x100
// &lucas.firstname // 0x100 =  0x100 + 0x00
// &lucas.lastname // 0x114 = 0x100 + 0x14
// &lucas.phone // 0x128 = 0x00 + 0x28

typedef struct {
    int length;
    char c_str[0];
} string;

void example() {
    const char* to_convert = "lucas";
    int length = strlen(to_convert);

    //Let's convet to a c string
    string* lucas_name;
    /* currently, the memory looks like junk in contiguous memory blocks */
    lucas_name = malloc(sizeof(string) + length + 1);
    /* lucas_name = |0|0|0|5| | | | | | |... */
    lucas_name->length = length;
    /* lucas_name = |0|0|0|5|l|u|c|a|s|\0| */
    strcpy(lucas_name->c_str, to_convert);

    strcmp(lucas_name->c_str, "lucas") == 0; // these strings are equal

}

/* structs may require something called padding */
struct __attribute__((packed, aligned(4))) picture {
    int height;
    pixel** data;
    int width;
    char* encoding;
}


int main(void) {

    char* hello_string = malloc(14);

    hello_string = "Hello Lucas!!";

    /* we allocated space for 14 bytes, reassigned the pointer and successfully seg. faulted */
    hello_string[9] = 't'; // seg. fault

    /* should use */
    strcpy(hello_string, "Hello Lucas!!");

    /* int strlen(const char *s) returns the length of the string not including the null byte */
    /* int strcmp(const char *s1, const char *s2) returns an interger determining the lexcographic order of the strings */
    /* char *strcpy(char *dest, const char *src) copies the string src to dest. assumes dest has enough space for src */
    /* char *strcat(char *dest, const char *src) concatenates the string at src to the end of destination. Assumes there is enough space for src at the end 
    of destination including the null byte */
    /* char *strdup(const char *dest) returns a malloc'ed copy of the string */
    /* char *strchr(const *haystack, int needle) returns a pointer to the first occurrence of needle in the haystack. */
    /* char *strstr(const char *haystack, const char *needle) for a string */

    char* upped = strdup("strtok,is,tricky,!!");
    /* takes a string and tokenizes it, which transform the strings into separate strings*/
    char* start = strtok(upped, ",");
    do {
        printf("%s\n", start);
    } while((start = strtok(NULL, ',')));


    /* strings are essentially raw memory with a null byte at the end of them */
    /* void *memcpy(void *dest, const void *src, size_t n) moves n bytes starting at src to dest */
    /* be careful with undefined behavior when the memory regions overlap */
    /* void *memmov(void *dest, const void *src, size_t n) does the same thing, but if memory overlap then it
    guaranteed that all the bytes will get copied over correctly */

    return 0;
}