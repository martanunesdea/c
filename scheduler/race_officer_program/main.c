/* 
 *      Title:  Main source file for sailing Round Robin program
 *    Summary:  Generate race combinations and/or add results of races
 *     Author:  Marta Nunes de Abreu
 *       Date:  01/05/2020
 *   Compiler:  Apple clang version 10.0.0
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"
#include "file_io.h"
#include "race_officer.h"

void create_schedule(void)
{
    int n_teams;
    printf("\nEnter the number of teams\n");
    scanf("%d", &n_teams);
    
    /* pointer to the 1st team in the array of teams */
    Team_t *teams_head_ptr = file_io_read_teams("teams.txt", n_teams);

    if (teams_head_ptr == NULL)
    {
        printf("\nThere was a problem reading the file. Quitting."); 
        // add free teams_head_ptr
        return;
    }

    char races_ptr[2048]; /* array containg all of race combinations */
    int total_races = race_officer_calculate_races(teams_head_ptr, n_teams, races_ptr);
        
    if ( file_io_create_races("races.csv", races_ptr, total_races) != OK )
    {
        printf("\nError in creating races file.\n");
    }

    free(teams_head_ptr);
    return;
}

void enter_result_single(void)
{
    int race_number; 
    printf("\nEnter race number: ");
    scanf("%d", &race_number);

    Results_t results;
    printf("\nEnter results for team A: ");
    scanf("%d%d%d", &(results.teamA1), &(results.teamA2), &(results.teamA3));
    printf("\nEnter results for team B: ");
    scanf("%d%d%d", &(results.teamB1), &(results.teamB2), &(results.teamB3));
    
    pPoints points = malloc(sizeof(pPoints));
    race_officer_calculate_points(results, points);
    
    if ( file_io_edit_races("races.csv", race_number, *points) != OK )
    {
        printf("\nError in editing races file\n");
    }

    free(points);
    return;
}

void enter_results_many(void)
{
    char input = '\0';
    bool exit = false;
    enter_result_single();
    do {
        printf("\nContinue? (y/n)\n");
        scanf("%s", &input);
        if ( input == 'y' || input == 'Y' ) enter_result_single();
        else if ( input == 'n' || input == 'N' ) exit = true;
        else continue;
    } while ( exit == false);
    
    return;
}

int main()
{
    char option;
    bool exit = false;
    do {
        printf("\nSelect option: \n");
        printf("A. Create schedule\n");
        printf("B. Enter results for one race\n");
        printf("C. Enter results for many races\n");
        printf("Q. Quit\n");
        scanf("%s", &option);

        switch(option)
        {
            case 'a': /* flows into A */
            case 'A': create_schedule(); break;
            case 'b': /* flows into B */
            case 'B': enter_result_single(); break;
            case 'c': /* flows into C */
            case 'C': enter_results_many(); break;
            default: exit = true; break;
        }
    } while ( exit == false);

    printf("Quitting...\n");
    return OK;
}


