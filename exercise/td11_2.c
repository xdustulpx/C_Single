#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#define MAX 100
struct node{
    int elem;
    struct node *next;
};
typedef struct node Node;

struct pile{
    Node *top;
    int sp;
};
typedef struct pile Pile;

const Pile pilevide={NULL,0};

int estvide(const Pile p);
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
                    else{
                    empiler(&p,op1st/op2nd);break;
                    }
                }
            }
        }

    }
    if(!estvide(p)){
        int result = sommet(&p);
        depiler(&p);
        if(!estvide(p)) errordisplay("incorrect");
        printf("result is %d\n",result);
    }
    return EXIT_SUCCESS;
}
int estvide(const Pile p){
    return (p.sp==0);
}
void empiler(Pile *p,const int e){
    Node *q =(Node *)malloc(sizeof(Node));
    (*q).elem = e;
    (*q).next = (*p).top;
    (*p).top = q;
    (*p).sp++;
}
void depiler(Pile *p){
    assert(!((*p).top == NULL));
    Node *q = (*p).top;
    (*p).top =(*q).next;
    (*p).sp--;
    free(q);
}
int sommet(Pile *p){
    assert(!((*p).top == NULL));
    return (p->top->elem);
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
    printf("Error: %s\n",s);
}