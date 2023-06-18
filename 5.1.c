#include<stdio.h>
#include<stdlib.h>
double meanTab(int t[],int n);
int main()
{
  static int i,n=0;
  double average=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  average=meanTab(a,n);
  printf("%lf",average);
  return EXIT_SUCCESS;
}
double meanTab(int t[],int n)
{
  int i;
  double average,sum=0;
  for(i=0;i<n;i++)
    {
      sum+=t[i];
    }
  average=sum/n;
  return average;
}