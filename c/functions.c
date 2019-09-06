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
int** creare_arr (int m, int n)
{
    int **p, i;
    p = (int **)malloc(m*sizeof(int*));/* this will store base order of all the row in p */
    for(i = 0; i < m; i++)
        p[i] = (int *)malloc(n*sizeof(int));/* this will create m row of n elements */
    return p;
}

void free_arr (int** ptr, int m) {
    int i;
    for (i=0; i<m; i++) {
        free(ptr[i]);
    }
    free(ptr);
    return;
}

void print_arr (int** arr, int m, int n) {
    int i;
    int j;
    
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("%d    ", arr[i][j]);
        }
        printf("\n");
    }
    return;
}

void fill_arr (int** arr, int m, int n) {
    int i;
    int j;
    
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            arr[i][j] = 0;
        }
    }
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
    arr = creare_arr(m,n);
    fill_arr(arr, m, n);
    print_arr(arr, m, n);
    free_arr(arr, m);
    
    return(0);
}

