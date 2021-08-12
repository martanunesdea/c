/* 
 *      Title:  Header file for File IO
 *     Author:  Marta Nunes de Abreu
 *       Date:  20/03/2020
 *   Compiler:  clang-1103.0.32.62 
 */
#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

struct Team_t* file_io_read_teams(char *filename, int n_teams);
int file_io_create_races(char* filename, char *races_ptr, int no_races);
int file_io_edit_races(char* filename, int race_number, struct Points_t points);

#endif