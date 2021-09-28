#include<stdio.h>

int main(){

    int square, cube, input_data;
    printf("Enter the Input value: \n");
    scanf("%d", &input_data);

    square = input_data * input_data;
    cube = input_data * input_data * input_data;

    printf("The Square of the input value is %d and cube is %d\n", square, cube);

    return 0;
}