#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *arr = (int*) malloc(n * sizeof(int));

    scanf("%d", &n);
        
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    int *reversed = (int *) malloc(n * sizeof(int));
    int j = 0;

    for(int i = n-1; i >= 0; i-- ){
        reversed[j] = arr[i];
        j += 1;

        printf("%d ",(arr[i]));
    }
    
    return 0;
}