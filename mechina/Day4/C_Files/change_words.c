/*------------------------------------------------------
* Filename: dynamic_struct.c
* Description: gets two times from the user and then add them together.
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANNOT_OPEN_INPUT_FILE (-1)
#define CANNOT_OPEN_OUTPUT_FILE (-2)
#define CANNOT_CLOSE_INPUT_FILE (-3)
#define CANNOT_CLOSE_OUTPUT_FILE (-4)
#define CANNOT_RMOVE_FILE (-5)
#define CANNOT_RENAME_FILE (-6)

#define MAX_FILE_NAME_LEN (64)
#define BUFFER_SIZE (1024)
#define LINE_SIZE (1024)
#define WORD_SIZE (128)
#define TEMP_FILE_NAME "temp.txt"


/*------------------------------------------------------
* Function Name - read_and_copy_file
*
* Function Purpose - read a file and copy it's contant to another file
*
* Parameters –  in_f: char*, the input file's name
*               out_f: char*, the output file's name
*
* Return Values - int, for error info
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int read_and_copy_file(char* in_f, char* out_f) {

    int c = 0;

    FILE* in_ptr =  fopen(in_f, "r");
    if(in_ptr == NULL) {
        printf("cannot open the input file\n");
        return CANNOT_OPEN_INPUT_FILE;
    }

    FILE* out_ptr =  fopen(out_f, "w");
    if(out_ptr == NULL) {
        printf("cannot open the output file\n");
        return CANNOT_OPEN_OUTPUT_FILE;
    }

    while (EOF != (c = fgetc(in_ptr))) {
        fputc(c, out_ptr);
    }

    if(0 != fclose(in_ptr)) {
        printf("cannot close the input file\n");
        fclose(in_ptr);
        return CANNOT_CLOSE_INPUT_FILE;
    }

    if(0 != fclose(out_ptr)) {
        printf("cannot close the output file\n");
        return CANNOT_CLOSE_OUTPUT_FILE;
    }
    
    return 0;
}



int change_words(char* fn, char* fn_copy) {
    FILE* fptr =  fopen(fn, "w");
    if(fptr == NULL) {
        printf("cannot open the first file\n");
        return CANNOT_OPEN_INPUT_FILE;
    }

    FILE* copy_ptr =  fopen(fn_copy, "r");
    if(copy_ptr == NULL) {
        printf("cannot open the second file\n");
        return CANNOT_OPEN_OUTPUT_FILE;
    }

    char buffer[BUFFER_SIZE] = {0};
    char line[LINE_SIZE] = {0};
    char word[WORD_SIZE] = {0};

    int which_word = 0;

    memset(buffer,'\0', BUFFER_SIZE);

    int count = 5;

    while (1) {
        if(!(count--))
            exit(EXIT_SUCCESS);
        
        memset(line,'\0', LINE_SIZE);
        
        while(fgets(buffer, BUFFER_SIZE, copy_ptr)) {
            
            memset(word,'\0', WORD_SIZE);

            int word_number = 0;
            int start = 0;

            for (;start < BUFFER_SIZE && (buffer[start] != '\0'); start++) {
                if(which_word == word_number) break;
                if(buffer[start] == ' ')
                    word_number++;
            }


            start += (which_word > 0);
            
            for (int i = 0; (i < WORD_SIZE && (start + i) < BUFFER_SIZE && buffer[start + i] != '\0' && buffer[start + i] != ' '); i++) {
                word[i] = buffer[start + i];
            }

            
            if(word[0] != '\0') {
                strcat(line, word);
                strcat(line, " ");
            }
        }
        
        if(line[0] == '\0') break;
        strcat(line, "\n");
        fprintf(fptr, line);
        rewind(copy_ptr);
        which_word++;

    }
    

    if(0 != fclose(fptr)) {
        printf("cannot close the first file\n");
        fclose(copy_ptr);
        return CANNOT_CLOSE_INPUT_FILE;
    }

    if(0 != fclose(copy_ptr)) {
        printf("cannot close the second file\n");
        return CANNOT_CLOSE_OUTPUT_FILE;
    }
    
    return 0;
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

    char input_file[MAX_FILE_NAME_LEN];
    char output_file[MAX_FILE_NAME_LEN] = TEMP_FILE_NAME;
    
    printf("please enter the input file's name: ");
    if(scanf("%s", input_file) != 1) exit(EXIT_FAILURE);

    // if(read_and_copy_file(input_file, output_file) < 0) exit(EXIT_FAILURE);
    if(change_words(input_file, output_file) < 0) exit(EXIT_FAILURE);

    return 0;
}