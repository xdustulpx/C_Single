//在机器学习中，对数据进行归一化处理是一种常用的技术。
//将数据从各种各样分布调整为平均值为0、方差为1的标准分布，在很多情况下都可以有效地加速模型的训练。
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
   int n,i=0;
   scanf("%d",&n);//读取n个整数
   int d[n];
   double f[n],a,b=0;//定义长度为n的数组
   for(i=0;i<n;i++)//将n个整数存入数组中
      {
       scanf("%d",&d[i]);
      }
   for(i=0;i<n;i++)
      {
      a+=d[i];
      }
   a=(double)a/n;//将n个整数相加，并取平均
   for(i=0;i<n;i++)
      {
       b+=(d[i]-a)*(d[i]-a);
      }
   b=sqrt(b/n);//对n个整数进行求方差
   for(i=0;i<n;i++)
      {
       f[i]=(double)(d[i]-a)/b;
       printf("%f\n",f[i]);
      }//对n个整数进行归一化处理
   return EXIT_SUCCESS;
}