#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int item;
    struct node *next;
}*liste;
void creerFicherDoublesPositifs(liste l,const char* f);
void ajouterEntete(liste l,const double x);
int main(){
    liste l=malloc(sizeof(liste));
    double x;
    char* f="myprog";
    while(scanf("%lf\n",&x)!=EOF){
    ajouterEntete(l,x);
    }
    creerFicherDoublesPositifs(l,f);
}
void creerFicherDoublesPositifs(liste l,const char* f){
    FILE* fd;
    if((fd=fopen(f,"w"))==NULL){
        perror(f);
        exit(errno);
    }
    else{
        liste p=l;
        while(p!=NULL){
        double x=p->item;
            if(x>0){
                fwrite(&x,sizeof(double),1,fd);
            }
        p=p->next;
        }
    }
}
void ajouterEntete(liste l,const double x){
    liste p=malloc(sizeof(liste));
    p->next=l;
    p->item=x;
    l=p;
}