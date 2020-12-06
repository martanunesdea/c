/* 
 *      Title:  Main
 *    Section:  Searching algorithms
 *    Summary:  Basic Sequential Searching algorithm
 *     Author:  Marta Nunes de Abreu
 *       Date:  21/11/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct node {
    int key;
    int info;
    struct node *next;
};
struct node array[MAX+1];
struct node *head, *tail;
static int N;

void seq_initialize(void)
{
    N = 0;
}

int seq_search(int value)
{
    int x = N + 1;
    array[0].key = value; // sentinel record
    array[0].info = -1; // sentinel record
    while ( value != array[--x].key)
        ;
    return array[x].info;
}

void seq_insert(int value, int info)
{
    array[++N].key = value;
    array[N].info = info;
    printf("\n Inserted %d in position %d of array \n\n", info, value);
}

// Can also implement sequential search with sorted lists
void list_initialize (void)
{
    head = (struct node *) malloc(sizeof *head);
    tail = (struct node*) malloc(sizeof *tail);
    head->next = tail;
    tail->next = tail;
    tail->info = -1;
}


void list_search(int value)
{
    struct node *temp = head;
    tail->key = value;

    // this while loop assumes the list is sorted
    while ( value > temp->key )
    {
        temp = temp->next;
    }
    if ( value != temp->key )
        return tail->info;
    else 
        return temp->info;

}


void list_insert(int value, int info)
{
    struct node *x, *temp = head;
    tail->key = value;
    while ( value > temp->next->key )
        temp = temp->next;
    
    x = (struct node*) malloc(sizeof *x);
    
    x->next = temp->next;
    temp->next = x;
    x->key = value;
    x->info = info;
}

int main(void)
{
    seq_initialize();
    seq_insert(1, 2);
    seq_insert(1, 1);

    int input = 1;
    int output = seq_search(input);
    if( output == -1)
    {
        printf("Value %d not found in array\n", input);
    }
    else
    {
        printf("Info stored in value %d is: \t %d \n", input, output);
    }
    
    return 0;
}

