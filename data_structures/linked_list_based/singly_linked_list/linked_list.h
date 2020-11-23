/* 
 * Header file of source file linked_list.c
 * Author: Marta
 * Date: 02/11/2020
 */
typedef struct node {
    int item;
    struct node *next;
} node;

node *initialize_list();
void insert_node(node **head_ref, int x);
struct node *insert_after_node(struct node *t, int x);
struct node *search_list_recursively(node *l, int x);
struct node *search_list_iteratively(node *l, int x);
void delete_node(node **l, int x);
void print_list(node *node_ref);