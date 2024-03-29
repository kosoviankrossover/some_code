// this is a one line comment

// include a header file
// this header in particular includes the printf function that we often use
#include <stdio.h>

// header file containing the bool type
#include <stdbool.h>

// define an alias
#define SUCCESS 0

/* This is a multi-line comment.
We are declaring a helper function that will provide some function for our
main program. The int before the function declaration indicates that we expect
to return an integer. */
int helper_function(int a, int b);

/* This is the main function of the program. */
int main(){

     // declare an integer
    int i,j;
    
    i = 8;
    
    // condition if statement
    // check equality -> ==
    // check less/ greater than -> < or >
    // check less/ greater than or equal -> <= or >=
    // check inequality -> !=
    if (i == 8) {
        printf("equality conditional... i = 8\n");
    }
    
    // if/else
    if (i < 8) {
        printf("i < 8\n");
    }
    else {
        printf("i >= 8\n");
    }
    
    // if else then
    if (i<8) {
        printf("i < 8\n");
    }
    else if (i>8) {
        printf("i > 8\n");
    }
    else {
        printf("i = 8\n");
    }
    
    // more complex conditionals
    j = 10;
    // AND
    if ( i>5 && j < 15) {
        printf("i>5 && j < 15 \n");
    }
    // OR
    if ( i>5 || j > 15) {
        printf("i>5 || j > 15 \n");
    }
    
    printf("\n\n");
    
    // switch statements
    printf("switch statements...\n");
    switch (i) {
        case 1:
            printf("1\n");
            break;
        case 10:
            printf("10\n");
            break;
        default:
            printf("i != 1 or 10 \n");
    }
    
    i = 10;
    
    // above is same as
    if (i == 1) {
        printf("1\n");
    }
    else if (i == 10) {
        printf("10\n");
    }
    else {
        printf("i != 1 or 10 \n");
    }
    
    printf("\n\n");
    
    // conditional operator
    // condition ? expression_1 : expression_2
    // if {condition} is TRUE then expression_1 is evaluated
    // if {condition} is FALSE then expression_2 is evaluated
    printf("conditional operator\n");
    printf("%d\n", i);
    j = (i < 0) ? -1 : 1;
    printf("%d \n", j);
    
    printf("\n\n");
    
    // simple for loop addition
    printf("using a loop....\n");
    printf("i + j -- looping over j\n");
     for (int j=0; j<3; j++){
         printf("%d + %d = %d\n",i,j,i+j);
     }
    
    printf("\n");
    printf("\n");

	// use our helper function to add the two variables
    j = 4;
    int sum;
    sum = helper_function(i,j);
	// print the result
    printf("using a helper function to add....\n");
	printf("%d + %d = %d \n", i, j, sum);

    printf("\n");
    printf("\n");
    
    // octal notaion - base 8 numbers
    // in base 8, the number 40 is expressed as 50
    // to declare a variable in base 8, use a preceeding 0
    int octal = 050;
    printf("The number \'%o\' in base 8 is equal to %d in base 10\n", octal, octal);
    
    printf("\n");
    printf("\n");
    
    // floating point values
    float flt_ex = 3.87;
    printf("This is me printing a float: \'%f\'\n", flt_ex);
    printf("Printing only the first two decimal values: %.2f\n", flt_ex);
    
    printf("\n");
    printf("\n");
    
    // boolean and some if statements
    printf("boolean condtionals...\n");
    bool boolvar1 = false;
    bool boolvar2 = true;
    if (boolvar1) {
        printf("boolvar1 is true\n");
    }
    else if (boolvar2) {
        printf("Boolvar2 is true\n");
    }
    else{
        printf("Neither bool is true\n");
    }
    
    printf("\n");
    printf("\n");
    
    // integer and float math
    printf("integer and float math....\n");
    float f1, f2;
    int i1, i2;
    
    i1 = 156;
    f1 = 10.367;
    
    i2 = f1;
    printf("float into int %d\n", i2);
    f2 = i1;
    printf("int into float %f\n", f2);
    
    f2 = i1/100;
    printf("%d / 100 = %f\n", i1, f2);
    
    f2 = i1/100.0;
    printf("%d / 100.0 = %f\n", i1, f2);
    
    printf("\n");
    printf("\n");
    
	// a pointer
    printf("pointers...\n");
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

    printf("\n");
    printf("\n");
    
    // looping and aligning output
    printf("looping and aligning output...\n");
    printf("TRIANGULAR NUMBERS\n");
    printf("  n            sum from 1 to n\n");
    printf("----           ---------------\n");
    int triangularNumber;
    triangularNumber = 0;
    
    for (int n = 1; n < 11; n++){
        triangularNumber += n;
        printf("%2d                   %d\n", n, triangularNumber);
    }
    
    printf("\n");
    printf("\n");
    
    // constants
    const float pi = 3.14159265358970;
    // pi is a constant and cannot be changed
    // pi = pi/2 will produce an error
    printf("the 'const' qualifier means a variable won't be changed \n");
    
	return(SUCCESS);
}


// the helper function
// this helper functions adds together the two input argumetns and return their sum. 
int helper_function(int a, int b){
	return(a+b);
}
