#include "computer.h"
#include "coor_win_header.h"

#include <stdio.h>
#include <stdlib.h>

#define n 3

char space[n][n];

int winning_case() {    
                                        
    char mark = 'O';
    char mark_X = 'X';
    int winning_counter_row=0;
    int winning_counter_column=0;
    int winning_counter_diagonal_1=0;
    int winning_counter_diagonal_2=0;
    int tmp_counter_row=0;
    int tmp_counter_column=0;


    for(int i=0; i<n; i++) {
        
        tmp_counter_column = 0;
        tmp_counter_row = 0;
        
        if(space[i][i] ==  mark) 
            winning_counter_diagonal_1++;
        if(space[i][i] == mark_X)
            winning_counter_diagonal_1--;

        for(int j=0; j<n; j++) {

            if(space[i][j] == mark) 
                tmp_counter_row++;
            if(space[i][j] == mark_X)
                tmp_counter_row--;

            if(space[j][i] == mark) 
                tmp_counter_column++;
            if(space[j][i] == mark_X)
                tmp_counter_column--;

            if( (i+j) == 2 && space[i][j] == mark) 
                winning_counter_diagonal_2++;
            if((i+j) == 2 && space[i][j] == mark_X)
                winning_counter_diagonal_2--;

         

        }   
        if(tmp_counter_column == 2)
            winning_counter_column = 2;
        if(tmp_counter_row == 2)
            winning_counter_row = 2;
        
    }
    if(winning_counter_diagonal_1 == 2) {
        return diagonal_1_win();
       
     
    }
    if(winning_counter_diagonal_2 == 2) {
        return diagonal_2_win();
    
    }
    if(winning_counter_row == 2) {
        return row_win();
        
    }
    if(winning_counter_column == 2) {
        return col_win();
      
    }

    return 0;
}