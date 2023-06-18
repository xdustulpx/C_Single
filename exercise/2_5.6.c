#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int item;
    struct node *next;
}*liste;
void creerFicherDoublesPositifs(liste l,const char* f);
void creerListeDeDouble(liste l,const char* f);
int main(int argc,char *argv[]){
    if(argc!=3){
        fprintf(stderr,"output wrong\n");
    }
    liste l=malloc(sizeof(liste));
    creerListeDeDouble(l,argv[1]);
    creerFicherDoublesPositifs(l,argv[2]);
    return EXIT_SUCCESS;
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