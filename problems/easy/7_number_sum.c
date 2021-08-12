#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// note for future: can solve with module and division or bit-masks
int main() {
	
    int n;
    int numbers[10]; 
    scanf("%d", &n);
    printf("%d\n\n", n);
    //Complete the code to calculate the sum of the five digits on n.
    int sum = 0;
    int i = 0;

    while (1)
    {
        numbers[i] = (n%10);
        sum += numbers[i];
        n = n/10;
        i++;
        if (n <= 0) break;
    }
    printf("%d\n", sum);
    return 0;
}