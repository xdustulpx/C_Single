#include<stdio.h>
#include<math.h>
int main(){
	int n, i, sum=0;
	scanf("%d", &n);
	int a[n];
	double f[n];
	double average=0, D;
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	average = (double)sum/n;//计算平均数 
	for(i=0; i<n; i++){ 
	D += (a[i]-average)*(a[i]-average);
	}
	D = sqrt(D/n);//计算标准差 
	for(i=0; i<n; i++){
		f[i] = (double)(a[i]-average)/D;
		printf("%f\n", f[i]);
	}
	return 0;
}