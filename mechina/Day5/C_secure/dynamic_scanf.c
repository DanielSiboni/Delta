/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: get input from the user in a secure way without using scanf
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_INPUT_SIZE (1024)


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

    printf("please enter a string followd by enter\n");
    char* user_str = dyn_scanf();

    printf("user's string:\n%s", user_str);

    free(user_str);
    
    return 0;
}