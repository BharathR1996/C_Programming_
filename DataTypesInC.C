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

    //format specifier tells the printf function to print data which is other than text
    printf("The variable of type integer is storing %d\n", age);    // %d is used as format specifier for decimal numbers
    printf("The variable of type float is storing %f\n", decimal);  // %f is used as format specifier for float numbers
    printf("The variable of type char is storing %c\n", grade);     // %c is used as format specifier for characters
    printf("The variable of type phrase is storing %s", phrase);    // %s is used as format specifier for string

    printf("My Favourite %s is %d", "number", 500); // Here we are directly passing the string
                                                    // and decimal value in printf function

    

    return 0;
}