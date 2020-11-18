#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
};

static struct node *head, *tail, *top;

void stack_init()
{
    head = (struct node *) malloc(sizeof *head);
    tail = (struct node*) malloc(sizeof *tail);
    head->next = tail;
    head->key = 0;
    tail->next = tail;
}

void push(int v)
{
    top = (struct node *) malloc(sizeof *top);
    top->key = v;
    top->next = head->next;
    head->next = top;
}

int pop(void)
{
    int x;
    top = head->next;
    head->next = top->next;
    x = top->key;
    free(top);
    return x;
}

int is_stack_empty()
{
    return head->next == tail;
}

int main()
{
    stack_init();
    push(5);
    push(7);
    int n;
    n = pop();
    printf("%d \n", n);
    return 0;
}
