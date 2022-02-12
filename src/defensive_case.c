#include "defensive.h"
#include "computer.h"
#include "def_coor.h"
                          //defending case
#include <stdio.h>
#include <stdlib.h>
#define n 3

char space[n][n];
coor_t coordinates[n];
important_t *coor;

int defending_case() {        //im looking two X (in row, column, diagonal_1, diagonal_2)

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
    if(winning_counter_diagonal_1 == 2) {           //if i ve found two X in diagonal_1
        int tmp = diagonal_coor_1();
        if(tmp == 0)
            return 2;
    }

    if(winning_counter_diagonal_2 == 2) {           // if i ve found two X in diagonal_2
        int tmp = diagonal_coor_2();
        if(tmp == 0)
            return 2;
    }
    if(winning_counter_row == 2) {                  // if i ve found two X in some rows
        int tmp = row_and_column_coordinates(0);
        if(tmp == 0)
            return 2;
    }
    if(winning_counter_column == 2) {               // if i ve found two X in some columns
        int tmp = row_and_column_coordinates(1);
        if(tmp == 0)
            return 2;
    }
   
    return 0;                                       // if i havent found anything(so i dont have to defend myself)
    
}



