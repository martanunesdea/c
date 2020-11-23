/* 
 * Implementing a BST
 * Author: Marta
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
    int item;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

void insert(tree **l, int x, tree *parent)
{
    tree *p;        // temporary pointer

    if (*l == NULL)
    {
        p = malloc(sizeof(tree)); // allocate new node
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;     // link into parent's record
        return;
    }

    if (x < (*l)->item)
        insert( &((*l)->left), x, *l);
    else
        insert( &((*l)->right), x, *l);    
}

struct tree *search_tree(tree *l, int key)
{
    if (l == NULL)
        return NULL;
    
    if (l->item == key)
        return(l);
    
    if (key < l->item)
        return( search_tree(l->left, key) );
    else
        return ( search_tree(l->right, key));   
}

struct tree *find_minimum(tree *t)
{
    tree *min; // pointer to minimum
    
    if (t == NULL)
        return NULL;
    
    min = t;
    // exclude the right-most elements as these larger than the item in t
    while (min->left != NULL)
        min = min->left;

    return(min);
}

void process_item(int x)
{
    printf(" %d \n", x);
}

void traverse_tree(tree *l)
{
    if (l != NULL)
    {
        traverse_tree(l->left);
        process_item(l->item);
        traverse_tree(l->right);
    }
}


int main(void)
{
    struct tree *my_tree;
    my_tree = (struct tree*) malloc(sizeof *my_tree);
    my_tree->item = 2;

    insert(&my_tree, 1, my_tree);
    struct tree *to_find = search_tree(my_tree, 1);
    printf("item is: %d\n", to_find->item);

    insert(&my_tree, 3, my_tree);

    struct tree *max_item = search_tree(my_tree, 3);
    insert(&my_tree, 4, max_item);

    printf("\n Tree ---- \n");
    traverse_tree(my_tree);
}