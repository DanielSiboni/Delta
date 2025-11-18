/*------------------------------------------------------
* Filename: array_sort.c
* Description: sort an array of pointers based on their pointed variables values.
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>

#define ARRAY_SIZE (10)


/*------------------------------------------------------
* Function Name - printArray
*
* Function Purpose - print the values of an integer array using a pointer to a pointers array
* Parameters –  nums_ptr: const int**, a pointer to an array of pointers to cells from an const in array
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void printArray(const int** nums_ptr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("value: %d, address: %p\n", *(nums_ptr[i]), *(nums_ptr + i)); 
    } 
    printf("\n\n");
}

/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - swap between to const int* pointer values
*
* Parameters –  a: const int**, a pointer to the first const int*
*               b: const int**, a pointer to the second const int*
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void swap(const int** a, const int** b) {
    const int *tmp = *a;
    *a = *b;
    *b = tmp;
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
    const int nums[ARRAY_SIZE];
    const int* nums_ptr[ARRAY_SIZE];

    printf("enter 10 integers:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        nums_ptr[i] = &(nums[i]);
        if(scanf("%d", &nums[i]) != 1) {
            printf("invalid num\n");
            return 1;
        }
    }

    printArray(nums_ptr);

    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - 1 - i; j++) {
            if (*(nums_ptr[j]) > *(nums_ptr[j+1]))
                swap(&(nums_ptr[j]), &(nums_ptr[j+1]));

        }
    }

    printArray(nums_ptr);

}