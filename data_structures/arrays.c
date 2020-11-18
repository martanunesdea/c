#include <stdlib.h>
#include <stdio.h>

#define N 1000

int main(void)
{
    int j, a[N+1];
    int i = 2;
    for (a[1] = 0; i <= N; i++) a[i] = 1;
    for (i = 2; i <= N/2; i++)
    {
        for (j = 2; j < N/i; j++)
        {
            a[i*j] = 0;
        }
        if (a[i]) printf("%d \n", i);  
    } 
    // redundnat for loop when if clause is added in 2nd for loop
    /*for (i = 1; i <= N; i++)
    {
        if (a[i]) printf("%d \n", i);   
    }*/


}