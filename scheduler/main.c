/* 
 *      Title:  Array of functions
 *    Section:  Scheduler
 *    Summary:  Looping through array of functions
 *     Author:  Marta Nunes de Abreu
 *       Date:  01/06/2021
 *   Compiler:  clang-1103.0.32.62 
 */

#include <stdlib.h>
#include <stdio.h>

void func1(void)
{
    printf("This is func1\n");
}

void func2(void)
{
    printf("This is func2\n");
}

void start_function( void (*functionPTR)() )
{
    functionPTR();
}

int main()
{
    void (*func1_ptr)(void) = &func1; 
    start_function( func1_ptr );

    return 0;
}