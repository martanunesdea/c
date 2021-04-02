#include <stdlib.h>
#include <stdio.h>

void print(int a[], int N)
{
    for ( int i = 0; i < N; i++ )
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubble(int a[], int N)
{
    int i, j, t;
    for ( i = N-1; i >= 0; i-- )
    {
        for ( j = 1; j <= i; j++ )
        {
            if ( a[j-1] > a[j] )
            {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t; 
            }   
        }
    }

    print(a, N);
}


int main(void)
{
    int array[7] = {1, 5, 4, 2, 8, 6, 3};
    bubble(array, 7);
}