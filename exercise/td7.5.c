#include<stdio.h>
#include<stdlib.h>
void strcpy(char *s1,char *s2);
int main(void){
    char *s1="what is the world!";
    int n=4;
    char*s2=malloc(sizeof(char)*n);
    strcpy(s1,s2);
    printf("%s",s2);
    return EXIT_SUCCESS;
}
void strcpy(char *s1,char *s2){
    while(*s1){
        if(*s1!='\0'){
            *s2=*s1;
            s2++;
        }
        s1++;
    }
}