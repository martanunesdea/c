#include <stdio.h>
#include <stdlib.h>


int getInt (char *prompt)
{
    char *line = NULL;      /* pointer to use with getline ()       */
    ssize_t read = 0;       /* number of characters read            */
    size_t n = 5;           /* numer of chars to read, 0 no limit   */
    static int c = 0;     /* number result                        */

    while (printf ("\n %s ", prompt) && (read = getline (&line, &n, stdin)) != -1)
    {
        if( *line == '*' || *line == '+')
            break;
        else if( *line >= '0' && *line <= '9')
            break;
        else
            printf ("Invalid Input, Try Again...\n");
    }
    printf ("%c", *line);
    return c;
}

int main(){

    char a , b, op;

    a = getInt(">");
    op = getInt(">");
    b = getInt(">");

}