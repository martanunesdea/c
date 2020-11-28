/* 
 *      Title:  Main
 *    Section:  Binary Search
 *    Summary:  Entry-point to test binary serch
 *     Author:  Marta Nunes de Abreu
 *       Date:  21/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdio.h>
#include <stdlib.h>
int binary_search(int s[], int key, int low, int high)
{
    if ( low > high )
    {
        /* key not found */
        return -1; 
    }
    int middle = (low + high) / 2; /* index of middle element */

    if ( s[middle] == key )
    {
        return(middle);
    }

    if ( s[middle] > key)
        return( binary_search(s, key, low, middle-1) );
    else
        return( binary_search(s, key, middle+1, high) );
    
}

int main(void)
{
    
    int s[5] = {1, 2, 4, 5, 6}; // sorted array

    int key_to_find = 5;
    int size = sizeof(s)/sizeof(s[0]);
    int starting_element = 0;

    int value = binary_search(s, key_to_find, starting_element, size-1);
    printf("Place of %d is %d \n", key_to_find, value);

    return 0;
}