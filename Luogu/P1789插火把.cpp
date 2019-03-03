#include<iostream>
#include<cstdio>
using namespace std;
int a[505][505],n,m,k,x,y,v;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		for(int j=x-2;j<=x+2;j++)
			a[j][y]=1;
		for(int j=y-2;j<=y+2;j++)
			a[x][j]=1;
		for(int j=x-1;j<=x+1;j++)
		{
			for(int k=y-1;k<=y+1;k++)
				a[j][k]=1;
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&x,&y);
		for(int j=x-2;j<=x+2;j++)
		{
			for(int k=y-2;k<=y+2;k++)
				a[j][k]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
				v++;
		}
	}
	printf("%d\n",v);
	return 0;
}

