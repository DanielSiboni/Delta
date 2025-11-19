/*------------------------------------------------------
* Filename: remove_dup.c
* Description: removes duplicates from an array using three functions that has diff params
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE (20)

/*------------------------------------------------------
* Function Name - prinArr
*
* Function Purpose - prints an array
*
* Parameters –  arr: int*, pointer to the array
*               len: int, the length of the array
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void prinArr(int* arr, int len) {
    if(arr == NULL) return;

    for(int i = 0; i < len; i++) {
        printf("%d -> ", arr[i]);
    }
    printf("\n");
}

/*------------------------------------------------------
* Function Name - count_diff_elements
*
* Function Purpose - count how many different elements there are in the array
*
* Parameters –  arr: int*, pointer to the array
*               len: int, the length of the array
*
* Return Values - int
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int count_diff_elements(int* arr, int len) {
    int count_diff_elements = 1;
    for(int i = 0; i < len - 1; i++) {
        if(arr[i] != arr[i + 1])
            count_diff_elements++;
    }
    return count_diff_elements;
}


/*------------------------------------------------------
* Function Name - removeDup1
*
* Function Purpose - create new array without duplicates
*
* Parameters –  arr: int*, pointer to the initial array
*               len: int, the length of the initial array
*               no_dup_len: int*, pointer to a variable that will hold the new array's length
*
* Return Values - int*, the new array
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int* removeDup1(int* arr, int len, int* no_dup_len) {
    int diff_elements = count_diff_elements(arr, len);
    
    int* no_dup_arr = (int*)malloc(diff_elements * sizeof(int));
    if(no_dup_arr == NULL) return NULL;
    
    *no_dup_len = diff_elements;

    for (int i = 0; i < diff_elements; i++) {
        no_dup_arr[i] = *arr;
        while (*arr == *((arr++) + 1));
    }

    return no_dup_arr;
}


/*------------------------------------------------------
* Function Name - removeDup2
*
* Function Purpose - create new array without duplicates
*
* Parameters –  arr: int*, pointer to the initial array
*               len: int, the length of the initial array
*               no_dup_arr: int**, pointer to a variable that will point to the new array
*
* Return Values - int, the new array's length
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int removeDup2(int* arr, int len, int** no_dup_arr) {
    int diff_elements = count_diff_elements(arr, len);
    
    *no_dup_arr = (int*)malloc(diff_elements * sizeof(int));
    if(*no_dup_arr == NULL) return -1;

    for (int i = 0; i < diff_elements; i++) {
        (*no_dup_arr)[i] = *arr;
        while (*arr == *((arr++) + 1));
    }

    return diff_elements;
}

/*------------------------------------------------------
* Function Name - removeDup2
*
* Function Purpose - create new array without duplicates
*
* Parameters –  arr: int*, pointer to the initial array
*               len: int, the length of the initial array
*               no_dup_arr: int**, pointer to a variable that will point to the new array
*               no_dup_len: int*, pointer to a variable that will hold the new array's length
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void removeDup3(int* arr, int len, int** no_dup_arr, int* no_dup_len) {
    int diff_elements = count_diff_elements(arr, len);
    
    *no_dup_arr = (int*)malloc(diff_elements * sizeof(int));
    if(*no_dup_arr == NULL) return;

    *no_dup_len = diff_elements;
    
    for (int i = 0; i < diff_elements; i++) {
        (*no_dup_arr)[i] = *arr;
        while (*arr == *((arr++) + 1));
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
    int arr[ARRAY_SIZE] = {1, 1, 2, 2, 2, 3, 4, 5, 5, 6, 6, 7, 8, 8, 8, 9, 9, 10, 11, 11};

    prinArr(arr, ARRAY_SIZE);

    int no_dup_len1 = 0;
    int* no_dup_arr1 = removeDup1(arr, ARRAY_SIZE, &no_dup_len1);
    if(no_dup_arr1 == NULL) exit(EXIT_FAILURE);
    prinArr(no_dup_arr1, no_dup_len1);

    int* no_dup_arr2 = NULL;
    int no_dup_len2 = removeDup2(arr, ARRAY_SIZE, &no_dup_arr2);
    if(no_dup_len2 == -1) {
        free(no_dup_arr1);
        exit(EXIT_FAILURE);
    }
    prinArr(no_dup_arr2, no_dup_len2);

    int no_dup_len3 = 0;
    int* no_dup_arr3 = NULL;
    removeDup3(arr, ARRAY_SIZE, &no_dup_arr3, &no_dup_len3);
    if(no_dup_arr3 == NULL) {
        free(no_dup_arr1);
        free(no_dup_arr2);
        exit(EXIT_FAILURE);
    }
    prinArr(no_dup_arr3, no_dup_len3);


}