#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int *base, *p;

    base = (int *)malloc( sizeof(int) * 10);

    if (base == NULL)
    {
        fprintf(stderr, "Invalid pointer");
        exit(1);
    }
    
    p = base;
    printf("\nMemory allocated, not initialized\n");
    printf("Pointer p points to %d\n", *p);
    printf("Pointer base points to %d\n\n", *base);
    

    for (int i = 1; i < 10; i++)
    {
        // here p is also changing the value stored by base too
        *p = i * 100;    
        printf("%d\n", *p);
        p++;
    }
    puts("Memory allocated and filled\n");
    printf("Pointer p points to %d\n", *p);
    printf("Pointer base points to %d\n\n", *base);
    

    return(0);
}