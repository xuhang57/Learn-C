typedef int antelop;

antelop x= 10;

// typedef follows regular scoping rules

struct animal {
    char *name;
    int leg_count, speed;
}

typedef struct animal animal;

// both of these work
struct animal y;
animal z;

// Or
typedef struct animal {
    char *name;
    int leg_count, speed;
} animal; // new name

// anonymous structure
typedef struct {
    char *name;
    int leg_count, speed;
};

// struct animal y; // ERROR
animal z;

typedef long double app_float; // long double

typedef int *intptr;

int a = 10;
intptr x = &a; // "intptr is type int*"
