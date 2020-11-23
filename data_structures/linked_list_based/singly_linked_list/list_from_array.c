#include <stdio.h>
#include <stdlib.h>

#define max 30

int key[max+2];
int next[max+2];
int x, head, z;

void list_initialize()
{
    int head = 0;
    int z = 1;
    int x = 2;
    next[head] = z;
    next[z] = z;
}

void delete_next(int t)
{
    next[t] = next[next[t]];
}

int insert_after(int v, int t)
{
    key[x] = v;
    next[x] = next[t];
    next[t] = x;
    return x++;
}

int main(void)
{
    list_initialize();

}