/* 
 *      Title:  Stack source file
 *    Section:  Array-based data structures
 *    Summary:  Implementing LIFO operations of stack
 *     Author:  Marta Nunes de Abreu
 *       Date:  19/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

int stack_empty(struct stack *s)
{
    return( !(s->ptr));
}

int stack_full(struct stack *s)
{
    return( (s->ptr) == max);
}

int stack_push(struct stack *s, int v)
{
    if ( !stack_full(s) )
    {
        s->ptr += 1;
        s->stack[s->ptr] = v;
        return 0;
    }
    else 
    {
        printf("\nError: Stack full. Aborting.\n");
        return 1;
    }

}

int stack_pop(struct stack *s)
{
    // check pointer is within bounds
    if ( stack_empty(s) )
    {
        printf("\nError: Reached end of stack.\n");
        return (-1);
    }

    // retrieve item at the top
    int value = s->stack[s->ptr];
    // subtract pointer
    s->ptr -= 1;

    return value;
}

void stack_initialiase(struct stack *s)
{
    // set contents of stack to 0
    memset(s, 0, sizeof(struct stack));
    // set pointer of stack to 0;
    s->ptr = 0;
}

int test_stack_empty(struct stack *s)
{
    if( stack_empty(s) == 1)
    {
        return OK;
    }
    else
    {
        return NOK;
    }
    
}

int test_stack_push(struct stack *s, int item_total)
{
    int i = 0;
    int error = 0;
    for( int i = 0; i < item_total; i++)
    {
        error = stack_push(s, i);
        if (error)
            return NOK;
    }
    return OK;
}

int test_stack_pop(struct stack *s, int n)
{
    int i;
    int error = 0;
    for (int i = 0; i < n; i++)
    {
        error = stack_pop(s);
        if ( error == (-1))
        {
            return NOK;
        }
    }
    return OK;
}

int main(void)
{
    struct stack *s;
    /* defining test inputs */
    int items_to_push = 2;            /* set to max+1 to test for overflow  */
    int items_to_pop = items_to_push; /* add 1 to test for overflow         */

    stack_initialiase(s);
    if (s == NULL)
    {
        printf("\nError: Stack is null\n");
    }
    else
    {
        printf("\nStack initialised\n");
    }

    if( test_stack_empty(s) == OK )
    {
        printf("\nPassed test: Empty stack\n");
    }

    if( test_stack_push(s, items_to_push) == OK)
    {
        printf("\nPassed test: Stack push\n");
    }
    if( test_stack_pop(s, items_to_pop) == OK)
    {
        printf("\nPassed test: Stack pop \n");
    }
}