//输入a,b，输入a与b,a或b,a异或b
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int a,b,c,n,i,j;
    n=2;
    c=0;
    int x[17];
    int y[17];
    scanf("%d %d",&a,&b);
    while (a>0)
    {
        c=(a%n);
        x[i]=c;
        a=a/n;
        i++;
    }
    for (i--; i>=0; i--)
    {
       printf("%d",x[i]);
    }
    printf("\n");
    while (b>0)
    {
        c=(b%n);
        y[j]=c;
        b=b/n;
        j++;
    }
    for (j--; j>=0; j--)
    {
       printf("%d",y[j]);
    }
    printf("\n");
    system("pause");
    return 0;
}
