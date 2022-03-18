#include <stdio.h>

#define INITIAL_SIZE 10
#define BUCKET_SIZE 5

static int data_count;  // how many ints we have stored
static int data_size;  // how many ints we can store in this block
static int *data;  // the block of data itself

int main(void) {
    void add_data(int new_data);
    int i;

    data_count = 0;
    data_size = INITIAL_SIZE;
    data = malloc(data_size * sizeof(int));

    for (i=0;i<23;i++) {
        add_data(i);
    }

    return 0;
}

void add_data(int new_data) {
    if (data_count == data_size) {
        data_size += BUCKET_SIZE;
        data = realloc(data, data_size * sizeof(int));
    }

    *(data+data_count) = new_data; // data[data_count] = new_data;
    data_count++;
}

/*
Maybe you though you only needed 100 ints at first, but now you need 200. You can realloc() the block to give you the space you need
realloc() might have to move your data to another place in memory if it cannot, for whatever reason, increase the size of the current
block.

calloc() is just like malloc(), except that it 1) clears the memory to zero for you, and 2) it takes two parameters instead of one.
Parameters are the number of element that are to be in the memory block, and the size of each element

*/