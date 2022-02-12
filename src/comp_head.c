#include "defensive.h"
#include "computer.h"
#include "def_coor.h"
#include "win_header.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char space[n][n];
important_t *coor;


int computer_move() {

    int move;
    int best_case = 1;
    

    srand(time(NULL));
    best_case = look_for_case();   //im looking for best case(attack or defend)
    switch(best_case) {             
        case 1:                             //move is random
            while(1) {
                move = rand()% 9 + 1;
                int a = check_free_box(move); 
                if(a == 0)
                    break;
                else 
                    continue;  
            }
            return move;                      
            break;
        case 2:                             //im defending myself
            move = find_free();  
            printf("move byl zamierzony: %d\n", move);
            return move;                     
            break;
        case 3:                         //im going to win with u
            break;
        default:  
                               //if box is full
            break;

    }
      
    return move;
}

int look_for_case() {           //choosing best case
    
    int stand = winning_case();
    int stand_2 = defending_case();

    if (stand_2 >= stand && stand_2 == 2)
        return 2;
    else if(stand > stand_2)
        return 3;
    else if(stand_2 == 0 && stand == 0)
        return 1;
    else
        return 1;
}   

int find_free() {                       //find a place where i can defend
    int holder;
    char holder_char;

    for(int i=0; i<n; i++) 
        coor->coor_char[i] = coor->arr_coor[i] + '0';

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(coor->coor_char[i] == space[j][k]) {
                    holder = coor->arr_coor[i];              //finding a free place where i am defending myself
                    break;
                }
            }
       }
    }
    return holder;
}

int check_free_box(int move) {                          //when move is random chceck if i can enter move there
    
    char changed_move = move + '0'; 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(changed_move == space[i][j])
                return 0;
        }
    }
    return 1;
}


