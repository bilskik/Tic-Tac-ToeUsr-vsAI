#include "Part_1.h"             //defending case
#include <stdio.h>
#include <stdlib.h>
#define n 3

char space[n][n];
coor_t coordinates[n];
important_t *coor;

int defending_case() {
    char mark = 'X';
    int winning_counter_row=0;
    int winning_counter_column=0;
    int winning_counter_diagonal_1=0;
    int winning_counter_diagonal_2=0;
    int tmp_counter_row=0;
    int tmp_counter_column=0;

    for(int i=0; i<n; i++) {
        
        tmp_counter_column=0;
        tmp_counter_row=0;
        
        if(space[i][i] ==  mark)
            winning_counter_diagonal_1++;

        for(int j=0; j<n; j++) {

            if(space[i][j] == mark) 
                tmp_counter_row++;

            if(space[j][i] == mark) 
                tmp_counter_column++;

            if( (i+j) == 2 && space[i][j] == mark)
                winning_counter_diagonal_2++;

            if(tmp_counter_column == 2)
                winning_counter_column=2;
            if(tmp_counter_row == 2)
                winning_counter_row=2;

        }   
        
    }
    if(winning_counter_row == 2) {
        row_coordinates();
        
    }

    if(winning_counter_column == 2) {
       // coordinates();
     ;
    }

    if(winning_counter_diagonal_1 == 2) {
        //coordinates();
        ;
    }
    
    if(winning_counter_diagonal_2 == 2) {
       // coordinates();
       ;
    }

}

void row_coordinates() {
    
    coor=malloc(sizeof(coor));
    int which_row;
    int tmp_tab[n]={0};
    int max;
    int i_counter;
    int tmp=0;
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
  
    for(int i=0; i<n; i++)
        coordinates[0].tab_coor[i]=i+1;
  
    int j=0;
    for(int i=4; i<7; i++) 
        coordinates[1].tab_coor[j++]=i;
    j=0;
    for(int i=7; i<10; i++) 
        coordinates[2].tab_coor[j++]=i;

    for(int i=0; i<n; i++) {
        if(tmp_tab[i] == 3) {
            for(int j=0; j<n; j++)
                coordinates[i].tab_coor[j] = 0;
        }

    }

  
    for(int i=0; i<n; i++) {
        if(coordinates[i].tab_coor[i] != 0) {
            for(int j=0; j<n; j++)  
                coor->arr_coor[j]=coordinates[i].tab_coor[j];     
        }
    
    }
 

}

