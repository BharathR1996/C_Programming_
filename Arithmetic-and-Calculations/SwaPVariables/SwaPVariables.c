#include<stdio.h>

int main( ){

    int var_1, var_2;
    printf("Enter the values of Variable 1 and 2: \n");
    scanf("%d%d",&var_1,&var_2);
    printf("The data stored in variable1 is %d variable2 is %d\n", var_1, var_2);

    var_1 = var_1 + var_2;
    var_2 = var_1 - var_2;
    var_1 = var_1 - var_2;

    printf(" The values entered are swapped\n variable1 =%d\n variable2 = %d\n", var_1, var_2);

    return 0;
}