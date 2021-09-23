#include<stdio.h>

int main(){

    printf("%f\n", 4.0 + 5.5);  // doing this operation between two float numbers will result in float
    printf("%f\n", 5.0 * 4);  // doing this operation between one float and one integer will result in float
    printf("%f\n", 5 + 3);  // doing this operation between two decimal numbers and since format 
                            // specifier is float we will get output as 0.000000
    return 0;
}