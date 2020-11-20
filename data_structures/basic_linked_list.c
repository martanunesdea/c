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

int delete_node(struct node *node_to_delete)
{
    struct node *temp = (struct node *)malloc(sizeof *temp);
    temp->next = head->next;
    temp->key = 0;
    // trasverse through linked list to find node
    while( temp->next != z)
    {
        if( temp->next == node_to_delete )
        {
            temp->next = temp->next->next;
        }
        temp->next = temp->next->next;
    }
    return z->key;
}

struct node *insert_after (int key_to_add, struct node *existing_node)
{
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof *new_node);
    new_node->key = key_to_add;
    new_node->next = existing_node->next; // take on existing node's pointer
    existing_node->next = new_node; // give new pointer to existing node
    return new_node;
}


int main(void)
{
    list_initialize();
    int key_to_add = 2;
    struct node *new_item = insert_after(key_to_add, head);

    if( key_to_add == new_item->key )
    {
        printf("inserted \n");
    }
    int last_key = delete_node(new_item);
    printf("reached end: %d", last_key);
}