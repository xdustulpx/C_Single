#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<errno.h>
void creerFichierEntiers(char *f,int n);
int main(int argc,char *argv[]){
    if(argc!=2){
        printf("incorrect input");
        return EXIT_FAILURE;
    }
    creerFichierEntiers(argv[1],20);
}
void creerFichierEntiers(char *f,int n){
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