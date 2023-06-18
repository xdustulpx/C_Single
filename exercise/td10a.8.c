#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define NBDEFAUT 5
int estEnter(char *str);
int main(int argc,char *argv[]){
    int lines,c;
    if(argc>2){
        fprintf(stderr,"wrong input number\n");
        return EXIT_FAILURE;
    }
    lines=NBDEFAUT;
    if(argc==2){
        if(*argv[1]!='-'||!estEnter(argv[1]+1)){
            fprintf(stderr,"wrong input format\n");
            return EXIT_FAILURE;
        }

        lines=atoi(argv[1]+1);
    }
    while(lines!=0){
        switch(c=getchar()){
            case '\n':lines--;
            default:putchar(c);
        }
        if(lines==0) 
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
int estEnter(char *str){
    if(*str=='\0')
    return 0;
    while(*str){
        if(!isdigit(*str)){
            return 0;
            str++;
        }
    }
    return 1;
}