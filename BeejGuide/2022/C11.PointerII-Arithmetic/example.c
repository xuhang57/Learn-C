#include <stdio.h>
#include <stdlib.h>

// The type of Struct we are going to sort
struct animal {
    char *name;
    int leg_count;
};

// This is a comparison function called by qsort() to help it determine what exactly to sort by
// We will use it to sort an array of struct animals by leg_count
int compar(const void *e1, const void *e2)
{
    // We know we are sorting struct animals, so let's make both
    // arguments pointers to struct animals
    const struct animal *animal1 = e1;
    const struct animal *animal2 = e2;

    // Return <0 =0 or >0 depending on whatever we want to sort by

    // Let's sort ascending by leg_count
    if (animal1->leg_count > animal2->leg_count)
        return 1;
    if (animal1->leg_count < animal2->leg_count)
        return -1;

    return 0;
}

int main(void)
{
    // build an array of 4 struct animals with different characteristics
    // This array is out of order by leg_count, but we'll sort it in a second
    struct animal a[4] = {
        {.name="Dog", .leg_count=4},
        {.name="Monkey", .leg_count=2},
        {.name="Antelope", .leg_count=4},
        {.name="Snake", .leg_count=0}
    };

    // qsort() needs to be told exactly what to sort this data by, and we'll do that inside the compar()
    qsort(a, 4, sizeof(struct animal), compar);
}
