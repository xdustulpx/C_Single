#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    int i=1;
    while(--argc && argv[i][0]=='-'){
        int j=1;
        while(argv[i][j]!='\0'){
            printf("option %c\n",argv[i][j]);
            j++;
        }
        i++;
    }
    while(argc--){
        printf("parameter %s\n",argv[i++]);
    }
    return EXIT_SUCCESS;
}