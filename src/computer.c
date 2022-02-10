#include "komputer.h"
#include "Part_1.h"
#include "Coordinates.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char space[n][n];
important_t *coor;


int computer_move() {

    int move;
    int best_case = 1;
    coor=malloc(sizeof(coor));

    srand(time(NULL));
    best_case = look_for_case();
    printf("Best case: %d\n", best_case);
    switch(best_case) {
        case 1:    
            printf("Im here!\n");
            move = rand()% 9 + 1;   
            return move;                      //im randomizing
            break;
        case 2:
            move = find_free();  
            return move;                      //im defending myself
            break;
        case 3:                         //im looking for win
            break;
        default:  
                               //if box is full
            break;

    }
      
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
        return 1;
}
int winning_case() {
    return 0;
}
int find_free() {
    int holder;
    for(int i=0; i<n; i++) {
        if(coor->arr_coor[i] != 'X') {
            holder = coor->arr_coor[i];
            return holder;
        }
    }
}


