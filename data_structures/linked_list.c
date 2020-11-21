#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int item;
    struct node *next;
} node;

node *initialize_list()
{
    node *head;
    head = (struct node*) malloc(sizeof head);
    head->item = 0;
    head->next = NULL;

    return head;
}

void insert_node(node **head_ref, int x)
{
    node *new_node = (struct node*) malloc(sizeof new_node);         /* temporary pointer */
    new_node->item = x;     /* initialise new node with an "item" */
    new_node->next = *head_ref;    /* initialise new node with a "next" pointer */
    *head_ref = new_node;          /* head now points to newly added item */
}

struct node *insert_after_node(struct node *t, int x)
{
    struct node *to_add;
    to_add = (struct node*) malloc(sizeof *to_add);
    to_add->item = x;
    to_add->next = t->next;
    t->next = to_add;
    return to_add;
}

struct node *search_list_recursively(node *l, int x)
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

struct node *search_list_iteratively(node *l, int x)
{
    while( l->item != x)
    {
        if (l->next == NULL)
        {  
            printf("Error: predecessor sought on null list.\n");
            return(NULL);
        }
        l = l->next;
    }
    return l;
}

void delete_node(node **l, int x)
{
    /* defensive programming - check if node exists in list 
    node node_to_delete = search_list_iteratively(*l, x);
    if (node_to_delete == NULL)
    {
        printf("Error: Node not present in list");
    } */

    node *previous_node;
    node *temp = *l;

    // Check if node to delete is the head node
    if( temp != NULL && temp->item == x)
    {
        *l = temp->next;
        free(temp);
        return;
    }

    while( temp != NULL && temp->item != x)
    {
        previous_node = temp;
        temp = temp->next;
        if( temp->next == NULL)
        {
            printf("Error: Node not found in list.\n");
            return;
        }
    }   
    // Replace node to delete with the node next to it
    previous_node->next = temp->next; 
  
    free(temp);  // Free memory 
}

void print_list(node *node_ref)
{
    printf("\nList ---------- \n");
    while (node_ref != NULL) 
    { 
        printf(" %d \n", node_ref->item); 
        node_ref = node_ref->next; 
    } 
    printf("\n");
}

int main(void)
{
    node *list = initialize_list();
    
    insert_node(&list, 1);
    insert_node(&list, 2);
    insert_node(&list, 3);
    insert_node(&list, 4);
    print_list(list);

   // node *to_find = search_list_iteratively(list, 2);
   // printf("node next to 2: %d", to_find->next->item);

    //node *temp = get_previous_node(list, 2);
    //printf("node previous to 2 is %d", temp->item);

    delete_node(&list, 2);
    print_list(list);

    delete_node(&list, 4);
    print_list(list);

    node *previous_node = search_list_iteratively(list, 3);
    node *new_node = insert_after_node(previous_node, 10);
    print_list(list);

}