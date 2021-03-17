#include <stdio.h>
#include <stdlib.h>


int main(void) {
   //char mystring [100];
    char *mystring = (char *)malloc(sizeof(char *));

    printf("Enter a string; ");
    if ( fgets (mystring , 100 , stdin) != NULL )
    {
        //puts(mystring);
        printf("%s", mystring);
    }

   return 0;
}