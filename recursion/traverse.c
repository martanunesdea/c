/* 
 *      Title:  Tree Traversal
 *    Section:  Recursion
 *    Summary:  Possible recusrive traversal of a tree
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
    y++;
    if (t != z)
    {
        traverse(t->l);
        visit(t);
        traverse(t->r);
    }
    y--;
}

int main(void)
{
    // traverse();
}