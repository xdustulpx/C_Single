#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,a,b,i,j=0;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    long long f[36][36];
    int g[25][25];
    g[a][b]=1;
    if(a>1 && b!=0)
    g[a-2][b-1]=1;
	if(a<19 && b!=0)
	g[a+2][b-1]=1;
	if(a>1 && b!=20)
	g[a-2][b+1]=1;
	if(a<19 && b!=20)
	g[a+2][b+1]=1;
	if(a!=0 && b>1)
	g[a-1][b-2]=1;
	if(a!=0 && b<19)
	g[a-1][b+2]=1;
	if(a!=20 && b>1)
	g[a+1][b-2]=1;
	if(a!=20 && b<19)
	g[a+1][b+2]=1;
    for (i=0;i<=n;++i)
    {
        for(j=0;j<=m;++j)
        {
            if(!g[i][j])
            {
                if(i==0&&j==0)
                {
                    f[0][0]=1;
                }
                else if(i==0&&j>0)
                {
                    f[0][j]=f[0][j-1];
                }
                else if(i>0&&j==0)
                {
                    f[i][0]=f[i-1][0];
                }
                else
                    f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
    }
    printf("%lld\n",f[n][m]);
    return EXIT_SUCCESS;
}