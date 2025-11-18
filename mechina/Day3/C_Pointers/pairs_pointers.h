/*------------------------------------------------------
* Filename: pairs_pointers.h
* Description: managa the fight between the kids
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define KIDS_ARRAY_SIZE (5)
#define MAX_NAME (20)

typedef struct kid_s
{
    char name[MAX_NAME];
    struct kid_s* blames;
} kid_t;



/*------------------------------------------------------
* Function Name - initKidsArray
*
* Function Purpose - init the kids array and get the values for the kids from the user.
*
* Parameters –  kids: kid_t**, a pointer to array of pointers to kids.
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void initKidsArray(kid_t** kids);


/*------------------------------------------------------
* Function Name - printKidsArray
*
* Function Purpose - prints the kids
*
* Parameters –  kids: kid_t**, a pointer to array of pointers to kids.
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void printKidsArray(kid_t** kids);