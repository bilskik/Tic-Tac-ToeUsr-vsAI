#include "defensive.h"
#include "computer.h"
#include "def_coor.h"
#include "win_header.h"
#include "header_attack.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 3
#define negative_value 10

char space[n][n];
important_t *coor;


int computer_move() {

    int move;
    int best_case = 0;
    int count = 0;
    srand(time(NULL));
    best_case = look_for_case();   //im looking for best case(attack or defend)
    switch(best_case) {             
        case 1:                                          //move is random
            move = 5;
            int check = check_free_box(move);
            if(check == 0) 
                return move;                                 
            while(1) {
                move= (rand() % ((12 - 1)/ 2)) * 2 + 1;
                int a = check_free_box(move); 
                count++;
                if(count == 30) {
                    while(1) {
                        move = rand() % 9 + 1;
                        int b = check_free_box(move);
                        if(b == 0)
                            return move;
                        else
                            continue;
                    }
                }
                if(a == 0)
                    break;
                else 
                    continue;  
            }
            
            return move;                      
            break;
        case 2:                             //im defending myself
            move = find_free();  
            return move;                     
            break;
        case 3:
            move = find_pos();
            return move;                                                         //im going to win with u
            break;
        case 4:   
            move = find_attack();
            return move;                                            //attack case
            break;
        default:
            break;

    }
      
    return move;
}

int look_for_case() {           //choosing best case
    
    int stand_1 = winning_case();
    int stand_2 = defending_case();
    int stand_3 = attack_case();

    if (stand_1 == 3 && stand_2 == 2 || stand_1 > stand_2)
        return 3;
    else if(stand_2 > stand_1)
        return 2;
    else if(stand_2 == 0 && stand_1 == 0 && stand_3 > 0)
        return 4;
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
int find_pos() {
   
    for(int i=0; i<n; i++) {
        if(coor->win_coor[i] != negative_value) 
            return coor->win_coor[i];
    }
}

int find_attack() {

    for(int i=0; i<n; i++) {
        if(coor->att_coor[i] != negative_value)
            return coor->att_coor[i];
    }
}

