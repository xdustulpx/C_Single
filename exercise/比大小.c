#include<stdio.h>
int main()
{
    int a,b,max;
    printf("please input a,b:");
    scanf("%d%d",&a,&b);
    if (a<=b)
    {max=b;
    printf("max=%d",max);
    }
    else
    {max=a;
    printf("max=%d",max);
    }
    return 0;
}