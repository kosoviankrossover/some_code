// this is a one line comment

// include a header file
// this header in particular includes the printf function that we often use
#include <stdio.h>

// define an alias
#define SUCCESS 0

/* This is a multi-line comment.
We are declaring a helper function that will provide some function for our
main program. The int before the function  declaration indicates that we expect
to return an integer. */
int helper_function(int a, int b);

/* This is the main function of the program. */
int main(){

	// // simple for loop addition
	// int i = 8;
	// for (int j=0; j<3; j++){
	// 	printf("%d + %d = %d\n",i,j,i+j);
	// }

	// declare and define some integers
	int i = 10;
	int j = 20;

	// use our helper function to add the two variables
	int sum = helper_function(i,j);

	// print the result
	printf("i+j = %d \n", helper_function(i,j));

	// a pointer
	int* ptr;

	// let ptr point towards the location holding i
	ptr = &i;
	// print the dereferenced ptr
	printf("The value at the dereferenced ptr: %d \n", *ptr);

	// let ptr point towards the location holding j
	ptr = &j;
	// print the dereferenced ptr
	printf("The value at the dereferenced ptr: %d \n", *ptr);

	// lets store something else to where ptr points
	*ptr = 30;
	printf("The value at the dereferenced ptr: %d \n", *ptr);

	// whats store in j now tho?
	printf("j = %d \n", j);


	return(SUCCESS);
}


// the helper function
// this helper functions adds together the two input argumetns and return their sum. 
int helper_function(int a, int b){
	return(a+b);
}
