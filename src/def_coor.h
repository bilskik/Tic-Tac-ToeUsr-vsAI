#ifndef _COORDINATES_
#define _COORDINATES_

#include <stdio.h>

#define n 3 

typedef struct coor {

    int tab_coor[n];
}coor_t;

typedef struct important {
    int arr_coor[n];
    int win_coor[n];
    char coor_char[n];
}important_t;

extern important_t* coor;

int row_and_column_coordinates();
void insert_row(int tmp_tab[], int x_counter[]);
void insert_column(int tmp_tab[], int x_counter[]);
int diagonal_coor_1();
int diagonal_coor_2();


#endif