#include "def_coor.h"
#include "win_header.h"

#include <stdio.h>
#include <stdlib.h>

#define n 3
#define negative_value 10
char space[n][n];
important_t *coor;

int diagonal_1_win() {
    for(int i=0; i<n; i++) {
        if(space[i][i] != 'X' && space[i][i] != 'O') 
            coor->win_coor[i] = i*4 +1;
        else 
            coor->win_coor[i] = negative_value;
    }
    return 3;
}
int diagonal_2_win() {
    int j=2; 
    for(int i=0; i<n; i++) {
        if(space[i][j] != 'X' && space[i][j] != 'O')
            coor->win_coor[i] = i*2 + 3;
        else
            coor->win_coor[i] = negative_value;
        
        j--;
    }
    return 3;
}
int row_win() {
    int funny = 0;
    int funny_o = 0;
    for(int i=0; i<n; i++) {
        funny = 0;
        funny_o = 0;
        for(int j=0; j<n; j++) {
            if(space[i][j] != 'X' && space[i][j] != 'O') {
                coor->win_coor[j] = 3*i + j + 1;
                funny++;
            }
            else {
                if(space[i][j] == 'O')
                    funny_o++;
                coor->win_coor[j] = negative_value;
            }
        }
        //printf("funny row %d, funny_ o %d\n", funny, funny_o);
        if(funny == 1 && funny_o == 2)
            return 3;
    }
}
int col_win() {
    int funny_o = 0;
    int funny = 0;
    for(int i=0; i<n; i++) {
        funny = 0;
        funny_o = 0;
        for(int j=0; j<n; j++) {
            if(space[j][i] != 'X' && space[j][i] != 'O') {
                coor->win_coor[j] = 3*j + i + 1;
                //printf("win_coor in col_win(): %d\n", coor->win_coor[i]);
                funny++;
              
            }
            else {
                if(space[j][i] == 'O')
                    funny_o++;
                coor->win_coor[j] = negative_value; 
            }
        }
       // printf("funny col: %d\n , funny_o: %d\n", funny, funny_o);
        if(funny == 1 && funny_o == 2)
            return 3;
    }
}
