#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void inverser(char* s1,char* s2);//函数声明
int main(){
    int n,i=0;
    char *s1,*s2;
    s1=malloc(sizeof(int));
    s2=malloc(sizeof(int));//数组不定长度，开辟内存空间
    printf("请输入字符串：");
    scanf("%s",s1);
    inverser(s1,s2);
    n=strlen(s2);
    for(i=0;i<n;i++){
    printf("%c",s2[i]);
    }
    free(s1);
    free(s2);
    return EXIT_SUCCESS;
}
void inverser(char* s1,char* s2){//字符反转函数
    int n=strlen(s1);
    for(int i=0;i<n;i++){   
    *(s2+i)=*(s1+n-i-1);
    }
}