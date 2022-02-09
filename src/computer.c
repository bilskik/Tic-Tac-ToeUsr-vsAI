#include "komputer.h"
#include "Part_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int computer_move() {

    int move;
    int best_case = 1;

    srand(time(NULL));
    best_case = look_for_case();
    switch(best_case) {
        case 1:                         //im randomizing
            break;
        case 2:                         //im defending myself
            break;
        case 3:                         //im looking for win
            break;
        default:                        //if box is full
            break;

    }
    move = rand()% 9 + 1;   
    return move;
}

int look_for_case() {
    
    int stand = winning_case();
    int stand_2 = defending_case();
    if (stand_2 >= stand)
        return 2;
    else if(stand > stand_2)
        return 3;
    else if(stand_2 == 0 && stand == 0)
        return 1;
    else
        return 0;
}
int winning_case() {
    ;
}


