/* A Storage class is a class of storing variables */

void print_plus_one(void) {
    static int a = 0; // static storage class

    printf("%d\n", a);
}

int main(void) {
    print_plus_one(); // prints "0"
    print_plus_one(); // prints "1"
    print_plus_one(); // prints "2"

    return 0;
}

/*
The keyword "static" is a directive (given before the type) tells the compiler to
actually store this data somewhere permanent rather than the stack. In other words,
the value gets initialized once, and it never gets initialized again.

Some other storage classes such as: auto, which is default.
Another is extern which tells the compiler that the definition of the variable is
different file, which allows you to reference a global variable from a file, even
if its definition is somewhere else.

*/