#include "coor_attack_header.h"
#include "def_coor.h"
#include <stdio.h>
#include <stdlib.h>

#define n 3
#define negative_value 10
char space[n][n];
important_t *coor;

int diagonal_1_attack() {
    for(int i=0; i<n; i++) {
        if(space[i][i] != 'O')
            coor->att_coor[i] = i*4 +1;
        else
            coor->att_coor[i] =  negative_value;
    }
    return 1;
}
int diagonal_2_attack() {
    int j=2; 
    for(int i=0; i<n; i++) {
        if(space[i][j] != 'O')
            coor->att_coor[i] = i*2 + 3;
        else
            coor->att_coor[i] = negative_value;
        
        j--;
    }
    return 1;
}

int row_attack(int which) {
    for(int i=0; i<n; i++) {
        
        if(which == i) {
            for(int j=0; j<n; j++) {
                if(space[i][j] != 'O')
                    coor->att_coor[j] = 3*i + j + 1;
                else    
                    coor->att_coor[j] = negative_value;
            }
        }
    }
    return 1;
}

int col_attack(int which) {
  
    for(int i=0; i<n; i++) {
       
        if(which == i) {
            for(int j=0; j<n; j++) {
                if(space[j][i] != 'O')
                    coor->att_coor[j] = 3*j + i + 1;
                else
                    coor->att_coor[j] = negative_value;
            }
        }
    }
    return 1;
}




