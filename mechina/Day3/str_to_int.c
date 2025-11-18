/*------------------------------------------------------
* Filename: str_to_int.c
* Description: cast a string of a number to its number with and without atio and add 36 to the answer
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE (100)
#define ADDED_NUMBER (36)
#define ZERE_CHAR ('0')

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
    char userInput[MAX_STR_SIZE];

    printf("please enter a positive integer\n");
    scanf("%s", userInput);

    int usersNum = atoi(userInput);
    printf("the number using atoi: %d\n", (usersNum + ADDED_NUMBER));

    usersNum = 0;
    for (size_t i = 0; i < strlen(userInput); i++) {
        usersNum += (userInput[i] - ZERE_CHAR);
        usersNum *= 10;
    }

    printf("the number without using atoi: %d\n", (usersNum/10 + ADDED_NUMBER));
    

}