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
#define max 100

int is_stack_empty(struct stack *s)
{
    return( !(s->ptr));
}

int is_stack_full(struct stack *s)
{
    return( (s->ptr) == max);
}

int push(struct stack *s, int v)
{
    if ( !is_stack_full(s) )
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

int pop(struct stack *s)
{
    // check pointer is within bounds
    if ( is_stack_empty(s) )
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

void stack_init(struct stack *s)
{
    // set contents of stack to 0
    memset(s, 0, sizeof(struct stack));
    // set pointer of stack to 0;
    s->ptr = 0;
}

int test_stack_empty(struct stack *s)
{
    if( is_stack_empty(s) == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}

int test_stack_push(struct stack *s, int item_total)
{
    int i = 0;
    int error = 0;
    while( i < item_total && error == 0)
    {
        error = push(s, i);
        if( !error)
            i++;
    }
    return error;
}

int test_stack_pop(struct stack *s, int n)
{
    int i;
    int error = 0;
    for (int i = 0; i < n; i++)
    {
        error = pop(s);
        if ( error == (-1))
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    struct stack *s;
    stack_init(s);

    if (s == NULL)
    {
        printf("\nError: Stack is null\n");
    }
    else
    {
        printf("\nStack initialised\n");
    }

    if( test_stack_empty(s) == 0 )
    {
        printf("\nPassed test: Empty stack\n");
    }

    int items_to_push = 2;            // set to max+1 to test for overflow
    int items_to_pop = items_to_push; // add 1 to test for overflow

    if( test_stack_push(s, items_to_push) == 0)
    {
        printf("\nPassed test: Stack push\n");
    }
    if( test_stack_pop(s, items_to_pop) == 0)
    {
        printf("\nPassed test: Stack pop \n");
    }


}