/* 
 * Implementation of methods associated with a singly linked list
 * Author: Marta
 * Date: 02/11/2020
 */
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

node *initialize_list()
{
    node *head;
    head = (struct node*) malloc(sizeof *head);
    head->item = 0;     // initialize "dummy" last node to be 0
    head->next = NULL;  // last node has a "NULL" pointer
    return head;
}

node *initialize_circular_list(node *head, node *tail)
{
    head = (struct node*) malloc(sizeof *head);
    tail = (struct node*) malloc(sizeof *tail);
    head->next = tail; // when it comes to end, head points to the tail 
    tail->next = head;
    return head;
}

void insert_node(node **head_ref, int x)
{
    node *new_node = (struct node*) malloc(sizeof *new_node);         /* temporary pointer */
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
    /* Defensive programming - check if node exists in list 
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
        previous_node = temp;   // Keep track of previous node
        temp = temp->next;      // Trasverse through list
        if( temp->next == NULL)
        {   
            // Reached the end of list
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
    printf("\n List ---------- \n");
    while (node_ref != NULL) 
    { 
        printf(" %d \n", node_ref->item); 
        node_ref = node_ref->next; 
    } 
    printf("\n");
}
