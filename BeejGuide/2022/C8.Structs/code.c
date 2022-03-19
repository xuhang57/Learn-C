struct car {
    char *name;
    float price;
    int speed;
};

int main(void)
{
    struct car saturn = {"Saturn SL/2", 16000.99, 175};

    // Pass a pointer to this struct car, along with a new more realistic price
    set_price(&saturn, 799.99);
}

void set_price(struct car *c, float new_price)
{
    // c.price = new_price; // ERROR !!
    // As dot operator only works on structs, it does not work on pointers to structs
    (*c).price = new_price; // works, but is ugly and non-idiomatic

    // The Arrow Operator
    // When accessing fields, when do we use dot or error?
    // * If you have a struct, use dot (.)
    // * if you have a pointer to a struct, use arrow ( -> )
    c->price = new_price; // helps refer to fields in pointers to structs
}
