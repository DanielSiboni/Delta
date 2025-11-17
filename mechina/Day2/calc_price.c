/*------------------------------------------------------
* Filename: calc_price.c
* Description: calculate the price of delivery for a package
* Author: Daniel Siboni
-------------------------------------------------------*/

#include <stdio.h>

#define MM_TO_CM ((float)1/10)
#define G_TO_KG ((float)1/1000)

#define FIXED_SHIP_FEE ((float)11/2)
#define COST_PER_KG (11)
#define COST_PER_CMS ((float)3/100)
#define COST_PER_CMS_BY_KG ((float)1/100)

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
    float cost = FIXED_SHIP_FEE + (COST_PER_KG * (kg_weight * G_TO_KG)) + (COST_PER_CMS * area) + (COST_PER_CMS_BY_KG * (area / kg_weight));

    printf("the size of the box: %.2f cm\n", area);
    printf("the weight of the box: %.3f kg\n", kg_weight);
    printf("the cost of the box: %.2f nis\n", cost);


    return 0;
}