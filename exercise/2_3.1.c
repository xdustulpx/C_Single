#include<stdio.h>
#include<stdlib.h>
typedef struct date{
    int day;
    int mois;
    int annee;
    char* weekend;
}Date;
Date* initDate(int day,int mois,int annee,char *weekend){
    Date *p,*date=malloc(sizeof(struct date));
    date->day=day;
    date->mois=mois;
    date->annee=annee;
    date->weekend=weekend;
    p=date;
    if(intvalidatedate(p)){
        return p;
    }
    else
    return NULL;
}
int intvalidatedate(Date *d){
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    // check year
    if (d->annee < 1 || d->annee > 9999) {
        return 0;
    }
    // check month
    if (d->mois < 1 || d->mois > 12) {
        return 0;
    }
    // check day
    int days_this_month = days_in_month[d->mois - 1];
    if (d->mois == 2 && (d->annee % 4 == 0 && (d->annee % 100 != 0 || d->annee % 400 == 0))) {
        days_this_month = 29;
    }
    if (d->day < 1 || d->day > days_this_month) {
        return 0;
    }
    // date is valid
    return 1;
}
int main(){
    int day,mois,annee=0;
    char* weekend=malloc(sizeof(char*));
    Date* date=malloc(sizeof(struct date));
    scanf("%d",&day);
    scanf("%d",&mois);
    scanf("%d",&annee);
    scanf("%s",weekend);
    date=initDate(day,mois,annee,weekend);
    if (date == NULL) {
        printf("Invalid date!\n");
    } 
    else {
        printf("Annee: %d\n", date->annee);
        printf("Mois: %d\n", date->mois);
        printf("Day: %d\n", date->day);
        printf("Weekday: %s\n", date->weekend);
        free(date->weekend); // 释放内存
        free(date);
    }
    return 0;
}