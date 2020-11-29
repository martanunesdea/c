#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 100

struct stack {
    int stack[max+1];
    int ptr;
};

int push(struct stack *s, int v)
{
    if ( s->ptr < max )
    {
        s->ptr += 1;
        s->stack[s->ptr] = v;
        return 0;
    }
    else 
    {
        printf("\nStack full. Aborting\n");
        return 1;
    }

}

int pop(struct stack *s)
{
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

int is_stack_empty(struct stack *s)
{
    return( !(s->ptr));
}

int test_stack(struct stack *s, int n)
{
    int i = 0;
    int error = 0;
    while( i < n && error == 0)
    {
        error = push(s, i);
        if( !error)
            printf("\n inserted: %d ", i);
            i++;
    }
    return error;
}

int main(void)
{
    struct stack *s;
    stack_init(s);
    int error = 0;
    if( is_stack_empty(s) )
    {
        printf("Stack has been initiated but it's empty \n");
    }
    error = push(s, 5);
    error = push(s, 8);
    if( push(s, 8) != 0)
    {
        printf("\nError \n");
    }
    else 
    {
        printf("Popping one item: %d \n", pop(s));
    }


    if( test_stack(s, 100) == 0)
    {
        printf("\n\nTest passed\n");
    }


}