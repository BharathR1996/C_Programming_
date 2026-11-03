#include<stdio.h>

int main(){

    int Num1, Num2;

    printf("Enter the Value of Num1: \n");
    scanf("%d", &Num1);
    printf("Enter the Value of Num2: \n");
    scanf("%d", &Num2);

    if(Num1>Num2){
        printf("Num1 = %d is the largest of the two numbers", Num1);
    }
    else{
        printf("Num2 = %d is the largest of the two numbers", Num2);
    }
    return 0;
}