/* 
 *      Title:  Traversal
 *    Section:  Graphs
 *    Summary:  BFS, DFS and some applications
 *     Author:  Marta Nunes de Abreu
 *       Date:  05/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include "traversal.h"

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
    
   // nedges += 1;
    printf("Processing edge (%d, %d) \n ", x, y);
    

   /* for detecting cycles 
    printf("processing (%d , %d )\n", x, y);

    if ( parent[x] != y ) {
       printf("Cycle from %d to %d: ", y, x);
       find_path(y, x, parent);
       printf("\n\n");
        // TODO: Change from global finished to local or element-level flag
       finished = true;       
       printf("returning... \n");
    }*/

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
    {
        return;     /* allow for search termination */
    }
    
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
        {
            printf("\nJumping out of loop with vertex %d, setting it to processed \n", v);
            // processed[v] = true;
            return;
        }
        p = (edgenode *) p->next;
    }
    dfs_process_vertex_late(v);

    time = time + 1;
    exit_time[v] = time;

    processed[v] = true;
}


int test_traversal (void )
{
    graph *g1;
    g1 = (graph *) malloc(sizeof *g1);
    bool directed = true;
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