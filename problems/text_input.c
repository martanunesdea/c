#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING 80

int main()
{
    char name[MAX_STRING];
    char locale[MAX_STRING];
    char *newlocale;
    int i;

    printf("Who are you? ");
    bool empty = true;
    do
    {
        fgets(name, sizeof(name), stdin);
        if ( !strncmp(name, "\n",sizeof(name)))
        {
            empty = false;
        }
    } while ( empty );


}