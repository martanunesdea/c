#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *base;

    base = (int *)malloc(sizeof(int)*10);
    if ( base == NULL )
    {
        fprintf(stderr, "Allocation failure\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        *(base+i) = i * 100;
    }

    FILE *fp;
    fp = fopen("integers.dat", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to create file\n");
        exit(1);
    }

    fwrite(base, sizeof(int), 10, fp);
    
    fclose(fp);
    return 0;
}