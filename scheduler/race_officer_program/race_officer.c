/* 
 *      Title:  Race Office source file
 *    Summary:  Manages the "rules", creates race combinations, calculates races points, etc.
 *     Author:  Marta Nunes de Abreu
 *       Date:  01/05/2020
 *   Compiler:  Apple clang version 10.0.0
 */

#include "race_officer.h"

int race_officer_calculate_races(struct Team_t *teams_ptr, int no_teams, char races_ptr[])
{
    int race_number = 0;
    int index = 0;
    char str[40];
    for (int i = 0; i < no_teams; i++)
    {
        for (int j = 1; j < no_teams; j++)
        {
            if ( i != j && j > i) {
                // generate string with race info: "id, teamA, teamB"
                sprintf(str, "%d, %s, %s\n", race_number, (teams_ptr+i)->name, (teams_ptr+j)->name);
                
                // print to IO buffer
                sprintf(races_ptr+index, "%s", str);
                index = strlen(races_ptr);
                race_number++;
            }
        }
    }
    
    return race_number;
}

void race_officer_calculate_points(struct Results_t results, struct Points_t *points)
{
    // to do: check that team A and B don't have same results
    // to do: store positions in races file?
    points->teamA = results.teamA1 + results.teamA2 + results.teamA3;
    points->teamB = results.teamB1 + results.teamB2 + results.teamB3;

    return;
}


