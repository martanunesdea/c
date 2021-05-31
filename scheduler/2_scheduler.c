/* 
 *      Title:  Array of functions
 *    Section:  Scheduler
 *    Summary:  Looping through array of functions
 *     Author:  Marta Nunes de Abreu
 *       Date:  01/06/2021
 *   Compiler:  clang-1103.0.32.62 
 */

#include <stdlib.h>
#include <stdio.h>

#define NUMBER_OF_FUNCTIONS 10

void (*ready_tasks[NUMBER_OF_FUNCTIONS])(void *p);
void (*halted_tasks[NUMBER_OF_FUNCTIONS])(void *p);
void (*waiting_tasks[NUMBER_OF_FUNCTIONS])(void *p);

int delays[NUMBER_OF_FUNCTIONS];

static int task_index = 0;
static int global_err = 0;
static int halted_task_index = 0;
static int waiting_task_index = 0;


void start_function( void (*functionPTR)() )
{
    functionPTR();
}

void remove_current_task(char *str)
{
    // for now, check if halted tasks is working;
    printf("%s", str);
    for (int temp_count = task_index; temp_count < NUMBER_OF_FUNCTIONS; temp_count++)
    {
        if ( ready_tasks[temp_count+1] != NULL )
        {
            ready_tasks[temp_count] = ready_tasks[temp_count+1];
        }
        else
        {
            ready_tasks[temp_count] = NULL;
            temp_count = NUMBER_OF_FUNCTIONS;
        }
    }
    // Update task index so that new function doesn't get skipped
    task_index -= 1;
}

void halt_function( void )
{
    // Copy the function pointer from ready tasks to halted tasks
    halted_tasks[halted_task_index] = ready_tasks[task_index];
    halted_task_index += 1;
    // Remove halted task from ready tasks list
    remove_current_task("halting\n");
}

void sleep_function( int d )
{
    // 1. Copy the function pointer from ready_tasks to waiting_tasks
    waiting_tasks[waiting_task_index] = ready_tasks[task_index];
    // 2. Copy the sleep interval into the delays array with same index as function pointer
    delays[waiting_task_index] = d;
    // Update waiting task index
    waiting_task_index += 1;
    // 3. Clean up ready_tasks
    remove_current_task("sleeping\n");
}


void task0(void *p)
{
    printf("This is task 0\n");
}

void task1(void *p)
{
    printf("This is task 1\n");
    sleep_function(2);
    return;
}

void task2(void *p)
{
    printf("This is task 2\n");
}

void task3(void *p)
{
    printf("This is task 3\n");
}
void task4(void *p)
{
    printf("This is task 4\n");
}
void task5(void *p)
{
    printf("This is task 5\n");
    halt_function();
}

void add_function_to_ready(int wait_index)
{
    printf("Function is now ready...\n");
    int temp_index = task_index;
    while (ready_tasks[temp_index] != NULL)
    {
        temp_index++;
    }
    ready_tasks[temp_index] = waiting_tasks[wait_index];
    ready_tasks[temp_index+1] = NULL;
}

void remove_function_from_waiting(int wait_index)
{
    for(int i = wait_index; i < NUMBER_OF_FUNCTIONS; i++)
    {
        if ( waiting_tasks[i+1] != NULL )
        {
            waiting_tasks[i] = waiting_tasks[i+1];
        }
        else
        {
            waiting_tasks[i] = NULL;
            i = NUMBER_OF_FUNCTIONS;
        }
    }
    waiting_task_index -= 1;
}

void scheduler(void)
{
    if (ready_tasks[task_index] == NULL  && (task_index != 0) )
    {
        task_index = 0;
    }
    if (ready_tasks[task_index] == NULL && task_index == 0)
    {
        printf("No tasks, quitting\n");
        global_err = 1;
        return;
    }
    start_function(ready_tasks[task_index]);
    task_index++;

    int wait_index = 0;
    while( waiting_tasks[wait_index] != NULL )
    {
        delays[wait_index] -= 1;
        if (delays[wait_index] == 0)
        {
            add_function_to_ready(wait_index);
            remove_function_from_waiting(wait_index);
        }
        wait_index += 1;
    }
    return;
}

void initialize_lists(void)
{
    // fill task lists with NULL
    for (int i = 0; i < NUMBER_OF_FUNCTIONS; i++)
    {
        waiting_tasks[i] = NULL;
        halted_tasks[i] = NULL;
        ready_tasks[i] = NULL;
    }
}


int main()
{
    /*
    void (*func1_ptr)(void) = &func1; 
    start_function( func1_ptr );
    */ 

    initialize_lists();

    ready_tasks[0] = &task0;
    ready_tasks[1] = &task1;
    ready_tasks[2] = &task2;
    ready_tasks[3] = &task3;
    ready_tasks[4] = &task4;
    ready_tasks[5] = &task5;


    for (int i = 0; i < 15; i++)
    {
        if (!global_err) scheduler();
    }

    return 0;
}