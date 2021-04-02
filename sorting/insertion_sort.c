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

void insertion(int a[], int N)
{
    int i, j, v;
    for ( i = 0; i < N; i++ )
    {
        v = a[i];
        j = i;
        while ( a[j-1] > v )
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }

    print(a, N);
}


int main(void)
{
    int array[7] = {1, 5, 4, 2, 8, 6, 3};
    insertion(array, 7);
}