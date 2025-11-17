/*------------------------------------------------------
* Filename: calc_age.c
* Description: fing Gary's age in days, months and years
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
    int cd, cm, cy; // current day, current month, current year
    int bd, bm, by; // birth day, birth month, birth year

    printf("Enter current date:\n");
    scanf("%d/%d/%d", &cd, &cm, &cy);
    printf("Enter Gary's Birthday:\n");
    scanf("%d/%d/%d", &bd, &bm, &by);

    int diff = (cd - bd) + (cm - bm) * 30 + (cy - by) * 365;

    printf("Gary's age in days: %d\n", diff);
    printf("Gary's age in months: %f\n", (float)diff / 30);
    printf("Gary's age in years: %f\n", (float)diff / 365);

    return 0;
}