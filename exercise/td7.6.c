#include<stdio.h>
#include<stdlib.h>
void trim(char *s1,char *s2);
int main(void){
    char *s1="\n bonne année 2023\t";
    char *s2=malloc(sizeof(char)*4);
    trim(s1,s2);
    printf("%s",s2);
    return EXIT_SUCCESS;
}
void trim(char *s1,char *s2){
    int flag=0;
    while(*s1){
        if((*s1!=' '&&9)||flag>1){
            *s2=*s1;
            s2++;
            flag++;
        }
        s1++;
    }
}