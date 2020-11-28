/* 
 *      Title:  Main
 *    Section:  Graphs
 *    Summary:  Implementing adjacency lists
 *     Author:  Marta Nunes de Abreu
 *       Date:  21/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */

/* For each graph, we keep a count of the number of vertices
 * and assign each vertex a unique ID number from 1 to nvertices
 * Represent edges using array of linked lists */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 

#define MAX 1000
#define TRUE 1
#define FALSE 0

/* for BFS */
bool processed[MAX+1];      /* vertices that have been processed */
bool discovered[MAX+1];     /* vertices that have been found */
int parent[MAX+1];          /* discovery relation */

typedef struct {
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct {
    struct edgenode *edges[MAX+1];
    int degree[MAX+1];
    int nvertices;
    int nedges;
    bool directed;
} graph;


/* a typical graph format consists of an initial line featuring
 * the number of vertices and edges in the graph
 * followed by a listing of the edges at one vertex per line */
void initialize_graph(graph *g, bool directed)
{
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    for( int i = 0; i <= MAX; i++)
    {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int vertex, int edge, bool directed)
{
    edgenode *p;
    p = malloc(sizeof(edgenode));
    p->weight = 0;
    p->y = edge;
    p->next = g->edges[vertex];

    g->edges[vertex] = p; /* insert at head of list */
    g->degree[vertex] += 1;

    if (directed == FALSE)
    {
        insert_edge(g, vertex, edge, TRUE);
    }
    else
    {
        g->nedges += 1;
    }
}

void read_graph(graph *g, bool directed)
{
    int n_edges, vertex, edge;

    initialize_graph(g, directed);
    printf("\n insert vertex and edge > ");
    scanf(" %d %d \n", &(g->nvertices), &n_edges);

    for(int i = 0; i <= n_edges; i++)
    {
        scanf("%d %d", &vertex, &edge);
        insert_edge(g, vertex, edge, directed);
    }

}

void print_graph( graph *g)
{
    edgenode *p;
    
    for( int i = 0; i <= g->nvertices; i++)
    {
        printf(" %d: ", i);
        p = g->edges[i];
        while( p != NULL)
        {
            printf(" %d", p->y);
            p = p->next;
        }
        printf("\n");
    }
}


void initialize_search(graph *g)
{
    for (int i = 0; i <= g->nvertices; i++)
    {
        processed[i] = discovered[i] = FALSE;
        parent[i] = -1;
    }
}

/* through the processs functions, can customize what the traversal does 
 * as it makes its official visit to each edge and each vertex */


void process_vertex_late( int v )
{
    // returns without action, since all processing done early on
}

void process_vertex_early(int v)
{
    printf("processed vertex %d \n", v);
}

void process_edge(int x, int y)
{
    printf("processed edge (%d, %d) \n", x, y);
    nedges += 1; // get accurate count of number of edges
}


void connected_components(graph *g)
{
    initialize_search(g);
    int c = 0;
    for (int i = 0; i <= g->nvertices; i++)
    {
        if( discovered[i] == FALSE)
        {
            c += 1;
            printf("Component %d:", c);
            bfs(g, i);
            printf("\n");
        }
    }
}

/* for connected components we would need helper functions */ 
void process_vertex_early(int v)
{
    printf(" %d \n", v);
}

void process_edge(int x, int y)
{
    // deliberately empty
}

/* add two-color solution here */

void bfs(graph *g, int start)
{
    queue q;
    int current_vertex;
    int next_vertex;
    edgenode *p;

    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = TRUE;

    while( !empty_queue(&q) )
    {
        current_vertex = dequeue(&q);
        process_vertex_early(current_vertex);
        processed[current_vertex] = TRUE;
        p = g->edges[current_vertex];
        while ( p != NULL )
        {
            next_vertex = p->y;
            if ( (processed[next_vertex] == FALSE) 
                || g->directed )
            {
                process_edge(current_vertex, next_vertex);
            }
            if( discovered[next_vertex] == FALSE) {
                enqueue(&q, next_vertex);
                discovered[next_vertex] = TRUE;
                parent[next_vertex] = current_vertex; 
            }
            p = p->next;
        }
        process_vertex_late(current_vertex);
    }
}

int main(void)
{   graph *g;
    g = (struct graph*) malloc(sizeof *g);
    bool directed = TRUE;

    read_graph(g, directed);
}