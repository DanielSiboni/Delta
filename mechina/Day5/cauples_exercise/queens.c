/*------------------------------------------------------
* Filename: queens.c
* Description: find a proper position for each queen in the board.
* Author: Paula Gelman & Daniel Siboni
-------------------------------------------------------*/


#include <stdio.h>

#define BOARD_SIZE (8)
#define QUEENS_COUNT (8)
#define EMPTY_CELL ('#')
#define QUEEN_CELL ('O')
#define DEFUALT_QUEEN_VALUE (-1)

typedef struct point_s{
    int x_axis;
    int y_axis;
}point_t;

char board[BOARD_SIZE][BOARD_SIZE] = {0}; //game's board
point_t queens[QUEENS_COUNT] = {0}; //queen's points


/*------------------------------------------------------
* Function Name - point_collide_queens
*
* Function Purpose - check if the pointes can be eaten by the queens
*
* Parameters – point_t queen, point_t try
*
* Return Values - int
*
* Author - Gelman Paula & Daniel Siboni
-------------------------------------------------------*/
int point_collide_queens(point_t queen, point_t try) {

    if(try.x_axis == queen.x_axis) return 1;
    if(try.y_axis == queen.y_axis) return 1;
    
    if(try.x_axis - try.y_axis == queen.x_axis - queen.y_axis )return 1;
    if((try.x_axis + try.y_axis) == (queen.x_axis + queen.y_axis) )return 1;
    
    return 0;
}

/*------------------------------------------------------
* Function Name - can_be_placed
*
* Function Purpose - check if the queen can be placed

* Parameters – point_t try
*
* Return Values - int
*
* Author - Gelman Paula & Daniel Siboni
-------------------------------------------------------*/
int can_be_placed(point_t try) {
    for(int i = 0; i < QUEENS_COUNT; i++) {
        if(queens[i].x_axis == DEFUALT_QUEEN_VALUE || queens[i].y_axis == DEFUALT_QUEEN_VALUE) break;

        for(int x = 0; x < BOARD_SIZE; x++) {
            for(int y = 0; y < BOARD_SIZE; y++) {
                if(point_collide_queens(queens[i], try)) return 0;
            }
        }
    }

    return 1;
}

/*------------------------------------------------------
* Function Name - print_board
*
* Function Purpose - check if the queen can be placed

* Parameters – point_t try
*
* Return Values - none
*
* Author - Gelman Paula & Daniel Siboni
-------------------------------------------------------*/
void print_board() {
    for(int x = 0; x < BOARD_SIZE; x++) {
        for(int y = 0; y < BOARD_SIZE; y++) {
            printf("  %c", board[x][y]);
        }
        printf("\n");
    }
}

/*------------------------------------------------------
* Function Name - solve_problem
*
* Function Purpose - recursive 

* Parameters – int queen_count
*
* Return Values - none
*
* Author - Gelman Paula & Daniel Siboni
-------------------------------------------------------*/
int solve_problem(int queen_count) {
    point_t try;
    if(queen_count == QUEENS_COUNT) {
        return 1;
    }
    
    for(int i = 0; i < QUEENS_COUNT; i++) {

        if((queens[i].x_axis == DEFUALT_QUEEN_VALUE || queens[i].y_axis == DEFUALT_QUEEN_VALUE) && queen_count) continue;

        int x = queen_count;
        for(int y = 0; y < BOARD_SIZE; y++) {
            try.x_axis = x;
            try.y_axis = y;
            if(can_be_placed(try)) {
                queens[queen_count].x_axis = x;
                queens[queen_count].y_axis = y;
                board[x][y] = QUEEN_CELL;
                if(solve_problem(queen_count + 1)) return 1;
                queens[queen_count].x_axis = DEFUALT_QUEEN_VALUE;
                queens[queen_count].y_axis = DEFUALT_QUEEN_VALUE;
                board[x][y] = EMPTY_CELL;
            }
        }

    }

    return 0;

}

/*------------------------------------------------------
* Function Name - initial_location
*
* Function Purpose - 
* Parameters – int arr[],int *pointers[],int size
*
* Return Values - none
*
* Author - Gelman Paula
-------------------------------------------------------*/
void initial_location(){

    for(int i = 0; i < QUEENS_COUNT; i++){
        
        queens[i].x_axis = DEFUALT_QUEEN_VALUE;
        queens[i].y_axis = DEFUALT_QUEEN_VALUE;
    }


    
}
/*------------------------------------------------------
* Function Name -  initial_board
*
* Function Purpose - to initial the board to '#'

* Parameters – none
*
* Return Values - none
*
* Author - Gelman Paula & Daniel Siboni
-------------------------------------------------------*/
void initial_board(){

    for(int i=0;i< BOARD_SIZE;i++){
        for(int j=0;j< BOARD_SIZE;j++){
            
            board[i][j] = '#';
        }
    }
}





int main() {

    
    initial_board();
    initial_location();

    solve_problem(0);
    print_board();

    return 0;
}
