#ifndef _PART_1_
#define _PART_1_

#include <stdio.h>

#define n 3

typedef struct coor {

    int tab_coor[n];
}coor_t;

typedef struct important {
    int arr_coor[n];
}important_t;

int defending_case();
void row_coordinates();



#endif