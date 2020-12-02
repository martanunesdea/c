
/* 
 *      Title:  Union find
 *    Section:  Graphs
 *    Summary:  Data structure for finding membership in a set
 *     Author:  Marta Nunes de Abreu
 *       Date:  02/12/2020
 *   Compiler:  clang-1103.0.32.62 
 */

#define SET_SIZE 100

struct set_union {
    int parent[SET_SIZE+1]; // parent element
    int size[SET_SIZE+1];   // number of elements in subtree i
    int n;                  // number of elements in set
};


void set_union_initialize(struct set_union *s, int n)
{
    for( int i = 0; i <= n; i++ )
    {
        s->parent[i] = i;
        s->size[i] = 1;
    }

    s->n = n;
}

// find: find the root of tree containing element i
// by walking up the parent pointers until nothing's left
// return to label of the root
int find(struct set_union *s, int x)
{
    if ( s->parent[x] == x )
        return (x);
    else
        return( find(s, s->parent[x]) );
    
}

int union_sets(struct set_union *s, int x)
{
    int r1 = find(s, s1);
    int r2 = find(s, s2);

    if ( r1 == r2) 
        return;
    
    if ( s->size[r1] >= s->size[r2] )
    {
        s->size[r1] = s->size[r1] + s->size[r2];
        s->parent[r2] = r1;
    }
    else
    {
        s->size[r2] = s->size[r1] + s->size[r2];
        s->parent[r1] = r2;
    }
    
}

bool same_component(struct set_union *s, int s1, int s2)
{
    return ( find(s, s1) == find(s, s2) );
}