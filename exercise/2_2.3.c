#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *strdup(const char *p);
int main(){
    char *str;
    char *p;
    int i,n=0;
    str=malloc(sizeof(int));
    scanf("%s",str);
    p=strdup(str);
    n=strlen(str);
    for(i=0;i<n;i++){
    printf("%c",*(p+i));
    }
    free(str);
    free(p);
    return EXIT_SUCCESS;
}
char *strdup(const char *p){
    char *str;
    int i=0;
    str=malloc(sizeof(*p));
    for(i=0;*(p+i)!='\0';i++){
    *(str+i)=*(p+i);
    }
    if(str==NULL)
        return NULL;
    return str;
}