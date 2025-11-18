/*------------------------------------------------------
* Filename: encryption.c
* Description: decrypt a secret message to help Gargamel
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>

#define MESSAGE_SIZE 26

/*------------------------------------------------------
* Function Name - decreaseByFive
*
* Function Purpose - decrease cells value by 5
*
* Parameters –  arr: char*, holds the array we edit
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void decreaseByFive(int* const arr) {
    for(int i = 0; i < MESSAGE_SIZE; i++) {
        arr[i] -= 5;
    }
}

/*------------------------------------------------------
* Function Name - evenCellsDivideBySeven
*
* Function Purpose - divide evens cells value by 7
*
* Parameters –  arr: char*, holds the array we edit
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void evenCellsDivideBySeven(int* const arr) {
    for(int i = 0; i < MESSAGE_SIZE / 2; i++) {
        arr[i * 2 ] /= 7;
    }
}


/*------------------------------------------------------
* Function Name - decreaseByPreCell
*
* Function Purpose - decrease each cell value by the previous cell's value in a array
*
* Parameters –  arr: char*, holds the array we edit
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void decreaseByPreCell(int* const arr) {
    for(int i = 1; i < MESSAGE_SIZE; i++) {
        arr[i] -= arr[i-1];
    }
}

/*------------------------------------------------------
* Function Name - arrayRotation
*
* Function Purpose - rotate the array to the right
*
* Parameters –  arr: char*, holds the array we edit
*               times: int, how many rotations we should do 
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void arrayRotation(int* const arr, int times) {
    for(int j = 0; j < times; j++) {
        int lastValue = arr[MESSAGE_SIZE - 1];
        for(int i = MESSAGE_SIZE - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = lastValue;
    }

}

/*------------------------------------------------------
* Function Name - switchSides
*
* Function Purpose - switch between both sides of an array
*
* Parameters –  arr: char*, holds the array we edit
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void switchSides(int* const arr) {
    for(int i = 0; i < MESSAGE_SIZE / 2; i++) {
        arr[i] = arr[i] ^ arr[(i + (MESSAGE_SIZE/2)) % MESSAGE_SIZE];
         arr[(i + (MESSAGE_SIZE/2)) % MESSAGE_SIZE] ^= arr[i];
         arr[i] ^=  arr[(i + (MESSAGE_SIZE/2)) % MESSAGE_SIZE];
    }
}


/*------------------------------------------------------
* Function Name - decrypt
*
* Function Purpose - do the decryption steps in a sequence order
*
* Parameters –  message: char*, holds the message we try to decrypt
*
* Return Values - void
*
* Author - Daniel Siboni
-------------------------------------------------------*/
void decrypt(int* const message) {

    switchSides(message);

    decreaseByPreCell(message);

    arrayRotation(message, 5);

    evenCellsDivideBySeven(message);

    arrayRotation(message, MESSAGE_SIZE - 4);

    decreaseByFive(message);
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
    int message[MESSAGE_SIZE];

    printf("please enter 26 numbers:\n");
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        scanf("%d", &message[i]);
    }


    decrypt(message);

    for (int i = 0; i < MESSAGE_SIZE; i++) {
        printf(" %c", (char)message[i]);
    }
    printf("\n");
    
}