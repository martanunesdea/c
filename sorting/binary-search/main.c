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
    int middle; /* index of middle element */

    if ( low > high )
    {
        /* key not found */
        return -1; 
    }
    int middle = (low + high) / 2;
    
    if ( s[middle] == key )
        return(middle);
    
    if ( s[middle] > key)
        return( binary_search(s, key, low, middle-1) );
    else
        return( binary_search(s, key, middle+1, high) );
    
}

int main(void)
{
    return 0;
}