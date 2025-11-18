/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: print array of integers and chars using a pointer
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>

#define ARRAY_SIZE (8)

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
    int nums[8];
    char chars[8];
    int* nums_ptr = nums;
    char* chars_ptr = chars;

    printf("enter 8 integers:\n");
    for (int i = 0; i < 8; i++) {
        if(scanf("%d", &nums[i]) != 1) {
            printf("invalid num\n");
            return 1;
        }
    }

    printf("enter 8 characters:\n");
    for (int i = 0; i < 8; i++) {
        if(scanf(" %c", &chars[i]) != 1) {
            printf("invalid char\n");
            return 1;
        }
    }

    printf("\n");

    for (int i = 0; i < 8; i++) {
        printf("value: %d, address: %p\n", *(nums_ptr + i), (nums_ptr + i)); 
    } 

    printf("\n");

    for (int i = 0; i < 8; i++) {
        printf("value: %c, address: %p\n", *(chars_ptr + i), (chars_ptr + i)); 
    }

    printf("\n");

    for (int i = 0; i < 8; i++) {
        printf("value: %d, address: %p\n", nums_ptr[i], &nums_ptr[i]); 
    }

    printf("\n");

    for (int i = 0; i < 8; i++) {
        printf("value: %c, address: %p\n", chars_ptr[i], &chars_ptr[i]); 
    } 

    return 0;
}