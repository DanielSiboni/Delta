/*------------------------------------------------------
* Filename: calc_age.c
* Description: fing Gary's age in days, months and years
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>

#define MONTH_TO_DAYS 30
#define YEARS_TO_DAYS 365

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
    int currentDay, currentMonth, currentYear;
    int birthDay, birthMonth, birthYear;

    printf("Enter current date:\n");
    scanf("%d/%d/%d", &currentDay, &currentMonth, &currentYear);
    printf("Enter Gary's Birthday:\n");
    scanf("%d/%d/%d", &birthDay, &birthMonth, &birthYear);

    int diff = (currentDay - birthDay) + (currentMonth - birthMonth) * 30 + (currentYear - birthYear) * 365;

    printf("Gary's age in days: %d\n", diff);
    printf("Gary's age in months: %f\n", (float)diff / 30);
    printf("Gary's age in years: %f\n", (float)diff / 365);

    return 0;
}