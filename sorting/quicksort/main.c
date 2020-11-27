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

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int s[], int low, int high)
{
    int pivot = s[high];  /* pivot, element to be placed at right-most position */
    int lower = low - 1; /* index of smaller element */

    for ( int i = low; i <= high - 1; i++)
    {
        /* if current element is smaller than the pivot */
        if (s[i] < pivot)
        {
            lower++;
            swap(&s[lower], &s[i]);
        }
    }
    swap(&s[lower+1], &s[high]);

    return(lower+1);
}

void my_quick_sort(int s[], int l, int h)
{
    int p;      /* index of partition */

    if ( l < h )  /* check pointers haven't crossed */
    {
        p = partition(s, l, h);
        my_quick_sort(s, l, p-1);
        my_quick_sort(s, p+1, h);
    }


}

void print_array(int s[], int size)
{
    printf(" \n ----------------- \n");
    for( int j = 0; j < size; j++)
    {
        printf(" %d \n", s[j]);
    }
}

int main(void)
{
    int s[] = {22, 7, 5, 3};
    int size = sizeof(s)/sizeof(s[0]);

    my_quick_sort(s, 0, size-1);
    print_array(s, size);
    return 0;
}