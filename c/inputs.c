// libraries
#include <stdio.h>
#include <string.h>

// definitions
#define ERROR 1
#define SUCCESS 0

// helper functions
int get_intput (char string[], int buff_size) {
    // end of string
    unsigned int str_end;
    
    // newline check
    int check = 0;

    // read in input
    if (fgets(string, buff_size, stdin) != NULL) {
        // find first null
        str_end = strcspn(string, "\0");
        
        // remove new line character if present
        if (string[str_end-1] == '\n') {
            check = 1;
            string[str_end-1] = '\0';
        }
        
        //printf("\n-----str_end : %d ------\n", str_end);
        
        // clear input
        if ( (str_end == buff_size-1 ) && (check == 0) ){
            int c;
            for (;;)
            {
                c = getchar(); // c has been declared elsewhere
                if ((c == '\n') || (c == EOF)) break;
            }
        }
        
        return(SUCCESS);

    }
    else {
        return(ERROR);
    }
}



// main function
int main (void) {
    
    //buffer size for fgets
    int buff_size = 6;
    /*
     fgets stores values intil buff_size-1 characters have been read
     or a newline character has been read.
     fgets appends a null character '0' at the end of the given string
     */
    // declare some strings
    /*
     declare two strings so that we can show how to deal with inputs
     of various lengths: 1) the same size as buff_size, 2) less than
     the buff_size, and 3) more than the buff_size
    */
    char string[buff_size];
    char string_[buff_size];
    
    // grab input
    printf("Input[<6]: ");
    if ( get_intput(string, buff_size) == ERROR ) return(ERROR);
    printf("You're stored input was '%s'\n", string);
    
    // grab some more input
    printf("Input[<6]: ");
    if ( get_intput(string_, buff_size) == ERROR ) return(ERROR);
    printf("You're stored input was '%s'\n", string_);
    
    return(SUCCESS);
}
