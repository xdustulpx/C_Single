#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int max;
    int a[1000],n,i;
    double p,m;
    (void)p;
    scanf("%lf %d",&m,&n);
    for(i=0;i<1000;i++)
    {
        if(m<=pow(m,i))
        {
            max=i-1;
            break;
        }
        else
        continue;
    }
    for(i=max;i<1000;i--)
    {
        a[i]=0;
        p=pow(m,i);
        while(m-p>p)
        {
            a[i]++;
        }
    }
    for(i=max;i<1000;i--)
    {
        if(a[i]!=0&&i>0)
        printf("%d*%lf^%d+",a[i],m,i);
        else if(a[i]!=0&&i==0)
        printf("%d*%lf^%d",a[i],m,i);
        else
        printf("0");
    }
    return EXIT_SUCCESS;
}