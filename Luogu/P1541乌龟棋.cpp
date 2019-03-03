#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[400],b,x[5],f[400][50][50][50];
int min(int a,int b)
{
	return a<b?a:b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	for(int i=1; i<=m; i++)scanf("%d",&b),x[b]++;
	f[1][0][0][0]=a[1];
	for(int s=2; s<=n; s++)
		for(int i=0; i<=min(x[4],s/4); i++)
			for(int j=0; j<=min(x[3],s/3); j++)
				for(int k=0; k<=min(x[2],s/2); k++)
				{
					if(i*4+j*3+k*2+1>s)continue;
					int tmp=s-i*4-j*3-k*2-1;
					if(tmp>x[1])continue;
					if(s-4>0&&i-1>=0)f[s][i][j][k]=max(f[s][i][j][k],f[s-4][i-1][j][k]+a[s]);
					if(s-3>0&&j-1>=0)f[s][i][j][k]=max(f[s][i][j][k],f[s-3][i][j-1][k]+a[s]);
					if(s-2>0&&k-1>=0)f[s][i][j][k]=max(f[s][i][j][k],f[s-2][i][j][k-1]+a[s]);
					if(tmp<=x[1])f[s][i][j][k]=max(f[s][i][j][k],f[s-1][i][j][k]+a[s]);
				}
	printf("%d\n",f[n][x[4]][x[3]][x[2]]);
	return 0;
}
