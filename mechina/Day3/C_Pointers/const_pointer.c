/*------------------------------------------------------
* Filename: const_pointer.c
* Description: help gili change the const chanel's number
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define CHANEL_INIT_NUM (10)

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
    const int chanel = CHANEL_INIT_NUM;

    printf("the chanel's number is: %d\n", chanel);

    int gilisNum;

    printf("please enter a new chanel: ");
    if( scanf("%d", &gilisNum) != 1) {
        printf("invalid num\n");
        exit(EXIT_FAILURE);
    }

    int* chanel_ptr = &chanel;

    *chanel_ptr = gilisNum;

    printf("the new chanel's number is: %d\n", chanel);

    return 0;
}