#include<stdio.h>

int main(){
    int data; 
    float perimeter, area;
    printf("Enter the radius of the circle: \n");
    scanf("%d", &data);
    perimeter = 2 * 3.14 * data;
    area = 3.14 * (data*data);

    printf("Perimeter of the Circle = %f\n", perimeter);
    printf("Area of the circle = %f\n", area);

    return 0;
}