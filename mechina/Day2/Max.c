/*------------------------------------------------------
* Filename: Max.c
* Description: 
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
    int x = 10;
    int y = 9;
    int z = x * (x > y) + y * (y >= x);
    printf("z: %d\n", z);

    return 0;
}