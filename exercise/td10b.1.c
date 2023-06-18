#include<stdio.h>
#include<stdlib.h>
typedef enum{carre,rond,triangle}forme;
void afficherForme(forme f);
int main(void){
    //1
    forme *p,*q,*r;
    //2
    p=malloc(sizeof(int));
    *p=carre;
    q=malloc(sizeof(int));
    *q=rond;
    //3
    afficherForme(*p);
    afficherForme(*q);
    //4
    r=p;
    afficherForme(*r);
    //5
    *p=triangle;
    afficherForme(*r);
    //6
    free(p);
    //7
    afficherForme(*r);
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