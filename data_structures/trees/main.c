/* 
 *      Title:  Main
 *    Section:  Trees
 *    Summary:  Entry point to test and debug tree-related algorithms
 *     Author:  Marta Nunes de Abreu
 *       Date:  20/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

int main(void)
{
    priority_queue *q;
    q = (priority_queue*) malloc(sizeof q);
    
    const int array_size = 5;
    int s[array_size] = {23, 32, 10, 21, 19};
    
    make_heap(q, s, array_size);
    print_heap(q, array_size);

    extract_min(q);
    print_heap(q, 4);

    int array[5] = {3, 5, 6, 1, 9};
    my_heap_sort(array, 5);
    return 0;
}