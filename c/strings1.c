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
    
    printf("\n\n");
    
    // strings as character arrrays
    // Strings in C are actually arrays of characters
    // use pointers to a character array to define simple strings
    char* str_1 = "Hello world 1";
    // This method creates a string which we can only use for reading.
    // If we wish to define a string which can be manipulated, we will
    // need to define it as a local character array:
    char str_2[] = "Hello world 2";
    printf("%s ... %s \n", str_1, str_2);
    
    // str length
    int len_1 = strlen(str_1);
    int len_2 = strlen(str_2);
    if (len_1 == len_2) {
        printf("lengths are the same \n");
        // string comparison
        if (strncmp(str_1, str_2, len_1) != 0) {
            printf("but the strings are different\n");
        }
    }
    // string concatenation
    char dest[20]="Hello";
    char src[20]="World";
    strncat(dest,src,3);
    printf("%s\n",dest);
    strncat(dest,src,20);
    printf("%s\n",dest);
    
    printf("\n\n");
    
    
}
