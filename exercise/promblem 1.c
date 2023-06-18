//输入a,b，输入a与b,a或b,a异或b
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,n,x1,x2,x3,i;
    int n=2;
    c=0;
    int a[17];
    int b[17];
    scanf("%d %d",&a,&b);
    while (a>0)
    {
        c=(a%n);
        a[i]=c;
        a=a/n;
        i++;
    } 
    while (b>0)
    {
        c=(b%n);
        b[i]=c;
        b=b/n;
        i++;
    } 
    for (i; i>=0; i--)
    {
       printf("%d\n%d\n",a[i],b[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}