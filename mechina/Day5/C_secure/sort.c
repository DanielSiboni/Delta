/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: get input from the user in a secure way without using scanf
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define CHUNK_INPUT_SIZE (1024)
#define STRING_ARRAY_SIZE (5)


/*------------------------------------------------------
* Function Name - buffer_contains_newline
*
* Function Purpose - check if buffer contain a '\n' and if so return early
*
* Parameters –  buffer: char*, pointer to the buffer
*               buffer_size: unsigned int, buffer's size
*
* Return Values - unsigned int, buffer's length
*
* Author - Daniel Siboni
-------------------------------------------------------*/
unsigned int buffer_contains_newline(char* buffer, unsigned int buffer_size) {
    unsigned int i = 0;
    for(; i < CHUNK_INPUT_SIZE; i++) {
        if(buffer[i] == '\n')
            return i;
    }
    return i;
}

/*------------------------------------------------------
* Function Name - dyn_scanf
*
* Function Purpose - gets input from the user and save it in a dynamic allocated string
*
* Parameters –  None
*
* Return Values - char*, a pointer to the string
*
* Author - Daniel Siboni
-------------------------------------------------------*/
char* dyn_scanf(void) {

    char user_input_buffer[CHUNK_INPUT_SIZE + 1]; // +1 for null terminator
    char* user_str = (char*)malloc(sizeof(char));
    if(user_str == NULL) exit(EXIT_FAILURE);
    user_str[0] = '\0';

    unsigned long long int str_size = 1;
    fgets(user_input_buffer, CHUNK_INPUT_SIZE, stdin);
    user_input_buffer[CHUNK_INPUT_SIZE] = '\0';

    unsigned int buffer_length = 0;
    while ((buffer_length = buffer_contains_newline(user_input_buffer, CHUNK_INPUT_SIZE)) == CHUNK_INPUT_SIZE || buffer_length) {

        if(buffer_length != CHUNK_INPUT_SIZE)
            user_input_buffer[buffer_length] = '\0';

        if(str_size + buffer_length < str_size) {
            printf("your input is too long\n");
            exit(EXIT_FAILURE);
        }

        str_size += buffer_length;

        user_str = (char*)realloc(user_str, str_size);
        if(user_str == NULL) exit(EXIT_FAILURE);

        if(strcat_s(user_str,buffer_length + 1, user_input_buffer)) {
            printf("error acurred while copying your string\n");
            exit(EXIT_FAILURE);
        }

        if(buffer_length != CHUNK_INPUT_SIZE) break;

        fgets(user_input_buffer, CHUNK_INPUT_SIZE, stdin);
        user_input_buffer[CHUNK_INPUT_SIZE] = '\0';
    }

    return user_str;

}


/*------------------------------------------------------
* Function Name - cmp_by_length
*
* Function Purpose - gets two strings and compare them by length
*
* Parameters –  str1: char*, pointer to the first string
*               str2: char*, pointer to the second string
*
* Return Values - int, positive if st1 > str2, 0 if str1 = str2 and negative if str1 < str2
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int cmp_by_length(char* str1, char* str2) {
    return (strlen(str1) - strlen(str2));
}


/*------------------------------------------------------
* Function Name - cmp_by_alphabet
*
* Function Purpose - gets two strings and compare them by alphabet order
*
* Parameters –  str1: char*, pointer to the first string
*               str2: char*, pointer to the second string
*
* Return Values - int, positive if st1 > str2, 0 if str1 = str2 and negative if str1 < str2
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int cmp_by_alphabet(char* str1, char* str2) {
    return strcmp(str1, str2);
}

/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - gets two pointers and swap their pointing address
*
* Parameters –  a: void**, pointer to the first pointer
*               b: void**, pointer to the second pointer
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void swap(void**  a, void** b) {
    void* tmp = *a;
    *a = *b;
    *b = tmp;
}

/*------------------------------------------------------
* Function Name - sort
*
* Function Purpose - gets an array of pointers and sort it using the cmp function
*
* Parameters –  arr: void*[], an array of pointers
*               arr_len: int, the length of the array
*               cmp: (void*, void*) -> int, the function that compares two cells
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void sort(void* arr[], int arr_len, int (*cmp)(void* a, void* b)) {
    for(int i = 0; i < arr_len - 1; i++) {
        for (int j = 0; j < arr_len - i - 1; j++)
        {
            if(cmp(arr[j], arr[j+1]) > 0)
                swap(arr[j], arr[j+1]);
        }
    }
}

/*------------------------------------------------------
* Function Name - print_string_array
*
* Function Purpose - prints the array of strings
*
* Parameters –  arr: void*[], an array of strings
*               arr_len: int, the length of the array
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void print_string_array(char* arr[], int arr_len) {
    for(int i = 0; i < arr_len - 1; i++) {
        printf("%s,", arr[i]);
    }
    printf("%s\n", arr[arr_len - 1]);

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

    char* string_array[STRING_ARRAY_SIZE] = {0};
    for(int i = 0; i < STRING_ARRAY_SIZE; i++) {
        printf("Enter %d string: ", i + 1);
        string_array[i] = dyn_scanf();
    }

    int (*cmp_function)(char*, char*);

    cmp_function = &cmp_by_length;
    sort(string_array, STRING_ARRAY_SIZE, cmp_function);
    print_string_array(string_array, STRING_ARRAY_SIZE);

    cmp_function = &cmp_by_alphabet;
    sort(string_array, STRING_ARRAY_SIZE, cmp_function);
    print_string_array(string_array, STRING_ARRAY_SIZE);

    for(int i = 0; i < STRING_ARRAY_SIZE; i++) free(string_array[i]);
    
    return 0;
}