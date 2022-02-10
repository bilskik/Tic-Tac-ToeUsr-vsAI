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
    

    srand(time(NULL));
    best_case = look_for_case();
    switch(best_case) {
        case 1:  
            while(1) {
                move = rand()% 9 + 1;
                int a = check_free_box(move); 
                if(a == 0)
                    break;
                else 
                    continue;  
            }
            return move;                      //im randomizing
            break;
        case 2:
            move = find_free();  
            printf("move byl zamierzony: %d\n", move);
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
    //printf("stand_2 = %d\n", stand_2);
    if (stand_2 >= stand && stand_2 == 2)
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
    char holder_char;

    for(int i=0; i<n; i++) 
        coor->coor_char[i] = coor->arr_coor[i] + '0';

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(coor->coor_char[i] == space[j][k]) {
                    holder = coor->arr_coor[i];
                    break;
                }
            }
       }
    }
    return holder;
}

int check_free_box(int move) {
    
    char changed_move = move + '0'; 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(changed_move == space[i][j])
                return 0;
        }
    }
    return 1;
}


