#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	signed int n1, n2, sum, diff;
    float n3, n4, sum_f, diff_f;

    scanf("%d %d", &n1, &n2);
    scanf("\n");
    scanf("%f %f", &n3, &n4);
    
    printf("%d %d\n", n1+n2, n1-n2);

    printf("%.1f %.1f\n", n3+n4, n3-n4);
    
    return 0;
}