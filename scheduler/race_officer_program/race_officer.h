/* 
 *      Title:  Header file for Race Officer Controller
 *     Author:  Marta Nunes de Abreu
 *       Date:  01/05/2020
 *   Compiler:  Apple clang version 10.0.0
 */
#ifndef RACE_OFFICER_H
#define RACE_OFFICER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_io.h"
#include "types.h"

int race_officer_calculate_races(struct Team_t *teams_ptr, int no_teams, char races_ptr[]);
void race_officer_calculate_points(struct Results_t results, struct Points_t *points);


#endif