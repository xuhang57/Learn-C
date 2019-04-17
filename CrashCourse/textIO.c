#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name = "Lucas";
    int score = 100;
    /* %s treats the argument as a c string pointer, keep printing all characters until the NULL-char */
    printf("Hello %s, your score is %d\n", name, score);
    /* name has already a pointer */
    printf("Debug: The string and int are stored at: %p and %p\n", name, &score );

    // puts(name);
    /* single quotes here */
    // char c = 'y';
    // putchar(c);

    /* print data into a C string */
    char result[200];
    int len = snprintf(result, sizeof(result), "%s:%d", name, score);
    printf("%d\n", len);

    fprintf(stdout, "Hello World\n");
    fflush(stdout);

    const char *nptr = "1a2436";
    char* endptr;
    /* take the pointer to your string *nptr, and a base and an optional pointer endptr -> returns a parsed value */
    long int ans = strtol(nptr, &endptr, 16);
    /* above function won't return an error code, need to check whether ans == 0 */
    printf("%ld\n", ans);

    int *data = (int *) malloc(sizeof(int));
    char *line = "v 10";
    char type;
    /* use scanf(sscanf) to get input from the defult input stream */
    int ok = 2 == sscanf(line, "%c %d", &type, &data);
    printf("data is %d\n", data);
    printf("type is %c\n", type);

    char buffer[10];
    /* read up to 9 chars, last byte is the termination byte */
    scanf("%9s", buffer);
    printf("%s\n", buffer);

    char buf[10];
    /* vulnerable to buffer overflow, since it assumes that the input line will be no more than 10 characters */
    //gets(buf);
    char *res = fgets(buf, sizeof(buf), stdin); // or getline();

    return 0;
}

