/*
Convert a number from base 10 to a new base.
In the future, we will allow for a the input base to vary as well.
*/

// libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// definitions
#define ERROR 1
#define SUCCESS 0
#define BUFF_SIZE 64

// global vars
long int number_to_convert;
unsigned int new_base;
char converted_number[BUFF_SIZE+1];

// helper functions
int get_intput ( char string[], int buff_size ); // safely grab input
int convert_the_number ( void ); // convert the number
int rev_str ( char str[], unsigned int end ); // reverse a string



// main function
int main (void) {
    
    // buffer to hold input
    char holder[BUFF_SIZE+1];
    
    
    // prompt for input: decimal number
    printf("Give me a base 10 number to convert... ");
    // get input
    if (get_intput(holder, BUFF_SIZE) == ERROR) {
        printf("---- input error ----\n");
        return(ERROR);
    }
    // grab integer
    if (sscanf(holder, "%ld", &number_to_convert) != 1) {
        printf("---- input error ----\n");
        return(ERROR);
    }
    // display input
    printf("--- Your number is '%ld' ---\n", number_to_convert);
    
    
    // prompt for input: new base
    printf("Give me a new base... ");
    if (get_intput(holder, BUFF_SIZE) == ERROR) {
        printf("---- input error ----\n");
        return(ERROR);
    }
    // grab integer
    if (sscanf(holder, "%u", &new_base) != 1) {
        printf("---- input error ----\n");
        return(ERROR);
    }
    // display input
    printf("--- Your new base is '%u' ---\n", new_base);
    // check for proper base
    if ( (new_base<2) || (new_base>16) ) {
        printf("Provide a new base between 2 and 16.\n");
        return(ERROR);
    }
    
    
    // convert the number
    if (convert_the_number() == ERROR) {
        printf("Error in converting number.\n");
        return(ERROR);
    }
    
    printf("Your base 10 number converted to base '%d' is '%s'.\n", new_base, converted_number);
    
    
    return(SUCCESS);
}



/*
 HELPER FUNCTIONS
 */

// reverse a string
int rev_str ( char str[], unsigned int len ) {
    
    // declare string where we will temporarily hold a copy
    char temp_str[len+1];
    strcpy(temp_str, str);
    
    // print the copy
    // printf("--- copied string '%s' ---\n", temp_str);
    
    // for loop iterator
    int i;
    
    // loop through transferring the end characters in
    // the copy to the front character in the original
    for (i=0; i<len; i++) {
        str[i] = temp_str[len-i-1];
    }
    
    return(SUCCESS);
}

// convert number to new base
int convert_the_number ( void ) {
    
    // conversion table
    const char conversion[16] = {
        '0','1','2','3',
        '4','5','6','6',
        '8','9','A','B',
        'C','D','E','F'
    };
    
    // index tracker
    unsigned int _index = 0;
    
    // loop through to convert
    while ( number_to_convert != 0 ) {
        
        // dont exceed limits
        if (_index > (BUFF_SIZE-1)) {
            printf("Error exceeding limits.\n");
            return(ERROR);
        }
        
        // conversion
        converted_number[_index] = conversion[(number_to_convert % new_base)];
        
        // reduce number
        number_to_convert /= new_base;
        
        // increment index
        _index++;
    }
    // make sure the null is there
    converted_number[_index] = '\0';
    
    // now, we reverse the string to get the actual converted number
    rev_str(converted_number, _index);
    
    // print the conversion
    // printf("--- convertion '%s' ---\n", converted_number);
    
    return(SUCCESS);
}

// safely grab input
int get_intput (char string[], int buff_size) {
    /* Grabs input safely from the user. */
    
    // end of string
    unsigned int str_end;
    
    // newline check
    /*
     If newline is present, it is either at the second to last
     character of the string behind the null character, or the
     newline character has some distance >=1 between it and the
     null character. In the former scenario, we do not need to
     clear the standard input. In the latter scenario, we do.
     */
    bool clear_in = true;
    
    // read in input
    if (fgets(string, buff_size, stdin) != NULL) {
        // find first null
        str_end = strcspn(string, "\0");
        
        // remove new line character if present
        if (string[str_end-1] == '\n') {
            clear_in = false;
            string[str_end-1] = '\0';
        }
        
        //printf("\n-----str_end : %d ------\n", str_end);
        
        // clear input
        if ( (str_end == buff_size-1 ) && (clear_in == true) ){
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

