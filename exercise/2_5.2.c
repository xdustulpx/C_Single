typedef struct node{
    double item;
    struct node *next;
}*liste;
void ajouterEntete(liste l,const double x){
    liste p=malloc(sizeof(liste));
    p->next=l;
    p->item=x;
    l=p;
}