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

static int task_index = 0;
static int global_err = 0;
static int halted_task_index = 0;


void start_function( void (*functionPTR)() )
{
    functionPTR();
}

void remove_current_task(void)
{
    // for now, check if halted tasks is working;
    printf("halting...\n");
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
}

void halt_function( void )
{
    // Copy the function pointer from ready tasks to halted tasks
    halted_tasks[halted_task_index] = ready_tasks[task_index];
    remove_current_task();
    task_index -= 1;
    halted_task_index += 1;
}


void task0(void *p)
{
    printf("This is task 0\n");
}

void task1(void *p)
{
    printf("This is task 1\n");
    halt_function();
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
    return;
}



int main()
{
    /*
    void (*func1_ptr)(void) = &func1; 
    start_function( func1_ptr );
    */ 

    ready_tasks[0] = &task0;
    ready_tasks[1] = &task1;
    ready_tasks[2] = &task2;
    ready_tasks[3] = &task3;
    ready_tasks[4] = &task4;
    ready_tasks[5] = &task5;
    ready_tasks[6] = NULL;

    for (int i = 0; i < 12; i++)
    {
        if (!global_err) scheduler();
    }

    return 0;
}