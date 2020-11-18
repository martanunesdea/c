/*
Title: Queues
Description: Restricted-access data structure with 
two basic operations: insert an item, remove an item.
Items get processed in the order received (First-In First-Out)
*/

#define max 100
static int queue[max+1], head, tail;

void put(int new_value)
{
    queue[tail++] = new_value;
    if (tail > max)
    {
        // reset queue
        tail = 0;
    }
}
int get(void)
{
    int top = queue[head++];
    if (head > max)
    {
        // reset queue
        head = 0;
    }
    return top;
}
void queue_init(void)
{
    head = 0;
    tail = 0;
}
int is_queue_empty(void)
{
    return head == tail;
}