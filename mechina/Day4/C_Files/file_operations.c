/*------------------------------------------------------
* Filename: file_operations.c
* Description: perform some file oprations on a demo file
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

#define MAX_FILE_NAME_LEN (256)
#define MAX_WORD_LEN (100)


/*------------------------------------------------------
* Function Name - read_and_print_file
*
* Function Purpose - read a file and print it's contant
*
* Parameters – fn: char*, the file's name
*
* Return Values - int, for error info
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int read_and_print_file(char* fn) {

    int c = 0;

    FILE* fptr =  fopen(fn, "r");

    if(fptr == NULL) {
        printf("cannot open file\n");
        return CANNOT_OPEN_INPUT_FILE;
    }

    printf("\n%s content:\n", fn);
    while (EOF != (c = fgetc(fptr))) {
        fputc(c, stdout);
    }
    printf("\n");

    if(0 != fclose(fptr)) {
        printf("cannot close file\n");
        return CANNOT_CLOSE_INPUT_FILE;
    }
    
    return 0;
}


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
        return CANNOT_CLOSE_INPUT_FILE;
    }

    if(0 != fclose(out_ptr)) {
        printf("cannot close the output file\n");
        return CANNOT_CLOSE_OUTPUT_FILE;
    }
    
    return 0;
}


/*------------------------------------------------------
* Function Name - is_char
*
* Function Purpose - check if a number is ASCII for letter in the English alphabet
*
* Parameters – fn: char*, the file's name
*
* Return Values - int, 1 for true and 0 for false
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int is_char(int c) {
    if(('a' <= c && 'z' >= c) || ('A' <= c && 'Z' >= c))
        return 1;
    return 0;
}

/*------------------------------------------------------
* Function Name - prints_file_info
*
* Function Purpose - prints information about the text file (num of lines, num of words, num of chars)
*
* Parameters – fn: char*, the file's name
*
* Return Values - int, for error info
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int prints_file_info(char* fn) {
    int c = 0;
    int pc = 0;

    int numOfLines = 0;
    int numOfWords = 0;
    int numOfChars = 0;

    FILE* fptr =  fopen(fn, "r");

    if(fptr == NULL) {
        printf("cannot open file\n");
        return CANNOT_OPEN_INPUT_FILE;
    }

    while (EOF != (c = fgetc(fptr))) {
        if(is_char(c))
            numOfChars++;

        if((c == ' ' || c == '\n') && pc && (is_char(pc) || pc == '.' || pc == ',' || pc == '?' || pc == '!'))
            numOfWords++;

        if(c == '\n') {
            numOfLines++;
        }

        pc = c;
    }

    if(pc != ' ' && pc != '\n') {
        numOfWords++;
        numOfLines++;
    }

    printf("\n%s content:\n", fn);
    printf("%d\n%d\n%d\n", numOfLines, numOfWords, numOfChars);


    if(0 != fclose(fptr)) {
        printf("cannot close file\n");
        return CANNOT_CLOSE_INPUT_FILE;
    }
    
    return 0;
}

/*------------------------------------------------------
* Function Name - earase_line_from_file
*
* Function Purpose - earase a line from a text file
*
* Parameters –  line: int, the number of the line we should earase
*               fn: char*, the file's name
*
* Return Values - int, for error info
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int earase_line_from_file(int line, char* fn) {
    
    char buff[100];
    int n = sizeof(buff);

    FILE* fptr =  fopen(fn, "r+");

    if(fptr == NULL) {
        printf("cannot open file\n");
        return CANNOT_OPEN_INPUT_FILE;
    }

    FILE* temp_fptr =  fopen("temp.txt", "w");

    if(temp_fptr == NULL) {
        printf("cannot open file\n");
        return CANNOT_OPEN_INPUT_FILE;
    }

    while (fgets(buff, n, fptr) != NULL) {
        if(strlen(buff) < n)
            line--;

        if(line == 0)
            continue;

        fputs(buff, temp_fptr);
    }

    if(0 != fclose(fptr)) {
        printf("cannot close file\n");
        return CANNOT_CLOSE_INPUT_FILE;
    }

    if(0 != fclose(temp_fptr)) {
        printf("cannot close file\n");
        return CANNOT_CLOSE_INPUT_FILE;
    }

    if (remove(fn) != 0) {
        printf("cannot remove file\n");
        return CANNOT_RMOVE_FILE;
    }

    if (rename("temp.txt", fn) != 0) {
        printf("cannot rename file\n");
        return CANNOT_RENAME_FILE;
    }
    
    return 0;
    
}

/*------------------------------------------------------
* Function Name - count_appearences_in_file
*
* Function Purpose - count the apearences of string s in file fn
*
* Parameters –  s: char*, the string we are searching for
*               fn: char*, the file's name
*
* Return Values - int, how many time s apears in the file called fn
*
* Author - Daniel Siboni
-------------------------------------------------------*/
int count_appearences_in_file(char* s, char* fn) {

    int count = 0;
    int c = 0;

    FILE* fptr =  fopen(fn, "r");

    if(fptr == NULL) {
        printf("cannot open file\n");
        return CANNOT_OPEN_INPUT_FILE;
    }

    char* temp_s = s;
    while (EOF != (c = fgetc(fptr))) {
        if(*temp_s == c) {
            temp_s++;
        } else {
            temp_s = s;
        }

        if(*temp_s == '\0') {
            count++;
            temp_s = s;
        }
    }

    printf("%s apears in the file %d times\n", s, count);

    if(0 != fclose(fptr)) {
        printf("cannot close file\n");
        return CANNOT_CLOSE_INPUT_FILE;
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
    char output_file[MAX_FILE_NAME_LEN];
    
    printf("please enter the input's file name: ");
    if(scanf("%s", input_file) != 1) exit(EXIT_FAILURE);
    if(read_and_print_file(input_file) < 0) exit(EXIT_FAILURE);

    printf("please enter the output's file file name: ");
    if(scanf("%s", output_file) != 1) exit(EXIT_FAILURE);

    if(read_and_copy_file(input_file, output_file) < 0) exit(EXIT_FAILURE);
    if(read_and_print_file(output_file) < 0) exit(EXIT_FAILURE);

    if(prints_file_info(input_file) < 0) exit(EXIT_FAILURE);

    unsigned int line = 0;

    printf("please enter a line to earase: ");
    if(scanf("%d", &line) != 1) {
        printf("invalid number\n");
        exit(EXIT_FAILURE);
    }

    if(earase_line_from_file(line, input_file) < 0) exit(EXIT_FAILURE);

    char word[MAX_WORD_LEN];

    printf("please enter a word to check for apearence in the file: ");
    if(scanf("%s", word) != 1) exit(EXIT_FAILURE);

    if(count_appearences_in_file(word, input_file) < 0) exit(EXIT_FAILURE);

}