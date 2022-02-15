#include "computer.h"
#include "coor_attack_header.h"
#include "header_attack.h"

#include <stdio.h>
#include <stdlib.h>

#define n 3
#define negative_value 10
char space[n][n];

int attack_case() {
    char mark = 'X';
    int winning_counter_row=0;
    int winning_counter_column=0;
    int winning_counter_diagonal_1=0;
    int winning_counter_diagonal_2=0;
    int tmp_counter_row=0;
    int tmp_counter_column=0;
    int which_row = 0;
    int which_col = 0;
    int which_row_or_col = 0;
    int dia_1_o = 0;
    int dia_2_o = 0;
    int row_o = 0;
    int col_o = 0;

    for(int i=0; i<n; i++) {
        
        tmp_counter_column = 0;
        tmp_counter_row = 0;
        row_o = 0;
        col_o = 0;
        
        if(space[i][i] != mark) {
            winning_counter_diagonal_1++;
            if(space[i][i] == 'O')
                dia_1_o++;
        }

        for(int j=0; j<n; j++) {

            if(space[i][j] != mark) {
                tmp_counter_row++;
                if(space[i][j] == 'O')
                    row_o++;
            }
            
    
            if(space[j][i] != mark) {
                tmp_counter_column++;
                if(space[i][j] == 'O')
                    col_o++;
            }

            if( (i+j) == 2 && space[i][j] != mark) {
                winning_counter_diagonal_2++;
                if(space[i][j] == 'O')
                    dia_2_o++;

            }
        }   
        which_row_or_col++;
        if(tmp_counter_column == 3 && col_o == 1) {
            winning_counter_column = 3;
            which_col = which_row_or_col;
        }
        if(tmp_counter_row == 3 && row_o == 1) {
            winning_counter_row = 3;
            which_row = which_row_or_col;
        }
        
    }

    if(winning_counter_diagonal_1 == 3 && dia_1_o == 1) {
        return diagonal_1_attack();
      
       
    }
    if(winning_counter_diagonal_2 == 3 && dia_2_o == 1) {
        return diagonal_2_attack();
       
      
    }
    if(winning_counter_row == 3) {
        return row_attack(which_row);
    
       
    }
    if(winning_counter_column == 3) {
        return col_attack(which_col);
  
       
    }
    return 0;
}