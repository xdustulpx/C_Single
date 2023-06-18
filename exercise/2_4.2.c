#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct {
    int nbLettres;
    int nbChiffres;
}compteurs;
compteurs compter(char* str);
int main(void){
    char* str1=malloc(sizeof(char*));
    compteurs str2;
    scanf("%s",str1);
    str2=compter(str1);
    printf("%d %d",str2.nbLettres,str2.nbChiffres);
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