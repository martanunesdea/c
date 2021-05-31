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

void (*list_of_functions[NUMBER_OF_FUNCTIONS])(void *p);
static int task_index = 0;
static int global_err = 0;
void task0(void *p)
{
    printf("This is task 0\n");
}

void task1(void *p)
{
    printf("This is task 1\n");
}

void task2(void *p)
{
    printf("This is task 2\n");
}

void task3(void *p)
{
    printf("This is task 3\n");
}


void start_function( void (*functionPTR)() )
{
    functionPTR();
}


void scheduler(void)
{
    if (list_of_functions[task_index] == NULL  && (task_index != 0) )
    {
        task_index = 0;
    }
    if (list_of_functions[task_index] == NULL && task_index == 0)
    {
        printf("No tasks, quitting\n");
        global_err = 1;
        return;
    }
    start_function(list_of_functions[task_index]);
    task_index++;
    return;
}



int main()
{
    /*
    void (*func1_ptr)(void) = &func1; 
    start_function( func1_ptr );
    */ 

    list_of_functions[0] = &task0;
    list_of_functions[1] = &task1;
    list_of_functions[2] = &task2;
    list_of_functions[3] = &task3;
    list_of_functions[4] = NULL;

    for (int i = 0; i < 5; i++)
    {
        if (!global_err) scheduler();
    }

    return 0;
}