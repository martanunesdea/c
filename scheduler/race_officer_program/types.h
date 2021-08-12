/* 
 *      Title:  Types Header file
 *     Author:  Marta Nunes de Abreu
 *       Date:  01/05/2020
 *   Compiler:  Apple clang version 10.0.0
 */
#ifndef TYPES_H
#define TYPES_H

#define OK 0
#define NOK 1

typedef struct Team_t {
    int id;
    char name[100];
} Team_t;

typedef struct Results_t {
    int teamA1;
    int teamA2;
    int teamA3;
    int teamB1;
    int teamB2;
    int teamB3;
} Results_t;

typedef struct Points_t {
    int teamA;
    int teamB;
    char *points_str;
} Points_t, *pPoints;



#endif