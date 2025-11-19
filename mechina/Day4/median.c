/*------------------------------------------------------
* Filename: median.c
* Description: gets a list of numbers from the user and then find and print the median number
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
}node;


/*------------------------------------------------------
* Function Name - getArray
*
* Function Purpose - gets a list of node from the user
*
* Parameters –  None
*
* Return Values - node*, the start of the created list
*
* Author - Daniel Siboni
-------------------------------------------------------*/
node* getArray() {

    int input = 0;
    printf("enter integers, enter a char to stop.\n");

    node* start = (node*)malloc(sizeof(node));
    if(start == NULL) exit(EXIT_FAILURE);

    if(scanf("%d", &input) != 1)
        return NULL;

    start->value = input;
    node* cur = start;

    while (scanf("%d", &input) == 1) {
        cur->next = (node*)malloc(sizeof(node));
        if((cur = cur->next) == NULL) exit(EXIT_FAILURE);
        cur->value = input;
        cur->next = NULL;
    }
   
    return start;

}


/*------------------------------------------------------
* Function Name - printArray
*
* Function Purpose - prints the list of nodes
*
* Parameters –  start: node*, a pointer to the start of the list
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void printArray(node* start) {
    node* cur = start;
    while (cur != NULL) {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
    
}


/*------------------------------------------------------
* Function Name - findMedian
*
* Function Purpose - go through the list to find and print the median
*
* Parameters –  start: node*, a pointer to the start of the list
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void findMedian(node* start) {
    node* cur = start;
    int countElements = 0;

    while (cur != NULL) {
        countElements++;
        cur = cur->next;
    }

    cur = start;

    for(int i = 0; i < countElements / 2 - 1; i++) cur = cur->next; 

    float median = (countElements % 2) ? (cur->next->value) :  ((float)(cur->value + cur->next->value) / 2);
    printf("the list's median is: %.1f", median);
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

    node* start = getArray();
    printArray(start);
    findMedian(start);

    return 0;
}