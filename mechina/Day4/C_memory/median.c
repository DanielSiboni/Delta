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
* Function Name - free_list
*
* Function Purpose - free all the allocated nodes from the list
*
* Parameters –  start: node*, a pointer to the start of the list
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void free_list(node* start) {
    node* pre = start, *cur = pre->next;
    while(cur != NULL) {
        free(pre);
        pre = cur;
        cur = cur->next;
    }
}

/*------------------------------------------------------
* Function Name - count_elements
*
* Function Purpose - count how many elements in the list
*
* Parameters –  start: node*, a pointer to the start of the list
*
* Return Values - int
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int count_elements(node* start) {
    node* cur = start;
    int num_elements = 0;

    while (cur != NULL) {
        num_elements++;
        cur = cur->next;
    }

    return num_elements;
}

/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - swap between two elements in the list
*
* Parameters –  a_parent: node*, a pointer to the parent of the first element
*               a: node*, a pointer to the first element
*               b: node*, a pointer to the second element
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void swap(node* a_parent, node* a, node* b) {
    a_parent->next = b;
    a->next = b->next;
    b->next = a;
}

/*------------------------------------------------------
* Function Name - sort
*
* Function Purpose - sort the list of elements
*
* Parameters –  start: node*, a pointer to the start of the list
*
* Return Values - node*, a pointer to the new start of thge list
*
* Author - Daniel Siboni
-------------------------------------------------------*/
node* sort(node* start) {

    if(!start || !start->next) return start; //check if the first two element are NULL

    node* newStart = start, *cur = start;

    //search for the first smallest node because it will be the new head of the list
    while (cur != NULL) {
        if(newStart->value > cur->value)
            newStart = cur;
        cur = cur->next;
    }

    // special check to sort the first two elements
    if(start->value > start->next->value) {
        node* tmp = start->next;
        start->next = tmp->next;
        tmp->next = start;
        start = tmp;
    }

    //bubble sort
    node* stop = start;
    while (stop != NULL) { //runs as the lenght of the list (instead of searching the list size and then use for loop)
        cur = start;
        while (cur->next->next != NULL) {   // we use cur->next->next because we need to send the parent of the first element of the swap (if we swap a and b we need a_p -> a -> b)
            if(cur->next->value > cur->next->next->value) // check if swap needed
                swap(cur, cur->next, cur->next->next);
            cur = cur->next;
        }
        stop = stop->next;
    }
    
    return newStart;
    
}


/*------------------------------------------------------
* Function Name - get_array
*
* Function Purpose - gets a list of node from the user
*
* Parameters –  None
*
* Return Values - node*, the start of the created list
*
* Author - Daniel Siboni
-------------------------------------------------------*/
node* get_array() {

    int input = 0;
    printf("enter integers, enter a char to stop.\n");

    node* start = (node*)malloc(sizeof(node));
    if(start == NULL) exit(EXIT_FAILURE);

    if(scanf("%d", &input) != 1) {
        printf("you didnt enter any number\n");
        exit(EXIT_FAILURE);
    }

    start->value = input;
    node* cur = start;

    while (scanf("%d", &input) == 1) {
        cur->next = (node*)malloc(sizeof(node));
        if((cur = cur->next) == NULL) {
            free_list(start);
            exit(EXIT_FAILURE);
        }
        cur->value = input;
    }
   
    cur->next = NULL;

    return start;

}


/*------------------------------------------------------
* Function Name - print_array
*
* Function Purpose - prints the list of nodes
*
* Parameters –  start: node*, a pointer to the start of the list
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void print_array(node* start) {
    node* cur = start;
    while (cur != NULL) {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}


/*------------------------------------------------------
* Function Name - find_median
*
* Function Purpose - go through the list to find and print the median
*
* Parameters –  start: node*, a pointer to the start of the list
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void find_median(node* start) {
    int num_elements = count_elements(start);
    node* cur = start;
    
    if(num_elements == 1) {
        printf("the list's median is: %.1f", (float)cur->value);
        return;
    }


    for(int i = 0; i < num_elements / 2 - 1; i++) cur = cur->next; 

    float median = (num_elements % 2) ? ((float)cur->next->value) :  ((float)(cur->value + cur->next->value) / 2);
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

    node* start = get_array();
    start = sort(start);
    print_array(start);
    find_median(start);
    free_list(start);

    return 0;
}