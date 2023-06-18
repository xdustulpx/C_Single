#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef enum {carre, rond, triangle } forme;
/* Rôle : affiche la forme f sur la sortie standard */
void afficherForme(const forme f) {
    switch (f) {
        case carre : printf("carre"); break;
        case rond : printf("rond"); break;
        case triangle : printf("triangle"); break;
        default : printf("forme inconnue");
 }
}
void afficherFormeLn(const forme f) {
    afficherForme(f);
    printf("\n");
}
// type ListeDeFormes pour représenter des listes linéaires
// simplement chaînée
typedef struct noeud {
    forme f;
    struct noeud *suivant;
} * ListeDeFormes;
/**
 * Rôle : affiche sur la S/S la liste de formes l
 */
void afficherListedeFormes(const ListeDeFormes l) {
    struct noeud *p = l;
    printf("< ");
    while (p!=NULL) {
// *p exists ; p désigne le noeud dont je veux affichier la forme
        afficherForme(p->f);
        printf(" ");
// passer au noeud suivant
        p = p->suivant;
    }
    printf(">");
}
void afficherListedeFormesLn(const ListeDeFormes l) {
    afficherListedeFormes(l);
    printf("\n");
}
// Rôle : renvoie une liste vide
ListeDeFormes listeVide(void) {
    return NULL; 
}
// Rôle : renvoie le nombre de formes de la liste
int longueur(const ListeDeFormes l) {
    struct noeud *p = l;
    int i=0;
    while (p!=NULL) {
// *p exists => incrémenter i;
    i++;
// passer au noeud suivant
    p = p->suivant;
    }
// i est le nombre de noeuds de ma liste
// => c−à−d sa longueur
    return i;
}
// Rôle : renvoie la forme de rang r de la liste l
// Antécédent : 1 <= r <= longueur(l)
    forme ieme(const ListeDeFormes l, const int r) {
    assert(r>=1 && r<=longueur(l));
// r est un rang valide => il existe une forme au rang r
// renvoyer cette forme
    struct noeud *p = l;
    for (int i= 1 ; i<r; i++)
    p=p->suivant;
// p désigne la forme de rang r dans la liste l
    return p->f;
}
// Rôle : insérer dans la liste l la forme f, au rang r
// Antécédent : 1 <= r <= longueur(l)+1
void inserer(ListeDeFormes *l, const int r, const forme f) {
    assert(r>=1 && r<=longueur(*l)+1);
// le rang r est correct
// créer un nouveau noeud dans lequel on met f
    struct noeud *p = malloc(sizeof(struct noeud));
    p->f = f;
    if (r==1) {
// cas particulier : insertion au rang 1 (first position)
    p->suivant = *l;
    *l = p;
    }
    else {
// cas général : r>=2
// insert ce nouveau noeud au rang r
// se positionner au rang r−1
    struct noeud *q = *l;
for (int i=2 ; i<r; i++)
    q=q->suivant;
// q désigne la forme de rang r−1 dans la liste l
// (a)
    p->suivant = q->suivant;
// (b)
    q->suivant = p;
 }
}
// Rôle : supprime la forme de rang r de la liste l
// Antécédent : 1 <= r <= longueur(l)
void supprimer(ListeDeFormes *l, const int r) {
    assert(r>=1 && r<=longueur(*l));
    struct noeud *p;
    if (r==1) {
// cas particulier : insertion au rang 1 (first position)
    p = *l;
    *l = (*l)->suivant;
    }
    else {
// cas général : r>=2
// se positionner au rang r−1
    struct noeud *q = *l;
    for (int i=2 ; i<r; i++){
    q=q->suivant;}
 // q désigne la forme de rang r−1 dans la liste l
// l’élément à supprimer est au rang r => le mémoriser
    p = q->suivant;
    q->suivant = p->suivant;
    }
// p désigne l’élément à supprimer => libérer son espace mémoire
    free(p);
}
int main(void) {
    ListeDeFormes lf = listeVide();
    afficherListedeFormesLn(lf);
    printf("longueur de lf = %d\n", longueur(lf));
// lf est une liste vide => longueur(lf)==0
    inserer(&lf, 1, carre); 
    inserer(&lf, 1, rond); // 
    inserer(&lf, 2, triangle); //
    afficherListedeFormesLn(lf);
// printf("longueur de lf = %d\n", longueur(lf));
// lf est une liste vide => longueur(lf)==0
//afficherFormeLn(ieme(lf, 2));
    supprimer(&lf, 3);
    afficherListedeFormesLn(lf);
    supprimer(&lf, 1);
    afficherListedeFormesLn(lf);
    return EXIT_SUCCESS;
}