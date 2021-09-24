#include<stdio.h>

int main(){
    int Age;        // declaring a variable
    printf("Enter your Age: \n");
    scanf("%d", &Age);  // It is used to take input from the user
                        // &Age is known as a pointer here
    printf("You are %d years old\n", Age);

    
    return 0;
}