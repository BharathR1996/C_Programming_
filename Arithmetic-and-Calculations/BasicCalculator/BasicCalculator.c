#include<stdio.h>

int main(){

    double data1, data2, result;
    printf("Enter the first Number: \n");
    scanf("%lf", &data1);
    printf("Enter the second Number: \n");
    scanf("%lf", &data2);
    
    result = data1 + data2;

    printf("The result is: %.2f\n", result);
    return 0;

}