#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#define MAX 100
typedef struct pile{
    int sp;
    int elem[MAX];
}Pile;
const Pile pilevide={0};//定义空栈
int estvide(const Pile p);
int overflow(const Pile p);
void empiler(Pile *p,const int e);
void depiler(Pile *p);
int sommet(Pile *p);
int estEntiers(char *s);
int estOperator(char *s);
void errordisplay(char *s);
int main(int argc,char *argv[]){
    Pile p=pilevide;
    for(int i=1;i<argc;i++){
        if(estEntiers(argv[i])){
            empiler(&p,atoi(argv[i]));//如果是数字，就入栈
        }
        else{
            if(estOperator(argv[i])){
                int op2nd =sommet(&p);depiler(&p);
                int op1st =sommet(&p);depiler(&p);
                switch(*argv[i]){
                    case '+':empiler(&p,op1st+op2nd);break;
                    case '-':empiler(&p,op1st-op2nd);break;
                    case 'x':empiler(&p,op1st*op2nd);break;
                    case '/':
                    if(op2nd==0){
                        errordisplay("division by zero");
                    }
                      empiler(&p,op1st/op2nd);break;
                }
            }
        }
    }
    if(!estvide(p)){
        int result = sommet(&p);
        depiler(&p);
        if(!estvide(p)) {
            errordisplay("incorrect");
        }
        printf("result is %d\n",result);
    }
    return EXIT_SUCCESS;
}
int estvide(const Pile p){
    return p.sp==0;
}
int overflow(const Pile p){
    return p.sp==MAX;
}
void empiler(Pile *p,const int e){
    assert(!overflow(*p));
    (*p).elem[((*p).sp++)]=e;
}
void depiler(Pile *p){
    assert(!estvide(*p));
    (*p).sp--;
}
int sommet(Pile *p){
    assert(!estvide(*p));
    return ((*p).elem[(*p).sp-1]);
}
int estEntiers(char *s){
    if((*s=='\0'))return 0;
    while(*s)
        if(!isdigit(*s++)) return 0;
    return 1;
}

int estOperator(char *s){
    return ((*s=='+')||(*s=='-')||(*s=='x')||(*s=='/'))&&(*(s+1)=='\0');
}

void errordisplay(char *s){
    printf("Error: %s \n",s);
}