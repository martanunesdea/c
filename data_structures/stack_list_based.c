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
    char c;
    int x;
    for( stack_init(); scanf("%1s", &c) != EOF; )
    {
        x = 0;
        if ( c == '+')
        {
            x = pop()+pop();
        }
        if ( c == '*')
        {
            x = pop()*pop();
        }
        while ( c >= '0' && c <= '9')
        {
            x = 10*x + (c-'0');
            scanf("%1c", &c);
        }
        push(x);
    }
    printf("%d\n", x);
    return 0;
}
