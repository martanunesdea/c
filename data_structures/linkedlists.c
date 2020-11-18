#include <stdio.h>
#include <stdlib.h>


struct node
{
    int key;
    struct node *next;
};
struct node *head, *z, *t;

void list_initialize()
{
    head = (struct node *) malloc(sizeof *head);
    z = (struct node *) malloc(sizeof *z);
    head->next = z;
    z->next = z;

}

void delete_next(struct node *t)
{
    t->next = t->next->next;
}

struct node *insert_after (int v, struct node *existing_node)
{
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof *new_node);
    new_node->key = v;
    new_node->next = existing_node->next;
    existing_node->next = new_node;
    return new_node;
}

int main(void)
{
    list_initialize();
    struct node *new_item;
    insert_after(2,  head);
}