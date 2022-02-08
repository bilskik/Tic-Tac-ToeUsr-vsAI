#include "komputer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define n 3

char space[n][n];
char show_space[n][n];


int computer_move() {

    int move;
    srand(time(NULL));
    winning_t* win = look_for_best_option('X');
    move = rand()% 9 + 1;
    free(win);
    return move;
}
winning_t* look_for_best_option(char mark) {
    
    winning_t* winning = malloc(sizeof(*winning));

    int winning_counter_row=0;
    int winning_counter_column=0;
    int winning_counter_diagonal_1=0;
    int winning_counter_diagonal_2=0;
    int funny=1;
    
    

    for(int i=0; i<n; i++) {
        
        winning_counter_column=0;
        winning_counter_row=0;

        if(space[i][i] ==  mark)
            winning_counter_diagonal_1++;

        for(int j=0; j<n; j++) {
            

            if(space[i][j] == mark) 
                winning_counter_column++;

            if(space[j][i] == mark) 
                winning_counter_row++;

            if( (i+j) == 2 && space[i][j] == mark)
                winning_counter_diagonal_2++;

        }
           
        
    }
    winning->row_counter_mark = winning_counter_row;
    winning->column_counter_mark = winning_counter_column;
    winning-> diagonal_1_counter_mark = winning_counter_diagonal_1;
    winning->diagonal_2_counter_mark = winning_counter_diagonal_2;
    
    return winning;
}