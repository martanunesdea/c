#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int a[5] = {1, 3, 5, 7, 9};
    int *p;

    p = a;      // pointer to first element of array
    // p = &a[0];  // pointer to first element of array
    // p = &a;     // pointer to array of 5 integers

    int *p_arr[5] = &a;
    
    for ( int i = 0; i < 5; i++ )
    {
        printf("a[%d] = %d\n", i, *(p+i));
    }
}