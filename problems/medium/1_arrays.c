#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n = 0;
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));
    int sum = 0;
    for ( int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
        sum += array[i];
    }
    
    printf("%d\n", sum);
    free(array);

    return 0;
}