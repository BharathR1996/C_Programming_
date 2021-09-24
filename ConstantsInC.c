#include<stdio.h>

int main(){
    /* This part of code is giving an example where we can modify the value of variables*/
    int num = 5;
    printf("%d\n", num);

    num = 8;
    printf("%d\n", num);
    
    /* how to use a constant variable */
    int const num1 = 5;         // constant numbers are read only variables.
                                // we cannot write data into the variables.

    printf("%d\n", num1);

    //num1 = 8;               // this gives me an error i.e. assignment of read only variable
    
    
    return 0;
}