#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    int difference = (b - a);

    int numb = 0;
    for ( int i = 0; i <= difference; ++i)
    {
        numb = a+i;
        if ( numb > 9 )
        {
            printf("%s", numb % 2 ? "odd\n" : "even\n");
        }
        else {
            switch(numb)
            {
                case 1:
                    printf("one\n");
                    break;
                case 2:
                    printf("two\n");
                    break;
                case 3:
                    printf("three\n");
                    break;
                case 4:
                    printf("four\n");
                    break;
                case 5:
                    printf("five\n");
                    break;
                case 6:
                    printf("six\n");
                    break;
                case 7:
                    printf("seven\n");
                    break;
                case 8:
                    printf("eitht\n");
                    break;
                case 9:
                    printf("nine\n");
                    break;
                default:
                    printf("larger than 9\n");
                    break;
            }
                
        }
    }
    
    return 0;
}
