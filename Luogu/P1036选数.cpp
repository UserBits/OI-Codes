#include<iostream>
#include<cstdio>
using namespace std;
int n,k,ans,a[25];
bool prime(int x)
{
	if(x<2)
		return 0;
	if(x==2)
		return 1;
	if(x%2==0)
		return 0;
	for(int i=3;i*i<=x;i+=2)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}
void dfs(int i,int j,int sum)
{
	if(!i)
	{
		ans+=prime(sum);
		return;
	}
	for(j;j<=n;j++)
		dfs(i-1,j+1,sum+a[j]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(k,1,0);
	printf("%d\n",ans);
	return 0;
}
