// libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// helper functions
/*
 function:
 - take a string/ character array as input
 - return nothing -> can add blank 'return;' to line, but it's optional
 */
void no_return_func (char* word) {
    printf("...printing passed in string to void return function...\n");
}
/*
 function:
 - take a string/ character array as input
 - returns an int: the length of the input string
 */
int int_return_func (char* word) {
    int len;
    len = strlen(word);
    return(len);
    // could do: return(strlen(word));
}

/*
 function:
 - take a string/ character array as input
 - returns a float: the length of the input string times pi
 */
float float_return_func (char* word) {
    // vars
    int len;
    float pi;
    float out;
    
    // len
    len = strlen(word);
    
    // pi
    pi = 3.14159265358979323846;
    
    // out
    out = len*pi;
    
    return(out);
    // could do: return(strlen(word)*3.14159265358979323846);
}

/*
 function:
 - take int values as input - row and column size
 - returns an array/ matrix of dim m-by-n
 credit: https://en.wikibooks.org/wiki/C_Programming/stdlib.h/malloc
 */
int** create_matrix (int m, int n)
{
    // init
    int **p, i;
    
    // allocate row memmory
    p = (int **)malloc(m*sizeof(int*));/* this will store base order of all the row in p */
    
    // loop over rows
    for(i = 0; i < m; i++)
        // allocate column memmory
        p[i] = (int *)malloc(n*sizeof(int));/* this will create m row of n elements */
    
    return (p);
}

/*
 function:
 - takes input matrix with memmory allocated by malloc
 - frees memmeory allocated for matrix
 - retruns nothing
 */
void free_matrix (int** ptr, int m) {
    // init value
    int i;
    
    // loop over array
    for (i=0; i<m; i++) {
        free(ptr[i]);
    }
    free(ptr);
    return;
}

/*
 function:
 - take matrix input along with values for the row and column dims
 - prints contents of matrix
 - returns nothing
 */
void print_matrix (int** arr, int m, int n) {
    // init values
    int i;
    int j;
    
    // loop over rows and columns
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("%5d    ", arr[i][j]);
        }
        printf("\n");
    }
    return;
}

/*
 function:
 - take array input along with its length
 - prints contents of array
 - returns nothing
 */
void print_arr (int* arr, int len) {
    // init values
    int i;
    
    // loop over array
    for (i=0; i<len; i++) {
        printf("%d...", arr[i]);
    }
    printf("\n");
}

/*
 function:
 - take matrix input along with values for the row and column dims
 - fills matrix with zeros
 - returns nothing
 */
void fill_matrix_rand (int** arr, int m, int n, int lower, int upper) {
    // init values
    int i;
    int j;
    int temp;
    
    // loop over rows and columns
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            // get rand value from lower to upper, inclusive
            temp = (rand() % (upper-lower+1)) + lower;
            // store value
            arr[i][j] = temp;
        }
    }
    return;
}

/*
function:
 - take array as input along with length and multiplicative factor
 - multiplies array elements by multiplicative factor
 - returns nothing
 */
void mult_arr_by (int* arr, int len, int mult) {
    // init values
    int i;
    
    // loop over array
    for (i=0; i<len; i++) {
        arr[i] *= mult;
    }
    return;
}

/*
 function:
 - take array as input along with length
 - returns minimum element
 */
int minimum (int* arr, int len) {
    // init values
    int i;
    int min;

    // set min to first value
    min = arr[0];

    // loop to update min
    for (i=1; i<len; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return(min);
}

// moving through an array with pointer notation
void pointers_and_arrays (int* arr) {

    printf("arr: %d", *arr);
    //move forward
    arr++;
    printf("...-> arr++ ->");
    printf("...-> %d ->", *arr);
    printf("...-> arr[1] = %d \n", arr[1]);
    
    return;
}



// main function
int main (void) {
    
    // declare string
    char* word = "hello world";
    // where is the string, what is it
    printf("pointer at '%p' and string is '%s'\n", word, word);
    
    // indexing string
    printf("\n...indexing string...\n");
    printf("array index: %c\npointer index: %c\n", word[0], *(word+1));
    printf("\n");
    
    // no return function
    no_return_func(word);
    
    // int return function
    int len;
    len = int_return_func(word);
    printf("len = %d\n", len);
    
    // float return function
    float len_pi;
    len_pi = float_return_func(word);
    printf("len_pi = %f\n", len_pi);
    
    // array return function
    int** arr;
    int m = 3;
    int n = 3;
    printf("creating matrix....\n");
    arr = create_matrix(m,n);
    printf("filling matrix....\n");
    fill_matrix_rand(arr, m, n, 1, 555);
    printf("printing matrix....\n");
    print_matrix(arr, m, n);
    printf("freeing matrix....\n");
    free_matrix(arr, m);
    
    // minimum of array of values
    printf("\n");
    printf("array... length of array and minimum \n");
    int min;
    int arr_2[] = {1,2,3,0,4,5};
    len = sizeof(arr_2)/sizeof(int);
    print_arr(arr_2, len);
    printf("multiplying array by 3...\n");
    mult_arr_by(arr_2, len, 3);
    print_arr(arr_2, len);
    pointers_and_arrays(arr_2);
    min = minimum(arr_2, len);
    printf("array has length %d and minimum value of %d \n", len, min);
    
    return(0);
}

