#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *exchanger(char *str);
char *strfry(char *str);
int main(){
    char *str1,*str2;
    int n=100;
    str1=(char*)malloc(sizeof(int)*n);
    str2=(char*)malloc(sizeof(int)*n);
    scanf("%s",str1);
    str2=strfry(str1);
    printf("%s",str2);
    free(str1);
    free(str2);
    return EXIT_SUCCESS;
}
char *exchanger(char *str){
    int i,j,len=0;
    char autre='0';
    len=strlen(str);
    i=rand()%len;
    j=rand()%len;
    autre=*(str+i);
    *(str+i)=*(str+j);
    *(str+j)=autre;
    return str;
}
char *strfry(char *str){
    int len=strlen(str);
    for(int i=0;i<len;i++){
        exchanger(str);
    }
    return str;
}