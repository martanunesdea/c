#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int item;
    struct node *next;
} node;

node *search_list_recursively(node *l, int x)
{
    if (l == NULL)
        return(NULL);
    if (l->item == x)
    {
        return(l);
    }
    else
    {
        return( search_list_recursively(l->next, x) );   
    }
}

node *search_list_iteratively(node *l, int x)
{
    while( l->item != x)
    {
        if (l->next == NULL)
        {  
            printf("Error: predecessor sought on null list.\n");
            return(NULL);
        }
        printf("item: %d", l->item);
        l = l->next;
    }
    printf("found %d", l->item);
    return l;
}

void insert_node(node **l, int x)
{
    node *temp;         /* temporary pointer */
    temp = (struct node*) malloc(sizeof temp);
    temp->item = x;     /* initialise new node with an "item" */
    temp->next = *l;    /* initialise new node with a "next" pointer */
    *l = temp;          /* head now points to newly added item */
}

node *get_previous_node(node *l, int x)
{
    if( l->item == x)
    {
        return l;
    }

    while( (l->next)->item != x)
    {
        l = l->next;
        if( l->next == NULL)
        {
            printf("Error: predecessor sought on null list.\n");
            return(NULL);
        }
    }   
    return l;
}

void delete_list(node **l, int x)
{
    node *p; 
    node *previous_node;
    node *search_list_iteratively(), *get_previous_node();

    p = search_list_iteratively(*l, x);

    printf("Found node %d\n", p->item);
    if (p != NULL)
    {
        previous_node = get_previous_node(*l, x);
        if( previous_node == NULL)
        {
            /* node to delete is in HEAD */
            *l = p->next;
        }
        else
        {
            printf("Deleting node %d \n", p->item);
            previous_node->next = p->next; // doesn't get saved to list so it's wrong
        }
        free(p);
    }
    else
    {
        printf("Error: Couldn't find node \n");
    }
    

}

node *initialize_list()
{
    node *head;
    head = (struct node*) malloc(sizeof head);
    head->item = 0;
    head->next = NULL;

    return head;
}

int main(void)
{
    node *list = initialize_list();
    
    printf("List holds %d \n", list->item);

    insert_node(&list, 2);
    printf("List holds %d \n", list->item);

    insert_node(&list, 4);
    printf("List holds %d \n", list->item);

    insert_node(&list, 3);
    printf("List holds %d \n", list->item);

    search_list_iteratively(list, 2);

    node *temp = get_previous_node(list, 4);
    printf("Node previous to 4 is %d \n", temp->item);

    //delete_list(&head, 4);
    //search_list_iteratively(head, 2);    
    delete_list(&list, 3);
    delete_list(&list, 4);
    delete_list(&list, 2);
    //search_list_iteratively(list, 4);   

    //delete_list(&list, 3);

}