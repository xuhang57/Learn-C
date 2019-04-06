/* hello world program */
/* C preprocessor: GCC, VC++, Turbo C */

/* tell C preprocessor to pull the contents of another file and insert it into the code here */
/* stdio.h is a header file called Standard IO header file */
#include <stdio.h>

/* a function called main */
int main(void)
{
    /* passing parameter to the function printf() */
    printf("Hello, World!");

    return 0;
}

/*
C preprocessor: Anything that starts with pound sign (#) is something the preprocessor operates on before the compiler even gets started.

Common preprocessor directives: "#include", "#define"
After the C preprocessor has fininshed preprocessing everything, the results are ready for the compiler to take them and produce assembly
code, machine code.

Standard IO header file contains preprocessor directives and function prototypes for common input and output needs. "man printf"

*/