// all about arrays

#include <stdio.h>

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
    int i;
    for (i=0; i<10; i++) {
        array[i] = i;
        printf("%d...", i);
    }
    printf("\n");
    
    // character array
    char word[] = {'h','e','l','l','o'};
    for (int i = 0; i<5; i++) {
        printf("%c", word[i]);
    }
    printf("\n");
}

