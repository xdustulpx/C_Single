#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    int jour,mois,annee;
    char nomDuMois[10];
}Date;
int dateValide(Date d);
int main(void){
    Date d1={18,4,2017,"avril"};
    Date d2={33,13,2017,"mars"};
    if(!dateValide(d1)){
        printf("d1有效\n");
    }
    else
    printf("d1无效\n");
    if(!dateValide(d2)){
        printf("d2有效\n");
    }
    else
    printf("d2无效\n");
    return EXIT_SUCCESS;
}
int dateValide(Date d){
    if(!(strcmp(d.nomDuMois,"avril")==0 || strcmp(d.nomDuMois,"mars")==0)){
        fprintf(stderr,"nom du mois wrong");
        return EXIT_FAILURE;
    }
    if(d.annee<0||d.annee>9999){
        fprintf(stderr,"annee wrong");
        return EXIT_FAILURE;
    }
    if(d.mois<1||d.mois>12){
        fprintf(stderr,"mois wrong");
        return EXIT_FAILURE;
    }
    if((d.jour<1&&d.jour>30&&d.mois==(4||6||9||11))||(d.jour<1&&d.jour>31&&d.mois==(1||3||5||7||8||10||12))||(d.jour<1&&d.jour>28&&d.mois==2&&d.annee%4==0&&d.annee%100!=0&&d.annee%400==0)){
        fprintf(stderr,"jour wrong");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}