/*------------------------------------------------------
* Filename: print_chars.c
* Description: print a squere the size of the user input with the chars based on the number division.
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>

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
    unsigned int user_input;
    char printed_char;

    // get uthe user input
    printf("Please enter a positive integer: ");
    if(scanf("%u", &user_input) != 1) {
        printf("Bad input!\n");
        return 1;
    }

    // check which char should be use
    if(user_input & 1) {
        if(user_input % 3) {
            if (user_input % 5) {
                printed_char = '@';
            } else {
                printed_char = '%';
            }
        } else {
            printed_char = '^';
        }
    } else {
        printed_char = '*';
    }

    // printing the square
    size_t square_len = user_input;
    for (size_t i = 0; i < square_len; i++) {
        for (size_t j = 0; j < square_len; j++) {
            printf("%c", printed_char);
        }
        printf("\n");
    }
    
 

    return 0;
}