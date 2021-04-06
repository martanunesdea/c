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
    
    for (int i = 1; i < 10; i++)
    {
        *p = i * 100;           // if missing p would be uninitialized - not good !
        printf("%d\n", *p);
        p++;
    }
    puts("Memory allocated and filled\n");
    printf("Pointer p points to %d\n\n", *p);

    free(p);
    p = NULL;

    


    return(0);
}