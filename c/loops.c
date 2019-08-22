#include <stdio.h>

int main (void){
    // for loop
    int i;
    
    for (i=0; i<5; i++) {
        printf("for loop...%d\n", i);
    }
    
    i = 0;
    printf("\n\n");
    
    // while loop
    while (i<5) {
        printf("while loop...%d\n", i);
        i += 1;
    }
    
    i = 0;
    printf("\n\n");
    
    // do while loop
    do {
        printf("do while loop...%d\n", i);
        i += 1;
    }
    while (i < 5);
    
    printf("\n\n");
    
    // break
    for (i=0; i<5; i++) {
        if (i == 3) {
            printf("break at i=3...\n");
            break;
        }
        printf("break loop...%d\n", i);
    }
    
    printf("\n\n");
    
    // continue
    for (i=0; i<5; i++) {
        if (i == 3) {
            printf("continue at i=3...\n");
            continue;
        }
        printf("continue loop...%d\n", i);
    }
        
    return(0);
}
