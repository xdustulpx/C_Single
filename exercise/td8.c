#include<stdio.h>
#include<stdlib.h>
#include "param.h"
int main(void){
#ifdef SIZE
    #if SIZE >= 1024
        double tab[SIZE];
    #else
        #error "SIZE should be higher than 1024"
    #endif
#endif

#ifdef DEBUG
    #ifdef SIZE
        printf("SIZE=%d\n", SIZE);
    #else
        printf("SIZE is not defined\n");
    #endif
#endif

    return EXIT_SUCCESS;
}