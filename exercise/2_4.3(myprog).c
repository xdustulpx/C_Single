#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct {
    int nbLettres;
    int nbChiffres;
}compteurs;
compteurs compter(char* str);
int main(int argc,char* argv[]){
    if(argc!=2){
        fprintf(stderr,"usage:compter str\n");
        return EXIT_FAILURE;
    }
    else{
    compteurs str;
    str=compter(argv[1]);
    printf("%d %d",str.nbLettres,str.nbChiffres);
    }
    return EXIT_SUCCESS;
}
compteurs compter(char* str){
    int i=0;
    compteurs tableau;
    while(*(str+i)){
        for(i=0;*(str+i);i++){
            if(isalpha(*(str+i)))
            tableau.nbLettres++;
            if(isdigit(*(str+i)))
            tableau.nbChiffres++;
        }
    }
    return tableau;
}