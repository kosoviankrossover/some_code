// strings
// import header for strings - contains strlen
#include <string.h>

#include <stdio.h>

int main(void){
    
    // declare string - with size
    char str[255];

    // to read in only the first word of the string
    // scanf("%s", str);
    // but if you want to read spaces and commas, for example
    // this will read everything but the new line character "\n"
    scanf("%[^\n]s", str);
    
    // print string
    printf("Your input was %s\n", str);
    
    // string length
    int len = strlen(str);
    printf("It is %d characters long\n", len);
}
