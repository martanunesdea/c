#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;

    printf("Address of a is %p\n", &a);
    printf("Address of b is %p\n", &b);

    int *x;
    int *y;

    x = &a;
    y = &b;
    printf("Pointer x contains %p\n", x);
    printf("Pointer y contains %p\n\n", y);

    // changing a 
    a = 12;
    printf("Pointer x contains %d\n", *x);

    *x = 14;
    printf("Pointer x contains %d\n", *x);
    printf("a  contains %d\n", a);


     
    /* 
    --- INVALID CODE ---
    int *z = NULL;

    *z = a;
    printf("z contains %d\n", z);
    *z = 13;
    printf("a contains %d\n", *z);
    */


}