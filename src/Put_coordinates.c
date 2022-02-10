
#include "Coordinates.h"
#include <stdio.h>
#include <stdlib.h>

#define n 3
#define negative_value 10

char space[n][n];
coor_t coordinates[n];
important_t *coor;

int row_and_column_coordinates(int a) {
    
    coor=malloc(sizeof(coor));
    int which_row;
    int tmp_tab[n]={0};
    int max;
    int i_counter;
    int tmp=0;
    int funny = 0;
    int counter = 0;

    if(a == 0)
        insert_row(tmp_tab);
    else if(a == 1)
        insert_column(tmp_tab);
   
    for(int i=0; i<n; i++) {
        if(tmp_tab[i] == 3) {
            for(int j=0; j<n; j++)
                coordinates[i].tab_coor[j] = 0;
        }
        else if(tmp_tab[i] == 1 || tmp_tab[i] == 0) {
            for(int j=0; j<n; j++)
                coordinates[i].tab_coor[j] = negative_value;
        }

    }

  
    for(int i=0; i<n; i++) {
        if(coordinates[i].tab_coor[i] != 0 && coordinates[i].tab_coor[i] != negative_value) {
            for(int k=0; k<n; k++) {
                if(coordinates[i].tab_coor[k] == 'X')
                    counter++;
            }
            if(counter == 2) {
                funny = 1;
                for(int j=0; j<n; j++)  
                    coor->arr_coor[j]=coordinates[i].tab_coor[j];     
            }
        }
    
    }
    if (funny == 1)
        return 0;
    else 
        return 1;
 

}

void insert_row(int tmp_tab[]) {

     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if((space[i][j] == 'X' || space[i][j] == '0') && i == 0 ) {
                tmp_tab[0]++;
            }
            else if((space[i][j] == 'X' || space[i][j] == '0') && i == 1) {
                tmp_tab[1]++;
            }
            else if((space[i][j] == 'X' || space[i][j] == '0') && i == 2) {
                tmp_tab[2]++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            coordinates[i].tab_coor[j] = 3*i + j + 1;
    }

}
void insert_column(int tmp_tab[]) {

      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if((space[j][i] == 'X' || space[j][i] == '0') && i == 0 ) {
                tmp_tab[0]++;
            }
            else if((space[j][i] == 'X' || space[j][i] == '0') && i == 1) {
                tmp_tab[1]++;
            }
            else if((space[j][i] == 'X' || space[j][i] == '0') && i == 2) {
                tmp_tab[2]++;
            }
        }
    }
     for(int i=0; i<n; i++) { 
        for(int j=0; j<n; j++) {
            coordinates[i].tab_coor[j]=3*j + i+1;
        }
    }
}
int diagonal_coor_1() {
    
    int counter = 0;

    for(int i=0; i<n; i++) {
         if(space[i][i] ==  'O')
            counter++;
    }
    if(counter != 1) {
        for(int i=0; i<n; i++)
            coor->arr_coor[i]=i*4 +1;
        return 0;
    }
    else 
        return 1;
  
}
int diagonal_coor_2() {
    int counter = 0;
    int j = 2;

    for(int i=0; i<n; i++) {
        if(space[i][j--] == '0')
            counter++;
    }
    if(counter != 1) {
        for(int i=0; i<n; i++) 
            coor->arr_coor[i]=i*2 + 3;
        return 0;
    }
    else 
        return 1;
}