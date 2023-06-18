#include<stdio.h>
#include<stdlib.h>
typedef struct{
    double reel;
    double img;
}Complexe;
Complexe initComplexe(double reel,double img);
void ecrireComplexe(Complexe a);
int main(void){
    double reel=0;
    double img=0;
    scanf("%lf %lf",&reel,&img);
    Complexe a;
    a=initComplexe(reel,img);
    ecrireComplexe(a);
    return EXIT_SUCCESS;
}
Complexe initComplexe(double reel,double img){
    Complexe s1;
    s1.reel=reel;
    s1.img=img;
    return s1;
}
void ecrireComplexe(Complexe a){
    printf("输入的复数为%.2lf+%.2lfi",a.reel,a.img);
}