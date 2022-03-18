

int main(void) {
    int *p;

    p = malloc(sizeof(int) * 12); // allocate for me 12 ints

    free(p);

    return 0;
}