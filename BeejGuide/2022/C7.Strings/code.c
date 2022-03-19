#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hello, world!";
    printf("%s\n", s);

    char s[14] = "Hello, world!";
    char s[] = "Hello, world!";

    printf("The string is %zu bytes long.\n", strlen(s));

    // In C, a "string" is defined by two basic characteristics
    // * A pointer to the first character in the string
    // * A zero-valued byte (or NUL character) somewhere in memory after the pointer that indicates the end of the stirng
    char *s = "Hello!"; // Actually "Hello!\0" behind the scnens

    char s[] = "Hello, world!";
    char t[100]; // Each char is one byte, so plenty of room
    strcpy(t, s);
    t[0] = 'z';
    printf("%s\n", t); // "zello, world!"
}

int my_strlen(char *s)
{
    int count = 0;

    while (s[count] != '\0') // Single quotes for single char
        count++;

    return count;
}
