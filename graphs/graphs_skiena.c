/* Implementing Adjacency Lists as described in Skiena's
 * The Algorithm Design Manual */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

#define MAXV        1000
/* for BFS */
bool processed[MAXV+1];     /* which vertices have been processed */ 
bool discovered[MAXV+1];    /* which vertices have been found */
int parent[MAXV+1];         /* discovery relation */
int nedges;

/* for DFS */
bool finished = false;
/* DFS organises vertices by entry/exit times,
 * and edgs into tree and back edges. */
int entry_time[MAXV+1];    /* time we started discovering node */
int exit_time[MAXV+1];     /* time we finished discovering one node */
int time = 0;  

typedef struct {
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;
} graph;

void initialize_graph(graph *g, bool directed)
{
    int i;

    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    if ( directed == true) 
    {
        printf("making a directed graph \n");
    }
    nedges = 0;

    for (i = 1; i <= MAXV; i++)
    {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y, bool directed)
{
    edgenode *p;
    printf("Inserting edge between: (%d, %d)\n", x, y);
    p = (edgenode *) malloc(sizeof(*p));
    p->weight = -1;
    p->y = y;
    p->next = (struct edgenode *) g->edges[x];

    g->edges[x] = p;
    g->degree[x] += 1;

    if ( directed == false )
    {
        insert_edge(g, y, x, true);
    }
    else
    {
        g->nedges += 1;
    }
    
}

void read_graph(graph *g, bool directed)
{
    int i;
    int m;
    int x, y;

    initialize_graph(g, directed);

    scanf("%d %d", &(g->nvertices), &m);
    printf("Number of vertices: %d \n Number of edges: %d \n\n", g->nvertices, m);

    for (i = 1; i <= m; i++)
    {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

void print_graph(graph *g)
{
    int i;
    edgenode *p;

    for ( i = 1; i <= g->nvertices; i++)
    {
        printf("%d: ", i);
        p = g->edges[i];
        while ( p != NULL )
        {
            printf(" %d", p->y);
            p = (edgenode*) p->next;
        }
        printf("\n");
    }
}

void initialize_search(graph *g)
{
    int i; /* counter */
    for ( i = 1; i <= g->nvertices; i++ )
    {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}

void process_vertex_early( int v)
{
    // something here 
    printf("Processing vertex early: %d \n", v);
    // printf(" %d", v); for connected components 
}

void process_edge(int x, int y)
{
    // something here 
    nedges += 1;
    printf("Processing edge (%d, %d) \t\t Current edge count: %d\n", x, y, nedges);
}

void process_vertex_late( int v )
{
    printf("Processing vertex %d \n", v);
    // empty
}

void bfs(graph *g, int start)
{
    struct queue q;
    int v;
    int y;
    edgenode *p;

    queue_initialize(&q);
    queue_put(&q, start);
    discovered[start] = true;

    while ( queue_empty(&q) == false )
    {

        v = queue_get(&q);
        process_vertex_early(v);
        p = g->edges[v];

        while ( p != NULL )
        {
            y = p->y;
            
            if ( (g->directed) || (processed[y] == false) )
            {
                process_edge(v, y);
            }
            if ( discovered[y] == false )
            {
                queue_put(&q, y);
                discovered[y] = true;
                parent[y] = v;
                // printf("Marking %d as discovered \t With parent %d \n", y, v);
            }
            // assumes all nodes in graph are connected
            // printf("Moving on to next connected vertex \n");
            p = (edgenode *) p->next; 
        }
        process_vertex_late(v);
        processed[v] = true;

    }
}


void find_path(int start, int end, int parents[])
{
    if ( (start == end) || (end == -1) )
        printf("\n %d", start);
    else {
        find_path(start, parents[end], parents);
        printf( " %d", end);
    }
    printf("\t");
}

void connected_components( graph *g )
{
    int c;
    int i; 

    initialize_search(g);

    c = 0;
    for ( i = 1; i <= g->nedges; i++ )  // edited: from nvertices to nedges 
    {
        if ( discovered[i] == false )
        {
            c += 1;
            printf("Component %d: ", c);
            bfs(g, i);
            printf("\n");
        }
    }
}

void dfs_process_edge(int x, int y)
{
    // something here 
    nedges += 1;
    printf("Processing edge (%d, %d) \t\t Current edge count: %d\n", x, y, nedges);
}
void dfs_process_vertex_early( int v)
{
    // something here 
    printf("Processing vertex early: %d \n", v);
    // printf(" %d", v); for connected components 
}

void dfs_process_vertex_late( int v )
{
    // empty
}

void dfs( graph *g, int v)
{
    edgenode *p;
    int y;
    
    if ( finished ) 
        return;     /* allow for search termination */
    
    discovered[v] = true;
    time = time + 1;
    entry_time[v] = time;

    dfs_process_vertex_early(v);

    p = g->edges[v];
    while ( p != NULL )
    {
        y = p->y;

        if ( discovered[y] == false )
        {
            parent[y] = v;
            // dfs_process_edge(v, y); // this was duplicating how edges were processed
            dfs(g, y);
        }
        if ( (processed[y] == false) || (g->directed) )
        {
            dfs_process_edge(v, y);
        }
        if ( finished ) 
            // this value doesn't get attributed, inspect potential unintended behaviour
            return;
        
        p = (edgenode *) p->next;
    }

    dfs_process_vertex_late(v);

    time = time + 1;
    exit_time[v] = time;

    processed[v] = true;
}



int main(void)
{
    graph *g1;
    g1 = (graph *) malloc(sizeof *g1);
    bool directed = false;
    printf("\n\n Reading in graph elements: \n");
    initialize_graph(g1, directed);
    read_graph(g1, directed);

    printf("\n\n Printing graph \n");
    print_graph(g1);

   
 /*   printf("\n\n Trasversing with BFS \n");
    bfs(g1, 1);

    printf("\n\n Finding path\n");
    find_path(1, 9, parent); 
    */


 //   connected_components(g1); 
     printf("\n\n Trasversing with DFS \n");
    dfs(g1, 1);  
    return 0;
}