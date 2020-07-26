/* Func Prototypes */

int foo(void); /* a prototype */

/* Func def */
int plus_one(int n) {
    return n + 1;
}

void increment(int a) {
    a++;
}

int foo(void) {
    return 123;
}

int main(void) {
    int i = 10, j;
    /* passing by value */
    j = plus_one(i);
    printf("i + 1 is %d\n", j);

    int w = 10;

    /* the value of w is still 10 */
    increment(w);

    return 0;
}

/*
Passing by Value:
    when you pass a value to a function, a **copy** of that value gets made in the stack
    note that C specification doesn't say anything about a stack.
Passing by Reference:
    that's how Java/Python works. In C, you need to explicit claim it is a pointer in the function parameters

Prototypes:
    notify the complier in advance that you will be using a function of a certain type that has a certain parameter
    list and that way the function can be defined anywhere at all, as long as the function prototype has been decalared first
    

*/