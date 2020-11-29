/* 
 *      Title:  Stack header file
 *    Section:  Array-based data structures
 *    Summary:  Implementing FIFO operations of stack
 *     Author:  Marta Nunes de Abreu
 *       Date:  19/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 100

struct stack {
    int stack[max+1];
    int ptr;
};

int is_stack_empty(struct stack *s);
int is_stack_full(struct stack *s);
int push(struct stack *s, int v);
int pop(struct stack *s);
void stack_init(struct stack *s);
int test_stack_empty(struct stack *s);
int test_stack_push(struct stack *s, int n);
int test_stack_pop(struct stack *s, int n);