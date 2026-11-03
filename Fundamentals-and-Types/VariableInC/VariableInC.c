#include <stdio.h>

int main(){
    // Here i will be creating two varibles one for name and one for age
    // variables are containers and it is a good practice to provide understandable names for the variable
   
    char Name[] = "John";   // collection of characters
    int age = 35;           // integer value stored in a variable

    printf("There once was a man named %s\n", Name);    // When we use %s inside of the printf statement 
                                                        // we want to insert another string
    printf("He was %d Years old. \n", age);             // when we use %d inside of printf statement
                                                        // we want to insert an integer
    printf("He really liked the name %s\n", Name);
    printf("but did not like being %d\n", Name);
    return 0;
}

// Here I have not used any variables and now if i want to change 
// the name from George to John and age from 70 to 35 then
// i need to edit the printf statement