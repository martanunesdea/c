/* 
 *      Title:  File Input/Output Source file
 *    Summary:  Saves race information to persistent memory
 *     Author:  Marta Nunes de Abreu
 *       Date:  01/05/2020
 *   Compiler:  Apple clang version 10.0.0
 */
#include "file_io.h"

struct Team_t* file_io_read_teams(char *filename, int n_teams)
{
    FILE* f_ptr = fopen(filename, "r");  
    if ( f_ptr == NULL )
    {  
        printf("Couldn't open file, quitting...\n");
        return NULL;
    }
    
    char buff[20];
    int idx = 0;
    struct Team_t *teams_ptr = malloc(sizeof(struct Team_t)*n_teams);
    struct Team_t *teams_head_ptr = teams_ptr;
    printf("\nReading file...\n");
    while ( fgets(buff, 20, (FILE*)f_ptr) != NULL )
    {
        buff [strcspn(buff, "\r\n")] = 0;
        teams_ptr->id = idx;
        sprintf(teams_ptr->name, "%s", buff);
        printf("[%d] %s\n", teams_ptr->id, teams_ptr->name);
        teams_ptr++;
        idx++;

    }

    return NULL;
    
}


int file_io_create_races(char* filename, char *races_ptr, int no_races)
{
    FILE* f_ptr = fopen(filename, "w+");  
    if ( f_ptr == NULL )
    {  
        printf("\nCouldn't open file, quitting...\n");
        return NOK;
    }

    printf("\nSaving races into 'races.txt'...\n");
    fputs(races_ptr, f_ptr);
    printf("%s\n", races_ptr);
    fclose(f_ptr);

    return OK;
}


int file_io_edit_races(char* filename, int race_number, struct Points_t points)
{
    FILE* f_ptr = fopen(filename, "r+");  
    if ( f_ptr == NULL )
    {  
        printf("Couldn't open file, quitting...\n");
        return NOK;
    }
    
    char buff[20];
    int idx = 0;
    char existing_line[40];

    printf("\nEditing file...\n");
    while ( fgets(buff, 20, (FILE*)f_ptr) != NULL )
    {
        /* to do: add details in place where the existing race is */
        if ( idx == race_number )
        {
            sprintf(existing_line, "\n%s", buff);
            int index = strlen(existing_line)-1;
            sprintf(existing_line+index, ",%d,%d", points.teamA, points.teamB);
            fputs(existing_line, f_ptr);
            fclose(f_ptr);
            printf("\nAdded results to file\n");
            break;
        }
        idx++;        
    }
    return OK;
}
