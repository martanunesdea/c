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
#include "queue.h"
#include "bfs.h"

#define MAX 1000
#define TRUE 1
#define FALSE 0

/* for BFS */
bool processed[MAX+1];      /* vertices that have been processed */
bool discovered[MAX+1];     /* vertices that have been found */
int parent[MAX+1];          /* discovery relation */


/* a typical graph format consists of an initial line featuring
 * the number of vertices and edges in the graph
 * followed by a listing of the edges at one vertex per line */

struct adj_node* graph_create_new_adj_node(int dest)
{
    struct adj_node* new_node = (struct adj_node*)malloc(sizeof(struct adj_node));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

struct graph* graph_initialize(int n_vertices)
{
    struct graph* g = (struct graph*) malloc(sizeof(struct graph));
    g->n_vertices = n_vertices;
    g->array = (struct adj_list*) malloc(n_vertices * sizeof(struct adj_list));

    // initialise each list as empty
    for (int i = 0; i < n_vertices; i++)
    {
        g->array[i].head = NULL;
    }
    return g;
}

void graph_insert_edge(struct graph* g, int src, int dest) 
{ 
    // Initialise new node and set adjacency to current head 
    struct adj_node* new_node = graph_create_new_adj_node(dest); 
    new_node->next = g->array[src].head; 
    g->array[src].head = new_node; 
  
    // Undirected graph: add edge from dest to src 
    new_node = graph_create_new_adj_node(src); 
    new_node->next = g->array[dest].head; 
    g->array[dest].head = new_node; 
} 
 
void graph_print(struct graph* g) 
{ 
    int v; 
    for (v = 0; v < g->n_vertices; ++v) 
    { 
        struct adj_node* p = g->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (p) 
        { 
            printf("-> %d", p->dest); 
            p = p->next; 
        } 
        printf("\n"); 
    } 
}


void initialize_search(struct graph *g)
{
    for (int i = 0; i <= g->n_vertices; i++)
    {
        processed[i] = discovered[i] = FALSE;
        parent[i] = -1;
    }
    printf("initialized search\n");
}

/* through the processs functions, can customize what the traversal does 
 * as it makes its official visit to each edge and each vertex */


void process_vertex_late( int v )
{
    // returns without action, since all processing done early on
}

void process_vertex_early(int v)
{
    printf("1. Discovering vertex %d \n", v);
}


void process_edge(int x, int y)
{
    printf("2. Processing adjacent vertex: %d \n", y);
    printf("3. Processed edge (%d, %d) \n", x, y);
    // nedges += 1; // get accurate count of number of edges
}


void connected_components(struct graph *g)
{
    initialize_search(g);
    int c = 0;
    for (int i = 0; i <= g->n_vertices; i++)
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

/* for connected components we would need helper functions  
void process_vertex_early(int v)
{
    printf(" %d \n", v);
}

void process_edge(int x, int y)
{
    // deliberately empty
}*/

/* add two-color solution here */

void bfs(struct graph *g, int start)
{
    struct queue q;
    int current_vertex;
    int next_vertex;
    struct adj_node *p;

    initialize_search(g);
    queue_initialize(&q);
    queue_put(&q, start);
    discovered[start] = TRUE;

    while( !queue_empty(&q) )
    {
        current_vertex = queue_get(&q);
        process_vertex_early(current_vertex);
        processed[current_vertex] = TRUE;

        p = g->array[current_vertex].head;

        while ( p != NULL )
        {

            next_vertex = p->dest;

            if ( (processed[next_vertex]) == FALSE )
            {
                process_edge(current_vertex, next_vertex);
            }
            if( (discovered[next_vertex]) == FALSE) 
            {
                queue_put(&q, next_vertex);
                discovered[next_vertex] = TRUE;
                parent[next_vertex] = current_vertex; 
            }
            if ( p->next == NULL )
            {
                break;
            }
            else 
            {
                p = p->next;
            }
            printf("\t New adjacent vertex is %d \n", p->dest);

        }
        printf("\n \n");
        process_vertex_late(current_vertex);
    }
}

int main(void)
{   struct graph *g;
    g = (struct graph*) malloc(sizeof *g);

    // initialise graph object
    int vertices = 5; 
    g = graph_initialize(vertices); 
    
    graph_insert_edge(g, 0, 1);
    graph_insert_edge(g, 0, 4);
    graph_insert_edge(g, 1, 2);
    graph_insert_edge(g, 1, 4);

    // print the adjacency list representation of the above graph 
    graph_print(g); 
  
    printf("\n\n breadth first search: \n\n");
    bfs(g, 1);


    return 0; 


}