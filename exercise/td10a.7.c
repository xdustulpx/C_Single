#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int estOperate(char *s);
int estEntier(char *s);
int main(int argc,char *argv[]){
    if(argc!=4){
        fprintf(stderr,"wrong\n");
        return EXIT_FAILURE;
    }
    if(!estEntier(argv[1])){
        fprintf(stderr,"wrong entier1\n");
       return EXIT_FAILURE;
    }
    if(!estOperate(argv[2])){
        fprintf(stderr,"wrong operate\n");
        return EXIT_FAILURE;
    }
    if(!estEntier(argv[3])){
        fprintf(stderr,"wrong entier2\n");
        return EXIT_FAILURE;
    }
    int res,opG=atoi(argv[1]),opD=atoi(argv[3]);
    switch(*argv[2]){
        case '+':res=opG+opD;break;
        case '-':res=opG-opD;break;
        case 'x':res=opG*opD;break;
        case '/':
            if(opD==0){
                fprintf(stderr,"Division is zero");
                return EXIT_FAILURE;
            }
        res=opG/opD;break; 
    }
    printf("%d %c %d = %d\n",opG,*argv[2],opD,res);
    return EXIT_SUCCESS;
}
int estOperate(char *s){
    return ((*s=='+'|| *s=='-'|| *s=='x'||*s=='/')&&*(s+1)=='\0');
}
int estEntier(char *s){
    if(*s=='\0') return 0;
    while (*s){
        if(!isdigit(*s))
        return 0;
    s++;
    }
    return 1;
}