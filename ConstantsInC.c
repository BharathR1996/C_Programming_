#include<stdio.h>

int main(){
    /* This part of code is giving an example where we can modify the value of variables*/
    int num = 5;
    printf("%d\n", num);

    num = 8;
    printf("%d\n", num);
    
    /* how to use a constant variable */

    // Generally programmers declare constants using uppercase letters just to distinguish between constants and variables
    int const NUM1 = 5;         // constant numbers are read only variables.
                                // we cannot write data into the variables.
    const int NUM2 = 8;         // we can declare a constant integer as 
                                                    // int const variable_name (OR) const int variable_name

    printf("%d\n", NUM1);
    printf("%d\n", NUM2);
    //num1 = 8;               // this gives me an error i.e. assignment of read only variable
    
    printf("%d\n", 90);     // This is also considered as constants
    printf("Hello\n");      // This is also considered as constants
    return 0;
}