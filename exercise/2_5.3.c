#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
typedef struct node{
    double item;
    struct node *next;
}*liste;
void ajouterEntete(liste l,const double x);
void creerListeDeDouble (liste l,const char* f);
int main(void){
    char* f="myprog";
    liste l=NULL;
    creerListeDeDouble(l,f);
}
/*功能：*/
void creerListeDeDouble (liste l,const char* f){
    FILE *fd;//定义文件类型指针
    if((fd=fopen(f,"r"))==NULL){//读取不成功就报错
        perror(f);
        exit(errno);
    }
    else{
        double x;
        while(fread(&x,sizeof(double),1,fd)>0){//每次从fd指向的文件中读取实数，并存入到x变量中，再用ajouterEntete函数插入到链表头
                ajouterEntete(l,x);
    }
        fclose(fd);
    }
}
/*功能：在链表的头处插入一个新元素x*/
void ajouterEntete(liste l,const double x){
    liste p=malloc(sizeof(liste));//生成一个新的结点p
    p->next=l;
    p->item=x;
    l=p;//更新头结点
}
/*
        liste p=l;//p指向链表l
        while(fread(&x,sizeof(double),1,fd)){
            p->item=x;
            p=p->next;
        }
        */
    
    /**
    else{
        liste head=malloc(sizeof(liste));//创建头结点
        liste temp=head;//temp指向头结点
        temp->next=NULL;
        while(fread(&x,sizeof(double),1,fd)!=NULL){
            liste p=malloc(sizeof(liste));
            p->item=x;
            temp->next=p;
            temp=p;
        }
        temp->next=NULL;
    }
    l=temp;
     */