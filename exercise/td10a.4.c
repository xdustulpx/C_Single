#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b);
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int *x=&a;
    int *y=&b;
    swap(x,y);
    printf("%d %d",a,b);
    return EXIT_SUCCESS;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}