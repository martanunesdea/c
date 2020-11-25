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

// TODO: add queue header and source files to directory


mergesort(int s[], int low, int high)
{
    int i;
    int middle;

    if (low < high)
    {
        middle = (low + high)/2;
        mergesort(s, low, middle);
        mergesort(s, middle+1, high);
        merge(s, low, middle, high);
    }
}

/* To merge
 * avoid losing an element by overwriting it
 * first, copy each subarray to a separate queue
 * and merge these elements back into the array */
merge(int s[], int low, int middle, int high)
{
    int i;
    queue buffer1, buffer2;

    init_queue(&buffer1);
    init_queue(&buffer2);

    for( i = low; i <= middle; i++)
    {
        enqueue(&buffer1, s[i]);
    }
    for( i = middle+1; i <= high; i++)
    {
        enqueue(&buffer2, s[i]);
    }

    i = low;
    while( !(empty_queue(&buffer1) || empty_queue(&buffer2)))
    {
        if (headq(&buffer1) <= headq(&buffer2))
            s[i++] = dequeue(&buffer1);
        else
            s[i++] = dequeue(&buffer2);
    }

    while( !empty_queue(&buffer1))
        s[i++] = dequeue(&buffer1);
    while( !empty_queue(&buffer2))
        s[i++] = dequeue(&buffer2);
} 