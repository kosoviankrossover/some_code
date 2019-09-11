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





//int main (void) {
//
//    int buff_size = 6;
//    int end;
//
//    char string[6];
//    char string_[6];
//
//    fgets(string, buff_size, stdin);
//    for (int i=0; i<buff_size; i++) {
//        printf("%d - '%c'....\n", i, string[i]);
//        if (string[i] == '\n') printf("newline\n");
//        if (string[i] == '\0') printf("newline\n");
//    }
//
//    end = strcspn(string, "\0");
//    printf("end = %d\n", end);
//    printf("string[end-1] = '...%c' \n", string[end-1]);
//
//    if (string[end-1] == '\n') string[end-1] = '\0';
//
//    printf("string[end-1] = '...%c' \n", string[end-1]);
//
//    if ( end == (buff_size-1) ) {
//        if (string[buff_size])
//        printf("if\n");
//        // clear stdin
//        int c;
//        for (;;)
//        {
//            c = getchar(); // c has been declared elsewhere
//            if ((c == '\n') || (c == EOF)) break;
//        }
//    }
//
//    printf("-------\n");
//    fgets(string_, buff_size, stdin);
//    printf("%s\n", string_);
//    printf("-------\n");
//
//    return(0);
//}
