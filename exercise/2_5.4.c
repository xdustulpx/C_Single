#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
typedef struct node{
    double item;
    struct node *next;
}*liste;
void ajouterEntete(liste l,const double x);
void creerListeDeDouble(liste l,const char* f);
int main(void){
    char* f="myprog";
    liste l=malloc(sizeof(liste));
    creerListeDeDouble(l,f);
}
void creerListeDeDouble(liste l,const char* f){
    FILE *fd;
    if((fd=fopen(f,"r"))==NULL){//读取不成功就报错
        perror(f);
        exit(errno);
    }
    else{
        liste p=l;
        double x;
        while(fread(&x,sizeof(double),1,fd)>0){
            x=p->item;
            p=p->next;
        }
    }
    fclose(fd);
}
void ajouterEntete(liste l,const double x){
    liste p=malloc(sizeof(struct node));
    p->next=l;
    p->item=x;
    l=p;
}