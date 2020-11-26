/* 
 *      Title:  Main
 *    Section:  Quicksort
 *    Summary:  Entry-point to test quicksort
 *     Author:  Marta Nunes de Abreu
 *       Date:  20/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = a;
}


int partition(int s[], int l, int h)
{
    int i;          /* counter */
    int p;          /* pivot element index */
    int firsthigh;  /* divider position for pivot element */

    p = h;
    firsthigh = l;
    for ( i = l; i < h; i++)
    {
        if (s[i] < s[p])
        {
            swap(&s[i], &s[firsthigh]);
            firsthigh++;
        }
    }
    swap(&s[p], &s[firsthigh]);

    return(firsthigh);
}

void my_quick_sort(int s[], int l, int h)
{
    int p;      /* index of partition */

    if ( (h-l) > 0 )
    {
        p = partition(s, l, h);
        my_quick_sort(s, l, p-1);
        my_quick_sort(s, p+1, h);
    }

    printf(" \n ----------------- \n");
    for( int j = 0; j < 4; j++)
    {
        printf(" %d \n", s[j]);
    }
}

int main(void)
{
    int s[4] = {1, 2, 5, 3};

    my_quick_sort(s, 1, 5);

    return 0;
}