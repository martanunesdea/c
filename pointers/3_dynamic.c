#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    char *storage;
    int size = 5;

    /* malloc */ 
    storage = (char *)malloc( sizeof(char) * size + 1); /* don't forget the null character of the string! */
    if (storage == NULL)
    {
        fprintf(stderr, "Allocation error\n");
        exit(1);
    }
    /* not good - storage has not been initialized !!!
    for ( int i = 0; i < size+1; i++ )
    {
        printf("%c\n", *(str+i));
    }
    */
    free(storage);
    storage = NULL;

    /* calloc */
    storage = (char *)calloc(size, sizeof(char));
    if (storage == NULL)
    {
        fprintf(stderr, "Allocation error\n");
        exit(1);
    }
    puts("\nBuffer initialized\n");

    for ( int i = 0; i < size; i++ )
    {
        printf("%c\n", *(storage+i));
    }


    /* realloc */
    int new_size = 7;
    storage = (char *)realloc(storage, sizeof(char) * new_size);
    if (storage == NULL)
    {
        fprintf(stderr, "Allocation error\n");
        exit(1);
    }
    puts("\nBuffer re-sized\n");

    *(storage+5) = 'm';
    *(storage+6) = 'n';
    for ( int i = 0; i < new_size; i++ )
    {
        printf("%c\n", *(storage+i));
    }

}