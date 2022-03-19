# Pointer II

## Void Pointers

Two use cases

* A function is going to operate on something byte-by-byte. For example, `memcpy()` copies bytes of memory from one pointer to another, but those pointers can point to any type. `memcpy()` takes advantage of the fact that if you iterate through `char`'s, you are iterating through the bytes of an object no matter what type the object is.
* Another function is calling a function you passed to it (a callback), and it's passing you data. You know the type of the data, but the function calling you does not. So it passes you `void`'s as it does not know the type. You convert those to the type you need. The built-in `qsort()` and `bsearch()` use this technique.

Limitations

* You cannot do pointer arithmetic on a `void*`
* You cannot dereference a `void*`
* You cannot use the arrow operator on a `void*`, since it is also a dereference
* You cannot use array notation on a `void*`, since it is also a dereference
