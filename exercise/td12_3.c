#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<errno.h>
void creerFichEntiers(char *f,int n);
void afficherFichEntiers(char *f);
int main(int argc,char *argv[]){
    if(argc!=2){
        printf("incorrect input");
        return EXIT_FAILURE;
    }
    creerFichEntiers(argv[1],20);
    afficherFichEntiers(argv[1]);
}
void creerFichEntiers(char *f,int n){
    FILE *fd;
    if((fd = fopen(f,"w"))==NULL){
        perror(f);
        exit(errno);
    }
    srand(time(0));
    for(int i=0; i<n ; i++){
        int num = rand() %100;
        fwrite(&num,sizeof(int),1,fd);
    }
    fclose(fd);
}
void afficherFichEntiers(char *f){
    FILE *fd;
    int num;
    if((fd = fopen(f,"w"))==NULL){
        perror(f);
        exit(errno);
    }
    while((fread(&num,sizeof(int),1,fd)>0)){
        printf("%4d",num);
    }
    printf("\n");
    fclose(fd);
}