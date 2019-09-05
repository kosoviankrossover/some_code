// all about arrays

#include <stdio.h>
#include <string.h> // contains string length, comparison, concat
#include <stdlib.h>

// array print
void arr_print (int arr[], int n);

int main (void) {
    // declare array of size 10 of integer values
    int array[10];

    // what is in the ith position? i.e. index i-1
    // sinxe arrays are 0 indexed
    int index = 2;
    printf("in position %d we have a value of %d \n", index, array[index]);
    // we see that the array is instantiate with 0s

    // store in position i a value of j
    index = 4;
    array[index] = 83;
    printf("in position %d we have a value of %d \n", index, array[index]);

    // looping through an array
    printf("looping through an array \n");
    int i;
    for (i=0; i<10; i++) {
        array[i] = i;
        printf("%d...", i);
    }
    printf("\n\n");
    
    // initializes array of size 4
    int n = 4;
    int arr_1[] = {1,2,3,4};
    arr_print(arr_1, n);
    
    // initializes array of size 4
    int arr_2[4] = {1,2,3,4};
    arr_print(arr_2, n);
    
    // intialize array of size 6
    // first four vallues are initialized
    int arr_3[6] = {1,2,4,4};
    arr_print(arr_3, n);
    
    printf("\n\n");
    
    // multi-dim arrays
    // matrix here- filled by rows
    int matrix[4][4] = {
        {1,0,0,0},
        {0,1,100,0},
        {0,0,1,0},
        {0,0,0,1}
    };
    printf("row 2, column three entr of matrixy = %d", matrix[1][2]);
    
    printf("\n\n");
    
    // character array
    printf("character array... \n");
    char word[] = {'h','e','l','l','o'};
    for (int i = 0; i<5; i++) {
        printf("%c", word[i]);
    }
    
    printf("\n\n");
    
    printf("strings...\n");
    
    // strings as character arrrays
    // Strings in C are actually arrays of characters
    // use pointers to a character array to define simple strings
    char* str_1 = "Hello world 1";
    // This method creates a string which we can only use for reading.
    // If we wish to define a string which can be manipulated, we will
    // need to define it as a local character array:
    char str_2[] = "Hello world 2";
    printf("%s ... %s \n", str_1, str_2);
    
    // str length
    int len_1 = strlen(str_1);
    int len_2 = strlen(str_2);
    if (len_1 == len_2) {
        printf("lengths are the same \n");
        // string comparison
        if (strncmp(str_1, str_2, len_1) != 0) {
            printf("but the strings are different\n");
        }
    }
    // string concatenation
    char dest[20]="Hello";
    char src[20]="World";
    strncat(dest,src,3);
    printf("%s\n",dest);
    strncat(dest,src,20);
    printf("%s\n",dest);
    
    printf("\n\n");
    
    // stack vs heap
    int a_1[3] = {1,2,3}; // stored in stack
    int* a_2 = (int*) malloc(3*sizeof(int));
    for (i=0; i<3; i++) {
        a_2[i] = i+4;
    }
    printf("heap: ");
    for (i=0; i<3; i++) {
        printf("%d...", a_2[i]);
    }
    printf("\n");
    printf("%p \n", a_2);
    free(a_2);
    printf("%p \n", a_2);
    a_2 = NULL;
    printf("%p \n", a_2);
    
    return(0);
}

void arr_print (int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d...", arr[i]);
    }
    printf("\n");
}
