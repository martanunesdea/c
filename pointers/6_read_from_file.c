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

    FILE *fp;
    fp = fopen("integers.dat", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to read file\n");
        exit(1);
    }

    int r;
    r = fread(base, sizeof(int), 10, fp);
    if (r != 10)
    {
        fprintf(stderr, "Could not read from file\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *(base+i));
    }

    fclose(fp);

    return 0;
}