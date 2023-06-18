#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p;
    int i;
    int k;
    i=42;
    k=i;
    p=&i;
    *p=75;
    #ifdef DEBUG
    printf("%d",i);
    #endif
    return EXIT_SUCCESS;
}