#include<stdio.h>
#include<stdlib.h>
int main(){
    int i=0;
    char* day[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Sarturday","Sunday"};
    for(i=0;i<7;i++){
    printf("%s\n",*(day+i));
    }
    return EXIT_SUCCESS;
}