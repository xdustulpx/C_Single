#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
typedef enum{carre, rond, triangle} forme;
typedef struct node{
    forme f;
    struct node *next;
} *ListeDeformes;
forme iere(ListeDeformes l,int r);
void insert(ListeDeformes *l,int r,forme f);
void supprimer(ListeDeformes *l,int r);
int longueur(const ListeDeformes l);
void afficherForme(forme f);
ListeDeformes listeVide(void);
void afficherListeDeforme(ListeDeformes lf);
int main(void){
    ListeDeformes lf = listeVide();
    afficherListeDeforme(lf);
    printf("longueur de lf = %d\n", longueur(lf)); 
    insert(&lf, 1, carre); 
    insert(&lf, 1, rond); 
    insert(&lf, 2, triangle); 
    afficherListeDeforme(lf);
    printf("longueur de lf = %d\n",longueur(lf));
    supprimer(&lf, 3);
    afficherListeDeforme(lf);
    supprimer(&lf, 1);
    afficherListeDeforme(lf);
    return EXIT_SUCCESS;
}
int longueur(const ListeDeformes l){
    struct node *p=l;
    int i=0;
    while(p!=NULL){
        if(p->next!=NULL){ 
            p=p->next;
            i++;
        }
    }
    return i;
}
forme iere(ListeDeformes l,int r){
    assert(r>=1&&r<=longueur(l));
    int i;
    forme f1;
    for(i=0;i<r;i++){
        l=l->next;
        if(i==r-1){
            f1=l->f;
        }
    }
    return f1;
}
void insert(ListeDeformes *l,int r,forme f){
    assert(r>=1 && r<=longueur(*l)+1);
    struct node *p=malloc(sizeof(struct node));
    p->f=f;
    if (r==1) {
        p->next=*l;
        *l=p;
    }
    else{
        struct node *q=*l;
        for(int i=2 ; i<r ; i++){
            q=q->next;
        }
            p->next=q->next;
            q->next=p;
        
    }
}
void supprimer(ListeDeformes *l,int r){
    assert(r>1&&r<=longueur(*l));
    struct node *p;
    if(r==1){
        p=*l;
        p=p->next;
        *l=p;
    }
    else{
        struct node *q=*l;
        for(int i=2;i<r;i++){
            q=q->next;
        }
            p = q->next;
            q->next = p->next;
    }
    free(p);
}
void afficherForme(forme f){
    switch (f){
        case carre:printf("carre\n");break;
        case rond:printf("rond\n");break;
        case triangle:printf("triangle\n");break;
        default:printf("forme inconnue\n");
    }
}
ListeDeformes listeVide(void) {
    return NULL; 
}
void afficherListeDeforme(ListeDeformes lf){
    struct node *p=lf;
    printf("<");
    while(p!=NULL){
        afficherForme(p->f);
        printf(" ");
        p=p->next;
    }
    printf(">");
}