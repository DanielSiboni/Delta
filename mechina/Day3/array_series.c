/*------------------------------------------------------
* Filename: array_series.c
* Description: check if array is increasing, decreasing, constant or messed up
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>

#define ARRAY_SIZE 15

/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - program's main function
*
* Parameters –  None
*
* Return Values - int
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int main() {
    int userInputArray[ARRAY_SIZE];

    int increaseCheck = 1, decreaseCheck = 1, constantCheck = 1;
    printf("please enter 15 numbers:\n");
    scanf("%d", &userInputArray[0]);
    for (int i = 1; i < ARRAY_SIZE; i++) {
        scanf("%d", &userInputArray[i]);
        if (increaseCheck && userInputArray[i-1] >= userInputArray[i])
            increaseCheck = 0;
        if (decreaseCheck && userInputArray[i-1] <= userInputArray[i])
            decreaseCheck = 0;
        if (constantCheck && userInputArray[i-1] != userInputArray[i])
            constantCheck = 0;
    }

    if (constantCheck) {
        printf("The array is constant\n");
        return 0;
    }

    if (increaseCheck) {
        printf("The array is increasing\n");
        return 0;
    }

    if (decreaseCheck) {
        printf("The array is decreasing\n");
        return 0;
    }

    printf("The array is messed up\n");

}