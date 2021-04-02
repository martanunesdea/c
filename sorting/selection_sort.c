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

void selection(int a[], int N)
{
    int i, j, min, t;
    
    for ( i = 0; i < N; i++ )
    {
        min = i;
        for ( j = i+1; j < N; j++ )
            if ( a[j] < a[min]) min = j;
        t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
    printf("\n\n");
    print(a, N);
}

int main(void)
{
    int array[4] = {3, 5, 4, 2};
    selection(array, 4);
}
