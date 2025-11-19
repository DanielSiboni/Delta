/*------------------------------------------------------
* Filename: dynamic_struct.c
* Description: gets two times from the user and then add them together.
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HOUR (23)
#define MAX_MINUTE (59)
#define MAX_SECOND (59)


typedef struct time {
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
}time;


/*------------------------------------------------------
* Function Name - getInputFromUser
*
* Function Purpose - create new time object in the heap and fill it with user's input
*
* Parameters –  None
*
* Return Values - time*, a pointer to the new time object
*
* Author - Daniel Siboni
-------------------------------------------------------*/
time* getInputFromUser() {
    unsigned int hour = 0, minute = 0, second = 0;
    
    printf("please enter time's hour: ");
    if((scanf("%u", &hour) != 1) || hour > MAX_HOUR) {
        printf("invalid hour\n");
        return NULL;
    }

    printf("please enter time's minute: ");
    if((scanf("%u", &minute) != 1) || minute > MAX_MINUTE) {
        printf("invalid minute\n");
        return NULL;
    }

    printf("please enter time's second: ");
    if((scanf("%u", &second) != 1) || second > MAX_SECOND) {
        printf("invalid hour\n");
        return NULL;
    }

    time* t = (time*)malloc(sizeof(time));
    if(t == NULL) return NULL;

    t->hour = hour;
    t->minute = minute;
    t->second = second;

    return t;
}

/*------------------------------------------------------
* Function Name - timesAddition
*
* Function Purpose - create new time object in the heap and fill it with the sum of times
*
* Parameters –  t1: time*, a pointer to the first time object
*               t2: time*, a pointer to the second time object
*
* Return Values - time*, a pointer to the new time object
*
* Author - Daniel Siboni
-------------------------------------------------------*/
time* timesAddition(time* t1, time* t2) {
    unsigned int second = t1->second + t2->second;
    unsigned int minute = t1->minute + t2->minute + (second / MAX_SECOND);
    unsigned int hour = t1->hour + t2->hour + (minute / MAX_MINUTE);

    time* tSum = (time*)malloc(sizeof(time));
    if(tSum == NULL) return NULL;

    tSum->hour = hour % MAX_HOUR;
    tSum->minute = minute % MAX_MINUTE;
    tSum->second = second % MAX_SECOND;
    
    return tSum;
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

    time* t1 = getInputFromUser();
    if(t1 == NULL) exit(EXIT_FAILURE);
    
    time* t2 = getInputFromUser();
    if(t1 == NULL) {
        free(t1);
        exit(EXIT_FAILURE);
    }

    time* tSum = timesAddition(t1, t2);
    if(tSum == NULL) {
        free(t1);
        free(t2);
        exit(EXIT_FAILURE);
    }

    printf("first time: %02u:%02u:%02u\n", t1->hour, t1->minute, t1->second);
    printf("second time: %02u:%02u:%02u\n", t2->hour, t2->minute, t2->second);
    printf("sum of times: %02u:%02u:%02u\n", tSum->hour, tSum->minute, tSum->second);
    
    free(t1);
    free(t2);
    free(tSum);

    return 0;
}