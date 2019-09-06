// pointers

#include <stdio.h>

void pointers_to_array (void);

void matrix (void);

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
    /*
     const int* ptr;
     Declares ptr a pointer to const int type.
     You can modify ptr itself but the object pointed to by ptr shall not be modified.
     */
    const int *ptr_ = &i;
    printf("ptr: %d\n", *ptr_);
    // but this produces an error
    // *ptr = 100;
    
    printf("\n\n");
    
    printf("pointers to array \n");
    pointers_to_array();
    
    printf("\n\n");
    
    printf("matrix \n");
    matrix();
    
    return(0);
}

void pointers_to_array (void) {
    int arr[] = { 3, 5, 6, 7, 9 };
    int* p = arr;
    int (*ptr)[5] = &arr;
    
    printf("p = %p, ptr = %p\n", p, ptr);
    printf("*p = %d, *ptr = %p\n", *p, *ptr);
    
    printf("sizeof(p) = %lu, sizeof(*p) = %lu\n",
           sizeof(p), sizeof(*p));
    printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n",
           sizeof(ptr), sizeof(*ptr));
    printf("second element of array: arr[1] or *(p+1) or *((*ptr)+1) = %d,%d,%d \n", arr[1], *(p+1), *((*ptr)+1));
    
    return;
}

void matrix (void) {
    // vars
    int i;
    int j;
    
    // matrix
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            printf("%d      ", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("arr : points to first row - %p \n", arr);
    printf("(arr+1) : points to second row - %p \n", (arr+1));
    printf("*(arr+1)+2 : points third element of the second row - %p \n", *(arr+1)+2);
    
    printf("\n");
    
    printf("**arr : represents the first element of the first row - %d \n", **arr);
    printf("**(arr+1) : represents the first element of the second row - %d \n", **(arr+1));
    printf("*(*(arr+1)+2) : represents the third element of the second row - %d \n", *(*(arr+1)+2));
    
    return;
}
