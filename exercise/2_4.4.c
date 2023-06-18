#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<errno.h>
typedef struct node{
    double item;
    struct node *next;
}*listeD;
void creerListeD(const char *f,listeD *l);
void printListD(listeD *l);
int main(void){
    const char *f="myprog";
    listeD *l;
    creerListeD(f,l); 
}
void creerListeD(const char *f,listeD *l){
    FILE* fd;
    double *arr=malloc(sizeof(double));
    if((fd=fopen(f,"r"))==NULL){//判断是否成功打开文件
        perror(f);
        exit(errno);//不成功就报错
    }
    else{
        fread(arr,sizeof(double),1,fd);//将fd指向的文件的数据写入到arr数组中
        int n;
        n=sizeof(arr)/sizeof(*arr);
        //生成一个链表
        listeD head=malloc(sizeof(listeD));
        listeD temp=head;//让temp指向head
        temp->item=0;
        temp->next=NULL;
        for(int i=0;i<n;i++){//生成n个p结点
            listeD p=malloc(sizeof(listeD));
            p->item=0;
            temp->next=p;
            temp=p;
        }
        temp->next=NULL;
        //将arr数组的数据写入链表中
        temp=head;//更新temp为head
        for(int i=0;i<n;i++){
            while(temp!=NULL){
                if(temp->next!=NULL){
                    temp->item=*(arr+i);
                    temp=temp->next;
                }
                else{
                    temp->item=*(arr+i);
                    temp=temp->next;
                }
            }
        }
    *l=temp;//链表指针l指向链表头结点
    }
}
void printListD(listeD *l){
    while(l!=NULL){
        // 如果p不是链表尾结点，则打印结点数据和箭头符号
        if(l->next!=NULL){
            printf("%lf->",l->item);
            l=l->next;
        }
        // 如果p是链表尾结点，则只打印结点数据
        else{
            printf("%lf\n",l->item);
            l=l->next;
        }
    }
}