/* 
 *      Title:  Header of Breadth First Search
 *    Section:  Graphs
 *    Summary:  Implementing BFS with unweighted graphs
 *     Author:  Marta Nunes de Abreu
 *       Date:  21/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 

#define MAX    1000

/* for BFS */
bool processed[MAX+1];      /* vertices that have been processed */
bool discovered[MAX+1];     /* vertices that have been found */
int parent[MAX+1];          /* discovery relation */


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

struct adj_node* graph_create_new_adj_node(int dest);
struct graph* graph_initialize(int n_vertices);
void graph_insert_edge(struct graph* g, int src, int dest);
void graph_print(struct graph* g);
void initialize_search(struct graph *g);
void process_vertex_late( int v );
void process_vertex_early(int v);
void process_edge(int x, int y);
void connected_components(struct graph *g);
void process_vertex_early(int v);
void process_edge(int x, int y);
void bfs(struct graph *g, int start);