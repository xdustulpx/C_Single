
/*
 *antécédent:
 *consequent:
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int counter=0;//initialiser counter
    char str[]="HI!XIDIAN";//initialiser str[] tableau
    for(int i=0;i<9;i++){//utilisez la boucle for pour rechercher et compter des caractères dans chaîne de caractère
        if(str[i]=='I'){//déterminer les conditions de boucle
            counter++;//compteur counter plus un
        }
    }
    printf("%d",counter);//compostez des nombre
    return EXIT_SUCCESS;//valeur de retour
}