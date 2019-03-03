#include<iostream>
#include<cstdio>
using namespace std;
int a[15],n;
bool b[15];
void dfs(int now)
{
	if(now>n)
	{
		for(int i=1;i<=n;i++)
			printf("%5d",a[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			a[now]=i;
			b[i]=1;
			dfs(now+1);
			b[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}
