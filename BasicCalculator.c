#include<stdio.h>

int main(){

    int data1, data2, result;
    printf("Enter the first Number: \n");
    scanf("%d", &data1);
    printf("Enter the second Number: \n");
    scanf("%d", &data2);
    
    result = data1 + data2;

    printf("The result is: %d\n", result);
    return 0;
    
}