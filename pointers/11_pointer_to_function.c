#include <stdio.h>
#include <stdlib.h>

void initialise(int **p)
{
    *p = (int *)malloc(sizeof(int) * 4);
    
    if (*p == NULL)
    {
        fprintf(stderr, "Pointer allocation failed\n");
        exit(1);
    }
    printf("Address after malloc %p\n", *p);

    for (int i = 0; i < 4; i++)
    {
        *((*p)+i) = i * 100;
        printf("%d ", *((*p)+i));
    }
    printf("\n");
}

int main()
{
	int *new_array;

	initialise(&new_array);
    printf("Address after function call %p\n", new_array);

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(new_array+i) );
	}
	printf("\n");

	return(0);
}
