#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int *p;

    p = (int *)malloc( sizeof(int) * 10);

    if (p == NULL)
    {
        fprintf(stderr, "Invalid pointer");
        exit(1);
    }
    
    printf("\nMemory allocated, not initialized\n");
    printf("Pointer p points to %d\n\n", *p);    

    for (int i = 1; i < 10; i++)
    {
        // here p is also changing the value stored by base too
        *(p+i) = i * 100;    
        printf("%d\n", *(p+i));
    }

    puts("\nMemory allocated and filled\n");
    printf("Pointer p points to %d\n\n", *p);
    

    return(0);
}