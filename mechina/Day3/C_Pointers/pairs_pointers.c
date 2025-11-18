/*------------------------------------------------------
* Filename: pairs_pointers.c
* Description: managa the fight between the kids
* Author: Daniel Siboni
-------------------------------------------------------*/

#include "pairs_pointers.h"

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
void initKidsArray(kid_t** kids) {
    for (int i = 0; i < KIDS_ARRAY_SIZE; i++) {
        kids[i] = (kid_t*)malloc(sizeof(kid_t));
        if(kids[i] == NULL) exit(EXIT_FAILURE);
        itoa(i, kids[i]->name, 10);
        kids[i]->blames = NULL;
    }

    printf("please enter %d pairs of numbers representing which kids blames who in this format: \"k,b\"\n", KIDS_ARRAY_SIZE);

    int kid = 0;
    int blames = 0;
    for(int i = 0; i < KIDS_ARRAY_SIZE; i++) {
        if(scanf("%d,%d", &kid, &blames) != 2) {
            printf("bad input!\n");
            exit(EXIT_FAILURE);
        }

        if(kid < 0 || kid > 4 || blames < 0 || blames > 4) {
            printf("bad input!\n");
            exit(EXIT_FAILURE);
        }
        kids[kid]->blames = kids[blames];
    }
}

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
void printKidsArray(kid_t** kids) {
    for (int i = 0; i < KIDS_ARRAY_SIZE; i++) {
        printf("kid%d blames kid%s\n", i, kids[i]->blames->name);
    }
    
}


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
    kid_t* kids[KIDS_ARRAY_SIZE] = {0};

    initKidsArray(kids);
    printKidsArray(kids);

    return 0;
}