#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "komputer.h"
#include "Part_1.h"

#define n 3
#define max_name_length 100

extern char space[n][n];
char show_space[n][n];

//initiation a show_space[][] from 1 to 9
void initiation_show_space() {
    char a='1';
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            show_space[i][j]=a;
            a++;
        }
    }
}

//initiation a space[][] from 1 to 9
void initiation() {

    char a='1';
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            space[i][j]=a;
            a++;
        }
    }
}

//help (how to play):

void show_numbers() {
    printf("\t\t   %c|  %c| %c\n",show_space[0][0], show_space[0][1], show_space[0][2]);
    printf("\t\t ___|___|___  \n");
    printf("\t\t   %c|  %c|%c \n",show_space[1][0], show_space[1][1], show_space[1][2]);
    printf("\t\t____|___|___\n");
    printf("\t\t   %c|  %c|%c   \n",show_space[2][0], show_space[2][1], show_space[2][2]);
    printf("\t\t    |   |   \n");
}
// an actual state of map
void map() {

    char printer[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(space[i][j] == 'X' )
                printer[i][j]='X';
            else if(space[i][j] == 'O')
                printer[i][j]='O';
            else   
                printer[i][j]=32;
        }
    }
    printf("\t\t  %c | %c | %c\n",printer[0][0], printer[0][1], printer[0][2]);
    printf("\t\t ___|___|___  \n");
    printf("\t\t  %c | %c | %c \n",printer[1][0], printer[1][1], printer[1][2]);
    printf("\t\t____|___|___\n");
    printf("\t\t  %c | %c | %c   \n",printer[2][0], printer[2][1], printer[2][2]);
    printf("\t\t    |   |   \n");
}

//instruction
void instruction(char *player_1_name, char *player_2_name) {
    printf("Zaczyna gracz %s\n", player_1_name);
    printf("Jego zadaniem jest wprowadzenie odpowiedniego numeru, tam gdzie chce postawic 'X'\n");
    printf("Natepnia numer wprowadza gracz %s, tam gdzie chce postawic 'O' \n", player_2_name);
    printf("Oznaczenia numerow: \n");
    show_numbers();
    
}

//entering values to space[][]

int enter_value(int choice_1, int choice_2) {

        int holder;
        char mark;
        if(choice_1 < 0) {
            holder=choice_2;
            mark='O';
        }
        else {
            holder=choice_1;
            mark='X';
        }
    
        switch(holder) {
        case 1: {
            if(space[0][0] == 'X' || space[0][0] == 'O') {
                
                return 1;
            }
            space[0][0]=mark;
            break;
        }
        case 2: {
            if(space[0][1] == 'X' || space[0][1] == 'O') {
                
                return 1;
            }
            space[0][1]=mark;
            break;
        }
        case 3: {
            if(space[0][2] == 'X' || space[0][2] == 'O') {
                
                return 1;
            }
            space[0][2]=mark;
            break;
        }
        case 4: {
            if(space[1][0] == 'X' || space[1][0] == 'O') {
                
                return 1;
            }
            space[1][0]=mark;
            break;
        }
        case 5: {
            if(space[1][1] == 'X' || space[1][1] == 'O') {
                
                return 1;
            }
            space[1][1]=mark;
            break;
        }
        case 6: {
            if(space[1][2] == 'X' || space[1][2] == 'O') {
                
                return 1;
            }
            space[1][2]=mark;
            break;
        }
        case 7: {
            if(space[2][0] == 'X' || space[2][0] == 'O') {
                
                return 1;
            }
            space[2][0]=mark;
            break;
        }
        case 8: {
            if(space[2][1] == 'X' || space[2][1] == 'O') {
                
                return 1;
            }
            space[2][1]=mark;
            break;
        }
        case 9: {
            if(space[2][2] == 'X' || space[2][2] == 'O') {
                
                return 1;
            }
            space[2][2]=mark;
            break;
        }
        default: {
            return 2;
            break;
        }

    }
    return 0;
}
int  entering_search(int a) {
    if(a == 0)
        return 0;
    else if(a == 1) {
        printf("Pole zajete!\nWprowadz wartosc jeszcze raz!\n");
        return 1;
    }
    else {
        printf("Wprowadz wartosc od 0-8\n");
        return 1;
    }
}
//looking for solution
int look_for_sol(char mark) {

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

        if(winning_counter_diagonal_1 == 3)
            return 1;


        for(int j=0; j<n; j++) {
            
            if(space[i][j] == mark) 
                winning_counter_column++;

            if(space[j][i] == mark) 
                winning_counter_row++;

            if( (i+j) == 2 && space[i][j] == mark)
                winning_counter_diagonal_2++;

            if(winning_counter_column == 3 )
                return 1;
            else if(winning_counter_row == 3)
                return 1;
            else if(winning_counter_diagonal_2 == 3)
                return 1;

        }
           
        
    }
    return 0;

}
//looking for draw
int look_for_draw(char mark_1, char mark_2) {
    int mark_counter=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(space[i][j] == mark_1 || space[i][j] == mark_2)
                mark_counter++;
        }
    }
    if(mark_counter == 9)
        return 0;
    else
        return 1;
}

