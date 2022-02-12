#include "def_coor.h"

#include <stdio.h>
#include <stdlib.h>

#define n 3
#define negative_value 10

char space[n][n];
coor_t coordinates[n];
important_t *coor;

int row_and_column_coordinates(int a) {            //a == 0 -> row case , a == 1 ->column case
    
    
    int tmp_tab[n]={0};
    int x_counter[n] = {0};
    int funny = 0;

    if(a == 0)
        insert_row(tmp_tab, x_counter);                 //intializing row coordinates
    else if(a == 1)
        insert_column(tmp_tab, x_counter);              //initializing column coordinates
   
    for(int i=0; i<n; i++) {                             //looking for cases where there's no sense of defending
        if(tmp_tab[i] == 3) {                           //case where we have for example: ( X X O) - despite having two X we have full row/column
            for(int j=0; j<n; j++)
                coordinates[i].tab_coor[j] = 0;        
        }
        else if(tmp_tab[i] == 2 && x_counter[i] == 1) {       // case where we have for example (O  X) -  in that row/column we dont have two X
            for(int j=0; j<n; j++)
                coordinates[i].tab_coor[j] = negative_value;
        }
        else if(tmp_tab[i] == 1 || tmp_tab[i] == 0) {          // case where we have for example (O  ) or (   ) -in that row/column we dont have two X
            for(int j=0; j<n; j++)
                coordinates[i].tab_coor[j] = negative_value;
        }
       
    }
    for(int i=0; i<n; i++) {
        if(coordinates[i].tab_coor[i] != 0 && coordinates[i].tab_coor[i] != negative_value) {    //looking for coordinates where there are only two X without anything more
            funny = 1;
            for(int j=0; j<n; j++)  
                coor->arr_coor[j]=coordinates[i].tab_coor[j];     
        }
        
    
    }
    if (funny == 1)             //if i have to defend myself
        return 0;
    else                        // if there is no sense of defending
        return 1;
 

}

void insert_row(int tmp_tab[], int x_counter[]) {


     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if((space[i][j] == 'X' || space[i][j] == 'O') && i == 0 ) {
                if(space[i][j] == 'X')
                    x_counter[0]++;                                 //counter X in each row

                tmp_tab[0]++;                                       //counter X and O in each row
            }
            else if((space[i][j] == 'X' || space[i][j] == 'O') && i == 1) {
                if(space[i][j] == 'X')
                    x_counter[1]++;

                tmp_tab[1]++;
            }
            else if((space[i][j] == 'X' || space[i][j] == 'O') && i == 2) {
                if(space[i][j] == 'X')
                    x_counter[2]++;

                tmp_tab[2]++;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            coordinates[i].tab_coor[j] = 3*i + j + 1;               //initializing a row coordinates, example: 1,2,3 - coordinates of first row
    }

}
void insert_column(int tmp_tab[], int x_counter[]) {

      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if((space[j][i] == 'X' || space[j][i] == 'O') && i == 0 ) {
                if(space[j][i] == 'X')
                    x_counter[0]++;                                         //counter X in each column
                tmp_tab[0]++;                                               //counter X and O in each row
            }
            else if((space[j][i] == 'X' || space[j][i] == 'O') && i == 1) {
                if(space[j][i] == 'X')
                    x_counter[1]++;
                tmp_tab[1]++;
            }
            else if((space[j][i] == 'X' || space[j][i] == 'O') && i == 2) {
                if(space[j][i] == 'X')
                    x_counter[2]++;
                tmp_tab[2]++;
            }
        }
    }
    
     for(int i=0; i<n; i++) { 
        for(int j=0; j<n; j++) {
            coordinates[i].tab_coor[j]=3*j + i+1;            //initializing a column coordinates, example 1,4,7 - coordinates of first column
        }
    }
}
int diagonal_coor_1() {                                           //looking for defending in diagonal_1
    
    int counter = 0;
    int x_counter = 0;

    for(int i=0; i<n; i++) {
        if(space[i][i] == 'O')                          // O counter 
            counter++;
        if(space[i][i] == 'X')
            x_counter++;                                // X counter
    }
    if(counter != 1 && x_counter == 2) {                    //if i have a situation like that: (X X  ) etc.
        for(int i=0; i<n; i++) {
            coor->arr_coor[i]=i*4 +1;                        //initializing diagonal_1 coordinates(1, 5, 9)
        }
        return 0;
    }   
    else 
        return 1;                                   //there is no sense of defending
    
}
int diagonal_coor_2() {
    int counter = 0;
    int x_counter = 0;
    int j = 2;

    for(int i=0; i<n; i++) {
        if(space[i][j] == 'O')                      // O counter 
            counter++;
        if(space[i][j--] == 'X')
            x_counter++;                            // X counter
    }

    if(counter != 1 && x_counter == 2) {                //if i have a situation like that: (X X  ) etc.
        for(int i=0; i<n; i++)
            coor->arr_coor[i]=i*2 + 3;                  //initializing diagonal_2 coordinates(3,5,7)
        return 0;
    }
    else 
        return 1;                       //there is no sense of defending
}
