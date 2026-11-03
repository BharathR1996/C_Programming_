#include<stdio.h>

int main(){
    float P, N, R;
    float simple_interest;
    printf("Enter the value of P, N and R: \n");
    scanf("%f%f%f",&P, &N, &R);
    simple_interest = (P*N*R)/100;

    printf(" The Simple Interest is: %f\n", simple_interest);

    return 0;

}