int main(int argc, char **argv) {

    initiation();
    initiation_show_space();
    int final_state = 1;
    //char player_1_name[max_name_length];
    char *player_1_name="Kamil";
    char *player_2_name;
    int player_1_choice;
    int player_2_choice;
    int a;
    int games_counter=0;
    int counter_of_points_player_1=0;
    int counter_of_points_player_2=0;
    char bufor[max_name_length];
    int tmp_draw;


    //printf("Wprowadz imie 1 gracza!\n");
    //scanf("%s", player_1_name);
    player_2_name= "Komputer";

    /*if(games_counter == 0) {
        instruction(player_1_name, player_2_name);
        games_counter=1;
        sleep(7);
    }
    */
    while(1) {
        
       // sleep(1);
       // system("clear");
        printf("POMOC:\n");
        show_numbers();
        printf("\n");
        printf("AKTUALNY STAN MAPY\n");
        map();
        
        printf("Ruch wykonuje gracz: %s \n", player_1_name);
        while(1) {                                             //entering a move (player 1)
            player_2_choice=-1;
            scanf("%d", &player_1_choice);
            a=enter_value(player_1_choice, player_2_choice);
            int search = entering_search(a);
            if (search == 0)
                break;            
        }
        map();
        final_state=look_for_sol('X');
         if(final_state == 1) {                 //if player 1 is winning
             printf("Gratulacje dla %s za zwyciestwo w tej rundzie!\n", player_1_name);
             games_counter=1;
             counter_of_points_player_1++;
            printf("Jesli chcesz zagrac kolejna runde napisz tak\nJesli nie, napisz nie\n");
            scanf("%s", bufor);
            if(strcmp(bufor, "tak") == 0) {
                initiation();
                continue;
            }
            else
                break;
            
         }
         else {                                 //if draw
            tmp_draw=look_for_draw('X', 'O');
            if(tmp_draw == 0) {
                printf("Remis!!\n");
                counter_of_points_player_2++;
                counter_of_points_player_1++;
                printf("Jesli chcesz zagrac kolejna runde napisz tak\nJesli nie, napisz nie\n");
                scanf("%s", bufor);
                if(strcmp(bufor, "tak") == 0) {
                    initiation();
                    continue;
                }
                else 
                    break;
             }
         }
        

        printf("Ruch wykonuje gracz: %s: \n", player_2_name);
        while(1) {                                                         //entering a move (player 2)
            player_1_choice = -1;
            player_2_choice = computer_move();
            a = enter_value(player_1_choice, player_2_choice);
            if(a == 0)
                break;
        }
        map();
        
        final_state=look_for_sol('O');
        if(final_state == 1) {                                            //if player 2 is winning 
            printf("Gratulacje dla %s za zwyciestwo w tej rundzie!\n", player_2_name);
            games_counter=1;
            counter_of_points_player_2++;
            printf("Jesli chcesz zagrac kolejna runde napisz tak\nJesli nie, napisz nie\n");
            scanf("%s", bufor);
            if(strcmp(bufor, "tak") == 0) {
                initiation();
                continue;
            }
            else
                break;
        }
        else {
            tmp_draw=look_for_draw('X', 'O');    //if draw
            if(tmp_draw == 0) {
                printf("Remis!!\n");
                counter_of_points_player_2++;
                counter_of_points_player_1++;
                printf("Jesli chcesz zagrac kolejna runde napisz tak\nJesli nie, napisz nie\n");
                scanf("%s", bufor);
                if(strcmp(bufor, "tak") == 0) {
                    initiation();
                    continue;
                }
                else
                    break;
             }
         }
       
    }

    //printing a results of game
    
    if(counter_of_points_player_1 > counter_of_points_player_2) {
        printf("Gre wygrywa gracz %s z liczba punktow: %d \nGRATULACJE!!!\n", player_1_name, counter_of_points_player_1);
        printf("Gracz %s zdobyl %d punktow\n", player_2_name, counter_of_points_player_2);
    }
    else if(counter_of_points_player_1 < counter_of_points_player_2) {
        printf("Gre wygrywa gracz %s z liczba punktow %d \nGRATULACJE!!!\n", player_2_name, counter_of_points_player_2);
        printf("Gracz %s zdobyl %d punktow\n", player_1_name, counter_of_points_player_1);
    }
    else
        printf("Gratulacje dla obu graczy %s i %s \nREMIS!\n Mieli po %d punktow!", player_1_name, player_2_name, counter_of_points_player_1);

    printf("\n");

    return 0;
}