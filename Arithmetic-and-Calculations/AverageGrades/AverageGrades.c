#include<stdio.h>

int main(){

    float Grade1, Grade2, Grade3, Sum, Average;

    printf("Enter the Grade 1 value: \n");
    scanf("%f", &Grade1);
    printf("Enter the Grade 2 value: \n");
    scanf("%f", &Grade2);
    printf("Enter the Grade 3 value: \n");
    scanf("%f", &Grade3);

    Sum = Grade1 + Grade2 + Grade3;
    Average = Sum/3;

    printf("The average of the Grades are: %f\n", Average);

    return 0;

}