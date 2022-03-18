#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Hello World\n");


    char *s = "Hello!";

    printf("$s\n", s); /* Prints "Hello!" */
    printf("%c\n", *s); /* prints 'H' */
    printf("%c\n", s[1]); /* prints 'e' */


    char s[20] = "The aliens are comming!";
    // char s[] = "The aliens are comming!";

    char a[20] = "Cats are better.";
    char *p;

    p = a; /* p now points to the first char in array a */

    char b[] = "Hellow, world!";

    for (int i = 0; i < 13; i++) {
        printf("%c]n", s[i]);
    }

    char *d = "Hello, world!";  // char* here, pointer to a constant string (first char in a constant str)

    for (int i = 0; i < 13; i++) {
        printf("%c\n", d[i]); // still works, hinting tht arrays and pointers are the same thing, deep down
    }

    char *s = "Hello, world!";
    s[0] = 'z'; // BAD NEWS: tried to mutate a constant string
    char t[] = "Hello, again!"; // t is an array copy of the string
    t[0] = 'z'; // Success
    printf("%s\n", t); // "zello, again!"

    //String length
    printf("The string is %zu characters long.\n", strlen(s)); // return type size_t, which is an integer type [%zu]

    return 0;
}

int my_strlen(char *s) {
    int count = 0;

    while (s[count] != '\0') {
        count++;
    }

    return count;
}

int copy_str(void) {
    char s[] = "Hello, world!";
    char *t;

    // This makes a copy of the pointer, not a copy of the string!
    t = s;

    // Modify t
    t[0] = 'z';

    // But printing s shows the modification
    // Because t and s point to the same string
    printf("%s\n", s); // "zello, world!";

    char s[] = "Hello, world!";
    char t[100]; // Each char is one byte

    // This makes a copy of the string
    strcpy(t, s);

    // Modify t
    t[0] = 'z';

    // And s remains unaffected because it is a different string
    printf("%s\n", s); // Hello, world!

    // But t has bene changed
    printf("%s\n", t); // "zello, world!"
}



/* 

"Hello World!" is a constant string (String Literal) and it is a type *char. BUt you can also put a string in a char array.
The char* points at the first character in the string

strings in C end with a NUL character. That's a zero: "\0". You can truncate a string to zero length by assigning "\0" to the
first byte in the string. Also, all the standard string functions assume the string ends with a NUL character.

*/