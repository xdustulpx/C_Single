#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char* metEnMajuscule(char* str);
int main(){
    char s1[]="abcdef";
    char *s2=metEnMajuscule(s1);
    printf("%s",s2);
}
char* metEnMajuscule(char* str){
    char *p=str;
    while(*str){
        if(*str!='\0'){
            *str=*str-32;
        }
        str++;
    }
    return p;
}