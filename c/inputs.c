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

int main (void) {
    
    int buff_size = 6;
    char string[buff_size];
    char string_[buff_size];
    
    printf("Input[<6]: ");
    if ( get_intput(string, buff_size) == ERROR ) return(ERROR);

    printf("You're stored input was '%s'\n", string);
    
    printf("Input[<6]: ");
    if ( get_intput(string_, buff_size) == ERROR ) return(ERROR);
    
    printf("You're stored input was '%s'\n", string_);
    
    return(SUCCESS);
}
