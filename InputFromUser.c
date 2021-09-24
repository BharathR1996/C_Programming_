#include<stdio.h>

int main(){
        // how to read a character
    char grade;
    printf("Enter your Grade: \n");
    scanf("%c", &grade);
    printf("Your Grade is %c \n", grade);

    // how to read an integer value
    int Age;        // declaring a variable
    printf("Enter your Age: \n");
    scanf("%d", &Age);  // It is used to take input from the user
                        // &Age is known as a pointer here
    printf("You are %d years old\n", Age);
    
    //how to read a double value
    double gpa;
    printf("Enter your gpa: \n");
    scanf("%lf", &gpa);                 // when taking input from user for double, we need to use %lf
    printf("Your gpa is %f\n", gpa);    // when printing the double value we can use %f as format specifier


    return 0;
}