  #include<stdio.h>

  int main(){
  
    // how to read a complete string
    char name1[20];
    printf("Enter the name: \n");
    fgets(name1,20, stdin);          // fgets(variable name to store data, size of the variable, stdin)
    printf("Your Name is %s",name1); // One disadvantage here is that when we use fgets a new line will be printed
                                    // When we press enter key it will be considered as new line character
                                    // and will be stored inside the string. 

    return 0;
  }