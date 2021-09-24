#include<stdio.h>
#include<math.h>

int main(){

    printf("%f\n", 4.0 + 5.5);  // doing this operation between two float numbers will result in float
    printf("%f\n", 5.0 * 4);    // doing this operation between one float and one integer will result in float
    printf("%f\n", 5 + 3);      // doing this operation between two decimal numbers and since format 
                                // specifier is float we will get output as 0.000000
    printf("%d\n", 5/4);        // When this line is executed we get output in the form of decimal number

    printf("%f\n", 5/4.0);      // When this line is executed we get output in the form of float number 
                                // which is the exact output as per the math operation
    printf("%f\n", 5/4);        // doing this operation between two decimal numbers and since format 
                                // specifier is float we will get output as 0.000000

    // Usage of Math Functions

    printf("%d\n", pow(2, 3));  // Here the data output what we get is zero as format specifier is %d

    printf("%f\n", pow(4, 3));  // pow(double number,double exponential) is the syntax where it returns 
                                // the value for example here 4^3 = 64 will be returned
                                // Here we need to use format specifier as %f when using pow() function    
    
    printf("%f\n", sqrt(36));   // sqrt(double number) is the syntax where it returns the sqrt value 
                                // of the number entered as parameter
                                // Here we need to use format specifier as %f when using sqrt() function 
    
    return 0;       
}