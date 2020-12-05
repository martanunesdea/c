/* 
 *      Title:  Header of Adjacency lists
 *    Section:  Graphs
 *    Summary:  Implementing adjacency lists
 *     Author:  Marta Nunes de Abreu
 *       Date:  29/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 

#define MAX 1000
#define TRUE 1
#define FALSE 0

bool processed[MAX+1];      /* vertices that have been processed */
bool discovered[MAX+1];     /* vertices that have been found */
int parent[MAX+1];          /* discovery relation */


struct adj_node {
    int dest;
    struct adj_node* next;
    int weight;
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
void graphs_test(void);