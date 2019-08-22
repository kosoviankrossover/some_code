// pointers

#include <stdio.h>

int main(void){
    // a pointer
    printf("pointers...\n");
    int i;
    int j;
    int* ptr;
    
    i = 1;
    j = 2;
    
    // let ptr point towards the location holding i
    ptr = &i;
    
    // print the dereferenced ptr
    printf("i=1;\nj=2;\nptr = &i;\n");
    printf("The value at the dereferenced ptr: %d \n", *ptr);
    
    // let ptr point towards the location holding j
    ptr = &j;
    // print the dereferenced ptr
    printf("ptr = &j;\n");
    printf("The value at the dereferenced ptr: %d \n", *ptr);
    
    // lets store something else to where ptr points
    *ptr = 30;
    printf("*ptr = 30;\n");
    printf("The value at the dereferenced ptr: %d \n", *ptr);
    
    // whats stored in j now tho?
    printf("whats stored in i now tho?\n");
    printf("i = %d \n", i);
    printf("whats stored in j now tho?\n");
    printf("j = %d \n", j);
    
    
    
    
    /*
     We can change the pointer to point to any other integer variable,
     but cannot change the value of the object (entity) pointed using
     pointer ptr.
     */
    printf("\n\n");
    printf("constant pointer...\n");
    
    // constant pointer - this is fine
    const int *ptr_ = &i;
    printf("ptr: %d\n", *ptr_);
    // but this produces an error
    // *ptr = 100;
    
    return(0);
}
