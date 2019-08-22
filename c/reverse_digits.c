/* reverse the digits in a given number */
#include <stdio.h>

int main(void){
    
    // store the number and right digit
    int num;
    int r_dig;
    
    // ask for and get input
    printf("Enter a number to reverse....\n");
    // store input value at location of num -- &num
    scanf("%d", &num);
    
    while (num != 0) {
        r_dig = num%10;
        printf("%d", r_dig);
        num /= 10;
    }
    printf("\n");
    
    return(0);
}
