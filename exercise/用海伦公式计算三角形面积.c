//输入三角形边长，利用海伦公式计算一个任意三角形面积
#include<stdio.h>
#include<math.h>
int main()
{
    printf("please input a,b,c:");
    double area,s,a,b,c;
    scanf("%lf,%lf,%lf",&a,&b,&c);
    s=(a+b+c)/2.0;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("area=%lf",area);
    return 0;


}