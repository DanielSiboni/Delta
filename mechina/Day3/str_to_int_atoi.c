/*------------------------------------------------------
* Filename: str_to_int_atoi.c
* Description: cast a string of a number to its number with atio and add 36 to the answer
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE (10)
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

    int startLoop = (userInput[0] == '-');
    for (size_t i = startLoop; i < strlen(userInput); i++) {
        if(userInput[i] > '9' || userInput[i] < '0') {
            printf("not a number\n");
            return 1;
        }
    }

    int usersNum = atoi(userInput);
    printf("the number using atoi: %d\n", (usersNum + ADDED_NUMBER));

}