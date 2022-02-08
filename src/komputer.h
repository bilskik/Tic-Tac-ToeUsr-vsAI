#ifndef _KOMPUTER_H
#define _KOMPUTER_H

#include <stdio.h>


typedef struct winning {

    int row_counter_mark;
    int column_counter_mark;
    int diagonal_1_counter_mark;
    int diagonal_2_counter_mark;

} winning_t;

int computer_move();
winning_t* look_for_best_option(char mark);

#endif
