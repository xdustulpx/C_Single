#include<stdio.h>
#include<stdlib.h>
typedef enum{carre,rond,triangle}forme;
void afficherForme(forme f);
typedef struct node{
    forme f;
    struct node *next;
}*ListeDeforme;
void afficherListeDeforme(ListeDeforme lf);
int main(void){
    ListeDeforme lf;
    struct node *p,*q,*r;
    p=malloc(sizeof(struct node));
    p->f=rond;
    lf=p;
    q=malloc(sizeof(struct node));
    q->f=triangle;
    p->next=q;
    r=malloc(sizeof(struct node));
    r->f=carre;
    q->next=r;
    r->next=NULL;
    afficherForme(lf->f);
    afficherForme(lf->next->f);
    afficherForme(lf->next->next->f);
    //2,3
    afficherListeDeforme(lf);
    //4
    p=malloc(sizeof(struct node));
    p->f=carre;
    p->next=lf;
    lf=p;
    afficherListeDeforme(lf);
    printf("-------------------------\n");
    //5
    lf->next->next=lf->next->next->next;
    afficherListeDeforme(lf);
    return EXIT_SUCCESS;
}
void afficherForme(forme f){
    switch (f){
        case carre:printf("carre\n");break;
        case rond:printf("rond\n");break;
        case triangle:printf("triangle\n");break;
        default:printf("forme inconnue\n");
    }
}
void afficherListeDeforme(ListeDeforme lf){
    while(lf!=NULL){
        afficherForme(lf->f);
        lf=lf->next;
    }
}