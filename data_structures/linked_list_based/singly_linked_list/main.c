/* 
 * Entry point for testing and debugging the source file linked_list.c
 * Author: Marta
 * Date: 02/11/2020
 */
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    node *list = initialize_list();
    
    insert_node(&list, 1);
    insert_node(&list, 2);
    insert_node(&list, 3);
    insert_node(&list, 4);
    print_list(list);

   // node *to_find = search_list_iteratively(list, 2);
   // printf("node next to 2: %d", to_find->next->item);

    //node *temp = get_previous_node(list, 2);
    //printf("node previous to 2 is %d", temp->item);

    delete_node(&list, 2);
    print_list(list);

    delete_node(&list, 4);
    print_list(list);

    node *previous_node = search_list_iteratively(list, 3);
    node *new_node = insert_after_node(previous_node, 10);
    print_list(list);

}