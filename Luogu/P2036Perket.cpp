#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[15],b[15],n,ans=2147483647;
int abs(int x)
{
	if(x>=0)
		return x;
	return -x;
}
void dfs(int i,int sour,int sweet)
{
	if(i>n)
	{
		if(sour==0 || sweet==0)
			return;
		ans=min(ans,abs(sour-sweet));
		return;
	}
	dfs(i+1,sour*a[i],sweet+b[i]);
	dfs(i+1,sour,sweet);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	dfs(1,1,0);
	printf("%d\n",ans);
	return 0;
}

