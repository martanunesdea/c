/* 
 *      Title:  Graphs as per Sedgewick's book
 *    Section:  Graphs
 *    Summary:  Adjacency matrix and lists
 *     Author:  Marta Nunes de Abreu
 *       Date:  05/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>

#define MAXV 50

int V, E;
int a[MAXV][MAXV];


void print_graph(int arr[MAXV][MAXV])
{
    for (int x = 1; x <= V; x++)
    {
        for( int y = 1; y <= V; y++)
        {
            printf(" %d ", arr[x][y]);
        }
        printf("\n");
    }
}

void adj_matrix(void)
{
    int x, y;
    int v1, v2;

    scanf("%d %d", &V, &E);
    printf("Got dimensions: %d %d \n\n", V, E);

    /* initialise matrix elements with 1 */
    for (int x = 1; x <= V; x++)
    {
        for( int y = 1; y <= V; y++)
        {
            a[x][y] = 0;
        }
        a[x][x] = 1;
    }

    /* scan in edges */
    for ( int j = 1; j <= E; j++)
    {
        scanf("%d %d", &v1, &v2);
        x = v1;
        y = v2;
        a[x][y] = 1;
        a[y][x] = 1;
        printf("Entered in graph: (%d,%d) \t (%d,%d)\n", x, y, y, x);
    }

    print_graph(a);    
}

struct node
{
    int v;
    struct node *next;
};

void adj_list(void)
{
    int V, E;
    scanf("%d %d", &V, &E);
    printf("\n Got dimensions: %d and number of edges %d \n", V, E);

    struct node *z, *t;
    z = (struct node *) malloc(sizeof *z);
    z->next = z;

    struct node *adj[MAXV];

    /* initialize lists within grah */
    for( int j = 1; j <= V; j++)
    {
        adj[j] = z;
    }

    int v1, v2; // new vertices creating edges
    /* filling in lists */ 
    for(int j = 1; j <= E; j++)
    {
        scanf("%d %d", &v1, &v2);
        t = (struct node *) malloc(sizeof *t);
        t->v = v1; 
        t->next = adj[v2];
        adj[v2] = t;
        printf("1 Created vertex %d in position %d \n", adj[v2]->v, v2);

        // undirected: add another edge
        t = (struct node *) malloc(sizeof *t);
        t->v = v2;
        t->next = adj[v1];
        adj[v1] = t;
        printf("2 Created vertex %d in position %d \n\n", adj[v1]->v, v1);

    }

}

int main(void) 
{
   // adj_matrix();
    adj_list();
    return 0;
}