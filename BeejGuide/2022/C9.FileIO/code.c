#include <stdio.h>

int main(void)
{
    FILE *fp; // variable to represent open file

    fp = fopen("hello.txt", "r"); // open file for reading

    int c = fgetc(fp);  // read a single character
    printf("%c\n", c);

    fclose(fp);

    // End of File: EOF
    FILE *fp;
    int c;

    fp = fopen("hello.txt", "r");
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);

    fclose(fp);

    // Other APIs: fgets (read lines), fscanf (formatted Input), 

}
