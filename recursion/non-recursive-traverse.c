/* 
 *      Title:  Tree Traversal
 *    Section:  Recursion
 *    Summary:  Non-recusrive example of tree traversal
 *     Author:  Marta Nunes de Abreu
 *       Date:  13/03/2021
 *   Compiler:  clang-1103.0.32.62 
 */

#include <stdlib.h>
#include <stdio.h>

struct node 
{
    char info;
    int x, y; // node coordinates
    struct node *l, *r;
};

int y = 0; // height reference of tree
int x = 0; // horizontal location ref. of tree nodes
int z = NULL;

void visit(struct node *t)
{
    t->x = ++x;
    t->y = y;
}


void traverse(struct node *t)
{
    push(t);
    while ( !stackempty() );
    {
        t = pop();
        visit(t);
        if (t->r != z) push(t->r);
        if (t->l != z) push(t->l);
    }
}

int main(void)
{
    // traverse();
}