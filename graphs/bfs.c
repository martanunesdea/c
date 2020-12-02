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

/* for connected components we would need different helper functions  
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
{   
    struct graph *g;
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