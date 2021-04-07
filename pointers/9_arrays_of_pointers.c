#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	int x;

	for(x=0; x<4; x++)
		printf("Address: %p = %s\n", fruit[x], fruit[x]);

	char *fruit_diff[4] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};

	for(x=0; x<4; x++)
		printf("Address: %p = %s\n", fruit_diff[x], fruit_diff[x]);
    


	return(0);
}
