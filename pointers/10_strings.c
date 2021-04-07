#include <stdio.h>

int main()
{
	char *fruit[] = {
		"Apples", "Bananas", "Grapes", "Strawberries"
	};
	char **f;

	f = fruit;
    int y;
	for(int x = 0; x < 4; x++)
	{
		y = 0;
		while( *((*f)+y) )
		{
			putchar( *(*f+y) );
			y++;
		}
		putchar('\n');
		f++;
	}

	return(0);
}
