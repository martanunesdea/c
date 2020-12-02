/* 
 *      Title:  Adjacency lists source file
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

struct adj_node {
    int dest;
    struct adj_node* next;
};

struct adj_list{
    struct adj_node *head;
};

struct graph {
    int n_vertices;
    struct adj_list* array;
};

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

// Driver program to test above functions 
void graphs_test(void) 
{ 
    // initialise graph object
    int vertices = 5; 
    struct graph* g;
    g = graph_initialize(vertices); 
    
    graph_insert_edge(g, 0, 1);
    graph_insert_edge(g, 0, 4);
    graph_insert_edge(g, 1, 2);
    graph_insert_edge(g, 1, 4);

    // print the adjacency list representation of the above graph 
    graph_print(g); 
} 