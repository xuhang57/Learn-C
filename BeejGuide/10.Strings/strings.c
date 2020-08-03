#include <stdio.h>

int main(void) {
    printf("Hello World\n");


    char *s = "Hello!";

    printf("$s\n", s); /* Prints "Hello!" */
    printf("%c\n", *s); /* prints 'H' */
    printf("%c\n", s[1]); /* prints 'e' */


    char s[20] = "The aliens are comming!";

    char a[20] = "Cats are better.";
    char *p;

    p = a; /* p now points to the first char in array a */

    return 0;

}

/* 

"Hello World!" is a constant string (String Literal) and it is a type *char. BUt you can also put a string in a char array.
The char* points at the first character in the string

strings in C end with a NUL character. That's a zero: "\0". You can truncate a string to zero length by assigning "\0" to the
first byte in the string. Also, all the standard string functions assume the string ends with a NUL character.

*/