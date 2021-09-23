#include<stdio.h>

int main(){

// BASIC DATATYPES
    // integer is basically a whole number
    int age = 25;       // no quotation or paranthesis is required
    float decimal = 5.8;    // decimal numeber can be stored using float

    // single character can be stored inside a variable
    char grade = 'A'; // A character has to be stored using Single quotes

    //To Create a String
    char phrase[] = "My Name is Bharath"; // To create a string we need to use double quotes

    // It is a function which prints the data on the screen
    // To create a new line we can use \n
    // for quotation we need to use \"
    printf("Hello \"This program is very important\"\n");

    printf("The variable of type integer is storing %d\n", age);  
    printf("The variable of type float is storing %f\n", decimal);
    printf("The variable of type char is storing %c\n", grade);
    printf("The variable of type phrase is storing %s", phrase);    

    return 0;
}