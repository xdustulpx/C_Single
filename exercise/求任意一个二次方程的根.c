//利用求根公式计算一个二次方程的根
#include<stdio.h>
#include<math.h>
int main()
{
    printf("input a,b,c:");
    double a,b,c,x1,x2;
    scanf("%lf,%lf,%lf",&a,&b,&c);
    x1=(-b+sqrt(b*b-4*a*c))/2*a;
    x2=(-b-sqrt(b*b-4*a*c))/2*a;
    if(b*b-4*a*c>=0)
    printf("x1=%lf\nx2=%lf\n",x1,x2);
    else
    printf("x1,x2 not exits,please check it out");
    return 0;
}