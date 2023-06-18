#include<stdio.h>
#include<stdlib.h>
typedef struct data{
        int item;
        struct data *next;
    }*liste;
liste creatnode(int x){
    liste p=malloc(sizeof(struct data));
    p->item=12;
    p->next=NULL;
    return p;
    }
int main(){
    struct data d1,d2,d3;
    d2.item=creatnode(12);
    return EXIT_SUCCESS;
}