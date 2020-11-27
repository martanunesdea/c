/* 
 *      Title:  Main
 *    Section:  Mergesort
 *    Summary:  Entry-point to test mergesort
 *     Author:  Marta Nunes de Abreu
 *       Date:  20/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* To merge
 * avoid losing an element by overwriting it
 * first, copy each subarray to a separate queue
 * and merge these elements back into the array */
void merge(int s[], int low, int middle, int high)
{
    int i, j, k;
    int n1 = middle - low + 1;
    int n2 = high - middle;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = s[low + i];
    for (j = 0; j < n2; j++)
        R[j] = s[middle + 1 + j];
 
    /* Merge the temp arrays back into s[low..high]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = low; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            s[k] = L[i];
            i++;
        }
        else {
            s[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        s[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        s[k] = R[j];
        j++;
        k++;
    }
} 

void my_merge_sort(int s[], int low, int high)
{
    int i;
    int middle;

    if (low < high)
    {
        middle = (low + high)/2;
        my_merge_sort(s, low, middle);
        my_merge_sort(s, middle+1, high);
        merge(s, low, middle, high);
    }
}

void print_array(int s[], int size)
{
    printf("\n ---- Array ---- \n");
    for( int i = 0; i < size; i++)
    {
        printf(" %d \n", s[i]);
    }
}

int main(void)
{

    int s[4] = {1, 6, 4, 3};
    int size = sizeof(s)/sizeof(s[0]);

    printf("\nInput array: ");
    print_array(s, size);
    my_merge_sort(s, 0, size - 1);

    printf("\nOutput array: ");
    print_array(s, size);
    
    return 0;
}