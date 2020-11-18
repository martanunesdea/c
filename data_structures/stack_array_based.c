#include <stdlib.h>
#include <stdio.h>
#define max 100

static int stack[max+1], p;

void push (int v)
{
    stack[p++] = v;
}

int pop(void)
{
    return stack[--p];
}

void stack_init(void)
{
    p = 0;
}

int is_stack_emtpy(void)
{
    return !p;
}

int main(void)
{
    stack_init();
    push(5);
    int d = pop();
    printf("%d \n", d);
    push(7);
    push(8);
}