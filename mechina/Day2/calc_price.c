/*------------------------------------------------------
* Filename: calc_price.c
* Description: calculate the price of delivery for a package
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>

#define MM_TO_CM ((float)1/10)
#define G_TO_KG ((float)1/1000)
#define AGOROT_TO_SHEKEL ((float)1/100)

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
    int length, width, weight;

    printf("please enter the length of the box in millimeters: ");
    scanf("%d", &length);
    
    printf("please enter the width of the box in millimeters: ");
    scanf("%d", &width);

    printf("please enter the weigth of the box in grams: ");
    scanf("%d", &weight);

    float area = (length * MM_TO_CM) * (width * MM_TO_CM);
    float kg_weight = weight * G_TO_KG;
    float cost = 5.5 + (11 * (kg_weight * G_TO_KG)) + ((3 * AGOROT_TO_SHEKEL) * area) + ((1 * AGOROT_TO_SHEKEL) * (area / kg_weight));

    printf("the size of the box: %.2f cm\n", area);
    printf("the weight of the box: %.3f kg\n", kg_weight);
    printf("the cost of the box: %.2f nis\n", cost);


    return 0;
}